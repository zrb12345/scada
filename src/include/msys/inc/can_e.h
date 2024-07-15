/**
********************************************************************************
* @file     can_e.h
* @author   Bertel
*
* @brief This file contains all definitions and declarations exported by
*        the CANopen Server for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef CAN_E__H
#define CAN_E__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mio_e.h>
#include <can.h>
#include <cpn_e.h>


/*--- Defines ---*/

/*--- Structures ---*/

/*--- Function Prototypes ---*/

/* can_main.c */
SINT32 can_Init(VOID);
VOID can_Deinit(VOID);

/* can_lib.c */
SINT32 can_GetNbOfVar(UINT32 NetNumber, UINT32 Index);
SINT32 can_GetLocalNodeId(UINT32 NetNumber, UINT32 *pNodeId);
SINT32 can_GetState(UINT32 NetNumber, UINT32 NodeId, UINT32 *pState);
SINT32 can_GetCANopenKernelState(UINT32 NetNumber, UINT32 *pState);
SINT32 can_GetNetNumber(CHAR *pNetName, UINT32 *pNetNumber);
SINT32 can_GetNetName(UINT32 NetNumber, CHAR *pBuff, UINT32 BuffLen);
SINT32 can_RecvEmy(UINT32 NetNumber, UINT32 *pNodeId, 
		   CAN_EMY_ERROR *pEmyError);
SINT32 can_RecvEmyDev(UINT32 NetNumber, UINT32 NodeId, 
		      CAN_EMY_ERROR *pEmyError);
SINT32 can_SdoRead(UINT32 NetNumber, UINT32 NodeId, UINT32 Index, 
		   UINT32 SubIndex, UINT8 *pData, UINT32 *pLength,
		   UINT32 *pError, CAN_SDO_ERROR *pErrorInfo);
SINT32 can_SdoWrite(UINT32 NetNumber, UINT32 NodeId, UINT32 Index, 
		    UINT32 SubIndex, UINT8 *pData, UINT32 Length,
		    UINT32 *pError, CAN_SDO_ERROR *pErrorInfo);
SINT32 can_SdoToFile(UINT32 NetNumber, UINT32 NodeId, UINT32 Index, 
		     UINT32 SubIndex, CHAR *FileName,
		     UINT32 *pError, CAN_SDO_ERROR *pErrorInfo);
SINT32 can_FileToSdo(UINT32 NetNumber, UINT32 NodeId, UINT32 Index, 
		     UINT32 SubIndex, CHAR *FileName,
		     UINT32 *pError, CAN_SDO_ERROR *pErrorInfo);
SINT32 can_StartNode(UINT32 NetNumber, UINT32 NodeId, UINT32 *pError);
SINT32 can_StopNode(UINT32 NetNumber, UINT32 NodeId, UINT32 *pError);
VOID *can_GetCard(UINT32 NetNumber);
SINT32 can_GetChanNb(UINT32 NetNumber);
SINT32 can_NmtCmd(UINT32 NetNumber, UINT32 NodeId, UINT32 Cmd,
		  UINT32 Value, UINT32 *pError);
SINT32 can_LmtCmd(UINT32 NetNumber, UINT32 RespTime, 
		  CAN_LMT_MSG *pLmtMsg, CAN_LMT_MSG *pLmtResp);
SINT32 can_SendEmy(UINT32 NetNumber, CAN_EMY_ERROR *pEmyError);
SINT32 can_SetEmy(UINT32 NetNumber, CAN_EMY_ERROR *pEmyError);
SINT32 can_ResetEmy(UINT32 NetNumber, CAN_EMY_ERROR *pEmyError);
SINT32 can_SetAppReady(UINT32 NetNumber, BOOL8 ReadyFlag);


/*--- CANopen Event-Handling (via MIO-Attach-Event procedure) ---*/ 

struct can_msg                      /* CANopen event message data format */
{
    UINT16 Dlen  : 4;               /* Data length in bytes */
    UINT16 Rtr   : 1;               /* Remote transmit request flag */
    UINT16 CobId : 11;              /* 11-Bit COB-ID */
    UINT8  Data[8];                 /* 0..8 CAN data bytes (length) */
} __attribute__ ((packed));         /* CRID#38760 avoid problem with Bug in GCC V4.1.2 */

typedef struct can_msg CAN_MSG;     /* CAN message data structure */


/* CANopen Flags for Attach-/Detach-Event functions */

#define CAN_EVT_ALL         0x0000ffff      /* All COB-ID's, PDO's or Object Indexe's */ 

