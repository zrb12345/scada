/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     gmp232x.h
* @author   MAAB
* @brief    MIO interface for the GMP232X driver
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef GMP232X__H
#define GMP232X__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @addtogroup GMP232X_DEF
 * @{
 */

/**
 * @name Relay configuration constants (MIO_CMD_GMP232X_G/SETLIMIT_*)
 * @{
 */

#define GMP232X_RELAY_NONE  0x0000   /**< no relay is used/set */
#define GMP232X_RELAY_1     0x0001   /**< relay 1 is used/set */
#define GMP232X_RELAY_2     0x0002   /**< relay 2 is used/set */
#define GMP232X_RELAY_BOTH  0x0003   /**< relay 1 + 2 are used/set */
/** @} */

/**
 * @name Values used to reflect errors when parsing the parameter file (MIO_CMD_GMP232X_PROCESSPARAMFILE)
 * @{
 */

#define GMP232X_ER_CFG_OK       0x00000000   /**< No error while parsing the parameter file */
#define GMP232X_ER_CFG_FILEMISS 0x00000001   /**< Parameter file missing */
/** @} */

/**
 * @name General defines
 * @{
 */

/**
 * Not a number (this value is returned in case a measuring mode can
 * not provide a value for the corresponding field; only used for
 * integer values, not floating point values; for floating point values,
 * the conventional NaN representation is used instead)
 */
#define GMP232X_VALUE_NaN   999999
/** @} */

/**
 * @name GMP232X measuring modes (GMP232X_CONFIG.Mode)
 * @{
 */

#define GMP232X_M_2WIRE1PHASE_LN            1    /**< 2 wires, 1 phase (phase neutral) */
#define GMP232X_M_3WIRE2PHASE_ASYM_LN       2    /**< 3 wires, 2 phases, asymmetric (phase neutral) */
#define GMP232X_M_3WIRE3PHASE_BALANCED_LL   3    /**< 3 wires, 3 phases, symmetric (phase phase) */
#define GMP232X_M_3WIRE3PHASE_ASYM_LL       4    /**< 3 wires, 3 phases, asymmetric (phase phase) */
#define GMP232X_M_3WIRE3PHASE_ARON_LL       5    /**< 3 wires, 3 phases, aron circuit (phase phase) */
#define GMP232X_M_4WIRE3PHASE_ASYM_LL       7    /**< 4 wires, 3 phases, asymmetric (phase phase) */
#define GMP232X_M_4WIRE3PHASE_BALANCED_LN   8    /**< 4 wires, 3 phases, symmetric (phase neutral) */
#define GMP232X_M_4WIRE3PHASE_ASYM_LN       9    /**< 4 wires, 3 phases, asymmetric (phase neutral) */
/** @} */

/**
 * @name Module States (MIO_CMD_GMP232X_GETSTATE/MIO_CMD_GMP232X_SETSTATE)
 * @{
 */

#define GMP232X_STATE_CONFIG        0x0  /**< configuration mode */
#define GMP232X_STATE_RUN           0x1  /**< run (in configured setup) mode */
#define GMP232X_STATE_FORCERELAY    0x2  /**< relay simulation mode */
#define GMP232X_STATE_SIMULATION    0x4  /**< simulation mode */
/** @} */

/**
 * @name Integrity (Overflow/Underflow statusbits)
 * @{
 */

#define GMP232X_INTEGRITY_OF_U1 0x01     /**< Overflow of ADC for U1 */
#define GMP232X_INTEGRITY_OF_U2 0x02     /**< Overflow of ADC for U2 */
#define GMP232X_INTEGRITY_OF_U3 0x04     /**< Overflow of ADC for U3 */
#define GMP232X_INTEGRITY_OF_I1 0x08     /**< Overflow of ADC for I1 */
#define GMP232X_INTEGRITY_OF_I2 0x10     /**< Overflow of ADC for I2 */
#define GMP232X_INTEGRITY_OF_I3 0x20     /**< Overflow of ADC for I3 */
#define GMP232X_INTEGRITY_OF_F  0x40     /**< Overflow of frequency */
#define GMP232X_INTEGRITY_UF_U1 0x100    /**< Underflow for U1 */
#define GMP232X_INTEGRITY_UF_U2 0x200    /**< Underflow for U2 */
#define GMP232X_INTEGRITY_UF_U3 0x400    /**< Underflow for U3 */
#define GMP232X_INTEGRITY_UF_I1 0x800    /**< Underflow for I1 */
#define GMP232X_INTEGRITY_UF_I2 0x1000   /**< Underflow for I2 */
#define GMP232X_INTEGRITY_UF_I3 0x2000   /**< Underflow for I3 */
#define GMP232X_INTEGRITY_UF_F  0x4000   /**< Underflow of frequency */
#define GMP232X_INTEGRITY_OF    0x00ff   /**< Overflow detected */
#define GMP232X_INTEGRITY_UF    0xff00   /**< Underflow detected */
/** @} */

/**
 * @name Defines used at GMP232X_VALUES.RotDir_U/I
 * @{
 */

#define GMP232X_ROTATION_CW         0x0000   /**< Clockwise rotation, phase sequence L1-L2-L3 */
#define GMP232X_ROTATION_CCW        0x0001   /**< Counter clockwise rotation, phase sequence L3-L2-L1 */
#define GMP232X_ROTATION_UNKNOWN    -1   /**< unknown rotation, phase sequence not identifiable */
/** @} */

/**
 * @name Constants used at GMP232X_SCOPESTATE.State
 * @{
 */

#define GMP232X_SCOPE_STATE_NOTTRIGGERED    0x0  /**< Scope scope: not yet triggered */
#define GMP232X_SCOPE_STATE_RUNNING         0x1  /**< Scope state: running */
#define GMP232X_SCOPE_STATE_TRIGGERED       0x2  /**< Scope state: triggered */
#define GMP232X_SCOPE_STATE_READY           0x4  /**< Scope state: ready */
#define GMP232X_SCOPE_STATE_LOCKED          0x8  /**< Scope state: locked */
#define GMP232X_SCOPE_STATE_RECORDING       0x10     /**< Scope state: recording */
#define GMP232X_SCOPE_STATE_NEWDATA         0x20     /**< Scope state: new data */
/** @} */

/**
 * @name Scope related constants
 * @{
 */

#define GMP232X_SCOPE_MAXCHAN       24   /**< Maximal number of channels for scope recording */
#define GMP232X_SCOPE_MAXSAMPLES    16   /**< Maximal number of scope samples */
#define GMP232X_SCOPE_VALCNT        61440    /**< Maximal number of scope values */
#define GMP232X_SCOPE_MAXVALIDX     (GMP232X_SCOPE_VALCNT - GMP232X_SCOPE_MAXSAMPLES)    /**< Highest possible index for a scope value */
/** @} */

/**
 * @name Constants used at GMP232X_HISTORY_ENTRY.EventID
 * @{
 */

#define GMP232X_HISTORY_FLAG_TRIP   0x8000   /**< bit flag */
#define GMP232X_HISTORY_FLAG_START  0x4000   /**< bit flag */
#define GMP232X_HISTORY_FLAG_SPARE  0x2000   /**< reserved */
#define GMP232X_HISTORY_FLAG_APPEAR 0x0100   /**< bit flag, entry appeared (1) or disappeared (0) */
/** @} */

/**
 * @name Constants used at GMP232X_SCOPECFG.SampleRate and GMP232X_SAMPLE_CONFIG.SampleRate
 * @{
 */

#define GMP232X_SCOPE_SAMPLE_100US  0    /**< Sample rate of    10kHz */
#define GMP232X_SCOPE_SAMPLE_200US  1    /**< Sample rate of     5kHz */
#define GMP232X_SCOPE_SAMPLE_400US  2    /**< Sample rate of   2.5kHz */
#define GMP232X_SCOPE_SAMPLE_800US  3    /**< Sample rate of  1.25kHz */
#define GMP232X_SCOPE_SAMPLE_1600US 4    /**< Sample rate of 0.625kHz */
/** @} */

/**
 * @name Constants used at GMP232X_SCOPECFG.ChanBitMask1
 * @{
 */

#define GMP232X_SCOPE_1_U_L1N_INST      0x00000001   /**< Flag for U L1N instantaneous scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L2N_INST      0x00000002   /**< Flag for U L2N instantaneous scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L3N_INST      0x00000004   /**< Flag for U L3N instantaneous scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L1L2_INST     0x00000008   /**< Flag for U L1L2 instantaneous scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L2L3_INST     0x00000010   /**< Flag for U L2L3 instantaneous scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L3L1_INST     0x00000020   /**< Flag for U L3L1 instantaneous scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_I_L1_INST       0x00000040   /**< Flag for I L1 instantaneous scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_I_L2_INST       0x00000080   /**< Flag for I L2 instantaneous scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_I_L3_INST       0x00000100   /**< Flag for I L3 instantaneous scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_I_N_INST        0x00000200   /**< Flag for I N instantaneous scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L1N_FRMS_FCS  0x00000400   /**< Flag for U L1N FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L2N_FRMS_FCS  0x00000800   /**< Flag for U L2N FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L3N_FRMS_FCS  0x00001000   /**< Flag for U L3N FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L1L2_FRMS_FCS 0x00002000   /**< Flag for U L1L2 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L2L3_FRMS_FCS 0x00004000   /**< Flag for U L2L3 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L3L1_FRMS_FCS 0x00008000   /**< Flag for U L3L1 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_I_L1_FRMS_FCS   0x00010000   /**< Flag for I L1 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_I_L2_FRMS_FCS   0x00020000   /**< Flag for I L2 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_I_L3_FRMS_FCS   0x00040000   /**< Flag for I L3 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_I_N_FRMS_FCS    0x00080000   /**< Flag for I N  FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L1N_FRMS_FCC  0x00100000   /**< Flag for U L1N FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L2N_FRMS_FCC  0x00200000   /**< Flag for U L2N FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L3N_FRMS_FCC  0x00400000   /**< Flag for U L3N FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L1L2_FRMS_FCC 0x00800000   /**< Flag for U L1L2 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L2L3_FRMS_FCC 0x01000000   /**< Flag for U L2L3 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L3L1_FRMS_FCC 0x02000000   /**< Flag for U L3L1 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_I_L1_FRMS_FCC   0x04000000   /**< Flag for I L1 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_I_L2_FRMS_FCC   0x08000000   /**< Flag for I L2 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_I_L3_FRMS_FCC   0x10000000   /**< Flag for I L3 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_I_N_FRMS_FCC    0x20000000   /**< Flag for I N FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L1N_TRMS_HCC  0x40000000   /**< Flag for U L1N TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
#define GMP232X_SCOPE_1_U_L2N_TRMS_HCC  0x80000000   /**< Flag for U L2N TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask1 */
/** @} */

/**
 * @name Constants used at GMP232X_SCOPECFG.ChanBitMask2
 * @{
 */

#define GMP232X_SCOPE_2_U_L3N_TRMS_HCC  0x00000001   /**< Flag for U L3N TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_U_L1L2_TRMS_HCC 0x00000002   /**< Flag for U L1L2 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_U_L2L3_TRMS_HCC 0x00000004   /**< Flag for U L2L3 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_U_L3L1_TRMS_HCC 0x00000008   /**< Flag for U L3L1 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_I_L1_TRMS_HCC   0x00000010   /**< Flag for I L1 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_I_L2_TRMS_HCC   0x00000020   /**< Flag for I L2 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_I_L3_TRMS_HCC   0x00000040   /**< Flag for I L3 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_I_N_TRMS_HCC    0x00000080   /**< Flag for I N TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_U_L1N_TRMS_HCS  0x00000100   /**< Flag for U L1N TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_U_L2N_TRMS_HCS  0x00000200   /**< Flag for U L2N TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_U_L3N_TRMS_HCS  0x00000400   /**< Flag for U L3N TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_U_L1L2_TRMS_HCS 0x00000800   /**< Flag for U L1L2 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_U_L2L3_TRMS_HCS 0x00001000   /**< Flag for U L2L3 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_U_L3L1_TRMS_HCS 0x00002000   /**< Flag for U L3L1 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_I_L1_TRMS_HCS   0x00004000   /**< Flag for I L1 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_I_L2_TRMS_HCS   0x00008000   /**< Flag for I L2 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_I_L3_TRMS_HCS   0x00010000   /**< Flag for I L3 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_I_N_TRMS_HCS    0x00020000   /**< Flag for I N TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_U_pos_FRMS_FCS  0x00040000   /**< Flag for Positive sequence system voltage used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_U_neg_FRMS_FCS  0x00080000   /**< Flag for Negative sequence system voltage used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_U_null_FRMS_FCS 0x00100000   /**< Flag for Zero sequence system voltage used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_I_pos_FRMS_FCS  0x00200000   /**< Flag for Positive sequence system current used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_I_neg_FRMS_FCS  0x00400000   /**< Flag for Negative sequence system current used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_I_null_FRMS_FCS 0x00800000   /**< Flag for Zero sequence system current used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_F               0x01000000   /**< Flag for frequency scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_f_avg           0x02000000   /**< Flag for average frequency scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_ROCOF           0x04000000   /**< Flag for ROCOF scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_PHI_U1U2        0x08000000   /**< Flag for PHI U1U2 scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_PHI_U2U3        0x10000000   /**< Flag for PHI U2U3 scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_PHI_U3U1        0x20000000   /**< Flag for PHI U3U1 scope value used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_PHI_UposUref    0x40000000   /**< Flag for Phi positive sequence system voltage phasor minus reference system phasor used in GMP232X_SCOPECFG.ChanBitMask2 */
#define GMP232X_SCOPE_2_PHI_UnegUref    0x80000000   /**< Flag for Phi negative sequence system voltage phasor minus reference system phasor used in GMP232X_SCOPECFG.ChanBitMask2 */
/** @} */

/**
 * @name Constants used at GMP232X_SCOPECFG.ChanBitMask3
 * @{
 */

#define GMP232X_SCOPE_3_PHI_UnullUref       0x00000001   /**< Flag for Phi zero sequence system voltage phasor minus reference system phasor used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_PHI_IposIref        0x00000002   /**< Flag for Phi positive sequence system current phasor minus reference system phasor used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_PHI_InegIref        0x00000004   /**< Flag for Phi negative sequence system current phasor minus reference system phasor used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_PHI_InullIref       0x00000008   /**< Flag for Phi zero sequence system current phasor minus reference system phasor used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_PHI_U1I1            0x00000010   /**< Flag for PHI U1I1 scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_PHI_U2I2            0x00000020   /**< Flag for PHI U2I2 scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_PHI_U3I3            0x00000040   /**< Flag for PHI U3I3 scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_L1_FRMS_FCS       0x00000080   /**< Flag for P L1 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_L2_FRMS_FCS       0x00000100   /**< Flag for P L2 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_L3_FRMS_FCS       0x00000200   /**< Flag for P L3 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_sumpos_FRMS_FCS   0x00000400   /**< Flag for Fundamental positive sequence system active power used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_sumneg_FRMS_FCS   0x00000800   /**< Flag for Fundamental negative sequence system active power used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_L1_FRMS_FCC       0x00001000   /**< Flag for P L1 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_L2_FRMS_FCC       0x00002000   /**< Flag for P L2 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_L3_FRMS_FCC       0x00004000   /**< Flag for P L3 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_sum2_FRMS_FCC     0x00008000   /**< Flag for P sum 2 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_L1_TRMS_HCS       0x00010000   /**< Flag for P L1 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_L2_TRMS_HCS       0x00020000   /**< Flag for P L2 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_L3_TRMS_HCS       0x00040000   /**< Flag for P L3 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_sum_TRMS_HCS      0x00080000   /**< Flag for P sum TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_L1_TRMS_HCC       0x00100000   /**< Flag for P L1 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_L2_TRMS_HCC       0x00200000   /**< Flag for P L2 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_L3_TRMS_HCC       0x00400000   /**< Flag for P L3 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_P_sum_TRMS_HCC      0x00800000   /**< Flag for P sum TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_Q_L1_FRMS_FCS       0x01000000   /**< Flag for Q L1 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_Q_L2_FRMS_FCS       0x02000000   /**< Flag for Q L2 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_Q_L3_FRMS_FCS       0x04000000   /**< Flag for Q L3 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_Q_sumpos_FRMS_FCS   0x08000000   /**< Flag for Fundamental positive sequence system reactive power used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_Q_sumneg_FRMS_FCS   0x10000000   /**< Flag for Fundamental negative sequence system reactive power used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_Q_L1_FRMS_FCC       0x20000000   /**< Flag for Q L1 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_Q_L2_FRMS_FCC       0x40000000   /**< Flag for Q L2 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
#define GMP232X_SCOPE_3_Q_L3_FRMS_FCC       0x80000000   /**< Flag for Q L3 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask3 */
/** @} */

/**
 * @name Constants used at GMP232X_SCOPECFG.ChanBitMask4
 * @{
 */

#define GMP232X_SCOPE_4_Q_sum2_FRMS_FCC     0x00000001   /**< Flag for Q sum2 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_Q_L1_TRMS_HCS       0x00000002   /**< Flag for Q L1 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_Q_L2_TRMS_HCS       0x00000004   /**< Flag for Q L2 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_Q_L3_TRMS_HCS       0x00000008   /**< Flag for Q L3 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_Q_sum_TRMS_HCS      0x00000010   /**< Flag for Q sum TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_Q_L1_TRMS_HCC       0x00000020   /**< Flag for Q L1 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_Q_L2_TRMS_HCC       0x00000040   /**< Flag for Q L2 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_Q_L3_TRMS_HCC       0x00000080   /**< Flag for Q L3 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_Q_sum_TRMS_HCC      0x00000100   /**< Flag for Q sum TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_L1_FRMS_FCS       0x00000200   /**< Flag for S L1 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_L2_FRMS_FCS       0x00000400   /**< Flag for S L2 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_L3_FRMS_FCS       0x00000800   /**< Flag for S L3 FRMS FCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_sumpos_FRMS_FCS   0x00001000   /**< Flag for Fundamental positive sequence system apparent power used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_L1_FRMS_FCC       0x00002000   /**< Flag for S L1 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_L2_FRMS_FCC       0x00004000   /**< Flag for S L2 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_L3_FRMS_FCC       0x00008000   /**< Flag for S L3 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_sum2_FRMS_FCC     0x00010000   /**< Flag for S sum2 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_L1_TRMS_HCS       0x00020000   /**< Flag for S L1 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_L2_TRMS_HCS       0x00040000   /**< Flag for S L2 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_L3_TRMS_HCS       0x00080000   /**< Flag for S L3 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_sum_TRMS_HCS      0x00100000   /**< Flag for S sum TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_L1_TRMS_HCC       0x00200000   /**< Flag for S L1 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_L2_TRMS_HCC       0x00400000   /**< Flag for S L2 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_L3_TRMS_HCC       0x00800000   /**< Flag for S L3 TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_S_sum_TRMS_HCC      0x01000000   /**< Flag for S sum TRMS HCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_COSPHI_pos_FRMS_FCS 0x02000000   /**< Flag for Cos-Phi of fundamental positive sequence system powers used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_COSPHI_L1_FRMS_FCC  0x04000000   /**< Flag for COSPHI L1 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_COSPHI_L2_FRMS_FCC  0x08000000   /**< Flag for COSPHI L2 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_COSPHI_L3_FRMS_FCC  0x10000000   /**< Flag for COSPHI L3 FRMS FCC scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_PF_L1_TRMS_HCS      0x20000000   /**< Flag for power factor L1 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_PF_L2_TRMS_HCS      0x40000000   /**< Flag for power factor L2 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
#define GMP232X_SCOPE_4_PF_L3_TRMS_HCS      0x80000000   /**< Flag for power factor L3 TRMS HCS scope value used in GMP232X_SCOPECFG.ChanBitMask4 */
/** @} */

/**
 * @name Constants used at GMP232X_SCOPECFG.ChanBitMask5
 * @{
 */

#define GMP232X_SCOPE_5_PF_sum_TRMS_HCS 0x00000001   /**< Flag for power factor sum (TRMS_HCS) scope value used in GMP232X_SCOPECFG.ChanBitMask5 */
#define GMP232X_SCOPE_5_ASYM_U          0x00000002   /**< Flag for Voltage asymmetry scope value used in GMP232X_SCOPECFG.ChanBitMask5 */
#define GMP232X_SCOPE_5_ASYM_I          0x00000004   /**< Flag for Current asymmetry scope value used in GMP232X_SCOPECFG.ChanBitMask5 */
#define GMP232X_SCOPE_5_F2              0x00000008   /**< Flag for frequency 2 scope value used in GMP232X_SCOPECFG.ChanBitMask5 */
#define GMP232X_SCOPE_5_DOR_1_STATE     0x00000010   /**< Flag for state of relay 1 scope value used in GMP232X_SCOPECFG.ChanBitMask5 */
#define GMP232X_SCOPE_5_DOR_2_STATE     0x00000020   /**< Flag for state of relay 2 scope value used in GMP232X_SCOPECFG.ChanBitMask5 */
/** @} */

/**
 * @name Possible values for GMP232X_CONFIG.HistoryLoggingMode
 * @{
 */

#define GMP232X_HISTORY_MODE_TRIP_ONLY      0    /**< log Trip entries only */
#define GMP232X_HISTORY_MODE_START_AND_TRIP 1    /**< log Start and trip entries */
/** @} */

/**
 * @name Possible values for GMP232X_CONFIG.AveragingPeriodMode
 * @{
 */

#define GMP232X_AVG_MODE_FIXED_TIME     0    /**< fixed time mode */
#define GMP232X_AVG_MODE_FIXED_PERIOD   1    /**< fixed period mode */
/** @} */

/**
 * @name Possible values for GMP232X_CONFIG.FreqAvgMode
 * @{
 */

#define GMP232X_AVG_MODE_F_NONE         0    /**< No mean calculation */
#define GMP232X_AVG_MODE_F_MOVING       1    /**< Moving average calculation */
#define GMP232X_AVG_MODE_F_SEQUENTIAL   2    /**< Sequential average calculation */
/** @} */

/**
 * @name GMP232X_CONFIG.HarmonicVoltageRef / GMP232X_CONFIG.HarmonicCurrentRef
 * @{
 */

#define GMP232X_HARMONICS_REF_NOMINAL       0    /**< use rated value as harmonic percentage reference */
#define GMP232X_HARMONICS_REF_FUNDAMENTAL   1    /**< use fundamental value as harmonic percentage reference */
/** @} */

/**
 * @name Possible values for GMP232X_CONFIG.AsymModeU and GMP232X_CONFIG.AsymModeI
 * @{
 */

#define GMP232X_ASYM_REF_POS        0    /**< Asymmetric counter system to positive sequence system */
#define GMP232X_ASYM_REF_DEFAULT    1    /**< Asymmetric counter system to nominal value */
/** @} */

/**
 * @name Possible values for GMP232X_CONFIG.PowerFactorMode
 * @{
 */

#define GMP232X_PF_MODE_DIN40110    0    /**< Powerfactor Mode DIN40110: PF =  |P|/S; [0 - 1000] */
#define GMP232X_PF_MODE_IEC61400_21 1    /**< Powerfactor Mode IEC61400-21: PF =  P/S; [-1000 - 1000] */
#define GMP232X_PF_MODE_2           2    /**< Powerfactor Mode 2: PF =  1-SIGN(Q)*(1-ABS(P)/S); [0 - 2000] */
#define GMP232X_PF_MODE_3           3    /**< Powerfactor Mode 3: PF =  SIGN(Q)*(1-ABS(P)/S); [-1000 - 1000] */
#define GMP232X_PF_MODE_4           4    /**< Powerfactor Mode 4: PF = -SIGN(Q)*ABS(P)/S; [-1000 - 1000] */
#define GMP232X_PF_MODE_5           5    /**< Powerfactor Mode 5: PF =  SIGN(Q)*ABS(P)/S; [-1000 - 1000] */
/** @} */

/**
 * @name Possible values for GMP232X_CONFIG.ROCOF_source
 * @{
 */

#define GMP232X_ROCOF_SOURCE_f  0    /**< ROCOF signal source f */
#define GMP232X_ROCOF_SOURCE_f2 1    /**< ROCOF signal source f2 */
/** @} */

/**
 * @name Maximum number of sample values
 * @{
 */

#define GMP232X_SAMPLE_BUFFERSIZE   33   /**< Size of sample storage (see GMP232X_SAMPLE_REQUEST), max. number of samples */
/** @} */

/**
 * @name Mean specific defines
 * @{
 */

#define GMP232X_MEAN_MAXCHAN    24   /**< Maximal number of channels configurable for averager 1 and 2 */
/** @} */

/**
 * @name Possible values for GMP232X_LIMIT_V.Source selection (TRMS or FRMS) and parameter SourceSelect at MIO_CMD_GMP232X_G/SETENERGY, MIO_CMD_GMP232X_G/SETENERGY_REAL
 * @{
 */

#define GMP232X_SOURCE_TRMS 0    /**< True RMS */
#define GMP232X_SOURCE_FRMS 1    /**< Fundamental RMS */
/** @} */

/**
 * @name Possible values for GMP232X_LIMIT_FREQ.Source selection
 * @{
 */

#define GMP232X_SOURCE_F        2    /**< Frequency */
#define GMP232X_SOURCE_F_AVG    3    /**< Frequency average */
#define GMP232X_SOURCE_F2       4    /**< Frequency 2 */
/** @} */

/**
 * @name Possible maximum number for harmonics
 * @{
 */

#define GMP232X_MAX_HARMONICS   50   /**< Used in GMP232X_HARMONICS only! */
/** @} */

/**
 * @name Defines used as ValueIdx at MIO_CMD_GMP232X_GETHARMONICS
 * @{
 */

#define GMP232X_HARMONICS_U_L1  0    /**< Harmonics value index for U L1 */
#define GMP232X_HARMONICS_U_L2  1    /**< Harmonics value index for U L2 */
#define GMP232X_HARMONICS_U_L3  2    /**< Harmonics value index for U L3 */
#define GMP232X_HARMONICS_I_L1  3    /**< Harmonics value index for I L1 */
#define GMP232X_HARMONICS_I_L2  4    /**< Harmonics value index for I L2 */
#define GMP232X_HARMONICS_I_L3  5    /**< Harmonics value index for I L3 */
/** @} */

/**
 * @name Maximum number for history entries
 * @{
 */

#define GMP232X_HISTORY_MAXENTRIES  2048     /**< Size of history entry storage */
/** @} */

/**
 * @name Number of compensation points
 * @{
 */

#define GMP232X_CT_COMPENSATION_POINTCOUNT  16   /**< Number of CT compensation points */
/** @} */

/**
 * @name CT Compensation table: percent to index mapping. Percent of rated current (100% for variant /1 and /2 = 1A,  /3 and /4 = 5A)
 * @{
 */

#define GMP232X_IDX_CT_COMPENSATION_CURRENT_1_PERCENT   0    /**< Index for CT compensation point 1 at 1 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_5_PERCENT   1    /**< Index for CT compensation point 2 at 5 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_10_PERCENT  2    /**< Index for CT compensation point 3 at 10 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_20_PERCENT  3    /**< Index for CT compensation point 4 at 20 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_30_PERCENT  4    /**< Index for CT compensation point 5 at 30 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_40_PERCENT  5    /**< Index for CT compensation point 6 at 40 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_50_PERCENT  6    /**< Index for CT compensation point 7 at 50 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_60_PERCENT  7    /**< Index for CT compensation point 8 at 60 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_70_PERCENT  8    /**< Index for CT compensation point 9 at 70 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_80_PERCENT  9    /**< Index for CT compensation point 10 at 80 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_90_PERCENT  10   /**< Index for CT compensation point 11 at 90 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_100_PERCENT 11   /**< Index for CT compensation point 12 at 100 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_120_PERCENT 12   /**< Index for CT compensation point 13 at 120 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_150_PERCENT 13   /**< Index for CT compensation point 14 at 150 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_200_PERCENT 14   /**< Index for CT compensation point 15 at 200 percent */
#define GMP232X_IDX_CT_COMPENSATION_CURRENT_400_PERCENT 15   /**< Index for CT compensation point 16 at 400 percent */
/** @} */
/** @} */
/**
 * GMP232X Configuration (deprecated with GMP232X Driver V1.01R) @deprecated
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETCONFIG / MIO_CMD_GMP232X_SETCONFIG
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  Mode;               /**< Operating mode (#GMP232X_M_2WIRE1PHASE_LN or similar); enum */
    UINT32  Frequency;          /**< Nominal frequency in Hz, 50 or 60; number */
    UINT32  PTPrimary;          /**< Rated voltage primary side in V; represents 100% for pu values and alarms; [1 - 4294967295]; 1V */
    UINT32  PTSecondary;        /**< Voltage secondary side in mV when primary has rated value; [3600 - 1173000]; 1mV */
    UINT32  CTPrimary;          /**< Rated current primary side in A; represents 100% for pu values and alarms; [1 - 4294967295]; 1A */
    UINT32  CTSecondary;        /**< Current secondary side in mA when primary has rated value; [1 - 10000]; 1mA */
    UINT32  HarmonicVoltageRef; /**< Harmonic voltage percent reference value (#GMP232X_HARMONICS_REF_NOMINAL or similar); enum */
    UINT32  HarmonicCurrentRef; /**< Harmonic current percent reference value (#GMP232X_HARMONICS_REF_NOMINAL or similar); enum */
    UINT32  Variant;            /**< Module variant (#MIO_V_GMP232_1 or similar); enum */
    UINT32  AveragerPeriodMode; /**< Period setting for all Averagers (#GMP232X_AVG_MODE_F_NONE or similar); enum */
    UINT32  Averager1Interval;  /**< Averager1 fixed frame window time; [2 - 600]; 0.1s */
    UINT32  Averager2Factor;    /**< Averager2 fixed frame window time; [1 - 120]; number of Averager1 intervals */
    UINT32  Averager3Interval;  /**< Averager3 (Harmonics) fixed frame window time; [30 - 9000]; 0.1s */
    UINT32  FreqAvgMode;        /**< Frequency average calculation mode (#GMP232X_AVG_MODE_F_NONE or similar); enum */
    UINT32  FreqAvgParam;       /**< Measuring value [1 - 120] (for Moving Average) or milliseconds [200 - 1000] (for Sequential Average); 1value or 1msec */
    UINT32  ROCOFAvgValues;     /**< Number of measuring values used for ROCOF calculation; [2 - 240]; 1value */
    BOOL32  AutoResetEnable1;   /**< Relay auto reset enable for relay 1; bool */
    BOOL32  AutoResetEnable2;   /**< Relay auto reset enable for relay 2; bool */
    UINT32  AutoResetDelay1;    /**< Reset time for the relay 1; [0 - 120000]; 1msec */
    UINT32  AutoResetDelay2;    /**< Reset time for the relay 2; [0 - 120000]; 1msec */
    BOOL32  RuntimeConfiguration;    /**< If true, module is NOT configured automatically at startup; bool */
    UINT32  HistoryLoggingMode; /**< Alarm history log setting (#GMP232X_HISTORY_MODE_TRIP_ONLY or similar); enum */
    UINT32  AsymRefModeU;       /**< Asymmetric counter system reference for voltage (#GMP232X_ASYM_REF_POS or similar); enum */
    UINT32  AsymRefModeI;       /**< Asymmetric counter system reference for current (#GMP232X_ASYM_REF_POS or similar); enum */
    UINT32  PowerFactorMode;    /**< Powerfactor mode (#GMP232X_PF_MODE_DIN40110 or similar); enum */
    UINT32  ROCOFSource;        /**< Source selector for ROCOF (#GMP232X_ROCOF_SOURCE_f or similar); enum */
} GMP232X_CONFIG;

