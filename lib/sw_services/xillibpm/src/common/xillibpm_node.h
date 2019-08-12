/******************************************************************************
*
* Copyright (C) 2018-2019 Xilinx, Inc.  All rights reserved.
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

#ifndef XILLIBPM_NODE_H_
#define XILLIBPM_NODE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define NODE_CLASS_SHIFT	26U
#define NODE_SUBCLASS_SHIFT	20U
#define NODE_TYPE_SHIFT		14U
#define NODE_INDEX_SHIFT	0U
#define NODE_CLASS_MASK_BITS    0x3F
#define NODE_SUBCLASS_MASK_BITS 0x3F
#define NODE_TYPE_MASK_BITS     0x3F
#define NODE_INDEX_MASK_BITS    0x3FFF
#define NODE_CLASS_MASK         (NODE_CLASS_MASK_BITS << NODE_CLASS_SHIFT)
#define NODE_SUBCLASS_MASK      (NODE_SUBCLASS_MASK_BITS << NODE_SUBCLASS_SHIFT)
#define NODE_TYPE_MASK          (NODE_TYPE_MASK_BITS << NODE_TYPE_SHIFT)
#define NODE_INDEX_MASK         (NODE_INDEX_MASK_BITS << NODE_INDEX_SHIFT)

#define NODEID(CLASS, SUBCLASS, TYPE, INDEX)	\
	((((CLASS) & NODE_CLASS_MASK_BITS) << NODE_CLASS_SHIFT) | \
	(((SUBCLASS) & NODE_SUBCLASS_MASK_BITS) << NODE_SUBCLASS_SHIFT) | \
	(((TYPE) & NODE_TYPE_MASK_BITS) << NODE_TYPE_SHIFT) | \
	(((INDEX) & NODE_INDEX_MASK_BITS) << NODE_INDEX_SHIFT))

#define NODECLASS(ID)		(((ID) & NODE_CLASS_MASK) >> NODE_CLASS_SHIFT)
#define NODESUBCLASS(ID)	(((ID) & NODE_SUBCLASS_MASK) >> NODE_SUBCLASS_SHIFT)
#define NODETYPE(ID)		(((ID) & NODE_TYPE_MASK) >> NODE_TYPE_SHIFT)
#define NODEINDEX(ID)		(((ID) & NODE_INDEX_MASK) >> NODE_INDEX_SHIFT)

#define LMIONODEID(PINNUM)	NODEID(XPM_NODECLASS_STMIC,\
	XPM_NODESUBCL_PIN, XPM_NODETYPE_LPD_MIO, (PINNUM) + XPM_NODEIDX_STMIC_LMIO_0)

#define PMIONODEID(PINNUM)	NODEID(XPM_NODECLASS_STMIC,\
	XPM_NODESUBCL_PIN, XPM_NODETYPE_PMC_MIO, (PINNUM) + XPM_NODEIDX_STMIC_PMIO_0)

/* Node class types */
enum class {
	XPM_NODECLASS_MIN,

	XPM_NODECLASS_POWER,
	XPM_NODECLASS_CLOCK,
	XPM_NODECLASS_RESET,
	XPM_NODECLASS_MEMIC,
	XPM_NODECLASS_STMIC,
	XPM_NODECLASS_DEVICE,
	XPM_NODECLASS_SUBSYSTEM,
	XPM_NODECLASS_ISOLATION,
	XPM_NODECLASS_PROTECTION,
	XPM_NODECLASS_EVENT,

	XPM_NODECLASS_MAX
} XPm_NodeClass;

/* Node subclass types */
typedef enum {
        /* Power nodes */
        XPM_NODESUBCL_POWER_ISLAND=1,
        XPM_NODESUBCL_POWER_DOMAIN,
} XPm_PowerNodeSubclass;

typedef enum {
        /* Clock nodes */
        XPM_NODESUBCL_CLOCK_PLL=1,
        XPM_NODESUBCL_CLOCK_OUT,
        XPM_NODESUBCL_CLOCK_REF,
} XPm_ClockNodeSubclass;

typedef enum {
        /* Reset nodes */
        XPM_NODESUBCL_RESET_PERIPHERAL=1,
        XPM_NODESUBCL_RESET_DBG,
        XPM_NODESUBCL_RESET_POR,
        XPM_NODESUBCL_RESET_SRST,
} XPm_ResetNodeSubclass;

typedef enum {
	/* MEMIC subclasses */
	XPM_NODESUBCL_MEMIC_NOC,
} XPm_MemicNodeSubclass;

typedef enum {
        /* Pin nodes */
        XPM_NODESUBCL_PIN=1,
} XPm_PinNodeSubclass;

typedef enum {
        /* Device types */
        XPM_NODESUBCL_DEV_CORE=1,
        XPM_NODESUBCL_DEV_PERIPH,
        XPM_NODESUBCL_DEV_MEM,
        XPM_NODESUBCL_DEV_SOC,
        XPM_NODESUBCL_DEV_MEM_CTRLR,
        XPM_NODESUBCL_DEV_PHY,
} XPm_DeviceNodeSubclass;

typedef enum {
	/* Subsystem classes */
	XPM_NODESUBCL_SUBSYSTEM=0,
} XPm_SubsystemSubclass;

typedef enum {
	/* isoaltion subclasses */
	XPM_NODESUBCL_ISOLATION=0,
} XPm_IsolationSubclass;

typedef enum {
	/* Protection subclasses */
	XPM_NODESUBCL_PROT_XPPU,
	XPM_NODESUBCL_PROT_XMPU,
} XPm_ProtNodeSubclass;

typedef enum {
	/* Event subclasses */
	XPM_NODESUBCL_EVENT_ERROR=1,
	XPM_NODESUBCL_EVENT_INTERRUPT,
} XPm_EventSubclass;

/* Node types */
typedef enum {
        /* Power nodes */
        XPM_NODETYPE_POWER_ISLAND=1,
        XPM_NODETYPE_POWER_DOMAIN_PMC,
        XPM_NODETYPE_POWER_DOMAIN_PS_FULL,
        XPM_NODETYPE_POWER_DOMAIN_PS_LOW,
        XPM_NODETYPE_POWER_DOMAIN_NOC,
        XPM_NODETYPE_POWER_DOMAIN_CPM,
	XPM_NODETYPE_POWER_DOMAIN_ME,
	XPM_NODETYPE_POWER_DOMAIN_PL,
} XPm_PowerNodeType;

typedef enum {
        /* Clock nodes */
        XPM_NODETYPE_CLOCK_PLL=1,
        XPM_NODETYPE_CLOCK_OUT,
        XPM_NODETYPE_CLOCK_REF,
        XPM_NODETYPE_CLOCK_SUBNODE,
} XPm_ClockNodeType;

