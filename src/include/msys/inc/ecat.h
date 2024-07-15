/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     ecat.h
* @author   dorner
* @brief    EtherCAT
*           This file contains all EtherCAT definitions and declarations.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef ECAT__H
#define ECAT__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>
#include <msys.h>

/**
 * @addtogroup ECAT_API
 * @{
 */

/**
 * @name Defines
 * @{
 */

#define P __attribute__((packed))

/**
 * @name Master and Slave States
 * @{
 */

#define EC_STATE_UNKNOWN    0x00
#define EC_STATE_INIT       0x01
#define EC_STATE_PREOP      0x02
#define EC_STATE_BOOTSTRAP  0x03
#define EC_STATE_SAFEOP     0x04
#define EC_STATE_OP         0x08
#define EC_STATE_ERROR      0x10
/** @} */

/**
 * @name EtherCAT Debug Modes
 * @{
 */

#define EC_DBG_INFO1    0x01     /**< Normal */
#define EC_DBG_INFO2    0x02     /**< Extended */
#define EC_DBG_INFO4    0x04     /**< Stack */
#define EC_DBG_INFO8    0x08     /**< Debug */
/** @} */

/**
 * @name Possible modes for file write (FoE)
 * @{
 */

#define EC_FILE_WRITE       1    /**< Write file */
#define EC_FILE_PROGRESS    2    /**< Get progress */
/** @} */

/**
 * @name Possible SMI Commands
 * @{
 */

#define EC_PROC_GETIF           100  /**< Get all EtherCAT interfaces */
#define EC_PROC_BUSSCAN         102  /**< Start bus scan */
#define EC_PROC_GETSLAVEINFO    104  /**< Get EtherCAT slave info */
#define EC_PROC_SDOREAD         110  /**< Read SDO */
#define EC_PROC_SDOWRITE        112  /**< Write SDO */
#define EC_PROC_GETOBJDICT      114  /**< Get object dictionary */
#define EC_PROC_GETOBJDESC      116  /**< Get object description */
#define EC_PROC_GETOBJENTRY     118  /**< Get object entry description */
#define EC_PROC_WRITEALIAS      120  /**< Set slave alias address */
#define EC_PROC_FILEREAD        122  /**< read File (not yet supported) */
#define EC_PROC_FILEWRITE       124  /**< write File */
#define EC_PROC_GETMASTERSTATE  126  /**< get state of master */
#define EC_PROC_SETMASTERSTATE  128  /**< set state of master */
#define EC_PROC_GETSLAVESTATE   130  /**< get state of slave */
#define EC_PROC_SETSLAVESTATE   132  /**< set state of slave */
/** @} */

/**
 * @name SMI Error Codes
 * @{
 */

#define EC_EC_OK        0   /**< Everything OK */
#define EC_EC_FAILED    (M_ES_EC | M_E_FAILED)   /**< General error */
#define EC_EC_PARM      (M_ES_EC | M_E_PARM)     /**< Wrong parameter */
#define EC_EC_TIMEOUT   (M_ES_EC | M_E_TIMEOUT)  /**< Timeout in execution */
/** @} */

/**
 * @name EtherCAT IO Events & Errors
 * @{
 */

#define EC_EV_STATE 0x00010000   /**< Master state change */
#define EC_EV_SYNC  0x00020000   /**< SYNC state */
#define EC_EV_ERROR 0x01000000   /**< General error */
#define EC_EV_EMCY  0x02000000   /**< CoE Emergency */
/** @} */

/**
 * @name CoE Entry description 'ValueInfo' information
 * @{
 */

#define EC_COE_OBJACCESS    0x01
#define EC_COE_OBJCATEGORY  0x02
#define EC_COE_PDOMAPPING   0x04
#define EC_COE_UNITTYPE     0x08
#define EC_COE_DEFVALUE     0x10
#define EC_COE_MINVALUE     0x20
#define EC_COE_MAXVALUE     0x40
/** @} */

/**
 * @name CoE Entry description 'ObAccess' definitions
 * @{
 */

#define EC_COE_ACCESS_R_PREOP   0x01
#define EC_COE_ACCESS_R_SAFEOP  0x02
#define EC_COE_ACCESS_R_OP      0x04
#define EC_COE_ACCESS_W_PREOP   0x08
#define EC_COE_ACCESS_W_SAFEOP  0x10
#define EC_COE_ACCESS_W_OP      0x20
/** @} */

/**
 * @name Notification Error Codes
 * @{
 */

