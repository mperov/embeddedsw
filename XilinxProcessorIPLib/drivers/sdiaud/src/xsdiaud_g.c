
/*******************************************************************
*
* CAUTION: This file is automatically generated by HSI.
* Version: 2018.3.0
* DO NOT EDIT.
*
* Copyright (C) 2010-2018 Xilinx, Inc. All Rights Reserved.*
*Permission is hereby granted, free of charge, to any person obtaining a copy
*of this software and associated documentation files (the Software), to deal
*in the Software without restriction, including without limitation the rights
*to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*copies of the Software, and to permit persons to whom the Software is
*furnished to do so, subject to the following conditions:
*
*The above copyright notice and this permission notice shall be included in
*all copies or substantial portions of the Software.
*
*THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
*THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*SOFTWARE.
*
*
*

*
* Description: Driver configuration
*
*******************************************************************/

#include "xparameters.h"
#include "xsdiaud.h"

/*
* The configuration table for devices
*/

XSdiAud_Config XSdiAud_ConfigTable[XPAR_XSDIAUD_NUM_INSTANCES] =
{
	{
		XPAR_SDI_RX_HIER_V_UHDSDI_AUDIO_EXTRACT_DEVICE_ID,
		XPAR_SDI_RX_HIER_V_UHDSDI_AUDIO_EXTRACT_BASEADDR,
		XPAR_SDI_RX_HIER_V_UHDSDI_AUDIO_EXTRACT_AUDIO_FUNCTION,
		XPAR_SDI_RX_HIER_V_UHDSDI_AUDIO_EXTRACT_LINE_RATE,
		XPAR_SDI_RX_HIER_V_UHDSDI_AUDIO_EXTRACT_MAX_AUDIO_CHANNELS
	},
	{
		XPAR_SDI_TX_HIER_V_UHDSDI_AUDIO_EMBED_DEVICE_ID,
		XPAR_SDI_TX_HIER_V_UHDSDI_AUDIO_EMBED_BASEADDR,
		XPAR_SDI_TX_HIER_V_UHDSDI_AUDIO_EMBED_AUDIO_FUNCTION,
		XPAR_SDI_TX_HIER_V_UHDSDI_AUDIO_EMBED_LINE_RATE,
		XPAR_SDI_TX_HIER_V_UHDSDI_AUDIO_EMBED_MAX_AUDIO_CHANNELS
	}
};