typedef enum {
        /* Reset nodes */
        XPM_NODETYPE_RESET_PERIPHERAL=1,
        XPM_NODETYPE_RESET_DBG,
        XPM_NODETYPE_RESET_POR,
        XPM_NODETYPE_RESET_SRST,
} XPm_ResetNodeType;

typedef enum {
	/* MEMIC node types */
	XPM_NODETYPE_MEMIC_MASTER,
	XPM_NODETYPE_MEMIC_SLAVE,
} XPm_MemicNodeType;

typedef enum {
        /* Pin nodes */
        XPM_NODETYPE_LPD_MIO=1,
        XPM_NODETYPE_PMC_MIO,
} XPm_PinNodeType;

typedef enum {
        /* Device types */
        XPM_NODETYPE_DEV_CORE_PMC=1,
        XPM_NODETYPE_DEV_CORE_PSM,
        XPM_NODETYPE_DEV_CORE_APU,
        XPM_NODETYPE_DEV_CORE_RPU,
        XPM_NODETYPE_DEV_OCM,
        XPM_NODETYPE_DEV_TCM,
        XPM_NODETYPE_DEV_L2CACHE,
        XPM_NODETYPE_DEV_DDR,
        XPM_NODETYPE_DEV_PERIPH,
        XPM_NODETYPE_DEV_SOC,
        XPM_NODETYPE_DEV_GT,
	XPM_NODETYPE_DEV_EFUSE,
} XPm_DeviceNodeType;

typedef enum {
	/* Subsystem types */
        XPM_NODETYPE_SUBSYSTEM=0,
} XPm_SubsystemTypes;

typedef enum {
	/* isoaltion types */
	XPM_NODETYPE_ISOLATION=0,
} XPm_IsolationTypes;

typedef enum {
	/* Protection types */
	XPM_NODETYPE_PROTECTION=0,
} XPm_ProtTypes;

typedef enum {
	/* Event error types */
	XPM_NODETYPE_EVENT_PMC_ERR1=0,
	XPM_NODETYPE_EVENT_PMC_ERR2,
	XPM_NODETYPE_EVENT_PSM_ERR1,
	XPM_NODETYPE_EVENT_PSM_ERR2,
} XPm_EventType;

/* All node IDs */
typedef enum {
	/* Power nodes */
	XPM_NODEIDX_POWER_MIN,

	/* Power domains */
	XPM_NODEIDX_POWER_PMC,
	XPM_NODEIDX_POWER_LPD,
	XPM_NODEIDX_POWER_FPD,
	XPM_NODEIDX_POWER_NOC,
	XPM_NODEIDX_POWER_ME,
	XPM_NODEIDX_POWER_PLD,
	XPM_NODEIDX_POWER_CPM,
	XPM_NODEIDX_POWER_PL_SYSMON,

	/* LPD power islands */
	XPM_NODEIDX_POWER_RPU0_0,
	XPM_NODEIDX_POWER_GEM0,
	XPM_NODEIDX_POWER_GEM1,
	XPM_NODEIDX_POWER_OCM_0,
	XPM_NODEIDX_POWER_OCM_1,
	XPM_NODEIDX_POWER_OCM_2,
	XPM_NODEIDX_POWER_OCM_3,
	XPM_NODEIDX_POWER_TCM_0_A,
	XPM_NODEIDX_POWER_TCM_0_B,
	XPM_NODEIDX_POWER_TCM_1_A,
	XPM_NODEIDX_POWER_TCM_1_B,

	/* FPD power islands */
	XPM_NODEIDX_POWER_ACPU_0,
	XPM_NODEIDX_POWER_ACPU_1,
	XPM_NODEIDX_POWER_L2_BANK_0,

	XPM_NODEIDX_POWER_MAX,
} XPm_PowerNodeIndex;

