/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) 2015, Atmel Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */

#ifndef _SAMA5D4_SMC_COMPONENT_
#define _SAMA5D4_SMC_COMPONENT_

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Static Memory Controller */
/* ============================================================================= */
/** \addtogroup SAMA5D4_SMC Static Memory Controller */
/*@{*/

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SmcCs hardware registers */
typedef struct {
	__IO uint32_t SMC_SETUP;   /**< \brief (SmcCs Offset: 0x0) SMC Setup Register */
	__IO uint32_t SMC_PULSE;   /**< \brief (SmcCs Offset: 0x4) SMC Pulse Register */
	__IO uint32_t SMC_CYCLE;   /**< \brief (SmcCs Offset: 0x8) SMC Cycle Register */
	__IO uint32_t SMC_TIMINGS; /**< \brief (SmcCs Offset: 0xC) SMC Timings Register */
	__IO uint32_t SMC_MODE;    /**< \brief (SmcCs Offset: 0x10) SMC Mode Register */
} SmcCs;
/** \brief Smc hardware registers */
typedef struct {
	     SmcCs    SMC_CS[4]; /**< \brief (Smc Offset: 0x00) CS = 0 .. 3 */
	__I  uint32_t Reserved1[20];
	__IO uint32_t SMC_OCMS;  /**< \brief (Smc Offset: 0xA0) SMC Off Chip Memory Scrambling Register */
	__O  uint32_t SMC_KEY1;  /**< \brief (Smc Offset: 0xA4) SMC Off Chip Memory Scrambling KEY1 Register */
	__O  uint32_t SMC_KEY2;  /**< \brief (Smc Offset: 0xA8) SMC Off Chip Memory Scrambling KEY2 Register */
	__I  uint32_t Reserved2[14];
	__IO uint32_t SMC_WPMR;  /**< \brief (Smc Offset: 0xE4) SMC Write Protection Mode Register */
	__I  uint32_t SMC_WPSR;  /**< \brief (Smc Offset: 0xE8) SMC Write Protection Status Register */
} Smc;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */
/* -------- SMC_SETUP : (SMC Offset: N/A) SMC Setup Register -------- */
#define SMC_SETUP_NWE_SETUP_Pos 0
#define SMC_SETUP_NWE_SETUP_Msk (0x3fu << SMC_SETUP_NWE_SETUP_Pos) /**< \brief (SMC_SETUP) NWE Setup Length */
#define SMC_SETUP_NWE_SETUP(value) ((SMC_SETUP_NWE_SETUP_Msk & ((value) << SMC_SETUP_NWE_SETUP_Pos)))
#define SMC_SETUP_NCS_WR_SETUP_Pos 8
#define SMC_SETUP_NCS_WR_SETUP_Msk (0x3fu << SMC_SETUP_NCS_WR_SETUP_Pos) /**< \brief (SMC_SETUP) NCS Setup Length in Write Access */
#define SMC_SETUP_NCS_WR_SETUP(value) ((SMC_SETUP_NCS_WR_SETUP_Msk & ((value) << SMC_SETUP_NCS_WR_SETUP_Pos)))
#define SMC_SETUP_NRD_SETUP_Pos 16
#define SMC_SETUP_NRD_SETUP_Msk (0x3fu << SMC_SETUP_NRD_SETUP_Pos) /**< \brief (SMC_SETUP) NRD Setup Length */
#define SMC_SETUP_NRD_SETUP(value) ((SMC_SETUP_NRD_SETUP_Msk & ((value) << SMC_SETUP_NRD_SETUP_Pos)))
#define SMC_SETUP_NCS_RD_SETUP_Pos 24
#define SMC_SETUP_NCS_RD_SETUP_Msk (0x3fu << SMC_SETUP_NCS_RD_SETUP_Pos) /**< \brief (SMC_SETUP) NCS Setup Length in Read Access */
#define SMC_SETUP_NCS_RD_SETUP(value) ((SMC_SETUP_NCS_RD_SETUP_Msk & ((value) << SMC_SETUP_NCS_RD_SETUP_Pos)))
/* -------- SMC_PULSE : (SMC Offset: N/A) SMC Pulse Register -------- */
#define SMC_PULSE_NWE_PULSE_Pos 0
#define SMC_PULSE_NWE_PULSE_Msk (0x7fu << SMC_PULSE_NWE_PULSE_Pos) /**< \brief (SMC_PULSE) NWE Pulse Length */
#define SMC_PULSE_NWE_PULSE(value) ((SMC_PULSE_NWE_PULSE_Msk & ((value) << SMC_PULSE_NWE_PULSE_Pos)))
#define SMC_PULSE_NCS_WR_PULSE_Pos 8
#define SMC_PULSE_NCS_WR_PULSE_Msk (0x7fu << SMC_PULSE_NCS_WR_PULSE_Pos) /**< \brief (SMC_PULSE) NCS Pulse Length in WRITE Access */
#define SMC_PULSE_NCS_WR_PULSE(value) ((SMC_PULSE_NCS_WR_PULSE_Msk & ((value) << SMC_PULSE_NCS_WR_PULSE_Pos)))
#define SMC_PULSE_NRD_PULSE_Pos 16
#define SMC_PULSE_NRD_PULSE_Msk (0x7fu << SMC_PULSE_NRD_PULSE_Pos) /**< \brief (SMC_PULSE) NRD Pulse Length */
#define SMC_PULSE_NRD_PULSE(value) ((SMC_PULSE_NRD_PULSE_Msk & ((value) << SMC_PULSE_NRD_PULSE_Pos)))
#define SMC_PULSE_NCS_RD_PULSE_Pos 24
#define SMC_PULSE_NCS_RD_PULSE_Msk (0x7fu << SMC_PULSE_NCS_RD_PULSE_Pos) /**< \brief (SMC_PULSE) NCS Pulse Length in READ Access */
#define SMC_PULSE_NCS_RD_PULSE(value) ((SMC_PULSE_NCS_RD_PULSE_Msk & ((value) << SMC_PULSE_NCS_RD_PULSE_Pos)))
/* -------- SMC_CYCLE : (SMC Offset: N/A) SMC Cycle Register -------- */
#define SMC_CYCLE_NWE_CYCLE_Pos 0
#define SMC_CYCLE_NWE_CYCLE_Msk (0x1ffu << SMC_CYCLE_NWE_CYCLE_Pos) /**< \brief (SMC_CYCLE) Total Write Cycle Length */
#define SMC_CYCLE_NWE_CYCLE(value) ((SMC_CYCLE_NWE_CYCLE_Msk & ((value) << SMC_CYCLE_NWE_CYCLE_Pos)))
#define SMC_CYCLE_NRD_CYCLE_Pos 16
#define SMC_CYCLE_NRD_CYCLE_Msk (0x1ffu << SMC_CYCLE_NRD_CYCLE_Pos) /**< \brief (SMC_CYCLE) Total Read Cycle Length */
#define SMC_CYCLE_NRD_CYCLE(value) ((SMC_CYCLE_NRD_CYCLE_Msk & ((value) << SMC_CYCLE_NRD_CYCLE_Pos)))
/* -------- SMC_TIMINGS : (SMC Offset: N/A) SMC Timings Register -------- */
#define SMC_TIMINGS_TCLR_Pos 0
#define SMC_TIMINGS_TCLR_Msk (0xfu << SMC_TIMINGS_TCLR_Pos) /**< \brief (SMC_TIMINGS) CLE to REN Low Delay */
#define SMC_TIMINGS_TCLR(value) ((SMC_TIMINGS_TCLR_Msk & ((value) << SMC_TIMINGS_TCLR_Pos)))
#define SMC_TIMINGS_TADL_Pos 4
#define SMC_TIMINGS_TADL_Msk (0xfu << SMC_TIMINGS_TADL_Pos) /**< \brief (SMC_TIMINGS) ALE to Data Start */
#define SMC_TIMINGS_TADL(value) ((SMC_TIMINGS_TADL_Msk & ((value) << SMC_TIMINGS_TADL_Pos)))
#define SMC_TIMINGS_TAR_Pos 8
#define SMC_TIMINGS_TAR_Msk (0xfu << SMC_TIMINGS_TAR_Pos) /**< \brief (SMC_TIMINGS) ALE to REN Low Delay */
#define SMC_TIMINGS_TAR(value) ((SMC_TIMINGS_TAR_Msk & ((value) << SMC_TIMINGS_TAR_Pos)))
#define SMC_TIMINGS_OCMS (0x1u << 12) /**< \brief (SMC_TIMINGS) Off Chip Memory Scrambling Enable */
#define SMC_TIMINGS_TRR_Pos 16
#define SMC_TIMINGS_TRR_Msk (0xfu << SMC_TIMINGS_TRR_Pos) /**< \brief (SMC_TIMINGS) Ready to REN Low Delay */
#define SMC_TIMINGS_TRR(value) ((SMC_TIMINGS_TRR_Msk & ((value) << SMC_TIMINGS_TRR_Pos)))
#define SMC_TIMINGS_TWB_Pos 24
#define SMC_TIMINGS_TWB_Msk (0xfu << SMC_TIMINGS_TWB_Pos) /**< \brief (SMC_TIMINGS) WEN High to REN to Busy */
#define SMC_TIMINGS_TWB(value) ((SMC_TIMINGS_TWB_Msk & ((value) << SMC_TIMINGS_TWB_Pos)))
#define SMC_TIMINGS_RBNSEL_Pos 28
#define SMC_TIMINGS_RBNSEL_Msk (0x7u << SMC_TIMINGS_RBNSEL_Pos) /**< \brief (SMC_TIMINGS) Ready/Busy Line Selection */
#define SMC_TIMINGS_RBNSEL(value) ((SMC_TIMINGS_RBNSEL_Msk & ((value) << SMC_TIMINGS_RBNSEL_Pos)))
#define SMC_TIMINGS_NFSEL (0x1u << 31) /**< \brief (SMC_TIMINGS) NAND Flash Selection */
/* -------- SMC_MODE : (SMC Offset: N/A) SMC Mode Register -------- */
#define SMC_MODE_READ_MODE (0x1u << 0) /**< \brief (SMC_MODE) Selection of the Control Signal for Read Operation */
#define   SMC_MODE_READ_MODE_NCS_CTRL (0x0u << 0) /**< \brief (SMC_MODE) The Read operation is controlled by the NCS signal. */
#define   SMC_MODE_READ_MODE_NRD_CTRL (0x1u << 0) /**< \brief (SMC_MODE) The Read operation is controlled by the NRD signal. */
#define SMC_MODE_WRITE_MODE (0x1u << 1) /**< \brief (SMC_MODE) Selection of the Control Signal for Write Operation */
#define   SMC_MODE_WRITE_MODE_NCS_CTRL (0x0u << 1) /**< \brief (SMC_MODE) The Write operation is controller by the NCS signal. */
#define   SMC_MODE_WRITE_MODE_NWE_CTRL (0x1u << 1) /**< \brief (SMC_MODE) The Write operation is controlled by the NWE signal */
#define SMC_MODE_EXNW_MODE_Pos 4
#define SMC_MODE_EXNW_MODE_Msk (0x3u << SMC_MODE_EXNW_MODE_Pos) /**< \brief (SMC_MODE) NWAIT Mode */
#define SMC_MODE_EXNW_MODE(value) ((SMC_MODE_EXNW_MODE_Msk & ((value) << SMC_MODE_EXNW_MODE_Pos)))
#define   SMC_MODE_EXNW_MODE_DISABLED (0x0u << 4) /**< \brief (SMC_MODE) Disabled-The NWAIT input signal is ignored on the corresponding Chip Select. */
#define   SMC_MODE_EXNW_MODE_FROZEN (0x2u << 4) /**< \brief (SMC_MODE) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped. */
#define   SMC_MODE_EXNW_MODE_READY (0x3u << 4) /**< \brief (SMC_MODE) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high. */
#define SMC_MODE_BAT (0x1u << 8) /**< \brief (SMC_MODE) Byte Access Type */
#define   SMC_MODE_BAT_BYTE_SELECT (0x0u << 8) /**< \brief (SMC_MODE) Byte select access type:- Write operation is controlled using NCS, NWE, NBS0, NBS1.- Read operation is controlled using NCS, NRD, NBS0, NBS1. */
#define   SMC_MODE_BAT_BYTE_WRITE (0x1u << 8) /**< \brief (SMC_MODE) Byte write access type:- Write operation is controlled using NCS, NWR0, NWR1.- Read operation is controlled using NCS and NRD. */
#define SMC_MODE_DBW_Pos 12
#define SMC_MODE_DBW_Msk (0x1u << SMC_MODE_DBW_Pos) /**< \brief (SMC_MODE) Data Bus Width */
#define SMC_MODE_DBW(value) ((SMC_MODE_DBW_Msk & ((value) << SMC_MODE_DBW_Pos)))
#define   SMC_MODE_DBW_BIT_8 (0x0u << 12) /**< \brief (SMC_MODE) 8-bit bus */
#define   SMC_MODE_DBW_BIT_16 (0x1u << 12) /**< \brief (SMC_MODE) 16-bit bus */
#define SMC_MODE_TDF_CYCLES_Pos 16
#define SMC_MODE_TDF_CYCLES_Msk (0xfu << SMC_MODE_TDF_CYCLES_Pos) /**< \brief (SMC_MODE) Data Float Time */
#define SMC_MODE_TDF_CYCLES(value) ((SMC_MODE_TDF_CYCLES_Msk & ((value) << SMC_MODE_TDF_CYCLES_Pos)))
#define SMC_MODE_TDF_MODE (0x1u << 20) /**< \brief (SMC_MODE) TDF Optimization */
/* -------- SMC_OCMS : (SMC Offset: 0xA0) SMC Off Chip Memory Scrambling Register -------- */
#define SMC_OCMS_SMSE (0x1u << 0) /**< \brief (SMC_OCMS) Static Memory Controller Scrambling Enable */
#define SMC_OCMS_SRSE (0x1u << 1) /**< \brief (SMC_OCMS) NFC Internal SRAM Scrambling Enable */
/* -------- SMC_KEY1 : (SMC Offset: 0xA4) SMC Off Chip Memory Scrambling KEY1 Register -------- */
#define SMC_KEY1_KEY1_Pos 0
#define SMC_KEY1_KEY1_Msk (0xffffffffu << SMC_KEY1_KEY1_Pos) /**< \brief (SMC_KEY1) Off Chip Memory Scrambling (OCMS) Key Part 1 */
#define SMC_KEY1_KEY1(value) ((SMC_KEY1_KEY1_Msk & ((value) << SMC_KEY1_KEY1_Pos)))
/* -------- SMC_KEY2 : (SMC Offset: 0xA8) SMC Off Chip Memory Scrambling KEY2 Register -------- */
#define SMC_KEY2_KEY2_Pos 0
#define SMC_KEY2_KEY2_Msk (0xffffffffu << SMC_KEY2_KEY2_Pos) /**< \brief (SMC_KEY2) Off Chip Memory Scrambling (OCMS) Key Part 2 */
#define SMC_KEY2_KEY2(value) ((SMC_KEY2_KEY2_Msk & ((value) << SMC_KEY2_KEY2_Pos)))
/* -------- SMC_WPMR : (SMC Offset: 0xE4) SMC Write Protection Mode Register -------- */
#define SMC_WPMR_WPEN (0x1u << 0) /**< \brief (SMC_WPMR) Write Protection Enable */
#define SMC_WPMR_WPKEY_Pos 8
#define SMC_WPMR_WPKEY_Msk (0xffffffu << SMC_WPMR_WPKEY_Pos) /**< \brief (SMC_WPMR) Write Protection Key */
#define SMC_WPMR_WPKEY(value) ((SMC_WPMR_WPKEY_Msk & ((value) << SMC_WPMR_WPKEY_Pos)))
#define   SMC_WPMR_WPKEY_PASSWD (0x534D43u << 8) /**< \brief (SMC_WPMR) Writing any other value in this field aborts the write operation of bit WPEN.Always reads as 0. */
/* -------- SMC_WPSR : (SMC Offset: 0xE8) SMC Write Protection Status Register -------- */
#define SMC_WPSR_WPVS (0x1u << 0) /**< \brief (SMC_WPSR) Write Protection Violation Status */
#define SMC_WPSR_WPVSRC_Pos 8
#define SMC_WPSR_WPVSRC_Msk (0xffffu << SMC_WPSR_WPVSRC_Pos) /**< \brief (SMC_WPSR) Write Protection Violation Source */

/*@}*/

#endif /* _SAMA5D4_SMC_COMPONENT_ */
