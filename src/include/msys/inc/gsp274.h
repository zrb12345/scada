/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     gsp274.h
* @author   Holl
* @brief    MIO-Gegenstueck zu drv/gsp274/gsp274_dpm.h
*           Die hier enthaltenen Strukturen werden vom Anwender verwendet und vor
*           der weitergabe an die Hardware auf die entsprechenden Strukturen aus
*           gsp274_dpm.h umkopiert.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef GSP274__H
#define GSP274__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @addtogroup GSP274_DEF
 * @{
 */
#define GSP_ER_CFG_OK                       0x00000000   /**< No error while parsing the parameter file */
#define GSP_ER_CFG_FILEMISS                 0x00000001   /**< Parameter file missing */
#define GSP_ER_CFG_WRONGSYNC                0x00000002   /**< Wrong synchronisation configuration */
#define GSP_ER_CFG_NSPCHANGE                0x00000004   /**< NSP configuration changed (set with active RunThrough mode) */
#define GSP_M_OPEN                          0    /**< open */
#define GSP_M_2WIRE1PHASE                   1    /**< 2 wire 1 phase */
#define GSP_M_2WIRE2PHASE                   2    /**< 2 wire 2 phase */
#define GSP_M_3WIRE2PHASE                   3    /**< 3 wire 2 phase */
#define GSP_M_3WIRE3PHASE                   4    /**< 3 wire 3 phase */
#define GSP_M_4WIRE3PHASELL                 5    /**< 4 wire 3 phase (phase phase) */
#define GSP_M_4WIRE3PHASELN                 6    /**< 4 wire 3 phase (phase neutral) */
#define GSP_M_EQUALLYLOADED                 1    /**< equal load */
#define GSP_M_ARON                          2    /**< aron */
#define GSP_M_UNBALANCEDLOADED              3    /**< unbalanced load */
#define GSP_M_DISABLED                      0    /**< Disabled */
#define GSP_M_MEASURE                       1    /**< Measure */
#define GSP_M_CALCULATE                     2    /**< Calculate */
#define GSP_M_DO_PULSE                      0    /**< Pulse */
#define GSP_M_DO_CONTINUOUS                 1    /**< Continuous */
#define GSP_M_DO_PULSE_CONTINUOUS           2    /**< Pulse/Continuous (requires package version >= 1.04R) */
#define GSP_M_DI_FEEDBACK                   1    /**< Feedback */
#define GSP_M_DI_MANUALSYNC                 2    /**< Manual sync */
#define GSP_M_DI_BREAK                      3    /**< Break */
#define GSP_ER_U_MIN                        0x8000   /**< Error limit minimum voltage */
#define GSP_ER_U_MAX                        0x0000   /**< Error limit maximum voltage */
#define GSP_EV_U_MIN                        0x8001   /**< Event limit minimum voltage */
#define GSP_EV_U_MAX                        0x0001   /**< Event limit maximum voltage */
#define GSP_ER_I_MAX                        0x0002   /**< Event limit maximum current */
#define GSP_ER_THD_MAX                      0x0003   /**< Error limit maximum Total Harmonic Distortion (only GEN) */
#define GSP_ER_TDD_MAX                      0x0004   /**< Error limit maximum Total Demand Distortion (only GEN) */
#define GSP_ER_ASYM_U_MAX                   0x0005   /**< Error limit asymmetric voltage */
#define GSP_ER_ASYM_I_MAX                   0x0006   /**< Error limit asymmetric current */
#define GSP_ER_ROCOF_MAX                    0x0007   /**< Error limit maximum ROCOF */
#define GSP_EV_I_MAX                        0x0008   /**< Event limit maximum current */
#define GSP_SYNC_STOP                       0x0000   /**< Stop the synchronization */
#define GSP_SYNC_START                      0x0001   /**< Start the synchronization */
#define GSP_GEN                             0x0000   /**< Measuring point GEN */
#define GSP_BUS                             0x0001   /**< Measuring point BUS */
#define GSP_MAINS                           0x0002   /**< Measuring point MAINS */
#define GSP_NP                              0x0003   /**< Measuring point NP */
#define GSP_SCOPE_MODULE                    0x0010   /**< Scope Id Module */
#define GSP_SCOPE_SYNC1                     0x0020   /**< Scope Id Sync1 */
#define GSP_SCOPE_SYNC2                     0x0040   /**< Scope Id Sync2 */
#define GSP_ALARM_CB1                       0x0100   /**< Relay group 1 */
#define GSP_ALARM_CB2                       0x0200   /**< Relay group 2 */
#define GSP_DI_GROUP1                       0x0400   /**< DI channel group 1 */
#define GSP_DI_GROUP2                       0x0800   /**< DI channel group 2 */
#define GSP_SYNC_UNIT1                      0x1000   /**< Synchronization unit 1 */
#define GSP_SYNC_UNIT2                      0x2000   /**< Synchronization unit 2 */
#define GSP_SYNC_STATE_NOSYNC               1    /**< Switch open */
#define GSP_SYNC_STATE_DONE                 2    /**< Switch closed */
#define GSP_SYNC_STATE_BUSY                 4    /**< Sync in progress */
#define GSP_SYNC_STATE_ABORTED              8    /**< Sync aborted */
#define GSP_STATE_CONFIG                    0x0  /**< Configuration mode */
#define GSP_STATE_RUN                       0x1  /**< Run in configured setup */
#define GSP_STATE_FORCERELAY                0x2  /**< Relay simulation mode */
#define GSP_STATE_SIMULATION                0x4  /**< Simulation mode */
#define GSP_STATE_MEASURING                 0x8000   /**< Always together with one of the above values */
#define GSP_F_IN                            0x0  /**< Inner frequency limit */
#define GSP_F_MID                           0x1  /**< Middle frequency limit */
#define GSP_F_OUT                           0x2  /**< Outer frequency limit */
#define ROTATION_CW                         0x0000   /**< Rotation clockwise */
#define ROTATION_CCW                        0x0001   /**< Rotation counterclockwise */
#define ROTATION_UNKNOWN                    0xFFFF   /**< Rotation unknown */
#define GSP_SCOPE_STATE_NOTTRIGGERED        0x0  /**< Not triggered */
#define GSP_SCOPE_STATE_RUNNING             0x1  /**< Obsolete */
#define GSP_SCOPE_STATE_TRIGGERED           0x2  /**< Obsolete */
#define GSP_SCOPE_STATE_READY               0x4  /**< Ready */
#define GSP_SCOPE_STATE_LOCKED              0x8  /**< Locked */
#define GSP_SCOPE_STATE_RECORDING           0x10     /**< Recording */
#define GSP_SCOPE_STATE_NEWDATA             0x20     /**< New data available */
#define GSP_SCOPE_MAXCHAN                   16   /**< Number of the maximum scope channel */
#define GSP_SCOPE_MAXSAMPLES                16   /**< Number of the maximum scope sample */
#define GSP_SCOPE_VALCNT                    40960    /**< Number of the maximum scope values */
#define GSP_SCOPE_MAXVALIDX                 (GSP_SCOPE_VALCNT - GSP_SCOPE_MAXSAMPLES)    /**< Number of the maximum valid scope values */
#define GSP_SCOPE_TE_ERROR                  0x8000   /**< Alarm entry of type ERROR */
#define GSP_SCOPE_TE_EVENT                  0x4000   /**< Alarm entry of type WARNING */
#define GSP_SCOPE_TE_INFO                   0x2000   /**< Alarm entry of type INFO */
#define GSP_SCOPE_TE_APPEAR                 0x0100   /**< Alarm entry appeared or disappeared */
#define GSP_SCOPE_TE_ER_GEN_U_L1_MIN        0x0000   /**< GEN U-L12 lower limit */
#define GSP_SCOPE_TE_ER_GEN_U_L1_MAX        0x0001   /**< GEN U-L12 upper limit */
#define GSP_SCOPE_TE_ER_GEN_U_L2_MIN        0x0002   /**< GEN U-L23 lower limit */
#define GSP_SCOPE_TE_ER_GEN_U_L2_MAX        0x0003   /**< GEN U-L23 upper limit */
#define GSP_SCOPE_TE_ER_GEN_U_L3_MIN        0x0004   /**< GEN U-L31 lower limit */
#define GSP_SCOPE_TE_ER_GEN_U_L3_MAX        0x0005   /**< GEN U-L31 upper limit */
#define GSP_SCOPE_TE_ER_GEN_I_L1_MAX        0x0006   /**< GEN I-L1 upper limit */
#define GSP_SCOPE_TE_ER_GEN_I_L2_MAX        0x0007   /**< GEN I-L2 upper limit */
#define GSP_SCOPE_TE_ER_GEN_I_L3_MAX        0x0008   /**< GEN I-L3 upper limit */
#define GSP_SCOPE_TE_ER_GEN_THD_U_L1        0x0009   /**< GEN THD U-L12 */
#define GSP_SCOPE_TE_ER_GEN_THD_U_L2        0x000a   /**< GEN THD U-L23 */
#define GSP_SCOPE_TE_ER_GEN_THD_U_L3        0x000b   /**< GEN THD U-L31 */
#define GSP_SCOPE_TE_ER_GEN_TDD_I_L1        0x000c   /**< GEN TDD I-L1 */
#define GSP_SCOPE_TE_ER_GEN_TDD_I_L2        0x000d   /**< GEN TDD I-L2 */
#define GSP_SCOPE_TE_ER_GEN_TDD_I_L3        0x000e   /**< GEN TDD I-L3 */
#define GSP_SCOPE_TE_ER_GEN_ASYM_U          0x000f   /**< GEN voltage asymmetry */
#define GSP_SCOPE_TE_ER_GEN_ASYM_I          0x0010   /**< GEN current asymmetry */
#define GSP_SCOPE_TE_ER_GEN_F_IN_MIN        0x0011   /**< GEN inner frequency lower limit */
#define GSP_SCOPE_TE_ER_GEN_F_IN_MAX        0x0012   /**< GEN inner frequency upper limit */
#define GSP_SCOPE_TE_ER_GEN_F_MID_MIN       0x0013   /**< GEN middle frequency Lower limit */
#define GSP_SCOPE_TE_ER_GEN_F_MID_MAX       0x0014   /**< GEN middle frequency upper limit */
#define GSP_SCOPE_TE_ER_GEN_F_OUT_MIN       0x0015   /**< GEN outer frequency lower limit */
#define GSP_SCOPE_TE_ER_GEN_F_OUT_MAX       0x0016   /**< GEN outer frequency upper limit */
#define GSP_SCOPE_TE_ER_GEN_VECTORJMP       0x0017   /**< GEN vectorjump */
#define GSP_SCOPE_TE_ER_GEN_ROCOF           0x0018   /**< GEN ROCOF */
#define GSP_SCOPE_TE_ER_MAINS_FRT_U_L1      0x0019   /**< MAINS FRT U-L12 */
#define GSP_SCOPE_TE_ER_MAINS_FRT_U_L2      0x001a   /**< MAINS FRT U-L23 */
#define GSP_SCOPE_TE_ER_MAINS_FRT_U_L3      0x001b   /**< MAINS FRT U-L31 */
#define GSP_SCOPE_TE_ER_BUS_U_L1_MIN        0x0020   /**< BUS U-L12 lower limit */
#define GSP_SCOPE_TE_ER_BUS_U_L1_MAX        0x0021   /**< BUS U-L12 upper limit */
#define GSP_SCOPE_TE_ER_BUS_F_IN_MIN        0x0027   /**< BUS inner frequency lower limit */
#define GSP_SCOPE_TE_ER_BUS_F_IN_MAX        0x0028   /**< BUS inner frequency upper limit */
#define GSP_SCOPE_TE_ER_BUS_F_MID_MIN       0x0029   /**< BUS middle frequency lower limit */
#define GSP_SCOPE_TE_ER_BUS_F_MID_MAX       0x002a   /**< BUS middle frequency upper limit */
#define GSP_SCOPE_TE_ER_BUS_F_OUT_MIN       0x002b   /**< BUS outer frequency lower limit */
#define GSP_SCOPE_TE_ER_BUS_F_OUT_MAX       0x002c   /**< BUS outer frequency upper limit */
#define GSP_SCOPE_TE_ER_BUS_ROCOF           0x002d   /**< BUS ROCOF */
#define GSP_SCOPE_TE_ER_MAINS_U_L1_MIN      0x0030   /**< MAINS U-L12 lower limit */
#define GSP_SCOPE_TE_ER_MAINS_U_L1_MAX      0x0031   /**< MAINS U-L12 upper limit */
#define GSP_SCOPE_TE_ER_MAINS_U_L2_MIN      0x0032   /**< MAINS U-L23 lower limit */
#define GSP_SCOPE_TE_ER_MAINS_U_L2_MAX      0x0033   /**< MAINS U-L23 upper limit */
#define GSP_SCOPE_TE_ER_MAINS_U_L3_MIN      0x0034   /**< MAINS U-L31 lower limit */
#define GSP_SCOPE_TE_ER_MAINS_U_L3_MAX      0x0035   /**< MAINS U-L31 upper limit */
#define GSP_SCOPE_TE_ER_MAINS_U_ASYM        0x0036   /**< MAINS voltage asymmetry */
#define GSP_SCOPE_TE_ER_MAINS_F_IN_MIN      0x0037   /**< MAINS inner frequency lower limit */
#define GSP_SCOPE_TE_ER_MAINS_F_IN_MAX      0x0038   /**< MAINS inner frequency upper limit */
#define GSP_SCOPE_TE_ER_MAINS_F_MID_MIN     0x0039   /**< MAINS middle frequency lower limit */
#define GSP_SCOPE_TE_ER_MAINS_F_MID_MAX     0x003a   /**< MAINS middle frequency upper limit */
#define GSP_SCOPE_TE_ER_MAINS_F_OUT_MIN     0x003b   /**< MAINS outer frequency lower limit */
#define GSP_SCOPE_TE_ER_MAINS_F_OUT_MAX     0x003c   /**< MAINS outer frequency upper limit */
#define GSP_SCOPE_TE_ER_MAINS_ROCOF         0x003d   /**< MAINS ROCOF */
#define GSP_SCOPE_TE_ER_NP_I_L1_MAX         0x003f   /**< NP I-L1 upper limit */
#define GSP_SCOPE_TE_EV_GEN_U_L1_MIN        0x0000   /**< GEN U-L12 lower limit */
#define GSP_SCOPE_TE_EV_GEN_U_L1_MAX        0x0001   /**< GEN U-L12 upper limit */
#define GSP_SCOPE_TE_EV_GEN_U_L2_MIN        0x0002   /**< GEN U-L23 lower limit */
#define GSP_SCOPE_TE_EV_GEN_U_L2_MAX        0x0003   /**< GEN U-L23 upper limit */
#define GSP_SCOPE_TE_EV_GEN_U_L3_MIN        0x0004   /**< GEN U-L31 lower limit */
#define GSP_SCOPE_TE_EV_GEN_U_L3_MAX        0x0005   /**< GEN U-L31 upper limit */
#define GSP_SCOPE_TE_EV_GEN_I_L1_MAX        0x0006   /**< GEN I-L1 upper limit */
#define GSP_SCOPE_TE_EV_GEN_I_L2_MAX        0x0007   /**< GEN I-L2 upper limit */
#define GSP_SCOPE_TE_EV_GEN_I_L3_MAX        0x0008   /**< GEN I-L3 upper limit */
#define GSP_SCOPE_TE_EV_GEN_HARMONICS_U_L1  0x0009   /**< GEN harmonics U-L12 */
#define GSP_SCOPE_TE_EV_GEN_HARMONICS_U_L2  0x000a   /**< GEN harmonics U-L23 */
#define GSP_SCOPE_TE_EV_GEN_HARMONICS_U_L3  0x000b   /**< GEN harmonics U-L31 */
#define GSP_SCOPE_TE_EV_GEN_HARMONICS_I_L1  0x000c   /**< GEN harmonics I-L1 */
#define GSP_SCOPE_TE_EV_GEN_HARMONICS_I_L2  0x000d   /**< GEN harmonics I-L2 */
#define GSP_SCOPE_TE_EV_GEN_HARMONICS_I_L3  0x000e   /**< GEN harmonics I-L3 */
#define GSP_SCOPE_TE_EV_BUS_U_L1_MIN        0x0010   /**< BUS U-L12 lower limit */
#define GSP_SCOPE_TE_EV_BUS_U_L1_MAX        0x0011   /**< BUS U-L12 upper limit */
#define GSP_SCOPE_TE_EV_MAINS_U_L1_MIN      0x0016   /**< MAINS U-L12 lower limit */
#define GSP_SCOPE_TE_EV_MAINS_U_L1_MAX      0x0017   /**< MAINS U-L12 upper limit */
#define GSP_SCOPE_TE_EV_MAINS_U_L2_MIN      0x0018   /**< MAINS U-L23 lower limit */
#define GSP_SCOPE_TE_EV_MAINS_U_L2_MAX      0x0019   /**< MAINS U-L23 upper limit */
#define GSP_SCOPE_TE_EV_MAINS_U_L3_MIN      0x001a   /**< MAINS U-L31 lower limit */
#define GSP_SCOPE_TE_EV_MAINS_U_L3_MAX      0x001b   /**< MAINS U-L31 upper limit */
#define GSP_SCOPE_TE_EV_NP_I_L1_MAX         0x001f   /**< NP I-L1 upper limit */
#define GSP_SCOPE_SAMPLE_100US              0    /**< Sample rate 100 us */
#define GSP_SCOPE_SAMPLE_200US              1    /**< Sample rate 200 us */
#define GSP_SCOPE_SAMPLE_400US              2    /**< Sample rate 400 us */
#define GSP_SCOPE_SAMPLE_800US              3    /**< Sample rate 800 us */
#define GSP_SCOPE_SAMPLE_1600US             4    /**< Sample rate 1600 us */
#define GSP_SCOPE_1_GEN_U_L1N_SAMPLES       0x0000000000000001LL     /**< Voltage phase 1 */
#define GSP_SCOPE_1_GEN_U_L2N_SAMPLES       0x0000000000000002LL     /**< Voltage phase 2 */
#define GSP_SCOPE_1_GEN_U_L3N_SAMPLES       0x0000000000000004LL     /**< Voltage phase 1 */
#define GSP_SCOPE_1_GEN_U_L1L2_SAMPLES      0x0000000000000008LL     /**< Voltage phase 1 and phase 2 */
#define GSP_SCOPE_1_GEN_U_L2L3_SAMPLES      0x0000000000000010LL     /**< Voltage phase 2 and phase 3 */
#define GSP_SCOPE_1_GEN_U_L3L1_SAMPLES      0x0000000000000020LL     /**< Voltage phase 3 and phase 1 */
#define GSP_SCOPE_1_GEN_I_L1_SAMPLES        0x0000000000000040LL     /**< Current phase 1 */
#define GSP_SCOPE_1_GEN_I_L2_SAMPLES        0x0000000000000080LL     /**< Current phase 2 */
#define GSP_SCOPE_1_GEN_I_L3_SAMPLES        0x0000000000000100LL     /**< Current phase 3 */
#define GSP_SCOPE_1_GEN_I_N_SAMPLES         0x0000000000000200LL     /**< Current neutral */
#define GSP_SCOPE_1_GEN_U_L1N_RMS           0x0000000000000400LL     /**< Voltage phase 1 (RMS) */
#define GSP_SCOPE_1_GEN_U_L2N_RMS           0x0000000000000800LL     /**< Voltage phase 2 (RMS) */
#define GSP_SCOPE_1_GEN_U_L3N_RMS           0x0000000000001000LL     /**< Voltage phase 1 (RMS) */
#define GSP_SCOPE_1_GEN_U_L1L2_RMS          0x0000000000002000LL     /**< Voltage phase 1 and phase 2 (RMS) */
#define GSP_SCOPE_1_GEN_U_L2L3_RMS          0x0000000000004000LL     /**< Voltage phase 2 and phase 3 (RMS) */
#define GSP_SCOPE_1_GEN_U_L3L1_RMS          0x0000000000008000LL     /**< Voltage phase 3 and phase 1 (RMS) */
#define GSP_SCOPE_1_GEN_I_L1_RMS            0x0000000000010000LL     /**< Current phase 1 (RMS) */
#define GSP_SCOPE_1_GEN_I_L2_RMS            0x0000000000020000LL     /**< Current phase 2 (RMS) */
#define GSP_SCOPE_1_GEN_I_L3_RMS            0x0000000000040000LL     /**< Current phase 3 (RMS) */
#define GSP_SCOPE_1_GEN_I_N_RMS             0x0000000000080000LL     /**< Current neutral (RMS) */
#define GSP_SCOPE_1_GEN_P_SUM               0x0000000000100000LL     /**< Total real power */
#define GSP_SCOPE_1_GEN_P_L1                0x0000000000200000LL     /**< Real power phase 1 */
#define GSP_SCOPE_1_GEN_P_L2                0x0000000000400000LL     /**< Real power phase 2 */
#define GSP_SCOPE_1_GEN_P_L3                0x0000000000800000LL     /**< Real power phase 3 */
#define GSP_SCOPE_1_GEN_S_SUM               0x0000000001000000LL     /**< Total complex Power */
#define GSP_SCOPE_1_GEN_S_L1                0x0000000002000000LL     /**< Real complex power phase 1 */
#define GSP_SCOPE_1_GEN_S_L2                0x0000000004000000LL     /**< Real complex power phase 2 */
#define GSP_SCOPE_1_GEN_S_L3                0x0000000008000000LL     /**< Real complex power phase 3 */
#define GSP_SCOPE_1_GEN_Q_SUM               0x0000000010000000LL     /**< Total reactive power */
#define GSP_SCOPE_1_GEN_Q_L1                0x0000000020000000LL     /**< Real reactive power phase 1 */
#define GSP_SCOPE_1_GEN_Q_L2                0x0000000040000000LL     /**< Real reactive power phase 2 */
#define GSP_SCOPE_1_GEN_Q_L3                0x0000000080000000LL     /**< Real reactive power phase 3 */
#define GSP_SCOPE_1_GEN_U_L1_IEC            0x0000000100000000LL     /**< U1 IEC */
#define GSP_SCOPE_1_GEN_U_L2_IEC            0x0000000200000000LL     /**< U2 IEC */
#define GSP_SCOPE_1_GEN_U_L3_IEC            0x0000000400000000LL     /**< U3 IEC */
#define GSP_SCOPE_1_GEN_I_L1_IEC            0x0000000800000000LL     /**< I1 IEC */
#define GSP_SCOPE_1_GEN_I_L2_IEC            0x0000001000000000LL     /**< I2 IEC */
#define GSP_SCOPE_1_GEN_I_L3_IEC            0x0000002000000000LL     /**< I3 IEC */
#define GSP_SCOPE_1_GEN_P_IEC               0x0000004000000000LL     /**< P IEC */
#define GSP_SCOPE_1_GEN_S_IEC               0x0000008000000000LL     /**< S IEC */
#define GSP_SCOPE_1_GEN_Q_IEC               0x0000010000000000LL     /**< Q IEC */
#define GSP_SCOPE_1_GEN_F                   0x0000020000000000LL     /**< Frequency */
#define GSP_SCOPE_1_GEN_ROCOF               0x0000040000000000LL     /**< Rate of change of frequency */
#define GSP_SCOPE_1_GEN_ASYM_U              0x0000080000000000LL     /**< Voltage asymmetric */
#define GSP_SCOPE_1_GEN_ASYM_I              0x0000100000000000LL     /**< Current asymmetric */
#define GSP_SCOPE_1_GEN_PHI_U1I1            0x0000200000000000LL     /**< Phase angle from U1 and I1 */
#define GSP_SCOPE_1_GEN_PHI_U2I2            0x0000400000000000LL     /**< Phase angle from U2 and I2 */
#define GSP_SCOPE_1_GEN_PHI_U3I3            0x0000800000000000LL     /**< Phase angle from U3 and I3 */
#define GSP_SCOPE_1_BUS_U_SAMPLES           0x0001000000000000LL     /**< Voltage phase 1 (samples) */
#define GSP_SCOPE_1_BUS_U_RMS               0x0002000000000000LL     /**< Voltage phase 1 (RMS) */
#define GSP_SCOPE_1_BUS_F                   0x0004000000000000LL     /**< Frequency */
#define GSP_SCOPE_1_BUS_ROCOF               0x0008000000000000LL     /**< Rate Of Change Of Frequency */
#define GSP_SCOPE_1_MAINS_U_L1N_SAMPLES     0x0010000000000000LL     /**< Voltage phase 1 (samples) */
#define GSP_SCOPE_1_MAINS_U_L2N_SAMPLES     0x0020000000000000LL     /**< Voltage phase 2 (samples) */
#define GSP_SCOPE_1_MAINS_U_L3N_SAMPLES     0x0040000000000000LL     /**< Voltage phase 3 (samples) */
#define GSP_SCOPE_1_MAINS_U_L1L2_SAMPLES    0x0080000000000000LL     /**< Voltage phase 1 and phase 2 (samples) */
#define GSP_SCOPE_1_MAINS_U_L2L3_SAMPLES    0x0100000000000000LL     /**< Voltage phase 2 and phase 3 (samples) */
#define GSP_SCOPE_1_MAINS_U_L3L1_SAMPLES    0x0200000000000000LL     /**< Voltage phase 3 and phase 1 (samples) */
#define GSP_SCOPE_1_MAINS_U_L1N_RMS         0x0400000000000000LL     /**< Voltage phase 1 (RMS) */
#define GSP_SCOPE_1_MAINS_U_L2N_RMS         0x0800000000000000LL     /**< Voltage phase 2 (RMS) */
#define GSP_SCOPE_1_MAINS_U_L3N_RMS         0x1000000000000000LL     /**< Voltage phase 1 (RMS) */
#define GSP_SCOPE_1_MAINS_U_L1L2_RMS        0x2000000000000000LL     /**< Voltage phase 1 and phase 2 (RMS) */
#define GSP_SCOPE_1_MAINS_U_L2L3_RMS        0x4000000000000000LL     /**< Voltage phase 2 and phase 3 (RMS) */
#define GSP_SCOPE_1_MAINS_U_L3L1_RMS        0x8000000000000000LL     /**< Voltage phase 3 and phase 1 (RMS) */
#define GSP_SCOPE_2_MAINS_F                 0x0000000000000001LL     /**< Frequency */
#define GSP_SCOPE_2_MAINS_ROCOF             0x0000000000000002LL     /**< Rate Of Change Of Frequency */
#define GSP_SCOPE_2_MAINS_ASYM_U            0x0000000000000004LL     /**< Voltage asymmetric */
#define GSP_SCOPE_2_NP_I_SAMPLES            0x0000000000000008LL     /**< Current phase 1 (samples) */
#define GSP_SCOPE_2_NP_I_RMS                0x0000000000000010LL     /**< Current phase 1 (RMS) */
#define GSP_SCOPE_2_DO1                     0x0000000000000020LL     /**< Digital output (Sync1) */
#define GSP_SCOPE_2_DO2                     0x0000000000000040LL     /**< Digital output (Alarm1) */
#define GSP_SCOPE_2_DO3                     0x0000000000000080LL     /**< Digital output (Sync2) */
#define GSP_SCOPE_2_DO4                     0x0000000000000100LL     /**< Digital output (Alarm2) */
#define GSP_SCOPE_2_DI1                     0x0000000000000200LL     /**< Digital input 1 */
#define GSP_SCOPE_2_DI2                     0x0000000000000400LL     /**< Digital input 2 */
#define GSP_SCOPE_2_DI3                     0x0000000000000800LL     /**< Digital input 3 */
#define GSP_SCOPE_2_DI4                     0x0000000000001000LL     /**< Digital input 4 */
#define GSP_SCOPE_2_SYNC_PHI_1              0x0000000000002000LL     /**< Phi - Sync-Scope 1 only */
#define GSP_SCOPE_2_SYNC_PHI_2              0x0000000000004000LL     /**< Phi - Sync-Scope 2 only */
#define GSP_VAL_U_L1N_RMS                   0x0000000000000400LL     /**< RMS voltage L1N */
#define GSP_VAL_U_L2N_RMS                   0x0000000000000800LL     /**< RMS voltage L2N */
#define GSP_VAL_U_L3N_RMS                   0x0000000000001000LL     /**< RMS voltage L3N */
#define GSP_VAL_U_L1L2_RMS                  0x0000000000002000LL     /**< RMS voltage L1L2 */
#define GSP_VAL_U_L2L3_RMS                  0x0000000000004000LL     /**< RMS voltage L2L3 */
#define GSP_VAL_U_L3L1_RMS                  0x0000000000008000LL     /**< RMS voltage L3L1 */
#define GSP_VAL_I_L1_RMS                    0x0000000000010000LL     /**< RMS current L1 */
#define GSP_VAL_I_L2_RMS                    0x0000000000020000LL     /**< RMS current L2 */
#define GSP_VAL_I_L3_RMS                    0x0000000000040000LL     /**< RMS current L2 */
#define GSP_VAL_I_N_RMS                     0x0000000000080000LL     /**< RMS current Neutral */
#define GSP_VAL_P_SUM                       0x0000000000100000LL     /**< Active power P_SUM */
#define GSP_VAL_P_L1                        0x0000000000200000LL     /**< Active power P_L1 */
#define GSP_VAL_P_L2                        0x0000000000400000LL     /**< Active power P_L2 */
#define GSP_VAL_P_L3                        0x0000000000800000LL     /**< Active power P_L3 */
#define GSP_VAL_S_SUM                       0x0000000001000000LL     /**< Reactive power S_SUM */
#define GSP_VAL_S_L1                        0x0000000002000000LL     /**< Reactive power S_L1 */
#define GSP_VAL_S_L2                        0x0000000004000000LL     /**< Reactive power S_L2 */
#define GSP_VAL_S_L3                        0x0000000008000000LL     /**< Reactive power S_L3 */
#define GSP_VAL_Q_SUM                       0x0000000010000000LL     /**< Apparent power Q_SUM */
#define GSP_VAL_Q_L1                        0x0000000020000000LL     /**< Apparent power Q_L1 */
#define GSP_VAL_Q_L2                        0x0000000040000000LL     /**< Apparent power Q_L2 */
#define GSP_VAL_Q_L3                        0x0000000080000000LL     /**< Apparent power Q_L3 */
#define GSP_VAL_FREQUENCY                   0x0000000100000000LL     /**< Frequency */
#define GSP_VAL_ROCOF                       0x0000000200000000LL     /**< Rate of change of frequency */
#define GSP_VAL_ASYM_U                      0x0000000400000000LL     /**< Asymmetric voltage */
#define GSP_VAL_ASYM_I                      0x0000000800000000LL     /**< Asymmetric current */
#define GSP_VAL_I_RMS                       0x0000008000000000LL     /**< RMS current of the neutral point */
#define GSP_VAL_PHI_U1I1                    0x0008000000000000LL     /**< Phase angle between U1 and I1 */
#define GSP_VAL_PHI_U2I2                    0x0010000000000000LL     /**< Phase angle between U2 and I2 */
#define GSP_VAL_PHI_U3I3                    0x0020000000000000LL     /**< Phase angle between U3 and I3 */
#define GSP_VAL_PF_SUM                      0x0040000000000000LL     /**< Power factor sum */
#define GSP_VAL_PF_L1                       0x0080000000000000LL     /**< Power factor L1 */
#define GSP_VAL_PF_L2                       0x0100000000000000LL     /**< Power factor L2 */
#define GSP_VAL_PF_L3                       0x0200000000000000LL     /**< Power factor L3 */
#define GSP_VAL_ROTDIR_U                    0x0400000000000000LL     /**< Rotation direction voltage */
#define GSP_VAL_ROTDIR_I                    0x0800000000000000LL     /**< Rotation direction current */
#define GSP_VAL_OVERLOAD_U                  0x1000000000000000LL     /**< Overload voltage */
#define GSP_VAL_OVERLOAD_I                  0x2000000000000000LL     /**< Overload current */
#define GSP_VAL_VECTORJMP                   0x4000000000000000LL     /**< Vector jump */
#define GSP_VAL_ALL                         -1LL     /**< workaround: asgard does not yet support 0xffffffffffffffffs64 */
#define GSP_INH_ER_GEN_U_MIN                0x00000001   /**< Error Inhibit mask of GEN_U_MIN */
#define GSP_INH_ER_GEN_U_MAX                0x00000002   /**< Error Inhibit mask of GEN_U_MAX */
#define GSP_INH_ER_GEN_I_MAX                0x00000004   /**< Error Inhibit mask of GEN_I_MAX */
#define GSP_INH_ER_GEN_U_THD                0x00000008   /**< Error Inhibit mask of GEN_U_THD */
#define GSP_INH_ER_GEN_I_TDD                0x00000010   /**< Error Inhibit mask of GEN_I_TDD */
#define GSP_INH_ER_GEN_U_ASYM               0x00000020   /**< Error Inhibit mask of GEN_U_ASYM */
#define GSP_INH_ER_GEN_I_ASYM               0x00000040   /**< Error Inhibit mask of GEN_I_ASYM */
#define GSP_INH_ER_GEN_F                    0x00000080   /**< Error Inhibit mask of GEN_F; inhibits ALL frequency limits when used for limit inhibition; when used for sync inhibition (MIO_CMD_G[S]ETSYNCINHIBITCFG) see GSP_INH_ER_GEN_F_IN */
#define GSP_INH_ER_GEN_VECTORJMP            0x00000100   /**< Error Inhibit mask of GEN_VECTORJMP */
#define GSP_INH_ER_GEN_ROCOF                0x00000200   /**< Error Inhibit mask of GEN_FOCOF */
#define GSP_INH_ER_BUS_U_MIN                0x00001000   /**< Error Inhibit mask of BUS_U_MIN */
#define GSP_INH_ER_BUS_U_MAX                0x00002000   /**< Error Inhibit mask of BUS_U_MAX */
#define GSP_INH_ER_BUS_F                    0x00004000   /**< Error Inhibit mask of BUS_F; behaves like GSP_INH_ER_GEN_F when used for limit or sync inhibition */
#define GSP_INH_ER_BUS_ROCOF                0x00008000   /**< Error Inhibit mask of BUS_ROCOF */
#define GSP_INH_ER_MAINS_U_MIN              0x00010000   /**< Error Inhibit mask of MAINS_U_MIN */
#define GSP_INH_ER_MAINS_U_MAX              0x00020000   /**< Error Inhibit mask of MAINS_U_MAX */
#define GSP_INH_ER_MAINS_U_ASYM             0x00040000   /**< Error Inhibit mask of MAINS_U_ASYM */
#define GSP_INH_ER_MAINS_F                  0x00080000   /**< Error Inhibit mask of MAINS_F; behaves like GSP_INH_ER_GEN_F when used for limit or sync inhibition */
#define GSP_INH_ER_MAINS_ROCOF              0x00100000   /**< Error Inhibit mask of MAINS_ROCOF */
#define GSP_INH_ER_NP_I_MAX                 0x01000000   /**< Error Inhibit mask of NP_I_MAX */
#define GSP_INH_ER_GEN_F_IN                 0x00000080   /**< Error Inhibit mask of GEN_F IN; inhibits just GEN F_IN frequency limit (not all frequency limits) when used for sync inhibition (MIO_CMD_G[S]ETSYNCINHIBITCFG); when used for limit inhibition see GSP_INH_ER_GEN_F */
#define GSP_INH_ER_GEN_QU                   0x00000400   /**< Error Inhibit mask of GEN QU (only for MIO_CMD_G[S]ETSYNCINHIBITCFG); cannot be used for limit inhibition */
#define GSP_INH_ER_BUS_F_IN                 0x00004000   /**< Error Inhibit mask of BUS_F IN; behaves like GSP_INH_ER_GEN_F_IN when used for limit or sync inhibition */
#define GSP_INH_ER_MAINS_F_IN               0x00080000   /**< Error Inhibit mask of MAINS_F IN; behaves like GSP_INH_ER_GEN_F_IN when used for limit or sync inhibition */
#define GSP_INH_ER_MAINS_FRT                0x00200000   /**< Error Inhibit mask for MAINS FRT (only for MIO_CMD_G[S]ETSYNCINHIBITCFG); cannot be used for limit inhibition */
#define GSP_INH_ER_MAINS_NSP                0x00400000   /**< Error Inhibit mask for MAINS NSP (only for MIO_CMD_G[S]ETSYNCINHIBITCFG); cannot be used for limit inhibition */
#define GSP_INH_ER_GEN_F_MID                0x02000000   /**< Error Inhibit mask of GEN_F MIN (only for MIO_CMD_G[S]ETSYNCINHIBITCFG); cannot be used for limit inhibition */
#define GSP_INH_ER_GEN_F_OUT                0x04000000   /**< Error Inhibit mask of GEN_F OUT (only for MIO_CMD_G[S]ETSYNCINHIBITCFG); cannot be used for limit inhibition */
#define GSP_INH_ER_BUS_F_MID                0x08000000   /**< Error Inhibit mask of BUS_F MIN (only for MIO_CMD_G[S]ETSYNCINHIBITCFG); cannot be used for limit inhibition */
#define GSP_INH_ER_BUS_F_OUT                0x10000000   /**< Error Inhibit mask of BUS_F OUT (only for MIO_CMD_G[S]ETSYNCINHIBITCFG); cannot be used for limit inhibition */
#define GSP_INH_ER_MAINS_F_MID              0x20000000   /**< Error Inhibit mask of MAINS_F MID (only for MIO_CMD_G[S]ETSYNCINHIBITCFG); cannot be used for limit inhibition */
#define GSP_INH_ER_MAINS_F_OUT              0x40000000   /**< Error Inhibit mask of MAINS_F OUT (only for MIO_CMD_G[S]ETSYNCINHIBITCFG); cannot be used for limit inhibition */
#define GSP_INH_EV_GEN_U_MIN                0x00000001   /**< Event Inhibit mask of GEN_U_MIN */
#define GSP_INH_EV_GEN_U_MAX                0x00000002   /**< Event Inhibit mask of GEN_U_MAX */
#define GSP_INH_EV_GEN_I_MAX                0x00000004   /**< Event Inhibit mask of GEN_I_MAX */
#define GSP_INH_EV_GEN_U_HARMONICS          0x00000008   /**< Event Inhibit mask of GEN_U_HARMONICS */
#define GSP_INH_EV_GEN_I_HARMONICS          0x00000010   /**< Event Inhibit mask of GEN_I_HARMONICS */
#define GSP_INH_EV_BUS_U_MIN                0x00001000   /**< Event Inhibit mask of BUS_U_MIN */
#define GSP_INH_EV_BUS_U_MAX                0x00002000   /**< Event Inhibit mask of BUS_U_MAX */
#define GSP_INH_EV_MAINS_U_MIN              0x00010000   /**< Event Inhibit mask of MAINS_U_MIN */
#define GSP_INH_EV_MAINS_U_MAX              0x00020000   /**< Event Inhibit mask of MAINS_U_MAX */
#define GSP_INH_EV_NP_I_MAX                 0x01000000   /**< Event Inhibit mask of NP_I_MAX */
#define GSP_STATISTICS_GEN_U_L1N_SAMPLES    0    /**< Voltage phase 1 (samples) */
#define GSP_STATISTICS_GEN_U_L2N_SAMPLES    1    /**< Voltage phase 2 (samples) */
#define GSP_STATISTICS_GEN_U_L3N_SAMPLES    2    /**< Voltage phase 3 (samples) */
#define GSP_STATISTICS_GEN_U_L12_SAMPLES    3    /**< Voltage phase 1 and phase 2 (samples) */
#define GSP_STATISTICS_GEN_U_L23_SAMPLES    4    /**< Voltage phase 2 and phase 3 (samples) */
#define GSP_STATISTICS_GEN_U_L31_SAMPLES    5    /**< Voltage phase 3 and phase 1 (samples) */
#define GSP_STATISTICS_GEN_I_L1_SAMPLES     6    /**< Current phase 1 (samples) */
#define GSP_STATISTICS_GEN_I_L2_SAMPLES     7    /**< Current phase 2 (samples) */
#define GSP_STATISTICS_GEN_I_L3_SAMPLES     8    /**< Current phase 3 (samples) */
#define GSP_STATISTICS_GEN_I_N_SAMPLES      9    /**< Current neutral (samples) */
#define GSP_STATISTICS_GEN_U_L1N            10   /**< Voltage phase 1 (RMS) */
#define GSP_STATISTICS_GEN_U_L2N            11   /**< Voltage phase 2 (RMS) */
#define GSP_STATISTICS_GEN_U_L3N            12   /**< Voltage phase 1 (RMS) */
#define GSP_STATISTICS_GEN_U_L12            13   /**< Voltage phase 1 and phase 2 (RMS) */
#define GSP_STATISTICS_GEN_U_L23            14   /**< Voltage phase 2 and phase 3 (RMS) */
#define GSP_STATISTICS_GEN_U_L31            15   /**< Voltage phase 3 and phase 1 (RMS) */
#define GSP_STATISTICS_GEN_I_L1             16   /**< Current phase 1 (RMS) */
#define GSP_STATISTICS_GEN_I_L2             17   /**< Current phase 2 (RMS) */
#define GSP_STATISTICS_GEN_I_L3             18   /**< Current phase 3 (RMS) */
#define GSP_STATISTICS_GEN_I_N              19   /**< Current neutral (RMS) */
#define GSP_STATISTICS_GEN_P_SUM            20   /**< Total real power */
#define GSP_STATISTICS_GEN_P_L1             21   /**< Real power phase 1 */
#define GSP_STATISTICS_GEN_P_L2             22   /**< Real power phase 2 */
#define GSP_STATISTICS_GEN_P_L3             23   /**< Real power phase 3 */
#define GSP_STATISTICS_GEN_S_SUM            24   /**< Total complex power */
#define GSP_STATISTICS_GEN_S_L1             25   /**< Real complex power phase 1 */
#define GSP_STATISTICS_GEN_S_L2             26   /**< Real complex power phase 2 */
#define GSP_STATISTICS_GEN_S_L3             27   /**< Real complex power phase 3 */
#define GSP_STATISTICS_GEN_Q_SUM            28   /**< Total reactive power */
#define GSP_STATISTICS_GEN_Q_L1             29   /**< Real reactive power phase 1 */
#define GSP_STATISTICS_GEN_Q_L2             30   /**< Real reactive power phase 2 */
#define GSP_STATISTICS_GEN_Q_L3             31   /**< Real reactive power phase 3 */
#define GSP_STATISTICS_GEN_U_L1_IEC         32   /**< U1 IEC */
#define GSP_STATISTICS_GEN_U_L2_IEC         33   /**< U2 IEC */
#define GSP_STATISTICS_GEN_U_L3_IEC         34   /**< U3 IEC */
#define GSP_STATISTICS_GEN_I_L1_IEC         35   /**< I1 IEC */
#define GSP_STATISTICS_GEN_I_L2_IEC         36   /**< I2 IEC */
#define GSP_STATISTICS_GEN_I_L3_IEC         37   /**< I3 IEC */
#define GSP_STATISTICS_GEN_P_IEC            38   /**< P IEC */
#define GSP_STATISTICS_GEN_S_IEC            39   /**< S IEC */
#define GSP_STATISTICS_GEN_Q_IEC            40   /**< Q IEC */
#define GSP_STATISTICS_GEN_F                41   /**< Frequency */
#define GSP_STATISTICS_GEN_ROCOF            42   /**< Rate Of Change Of Frequency */
#define GSP_STATISTICS_GEN_THD_U1U12        43   /**< THD U1/U12 */
#define GSP_STATISTICS_GEN_THD_U2U23        44   /**< THD U2/U23 */
#define GSP_STATISTICS_GEN_THD_U3U31        45   /**< THD U3/U31 */
#define GSP_STATISTICS_GEN_TDD_I1           46   /**< TDD I1 */
#define GSP_STATISTICS_GEN_TDD_I2           47   /**< TDD I2 */
#define GSP_STATISTICS_GEN_TDD_I3           48   /**< TDD I3 */
#define GSP_STATISTICS_GEN_ASYM_U           49   /**< Voltage asymmetric */
#define GSP_STATISTICS_GEN_ASYM_I           50   /**< Current asymmetric */
#define GSP_STATISTICS_GEN_PHI_U1I1         51   /**< Phase angle from U1 and I1 */
#define GSP_STATISTICS_GEN_PHI_U2I2         52   /**< Phase angle from U2 and I2 */
#define GSP_STATISTICS_GEN_PHI_U3I3         53   /**< Phase angle from U3 and I3 */
#define GSP_STATISTICS_GEN_VECTORJMP        54   /**< Vector jump */
#define GSP_STATISTICS_BUS_U_L1N_SAMPLES    55   /**< Voltage phase 1 (samples) */
#define GSP_STATISTICS_BUS_U_L1N            56   /**< Voltage phase 1 (RMS) */
#define GSP_STATISTICS_BUS_F                57   /**< Frequency */
#define GSP_STATISTICS_BUS_ROCOF            58   /**< Rate Of Change Of Frequency */
#define GSP_STATISTICS_MAINS_U_L1N_SAMPLES  59   /**< Voltage phase 1 (samples) */
#define GSP_STATISTICS_MAINS_U_L2N_SAMPLES  60   /**< Voltage phase 2 (samples) */
#define GSP_STATISTICS_MAINS_U_L3N_SAMPLES  61   /**< Voltage phase 1 (samples) */
#define GSP_STATISTICS_MAINS_U_L12_SAMPLES  62   /**< Voltage phase 1 and phase 2 (samples) */
#define GSP_STATISTICS_MAINS_U_L23_SAMPLES  63   /**< Voltage phase 2 and phase 3 (samples) */
#define GSP_STATISTICS_MAINS_U_L31_SAMPLES  64   /**< Voltage phase 3 and phase 1 (samples) */
#define GSP_STATISTICS_MAINS_U_L1N          65   /**< Voltage phase 1 (RMS) */
#define GSP_STATISTICS_MAINS_U_L2N          66   /**< Voltage phase 2 (RMS) */
#define GSP_STATISTICS_MAINS_U_L3N          67   /**< Voltage phase 1 (RMS) */
#define GSP_STATISTICS_MAINS_U_L12          68   /**< Voltage phase 1 and phase 2 (RMS) */
#define GSP_STATISTICS_MAINS_U_L23          69   /**< Voltage phase 2 and phase 3 (RMS) */
#define GSP_STATISTICS_MAINS_U_L31          70   /**< Voltage phase 3 and phase 1 (RMS) */
#define GSP_STATISTICS_MAINS_F              71   /**< Frequency */
#define GSP_STATISTICS_MAINS_ROCOF          72   /**< Rate Of Change Of Frequency */
#define GSP_STATISTICS_MAINS_ASYM_U         73   /**< Voltage asymmetric */
#define GSP_STATISTICS_NP_ASYM_I            74   /**< Current asymmetric */
#define GSP_STATISTICS_NP_I_L1              75   /**< Current phase 1 */
#define GSP_MAX_STATISTICS_GEN              55   /**< Number of GSP_STATISTICS_GEN_* constants */
#define GSP_MAX_STATISTICS_BUS              4    /**< Number of GSP_STATISTICS_BUS_* constants */
#define GSP_MAX_STATISTICS_MAINS            15   /**< Number of GSP_STATISTICS_MAINS_* constants */
#define GSP_MAX_STATISTICS_NP               2    /**< Number of GSP_STATISTICS_NP_* constants */
#define GSP_MAX_STATISTICS                  76   /**< Sum of all values */
#define GSP_HARMONICS_U_L1                  0    /**< Harmonics voltage phase 1 */
#define GSP_HARMONICS_U_L2                  1    /**< Harmonics voltage phase 2 */
#define GSP_HARMONICS_U_L3                  2    /**< Harmonics voltage phase 3 */
#define GSP_HARMONICS_I_L1                  3    /**< Harmonics current phase 1 */
#define GSP_HARMONICS_I_L2                  4    /**< Harmonics current phase 2 */
#define GSP_HARMONICS_I_L3                  5    /**< Harmonics current phase 3 */
#define GSP_HARMONICS_U                     0    /**< Voltage harmonics */
#define GSP_HARMONICS_I                     1    /**< Current harmonics */
#define GSP_MAX_HARMONICS                   50   /**< Used in GSP_HARMONICS only! */
#define GSP_MAX_HARMONICSLIMIT              49   /**< Used in GSP_HARMONICSLIMIT only! */
#define GSP_QUMODE_REACTIVEPOWERTHRESHOLD   0    /**< Reactive power threshold */
#define GSP_QUMODE_ANGLE                    1    /**< Angle */
#define GSP_ASYM_REF_POS                    0    /**< Asymmetric counter system to actual positive sequence system */
#define GSP_ASYM_REF_NOMINAL                1    /**< Asymmetric counter system to nominal value */
/** @} */

/**
 * @name Structures
 * @{
 */

/**
 * Base GSP274 configuration, can only be changed during startup.
 * Structure for DoCmd-function MIO_CMD_GETCONFIG
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  VoltageModeGEN;     /**< Voltage mode (GSP_M_XXX) */
    UINT32  CurrentModeGEN;     /**< Current mode (GSP_M_XXX) */
    UINT32  PTSecondaryGEN;     /**< Voltage transformer secondary side, nom. [V] */
    UINT32  CTSecondaryGEN;     /**< Current transformer secondary side, nom. [mA] */
    UINT32  FrequencyGEN;       /**< Frequency [Hz] */
    UINT32  PTPrimaryGEN;       /**< Voltage transformer primary side, nom. [V] */
    UINT32  CTPrimaryGEN;       /**< Current transformer primary side, nom. [A] */
    UINT32  VoltageModeBUS;     /**< Voltage mode */
    UINT32  PTSecondaryBUS;     /**< Voltage transformer secondary side, nom. [V] */
    UINT32  PTPrimaryBUS;       /**< Voltage transformer primary side, nom. [V] */
    UINT32  VoltageModeMAINS;   /**< Voltage mode */
    UINT32  PTSecondaryMAINS;   /**< Voltage transformer secondary side, nom. [V] */
    UINT32  PTPrimaryMAINS;     /**< Voltage transformer primary side, nom. [V] */
    UINT32  NeutralPoint;       /**< NeutralPoint mode (Disabled, Measure, Calculate) */
    UINT32  CTPrimaryNP;        /**< Current transformer primary side, nom. [A] */
    UINT32  CTSecondaryNP;      /**< Current transformer secondary side, nom. [mA] */
    BOOL32  NSProtection;       /**< Network and system protection mode (NSProtection) */
} GSP_CONFIG;