/**
 * @brief To correlate the current in percent with the index of a certain interpolation node,
 * use the defines #GMP232X_IDX_CT_COMPENSATION_CURRENT_1_PERCENT or similar.
 * @since V1.01 Release
 */
typedef struct
{
    UINT32  PhaseCorrection;    /**< Phase correction value for current interpolation node; [0 - 35000]; 0.0001 degrees; (0) */
    UINT32  AmplitudeFactor;    /**< Amplitude factor for current interpolation node; [9500 - 10500]; 0.0001; (10000) */
} GMP232X_CT_COMPENSATION_POINT;

/**
 * GMP232X Configuration with extended capabilities (use this instead of GMP232X_CONFIG because GMP232X_CONFIG is deprecated with GMP232X Driver V1.01R)
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETCONFIG_EXT / MIO_CMD_GMP232X_SETCONFIG_EXT
 * @since V1.00 Release
 */
typedef struct
{
    UINT32                          Mode;    /**< Operating mode (#GMP232X_M_2WIRE1PHASE_LN or similar); enum */
    UINT32                          Frequency;   /**< Nominal frequency in Hz, 50 or 60; number */
    UINT32                          PTPrimary;   /**< Rated voltage primary side in V; represents 100% for pu values and alarms; [1 - 4294967295]; 1V */
    UINT32                          PTSecondary;     /**< Voltage secondary side in mV when primary has rated value; [3600 - 1173000]; 1mV */
    UINT32                          CTPrimary;   /**< Rated current primary side in A; represents 100% for pu values and alarms; [1 - 4294967295]; 1A */
    UINT32                          CTSecondary;     /**< Current secondary side in mA when primary has rated value; [1 - 10000]; 1mA */
    UINT32                          HarmonicVoltageRef;  /**< Harmonic voltage percent reference value (#GMP232X_HARMONICS_REF_NOMINAL or similar); enum */
    UINT32                          HarmonicCurrentRef;  /**< Harmonic current percent reference value (#GMP232X_HARMONICS_REF_NOMINAL or similar); enum */
    UINT32                          Variant;     /**< Module variant (#MIO_V_GMP232_1 or similar); enum */
    UINT32                          AveragerPeriodMode;  /**< Period setting for all Averagers (#GMP232X_AVG_MODE_F_NONE or similar); enum */
    UINT32                          Averager1Interval;   /**< Averager1 fixed frame window time; [2 - 600]; 0.1s */
    UINT32                          Averager2Factor;     /**< Averager2 fixed frame window time; [1 - 120]; number of Averager1 intervals */
    UINT32                          Averager3Interval;   /**< Averager3 (Harmonics) fixed frame window time; [30 - 9000]; 0.1s */
    UINT32                          FreqAvgMode;     /**< Frequency average calculation mode (#GMP232X_AVG_MODE_F_NONE or similar); enum */
    UINT32                          FreqAvgParam;    /**< Measuring value [1 - 120] (for Moving Average) or milliseconds [200 - 1000] (for Sequential Average); 1value or 1msec */
    UINT32                          ROCOFAvgValues;  /**< Number of measuring values used for ROCOF calculation; [2 - 240]; 1value; (60) */
    BOOL32                          AutoResetEnable1;    /**< Relay auto reset enable for relay 1; bool */
    BOOL32                          AutoResetEnable2;    /**< Relay auto reset enable for relay 2; bool */
    UINT32                          AutoResetDelay1;     /**< Reset time for the relay 1; [0 - 120000]; 1msec */
    UINT32                          AutoResetDelay2;     /**< Reset time for the relay 2; [0 - 120000]; 1msec */
    BOOL32                          RuntimeConfiguration;    /**< If true, module is NOT configured automatically at startup; bool */
    UINT32                          HistoryLoggingMode;  /**< Alarm history log setting (#GMP232X_HISTORY_MODE_TRIP_ONLY or similar); enum */
    UINT32                          AsymRefModeU;    /**< Asymmetric counter system reference for voltage (#GMP232X_ASYM_REF_POS or similar); enum */
    UINT32                          AsymRefModeI;    /**< Asymmetric counter system reference for current (#GMP232X_ASYM_REF_POS or similar); enum */
    UINT32                          PowerFactorMode;     /**< Powerfactor mode (#GMP232X_PF_MODE_DIN40110 or similar); enum */
    UINT32                          ROCOFSource;     /**< Source selector for ROCOF (#GMP232X_ROCOF_SOURCE_f or similar); enum */
    BOOL32                          FreqCalcULNEnable;   /**< Enable calculation of frequency for ULN zero crossings; bool */
    BOOL32                          FreqCalcULLEnable;   /**< Enable calculation of frequency for ULL zero crossings; bool */
    UINT32                          UpdateBlockingTimeF2;    /**< Blocking time after vectorjump for frequency 2; [0 - 200]; 1msec; (40) */
    UINT32                          StartupInhibitTime;  /**< Automatic supression for limit detection on startup; [0 - 60000]; 1msec; (500) */
    /**
     * Interpolation nodes for the compensation of the external current transformer
     * (see also: #GMP232X_IDX_CT_COMPENSATION_CURRENT_1_PERCENT or similar); not used in ver <= 1.01R
     */
    GMP232X_CT_COMPENSATION_POINT   CTCompensationPoints[GMP232X_CT_COMPENSATION_POINTCOUNT];
    UINT32                          Spare1;  /**< Spare data field, not used in ver <= 1.01R, must be 0 */
    UINT32                          Spare2;  /**< Spare data field, not used in ver <= 1.01R, must be 0 */
    UINT32                          Spare3;  /**< Spare data field, not used in ver <= 1.01R, must be 0 */
} GMP232X_CONFIG_EXT;

/**
 * Simulation Data
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETSIMDATA / MIO_CMD_GMP232X_GETSIMDATA
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  U_L1;               /**< Voltage; [0-15000]; 0.1% of rated voltage */
    UINT32  U_L2;               /**< Voltage; [0-15000]; 0.1% of rated voltage */
    UINT32  U_L3;               /**< Voltage; [0-15000]; 0.1% of rated voltage */
    UINT32  I_L1;               /**< Current; [0-15000]; 0.1% of rated current */
    UINT32  I_L2;               /**< Current; [0-15000]; 0.1% of rated current */
    UINT32  I_L3;               /**< Current; [0-15000]; 0.1% of rated current */
    UINT32  f;                  /**< Frequency (0 Hz - (configured nominal frequency +15Hz)); 0.01Hz */
    UINT32  Phi_U_L1;           /**< Phase U L1; [0-3600]; 0.1 degrees */
    UINT32  Phi_U_L2;           /**< Phase U L2; [0-3600]; 0.1 degrees */
    UINT32  Phi_U_L3;           /**< Phase U L3; [0-3600]; 0.1 degrees */
    UINT32  Phi_I_L1;           /**< Phase I L1; [0-3600]; 0.1 degrees */
    UINT32  Phi_I_L2;           /**< Phase I L2; [0-3600]; 0.1 degrees */
    UINT32  Phi_I_L3;           /**< Phase I L3; [0-3600]; 0.1 degrees */
} GMP232X_SIMDATA;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETHARMONICS
 * Harmonics, Voltage and current harmonics
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  Value[GMP232X_MAX_HARMONICS];    /**< Harmonic values (see also GMP232X_CONFIG.HarmonicVoltageRef/HarmonicCurrentRef); 0.1% */
    UINT32  THD;                /**< THD_U (reference fundamental voltage) or THD_I (reference fundamental current); 0.01% */
    UINT32  THDn_TDD;           /**< THDn_U (reference is rated voltage) or TDD_I (reference rated current); 0.01% */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_HARMONICS;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETSCOPE
 * scope sample within scope data
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  Timestamp;          /**< Timestamp relative to beginning of scope record; tbd */
    REAL64  Data[GMP232X_SCOPE_MAXCHAN];     /**< Recorded values */
} GMP232X_SCOPE_SAMPLE;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETSCOPE
 * scope data structure
 * @since V1.00 Release
 */
typedef struct
{
    GMP232X_SCOPE_SAMPLE    Samples[GMP232X_SCOPE_MAXSAMPLES];   /**< Scope data samples */
} GMP232X_SCOPE_DATA;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETSCOPECFG / MIO_CMD_GMP232X_GETSCOPECFG
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  ChanBitMask1;       /**< Bit mask 1 of enabled channels. (#GMP232X_SCOPE_1_U_L1N_INST or similar); bitfield */
    UINT32  ChanBitMask2;       /**< Bit mask 2 of enabled channels. (#GMP232X_SCOPE_2_U_L3N_TRMS_HCC or similar); bitfield */
    UINT32  ChanBitMask3;       /**< Bit mask 3 of enabled channels. (#GMP232X_SCOPE_3_PHI_UnullUref or similar); bitfield */
    UINT32  ChanBitMask4;       /**< Bit mask 4 of enabled channels. (#GMP232X_SCOPE_4_Q_sum2_FRMS_FCC or similar); bitfield */
    UINT32  ChanBitMask5;       /**< Bit mask 5 of enabled channels. (#GMP232X_SCOPE_5_PF_sum_TRMS_HCS or similar); bitfield */
    UINT32  SampleRate;         /**< Sample rate (#GMP232X_SCOPE_SAMPLE_100US or similar constants); enum */
    UINT32  Pretrigger;         /**< Number of scope samples elements prior to trigger, [0 up to #GMP232X_SCOPE_VALCNT]; number */
} GMP232X_SCOPE_CONFIG;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETSCOPESTATE
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  State;              /**< One of the GMP232X_SCOPE_STATE_ constants; enum */
    UINT32  PretriggerCount;    /**< Number of scope samples elements prior to trigger; number */
    UINT32  Timestamp_s;        /**< Timestamp seconds; 1sec since 1.1.1970 0:00 */
    UINT32  Timestamp_ms;       /**< Timestamp milliseconds; 1msec */
    UINT32  TriggerEvent;       /**< Event that caused scope recording (see GMP232X_HISTORY_ENTRY.EventID); enum */
} GMP232X_SCOPE_STATE;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_TAKEHISTORYLOCK
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  LockHandle;         /**< Lock handle; handle */
    UINT32  ActNbEntries;       /**< Number of entries stored the history, [0 up to GMP232X_HISTORY_MAXENTRIES]; number */
    UINT32  TotalNbEntries;     /**< Total number of entries since last history deletion, [0 up to infinite]; number */
} GMP232X_HISTORY_LOCK;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETALARMHISTORY
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  Timestamp_s;        /**< Timestamp seconds; 1sec since 1.1.1970 0:00 */
    UINT32  Timestamp_ms;       /**< Timestamp milliseconds; 1msec */
    UINT32  EventID;            /**< contains event id (#GMP232X_LIM_1_V_LO1 or similar) and possibly some flags (#GMP232X_HISTORY_FLAG_TRIP or similar); enum */
} GMP232X_HISTORY_ENTRY;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_FFRT / MIO_CMD_GMP232X_GETLIMIT_FFRT
 * Frequency point data structure used within GMP232X_LIMIT_FFRT
 * @since V1.01 Release
 */
typedef struct
{
    UINT32  Frequency;          /**< frequency; [10000 - 75000]; 1mHz; (10000) */
    UINT32  TimeMs;             /**< time; [0 - 600000]; 1msec; (0) */
} GMP232X_FREQPOINT;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_VFRT / MIO_CMD_GMP232X_GETLIMIT_VFRT
 * Voltage point data structure used within GMP232X_LIMIT_VFRT
 * @since V1.01 Release
 */
typedef struct
{
    UINT32  Voltage;            /**< value, [0 - 4000]; 0.1% pu(U); (0) */
    UINT32  TimeMs;             /**< time, [0 - 600000]; 1msec; (0) */
} GMP232X_VOLTAGEPOINT;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETENERGY / MIO_CMD_GMP232X_GETENERGY
 * Data structure for energy values
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  ActiveEnergyRcv_xRMS_xCS;    /**< Active energy received for TRMS/FRMS; Wh */
    REAL64  ActiveEnergyDel_xRMS_xCS;    /**< Active energy delivered for TRMS/FRMS; Wh */
    REAL64  ReactiveEnergyRcv_xRMS_xCS;  /**< Reactive energy received for TRMS/FRMS; VARh */
    REAL64  ReactiveEnergyDel_xRMS_xCS;  /**< Reactive energy delivered for TRMS/FRMS; VARh */
} GMP232X_ENERGY;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GET_FRMS_FCS / MIO_CMD_GMP232X_VRW_SETFRMS_FCS
 * Fundamental RMS values, RMS window length is full cycle (T), calculation cycle is half grid cycle (T/2)
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  U_L1N_FRMS_FCS;     /**< Voltage L1N FRMS FCS; 1V */
    REAL64  U_L2N_FRMS_FCS;     /**< Voltage L2N FRMS FCS; 1V */
    REAL64  U_L3N_FRMS_FCS;     /**< Voltage L3N FRMS FCS; 1V */
    REAL64  I_L1_FRMS_FCS;      /**< Current L1 FRMS FCS; 1A */
    REAL64  I_L2_FRMS_FCS;      /**< Current L2 FRMS FCS; 1A */
    REAL64  I_L3_FRMS_FCS;      /**< Current L3 FRMS FCS; 1A */
    REAL64  I_N_FRMS_FCS;       /**< Current N FRMS FCS; 1A */
    REAL64  U_L1L2_FRMS_FCS;    /**< Voltage L1L2 FRMS FCS; 1V */
    REAL64  U_L2L3_FRMS_FCS;    /**< Voltage L2L3 FRMS FCS; 1V */
    REAL64  U_L3L1_FRMS_FCS;    /**< Voltage L3L1 FRMS FCS; 1V */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_FRMS_FCS_VALUES;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GET_TRMS_HCS, MIO_CMD_GMP232X_VRW_SETTRMS_HCS
 * True RMS values, RMS window length is half cycle (T), calculation cycle is half grid cycle (T/2)
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  U_L1N_TRMS_HCS;     /**< Voltage L1N TRMS HCS; 1V */
    REAL64  U_L2N_TRMS_HCS;     /**< Voltage L1N TRMS HCS; 1V */
    REAL64  U_L3N_TRMS_HCS;     /**< Voltage L1N TRMS HCS; 1V */
    REAL64  I_L1_TRMS_HCS;      /**< Current L1 TRMS HCS; 1A */
    REAL64  I_L2_TRMS_HCS;      /**< Current L2 TRMS HCS; 1A */
    REAL64  I_L3_TRMS_HCS;      /**< Current L3 TRMS HCS; 1A */
    REAL64  I_N_TRMS_HCS;       /**< Current N TRMS HCS; 1A */
    REAL64  U_L1L2_TRMS_HCS;    /**< Voltage L1L2 TRMS HCS; 1V */
    REAL64  U_L2L3_TRMS_HCS;    /**< Voltage L2L3 TRMS HCS; 1V */
    REAL64  U_L3L1_TRMS_HCS;    /**< Voltage L3L1 TRMS HCS; 1V */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_TRMS_HCS_VALUES;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GET_FRMS_FCC, MIO_CMD_GMP232X_VRW_SETFRMS_FCC
 * Fundamental RMS values, RMS window length is full cycle (T), calculation cycle is continuous per sample
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  U_L1N_FRMS_FCC;     /**< Voltage L1N FRMS FCC; 1V */
    REAL64  U_L2N_FRMS_FCC;     /**< Voltage L2N FRMS FCC; 1V */
    REAL64  U_L3N_FRMS_FCC;     /**< Voltage L3N FRMS FCC; 1V */
    REAL64  I_L1_FRMS_FCC;      /**< Current L1 FRMS FCC; 1A */
    REAL64  I_L2_FRMS_FCC;      /**< Current L2 FRMS FCC; 1A */
    REAL64  I_L3_FRMS_FCC;      /**< Current L3 FRMS FCC; 1A */
    REAL64  I_N_FRMS_FCC;       /**< Current N FRMS FCC; 1A */
    REAL64  U_L1L2_FRMS_FCC;    /**< Voltage L1L2 FRMS FCC; 1V */
    REAL64  U_L2L3_FRMS_FCC;    /**< Voltage L2L3 FRMS FCC; 1V */
    REAL64  U_L3L1_FRMS_FCC;    /**< Voltage L3L1 FRMS FCC; 1V */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_FRMS_FCC_VALUES;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GET_TRMS_HCC, MIO_CMD_GMP232X_VRW_SETTRMS_HCC
 * True RMS values, RMS window length is half cycle (T), calculation cycle is continuous per sample
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  U_L1N_TRMS_HCC;     /**< Voltage L1N TRMS HCC; 1V */
    REAL64  U_L2N_TRMS_HCC;     /**< Voltage L2N TRMS HCC; 1V */
    REAL64  U_L3N_TRMS_HCC;     /**< Voltage L3N TRMS HCC; 1V */
    REAL64  I_L1_TRMS_HCC;      /**< Current L1 TRMS HCC; 1A */
    REAL64  I_L2_TRMS_HCC;      /**< Current L2 TRMS HCC; 1A */
    REAL64  I_L3_TRMS_HCC;      /**< Current L3 TRMS HCC; 1A */
    REAL64  I_N_TRMS_HCC;       /**< Current N TRMS HCC; 1A */
    REAL64  U_L1L2_TRMS_HCC;    /**< Voltage L1L2 TRMS HCC; 1V */
    REAL64  U_L2L3_TRMS_HCC;    /**< Voltage L2L3 TRMS HCC; 1V */
    REAL64  U_L3L1_TRMS_HCC;    /**< Voltage L3L1 TRMS HCC; 1V */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_TRMS_HCC_VALUES;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETSWITCHCOUNT
 * Data structure for switch counts
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  Relay1_Cycle;       /**< Cycle count of GMP232X_RELAY_1; number */
    UINT32  Relay2_Cycle;       /**< Cycle count of GMP232X_RELAY_2; number */
    UINT32  Relay_State;        /**< Relay state (#GMP232X_RELAY_NONE or similar); enum */
} GMP232X_SWITCHCOUNT;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETSAMPLECFG / MIO_CMD_GMP232X_GETSAMPLECFG
 * Configuration structure for samples
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  SampleRate;         /**< Sample rate (#GMP232X_SCOPE_SAMPLE_100US or similar*); enum */
} GMP232X_SAMPLE_CONFIG;

/**
 * Structure for DoCmd-function
 * MIO_CMD_GMP232X_GETSAMPLES / MIO_CMD_GMP232X_GETPENDINGSAMPLES / MIO_CMD_GMP232X_GETLATESTSAMPLE
 * Data structure for sample values
 * @since V1.00 Release
 */
typedef struct
{
    UINT64  Timestamp;          /**< Timestamp of the sample; 1us */
    REAL64  U_L1_INST;          /**< Voltage Phase to ground instantaneous value; 1V */
    REAL64  U_L2_INST;          /**< Voltage Phase to ground instantaneous value; 1V */
    REAL64  U_L3_INST;          /**< Voltage Phase to ground instantaneous value; 1V */
    REAL64  I_L1_INST;          /**< Current instantaneous value; 1A */
    REAL64  I_L2_INST;          /**< Current instantaneous value; 1A */
    REAL64  I_L3_INST;          /**< Current instantaneous value; 1A */
    REAL64  U_L1L2_INST;        /**< Voltage Phase to phase instantaneous value; 1V */
    REAL64  U_L2L3_INST;        /**< Voltage Phase to phase instantaneous value; 1V */
    REAL64  U_L3L1_INST;        /**< Voltage Phase to phase instantaneous value; 1V */
    REAL64  I_LN_INST;          /**< Current instantaneous value; 1A */
} GMP232X_SAMPLE_VAL;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETSAMPLES
 * Data structure to build a sample request
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  StartIdx;           /**< Index to start reading samples from [0-(GMP232X_SAMPLE_BUFFERSIZE-1)] */
    UINT32  NumSamples;         /**< Number of samples to be read [0-GMP232X_SAMPLE_BUFFERSIZE] */
} GMP232X_SAMPLE_REQUEST;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETPHASE_REF, MIO_CMD_GMP232X_VRW_SETPHASE_REF
 * Data structure for phase reference
 * @since V1.00 Release
 */
