/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     dn.h
* @author   Bertel
* @brief    DevicNet server
*           This file contains all definitions and declarations exported by
*           the DevicNet Server, that could be used by modules running on
*           another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef DN__H
#define DN__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @addtogroup DNM201_API
 * @{
 */

/**
 * @name Defines
 * @{
 */

#define DN_MAXNET   8       /**< Max. number of DeviceNet networks; */
#define DN_MINSLAVE 0       /**< First possible MacId; */
#define DN_MAXSLAVE 63      /**< Laste possible MacId; */

/**
 * @name DeviceNet State of the Identity Object Device State Transition Diagram (1.1.8)
 * @{
 */

#define DN_DS_NONEXISTENT   0    /**< Not existent (Power Loss from any state); */
#define DN_DS_SELFTESTING   1    /**< Device Self Testing (Flashing Red/Green); */
#define DN_DS_STANDBY       2    /**< Standby (Flashing Green); */
#define DN_DS_OPERATIONAL   3    /**< Operational (Solid Green); */
#define DN_DS_MAJRECFAULT   4    /**< Major Recoverable Fault (Flashing Red); */
#define DN_DS_MAJUNRECFAULT 5    /**< Major Unrecoverable Fault (Solid Red); */
/** @} */

/**
 * @name Additional internal states used by DNM201 state machine
 * @{
 */

#define DN_DS_IDLE              6
#define DN_DS_NOTCONNECTED      7
#define DN_DS_CONNECTED         8
#define DN_DS_AUTOBAUDDETECT    9
#define DN_DS_AUTOSTART         10
#define DN_DS_AUTOCONFIG        11
#define DN_DS_DUPMACCHK         12
#define DN_DS_ONLINE            13
#define DN_DS_OFFLINE           14
#define DN_DS_READY             15
#define DN_DS_UNDEFSTATE        16   /**< > 15 ist Undefined State; */
/** @} */

/**
 * @name DeviceNet bit values of the Identity-Status-Attribute (1.1.5)
 * @{
 */

#define DN_IS_EMPTY         0x0000   /**< Not configiured; */
#define DN_IS_OWNED         0x0001   /**< PreDefConSet has been alocated to a master; */
#define DN_IS_CONFIGURED    0x0004   /**< Configuration was executed; */
#define DN_IS_MINRECFAULT   0x0100   /**< Minor recoverable fault (not enter fault stats); */
#define DN_IS_MINUNRECFAULT 0x0200   /**< Minor unrecoverable fault (enter fault states); */
#define DN_IS_MAJRECFAULT   0x0400   /**< Major recoverable fault; */
#define DN_IS_MAJUNRECFAULT 0x0800   /**< Major unrecoverable fault; */
#define DN_IS_RESERVED      0xf0fa   /**< All reservied status bit's; */
/** @} */

/**
 * @name DeviceNet dn_SetState() Function Parameters
 * @{
 */

#define DN_ST_SCAN      0   /**< Set I/O transmission mode 'scan'; */
#define DN_ST_IDLE      1   /**< Set I/O transmission mode 'idle'; */
#define DN_ST_OFFLINE   2   /**< Transmit shutdown message and set 'offline state'; */
#define DN_ST_STANDBY   3   /**< Stop communication, disconnect from can bus; */
#define DN_ST_RESET     4   /**< Reset DeviceNet Master, new config required; */
#define DN_ST_ONLINE    5   /**< Start communication, set 'online state'; */
#define DN_ST_LEAVOFFL  6   /**< Leave 'offline state' after communication fault; */
/** @} */

/**
 * @name Scanner Instace Status Bits Attribut 1 Lo-Byte (66.n.1)
 * @{
 */

#define DN_SS_INIT      0x0000   /**< there is no status information (only for start up); */
#define DN_SS_EVENT     0x0001   /**< Bit set - if a new event was realized; */
#define DN_SS_SHUTDOWN  0x0002   /**< Bit set - node in Shutdown mode; */
#define DN_SS_TIMEOUT   0x0004   /**< Bit set - an Timeout occured; */
#define DN_SS_HEARTBEAT 0x0008   /**< Bit set - Heartbeat error; */
#define DN_SS_RESERVED  0x0010   /**< Bit set - ...; */
#define DN_SS_CREATE    0x0020   /**< Bit set - this Instance was created; */
#define DN_SS_APPLY     0x0040   /**< Bit set - the Instance was added (Apply-Service); */
#define DN_SS_ONLINE    0x0080   /**< Bit set - the Instance was valid and online; */
/** @} */

/**
 * @name Scanner Instace Status Bits Attribut 1 Hi-Byte (66.n.1) exdendet Error-Bits
 * @{
 */

#define DN_ES_VALID     0x8000   /**< validation bit of the extendet Error word; */
#define DN_ES_EKEY      0x2000   /**< E-Key Error; */
#define DN_ES_IOSIZE    0x0000   /**< IO-Size Error; */
/** @} */

/**
 * @name IO Error Flags
 * @{
 */

#define DN_ES_POLLCNXN      0x0000   /**< error in poll connection; */
#define DN_ES_STRCNXN       0x0800   /**< error in bitstrobe connection; */
#define DN_ES_COSCNXN       0x1000   /**< error in cos connection; */
#define DN_ES_IODIR_CONS    0x0000   /**< IO direction conuming; */
#define DN_ES_IODIR_PROD    0x0400   /**< IO direction producing; */
/** @} */

/**
 * @name E-Key Error Flags
 * @{
 */

#define DN_ES_REVISION  0x0200   /**< Revision Error Flag; */
#define DN_ES_PRODCODE  0x0400   /**< Product code Error Flag; */
#define DN_ES_DEVTYPE   0x0800   /**< Device Type Error Flag; */
#define DN_ES_VENDORID  0x1000   /**< VendorId Error Flag; */
/** @} */

/**
 * @name Possible error codes for DN_*.RetCode
 * @{
 */

#define DN_E_OK         (M_E_OK)     /**< No error; */
#define DN_E_FAILED     (M_ES_DN | M_E_FAILED)   /**< Unspecific error; */
#define DN_E_TIMEOUT    (M_ES_DN | M_E_TIMEOUT)  /**< Timout in function execution; */
#define DN_E_NETNB      (M_ES_DN | M_E_NETNB)    /**< Network number not valid or not available; */
#define DN_E_NODEID     (M_ES_DN | M_E_NODEID)   /**< MacId not valid or not available; */
#define DN_E_DSIZE      (M_ES_DN | M_E_DSIZE)    /**< Data size not valid, exceeds max size; */
#define DN_E_NOMEM      (M_ES_DN | M_E_NOMEM)    /**< Out of memory resources; */
#define DN_E_NOSEMA     (M_ES_DN | M_E_NOSEMA)   /**< Out of semaphore resurces; */
#define DN_E_CMDTAG     (M_ES_DN | M_E_CMDTAG)   /**< Command tag not valid; */
#define DN_E_CMDARG     (M_ES_DN | M_E_CMDARG)   /**< Command argument(s) not valid; */
#define DN_E_QUEUEFULL  (M_ES_DN | M_E_QUEUEFULL)    /**< Command/Event Queue overrun; */
#define DN_E_IOBUSFAIL  (M_ES_DN | M_E_IOBUSFAIL)    /**< I/O Bus access fails (bad station); */
#define DN_E_NOTSUPP    (M_ES_DN | M_E_NOTSUPP)  /**< Function not supported (plc dynamic linking); */
/** @} */
/** @} */

/**
 * @addtogroup DNM201_SMI
 * @{
 */

/**
 * @name Possible SMI Commands
 * @{
 */

#define DN_PROTVERS             2    /**< Version of RPC-Protocol; */
#define DN_PROC_EXPREQ          100  /**< Explicit message request; */
#define DN_PROC_EXPGET          102  /**< Expl. message service 'get attribiute single'; */
#define DN_PROC_EXPSET          104  /**< Expl. message service 'set attribute single'; */
#define DN_PROC_GETNODESTATE    106  /**< The actual state of a node (Scanner 66.n.1); */
#define DN_PROC_GETSTATE        108  /**< The global system state (Identity 1.1.8); */
#define DN_PROC_SETSTATE        110  /**< Change system and scanner state; */
#define DN_PROC_PUTCMD          112  /**< Puts a commands directly into queue; */
#define DN_PROC_PING            114  /**< Ping to the dnm201 firmware (communicaton process); */
/** @} */

/**
 * @name Size of explicit messages and command data
 * @{
 */

#define DN_MAXQDATA     56  /**< Dataspace of Cmd-/Event-Queue entries; */
#define DN_REQUDSIZE    (DN_MAXQDATA - 8)    /**< Max. service data length of explicit requests; */
#define DN_RESPDSIZE    (DN_MAXQDATA - 4)    /**< Max. service data length of explicit responses; */
/** @} */
/** @} */

/**
 * @name Structures
 * @{
 */

/**
 * Explicit Request data struct
 */
typedef struct _DN_REQ
{
    UINT8   UnSeqNb;            /**< Not applicable, used internal by Server */
    UINT8   MacId;              /**< Destination MAC Id {0..0x3F} */
    UINT8   DataLen;            /**< Request service data length */
    UINT8   SrvCode;            /**< DeviceNet service code */
    UINT16  Class;              /**< Class Id {0..0xFFFF} */
    UINT16  Instanc;            /**< Instanc Id {0..0xFFFF} */
    UINT8   SrvData[DN_REQUDSIZE];   /**< DeviceNet request service data */
} DN_REQ;

/**
 * Explicit Response data struct
 */
typedef struct _DN_RESP
{
    UINT8   UnSeqNb;            /**< Unique sequence number, used by server only */
    UINT8   MacId;              /**< Destination MAC Id {0..0x3F} */
    UINT8   DataLen;            /**< Respons service data length */
    UINT8   SrvCode;            /**< DeviceNet service code */
    UINT8   SrvData[DN_RESPDSIZE];   /**< DeviceNet response service data */
} DN_RESP;

/**
 * Structure for the SMI-Call #DN_PROC_EXPREQ
 */
typedef struct _DN_EXPREQ_C
{
    UINT32  NetNb;              /**< DeviceNet Network Number 1..8 */
    UINT32  Timeout;            /**< Explicit Timeout, 0 = Default-Timeout */
    DN_REQ  Req;                /**< Explicit Request Message Struct */
} DN_EXPREQ_C;

/**
 * Structure for the SMI-Reply #DN_PROC_EXPREQ
 */
typedef struct _DN_EXPREQ_R
{
    SINT32  RetCode;            /**< Return Code */
    DN_RESP Resp;               /**< Explicit Response Message Struct */
} DN_EXPREQ_R;

/**
 * Structure for the SMI-Call #DN_PROC_EXPGET
 */
typedef struct _DN_EXPGET_C
{
    UINT32  NetNb;              /**< DeviceNet Network Number 1..8 */
    UINT32  MacId;              /**< MacId 0..63 */
    UINT32  Class;              /**< Class-Id */
    UINT32  Inst;               /**< Instanc-Id */
    UINT32  Attr;               /**< Attribute-Id */
    UINT32  Timeout;            /**< Response Timeout, 0 = Default-Timeout */
} DN_EXPGET_C;

/**
 * Structure for the SMI-Reply #DN_PROC_EXPGET
 */
typedef struct _DN_EXPGET_R
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Size;               /**< Response data length */
    UINT8   Data[DN_RESPDSIZE]; /**< Response data field */
} DN_EXPGET_R;