/**
 * Extended base GSP274 configuration, can only be changed during startup.
 * Structure for DoCmd-function MIO_CMD_GETCONFIG_EXT
 * @since V1.04 Release
 */
typedef struct
{
    UINT32  VoltageModeGEN;     /**< Voltage mode (GSP_M_XXX) */
    UINT32  CurrentModeGEN;     /**< Current mode (GSP_M_XXX) */
    UINT32  PTSecondaryGEN;     /**< Voltage transformer secondary side, nom. [V] */
    UINT32  CTSecondaryGEN;     /**< Current transformer secondary side, nom. [mA] */
    UINT32  FrequencyGEN;       /**< Frequency [Hz] */
    UINT32  PTPrimaryGEN;       /**< Voltage transformer primary side, nom. [V] */
    UINT32  CTPrimaryGEN;       /**< Current transformer primary side, nom. [A] */
    UINT32  VoltageModeBUS;     /**< Voltage mode */
    UINT32  PTSecondaryBUS;     /**< Voltage transformer secondary side, nom. [V] */
    UINT32  PTPrimaryBUS;       /**< Voltage transformer primary side, nom. [V] */
    UINT32  VoltageModeMAINS;   /**< Voltage mode */
    UINT32  PTSecondaryMAINS;   /**< Voltage transformer secondary side, nom. [V] */
    UINT32  PTPrimaryMAINS;     /**< Voltage transformer primary side, nom. [V] */
    UINT32  NeutralPoint;       /**< NeutralPoint mode (Disabled, Measure, Calculate) */
    UINT32  CTPrimaryNP;        /**< Current transformer primary side, nom. [A] */
    UINT32  CTSecondaryNP;      /**< Current transformer secondary side, nom. [mA] */
    BOOL32  NSProtection;       /**< Network and system protection mode (NSProtection) */
    BOOL32  IECSignConvention;  /**< Angle calculation based on IEC */
    UINT32  AsymRefModeU_GEN;   /**< Asymmetric counter system reference for voltage (#GSP_ASYM_REF_POS or similar), for package versions >= 1.04R; enum */
    UINT32  AsymRefModeI_GEN;   /**< Asymmetric counter system reference for current (#GSP_ASYM_REF_POS or similar), for package versions >= 1.04R; enum */
    BOOL32  SuppressOffCmdOnFeedbackMismatch;    /**< Suppress Off command on mismatching position feedback, for package versions >= 1.04R */
    UINT32  Spare;              /**< Spare configuration settings, for package versions >= 1.04R */
} GSP_CONFIG_EXT;

