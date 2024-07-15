/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     can.h
* @author   Bertel
* @brief    CANopen Server
*           This file contains all definitions and declarations exported by
*           the CANopen Server, that could be used by modules running on
*           another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef CAN__H
#define CAN__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>
#include <msys.h>

/**
 * @addtogroup CAN_API
 * @{
 */

/**
 * @name Defines
 * @{
 */

#define CAN_PROTVERS        2    /**< Version of RPC-Protocol */
#define CAN_NETNAMELEN      20   /**< Size of network name without terminating '\0' */
#define CAN_NETNAMELEN_A    ((CAN_NETNAMELEN + 1 + 3) & 0xfffffffc)  /**< CAN_NETNAMELEN + '\0' + aligned */

/**
 * @name Possible values for CAN_SDO_ERROR.ErrorClass and CIA405_SDO_ERRORtyp.ERRORCLASS (PLC user);
 * @{
 */

#define CAN_EC_SERVICE  5   /**< Service error */
#define CAN_EC_ACCESS   6   /**< Access error */
#define CAN_EC_OTHER    8   /**< Other error */
/** @} */

/**
 * @name Possible values for CAN_SDO_ERROR.ErrorCode and CIA405_SDO_ERRORtyp.ERRORCODE (PLC user)
 * @{
 */

#define CAN_EO_ACCESS   1   /**< Object access unsupported */
#define CAN_EO_EXISTS   2   /**< Object not-existent */
#define CAN_EO_TOGGLE   3   /**< Toggle error, Parameter inconsistent */
#define CAN_EO_TIMEOUT  4   /**< Timeout, Illegal parameter */
#define CAN_EO_HW       6   /**< Hardware fault */
#define CAN_EO_TYPE     7   /**< Type conflict */
#define CAN_EO_ATTR     9   /**< Object attribute inconsistent */
/** @} */

/**
 * @name Possible values for CAN_*.Error and CIA405_*.Error (PLC user)
 * @{
 */

#define CAN_KE_OK       0   /**< No error */
#define CAN_KE_FAILED   0x0001   /**< Other error */
#define CAN_KE_DATAOVF  0x0002   /**< Data overflow */
#define CAN_KE_TIMEOUT  0x0003   /**< Time out */
#define CAN_KE_BUSOFF   0x0010   /**< CAN bus off */
#define CAN_KE_BUSERR   0x0011   /**< CAN erros passive */
#define CAN_KE_ESTATSET 0x0021   /**< CAN controller error status set */
#define CAN_KE_CANOVR   0x0022   /**< CAN controller RX overrun */
#define CAN_KE_HPTXOVR  0x0023   /**< Highpriority-Transmit-Queue overrun */
#define CAN_KE_HPRXOVR  0x0024   /**< Highpriority-Receive-Queue overrun */
#define CAN_KE_GUARD    0x0025   /**< Node-Guard-Protocol error */
#define CAN_KE_INVNODE  0x0030   /**< Node-ID not valid */
/** @} */

/**
 * @name Possible values for CAN_GETSTATE_R.State and CIA_GET_STATE.STATUS (PLC user)
 * @{
 */

#define CAN_S_INIT      0
#define CAN_S_RESCOM    6
#define CAN_S_RESAPP    7
#define CAN_S_PREOP     127
#define CAN_S_DISCON    1
#define CAN_S_CON       2
#define CAN_S_PREPARING 3
#define CAN_S_PREPARED  4
#define CAN_S_OP        5
#define CAN_S_GUARDERR  255
/** @} */

/**
 * @name Possible values for  CAN_*.RetCode
 * @{
 */

