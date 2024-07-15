/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     pn23.h
* @author   gmeiner
* @brief    PROFINET IO Server
*           This file contains all definitions and declarations exported by
*           the PROFINET IO Server.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef PN23__H
#define PN23__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>
#if M_OS_VXWORKS
#  include <svi_e.h>
#endif
#ifndef MAXHOSTNAMELEN
#define MAXHOSTNAMELEN  64
#endif

/**
 * @addtogroup PN23_API
 * @{
 */

/**
 * Defines
 */
/**
 * @name Warnings MIO functions
 * @{
 */

#define PN23_WRN_BUSY       0x01     /**< Job in execution */
#define PN23_WRN_DATA_STATE 0x02     /**< Remote data state BAD */
#define PN23_WRN_IRT_INCONS 0x03     /**< IRT access inconsistent */
/** @} */

/**
 * @name VendorId and DeviceId
 * @{
 */

#define PN23_M1_VENDOR_ID   0x012C   /**< VendorId Bachmann electronic */
#define PN23_M1_DEVICE_ID   0x0301   /**< DeviceId M1 */
/** @} */

/**
 * @name PROFINET Server Instance
 * @{
 */

#define PN23_MNAME  "PN23"
/** @} */

/**
 * @name PROFINET IO Alarms & Events
 * @{
 */

#define PN23_EV_PROCESS     0x00010000   /**< Process Alarm */
#define PN23_EV_DIAG_APP    0x00020000   /**< Diagnosis Alarm appears */
#define PN23_EV_DIAG_DIS    0x00040000   /**< Diagnosis Alarm disappears */
#define PN23_EV_DIAG        (PN23_EV_DIAG_APP | PN23_EV_DIAG_DIS)
#define PN23_EV_MOD_PLUG    0x00200000   /**< Plug Alarms */
#define PN23_EV_RET_OF_SUB  0x00400000
#define PN23_EV_REL_BY_SUP  0x00800000
#define PN23_EV_PLUG        (PN23_EV_MOD_PLUG | PN23_EV_RET_OF_SUB | PN23_EV_REL_BY_SUP)
#define PN23_EV_MOD_PULL    0x01000000   /**< Pull Alarms */
#define PN23_EV_PLUG_WRONG  0x02000000
#define PN23_EV_CON_BY_SUP  0x04000000
#define PN23_EV_PULL        (PN23_EV_MOD_PULL | PN23_EV_PLUG_WRONG | PN23_EV_CON_BY_SUP)
#define PN23_EV_INDATA      0x08000000   /**< Indata Alarm (first data transfer) */
#define PN23_EV_ABORT       0x10000000   /**< Abort Alarm */
#define PN23_EV_OFFLINE     0x20000000   /**< Offline Alarm */
#define PN23_EV_STATUS      0x40000000   /**< ApduStatus-Change */
#define PN23_EV_CTRL        (PN23_EV_ABORT | PN23_EV_OFFLINE | PN23_EV_STATUS)
#define PN23_EV_CYCLESTART  0x80000000   /**< IRT cycle start */
/** @} */

/**
 * @name PROFINET Debug Modes
 * @{
 */

#define PN23_DBG_INFO1  0x01
#define PN23_DBG_INFO2  0x02
/** @} */
/**
 * Structures
 */
typedef struct
{
    UINT16  ChanNum;
    UINT16  ChanProp;
    UINT16  ChanErrType;
} PN23_DIAG_ALARM;

/**
 * PN23 states
 */
typedef enum
{
    IOC_AR_DEFAULT          = 0,     /**< reserved */
    IOC_AR_OFFLINE          = 1,     /**< AR offline */
    IOC_AR_START            = 2,     /**< AR connecting till InData */
    IOC_AR_APPL_READY       = 3,     /**< AR RTC3 follows */
    IOC_AR_APPL_READY_ARP   = 4,     /**< AR RTC3 follows wit application ready pending */
    IOC_AR_INDATA           = 5,     /**< AR InData */
    IOC_AR_INDATA_ARP       = 6,     /**< AR InData with application ready pending */
    IOC_AR_PASSIVE          = 7,     /**< AR passive */
    IOC_AR_STATE_MAX,
} PN23_AR_STATE;

/**
 * PN23 reasons
 */