#define EC_NOTIFY_ERROR                         0x80010000
#define EC_NOTIFY_CYCCMD_WKC_ERROR              (EC_NOTIFY_ERROR | 1)    /**< Cyclic command: working counter error */
#define EC_NOTIFY_MASTER_INITCMD_WKC_ERROR      (EC_NOTIFY_ERROR | 2)    /**< Master init command: working counter error */
#define EC_NOTIFY_SLAVE_INITCMD_WKC_ERROR       (EC_NOTIFY_ERROR | 3)    /**< Slave init command: working counter error */
#define EC_NOTIFY_EOE_MBXRCV_WKC_ERROR          (EC_NOTIFY_ERROR | 4)    /**< EOE mbox receive: working counter error (obsolete) */
#define EC_NOTIFY_COE_MBXRCV_WKC_ERROR          (EC_NOTIFY_ERROR | 5)    /**< COE mbox receive: working counter error (obsolete) */
#define EC_NOTIFY_FOE_MBXRCV_WKC_ERROR          (EC_NOTIFY_ERROR | 6)    /**< FOE mbox receive: working counter error (obsolete) */
#define EC_NOTIFY_EOE_MBXSND_WKC_ERROR          (EC_NOTIFY_ERROR | 7)    /**< EOE mbox send: working counter error */
#define EC_NOTIFY_COE_MBXSND_WKC_ERROR          (EC_NOTIFY_ERROR | 8)    /**< COE mbox send: working counter error */
#define EC_NOTIFY_FOE_MBXSND_WKC_ERROR          (EC_NOTIFY_ERROR | 9)    /**< FOE mbox send: working counter error */
#define EC_NOTIFY_FRAME_RESPONSE_ERROR          (EC_NOTIFY_ERROR | 10)   /**< Got no response on a sent Ethernet frame */
#define EC_NOTIFY_SLAVE_INITCMD_RESPONSE_ERROR  (EC_NOTIFY_ERROR | 11)   /**< Got no response on a sent ecat init command from slave */
#define EC_NOTIFY_MASTER_INITCMD_RESPONSE_ERROR (EC_NOTIFY_ERROR | 12)   /**< Got no response on a sent ecat master init command */
#define EC_NOTIFY_CMD_MISSING                   (EC_NOTIFY_ERROR | 13)   /**< Missing ecat command in received ethernet frame (obsolete) */
#define EC_NOTIFY_MBSLAVE_INITCMD_TIMEOUT       (EC_NOTIFY_ERROR | 14)   /**< Timeout when waiting for mailbox init command response */
#define EC_NOTIFY_NOT_ALL_DEVICES_OPERATIONAL   (EC_NOTIFY_ERROR | 15)   /**< Not all slave devices are in operational state when receiving cyclic frames */
#define EC_NOTIFY_ETH_LINK_NOT_CONNECTED        (EC_NOTIFY_ERROR | 16)   /**< Ethernet link (cable) not connected */
#define EC_NOTIFY_CYCCMD_TIMEOUT                (EC_NOTIFY_ERROR | 17)   /**< Cyclic command timeout (obsolete) */
#define EC_NOTIFY_STATUS_SLAVE_ERROR            (EC_NOTIFY_ERROR | 19)   /**< At least one slave is in error state when receiving cyclic frames (BRD AL-STATUS) */
#define EC_NOTIFY_SLAVE_ERROR_STATUS_INFO       (EC_NOTIFY_ERROR | 20)   /**< Slave Error status information */
#define EC_NOTIFY_SLAVE_NOT_ADDRESSABLE         (EC_NOTIFY_ERROR | 21)   /**< Fixed station address lost (or slave missing) - FPRD to AL_STATUS failed */
#define EC_NOTIFY_MBSLAVE_COE_SDO_ABORT         (EC_NOTIFY_ERROR | 25)   /**< CoE mbox SDO abort */
#define EC_NOTIFY_MBXRCV_INVALID_DATA           (EC_NOTIFY_ERROR | 29)   /**< Invalid mbox data received */
#define EC_NOTIFY_PDIWATCHDOG                   (EC_NOTIFY_ERROR | 30)   /**< PDI Watchdog expired on slave, thrown by IST */
#define EC_NOTIFY_SLAVE_UNEXPECTED_STATE        (EC_NOTIFY_ERROR | 32)   /**< Slave in unexpected state */
#define EC_NOTIFY_EEPROM_CHECKSUM_ERROR         (EC_NOTIFY_ERROR | 35)   /**< EEPROM checksum error detected */
/** @} */

/**
 * @name Other
 * @{
 */

#define EC_STD_STRLEN       80
#define EC_SHORT_STRLEN     20
#define EC_EMCY_SIZE        5
#define EC_MAX_FILENAMELEN  32
#define EC_MAX_FOLDERLEN    (M_PATHLEN_A - EC_MAX_FILENAMELEN)
/** @} */
/** @} */

