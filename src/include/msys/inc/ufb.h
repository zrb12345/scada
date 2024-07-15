/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     ufb.h
* @author   Dornerm
* @brief    UFB conform IO-Driver Handler
*           This file contains all definitions and declarations exported by
*           a UFB conform IO-Driver Handler, that could be used by modules running
*           on another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef UFB__H
#define UFB__H

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
 * @addtogroup UFB_API
 * @{
 */

/**
 * @name Defines
 * @{
 */


/**
 * @name Defines for MBus
 * @{
 */

#define MBUS_MAXSTRING  50  /**< Maximal string length for MBus */
/** @} */

/**
 * @name Channel configuration flags: (r)ead, (w)rite, (p)lc, (s)vi (x)ch, (a)cyclic
 * @{
 */

#define UFB_CFL_READ    0x01     /**< 'r' */
#define UFB_CFL_WRITE   0x02     /**< 'w' */
#define UFB_CFL_RW      0x03     /**< 'rw' */
#define UFB_CFL_SVI     0x04     /**< 's' */
#define UFB_CFL_PLC     0x10     /**< 'p' */
#define UFB_CFL_EXC     0x20     /**< 'x' Motorola/Intel-Format (MSB/LSB first) */
#define UFB_CFL_ACY     0x40     /**< 'a' */
/** @} */
/** @} */

/**
 * @addtogroup MOD_SMI
 * @{
 */

/**
 * @name Common SMI-Calls, supported by the different fieldbus network servers
 * @{
 */

#define UFB_PROC_SCANCONTROL    1000     /**< Bus-Scan Control (Start, Stop, Progress...) */
#define UFB_PROC_GETSCANDATA    1002     /**< Scanned device data */
/** @} */

/**
 * @name Fieldbus network scan control commands
 * @{
 */

#define UFB_SCAN_CMD_START      1    /**< Starts a new network scan */
#define UFB_SCAN_CMD_PROGRESS   2    /**< Ask for the progress state of the started bus scan */
#define UFB_SCAN_CMD_STOP       3    /**< Stops the bus scan at current node */
#define UFB_SCAN_CMD_TERMINATE  4    /**< Aborts and/or close the scan (data freed ready, for new scan) */
/** @} */

/**
 * @name Fieldbus network scan version of reply data structure
 * @{
 */

#define UFB_SCAN_VER_ECAT       1    /**< EtherCAT */
#define UFB_SCAN_VER_PROFINET   1    /**< Profinet */
#define UFB_SCAN_VER_CAN        1    /**< CAN */
#define UFB_SCAN_VER_MBUS       1    /**< MBUS */
/** @} */

/**
 * @name Possible error codes for UFB_*.RetCode
 * @{
 */

#define UFB_E_OK            M_E_OK   /**< O.K., done, no error */
#define UFB_E_INPROGRESS    M_E_INPROGRESS   /**< Still in progress, no error */
#define UFB_E_PARM          (M_ES_UFB | M_E_PARM)    /**< Parameter not valid */
#define UFB_E_LOCKED        (M_ES_UFB | M_E_LOCKED)  /**< Access to bus scan is locked (scan is in progress) */
#define UFB_E_BADSESS       (M_ES_UFB | M_E_BADSESS)     /**< Session ID not valid */
#define UFB_E_NETNB         (M_ES_UFB | M_E_NETNB)   /**< Fieldbus network number not valid */
#define UFB_E_NODEID        (M_ES_UFB | M_E_NODEID)  /**< Fieldbus network node id, mac id not valid */
#define UFB_E_BADRANGE      (M_ES_UFB | M_E_BADRANGE)    /**< Scan range is not valid */
#define UFB_E_OFFLINE       (M_ES_UFB | M_E_OFFLINE)     /**< No connection to bus or device */
/** @} */
/** @} */

/**
 * @name Structures
 * @{
 */

/**
 * Information about the network to scan
 */
typedef union
{
    /**
     * EtherCAT
     */
    struct
    {
        UINT32  NetNb;              /**< EtherCAT network number */
    } Ecat;
    /**
     * ProfiNet
     */
    struct
    {
        UINT32  NetNb;              /**< ProfiNet network number */
        UINT32  MaxNodes;           /**< Maximum number of nodes to scan */
    } ProfiNet;
    /**
     * CANopen
     */
    struct
    {
        UINT32  NetNb;              /**< CANopen network number */
        UINT32  MaxNodes;           /**< Maximum number of nodes to scan */
        UINT32  FirstNode;          /**< Scan starts at node number */
    } Can;
    /**
     * MBus
     */
    struct
    {
        UINT32  NetNb;              /**< MBus network number */
    } Mbus;
    UINT32  Spare[16];          /**< Maybe an other fieldbus needs more scan-info */
} UFB_SCANINFO;

/**
 * EtherCAT
 */
typedef struct
{
    UINT32  VendorId;
    UINT32  ProductCode;
    UINT32  SerialNb;
    UINT32  RevisionNb;
    UINT16  PortState;
    UINT16  AliasAddr;
    UINT32  DcSupport;
    UINT32  Dc64Support;
} UFB_SCANDATA_ECAT;

/**
 * ProfiNet
 */
typedef struct
{
    UINT8   MAC[6];
    UINT16  Align;
    UINT32  IpAddr;
    UINT32  Subnet;
    UINT8   Role;
    CHAR8   IdentType[MAXHOSTNAMELEN];
    CHAR8   IdentName[MAXHOSTNAMELEN];
} UFB_SCANDATA_PROFINET;

/**
 * MBus
 */
typedef struct
{
    UINT32  VendorId;           /**< Vendor specific and unique ID */
    UINT32  Version;            /**< Device version */
    CHAR16  Medium[MBUS_MAXSTRING];  /**< eg gas or water */
    UINT32  NbOfChan;           /**< Number of channels available */
    UINT32  Spare[16];          /**< Until know not in use */
} UFB_SCANDATA_MBUS;

/**
 * Scan result of one scanned node
 */
typedef union
{
    UFB_SCANDATA_ECAT       Ecat[1];
    UFB_SCANDATA_PROFINET   ProfiNet[1];
    UFB_SCANDATA_MBUS       Mbus[1];
} UFB_SCANDATA;

/**
 * Structure for the SMI-Call #UFB_PROC_SCANCONTROL
 */
typedef struct
{
    UINT32          Cmd;        /**< Scan control command */
    UINT32          Timeout;    /**< Timeout (seconds) for implicit abort of scan */
    UINT32          SessionId;  /**< Scan session id */
    UFB_SCANINFO    ScanInfo;   /**< Information for starting the network scan */
} UFB_SCANCONTROL_C;

/**
 * Structure for the SMI-Reply #UFB_PROC_SCANCONTROL
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Version;            /**< Version of reply data structure */
    UINT32  SessionId;          /**< Scan session id */
    UINT32  ProgressDone;       /**< Progress indicator done */
    UINT32  ProgressTotal;      /**< Progress indicator total */
    UINT32  NodeCount;          /**< Number of found devices */
    UINT32  NodeSize;           /**< Size of data for one node */
} UFB_SCANCONTROL_R;

