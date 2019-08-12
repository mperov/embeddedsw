/******************************************************************************
*
* Copyright (C) 2002 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
*
*
******************************************************************************/

#include <string.h>
#include "xilmfs.h"
/** Global data for file system and open files
 * There can be only one MFS file system because of these globals
 * If you ever need multiple instances of the MFS file system
 * encapsulate these globals in a struct,
 * and replace all instances of these globals with members of the new struct
 * and pass a pointer to an instance of this struct to every function
 * that uses these globals
 */
/* file system data */
struct mfs_file_block* mfs_file_system; /* file system blocks allocated or reserved before calling mfs_init */
int mfs_max_file_blocks; /* max number of blocks available - parameter to mfs_init */
int mfs_free_block_list; /* first element in free list; set by mfs_init */
/* data for file open */
struct mfs_open_file_struct mfs_open_files[MFS_MAX_OPEN_FILES];
int mfs_num_open_files; /* the number of mfs_open_files */
int mfs_current_dir; /* index of current directory block */

/**
 * initialize the file system;
 * this function must be called before any file system operations
 * use mfs_init_genimage instead of this function for initializing with
 * file images generated by mfsgen
 * @param numbytes is the number of bytes allocated or reserved for this file system
 * @param address is the starting address of the memory block
 * Note: address must be word aligned (4 byte boundary)
 * @param init_type is one of
 * MFSINIT_NEW for creating empty read/write filesystem
 * MFSINIT_IMAGE for creating read/write filesystem with predefined data
 * MFSINIT_ROM_IMAGE for creating read-only filesystem with predefined data
 */
void mfs_init_fs(int numbytes, char *address, int init_type) {
  int i;
  mfs_max_file_blocks = numbytes/sizeof(struct mfs_file_block);
  mfs_file_system = (struct mfs_file_block *)address;
if (init_type == MFSINIT_NEW) {
  /* set the zeroth block to be a dir_block with itself as its parent */
  /* initialize the free block list */
  mfs_file_system[0].block_type = MFS_BLOCK_TYPE_DIR;
  mfs_file_system[0].index = 0;
  mfs_file_system[0].next_block = 0;
  mfs_file_system[0].prev_block = 0;
  mfs_file_system[0].u.dir_data.num_entries = 2; /* .. and . */
  mfs_file_system[0].u.dir_data.num_deleted = 0;
  strcpy(mfs_file_system[0].u.dir_data.dir_ent[0].name, "..");
  mfs_file_system[0].u.dir_data.dir_ent[0].deleted = 'n';
  mfs_file_system[0].u.dir_data.dir_ent[0].index = 0; /* .. = index of this block */
  strcpy(mfs_file_system[0].u.dir_data.dir_ent[1].name, ".");
  mfs_file_system[0].u.dir_data.dir_ent[1].deleted = 'n';
  mfs_file_system[0].u.dir_data.dir_ent[1].index = 0; /* . = index of this block */
  for (i = 1; i < mfs_max_file_blocks; i++) {
    mfs_file_system[i].block_type = MFS_BLOCK_TYPE_EMPTY;
    mfs_file_system[i].next_block = i+1;
    mfs_file_system[i].index = i;
    mfs_file_system[i].prev_block = i-1;
  }
  mfs_file_system[mfs_max_file_blocks-1].next_block = 0;
  /* the last block points to 0 */
  /* initialize free block list to the first free index = 1 */
  mfs_free_block_list = 1;
}
else if (init_type == MFSINIT_IMAGE) {
  i = 0;
  while (mfs_file_system[i].block_type != MFS_BLOCK_TYPE_EMPTY) {
    i++;
  }
  /* initialize free block list to the first free index = 1 */
  mfs_free_block_list = i;
}
else { // (init_type == MFSINIT_ROM_IMAGE)
	 mfs_free_block_list = 0;
}

  /* initialize current dir to the top level */
  mfs_current_dir = 0;

  /* initialize mfs_open_files */
  for (i = 0; i < MFS_MAX_OPEN_FILES; i++)
    mfs_open_files[i].mode = MFS_MODE_FREE;
  mfs_num_open_files = 0;
}

/**
 * initialize the file system with a file image generated by mfsgen;
 * this function must be called before any file system operations
 * use mfs_init_fs instead of this function for other initialization
 * @param numbytes is the number of bytes allocated or reserved for this file system
 * @param address is the starting address of the memory block
 * Note: address must be word aligned (4 byte boundary)
 * @param init_type is one of
 * MFSINIT_IMAGE for creating read/write filesystem with predefined data
 * MFSINIT_ROM_IMAGE for creating read-only filesystem with predefined data
 */
void mfs_init_genimage(int numbytes, char *address, int init_type) {
   /* mfsgen generates a file image that contains 4 bytes identifying
    * the file type as mfs2 or MFS2, followed by the file system blocks.
    * So the number of bytes is 4 more than the number of bytes in the
    * file system itself, and the start address of the file system blocks
    * is the given address plus 4.
    * Use these new values to call the mfs_init_fs function to do
    * the actual work
    */
   mfs_init_fs(numbytes-4, address+4, init_type);
}