enum {
	XPM_NODEIDX_CLK_MIN,
	XPM_NODEIDX_CLK_PMC_PLL,
	XPM_NODEIDX_CLK_APU_PLL,
	XPM_NODEIDX_CLK_RPU_PLL,
	XPM_NODEIDX_CLK_CPM_PLL,
	XPM_NODEIDX_CLK_NOC_PLL,
	XPM_NODEIDX_CLK_PLL_MAX,
	XPM_NODEIDX_CLK_PMC_PRESRC,
	XPM_NODEIDX_CLK_PMC_POSTCLK,
	XPM_NODEIDX_CLK_PMC_PLL_OUT,
	XPM_NODEIDX_CLK_PPLL,
	XPM_NODEIDX_CLK_NOC_PRESRC,
	XPM_NODEIDX_CLK_NOC_POSTCLK,
	XPM_NODEIDX_CLK_NOC_PLL_OUT,
	XPM_NODEIDX_CLK_NPLL,
	XPM_NODEIDX_CLK_APU_PRESRC,
	XPM_NODEIDX_CLK_APU_POSTCLK,
	XPM_NODEIDX_CLK_APU_PLL_OUT,
	XPM_NODEIDX_CLK_APLL,
	XPM_NODEIDX_CLK_RPU_PRESRC,
	XPM_NODEIDX_CLK_RPU_POSTCLK,
	XPM_NODEIDX_CLK_RPU_PLL_OUT,
	XPM_NODEIDX_CLK_RPLL,
	XPM_NODEIDX_CLK_CPM_PRESRC,
	XPM_NODEIDX_CLK_CPM_POSTCLK,
	XPM_NODEIDX_CLK_CPM_PLL_OUT,
	XPM_NODEIDX_CLK_CPLL,
	XPM_NODEIDX_CLK_PPLL_TO_XPD,
	XPM_NODEIDX_CLK_NPLL_TO_XPD,
	XPM_NODEIDX_CLK_APLL_TO_XPD,
	XPM_NODEIDX_CLK_RPLL_TO_XPD,
	XPM_NODEIDX_CLK_EFUSE_REF,
	XPM_NODEIDX_CLK_SYSMON_REF,
	XPM_NODEIDX_CLK_IRO_SUSPEND_REF,
	XPM_NODEIDX_CLK_USB_SUSPEND,
	XPM_NODEIDX_CLK_SWITCH_TIMEOUT,
	XPM_NODEIDX_CLK_RCLK_PMC,
	XPM_NODEIDX_CLK_RCLK_LPD,
	XPM_NODEIDX_CLK_WDT,
	XPM_NODEIDX_CLK_TTC0,
	XPM_NODEIDX_CLK_TTC1,
	XPM_NODEIDX_CLK_TTC2,
	XPM_NODEIDX_CLK_TTC3,
	XPM_NODEIDX_CLK_GEM_TSU,
	XPM_NODEIDX_CLK_GEM_TSU_LB,
	XPM_NODEIDX_CLK_MUXED_IRO_DIV2,
	XPM_NODEIDX_CLK_MUXED_IRO_DIV4,
	XPM_NODEIDX_CLK_PSM_REF,
	XPM_NODEIDX_CLK_GEM0_RX,
	XPM_NODEIDX_CLK_GEM0_TX,
	XPM_NODEIDX_CLK_GEM1_RX,
	XPM_NODEIDX_CLK_GEM1_TX,
	XPM_NODEIDX_CLK_CPM_CORE_REF,
	XPM_NODEIDX_CLK_CPM_LSBUS_REF,
	XPM_NODEIDX_CLK_CPM_DBG_REF,
	XPM_NODEIDX_CLK_CPM_AUX0_REF,
	XPM_NODEIDX_CLK_CPM_AUX1_REF,
	XPM_NODEIDX_CLK_QSPI_REF,
	XPM_NODEIDX_CLK_OSPI_REF,
	XPM_NODEIDX_CLK_SDIO0_REF,
	XPM_NODEIDX_CLK_SDIO1_REF,
	XPM_NODEIDX_CLK_PMC_LSBUS_REF,
	XPM_NODEIDX_CLK_I2C_REF,
	XPM_NODEIDX_CLK_TEST_PATTERN_REF,
	XPM_NODEIDX_CLK_DFT_OSC_REF,
	XPM_NODEIDX_CLK_PMC_PL0_REF,
	XPM_NODEIDX_CLK_PMC_PL1_REF,
	XPM_NODEIDX_CLK_PMC_PL2_REF,
	XPM_NODEIDX_CLK_PMC_PL3_REF,
	XPM_NODEIDX_CLK_CFU_REF,
	XPM_NODEIDX_CLK_SPARE_REF,
	XPM_NODEIDX_CLK_NPI_REF,
	XPM_NODEIDX_CLK_HSM0_REF,
	XPM_NODEIDX_CLK_HSM1_REF,
	XPM_NODEIDX_CLK_SD_DLL_REF,
	XPM_NODEIDX_CLK_FPD_TOP_SWITCH,
	XPM_NODEIDX_CLK_FPD_LSBUS,
	XPM_NODEIDX_CLK_ACPU,
	XPM_NODEIDX_CLK_DBG_TRACE,
	XPM_NODEIDX_CLK_DBG_FPD,
	XPM_NODEIDX_CLK_LPD_TOP_SWITCH,
	XPM_NODEIDX_CLK_ADMA,
	XPM_NODEIDX_CLK_LPD_LSBUS,
	XPM_NODEIDX_CLK_CPU_R5,
	XPM_NODEIDX_CLK_CPU_R5_CORE,
	XPM_NODEIDX_CLK_CPU_R5_OCM,
	XPM_NODEIDX_CLK_CPU_R5_OCM2,
	XPM_NODEIDX_CLK_IOU_SWITCH,
	XPM_NODEIDX_CLK_GEM0_REF,
	XPM_NODEIDX_CLK_GEM1_REF,
	XPM_NODEIDX_CLK_GEM_TSU_REF,
	XPM_NODEIDX_CLK_USB0_BUS_REF,
	XPM_NODEIDX_CLK_UART0_REF,
	XPM_NODEIDX_CLK_UART1_REF,
	XPM_NODEIDX_CLK_SPI0_REF,
	XPM_NODEIDX_CLK_SPI1_REF,
	XPM_NODEIDX_CLK_CAN0_REF,
	XPM_NODEIDX_CLK_CAN1_REF,
	XPM_NODEIDX_CLK_I2C0_REF,
	XPM_NODEIDX_CLK_I2C1_REF,
	XPM_NODEIDX_CLK_DBG_LPD,
	XPM_NODEIDX_CLK_TIMESTAMP_REF,
	XPM_NODEIDX_CLK_DBG_TSTMP,
	XPM_NODEIDX_CLK_CPM_TOPSW_REF,
	XPM_NODEIDX_CLK_USB3_DUAL_REF,
	XPM_NODEIDX_CLK_OUTCLK_MAX,
	XPM_NODEIDX_CLK_REF_CLK,
	XPM_NODEIDX_CLK_PL_ALT_REF_CLK,
	XPM_NODEIDX_CLK_MUXED_IRO,
	XPM_NODEIDX_CLK_PL_EXT,
	XPM_NODEIDX_CLK_PL_LB,
	XPM_NODEIDX_CLK_MIO_50_OR_51,
	XPM_NODEIDX_CLK_MIO_24_OR_25,
	XPM_NODEIDX_CLK_EMIO,
	XPM_NODEIDX_CLK_MIO,
	XPM_NODEIDX_CLK_MAX,
} XPm_ClockNodeIndex;

