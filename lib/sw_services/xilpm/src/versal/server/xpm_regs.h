/******************************************************************************
*
* Copyright (C) 2018-2020 Xilinx, Inc.  All rights reserved.
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
* Naming Convention: <MODULE>_<REGISTER>[_<FIELD>[_<DESC>]]
*     <MODULE>       Module name (e.g. can or usb)
*     <REGISTER>     Register within the current module
*     [_<FIELD>]     Bit field within a register
*     [_<DESC>]      Type of bit field define:
*         SHIFT:     Least significant bit for the field
*         WIDTH:     Size of field in bites
*         MASK:      A masking over a range of bits or a bit to
*                    be used for setting or clearing
*
******************************************************************************/

#ifndef XPM_REGS_H
#define XPM_REGS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Base Addresses
 */
#define PMC_GLOBAL_BASEADDR					(0xF1110000U)
#define CPM_CRCPM_BASEADDR					(0xFCA00000U)
#define PCIEA_ATTRIB_0_BASEADDR					(0xFCA50000U)
#define PCIEA_ATTRIB_1_BASEADDR					(0xFCA60000U)
#define CRL_BASEADDR						(0xFF5E0000U)
#define PMC_TAP_BASEADDR					(0xF11A0000U)
#define NPI_BASEADDR						(0xF6000000U)
#define XRAM_SLCR_BASEADDR					(0xFF950000U)

/**
 * PMC Global module
 */