#define CAN_EVT_OBJ         0x01000000      /* Object received (not available in this version) */
#define CAN_EVT_PDO         0x02000000      /* PDO received (not available in this version) */
#define CAN_EVT_MSG         0x04000000      /* Message Events (enables COB-ID in receive table if necessary) */
#define CAN_EVT_EXCL        0x08000000      /* Exclusive Flag (no forwarding to CANopen Kernel) */ 
#define CAN_EVT_EXIST       0x10000000      /* Existing Message Flag (don't enables COB-ID in receive table) */ 

/* Possible Combinations of Event Flags and Types */

#define CAN_EVT_EXIST_MSG           (CAN_EVT_EXIST | CAN_EVT_MSG)       
#define CAN_EVT_EXCL_MSG            (CAN_EVT_EXCL  | CAN_EVT_MSG)       
#define CAN_EVT_EXIST_EXCL_MSG      (CAN_EVT_EXIST | CAN_EVT_EXCL | CAN_EVT_MSG)       

#define CAN_EVT_ALL_MSG             (CAN_EVT_ALL | CAN_EVT_MSG)       
#define CAN_EVT_ALL_EXIST_MSG       (CAN_EVT_ALL | CAN_EVT_EXIST | CAN_EVT_MSG)       
#define CAN_EVT_ALL_EXCL_MSG        (CAN_EVT_ALL | CAN_EVT_EXCL  | CAN_EVT_MSG)       
#define CAN_EVT_ALL_EXIST_EXCL_MSG  (CAN_EVT_ALL | CAN_EVT_EXIST | CAN_EVT_EXCL | CAN_EVT_MSG)       

/* Inline functions CANopen Event-Handling  */

MLOCAL SINT32 can_SendMsg(SINT32 NetNb, UINT32 CobId, UINT32 Dlen, UINT32 *pData);
MLOCAL SINT32 can_EnableRxMsg(SINT32 NetNb, UINT32 CobId);

/**
********************************************************************************
* @brief Sends a message to the CAN-Bus
*        Inline function for standard mio_DoCmd() function
*
* @param[in]  NetNb       1..8    CAN net number
* @param[in]  CobId       0..7ff  COB-ID der CAN-Message
* @param[in]  Dlen        0..8 | 0x10  number data bytes and/or RTR request bit
* @param[in]  *pData      data to be sent
*
* @param[out] N/A
*
* @retval     0   Message successfully sent
* @retval     !=  Error
* @private_definition{INC}
*******************************************************************************/
MLOCAL INLINE SINT32 can_SendMsg(SINT32 NetNb, UINT32 CobId, UINT32 Dlen, UINT32 *pData)
{  
    VOID *DrvId;
  
    if ((DrvId = can_GetCard(NetNb)) == NULL)
        return (-1);

    return (mio_DoCmd(DrvId, can_GetChanNb(NetNb), CPN_CMD_SENDMSG, CobId, Dlen, pData));
}

/**
********************************************************************************
* @brief Enables a CAN message in the receive filter table.
*        Inline function for standard mio_DoCmd() function
*
* @param[in]  NetNb       1..8    CAN net number
* @param[in]  CobId       0..7ff  11-Bit COB-ID message identifier
*
* @param[out] N/A
*
* @retval     0   Message enabled
* @retval     !=  Error
*
* @private_definition{INC}
*******************************************************************************/
MLOCAL INLINE SINT32 can_EnableRxMsg(SINT32 NetNb, UINT32 CobId)
{
    VOID *DrvId;

    if ((DrvId = can_GetCard(NetNb)) == NULL)
        return (-1);
    
    return (mio_DoCmd(DrvId, can_GetChanNb(NetNb), CPN_CMD_ENABLERXMSG, CobId));
}

/*----------------------------------------------------------------------------*/
/*--- CAN Interface for 11/-29-Bit native communication ---*/
/*----------------------------------------------------------------------------*/

/* Possible Event Flags for mio_AttachEvent() functions with 'NativeCan' mode */
#define CAN_NAT_EVT_ALL         0xffffffff  /* all event types (messages and error)*/
#define CAN_NAT_EVT_RX_MSG      0x20000000  /* using with COB-ID for specific rx message */
#define CAN_NAT_EVT_TX_MSG      0x40000000  /* using with COB-ID for specific tx message */
#define CAN_NAT_EVT_ERR_INT     0x80000000  /* SJA1000 error events only */
#define CAN_NAT_EVT_GRP_FLT     0x00000000  /* using with group filter bits for message groups */