/**
 * Given a filename, get the directory block and the directory index within
 * that block that correspond to the entry for this filename
 * @param filename
 * @param dir_block is a pointer to the block that is found
 * @param dir_index is a pointer to the index within the block that is found
 * @return 0 for failure and 1 for success
 * on success:
 * return dir_block = index of dir block (may not always be mfs_current_dir)
 * return dir_index = index within dir_block or undefined on failure
 * on failure:
 * return dir_block = index of dir block that has the first "free entry" or
 *                    index of last searched block which should have no free entries or
 *                    -1 to indicate error
 * return dir_index = index within dir_block of first free entry or
 *                    MFS_MAX_LOCAL_ENT if last searched block has no free entry or
 *                    -1 to indicate error
 *
 */
static int get_dir_ent_base(const char *filename,  int *dir_block, int *dir_index, int *reuse_block, int *reuse_index) {
  /* *dir_index = 0; *dir_block = valid dir corresponding to filename prefixes processed so far, on entry to this proc */
  int numentriesleft = mfs_file_system[*dir_block].u.dir_data.num_entries;
  char tmpfilename[MFS_MAX_FILENAME_LENGTH];
  int index = 0;
  int basename = 0;
  int looking_for_reuse = 0;

  while(*filename != '/' && *filename != '\0') {
    tmpfilename[index] = *filename;
    filename++;
    index++;
  }
  tmpfilename[index] = '\0';
  if (*filename == '\0' || (*filename == '/' && *(filename+1)=='\0')) { /* this is the basename */
	  basename = 1;
	  looking_for_reuse = 1;
  }
  while (numentriesleft > 0) {
    if (*dir_index == MFS_MAX_LOCAL_ENT) { /* move to the next dir block */
      *dir_index = 0;
      *dir_block = mfs_file_system[*dir_block].next_block;
    }
    if (mfs_file_system[*dir_block].u.dir_data.dir_ent[*dir_index].deleted != 'y' &&
        !strcmp(mfs_file_system[*dir_block].u.dir_data.dir_ent[*dir_index].name,
                tmpfilename)) { /* found the entry */
      /* *dir_index = index; */
      /* *dir_block = dir; */
      if (basename == 1) /* this is the base file name, ignore final '/' if present */
        return 1;
      else { /* tmpname is the current prefix, filename is the rest of the path */
        *dir_block = mfs_file_system[*dir_block].u.dir_data.dir_ent[*dir_index].index;
        *dir_index = 0;
        filename++;
        return(get_dir_ent_base(filename, dir_block, dir_index, reuse_block, reuse_index));
      }

    }
	else if ((looking_for_reuse == 1) && (mfs_file_system[*dir_block].u.dir_data.dir_ent[*dir_index].deleted == 'y') && (basename == 1)) {
		/* found a possible reuse block */
		*reuse_block = *dir_block;
		*reuse_index = *dir_index;
		looking_for_reuse = 0;
	}
    *dir_index += 1;
    numentriesleft--;
  }
  if (basename == 1) { /* could not find the base name but path prefix is correct */
    return 0;
  }
  else { /* path prefix is wrong */
    *dir_block = -1;
    *dir_index = -1;
    return 0;
  }
}
/**
 * filename is an arbitrarily long  '/' separated path name
 * each component of the path name is never longer than MFS_MAX_FILENAME_LENGTH
 * if the first character is '/', search starting at the root directory
 * else search starting at the current directory
 * return 0 for failure and 1 for success
 * on success:
 * return dir_block = index of dir block (may not always be mfs_current_dir)
 * return dir_index = index within dir_block or undefined on failure
 * on failure:
 * return dir_block = index of dir block that has the first "free entry" or
 *                    index of last searched block which should have no free entries or
 *                    -1 to indicate error
 * return dir_index = index within dir_block of first free entry or
 *                    MFS_MAX_LOCAL_ENT if last searched block has no free entry or
 *                    -1 to indicate error
 *
 */
static int get_dir_ent(const char *filename,  int *dir_block, int *dir_index, int *reuse_block, int *reuse_index) {
  if (filename != NULL && *filename != '\0') {
    if (*filename == '/') {
      filename++;
      *dir_block = 0;
    }
    else {
      *dir_block = mfs_current_dir;
    }
    *dir_index = 0;
    if (*filename == '\0') /* done - looking for the root directory */
      return 1;
    else
      return(get_dir_ent_base(filename, dir_block, dir_index, reuse_block, reuse_index));
  }
  /* error condition */
  *dir_block = -1;
  *dir_index = -1;
  return 0;

}