#define CAN_E_OK        M_E_OK   /**< O.K. */
#define CAN_E_CARDNB    (M_ES_CAN | M_E_CARDNB)  /**< Card number not valid */
#define CAN_E_FAILED    (M_ES_CAN | M_E_FAILED)  /**< Unspecified error */
#define CAN_E_NOFILE    (M_ES_CAN | M_E_NOFILE)  /**< File not found */
#define CAN_E_NOEMY     (M_ES_CAN | M_E_EMPTY)   /**< No emergency present */
#define CAN_E_TIMEOUT   (M_ES_CAN | M_E_TIMEOUT)     /**< Timeout in function call */
#define CAN_E_NOAPP     (M_ES_CAN | M_E_NOAPP)   /**< Not available in boot mode NOAPP */
#define CAN_E_QUEUEFULL (M_ES_CAN | M_E_QUEUEFULL)   /**< Message/Event Queue overrun */
/** @} */
/** @} */

/**
 * @addtogroup CAN_SMI
 * @{
 */

/**
 * @name Possible SMI Commands
 * @{
 */

#define CAN_PROC_UPDATESW       100  /**< SW-Update on CM202 */
#define CAN_PROC_GETLOCNODEID   102  /**< Get local Node ID */
#define CAN_PROC_GETSTATE       104  /**< Get node status */
#define CAN_PROC_GETKERNSTATE   106  /**< Get CANopen kernel status */
#define CAN_PROC_GETNETNB       108  /**< Get network number */
#define CAN_PROC_GETNETNAME     110  /**< Get network name */
#define CAN_PROC_RECVEMY        112  /**< Read emergency */
#define CAN_PROC_RECVEMYDEV     114  /**< Read emergency from device */
#define CAN_PROC_SDOREAD        116  /**< Read SDO */
#define CAN_PROC_SDOWRITE       118  /**< Write SDO */
#define CAN_PROC_STARTNODE      120  /**< Start node */
#define CAN_PROC_STOPNODE       122  /**< Stop node */
#define CAN_PROC_SDOTOFILE      124  /**< Transfer SDO to file */
#define CAN_PROC_FILETOSDO      126  /**< Transfer file to SDO */
#define CAN_PROC_RDEMYLST       128  /**< Read current emergency list */
#define CAN_PROC_NMTCMD         130  /**< Send NMT commando to CM2020 */
#define CAN_PROC_LMTCMD         132  /**< Send LMT commando to CM2020 */
#define CAN_PROC_SENDEMY        134  /**< Send emergency message */
#define CAN_PROC_SETEMY         136  /**< Set and send emergency error */
#define CAN_PROC_RESETEMY       138  /**< Clear emergency error */
#define CAN_PROC_SETAPPREADY    140  /**< Signals application ready */
/** @} */

/**
 * @name Possible values for CAN_NMTCMD_C.Cmd and CIA_NMT_CMD.CMD (PLC user)
 * @{
 */

#define CAN_NMT_STARTREMNODE    1    /**< Start Remote Node Request CS=1 */
#define CAN_NMT_STOPREMNODE     2    /**< Stop  Remote Node Request CS=2 */
#define CAN_NMT_ENTERPREOP      128  /**< Enter Pre-Operational Rq. CS=128 */
#define CAN_NMT_RESETNODE       129  /**< Reset Node Request        CS=129 */
#define CAN_NMT_RESETCOMM       130  /**< Reset Communication Req.  CS=130 */
#define CAN_NMT_SETUSERNMT      (0x100 + 1)  /**< Set USER NMT-Control for a node */
#define CAN_NMT_SETAUTONMT      (0x100 + 2)  /**< Set AUTO NMT-Control for a node */
#define CAN_NMT_STARTGUARDING   (0x100 + 3)  /**< Start Node Guarding protocol */
#define CAN_NMT_STOPGUARDING    (0x100 + 4)  /**< Stops the Node Guarding */
#define CAN_NMT_SENDNODECONFIG  (0x100 + 5)  /**< Sends the Node Config from DCF */
#define CAN_NMT_REINITNETWORK   (0x100 + 6)  /**< Re-initials and starts the network */
#define CAN_NMT_CLEAROVERRUN    (0x100 + 7)  /**< Clears all overrun statis (Rx,Tx, CAN) */
#define CAN_NMT_RXPDORTRREQEST  (0x200 + 1)  /**< PDO RTR-Request of Rx-PDO number */
#define CAN_NMT_TXPDOTRIGGER    (0x200 + 2)  /**< PDO Set Trigger for Tx-PDO number */
#define CAN_NMT_SYNCMASTER      (0x200 + 3)  /**< Send SYNC-Object (if SYNC-Master) */
#define CAN_NMT_SENDTIMESTAMP   (0x200 + 4)  /**< Send TIME-Object (if TIME-Master) */
/** @} */