/**
 * GSP274 Alarm configuration, can only be changed during startup.
 * Structure for DoCmd-function MIO_CMD_SETALARMCFG / MIO_CMD_GETALARMCFG
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  SyncMode;           /**< Operation mode of sync */
    UINT32  SyncTime;           /**< Pulse length [ms] */
    UINT32  AlarmInv;           /**< Invert alarm */
    UINT32  AlarmTime;          /**< Pulse length [ms] */
    UINT32  AlarmReset;         /**< Auto reset alarm */
} GSP_ALARMCONFIG;

/**
 * GSP274 DI configuration
 * Structure for DoCmd-function MIO_CMD_SETDICFG / MIO_CMD_GETDICFG
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  DI1Mode;            /**< Operation mode of DI */
    UINT32  DI1Polarity;        /**< Polarity of DI */
    UINT32  DI1Delay;           /**< Feedback delay [ms] */
    UINT32  DI2Mode;            /**< Operation mode of DI */
    UINT32  DI2Polarity;        /**< Polarity of DI */
} GSP_DICONFIG;

/**
 * Upper/Lower Limit configuration.
 * Structure for DoCmd-function MIO_CMD_SETLIMITCFG / MIO_CMD_GETLIMITCFG
 * MIO_CMD_SETROCOFLIMIT / MIO_CMD_GETROCOFLIMIT
 * MIO_CMD_SETASYMLIMIT / MIO_CMD_GETASYMLIMIT
 * @since V1.00 Release
 */