typedef enum {
	/* Reset nodes */
	XPM_NODEIDX_RST_MIN,
	XPM_NODEIDX_RST_PMC_POR,
	XPM_NODEIDX_RST_PMC,
	XPM_NODEIDX_RST_PS_POR,
	XPM_NODEIDX_RST_PL_POR,
	XPM_NODEIDX_RST_NOC_POR,
	XPM_NODEIDX_RST_FPD_POR,
	XPM_NODEIDX_RST_ACPU_0_POR,
	XPM_NODEIDX_RST_ACPU_1_POR,
	XPM_NODEIDX_RST_OCM2_POR,
	XPM_NODEIDX_RST_PS_SRST,
	XPM_NODEIDX_RST_PL_SRST,
	XPM_NODEIDX_RST_NOC,
	XPM_NODEIDX_RST_NPI,
	XPM_NODEIDX_RST_SYS_RST_1,
	XPM_NODEIDX_RST_SYS_RST_2,
	XPM_NODEIDX_RST_SYS_RST_3,
	XPM_NODEIDX_RST_FPD,
	XPM_NODEIDX_RST_PL0,
	XPM_NODEIDX_RST_PL1,
	XPM_NODEIDX_RST_PL2,
	XPM_NODEIDX_RST_PL3,
	XPM_NODEIDX_RST_APU,
	XPM_NODEIDX_RST_ACPU_0,
	XPM_NODEIDX_RST_ACPU_1,
	XPM_NODEIDX_RST_ACPU_L2,
	XPM_NODEIDX_RST_ACPU_GIC,
	XPM_NODEIDX_RST_RPU_ISLAND,
	XPM_NODEIDX_RST_RPU_AMBA,
	XPM_NODEIDX_RST_R5_0,
	XPM_NODEIDX_RST_R5_1,
	XPM_NODEIDX_RST_SYSMON_PMC_SEQ_RST,
	XPM_NODEIDX_RST_SYSMON_PMC_CFG_RST,
	XPM_NODEIDX_RST_SYSMON_FPD_CFG_RST,
	XPM_NODEIDX_RST_SYSMON_FPD_SEQ_RST,
	XPM_NODEIDX_RST_SYSMON_LPD,
	XPM_NODEIDX_RST_PDMA_RST1,
	XPM_NODEIDX_RST_PDMA_RST0,
	XPM_NODEIDX_RST_ADMA,
	XPM_NODEIDX_RST_TIMESTAMP,
	XPM_NODEIDX_RST_OCM,
	XPM_NODEIDX_RST_OCM2_RST,
	XPM_NODEIDX_RST_IPI,
	XPM_NODEIDX_RST_SBI,
	XPM_NODEIDX_RST_LPD,
	XPM_NODEIDX_RST_QSPI,
	XPM_NODEIDX_RST_OSPI,
	XPM_NODEIDX_RST_SDIO_0,
	XPM_NODEIDX_RST_SDIO_1,
	XPM_NODEIDX_RST_I2C_PMC,
	XPM_NODEIDX_RST_GPIO_PMC,
	XPM_NODEIDX_RST_GEM_0,
	XPM_NODEIDX_RST_GEM_1,
	XPM_NODEIDX_RST_SPARE,
	XPM_NODEIDX_RST_USB_0,
	XPM_NODEIDX_RST_UART_0,
	XPM_NODEIDX_RST_UART_1,
	XPM_NODEIDX_RST_SPI_0,
	XPM_NODEIDX_RST_SPI_1,
	XPM_NODEIDX_RST_CAN_FD_0,
	XPM_NODEIDX_RST_CAN_FD_1,
	XPM_NODEIDX_RST_I2C_0,
	XPM_NODEIDX_RST_I2C_1,
	XPM_NODEIDX_RST_GPIO_LPD,
	XPM_NODEIDX_RST_TTC_0,
	XPM_NODEIDX_RST_TTC_1,
	XPM_NODEIDX_RST_TTC_2,
	XPM_NODEIDX_RST_TTC_3,
	XPM_NODEIDX_RST_SWDT_FPD,
	XPM_NODEIDX_RST_SWDT_LPD,
	XPM_NODEIDX_RST_USB,
	XPM_NODEIDX_RST_DPC,
	XPM_NODEIDX_RST_PMCDBG,
	XPM_NODEIDX_RST_DBG_TRACE,
	XPM_NODEIDX_RST_DBG_FPD,
	XPM_NODEIDX_RST_DBG_TSTMP,
	XPM_NODEIDX_RST_RPU0_DBG,
	XPM_NODEIDX_RST_RPU1_DBG,
	XPM_NODEIDX_RST_HSDP,
	XPM_NODEIDX_RST_DBG_LPD,
	XPM_NODEIDX_RST_CPM_POR,
	XPM_NODEIDX_RST_CPM,
	XPM_NODEIDX_RST_CPMDBG,
	XPM_NODEIDX_RST_PCIE_CFG,
	XPM_NODEIDX_RST_PCIE_CORE0,
	XPM_NODEIDX_RST_PCIE_CORE1,
	XPM_NODEIDX_RST_PCIE_DMA,
	XPM_NODEIDX_RST_CMN,
	XPM_NODEIDX_RST_L2_0,
	XPM_NODEIDX_RST_L2_1,
	XPM_NODEIDX_RST_ADDR_REMAP,
	XPM_NODEIDX_RST_CPI0,
	XPM_NODEIDX_RST_CPI1,
	XPM_NODEIDX_RST_MAX,
} XPm_ResetNodeIndex;

typedef enum {
	/* MEMIC nodes */
	XPM_NODEIDX_MEMIC_NMU_0,
	XPM_NODEIDX_MEMIC_NMU_1,
	XPM_NODEIDX_MEMIC_NMU_2,
	XPM_NODEIDX_MEMIC_NMU_3,
	XPM_NODEIDX_MEMIC_NMU_4,
	XPM_NODEIDX_MEMIC_NMU_5,
	XPM_NODEIDX_MEMIC_NMU_6,
	XPM_NODEIDX_MEMIC_NMU_7,
	XPM_NODEIDX_MEMIC_NMU_8,
	XPM_NODEIDX_MEMIC_NMU_9,
	XPM_NODEIDX_MEMIC_NMU_10,
	XPM_NODEIDX_MEMIC_NMU_11,
	XPM_NODEIDX_MEMIC_NMU_12,
	XPM_NODEIDX_MEMIC_NMU_13,
	XPM_NODEIDX_MEMIC_NMU_14,
	XPM_NODEIDX_MEMIC_NMU_15,
	XPM_NODEIDX_MEMIC_NMU_16,
	XPM_NODEIDX_MEMIC_NMU_17,
	XPM_NODEIDX_MEMIC_NMU_18,
	XPM_NODEIDX_MEMIC_NMU_19,
	XPM_NODEIDX_MEMIC_NMU_20,
	XPM_NODEIDX_MEMIC_NMU_21,
	XPM_NODEIDX_MEMIC_NMU_22,
	XPM_NODEIDX_MEMIC_NMU_23,
	XPM_NODEIDX_MEMIC_NMU_24,
	XPM_NODEIDX_MEMIC_NMU_25,
	XPM_NODEIDX_MEMIC_NMU_26,
	XPM_NODEIDX_MEMIC_NMU_27,
	XPM_NODEIDX_MEMIC_NMU_28,
	XPM_NODEIDX_MEMIC_NMU_29,
	XPM_NODEIDX_MEMIC_NMU_30,
	XPM_NODEIDX_MEMIC_NMU_31,
	XPM_NODEIDX_MEMIC_NMU_32,
	XPM_NODEIDX_MEMIC_NMU_33,
	XPM_NODEIDX_MEMIC_NMU_34,
	XPM_NODEIDX_MEMIC_NMU_35,
	XPM_NODEIDX_MEMIC_NMU_36,
	XPM_NODEIDX_MEMIC_NMU_37,
	XPM_NODEIDX_MEMIC_NMU_38,
	XPM_NODEIDX_MEMIC_NMU_39,
	XPM_NODEIDX_MEMIC_NMU_40,
	XPM_NODEIDX_MEMIC_NMU_41,
	XPM_NODEIDX_MEMIC_NMU_42,
	XPM_NODEIDX_MEMIC_NMU_43,
	XPM_NODEIDX_MEMIC_NMU_44,
	XPM_NODEIDX_MEMIC_NMU_45,
	XPM_NODEIDX_MEMIC_NMU_46,
	XPM_NODEIDX_MEMIC_NMU_47,
	XPM_NODEIDX_MEMIC_NMU_48,
	XPM_NODEIDX_MEMIC_NMU_49,
	XPM_NODEIDX_MEMIC_NMU_50,
	XPM_NODEIDX_MEMIC_NMU_51,
	XPM_NODEIDX_MEMIC_NMU_52,
	XPM_NODEIDX_MEMIC_NMU_53,

	XPM_NODEIDX_MEMIC_NSU_0,
	XPM_NODEIDX_MEMIC_NSU_1,
	XPM_NODEIDX_MEMIC_NSU_2,
	XPM_NODEIDX_MEMIC_NSU_3,
	XPM_NODEIDX_MEMIC_NSU_4,
	XPM_NODEIDX_MEMIC_NSU_5,
	XPM_NODEIDX_MEMIC_NSU_6,
	XPM_NODEIDX_MEMIC_NSU_7,
	XPM_NODEIDX_MEMIC_NSU_8,
	XPM_NODEIDX_MEMIC_NSU_9,
	XPM_NODEIDX_MEMIC_NSU_10,
	XPM_NODEIDX_MEMIC_NSU_11,
	XPM_NODEIDX_MEMIC_NSU_12,
	XPM_NODEIDX_MEMIC_NSU_13,
	XPM_NODEIDX_MEMIC_NSU_14,
	XPM_NODEIDX_MEMIC_NSU_15,
	XPM_NODEIDX_MEMIC_NSU_16,
	XPM_NODEIDX_MEMIC_NSU_17,
	XPM_NODEIDX_MEMIC_NSU_18,
	XPM_NODEIDX_MEMIC_NSU_19,
	XPM_NODEIDX_MEMIC_NSU_20,
	XPM_NODEIDX_MEMIC_NSU_21,
	XPM_NODEIDX_MEMIC_NSU_22,
	XPM_NODEIDX_MEMIC_NSU_23,
	XPM_NODEIDX_MEMIC_NSU_24,
	XPM_NODEIDX_MEMIC_NSU_25,
	XPM_NODEIDX_MEMIC_NSU_26,
	XPM_NODEIDX_MEMIC_NSU_27,
	XPM_NODEIDX_MEMIC_NSU_28,
	XPM_NODEIDX_MEMIC_NSU_29,
	XPM_NODEIDX_MEMIC_NSU_30,
	XPM_NODEIDX_MEMIC_NSU_31,
	XPM_NODEIDX_MEMIC_NSU_32,
	XPM_NODEIDX_MEMIC_NSU_33,
	XPM_NODEIDX_MEMIC_NSU_34,
	XPM_NODEIDX_MEMIC_NSU_35,
	XPM_NODEIDX_MEMIC_NSU_36,
	XPM_NODEIDX_MEMIC_NSU_37,
	XPM_NODEIDX_MEMIC_NSU_38,
	XPM_NODEIDX_MEMIC_NSU_39,
	XPM_NODEIDX_MEMIC_NSU_40,
	XPM_NODEIDX_MEMIC_NSU_41,
	XPM_NODEIDX_MEMIC_NSU_42,
	XPM_NODEIDX_MEMIC_NSU_43,
	XPM_NODEIDX_MEMIC_NSU_44,
	XPM_NODEIDX_MEMIC_NSU_45,
	XPM_NODEIDX_MEMIC_NSU_46,
	XPM_NODEIDX_MEMIC_NSU_47,
	XPM_NODEIDX_MEMIC_NSU_48,
	XPM_NODEIDX_MEMIC_NSU_49,

	XPM_NODEIDX_MEMIC_MAX,
} XPm_MemicNodeIndex;