typedef struct
{
    SINT32  PHI_UposUref;       /**< Phi positive sequence system voltage phasor minus reference system phasor; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_UnegUref;       /**< Phi negative sequence system voltage phasor minus reference system phasor; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_UnullUref;      /**< Phi zero sequence system voltage phasor minus reference system phasor; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_IposIref;       /**< Phi positive sequence system current phasor minus reference system phasor; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_InegIref;       /**< Phi negative sequence system current phasor minus reference system phasor; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_InullIref;      /**< Phi zero sequence system current phasor minus reference system phasor; [-179999 - 180000]; 0.001 degrees */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_PHASEREF;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETPHASE_REF_S
 * Lower resolution variant of MIO_CMD_GMP232X_GETPHASE_REF
 * @since V1.00 Release
 */
typedef struct
{
    SINT32  PHI_UposUref;       /**< Phi positive sequence system voltage phasor minus reference system phasor; [-17999 - 18000]; 0.01 degrees */
    SINT32  PHI_UnegUref;       /**< Phi negative sequence system voltage phasor minus reference system phasor; [-17999 - 18000]; 0.01 degrees */
    SINT32  PHI_UnullUref;      /**< Phi zero sequence system voltage phasor minus reference system phasor; [-17999 - 18000]; 0.01 degrees */
    SINT32  PHI_IposIref;       /**< Phi positive sequence system current phasor minus reference system phasor; [-17999 - 18000]; 0.01 degrees */
    SINT32  PHI_InegIref;       /**< Phi negative sequence system current phasor minus reference system phasor; [-17999 - 18000]; 0.01 degrees */
    SINT32  PHI_InullIref;      /**< Phi zero sequence system current phasor minus reference system phasor; [-17999 - 18000]; 0.01 degrees */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_PHASEREF_S;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETPHASE
 * Data structure for phase values
 * @since V1.00 Release
 */
typedef struct
{
    SINT32  PHI_U1U2;           /**< Phi U1U2; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U2U3;           /**< Phi U2U3; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U3U1;           /**< Phi U3U1; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U1I1;           /**< Phi U1I1; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U2I2;           /**< Phi U2I2; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U3I3;           /**< Phi U3I3; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U12U23;         /**< Phi U12U23; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U23U31;         /**< Phi U23U31; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U31U12;         /**< Phi U31U12; [-179999 - 180000]; 0.001 degrees */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_PHASE;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETROCOF_ROTDIR, MIO_CMD_GMP232X_VRW_SETROCOF_ROTDIR
 * Data structure for ROCOF rotation direction
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  f;                  /**< Frequency; 0.1mHz */
    UINT32  f_avg;              /**< Average frequency; 0.1mHz */
    UINT32  f2;                 /**< Frequency 2; 0.1mHz */
    SINT32  ROCOF;              /**< ROCOF (see also GMP232X_CONFIG.ROCOF_avg); [-100000 - 100000]; 0.1 mHz/s */
    SINT32  VectorJump;         /**< Vector jump; [-1799 - 1800]; 0.1 degrees */
    SINT32  RotDir_U;           /**< Voltage rotation direction (#GMP232X_ROTATION_CW or similar); enum */
    SINT32  RotDir_I;           /**< Current rotation direction (#GMP232X_ROTATION_CW or similar); enum */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_ROCOF_ROTDIR;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETPOWERFACTOR, MIO_CMD_GMP232X_VRW_SETPOWERFACTOR
 * Data structure for power factor
 * @since V1.00 Release
 */
typedef struct
{
    SINT32  CosPhi_L1_FRMS_FCC; /**< Cos-Phi L1 FRMS FCC; 0.001 */
    SINT32  CosPhi_L2_FRMS_FCC; /**< Cos-Phi L2 FRMS FCC; 0.001 */
    SINT32  CosPhi_L3_FRMS_FCC; /**< Cos-Phi L3 FRMS FCC; 0.001 */
    SINT32  PF_L1_TRMS_HCS;     /**< Powerfactor L1 TRMS HCS; 0.001 */
    SINT32  PF_L2_TRMS_HCS;     /**< Powerfactor L2 TRMS HCS; 0.001 */
    SINT32  PF_L3_TRMS_HCS;     /**< Powerfactor L3 TRMS HCS; 0.001 */
    SINT32  PF_sum_TRMS_HCS;    /**< Powerfactor Sum TRMS HCS; 0.001 */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_POWERFACTOR;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETASYM, MIO_CMD_GMP232X_VRW_SETASYM
 * Data structure for asymmetry values
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  Asym_U_FRMS_FCS;    /**< Voltage asymmetry; [0 up to infinite (=65535)]; 0.01% */
    UINT32  Asym_I_FRMS_FCS;    /**< Current asymmetry; [0 up to infinite (=65535)]; 0.01% */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_ASYM;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETSYM_COMPONENTS, MIO_CMD_GMP232X_VRW_SETSYM_COMPONENTS
 * Data structure for symmetric components
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  U_pos_FRMS_FCS;     /**< Positive sequence system voltage FRMS_FCS; 1V */
    REAL64  U_neg_FRMS_FCS;     /**< Negative sequence system voltage FRMS_FCS; 1V */
    REAL64  U_null_FRMS_FCS;    /**< Zero sequence system voltage FRMS_FCS; 1V */
    REAL64  I_pos_FRMS_FCS;     /**< Positive sequence system current FRMS_FCS; 1A */
    REAL64  I_neg_FRMS_FCS;     /**< Negative sequence system current FRMS_FCS; 1A */
    REAL64  I_null_FRMS_FCS;    /**< Zero sequence system current FRMS_FCS; 1A */
    REAL64  P_sumpos_FRMS_FCS;  /**< Fundamental positive sequence system active power FCS; 1W */
    REAL64  P_sumneg_FRMS_FCS;  /**< Fundamental negative sequence system active power FCS; 1W */
    REAL64  Q_sumpos_FRMS_FCS;  /**< Fundamental positive sequence system reactive power FCS; 1VAR */
    REAL64  Q_sumneg_FRMS_FCS;  /**< Fundamental negative sequence system reactive power FCS; 1VAR */
    REAL64  S_sumpos_FRMS_FCS;  /**< Fundamental positive sequence system apparent power FCS; 1VA */
    SINT32  CosPhi_pos_FRMS_FCS;     /**< Cos-Phi of fundamental positive sequence system powers FCS; 0.001 */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_SYMCOMPONENTS;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETPHI_UI_S
 * Optimized and lower resolution variant for Phi U, I
 * @since V1.00 Release
 */
typedef struct
{
    SINT32  PHI_U1I1;           /**< Phi UII1; [-17999 - 18000]; 0.01 degrees */
    SINT32  PHI_U2I2;           /**< Phi U2I2; [-17999 - 18000]; 0.01 degrees */
    SINT32  PHI_U3I3;           /**< Phi U3I3; [-17999 - 18000]; 0.01 degrees */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_PHASE_UI_S;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETBULK_THD_TDD
 * Data structure for THD TDD bulk values
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  THD_U1;             /**< THD_U or THDn_U (selector dependent) of phase 1; 0.01% */
    UINT32  THD_U2;             /**< THD_U or THDn_U (selector dependent) of phase 2; 0.01% */
    UINT32  THD_U3;             /**< THD_U or THDn_U (selector dependent) of phase 3; 0.01% */
    UINT32  TDD_I1;             /**< THD_I or TDD_I (selector dependent) of phase 1; 0.01% */
    UINT32  TDD_I2;             /**< THD_I or TDD_I (selector dependent) of phase 2; 0.01% */
    UINT32  TDD_I3;             /**< THD_I or TDD_I (selector dependent) of phase 3; 0.01% */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_BULK_THD_TDD;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETBULK_FRMS_FCS
 * Data structure for FRMS FCS bulk values
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  U_L1N_FRMS_FCS;     /**< Voltage FRMS FCS L1N; 1V */
    REAL64  U_L2N_FRMS_FCS;     /**< Voltage FRMS FCS L2N; 1V */
    REAL64  U_L3N_FRMS_FCS;     /**< Voltage FRMS FCS L3N; 1V */
    REAL64  U_L1L2_FRMS_FCS;    /**< Voltage FRMS FCS L1L2; 1V */
    REAL64  U_L2L3_FRMS_FCS;    /**< Voltage FRMS FCS L2L3; 1V */
    REAL64  U_L3L1_FRMS_FCS;    /**< Voltage FRMS FCS L3L1; 1V */
    REAL64  I_L1_FRMS_FCS;      /**< Current FRMS FCS L1; 1A */
    REAL64  I_L2_FRMS_FCS;      /**< Current FRMS FCS L2; 1A */
    REAL64  I_L3_FRMS_FCS;      /**< Current FRMS FCS L3; 1A */
    REAL64  I_N_FRMS_FCS;       /**< Current FRMS FCS N; 1A */
    UINT32  f;                  /**< Frequency; 0.1mHz */
    UINT32  f_avg;              /**< Average frequency; 0.1mHz */
    UINT32  f2;                 /**< Frequency 2; 0.1mHz */
    SINT32  ROCOF;              /**< ROCOF (in 0.1 mHz/s) */
    SINT32  VectorJump;         /**< Vector jump (in 0.1 degrees) */
    SINT32  RotDir_U;           /**< Voltage rotation direction, #GMP232X_ROTATION_CW or similar */
    SINT32  RotDir_I;           /**< Current rotation direction, #GMP232X_ROTATION_CW or similar */
    REAL64  U_pos_FRMS_FCS;     /**< Positive sequence system voltage FRMS_FCS; 1V */
    REAL64  U_neg_FRMS_FCS;     /**< Negative sequence system voltage FRMS_FCS; 1V */
    REAL64  U_null_FRMS_FCS;    /**< Zero sequence system voltage FRMS_FCS; 1V */
    REAL64  I_pos_FRMS_FCS;     /**< Positive sequence system current FRMS_FCS; 1A */
    REAL64  I_neg_FRMS_FCS;     /**< Negative sequence system current FRMS_FCS; 1A */
    REAL64  I_null_FRMS_FCS;    /**< Zero sequence system current FRMS_FCS; 1A */
    REAL64  P_sumpos_FRMS_FCS;  /**< Fundamental positive sequence system active power FCS; 1W */
    REAL64  Q_sumpos_FRMS_FCS;  /**< Fundamental positive sequence system reactive power FCS; 1VAR */
    REAL64  S_sumpos_FRMS_FCS;  /**< Fundamental positive sequence system apparent power FCS; 1VA */
    SINT32  CosPhi_pos_FRMS_FCS;     /**< Cos-Phi of fundamental positive sequence system powers FCS; 0.001 */
    SINT32  PHI_U1U2;           /**< Phi U1U2 (in 0.001 degrees) */
    SINT32  PHI_U2U3;           /**< Phi U2U3 (in 0.001 degrees) */
    SINT32  PHI_U3U1;           /**< Phi U3U1 (in 0.001 degrees) */
    SINT32  PHI_U1I1;           /**< Phi UII1; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U2I2;           /**< Phi U2I2; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U3I3;           /**< Phi U3I3; [-179999 - 180000]; 0.001 degrees */
    REAL64  P_L1_FRMS_FCS;      /**< Active power L1 FRMS FCS; 1W */
    REAL64  P_L2_FRMS_FCS;      /**< Active power L2 FRMS FCS; 1W */
    REAL64  P_L3_FRMS_FCS;      /**< Active power L3 FRMS FCS; 1W */
    REAL64  Q_L1_FRMS_FCS;      /**< Reactive power L1 FRMS FCS; 1VAR */
    REAL64  Q_L2_FRMS_FCS;      /**< Reactive power L2 FRMS FCS; 1VAR */
    REAL64  Q_L3_FRMS_FCS;      /**< Reactive power L3 FRMS FCS; 1VAR */
    REAL64  S_L1_FRMS_FCS;      /**< Apparent power L1 FRMS FCS; 1VA */
    REAL64  S_L2_FRMS_FCS;      /**< Apparent power L2 FRMS FCS; 1VA */
    REAL64  S_L3_FRMS_FCS;      /**< Apparent power L3 FRMS FCS; 1VA */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_BULK_FRMS_FCS;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETBULK_TRMS_HCS
 * Data structure for TRMS HCS bulk values
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  U_L1N_TRMS_HCS;     /**< Voltage TRMS HCS L1N; 1V */
    REAL64  U_L2N_TRMS_HCS;     /**< Voltage TRMS HCS L2N; 1V */
    REAL64  U_L3N_TRMS_HCS;     /**< Voltage TRMS HCS L3N; 1V */
    REAL64  U_L1L2_TRMS_HCS;    /**< Voltage TRMS HCS L1L2; 1V */
    REAL64  U_L2L3_TRMS_HCS;    /**< Voltage TRMS HCS L2L3; 1V */
    REAL64  U_L3L1_TRMS_HCS;    /**< Voltage TRMS HCS L3L1; 1V */
    REAL64  I_L1_TRMS_HCS;      /**< Current L1 TRMS HCS; 1A */
    REAL64  I_L2_TRMS_HCS;      /**< Current L2 TRMS HCS; 1A */
    REAL64  I_L3_TRMS_HCS;      /**< Current L3 TRMS HCS; 1A */
    REAL64  I_N_TRMS_HCS;       /**< Current N TRMS HCS; 1A */
    UINT32  f;                  /**< Frequency; 0.1mHz */
    UINT32  f_avg;              /**< Averaged Frequency (see also GMP232X_CONFIG.FreqAvgPeriods); 0.1mHz */
    UINT32  f2;                 /**< Frequency 2; 0.1mHz */
    SINT32  ROCOF;              /**< ROCOF (see also GMP232X_CONFIG.ROCOF_tavg); [-100000 - 100000]; 0.1 mHz/s */
    SINT32  Phi_U1U2;           /**< Phi U1U2; [-179999 - 180000]; 0.001 degrees */
    SINT32  Phi_U2U3;           /**< Phi U2U3; [-179999 - 180000]; 0.001 degrees */
    SINT32  Phi_U3U1;           /**< Phi U3U1; [-179999 - 180000]; 0.001 degrees */
    SINT32  RotDir_U;           /**< Voltage rotation direction, #GMP232X_ROTATION_CW or similar; enum */
    SINT32  RotDir_I;           /**< Current rotation direction, #GMP232X_ROTATION_CW or similar; enum */
    SINT32  PHI_U1I1;           /**< Phi UII1; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U2I2;           /**< Phi U2I2; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U3I3;           /**< Phi U3I3; [-179999 - 180000]; 0.001 degrees */
    SINT32  VectorJump;         /**< Vector jump; [-1799 - 1800]; 0.1 degrees */
    REAL64  P_L1_TRMS_HCS;      /**< Active power L1 TRMS HCS; 1W */
    REAL64  P_L2_TRMS_HCS;      /**< Active power L2 TRMS HCS; 1W */
    REAL64  P_L3_TRMS_HCS;      /**< Active power L3 TRMS HCS; 1W */
    REAL64  P_sum_TRMS_HCS;     /**< Sum of Active power TRMS HCS; 1W */
    REAL64  Q_L1_TRMS_HCS;      /**< Reactive power L1 TRMS HCS; 1VAR */
    REAL64  Q_L2_TRMS_HCS;      /**< Reactive power L2 TRMS HCS; 1VAR */
    REAL64  Q_L3_TRMS_HCS;      /**< Reactive power L3 TRMS HCS; 1VAR */
    REAL64  Q_sum_TRMS_HCS;     /**< Sum of reactive power TRMS HCS; 1VAR */
    REAL64  S_L1_TRMS_HCS;      /**< Apparent power L1 TRMS HCS; 1VA */
    REAL64  S_L2_TRMS_HCS;      /**< Apparent power L2 TRMS HCS; 1VA */
    REAL64  S_L3_TRMS_HCS;      /**< Apparent power L3 TRMS HCS; 1VA */
    REAL64  S_sum_TRMS_HCS;     /**< Sum of apparent power TRMS HCS; 1VA */
    SINT32  PF_sum_TRMS_HCS;    /**< Powerfactor Sum TRMS HCS; 0.001 */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_BULK_TRMS_HCS;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETBULK_SYMCOMPONENTS
 * Data structure for symmetric components bulk values
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  U_pos_FRMS_FCS;     /**< Positive sequence system voltage FRMS_FCS; 1V */
    REAL64  U_neg_FRMS_FCS;     /**< Negative sequence system voltage FRMS_FCS; 1V */
    REAL64  I_pos_FRMS_FCS;     /**< Positive sequence system current FRMS_FCS; 1A */
    REAL64  I_neg_FRMS_FCS;     /**< Negative sequence system current FRMS_FCS; 1A */
    SINT32  ROCOF;              /**< ROCOF (see also GMP232X_CONFIG.ROCOF_avg); [-100000 - 100000]; 0.1 mHz/s */
    SINT32  Phi_U1U2;           /**< Phi U1U2; [-179999 - 180000]; 0.001 degrees */
    SINT32  Phi_U2U3;           /**< Phi U2U3; [-179999 - 180000]; 0.001 degrees */
    SINT32  Phi_U3U1;           /**< Phi U3U1; [-179999 - 180000]; 0.001 degrees */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_BULK_SYMCOMPONENTS;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETBULK_FRMS_FCC
 * Data structure for FRMS FCC bulk values
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  U_L1N_FRMS_FCC;     /**< Voltage FRMS FCC L1N; 1V */
    REAL64  U_L2N_FRMS_FCC;     /**< Voltage FRMS FCC L2N; 1V */
    REAL64  U_L3N_FRMS_FCC;     /**< Voltage FRMS FCC L3N; 1V */
    REAL64  I_L1_FRMS_FCC;      /**< Current L1 FRMS FCC; 1A */
    REAL64  I_L2_FRMS_FCC;      /**< Current L2 FRMS FCC; 1A */
    REAL64  I_L3_FRMS_FCC;      /**< Current L3 FRMS FCC; 1A */
    REAL64  I_N_FRMS_FCC;       /**< Current N FRMS FCC; 1A */
    REAL64  U_L1L2_FRMS_FCC;    /**< Voltage FRMS FCC L1L2; 1V */
    REAL64  U_L2L3_FRMS_FCC;    /**< Voltage FRMS FCC L2L3; 1V */
    REAL64  U_L3L1_FRMS_FCC;    /**< Voltage FRMS FCC L3L1; 1V */
    UINT32  f;                  /**< Frequency; 0.1mHz */
    UINT32  f_avg;              /**< Averaged Frequency (see also GMP232X_CONFIG.FreqAvgPeriods); 0.1mHz */
    UINT32  f2;                 /**< Frequency 2; 0.1mHz */
    REAL64  U_neg_FRMS_FCS;     /**< Negative sequence system voltage FRMS_FCS; 1V */
    REAL64  I_neg_FRMS_FCS;     /**< Negative sequence system current FRMS_FCS; 1A */
    UINT32  Asym_U_FRMS_FCS;    /**< Voltage asymmetry; [0 up to infinite (=65535)]; 0.01% */
    UINT32  Asym_I_FRMS_FCS;    /**< Current asymmetry; [0 up to infinite (=65535)]; 0.01% */
    SINT32  PHI_UposUref;       /**< Phi positive sequence system voltage phasor minus reference system phasor; [-179999 - 180000]; 0.001 degrees */
    REAL64  P_L1_FRMS_FCC;      /**< Active power L1 FRMS FCC; 1W */
    REAL64  P_L2_FRMS_FCC;      /**< Active power L2 FRMS FCC; 1W */
    REAL64  P_L3_FRMS_FCC;      /**< Active power L3 FRMS FCC; 1W */
    REAL64  P_sum2_FRMS_FCC;    /**< Sum of Active power FRMS FCC; 1W */
    REAL64  Q_L1_FRMS_FCC;      /**< Reactive power L1 FRMS FCC; 1VAR */
    REAL64  Q_L2_FRMS_FCC;      /**< Reactive power L2 FRMS FCC; 1VAR */
    REAL64  Q_L3_FRMS_FCC;      /**< Reactive power L3 FRMS FCC; 1VAR */
    REAL64  Q_sum2_FRMS_FCC;    /**< Sum of reactive power FRMS FCC; 1VAR */
    REAL64  S_L1_FRMS_FCC;      /**< Apparent power L1 FRMS FCC; 1VA */
    REAL64  S_L2_FRMS_FCC;      /**< Apparent power L2 FRMS FCC; 1VA */
    REAL64  S_L3_FRMS_FCC;      /**< Apparent power L3 FRMS FCC; 1VA */
    REAL64  S_sum2_FRMS_FCC;    /**< Sum of apparent power FRMS FCC; 1VA */
    SINT32  CosPhi_L1_FRMS_FCC; /**< Cos-Phi L1 FRMS FCC; 0.001 */
    SINT32  CosPhi_L2_FRMS_FCC; /**< Cos-Phi L2 FRMS FCC; 0.001 */
    SINT32  CosPhi_L3_FRMS_FCC; /**< Cos-Phi L3 FRMS FCC; 0.001 */
    SINT32  PHI_U1I1;           /**< Phi UII1; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U2I2;           /**< Phi U2I2; [-179999 - 180000]; 0.001 degrees */
    SINT32  PHI_U3I3;           /**< Phi U3I3; [-179999 - 180000]; 0.001 degrees */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_BULK_FRMS_FCC;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETPOWERS_FRMS_FCS / MIO_CMD_GMP232X_VRW_SETPOWERS_FRMS_FCS
 * Data structure for FRMS FCS power values
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  P_L1_FRMS_FCS;      /**< Active power L1 FRMS FCS; 1W */
    REAL64  P_L2_FRMS_FCS;      /**< Active power L2 FRMS FCS; 1W */
    REAL64  P_L3_FRMS_FCS;      /**< Active power L3 FRMS FCS; 1W */
    REAL64  Q_L1_FRMS_FCS;      /**< Reactive power L1 FRMS FCS; 1VAR */
    REAL64  Q_L2_FRMS_FCS;      /**< Reactive power L2 FRMS FCS; 1VAR */
    REAL64  Q_L3_FRMS_FCS;      /**< Reactive power L3 FRMS FCS; 1VAR */
    REAL64  S_L1_FRMS_FCS;      /**< Apparent power L1 FRMS FCS; 1VA */
    REAL64  S_L2_FRMS_FCS;      /**< Apparent power L2 FRMS FCS; 1VA */
    REAL64  S_L3_FRMS_FCS;      /**< Apparent power L3 FRMS FCS; 1VA */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_POWERS_FRMS_FCS;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETPOWERS_FRMS_FCC / MIO_CMD_GMP232X_VRW_SETPOWERS_FRMS_FCC
 * Data structure for FRMS FCC power values
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  P_sum2_FRMS_FCC;    /**< Sum of Active power FRMS FCC; 1W */
    REAL64  P_L1_FRMS_FCC;      /**< Active power L1 FRMS FCC; 1W */
    REAL64  P_L2_FRMS_FCC;      /**< Active power L2 FRMS FCC; 1W */
    REAL64  P_L3_FRMS_FCC;      /**< Active power L3 FRMS FCC; 1W */
    REAL64  Q_sum2_FRMS_FCC;    /**< Sum of reactive power FRMS FCC; 1VAR */
    REAL64  Q_L1_FRMS_FCC;      /**< Reactive power L1 FRMS FCC; 1VAR */
    REAL64  Q_L2_FRMS_FCC;      /**< Reactive power L2 FRMS FCC; 1VAR */
    REAL64  Q_L3_FRMS_FCC;      /**< Reactive power L3 FRMS FCC; 1VAR */
    REAL64  S_sum2_FRMS_FCC;    /**< Sum of apparent power FRMS FCC; 1VA */
    REAL64  S_L1_FRMS_FCC;      /**< Apparent power L1 FRMS FCC; 1VA */
    REAL64  S_L2_FRMS_FCC;      /**< Apparent power L2 FRMS FCC; 1VA */
    REAL64  S_L3_FRMS_FCC;      /**< Apparent power L3 FRMS FCC; 1VA */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_POWERS_FRMS_FCC;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETPOWERS_TRMS_HCS, MIO_CMD_GMP232X_VRW_SETPOWERS_TRMS_HCS
 * Data structure for TRMS HCS power values
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  P_sum_TRMS_HCS;     /**< Sum of Active power TRMS HCS; 1W */
    REAL64  P_L1_TRMS_HCS;      /**< Active power L1 TRMS HCS; 1W */
    REAL64  P_L2_TRMS_HCS;      /**< Active power L2 TRMS HCS; 1W */
    REAL64  P_L3_TRMS_HCS;      /**< Active power L3 TRMS HCS; 1W */
    REAL64  Q_sum_TRMS_HCS;     /**< Sum of reactive power TRMS HCS; 1VAR */
    REAL64  Q_L1_TRMS_HCS;      /**< Reactive power L1 TRMS HCS; 1VAR */
    REAL64  Q_L2_TRMS_HCS;      /**< Reactive power L2 TRMS HCS; 1VAR */
    REAL64  Q_L3_TRMS_HCS;      /**< Reactive power L3 TRMS HCS; 1VAR */
    REAL64  S_sum_TRMS_HCS;     /**< Sum of apparent power TRMS HCS; 1VA */
    REAL64  S_L1_TRMS_HCS;      /**< Apparent power L1 TRMS HCS; 1VA */
    REAL64  S_L2_TRMS_HCS;      /**< Apparent power L2 TRMS HCS; 1VA */
    REAL64  S_L3_TRMS_HCS;      /**< Apparent power L3 TRMS HCS; 1VA */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_POWERS_TRMS_HCS;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETPOWERS_TRMS_HCC, MIO_CMD_GMP232X_VRW_SETPOWERS_TRMS_HCC
 * Data structure for TRMS HCC power values
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  P_sum_TRMS_HCC;     /**< Sum of Active power TRMS HCC; 1W */
    REAL64  P_L1_TRMS_HCC;      /**< Active power L1 TRMS HCC; 1W */
    REAL64  P_L2_TRMS_HCC;      /**< Active power L2 TRMS HCC; 1W */
    REAL64  P_L3_TRMS_HCC;      /**< Active power L3 TRMS HCC; 1W */
    REAL64  Q_sum_TRMS_HCC;     /**< Sum of reactive power TRMS HCC; 1VAR */
    REAL64  Q_L1_TRMS_HCC;      /**< Reactive power L1 TRMS HCC; 1VAR */
    REAL64  Q_L2_TRMS_HCC;      /**< Reactive power L2 TRMS HCC; 1VAR */
    REAL64  Q_L3_TRMS_HCC;      /**< Reactive power L3 TRMS HCC; 1VAR */
    REAL64  S_sum_TRMS_HCC;     /**< Sum of apparent power TRMS HCC; 1VA */
    REAL64  S_L1_TRMS_HCC;      /**< Apparent power L1 TRMS HCC; 1VA */
    REAL64  S_L2_TRMS_HCC;      /**< Apparent power L2 TRMS HCC; 1VA */
    REAL64  S_L3_TRMS_HCC;      /**< Apparent power L3 TRMS HCC; 1VA */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_POWERS_TRMS_HCC;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETRAWFFT_100
 * Data structure for raw FFT values
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  Value[100];         /**< Buffer for 100 raw harmonic values; array */
    UINT32  Integrity;          /**< Overflow/Underflow statusbits (#GMP232X_INTEGRITY_OF_U1 or similar); enum */
} GMP232X_RAWFFT_100;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETCALIB / MIO_CMD_GMP232X_GETCALIB
 * Calibration structure
 * @since V1.00 Release
 */
typedef struct
{
    SINT16  ValueG1;            /**< Value for G1 */
    SINT16  ValueG2;            /**< Value for G2 [0-16] */
    SINT16  Offset;             /**< Offset value */
} GMP232X_CALIB;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETFIRCFG / MIO_CMD_GMP232X_GETFIRCFG
 * Configuration structure for FIR
 * @since V1.00 Release
 */
typedef struct
{
    BOOL32  FilterEnabled;      /**< FIR filter operating mode, bool */
} GMP232X_FIRCFG;


/**
 * @addtogroup GMP232X_DEF
 * @{
 */

/**
 * @name Values for selector in MIO_CMD_GMP232X_GETBULK_THD_TDD / GMP232X_LIMIT_THDTDD.Source
 * @{
 */

#define GMP232X_THDTDD_RATED        0    /**< read/use rated THD/TDD values */
#define GMP232X_THDTDD_FUNDAMENTAL  1    /**< read/use fundamental THD/TDD values */
/** @} */

/**
 * @name Index Constants used for MIO_CMD_GMP232X_GETSTATISTIC_* and MIO_CMD_GMP232X_GETMEANVALUE_*
 * @{
 */

#define GMP232X_IDX_U_L1N_INST          0    /**< Voltage Phase 1 to ground instantaneous value; 1V */
#define GMP232X_IDX_U_L2N_INST          1    /**< Voltage Phase 2 to ground instantaneous value; 1V */
#define GMP232X_IDX_U_L3N_INST          2    /**< Voltage Phase 3 to ground instantaneous value; 1V */
#define GMP232X_IDX_U_L1L2_INST         3    /**< Voltage Phase to phase instantaneous value; 1V */
#define GMP232X_IDX_U_L2L3_INST         4    /**< Voltage Phase to phase instantaneous value; 1V */
#define GMP232X_IDX_U_L3L1_INST         5    /**< Voltage Phase to phase instantaneous value; 1V */
#define GMP232X_IDX_I_L1_INST           6    /**< Current Phase 1 instantaneous value; 1A */
#define GMP232X_IDX_I_L2_INST           7    /**< Current Phase 2 instantaneous value; 1A */
#define GMP232X_IDX_I_L3_INST           8    /**< Current Phase 3 instantaneous value; 1A */
#define GMP232X_IDX_I_N_INST            9    /**< Current instantaneous value; 1A */
#define GMP232X_IDX_U_L1N_FRMS_FCS      10   /**< Voltage Phase 1 FRMS_FCS */
#define GMP232X_IDX_U_L2N_FRMS_FCS      11   /**< Voltage Phase 2 FRMS_FCS */
#define GMP232X_IDX_U_L3N_FRMS_FCS      12   /**< Voltage Phase 3 FRMS_FCS */
#define GMP232X_IDX_U_L1L2_FRMS_FCS     13   /**< Voltage Phase to Phase FRMS_FCS */
#define GMP232X_IDX_U_L2L3_FRMS_FCS     14   /**< Voltage Phase to Phase FRMS_FCS */
#define GMP232X_IDX_U_L3L1_FRMS_FCS     15   /**< Voltage Phase to Phase FRMS_FCS */
#define GMP232X_IDX_I_L1_FRMS_FCS       16   /**< Current Phase 1 FRMS_FCS */
#define GMP232X_IDX_I_L2_FRMS_FCS       17   /**< Current Phase 2 FRMS_FCS */
#define GMP232X_IDX_I_L3_FRMS_FCS       18   /**< Current Phase 3 FRMS_FCS */
#define GMP232X_IDX_I_N_FRMS_FCS        19   /**< Current Neutral FRMS_FCS */
#define GMP232X_IDX_U_L1N_TRMS_HCS      20   /**< Voltage Phase 1 TRMS_HCS */
#define GMP232X_IDX_U_L2N_TRMS_HCS      21   /**< Voltage Phase 2 TRMS_HCS */
#define GMP232X_IDX_U_L3N_TRMS_HCS      22   /**< Voltage Phase 3 TRMS_HCS */
#define GMP232X_IDX_U_L1L2_TRMS_HCS     23   /**< Voltage Phase to Phase TRMS_HCS */
#define GMP232X_IDX_U_L2L3_TRMS_HCS     24   /**< Voltage Phase to Phase TRMS_HCS */
#define GMP232X_IDX_U_L3L1_TRMS_HCS     25   /**< Voltage Phase to Phase TRMS_HCS */
#define GMP232X_IDX_I_L1_TRMS_HCS       26   /**< Current Phase 1 TRMS_HCS */
#define GMP232X_IDX_I_L2_TRMS_HCS       27   /**< Current Phase 2 TRMS_HCS */
#define GMP232X_IDX_I_L3_TRMS_HCS       28   /**< Current Phase 3 TRMS_HCS */
#define GMP232X_IDX_I_N_TRMS_HCS        29   /**< Current Neutral TRMS_HCS */
#define GMP232X_IDX_U_pos_FRMS_FCS      30   /**< Positive sequence system voltage FRMS_FCS */
#define GMP232X_IDX_U_neg_FRMS_FCS      31   /**< Negative sequence system voltage FRMS_FCS */
#define GMP232X_IDX_U_null_FRMS_FCS     32   /**< Zero sequence system voltage FRMS_FCS */
#define GMP232X_IDX_I_pos_FRMS_FCS      33   /**< Positive sequence system current FRMS_FCS */
#define GMP232X_IDX_I_neg_FRMS_FCS      34   /**< Negative sequence system current FRMS_FCS */
#define GMP232X_IDX_I_null_FRMS_FCS     35   /**< zero sequence system current FRMS_FCS */
#define GMP232X_IDX_f                   36   /**< Frequency */
#define GMP232X_IDX_f2                  37   /**< Frequency 2 */
#define GMP232X_IDX_ROCOF               38   /**< ROCOF */
#define GMP232X_IDX_PHI_U1I1            39   /**< PHI value for U1_I1 */
#define GMP232X_IDX_PHI_U2I2            40   /**< PHI value for U2_I2 */
#define GMP232X_IDX_PHI_U3I3            41   /**< PHI value for U3_I3 */
#define GMP232X_IDX_P_L1_FRMS_FCS       42   /**< Active power Phase 1 (FRMS_FCS) */
#define GMP232X_IDX_P_L2_FRMS_FCS       43   /**< Active power Phase 2 (FRMS_FCS) */
#define GMP232X_IDX_P_L3_FRMS_FCS       44   /**< Active power Phase 3 (FRMS_FCS) */
#define GMP232X_IDX_P_sumpos_FRMS_FCS   45   /**< Fundamental positive sequence system active power (FRMS_FCS) */
#define GMP232X_IDX_P_sumneg_FRMS_FCS   46   /**< Fundamental negative sequence system active power (FRMS_FCS) */
#define GMP232X_IDX_P_L1_TRMS_HCS       47   /**< Active power Phase 1 (TRMS_HCS) */
#define GMP232X_IDX_P_L2_TRMS_HCS       48   /**< Active power Phase 2 (TRMS_HCS) */
#define GMP232X_IDX_P_L3_TRMS_HCS       49   /**< Active power Phase 3 (TRMS_HCS) */
#define GMP232X_IDX_P_sum_TRMS_HCS      50   /**< Active power sum (TRMS_HCS) */
#define GMP232X_IDX_Q_L1_FRMS_FCS       51   /**< Reactive power Phase 1 (FRMS_FCS) */
#define GMP232X_IDX_Q_L2_FRMS_FCS       52   /**< Reactive power Phase 2 (FRMS_FCS) */
#define GMP232X_IDX_Q_L3_FRMS_FCS       53   /**< Reactive power Phase 3 (FRMS_FCS) */
#define GMP232X_IDX_Q_sumpos_FRMS_FCS   54   /**< Fundamental positive sequence system reactive power (FRMS_FCS) */
#define GMP232X_IDX_Q_sumneg_FRMS_FCS   55   /**< Fundamental negative sequence system reactive power (FRMS_FCS) */
#define GMP232X_IDX_Q_L1_TRMS_HCS       56   /**< Reactive power Phase 1 (TRMS_HCS) */
#define GMP232X_IDX_Q_L2_TRMS_HCS       57   /**< Reactive power Phase 2 (TRMS_HCS) */
#define GMP232X_IDX_Q_L3_TRMS_HCS       58   /**< Reactive power Phase 3 (TRMS_HCS) */
#define GMP232X_IDX_Q_sum_TRMS_HCS      59   /**< Reactive power sum (TRMS_HCS) */
#define GMP232X_IDX_S_L1_FRMS_FCS       60   /**< Apparent power Phase 1 (FRMS_FCS) */
#define GMP232X_IDX_S_L2_FRMS_FCS       61   /**< Apparent power Phase 2 (FRMS_FCS) */
#define GMP232X_IDX_S_L3_FRMS_FCS       62   /**< Apparent power Phase 3 (FRMS_FCS) */
#define GMP232X_IDX_S_sumpos_FRMS_FCS   63   /**< Fundamental positive sequence system apparent power (FRMS_FCS) */
#define GMP232X_IDX_S_L1_TRMS_HCS       64   /**< Apparent power Phase 1 (TRMS_HCS) */
#define GMP232X_IDX_S_L2_TRMS_HCS       65   /**< Apparent power Phase 2 (TRMS_HCS) */
#define GMP232X_IDX_S_L3_TRMS_HCS       66   /**< Apparent power Phase 3 (TRMS_HCS) */
#define GMP232X_IDX_S_sum_TRMS_HCS      67   /**< Apparent power sum (TRMS_HCS) */
#define GMP232X_IDX_COSPHI_pos_FRMS_FCS 68   /**< Cos-phi of positive sequence powers (FRMS_FCS) */
#define GMP232X_IDX_PF_L1_TRMS_HCS      69   /**< Power factor Phase 1 (TRMS_HCS) */
#define GMP232X_IDX_PF_L2_TRMS_HCS      70   /**< Power factor Phase 2 (TRMS_HCS) */
#define GMP232X_IDX_PF_L3_TRMS_HCS      71   /**< Power factor Phase 3 (TRMS_HCS) */
#define GMP232X_IDX_PF_sum_TRMS_HCS     72   /**< Power factor sum  (TRMS_HCS) */
#define GMP232X_IDX_Asym_U              73   /**< Voltage asymmetry */
#define GMP232X_IDX_Asym_I              74   /**< Current asymmetry */
#define GMP232X_IDX_THD_U1              75   /**< THD U1 */
#define GMP232X_IDX_THD_U2              76   /**< THD U2 */
#define GMP232X_IDX_THD_U3              77   /**< THD U3 */
#define GMP232X_IDX_THDn_U1             78   /**< THDn U1 */
#define GMP232X_IDX_THDn_U2             79   /**< THDn U2 */
#define GMP232X_IDX_THDn_U3             80   /**< THDn U3 */
#define GMP232X_IDX_THD_I1              81   /**< THD I1 */
#define GMP232X_IDX_THD_I2              82   /**< THD I2 */
#define GMP232X_IDX_THD_I3              83   /**< THD I3 */
#define GMP232X_IDX_TDD_I1              84   /**< TDD I1 */
#define GMP232X_IDX_TDD_I2              85   /**< TDD I2 */
#define GMP232X_IDX_TDD_I3              86   /**< TDD I3 */
#define GMP232X_IDX_VectorJump          87   /**< Vector jump */
#define GMP232X_IDX_HARM_MEAN_U1_H00    200  /**< 00. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H01    201  /**< 01. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H02    202  /**< 02. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H03    203  /**< 03. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H04    204  /**< 04. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H05    205  /**< 05. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H06    206  /**< 06. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H07    207  /**< 07. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H08    208  /**< 08. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H09    209  /**< 09. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H10    210  /**< 10. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H11    211  /**< 11. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H12    212  /**< 12. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H13    213  /**< 13. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H14    214  /**< 14. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H15    215  /**< 15. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H16    216  /**< 16. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H17    217  /**< 17. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H18    218  /**< 18. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H19    219  /**< 19. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H20    220  /**< 20. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H21    221  /**< 21. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H22    222  /**< 22. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H23    223  /**< 23. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H24    224  /**< 24. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H25    225  /**< 25. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H26    226  /**< 26. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H27    227  /**< 27. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H28    228  /**< 28. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H29    229  /**< 29. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H30    230  /**< 30. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H31    231  /**< 31. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H32    232  /**< 32. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H33    233  /**< 33. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H34    234  /**< 34. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H35    235  /**< 35. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H36    236  /**< 36. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H37    237  /**< 37. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H38    238  /**< 38. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H39    239  /**< 39. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H40    240  /**< 40. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H41    241  /**< 41. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H42    242  /**< 42. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H43    243  /**< 43. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H44    244  /**< 44. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H45    245  /**< 45. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H46    246  /**< 46. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H47    247  /**< 47. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H48    248  /**< 48. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U1_H49    249  /**< 49. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H00    250  /**< 00. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H01    251  /**< 01. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H02    252  /**< 02. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H03    253  /**< 03. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H04    254  /**< 04. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H05    255  /**< 05. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H06    256  /**< 06. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H07    257  /**< 07. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H08    258  /**< 08. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H09    259  /**< 09. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H10    260  /**< 10. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H11    261  /**< 11. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H12    262  /**< 12. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H13    263  /**< 13. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H14    264  /**< 14. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H15    265  /**< 15. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H16    266  /**< 16. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H17    267  /**< 17. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H18    268  /**< 18. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H19    269  /**< 19. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H20    270  /**< 20. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H21    271  /**< 21. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H22    272  /**< 22. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H23    273  /**< 23. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H24    274  /**< 24. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H25    275  /**< 25. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H26    276  /**< 26. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H27    277  /**< 27. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H28    278  /**< 28. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H29    279  /**< 29. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H30    280  /**< 30. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H31    281  /**< 31. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H32    282  /**< 32. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H33    283  /**< 33. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H34    284  /**< 34. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H35    285  /**< 35. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H36    286  /**< 36. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H37    287  /**< 37. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H38    288  /**< 38. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H39    289  /**< 39. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H40    290  /**< 40. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H41    291  /**< 41. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H42    292  /**< 42. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H43    293  /**< 43. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H44    294  /**< 44. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H45    295  /**< 45. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H46    296  /**< 46. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H47    297  /**< 47. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H48    298  /**< 48. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U2_H49    299  /**< 49. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H00    300  /**< 00. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H01    301  /**< 01. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H02    302  /**< 02. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H03    303  /**< 03. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H04    304  /**< 04. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H05    305  /**< 05. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H06    306  /**< 06. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H07    307  /**< 07. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H08    308  /**< 08. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H09    309  /**< 09. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H10    310  /**< 10. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H11    311  /**< 11. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H12    312  /**< 12. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H13    313  /**< 13. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H14    314  /**< 14. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H15    315  /**< 15. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H16    316  /**< 16. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H17    317  /**< 17. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H18    318  /**< 18. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H19    319  /**< 19. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H20    320  /**< 20. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H21    321  /**< 21. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H22    322  /**< 22. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H23    323  /**< 23. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H24    324  /**< 24. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H25    325  /**< 25. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H26    326  /**< 26. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H27    327  /**< 27. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H28    328  /**< 28. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H29    329  /**< 29. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H30    330  /**< 30. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H31    331  /**< 31. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H32    332  /**< 32. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H33    333  /**< 33. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H34    334  /**< 34. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H35    335  /**< 35. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H36    336  /**< 36. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H37    337  /**< 37. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H38    338  /**< 38. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H39    339  /**< 39. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H40    340  /**< 40. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H41    341  /**< 41. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H42    342  /**< 42. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H43    343  /**< 43. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H44    344  /**< 44. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H45    345  /**< 45. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H46    346  /**< 46. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H47    347  /**< 47. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H48    348  /**< 48. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_U3_H49    349  /**< 49. harmonic voltage percent */
#define GMP232X_IDX_HARM_MEAN_I1_H00    350  /**< 00. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H01    351  /**< 01. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H02    352  /**< 02. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H03    353  /**< 03. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H04    354  /**< 04. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H05    355  /**< 05. armonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H06    356  /**< 06. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H07    357  /**< 07. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H08    358  /**< 08. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H09    359  /**< 09. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H10    360  /**< 10. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H11    361  /**< 11. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H12    362  /**< 12. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H13    363  /**< 13. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H14    364  /**< 14. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H15    365  /**< 15. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H16    366  /**< 16. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H17    367  /**< 17. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H18    368  /**< 18. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H19    369  /**< 19. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H20    370  /**< 20. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H21    371  /**< 21. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H22    372  /**< 22. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H23    373  /**< 23. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H24    374  /**< 24. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H25    375  /**< 25. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H26    376  /**< 26. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H27    377  /**< 27. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H28    378  /**< 28. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H29    379  /**< 29. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H30    380  /**< 30. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H31    381  /**< 31. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H32    382  /**< 32. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H33    383  /**< 33. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H34    384  /**< 34. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H35    385  /**< 35. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H36    386  /**< 36. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H37    387  /**< 37. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H38    388  /**< 38. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H39    389  /**< 39. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H40    390  /**< 40. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H41    391  /**< 41. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H42    392  /**< 42. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H43    393  /**< 43. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H44    394  /**< 44. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H45    395  /**< 45. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H46    396  /**< 46. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H47    397  /**< 47. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H48    398  /**< 48. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I1_H49    399  /**< 49. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H00    400  /**< 00. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H01    401  /**< 01. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H02    402  /**< 02. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H03    403  /**< 03. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H04    404  /**< 04. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H05    405  /**< 05. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H06    406  /**< 06. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H07    407  /**< 07. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H08    408  /**< 08. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H09    409  /**< 09. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H10    410  /**< 10. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H11    411  /**< 11. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H12    412  /**< 12. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H13    413  /**< 13. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H14    414  /**< 14. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H15    415  /**< 15. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H16    416  /**< 16. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H17    417  /**< 17. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H18    418  /**< 18. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H19    419  /**< 19. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H20    420  /**< 20. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H21    421  /**< 21. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H22    422  /**< 22. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H23    423  /**< 23. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H24    424  /**< 24. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H25    425  /**< 25. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H26    426  /**< 26. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H27    427  /**< 27. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H28    428  /**< 28. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H29    429  /**< 29. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H30    430  /**< 30. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H31    431  /**< 31. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H32    432  /**< 32. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H33    433  /**< 33. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H34    434  /**< 34. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H35    435  /**< 35. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H36    436  /**< 36. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H37    437  /**< 37. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H38    438  /**< 38. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H39    439  /**< 39. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H40    440  /**< 40. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H41    441  /**< 41. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H42    442  /**< 42. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H43    443  /**< 43. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H44    444  /**< 44. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H45    445  /**< 45. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H46    446  /**< 46. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H47    447  /**< 47. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H48    448  /**< 48. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I2_H49    449  /**< 49. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H00    450  /**< 00. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H01    451  /**< 01. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H02    452  /**< 02. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H03    453  /**< 03. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H04    454  /**< 04. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H05    455  /**< 05. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H06    456  /**< 06. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H07    457  /**< 07. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H08    458  /**< 08. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H09    459  /**< 09. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H10    460  /**< 10. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H11    461  /**< 11. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H12    462  /**< 12. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H13    463  /**< 13. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H14    464  /**< 14. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H15    465  /**< 15. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H16    466  /**< 16. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H17    467  /**< 17. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H18    468  /**< 18. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H19    469  /**< 19. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H20    470  /**< 20. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H21    471  /**< 21. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H22    472  /**< 22. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H23    473  /**< 23. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H24    474  /**< 24. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H25    475  /**< 25. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H26    476  /**< 26. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H27    477  /**< 27. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H28    478  /**< 28. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H29    479  /**< 29. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H30    480  /**< 30. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H31    481  /**< 31. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H32    482  /**< 32. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H33    483  /**< 33. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H34    484  /**< 34. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H35    485  /**< 35. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H36    486  /**< 36. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H37    487  /**< 37. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H38    488  /**< 38. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H39    489  /**< 39. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H40    490  /**< 40. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H41    491  /**< 41. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H42    492  /**< 42. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H43    493  /**< 43. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H44    494  /**< 44. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H45    495  /**< 45. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H46    496  /**< 46. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H47    497  /**< 47. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H48    498  /**< 48. harmonic current percent */
#define GMP232X_IDX_HARM_MEAN_I3_H49    499  /**< 49. harmonic current percent */
/** @} */

/**
 * @name Constants used at GMP232X_MEAN_CONFIG.ChanBitMask1
 * @{
 */

#define GMP232X_MEAN_1_U_L1N_FRMS_FCS   0x00000001   /**< Voltage Phase 1 FRMS_FCS */
#define GMP232X_MEAN_1_U_L2N_FRMS_FCS   0x00000002   /**< Voltage Phase 2 FRMS_FCS */
#define GMP232X_MEAN_1_U_L3N_FRMS_FCS   0x00000004   /**< Voltage Phase 3 FRMS_FCS */
#define GMP232X_MEAN_1_U_L1L2_FRMS_FCS  0x00000008   /**< Voltage Phase to Phase FRMS_FCS */
#define GMP232X_MEAN_1_U_L2L3_FRMS_FCS  0x00000010   /**< Voltage Phase to Phase FRMS_FCS */
#define GMP232X_MEAN_1_U_L3L1_FRMS_FCS  0x00000020   /**< Voltage Phase to Phase FRMS_FCS */
#define GMP232X_MEAN_1_I_L1_FRMS_FCS    0x00000040   /**< Current Phase 1 FRMS_FCS */
#define GMP232X_MEAN_1_I_L2_FRMS_FCS    0x00000080   /**< Current Phase 2 FRMS_FCS */
#define GMP232X_MEAN_1_I_L3_FRMS_FCS    0x00000100   /**< Current Phase 3 FRMS_FCS */
#define GMP232X_MEAN_1_I_N_FRMS_FCS     0x00000200   /**< Current Neutral FRMS_FCS */
#define GMP232X_MEAN_1_U_L1N_TRMS_HCS   0x00000400   /**< Voltage Phase 1 TRMS_HCS */
#define GMP232X_MEAN_1_U_L2N_TRMS_HCS   0x00000800   /**< Voltage Phase 2 TRMS_HCS */
#define GMP232X_MEAN_1_U_L3N_TRMS_HCS   0x00001000   /**< Voltage Phase 3 TRMS_HCS */
#define GMP232X_MEAN_1_U_L1L2_TRMS_HCS  0x00002000   /**< Voltage Phase to Phase TRMS_HCS */
#define GMP232X_MEAN_1_U_L2L3_TRMS_HCS  0x00004000   /**< Voltage Phase to Phase TRMS_HCS */
#define GMP232X_MEAN_1_U_L3L1_TRMS_HCS  0x00008000   /**< Voltage Phase to Phase TRMS_HCS */
#define GMP232X_MEAN_1_I_L1_TRMS_HCS    0x00010000   /**< Current Phase 1 TRMS_HCS */
#define GMP232X_MEAN_1_I_L2_TRMS_HCS    0x00020000   /**< Current Phase 2 TRMS_HCS */
#define GMP232X_MEAN_1_I_L3_TRMS_HCS    0x00040000   /**< Current Phase 3 TRMS_HCS */
#define GMP232X_MEAN_1_I_N_TRMS_HCS     0x00080000   /**< Current Neutral TRMS_HCS */
#define GMP232X_MEAN_1_U_pos_FRMS_FCS   0x00100000   /**< Positive sequence system voltage FRMS_FCS */
#define GMP232X_MEAN_1_U_neg_FRMS_FCS   0x00200000   /**< Negative sequence system voltage FRMS_FCS */
#define GMP232X_MEAN_1_U_null_FRMS_FCS  0x00400000   /**< Zero sequence system voltage FRMS_FCS */
#define GMP232X_MEAN_1_I_pos_FRMS_FCS   0x00800000   /**< Positive sequence system current FRMS_FCS */
#define GMP232X_MEAN_1_I_neg_FRMS_FCS   0x01000000   /**< Negative sequence system current FRMS_FCS */
#define GMP232X_MEAN_1_I_null_FRMS_FCS  0x02000000   /**< zero sequence system current FRMS_FCS */
#define GMP232X_MEAN_1_f                0x04000000   /**< Frequency */
#define GMP232X_MEAN_1_f2               0x08000000   /**< Frequency 2 */
#define GMP232X_MEAN_1_ROCOF            0x10000000   /**< ROCOF */
#define GMP232X_MEAN_1_PHI_U1I1         0x20000000   /**< PHI value for U1_I1 */
#define GMP232X_MEAN_1_PHI_U2I2         0x40000000   /**< PHI value for U2_I2 */
#define GMP232X_MEAN_1_PHI_U3I3         0x80000000   /**< PHI value for U3_I3 */
/** @} */

/**
 * @name Constants used at GMP232X_MEAN_CONFIG.ChanBitMask2
 * @{
 */

#define GMP232X_MEAN_2_P_L1_FRMS_FCS        0x00000001   /**< Active power Phase 1 (FRMS_FCS) */
#define GMP232X_MEAN_2_P_L2_FRMS_FCS        0x00000002   /**< Active power Phase 2 (FRMS_FCS) */
#define GMP232X_MEAN_2_P_L3_FRMS_FCS        0x00000004   /**< Active power Phase 3 (FRMS_FCS) */
#define GMP232X_MEAN_2_P_sumpos_FRMS_FCS    0x00000008   /**< Fundamental positive sequence system active power (FRMS_FCS) */
#define GMP232X_MEAN_2_P_sumneg_FRMS_FCS    0x00000010   /**< Fundamental negative sequence system active power (FRMS_FCS) */
#define GMP232X_MEAN_2_P_L1_TRMS_HCS        0x00000020   /**< Active power Phase 1 (TRMS_HCS) */
#define GMP232X_MEAN_2_P_L2_TRMS_HCS        0x00000040   /**< Active power Phase 2 (TRMS_HCS) */
#define GMP232X_MEAN_2_P_L3_TRMS_HCS        0x00000080   /**< Active power Phase 3 (TRMS_HCS) */
#define GMP232X_MEAN_2_P_sum_TRMS_HCS       0x00000100   /**< Active power sum (TRMS_HCS) */
#define GMP232X_MEAN_2_Q_L1_FRMS_FCS        0x00000200   /**< Reactive power Phase 1 (FRMS_FCS) */
#define GMP232X_MEAN_2_Q_L2_FRMS_FCS        0x00000400   /**< Reactive power Phase 2 (FRMS_FCS) */
#define GMP232X_MEAN_2_Q_L3_FRMS_FCS        0x00000800   /**< Reactive power Phase 3 (FRMS_FCS) */
#define GMP232X_MEAN_2_Q_sumpos_FRMS_FCS    0x00001000   /**< Fundamental positive sequence system reactive power (FRMS_FCS) */
#define GMP232X_MEAN_2_Q_sumneg_FRMS_FCS    0x00002000   /**< Fundamental negative sequence system reactive power (FRMS_FCS) */
#define GMP232X_MEAN_2_Q_L1_TRMS_HCS        0x00004000   /**< Reactive power Phase 1 (TRMS_HCS) */
#define GMP232X_MEAN_2_Q_L2_TRMS_HCS        0x00008000   /**< Reactive power Phase 2 (TRMS_HCS) */
#define GMP232X_MEAN_2_Q_L3_TRMS_HCS        0x00010000   /**< Reactive power Phase 3 (TRMS_HCS) */
#define GMP232X_MEAN_2_Q_sum_TRMS_HCS       0x00020000   /**< Reactive power sum (TRMS_HCS) */
#define GMP232X_MEAN_2_S_L1_FRMS_FCS        0x00040000   /**< Apparent power Phase 1 (FRMS_FCS) */
#define GMP232X_MEAN_2_S_L2_FRMS_FCS        0x00080000   /**< Apparent power Phase 2 (FRMS_FCS) */
#define GMP232X_MEAN_2_S_L3_FRMS_FCS        0x00100000   /**< Apparent power Phase 3 (FRMS_FCS) */
#define GMP232X_MEAN_2_S_sumpos_FRMS_FCS    0x00200000   /**< Fundamental positive sequence system apparent power (FRMS_FCS) */
#define GMP232X_MEAN_2_S_L1_TRMS_HCS        0x00400000   /**< Apparent power Phase 1 (TRMS_HCS) */
#define GMP232X_MEAN_2_S_L2_TRMS_HCS        0x00800000   /**< Apparent power Phase 2 (TRMS_HCS) */
#define GMP232X_MEAN_2_S_L3_TRMS_HCS        0x01000000   /**< Apparent power Phase 3 (TRMS_HCS) */
#define GMP232X_MEAN_2_S_sum_TRMS_HCS       0x02000000   /**< Apparent power sum (TRMS_HCS) */
#define GMP232X_MEAN_2_COSPHI_pos_FRMS_FCS  0x04000000   /**< Cos-phi of positive sequence powers (FRMS_FCS) */
#define GMP232X_MEAN_2_PF_L1_TRMS_HCS       0x08000000   /**< Power factor Phase 1 (TRMS_HCS) */
#define GMP232X_MEAN_2_PF_L2_TRMS_HCS       0x10000000   /**< Power factor Phase 2 (TRMS_HCS) */
#define GMP232X_MEAN_2_PF_L3_TRMS_HCS       0x20000000   /**< Power factor Phase 3 (TRMS_HCS) */
#define GMP232X_MEAN_2_PF_sum_TRMS_HCS      0x40000000   /**< Power factor sum  (TRMS_HCS) */
#define GMP232X_MEAN_2_Asym_U               0x80000000   /**< Voltage asymmetry */
/** @} */

/**
 * @name Constants used at GMP232X_MEAN_CONFIG.ChanBitMask3
 * @{
 */

#define GMP232X_MEAN_3_Asym_I   0x00000001   /**< Current asymmetry */
#define GMP232X_MEAN_3_THD_U1   0x00000002   /**< THD U1 */
#define GMP232X_MEAN_3_THD_U2   0x00000004   /**< THD U2 */
#define GMP232X_MEAN_3_THD_U3   0x00000008   /**< THD U3 */
#define GMP232X_MEAN_3_THDn_U1  0x00000010   /**< THDn U1 */
#define GMP232X_MEAN_3_THDn_U2  0x00000020   /**< THDn U2 */
#define GMP232X_MEAN_3_THDn_U3  0x00000040   /**< THDn U3 */
#define GMP232X_MEAN_3_THD_I1   0x00000080   /**< THD I1 */
#define GMP232X_MEAN_3_THD_I2   0x00000100   /**< THD I2 */
#define GMP232X_MEAN_3_THD_I3   0x00000200   /**< THD I3 */
#define GMP232X_MEAN_3_TDD_I1   0x00000400   /**< TDD I1 */
#define GMP232X_MEAN_3_TDD_I2   0x00000800   /**< TDD I2 */
#define GMP232X_MEAN_3_TDD_I3   0x00001000   /**< TDD I3 */
/** @} */


/**
 * Possible limit ids for MIO_CMD_GMP232X_GETLIMIT_STATE and Limit configuration defines
 */

#define GMP232X_LIM_1_MASK  0xFFFFF238   /**< Available limits for mask 1 */
#define GMP232X_LIM_2_MASK  0x3FFF8306   /**< Available limits for mask 2 */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETLIMIT_VOLTAGE
 * @{
 */

#define GMP232X_LIM_1_NEGSYS    0x00000008   /**< Negative system blocking */
#define GMP232X_LIM_1_V_LO1     0x00000010   /**< Voltage lower limit 1 */
#define GMP232X_LIM_1_V_LO2     0x00000020   /**< Voltage lower limit 2 */
#define GMP232X_LIM_1_V_LO3     0x00000200   /**< Voltage lower limit 3 */
#define GMP232X_LIM_1_V_HI1     0x00001000   /**< Voltage upper limit 1 */
#define GMP232X_LIM_1_V_HI2     0x00002000   /**< Voltage upper limit 2 */
#define GMP232X_LIM_1_V_HI3     0x00004000   /**< Voltage upper limit 3 */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETLIMIT_VFRT
 * @{
 */

#define GMP232X_LIM_1_VFRT1 0x00008000   /**< Voltage FRT 1 */
#define GMP232X_LIM_1_VFRT2 0x00010000   /**< Voltage FRT 2 */
#define GMP232X_LIM_1_VFRT3 0x00020000   /**< Voltage FRT 3 */
#define GMP232X_LIM_1_VFRT4 0x00040000   /**< Voltage FRT 4 */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETLIMIT_I
 * @{
 */

#define GMP232X_LIM_1_I_HI1 0x00080000   /**< Current upper limit 1 */
#define GMP232X_LIM_1_I_HI2 0x00100000   /**< Current upper limit 2 */
#define GMP232X_LIM_1_I_HI3 0x00200000   /**< Current upper limit 3 */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETLIMIT_QU
 * @{
 */

#define GMP232X_LIM_1_QU_GEN1   0x00400000   /**< QU limit 1 */
#define GMP232X_LIM_1_QU_GEN2   0x00800000   /**< QU limit 2 */
#define GMP232X_LIM_2_QU_PCC1   0x00000002   /**< QU limit PCC1 */
#define GMP232X_LIM_2_QU_PCC2   0x00000004   /**< QU limit PCC2 */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETLIMIT_FFRT
 * @{
 */

#define GMP232X_LIM_1_FFRT1 0x01000000   /**< Frequency FRT 1 */
#define GMP232X_LIM_1_FFRT2 0x02000000   /**< Frequency FRT 2 */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETLIMIT_FREQ
 * @{
 */

#define GMP232X_LIM_1_F_HI3 0x04000000   /**< Frequency upper limit 3 */
#define GMP232X_LIM_1_F_HI2 0x08000000   /**< Frequency upper limit 2 */
#define GMP232X_LIM_1_F_HI1 0x10000000   /**< Frequency upper limit 1 */
#define GMP232X_LIM_1_F_LO3 0x20000000   /**< Frequency lower limit 3 */
#define GMP232X_LIM_1_F_LO2 0x40000000   /**< Frequency lower limit 2 */
#define GMP232X_LIM_1_F_LO1 0x80000000   /**< Frequency lower limit 1 */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETLIMIT_HARMONICS
 * @{
 */

#define GMP232X_LIM_2_HARM_U    0x00008000   /**< Voltage harmonics */
#define GMP232X_LIM_2_HARM_I    0x00200000   /**< Current harmonics */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETLIMIT_ASYM
 * @{
 */

#define GMP232X_LIM_2_U_ASYM1   0x00010000   /**< Voltage asymmetry 1 */
#define GMP232X_LIM_2_U_ASYM2   0x00020000   /**< Voltage asymmetry 2 */
#define GMP232X_LIM_2_I_ASYM1   0x00080000   /**< Current asymmetry 1 */
#define GMP232X_LIM_2_I_ASYM2   0x00100000   /**< Current asymmetry 2 */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETLIMIT_THDTDD
 * @{
 */

#define GMP232X_LIM_2_THD_U 0x00040000   /**< Voltage THD */
#define GMP232X_LIM_2_TDD_I 0x01000000   /**< Current TDD */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETLIMIT_VECTORJUMP
 * @{
 */

#define GMP232X_LIM_2_VECTORJUMP1   0x00400000   /**< Vector jump 1 */
#define GMP232X_LIM_2_VECTORJUMP2   0x00800000   /**< Vector jump 2 */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_SETLIMIT_DIR_CURRENT
 * @{
 */

#define GMP232X_LIM_2_DIR_CURRENT1  0x02000000   /**< Directional overcurrent 1 */
#define GMP232X_LIM_2_DIR_CURRENT2  0x04000000   /**< Directional overcurrent 2 */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETLIMIT_ROCOF
 * @{
 */

#define GMP232X_LIM_2_ROCOF 0x08000000   /**< ROCOF */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETLIMIT_MAX_POWER
 * @{
 */

#define GMP232X_LIM_2_MAX_POWER1    0x10000000   /**< Maximum power 1 */
#define GMP232X_LIM_2_MAX_POWER2    0x20000000   /**< Maximum power 2 */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETLIMIT_REVERSE_POWER
 * @{
 */

#define GMP232X_LIM_2_REV_POWER1    0x00000100   /**< Reverse power 1 */
#define GMP232X_LIM_2_REV_POWER2    0x00000200   /**< Reverse power 2 */
/** @} */

/**
 * @name Possible IDs for MIO_CMD_GMP232X_G[S]ETMANUALRELAY
 * @{
 */

#define GMP232X_LIM_2_MANUAL_RELAY1 0x40000000   /**< Manual relay 1 */
#define GMP232X_LIM_2_MANUAL_RELAY2 0x80000000   /**< Manual relay 2 */
/** @} */

/**
 * @name Constants used in GMP232X_LIMIT_QU.Mode
 * @{
 */

#define GMP232X_QU_MODE_REACTIVEPOWERTHRESHOLD  0    /**< Reactive power threshold */
#define GMP232X_QU_MODE_ANGLE                   1    /**< Angle */
/** @} */

/**
 * @name Maximum index of mean and statistic values
 * @{
 */

#define GMP232X_MAX_IDX_STATISTICS      87   /**< Highest possible index; used in gmp232x_GetStatisticRanged() or similar */
#define GMP232X_MAX_IDX_MEAN_MEASURED   86   /**< Highest possible index of mean measure values; used in gmp232x_GetMeanValueRanged() or similar */
#define GMP232X_MAX_IDX_MEAN            750  /**< Highest possible index of mean values (total: measured and harmonics); used in gmp232x_GetMeanValueRanged() or similar */
/** @} */

/**
 * @name Values used at MIO_CMD_GMP232X_GETMEANVALUE_* to specify the meanValue Idx
 * @{
 */

#define GMP232X_AVERAGER1   0x1  /**< Averager 1 */
#define GMP232X_AVERAGER2   0x2  /**< Averager 2 */
#define GMP232X_AVERAGER3   0x4  /**< Averager 3 */
/** @} */

/**
 * @name Constants related to xFRT limit functions
 * @{
 */

#define GMP232X_MAX_FFRTPOINTS  11   /**< maximum number of FFRT points */
#define GMP232X_MAX_VFRTPOINTS  11   /**< maximum number of VFRT points */
/** @} */

/**
 * @name Possible values for GMP232X_LIMIT_VFRT.FrtType
 * @{
 */

#define GMP232X_XFRT_SELECT_LO  0    /**< use as low frt limit */
#define GMP232X_XFRT_SELECT_HI  1    /**< use as high frt limit */
/** @} */

/**
 * @name Possible values for GMP232X_LIMIT_FFRT.Source
 * @{
 */

#define GMP232X_FFRT_SELECT_F       0    /**< use default frequency */
#define GMP232X_FFRT_SELECT_F_AVG   1    /**< use f_avg */
/** @} */

/**
 * @name Defines used as ValueIdx at MIO_CMD_GMP232X_[GS]ETHARMONICSLIMIT
 * @{
 */

#define GMP232X_MAX_LIMIT_HARMONICS 49   /**< Used in GMP232X_LIMIT_HARMONICS only! */
/** @} */

/**
 * @name Possible values for GMP232X_LIMIT_HARMONICS.Source
 * @{
 */

#define GMP232X_HARMONICS_SELECT_DIRECT_FFT 0    /**< Use current values */
/** @} */

/**
 * @name Possible values for limits which support PhaseMode setting
 * @{
 */

#define GMP232X_LIMIT_PHASE_ALL         0    /**< All phases required to trigger */
#define GMP232X_LIMIT_PHASE_ANY         1    /**< Just one phases required to trigger */
#define GMP232X_LIMIT_PHASE_SUM         2    /**< The sum of phases is used for trigger */
#define GMP232X_LIMIT_REV_POWER_SUM     3    /**< Reverse power limit sum */
#define GMP232X_LIMIT_REV_POWER_PHASE   4    /**< Reverse power limit phase */
/** @} */

/**
 * @name Possible values for GMP232X_LIMIT_REVERSE_POWER.PowerDirection
 * @{
 */

#define GMP232X_LIMIT_POWERDIR_NEGATIVE 0    /**< Negative active power direction */
#define GMP232X_LIMIT_POWERDIR_POSITIVE 1    /**< Postive active power direction */
/** @} */

/**
 * @name Possible values for GMP232X_LIMIT_DIR_CURRENT.CurrentDirection
 * @{
 */

#define GMP232X_LIMIT_CURDIR_NEGATIVE   0    /**< Negative active power direction */
#define GMP232X_LIMIT_CURDIR_POSITIVE   1    /**< Positive active power direction */
/** @} */

/**
 * @name Values used at GMP232X_LIMIT_QU.ReactivePowerDirection to specify the direction of the reactive power flow.
 * @{
 */

#define GMP232X_QU_REACTIVEPOWER_DIR_INDUCTIVE  0x00     /**< QU reactive power direction inductive */
#define GMP232X_QU_REACTIVEPOWER_DIR_CAPACITIVE 0x01     /**< QU reactive power direction capacitive */
#define GMP232X_QU_REACTIVEPOWER_DIR_BOTH       0x02     /**< QU reactive power direction inductive and capacitive */
/** @} */

/**
 * @name Possible states for MIO_CMD_GMP232X_GETLIMIT_STATE
 * @{
 */

#define GMP232X_LIMIT_STATE_DISABLED    0    /**< Limit disabled or inhibited */
#define GMP232X_LIMIT_STATE_ENABLED     1    /**< Limit enabled */
#define GMP232X_LIMIT_STATE_STARTED     2    /**< Limit started */
#define GMP232X_LIMIT_STATE_TRIPPED     3    /**< Limit tripped */
/** @} */
/** @} */
/**
 * @since V1.01 Release
 */
typedef struct
{
    UINT32  Mask1;              /**< First limit mask (#GMP232X_LIM_1_V_LO1 or similar); bitfield */
    UINT32  Mask2;              /**< Second limit mask (#GMP232X_LIM_2_HARM_U or similar); bitfiled */
} GMP232X_LIMIT_MASK;

/**
 * Structure for DoCmd-function, for some of pattern MIO_CMD_GMP232X_SETLIMIT_* / MIO_CMD_GMP232X_GETLIMIT_
 * Data structure for undervoltage, overvoltage, Voltageblocking and Frequencyblocking (for GMP232X_LIMIT_VECTORJUMP)
 * @since V1.01 Release
 */
typedef struct
{
    GMP232X_LIMIT_MASK  BlockingMask;    /**< Blocking mask */
    UINT32              Delay;  /**< Blocking time, 0 == infinite; [0 - 600000]; 1msec; (0) */
} GMP232X_LIMIT_BLOCKING;

/**
 * Structure for DoCmd-function, for some of pattern MIO_CMD_GMP232X_SETVECTORJUMPLIMIT / MIO_CMD_GMP232X_GETVECTORJUMPLIMIT_
 * Data structure for negative system setting
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32  Enable;             /**< Enable the negative system setting; bool; (false) */
    UINT32  Value;              /**< Value; [0 - 4000]; 0.1% pu(U); (0) */
    UINT32  Hysteresis;         /**< Hysteresis; [0 - 4000]; 0.1% pu(U); (0) */
} GMP232X_LIMIT_NEGSYS;


/**
 * @name
 * @{
 */

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_RELAYCFG / MIO_CMD_GMP232X_GETLIMIT_RELAYCFG
 * Configuration structure for limit relay configuration
 * @since V1.01 Release
 */
typedef struct
{
    GMP232X_LIMIT_MASK  Relay1Cfg;   /**< Limit mask of relay 1 */
    GMP232X_LIMIT_MASK  Relay2Cfg;   /**< Limit mask of relay 2 */
} GMP232X_LIMIT_RELAYCFG;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_I / MIO_CMD_GMP232X_GETLIMIT_I
 * Configuration structure for current limit
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32  Enable;             /**< Enable/disable the limit; bool; (false) */
    UINT32  Value;              /**< Value of rated current; [0 - 4000]; 0.1% pu(I); (0) */
    UINT32  Hysteresis;         /**< Hysteresis of rated current; [0 - 4000]; 0.1% pu(I); (0) */
    UINT32  Source;             /**< Source to use; #GMP232X_SOURCE_TRMS or similar; (GMP232X_SOURCE_FRMS) */
    UINT32  Delay;              /**< Delay; [0 - 600000]; 1msec; (0) */
    UINT32  PhaseMode;          /**< Phase mode #GMP232X_LIMIT_PHASE_ALL or similar; enum; (GMP232X_LIMIT_PHASE_ALL) */
    UINT32  RelaySelector;      /**< Which relay to trigger; enum; (GMP232X_RELAY_NONE) */
    BOOL32  TriggerScope;       /**< Trigger scope in case of alarm; bool; (false) */
} GMP232X_LIMIT_I;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_THDTDD / MIO_CMD_GMP232X_GETLIMIT_THDTDD
 * Configuration structure for THD TDD limit
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32  Enable;             /**< Enable/disable the limit; bool; (false) */
    UINT32  Value;              /**< Value; [0 - 5000]; 0.1%; (0) */
    UINT32  Hysteresis;         /**< Hysteresis; [0 - 5000]; 0.1%; (0) */
    UINT32  Source;             /**< Source #GMP232X_THDTDD_RATED or similar; enum; (GMP232X_THDTDD_RATED) */
    UINT32  Delay;              /**< Delay; [0 - 600000]; 1msec; (0) */
    UINT32  PhaseMode;          /**< Phase mode #GMP232X_LIMIT_PHASE_ALL or similar; enum; (GMP232X_LIMIT_PHASE_ALL) */
    UINT32  RelaySelector;      /**< Which relay to trigger; enum; (GMP232X_RELAY_NONE) */
    BOOL32  TriggerScope;       /**< Trigger scope in case of alarm; bool; (false) */
} GMP232X_LIMIT_THDTDD;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_ASYM / MIO_CMD_GMP232X_GETLIMIT_ASYM
 * Configuration structure for asym limit
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32  Enable;             /**< Enable/disable the limit; bool; (false) */
    UINT32  Value;              /**< Value; [0 - 6000]; 0.1%; (0) */
    UINT32  Hysteresis;         /**< Hysteresis; [0 - 6000]; 0.1%; (0) */
    UINT32  Delay;              /**< Delay; [0 - 600000]; 1msec; (0) */
    UINT32  RelaySelector;      /**< Which relay to trigger; enum; (GMP232X_RELAY_NONE) */
    BOOL32  TriggerScope;       /**< Trigger scope in case of alarm; bool; (false) */
} GMP232X_LIMIT_ASYM;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_ROCOF / MIO_CMD_GMP232X_GETLIMIT_ROCOF
 * Configuration structure for ROCOF limit
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32                  Enable;  /**< Enable/disable the limit; bool; (false) */
    UINT32                  Value;   /**< Value; [0 - 1000]; 0.01Hz/s; (0) */
    UINT32                  Hysteresis;  /**< Hysteresis; [0 - 1000]; 0.01Hz/s; (0) */
    UINT32                  Delay;   /**< Delay; [0 - 600000]; 1msec; (0) */
    UINT32                  RelaySelector;   /**< Which relay to trigger; enum; (GMP232X_RELAY_NONE) */
    BOOL32                  TriggerScope;    /**< Trigger scope in case of alarm; bool; (false) */
    GMP232X_LIMIT_BLOCKING  OVB;     /**< Over voltage blocking values; struct */
    GMP232X_LIMIT_BLOCKING  UVB;     /**< Under voltage blocking values; struct */
} GMP232X_LIMIT_ROCOF;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_MAX_POWER / MIO_CMD_GMP232X_GETLIMIT_MAX_POWER
 * Configuration structure for max. power limit
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32  Enable;             /**< Enable/disable the limit; bool; (false) */
    UINT32  Value;              /**< Value; [0 - 5000]; 0.1% pu(S); (0) */
    UINT32  Hysteresis;         /**< Hysteresis; [0 - 5000]; 0.1% pu(S); (0) */
    UINT32  Delay;              /**< Delay; [0 - 600000]; 1msec; (0) */
    UINT32  RelaySelector;      /**< Which relay to trigger; enum; (GMP232X_RELAY_NONE) */
    BOOL32  TriggerScope;       /**< Trigger scope in case of alarm; bool; (false) */
} GMP232X_LIMIT_MAX_POWER;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_REVERSE_POWER / MIO_CMD_GMP232X_GETLIMIT_REVERSE_POWER
 * Configuration structure for reverse power limit
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32  Enable;             /**< Enable/disable the limit; bool; (false) */
    UINT32  Value;              /**< limit value; [0 - 5000]; 0.1% pu(S); (0) */
    UINT32  Hysteresis;         /**< limit hysteresis; [0 - 5000]; 0.1%; pu(S); (0) */
    UINT32  PowerDirection;     /**< Power direction; e.g #GMP232X_LIMIT_POWERDIR_NEGATIVE or similar; enum; (GMP232X_LIMIT_POWERDIR_POSITIVE) */
    UINT32  Source;             /**< Source to use; #GMP232X_SOURCE_FRMS or similar; enum; (GMP232X_SOURCE_FRMS) */
    UINT32  PhaseMode;          /**< Phase mode to use; #GMP232X_LIMIT_REV_POWER_SUM or similar; enum; (GMP232X_LIMIT_REV_POWER_SUM) */
    UINT32  Delay;              /**< limit delay; [0 - 600000]; 1msec; (0) */
    UINT32  RelaySelector;      /**< Which relay to trigger; enum; (GMP232X_RELAY_NONE) */
    BOOL32  TriggerScope;       /**< Trigger scope in case of alarm; bool; (false) */
} GMP232X_LIMIT_REVERSE_POWER;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_DIR_CURRENT / MIO_CMD_GMP232X_GETLIMIT_DIR_CURRENT
 * Configuration structure for current direction limit
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32  Enable;             /**< Enable/disable the limit; bool; (false) */
    UINT32  Value;              /**< Value; [10 - 4000]; 0.1% pu(I); (10) */
    UINT32  Hysteresis;         /**< Hysteresis; [0 - 4000]; 0.1% pu(I); (0) */
    UINT32  Source;             /**< Source to use; #GMP232X_SOURCE_FRMS or similar; enum; (GMP232X_SOURCE_FRMS) */
    UINT32  CurrentDirection;   /**< Current direction; #GMP232X_LIMIT_CURDIR_NEGATIVE or similar; enum; (GMP232X_LIMIT_CURDIR_POSITIVE) */
    UINT32  Delay;              /**< Delay; [0 - 600000]; 1msec; (0) */
    UINT32  PhaseMode;          /**< Phase mode; #GMP232X_LIMIT_PHASE_ALL or similar; enum; (GMP232X_LIMIT_PHASE_ALL) */
    UINT32  RelaySelector;      /**< Which relay to trigger; enum; (GMP232X_RELAY_NONE) */
    BOOL32  TriggerScope;       /**< Trigger scope in case of alarm; bool; (false) */
} GMP232X_LIMIT_DIR_CURRENT;

/** @} */
/**
 * Voltage limit configuration
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_VOLTAGE / MIO_CMD_GMP232X_GETLIMIT_VOLTAGE
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32  Enable;             /**< Enable/disable the limit; bool; (false) */
    UINT32  Value;              /**< Value; [0 - 4000]; 0.1% pu(U); (0) */
    UINT32  Hysteresis;         /**< Hysteresis; [0 - 4000]; 0.1% pu(U); (0) */
    UINT32  Source;             /**< Source for monitoring (#GMP232X_SOURCE_TRMS or similar); enum; (GMP232X_SOURCE_FRMS) */
    UINT32  Delay;              /**< Delay; [0 - 600000]; 1msec; (0) */
    UINT32  PhaseMode;          /**< Phase mode; #GMP232X_LIMIT_PHASE_ALL or similar; enum; (GMP232X_LIMIT_PHASE_ALL) */
    UINT32  RelaySelector;      /**< Which relay to trigger; enum; (GMP232X_RELAY_NONE) */
    BOOL32  TriggerScope;       /**< Trigger scope in case of alarm; bool; (false) */
} GMP232X_LIMIT_V;

/**
 * VectorJump configuration.
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_VECTORJUMP / MIO_CMD_GMP232X_GETLIMIT_VECTORJUMP
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32                  Enable;  /**< Enable/disable the limit; bool; (false) */
    UINT32                  Value;   /**< Limit value; [36 - 400]; 0.1 degrees; (100) */
    UINT32                  PulseLength;     /**< Pulse length; [0 - 600000]; 1msec; (10) */
    UINT32                  RelaySelector;   /**< Which relay to trigger; enum; (GMP232X_RELAY_NONE) */
    BOOL32                  TriggerScope;    /**< Trigger scope in case of alarm; bool; (false) */
    GMP232X_LIMIT_BLOCKING  VoltageBlocking;     /**< Under voltage and/or negative sequence system blocking settings; struct */
    GMP232X_LIMIT_BLOCKING  FrequencyBlocking;   /**< Frequency (Hi+Lo) blocking settings; struct */
} GMP232X_LIMIT_VECTORJUMP;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETSTATISTIC_* and MIO_CMD_GMP232X_GETMEANVALUE_
 * used within GMP232X_STATISTIC_DATA and GMP232X_MEAN_DATA
 * @since V1.01 Release
 */
typedef struct
{
    UINT32  Timestamp_s;        /**< Timestamp seconds (0 == invalid value); 1sec since 1.1.1970 0:00 */
    UINT32  Timestamp_ms;       /**< Timestamp milliseconds; 1msec */
    REAL64  Value;              /**< Data point value */
} GMP232X_DATAPOINT_VALUE;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETSTATISTIC_
 * used within GMP232X_STATISTIC
 * @since V1.01 Release
 */
typedef struct
{
    GMP232X_DATAPOINT_VALUE Minimum;     /**< Minimum data point */
    GMP232X_DATAPOINT_VALUE Maximum;     /**< Maximum data point */
} GMP232X_DATAPOINT_STATISTIC;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETSTATISTIC_
 * used within GMP232X_STATISTIC
 * @since V1.01 Release
 */
typedef struct
{
    CHAR8   Name[32];           /**< Name of the data point */
    UINT32  SiUnit;             /**< Si-Unit (UFB_SIUNIT_NONE or similar) */
    CHAR8   UnitStr[12];        /**< Unit optional text ("V", "uA"...) */
} GMP232X_DATAPOINT_INFO;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETSTATISTIC_
 * @since V1.01 Release
 */
typedef struct
{
    GMP232X_DATAPOINT_STATISTIC DataPoint;   /**< Statistic values (Min, Max) */
    GMP232X_DATAPOINT_INFO      AddInf;  /**< Additional information */
} GMP232X_STATISTIC;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETMEANVALUE_
 * used within GMP232X_MEAN
 * @since V1.01 Release
 */
typedef struct
{
    GMP232X_DATAPOINT_VALUE Minimum;     /**< Minimum data point */
    GMP232X_DATAPOINT_VALUE Avg;     /**< Average data point */
    GMP232X_DATAPOINT_VALUE Maximum;     /**< Maximum data point */
} GMP232X_DATAPOINT_MEAN;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETMEANVALUE_INDEXED
 * Data structure to build a mean value request
 * @since V1.01 Release
 */
typedef struct
{
    UINT32  dataPointIdx;       /**< Specific datapoint index (#GMP232X_IDX_U_L1N_INST or similar) */
    UINT32  averager;           /**< Identifier of the averaging point (#GMP232X_AVERAGER1 or similar) for dataPointIdx */
} GMP232X_MEAN_REQUEST;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETMEANVALUE_
 * @since V1.01 Release
 */
typedef struct
{
    GMP232X_DATAPOINT_MEAN  DataPoint;   /**< Averager data points (Min, Avg, Max) */
    GMP232X_DATAPOINT_INFO  AddInf;  /**< Additional information */
} GMP232X_MEAN;

/**
 * Harmonics Limit, Voltage and current harmonics
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_HARMONICS / MIO_CMD_GMP232X_GETLIMIT_HARMONICS
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32  Enable;             /**< Enable/disable the limit; bool; (false) */
    UINT32  Value[GMP232X_MAX_LIMIT_HARMONICS];  /**< Harmonic values - array of length: #GMP232X_MAX_LIMIT_HARMONICS; [0 - 1000]; 0.1%; (0) */
    UINT32  Source;             /**< Source to use; #GMP232X_HARMONICS_SELECT_DIRECT_FFT; enum; (GMP232X_HARMONICS_SELECT_DIRECT_FFT) */
    UINT32  Delay;              /**< Delay; [0 - 600000]; 1msec; (0) */
    UINT32  PhaseMode;          /**< Phase mode #GMP232X_LIMIT_PHASE_ALL or similar; enum; (GMP232X_LIMIT_PHASE_ALL) */
    UINT32  RelaySelector;      /**< Which relay to trigger; enum; (GMP232X_RELAY_NONE) */
    BOOL32  TriggerScope;       /**< Trigger scope in case of alarm; bool; (false) */
} GMP232X_LIMIT_HARMONICS;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_FREQ / MIO_CMD_GMP232X_GETLIMIT_FREQ
 * Data structure frequency limit
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32                  Enable;  /**< Enable/disable the limit; bool; (false) */
    UINT32                  Value;   /**< Value; [10000 - 75000]; 1mHz; (10000) */
    UINT32                  Hysteresis;  /**< Hysteresis; [0 - 75000]; 1mHz; (0) */
    UINT32                  Delay;   /**< Delay; [0 - 600000]; 1msec; (0) */
    UINT32                  RelaySelector;   /**< Which relay to trigger; enum; (GMP232X_RELAY_NONE) */
    BOOL32                  TriggerScope;    /**< Trigger scope in case of alarm; bool; (false) */
    UINT32                  Source;  /**< Frequency source to use; #GMP232X_SOURCE_F or similar; (GMP232X_SOURCE_F2) */
    GMP232X_LIMIT_BLOCKING  UVB;     /**< Under voltage blocking values; struct */
    GMP232X_LIMIT_BLOCKING  OVB;     /**< Over voltage blocking values; struct */
} GMP232X_LIMIT_FREQ;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_FFRT / MIO_CMD_GMP232X_GETLIMIT_FFRT
 * Data structure for FFRT configuration
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32                  Enable;  /**< Enable/disable the limit; bool; (false) */
    UINT32                  FrtType;     /**< FRT type; #GMP232X_XFRT_SELECT_HI of similar; enum; (GMP232X_XFRT_SELECT_HI) */
    UINT32                  Source;  /**< FRT value source (#GMP232X_SOURCE_F or similar); enum; (GMP232X_SOURCE_F2) */
    UINT32                  InitThreshold;   /**< threshold of initialization; [10000 - 75000]; 1mHz; (10000) */
    UINT32                  FallbackTime;    /**< Fallback time, [0 - 600000]; 1msec; (0) */
    UINT32                  FallbackFreq;    /**< Fallback frequency; [10000 - 75000]; 1mHz; (10000) */
    GMP232X_FREQPOINT       FrequencyPoints[GMP232X_MAX_FFRTPOINTS];     /**< FFRT Table; array */
    UINT32                  PointCount;  /**< used points in frequencyPoints array; [2 - #GMP232X_MAX_FFRTPOINTS]; number; (2) */
    UINT32                  RelaySelector;   /**< Which relay to trigger; enum; (GMP232X_RELAY_NONE) */
    BOOL32                  TriggerScope;    /**< Trigger scope in case of alarm; bool; (false) */
    GMP232X_LIMIT_BLOCKING  UVB;     /**< under voltage blocking values; struct */
    GMP232X_LIMIT_BLOCKING  OVB;     /**< over voltage blocking values; struct */
} GMP232X_LIMIT_FFRT;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_VFRT / MIO_CMD_GMP232X_GETLIMIT_VFRT
 * Data structure for VFRT configuration
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32                  Enable;  /**< Enable/disable the limit; bool; (false) */
    UINT32                  FrtType;     /**< FRT type select (#GMP232X_XFRT_SELECT_HI or similar); enum; (GMP232X_XFRT_SELECT_HI) */
    UINT32                  Source;  /**< FRT value source (#GMP232X_SOURCE_FRMS or similar); enum; (GMP232X_SOURCE_FRMS) */
    UINT32                  InitVoltage;     /**< Initial voltage; [0 - 4000]; 0.1% pu(U); (0) */
    UINT32                  FallbackTime;    /**< Fallback time, [0 - 600000]; 1msec; (0) */
    UINT32                  FallbackVoltage;     /**< Fallback voltage; [0 - 4000]; 0.1% pu(U); (0) */
    GMP232X_VOLTAGEPOINT    VoltagePoints[GMP232X_MAX_VFRTPOINTS];   /**< VFRT Table; array */
    UINT32                  PointCount;  /**< used points in frequencyPoints array; [2 - #GMP232X_MAX_VFRTPOINTS]; number; (2) */
    UINT32                  RelaySelector;   /**< Which relay to trigger; enum; (GMP232X_RELAY_NONE) */
    BOOL32                  TriggerScope;    /**< Trigger scope in case of alarm; bool; (false) */
} GMP232X_LIMIT_VFRT;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETLIMIT_QU / MIO_CMD_GMP232X_GETLIMIT_QU
 * Data structure for QU limit
 * @since V1.01 Release
 */
typedef struct
{
    BOOL32  Enable;             /**< Enable/disable the limit; (false) */
    UINT32  Mode;               /**< Mode; #GMP232X_QU_MODE_REACTIVEPOWERTHRESHOLD or similar; enum; (GMP232X_QU_MODE_REACTIVEPOWERTHRESHOLD) */
    UINT32  ReactivePowerDirection;  /**< Direction of reactive power #GMP232X_QU_REACTIVEPOWER_DIR_INDUCTIVE or similar; enum; (GMP232X_QU_REACTIVEPOWER_DIR_INDUCTIVE) */
    UINT32  MinCurrent;         /**< Minimum current; [0 - 1000]; 0.1% pu(I); (0) */
    UINT32  ThresholdVoltage;   /**< Threshold voltage; [50 - 1500]; 0.1% pu(U); (50) */
    UINT32  FallbackCurrent;    /**< Fallback current; [900 - 999]; 0.1% of MinCurrent; (900) */
    UINT32  FallbackVoltage;    /**< Fallback voltage; [1001 - 1200]; 0.1% of ThresholdVoltage; (1001) */
    UINT32  PowerAngle;         /**< Power angle (considered only if Mode is #GMP232X_QU_MODE_ANGLE); [0 - 100]; 0.1 degrees; (0) */
    UINT32  ReactivePowerThreshold;  /**< Reactive power threshold (considered only if Mode is #GMP232X_QU_MODE_REACTIVEPOWERTHRESHOLD), [10 - 300]; 0.1% pu(S); (10) */
    UINT32  GeneratorRelay;     /**< Generator protection relay; #GMP232X_RELAY_1 or similar; enum; (GMP232X_RELAY_NONE) */
    UINT32  PCCRelay;           /**< PCC protection relay; #GMP232X_RELAY_1 or similar; enum; (GMP232X_RELAY_NONE) */
    UINT32  GeneratorProtectionDelay;    /**< Generator protection delay; [0 - 600000]; 1msec; (0) */
    UINT32  PCCProtectionDelay; /**< PCC protection delay; [0 - 600000]; 1msec; (0) */
    BOOL32  TriggerScope;       /**< Trigger scope in case of alarm; bool; (false) */
} GMP232X_LIMIT_QU;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETLIMIT_STATUS
 * @since V1.01 Release
 */
typedef struct
{
    UINT32  LimitStartedMask1;  /**< Limit start status (#GMP232X_LIM_1_V_LO1 or similar); bitfield */
    UINT32  LimitStartedMask2;  /**< Limit start status (#GMP232X_LIM_2_HARM_U or similar); bitfield */
    UINT32  LimitTrippedMask1;  /**< Limit tripped status (#GMP232X_LIM_1_V_LO1 or similar); bitfield */
    UINT32  LimitTrippedMask2;  /**< Limit tripped status (#GMP232X_LIM_2_HARM_U or similar); bitfield */
} GMP232X_LIMIT_STATUS;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_SETMEANCFG
 * @since V1.01 Release
 */
typedef struct
{
    UINT32  ChanBitMask1;       /**< Bit mask 1 of enabled channels. (#GMP232X_MEAN_1_U_L1N_FRMS_FCS or similar); bitfield */
    UINT32  ChanBitMask2;       /**< Bit mask 2 of enabled channels. (#GMP232X_MEAN_2_P_L1_FRMS_FCS or similar); bitfield */
    UINT32  ChanBitMask3;       /**< Bit mask 3 of enabled channels. (#GMP232X_MEAN_3_Asym_I or similar); bitfield */
} GMP232X_MEAN_CONFIG;

/**
 * Structure for DoCmd-function MIO_CMD_GMP232X_GETHISTORYTOTAL
 * @since V1.01 Release
 */
typedef struct
{
    UINT32  Total;              /**< Total count of history entries */
    UINT32  LatestIndex;        /**< The index of the latest history entry */
} GMP232X_HISTORY_COUNT;

#if M_OS_VXWORKS


/*
 * This part contains all abstract do commands of GMP232X
 * @generated
 */
#include <mio_e.h>

/**
 * @ingroup GMP232X_ReadBulkValues_DoCmds
 * @brief Reads a collection of relevant FRMS FCS values. This function combines related values that can
 * be fetched together instead of reading them by their dedicated functions.
 * Using the function improves performance while simplifying client side logic.
 * @note Updated 2x per period
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] bulkFrmsFcs        FRMS FCS bulk data structure returned by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetBulkFrmsFcs(void *DrvId, UINT32 Chan, GMP232X_BULK_FRMS_FCS *bulkFrmsFcs)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETBULK_FRMS_FCS, bulkFrmsFcs);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadBulkValues_DoCmds
 * @brief Reads a collection of relevant TRMS HCS values. This function combines related values that can
 * be fetched together instead of reading them by their dedicated functions.
 * Using the function improves performance while simplifying client side logic.
 * @note Updated 2x per period
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] bulkTrmsHcs        TRMS HCS bulk data structure returned by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetBulkTrmsHcs(void *DrvId, UINT32 Chan, GMP232X_BULK_TRMS_HCS *bulkTrmsHcs)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETBULK_TRMS_HCS, bulkTrmsHcs);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadBulkValues_DoCmds
 * @brief Reads a collection of relevant THD and TDD values. This function combines related values that can
 * be fetched together instead of reading them by their dedicated functions.
 * Using the function improves performance while simplifying client side logic.
 * @note Updated every 10 periods
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  selector           Type selector to be specified; #GMP232X_THDTDD_RATED or similar, no combinations allowed
 * @param[out] bulkTHD_TDD        THD TDD data structure returned by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetBulkThdTdd(void *DrvId, UINT32 Chan, UINT32 selector, GMP232X_BULK_THD_TDD *bulkTHD_TDD)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETBULK_THD_TDD, selector, bulkTHD_TDD);
	return (retValue);
}


/**
 * @ingroup GMP232X_Config_DoCmds
 * @brief Enables or disables Runthrough mode; only applicable,
 * if #GMP232X_CONFIG_EXT.RuntimeConfiguration is activated. This function can be used by an
 * application during runtime as an alternative to setting the "RunThrough" parameter in the module configuration.
 * After changing the RunThrough mode setting, gmp232x_GetRunThrough() can be used to read the latest setting.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  enable             Enables Runthrough mode if set (TRUE), disables Runthrough if FALSE
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_SetRunThrough(void *DrvId, UINT32 Chan, BOOL32 enable)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETRUNTHROUGH, enable);
	return (retValue);
}


/**
 * @ingroup GMP232X_SampleValues_DoCmds
 * @brief Reads all pending samples beginning from a given start index up until the latest written sample index.
 * Although the number of samples returned can be below the size of #GMP232X_SAMPLE_BUFFERSIZE, a buffer of size #GMP232X_SAMPLE_BUFFERSIZE has to be
 * provided in order to ensure that no data is overwritten in case the number of samples returned exceed the size of the memory provided. The actual
 * number of samples is returned by the parameter newSamples. The value of startIdx is normally determined/calculated/derived from a previous sample read operation but has to be
 * smaller than the size of #GMP232X_SAMPLE_BUFFERSIZE.
 * @note Update rate depends on sample configuration
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  startIdx           Start/Offset index for sample values [0 up to (#GMP232X_SAMPLE_BUFFERSIZE-1)]; the samples are read beginning from this value
 * @param[out] sampleData[]       Array of type GMP232X_SAMPLE_VAL with size #GMP232X_SAMPLE_BUFFERSIZE, always use #GMP232X_SAMPLE_BUFFERSIZE as array size
 * @param[out] newSamples         Number of new samples that have been read (matches the number of valid samples in the sampleData array, beginning from array index 0); only utilize returned sample values up to this index value
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Delivers zero or up to #GMP232X_SAMPLE_BUFFERSIZE samples at most.
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetPendingSamples(void *DrvId, UINT32 Chan, UINT32 startIdx, GMP232X_SAMPLE_VAL *sampleData, UINT32  *newSamples)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETPENDINGSAMPLES, startIdx, sampleData, newSamples);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads the phase angle reference values. Although identical in composition,
 * this function provides the same data fields as gmp232x_GetPhaseRef() but with reduced resolution.
 * Therefore, its use should be considered if certain performance critical operations are an issue.
 * @note Updated 2x per period
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] phaseRef           Phase reference data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath PHASEREF_S
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetPhaseRefS(void *DrvId, UINT32 Chan, GMP232X_PHASEREF_S *phaseRef)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETPHASE_REF_S, phaseRef);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadBulkValues_DoCmds
 * @brief Reads a collection of relevant values regarding relevant symmetric components.
 * This function combines related values that can be fetched together instead of reading them by
 * their dedicated functions. Using the function improves performance while simplifying client side logic.
 * @note Updated 2x per period
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] bulkSymComponents  Symmetric components bulk data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetBulkSymComponents(void *DrvId, UINT32 Chan, GMP232X_BULK_SYMCOMPONENTS *bulkSymComponents)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETBULK_SYMCOMPONENTS, bulkSymComponents);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadBulkValues_DoCmds
 * @brief Reads a collection of relevant FRMS FCC values.
 * This function combines related values that can be fetched together instead of reading them by
 * their dedicated functions. Using the function improves performance while simplifying client side logic.
 * @note Updated with each sampled value (approx. 100 usec)
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] pBulkFRMSFCC       FRMS FCC bulk data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetBulkFrmsFcc(void *DrvId, UINT32 Chan, GMP232X_BULK_FRMS_FCC *pBulkFRMSFCC)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETBULK_FRMS_FCC, pBulkFRMSFCC);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads the FRMS FCC power values.
 * The returned data depends on the measure mode that is used, defined by the parameter "CardMode" (SolutionCenter configurator) or
 * GMP232X_CONFIG_EXT.Mode when invoking gmp232x_SetConfigExt()
 * @note Updated with each sampled value (approx. 100 usec)
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] powers             FRMS FCC powers data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath POWERS_FRMS_FCC
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetPowersFrmsFcc(void *DrvId, UINT32 Chan, GMP232X_POWERS_FRMS_FCC *powers)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETPOWERS_FRMS_FCC, powers);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads the FRMS FCS power value.
 * The returned data depends on the measure mode that is used, defined by the parameter "CardMode" (SolutionCenter configurator) or
 * GMP232X_CONFIG_EXT.Mode when invoking gmp232x_SetConfigExt()
 * @note Updated 2x per period
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] powers             FRMS FCS powers data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath POWERS_FRMS_FCS
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetPowersFrmsFcs(void *DrvId, UINT32 Chan, GMP232X_POWERS_FRMS_FCS *powers)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETPOWERS_FRMS_FCS, powers);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads the TRMS HCC power values.
 * The returned data depends on the measure mode that is used, defined by the parameter "CardMode" (SolutionCenter configurator) or
 * GMP232X_CONFIG_EXT.Mode when invoking gmp232x_SetConfigExt()
 * @note Updated with each sampled value (approx. 100 usec)
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] powers             TRMS HCC powers data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath POWERS_TRMS_HCC
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetPowersTrmsHcc(void *DrvId, UINT32 Chan, GMP232X_POWERS_TRMS_HCC *powers)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETPOWERS_TRMS_HCC, powers);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads the TRMS HCS power values.
 * The returned data depends on the measure mode that is used, defined by the parameter "CardMode" (SolutionCenter configurator) or
 * GMP232X_CONFIG_EXT.Mode when invoking gmp232x_SetConfigExt()
 * @note Updated 2x per period
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] powers             TRMS HCS powers data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath POWERS_TRMS_HCS
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetPowersTrmsHcs(void *DrvId, UINT32 Chan, GMP232X_POWERS_TRMS_HCS *powers)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETPOWERS_TRMS_HCS, powers);
	return (retValue);
}


/**
 * @ingroup GMP232X_EnergyCounter_DoCmds
 * @brief Sets the energy counter on the module to a certain value.
 * In addition to the counter values, it is required to provide a sourceSelect parameter
 * to specify which type of counter values should be written.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  sourceSelect       Type selector TRMS or FRMS; #GMP232X_SOURCE_TRMS or similar
 * @param[in]  energyData         Energy values to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_SetEnergy(void *DrvId, UINT32 Chan, UINT32 sourceSelect, GMP232X_ENERGY *energyData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETENERGY, sourceSelect, energyData);
	return (retValue);
}


/**
 * @ingroup GMP232X_EnergyCounter_DoCmds
 * @brief Reads the energy counter.
 * In addition to the counter values, it is required to provide a sourceSelect parameter
 * to specify which type of counter values should be read.
 * @note Updated 2x per period
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  sourceSelect       Type selector TRMS or FRMS; #GMP232X_SOURCE_TRMS or similar
 * @param[out] energyData         Energy data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath ENERGY/FRMS, ENERGY/TRMS
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetEnergy(void *DrvId, UINT32 Chan, UINT32 sourceSelect, GMP232X_ENERGY *energyData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETENERGY, sourceSelect, energyData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Scope_DoCmds
 * @brief Sets the scope configuration that is used for scope exports. While essential to only provide supported scope data channels, the
 * number of provided channels must not exceed the maximum possible value defined in #GMP232X_SCOPE_MAXCHAN.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  ScopeCfg        Scope configuration structure to configure
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_SetScopeCfg(void *DrvId, UINT32 Chan, GMP232X_SCOPE_CONFIG *ScopeCfg)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETSCOPECFG, ScopeCfg);
	return (retValue);
}


/**
 * @ingroup GMP232X_Scope_DoCmds
 * @brief Reads the scope configuration that is used for scope exports.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[out] ScopeCfg        Scope configuration structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath SCOPE_CONFIG
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetScopeCfg(void *DrvId, UINT32 Chan, GMP232X_SCOPE_CONFIG *ScopeCfg)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETSCOPECFG, ScopeCfg);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a frequency FRT limit.
 * The parameter FfrtId has to specify a single limit that defines for which FFRT limit the given configuration should be applied.
 * Aside from a single FFRTId value, each BlockingMask defined in OVB and UVB has to be set to a single limit.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  FfrtId          FFRT identifier; #GMP232X_LIM_1_FFRT1 or similar
 * @param[in]  FfrtData        FFRT data structure to be configured
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_FFRT_1, LIMIT_FFRT_2
 * @gmp232xParamPath COMMON/LIMIT_FFRT_1, COMMON/LIMIT_FFRT_2
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitFfrt(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *FfrtId, GMP232X_LIMIT_FFRT *FfrtData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_FFRT, FfrtId, FfrtData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Scope_DoCmds
 * @brief Takes the scope lock; the primary purpose of this function is to prepare the scope for data exports (when calling gmp232x_ExportScope()).
 * When taking the scope, a timeout must be specified to cancel the request in case the lock cannot be consumed within a certain timespan.
 * A scope lock can only be aquired, when the scope state is either #GMP232X_SCOPE_STATE_READY or #GMP232X_SCOPE_STATE_NEWDATA (has new data) -
 * check the scope state by calling gmp232x_GetScopeState() prior to calling this function.
 * Scope data can be made available by triggering a scope using gmp232x_TriggerScope().
 * A taken scope lock has to be freed with gmp232x_GiveScopeLock() prior to calling this function again;
 * the scope is normally freed after exporting available scope data (calling gmp232x_ExportScope()).
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  LockTimeout     Maximum time to wait for lock; in seconds
 * @param[out] pLockScope      Lock handle acquired (to be used when releasing the lock with gmp232x_GiveScopeLock())
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_TIMEOUT If LockTimeout occurred.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions As described above, always ensure, that the scope state is either #GMP232X_SCOPE_STATE_READY or #GMP232X_SCOPE_STATE_NEWDATA. Otherwise, this function will not return any data.
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_TakeScopeLock(void *DrvId, UINT32 Chan, UINT32 LockTimeout, UINT32  *pLockScope)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_TAKESCOPELOCK, LockTimeout, pLockScope);
	return (retValue);
}


/**
 * @ingroup GMP232X_Scope_DoCmds
 * @brief Returns (gives) a previously taken scope lock. Use this function to free a scope lock that has
 * been acquired by gmp232x_TakeScopeLock(). This function is typically invoked after successfully exporting
 * a scope with gmp232x_ExportScope(). A valid lock handle (previously acquired by gmp232x_TakeScopeLock()) has to
 * be provided in order to free the scope lock.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  LockHandle      Lock handle to be released (use LockHandle from gmp232x_TakeScopeLock())
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GiveScopeLock(void *DrvId, UINT32 Chan, UINT32 LockHandle)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GIVESCOPELOCK, LockHandle);
	return (retValue);
}


/**
 * @ingroup GMP232X_Scope_DoCmds
 * @brief Triggers a scope and starts a new scope record. Use gmp232x_GetScopeState() to check, if of scope data recording has already finished.
 * A scope can only be triggered in either simulation or run mode (invoke gmp232x_GetState() to check state). When a scope trigger has completed,
 * use gmp232x_TakeScopeLock() to lock the scope (as a preparation step prior to actually starting a scope export).
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_BADMODE  Invalid mode (use gmp232x_GetState() to check state)
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions This function is not applicable if either #GMP232X_STATE_CONFIG or #GMP232X_STATE_FORCERELAY module states are active. Ensure to set an appropriate module state with gmp232x_SetState() prior to invoking this function.
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_TriggerScope(void *DrvId, UINT32 Chan)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_TRIGGERSCOPE);
	return (retValue);
}


/**
 * @ingroup GMP232X_Scope_DoCmds
 * @brief Exports scope data that has been recorded previously. This function triggers the scope export procedure of the module by creating the required data files.
 * This function is invoked, when starting a scope export via SolutionCenter (yet no data files are persisted). If this function is called manually,
 * a comtrade header (configuration) as well as a comtrade data file are generated - each file has a filename corresponding to the filename parameter given when calling this function
 * (their specific extensions .cfg and .dat are automatically assigned);
 * both can be used to manually analyse the exported scope data. To successfully export a scope, a valid lock handle has to be given (previously acquired by gmp232x_TakeScopeLock()).
 * Depending on the number of channels configured, up to 10MB free space in ram0 is needed for loading the recording.
 * The parameter flags can be ignored (should be set to zero).
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  LockHandle      Valid lock handle (use LockHandle read by gmp232x_TakeScopeLock())
 * @param[in]  Filename        Filename for the scope data (name of header and data file)
 * @param[in]  flags           Unused, ignored (use 0)
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark This DoCmd does not  return until all data has been written, a nonblocking alternative is provided by gmp232x_ExportScopeInTask().
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that all previously started exports have finished prior to starting new ones
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_ExportScope(void *DrvId, UINT32 Chan, UINT32 LockHandle, const CHAR8 *Filename, UINT32 flags)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_EXPORTSCOPE, LockHandle, Filename, flags);
	return (retValue);
}


/**
 * @ingroup GMP232X_Scope_DoCmds
 * @brief Alternative (async, non-blocking) method for gmp232x_ExportScope() to export scope data as a task.
 * Use this function to export scope without blocking execution. Poll the scope export progress by invoking MIO_CMD_GETPROGRESS.
 * The parameter flags can be ignored (should be set to zero).
 * See gmp232x_ExportScope() for additional information.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  LockHandle      Valid lock handle (use LockHandle read by gmp232x_TakeScopeLock())
 * @param[in]  Filename        Filename for the scope data (name of header and data file)
 * @param[in]  flags           Unused; has to be zero
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark The used LockHandle should not be released (by executing gmp232x_GiveScopeLock()) before gmp232x_ExportScopeInTask() has finished.
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that all previously started exports have finished prior to starting new ones
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_ExportScopeInTask(void *DrvId, UINT32 Chan, UINT32 LockHandle, const CHAR8 *Filename, UINT32 flags)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_EXPORTSCOPEINTASK, LockHandle, Filename, flags);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads a frequency FRT limit. Use a single limit for FfrtId to specify which FFRT limit to read.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  FfrtId          FFRT identifier; #GMP232X_LIM_1_FFRT1 or similar
 * @param[out] FfrtData        FFRT data structure read by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_FFRT_1, LIMIT_FFRT_2
 * @gmp232xParamPath COMMON/LIMIT_FFRT_1, COMMON/LIMIT_FFRT_2
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitFfrt(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *FfrtId, GMP232X_LIMIT_FFRT *FfrtData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_FFRT, FfrtId, FfrtData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a voltage FRT limit. Use a single limit for VfrtId to specify which VFRT limit configuration to write.
 * This function allows the selective parameterization and enabling of the time dependent voltage monitoring functions
 * for all available limit  curves at runtime. Each of the four limit curves defines an independent monitoring function
 * and can be used in parallel to the others (combine them by OR logic to get the result).
 * The limit curves U(t) are defined as interpolation curves with an adjustable number of points as an array.
 * The monitoring parameters, limits and the enable state are actived immediately after execution.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  VfrtId          VFRT identifier; #GMP232X_LIM_1_VFRT1 or similar
 * @param[in]  VfrtData        VFRT data structure to write
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_VFRT_1, LIMIT_VFRT_2, LIMIT_VFRT_3, LIMIT_VFRT_4
 * @gmp232xParamPath COMMON/LIMIT_VFRT_1, COMMON/LIMIT_VFRT_2, COMMON/LIMIT_VFRT_3, COMMON/LIMIT_VFRT_4
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitVfrt(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *VfrtId, GMP232X_LIMIT_VFRT *VfrtData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_VFRT, VfrtId, VfrtData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads a voltage FRT limit. Use a single limit for VfrtId to specify which VFRT limit to read.
 * This function allows to read the current parameterization and enable state for all available limit curves of the time dependent voltage monitoring
 * function from the module.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  VfrtId          VFRT identifier; #GMP232X_LIM_1_VFRT1 or similar
 * @param[out] VfrtData        VFRT data structure read by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_VFRT_1, LIMIT_VFRT_2, LIMIT_VFRT_3, LIMIT_VFRT_4
 * @gmp232xParamPath COMMON/LIMIT_VFRT_1, COMMON/LIMIT_VFRT_2, COMMON/LIMIT_VFRT_3, COMMON/LIMIT_VFRT_4
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitVfrt(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *VfrtId, GMP232X_LIMIT_VFRT *VfrtData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_VFRT, VfrtId, VfrtData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a harmonic limit. Use a single limit for limitId to specify which harmonic limit configuration to write.
 * @param[in]  DrvId             Device Control Block
 * @param[in]  Chan              Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId           Harmonics identifier to be set; #GMP232X_LIM_2_HARM_U or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[in]  harmonicsLimit    Harmonics limit data structure to write
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_HARM_U, LIMIT_HARM_I
 * @gmp232xParamPath COMMON/LIMIT_HARM_U, COMMON/LIMIT_HARM_I
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitHarmonics(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_HARMONICS *harmonicsLimit)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_HARMONICS, limitId, harmonicsLimit);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads a harmonic limit. Use a single limit for limitId to specify which harmonic limit to read.
 * @param[in]  DrvId            Device Control Block
 * @param[in]  Chan             Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId          Harmonics identifier to be read; #GMP232X_LIM_2_HARM_U or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[out] harmonicsLimit   Harmonics limit data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_HARM_U, LIMIT_HARM_I
 * @gmp232xParamPath COMMON/LIMIT_HARM_U, COMMON/LIMIT_HARM_I
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitHarmonics(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_HARMONICS *harmonicsLimit)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_HARMONICS, limitId, harmonicsLimit);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a current limit. This function allows the selective parameterization and enabling of over-current monitoring
 * functions for all available levels at runtime. The monitoring parameters, limits and the enable state are then
 * active immediately after execution.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; #GMP232X_LIM_1_I_HI1 or similar; use mask GMP232X_LIMIT_MASK.Mask1
 * @param[in]  limitData       Limit data of structure to write
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_I_HI1, LIMIT_I_HI2, LIMIT_I_HI3
 * @gmp232xParamPath COMMON/LIMIT_I_HI1, COMMON/LIMIT_I_HI2, COMMON/LIMIT_I_HI3
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitI(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_I *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_I, limitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads a current limit. Use a single limit for limitId to specify which harmonic limit to read.
 * This function allows to read the current parameterization and enable state for all available levels of the over-current monitoring
 * function from the module.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; #GMP232X_LIM_1_I_HI1 or similar; use mask GMP232X_LIMIT_MASK.Mask1
 * @param[out] pLimitData      Limit data of structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_I_HI1, LIMIT_I_HI2, LIMIT_I_HI3
 * @gmp232xParamPath COMMON/LIMIT_I_HI1, COMMON/LIMIT_I_HI2, COMMON/LIMIT_I_HI3
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitI(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_I *pLimitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_I, limitId, pLimitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a THD TDD limit. Use a single limit for limitId to specify which THD/TDD limit configuration to write.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; e.g #GMP232X_LIM_2_THD_U or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[in]  limitData       Limit data structure to be configured
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_THDTDD_U, LIMIT_THDTDD_I
 * @gmp232xParamPath COMMON/LIMIT_THDTDD_U, COMMON/LIMIT_THDTDD_I
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitThdTdd(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_THDTDD *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_THDTDD, limitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads a THD TDD limit. Use a single limit for limitId to specify which THD/TDD limit to read.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; e.g #GMP232X_LIM_2_THD_U or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[out] limitData       Limit data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_THDTDD_U, LIMIT_THDTDD_I
 * @gmp232xParamPath COMMON/LIMIT_THDTDD_U, COMMON/LIMIT_THDTDD_I
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitThdTdd(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_THDTDD *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_THDTDD, limitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a asymmetry limit. Use a single limit for limitId to specify which asymmetry limit configuration to write.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; #GMP232X_LIM_2_U_ASYM1 or #GMP232X_LIM_2_I_ASYM1 or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[in]  limitData       Limit data structure to be configured
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_U_ASYM1, LIMIT_U_ASYM2, LIMIT_I_ASYM1, LIMIT_I_ASYM2
 * @gmp232xParamPath COMMON/LIMIT_U_ASYM1, COMMON/LIMIT_U_ASYM2, COMMON/LIMIT_I_ASYM1, COMMON/LIMIT_I_ASYM2
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitAsym(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_ASYM *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_ASYM, limitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads a asymmetry limit. Use a single limit for limitId to specify which asymmetry limit to read.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; #GMP232X_LIM_2_U_ASYM1 or #GMP232X_LIM_2_I_ASYM1 or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[out] limitData       Limit data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_U_ASYM1, LIMIT_U_ASYM2, LIMIT_I_ASYM1, LIMIT_I_ASYM2
 * @gmp232xParamPath COMMON/LIMIT_U_ASYM1, COMMON/LIMIT_U_ASYM2, COMMON/LIMIT_I_ASYM1, COMMON/LIMIT_I_ASYM2
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitAsym(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_ASYM *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_ASYM, limitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a ROCOF limit. Use a single limit for limitId to specify which ROCOF limit configuration to write.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; #GMP232X_LIM_2_ROCOF; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[in]  limitData       Limit data structure to be configured
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_ROCOF
 * @gmp232xParamPath COMMON/LIMIT_ROCOF
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitRocof(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_ROCOF *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_ROCOF, limitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads a ROCOF limit. Use a single limit for limitId to specify which ROCOF limit to read.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; #GMP232X_LIM_2_ROCOF; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[out] limitData       Limit data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_ROCOF
 * @gmp232xParamPath COMMON/LIMIT_ROCOF
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitRocof(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_ROCOF *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_ROCOF, limitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a maximum power limit. Use a single limit for limitId to specify which maximum power limit configuration to write.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; #GMP232X_LIM_2_MAX_POWER1 or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[in]  limitData       Limit data structure to be configured
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_MAXPOW1, LIMIT_MAXPOW2
 * @gmp232xParamPath COMMON/LIMIT_MAXPOW1, COMMON/LIMIT_MAXPOW2
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitMaxPower(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_MAX_POWER *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_MAX_POWER, limitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads a maximum power limit. Use a single limit for limitId to specify which maximum power limit to read.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; #GMP232X_LIM_2_MAX_POWER1 or similar ; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[out] limitData       Limit data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_MAXPOW1, LIMIT_MAXPOW2
 * @gmp232xParamPath COMMON/LIMIT_MAXPOW1, COMMON/LIMIT_MAXPOW2
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitMaxPower(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_MAX_POWER *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_MAX_POWER, limitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a reverse power limit. Use a single limit for limitId to specify which reverse power limit configuration to write.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; #GMP232X_LIM_2_REV_POWER1 or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[in]  limitData       Limit data structure to be configured
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_REVPOW1, LIMIT_REVPOW2
 * @gmp232xParamPath COMMON/LIMIT_REVPOW1, COMMON/LIMIT_REVPOW2
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitReversePower(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_REVERSE_POWER *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_REVERSE_POWER, limitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads a reverse power limit. Use a single limit for limitId to specify which reverse power limit to read.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; #GMP232X_LIM_2_REV_POWER1 or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[out] limitData       Limit data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_REVPOW1, LIMIT_REVPOW2
 * @gmp232xParamPath COMMON/LIMIT_REVPOW1, COMMON/LIMIT_REVPOW2
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitReversePower(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_REVERSE_POWER *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_REVERSE_POWER, limitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a directional overcurrent limit. Use a single limit for limitId to specify which directional overcurrent limit configuration to write.
 * @param[in]  DrvId             Device Control Block
 * @param[in]  Chan              Channel, unused for this particular DoCmd (use 0)
 * @param[in]  dirCurrentLimitId Limit identifier; #GMP232X_LIM_2_DIR_CURRENT1 or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[in]  limitData         Limit data structure to be configured
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_DIR_CUR1, LIMIT_DIR_CUR2
 * @gmp232xParamPath COMMON/LIMIT_DIR_CUR1, COMMON/LIMIT_DIR_CUR2
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitDirCurrent(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *dirCurrentLimitId, GMP232X_LIMIT_DIR_CURRENT *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_DIR_CURRENT, dirCurrentLimitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads a directional current limit. Use a single limit for limitId to specify which directional current limit to read.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; #GMP232X_LIM_2_DIR_CURRENT1 or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[out] limitData       Limit data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_DIR_CUR1, LIMIT_DIR_CUR2
 * @gmp232xParamPath COMMON/LIMIT_DIR_CUR1, COMMON/LIMIT_DIR_CUR2
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitDirCurrent(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_DIR_CURRENT *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_DIR_CURRENT, limitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a voltage limit. Use a single limit for limitId to specify which voltage limit configuration to write.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; #GMP232X_LIM_1_V_LO1 or similar; use mask GMP232X_LIMIT_MASK.Mask1
 * @param[in]  voltageLimit    Voltage limit data structure to be configured
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_V_LO1, LIMIT_V_LO2, LIMIT_V_LO3, LIMIT_V_HI1, LIMIT_V_HI2, LIMIT_V_HI3
 * @gmp232xParamPath COMMON/LIMIT_V_LO1, COMMON/LIMIT_V_LO2, LIMIT_V_LO3, LIMIT_V_HI1, COMMON/LIMIT_V_HI2, COMMON/LIMIT_V_HI3
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitVoltage(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_V *voltageLimit)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_VOLTAGE, limitId, voltageLimit);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads a configured voltage limit. Use a single limit for limitId to specify which voltage limit to read.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId         Limit identifier; #GMP232X_LIM_1_V_LO1 or similar; use mask GMP232X_LIMIT_MASK.Mask1
 * @param[out] voltageLimit    Limit data structure to be read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_V_LO1, LIMIT_V_LO2, LIMIT_V_LO3, LIMIT_V_HI1, LIMIT_V_HI2, LIMIT_V_HI3
 * @gmp232xParamPath COMMON/LIMIT_V_LO1, COMMON/LIMIT_V_LO2, LIMIT_V_LO3, LIMIT_V_HI1, COMMON/LIMIT_V_HI2, COMMON/LIMIT_V_HI3
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitVoltage(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_V *voltageLimit)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_VOLTAGE, limitId, voltageLimit);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads the status of an individual limit function / protection function (enabled, inhibited/disabled, started, tripped).
 * Uses the bit mask structure LimitId to identify the selected limit function for which to read the status. Requesting the status of
 * multiple limit functions at once is not supported. Thus the provided structure of bit masks may only contain one single "1" - so one of
 * the two masks stays always empty (all zeros) - To simplify the handling, the individual bit masks for all limit functions are defined
 * as global constants, e.g. #GMP232X_LIM_1_V_HI1 for "Over Voltage Protection Level 1" (see section \ref GMP232X_DEF "Defines"). Assign the related
 * global constant to structure element .Mask1 if the name of the constant contains xxx_LIM_1_xxx and assign zero to the other one (or to .Mask2 if
 * it contains xxx_LIM_2_xxx and assign zero to the first one). The function gmp232x_GetLimitSingleStatus() will return the status of the
 * addressed limit / protection function as an integer number in limitData.<p>
 * Since the configurational enable status of limit functions generally only changes after transitions from operational mode
 * #GMP232X_STATE_CONFIG to #GMP232X_STATE_RUN (or to #GMP232X_STATE_SIMULATION), a design should consider to use this function only after
 * configuration changes on all possible limit functions. If the application already knows which limit functions are in use, the most efficient
 * way to derive the started/tripped status would be to use gmp232x_GetLimitStatus() instead. This function delivers these status information
 * for all limit functions within one fast call.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  LimitId         Bit mask  as input value to select the desired limit function (type is #GMP232X_LIM_1_MASK); either use GMP232X_LIMIT_MASK.Mask1 or GMP232X_LIMIT_MASK.Mask2 depending on the limit function to select
 * @param[out] limitData       Returns state of the addressed single limit function as UINT32 value  (can be resolved by global constants named GMP232X_LIMIT_STATE_xxxxx for example #GMP232X_LIMIT_STATE_DISABLED)
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath SINGLE_STATUS/
 * @gmp232xPerfClassFast
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitSingleStatus(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *LimitId, UINT32  *limitData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_SINGLE_STATUS, LimitId, limitData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads the started / tripped status of all limit functions / protection functions at once.
 * All limit functions currently active and in state started or tripped on the GMP232/x module addressed by its DrvId are returned.
 * This result value is delivered in the structure of bit coded UINT32 double words defined by #GMP232X_LIMIT_STATUS. There are two double
 * words for the started state and two for the tripped state. The individual bits representing each limit / protection function can be identified
 * using the global constants defined for each limit function such as #GMP232X_LIM_1_V_LO1 for "Under Voltage Protection Level 1" (see section \ref GMP232X_DEF "Defines").
 * If the name of the constant contains xxx_LIM_1_xxx the first and third structure element are corresponding, if it contains xxx_LIM_2_xxx the
 * second and fourth bit field are related. If the status for an individual limit function shall be isolated, this can e.g. be performed by
 * bit wise AND of the corresponding structure element with the related global constant.<p>
 * In contrast to gmp232x_GetLimitSingleStatus(), this function delivers only "started" and "tripped" states but cannot
 * distinguish between "not configured", "no limit violation" or an "active inhibit" on the specific function (delivers in all cases 0 on the specific bit).
 * This additional information can be retrieved using gmp232x_GetLimitSingleStatus() instead, but it works only for a single protection function at once.<p>
 * To read the enabled/disabled (inhibited) state of all limits at once, use gmp232x_GetInhibitCfg().
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] status             Limit status information read back by the function as structure of type #GMP232X_LIMIT_STATUS
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_STATUS
 * @gmp232xPerfClassFast
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitStatus(void *DrvId, UINT32 Chan, GMP232X_LIMIT_STATUS *status)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_STATUS, status);
	return (retValue);
}


/**
 * @ingroup GMP232X_Statistics_DoCmds
 * @brief Reads statistic values between a certain range, or a single one. To read the statistic values from a range of statistic points,
 * use Id_RangeStart to provide one of the valid datapoint index values as well as dataPointLength to
 * specify the number of datapoints to read (if 1, a single datapoint is read). If more than one datapoint is requested, the dataPoint parameter
 * has to be an array of length dataPointLength (at least).
 * The sum of the first datapoint index (Id_RangeStart) and the last datapoint has to be smaller than #GMP232X_MAX_IDX_STATISTICS.
 * @note Update rate depends on statistic value; uses update rate of corresponding value
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  Id_RangeStart      Begin of range (inclusive); #GMP232X_IDX_U_L1N_INST or similar; max: #GMP232X_MAX_IDX_STATISTICS
 * @param[in]  dataPointLength    Number of data points to read, use 1 for a single data point
 * @param[out] dataPoint[]        Array of length dataPointLength for all data points read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassModerate
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetStatisticRanged(void *DrvId, UINT32 Chan, UINT32 Id_RangeStart, UINT32 dataPointLength, GMP232X_STATISTIC *dataPoint)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETSTATISTIC_RANGED, Id_RangeStart, dataPointLength, dataPoint);
	return (retValue);
}


/**
 * @ingroup GMP232X_Statistics_DoCmds
 * @brief Read certain statistic values, or a single one. In contrast to gmp232x_GetStatisticRanged(),
 * each statistic datapoint has to be specified within the dataPointIdx array instead of defining a range of datapoints. The parameter
 * dataPointLength is used to specify the number of datapoints within the dataPointIdx array. Because multiple datapoints can be returned,
 * dataPoint has to be specified as an array of length dataPointLength (at least). Each index defined in the dataPointIdx array, has to be
 * smaller than the maximum possible index value available (#GMP232X_MAX_IDX_STATISTICS).
 * @note Update rate depends on statistic value; uses update rate of corresponding value
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  dataPointIdx[]     Array of data point identifiers (#GMP232X_IDX_U_L1N_INST or similar), array of size dataPointLength
 * @param[in]  dataPointLength    Number of data points in dataPointId[], use 1 to read a single data point
 * @param[out] dataPoint[]        Data points read back by the function, array of size dataPointLength
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassModerate
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetStatisticIndexed(void *DrvId, UINT32 Chan, const UINT32 *dataPointIdx, UINT32 dataPointLength, GMP232X_STATISTIC *dataPoint)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETSTATISTIC_INDEXED, dataPointIdx, dataPointLength, dataPoint);
	return (retValue);
}


/**
 * @ingroup GMP232X_Averager_DoCmds
 * @brief Reads harmonic mean values by specifying a value range. Because this function is designed to read a range of consecutive harmonic mean values (thus belonging
 * to #GMP232X_AVERAGER3 values), Idx_RangeStart has to be higher than #GMP232X_IDX_HARM_MEAN_U1_H00 (harmonics only). Aside from reading a
 * certain range of mean values, a single value can be read by setting the dataPointLength parameter to 1. Because multiple values can be returned,
 * the parameter dataPoint has to be specificed as an array of length dataPointLength (at least).
 * Because only harmonic values can be read, the parameter averager has to be set to #GMP232X_AVERAGER3 (harmonics only).
 * @note Updated each averager period (dependent on averager configuration)
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  Idx_RangeStart     Begin of range (inclusive); see #GMP232X_IDX_HARM_MEAN_U1_H00
 * @param[in]  dataPointLength    Number of data points to read, use 1 for a single data point
 * @param[in]  averager           Identifier of the averaging point (#GMP232X_AVERAGER3 because harmonics only)
 * @param[out] dataPoint[]        Data points read back by the function, array of size dataPointLength
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassModerate
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetMeanValueRanged(void *DrvId, UINT32 Chan, UINT32 Idx_RangeStart, UINT32 dataPointLength, UINT32 averager, GMP232X_MEAN *dataPoint)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETMEANVALUE_RANGED, Idx_RangeStart, dataPointLength, averager, dataPoint);
	return (retValue);
}


/**
 * @ingroup GMP232X_Averager_DoCmds
 * @brief Read certain mean values, or a single one. In contrast to gmp232x_GetMeanValueRanged(),
 * each mean value that should be read has to be explicitly added to the array reqDataPoint defined by its index.
 * Because multiple datapoints can be returned, the dataPoint data array has to be at least of size dataPointLength.
 * In order to successfully read mean datapoints by their index, each datapoint has to be configured by
 * invoking gmp232x_SetMeanCfg() prior to reading its value. Requesting a not configured datapoint will fail as it
 * is excluded from internal calculation. The function gmp232x_GetMeanCfg() can be used to check, if a mean value is configured.
 * @note Updated each averager period (dependent on averager configuration)
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  dataPointLength    Number of data points in reqDataPoint[], use 1 for a single data point
 * @param[in]  reqDataPoint[]     Data point request structure, array of size dataPointLength
 * @param[out] dataPoint[]        Data points read back by the function, array of size dataPointLength
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassModerate
 * @gmp232xPreConditions As mentioned above, all data requested has to be configured for calculation first (see gmp232x_SetMeanCfg())
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetMeanValueIndexed(void *DrvId, UINT32 Chan, UINT32 dataPointLength, GMP232X_MEAN_REQUEST *reqDataPoint, GMP232X_MEAN *dataPoint)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETMEANVALUE_INDEXED, dataPointLength, reqDataPoint, dataPoint);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads FRMS FCS values. The returned data depends on the measure mode that is used, defined by
 * the parameter "CardMode" (SolutionCenter configurator) or GMP232X_CONFIG_EXT.Mode when invoking gmp232x_SetConfigExt().
 * @note Updated 2x per period
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] frmsFcs            FRMS FCS data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath FRMS_FCS_VALUES/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetFrmsFcs(void *DrvId, UINT32 Chan, GMP232X_FRMS_FCS_VALUES *frmsFcs)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GET_FRMS_FCS, frmsFcs);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads TRMS HCS values. The returned data depends on the measure mode that is used, defined by
 * the parameter "CardMode" (SolutionCenter configurator) or GMP232X_CONFIG_EXT.Mode when invoking gmp232x_SetConfigExt().
 * @note Updated 2x per period
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] trmsHcs            TRMS HCS data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath TRMS_HCS_VALUES/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetTrmsHcs(void *DrvId, UINT32 Chan, GMP232X_TRMS_HCS_VALUES *trmsHcs)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GET_TRMS_HCS, trmsHcs);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads FRMS FCC values. The returned data depends on the measure mode that is used, defined by
 * the parameter "CardMode" (SolutionCenter configurator) or GMP232X_CONFIG_EXT.Mode when invoking gmp232x_SetConfigExt().
 * @note Updated with each sampled value (approx. 100 usec)
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] frmsFcc            FRMS FCC data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath FRMS_FCC_VALUES/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetFrmsFcc(void *DrvId, UINT32 Chan, GMP232X_FRMS_FCC_VALUES *frmsFcc)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GET_FRMS_FCC, frmsFcc);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads TRMS HCC values. The returned data depends on the measure mode that is used, defined by
 * the parameter "CardMode" (SolutionCenter configurator) or GMP232X_CONFIG_EXT.Mode when invoking gmp232x_SetConfigExt().
 * @note Updated with each sampled value (approx. 100 usec)
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] trmsHcc            TRMS HCC data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath TRMS_HCC_VALUES/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetTrmsHcc(void *DrvId, UINT32 Chan, GMP232X_TRMS_HCC_VALUES *trmsHcc)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GET_TRMS_HCC, trmsHcc);
	return (retValue);
}


/**
 * @ingroup GMP232X_History_DoCmds
 * @brief Deletes the alarm history entries
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Prior to using this function, a valid LockHandle has to be acquired (via gmp232x_TakeHistoryLock())
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_DeleteAlarmHistory(void *DrvId, UINT32 Chan)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_DELETEALARMHISTORY);
	return (retValue);
}


/**
 * @ingroup GMP232X_History_DoCmds
 * @brief Takes the lock for the history. Use this function prior to calling gmp232x_GetAlarmHistory() in order to lock access the alarm history.
 * The parameter LockTimeout is used to provide a timeout in case the lock cannot be acquired within the given timespan.
 * When locked, free the alarm history again by invoking gmp232x_GiveHistoryLock().
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  LockTimeout     Maximum time to wait for lock; [0 - 100]; in seconds
 * @param[out] LockHistory     History lock data read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_TIMEOUT If LockTimeout occurred.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassModerate
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_TakeHistoryLock(void *DrvId, UINT32 Chan, SINT32 LockTimeout, GMP232X_HISTORY_LOCK *LockHistory)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_TAKEHISTORYLOCK, LockTimeout, LockHistory);
	return (retValue);
}


/**
 * @ingroup GMP232X_History_DoCmds
 * @brief Gives/releases the previously taken history lock. This function is normally used after locking the alarm history
 * (gmp232x_TakeHistoryLock()) and exporting the alarm data (gmp232x_GetAlarmHistory()).
 * Provide the lock returned by gmp232x_TakeHistoryLock() as LockHandle to free the history.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  LockHandle      Lock handle to be freed (use GMP232X_HISTORY_LOCK.LockHandle from gmp232x_TakeHistoryLock())
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GiveHistoryLock(void *DrvId, UINT32 Chan, UINT32 LockHandle)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GIVEHISTORYLOCK, LockHandle);
	return (retValue);
}


/**
 * @ingroup GMP232X_History_DoCmds
 * @brief Reads the alarm history. Use this function to read the alarm history data indentified by the parameter
 * LockHandle that has been previously returned by gmp232x_TakeHistoryLock() at the time of locking the alarm history.
 * The parameter AlarmIdx must be below the number of available lock entries returned when
 * locking the alarm history (see ActNbEntries in GMP232X_HISTORY_LOCK). Use the parameter nbEntries to limit the number of returned history entries.
 * Because multiple alarm history entries can be received, HistoryData must be provided as an array of size nbEntries (at least).
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  LockHandle      Valid lock handle (use LockHandle of #GMP232X_HISTORY_LOCK from gmp232x_TakeHistoryLock())
 * @param[in]  AlarmIdx        (starting) index of element(s) to return; [0 up to ActNbEntries of #GMP232X_HISTORY_LOCK]
 * @param[in]  nbEntries       Number of items to return (number of elements in the array HistoryData); [0 up to ActNbEntries of #GMP232X_HISTORY_LOCK]
 * @param[out] HistoryData[]   Alarm history elements read back by the function, array of size nbEntries
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassSlow
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetAlarmHistory(void *DrvId, UINT32 Chan, UINT32 LockHandle, UINT32 AlarmIdx, UINT32 nbEntries, GMP232X_HISTORY_ENTRY *HistoryData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETALARMHISTORY, LockHandle, AlarmIdx, nbEntries, HistoryData);
	return (retValue);
}


/**
 * @ingroup GMP232X_General_DoCmds
 * @brief Reads the current module state. Internally, the GMP module operation is based on a state machine. Trasistions between module states are triggered by calling gmp232x_SetState().
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[out] state           Current module state read back by the function (#GMP232X_STATE_CONFIG or similar)
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath MODULE/State
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetState(void *DrvId, UINT32 Chan, SINT32  *state)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETSTATE, state);
	return (retValue);
}


/**
 * @ingroup GMP232X_General_DoCmds
 * @brief Sets the operating state of the addressed module.
 * When operating in either run, simulation or force relay state, it is only allowed to change into configuration state at first;
 * every other state transition will fail. Always check the success of such a state transition by evaluating the return value.
 * As leaving the run state (#GMP232X_STATE_RUN) will stop all measurements and protective functions on the module, such state transitions
 * shall only be applied after setting the facility / plant to a safe operational state (e.g. stopped / disconnected) or making sure that a
 * secondary measurement and protection backup device is available.<p>
 * Although the parameter startupInhibitTime defined in #GMP232X_CONFIG_EXT or via SolutionCenter influences the time until limit functions
 * are active (after switching to #GMP232X_STATE_RUN), this command exits immediately and will not block until startupInhibitTime has elapsed.
 * Check the current operational state by calling gmp232x_GetState().<br>
 * The following distinct module states are possible:
 * <ul>
 * <li>GMP232X_STATE_CONFIG (configuration mode)</li>
 * <li>GMP232X_STATE_RUN (run state) </li>
 * <li>GMP232X_STATE_FORCERELAY (relay simulation mode)</li>
 * <li>GMP232X_STATE_SIMULATION (simulation mode)</li>
 * </ul>
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  state           Module state to be set (#GMP232X_STATE_CONFIG or similar)
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_TIMEOUT  State change not accepted within time
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_SetState(void *DrvId, UINT32 Chan, SINT32 state)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETSTATE, state);
	return (retValue);
}


/**
 * @ingroup GMP232X_Sim_DoCmds
 * @brief Forces the relay into the given state. This function only succeeds when operated in
 * #GMP232X_STATE_FORCERELAY state (use gmp232x_SetState() in case a state change is required).
 * Only a single relay can be set at once, no combinations allowed.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Relay channel; (12 .. Relay 1, 13 .. Relay 2)
 * @param[in]  setState        State to set the relay (0 or 1)
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_BADCHAN  The given channel is not a relay channel
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_ForceRelay(void *DrvId, UINT32 Chan, UINT32 setState)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_FORCERELAY, setState);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Resets the relay to default state. This function requires
 * the keywords AutoResetEnable1 or AutoResetEnable2 (defined in GMP232X_CONFIG_EXT and SolutionCenter)
 * to be disabled for the respective relay. Only a single relay can be reset at once, no combinations allowed.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Relay channel; (12 .. Relay 1, 13 .. Relay 2)
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_BADMODE If the corresponding setting for either AutoResetEnable1 (for relay 1) or AutoResetEnable2 (for relay 2) is enabled
 * @retval #MIO_ER_BADCHAN  The given channel is not a relay channel
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_ResetRelay(void *DrvId, UINT32 Chan)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_RESETRELAY);
	return (retValue);
}


/**
 * @ingroup GMP232X_General_DoCmds
 * @brief Reads the switch count of all relays.
 * @note Updated each relay switch
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[out] switchCount     Switch count data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath SWITCHCOUNT/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetSwitchCount(void *DrvId, UINT32 Chan, GMP232X_SWITCHCOUNT *switchCount)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETSWITCHCOUNT, switchCount);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads the configuration stored in the parameter file referenced by the functions input parameter Filename into the runtime system of the module.
 * The additional parameter file for protection functions, module scope and aggregations (averagers) of type *.gmpx must be stored on the file system on
 * the control system CPU (e.g. "/cfc0/GRID/gmp232x_ProtPrm02.gmpx"). All parameters in this configuration shall be correct and consistent and should
 * be previously checked in a safe testing environment. Before the function can be used, the module must be set to state #GMP232X_STATE_CONFIG
 * (see also gmp232x_SetState()). As all protection functions are disabled in this mode, it is strictly recommended to do this only in a safe mode
 * of the whole facility/machine (e.g. stopped). Executing the function will immediately change the parameters in the modules runtime system
 * but will only restart execution after changing the state back to #GMP232X_STATE_RUN (or #GMP232X_STATE_SIMULATION respectively).
 * This function is called on every parameter change within the SolutionCenter configuration. The parameter cfgErr provides additional
 * information gathered during parsing.<p>
 * Should the processing of the parameter file fail for any reason (e.g. file not found, wrong state etc.) the module will always return
 * the error state #MIO_E_BADCONFIG (visible e.g. via mio_GetError() or in the module monitors in Solution-Center/DeviceManager) and will remain in this state
 * until a future call of gmp232x_ProcessParamFile() completes successfully.
 * @param[in]  DrvId       Device Control Block
 * @param[in]  Chan        Channel, unused for this particular DoCmd (use 0)
 * @param[in]  Filename    Name of parameter file to be parsed (full path e.g."/cfc0/GRID/gmp232x_ProtPrm02.gmpx")
 * @param[out] cfgErr      Extended parser information: #GMP232X_ER_CFG_OK or similar
 *
 * @retval 1 Incomplete or missing parameters detected, but configuration has been written
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPreConditions The module must be in state #GMP232X_STATE_CONFIG to successfully accept the new/changed parameters.
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_ProcessParamFile(void *DrvId, UINT32 Chan, const CHAR8 *Filename, UINT32  *cfgErr)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_PROCESSPARAMFILE, Filename, cfgErr);
	return (retValue);
}


/**
 * @ingroup GMP232X_Config_DoCmds
 * @brief Reads the current run through mode setting. Under very few circumstances
 * (heartbeat error and subsequent module reset) this function might deliver unexpected results;
 * see <a class="el" href="§D-BA-0004071_2_4EBB8227_1§">reference manual</a> for additional information.
 * @param[in]  DrvId        Device Control Block
 * @param[in] Chan          Channel, unused for this particular DoCmd (use 0)
 * @param[out] runThrough   Run through state read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath MODULE/RunThrough
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetRunThrough(void *DrvId, UINT32 Chan, UINT32  *runThrough)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETRUNTHROUGH, runThrough);
	return (retValue);
}


/**
 * @ingroup GMP232X_General_DoCmds
 * @brief Reads the events status of the module.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel for which to read the events
 * @param[out] EventState      Event state read back by the function (#MIO_EV_QU_PCC1 or similar defines); these is a combination of event bits described in \ref gmp232ModuleSpecificEvents "Module events"
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetEvent(void *DrvId, UINT32 Chan, UINT32  *EventState)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETEVENT, EventState);
	return (retValue);
}


/**
 * @ingroup GMP232X_Config_DoCmds
 * @brief Reads the module configuration (deprecated with GMP232X Driver V1.01R, use gmp232x_GetConfigExt() instead).
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel, unused for this particular DoCmd (use 0)
 * @param[out] config       Module configuration read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath CONFIG/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetConfig(void *DrvId, UINT32 Chan, GMP232X_CONFIG *config)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETCONFIG, config);
	return (retValue);
}


/**
 * @ingroup GMP232X_Config_DoCmds
 * @brief Reads the module configuration, extended version. Use this function because gmp232x_GetConfig() is deprecated with GMP232X Driver V1.01R.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel, unused for this particular DoCmd (use 0)
 * @param[out] config       Module configuration read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath CONFIG/
 * @gmp232xPerfClassFast
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetConfigExt(void *DrvId, UINT32 Chan, GMP232X_CONFIG_EXT *config)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETCONFIG_EXT, config);
	return (retValue);
}


/**
 * @ingroup GMP232X_Sim_DoCmds
 * @brief Reads the simulated data
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[out] simData         Simulation values read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath SIMDATA/
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetSimData(void *DrvId, UINT32 Chan, GMP232X_SIMDATA *simData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETSIMDATA, simData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Sim_DoCmds
 * @brief Sets the simulation data
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  simData         Simulation values to be set
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in either configuration mode (#GMP232X_STATE_CONFIG) or simulation mode (#GMP232X_STATE_SIMULATION) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_SetSimData(void *DrvId, UINT32 Chan, GMP232X_SIMDATA *simData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETSIMDATA, simData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Statistics_DoCmds
 * @brief Resets all statistic data values.
 * @note This function is definitive - when executed, all statistic data will be lost.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_ResetStatistics(void *DrvId, UINT32 Chan)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_RESETSTATISTICS);
	return (retValue);
}


/**
 * @ingroup GMP232X_Config_DoCmds
 * @brief Sets the relay configuration. Combinations for relaySelector are allowed.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  relaySelector   Relay to be set; #GMP232X_RELAY_NONE or similar
 * @param[in]  relayState      Relay state to be set; TRUE = activated, FALSE = deactivated
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_SetRelayCfg(void *DrvId, UINT32 Chan, UINT32 relaySelector, BOOL32 relayState)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETRELAYCFG, relaySelector, relayState);
	return (retValue);
}


/**
 * @ingroup GMP232X_Config_DoCmds
 * @brief Reads a single relay configuration; in contrast to gmp232x_SetRelayCfg(), no relay combinations are allowed.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  relaySelector   Relay to read the state for; #GMP232X_RELAY_1 or #GMP232X_RELAY_2
 * @param[out] relayState      Relay state read back by the function; TRUE = activated, FALSE = deactivated
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath RELAYCFG/
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetRelayCfg(void *DrvId, UINT32 Chan, UINT32 relaySelector, BOOL32  *relayState)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETRELAYCFG, relaySelector, relayState);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a QU (reactive power undervoltage protection) limit to the given configuration. The parameter limitId has to specify
 * a single limit that defines for which QU limit the given configuration should be applied.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId            QU limit identifier, #GMP232X_LIM_1_QU_GEN1 or similar; use mask GMP232X_LIMIT_MASK.Mask1
 * @param[in]  quLimit            QU limit data to be configured
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_QU_GEN1, LIMIT_QU_GEN2
 * @gmp232xParamPath COMMON/LIMIT_QU_GEN1, COMMON/LIMIT_QU_GEN2
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitQU(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_QU *quLimit)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_QU, limitId, quLimit);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads a QU (reactive power undervoltage protection) limit. The parameter limitId has to specify
 * a single limit that defines for which QU limit the configuration should be read.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId            QU limit identifier, #GMP232X_LIM_1_QU_GEN1 or similar; use mask GMP232X_LIMIT_MASK.Mask1
 * @param[out] quLimit            QU limit data read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_QU_GEN1, LIMIT_QU_GEN2
 * @gmp232xParamPath COMMON/LIMIT_QU_GEN1, COMMON/LIMIT_QU_GEN2
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitQU(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_QU *quLimit)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_QU, limitId, quLimit);
	return (retValue);
}


/**
 * @ingroup GMP232X_SampleValues_DoCmds
 * @brief Reads a number of sample values. Besides a starting index, the function expects a count value
 * that defines the number of samples to be requested. Neither the value provided as start index, the
 * number of samples requested nor the sum of the start index and sample count are allowed to exceed the maximum
 * possible size of the buffer (#GMP232X_SAMPLE_BUFFERSIZE). Because multiple samples can be read (depending
 * on the number of samples requested), the parameter sampleData has to be specified as an array with length equal
 * the number of samples requested (at least). Although the exact number of samples requested is read back by the function,
 * the actual number of new samples might be lower (because of their internal representation as a circular buffer). If the number of requested samples
 * is higher than the number of associated samples, the parameter newSamples has a value below the number of requested
 * samples; therefore only sample values with an index lower than the returned value of newSamples should be considered.
 * @note Update rate depends on sample configuration
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  sampleReq          Sample request data structure; describes the data to be returned
 * @param[out] sampleData[]       Buffer with sample data structures, array buffer of size sampleReq.NumSamples
 * @param[out] newSamples         Number of new samples read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetSamples(void *DrvId, UINT32 Chan, GMP232X_SAMPLE_REQUEST *sampleReq, GMP232X_SAMPLE_VAL *sampleData, UINT32  *newSamples)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETSAMPLES, sampleReq, sampleData, newSamples);
	return (retValue);
}


/**
 * @ingroup GMP232X_SampleValues_DoCmds
 * @brief Reads the latest written (most recent) sample value. Use this function as an alternative to gmp232x_GetSamples() when only the
 * most recent sample is of interest. When polling, use the provided timestamp as a way to distinguish between two consecutive samples.
 * @note Update rate depends on sample configuration
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] sampleData         Sample data read back by the functoin
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetLatestSample(void *DrvId, UINT32 Chan, GMP232X_SAMPLE_VAL *sampleData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLATESTSAMPLE, sampleData);
	return (retValue);
}


/**
 * @ingroup GMP232X_SampleValues_DoCmds
 * @brief Sets the sample value configuration that is used when requesting the data.
 * This function can only be executed in configuration mode. Use gmp232x_SetState()
 * to change the mode if not applicable.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  sampleCfg          Sample configuration to be set
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_SetSampleCfg(void *DrvId, UINT32 Chan, GMP232X_SAMPLE_CONFIG *sampleCfg)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETSAMPLECFG, sampleCfg);
	return (retValue);
}


/**
 * @ingroup GMP232X_SampleValues_DoCmds
 * @brief Reads the sample value configuration that is set by calling gmp232x_SetSampleCfg().
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] sampleCfg          Sample configuration read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath SAMPLE_CONFIG/
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetSampleCfg(void *DrvId, UINT32 Chan, GMP232X_SAMPLE_CONFIG *sampleCfg)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETSAMPLECFG, sampleCfg);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Set a frequency limit. Use a single limit for limitId to specify which frequency limit configuration to write.
 * This function is only applicable in configuration mode.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId      Limit ID; #GMP232X_LIM_1_F_HI3 or similar; use mask GMP232X_LIMIT_MASK.Mask1
 * @param[in]  pFreqLim     Frequency limit data structure to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_F_LO1, LIMIT_F_LO2, LIMIT_F_LO3, LIMIT_F_HI1, LIMIT_F_HI2, LIMIT_F_HI3
 * @gmp232xParamPath COMMON/LIMIT_F_LO1, COMMON/LIMIT_F_LO2, COMMON/LIMIT_F_LO3, COMMON/LIMIT_F_HI1, COMMON/LIMIT_F_HI2, COMMON/LIMIT_F_HI3
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitFreq(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_FREQ *pFreqLim)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_FREQ, limitId, pFreqLim);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads a frequency limit. Use a single limit for freqLimitId to specify which frequency limit configuration to read.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel, unused for this particular DoCmd (use 0)
 * @param[in]  freqLimitId  Limit ID; #GMP232X_LIM_1_F_HI3 or similar; use mask GMP232X_LIMIT_MASK.Mask1
 * @param[out] pFreqLim     Frequency limit data read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_F_LO1, LIMIT_F_LO2, LIMIT_F_LO3, LIMIT_F_HI1, LIMIT_F_HI2, LIMIT_F_HI3
 * @gmp232xParamPath COMMON/LIMIT_F_LO1, COMMON/LIMIT_F_LO2, COMMON/LIMIT_F_LO3, COMMON/LIMIT_F_HI1, COMMON/LIMIT_F_HI2, COMMON/LIMIT_F_HI3
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitFreq(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *freqLimitId, GMP232X_LIMIT_FREQ *pFreqLim)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_FREQ, freqLimitId, pFreqLim);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets the vector jump limit. Use a single limit for limitId to specify which vector jump limit configuration to write.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId            Vector jump limit identifier to be set; #GMP232X_LIM_2_VECTORJUMP1 or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[in]  vectorJumpLimit    Vector jump data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark It is recommended to activate only parameters that have been previously tested and validated.
 * When calling the function directly after changing into run mode (e.g. after startup), the recommended startup inhibit
 * delays should be considered (see gmp232x_SetConfigExt() or the general desciption of the "StartupInhibitTime" configuration parameter).
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitVectorJump(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_VECTORJUMP *vectorJumpLimit)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_VECTORJUMP, limitId, vectorJumpLimit);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads the vector jump limit. Use a single limit for limitId to specify which vector jump limit configuration to read.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId            Vector jump limit identifier to be read; #GMP232X_LIM_2_VECTORJUMP1 or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[out] vectorJumpLimit    Vector jump data to be read
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_VECTORJUMP/
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitVectorJump(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_VECTORJUMP *vectorJumpLimit)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_VECTORJUMP, limitId, vectorJumpLimit);
	return (retValue);
}


/**
 * @ingroup GMP232X_General_DoCmds
 * @brief Reads the current module time. The time of the module is periodically synced with the CPU.
 * @param[in]  DrvId       Device Control Block
 * @param[in]  Chan        Channel, unused for this particular DoCmd (use 0)
 * @param[out] getTime     Current module time read back by the function; compatible to timespec structure
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath MODULETIME/
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetModuleTime(void *DrvId, UINT32 Chan, TIMESTAMP *getTime)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETMODULETIME, getTime);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads the phase angle reference values
 * @note Updated 2x per period
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] phaseRef           Phase reference data read back by function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath PHASEREF/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetPhaseRef(void *DrvId, UINT32 Chan, GMP232X_PHASEREF *phaseRef)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETPHASE_REF, phaseRef);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads the phase angle values
 * @note Updated every zero crossing
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] phase              Phase data structure read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath PHASE/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetPhase(void *DrvId, UINT32 Chan, GMP232X_PHASE *phase)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETPHASE, phase);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads ROCOF, rotation direction, frequency and related values
 * @note Updated every zero crossing
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] RocofRotDir        ROCOF rotation direction data read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath ROCOF_ROTDIR/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetRocofRotDir(void *DrvId, UINT32 Chan, GMP232X_ROCOF_ROTDIR *RocofRotDir)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETROCOF_ROTDIR, RocofRotDir);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads the powerfactor values
 * @note Powerfactors: 2x per period, CosPhis: with each sampled value (approx. 100 usec)
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] powerfactor        Powerfactor data read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath POWERFACTOR/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetPowerFactor(void *DrvId, UINT32 Chan, GMP232X_POWERFACTOR *powerfactor)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETPOWERFACTOR, powerfactor);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads the asymmetric data values
 * @note Updated 2x per period
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] asymData           Asymmetric data read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath ASYM/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetAsym(void *DrvId, UINT32 Chan, GMP232X_ASYM *asymData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETASYM, asymData);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads the symmetric components
 * @note Updated 2x per period
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] symComponents      Symmetric components data read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath SYM_COMPONENTS/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetSymComponents(void *DrvId, UINT32 Chan, GMP232X_SYMCOMPONENTS *symComponents)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETSYM_COMPONENTS, symComponents);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets the the inhibit configuration in order to block limits. This function allows to
 * enable/disable the start (activation) blocking for each monitoring function selectively. The
 * function can be called in every operation mode but will only take affect in either run or simulation mode.
 * Calling the function for an already tripped monitoring function will lead to an immediate fallback. The
 * behavior of the corresponding relay outputs depends on the configuration of auto-reset or any user specific
 * reset logic. When this function is called for an already started (activated) monitoring function, it will
 * lead to an immediate fallback and the system will not trip after the given tripping delay.
 * A set bit in inhibitCfg means that the corresponding monitoring (limit) function is enabled. A cleared bit
 * means that the corresponding monitoring function is disabled (inhibited).
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  inhibitCfg         Inhibit configuration data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Because of internal computations, an inhibit configuration that is set very shortly before the end of
 * a tripping delay of an already started monitoring function, could be prevented from tripping.
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetInhibitCfg(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *inhibitCfg)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETINHIBITCFG, inhibitCfg);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads the the inhibit configuration. The function gmp232x_GetInhibitCfg() allows to read the current
 * setting of a start (activation) blocking for each monitoring function of the module.
 * See gmp232x_SetInhibitCfg() for more information.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] inhibitCfg         Inhibit configuration data read back by the function. Provided as two individual masks with 32 possible flags in total.
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath INHIBITCFG/
 * @gmp232xPerfClassFast
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetInhibitCfg(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *inhibitCfg)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETINHIBITCFG, inhibitCfg);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads the limit relay configuration; the values are contained within two individual masks.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] relayCfg           Limit relay configuration data read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_RELAY1MASK, LIMIT_RELAY2MASK
 * @gmp232xParamPath COMMON/LIMIT_RELAY1MASK, COMMON/LIMIT_RELAY2MASK
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitRelayCfg(void *DrvId, UINT32 Chan, GMP232X_LIMIT_RELAYCFG *relayCfg)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_RELAYCFG, relayCfg);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets the limit relay configuration.
 * This function is only applicable in configuration mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  relayCfg           Limit relay configuration data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_RELAY1MASK, LIMIT_RELAY2MASK
 * @gmp232xParamPath COMMON/LIMIT_RELAY1MASK, COMMON/LIMIT_RELAY2MASK
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitRelayCfg(void *DrvId, UINT32 Chan, GMP232X_LIMIT_RELAYCFG *relayCfg)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_RELAYCFG, relayCfg);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads the limit scope configuration.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] scopeCfg           Limit scope configuration data read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_SCOPEMASK
 * @gmp232xParamPath COMMON/LIMIT_SCOPEMASK
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitScopeCfg(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *scopeCfg)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_SCOPECFG, scopeCfg);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets the limit scope configuration.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  scopeCfg           Scope configuration data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath LIMIT_SCOPEMASK
 * @gmp232xParamPath COMMON/LIMIT_SCOPEMASK
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (#GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitScopeCfg(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *scopeCfg)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_SCOPECFG, scopeCfg);
	return (retValue);
}


/**
 * @ingroup GMP232X_Scope_DoCmds
 * @brief Reads the recorded scope sample data without creating comtrade files; use gmp232x_ExportScope() for data exports.
 * Prior to reading the scope data, the scope has to be locked by invoking gmp232x_TakeScopeLock(). Provide the lock handle returned
 * as a value for LockHandle. The Index parameter is used as the first scope data value to be read respecting the maximum possible
 * index value defined by GMP232X_SCOPE_MAXVALIDX.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  LockHandle      Valid lock handle (use LockHandle from gmp232x_TakeScopeLock())
 * @param[in]  Index           First scope value to be read [0 up to #GMP232X_SCOPE_MAXVALIDX]
 * @param[out] ScopeData       Scope data read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetScope(void *DrvId, UINT32 Chan, UINT32 LockHandle, UINT32 Index, GMP232X_SCOPE_DATA *ScopeData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETSCOPE, LockHandle, Index, ScopeData);
	return (retValue);
}


/**
 * @ingroup GMP232X_Scope_DoCmds
 * @brief Reads the scope state. Use this function to poll the state of the scope recorder
 * to detect various state transistions (e.g. when new data is available or when the scope is ready). This
 * function is often used together with gmp232x_GetScope(), gmp232x_ExportScope() or similar.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[out] pScopeState     Scope state read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath SCOPESTATE/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetScopeState(void *DrvId, UINT32 Chan, GMP232X_SCOPE_STATE *pScopeState)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETSCOPESTATE, pScopeState);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Reads harmonic values. A start index as well as a value for an end index has to be provided
 * (both have to be below #GMP232X_MAX_HARMONICS; additionally, start index is not allowed to exceed end index). Use the
 * parameter harmonicsId to specify, which harmonics should be read.
 * @note Updated every 10 periods
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  harmonicsId     Harmonics identifier to be read; #GMP232X_HARMONICS_U_L1 or similar
 * @param[in]  indexStart      Begin index (inclusive); [0 up to (#GMP232X_MAX_HARMONICS - 1)]
 * @param[in]  indexEnd        End index (inclusive); [0 up to (#GMP232X_MAX_HARMONICS - 1)]
 * @param[out] harmonics       Harmonics data read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath HARMONICS/U_L1/ or HARMONICS/U_L2/ or HARMONICS/U_L3/ or HARMONICS/I_L1/ or HARMONICS/I_L2/ or HARMONICS/I_L3/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetHarmonics(void *DrvId, UINT32 Chan, UINT32 harmonicsId, UINT32 indexStart, UINT32 indexEnd, GMP232X_HARMONICS *harmonics)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETHARMONICS, harmonicsId, indexStart, indexEnd, harmonics);
	return (retValue);
}


/**
 * @ingroup GMP232X_Config_DoCmds
 * @brief Sets the module configuration (deprecated with GMP232X Driver V1.01R, use gmp232x_SetConfigExt() instead).
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel, unused for this particular DoCmd (use 0)
 * @param[in]  config       Module configuration to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_SetConfig(void *DrvId, UINT32 Chan, GMP232X_CONFIG *config)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETCONFIG, config);
	return (retValue);
}


/**
 * @ingroup GMP232X_Config_DoCmds
 * @brief Sets the module configuration, extended version. Use this function because gmp232x_SetConfig()
 * is deprecated with GMP232X Driver V1.01R. This function is only applicable in
 * configuration mode (if required, change to a different mode by calling gmp232x_SetState()).
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel, unused for this particular DoCmd (use 0)
 * @param[in]  config       Module configuration to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetConfigExt(void *DrvId, UINT32 Chan, GMP232X_CONFIG_EXT *config)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETCONFIG_EXT, config);
	return (retValue);
}


/**
 * @ingroup GMP232X_ReadValues_DoCmds
 * @brief Optimized variant with phi values for U and I with reduced resolution.
 * Use this function if performance is an issue.
 * @note Updated every zero crossing
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] phiData            Phi data read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @svipath PHASE_UI_S/
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetPhiUIS(void *DrvId, UINT32 Chan, GMP232X_PHASE_UI_S *phiData)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETPHI_UI_S, phiData);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the switch count to the given values.
 * This function writes switch count values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  switchCount        Switch count data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetSwitchCount(void *DrvId, UINT32 Chan, GMP232X_SWITCHCOUNT *switchCount)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETSWITCHCOUNT, switchCount);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the FRMS FCS values.
 * This function writes FRMS FCS  values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  frmsFcs            FRMS FCS data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetFrmsFcs(void *DrvId, UINT32 Chan, GMP232X_FRMS_FCS_VALUES *frmsFcs)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETFRMS_FCS, frmsFcs);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the FRMS FCC values.
 * This function writes FRMS FCC  values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  frmsFcc            FRMS FCC data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetFrmsFcc(void *DrvId, UINT32 Chan, GMP232X_FRMS_FCC_VALUES *frmsFcc)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETFRMS_FCC, frmsFcc);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the TRMS HCS values.
 * This function writes TRMS HCS  values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  trmsHcs            TRMS HCS data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetTrmsHcs(void *DrvId, UINT32 Chan, GMP232X_TRMS_HCS_VALUES *trmsHcs)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETTRMS_HCS, trmsHcs);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the TRMS HCC values.
 * This function writes TRMS HCC  values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  trmsHcc            TRMS HCC data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetTrmsHcc(void *DrvId, UINT32 Chan, GMP232X_TRMS_HCC_VALUES *trmsHcc)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETTRMS_HCC, trmsHcc);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the phase reference values.
 * This function writes phase reference values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  phaseRef           Phase reference data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetPhaseRef(void *DrvId, UINT32 Chan, GMP232X_PHASEREF *phaseRef)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETPHASE_REF, phaseRef);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the frequency phase values.
 * This function writes frequency phase values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  phase              Phase data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetPhase(void *DrvId, UINT32 Chan, GMP232X_PHASE *phase)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETPHASE, phase);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the ROCOF rotation direction.
 * This function writes the ROCOF rotation direction (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  RocofRotDir        ROCOF rotation direction to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetRocofRotDir(void *DrvId, UINT32 Chan, GMP232X_ROCOF_ROTDIR *RocofRotDir)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETROCOF_ROTDIR, RocofRotDir);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief  Sets the powerfactor values.
 * This function writes powerfactor values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  powerFactor        Power factor data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetPowerFactor(void *DrvId, UINT32 Chan, GMP232X_POWERFACTOR *powerFactor)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETPOWERFACTOR, powerFactor);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the asymmetric values.
 * This function writes asymmetric values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  asym               Asymmetrics data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetAsym(void *DrvId, UINT32 Chan, GMP232X_ASYM *asym)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETASYM, asym);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the symmetric components.
 * This function writes symmetric component values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  symComponents      Symmetric components data to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetSymComponents(void *DrvId, UINT32 Chan, GMP232X_SYMCOMPONENTS *symComponents)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETSYM_COMPONENTS, symComponents);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the FRMS FCS power values.
 * This function writes FRMS FCS power values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  powers             FRMS FCS powers to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetPowersFrmsFcs(void *DrvId, UINT32 Chan, GMP232X_POWERS_FRMS_FCS *powers)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETPOWERS_FRMS_FCS, powers);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the FRMS FCC power values.
 * This function writes FRMS FCC power values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  powers             FRMS FCC powers to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetPowersFrmsFcc(void *DrvId, UINT32 Chan, GMP232X_POWERS_FRMS_FCC *powers)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETPOWERS_FRMS_FCC, powers);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the TRMS HCS power values.
 * This function writes TRMS HCS power values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  powers             TRMS HCS powers to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetPowersTrmsHcs(void *DrvId, UINT32 Chan, GMP232X_POWERS_TRMS_HCS *powers)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETPOWERS_TRMS_HCS, powers);
	return (retValue);
}


/**
 * @ingroup GMP232X_VirtualRW_DoCmds
 * @brief Sets the TRMS HCC power values.
 * This function writes TRMS HCC power values (simulating a real module) but is only applicable in virtual RW mode.
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  powers             TRMS HCC powers to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Intended for VIRTUALRW mode; function has no effect in other modes
 * @gmp232xPerfClassIrrelevant
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_VRWSetPowersTrmsHcc(void *DrvId, UINT32 Chan, GMP232X_POWERS_TRMS_HCC *powers)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_VRW_SETPOWERS_TRMS_HCC, powers);
	return (retValue);
}


/**
 * @cond PRIVATE
 * @brief Gets the progress information for scope export and module update
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] progress           Progress information read by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @remark Wraps the common MIO progress information, to generate DoCmd wrapper functions
 * @gmp232xPerfClassIrrelevant
 * @endcond
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetProgress(void *DrvId, UINT32 Chan, MIO_PROGRESS_R *progress)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GETPROGRESS, progress);
	return (retValue);
}


/**
 * @ingroup GMP232X_General_DoCmds
 * @brief Reads the high resolution timestamp (same as used for sample value timestamps).
 * @note Updated on each call
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[out] timestamp          High resolution timestamp value read by the function; time based on 01/01/1970; 10ns
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassFast
 * @since V1.00 Release
 */
static inline SINT32 gmp232x_GetHiResTime(void *DrvId, UINT32 Chan, UINT64  *timestamp)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETHIRESTIME, timestamp);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a relay manually. Provide the relay selector as a single limit parameter to limitId.
 * @param[in]  DrvId             Device Control Block
 * @param[in]  Chan              Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId           Relay identifier to be set; #GMP232X_LIM_2_MANUAL_RELAY1 or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[in]  enable            Flag to enable or disable the relay
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetManualRelay(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, BOOL32 enable)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETMANUALRELAY, limitId, enable);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads if a relay was set manually. Only a single relay selector is allowed to be provided as limitId.
 * @param[in]  DrvId             Device Control Block
 * @param[in]  Chan              Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId           Relay identifier to be set; #GMP232X_LIM_2_MANUAL_RELAY1 or similar; use mask GMP232X_LIMIT_MASK.Mask2
 * @param[out] enable            Flag that indicates if the relay is enabled or disabled
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetManualRelay(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, BOOL32  *enable)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETMANUALRELAY, limitId, enable);
	return (retValue);
}