typedef struct
{
    BOOL32  Enabled;            /**< En-/Disable limit monitoring */
    UINT32  Value;              /**< Voltage limit. Definition of Input Signal Range */
    UINT32  Hysteresis;         /**< Threshold hysteresis [0.1% (Limits) mHz/s (ROCOF) 0.1% (Asym)] */
    UINT32  Delay;              /**< Minimum time of active limit before alarm [ms] */
    UINT32  Alarm;              /**< Alarm to switch [0,1,2,3] */
    UINT32  Breaker;            /**< Breaker to switch */
    BOOL32  ScopeEnabled;       /**< Scope enabled */
} GSP_LIMIT;

/**
 * Voltage point used in GSP_FRT structure
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  Voltage;            /**< Threshold voltage [0.1%] */
    UINT32  TimeMS;             /**< Time of this threshold [ms] Max:65535 */
} GSP_VOLTAGEPOINT;

#define MAX_FRTVPOINTS  11  /**< Maximum FRT points */
/**
 * Data structure for FRT configuration
 * Structure for DoCmd-function MIO_CMD_SETFRT / MIO_CMD_GETFRT
 * @since V1.00 Release
 */
typedef struct
{
    BOOL32              Enabled;     /**< En-/Disable limit monitoring */
    UINT32              PointCount;  /**< Count of voltage points (max 11) */
    UINT32              InitThreshold;   /**< Initial threshold [0.1% of nominal voltage] */
    UINT32              FallbackVoltage;     /**< Fallback voltage [0.1%] */
    UINT32              FallbackTime;    /**< Fallback time [ms] Max: 65535 */
    GSP_VOLTAGEPOINT    VoltagePoints[MAX_FRTVPOINTS];   /**< FRT Table */
    UINT32              Alarm;  /**< Alarm to switch [0,1,2,3] */
    UINT32              Breaker;     /**< Breaker to switch after event occurred */
    BOOL32              ScopeEnabled;    /**< Scope enabled */
} GSP_FRT;