typedef enum {
	/* MIO nodes */
	XPM_NODEIDX_STMIC_MIN,

	XPM_NODEIDX_STMIC_LMIO_0,
	XPM_NODEIDX_STMIC_LMIO_1,
	XPM_NODEIDX_STMIC_LMIO_2,
	XPM_NODEIDX_STMIC_LMIO_3,
	XPM_NODEIDX_STMIC_LMIO_4,
	XPM_NODEIDX_STMIC_LMIO_5,
	XPM_NODEIDX_STMIC_LMIO_6,
	XPM_NODEIDX_STMIC_LMIO_7,
	XPM_NODEIDX_STMIC_LMIO_8,
	XPM_NODEIDX_STMIC_LMIO_9,
	XPM_NODEIDX_STMIC_LMIO_10,
	XPM_NODEIDX_STMIC_LMIO_11,
	XPM_NODEIDX_STMIC_LMIO_12,
	XPM_NODEIDX_STMIC_LMIO_13,
	XPM_NODEIDX_STMIC_LMIO_14,
	XPM_NODEIDX_STMIC_LMIO_15,
	XPM_NODEIDX_STMIC_LMIO_16,
	XPM_NODEIDX_STMIC_LMIO_17,
	XPM_NODEIDX_STMIC_LMIO_18,
	XPM_NODEIDX_STMIC_LMIO_19,
	XPM_NODEIDX_STMIC_LMIO_20,
	XPM_NODEIDX_STMIC_LMIO_21,
	XPM_NODEIDX_STMIC_LMIO_22,
	XPM_NODEIDX_STMIC_LMIO_23,
	XPM_NODEIDX_STMIC_LMIO_24,
	XPM_NODEIDX_STMIC_LMIO_25,
	XPM_NODEIDX_STMIC_PMIO_0,
	XPM_NODEIDX_STMIC_PMIO_1,
	XPM_NODEIDX_STMIC_PMIO_2,
	XPM_NODEIDX_STMIC_PMIO_3,
	XPM_NODEIDX_STMIC_PMIO_4,
	XPM_NODEIDX_STMIC_PMIO_5,
	XPM_NODEIDX_STMIC_PMIO_6,
	XPM_NODEIDX_STMIC_PMIO_7,
	XPM_NODEIDX_STMIC_PMIO_8,
	XPM_NODEIDX_STMIC_PMIO_9,
	XPM_NODEIDX_STMIC_PMIO_10,
	XPM_NODEIDX_STMIC_PMIO_11,
	XPM_NODEIDX_STMIC_PMIO_12,
	XPM_NODEIDX_STMIC_PMIO_13,
	XPM_NODEIDX_STMIC_PMIO_14,
	XPM_NODEIDX_STMIC_PMIO_15,
	XPM_NODEIDX_STMIC_PMIO_16,
	XPM_NODEIDX_STMIC_PMIO_17,
	XPM_NODEIDX_STMIC_PMIO_18,
	XPM_NODEIDX_STMIC_PMIO_19,
	XPM_NODEIDX_STMIC_PMIO_20,
	XPM_NODEIDX_STMIC_PMIO_21,
	XPM_NODEIDX_STMIC_PMIO_22,
	XPM_NODEIDX_STMIC_PMIO_23,
	XPM_NODEIDX_STMIC_PMIO_24,
	XPM_NODEIDX_STMIC_PMIO_25,
	XPM_NODEIDX_STMIC_PMIO_26,
	XPM_NODEIDX_STMIC_PMIO_27,
	XPM_NODEIDX_STMIC_PMIO_28,
	XPM_NODEIDX_STMIC_PMIO_29,
	XPM_NODEIDX_STMIC_PMIO_30,
	XPM_NODEIDX_STMIC_PMIO_31,
	XPM_NODEIDX_STMIC_PMIO_32,
	XPM_NODEIDX_STMIC_PMIO_33,
	XPM_NODEIDX_STMIC_PMIO_34,
	XPM_NODEIDX_STMIC_PMIO_35,
	XPM_NODEIDX_STMIC_PMIO_36,
	XPM_NODEIDX_STMIC_PMIO_37,
	XPM_NODEIDX_STMIC_PMIO_38,
	XPM_NODEIDX_STMIC_PMIO_39,
	XPM_NODEIDX_STMIC_PMIO_40,
	XPM_NODEIDX_STMIC_PMIO_41,
	XPM_NODEIDX_STMIC_PMIO_42,
	XPM_NODEIDX_STMIC_PMIO_43,
	XPM_NODEIDX_STMIC_PMIO_44,
	XPM_NODEIDX_STMIC_PMIO_45,
	XPM_NODEIDX_STMIC_PMIO_46,
	XPM_NODEIDX_STMIC_PMIO_47,
	XPM_NODEIDX_STMIC_PMIO_48,
	XPM_NODEIDX_STMIC_PMIO_49,
	XPM_NODEIDX_STMIC_PMIO_50,
	XPM_NODEIDX_STMIC_PMIO_51,

	XPM_NODEIDX_STMIC_MAX,
} XPm_StmicNodeIndex;

