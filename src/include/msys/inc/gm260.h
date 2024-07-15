/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     gm260.h
* @author   Pilavci
* @brief    GM260 specific structures and defines.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef GM260__H
#define GM260__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @addtogroup GM260_DEF
 * @{
 */
#define GM260_M_3WIRE3PHASE     1    /**< 3 wires, 3 phases, (phase phase) */
#define GM260_M_4WIRE3PHASELN   0    /**< 4 wires, 3 phases, (phase neutral) */
#define GM260_ROTATION_CW       0x0000   /**< Rotation clockwise */
#define GM260_ROTATION_CCW      0x0001   /**< Rotation counterclockwise */
#define GM260_ROTATION_UNKNOWN  0xFFFF   /**< Rotation unknown */
#define GM260_MP1               0x0001   /**< Measuring point 1 */
#define GM260_MP2               0x0002   /**< Measuring point 2 */
#define GM260_VAL_U_L1N_RMS     0x0000000000000400LL     /**< Returns value of U_L1N_RMS */
#define GM260_VAL_U_L2N_RMS     0x0000000000000800LL     /**< Returns value of U_L2N_RMS */
#define GM260_VAL_U_L3N_RMS     0x0000000000001000LL     /**< Returns value of U_L3N_RMS */
#define GM260_VAL_U_L1L2_RMS    0x0000000000002000LL     /**< Returns value of U_L1L2_RMS */
#define GM260_VAL_U_L2L3_RMS    0x0000000000004000LL     /**< Returns value of U_L2L3_RMS */
#define GM260_VAL_U_L3L1_RMS    0x0000000000008000LL     /**< Returns value of U_L3L1_RMS */
#define GM260_VAL_I_L1_RMS      0x0000000000010000LL     /**< Returns I_L1_RMS values of both measuring points */
#define GM260_VAL_I_L2_RMS      0x0000000000020000LL     /**< Returns I_L2_RMS values of both measuring points */
#define GM260_VAL_I_L3_RMS      0x0000000000040000LL     /**< Returns I_L3_RMS values of both measuring points */
#define GM260_VAL_I_N_RMS       0x0000000000080000LL     /**< Returns I_N_RMS values of both measuring points */
#define GM260_VAL_P_SUM         0x0000000000100000LL     /**< Returns P_SUM values of both measuring points */
#define GM260_VAL_P_L1          0x0000000000200000LL     /**< Returns P_L1 values of both measuring points */
#define GM260_VAL_P_L2          0x0000000000400000LL     /**< Returns P_L2 values of both measuring points */
#define GM260_VAL_P_L3          0x0000000000800000LL     /**< Returns P_L3 values of both measuring points */
#define GM260_VAL_S_SUM         0x0000000001000000LL     /**< Returns S_SUM values of both measuring points */
#define GM260_VAL_S_L1          0x0000000002000000LL     /**< Returns S_L1 values of both measuring points */
#define GM260_VAL_S_L2          0x0000000004000000LL     /**< Returns S_L2 values of both measuring points */
#define GM260_VAL_S_L3          0x0000000008000000LL     /**< Returns S_L3 values of both measuring points */
#define GM260_VAL_Q_SUM         0x0000000010000000LL     /**< Returns Q_SUM values of both measuring points */
#define GM260_VAL_Q_L1          0x0000000020000000LL     /**< Returns Q_L1 values of both measuring points */
#define GM260_VAL_Q_L2          0x0000000040000000LL     /**< Returns Q_L2 values of both measuring points */
#define GM260_VAL_Q_L3          0x0000000080000000LL     /**< Returns Q_L3 values of both measuring points */
#define GM260_VAL_FREQUENCY     0x0000000100000000LL     /**< Returns value of frequency, f */
#define GM260_VAL_PHI_U1I1      0x0000000200000000LL     /**< Returns values of all measuring points! */
#define GM260_VAL_PHI_U2I2      0x0000000400000000LL     /**< Returns values of all measuring points! */
#define GM260_VAL_PHI_U3I3      0x0000000800000000LL     /**< Returns values of all measuring points! */
#define GM260_VAL_PF_SUM        0x0000001000000000LL     /**< Returns values of all measuring points! */
#define GM260_VAL_PF_L1         0x0000002000000000LL     /**< Returns values of all measuring points! */
#define GM260_VAL_PF_L2         0x0000004000000000LL     /**< Returns values of all measuring points! */
#define GM260_VAL_PF_L3         0x0000008000000000LL     /**< Returns values of all measuring points! */
#define GM260_VAL_ROTDIR_U      0x0000010000000000LL     /**< Returns value of RotDir_U */
#define GM260_VAL_PHI_U1U2      0x0000020000000000LL     /**< Returns value of PHI_U1U2 */
#define GM260_VAL_PHI_U2U3      0x0000040000000000LL     /**< Returns value of PHI_U2U3 */
#define GM260_VAL_PHI_U1U3      0x0000080000000000LL     /**< Returns value of PHI_U1U3 */
#define GM260_VAL_PHI_U3U1      0x0000080000000000LL     /**< Returns value of PHI_U3U1 */
#define GM260_VAL_PHI_U12U23    0x0000100000000000LL     /**< Returns value of PHI_U12U23 */
#define GM260_VAL_PHI_U23U31    0x0000200000000000LL     /**< Returns value of PHI_U23U31 */
#define GM260_VAL_PHI_U31U12    0x0000400000000000LL     /**< Returns value of PHI_U31U12 */
#define GM260_VAL_ALL           -1LL     /**< workaround: asgard does not yet support 0xffffffffffffffffs64 */
/** @} */

/**
 * @name Structures
 * @{
 */

/**
 * Structure for DoCmd-function MIO_CMD_GETCONFIG
 * Base GM260 configuration, can only be changed during startup.
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  Mode;               /**< Operation mode of the Card */
    UINT32  PTPrimary;          /**< Voltage transformer primary side, nom. in V */
    UINT32  PTSecondary;        /**< Voltage transformer secondary side, nom. in V */
    UINT32  Frequency;          /**< Frequency in Hz, 50 or 60 */
    UINT32  CTPrimaryMP1;       /**< Current transformer primary side, nom. in A from measuring point1 */
    UINT32  CTPrimaryMP2;       /**< Current transformer primary side, nom. in A from measuring point2 */
} GM260_CONFIG;