#define CAN_NAT_EVT_COBID_MASK  0x1fffffff  /* using this mask to get all COB-IDs */
#define CAN_NAT_EVT_TYPE_MASK   0xe0000000  /* mask for event type (internal used)*/
#define CAN_NAT_EVT_TYPE_START  0x20000000  /* bit start position event types (internal used) */

#define CAN_NAT_EVT_RX_ALL      (CAN_NAT_EVT_RX_MSG | CAN_NAT_EVT_COBID_MASK) /* event type for all rx messages */
#define CAN_NAT_EVT_TX_ALL      (CAN_NAT_EVT_TX_MSG | CAN_NAT_EVT_COBID_MASK) /* event type for all tx messages */

/* Frame Info Flags in DLC Field (see also structure CAN_DLC) */

#define CAN_SFF     0x00        /* Standard Frame Format (11 Bit Identifier) */
#define CAN_EFF     0x80        /* Extended Frame Format (29 Bit Identifier) */
#define CAN_RTR     0x40        /* Standard Remote Transmit Request Frame (11-Bit) */
#define CAN_ERT     0xC0        /* Extended Remote Transmit Request Frame (29-Bit) */

#define CAN_SFF_DLC(Dlc)    (Dlc | CAN_SFF) /* CAN frame with 11-Bit COB-ID */
#define CAN_EFF_DLC(Dlc)    (Dlc | CAN_EFF) /* CAN frame with 29-Bit COB-ID */
#define CAN_RTR_DLC(Dlc)    (Dlc | CAN_RTR) /* CAN RTR frame with 11-Bit COB-ID */
#define CAN_ERT_DLC(Dlc)    (Dlc | CAN_ERT) /* CAN RTR frame with 29-Bit COB-ID */
#define CAN_DLC_2_LEN(Dlc)  (Dlc & 0x0F)    /* Get data length from DLC field */

#define CAN_TYPE_RX_EVT     0   /* Message event type receive frame */
#define CAN_TYPE_TX_EVT     1   /* Message event type transmit frame */
#define CAN_TYPE_ER_EVT     2   /* Message event type CAN error interrupt */
#define CAN_TYPE_TO_EVT     3   /* Internal C165 16 bit timer overrun interrupt */

typedef struct                  /* data length control field (Len + Frame Info Flags) */
{
    UINT32 Dlen : 4;            /* CAN message data length 0..8 bytes */
    UINT32 Type : 2;            /* FrameType (receive direction only) 0:Rx 1:Tx 2:CAN Error Event */
    UINT32 RTR  : 1;            /* Remote Transmit Request Frame */
    UINT32 EFF  : 1;            /* Extended Frame Format (29 Bit Identifier) */
    UINT32 Upd  : 1;            /* Update for RTR message (internal used only) */
    UINT32 Urg  : 1;            /* Urgent transmit mode (internal used only) */
    UINT32 Reserved : 22;       /* reserved */
} CAN_DLC;

typedef struct CAN_EXMSG        /* RX/TX-Message and error interrupt data structure */
{
    UINT32 CobId;               /* 11/29-Bit CAN Identifier */
    CAN_DLC Dlc;                /* Data length and control field */

    union {                     /* RX/TX frame data or error interrupt info data */
        UINT8 Bytes[8];         /* 0..8 message data bytes (valid length in Dlc) */
        UINT64 _u64;            /* message data for 64 bit access */
        struct
        {
            UINT8 Interrupt;    /* [ 3] SJA1000 interrupt flag register */
            UINT8 Status;       /* [ 2] SJA1000 status register */
            UINT8 ArbLost;      /* [11] SJA1000 arbitration lost capture register */
            UINT8 ErrCode;      /* [12] SJA1000 error code capture register */
            UINT8 ErrWarn;      /* [13] SJA1000 error warning limit register */
            UINT8 RxErrCnt;     /* [14] SJA1000 RX error counter register */
            UINT8 TxErrCnt;     /* [15] SJA1000 TX error counter register */
            UINT8 Reserved;     /* currently unused */
        } ErrInfo;
    } Data;                     /* 0..8 message data bytes (Dlc) */

    UINT32 TimeStamp;           /* C165 RX/TX or error interrupt time stamp with 1.0 or 1.6us resolution */
    UINT32 Reserved      : 16;  /* Reserved */
    UINT32 NoScale       : 1;   /* TRUE if no Scale to us is required */
    UINT32 FlagsReserved : 15;  /* TRUE if no Scale to us is required */
} CAN_EXMSG;                    /* Parameter for Send/Receive message functions */