typedef enum {
	/* Device nodes */
	XPM_NODEIDX_DEV_MIN,

	/* Processor devices */
	XPM_NODEIDX_DEV_PMC_PROC,
	XPM_NODEIDX_DEV_PSM_PROC,
	XPM_NODEIDX_DEV_ACPU_0,
	XPM_NODEIDX_DEV_ACPU_1,
	XPM_NODEIDX_DEV_RPU0_0,
	XPM_NODEIDX_DEV_RPU0_1,

	/* Memory devices */
	XPM_NODEIDX_DEV_OCM_0,
	XPM_NODEIDX_DEV_OCM_1,
	XPM_NODEIDX_DEV_OCM_2,
	XPM_NODEIDX_DEV_OCM_3,
	XPM_NODEIDX_DEV_TCM_0_A,
	XPM_NODEIDX_DEV_TCM_0_B,
	XPM_NODEIDX_DEV_TCM_1_A,
	XPM_NODEIDX_DEV_TCM_1_B,
	XPM_NODEIDX_DEV_L2_BANK_0,
	XPM_NODEIDX_DEV_DDR_0,
	XPM_NODEIDX_DEV_DDR_1,
	XPM_NODEIDX_DEV_DDR_2,
	XPM_NODEIDX_DEV_DDR_3,
	XPM_NODEIDX_DEV_DDR_4,
	XPM_NODEIDX_DEV_DDR_5,
	XPM_NODEIDX_DEV_DDR_6,
	XPM_NODEIDX_DEV_DDR_7,

	/* LPD Peripheral devices */
	XPM_NODEIDX_DEV_USB_0,
	XPM_NODEIDX_DEV_GEM_0,
	XPM_NODEIDX_DEV_GEM_1,
	XPM_NODEIDX_DEV_SPI_0,
	XPM_NODEIDX_DEV_SPI_1,
	XPM_NODEIDX_DEV_I2C_0,
	XPM_NODEIDX_DEV_I2C_1,
	XPM_NODEIDX_DEV_CAN_FD_0,
	XPM_NODEIDX_DEV_CAN_FD_1,
	XPM_NODEIDX_DEV_UART_0,
	XPM_NODEIDX_DEV_UART_1,
	XPM_NODEIDX_DEV_GPIO,
	XPM_NODEIDX_DEV_TTC_0,
	XPM_NODEIDX_DEV_TTC_1,
	XPM_NODEIDX_DEV_TTC_2,
	XPM_NODEIDX_DEV_TTC_3,
	XPM_NODEIDX_DEV_SWDT_LPD,

	/* FPD Peripheral devices */
	XPM_NODEIDX_DEV_SWDT_FPD,

	/* PMC Peripheral devices */
	XPM_NODEIDX_DEV_OSPI,
	XPM_NODEIDX_DEV_QSPI,
	XPM_NODEIDX_DEV_GPIO_PMC,
	XPM_NODEIDX_DEV_I2C_PMC,
	XPM_NODEIDX_DEV_SDIO_0,
	XPM_NODEIDX_DEV_SDIO_1,
	XPM_NODEIDX_DEV_PL_0,
	XPM_NODEIDX_DEV_PL_1,
	XPM_NODEIDX_DEV_PL_2,
	XPM_NODEIDX_DEV_PL_3,
	XPM_NODEIDX_DEV_RTC,
	XPM_NODEIDX_DEV_ADMA_0,
	XPM_NODEIDX_DEV_ADMA_1,
	XPM_NODEIDX_DEV_ADMA_2,
	XPM_NODEIDX_DEV_ADMA_3,
	XPM_NODEIDX_DEV_ADMA_4,
	XPM_NODEIDX_DEV_ADMA_5,
	XPM_NODEIDX_DEV_ADMA_6,
	XPM_NODEIDX_DEV_ADMA_7,
	XPM_NODEIDX_DEV_IPI_0,
	XPM_NODEIDX_DEV_IPI_1,
	XPM_NODEIDX_DEV_IPI_2,
	XPM_NODEIDX_DEV_IPI_3,
	XPM_NODEIDX_DEV_IPI_4,
	XPM_NODEIDX_DEV_IPI_5,
	XPM_NODEIDX_DEV_IPI_6,

	/* Entire SoC */
	XPM_NODEIDX_DEV_SOC,

	/* DDR memory controllers */
	XPM_NODEIDX_DEV_DDRMC_0,
	XPM_NODEIDX_DEV_DDRMC_1,
	XPM_NODEIDX_DEV_DDRMC_2,
	XPM_NODEIDX_DEV_DDRMC_3,

	/* GT devices */
	XPM_NODEIDX_DEV_GT_0,
	XPM_NODEIDX_DEV_GT_1,
	XPM_NODEIDX_DEV_GT_2,
	XPM_NODEIDX_DEV_GT_3,
	XPM_NODEIDX_DEV_GT_4,
	XPM_NODEIDX_DEV_GT_5,
	XPM_NODEIDX_DEV_GT_6,
	XPM_NODEIDX_DEV_GT_7,
	XPM_NODEIDX_DEV_GT_8,
	XPM_NODEIDX_DEV_GT_9,
	XPM_NODEIDX_DEV_GT_10,

	XPM_NODEIDX_DEV_AMS_ROOT,
	XPM_NODEIDX_DEV_EFUSE_CACHE,

	XPM_NODEIDX_DEV_MAX
} XPm_DeviceNodeIndex;