/**
 * get the directory block and the index within the directory block that contain the value file_index
 * @param dir_block is the pointer to the directory block that is found
 * @param dir_index is the pointer to the directory index that is found
 * @return 0 for failure and 1 for success
 * on success:
 * return dir_block = index of dir block (may not always be mfs_current_dir)
 * return dir_index = index within dir_block or undefined on failure
 * on failure:
 * return dir_block = index of dir block that has the first "free entry" or
 *                    index of last searched block which should have no free entries
 * return dir_index = index within dir_block of first free entry or MFS_MAX_LOCAL_ENT if last searched block has no free entry
*/
static int get_dir_ent_by_index(unsigned int file_index,  int *dir_block, int *dir_index) {

   int numentriesleft;
   /* dir_block is the parent directory of file_index block -> entry 0 is always ".." */
   *dir_block = mfs_file_system[file_index].u.dir_data.dir_ent[0].index;
   numentriesleft = mfs_file_system[*dir_block].u.dir_data.num_entries;

   *dir_index = 0;

   while (numentriesleft > 0) {

      if (*dir_index == MFS_MAX_LOCAL_ENT) { /* move to the next dir block */
         *dir_index = 0;
         *dir_block = mfs_file_system[*dir_block].next_block;
      }

      if (mfs_file_system[*dir_block].u.dir_data.dir_ent[*dir_index].deleted != 'y' &&
          mfs_file_system[*dir_block].u.dir_data.dir_ent[*dir_index].index == file_index) { /* found the entry */
         /* *dir_index = index; */
         /* *dir_block = dir; */
         return 1;
      }
      *dir_index += 1;
      numentriesleft--;
   }
   return 0;
}


/**
 * modify global mfs_current_dir to index of newdir if it exists
 * mfs_current_dir is not modified otherwise
 * @param newdir is the name of the new directory
 * @return 1 for success and 0 for failure
 */
int mfs_change_dir(const char *newdir) {
  /* search current dir for newdir and change current dir if found */
  /* return 1 for success, 0 for failure */
  int new_dir_block;
  int new_dir_index;
  int reuse_block = -1;
  int reuse_index = -1;
  if (get_dir_ent(newdir, &new_dir_block, &new_dir_index, &reuse_block, &reuse_index)) {
    mfs_current_dir = mfs_file_system[new_dir_block].u.dir_data.dir_ent[new_dir_index].index;
    return 1;
  }
  return 0;
}

/**
 * allocate a new block from the free list
 * @param new_entry_index is modified to point to the newly allocated block
 * @return 1 on success, 0 on failure
 */
static int get_next_free_block(int *new_entry_index) {
  if (mfs_free_block_list != 0) {
    *new_entry_index = mfs_free_block_list;

    /* update free_list */
    mfs_free_block_list = mfs_file_system[*new_entry_index].next_block;
    if (mfs_free_block_list != 0) {
      mfs_file_system[mfs_free_block_list].prev_block = 0;
    }
    else {
      /* free list is empty so do not update prev pointer of first element */
    }
    /* remove block from free list */
    mfs_file_system[*new_entry_index].prev_block = 0;
    mfs_file_system[*new_entry_index].next_block = 0;
    return 1;
  }
  return 0; /* failed to get free block */
}

/**
 * create a new directory block, and initialize it with info about . and ..
 * if this dir wants to know its name, it needs to ask its parent
 * @param file_type is either MFS_BLOCK_TYPE_DIR or MFS_BLOCK_TYPE_FILE
 * @param new_entry_index is a pointer to the index of the newly allocated block for the new file
 * @param parent_dir_block is the index of the parent directory of the new file/dir
 * @return 1 for success and 0 for failure
 */
static int create_new_file(int file_type, int *new_entry_index, int parent_dir_block) {
  if (get_next_free_block(new_entry_index)) {
    if (file_type == MFS_BLOCK_TYPE_DIR) {
      /* fill in the new dir block with .. and . */
      mfs_file_system[*new_entry_index].block_type = MFS_BLOCK_TYPE_DIR;
      mfs_file_system[*new_entry_index].u.dir_data.num_entries = 2;
      mfs_file_system[*new_entry_index].u.dir_data.num_deleted = 0;
      mfs_file_system[*new_entry_index].u.dir_data.dir_ent[0].index = parent_dir_block; /* parent dir of this new dir */
      strcpy(mfs_file_system[*new_entry_index].u.dir_data.dir_ent[0].name, "..");
      mfs_file_system[*new_entry_index].u.dir_data.dir_ent[0].deleted = 'n';
      mfs_file_system[*new_entry_index].u.dir_data.dir_ent[1].index = *new_entry_index;
      strcpy(mfs_file_system[*new_entry_index].u.dir_data.dir_ent[1].name, ".");
      mfs_file_system[*new_entry_index].u.dir_data.dir_ent[1].deleted = 'n';
      return 1;
    }
    else if (file_type == MFS_BLOCK_TYPE_FILE) {
      mfs_file_system[*new_entry_index].block_type = MFS_BLOCK_TYPE_FILE;
      mfs_file_system[*new_entry_index].block_size = 0; /* empty file */
      return 1;
    }
    else { /* unknown file_type - error */
      return 0;
    }
  }
  return 0;
}


