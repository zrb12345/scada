/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     pn.h
* @author   dornerm
* @brief    PROFINET IO Server
*           This file contains all definitions and declarations exported by
*           the PROFINET IO Server.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef PN__H
#define PN__H

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @name Defines
 * @{
 */

#include <mtypes.h>
#if M_OS_VXWORKS
#  include <svi_e.h>
#endif
#ifndef MAXHOSTNAMELEN
#define MAXHOSTNAMELEN  64
#endif

/**
 * @addtogroup PN201_API
 * @{
 */

/**
 * @name VendorId and DeviceId
 * @{
 */

#define PN_M1_VENDOR_ID         0x012C   /**< VendorId Bachmann Electronic */
#define PN_M1_DEVICE_ID         0x0301   /**< DeviceId M1 */
#define PN_SIEMENS_VENDOR_ID    0x002A   /**< VendorId Siemens */
#define PN_ET200S_DEVICE_ID     0x0301   /**< DeviceId ET200S */
#define PN_PHOENIX_VENDOR_ID    0x00B0   /**< VendorId Phoenix Contact */
/** @} */

/**
 * @name Default StationName and StationType
 * @{
 */

#define PN_M1_STATION_NAME  "PN-M1-Station"
#define PN_M1_STATION_TYPE  "PN-M1-Station"
/** @} */

/**
 * @name PROFINET Server Instance
 * @{
 */

#define PN_MNAME    "PN"
/** @} */

/**
 * @name (Sub-)Module Plug State
 * @{
 */

#define PN_STATE_PLUGGED        1
#define PN_STATE_NOT_PLUGGED    0
/** @} */

/**
 * @name Error codes returned by mio_GetError()
 * @{
 */

#define PN_E_BADIOPS    0x00010000   /**< Bad IOPS */
#define PN_E_BADIOCS    0x00020000   /**< Bad IOCS */
#define PN_E_DIAG_APP   0x00100000   /**< Diagnosis alarm appeared */
/** @} */

/**
 * @name PROFINET IO Alarms & Events that can be registered by mio_AttachEvent()
 * @{
 */

#define PN_EV_PROCESS       0x00010000   /**< Process alarm */
#define PN_EV_MOD_PLUG      0x00200000   /**< Module plug alarm */
#define PN_EV_RET_OF_SUB    0x00400000   /**< Return of submodule alarm */
#define PN_EV_REL_BY_SUP    0x00800000   /**< Released by supervisor alarm */
#define PN_EV_PLUG          (PN_EV_MOD_PLUG | PN_EV_RET_OF_SUB | PN_EV_REL_BY_SUP)
#define PN_EV_MOD_PULL      0x01000000   /**< Module pull alarm */
#define PN_EV_PLUG_WRONG    0x02000000   /**< Plugged wrong */
#define PN_EV_CON_BY_SUP    0x04000000   /**< Controlled by supervisor */
#define PN_EV_PULL          (PN_EV_MOD_PULL | PN_EV_PLUG_WRONG | PN_EV_CON_BY_SUP)
#define PN_EV_INDATA        0x08000000   /**< Indata alarm (first data transfer) */
#define PN_EV_RECV_FRAME    0x80000000   /**< New data frame received */
/** @} */

/**
 * @name PROFINET IO Alarms & Events that can be registered by mio_AttachError()
 * @{
 */

#define PN_EV_CHAN_DIAG_APP 0x00020000   /**< Diagnosis alarm appears */
#define PN_EV_CHAN_DIAG_DIS 0x00040000   /**< Diagnosis alarm disappears */
#define PN_EV_GEN_DIAG_APP  0x00080000   /**< Generic alarm appears */
#define PN_EV_GEN_DIAG_DIS  0x00100000   /**< Generic alarm disappears */
#define PN_EV_DIAG          (PN_EV_CHAN_DIAG_APP | PN_EV_CHAN_DIAG_DIS | PN_EV_GEN_DIAG_APP | PN_EV_GEN_DIAG_DIS)
#define PN_EV_ABORT         0x10000000   /**< Abort alarm */
#define PN_EV_OFFLINE       0x20000000   /**< Offline alarm */
#define PN_EV_STATUS        0x40000000   /**< Apdu status change */
#define PN_EV_CTRL          (PN_EV_ABORT | PN_EV_OFFLINE | PN_EV_STATUS)
/** @} */

/**
 * @name PROFINET Debug Modes
 * @{
 */

#define PN_DBG_INFO1    0x01
#define PN_DBG_INFO2    0x02
/** @} */
/** @} */

/**
 * @addtogroup PN201_SMI
 * @{
 */

/**
 * @name Possible SMI Commands
 * @{
 */

#define PN_PROC_SEARCHDEV       100  /**< Search PROFINET IO Devices */
#define PN_PROC_SETNAME         102  /**< Set StationName of a device */
#define PN_PROC_SETADDR         104  /**< Set IP address of a device */
#define PN_PROC_BLINK           106  /**< Blink LEDs of a device */
#define PN_PROC_GETIF           108  /**< Get all configured interfaces */
#define PN_PROC_EXTSEARCHDEV    110  /**< Search PROFINET IO Devices */
#define PN_PROC_EXTSETNAME      112  /**< Set StationName of a device */
#define PN_PROC_EXTSETADDR      114  /**< Set IP address of a device */
#define PN_PROC_EXTBLINK        116  /**< Blink LEDs of a device */
/** @} */
/** @} */

/**
 * @name Structures
 * @{
 */

typedef struct
{
    UINT16  ChanNum;
    UINT16  ChanProp;
    UINT16  ChanErrType;
} PN_DIAG_ALARM;

typedef struct
{
    UINT16  ChanNum;
    UINT16  ChanProp;
    UINT16  ChanErrType;
    UINT16  ExtChanErrType;
    UINT32  ExtChanAddValue;
} PN_EXTDIAG_ALARM;

/**
 * Structure for the SMI-Call #PN_PROC_EXTSEARCHDEV
 */
typedef struct
{
    SINT32  MaxNodes;
    UINT32  NetNb;
    UINT32  Spare;
} PN_EXTSEARCHDEV_C;

/**
 * Structure for the SMI-Reply #PN_PROC_EXTSEARCHDEV
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} PN_EXTSEARCHDEV_R;

typedef struct
{
    UINT8   MAC[6];
    UINT32  IpAddr;
    UINT32  Subnet;
    UINT8   Role;
    UINT8   IdentType[MAXHOSTNAMELEN];
    UINT8   IdentName[MAXHOSTNAMELEN];
} PN_SEARCHRES;

/**
 * Structure for the SMI-Call #PN_PROC_SEARCHDEV
 */
typedef struct
{
    SINT32  MaxNodes;
} PN_SEARCHDEV_C;

/**
 * Structure for the SMI-Reply #PN_PROC_SEARCHDEV
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    SINT32          NodeCnt;
    PN_SEARCHRES    Result[0];
} PN_SEARCHDEV_R;

/**
 * Structure for the SMI-Call #PN_PROC_EXTSETNAME
 */
typedef struct
{
    UINT8   MAC[6];
    UINT8   IdentName[MAXHOSTNAMELEN];
    UINT32  NetNb;
    UINT32  Spare;
} PN_EXTSETNAME_C;

/**
 * Structure for the SMI-Reply #PN_PROC_EXTSETNAME
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} PN_EXTSETNAME_R;

/**
 * Structure for the SMI-Call #PN_PROC_SETNAME
 */
typedef struct
{
    UINT8   MAC[6];
    UINT8   IdentName[MAXHOSTNAMELEN];
} PN_SETNAME_C;

/**
 * Structure for the SMI-Reply #PN_PROC_SETNAME
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} PN_SETNAME_R;

/**
 * Structure for the SMI-Call #PN_PROC_EXTSETADDR
 */
typedef struct
{
    UINT8   MAC[6];
    UINT32  IpAddr;
    UINT32  Subnet;
    UINT32  DefRoute;
    UINT32  NetNb;
    UINT32  Spare;
} PN_EXTSETADDR_C;

/**
 * Structure for the SMI-Reply #PN_PROC_EXTSETADDR
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} PN_EXTSETADDR_R;

/**
 * Structure for the SMI-Call #PN_PROC_SETADDR
 */
typedef struct
{
    UINT8   MAC[6];
    UINT32  IpAddr;
    UINT32  Subnet;
    UINT32  DefRoute;
} PN_SETADDR_C;

/**
 * Structure for the SMI-Reply #PN_PROC_SETADDR
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} PN_SETADDR_R;

/**
 * Structure for the SMI-Call #PN_PROC_EXTBLINK
 */
typedef struct
{
    UINT8   MAC[6];
    UINT32  NetNb;
    UINT32  Spare;
} PN_EXTBLINK_C;

/**
 * Structure for the SMI-Reply #PN_PROC_EXTBLINK
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} PN_EXTBLINK_R;

/**
 * Structure for the SMI-Call #PN_PROC_BLINK
 */
typedef struct
{
    UINT8   MAC[6];
} PN_BLINK_C;

/**
 * Structure for the SMI-Reply #PN_PROC_BLINK
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} PN_BLINK_R;

typedef struct
{
    UINT32  NetNb;              /**< 0=Default */
    CHAR8   Name[8];
    UINT32  Spare;
} PN_IFDATA;

/**
 * Structure for the SMI-Call #PN_PROC_GETIF
 */
typedef struct
{
    UINT32  Spare1;
    UINT32  Spare2;
} PN_GETIF_C;

/**
 * Structure for the SMI-Reply #PN_PROC_GETIF
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    SINT32      IfCnt;
    UINT32      Spare;
    PN_IFDATA   If[0];
} PN_GETIF_R;

/** @} */
/** @} */

#ifdef __cplusplus
}
#endif

#endif
