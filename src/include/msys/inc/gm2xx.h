/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     gm2xx.h
* @author   Pilavci
* @brief    GM2XX specific structures and defines.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef GM2XX__H
#define GM2XX__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @addtogroup GM2XX_DEF
 * @{
 */
#define GM2XX_M_3WIRE3PHASE     1    /**< 3 wires, 3 phases, (phase phase) */
#define GM2XX_M_4WIRE3PHASELN   0    /**< 4 wires, 3 phases, (phase neutral) */
#define GM2XX_M_PTPrimaryV      0    /**< volt */
#define GM2XX_M_PTPrimarykV     1    /**< kilo volt */
#define GM2XX_ROTATION_CW       0x0000   /**< Rotation clockwise */
#define GM2XX_ROTATION_CCW      0x0001   /**< Rotation counterclockwise */
#define GM2XX_ROTATION_UNKNOWN  0xFFFF   /**< Rotation unknown */
#define GM2XX_VAL_U_L1N_RMS     0x0000000000000400LL     /**< Returns value of U_L1N_RMS */
#define GM2XX_VAL_U_L2N_RMS     0x0000000000000800LL     /**< Returns value of U_L2N_RMS */
#define GM2XX_VAL_U_L3N_RMS     0x0000000000001000LL     /**< Returns value of U_L3N_RMS */
#define GM2XX_VAL_U_L1L2_RMS    0x0000000000002000LL     /**< Returns value of U_L1L2_RMS */
#define GM2XX_VAL_U_L2L3_RMS    0x0000000000004000LL     /**< Returns value of U_L2L3_RMS */
#define GM2XX_VAL_U_L3L1_RMS    0x0000000000008000LL     /**< Returns value of U_L3L1_RMS */
#define GM2XX_VAL_I_L1_RMS      0x0000000000010000LL     /**< Returns I_L1_RMS value */
#define GM2XX_VAL_I_L2_RMS      0x0000000000020000LL     /**< Returns I_L2_RMS value */
#define GM2XX_VAL_I_L3_RMS      0x0000000000040000LL     /**< Returns I_L3_RMS value */
#define GM2XX_VAL_I_N_RMS       0x0000000000080000LL     /**< Returns I_N_RMS value */
#define GM2XX_VAL_P_SUM         0x0000000000100000LL     /**< Returns P_SUM value */
#define GM2XX_VAL_P_L1          0x0000000000200000LL     /**< Returns P_L1 value */
#define GM2XX_VAL_P_L2          0x0000000000400000LL     /**< Returns P_L2 value */
#define GM2XX_VAL_P_L3          0x0000000000800000LL     /**< Returns P_L3 value */
#define GM2XX_VAL_S_SUM         0x0000000001000000LL     /**< Returns S_SUM value */
#define GM2XX_VAL_S_L1          0x0000000002000000LL     /**< Returns S_L1 value */
#define GM2XX_VAL_S_L2          0x0000000004000000LL     /**< Returns S_L2 value */
#define GM2XX_VAL_S_L3          0x0000000008000000LL     /**< Returns S_L3 value */
#define GM2XX_VAL_Q_SUM         0x0000000010000000LL     /**< Returns Q_SUM value */
#define GM2XX_VAL_Q_L1          0x0000000020000000LL     /**< Returns Q_L1 value */
#define GM2XX_VAL_Q_L2          0x0000000040000000LL     /**< Returns Q_L2 value */
#define GM2XX_VAL_Q_L3          0x0000000080000000LL     /**< Returns Q_L3 value */
#define GM2XX_VAL_FREQUENCY     0x0000000100000000LL     /**< Returns value of frequency, f */
#define GM2XX_VAL_PHI_U1I1      0x0000000200000000LL     /**< Returns value of PHI_U1I1 */
#define GM2XX_VAL_PHI_U2I2      0x0000000400000000LL     /**< Returns value of PHI_U2I2 */
#define GM2XX_VAL_PHI_U3I3      0x0000000800000000LL     /**< Returns value of PHI_U3I3 */
#define GM2XX_VAL_PF_SUM        0x0000001000000000LL     /**< Returns value of PF_SUM */
#define GM2XX_VAL_PF_L1         0x0000002000000000LL     /**< Returns value of PF_L1 */
#define GM2XX_VAL_PF_L2         0x0000004000000000LL     /**< Returns value of PF_L2 */
#define GM2XX_VAL_PF_L3         0x0000008000000000LL     /**< Returns value of PF_L3 */
#define GM2XX_VAL_ROTDIR_U      0x0000010000000000LL     /**< Returns value of RotDir_U */
#define GM2XX_VAL_PHI_U1U2      0x0000020000000000LL     /**< Returns value of PHI_U1U2 */
#define GM2XX_VAL_PHI_U2U3      0x0000040000000000LL     /**< Returns value of PHI_U2U3 */
#define GM2XX_VAL_PHI_U1U3      0x0000080000000000LL     /**< Returns value of PHI_U1U3 */
#define GM2XX_VAL_ALL           -1LL     /**< Returns value of PHI_U3U1 */
/** @} */

/**
 * @name Structures
 * @{
 */

/**
 * Structure for DoCmd-function MIO_CMD_GETCONFIG
 * Base GM2XX configuration, can only be changed during startup.
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  Mode;               /**< Operation mode of the Card */
    UINT32  PTPrimaryUnit;      /**< Unit of PT primary configuration, V-kV */
    UINT32  PTPrimary;          /**< Voltage transformer primary side */
    UINT32  PTSecondary;        /**< Voltage transformer secondary side, nom. in V */
    UINT32  CTPrimary;          /**< Current transformer primary side, nom. in A */
    UINT32  CTSecondary;        /**< Current transformer secondary side, nom. in mA */
} GM2XX_CONFIG;