/**
 * Subsystem IDs
 */
typedef enum {
	XPM_NODEIDX_SUBSYS_DEFAULT,
	XPM_NODEIDX_SUBSYS_PMC,
	XPM_NODEIDX_SUBSYS_PSM,
	XPM_NODEIDX_SUBSYS_APU,
	XPM_NODEIDX_SUBSYS_RPU0_LOCK,
	XPM_NODEIDX_SUBSYS_RPU0_0,
	XPM_NODEIDX_SUBSYS_RPU0_1,
	XPM_NODEIDX_SUBSYS_DDR0,
	XPM_NODEIDX_SUBSYS_ME,
	XPM_NODEIDX_SUBSYS_PL,

	XPM_NODEIDX_SUBSYS_MAX,
} XPm_SubsystemId;

/**
 * Isolation IDs
 */
typedef enum {
	XPM_NODEIDX_ISO_FPD_PL_TEST,
	XPM_NODEIDX_ISO_FPD_PL,
	XPM_NODEIDX_ISO_FPD_SOC,
	XPM_NODEIDX_ISO_LPD_CPM_DFX,
	XPM_NODEIDX_ISO_LPD_CPM,
	XPM_NODEIDX_ISO_LPD_PL_TEST,
	XPM_NODEIDX_ISO_LPD_PL,
	XPM_NODEIDX_ISO_LPD_SOC,
	XPM_NODEIDX_ISO_PMC_LPD_DFX,
	XPM_NODEIDX_ISO_PMC_LPD,
	XPM_NODEIDX_ISO_PMC_PL_CFRAME,
	XPM_NODEIDX_ISO_PMC_PL_TEST,
	XPM_NODEIDX_ISO_PMC_PL,
	XPM_NODEIDX_ISO_PMC_SOC_NPI,
	XPM_NODEIDX_ISO_PMC_SOC,
	XPM_NODEIDX_ISO_PL_SOC,
	XPM_NODEIDX_ISO_VCCAUX_SOC,
	XPM_NODEIDX_ISO_VCCRAM_SOC,
	XPM_NODEIDX_ISO_VCCAUX_VCCRAM,
	XPM_NODEIDX_ISO_PL_CPM_PCIEA0_ATTR,
	XPM_NODEIDX_ISO_PL_CPM_PCIEA1_ATTR,
	XPM_NODEIDX_ISO_PL_CPM_RST_CPI0,
	XPM_NODEIDX_ISO_PL_CPM_RST_CPI1,
	XPM_NODEIDX_ISO_MAX,
} XPm_IsolationId;

/**
 * Protection IDs
 */
typedef enum {
	XPM_NODEIDX_PROT_MIN,

	XPM_NODEIDX_PROT_XPPU_LPD,
	XPM_NODEIDX_PROT_XPPU_PMC,
	XPM_NODEIDX_PROT_XPPU_PMC_NPI,

	XPM_NODEIDX_PROT_XMPU_FPD_SLAVES,
	XPM_NODEIDX_PROT_XMPU_OCM,
	XPM_NODEIDX_PROT_XMPU_PMC,

	XPM_NODEIDX_PROT_MAX,
} XPm_ProtectionId;

/**
 * Error Event IDs
 */