/**
 * given a filename such as a/b/c/d.txt return d.txt
 * @param filename is the input file name; this is not modified by the function
 * @return pointer to the base name portion of filename
 * return a pointer to the first char that follows the last '/' in filename
 * unless the last char in filename is a '/', in which case return a pointer
 * to the first char that follows the previous '/'
 * if there is no '/' in filename, return filename itself
 */

static char *get_basename(const char *filename) {
   char *base_filename = (char*)filename;

   while(*filename != '\0') {
      if (*filename == '/') {
         filename++;
         if (*filename != '\0')
            base_filename = (char*)filename; /* the first char after / */
      }
      else
         filename++;
   }
   return base_filename;
}

/**
 * special strcpy for filename that omits the final '/' in the stored file name
 * @param to_name
 * @param from_name
 * @return 2 if final '/' is seen
 * @return 1 otherwise
 */
static int set_filename(char *to_name, char *from_name) {
  while (*from_name != '\0') {
    if (*from_name == '/') {
      *to_name = '\0';
      return 2;
    }
    *to_name = *from_name;
    to_name++;
    from_name++;
  }
  *to_name = '\0';
  return 1;
}

/**
 * get the first directory block corresponding to "this" directory block
 * the first directory block contains info about the number of files in the dir
 * @param dir_block is the index of "this" directory block
 * @return the index of the first directory block
 */
static int get_first_dir_block(unsigned int dir_block) {
   while (mfs_file_system[dir_block].prev_block != 0) {
    dir_block = mfs_file_system[dir_block].prev_block;
  }
   /* Fix for CR #161963 */
   /* If the previous block was '0' and not a free block return 0 */
   if (mfs_file_system[0].next_block == dir_block)
      return 0;
   return dir_block;
}

/**
 * Create a new file or dir  named filename
 * If a dir or file of the same name exists, return 0
 * If there is no space on the file system to create file, return 0
 * else create the new file or dir, add entry in current dir table
 * and return index of first block of file or dir
 * @param filename is name of file to create
 * @param file_type is either MFS_BLOCK_TYPE_DIR (for directory) or MFS_BLOCK_TYPE_FILE (for a regular file)
 * @return 1 for success and 0 for failure
 */
static int create_file(const char *filename, int file_type) {
  int new_dir_block;
  int new_dir_index;
  int new_entry_index;
  int new_block;
  int first_dir_block;
  int reuse_block = -1;
  int reuse_index = -1;
  int reusing = 0;

  if (get_dir_ent(filename, &new_dir_block, &new_dir_index, &reuse_block, &reuse_index)) {
    /* file already exists */
    return 0 ; /* cannot create file if it already exists */
  }
  else if (new_dir_block == -1 || new_dir_index == -1) {
    /* file does not exist but path prefix does not exist either */
    return 0; /* cannot create file because its parent dir does not exist */
  }
  else { /* create the file */
    /* first check if there is a reusable entry */
	if ((reuse_block != -1) && (reuse_index != -1)) {
	  /* found an entry to reuse */
	  new_dir_index = reuse_index;
	  new_dir_block = reuse_block;
	  reusing = 1;
	}
    else {
	  /* check if the current dir block is full and
         allocate a new dir block if needed */

      if (new_dir_index == MFS_MAX_LOCAL_ENT) {
        /* create a new dir block linked from this one */
        if (get_next_free_block(&new_block)) { /* found a free block */
	      mfs_file_system[new_block].prev_block = new_dir_block;
	      mfs_file_system[new_block].next_block = 0;
	      mfs_file_system[new_block].block_type = MFS_BLOCK_TYPE_DIR;
	      mfs_file_system[new_block].u.dir_data.num_entries = 0;
	      mfs_file_system[new_block].u.dir_data.num_deleted = 0;
	      mfs_file_system[new_dir_block].next_block = new_block;
	      new_dir_block = new_block;
	      new_dir_index = 0;
        }
        else { /* no space for new block  - return failure */
	      return 0;
        }
      }
    }
    /* at this point new_dir_index and new_dir_block both point to
       the first free entry */
    first_dir_block = get_first_dir_block(new_dir_block);
    if (!create_new_file(file_type, &new_entry_index, first_dir_block)) { /* cannot create new file */
      return 0; /* failure */
    };

	if (reusing != 1) {
      /* update number of entries in current block */
      mfs_file_system[new_dir_block].u.dir_data.num_entries += 1;
      /* update number of entries in directory if it is different than current block */

      if (new_dir_block != first_dir_block)
        mfs_file_system[first_dir_block].u.dir_data.num_entries += 1;
	}
    mfs_file_system[new_dir_block].u.dir_data.dir_ent[new_dir_index].index = new_entry_index;
    set_filename(mfs_file_system[new_dir_block].u.dir_data.dir_ent[new_dir_index].name, get_basename(filename));
    mfs_file_system[new_dir_block].u.dir_data.dir_ent[new_dir_index].deleted = 'n';
    return new_entry_index;
  }
}