/**
 * Structure for the SMI-Call #DN_PROC_EXPSET
 */
typedef struct _DN_EXPSET_C
{
    UINT32  NetNb;              /**< DeviceNet Network Number 1..8 */
    UINT32  MacId;              /**< MacId 0..63 */
    UINT32  Class;              /**< Class-Id */
    UINT32  Inst;               /**< Instanc-Id */
    UINT32  Attr;               /**< Attribute-Id */
    UINT32  Timeout;            /**< Explicit Timeout 0 = Default-Timeout */
    UINT32  Size;               /**< Request service data length */
    UINT8   Data[DN_REQUDSIZE]; /**< Service data field */
} DN_EXPSET_C;

/**
 * Structure for the SMI-Reply #DN_PROC_EXPSET
 */
typedef struct _DN_EXPSET_R
{
    SINT32  RetCode;            /**< Return Code */
} DN_EXPSET_R;

/**
 * Structure for the SMI-Call #DN_PROC_GETNODESTATE
 */
typedef struct _DN_GETNODESTATE_C
{
    UINT32  NetNb;              /**< DeviceNet Network Number 1..8 */
    UINT32  MacId;              /**< MacId 0..63 */
} DN_GETNODESTATE_C;

/**
 * Structure for the SMI-Reply #DN_PROC_GETNODESTATE
 */