/**
 * Structure for DoCmd-function MIO_CMD_SETENERGY / MIO_CMD_GETENERGY
 * Energy values UINT64
 * @since V1.00 Release
 */
typedef struct
{
    UINT64  MP1_ActiveEnergyDelivered;   /**< Active energy delivered [Wh] */
    UINT64  MP1_ActiveEnergyReceived;    /**< Active energy received [Wh] */
    UINT64  MP1_ReactiveEnergyDelivered;     /**< Reactive energy delivered [varh] */
    UINT64  MP1_ReactiveEnergyReceived;  /**< Reactive energy received [varh] */
    UINT64  MP2_ActiveEnergyDelivered;   /**< Active energy delivered [Wh] */
    UINT64  MP2_ActiveEnergyReceived;    /**< Active energy received [Wh] */
    UINT64  MP2_ReactiveEnergyDelivered;     /**< Reactive energy delivered [varh] */
    UINT64  MP2_ReactiveEnergyReceived;  /**< Reactive energy received [varh] */
} GM260_ENERGY;

/**
 * Structure for DoCmd-function MIO_CMD_SETENERGY_MP / MIO_CMD_GETENERGY
 * Energy values UINT64
 * @since V1.03 Release
 */
typedef struct
{
    UINT64  ActiveEnergyDelivered;   /**< Active energy delivered [Wh] */
    UINT64  ActiveEnergyReceived;    /**< Active energy received [Wh] */
    UINT64  ReactiveEnergyDelivered;     /**< Reactive energy delivered [varh] */
    UINT64  ReactiveEnergyReceived;  /**< Reactive energy received [varh] */
} GM260_ENERGY_MP;

/**
 * Structure for DoCmd-function MIO_CMD_SETENERGYREAL / MIO_CMD_GETENERGYREAL
 * Energy values REAL64
 * @since V1.00 Release
 */