/**
 * Data structure for frequency limit
 * Structure for DoCmd-function MIO_CMD_SETFREQUENCYWINDOW / MIO_CMD_GETFREQUENCYWINDOW
 * @since V1.00 Release
 */
typedef struct
{
    BOOL32  Enabled;            /**< En-/Disable limit monitoring */
    UINT32  Minimum;            /**< Minimum frequency [0.01Hz] */
    UINT32  Maximum;            /**< Maximum frequency [0.01Hz] */
    UINT32  Delay;              /**< Minimum time of active limit before alarm [ms] */
    UINT32  Alarm;              /**< Alarm to switch [0,1,2,3] */
    UINT32  Breaker;            /**< Breaker to switch */
    BOOL32  ScopeEnabled;       /**< Scope enabled */
} GSP_FREQUENCYLIMIT;

/**
 * Data structure for IEC values
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
} GSP_IECVALUES;

/**
 * Data structure for NSP configuration
 * Structure for DoCmd-function MIO_CMD_SETNSPCFG / MIO_CMD_GETNSPCFG
 * @since V1.00 Release
 */
typedef struct
{
    UINT16  UDecProtLt;         /**< Limit U<  in 0.1% of Un, default  80.0% */
    UINT16  UIncProtGt;         /**< Limit U>  in 0.1% of Un, default 110.0% */
    UINT16  UIncProtGtGt;       /**< Limit U>> in 0.1% of Un, default 115.0% */
    UINT16  FDecProtLt;         /**< Limit f<  in 0.1Hz of Un, default 47.5Hz */
    UINT16  FIncProtGt;         /**< Limit f>  in 0.1Hz of Un, default 51.5Hz */
    UINT16  ReconnDelay1;       /**< Short time interruption delay in sec. (default 5s) */
    UINT16  ReconnDelay2;       /**< Long time interruption delay in sec. (default 60s) */
    UINT16  IslandGrdD;         /**< Islanded grid detection */
} GSP_NSPCFG;