/**
 * @name Structures
 * @{
 */

/** @} */

/**
 * @addtogroup ECAT_SMI
 * @{
 */
/**
 * Master/slave states
 */
typedef enum
{
    EcStateUnknown  = 0,        /**< Unknown */
    EcStateInit     = 1,        /**< Init */
    EcStatePreop    = 2,        /**< Pre-operational */
    EcStateBoot     = 3,        /**< Bootstrap mode */
    EcStateSsafeop  = 4,        /**< Safe operational */
    EcStateOp       = 8,        /**< Operational */
} EC_STATE;

/**
 * Slave properties (EC_T_SLAVE_PROP)
 */
typedef struct
{
    UINT16  StationAddr;
    UINT16  AutoIncAddr;
    CHAR8   Name[EC_STD_STRLEN];
} EC_SLAVE_PROP;

/**
 * WKC error description (EC_T_WKCERR_DESC)
 */
typedef struct
{
    EC_SLAVE_PROP   SlaveProp;
    UINT8           Cmd;
    UINT32          Addr;
    UINT16          WkcSet;
    UINT16          WkcAct;
} EC_WKCERR_DESC;

/**
 * Frame response error description (EC_T_FRAME_RSPERR_DESC)
 */
typedef struct
{
    UINT32  IsCyclicFrame;
    UINT32  ErrorType;
    UINT8   CmdHeaderIdxSet;
    UINT8   CmdHeaderIdxAct;
} EC_FRAME_RSPERR_DESC;

/**
 * Init command response error (EC_T_INITCMD_ERR_DESC)
 */
typedef struct
{
    EC_SLAVE_PROP   SlaveProp;
    CHAR8           StateChangeName[EC_SHORT_STRLEN];
    UINT32          ErrorType;
} EC_INITCMD_ERR_DESC;

/**
 * Missing command descriptor (EC_T_MISSCMD_DESC)
 */
typedef struct
{
    EC_SLAVE_PROP   SlaveProp;
    UINT32          CmdIndex;
    UINT32          MasterCmd;
} EC_MISSCMD_DESC;

/**
 * Slave error status info descriptor (EC_T_SLAVE_ERROR_INFO_DESC)
 */
typedef struct
{
    EC_SLAVE_PROP   SlaveProp;
    UINT16          Status;
    UINT16          StatusCode;
} EC_SLAVE_ERROR_INFO_DESC;

/**
 * SDO abort descriptor (EC_T_MBOX_SDO_ABORT_DESC)
 */
typedef struct
{
    EC_SLAVE_PROP   SlaveProp;
    UINT32          ErrorCode;
    UINT16          Index;
    UINT8           SubIndex;
} EC_MBOX_SDO_ABORT_DESC;

/**
 * Slave unexpected state descriptor (EC_T_SLAVE_UNEXPECTED_STATE_DESC)
 */
typedef struct
{
    EC_SLAVE_PROP   SlaveProp;
    UINT32          CurState;
    UINT32          ExpState;
} EC_SLAVE_UNEXPECTED_STATE_DESC;

/**
 * CoE Emergency (EC_T_COE_EMERGENCY)
 */
typedef struct
{
    UINT16  ErrorCode;
    UINT8   ErrorRegister;
    UINT8   ErrorData[EC_EMCY_SIZE];
    UINT16  StationAddr;
} EC_COE_EMERGENCY;

/**
 * CoE Object Description (EC_T_COE_OBDESC)
 */
typedef struct
{
    UINT16  ObIndex;            /**< Object index */
    UINT16  DataType;           /**< Data type */
    UINT8   ObjCode;            /**< Object code defined in DS301 */
    UINT8   ObjCategory;        /**< Category: 0=optional; 1=mandatory */
    UINT8   NumSubIndex;        /**< Number of sub-indexes */
    UINT16  NameLen;            /**< Length of object name */
    CHAR8   ObName[0];          /**< Name follows at end of struct */
} P EC_COE_OBDESC;

/**
 * CoE Object Entry Description (EC_T_COE_ENTRYDESC)
 */