typedef struct
{
    REAL64  MP1_ActiveEnergyDelivered;   /**< Active energy delivered [Wh] */
    REAL64  MP1_ActiveEnergyReceived;    /**< Active energy received [Wh] */
    REAL64  MP1_ReactiveEnergyDelivered;     /**< Reactive energy delivered [varh] */
    REAL64  MP1_ReactiveEnergyReceived;  /**< Reactive energy received [varh] */
    REAL64  MP2_ActiveEnergyDelivered;   /**< Active energy delivered [Wh] */
    REAL64  MP2_ActiveEnergyReceived;    /**< Active energy received [Wh] */
    REAL64  MP2_ReactiveEnergyDelivered;     /**< Reactive energy delivered [varh] */
    REAL64  MP2_ReactiveEnergyReceived;  /**< Reactive energy received [varh] */
} GM260_ENERGYREAL;

/**
 * Structure for DoCmd-function MIO_CMD_SETENERGYREAL_MP / MIO_CMD_GETENERGYREAL
 * Energy values REAL64
 * @since V1.03 Release
 */
typedef struct
{
    REAL64  ActiveEnergyDelivered;   /**< Active energy delivered [Wh] */
    REAL64  ActiveEnergyReceived;    /**< Active energy received [Wh] */
    REAL64  ReactiveEnergyDelivered;     /**< Reactive energy delivered [varh] */
    REAL64  ReactiveEnergyReceived;  /**< Reactive energy received [varh] */
} GM260_ENERGYREAL_MP;

/**
 * Structure for DoCmd-function MIO_CMD_GETVALUES / MIO_CMD_GETSELECTEDVALUES
 * All measured values
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  MP1_U_L1L2_RMS;     /**< Voltage U12 [mV] */
    UINT32  MP1_U_L2L3_RMS;     /**< Voltage U23 [mV] */
    UINT32  MP1_U_L3L1_RMS;     /**< Voltage U31 [mV] */
    UINT32  MP1_U_L1N_RMS;      /**< Voltage U1 [mV] */
    UINT32  MP1_U_L2N_RMS;      /**< Voltage U2 [mV] */
    UINT32  MP1_U_L3N_RMS;      /**< Voltage U3 [mV] */
    UINT32  MP1_I_L1_RMS;       /**< Current I1 [mA] */
    UINT32  MP1_I_L2_RMS;       /**< Current I2 [mA] */
    UINT32  MP1_I_L3_RMS;       /**< Current I3 [mA] */
    UINT32  MP1_I_N_RMS;        /**< Current IN [mA] */
    UINT32  MP1_f;              /**< Current frequency [mHz] */
    SINT32  MP1_Phi_U1I1;       /**< Phase angle between U1 and I1 [0.1°] */
    SINT32  MP1_Phi_U2I2;       /**< Phase angle between U2 and I2 [0.1°] */
    SINT32  MP1_Phi_U3I3;       /**< Phase angle between U3 and I3 [0.1°] */
    SINT32  Phi_U1U2;           /**< Phase angle between U1 and U2 [0.1°] */
    SINT32  Phi_U2U3;           /**< Phase angle between U2 and U3 [0.1°] */
    SINT32  Phi_U1U3;           /**< Phase angle between U1 and U3 [0.1°] */
    SINT32  MP1_PF_sum;         /**< Power factor Sum (0 - 1000) */
    SINT32  MP1_PF_L1;          /**< Power factor phase 1 (0 - 1000) */
    SINT32  MP1_PF_L2;          /**< Power factor phase 2 (0 - 1000) */
    SINT32  MP1_PF_L3;          /**< Power factor phase 3 (0 - 1000) */
    SINT32  MP1_P_sum;          /**< Sum real power [W] */
    SINT32  MP1_P_L1;           /**< Real power phase 1 [W] */
    SINT32  MP1_P_L2;           /**< Real power phase 2 [W] */
    SINT32  MP1_P_L3;           /**< Real power phase 3 [W] */
    SINT32  MP1_Q_sum;          /**< Sum reactive power [var] */
    SINT32  MP1_Q_L1;           /**< Reactive power phase 1 [var] */
    SINT32  MP1_Q_L2;           /**< Reactive power phase 2 [var] */
    SINT32  MP1_Q_L3;           /**< Reactive power phase 3 [var] */
    SINT32  MP1_S_sum;          /**< Sum apparent power [VA] */
    SINT32  MP1_S_L1;           /**< Apparent power phase 1 [VA] */
    SINT32  MP1_S_L2;           /**< Apparent power phase 2 [VA] */
    SINT32  MP1_S_L3;           /**< Apparent power phase 3 [VA] */
    UINT32  MP1_RotDir_U;       /**< Rotation direction of voltage. ROTATION_CW, ROTATION_CCW, ROTATION_UNKNOWN */
    UINT32  MP2_I_L1_RMS;       /**< Current I1 [mA] */
    UINT32  MP2_I_L2_RMS;       /**< Current I2 [mA] */
    UINT32  MP2_I_L3_RMS;       /**< Current I3 [mA] */
    UINT32  MP2_I_N_RMS;        /**< Current IN [mA] */
    SINT32  MP2_Phi_U1I1;       /**< Phase angle between U1 and I1 [0.1°] */
    SINT32  MP2_Phi_U2I2;       /**< Phase angle between U2 and I2 [0.1°] */
    SINT32  MP2_Phi_U3I3;       /**< Phase angle between U3 and I3 [0.1°] */
    SINT32  MP2_PF_sum;         /**< Power factor Sum (0 - 1000) */
    SINT32  MP2_PF_L1;          /**< Power factor phase 1 (0 - 1000) */
    SINT32  MP2_PF_L2;          /**< Power factor phase 2 (0 - 1000) */
    SINT32  MP2_PF_L3;          /**< Power factor phase 3 (0 - 1000) */
    SINT32  MP2_P_sum;          /**< Sum real power [W] */
    SINT32  MP2_P_L1;           /**< Real power phase 1 [W] */
    SINT32  MP2_P_L2;           /**< Real power phase 2 [W] */
    SINT32  MP2_P_L3;           /**< Real power phase 3 [W] */
    SINT32  MP2_Q_sum;          /**< Sum reactive power [var] */
    SINT32  MP2_Q_L1;           /**< Reactive power phase 1 [var] */
    SINT32  MP2_Q_L2;           /**< Reactive power phase 2 [var] */
    SINT32  MP2_Q_L3;           /**< Reactive power phase 3 [var] */
    SINT32  MP2_S_sum;          /**< Sum apparent power [VA] */
    SINT32  MP2_S_L1;           /**< Apparent power phase 1 [VA] */
    SINT32  MP2_S_L2;           /**< Apparent power phase 2 [VA] */
    SINT32  MP2_S_L3;           /**< Apparent power phase 3 [VA] */
} GM260_VALUES;