typedef enum {
	/* PMC ERR1 errors */
	XPM_NODEIDX_ERROR_BOOT_CR = 0x0,
	XPM_NODEIDX_ERROR_BOOT_NCR,	/* 0x1 */
	XPM_NODEIDX_ERROR_FW_CR,	/* 0x2 */
	XPM_NODEIDX_ERROR_FW_NCR,	/* 0x3 */
	XPM_NODEIDX_ERROR_GSW_CR,	/* 0x4 */
	XPM_NODEIDX_ERROR_GSW_NCR,	/* 0x5 */
	XPM_NODEIDX_ERROR_CFU,		/* 0x6 */
	XPM_NODEIDX_ERROR_CFRAME,	/* 0x7 */
	XPM_NODEIDX_ERROR_PMC_PSM_CR,	/* 0x8 */
	XPM_NODEIDX_ERROR_PMC_PSM_NCR,	/* 0x9 */
	XPM_NODEIDX_ERROR_DDRMB_CR,	/* 0xA */
	XPM_NODEIDX_ERROR_DDRMB_NCR,	/* 0xB */
	XPM_NODEIDX_ERROR_NOCTYPE1_CR,	/* 0xC */
	XPM_NODEIDX_ERROR_NOCTYPE1_NCR,	/* 0xD */
	XPM_NODEIDX_ERROR_NOCUSER,	/* 0xE */
	XPM_NODEIDX_ERROR_MMCM,		/* 0xF */
	XPM_NODEIDX_ERROR_ME_CR,	/* 0x10 */
	XPM_NODEIDX_ERROR_ME_NCR,	/* 0x11 */
	XPM_NODEIDX_ERROR_DDRMC_CR,	/* 0x12 */
	XPM_NODEIDX_ERROR_DDRMC_NCR,	/* 0x13 */
	XPM_NODEIDX_ERROR_GT_CR,	/* 0x14 */
	XPM_NODEIDX_ERROR_GT_NCR,	/* 0x15 */
	XPM_NODEIDX_ERROR_PLSMON_CR,	/* 0x16 */
	XPM_NODEIDX_ERROR_PLSMON_NCR,	/* 0x17 */
	XPM_NODEIDX_ERROR_PL0,		/* 0x18 */
	XPM_NODEIDX_ERROR_PL1,		/* 0x19 */
	XPM_NODEIDX_ERROR_PL2,		/* 0x1A */
	XPM_NODEIDX_ERROR_PL3,		/* 0x1B */
	XPM_NODEIDX_ERROR_NPIROOT,	/* 0x1C */
	XPM_NODEIDX_ERROR_SSIT3,	/* 0x1D */
	XPM_NODEIDX_ERROR_SSIT4,	/* 0x1E */
	XPM_NODEIDX_ERROR_SSIT5,	/* 0x1F */
	XPM_NODEIDX_ERROR_PMCERR1_MAX,	/* 0x20 */
	/* PMC ERR2 errors */
	XPM_NODEIDX_ERROR_PMCAPB = 32,	/* 0x20 */
	XPM_NODEIDX_ERROR_PMCROM,	/* 0x21 */
	XPM_NODEIDX_ERROR_MB_FATAL0,	/* 0x22 */
	XPM_NODEIDX_ERROR_MB_FATAL1,	/* 0x23 */
	XPM_NODEIDX_ERROR_PMCPAR,	/* 0x24 */
	XPM_NODEIDX_ERROR_PMC_CR,	/* 0x25 */
	XPM_NODEIDX_ERROR_PMC_NCR,	/* 0x26 */
	XPM_NODEIDX_ERROR_PMCSMON0,	/* 0x27 */
	XPM_NODEIDX_ERROR_PMCSMON1,	/* 0x28 */
	XPM_NODEIDX_ERROR_PMCSMON2,	/* 0x29 */
	XPM_NODEIDX_ERROR_PMCSMON3,	/* 0x2A */
	XPM_NODEIDX_ERROR_PMCSMON4,	/* 0x2B */
	XPM_NODEIDX_ERROR_PMCSMON5,	/* 0x2C */
	XPM_NODEIDX_ERROR_PMCSMON6,	/* 0x2D */
	XPM_NODEIDX_ERROR_PMCSMON7,	/* 0x2E */
	XPM_NODEIDX_ERROR_PMCSMON8,	/* 0x2F */
	XPM_NODEIDX_ERROR_PMCSMON9,	/* 0x30 */
	XPM_NODEIDX_ERROR_CFI,		/* 0x31 */
	XPM_NODEIDX_ERROR_SEUCRC,	/* 0x32 */
	XPM_NODEIDX_ERROR_SEUECC,	/* 0x33 */
	XPM_NODEIDX_ERROR_RTCALARM,	/* 0x34 */
	XPM_NODEIDX_ERROR_NPLL,		/* 0x35 */
	XPM_NODEIDX_ERROR_PPLL,		/* 0x36 */
	XPM_NODEIDX_ERROR_CLKMON,	/* 0x37 */
	XPM_NODEIDX_ERROR_PMCTO,	/* 0x38 */
	XPM_NODEIDX_ERROR_PMCXMPU,	/* 0x39 */
	XPM_NODEIDX_ERROR_PMCXPPU,	/* 0x3A */
	XPM_NODEIDX_ERROR_SSIT0,	/* 0x3B */
	XPM_NODEIDX_ERROR_SSIT1,	/* 0x39 */
	XPM_NODEIDX_ERROR_SSIT2,	/* 0x3A */
	XPM_NODEIDX_ERROR_PMCERR2_MAX,	/* 0x3B */
	/* PSM ERR1 errors */
	XPM_NODEIDX_ERROR_PS_SW_CR = 64, /* 0x40 */
	XPM_NODEIDX_ERROR_PS_SW_NCR,	/* 0x41 */
	XPM_NODEIDX_ERROR_PSM_B_CR,	/* 0x42 */
	XPM_NODEIDX_ERROR_PSM_B_NCR,	/* 0x43 */
	XPM_NODEIDX_ERROR_MB_FATAL,	/* 0x44 */
	XPM_NODEIDX_ERROR_PSM_CR,	/* 0x45 */
	XPM_NODEIDX_ERROR_PSM_NCR,	/* 0x46 */
	XPM_NODEIDX_ERROR_OCM_ECC,	/* 0x47 */
	XPM_NODEIDX_ERROR_L2_ECC,	/* 0x48 */
	XPM_NODEIDX_ERROR_RPU_ECC,	/* 0x49 */
	XPM_NODEIDX_ERROR_RPU_LS,	/* 0x4A */
	XPM_NODEIDX_ERROR_RPU_CCF,	/* 0x4B */
	XPM_NODEIDX_ERROR_GIC_AXI,	/* 0x4C */
	XPM_NODEIDX_ERROR_GIC_ECC,	/* 0x4D */
	XPM_NODEIDX_ERROR_APLL_LOCK,	/* 0x4E */
	XPM_NODEIDX_ERROR_RPLL_LOCK,	/* 0x4F */
	XPM_NODEIDX_ERROR_CPM_CR,	/* 0x50 */
	XPM_NODEIDX_ERROR_CPM_NCR,	/* 0x51 */
	XPM_NODEIDX_ERROR_LPD_APB,	/* 0x52 */
	XPM_NODEIDX_ERROR_FPD_APB,	/* 0x53 */
	XPM_NODEIDX_ERROR_LPD_PAR,	/* 0x54 */
	XPM_NODEIDX_ERROR_FPD_PAR,	/* 0x55 */
	XPM_NODEIDX_ERROR_IOU_PAR,	/* 0x56 */
	XPM_NODEIDX_ERROR_PSM_PAR,	/* 0x57 */
	XPM_NODEIDX_ERROR_LPD_TO,	/* 0x58 */
	XPM_NODEIDX_ERROR_FPD_TO,	/* 0x59 */
	XPM_NODEIDX_ERROR_PSM_TO,	/* 0x5A */
	XPM_NODEIDX_ERROR_PSMERR1_MAX,	/* 0x5B */
	/* PSM ERR2 errors */
	XPM_NODEIDX_ERROR_LPD_SWDT = 96, /* 0x60 */
	XPM_NODEIDX_ERROR_FPD_SWDT,	/* 0x61 */
	XPM_NODEIDX_ERROR_LPD_SMON0,	/* 0x62 */
	XPM_NODEIDX_ERROR_LPD_SMON1,	/* 0x63 */
	XPM_NODEIDX_ERROR_LPD_SMON2,	/* 0x64 */
	XPM_NODEIDX_ERROR_LPD_SMON3,	/* 0x65 */
	XPM_NODEIDX_ERROR_LPD_SMON4,	/* 0x66 */
	XPM_NODEIDX_ERROR_LPD_SMON5,	/* 0x67 */
	XPM_NODEIDX_ERROR_LPD_SMON6,	/* 0x68 */
	XPM_NODEIDX_ERROR_LPD_SMON7,	/* 0x69 */
	XPM_NODEIDX_ERROR_FPD_SMON0,	/* 0x6A */
	XPM_NODEIDX_ERROR_FPD_SMON1,	/* 0x6B */
	XPM_NODEIDX_ERROR_FPD_SMON2,	/* 0x6C */
	XPM_NODEIDX_ERROR_FPD_SMON3,	/* 0x6D */
	XPM_NODEIDX_ERROR_FPD_SMON4,	/* 0x6E */
	XPM_NODEIDX_ERROR_FPD_SMON5,	/* 0x6F */
	XPM_NODEIDX_ERROR_FPD_SMON6,	/* 0x70 */
	XPM_NODEIDX_ERROR_FPD_SMON7,	/* 0x71 */
	XPM_NODEIDX_ERROR_LPD_XMPU,	/* 0x72 */
	XPM_NODEIDX_ERROR_LPD_XPPU,	/* 0x73 */
	XPM_NODEIDX_ERROR_FPD_XMPU,	/* 0x74 */
	XPM_NODEIDX_ERROR_PSMERR2_MAX,	/* 0x75 */
} XPm_ErrorId;

#ifdef __cplusplus
}
#endif

#endif /* XILLIBPM_NODE_H_ */