/**
 * move a list of blocks starting and start_index and chained
 * through next_block pointers and ending at end_index
 * to the free list
 * the blocks are all already marked as MFS_BLOCK_TYPE_EMPTY
 * the prev_block of start_index is 0, and the next_block of end_index = 0
 * @param start_index
 * @param end_indexA
 * @return 1 - always succeeds
 */
static int move_to_free_list(int start_index, int end_index) {
  if (mfs_free_block_list != 0) { /* free list exists and is non empty */
    /* prepend this list to the existing free list */
    mfs_file_system[mfs_free_block_list].prev_block = end_index;
    mfs_file_system[end_index].next_block = mfs_free_block_list;
  }
  else { /* free list is empty - no need to prepend */
  }
  mfs_free_block_list = start_index;
  return 1; /* always succeeds */
}

/**
 * mark all the data blocks associated with a file as free and add them
 * to the free list
 *  @param file_index is the index of the first block in the list of blocks that make up the file
 * @return 1 for success and 0 for failure
 * delete dir blocks only if the directory is empty
 */
static int delete_data_in_file(int file_index) {
  int next_block;
  int current_block;
  if (mfs_file_system[file_index].block_type == MFS_BLOCK_TYPE_FILE) {
    /* OK to delete */
  }
  else if (mfs_file_system[file_index].block_type == MFS_BLOCK_TYPE_DIR) {
    /* first verify whether dir is actually empty */
    if (mfs_file_system[file_index].u.dir_data.num_entries - mfs_file_system[file_index].u.dir_data.num_deleted != 2) {
      /* dir is not empty so cannot delete */
      return 0;
    }
  }
  else { /* don't know what this is; cannot delete */
    return 0;
  }
  /* at this point we know that it is OK to delete */

  current_block = file_index;
  while((next_block = mfs_file_system[current_block].next_block) != 0) {
    mfs_file_system[current_block].block_type = MFS_BLOCK_TYPE_EMPTY;
    current_block = next_block;
  }
  mfs_file_system[current_block].block_type = MFS_BLOCK_TYPE_EMPTY;
  move_to_free_list(file_index, current_block);
  return 1;
}

/**
 * delete a file
 * @param filename is the name of the file to be deleted
 * delete the data blocks corresponding to the file and then delete the
 * file entry from its directory
 * @return 1 on success, 0 on failure
 * delete will not work on a directory unless the directory is empty
 */
int mfs_delete_file (char *filename) {
  int dir_block;
  int dir_index;
  int entry_index;
  int first_dir_block;
  int reuse_block = -1;
  int reuse_index = -1;

  if (!get_dir_ent(filename, &dir_block, &dir_index, &reuse_block, &reuse_index)) {
    /* file does not exist */
    return 0 ; /* cannot delete file if it does not exist */
  }
  entry_index = mfs_file_system[dir_block].u.dir_data.dir_ent[dir_index].index;
  if (delete_data_in_file(entry_index)) {
    /* now delete the file entry from the directory */
    mfs_file_system[dir_block].u.dir_data.dir_ent[dir_index].deleted = 'y';
    mfs_file_system[dir_block].u.dir_data.num_deleted += 1;
    first_dir_block = get_first_dir_block(dir_block);
    if (dir_block != first_dir_block)
      mfs_file_system[first_dir_block].u.dir_data.num_deleted += 1;
  }
  return 1;
}

/**
 * create a new empty directory inside the current directory
 * @param newdir is the name of the directory
 * @return index of new directory in file system if success, 0 if failure
 */
int mfs_create_dir(char *newdir) {
  return create_file(newdir, MFS_BLOCK_TYPE_DIR);
}

/**
 * delete the directory named newdir if it exists, and is empty
 * return 1 on success, 0 on failure
 * cannot delete . or ..
 */
int mfs_delete_dir (char *newdir) {
  if (!strcmp(newdir,"..") || !strcmp(newdir,"."))
    return 0;
  return mfs_delete_file(newdir);
}

/**
 * rename from_file to to_file
 * works for dirs as well as files
 * cannot rename to something that already exists
 * @param from_file
 * @param to_file
 * @return 1 on success, 0 on failure
 */
int mfs_rename_file(char *from_file, char *to_file) {
  int from_dir_block;
  int to_dir_block;
  int from_dir_index;
  int to_dir_index;
  int reuse_block = -1;
  int reuse_index = -1;
  if (get_dir_ent(from_file, &from_dir_block, &from_dir_index, &reuse_block, &reuse_index) &&
      !get_dir_ent(to_file, &to_dir_block, &to_dir_index, &reuse_block, &reuse_index)) {
    set_filename(mfs_file_system[from_dir_block].u.dir_data.dir_ent[from_dir_index].name, get_basename(to_file));
    return 1;
  }
  return 0;
}

/**
 * check if a file exists
 * @param filename is the name of the file
 * @return 0 if filename is not a file in the current directory
 * @return 1 if filename is a file in the current directory
 * @return 2 if filename is a directory in the current directory
 */