typedef struct _DN_GETNODESTATE_R
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  State;              /**< The global system state (Identity 1.1.8) */
} DN_GETNODESTATE_R;

/**
 * Structure for the SMI-Call #DN_PROC_GETSTATE
 */
typedef struct _DN_GETSTATE_C
{
    UINT32  NetNb;              /**< DeviceNet Network Number 1..8 */
} DN_GETSTATE_C;

/**
 * Structure for the SMI-Reply #DN_PROC_GETSTATE
 */
typedef struct _DN_GETSTATE_R
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  State;              /**< The global system state (Identity 1.1.8) */
} DN_GETSTATE_R;

/**
 * Structure for the SMI-Call #DN_PROC_SETSTATE
 */
typedef struct _DN_SETSTATE_C
{
    UINT32  NetNb;              /**< DeviceNet Network Number 1..8 */
    UINT32  State;              /**< System state (Scan, Idle Reset...) */
} DN_SETSTATE_C;

/**
 * Structure for the SMI-Reply #DN_PROC_SETSTATE
 */
typedef struct _DN_SETSTATE_R
{
    SINT32  RetCode;            /**< Return Code */
} DN_SETSTATE_R;

/**
 * Structure for the SMI-Call #DN_PROC_PUTCMD
 */
typedef struct _DN_PUTCMD_C
{
    UINT32  NetNb;              /**< DeviceNet Network Number 1..8 */
    UINT32  CmdTag;             /**< Command-Tag */
    UINT8   Data[DN_MAXQDATA];  /**< Command Data field */
} DN_PUTCMD_C;

/**
 * Structure for the SMI-Reply #DN_PROC_PUTCMD
 */
typedef struct _DN_PUTCMD_R
{
    SINT32  RetCode;            /**< Return Code */
} DN_PUTCMD_R;

/**
 * Structure for the SMI-Call #DN_PROC_PING
 */
typedef struct _DN_PING_C
{
    UINT32  NetNb;              /**< DeviceNet Network Number 1..8 */
} DN_PING_C;

/**
 * Structure for the SMI-Reply #DN_PROC_PING
 */
typedef struct _DN_PING_R
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  RespTime;           /**< Response Time of communication process */
} DN_PING_R;

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