/**
 * Data structure for NSP status
 * Structure for DoCmd-function MIO_CMD_GETNSPSTATUS
 * @since V1.00 Release
 */
typedef struct
{
    UINT16  Status;             /**< Status (bitcoded) */
    UINT16  BreakType;          /**< 0: No break active, 1: short break, 2: long break */
    UINT16  RemainingTime;      /**< Remaining time to reconnect in seconds */
} GSP_NSPSTATUS;

/**
 * Data structure for NSP history
 * Structure for DoCmd-function MIO_CMD_GETNSPHISTORY
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  TimestampS;         /**< Time - Seconds since 1.1.1970 0:00 */
    UINT32  TimestampMS;        /**< Time - mSec part */
    UINT32  EventID;            /**< Type of event */
} GSP_NSPHISTORY;

/**
 * Data structure for the inhibit configuration
 * Structure for DoCmd-function MIO_CMD_SETINHIBITCFG /  MIO_CMD_GETINHIBITCFG
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  Errors;             /**< Error inhibit mask */
    UINT32  Events;             /**< Event inhibit mask */
} GSP_INHIBITCFG;

/**
 * Data structure for the synchronization inhibit configuration
 * Structure for DoCmd-function MIO_CMD_SETSYNCINHIBITCFG /  MIO_CMD_GETSYNCINHIBITCFG
 * @since V1.04 Release
 */
typedef struct
{
    UINT32  Sync1Errors;        /**< Error synchronization 1 inhibit mask */
    UINT32  Sync2Errors;        /**< Error synchronization 2 inhibit mask */
    UINT32  Sync1Events;        /**< Event synchronization 1 inhibit mask */
    UINT32  Sync2Events;        /**< Event synchronization 2 inhibit mask */
} GSP_SYNCINHIBITCFG;

/**
 * Data structure for SYNC configuration
 * Structure for DoCmd-function MIO_CMD_SETSYNCCFG / MIO_CMD_GETSYNCCFG
 * @since V1.00 Release
 */
typedef struct
{
    BOOL32  Enabled;            /**< En-/Disable this synchronization unit [1/0] */
    UINT32  Grid1;              /**< Grid as reference to sync to [GSP_GEN, GSP_BUS or GSP_MAINS], syncs always from Grid2 onto Grid1 */
    UINT32  Grid2;              /**< Grid to be synced, usually the manipulated grid [GSP_GEN, GSP_BUS or GSP_MAINS] */
    UINT32  Timeout;            /**< Maximum duration of started sync procedure until sync attempt is aborted 1..1000 [s] */
    UINT32  CloseDelay;         /**< Time delay of sync breaker from close command to closed state 10..1000 [ms] */
    BOOL32  MotorCondition;     /**< Allow synchronization also if Grid2 has lower frequency then Grid1 (would draw power) [1/0] */
    BOOL32  DeadBusStart;       /**< Allow synchronization onto an (almost) unpowered "black" Grid1 [1/0] */
    BOOL32  SameFrequency;      /**< Synchronize immediately if delta f is < 10mHz (used when closing loops in meshed grids) [1/0] */
    SINT32  VectorGroupCompensation;     /**< Phase shift to add to measured Grid? signal to compensate transformer +- 180° [0.1°] */
    UINT32  MaxFreqDeviationDeadBus;     /**< Maximum frequency deviation from nominal in operating Grid2 for BlackBusStart 0..10000 [0.001Hz] */
    UINT32  MaxVoltageDeviationDeadBus;  /**< Maximum voltage deviation from nominal in operating Grid2 for BlackBusStart 0..250 [0.1%] */
    UINT32  MaxPhaseDiff;       /**< Maximum phase difference between Grid2 and Grid1 for normal sync 0..100 [0.1°] */
    UINT32  MaxFrequencyDeviation;   /**< Maximum frequency difference between Grid2 and Grid1 for normal sync 0..500 [0.001Hz] */
    UINT32  MaxVoltageDeviation;     /**< Maximum voltage difference between Grid2 and Grid1 for normal sync 0..100 [0.1%] */
} GSP_SYNCCFG;

/**
 * Data structure for extended SYNC configuration (requires FW >= 1.04R)
 * Structure for DoCmd-function MIO_CMD_SETSYNCCFG_EXT / MIO_CMD_GETSYNCCFG_EXT
 * @since V1.04 Release
 */
typedef struct
{
    BOOL32  Enabled;            /**< En-/Disable this synchronization unit [1/0] */
    UINT32  Grid1;              /**< Grid as reference to sync to [GSP_GEN, GSP_BUS or GSP_MAINS], syncs always from Grid2 onto Grid1 */
    UINT32  Grid2;              /**< Grid to be synced, usually the manipulated grid [GSP_GEN, GSP_BUS or GSP_MAINS] */
    UINT32  Timeout;            /**< Maximum duration of started sync procedure until sync attempt is aborted 1..1000 [s] */
    UINT32  CloseDelay;         /**< Time delay of sync breaker from close command to closed state 10..1000 [ms] */
    BOOL32  MotorCondition;     /**< Allow synchronization also if Grid2 has lower frequency then Grid1 (would draw power) [1/0] */
    BOOL32  BlackBusStart;      /**< Allow synchronization onto an (almost) unpowered "black" Grid1 [1/0] */
    BOOL32  SameFrequency;      /**< Synchronize immediately if delta f is < 10mHz (used when closing loops in meshed grids) [1/0] */
    SINT32  VectorGroupCompensation;     /**< Phase shift to add to measured Grid? signal to compensate transformer +- 180° [0.1°] */
    UINT32  MaxFreqDeviationOperatingGrid;   /**< Maximum frequency deviation from nominal in operating Grid2 for BlackBusStart 0..10000 [0.001Hz] */
    UINT32  MaxVoltageDeviationOperatingGrid;    /**< Maximum voltage deviation from nominal in operating Grid2 for BlackBusStart 0..250 [0.1%] */
    UINT32  MaxPhaseDiff;       /**< Maximum phase difference between Grid2 and Grid1 for normal sync 0..100 [0.1°] */
    UINT32  MaxFrequencyDeviation;   /**< Maximum frequency difference between Grid2 and Grid1 for normal sync 0..500 [0.001Hz] */
    UINT32  MaxVoltageDeviation;     /**< Maximum voltage difference between Grid2 and Grid1 for normal sync 0..100 [0.1%] */
    UINT32  MaximumRemainingVoltageBlackBus;     /**< Maximum allowed remaining voltage in "black" Grid1 for BlackBusStart 0-15 [%], default 10% */
} GSP_SYNCCFG_EXT;