/**
 * Structure for the SMI-Call #UFB_PROC_GETSCANDATA
 */
typedef struct
{
    UINT32  SessionId;          /**< Scan session id */
    UINT32  FirstIdx;           /**< Index of the first node from scan result list */
    UINT32  LastIdx;            /**< Index of the last node in the list */
} UFB_GETSCANDATA_C;

/**
 * Structure for the SMI-Reply #UFB_PROC_GETSCANDATA
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NodeCount;  /**< Number of returned nodes in ScanData */
    UINT32          SessionId;  /**< Scan session id */
    UFB_SCANDATA    ScanData;   /**< Scan result */
} UFB_GETSCANDATA_R;

/**
 * UFB extended channel display modes
 */
typedef enum _UFB_DISP_MODE
{
    UFB_DISP_MODE_RAW_DEZ   = 0,
    UFB_DISP_MODE_RAW_HEX   = 1,
    UFB_DISP_MODE_DEC       = 2,
    UFB_DISP_MODE_HEX       = 3,
    UFB_DISP_MODE_REAL      = 4,
    UFB_DISP_MODE_ENG       = 5,
} UFB_DISP_MODE;

/**
 * UFB SI-Units
 */
typedef enum _UFB_SIUNIT
{
    UFB_SIUNIT_NONE         = 0,
    UFB_SIUNIT_METER        = 1,
    UFB_SIUNIT_KILO         = 2,
    UFB_SIUNIT_SECOND       = 3,
    UFB_SIUNIT_AMPERE       = 4,
    UFB_SIUNIT_KELVIN       = 5,
    UFB_SIUNIT_MOL          = 6,
    UFB_SIUNIT_CANDELA      = 7,
    UFB_SIUNIT_RADIANT      = 8,
    UFB_SIUNIT_STERAD       = 9,
    UFB_SIUNIT_HERTZ        = 10,
    UFB_SIUNIT_NEWTON       = 11,
    UFB_SIUNIT_PASCAL       = 12,
    UFB_SIUNIT_JOULE        = 13,
    UFB_SIUNIT_WATT         = 14,
    UFB_SIUNIT_VOLT         = 15,
    UFB_SIUNIT_COULOMB      = 16,
    UFB_SIUNIT_WEBER        = 17,
    UFB_SIUNIT_OHM          = 18,
    UFB_SIUNIT_SIEMENS      = 19,
    UFB_SIUNIT_HENRY        = 20,
    UFB_SIUNIT_FARAD        = 21,
    UFB_SIUNIT_TESLA        = 22,
    UFB_SIUNIT_CELSIUS      = 23,
    UFB_SIUNIT_LUMEN        = 24,
    UFB_SIUNIT_LUX          = 25,
    UFB_SIUNIT_BECQUEREL    = 26,
    UFB_SIUNIT_GRAY         = 27,
    UFB_SIUNIT_SIEVERT      = 28,
    UFB_SIUNIT_KATAL        = 29,
} UFB_SIUNIT;


