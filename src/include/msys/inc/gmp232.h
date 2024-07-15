/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     gmp232.h
* @author   Holl
* @brief    MIO-Gegenstueck zu drv/gmp232/gmp232_dpm.h
*           Die hier enthaltenen Strukturen werden vom Anwender verwendet und vor
*           der weitergabe an die Hardware auf die entsprechenden Strukturen aus
*           gmp232_dpm.h umkopiert.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef GMP232__H
#define GMP232__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @name Defines
 * @{
 */

#define GMP_RELAY_1 0x0001
#define GMP_RELAY_2 0x0002

/**
 * @name Values used in GMP_CONFIG.Mode and GMP_VECTORDIAGRAM.Mode
 * @{
 */

#define GMP_M_SINGLEPHASE           1    /**< Single phase */
#define GMP_M_2PHASEASYM            2    /**< 2 phases, asymmetric load */
#define GMP_M_3WIRE3PHASEBALANCED   3    /**< 3 wires, 3 phases, symmetric load */
#define GMP_M_3WIRE3PHASEASYM       4    /**< 3 wires, 3 phases, asymmetric load */
#define GMP_M_3WIRE3PHASEARON       5    /**< 3 wires, 3 phases, Aron circuit */
#define GMP_M_4WIRE3PHASEBALANCED   6    /**< 4 wires, 3 phases, symmetric load */
#define GMP_M_4WIRE3PHASEASYM       7    /**< 4 wires, 3 phases asymmetric (phase phase) */
#define GMP_M_4WIRE3PHASEBALANCEDLN 8    /**< 4 wires, 3 phases symmetric (phase neutral) */
#define GMP_M_4WIRE3PHASEASYMLN     9    /**< 4 wires, 3 phases asymmetric (phase neutral) */
/** @} */

/**
 * @name 'State-machine' States
 * @{
 */

#define GMP_STATE_CONFIG        0x0  /**< wait for run mode */
#define GMP_STATE_RUN           0x1  /**< run in configured setup */
#define GMP_STATE_FORCERELAY    0x2  /**< Relay simulation mode */
#define GMP_STATE_SIMULATION    0x4  /**< simulation mode */
#define GMP_STATE_MEASURING     0x8000   /**< Always together with one of the above values */
/** @} */

/**
 * @name Values used at GMP_FREQUENCYLIMIT.LimitId to specify the frequency window.
 * @{
 */

#define GMP_F_IN    0x0
#define GMP_F_MID   0x1
#define GMP_F_OUT   0x2
/** @} */

/**
 * @name Power descriptors for mean sample values
 * @{
 */

#define GMP_SAMPLE_MEAN_P   0x00     /**< Calculate mean value from real power */
/** @} */

/**
 * @name Limit configuration constants
 * @{
 */

#define GMP_ERR_U_MIN       0x8000
#define GMP_ERR_U_MAX       0x0000
#define GMP_EVT_U_MIN       0x8001
#define GMP_EVT_U_MAX       0x0001
#define GMP_ERR_I_MAX       0x0002
#define GMP_ERR_THD_MAX     0x0003
#define GMP_ERR_TDD_MAX     0x0004
#define GMP_ERR_ASYM_U_MAX  0x0005
#define GMP_ERR_ASYM_I_MAX  0x0006
#define GMP_ERR_ROCOF_MAX   0x0007
#define GMP_EVT_I_MAX       0x0008
/** @} */

/**
 * @name Defines unsed at GMP_VALUES.RotDir_U/I
 * @{
 */

#define ROTATION_CW         0x0000
#define ROTATION_CCW        0x0001
#define ROTATION_UNKNOWN    0xFFFF
/** @} */

/**
 * @name Constants used at GMP_SCOPESTATE.State
 * @{
 */

#define GMP_SCOPE_STATE_NOTTRIGGERED    0x0
#define GMP_SCOPE_STATE_RUNNING         0x1
#define GMP_SCOPE_STATE_TRIGGERED       0x2
#define GMP_SCOPE_STATE_READY           0x4
#define GMP_SCOPE_STATE_LOCKED          0x8
#define GMP_SCOPE_STATE_RECORDING       0x10
#define GMP_SCOPE_STATE_NEWDATA         0x20
#define GMP_SCOPE_MAXCHAN               16
#define GMP_SCOPE_MAXSAMPLES            16
#define GMP_SCOPE_VALCNT                40960
#define GMP_SCOPE_MAXVALIDX             (GMP_SCOPE_VALCNT - GMP_SCOPE_MAXSAMPLES)
/** @} */

/**
 * @name Constants used at GMP_SCOPESTATE.TriggerEvent
 * @{
 */

#define GMP_SCOPE_TE_ERROR              0x8000   /**< Alarm entry of type ERROR */
#define GMP_SCOPE_TE_EVENT              0x4000   /**< Alarm entry of type WARNING */
#define GMP_SCOPE_TE_INFO               0x2000   /**< Alarm entry of type INFO */
#define GMP_SCOPE_TE_APPEAR             0x0100   /**< Alarm entry appeared or disappeared */
#define GMP_SCOPE_TE_ER_U_L1_MIN        0x0000
#define GMP_SCOPE_TE_ER_U_L1_MAX        0x0001
#define GMP_SCOPE_TE_ER_U_L2_MIN        0x0002
#define GMP_SCOPE_TE_ER_U_L2_MAX        0x0003
#define GMP_SCOPE_TE_ER_U_L3_MIN        0x0004
#define GMP_SCOPE_TE_ER_U_L3_MAX        0x0005
#define GMP_SCOPE_TE_ER_I_L1_MAX        0x0006
#define GMP_SCOPE_TE_ER_I_L2_MAX        0x0007
#define GMP_SCOPE_TE_ER_I_L3_MAX        0x0008
#define GMP_SCOPE_TE_ER_THD_U_L1_MAX    0x0009
#define GMP_SCOPE_TE_ER_THD_U_L2_MAX    0x000a
#define GMP_SCOPE_TE_ER_THD_U_L3_MAX    0x000b
#define GMP_SCOPE_TE_ER_TDD_I_L1_MAX    0x000c
#define GMP_SCOPE_TE_ER_TDD_I_L2_MAX    0x000d
#define GMP_SCOPE_TE_ER_TDD_I_L3_MAX    0x000e
#define GMP_SCOPE_TE_ER_ASYM_U_MAX      0x000f
#define GMP_SCOPE_TE_ER_ASYM_I_MAX      0x0010
#define GMP_SCOPE_TE_ER_F_IN_MIN        0x0011
#define GMP_SCOPE_TE_ER_F_IN_MAX        0x0012
#define GMP_SCOPE_TE_ER_F_MID_MIN       0x0013
#define GMP_SCOPE_TE_ER_F_MID_MAX       0x0014
#define GMP_SCOPE_TE_ER_F_OUT_MIN       0x0015
#define GMP_SCOPE_TE_ER_F_OUT_MAX       0x0016
#define GMP_SCOPE_TE_ER_VECTORJMP       0x0017
#define GMP_SCOPE_TE_ER_ROCOF_MAX       0x0018
#define GMP_SCOPE_TE_ER_FRT_U_L1        0x0019
#define GMP_SCOPE_TE_ER_FRT_U_L2        0x001a
#define GMP_SCOPE_TE_ER_FRT_U_L3        0x001b
#define GMP_SCOPE_TE_EV_U_L1_MIN        0x0000
#define GMP_SCOPE_TE_EV_U_L1_MAX        0x0001
#define GMP_SCOPE_TE_EV_U_L2_MIN        0x0002
#define GMP_SCOPE_TE_EV_U_L2_MAX        0x0003
#define GMP_SCOPE_TE_EV_U_L3_MIN        0x0004
#define GMP_SCOPE_TE_EV_U_L3_MAX        0x0005
#define GMP_SCOPE_TE_EV_I_L1_MAX        0x0006
#define GMP_SCOPE_TE_EV_I_L2_MAX        0x0007
#define GMP_SCOPE_TE_EV_I_L3_MAX        0x0008
#define GMP_SCOPE_TE_EV_HARMONICS_U_L1  0x0009
#define GMP_SCOPE_TE_EV_HARMONICS_U_L2  0x000a
#define GMP_SCOPE_TE_EV_HARMONICS_U_L3  0x000b
#define GMP_SCOPE_TE_EV_HARMONICS_I_L1  0x000c
#define GMP_SCOPE_TE_EV_HARMONICS_I_L2  0x000d
#define GMP_SCOPE_TE_EV_HARMONICS_I_L3  0x000e
/** @} */

/**
 * @name Constants used at GMP_SCOPECFG.SampleRate.
 * @{
 */

#define GMP_SCOPE_SAMPLE_100US  0    /**< Sample rate of    10kHz */
#define GMP_SCOPE_SAMPLE_200US  1    /**< Sample rate of     5kHz */
#define GMP_SCOPE_SAMPLE_400US  2    /**< Sample rate of   2.5kHz */
#define GMP_SCOPE_SAMPLE_800US  3    /**< Sample rate of  1.25kHz */
#define GMP_SCOPE_SAMPLE_1600US 4    /**< Sample rate of 0.625kHz */
/** @} */

/**
 * @name Constants used at GMP_SCOPECFG.ChanBitMask.
 * @{
 */

#define GMP_SCOPE_U_L1N         0x0000000000000001LL
#define GMP_SCOPE_U_L2N         0x0000000000000002LL
#define GMP_SCOPE_U_L3N         0x0000000000000004LL
#define GMP_SCOPE_U_L1L2        0x0000000000000008LL
#define GMP_SCOPE_U_L2L3        0x0000000000000010LL
#define GMP_SCOPE_U_L3L1        0x0000000000000020LL
#define GMP_SCOPE_I_L1          0x0000000000000040LL
#define GMP_SCOPE_I_L2          0x0000000000000080LL
#define GMP_SCOPE_I_L3          0x0000000000000100LL
#define GMP_SCOPE_I_N           0x0000000000000200LL
#define GMP_SCOPE_U_L1N_RMS     0x0000000000000400LL
#define GMP_SCOPE_U_L2N_RMS     0x0000000000000800LL
#define GMP_SCOPE_U_L3N_RMS     0x0000000000001000LL
#define GMP_SCOPE_U_L1L2_RMS    0x0000000000002000LL
#define GMP_SCOPE_U_L2L3_RMS    0x0000000000004000LL
#define GMP_SCOPE_U_L3L1_RMS    0x0000000000008000LL
#define GMP_SCOPE_I_L1_RMS      0x0000000000010000LL
#define GMP_SCOPE_I_L2_RMS      0x0000000000020000LL
#define GMP_SCOPE_I_L3_RMS      0x0000000000040000LL
#define GMP_SCOPE_I_N_RMS       0x0000000000080000LL
#define GMP_SCOPE_P_SUM         0x0000000000100000LL
#define GMP_SCOPE_P_L1          0x0000000000200000LL
#define GMP_SCOPE_P_L2          0x0000000000400000LL
#define GMP_SCOPE_P_L3          0x0000000000800000LL
#define GMP_SCOPE_S_SUM         0x0000000001000000LL
#define GMP_SCOPE_S_L1          0x0000000002000000LL
#define GMP_SCOPE_S_L2          0x0000000004000000LL
#define GMP_SCOPE_S_L3          0x0000000008000000LL
#define GMP_SCOPE_Q_SUM         0x0000000010000000LL
#define GMP_SCOPE_Q_L1          0x0000000020000000LL
#define GMP_SCOPE_Q_L2          0x0000000040000000LL
#define GMP_SCOPE_Q_L3          0x0000000080000000LL
#define GMP_SCOPE_F             0x0000000100000000LL
#define GMP_SCOPE_ROCOF         0x0000000200000000LL
#define GMP_SCOPE_ASYM_U        0x0000000400000000LL
#define GMP_SCOPE_ASYM_I        0x0000000800000000LL
#define GMP_SCOPE_PHI_U1I1      0x0000001000000000LL
#define GMP_SCOPE_PHI_U2I2      0x0000002000000000LL
#define GMP_SCOPE_PHI_U3I3      0x0000004000000000LL
#define GMP_SCOPE_U_L1_IEC      0x0000008000000000LL
#define GMP_SCOPE_U_L2_IEC      0x0000010000000000LL
#define GMP_SCOPE_U_L3_IEC      0x0000020000000000LL
#define GMP_SCOPE_I_L1_IEC      0x0000040000000000LL
#define GMP_SCOPE_I_L2_IEC      0x0000080000000000LL
#define GMP_SCOPE_I_L3_IEC      0x0000100000000000LL
#define GMP_SCOPE_P_IEC         0x0000200000000000LL
#define GMP_SCOPE_S_IEC         0x0000400000000000LL
#define GMP_SCOPE_Q_IEC         0x0000800000000000LL
#define GMP_SCOPE_RELAYS        0x0100000000000000LL
/** @} */

/**
 * @name Constants used to determine which values of GMP_VALUES should be read by MIO_CMD_GETSELECTEDVALUES.
 * @{
 */


/**
 * @name The values match the GMP_SCOPE_ constants used at the GMP_SCOPECFG.ChanBitMask.
 * @{
 */

#define GMP_VAL_U_L1N_RMS   0x0000000000000400LL
#define GMP_VAL_U_L2N_RMS   0x0000000000000800LL
#define GMP_VAL_U_L3N_RMS   0x0000000000001000LL
#define GMP_VAL_U_L1L2_RMS  0x0000000000002000LL
#define GMP_VAL_U_L2L3_RMS  0x0000000000004000LL
#define GMP_VAL_U_L3L1_RMS  0x0000000000008000LL
#define GMP_VAL_I_L1_RMS    0x0000000000010000LL
#define GMP_VAL_I_L2_RMS    0x0000000000020000LL
#define GMP_VAL_I_L3_RMS    0x0000000000040000LL
#define GMP_VAL_I_N_RMS     0x0000000000080000LL
#define GMP_VAL_P_SUM       0x0000000000100000LL
#define GMP_VAL_P_L1        0x0000000000200000LL
#define GMP_VAL_P_L2        0x0000000000400000LL
#define GMP_VAL_P_L3        0x0000000000800000LL
#define GMP_VAL_S_SUM       0x0000000001000000LL
#define GMP_VAL_S_L1        0x0000000002000000LL
#define GMP_VAL_S_L2        0x0000000004000000LL
#define GMP_VAL_S_L3        0x0000000008000000LL
#define GMP_VAL_Q_SUM       0x0000000010000000LL
#define GMP_VAL_Q_L1        0x0000000020000000LL
#define GMP_VAL_Q_L2        0x0000000040000000LL
#define GMP_VAL_Q_L3        0x0000000080000000LL
#define GMP_VAL_FREQUENCY   0x0000000100000000LL
#define GMP_VAL_ROCOF       0x0000000200000000LL
#define GMP_VAL_ASYM_U      0x0000000400000000LL
#define GMP_VAL_ASYM_I      0x0000000800000000LL
/** @} */

/**
 * @name The following values are not available at GMP_SCOPECFG.ChanBitMask.
 * @{
 */

#define GMP_VAL_PHI_U1I1    0x0008000000000000LL
#define GMP_VAL_PHI_U2I2    0x0010000000000000LL
#define GMP_VAL_PHI_U3I3    0x0020000000000000LL
#define GMP_VAL_PF_SUM      0x0040000000000000LL
#define GMP_VAL_PF_L1       0x0080000000000000LL
#define GMP_VAL_PF_L2       0x0100000000000000LL
#define GMP_VAL_PF_L3       0x0200000000000000LL
#define GMP_VAL_ROTDIR_U    0x0400000000000000LL
#define GMP_VAL_ROTDIR_I    0x0800000000000000LL
#define GMP_VAL_OVERLOADU   0x1000000000000000LL
#define GMP_VAL_OVERLOADI   0x2000000000000000LL
#define GMP_VAL_VECTORJMP   0x4000000000000000LL
#define GMP_VAL_ALL         0xFFFFFFFFFFFFFFFFLL
/** @} */
/** @} */
/** @} */

/**
 * @name Strukturen
 * @{
 */

/**
 * Core GMP232 Konfiguration, can only be changed during startup.
 * Structure for DoCmd-function MIO_CMD_GETCONFIG
 */
typedef struct
{
    /**
     * The GMP mode. Possible values are
     * GMP_M_SINGLEPHASE, GMP_M_2PHASEASYM, GMP_M_3WIRE3PHASEBALANCED,
     * GMP_M_3WIRE3PHASEASYM, GMP_M_3WIRE3PHASEARON,
     * GMP_M_4WIRE3PHASEBALANCED, GMP_M_4WIRE3PHASEASYM
     */
    UINT32  Mode;
    UINT32  PTSecondary;        /**< Voltage transformer secondary side, nom. in V */
    UINT32  CTSecondary;        /**< Current transformer secondary side, nom. in mA */
    UINT32  Frequency;          /**< Frequency in Hz, 50 or 60 */
    UINT32  PTPrimary;          /**< Voltage transformer primary side, nom. in V */
    UINT32  CTPrimary;          /**< Current transformer primary side, nom. in A */
} GMP_CONFIG;

/**
 * Upper/Lower Limit configuration.
 * Structure for DoCmd-function MIO_CMD_SETLIMITCFG / MIO_CMD_GETLIMITCFG /
 * MIO_CMD_SETROCOFLIMIT / MIO_CMD_GETROCOFLIMIT / MIO_CMD_SETASYMLIMIT / MIO_CMD_GETASYMLIMIT
 */
typedef struct
{
    UINT32  Enabled;            /**< Enable/Disable limit monitoring */
    UINT32  Value;              /**< Voltage limit in [0.1%], Max: 500% */
    UINT32  Hysteresis;         /**< Threshold Hysteresis in [0.1%], Max. 500% */
    UINT32  Delay;              /**< In [ms], Max. 65535 */
    UINT32  Relay;              /**< Relay to switch after event occurred */
    UINT32  ScopeEnabled;       /**< Generate scope event */
} GMP_LIMIT;

/**
 * Vector Jump configuration.
 * Structure for DoCmd-function MIO_CMD_SETVECTORJMPLIMIT / MIO_CMD_GETVECTORJMPLIMIT
 */
typedef struct
{
    UINT32  Enabled;            /**< En-/Disable limit monitoring */
    UINT32  Value;              /**< Voltage limit in in steps of [0.1°], Valid: 50 - 300 */
    UINT32  Relay;              /**< Relay to switch after event occurred */
    UINT32  ScopeEnabled;       /**< Generate scope event */
} GMP_VECTORJMPLIMIT;


/**
 * @name Constants used in parameter DataPointId of MIO_CMD_GETSTATISTICS
 * @{
 */

#define GMP_STATISTICS_U_L1N_PEAK   0    /**< Voltage Phase 1 (peak) */
#define GMP_STATISTICS_U_L2N_PEAK   1    /**< Voltage Phase 2 (peak) */
#define GMP_STATISTICS_U_L3N_PEAK   2    /**< Voltage Phase 1 (peak) */
#define GMP_STATISTICS_U_L12_PEAK   3    /**< Voltage Phase 1 and Phase 2 (peak) */
#define GMP_STATISTICS_U_L23_PEAK   4    /**< Voltage Phase 2 and Phase 3 (peak) */
#define GMP_STATISTICS_U_L31_PEAK   5    /**< Voltage Phase 3 and Phase 1 (peak) */
#define GMP_STATISTICS_I_L1_PEAK    6    /**< Current Phase 1 (peak) */
#define GMP_STATISTICS_I_L2_PEAK    7    /**< Current Phase 2 (peak) */
#define GMP_STATISTICS_I_L3_PEAK    8    /**< Current Phase 3 (peak) */
#define GMP_STATISTICS_I_N_PEAK     9    /**< Current Neutral (peak) */
#define GMP_STATISTICS_U_L1N        10   /**< Voltage Phase 1 (RMS) */
#define GMP_STATISTICS_U_L2N        11   /**< Voltage Phase 2 (RMS) */
#define GMP_STATISTICS_U_L3N        12   /**< Voltage Phase 1 (RMS) */
#define GMP_STATISTICS_U_L12        13   /**< Voltage Phase 1 and Phase 2 (RMS) */
#define GMP_STATISTICS_U_L23        14   /**< Voltage Phase 2 and Phase 3 (RMS) */
#define GMP_STATISTICS_U_L31        15   /**< Voltage Phase 3 and Phase 1 (RMS) */
#define GMP_STATISTICS_I_L1         16   /**< Current Phase 1 (RMS) */
#define GMP_STATISTICS_I_L2         17   /**< Current Phase 2 (RMS) */
#define GMP_STATISTICS_I_L3         18   /**< Current Phase 3 (RMS) */
#define GMP_STATISTICS_I_N          19   /**< Current Neutral (RMS) */
#define GMP_STATISTICS_P_SUM        20   /**< Total Real Power */
#define GMP_STATISTICS_P_L1         21   /**< Real Power Phase 1 */
#define GMP_STATISTICS_P_L2         22   /**< Real Power Phase 2 */
#define GMP_STATISTICS_P_L3         23   /**< Real Power Phase 3 */
#define GMP_STATISTICS_S_SUM        24   /**< Total Complex Power */
#define GMP_STATISTICS_S_L1         25   /**< Real Complex Power Phase 1 */
#define GMP_STATISTICS_S_L2         26   /**< Real Complex Power Phase 2 */
#define GMP_STATISTICS_S_L3         27   /**< Real Complex Power Phase 3 */
#define GMP_STATISTICS_Q_SUM        28   /**< Total Reactive Power */
#define GMP_STATISTICS_Q_L1         29   /**< Real Reactive Phase 1 */
#define GMP_STATISTICS_Q_L2         30   /**< Real Reactive Phase 2 */
#define GMP_STATISTICS_Q_L3         31   /**< Real Reactive Phase 3 */
#define GMP_STATISTICS_F            32   /**< Frequency */
#define GMP_STATISTICS_ROCOF        33   /**< ROCOF */
#define GMP_STATISTICS_THD_U1U12    34   /**< THD U1/U12 */
#define GMP_STATISTICS_THD_U2U23    35   /**< THD U2/U23 */
#define GMP_STATISTICS_THD_U3U31    36   /**< THD U3/U31 */
#define GMP_STATISTICS_TDD_I1       37   /**< TDD I1 */
#define GMP_STATISTICS_TDD_I2       38   /**< TDD I2 */
#define GMP_STATISTICS_TDD_I3       39   /**< TDD I3 */
#define GMP_STATISTICS_ASYM_U       40   /**< Voltage Asymetric */
#define GMP_STATISTICS_ASYM_I       41   /**< Current Asymetric */
#define GMP_STATISTICS_PHI_U1I1     42   /**< Phase Angle from U1 and I1 */
#define GMP_STATISTICS_PHI_U2I2     43   /**< Phase Angle from U2 and I2 */
#define GMP_STATISTICS_PHI_U3I3     44   /**< Phase Angle from U3 and I3 */
#define GMP_STATISTICS_VECTORJMP    45   /**< Vector jump */
/** @} */
/**
 * Statistics data:
 */
typedef struct
{
    UINT32  Timestamp;          /**< Timestamp - Seconds since, 1.1.1970 0:00 / 0 - invalid point */
    UINT32  TimestampMs;        /**< Timestamp - mSec part */
    SINT32  Value;              /**< Data point value */
} GMP_STATISTICDATAPOINT;

/**
 * Structure for DoCmd-function MIO_CMD_GETSTATISTICS
 */
typedef struct
{
    GMP_STATISTICDATAPOINT  Min;     /**< Minimum data point */
    GMP_STATISTICDATAPOINT  Max;     /**< Maximum data point */
} GMP_GETSTATISTIC;

typedef struct
{
    CHAR8   Name[32];           /**< Name of the data point */
    REAL32  Scale;              /**< Scaling factor */
    REAL32  Offset;             /**< Offset */
    UINT32  SiUnit;             /**< Si-Units:  UFB_SIUNIT */
    CHAR8   UnitStr[12];        /**< Unit optional text ("V", "uA"...) */
} GMP_STATISTICINF;

/**
 * Structure for DoCmd-function MIO_CMD_DISPSTATISTICS
 */
typedef struct
{
    GMP_GETSTATISTIC    DataPoint;   /**< Statistic values */
    GMP_STATISTICINF    AddInf; /**< Additional information */
} GMP_DISPLAYSTATISTICS;

/**
 * Simulation Data
 * Structure for DoCmd-function MIO_CMD_SETSIMDATA / MIO_CMD_GETSIMDATA
 */
typedef struct
{
    UINT32  U_L1;               /**< Voltage in [0.1%], Max: 500% */
    UINT32  U_L2;               /**< Voltage in [0.1%], Max: 500% */
    UINT32  U_L3;               /**< Voltage in [0.1%], Max: 500% */
    UINT32  I_L1;               /**< Current in [0.1%], Max: 500% */
    UINT32  I_L2;               /**< Current in [0.1%], Max: 500% */
    UINT32  I_L3;               /**< Current in [0.1%], Max: 500% */
    UINT32  f;                  /**< Frequency in [0.01Hz], Max: +/- 15Hz of net frequency */
    UINT32  Phi_U_L1;           /**< Phase U L1 in [0.1°], Max: 360° */
    UINT32  Phi_U_L2;           /**< Phase U L2 in [0.1°], Max: 360° */
    UINT32  Phi_U_L3;           /**< Phase U L3 in [0.1°], Max: 360° */
    UINT32  Phi_I_L1;           /**< Phase I L1 in [0.1°], Max: 360° */
    UINT32  Phi_I_L2;           /**< Phase I L2 in [0.1°], Max: 360° */
    UINT32  Phi_I_L3;           /**< Phase I L3 in [0.1°], Max: 360° */
} GMP_SIMDATA;


/**
 * @name Defines used as ValueIdx at MIO_CMD_[GS]ETHARMONICSLIMIT
 * @{
 */

#define GMP_HARMONICS_U         0
#define GMP_HARMONICS_I         1
#define GMP_MAX_HARMONICS       50   /**< Used in GMP_HARMONICS only! */
#define GMP_MAX_HARMONICSLIMIT  49   /**< Used in GMP_HARMONICSLIMIT only! */
/** @} */
/**
 * Harmonics Limit,  Voltage and current harmonics
 * Structure for DoCmd-function MIO_CMD_SETHARMONICSLIMIT / MIO_CMD_GETHARMONICSLIMIT
 */
typedef struct
{
    UINT32  Enabled;            /**< Enable/disable monitoring */
    UINT32  Value[GMP_MAX_HARMONICSLIMIT];   /**< Limit values in [0.1%], Max. 100% */
    UINT32  Relay;              /**< Relay to be switched */
    UINT32  ScopeEnabled;       /**< Generate scope event */
} GMP_HARMONICSLIMIT;


/**
 * @name Defines used as ValueIdx at MIO_CMD_GETHARMONICS
 * @{
 */

#define GMP_HARMONICS_U_L1  0
#define GMP_HARMONICS_U_L2  1
#define GMP_HARMONICS_U_L3  2
#define GMP_HARMONICS_I_L1  3
#define GMP_HARMONICS_I_L2  4
#define GMP_HARMONICS_I_L3  5
/** @} */
/**
 * Structure for DoCmd-function MIO_CMD_GETHARMONICS
 * Harmonics, Voltage and current harmonics
 */
typedef struct
{
    UINT32  Value[GMP_MAX_HARMONICS];    /**< Harmonics values */
    UINT32  THDTDD;             /**< THD/TDD in 0.01% */
} GMP_HARMONICS;

/**
 * Structure for DoCmd-function MIO_CMD_SETFREQUENCYWINDOW / MIO_CMD_GETFREQUENCYWINDOW
 */
typedef struct
{
    UINT32  Enabled;            /**< En-/Disable limit monitoring */
    UINT32  Min;                /**< Frequency in 0.01Hz. */
    UINT32  Max;                /**< Frequency in 0.01Hz. */
    UINT32  Delay;              /**< Delay */
    UINT32  Relay;              /**< Relay to switch */
    UINT32  ScopeEnabled;       /**< Scope is enabled by mio_AttachEvent */
} GMP_FREQUENCYLIMIT;

typedef struct
{
    UINT32  Time;               /**< Timestamp relative to GMP_SCOPECFG */
    SINT32  Data[GMP_SCOPE_MAXCHAN];     /**< Recorded values */
} GMP_SCOPESAMPLE;

/**
 * Structure for DoCmd-function MIO_CMD_GETSCOPE
 * scope data structure
 */
typedef struct
{
    GMP_SCOPESAMPLE Samples[GMP_SCOPE_MAXSAMPLES];
} GMP_SCOPEDATA;

/**
 * Structure for DoCmd-function MIO_CMD_SETSCOPECFG / MIO_CMD_GETSCOPECFG
 */
typedef struct
{
    UINT64  ChanBitMask;        /**< Bit mask of enabled channels. */
    UINT32  SampleRate;         /**< One of the GMP_SCOPE_SAMPLE_xxx constants */
    UINT32  Pretrigger;         /**< Number of GMP_SCOPEDATA elements prior event */
} GMP_SCOPECFG;

/**
 * Structure for DoCmd-function MIO_CMD_GETSCOPESTATE
 */
typedef struct
{
    UINT32  State;              /**< One of the GMP_SCOPE_STATE_ constants */
    UINT32  PretriggerCount;    /**< Number of pre-trigger samples */
    UINT32  Time;               /**< Timestamp - Seconds since 1.1.1970 0:00 */
    UINT32  TimeMs;             /**< Timestamp - mSec part */
    UINT32  TriggerEvent;       /**< Event that caused scope recording */
} GMP_SCOPESTATE;

/**
 * Structure for DoCmd-function MIO_CMD_TAKEHISTORYLOCK
 */
typedef struct
{
    UINT32  LockHandle;         /**< Lock handle */
    UINT32  ActNbEntries;       /**< Number of entries in the history */
    UINT32  TotalNbEntries;     /**< Number of entries since last history delete */
} GMP_LOCKHISTORY;

/**
 * Structure for DoCmd-function MIO_CMD_GETALARMHISTORY
 */
typedef struct
{
    UINT32  Time;               /**< Time - Seconds since 1.1.1970 00:00 */
    UINT32  TimeMs;             /**< Time - mSec part */
    /**
     * Event type bit mask, any of the following can be set:
     * GMP_SCOPE_TE_ERROR, GMP_SCOPE_TE_EVENT,
     * GMP_SCOPE_TE_INFO, GMP_SCOPE_TE_APPEAR
     */
    UINT32  EventID;
} GMP_ALARMHISTORY;

typedef struct
{
    UINT32  Voltage;            /**< In 0.1%. */
    UINT32  Time;               /**< Zeit in mSec, Max: 65535 */
} GMP_VOLTAGEPOINT;

#define MAX_FRTVPOINTS  11
/**
 * Structure for DoCmd-function MIO_CMD_SETFRT / MIO_CMD_GETFRT
 * Data structure for FRT configuration
 */
typedef struct
{
    UINT32              Enabled;     /**< En-/Disable FRT monitoring */
    UINT32              PointCount;  /**< Max. 11 (MAX_FRTVPOINTS) */
    UINT32              InitThreshold;   /**< Initial threshold [0.1% of nominal voltage] */
    UINT32              FallbackVoltage;     /**< In [0.1%] */
    UINT32              FallbackTime;    /**< Time in mSec, Max: 65535 */
    GMP_VOLTAGEPOINT    VoltagePoints[MAX_FRTVPOINTS];   /**< FRT Table */
    UINT32              Relay;  /**< 0 (disabled) to 2 */
    UINT32              ScopeEnabled;    /**< Interrupt triggering scope must be enabled via mio_AttachEvent */
} GMP_FRT;

/**
 * Structure for DoCmd-function MIO_CMD_SETENERGY / MIO_CMD_GETENERGY
 */
typedef struct
{
    UINT64  ActiveEnergyDelivered;
    UINT64  ActiveEnergyReceived;
    UINT64  ReactiveEnergyDelivered;
    UINT64  ReactiveEnergyReceived;
} GMP_ENERGY;

/**
 * Structure for DoCmd-function MIO_CMD_SETENERGYREAL / MIO_CMD_GETENERGYREAL
 * @since V1.01.03 Beta
 */
typedef struct
{
    REAL64  ActiveEnergyDelivered;
    REAL64  ActiveEnergyReceived;
    REAL64  ReactiveEnergyDelivered;
    REAL64  ReactiveEnergyReceived;
} GMP_ENERGYREAL;

/**
 * Structure for DoCmd-function MIO_CMD_GETVALUES / MIO_CMD_GETSELECTEDVALUES
 * All measured values
 */
typedef struct
{
    UINT32  U_L1L2_rms;         /**< mV */
    UINT32  U_L2L3_rms;         /**< mV */
    UINT32  U_L3L1_rms;         /**< mV */
    UINT32  U_L1N_rms;          /**< mV */
    UINT32  U_L2N_rms;          /**< mV */
    UINT32  U_L3N_rms;          /**< mV */
    UINT32  I_L1_rms;           /**< mA */
    UINT32  I_L2_rms;           /**< mA */
    UINT32  I_L3_rms;           /**< mA */
    UINT32  I_N_rms;            /**< mA */
    UINT32  f;                  /**< mHz */
    SINT32  Phi_U1I1;           /**< 0.1° */
    SINT32  Phi_U2I2;           /**< 0.1° */
    SINT32  Phi_U3I3;           /**< 0.1° */
    UINT32  PF_sum;             /**< 0 - 1000 */
    UINT32  PF_L1;              /**< 0 - 1000 */
    UINT32  PF_L2;              /**< 0 - 1000 */
    UINT32  PF_L3;              /**< 0 - 1000 */
    SINT32  P_sum;              /**< W */
    SINT32  P_L1;               /**< W */
    SINT32  P_L2;               /**< W */
    SINT32  P_L3;               /**< W */
    SINT32  Q_sum;              /**< Var */
    SINT32  Q_L1;               /**< Var */
    SINT32  Q_L2;               /**< Var */
    SINT32  Q_L3;               /**< Var */
    UINT32  S_sum;              /**< VA */
    UINT32  S_L1;               /**< VA */
    UINT32  S_L2;               /**< VA */
    UINT32  S_L3;               /**< VA */
    UINT32  Asym_U;             /**< only in mode GMP_M_4WIRE3PHASEASYM */
    UINT32  Asym_I;             /**< only in mode GMP_M_4WIRE3PHASEASYM */
    UINT32  RotDir_U;           /**< ROTATION_CW, ROTATION_CCW, ROTATION_UNKNOWN */
    UINT32  RotDir_I;           /**< ROTATION_CW, ROTATION_CCW, ROTATION_UNKNOWN */
    SINT32  ROCOF;              /**< Rate of change of frequency in 0.01 Hz/Second */
    UINT32  Overload_U;         /**< Bitfield Bit 0 Overload U1, Bit 1 Overload U2, Bit 2 Overload U3 */
    UINT32  Overload_I;         /**< Bitfield Bit 0 Overload I1, Bit 1 Overload I2, Bit 2 Overload I3 */
    SINT32  VectorJmp;          /**< Vector Jump in 0.1° */
} GMP_VALUES;

/**
 * Structure for DoCmd-function MIO_CMD_GETPHASEANGLES
 */
typedef struct
{
    SINT32  Phi_U1U2;           /**< in 0.01° */
    SINT32  Phi_U2U3;           /**< in 0.01° */
    SINT32  Phi_U3U1;           /**< in 0.01° */
    SINT32  Phi_U1I1;           /**< in 0.01° */
    SINT32  Phi_U2I2;           /**< in 0.01° */
    SINT32  Phi_U3I3;           /**< in 0.01° */
    SINT32  Phi_UL12L23;        /**< in 0.01° */
    SINT32  Phi_UL23L31;        /**< in 0.01° */
    SINT32  Phi_UL31L12;        /**< in 0.01° */
} GMP_PHASEANGLES;

/**
 * Structure for DoCmd-function MIO_CMD_GETHIGHRESANGLES
 */
typedef struct
{
    SINT32  AbsPhaseU1;         /**< in 0.001° (always 0) */
    SINT32  AbsPhaseU2;         /**< in 0.001° */
    SINT32  AbsPhaseU3;         /**< in 0.001° */
    SINT32  AbsPhaseI1;         /**< in 0.001° */
    SINT32  AbsPhaseI2;         /**< in 0.001° */
    SINT32  AbsPhaseI3;         /**< in 0.001° */
} GMP_HIGHRESANGLES;

/**
 * Structure for DoCmd-function MIO_CMD_GETVECTORDIAGRAM
 */
typedef struct
{
    UINT32  Mode;               /**< One of the GMP_M_... constants */
    UINT32  f;                  /**< Frequency */
    UINT32  U_L1;               /**< mV */
    UINT32  U_L2;               /**< mV */
    UINT32  U_L3;               /**< mV */
    UINT32  U_L1L2;             /**< mV */
    UINT32  U_L2L3;             /**< mV */
    UINT32  U_L3L1;             /**< mV */
    UINT32  I_L1;               /**< mA */
    UINT32  I_L2;               /**< mA */
    UINT32  I_L3;               /**< mA */
    SINT32  Phi_U1;             /**< 0.01° */
    SINT32  Phi_U2U1;           /**< 0.01° */
    SINT32  Phi_U3U1;           /**< 0.01° */
    SINT32  Phi_I1U1;           /**< 0.01° */
    SINT32  Phi_I2U1;           /**< 0.01° */
    SINT32  Phi_I3U1;           /**< 0.01° */
    SINT32  P_sum;              /**< W */
    UINT32  S_sum;              /**< VA */
    SINT32  Q_sum;              /**< VAR */
    UINT32  Overload_U;         /**< Bitfield Bit 0 Overload U1, Bit 1 Overload U2, Bit 2 Overload U3 */
    UINT32  Overload_I;         /**< Bitfield Bit 0 Overload I1, Bit 1 Overload I2, Bit 2 Overload I3 */
} GMP_VECTORDIAGRAM;

/**
 * Structure for DoCmd-function MIO_CMD_GETSWITCHCOUNT
 */
typedef struct
{
    UINT32  Relay1;
    UINT32  Relay2;
} GMP_SWITCHCOUNT;


/**
 * @name Constants used in GMP_QULIMIT.Mode
 * @{
 */

#define GMP_QUMODE_REACTIVEPOWERTHRESHOLD   0    /**< Reactive power threshold */
#define GMP_QUMODE_ANGLE                    1    /**< Angle */
/** @} */
/**
 * Structure for DoCmd-function MIO_CMD_SETQULIMIT / MIO_CMD_GETQULIMIT
 * Simulation Data
 */
typedef struct
{
    BOOL32  Enabled;            /**< En-/Disable limit monitoring */
    UINT32  Mode;               /**< GMP_QUMODE_REACTIVEPOWERTHRESHOLD / GMP_QUMODE_ANGLE */
    UINT32  I_Min;              /**< Minimum current [0.1%] */
    UINT32  U_Min;              /**< Minimum voltage [0.1%] */
    UINT32  I_Fallback;         /**< Current fallback [0.1%] */
    UINT32  U_Fallback;         /**< Voltage fallback [0.1%] */
    UINT32  Phi;                /**< [0.1°] */
    UINT32  Q_Min;              /**< [0.1%] */
    UINT32  DelayGeneratorProtection;    /**< [ms] */
    UINT32  AlarmGeneratorProtection;    /**< 0, 1, 2 */
    UINT32  DelayPCCProtection; /**< [ms] */
    UINT32  AlarmPCCProtection; /**< 0, 1, 2 */
} GMP_QULIMIT;

/**
 * Structure for DoCmd-function MIO_CMD_GETIECVALUES
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  U_L1N_rms;          /**< Voltage phase 1 [mV] */
    UINT32  U_L2N_rms;          /**< Voltage phase 2 [mV] */
    UINT32  U_L3N_rms;          /**< Voltage phase 3 [mV] */
    UINT32  I_L1_rms;           /**< Current phase 1 [mA] */
    UINT32  I_L2_rms;           /**< Current phase 2 [mA] */
    UINT32  I_L3_rms;           /**< Current phase 3 [mA] */
    SINT32  P_sum;              /**< Total real power [W] */
    UINT32  S_sum;              /**< Total complex power [VA] */
    SINT32  Q_sum;              /**< Total reactive power [var] */
} GMP_IECVALUES;