/**
 * @name Possible values for CAN_LMTCMD_C.Cmd.cs and CIA_LMT_CMD.CS (PLC user)
 * @{
 */

#define CAN_LSS_SMS_VENDOR_ID       64   /**< CANopen Vendor-ID (registrated) */
#define CAN_LSS_SMS_PRODUCT_CODE    65   /**< Product Code */
#define CAN_LSS_SMS_REVISION_NO     66   /**< Revision Number */
#define CAN_LSS_SMS_SERIAL_NO       67   /**< Serial Number */
#define CAN_LSS_SMS_RESPONS         68   /**< Response cs from LSS server */
#define CAN_LMT_SM_GLOBAL           4    /**< Switch Mode Global service */
#define CAN_LMT_CFG_MODULE_ID       17   /**< Configure Module ID service */
#define CAN_LMT_CFG_BIT_TIME        19   /**< Configure Bit-Timing parameters */
#define CAN_LMT_STORE_CFG           23   /**< Store Configuration service */
/** @} */
/** @} */

/**
 * @name Structures
 * @{
 */

/**
 * Structure for the SMI-Call #CAN_PROC_UPDATESW
 */
typedef struct
{
    UINT32  CardNb;             /**< Card number (1-n) */
    UINT32  Reserved;           /**< must be 0 */
    CHAR8   FileName[M_PATHLEN_A];   /**< Directory of file with new SW */
} CAN_UPDATESW_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_UPDATESW
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} CAN_UPDATESW_R;

/**
 * Structure for the SMI-Call #CAN_PROC_GETLOCNODEID
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
} CAN_GETLOCNODEID_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_GETLOCNODEID
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  NodeId;             /**< Node number (1-127) */
} CAN_GETLOCNODEID_R;

/**
 * Structure for the SMI-Call #CAN_PROC_GETSTATE
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
    UINT32  NodeId;             /**< Node number (1-127) */
} CAN_GETSTATE_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_GETSTATE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  State;              /**< State of node */
} CAN_GETSTATE_R;

/**
 * Structure for the SMI-Call #CAN_PROC_GETKERNSTATE
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
} CAN_GETKERNSTATE_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_GETKERNSTATE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  State;              /**< State of node */
} CAN_GETKERNSTATE_R;

/**
 * Structure for the SMI-Call #CAN_PROC_GETNETNB
 */
typedef struct
{
    CHAR8   NetName[CAN_NETNAMELEN_A];   /**< Network name */
} CAN_GETNETNB_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_GETNETNB
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  NetNumber;          /**< Network number (1-8) */
} CAN_GETNETNB_R;

/**
 * Structure for the SMI-Call #CAN_PROC_GETNETNAME
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
} CAN_GETNETNAME_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_GETNETNAME
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    CHAR8   NetName[CAN_NETNAMELEN_A];   /**< Network name */
} CAN_GETNETNAME_R;

/**
 * Data of emergency, see CIA DSP-405
 */
typedef struct
{
    UINT16  ErrorCode;
    UINT8   ErrorRegister;
    UINT8   ErrorField[5];
} CAN_EMY_ERROR;

/**
 * Structure for the SMI-Call #CAN_PROC_RECVEMY
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
} CAN_RECVEMY_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_RECVEMY
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NodeId;     /**< Node number (1-127) */
    CAN_EMY_ERROR   Emy;        /**< Emergency message */
} CAN_RECVEMY_R;

/**
 * Structure for the SMI-Call #CAN_PROC_SENDEMY
 */