/**
 * Data structure for SYNC state
 * Structure for DoCmd-function MIO_CMD_GETSYNCSTATE
 * @since V1.00 Release
 */
typedef struct
{
    SINT32  VoltageDiff1;       /**< Voltage difference 1 [mV] */
    SINT32  VoltageDiff2;       /**< Voltage difference 2 [mV] */
    SINT32  VoltageDiff3;       /**< Voltage difference 3 [mV] */
    SINT32  PhaseDiff;          /**< Phase difference [0.1°] */
    SINT32  FreqDiff;           /**< Frequency difference [mHz] */
    UINT32  State;              /**< Sync state; one of GSP_SYNC_STATE_ constants */
    UINT32  RemainingTime;      /**< Remaining time to synchronize [s] */
} GSP_SYNCSTATE;

/**
 * Vector Jump configuration.
 * Structure for DoCmd-function MIO_CMD_SETVECTORJMPLIMIT / MIO_CMD_GETVECTORJMPLIMIT
 */
typedef struct
{
    BOOL32  Enabled;            /**< En-/Disable limit monitoring */
    UINT32  Value;              /**< Limit value [0.1°] */
    UINT32  Alarm;              /**< Alarm to switch [0,1,2,3] */
    UINT32  Breaker;            /**< Breaker to switch after event occurred */
    BOOL32  ScopeEnabled;       /**< Scope enabled */
} GSP_VECTORJMPLIMIT;

/**
 * Statistics data point used in GSP_GETSTATISTIC
 */
typedef struct
{
    UINT32  Timestamp;          /**< Timestamp - seconds since, 1.1.1970 0:00 / 0 - invalid point */
    UINT32  TimestampMs;        /**< Timestamp - ms */
    SINT32  Value;              /**< Data point value */
} GSP_STATISTICDATAPOINT;

/**
 * Data structure for statistic data used in GSP_DISPLAYSTATISTICS
 * Structure for DoCmd-function MIO_CMD_GETSTATISTICS
 */
typedef struct
{
    GSP_STATISTICDATAPOINT  Minimum;     /**< Minimum data point */
    GSP_STATISTICDATAPOINT  Maximum;     /**< Maximum data point */
} GSP_GETSTATISTIC;

/**
 * Statistics information used in GSP_DISPLAYSTATISTICS
 */
typedef struct
{
    CHAR8   Name[32];           /**< Name of the data point */
    REAL32  Scale;              /**< Scaling factor */
    REAL32  Offset;             /**< Offset */
    UINT32  SiUnit;             /**< Si-Units:  UFB_SIUNIT */
    CHAR8   UnitStr[12];        /**< Unit optional text ("V", "uA"..) */
} GSP_STATISTICINF;

/**
 * Data structure for display statistics
 * Structure for DoCmd-function MIO_CMD_DISPSTATISTICS
 */
typedef struct
{
    GSP_GETSTATISTIC    DataPoint;   /**< Statistic values */
    GSP_STATISTICINF    AddInf; /**< Additional information */
} GSP_DISPLAYSTATISTICS;

/**
 * Simulation Data
 * Structure for DoCmd-function MIO_CMD_SETSIMDATA / MIO_CMD_GETSIMDATA
 */
typedef struct
{
    UINT32  U_L1_GEN;           /**< Voltage [0.1%] */
    UINT32  U_L2_GEN;           /**< Voltage [0.1%] */
    UINT32  U_L3_GEN;           /**< Voltage [0.1%] */
    UINT32  I_L1_GEN;           /**< Current [0.1%] */
    UINT32  I_L2_GEN;           /**< Current [0.1%] */
    UINT32  I_L3_GEN;           /**< Current [0.1%] */
    UINT32  f_GEN;              /**< Frequency [0.001Hz] */
    SINT32  Phi_U_L1_GEN;       /**< Phase angle between U1 and N [0.1°] */
    SINT32  Phi_U_L2_GEN;       /**< Phase angle between U2 and N [0.1°] */
    SINT32  Phi_U_L3_GEN;       /**< Phase angle between U3 and N [0.1°] */
    SINT32  Phi_I_L1_GEN;       /**< Phase angle between I1 and N [0.1°] */
    SINT32  Phi_I_L2_GEN;       /**< Phase angle between I2 and N [0.1°] */
    SINT32  Phi_I_L3_GEN;       /**< Phase angle between I3 and N [0.1°] */
    UINT32  U_L1_BUS;           /**< Voltage [0.1%] */
    UINT32  f_BUS;              /**< Frequency [0.001Hz] */
    UINT32  U_L1_MAINS;         /**< Voltage [0.1%] */
    UINT32  U_L2_MAINS;         /**< Voltage [0.1%] */
    UINT32  U_L3_MAINS;         /**< Voltage [0.1%] */
    SINT32  Phi_U_L1L2_MAINS;   /**< Phase U L1L2 [0.1°] */
    SINT32  Phi_U_L2L3_MAINS;   /**< Phase U L2L3 [0.1°] */
    UINT32  f_MAINS;            /**< Frequency in [0.001Hz] */
    UINT32  I_NP;               /**< Current [0.1%] */
    UINT32  FeedbackDI1;        /**< (Feedback) DI Channel 21 */
    UINT32  DI1;                /**< DI1 Channel 22 */
    UINT32  FeedbackDI2;        /**< (Feedback) DI Channel 23 */
    UINT32  DI2;                /**< DI1 Channel 24 */
} GSP_SIMDATA;

/**
 * Data structure for QU-Limit
 * Structure for DoCmd-function MIO_CMD_SETQULIMIT / MIO_CMD_GETQULIMIT
 */
typedef struct
{
    BOOL32  Enabled;            /**< En-/Disable limit monitoring */
    UINT32  Mode;               /**< GSP_QUMODE_REACTIVEPOWERTHRESHOLD / GSP_QUMODE_ANGLE */
    UINT32  I_Min;              /**< Minimum current [0.1%] */
    UINT32  U_Min;              /**< Minimum voltage [0.1%] */
    UINT32  I_Fallback;         /**< Current fallback [0.1%] */
    UINT32  U_Fallback;         /**< Voltage fallback [0.1%] */
    UINT32  Phi;                /**< [0.1°] */
    UINT32  Q_Min;              /**< [0.1%] */
    UINT32  DelayGeneratorProtection;    /**< [ms] */
    UINT32  AlarmGeneratorProtection;    /**< 0, 1, 2, 3 */
    UINT32  BreakerGeneratorProtection;  /**< 0, 1, 2, 3 */
    UINT32  DelayPCCProtection; /**< [ms] */
    UINT32  AlarmPCCProtection; /**< 0, 1, 2, 3 */
    UINT32  BreakerPCCProtection;    /**< 0, 1, 2, 3 */
} GSP_QULIMIT;

/**
 * Harmonics Limit
 * Structure for DoCmd-function MIO_CMD_SETHARMONICSLIMIT / MIO_CMD_GETHARMONICSLIMIT
 */
typedef struct
{
    BOOL32  Enabled;            /**< En-/Disable limit monitoring */
    UINT32  Value[GSP_MAX_HARMONICSLIMIT];   /**< Limits [0.1%] */
    UINT32  Alarm;              /**< Alarm to switch [0,1,2,3] */
    BOOL32  ScopeEnabled;       /**< Scope Enabled */
} GSP_HARMONICSLIMIT;

/**
 * Data structure for harmonics
 * Structure for DoCmd-function MIO_CMD_GETHARMONICS
 */
typedef struct
{
    UINT32  Value[GSP_MAX_HARMONICS];    /**< Value of harmonics [0.1%] */
    UINT32  THDTDD;             /**< Harmonics Factor [0.1%] */
} GSP_HARMONICS;

/**
 * Scope sample data used in GSP_SCOPEDATA
 */
typedef struct
{
    UINT32  Timestamp;          /**< Timestamp relative to GSP_SCOPECFG */
    SINT32  Data[GSP_SCOPE_MAXCHAN];     /**< Recorded values */
} GSP_SCOPESAMPLE;

/**
 * Scope data structure
 * Structure for DoCmd-function MIO_CMD_GETSCOPE
 */
typedef struct
{
    GSP_SCOPESAMPLE Samples[GSP_SCOPE_MAXSAMPLES];   /**< Scope samples */
} GSP_SCOPEDATA;

/**
 * Scope configuration
 * Structure for DoCmd-function MIO_CMD_SETSCOPECFG / MIO_CMD_GETSCOPECFG
 */
typedef struct
{
    UINT64  ChanBitMask1;       /**< Bit mask of enabled channels 1-64. */
    UINT64  ChanBitMask2;       /**< Bit mask of enabled channels 65-128. */
    UINT32  SampleRate;         /**< One of the GSP_SCOPE_SAMPLE_xxx constants */
    UINT32  Pretrigger;         /**< Number of GSP_SCOPEDATA elements prior event */
} GSP_SCOPECFG;

/**
 * Scope state
 * Structure for DoCmd-function MIO_CMD_GETSCOPESTATE
 */
typedef struct
{
    UINT32  State;              /**< One of the GSP_SCOPE_STATE_ constants */
    UINT32  PretriggerCount;    /**< Number of pre-trigger samples */
    UINT32  TimestampS;         /**< Timestamp - seconds since 1.1.1970 0:00 */
    UINT32  TimestampMS;        /**< Timestamp - ms */
    UINT32  TriggerEvent;       /**< Event that caused scope recording */
} GSP_SCOPESTATE;

/**
 * Structure for history lock
 * Structure for DoCmd-function MIO_CMD_TAKEHISTORYLOCK / MIO_CMD_TAKENSPHISTORYLOCK
 */
typedef struct
{
    UINT32  LockHandle;         /**< Lock handle */
    UINT32  ActNbEntries;       /**< Number of entries in the history */
    UINT32  TotalNbEntries;     /**< Number of entries since last history delete */
} GSP_LOCKHISTORY;

/**
 * Structure for alarm history
 * Structure for DoCmd-function MIO_CMD_GETALARMHISTORY
 */