/**
 * Structure for DoCmd-function MIO_CMD_SETSAMPLECFG / MIO_CMD_GETSAMPLECFG
 * @since V1.03 Release
 */
typedef struct
{
    UINT32  SampleRate;         /**< Sample rate */
    UINT32  PAvgLen;            /**< Averaging length of P */
    UINT32  MeanValue;          /**< Value, for which to calculate the mean */
} GMP_SAMPLECFG;

/**
 * Structure for DoCmd-function MIO_CMD_GETSAMPLES
 * @since V1.03 Release
 */
typedef struct
{
    UINT64  Timestamp;          /**< Timestamp of the sample */
    SINT32  U1N;                /**< U1N [mV] Voltage phase 1 to neutral wire */
    SINT32  U2N;                /**< U2N [mV] Voltage phase 2 to neutral wire */
    SINT32  U3N;                /**< U3N [mV] Voltage phase 3 to neutral wire */
    SINT32  I1;                 /**< I1  [mA] Current phase 1 */
    SINT32  I2;                 /**< I2  [mA] Current phase 2 */
    SINT32  I3;                 /**< I3  [mA] Current phase 3 */
    SINT32  W;                  /**< P   [W]  Real power */
} GMP_SAMPLEVAL;

/**
 * Structure for DoCmd-function MIO_CMD_GETSAMPLES
 * @since V1.03 Release
 */
typedef struct
{
    UINT32  StartIdx;           /**< Index to start reading samples from */
    UINT32  MaxSamples;         /**< Number of samples to be read */
} GMP_SAMPLEREQ;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