typedef struct
{
    UINT32          NetNumber;  /**< Network number (1-8) */
    CAN_EMY_ERROR   Emy;        /**< Emergency message */
} CAN_SENDEMY_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_SENDEMY
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} CAN_SENDEMY_R;

/**
 * Structure for the SMI-Call #CAN_PROC_SETEMY
 */
typedef struct
{
    UINT32          NetNumber;  /**< Network number (1-8) */
    CAN_EMY_ERROR   Emy;        /**< Emergency message */
} CAN_SETEMY_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_SETEMY
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} CAN_SETEMY_R;

/**
 * Structure for the SMI-Call #CAN_PROC_RESETEMY
 */
typedef struct
{
    UINT32          NetNumber;  /**< Network number (1-8) */
    CAN_EMY_ERROR   Emy;        /**< Emergency message */
} CAN_RESETEMY_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_RESETEMY
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} CAN_RESETEMY_R;

/**
 * Structure for the SMI-Call #CAN_PROC_RECVEMYDEV
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
    UINT32  NodeId;             /**< Node number (1-127) */
} CAN_RECVEMYDEV_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_RECVEMYDEV
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    CAN_EMY_ERROR   Emy;        /**< Emergency message */
} CAN_RECVEMYDEV_R;

/**
 * Data of one emergency entry
 */
typedef struct
{
    UINT32          NodeId;     /**< Node number (1-127) */
    CAN_EMY_ERROR   Inf;        /**< actual error data */
} CAN_EMY_ENTRY;

/**
 * Structure for the SMI-Call #CAN_PROC_RDEMYLST
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
    UINT32  Reserved1;          /**< must be 0 */
    UINT32  Reserved2;          /**< must be 0 */
} CAN_RDEMYLST_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_RDEMYLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfEmy;    /**< Number of emergenies */
    CAN_EMY_ENTRY   Emy[1];     /**< Emergency messages */
} CAN_RDEMYLST_R;

/**
 * SDO error info, see CIA DSP-405
 */
typedef struct
{
    UINT8   ErrorClass;
    UINT8   ErrorCode;
    UINT16  AdditionalCode;
} CAN_SDO_ERROR;

/**
 * Structure for the SMI-Call #CAN_PROC_SDOREAD
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
    UINT32  NodeId;             /**< Node number (1-127) */
    UINT32  Index;              /**< Index to object */
    UINT32  SubIndex;           /**< Index to subobject */
    UINT32  Length;             /**< Size of data to read */
} CAN_SDOREAD_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_SDOREAD
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          Error;      /**< CANopen kernel error */
    CAN_SDO_ERROR   ErrorInfo;  /**< Additional error info */
    UINT32          Length;     /**< Number of bytes read */
    UINT8           Data[1];    /**< Data read */
} CAN_SDOREAD_R;

/**
 * Structure for the SMI-Call #CAN_PROC_SDOWRITE
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
    UINT32  NodeId;             /**< Node number (1-127) */
    UINT32  Index;              /**< Index to object */
    UINT32  SubIndex;           /**< Index to subobject */
    UINT32  Length;             /**< Number of bytes to write */
    UINT8   Data[1];            /**< Data to write */
} CAN_SDOWRITE_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_SDOWRITE
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          Error;      /**< CANopen kernel error */
    CAN_SDO_ERROR   ErrorInfo;  /**< Additional error info */
} CAN_SDOWRITE_R;

/**
 * Structure for the SMI-Call #CAN_PROC_STARTNODE
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
    UINT32  NodeId;             /**< Node number (1-127) */
} CAN_STARTNODE_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_STARTNODE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Error;              /**< CANopen kernel error */
} CAN_STARTNODE_R;

/**
 * Structure for the SMI-Call #CAN_PROC_STOPNODE
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
    UINT32  NodeId;             /**< Node number (1-127) */
} CAN_STOPNODE_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_STOPNODE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Error;              /**< CANopen kernel error */
} CAN_STOPNODE_R;