typedef struct
{
    UINT16  ObIndex;            /**< Object index */
    UINT8   ObSubIndex;         /**< Object sub-index */
    UINT8   ValueInfo;          /**< Determines which of the following elements are valid */
    UINT16  DataType;           /**< Data type */
    UINT16  BitLen;             /**< Bit length of the object */
    UINT8   ObAccess;           /**< Object access */
    UINT32  RxPdoMap;           /**< TRUE if it is PDO mappable */
    UINT32  TxPdoMap;           /**< TRUE if PDO mappable object can be changed */
    UINT32  ObCanBeUsedForBackup;    /**< Parameter may be back upped */
    UINT32  ObCanBeUsedForSettings;  /**< Parameter may be used for Settings */
    /**
     * Unit type of the object
     * only valid if EC_COE_UNITTYPE bit is set in ValueInfo
     */
    UINT16  UnitType;
    UINT16  DataLen;            /**< Length of the data */
    /**
     * Data follows at end of struct:
     * default value, if EC_COE_DEFVALUE bit is set in ValueInfo
     * minimum value, if EC_COE_MINVALUE bit is set in ValueInfo
     * maximum value, if EC_COE_MAXVALUE bit is set in ValueInfo
     * object description
     */
    UINT8   Data[0];
} P EC_COE_ENTRYDESC;

typedef struct
{
    UINT32  NetNb;
    CHAR8   Name[8];
    UINT8   MAC[6];
    UINT16  Spare1;
    UINT32  Spare2;
} EC_IFDATA;

/**
 * Structure for the SMI-Call #EC_PROC_GETIF
 */
typedef struct
{
} EC_GETIF_C;

/**
 * Structure for the SMI-Reply #EC_PROC_GETIF
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      IfCnt;
    UINT32      Spare;
    EC_IFDATA   If[0];
} EC_GETIF_R;

/**
 * Structure for the SMI-Call #EC_PROC_BUSSCAN
 */
typedef struct
{
    UINT32  NetNb;              /**< 0=default */
    UINT32  Spare[3];
} EC_BUSSCAN_C;

/**
 * Structure for the SMI-Reply #EC_PROC_BUSSCAN
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  SlaveCnt;
    UINT32  Spare[3];
} EC_BUSSCAN_R;

/**
 * Structure for the SMI-Call #EC_PROC_GETSLAVEINFO
 */
typedef struct
{
    UINT32  NetNb;              /**< 0=default */
    UINT32  AutoIncAddr;
    UINT32  Spare[3];
} EC_GETSLAVEINFO_C;

/**
 * Structure for the SMI-Reply #EC_PROC_GETSLAVEINFO
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  VendorId;
    UINT32  ProductCode;
    UINT32  SerialNb;
    UINT32  RevisionNb;
    UINT16  PortState;
    UINT16  AliasAddr;
    UINT32  DcSupport;
    UINT32  Dc64Support;
    UINT32  Spare[5];
} EC_GETSLAVEINFO_R;

/**
 * Structure for the SMI-Call #EC_PROC_SDOREAD
 */
typedef struct
{
    UINT32  NetNb;
    UINT32  PhysAddr;
    UINT32  Index;
    UINT32  SubIndex;
    UINT32  Spare[4];
} EC_SDOREAD_C;

/**
 * Structure for the SMI-Reply #EC_PROC_SDOREAD
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Error;
    UINT32  Spare[4];
    UINT32  Length;
    UINT8   Data[0];
} EC_SDOREAD_R;

/**
 * Structure for the SMI-Call #EC_PROC_SDOWRITE
 */
typedef struct
{
    UINT32  NetNb;
    UINT32  PhysAddr;
    UINT32  Index;
    UINT32  SubIndex;
    UINT32  Spare[4];
    UINT32  Length;
    UINT8   Data[0];
} EC_SDOWRITE_C;

/**
 * Structure for the SMI-Reply #EC_PROC_SDOWRITE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Error;
    UINT32  Spare[4];
} EC_SDOWRITE_R;

/**
 * Structure for the SMI-Call #EC_PROC_FILEWRITE
 */
typedef struct
{
    UINT32  NetNb;              /**< Not in use for this specific command */
    UINT32  PhysAddr;           /**< Physical address of slave */
    UINT32  Mode;               /**< EC_FILE_WRITE or EC_FILE_PROGRESS */
    UINT32  Id;                 /**< ID of file transfer (used for EC_FILE_PROGRESS) */
    CHAR8   FilePath[M_PATHLEN_A];   /**< Path and name of file to write to slave */
    UINT32  Password;           /**< Slave password */
    UINT32  Timeout;            /**< Timeout for file transfer in milliseconds */
    UINT32  Spare[4];
} EC_FILEWRITE_C;

/**
 * Structure for the SMI-Reply #EC_PROC_FILEWRITE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Error;              /**< EtherCAT error code */
    UINT32  Id;                 /**< ID of file transfer (needed for EC_FILE_PROGRESS) */
    UINT32  Progress;           /**< Progress of file transfer (0-100%) */
    UINT32  Spare[4];
} EC_FILEWRITE_R;