typedef struct _UFB_EXTCHANCFG  /**< UFB extended channel configuration */
{
    UINT32      Configured:1;   /**< Set, if channel is configured (no default Values) */
    UINT32      DispMode:7;     /**< Display Mode: UFB_DISP_MODE (default: UFB_DISP_MODE_RAW_DEZ) */
    UINT32      SiUnit:8;       /**< SI-Unit:  UFB_SIUNIT (default: UFB_SIUNIT_NONE) */
    REAL32      Scale;          /**< Scaling factor (default: 1.0) */
    REAL32      Offset;         /**< Offset (default: 0.0) */
    REAL32      Min;            /**< Minimum value (default: minimum of SVI_F_* value type) */
    REAL32      Max;            /**< Maximum value (default: maximum of SVI_F_* value type) */
    CHAR8       UnitStr[12];    /**< Physical unit optional text (e.g. "V", "RPM", "uA", "bar") */
} UFB_EXTCHANCFG;


/* Channel Configuration */
typedef struct _UFB_BITINF       /**< UFB BitInfo */
{
    UINT32  Len:31;              /**< Length in bit */
    UINT32  BitArray:1;          /**< Set, if channel is a bit array */
    UINT32  Offs;                /**< Offset in bit */
} UFB_BITINF;

typedef struct _UFB_SVINF           /**< Info to SVI variable */
{
    CHAR8   Name[SVI_ADDRLEN_A];    /**< Symbolic name */
    UINT16  Format;                 /**< Format of variable */
    UINT16  Len;                    /**< Size of variable */
} UFB_SVIINF;

typedef struct _UFB_CHANCFG         /**< UFB channel configuration */
{
    UFB_SVIINF  SviInf;             /**< UFB SVI variable info */
    UFB_BITINF  BitInf;             /**< UFB Bit info */
    UINT32      Categ;              /**< MIO_CATEG_XXX IO_CHANINF.Category */
    UINT16      Cfl;                /**< UFB_CFL_XXX Configuration Flags */
    UFB_EXTCHANCFG ExtCfg;          /**< Extended Channel Configuration */
} UFB_CHANCFG;


/* transport container */
typedef enum _UFB_DOCMD_TYPE
{
    UFB_GET_CHANCFG_BYVAL = 0,      /**< for general use (data are copied) */
    UFB_GET_CHANCFG_BYREF = 1,      /**< only for use in system space */
} UFB_CMD_TYPE;

typedef struct _UFB_CHAN_CONTAINER
{
    UFB_CMD_TYPE Type;          /**< identifies the container data [0..n] */
    union {
        UFB_CHANCFG  ByVal;     /**< UFB_GET_CHANCFG_BYVAL: general use */
        UFB_CHANCFG *ByRef;     /**< UFB_GET_CHANCFG_BYREF: use in system space*/
    } Common;
} UFB_CMD_CONTAINER;
/** @} */
/** @} */

#ifdef __cplusplus
}
#endif

#endif