typedef struct
{
    UINT32  TimestampS;         /**< Timestamp seconds since 1.1.1970 00:00 */
    UINT32  TimestampMS;        /**< Timestamp ms */
    /**
     * Event type bit mask, any of the following can be set:
     * GSP_SCOPE_TE_ERROR, GSP_SCOPE_TE_EVENT,
     */
    UINT32  EventID;
} GSP_ALARMHISTORY;

/**
 * Data Structure for energy
 * Structure for DoCmd-function MIO_CMD_SETENERGY / MIO_CMD_GETENERGY
 */
typedef struct
{
    UINT64  ActiveEnergyDelivered;   /**< Active energy delivered [Wh] */
    UINT64  ActiveEnergyReceived;    /**< Active energy received [Wh] */
    UINT64  ReactiveEnergyDelivered;     /**< Reactive energy delivered [varh] */
    UINT64  ReactiveEnergyReceived;  /**< Reactive energy received [varh] */
} GSP_ENERGY;

/**
 * Data Structure for energy (real)
 * Structure for DoCmd-function MIO_CMD_SETENERGYREAL / MIO_CMD_GETENERGYREAL
 * @since V1.01-03 Release
 */
typedef struct
{
    REAL64  ActiveEnergyDelivered;   /**< Active energy delivered [Wh] */
    REAL64  ActiveEnergyReceived;    /**< Active energy received [Wh] */
    REAL64  ReactiveEnergyDelivered;     /**< Reactive energy delivered [varh] */
    REAL64  ReactiveEnergyReceived;  /**< Reactive energy received [varh] */
} GSP_ENERGYREAL;

/**
 * Data structure for measured values
 * Structure for DoCmd-function MIO_CMD_GETVALUES / MIO_CMD_GETSELECTEDVALUES
 */
typedef struct
{
    UINT32  GEN_U_L1L2_rms;     /**< Voltage U12 [mV] */
    UINT32  GEN_U_L2L3_rms;     /**< Voltage U23 [mV] */
    UINT32  GEN_U_L3L1_rms;     /**< Voltage U31 [mV] */
    UINT32  GEN_U_L1N_rms;      /**< Voltage U1 [mV] */
    UINT32  GEN_U_L2N_rms;      /**< Voltage U2 [mV] */
    UINT32  GEN_U_L3N_rms;      /**< Voltage U3 [mV] */
    UINT32  GEN_I_L1_rms;       /**< Current I1 [mA] */
    UINT32  GEN_I_L2_rms;       /**< Current I2 [mA] */
    UINT32  GEN_I_L3_rms;       /**< Current I3 [mA] */
    UINT32  GEN_I_N_rms;        /**< Current IN [mA] */
    UINT32  GEN_f;              /**< Current frequency [mHz] */
    SINT32  GEN_Phi_U1I1;       /**< Phase angle between U1 and I1 [0.1°] */
    SINT32  GEN_Phi_U2I2;       /**< Phase angle between U2 and I2 [0.1°] */
    SINT32  GEN_Phi_U3I3;       /**< Phase angle between U3 and I3 [0.1°] */
    UINT32  GEN_PF_sum;         /**< Powerfactor Sum (0 - 1000) */
    UINT32  GEN_PF_L1;          /**< Powerfactor phase 1 (0 - 1000) */
    UINT32  GEN_PF_L2;          /**< Powerfactor phase 2 (0 - 1000) */
    UINT32  GEN_PF_L3;          /**< Powerfactor phase 3 (0 - 1000) */
    SINT32  GEN_P_sum;          /**< Sum real power [W] */
    SINT32  GEN_P_L1;           /**< Real power phase 1 [W] */
    SINT32  GEN_P_L2;           /**< Real power phase 2 [W] */
    SINT32  GEN_P_L3;           /**< Real power phase 3 [W] */
    SINT32  GEN_Q_sum;          /**< Sum reactive power [var] */
    SINT32  GEN_Q_L1;           /**< Reactive power phase 1 [var] */
    SINT32  GEN_Q_L2;           /**< Reactive power phase 2 [var] */
    SINT32  GEN_Q_L3;           /**< Reactive power phase 3 [var] */
    UINT32  GEN_S_sum;          /**< Sum apparent power [VA] */
    UINT32  GEN_S_L1;           /**< Apparent power phase 1 [VA] */
    UINT32  GEN_S_L2;           /**< Apparent power phase 2 [VA] */
    UINT32  GEN_S_L3;           /**< Apparent power phase 3 [VA] */
    UINT32  GEN_Asym_U;         /**< Asymmetric voltage */
    UINT32  GEN_Asym_I;         /**< Asymmetric current */
    UINT32  GEN_RotDir_U;       /**< Rotation direction of voltage. ROTATION_CW, ROTATION_CCW, ROTATION_UNKNOWN */
    UINT32  GEN_RotDir_I;       /**< Rotation direction of current. ROTATION_CW, ROTATION_CCW, ROTATION_UNKNOWN */
    SINT32  GEN_ROCOF;          /**< Rate of change of frequency [0.001Hz/s] */
    UINT32  GEN_Overload_U;     /**< Bitfield Bit 0 Overload U1, Bit 1 Overload U2, Bit 2 Overload U3 */
    UINT32  GEN_Overload_I;     /**< Bitfield Bit 0 Overload I1, Bit 1 Overload I2, Bit 2 Overload I3 */
    SINT32  GEN_VectorJmp;      /**< Vector jump [0.1°] */
    UINT32  BUS_U_L1L2_rms;     /**< Voltage U12 [mV] */
    UINT32  BUS_f;              /**< Current frequency [mHz] */
    SINT32  BUS_ROCOF;          /**< Rate of change of frequency [0.001Hz/s] */
    UINT32  BUS_Overload_U;     /**< Bitfield Bit 0 Overload U1, Bit 1 Overload U2, Bit 2 Overload U3 */
    UINT32  MAINS_U_L1L2_rms;   /**< Voltage U12 [mV] */
    UINT32  MAINS_U_L2L3_rms;   /**< Voltage U23 [mV] */
    UINT32  MAINS_U_L3L1_rms;   /**< Voltage U31 [mV] */
    UINT32  MAINS_U_L1N_rms;    /**< Voltage U1 [mV] */
    UINT32  MAINS_U_L2N_rms;    /**< Voltage U2 [mV] */
    UINT32  MAINS_U_L3N_rms;    /**< Voltage U3 [mV] */
    UINT32  MAINS_f;            /**< Current frequency [mHz] */
    UINT32  MAINS_Asym_U;       /**< Asymmetric voltage */
    UINT32  MAINS_RotDir_U;     /**< Rotation direction of voltage. ROTATION_CW, ROTATION_CCW, ROTATION_UNKNOWN */
    SINT32  MAINS_ROCOF;        /**< Rate of change of frequency [0.001Hz/s] */
    UINT32  MAINS_Overload_U;   /**< Bitfield Bit 0 Overload U1, Bit 1 Overload U2, Bit 2 Overload U3 */
    UINT32  NP_I_rms;           /**< Current [mA] */
    UINT32  NP_Overload_I;      /**< Bitfield Bit 0 Overload I1, Bit 1 Overload I2, Bit 2 Overload I3 */
} GSP_VALUES;

/**
 * Phase angles structure
 * Structure for DoCmd-function MIO_CMD_GETPHASEANGLES
 */
typedef struct
{
    SINT32  Phi_U1U2;           /**< Phase angle between U1 and U2 [0.01°] */
    SINT32  Phi_U2U3;           /**< Phase angle between U2 and U3 [0.01°] */
    SINT32  Phi_U3U1;           /**< Phase angle between U3 and U1 [0.01°] */
    SINT32  Phi_U1I1;           /**< Phase angle between U1 and I1 [0.01°] */
    SINT32  Phi_U2I2;           /**< Phase angle between U2 and I2 [0.01°] */
    SINT32  Phi_U3I3;           /**< Phase angle between U3 and I3 [0.01°] */
    SINT32  Phi_UL12L23;        /**< Phase angle between U12 and U23 [0.01°] */
    SINT32  Phi_UL23L31;        /**< Phase angle between U23 and U31 [0.01°] */
    SINT32  Phi_UL31L12;        /**< Phase angle between U31 and U12 [0.01°] */
} GSP_PHASEANGLES;

/**
 * Data structure for vector diagram
 * Structure for DoCmd-function MIO_CMD_GETVECTORDIAGRAM
 */
typedef struct
{
    UINT32  ModeU;              /**< Voltage mode (GSP_M_XXX) */
    UINT32  ModeI;              /**< Current mode (GSP_M_XXX) */
    UINT32  f;                  /**< Frequency [mHz] */
    UINT32  U_L1;               /**< Voltage U1 [mV] */
    UINT32  U_L2;               /**< Voltage U2 [mV] */
    UINT32  U_L3;               /**< Voltage U3 [mV] */
    UINT32  U_L1L2;             /**< Voltage U12 [mV] */
    UINT32  U_L2L3;             /**< Voltage U23 [mV] */
    UINT32  U_L3L1;             /**< Voltage U31 [mV] */
    UINT32  I_L1;               /**< Current I1 [mA] */
    UINT32  I_L2;               /**< Current I2 [mA] */
    UINT32  I_L3;               /**< Current I3 [mA] */
    SINT32  Phi_U1;             /**< Angle between U1 and N  [0.01°] */
    SINT32  Phi_U2U1;           /**< Angle between U2 and U1 [0.01°] */
    SINT32  Phi_U3U1;           /**< Angle between U3 and U1 [0.01°] */
    SINT32  Phi_I1U1;           /**< Angle between I1 and U1 [0.01°] */
    SINT32  Phi_I2U1;           /**< Angle between I2 and U1 [0.01°] */
    SINT32  Phi_I3U1;           /**< Angle between I3 and U1 [0.01°] */
    SINT32  P_sum;              /**< Sum real power [W] */
    UINT32  S_sum;              /**< Sum apparent power [VA] */
    SINT32  Q_sum;              /**< Sum reactive power [var] */
    UINT32  Overload_U;         /**< Bitfield Bit 0 Overload U1, Bit 1 Overload U2, Bit 2 Overload U3 */
    UINT32  Overload_I;         /**< Bitfield Bit 0 Overload I1, Bit 1 Overload I2, Bit 2 Overload I3 */
} GSP_VECTORDIAGRAM;

/**
 * Data structure for switch count
 * Structure for DoCmd-function MIO_CMD_GETSWITCHCOUNT
 */
typedef struct
{
    UINT32  NSPRelay1;          /**< NSP relay 1 */
    UINT32  NSPRelay2;          /**< NSP relay 2 */
} GSP_SWITCHCOUNT;

/**
 * Structure for DoCmd-function MIO_CMD_GETHISTORYTOTAL
 * @since V1.04 Release
 */
typedef struct
{
    UINT32  Total;              /**< (Total) Number of entries since last history delete */
    UINT32  LatestIndex;        /**< Number of entries in the history. */
} GSP_HISTORY_COUNT;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