/**
 * Structure for DoCmd-function MIO_CMD_SETENERGY / MIO_CMD_GETENERGY
 * Energy values UINT64
 * @since V1.00 Release
 */
typedef struct
{
    UINT64  ActiveEnergyDelivered;   /**< Active energy delivered [Wh] */
    UINT64  ActiveEnergyReceived;    /**< Active energy received [Wh] */
    UINT64  ReactiveEnergyDelivered;     /**< Reactive energy delivered [varh] */
    UINT64  ReactiveEnergyReceived;  /**< Reactive energy received [varh] */
} GM2XX_ENERGY;

/**
 * Structure for DoCmd-function MIO_CMD_SETENERGYREAL / MIO_CMD_GETENERGYREAL
 * Energy values REAL64
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  ActiveEnergyDelivered;   /**< Active energy delivered [Wh] */
    REAL64  ActiveEnergyReceived;    /**< Active energy received [Wh] */
    REAL64  ReactiveEnergyDelivered;     /**< Reactive energy delivered [varh] */
    REAL64  ReactiveEnergyReceived;  /**< Reactive energy received [varh] */
} GM2XX_ENERGYREAL;

/**
 * Structure for DoCmd-function MIO_CMD_GETVALUES / MIO_CMD_GETSELECTEDVALUES
 * All measured values
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  U_L1L2_RMS;         /**< Voltage U12 [V] */
    REAL64  U_L2L3_RMS;         /**< Voltage U23 [V], 0 on GM210 */
    REAL64  U_L3L1_RMS;         /**< Voltage U31 [V], 0 on GM210 */
    REAL64  U_L1N_RMS;          /**< Voltage U1 [V] */
    REAL64  U_L2N_RMS;          /**< Voltage U2 [V], 0 on GM210 */
    REAL64  U_L3N_RMS;          /**< Voltage U3 [V], 0 on GM210 */
    REAL64  I_L1_RMS;           /**< Current I1 [A] */
    REAL64  I_L2_RMS;           /**< Current I2 [A], 0 on GM210 */
    REAL64  I_L3_RMS;           /**< Current I3 [A], 0 on GM210 */
    REAL64  I_N_RMS;            /**< Current IN [A] */
    UINT32  f;                  /**< Current frequency [mHz] */
    SINT32  Phi_U1I1;           /**< Phase angle between U1 and I1 [0.1°] */
    SINT32  Phi_U2I2;           /**< Phase angle between U2 and I2 [0.1°], 0 on GM210 */
    SINT32  Phi_U3I3;           /**< Phase angle between U3 and I3 [0.1°], 0 on GM210 */
    SINT32  Phi_U1U2;           /**< Phase angle between U1 and U2 [0.1°] */
    SINT32  Phi_U2U3;           /**< Phase angle between U2 and U3 [0.1°] */
    SINT32  Phi_U1U3;           /**< Phase angle between U1 and U3 [0.1°] */
    SINT32  PF_sum;             /**< Powerfactor Sum (0 - 1000) */
    SINT32  PF_L1;              /**< Powerfactor phase 1 (0 - 1000) */
    SINT32  PF_L2;              /**< Powerfactor phase 2 (0 - 1000), 0 on GM210 */
    SINT32  PF_L3;              /**< Powerfactor phase 3 (0 - 1000), 0 on GM210 */
    REAL64  P_sum;              /**< Sum real power [W] */
    REAL64  P_L1;               /**< Real power phase 1 [W] */
    REAL64  P_L2;               /**< Real power phase 2 [W], 0 on GM210 */
    REAL64  P_L3;               /**< Real power phase 3 [W], 0 on GM210 */
    REAL64  Q_sum;              /**< Sum reactive power [var] */
    REAL64  Q_L1;               /**< Reactive power phase 1 [var] */
    REAL64  Q_L2;               /**< Reactive power phase 2 [var], 0 on GM210 */
    REAL64  Q_L3;               /**< Reactive power phase 3 [var], 0 on GM210 */
    REAL64  S_sum;              /**< Sum apparent power [VA] */
    REAL64  S_L1;               /**< Apparent power phase 1 [VA] */
    REAL64  S_L2;               /**< Apparent power phase 2 [VA], 0 on GM210 */
    REAL64  S_L3;               /**< Apparent power phase 3 [VA], 0 on GM210 */
    UINT32  RotDir_U;           /**< Rotation direction of voltage. ROTATION_CW, ROTATION_CCW, ROTATION_UNKNOWN */
} GM2XX_VALUES;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