/**
 * Structure for the SMI-Call #CAN_PROC_SDOTOFILE
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
    UINT32  NodeId;             /**< Node number (1-127) */
    UINT32  Index;              /**< Index to object */
    UINT32  SubIndex;           /**< Index to subobject */
    CHAR8   FileName[M_PATHLEN_A];   /**< Directory/Name of file */
} CAN_SDOTOFILE_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_SDOTOFILE
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          Error;      /**< CANopen kernel error */
    CAN_SDO_ERROR   ErrorInfo;  /**< Additional error info */
} CAN_SDOTOFILE_R;

/**
 * Structure for the SMI-Call #CAN_PROC_FILETOSDO
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
    UINT32  NodeId;             /**< Node number (1-127) */
    UINT32  Index;              /**< Index to object */
    UINT32  SubIndex;           /**< Index to subobject */
    CHAR8   FileName[M_PATHLEN_A];   /**< Path of source file */
} CAN_FILETOSDO_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_FILETOSDO
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          Error;      /**< CANopen kernel error */
    CAN_SDO_ERROR   ErrorInfo;  /**< Additional error info */
} CAN_FILETOSDO_R;

/**
 * Structure for the SMI-Call #CAN_PROC_NMTCMD
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
    UINT32  NodeId;             /**< Node number (1-127) */
    UINT32  Cmd;                /**< Nmt Command Identifier */
    UINT32  Value;              /**< Nmt Command Parameter Value */
} CAN_NMTCMD_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_NMTCMD
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Error;              /**< CANopen kernel error */
} CAN_NMTCMD_R;

typedef union
{
    /**
     * Structure of LMT-Commands
     */
    struct
    {
        UINT8   cs;                 /**< LMT-Command specifier */
        UINT8   buff[7];            /**< LMT-Command data buffer */
    } Cmd;
    /**
     * Structure of LMT-Response
     */
    struct
    {
        UINT8   cs;                 /**< LMT-Command specifier */
        UINT8   ec;                 /**< LMT-Error code */
        UINT8   se;                 /**< LMT-Specific error */
        UINT8   buff[5];            /**< LMT-Additional error enfo */
    } Resp;
    UINT8   Data[8];            /**< LMT-Message data buffer */
} CAN_LMT_MSG;

/**
 * Structure for the SMI-Call #CAN_PROC_LMTCMD
 */
typedef struct
{
    UINT32      NetNumber;      /**< Network number (1-8) */
    UINT32      RespTime;       /**< Response time for LMT (mS) */
    CAN_LMT_MSG LmtCmd;         /**< LMT-Command buffer */
} CAN_LMTCMD_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_LMTCMD
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    CAN_LMT_MSG LmtResp;        /**< Response of LMT server */
} CAN_LMTCMD_R;

/**
 * Structure for the SMI-Call #CAN_PROC_SETAPPREADY
 */
typedef struct
{
    UINT32  NetNumber;          /**< Network number (1-8) */
    UINT32  ReadyFlag;          /**< TRUE signals ready (init done) */
} CAN_SETAPPREADY_C;

/**
 * Structure for the SMI-Reply #CAN_PROC_SETAPPREADY
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} CAN_SETAPPREADY_R;

typedef struct CANOBJENTRY
{
    UINT16  uiIndex;            /**< CAN object index */
    UINT8   uiSubIdx;           /**< CAN object subindex */
    /**
     * Offset to PLC-image, that
     * is relativ zu MIO_CARD_ITEM.
     * pCardImage...
     */
    UINT32  relOffset;
} CANOBJENTRY;

typedef struct CANOBJDESCHEADER
{
    SINT32      iChanNb;        /**< CAN connector number (0,1) */
    UINT32      nObjEntries;    /**< Number of CAN objects */
    UINT32      reserve1;
    UINT32      reserve2;
    CANOBJENTRY Obj[1];         /**< Open Array of CAN objects */
} CANOBJDESCHEADER;

/** @} */

/**
 * @name Function Prototypes
 * @{
 */
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