#define DOMAIN_ISO_CTRL_OFFSET					(0x10000U)
#define PMC_GLOBAL_DOMAIN_ISO_CONTROL				( ( PMC_GLOBAL_BASEADDR ) + DOMAIN_ISO_CTRL_OFFSET )
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCAUX_VCCRAM_SHIFT		(18U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCAUX_VCCRAM_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCAUX_VCCRAM_MASK		(0x00040000U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCRAM_SOC_SHIFT		(17U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCRAM_SOC_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCRAM_SOC_MASK		(0x00020000U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCAUX_SOC_SHIFT		(16U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCAUX_SOC_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCAUX_SOC_MASK		(0x00010000U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PL_SOC_SHIFT		(15U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PL_SOC_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PL_SOC_MASK			(0x00008000U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_SOC_SHIFT		(14U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_SOC_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_SOC_MASK		(0x00004000U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_SOC_NPI_SHIFT		(13U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_SOC_NPI_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_SOC_NPI_MASK		(0x00002000U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_SHIFT		(12U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_MASK			(0x00001000U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_TEST_SHIFT		(11U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_TEST_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_TEST_MASK		(0x00000800U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_CFRAME_SHIFT		(10U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_CFRAME_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_CFRAME_MASK		(0x00000400U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_LPD_SHIFT		(9U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_LPD_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_LPD_MASK		(0x00000200U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_LPD_DFX_SHIFT		(8U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_LPD_DFX_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_LPD_DFX_MASK		(0x00000100U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_SOC_SHIFT		(7U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_SOC_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_SOC_MASK		(0x00000080U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_PL_SHIFT		(6U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_PL_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_PL_MASK			(0x00000040U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_PL_TEST_SHIFT		(5U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_PL_TEST_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_PL_TEST_MASK		(0x00000020U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_CPM_SHIFT		(4U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_CPM_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_CPM_MASK		(0x00000010U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_CPM_DFX_SHIFT		(3U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_CPM_DFX_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_CPM_DFX_MASK		(0x00000008U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_SOC_SHIFT		(2U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_SOC_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_SOC_MASK		(0x00000004U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_PL_SHIFT		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_PL_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_PL_MASK			(0x00000002U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_PL_TEST_SHIFT		(0U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_PL_TEST_WIDTH		(1U)
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_PL_TEST_MASK		(0x00000001U)

#define PWR_SUPPLY_STATUS_OFFSET				(0x10CU)
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_RAM_MASK		(0x00000080U)
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_PL_MASK		(0x00000040U)
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCAUX_MASK		(0x00000020U)
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_SOC_MASK		(0x00000010U)
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_LPD_MASK		(0x00000008U)
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_FPD_MASK		(0x00000004U)
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_PMC_MASK		(0x00000002U)
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCAUX_PMC_MASK		(0x00000001U)

#define PMC_GLOBAL_SSIT_NOC_ID_OFFSET				(0x00000950U)
#define PMC_GLOBAL_SSIT_NOC_ID_SWITCHID_WIDTH			(13U)
#define PMC_GLOBAL_SSIT_NOC_ID_SWITCHID_MASK			(0x00003FFFU)

#define CPM_PCSR_HOLDSTATE_MASK					(0x00000080U)
#define CPM_PCSR_INITSTATE_MASK					(0x00000040U)

#define EFUSE_CACHE_MISC_CTRL_OFFSET				(0x000000A0U)
#define EFUSE_CACHE_MISC_CTRL_LBIST_EN_MASK			(0x00004000U)
#define EFUSE_CACHE_TRIM_CFRM_VGG_0_OFFSET			(0x000001B4U)
#define EFUSE_CACHE_TRIM_CFRM_VGG_1_OFFSET			(0x000001B8U)
#define EFUSE_CACHE_TRIM_CFRM_VGG_2_OFFSET			(0x000001BCU)
#define EFUSE_CACHE_TRIM_CRAM_OFFSET				(0x000001C0U)
#define EFUSE_CACHE_TRIM_BRAM_OFFSET				(0x00000098U)
#define EFUSE_CACHE_TRIM_URAM_OFFSET				(0x0000009CU)
#define EFUSE_CACHE_BISR_RSVD_0_OFFSET				(0x00000300U)
#define EFUSE_CACHE_TBITS1_BISR_RSVD_OFFSET			(0x00000400U)
#define EFUSE_CACHE_TBITS2_BISR_RSVD_OFFSET			(0x00000800U)
#define EFUSE_CACHE_TRIM_AMS_3_OFFSET				(0X00000200U)
#define EFUSE_CACHE_TRIM_AMS_3_TSENS_SLOPE_5_0_SHIFT		(9U)
#define EFUSE_CACHE_TRIM_AMS_3_TSENS_SLOPE_5_0_MASK		(0X00007E00U)
#define EFUSE_CACHE_TRIM_AMS_3_TSENS_INT_OFFSET_5_0_SHIFT	(3U)
#define EFUSE_CACHE_TRIM_AMS_3_TSENS_INT_OFFSET_5_0_MASK	(0X000001F8U)
#define EFUSE_CACHE_TRIM_AMS_3_TSENS_DELTA_16_0_SHIFT		(15U)
#define EFUSE_CACHE_TRIM_AMS_3_TSENS_DELTA_16_0_MASK		(0Xffff8000U)
#define EFUSE_CACHE_TRIM_AMS_4_OFFSET				(0x00000190U)
#define EFUSE_CACHE_TRIM_AMS_11_OFFSET				(0X000001ACU)
#define EFUSE_CACHE_TRIM_AMS_11_IXPCM_PROCESS_15_0_SHIFT	(15U)
#define EFUSE_CACHE_TRIM_AMS_11_IXPCM_PROCESS_15_0_MASK		(0X7FFF8000U)
#define EFUSE_CACHE_TRIM_AMS_11_RES_PROCESS_0_SHIFT		(31U)
#define EFUSE_CACHE_TRIM_AMS_11_RES_PROCESS_0_MASK		(0X80000000U)
#define EFUSE_CACHE_TRIM_AMS_12_OFFSET				(0X000001B0U)
#define EFUSE_CACHE_TRIM_AMS_12_BJT_PROCESS_3_0_SHIFT		(6U)
#define EFUSE_CACHE_TRIM_AMS_12_BJT_PROCESS_3_0_MASK		(0X000003C0U)
#define EFUSE_CACHE_TRIM_AMS_12_RES_PROCESS_6_1_SHIFT		(0U)
#define EFUSE_CACHE_TRIM_AMS_12_RES_PROCESS_6_1_MASK		(0X0000003FU)
#define EFUSE_CACHE_TRIM_AMS_12_TSENS_EXT_OFFSET_5_0_SHIFT	(10U)
#define EFUSE_CACHE_TRIM_AMS_12_TSENS_EXT_OFFSET_5_0_MASK	(0X0000FC00U)
#define EFUSE_CACHE_TRIM_AMS_12_SHARED_SPARE_1_0_SHIFT		(16U)
#define EFUSE_CACHE_TRIM_AMS_12_SHARED_SPARE_1_0_MASK		(0X00030000U)
#define EFUSE_CACHE_TRIM_AMS_12_SHARED_SPARE_14_2_SHIFT		(18U)
#define EFUSE_CACHE_TRIM_AMS_12_SHARED_SPARE_14_2_MASK		(0X7ffc0000U)
#define EFUSE_CACHE_TRIM_AMS_12_SHARED_SPARE_2_SHIFT		(18U)
#define EFUSE_CACHE_TRIM_AMS_12_SHARED_SPARE_2_MASK		(0X00040000U)
#define EFUSE_CACHE_TRIM_AMS_12_SHARED_SPARE_6_SHIFT		(22U)
#define EFUSE_CACHE_TRIM_AMS_12_SHARED_SPARE_6_MASK		(0X00400000U)
#define EFUSE_CACHE_TRIM_AMS_12_SHARED_SPARE_4_3_SHIFT		(19U)
#define EFUSE_CACHE_TRIM_AMS_12_SHARED_SPARE_4_3_MASK		(0X00180000U)
#define EFUSE_CACHE_NIDB_0_OFFSET				(0x000001C4U)
#define EFUSE_CACHE_NIDB_0_NPI_BASE_1_SHIFT			(23U)
#define EFUSE_CACHE_NIDB_0_NPI_BASE_1_WIDTH			(9U)
#define EFUSE_CACHE_NIDB_0_NPI_BASE_1_MASK			(0xFF800000U)
#define EFUSE_CACHE_NIDB_0_NPI_OFFSET_1_SHIFT			(19U)
#define EFUSE_CACHE_NIDB_0_NPI_OFFSET_1_WIDTH			(4U)
#define EFUSE_CACHE_NIDB_0_NPI_OFFSET_1_MASK			(0x00780000U)
#define EFUSE_CACHE_NIDB_0_RDN_CNTRL_0_SHIFT			(13U)
#define EFUSE_CACHE_NIDB_0_RDN_CNTRL_0_WIDTH			(6U)
#define EFUSE_CACHE_NIDB_0_RDN_CNTRL_0_MASK			(0x0007E000U)
#define EFUSE_CACHE_NIDB_0_NPI_BASE_0_SHIFT			(4U)
#define EFUSE_CACHE_NIDB_0_NPI_BASE_0_WIDTH			(9U)
#define EFUSE_CACHE_NIDB_0_NPI_BASE_0_MASK			(0x00001FF0U)
#define EFUSE_CACHE_NIDB_0_NPI_OFFSET_0_SHIFT			(0U)
#define EFUSE_CACHE_NIDB_0_NPI_OFFSET_0_WIDTH			(4U)
#define EFUSE_CACHE_NIDB_0_NPI_OFFSET_0_MASK			(0x0000000FU)
#define EFUSE_CACHE_NIDB_1_OFFSET				(0x000001C8U)
#define EFUSE_CACHE_NIDB_1_NPI_BASE_3_SHIFT			(29U)
#define EFUSE_CACHE_NIDB_1_NPI_BASE_3_WIDTH			(3U)
#define EFUSE_CACHE_NIDB_1_NPI_BASE_3_MASK			(0xE0000000U)
#define EFUSE_CACHE_NIDB_1_NPI_OFFSET_3_SHIFT			(25U)
#define EFUSE_CACHE_NIDB_1_NPI_OFFSET_3_WIDTH			(4U)
#define EFUSE_CACHE_NIDB_1_NPI_OFFSET_3_MASK			(0x1E000000U)
#define EFUSE_CACHE_NIDB_1_RDN_CNTL_2_SHIFT			(19U)
#define EFUSE_CACHE_NIDB_1_RDN_CNTL_2_WIDTH			(6U)
#define EFUSE_CACHE_NIDB_1_RDN_CNTL_2_MASK			(0x01F80000U)
#define EFUSE_CACHE_NIDB_1_NPI_BASE_2_SHIFT			(10U)
#define EFUSE_CACHE_NIDB_1_NPI_BASE_2_WIDTH			(9U)
#define EFUSE_CACHE_NIDB_1_NPI_BASE_2_MASK			(0x0007FC00U)
#define EFUSE_CACHE_NIDB_1_NPI_OFFSET_2_SHIFT			(6U)
#define EFUSE_CACHE_NIDB_1_NPI_OFFSET_2_WIDTH			(4U)
#define EFUSE_CACHE_NIDB_1_NPI_OFFSET_2_MASK			(0x000003C0U)
#define EFUSE_CACHE_NIDB_1_RDN_CNTRL_1_SHIFT			(0U)
#define EFUSE_CACHE_NIDB_1_RDN_CNTRL_1_WIDTH			(6U)
#define EFUSE_CACHE_NIDB_1_RDN_CNTRL_1_MASK			(0x0000003FU)
#define EFUSE_CACHE_NIDB_2_OFFSET				(0x000001CCU)
#define EFUSE_CACHE_NIDB_2_RDN_CNTRL_4_SHIFT			(25U)
#define EFUSE_CACHE_NIDB_2_RDN_CNTRL_4_WIDTH			(6U)
#define EFUSE_CACHE_NIDB_2_RDN_CNTRL_4_MASK			(0x7E000000U)
#define EFUSE_CACHE_NIDB_2_NPI_BASE_4_SHIFT			(16U)
#define EFUSE_CACHE_NIDB_2_NPI_BASE_4_WIDTH			(9U)
#define EFUSE_CACHE_NIDB_2_NPI_BASE_4_MASK			(0x01FF0000U)
#define EFUSE_CACHE_NIDB_2_NPI_OFFSET_4_SHIFT			(12U)
#define EFUSE_CACHE_NIDB_2_NPI_OFFSET_4_WIDTH			(4U)
#define EFUSE_CACHE_NIDB_2_NPI_OFFSET_4_MASK			(0x0000F000U)
#define EFUSE_CACHE_NIDB_2_RDN_CNTL_3_SHIFT			(6U)
#define EFUSE_CACHE_NIDB_2_RDN_CNTL_3_WIDTH			(6U)
#define EFUSE_CACHE_NIDB_2_RDN_CNTL_3_MASK			(0x00000FC0U)
#define EFUSE_CACHE_NIDB_2_NPI_BASE_3_SHIFT			(0U)
#define EFUSE_CACHE_NIDB_2_NPI_BASE_3_WIDTH			(6U)
#define EFUSE_CACHE_NIDB_2_NPI_BASE_3_MASK			(0x0000003FU)

#define EFUSE_CONFIG0_OFFSET					(0x180U)
#define EFUSE_CONFIG0_OFFSET_MASK				(0x3fU)
#define EFUSE_CONFIG0_OFFSET_SHIFT				(0U)
#define EFUSE_CONFIG0_SLOPE_MASK				(0xfc0U)
#define EFUSE_CONFIG0_SLOPE_SHIFT				(6U)
#define EFUSE_CONFIG0_PROCESS_MASK				(0xffff0000U)
#define EFUSE_CONFIG0_DELTA_SHIFT				(12U)
#define EFUSE_CONFIG0_DELTA_MASK				(0x0000f000U)
#define EFUSE_CONFIG0_PROCESS_SHIFT				(16U)
#define EFUSE_CONFIG1_OFFSET					(0x184U)
#define EFUSE_CONFIG1_RESISTOR_MASK				(0x7fU)
#define EFUSE_CONFIG1_RESISTOR_SHIFT				(0U)
#define EFUSE_CONFIG1_BJT_OFFSET_MASK				(0x780U)
#define EFUSE_CONFIG1_BJT_OFFSET_SHIFT				(7U)
#define EFUSE_CONFIG1_EXT_OFFSET_MASK				(0x1f800U)
#define EFUSE_CONFIG1_EXT_OFFSET_SHIFT				(11U)
#define EFUSE_CONFIG1_ANA_SPARE_MASK				(0x00060000U)
#define EFUSE_CONFIG1_ANA_SPARE_SHIFT				(17U)
#define EFUSE_CONFIG1_DIG_SPARE_MASK				(0xfff80000U)
#define EFUSE_CONFIG1_DIG_SPARE_SHIFT				(19U)
#define CAL_SM_BIP_TSENS_OFFSET					(0x144U)
#define CAL_SM_BIP_TSENS_BIP_MASK				(0x00000001U)
#define CAL_SM_BIP_TSENS_BIP_SHIFT				(0U)
#define CAL_SM_BIP_TSENS_TSENS_MASK				(0x00000002U)
#define CAL_SM_BIP_TSENS_TSENS_SHIFT				(1U)
#define TSENS_BIAS_CTRL_OFFSET					(0x17CU)
#define TSENS_BIAS_VAL_MASK					(0x00000003U)
#define TSENS_BIAS_VAL_SHIFT					(0U)

#define DOMAIN_ISO_CTRL_OFFSET					(0x10000U)
#define PMC_GLOBAL_DOMAIN_ISO_CONTROL				( ( PMC_GLOBAL_BASEADDR ) + DOMAIN_ISO_CTRL_OFFSET )

#define PMC_GLOBAL_PERS_GLOB_GEN_STORAGE0			( ( PMC_GLOBAL_BASEADDR ) + 0x00000050U )

#define PMC_GLOBAL_PL_STATUS_OFFSET				(0x00000880U)
#define PMC_GLOBAL_PL_STATUS_POR_PL_B_MASK			(0x00000001U)

#define PMC_GLOBAL_PMC_GSW_ERR_OFFSET				(0x00000064U)
#define PMC_GLOBAL_PMC_GSW_ERR_CR_FLAG_SHIFT			(30U)

#define PMC_GLOBAL_ERR1_STATUS_OFFSET				(0x00020000U)
#define PMC_GLOBAL_ERR1_STATUS_CFU_MASK				(0x00000040U)
#define PMC_GLOBAL_ERR1_STATUS_CFRAME_MASK			(0x00000080U)
#define PMC_GLOBAL_ERR1_STATUS_DDRMC_MC_NCR_MASK		(0x00080000U)
#define PMC_GLOBAL_ERR1_STATUS_NOC_TYPE_1_NCR_MASK		(0x00002000U)

#define PMC_GLOBAL_ERR2_STATUS_OFFSET				(0x00020004U)
#define PMC_GLOBAL_ERR2_STATUS_CFI_MASK				(0x00020000U)
#define PMC_GLOBAL_ERR2_STATUS_CFRAME_SEU_CRC_MASK		(0x00040000U)
#define PMC_GLOBAL_ERR2_STATUS_CFRAME_SEU_ECC_MASK		(0x00080000U)

/**
 * PMC Global GIC Proxy Module
 */
#define PMC_GLOBAL_GIC_PROXY_BASE_OFFSET			(0x30000U)
#define GIC_PROXY_GROUP_OFFSET(g)				(0x14U * (g))

#define PMC_GLOBAL_GICP_IRQ_ENABLE_OFFSET			(0x300A8U)
#define PMC_GLOBAL_GICP_IRQ_DISABLE_OFFSET			(0x300ACU)

/**
 * GIC Proxy register offsets
 */
#define GIC_PROXY_IRQ_STATUS_OFFSET				(0x0U)
#define GIC_PROXY_IRQ_MASK_OFFSET				(0x4U)
#define GIC_PROXY_IRQ_ENABLE_OFFSET				(0x8U)
#define GIC_PROXY_IRQ_DISABLE_OFFSET				(0xCU)

#define GIC_PROXY_ALL_MASK					(0xFFFFFFFFU)
#define GICP3_CFU_MASK						(0x01000000U)
#define GICP3_CFRAME_SEU_MASK					(0x02000000U)

/**
 * PMC IOU SLCR Module
 */
#define PMC_IOU_SLCR_SD0_DLL_DIV_MAP0_OFFSET			(0x00000458U)
#define PMC_IOU_SLCR_SD0_DLL_DIV_MAP1_OFFSET			(0x0000045CU)
#define PMC_IOU_SLCR_SD1_DLL_DIV_MAP0_OFFSET			(0x000004D8U)
#define PMC_IOU_SLCR_SD1_DLL_DIV_MAP1_OFFSET			(0x000004DCU)
#define PMC_IOU_SLCR_WPROT0_OFFSET				(0x00000828U)

/**
 * PSM Global Module
 */
#define PSM_GLOBAL_APU_POWER_STATUS_INIT_OFFSET			(0x00000008U)
#define PSM_GLOBAL_SCAN_CLEAR_FPD_OFFSET			(0x0000092CU)

#define PSM_GLOBAL_SCAN_CLEAR_TRIGGER				(0x1U)
#define PSM_GLOBAL_SCAN_CLEAR_DONE_STATUS			(0x2U)
#define PSM_GLOBAL_SCAN_CLEAR_PASS_STATUS			(0x4U)

#define PSM_GLOBAL_MBIST_RST_OFFSET				(0x00000900U)
#define PSM_GLOBAL_MBIST_PG_EN_OFFSET				(0x00000904U)
#define PSM_GLOBAL_MBIST_SETUP_OFFSET				(0x00000908U)
#define PSM_GLOBAL_MBIST_DONE_OFFSET				(0x00000910U)
#define PSM_GLOBAL_MBIST_GO_OFFSET				(0x00000914U)

#define PSM_GLOBAL_MBIST_RST_FPD_MASK				(0x0000001FU)
#define PSM_GLOBAL_MBIST_PG_EN_FPD_MASK				(0x0000001FU)
#define PSM_GLOBAL_MBIST_SETUP_FPD_MASK				(0x0000001FU)
#define PSM_GLOBAL_MBIST_DONE_FPD_MASK				(0x0000001FU)
#define PSM_GLOBAL_MBIST_GO_FPD_MASK				(0x0000001FU)

/**
 * LPD IOU SLCR Module
 */
#define LPD_IOU_SLCR_WPROT0_OFFSET				(0x00000728U)

/**
 * LPD SLCR Module
 */
#define LPD_SLCR_WPROT0_OFFSET					(0x00000000U)
#define LPD_SLCR_BISR_CACHE_DATA_0_OFFSET			(0x0000010CU)
#define LPD_SLCR_BISR_CACHE_CTRL_0_OFFSET			(0x00000100U)
#define LPD_SLCR_CACHE_CTRL_0_BISR_TRIGGER_MASK			(0x00000001U)
#define LPD_SLCR_BISR_CACHE_CTRL_1_OFFSET			(0x00000104U)
#define LPD_SLCR_CACHE_CTRL_1_PGEN0_MASK			(0x00000001U)
#define LPD_SLCR_CACHE_CTRL_1_PGEN1_MASK			(0x00000002U)
#define LPD_SLCR_BISR_CACHE_STATUS_OFFSET			(0x00000108U)
#define LPD_SLCR_BISR_PASS_GLOBAL_MASK				(0x8000000U)
#define LPD_SLCR_BISR_DONE_GLOBAL_MASK				(0x4000000U)
#define LPD_SLCR_BISR_PASS_1_MASK				(0x0000008U)
#define LPD_SLCR_BISR_DONE_1_MASK				(0x0000004U)
#define LPD_SLCR_BISR_PASS_0_MASK				(0x0000002U)
#define LPD_SLCR_BISR_DONE_0_MASK				(0x0000001U)

/**
 * Register: LPD_SLCR_SECURE
 */
#define LPD_SLCR_SECURE_WPROT0_OFFSET				(0x00000000U)
#define LPD_SLCR_SECURE_ADMA_0_OFFSET				(0x00000060U)

/**
 * FPD_SLCR Module
 */
#define FPD_SLCR_WPROT0_OFFSET					(0x00000000U)
#define FPD_SLCR_BISR_CACHE_DATA_0_OFFSET 			(0x0000040CU)
#define FPD_SLCR_BISR_CACHE_CTRL_0_OFFSET			(0x00000400U)
#define FPD_SLCR_CACHE_CTRL_0_BISR_TRIGGER_MASK			(0x00000001U)
#define FPD_SLCR_BISR_CACHE_CTRL_1_OFFSET			(0x00000404U)
#define FPD_SLCR_CACHE_CTRL_1_PGEN0_MASK			(0x00000001U)
#define FPD_SLCR_CACHE_CTRL_1_PGEN1_MASK			(0x00000002U)
#define FPD_SLCR_CACHE_CTRL_1_PGEN2_MASK			(0x00000004U)
#define FPD_SLCR_CACHE_CTRL_1_PGEN3_MASK			(0x00000008U)
#define FPD_SLCR_BISR_CACHE_STATUS_OFFSET			(0x00000408U)
#define FPD_SLCR_BISR_PASS_3_MASK				(0x0000200U)
#define FPD_SLCR_BISR_DONE_3_MASK				(0x0000100U)
#define FPD_SLCR_BISR_PASS_2_MASK				(0x0000080U)
#define FPD_SLCR_BISR_DONE_2_MASK				(0x0000040U)
#define FPD_SLCR_BISR_PASS_1_MASK				(0x0000020U)
#define FPD_SLCR_BISR_DONE_1_MASK				(0x0000010U)
#define FPD_SLCR_BISR_PASS_0_MASK				(0x0000008U)
#define FPD_SLCR_BISR_DONE_0_MASK				(0x0000004U)
#define FPD_SLCR_BISR_PASS_GLOBAL_MASK				(0x0000002U)
#define FPD_SLCR_BISR_DONE_GLOBAL_MASK				(0x0000001U)

#define APU_DUAL_RVBARADDR0L_OFFSET				(0x40U)
#define APU_DUAL_RVBARADDR0H_OFFSET				(0x44U)
#define APU_DUAL_RVBARADDR1L_OFFSET				(0x48U)
#define APU_DUAL_RVBARADDR1H_OFFSET				(0x4CU)

#define RPU_0_CFG_OFFSET					(0x00000100U)
#define RPU_1_CFG_OFFSET					(0x00000200U)
#define RPU_GLBL_CNTL_OFFSET					(0x00000000U)

#define CRL_RCLK_CTRL						(CRL_BASEADDR + 0x000001A0)
#define CRL_RCLK_CTRL_CLKACT_GEM_TSU_MASK			(0x1000)
#define CRL_RCLK_CTRL_CLKACT_GEM0_TXRX_MASK			(0x300)
#define CRL_RCLK_CTRL_CLKACT_GEM1_TXRX_MASK			(0xC00)

#define CRL_PSM_RST_MODE_OFFSET					(0x00000370U)

#define FPD_APU_PWRCTL_OFFSET					(0x00000090U)

#define RPU_0_PWRDWN_OFFSET					(0x00000108U)
#define RPU_1_PWRDWN_OFFSET					(0x00000208U)
#define RPU_ERR_INJ_OFFSET					(0x00000020U)

/**
 * AMS_ROOT Module
 */
#define AMS_ROOT_REG_PCSR_LOCK_OFFSET				(0x0000000CU)
#define AMS_ROOT_TOKEN_MNGR_OFFSET				(0x00000104U)
#define AMS_ROOT_TOKEN_MNGR_BYPASS_FPD_MASK			(0x00040000U)
#define AMS_ROOT_TOKEN_MNGR_BYPASS_LPD_MASK			(0x00080000U)
#define AMS_ROOT_TOKEN_MNGR_BYPASS_PL_MASK			(0x00100000U)

/**
 * CFU APB Module
 */
#define CFU_APB_CFU_FGCR_OFFSET					(0x00000018U)
#define CFU_APB_CFU_MASK_OFFSET					(0x00000028U)
#define CFU_APB_CFU_MASK_INIT_COMPLETE_ENABLE_MASK		(0x00000001U)
#define CFU_APB_CFU_STATUS_OFFSET				(0x00000100U)
#define CFU_APB_CFU_PROTECT_OFFSET				(0x00000014U)

/**
 * CPM PCSR Module
 */
#define CPM_PCSR_MASK_OFFSET					(0x00000000U)
#define CPM_PCSR_MASK_SCAN_CLEAR_TRIGGER_WEN_MASK		(0x00000800U)
#define CPM_PCSR_PCR_OFFSET					(0x00000004U)
#define CPM_PCSR_PCR_SCAN_CLEAR_TRIGGER_MASK			(0x00000800U)
#define CPM_PCSR_PSR_OFFSET					(0x00000008U)
#define CPM_PCSR_PSR_SCAN_CLEAR_DONE_MASK			(0x00000002U)
#define CPM_PCSR_PSR_SCAN_CLEAR_PASS_MASK			(0x00000004U)
#define CPM_PCSR_LOCK_OFFSET					(0x0000000CU)
#define CPM_PCSR_ECO_OFFSET					(0x00000020U)

/**
 * CPM CRCPM Module
 */
#define CPM_CRCPM_RST_CPI0					(CPM_CRCPM_BASEADDR + 0x00000324)
#define CPM_CRCPM_RST_CPI0_RESET_SHIFT				(0U)

#define CPM_CRCPM_RST_CPI1					(CPM_CRCPM_BASEADDR + 0x00000328)
#define CPM_CRCPM_RST_CPI1_RESET_SHIFT				(0U)

/**
 * CPM_SLCR Module
 */
#define CPM_SLCR_BISR_CACHE_DATA_0_OFFSET 			(0x000003F4U)
#define CPM_SLCR_BISR_CACHE_CTRL_OFFSET 			(0x000003F0U)
#define CPM_SLCR_BISR_CACHE_STATUS_OFFSET 			(0x000003ECU)
#define CPM_SLCR_BISR_CACHE_CTRL_CLR_MASK			(0x00000010U)
#define CPM_SLCR_BISR_CACHE_CTRL_TRIGGER_MASK			(0x00000001U)
#define CPM_SLCR_BISR_CACHE_STATUS_DONE_MASK			(0x00000001U)
#define CPM_SLCR_BISR_CACHE_STATUS_PASS_MASK			(0x00000002U)

/**
 * CPM5_SLCR Module
 */
#define CPM5_SLCR_WPROTS_OFFSET					(0x00000000U)
#define CPM5_SLCR_WPROTP_OFFSET					(0x00000004U)
#define CPM5_SLCR_BISR_CACHE_STATUS_OFFSET			(0x00000500U)
#define CPM5_SLCR_BISR_CACHE_STATUS_DONE_MASK			(0x00000001U)
#define CPM5_SLCR_BISR_CACHE_STATUS_PASS_MASK			(0x00000002U)
#define CPM5_SLCR_BISR_CACHE_CTRL_OFFSET 			(0x00000504U)
#define CPM5_SLCR_BISR_CACHE_CTRL_TRIGGER_MASK			(0x00000001U)
#define CPM5_SLCR_BISR_CACHE_CTRL_CLR_MASK			(0x00000010U)
#define CPM5_SLCR_BISR_CACHE_DATA_0_OFFSET			(0x00000508U)

/**
 * CPM_SLCR_SECURE Module
 */
#define CPM_SLCR_SECURE_WPROT0_OFFSET 				(0x00000000U)
#define CPM_SLCR_SECURE_OD_MBIST_RESET_N_OFFSET 		(0x00000420U)
#define CPM_SLCR_SECURE_OD_MBIST_PG_EN_OFFSET	 		(0x00000424U)
#define CPM_SLCR_SECURE_OD_MBIST_SETUP_OFFSET			(0x00000428U)
#define CPM_SLCR_SECURE_OD_MBIST_DONE_OFFSET			(0x0000042CU)
#define CPM_SLCR_SECURE_OD_MBIST_GO_OFFSET			(0x00000430U)

/**
 * CPM5_SLCR_SECURE Module
 */
#define CPM5_SLCR_SECURE_WPROTS_OFFSET				(0x00000000U)
#define CPM5_SLCR_SECURE_WPROTP_OFFSET				(0x00000004U)
#define CPM5_SLCR_SECURE_OD_MBIST_TRIGGER_OFFSET		(0x00000420U)
#define CPM5_SLCR_SECURE_OD_MBIST_TRIGGER_MASK			(0x0007FFFFU)
#define CPM5_SLCR_SECURE_OD_MBIST_DONE_OFFSET			(0x0000042CU)
#define CPM5_SLCR_SECURE_OD_MBIST_DONE_MASK			(0x0007FFFFU)
#define CPM5_SLCR_SECURE_OD_MBIST_PASSOUT_OFFSET		(0x00000430U)
#define CPM5_SLCR_SECURE_OD_MBIST_PASSOUT_MASK			(0x0007FFFFU)

/**
 * GTY PCSR Module
 */
#define GTY_PCSR_LOCK_OFFSET					(0x0000000CU)
#define GTY_PCSR_MASK_OFFSET					(0x00000000U)
#define GTY_PCSR_CONTROL_OFFSET					(0x00000004U)
#define GTY_PCSR_STATUS_OFFSET					(0x00000008U)
#define GTY_PCSR_INITCTRL_MASK					(0x01000000U)
#define GTY_PCSR_MEM_CLEAR_TRIGGER_MASK				(0x00040000U)
#define GTY_PCSR_BISR_TRIGGER_MASK				(0x20000000U)
#define GTY_PCSR_STATUS_MEM_CLEAR_DONE_MASK			(0x00000040U)
#define GTY_PCSR_STATUS_MEM_CLEAR_PASS_MASK			(0x00000080U)
#define GTY_PCSR_STATUS_BISR_DONE_MASK				(0x00080000U)
#define GTY_PCSR_STATUS_BISR_PASS_MASK				(0x00100000U)

/**
 * EFUSE CACHE Module
 */
#define EFUSE_CACHE_MISC_CTRL_OFFSET				(0x000000A0U)
#define EFUSE_CACHE_MISC_CTRL_LBIST_EN_MASK			(0x00004000U)
#define EFUSE_CACHE_TRIM_CFRM_VGG_0_OFFSET			(0x000001B4U)
#define EFUSE_CACHE_TRIM_CFRM_VGG_1_OFFSET			(0x000001B8U)
#define EFUSE_CACHE_TRIM_CFRM_VGG_2_OFFSET			(0x000001BCU)
#define EFUSE_CACHE_TRIM_CRAM_OFFSET				(0x000001C0U)
#define EFUSE_CACHE_TRIM_BRAM_OFFSET				(0x00000098U)
#define EFUSE_CACHE_TRIM_URAM_OFFSET				(0x0000009CU)
#define EFUSE_CACHE_BISR_RSVD_0_OFFSET				(0x00000300U)
#define EFUSE_CACHE_TBITS1_BISR_RSVD_OFFSET			(0x00000400U)
#define EFUSE_CACHE_TBITS2_BISR_RSVD_OFFSET			(0x00000800U)

/**
 * PCIe controller module
 */
#define PCIEA_ATTRIB_0_FABRICEN					( PCIEA_ATTRIB_0_BASEADDR + 0x00000E84 )
#define PCIEA_ATTRIB_0_FABRICEN_ATTR_SHIFT			(0U)

#define PCIEA_ATTRIB_1_FABRICEN					( PCIEA_ATTRIB_1_BASEADDR + 0x00000E84 )
#define PCIEA_ATTRIB_1_FABRICEN_ATTR_SHIFT			(0U)

/**
 * Register: PCSR_CONTROL
 */
#define NPI_PCSR_UNLOCK_VAL					(0xF9E8D7C6U)
#define NPI_PCSR_LOCK_OFFSET					(0x0000000CU)
#define NPI_PCSR_MASK_OFFSET					(0x00000000U)
#define NPI_PCSR_CONTROL_OFFSET					(0x00000004U)
#define NPI_PCSR_CONTROL_MEM_CLEAR_TRIGGER_MASK			(0x00040000U)
#define NPI_PCSR_CONTROL_ODISABLE_NPP_MASK			(0x00000008U)
#define NPI_PCSR_STATUS_OFFSET					(0x00000008U)
#define NPI_PCSR_STATUS_MEM_CLEAR_DONE_MASK			(0x00000040U)
#define NPI_PCSR_STATUS_MEM_CLEAR_PASS_MASK			(0x00000080U)
#define NPI_PCSR_CONTROL_PCOMPLETE_MASK				(0x00000001U)
#define NOC_DDRMC_UB_CLK_GATE_OFFSET				(0x0000024CU)
#define NOC_DDRMC_UB_CLK_GATE_BISR_EN_MASK			(0x00000040U)
#define NOC_DDRMC_UB_CLK_GATE_ILA_EN_MASK			(0x00000020U)
#define NPI_DDRMC_PSCR_CONTROL_UB_INITSTATE_MASK		(0x01000000U)

/**
 * DDRMC_UB Registers
 */
#define DDRMC_UB_PMC2UB_INTERRUPT_OFFSET			(0x228U)
#define DDRMC_UB_UB2PMC_ACK_OFFSET				(0x22CU)
#define DDRMC_UB_UB2PMC_DONE_OFFSET				(0x230U)
#define DDRMC_UB_PMC2UB_INTERRUPT_SPARE_0_MASK			BIT(2U)
#define DDRMC_UB_UB2PMC_ACK_SPARE_0_MASK			BIT(2U)
#define DDRMC_UB_UB2PMC_DONE_SPARE_0_MASK			BIT(2U)
#define DDRMC_UB_PMC2UB_INTERRUPT_SR_EXIT_MASK			BIT(1U)
#define DDRMC_UB_UB2PMC_ACK_SR_EXIT_MASK			BIT(1U)
#define DDRMC_UB_UB2PMC_DONE_SR_EXIT_MASK			BIT(1U)
#define DDRMC_UB_PCSR_CONTROL_PCOMPLETE_MASK			(0x1U)

/* Probe Counter Register related macros */
#define CORESIGHT_LPD_ATM_BASE					(0xF0980000U)
#define CORESIGHT_FPD_ATM_BASE					(0xF0B80000U)

#define PROBE_COUNTER_LAR_OFFSET				(0x0FB0U)
#define PROBE_COUNTER_LSR_OFFSET				(0x0FB4U)
#define PROBE_COUNTER_MAIN_CTL_OFFSET				(0x1008U)
#define PROBE_COUNTER_CFG_CTL_OFFSET				(0x100CU)
#define PROBE_COUNTER_STATE_PERIOD_OFFSET			(0x1024U)
#define PROBE_COUNTER_PORT_SEL_OFFSET				(0x1134U)
#define PROBE_COUNTER_SRC_OFFSET				(0x1138U)
#define PROBE_COUNTER_VAL_OFFSET				(0x113CU)

#define PROBE_COUNTER_FPD_RD_REQ_OFFSET				(0x800U)
#define PROBE_COUNTER_FPD_RD_RES_OFFSET				(0x000U)
#define PROBE_COUNTER_FPD_WR_REQ_OFFSET				(0xC00U)
#define PROBE_COUNTER_FPD_WR_RES_OFFSET				(0x400U)
#define PROBE_COUNTER_LPD_REQ_TYPE_OFFSET			(0x1000U)

/**
 * CRP_RESET_REASON
 */
#define CRP_RESET_REASON					(0xF1260220U)
#define CRP_RESET_REASON_SLR_SYS_MASK				(0x00000400U)
#define CRP_RESET_REASON_SW_SYS_MASK				(0x00000200U)
#define CRP_RESET_REASON_ERR_SYS_MASK				(0x00000100U)
#define CRP_RESET_REASON_DAP_SYS_MASK				(0x00000080U)
#define CRP_RESET_REASON_ERR_POR_MASK				(0x00000008U)
#define CRP_RESET_REASON_SLR_POR_MASK				(0x00000004U)
#define CRP_RESET_REASON_SW_POR_MASK				(0x00000002U)
#define CRP_RESET_REASON_EXTERNAL_POR_MASK			(0x00000001U)

/**
 * Definitions required from pmc_tap.h
 */
#define PMC_TAP_IDCODE						( ( PMC_TAP_BASEADDR ) + 0x00000000U )
#define PMC_TAP_VERSION						( ( PMC_TAP_BASEADDR ) + 0x00000004U )
#define PMC_TAP_VERSION_PLATFORM_SHIFT				(24U)
#define PMC_TAP_VERSION_PLATFORM_MASK				(0x0F000000U)
#define PMC_TAP_VERSION_PLATFORM_VERSION_SHIFT			(28U)
#define PMC_TAP_VERSION_PLATFORM_VERSION_MASK			(0xF0000000U)

/**
 * SLR TYPES
 */
#define PMC_TAP_SLR_TYPE_OFFSET					(0x00000024U)
#define PMC_TAP_SLR_TYPE_WIDTH					(0x00000002U)
#define PMC_TAP_SLR_TYPE_MASK					(0x00000007U)

#define XPPU_CTRL_OFFSET 					(0x0U)
#define XPPU_CTRL_ENABLE_SHIFT					(0U)
#define XPPU_CTRL_ENABLE_MASK					(0x1U)
#define XPPU_CTRL_MID_PARITY_EN_SHIFT				(1U)
#define XPPU_CTRL_MID_PARITY_EN_MASK				(0x2U)
#define XPPU_CTRL_APER_PARITY_EN_SHIFT				(2U)
#define XPPU_CTRL_APER_PARITY_EN_MASK				(0x4U)
#define XPPU_M_APERTURE_64KB_OFFSET				(0x44U)
#define XPPU_M_APERTURE_1MB_OFFSET				(0x48U)
#define XPPU_M_APERTURE_512MB_OFFSET				(0x4CU)
#define XPPU_BASE_64KB_OFFSET					(0x54U)
#define XPPU_BASE_1MB_OFFSET					(0x58U)
#define XPPU_BASE_512MB_OFFSET					(0x5CU)
#define XPPU_APERTURE_0_OFFSET					(0x1000U)
#define XPPU_APERTURE_384_OFFSET				(0x1600U)
#define XPPU_APERTURE_400_OFFSET				(0x1640U)
#define XPPU_APERTURE_PERMISSION_MASK				(0xFFFFFU)
#define XPPU_APERTURE_TRUSTZONE_OFFSET				(27U)
#define XPPU_APERTURE_TRUSTZONE_MASK				(0x8000000U)
#define XPPU_APERTURE_PARITY_SHIFT				(28U)
#define XPPU_APERTURE_PARITY_MASK				(0xF0000000U)
//for ES2
#define	XPPU_DYNAMIC_RECONFIG_APER_ADDR_OFFSET			(0x150U)
#define XPPU_DYNAMIC_RECONFIG_APER_PERM_OFFSET			(0x154U)
#define XPPU_DYNAMIC_RECONFIG_EN_OFFSET				(0xFCU)
//for ES1
#define XPPU_ENABLE_PERM_CHECK_REG00_OFFSET			(0x150U)


/**
 * OSPI Mux select related macros
 */
#define XPM_OSPI_MUX_SEL_OFFSET					(0x00000504U)
#define XPM_OSPI_MUX_SEL_MASK					(0x2U)
#define XPM_OSPI_MUX_SEL_SHIFT					(0x1U)

/**
 * USB PMU registers
 */
#define XPM_USB_CUR_PWR_OFFSET					(0x00000600U)
#define XPM_USB_PWR_REQ_OFFSET					(0x00000608U)
#define XPM_USB_PWR_MASK					(0x3U)

/**
 * IPI register masks
 */
#define IPI_PMC_ISR_ADDR					(0xFF320010U)
#define PSM_IPI_BIT						(0x1U)
#define PMC_IPI_MASK						(0x00000002U)
#define IPI_0_MASK						(0x00000004U)
#define IPI_1_MASK						(0x00000008U)
#define IPI_2_MASK						(0x00000010U)
#define IPI_3_MASK						(0x00000020U)
#define IPI_4_MASK						(0x00000040U)
#define IPI_5_MASK						(0x00000080U)
#define IPI_6_MASK						(0x00000200U)

/**
 * XRAM registers
 */
#define XRAM_SLCR_PCSR_MASK_OFFSET					(0x0000U)
#define XRAM_SLCR_PCSR_PCR_OFFSET					(0x0004U)
#define XRAM_SLCR_PCSR_ODISABLE_PL_AXI0_MASK		(0x00000004U)
#define XRAM_SLCR_PCSR_ODISABLE_PL_AXI1_MASK		(0x00000008U)
#define XRAM_SLCR_PCSR_ODISABLE_PL_AXI2_MASK		(0x00000010U)
#define XRAM_SLCR_PCSR_ODISABLE_PL_AXILITE_MASK		(0x00000020U)
#define XRAM_SLCR_PCSR_FABRICEN_MASK				(0x00000200U)
#define XRAM_MEM_CLEAR_TRIGGER_0_MASK				(0x00040000U)
#define XRAM_SLCR_PCSR_PSR_OFFSET					(0x0008U)
#define XRAM_SLCR_PCSR_PSR_MEM_CLEAR_DONE_0_MASK	(0x00000040U)
#define XRAM_SLCR_PCSR_PSR_MEM_CLEAR_DONE_3_TO_1_MASK	(0x000E0000U)
#define XRAM_SLCR_PCSR_PSR_MEM_CLEAR_PASS_0_MASK	(0x00000080U)
#define XRAM_SLCR_PCSR_PSR_MEM_CLEAR_PASS_3_TO_1_MASK	(0x00700000U)
#define XRAM_SLCR_PCSR_LOCK_OFFSET					(0x000CU)
#define XRAM_SLCR_BISR_CACHE_DATA_0_OFFSET			(0xE010U)
#define XRAM_SLCR_PWR_UP_BANK0_OFFSET				(0x1100U)
#define XRAM_SLCR_PWR_UP_BANK1_OFFSET				(0x1110U)
#define XRAM_SLCR_PWR_UP_BANK2_OFFSET				(0x1120U)
#define XRAM_SLCR_PWR_UP_BANK3_OFFSET				(0x1130U)
#define XRAM_SLCR_PWR_DWN_BANK0_OFFSET				(0x1104U)
#define XRAM_SLCR_PWR_DWN_BANK1_OFFSET				(0x1114U)
#define XRAM_SLCR_PWR_DWN_BANK2_OFFSET				(0x1124U)
#define XRAM_SLCR_PWR_DWN_BANK3_OFFSET				(0x1134U)
#define XRAM_SLCR_PWR_STATUS_BANK0_OFFSET			(0x1108U)
#define XRAM_SLCR_PWR_STATUS_BANK1_OFFSET			(0x1118U)
#define XRAM_SLCR_PWR_STATUS_BANK2_OFFSET			(0x1128U)
#define XRAM_SLCR_PWR_STATUS_BANK3_OFFSET			(0x1138U)


/**
 * NPI Module for SSIT device
 */
#define NPI_NIR_0_OFFSET					(0x00000000U)

#ifdef __cplusplus
}
#endif

#endif /* XPM_REGS_H */
