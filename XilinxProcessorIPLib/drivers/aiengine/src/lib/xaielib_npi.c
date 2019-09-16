/*******************************************************************************
*
* Copyright (C) 2019 Xilinx, Inc.  All rights reserved.
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
*******************************************************************************/

/******************************************************************************/
/**
* @file xaielib_npi.c
* @{
*
* This file contains routines for NPI module
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who     Date     Changes
* ----- ------  -------- -----------------------------------------------------
* 1.0  Jubaer  03/08/2019  Initial creation
* 1.1  Hyun    04/04/2019  Add the unlock and lock sequences
* 1.2  Wendy   09/15/2019  Remove AIE array reset and shim reset implementation
* </pre>
*
*******************************************************************************/

/***************************** Include Files **********************************/
#include "xaiegbl.h"
#include "xaiegbl_defs.h"
#include "xaiegbl_reginit.h"
#include "xaielib_npi.h"

/***************************** Constant Definitions ***************************/
/***************************** Macro Definitions ******************************/
/************************** Variable Definitions ******************************/
/************************** Function Definitions ******************************/
/*****************************************************************************/
/**
*
* This API is used to assert shim reset from NPI.
*
* @param	Reset - Reset/Unreset the Shim Tile (1-Reset,0-Unreset).
*
* @return	XAIE_SUCCESS if successful, else XAIE_FAILURE.
*
* @note		None.
*
*******************************************************************************/
u8 XAieLib_NpiShimReset(u8 Reset)
{
	/* Operation not supported */
	(void)Reset;
	return XAIE_FAILURE;
}

/*****************************************************************************/
/**
*
* This API is used to assert AIE array reset from NPI.
*
* @param	Reset - Reset/Unreset the AIE array.
*
* @return	XAIE_SUCCESS if successful, else XAIE_FAILURE.
*
* @note		None.
*
*******************************************************************************/
u8 XAieLib_NpiAieArrayReset(u8 Reset)
{
	/* Operation not supported */
	(void)Reset;
	return XAIE_FAILURE;
}

/** @} */