/**
 * Structure for the SMI-Call #EC_PROC_GETMASTERSTATE
 */
typedef struct
{
    UINT32  NetNb;              /**< Not in use for this specific command */
    UINT32  PhysAddr;           /**< Not in use for this specific command */
    UINT32  Spare[4];
} EC_GETMASTERSTATE_C;

/**
 * Structure for the SMI-Reply #EC_PROC_GETMASTERSTATE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  CurrState;          /**< Current operating state */
    UINT32  Spare[4];
} EC_GETMASTERSTATE_R;

/**
 * Structure for the SMI-Call #EC_PROC_GETSLAVESTATE
 */
typedef struct
{
    UINT32  NetNb;              /**< Not in use for this specific command */
    UINT32  PhysAddr;           /**< Physical address of slave */
    UINT32  Spare[4];
} EC_GETSLAVESTATE_C;

/**
 * Structure for the SMI-Reply #EC_PROC_GETSLAVESTATE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  CurrState;          /**< Current operating state */
    UINT32  ReqState;           /**< Set value of the operating state */
    UINT32  Spare[4];
} EC_GETSLAVESTATE_R;

/**
 * Structure for the SMI-Call #EC_PROC_SETMASTERSTATE
 */
typedef struct
{
    UINT32  NetNb;              /**< Not in use for this specific command */
    UINT32  PhysAddr;           /**< Not in use for this specific command */
    UINT32  ReqState;           /**< Requested state */
    UINT32  Timeout;            /**< Timeout in ms */
    UINT32  Spare[4];
} EC_SETMASTERSTATE_C;

/**
 * Structure for the SMI-Reply #EC_PROC_SETMASTERSTATE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[4];
} EC_SETMASTERSTATE_R;

/**
 * Structure for the SMI-Call #EC_PROC_SETSLAVESTATE
 */
typedef struct
{
    UINT32  NetNb;              /**< Not in use for this specific command */
    UINT32  PhysAddr;           /**< Physical address of slave */
    UINT32  ReqState;           /**< Requested state */
    UINT32  Timeout;            /**< Timeout in ms */
    UINT32  Spare[4];
} EC_SETSLAVESTATE_C;

/**
 * Structure for the SMI-Reply #EC_PROC_SETSLAVESTATE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[4];
} EC_SETSLAVESTATE_R;

/**
 * Structure for the SMI-Call #EC_PROC_GETOBJDICT
 */
typedef struct
{
    UINT32  NetNb;
    UINT32  PhysAddr;
    UINT32  Type;
    UINT32  StartIdx;
    UINT32  Spare[4];
} EC_GETOBJDICT_C;

/**
 * Structure for the SMI-Reply #EC_PROC_GETOBJDICT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Error;
    UINT32  Length;
    UINT32  Spare[4];
    UINT8   Data[0];
} EC_GETOBJDICT_R;

/**
 * Structure for the SMI-Call #EC_PROC_GETOBJDESC
 */
typedef struct
{
    UINT32  NetNb;
    UINT32  PhysAddr;
    UINT32  Index;
    UINT32  Spare[4];
} EC_GETOBJDESC_C;

/**
 * Structure for the SMI-Reply #EC_PROC_GETOBJDESC
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          Error;
    UINT32          Spare[4];
    EC_COE_OBDESC   Data;
} EC_GETOBJDESC_R;

/**
 * Structure for the SMI-Call #EC_PROC_GETOBJENTRY
 */
typedef struct
{
    UINT32  NetNb;
    UINT32  PhysAddr;
    UINT32  Index;
    UINT32  SubIndex;
    UINT32  Spare[4];
} EC_GETOBJENTRY_C;

/**
 * Structure for the SMI-Reply #EC_PROC_GETOBJENTRY
 */
typedef struct
{
    SINT32              RetCode;     /**< Return Code */
    UINT32              Error;
    UINT32              Spare[4];
    EC_COE_ENTRYDESC    Data;
} EC_GETOBJENTRY_R;

/**
 * Structure for the SMI-Call #EC_PROC_WRITEALIAS
 */
typedef struct
{
    UINT32  NetNb;              /**< 0=default */
    UINT32  AutoIncAddr;
    UINT16  AliasAddr;
    UINT16  Reserved;
    UINT32  Spare[4];
} EC_WRITEALIAS_C;

/**
 * Structure for the SMI-Reply #EC_PROC_WRITEALIAS
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[4];
} EC_WRITEALIAS_R;

/** @} */

/**
 * @name Definition of Variables
 * @{
 */
/** @} */
/** @} */

#ifdef __cplusplus
}
#endif

#endif