int mfs_exists_file(char *filename) {
  int dir_block;
  int dir_index;
  int file_block;
  int reuse_block = -1;
  int reuse_index = -1;
  if (get_dir_ent(filename, &dir_block, &dir_index, &reuse_block, &reuse_index)) {
    file_block = mfs_file_system[dir_block].u.dir_data.dir_ent[dir_index].index;
    if (mfs_file_system[file_block].block_type == MFS_BLOCK_TYPE_DIR)
      return 2;
    else if (mfs_file_system[file_block].block_type == MFS_BLOCK_TYPE_FILE)
      return 1;
    else return 0;
  }
  return 0;
}

/**
 * get the name of the current directory
 * @param dirname =  pre_allocated buffer of at least MFS_MAX_FILENAME_SIZE+1 chars
 * The directory name is copied to this buffer
 * @return 1 if success, 0 if failure
 */
int mfs_get_current_dir_name(char *dirname){
  int dir_block;
  int dir_index;
  int file_block;

  file_block = mfs_current_dir;
  if (file_block == 0) {
     strcpy(dirname, "/");
     return 1;
  }
  if(!get_dir_ent_by_index(file_block, &dir_block, &dir_index)) {
     return 0; /* cannot find current dir in its parent */
  }
  strcpy(dirname, mfs_file_system[dir_block].u.dir_data.dir_ent[dir_index].name);
  return 1;
}

/**
 * get the number of used blocks and the number of free blocks in the file system through pointers
 * @param num_blocks_used
 * @param num_blocks_free
 * the return value is  1 (for success) and 0 for failure to obtain the numbers
 */
int mfs_get_usage(int *num_blocks_used, int *num_blocks_free) {
  int i;
  *num_blocks_used = 0;
  *num_blocks_free = 0;
  for ( i = 0; i < mfs_max_file_blocks; i++) {
    if (mfs_file_system[i].block_type == MFS_BLOCK_TYPE_EMPTY)
      *num_blocks_free += 1;
    else
      *num_blocks_used += 1;
  }
  return 1;
}


/**
 * get the first available/free block
 * @return the index of the first free entry in the mfs_open_files array
 * if there is no free entry, returns -1
 */
static int get_first_free_ftab_index() {
  int i;
  for (i=0; i < MFS_MAX_OPEN_FILES; i++) {
    if (mfs_open_files[i].mode == MFS_MODE_FREE)
      return i;
  }
  return -1;
}

/**
 * open a directory for reading
 * each subsequent call to mfs_dir_read() returns one directory entry until
 * end of directory
 * @param dirname is the name of the directory to open
 * @return index of dir in array mfs_open_files or -1
 */
int mfs_dir_open(const char *dirname) {
  return mfs_file_open(dirname, MFS_MODE_READ);
}

/**
 * close a directory - same as closing a file
 * @param fd is the descriptor of the directory to close
 * @return  1 on success, 0 otherwise
 */
int mfs_dir_close(int fd) {
  return mfs_file_close(fd);
}

/**
 * read values from the next valid directory entry
 * The last 3 parameters are output values
 * @param fd is the file descriptor for an open directory file
 * @param filename is a pointer to the filename within the MFS itself
 * @param filesize is the size in bytes for a regular file or
 * the number of entries in a directory
 * @param filetype is MFS_BLOCK_TYPE_FILE or MFS_BLOCK_TYPE_DIR
 * @return 1 for success and 0 for failure or end of dir
 */
int mfs_dir_read(int fd, char **filename, int *filesize, int *filetype) {
  int numentriesleft =
    mfs_file_system[mfs_open_files[fd].first_block].u.dir_data.num_entries;
  int dir_block = mfs_open_files[fd].current_block;
  int dir_index = mfs_open_files[fd].offset;
  int direntry_block;

  numentriesleft -= dir_index;
/* now get dir_index modulo MFS_MAX_LOCAL_ENT -> current_block is the correct block but dir_index is the number of entries processed so far in all the blocks so it can be arbitrarily large */

  while(dir_index > MFS_MAX_LOCAL_ENT)
    dir_index -= MFS_MAX_LOCAL_ENT;
  while (numentriesleft > 0) {
    if (dir_index == MFS_MAX_LOCAL_ENT) { /* move to the next dir block */
      dir_index = 0;
      dir_block = mfs_file_system[dir_block].next_block;
      mfs_open_files[fd].current_block = dir_block;
    }
    if (mfs_file_system[dir_block].u.dir_data.dir_ent[dir_index].deleted
	!= 'y' ) {
      /* found a valid entry */

      *filename =
	mfs_file_system[dir_block].u.dir_data.dir_ent[dir_index].name;
      direntry_block =
	mfs_file_system[dir_block].u.dir_data.dir_ent[dir_index].index;
      *filetype = mfs_file_system[direntry_block].block_type;
      if (*filetype == MFS_BLOCK_TYPE_DIR) {
	*filesize =
	  mfs_file_system[direntry_block].u.dir_data.num_entries
	  - mfs_file_system[direntry_block].u.dir_data.num_deleted;
      }
      else {
	*filesize = mfs_file_system[direntry_block].block_size;
      }
      mfs_open_files[fd].offset +=1;
      return 1;
    }
    dir_index += 1;
    mfs_open_files[fd].offset += 1;
    numentriesleft--;
  }

  return 0; /* nothing left to read */
}