typedef struct CAN_STATE        /* CAN Network status information */
{
    union {
        struct {
            UINT16 NoAck        : 1;    /* CAN: no bus activity (ACK missing)*/
            UINT16 CanOverrun   : 1;    /* CAN: overrun */
            UINT16 BusOff       : 1;    /* CAN: bus-off */
            UINT16 ErrStatSet   : 1;    /* CAN: error-status-bit set */
            UINT16 ErrStatReSet : 1;    /* CAN: error-status-bit reset */
            UINT16 TxOverrun    : 1;    /* transmit queue full */
            UINT16 EvtOverrun   : 1;    /* event buffer overrun */
            UINT16 RxOverrun    : 1;    /* receive queue overrun */
            UINT16 Reserved     : 7;
            UINT16 Reset        : 1;    /* CAN is in reset mode */
       } Bit;
       UINT16 Reg;
    };
    UINT32 Reserved[4];                 /* reserved for addition information's */
} CAN_STATE;

/**
********************************************************************************
* @brief Reads a 11/29-Bit CAN message from the receive queue. The read message
*        will be removed.
*
* @param[in]  NetNb     CAN network number
* @param[out] pExMsg    Pointer to a message data structure
*
* @retval     >0        CAN message received (and returned in pExMesg)
* @retval     0         no (more) message received
* @retval     <0        error (net not found, function not supported, net not
*                       running in 'NativeCan' mode, receive queue overrun)
*******************************************************************************/
MLOCAL INLINE SINT32 can_Receive(SINT32 NetNb, CAN_EXMSG *pExMsg)
{
    VOID *DrvId;

    if ((DrvId = can_GetCard(NetNb)) == NULL)
        return (-1);

    return (mio_DoCmd(DrvId, can_GetChanNb(NetNb), MIO_CMD_CAN_RECEIVE, pExMsg));
}

/**
********************************************************************************
* @brief Sends the given 11/29-Bit CAN message to the CAN bus. The message is
*        stored in a transmit queue. The function will not wait until the message
*        is really transmitted.
*
* @param[in]  NetNb     CAN network number
* @param[in]  pExMsg    Pointer to the message data structure
* @param[out] N/A
*
* @retval     0         all OK, CAN message successfully put to transmit queue
* @retval     <0        error (transmit queue full, network number not found,
*                       function not supported, net not running in 'NativeCan'
*                       mode)
*******************************************************************************/
MLOCAL INLINE SINT32 can_Send(SINT32 NetNb, CAN_EXMSG *pExMsg)
{
    VOID *DrvId;

    if ((DrvId = can_GetCard(NetNb)) == NULL)
        return (-1);

    return (mio_DoCmd(DrvId, can_GetChanNb(NetNb), MIO_CMD_CAN_SEND, pExMsg));
}

/**
********************************************************************************
* @brief This function starts the CAN-Controller with the configured mode.
*        (Normal Operating Mode | Listen Only Mode | Self Test Mode)
*
*        NOTE: After boot-up (initializing) the CAN controller stays in reset
*        mode. The CAN communication must be started by the application program
*        (calling this function).
*
* @param[in]  NetNb     CAN network number
* @param[out] N/A
*
* @retval     0         all OK, CAN controller successfully started
* @retval     <0        error (network number not found, function not supported,
*                       network not running in 'NativeCan' mode)
*******************************************************************************/
MLOCAL INLINE SINT32 can_Start(SINT32 NetNb)
{
    VOID *DrvId;

    if ((DrvId = can_GetCard(NetNb)) == NULL)
        return (-1);

    return (mio_DoCmd(DrvId, can_GetChanNb(NetNb), MIO_CMD_CAN_START));
}

/**
********************************************************************************
* @brief This function resets the CAN-Controller. RX/TX queues, statistics and
*        error counters are also reseted.
*
* @param[in]  NetNb     CAN network number
* @param[out] N/A
*
* @retval     0         all OK, CAN controller successfully reseted
* @retval     <0        error (network number not found, function not supported,
*                       network not running in 'NativeCan'  mode)
*******************************************************************************/
MLOCAL INLINE SINT32 can_Reset(SINT32 NetNb)
{
    VOID *DrvId;

    if ((DrvId = can_GetCard(NetNb)) == NULL)
        return (-1);

    return (mio_DoCmd(DrvId, can_GetChanNb(NetNb), MIO_CMD_CAN_RESET));
}