typedef enum
{
    PN23_REASON_NONE        = 0,     /**< 0x00: none */
    PN23_REASON_1           = 1,     /**< 0x01: sequence numbers do not match (no longer used in versions >= V3.9) */
    PN23_REASON_2           = 2,     /**< 0x02: alarm instance closed (no longer used in versions >= V3.6) */
    PN23_REASON_MEM         = 3,     /**< 0x03: out of mem */
    PN23_REASON_FRAME       = 4,     /**< 0x04: add provider or consumer failed */
    PN23_REASON_MISS        = 5,     /**< 0x05: miss (consumer) */
    PN23_REASON_TIMER       = 6,     /**< 0x06: cmi timeout */
    PN23_REASON_ALARM       = 7,     /**< 0x07: alarm-open failed */
    PN23_REASON_ALSND       = 8,     /**< 0x08: alarm-send.cnf(-) */
    PN23_REASON_ALACK       = 9,     /**< 0x09: alarm-ack-send.cnf(-) */
    PN23_REASON_ALLEN       = 10,    /**< 0x0A: alarm-data too long */
    PN23_REASON_ASRT        = 11,    /**< 0x0B: alarm.ind(err) */
    PN23_REASON_RPC         = 12,    /**< 0x0C: rpc-client call.cnf(-) */
    PN23_REASON_ABORT       = 13,    /**< 0x0D: ar-abort.req */
    PN23_REASON_RERUN       = 14,    /**< 0x0E: rerun aborts existing */
    PN23_REASON_REL         = 15,    /**< 0x0F: got release.ind */
    PN23_REASON_PAS         = 16,    /**< 0x10: device passivated */
    PN23_REASON_RMV         = 17,    /**< 0x11: device / AR removed */
    PN23_REASON_PROT        = 18,    /**< 0x12: protocol violation */
    PN23_REASON_NARE        = 19,    /**< 0x13: NARE error */
    PN23_REASON_BIND        = 20,    /**< 0x14: RPC-Bind error */
    PN23_REASON_CONNECT     = 21,    /**< 0x15: RPC-Connect error */
    PN23_REASON_READ        = 22,    /**< 0x16: RPC-Read error */
    PN23_REASON_WRITE       = 23,    /**< 0x17: RPC-Write error */
    PN23_REASON_CONTROL     = 24,    /**< 0x18: RPC-Control error */
    PN23_REASON_PULLPLUG    = 25,    /**< 0x19: forbidden pull or plug after check.rsp and before in-data.ind */
    PN23_REASON_26          = 26,    /**< 0x1A: reserved (formerly: AP removed) */
    PN23_REASON_LNK_DWN     = 27,    /**< 0x1B: link "down" */
    PN23_REASON_MMAC        = 28,    /**< 0x1C: could not register multicast-mac */
    PN23_REASON_SYNC        = 29,    /**< 0x1D: not synchronized (cannot start companion-ar) */
    PN23_REASON_TOPO        = 30,    /**< 0x1E: wrong topology (cannot start companion-ar) */
    PN23_REASON_DCP_NAME    = 31,    /**< 0x1F: dcp, station-name changed */
    PN23_REASON_DCP_RESET   = 32,    /**< 0x20: dcp, reset to factory-settings */
    PN23_REASON_33          = 33,    /**< 0x21: reserved (formerly: cannot start companion-ar) */
    PN23_REASON_IRDATA      = 34,    /**< 0x22: no irdata record yet */
    PN23_REASON_PDEV        = 35,    /**< 0x23: ownership of physical device */
    PN23_REASON_LNK_MODE    = 36,    /**< 0x24: link mode not full duplex */
} PN23_REASON_CODE;


/** @} */

/**
 * @addtogroup PN23_SMI
 * @{
 */

/**
 * @name SMI Commands
 * @{
 */

#define PN23_PROC_SETNAME   100  /**< Set device name */
/** @} */
/**
 * Structure for the SMI-Call #PN23_PROC_SETNAME
 */
typedef struct
{
    UINT32  NetNb;
    UINT32  Spare;
    UINT8   MAC[6];
    UINT8   Align[2];
    UINT8   IdentName[MAXHOSTNAMELEN];
} PN23_SETNAME_C;

/**
 * Structure for the SMI-Reply #PN23_PROC_SETNAME
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} PN23_SETNAME_R;


#ifdef __cplusplus
}
#endif

/** @} */

#endif