/**
 * Structure for DoCmd-function MIO_CMD_GETVALUES2 / MIO_CMD_GETSELECTEDVALUES2
 * All measured values
 * @since V1.03 Release
 */
typedef struct
{
    UINT32  U_L1L2_RMS;         /**< Voltage U12 [mV] */
    UINT32  U_L2L3_RMS;         /**< Voltage U23 [mV] */
    UINT32  U_L3L1_RMS;         /**< Voltage U31 [mV] */
    UINT32  U_L1N_RMS;          /**< Voltage U1 [mV] */
    UINT32  U_L2N_RMS;          /**< Voltage U2 [mV] */
    UINT32  U_L3N_RMS;          /**< Voltage U3 [mV] */
    UINT32  MP1_I_L1_RMS;       /**< Current I1 [mA] */
    UINT32  MP1_I_L2_RMS;       /**< Current I2 [mA] */
    UINT32  MP1_I_L3_RMS;       /**< Current I3 [mA] */
    UINT32  MP1_I_N_RMS;        /**< Current IN [mA] */
    UINT32  f;                  /**< Current frequency [mHz] */
    SINT32  MP1_Phi_U1I1;       /**< Phase angle between U1 and I1 [0.1°] */
    SINT32  MP1_Phi_U2I2;       /**< Phase angle between U2 and I2 [0.1°] */
    SINT32  MP1_Phi_U3I3;       /**< Phase angle between U3 and I3 [0.1°] */
    SINT32  Phi_U1U2;           /**< Phase angle between U1 and U2 [0.1°] */
    SINT32  Phi_U2U3;           /**< Phase angle between U2 and U3 [0.1°] */
    SINT32  Phi_U3U1;           /**< Phase angle between U3 and U1 [0.1°] */
    SINT32  MP1_PF_sum;         /**< Power factor Sum (0 - 1000) */
    SINT32  MP1_PF_L1;          /**< Power factor phase 1 (0 - 1000) */
    SINT32  MP1_PF_L2;          /**< Power factor phase 2 (0 - 1000) */
    SINT32  MP1_PF_L3;          /**< Power factor phase 3 (0 - 1000) */
    SINT32  MP1_P_sum;          /**< Sum real power [W] */
    SINT32  MP1_P_L1;           /**< Real power phase 1 [W] */
    SINT32  MP1_P_L2;           /**< Real power phase 2 [W] */
    SINT32  MP1_P_L3;           /**< Real power phase 3 [W] */
    SINT32  MP1_Q_sum;          /**< Sum reactive power [var] */
    SINT32  MP1_Q_L1;           /**< Reactive power phase 1 [var] */
    SINT32  MP1_Q_L2;           /**< Reactive power phase 2 [var] */
    SINT32  MP1_Q_L3;           /**< Reactive power phase 3 [var] */
    SINT32  MP1_S_sum;          /**< Sum apparent power [VA] */
    SINT32  MP1_S_L1;           /**< Apparent power phase 1 [VA] */
    SINT32  MP1_S_L2;           /**< Apparent power phase 2 [VA] */
    SINT32  MP1_S_L3;           /**< Apparent power phase 3 [VA] */
    UINT32  RotDir_U;           /**< Rotation direction of voltage. ROTATION_CW, ROTATION_CCW, ROTATION_UNKNOWN */
    UINT32  MP2_I_L1_RMS;       /**< Current I1 [mA] */
    UINT32  MP2_I_L2_RMS;       /**< Current I2 [mA] */
    UINT32  MP2_I_L3_RMS;       /**< Current I3 [mA] */
    UINT32  MP2_I_N_RMS;        /**< Current IN [mA] */
    SINT32  MP2_Phi_U1I1;       /**< Phase angle between U1 and I1 [0.1°] */
    SINT32  MP2_Phi_U2I2;       /**< Phase angle between U2 and I2 [0.1°] */
    SINT32  MP2_Phi_U3I3;       /**< Phase angle between U3 and I3 [0.1°] */
    SINT32  MP2_PF_sum;         /**< Power factor Sum (0 - 1000) */
    SINT32  MP2_PF_L1;          /**< Power factor phase 1 (0 - 1000) */
    SINT32  MP2_PF_L2;          /**< Power factor phase 2 (0 - 1000) */
    SINT32  MP2_PF_L3;          /**< Power factor phase 3 (0 - 1000) */
    SINT32  MP2_P_sum;          /**< Sum real power [W] */
    SINT32  MP2_P_L1;           /**< Real power phase 1 [W] */
    SINT32  MP2_P_L2;           /**< Real power phase 2 [W] */
    SINT32  MP2_P_L3;           /**< Real power phase 3 [W] */
    SINT32  MP2_Q_sum;          /**< Sum reactive power [var] */
    SINT32  MP2_Q_L1;           /**< Reactive power phase 1 [var] */
    SINT32  MP2_Q_L2;           /**< Reactive power phase 2 [var] */
    SINT32  MP2_Q_L3;           /**< Reactive power phase 3 [var] */
    SINT32  MP2_S_sum;          /**< Sum apparent power [VA] */
    SINT32  MP2_S_L1;           /**< Apparent power phase 1 [VA] */
    SINT32  MP2_S_L2;           /**< Apparent power phase 2 [VA] */
    SINT32  MP2_S_L3;           /**< Apparent power phase 3 [VA] */
    SINT32  Phi_U12U23;         /**< Phase angle between UL12 and UL23 [0.1°] */
    SINT32  Phi_U23U31;         /**< Phase angle between UL23 and UL31 [0.1°] */
    SINT32  Phi_U31U12;         /**< Phase angle between UL31 and UL12 [0.1°] */
} GM260_VALUES2;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