/**
********************************************************************************
* @brief This function changes the CAN Bit-Rate of the CAN-Network
*
* @param[in]  NetNb     CAN network number
* @param[in]  Baudrate  CAN Bit-Rate 10, 20, ... 10000 kBit/s
*
* @retval     0         all OK, Bit-Rate successfully changed
* @retval     <0        error (network number not found, function not supported
*                       on older drivers, wrong bit-rate)
*******************************************************************************/
MLOCAL INLINE SINT32 can_SetBaudRate(SINT32 NetNb, UINT32 Baudrate)
{
    VOID *DrvId;

    if ((DrvId = can_GetCard(NetNb)) == NULL)
        return (-1);

    return (mio_DoCmd(DrvId, can_GetChanNb(NetNb), MIO_CMD_CAN_BAUDRATE, Baudrate));
}

/**
********************************************************************************
* @brief This function returns status informations of the CAN-Network
*
* @param[in]  NetNb     CAN network number
* @param[out] pState    Pointer to get the status information
*
* @retval     0         all OK, status information is returned
* @retval     <0        error (network number not found, function not supported,
*                       network not running in 'NativeCan'  mode)
*******************************************************************************/
MLOCAL INLINE SINT32 can_State(SINT32 NetNb, CAN_STATE *pState)
{
    VOID *DrvId;

    if ((DrvId = can_GetCard(NetNb)) == NULL)
        return (-1);

    return (mio_DoCmd(DrvId, can_GetChanNb(NetNb), MIO_CMD_CAN_STATE, pState));
}


/********************************************************************************
*   CAN Message data logger and debug functions (shell commands) overview:
*       - can_Debug()
*       - can_StartLog()
*       - can_StopLog()
*       - can_ShowLog()
*       - can_ExportLog()
********************************************************************************/

/**
********************************************************************************
* @brief CAN Debug mode setting for message printing (shell function)
*        Note: The debug printing of the CAN messages data is processed by the
*        IDLE-Task, not by COP-Task itself. At higher CAN bus activity some
*        messages can be lost and are not printed. But the advantage of this is,
*        that the real-time behavior of the CAN communication is not affected by
*        active debug modes.
*
* @param[in]  NetNb CAN Network Number
* @param[in]  Debug Bit coded CAN debug mode
*                   Bit 1: (0x01) prints the received messages
*                   Bit 2: (0x02) prints the transmitted messages
*                   Bit 3: (0x04) prints CAN error interrupts
*                   0 No mode change, print the actual debug mode setting
*                   7 Prints all messages
*                   -1 Resets all debug modes
*
* @retval     Actual debug mode setting
*******************************************************************************/
SINT32 can_Debug(UINT32 NetNb, SINT32 Debug);

/**
********************************************************************************
* @brief Starts the CAN message data logging
*
* @param[in]  NetNb   CAN Network Number
* @param[in]  Size    Logging buffer size (number of messages)
* @param[in]  Mode    0 = Continues, 1 = Single (stop if size is reached)
********************************************************************************/
SINT32 can_StartLog(UINT32 NetNb, UINT32 Size, UINT32 Mode);

/**
********************************************************************************
* @brief Stops the CAN message data logging
*
* @param[in]  NetNb   CAN Network Number
* @param[in]  Free    0 keeps the logging buffer (for shell printing, export or restart)
*                     1 frees the logging buffer
*******************************************************************************/
SINT32 can_StopLog(UINT32 NetNb, BOOL Free);

/**
********************************************************************************
* @brief Prints the CAN messages data to standard out (shell function)
*
* @param[in]  NetNb     CAN Network Number
* @param[in]  StartIdx  Start index for printing
* @param[in]  NbrOf     Number of messages for printing (0=all)
* @param[in]  CobFlt    Prints only messages with matching COB-ID (0=all)
* @param[in]  DirFlt    Bit coded message direction filter (0=all)
*                       Bit 1 received messages
*                       Bit 2 transmitted
*
* @retval     Number of printed messages
*******************************************************************************/

SINT32 can_ShowLog(UINT32 NetNb, UINT32 StartIdx, UINT32 NbrOf, UINT32 CobFlt, UINT8 DirFlt);
/**
********************************************************************************
* @brief Exports the logged CAN massage data to a readable ASCII text file
*
* @param[in]  NetNb       CAN Network Number
* @param[in]  Filename    Filename oder NULL (Default 'can_x_log.txt)
* @param[in]  StartOffset Offset to the record beginning (oldest entry)
* @param[in]  NbrOf       Number of messages to export (0=all)
*
* @retval     Number of exported messages
*******************************************************************************/
SINT32 can_ExportLog(UINT32 NetNb, CHAR *Filename, UINT32 StartOffset, UINT32 NbrOf);

#ifdef __cplusplus
}
#endif

#endif