/**
 * open a file
 * @param filename is the name of the file to open
 * @param mode is MFS_MODE_READ or MFS_MODE_WRITE or MFS_MODE_CREATE
 * this function should be used for FILEs and not DIRs
 * no error checking (is this FILE and not DIR?) is done for MFS_MODE_READ
 * MFS_MODE_CREATE automatically creates a FILE and not a DIR
 * MFS_MODE_WRITE fails if the specified file is a DIR
 * @return index of file in array mfs_open_files or -1
 */
int mfs_file_open(const char *filename, int mode) {
  int dir_block;
  int dir_index;
  int current_index;
  int reuse_block = -1;
  int reuse_index = -1;

  if (mfs_num_open_files >= MFS_MAX_OPEN_FILES) {/* cannot open any more files */
    return -1;
  }
  if (mode == MFS_MODE_READ || mode == MFS_MODE_WRITE) { /* look for existing file */
    if (get_dir_ent(filename, &dir_block, &dir_index, &reuse_block, &reuse_index)) { /* found it */
      if (mode == MFS_MODE_WRITE && mfs_file_system[mfs_file_system[dir_block].u.dir_data.dir_ent[dir_index].index].block_type != MFS_BLOCK_TYPE_FILE) {
	/* cannot open anything other than FILE for write */
	return -1;
      }
      mfs_num_open_files++;
      current_index = get_first_free_ftab_index();
      mfs_open_files[current_index].first_block = mfs_file_system[dir_block].u.dir_data.dir_ent[dir_index].index;
      mfs_open_files[current_index].current_block = mfs_open_files[current_index].first_block;
      mfs_open_files[current_index].mode = mode;
      mfs_open_files[current_index].offset = 0;
      return current_index;
    }
    else {
       //file/dir not found, open it in create mode
       if (mode == MFS_MODE_WRITE)
          mode = MFS_MODE_CREATE;
    }
  }

  if (mode == MFS_MODE_CREATE) { /* create a new file */
     dir_block = create_file(filename, MFS_BLOCK_TYPE_FILE);
    if (dir_block == 0) { /* failed to create the file */
      return -1;
    }
    mfs_num_open_files++;
    current_index = get_first_free_ftab_index();
    mfs_open_files[current_index].first_block = dir_block;
    mfs_open_files[current_index].current_block = dir_block;
    mfs_open_files[current_index].mode = MFS_MODE_WRITE;
    mfs_open_files[current_index].offset = 0;
    return current_index;
  }
  return -1;
}

/**
 * read characters to a file
 * @param fd is a descriptor for the file from which the characters are read
 * @param buf is a pre allocated buffer that will contain the read characters
 * @param buflen is the number of characters from buf to be read
 * fd should be a valid index in mfs_open_files array
 * Works only if fd points to a file and not a dir
 * buf should be a pointer to a pre-allocated buffer of size buflen or more
 * buflen chars are read and placed in buf
 * if fewer than buflen chars are available then only that many chars are read
 * @return num bytes read or 0 for error=no bytes read
*/
int mfs_file_read(int fd, char *buf, int buflen) {
  int num_read = 0;
  char *from_ptr = (char *) &(mfs_file_system[mfs_open_files[fd].current_block].u.block_data[mfs_open_files[fd].offset]);
  int num_left ;
  num_left =  mfs_file_system[mfs_open_files[fd].current_block].block_size ;
  if (num_left > MFS_BLOCK_DATA_SIZE)
    num_left = MFS_BLOCK_DATA_SIZE;
  num_left -=  mfs_open_files[fd].offset ;
  while (buflen > 0) {
    if (num_left == 0) { /* see if there is a next_block */
      int next_block = mfs_file_system[mfs_open_files[fd].current_block].next_block;
      if (next_block == 0) { /* nothing more to read */
	break;
      }
      if (mfs_file_system[next_block].block_size == 0) { /* nothing more to read */
	break;
      }
      from_ptr = (char *) &(mfs_file_system[next_block].u.block_data[0]);
      num_left = mfs_file_system[next_block].block_size;
      mfs_open_files[fd].current_block = next_block;
      mfs_open_files[fd].offset = 0;
    }

    *buf = *from_ptr;
    buf++;
    from_ptr++;
    mfs_open_files[fd].offset += 1;
    num_read++;
    num_left--;
    buflen--;
  }
  return num_read;
}