/**
 * @ingroup GMP232X_Averager_DoCmds
 * @brief Resets a certain mean averager (or multiple).
 * @param[in]  DrvId              Device Control Block
 * @param[in]  Chan               Channel, unused for this particular DoCmd (use 0)
 * @param[in]  averager           Bitmask of the averager(s) to be reset (#GMP232X_AVERAGER1 or similar)
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_ResetAverager(void *DrvId, UINT32 Chan, UINT32 averager)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_RESETAVERAGER, averager);
	return (retValue);
}


/**
 * @ingroup GMP232X_Averager_DoCmds
 * @brief Sets the mean configuration (channels that will be averaged) for #GMP232X_AVERAGER1 and #GMP232X_AVERAGER2. Use this
 * function to configure all mean values prior to reading them via gmp232x_GetMeanValueIndexed() or similar. If a mean value requested
 * is not configured (selected to be internally calculated), reading the value will fail.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  MeanCfg         Mean configuration structure (use bitmasks #GMP232X_MEAN_1_U_L1N_FRMS_FCS or similar). Up to 24 channels are allowed.
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetMeanCfg(void *DrvId, UINT32 Chan, GMP232X_MEAN_CONFIG *MeanCfg)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETMEANCFG, MeanCfg);
	return (retValue);
}


/**
 * @ingroup GMP232X_Averager_DoCmds
 * @brief Reads the mean configuration for #GMP232X_AVERAGER1 and #GMP232X_AVERAGER2.
 * If reading one of the mean values fails (returning #MIO_ER_BADPARM), use this function to check if the mean value requested is configured for calculation.
 * @param[in]  DrvId           Device Control Block
 * @param[in]  Chan            Channel, unused for this particular DoCmd (use 0)
 * @param[in]  MeanCfg         Mean configuration structure read by the function (delivered as bitmasks with #GMP232X_MEAN_1_U_L1N_FRMS_FCS or similar)
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetMeanCfg(void *DrvId, UINT32 Chan, GMP232X_MEAN_CONFIG *MeanCfg)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETMEANCFG, MeanCfg);
	return (retValue);
}


/**
 * @ingroup GMP232X_Averager_DoCmds
 * @brief Function to read all configured mean values for #GMP232X_AVERAGER1 or #GMP232X_AVERAGER2.
 * This docmd does not work for #GMP232X_AVERAGER3, to read mean values for #GMP232X_AVERAGER3 use gmp232x_GetMeanValueRanged() or gmp232x_GetMeanValueIndexed().
 * Because this function may deliver multiple mean values, always provide a data array buffer of size #GMP232X_MEAN_MAXCHAN via the meanValues parameter. Use
 * the parameter NbrOfValues to identify the valid mean values in the returned data buffer meanValues.
 * @param[in]  DrvId            Module instance handle
 * @param[in]  Chan             Channel, unused for this particular DoCmd (use 0)
 * @param[in]  averager         Identifier of the averaging point
 * @param[out] meanValues[]     Data points read; always provide an array of length #GMP232X_MEAN_MAXCHAN
 * @param[out] NbrOfValues      Number of configured values found; use this when reading the array of meanValues
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassModerate
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetMeanValueConfigured(void *DrvId, UINT32 Chan, UINT32 averager, GMP232X_MEAN *meanValues, UINT32  *NbrOfValues)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETMEANVALUECONFIGURED, averager, meanValues, NbrOfValues);
	return (retValue);
}


/**
 * @ingroup GMP232X_General_DoCmds
 * @brief Generates a configuration checksum for specific values, including all extended configuration values,
 * mean- and relay configurations as well as all values provided by the limit functions.
 * This function can be used as an easy way to identify configuration manipulations; it is primary intended for maintainance and initial setups.
 * @param[in]  DrvId            Module instance handle
 * @param[in]  Chan             Channel, unused for this particular DoCmd (use 0)
 * @param[out] checkSumPart     Calculated MD5 digest array for specific configured values; provide an array of length 16, size 8-byte each; no additional space for null termination required
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassSlow
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetCfgChecksum(void *DrvId, UINT32 Chan, UINT8  *checkSumPart)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETCFGCHECKSUM, checkSumPart);
	return (retValue);
}


/**
 * @ingroup GMP232X_History_DoCmds
 * @brief Reads various alarm history counter values. Use this helper function to check, if alarm history
 * entries are available; prevents unnecessary locking of the alarm history if no history entries are available.
 * @param[in]  DrvId            Module instance handle
 * @param[in]  Chan             Channel, unused for this particular DoCmd (use 0)
 * @param[out] historyCounters  Various counters related to the alarm history read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassFast
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetHistoryTotal(void *DrvId, UINT32 Chan, GMP232X_HISTORY_COUNT *historyCounters)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETHISTORYTOTAL, historyCounters);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Sets a negative system blocking configuration. Use the parameter GMP232X_LIM_1_NEGSYS as
 * limitId to provide a single limit for which to set the limit configuration. For consistency reasons,
 * this parameter has to be provided (even if it is the only allowed value for limitId).
 * This function is only applicable in configuration mode.
 * @param[in]  DrvId            Module instance handle
 * @param[in]  Chan             Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId          Limit identifier; #GMP232X_LIM_1_NEGSYS or similar; use mask GMP232X_LIMIT_MASK.Mask1
 * @param[in]  negSys           Negative system settings to be written
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @gmp232xPreConditions Ensure, that the GMP module is operating in configuration mode (GMP232X_STATE_CONFIG) prior to invoking this function. Use gmp232x_SetState() to change module states.
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_SetLimitNegSys(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_NEGSYS *negSys)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_SETLIMIT_NEGSYS, limitId, negSys);
	return (retValue);
}


/**
 * @ingroup GMP232X_Limit_DoCmds
 * @brief Reads the negative system blocking configuration.
 * @param[in]  DrvId            Module instance handle
 * @param[in]  Chan             Channel, unused for this particular DoCmd (use 0)
 * @param[in]  limitId          Limit identifier; #GMP232X_LIM_1_NEGSYS; use mask GMP232X_LIMIT_MASK.Mask1
 * @param[out] negSys           Negative system settings read back by the function
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @gmp232xPerfClassIrrelevant
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetLimitNegSys(void *DrvId, UINT32 Chan, GMP232X_LIMIT_MASK *limitId, GMP232X_LIMIT_NEGSYS *negSys)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETLIMIT_NEGSYS, limitId, negSys);
	return (retValue);
}


/**
 * @ingroup GMP232X_General_DoCmds
 * @brief Reads all errors of the module. In contrast to the GMP232X specific implementation of mio_GetError(),
 * this function provides all available errors - including module and limit errors. The generic function mio_GetError() filters errors based on the #MIO_E_MSK_GMP232X mask.
 * @param[in]  DrvId            Module instance handle
 * @param[in]  Chan             Channel, unused for this particular DoCmd (use 0)
 * @param[out] error            Errors of the module read back by the function (#MIO_E_V_LO1 or one of the similar defines); these is a combination of error bits described in \ref gmp232xModuleSpecificErrors "Module errors"
 *
 * @retval #MIO_ER_OK Successful.
 * @gmp232xPerfClassFast
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetError(void *DrvId, UINT32 Chan, UINT32  *error)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETERROR, error);
	return (retValue);
}


/**
 * @ingroup GMP232X_General_DoCmds
 * @brief Reads the AutoStart configuration setting of the module defined as parameter "AutoStart" in SolutionCenter.
 * @param[in]  DrvId            Module instance handle
 * @param[in]  Chan             Channel, unused for this particular DoCmd (use 0)
 * @param[out] autoStart        AutoStart setting read back by the function (possible values TRUE or FALSE)
 *
 * @retval #MIO_ER_OK Successful.
 * @gmp232xPerfClassFast
 * @since V1.01 Release
 */
static inline SINT32 gmp232x_GetAutoStart(void *DrvId, UINT32 Chan, UINT32  *autoStart)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GMP232X_GETAUTOSTART, autoStart);
	return (retValue);
}


#endif /*M_OS_VXWORKS*/

#ifdef __cplusplus
}
#endif

#endif