/**
 * write characters to a file
 * @param fd is a descriptor for the file to which the characters are written
 * @param buf is a buffer containing the characters to be written out
 * @param buflen is the number of characters from buf to be written out
 * fd should be a valid index in mfs_open_files array
 * buf should be a pointer to a pre-allocated buffer of size buflen or more
 * buflen chars are read from buf and written to 1 or more blocks of the file
 * @return 1 for success or 0 for error=unable to write to file
*/
int mfs_file_write (int fd, const char *buf, int buflen) {
  char *to_ptr = (char *) &(mfs_file_system[mfs_open_files[fd].current_block].u.block_data[mfs_open_files[fd].offset]);
  int num_left = MFS_BLOCK_DATA_SIZE - mfs_open_files[fd].offset;

  while (buflen > 0) {
    if (num_left == 0) { /* create next_block */
      int new_block;
      /* create a new file block linked from this one */
      if (get_next_free_block(&new_block)) { /* found a free block */
	mfs_file_system[new_block].prev_block = mfs_open_files[fd].current_block;
	mfs_file_system[new_block].next_block = 0;
	mfs_file_system[new_block].block_type = MFS_BLOCK_TYPE_FILE;
	mfs_file_system[new_block].block_size = 0;
	mfs_file_system[mfs_open_files[fd].current_block].next_block = new_block;
	mfs_open_files[fd].current_block = new_block;
	mfs_open_files[fd].offset = 0;
      }
      else { /* no space for new block  - return failure */
	return 0;
      }

      to_ptr = (char *) &(mfs_file_system[new_block].u.block_data[0]);
      num_left = MFS_BLOCK_DATA_SIZE;
    }

    *to_ptr = *buf;
    buf++;
    to_ptr++;
    mfs_open_files[fd].offset += 1;
    num_left--;
    mfs_file_system[mfs_open_files[fd].current_block].block_size +=1;
    if (mfs_open_files[fd].current_block != mfs_open_files[fd].first_block)
      mfs_file_system[mfs_open_files[fd].first_block].block_size += 1;
    buflen--;

  }
  return 1;
}

/**
 * close an open file and
 * recover the file table entry in mfs_open_files corresponding to the fd
 * if the fd is not valid, return 0
 * fd is not valid if the index in mfs_open_files is out of range, or
 * if the corresponding entry is not an open file
 * @param fd is the file descriptor for the file to be closed
 * @return 1 on success, 0 otherwise
 */
int mfs_file_close(int fd) {
  if (fd <0 || fd >= MFS_MAX_OPEN_FILES)
    return 0;
  if (mfs_open_files[fd].mode != MFS_MODE_FREE) {
    mfs_open_files[fd].mode = MFS_MODE_FREE;
    mfs_num_open_files--;
    return 1;
  }
  return 0;
}

/**
 * seek to a given offset within the file
 * @param fd should be a valid file descriptor for an open file
 * @param whence is one of MFS_SEEK_SET, MFS_SEEK_CUR or MFS_SEEK_END
 * @param offset is the offset from the beginning, end or current position as specified by the whence parameter
 * if MFS_SEEK_END is specified, the offset can be either 0 or negative
 * otherwise offset should be positive or 0
 * it is an error to seek before beginning of file or after the end of file
 * @return -1 on failure, value of offset from beginning of file on success
 */
long mfs_file_lseek(int fd, long offset, int whence) {
  long local_offset;
  unsigned int local_block;
  if (fd <0 || fd >= MFS_MAX_OPEN_FILES || mfs_open_files[fd].mode == MFS_MODE_FREE)
    return -1;
  /* calculate value of offset from the beginning of the file */
  if (whence == MFS_SEEK_SET || whence == MFS_SEEK_CUR) {
    if (whence == MFS_SEEK_CUR) {
      /* add the size of all the previous blocks if any */
      local_block = mfs_open_files[fd].first_block;
      while (mfs_open_files[fd].current_block != local_block) {
        local_block = mfs_file_system[local_block].next_block;
        offset += MFS_BLOCK_DATA_SIZE;
      }
      /* add the offset within the current block */
      offset += mfs_open_files[fd].offset;
    } else {
      /* nothing to do here - offset is already calculated from the beginning of the file */
    }
    if (offset >= mfs_file_system[mfs_open_files[fd].first_block].block_size) { /* attempting to seek beyond end of file */
      return -1;
    }
  }
  else { /* whence == MFS_SEEK_END */
    if (offset > 0) { /* cannot seek beyond end of file */
      return -1;
    }
    else if (offset == 0) { /* return file size */
      return (mfs_file_system[mfs_open_files[fd].first_block].block_size);
    }
    else {
      offset += mfs_file_system[mfs_open_files[fd].first_block].block_size;
    }
  }
  /* at this point offset is a positive value, guaranteed to be within the file
   */
  local_offset = offset;
  local_block = mfs_open_files[fd].first_block;
  while(local_offset >= MFS_BLOCK_DATA_SIZE) {
    local_block = mfs_file_system[local_block].next_block;
    local_offset -= MFS_BLOCK_DATA_SIZE;
  }
  mfs_open_files[fd].current_block = local_block;
  mfs_open_files[fd].offset = local_offset;
  return offset;
}








