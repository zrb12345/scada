/**
********************************************************************************
* @file     smi_e.h
* @author   Diem
*
* @brief This file contains all definitions and declarations exported by
*        the Standard Module Interface Library for use by modules running
*        on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef SMI_E__H
#define SMI_E__H

#ifdef __cplusplus
extern  "C"
{
#endif

#include <msgqlib.h>
#include <smi.h>
#include <lst_e.h>

#include <rpc\rpc.h>
#include <netinet\in.h>
#include <msys.h>

/**
 * @addtogroup SMI-DEF
 * @{
 */

#define SMI_MAXTCPCON   5               /**< Maximum number of concurrent TCP- connections for each SMI */
#define SMI_COPYLEN     20              /**< Maximum size of a message to be copied into message queue */

/**
 * @name Possible masks for SMI XId
 * @see #SMI_MSG.XId
 * @{
 */
#define SMI_SYSXIDMSK   0xffff0000      /**< Mask for the part in XId, that is used by the system itself */
#define SMI_USERXIDMSK  0x0000ffff      /**< Mask for the part in XId, that must be set by the user */
/** @} */

/**
 * @name Possible SMI message types
 * @{
 */
#define SMI_F_CALL      0x0001          /**< Message is a request */
#define SMI_F_REPLY     0x0002          /**< Message is an answer */
#define SMI_F_EXTRADATA 0x0010          /**< Message has extra data in LocData */
#define SMI_F_LOC       0x0100          /**< Message is for local CPU */
#define SMI_F_UDP       0x0200          /**< Global message using UDP */
#define SMI_F_TCP       0x0400          /**< Global message using TCP */
#define SMI_F_RTRY      0x0800          /**< Message is a retry */
#define SMI_F_COPY      0x1000          /**< Message is short, is copied and not allocated */
#define SMI_F_NOFREE    0x2000          /**< Do not automatically free memory after usage */
#define SMI_F_QSOAP     0x4000          /**< Global message with Quick SOAP */
#define SMI_F_SSL       0x8000          /**< Global message with SSL */
/** @} */

/**
 * @name Possible values for DelFlag
 * @see #SMI_ID.DelFlag
 * @{
 */
#define SMI_D_TCP       0x0001          /**< Delete TCP data */
#define SMI_D_UDP       0x0002          /**< Delete UDP data */
#define SMI_D_ACTIV     0x0004          /**< Delete complete SMI */
#define SMI_D_QSOAP     0x0008          /**< Delete QSOAP data */
#define SMI_D_SSL       0x0010          /**< Delete SSL data */
/** @} */

/**
 * @name Error codes
 * @{
 */
#define SMI_E_PROG      (M_ES_SMI|M_E_BADPROG)  /**< Program not valid */
#define SMI_E_PROC      (M_ES_SMI|M_E_BADPROC)  /**< Procedure not valid */
#define SMI_E_ARGS      (M_ES_SMI|M_E_BADARGS)  /**< Arguments not valid */
#define SMI_E_RPC       (M_ES_SMI|M_E_BADRPC)   /**< Version not valid */
#define SMI_E_AUTH      (M_ES_SMI|M_E_BADAUTH)  /**< Authentication failed */
#define SMI_E_VERS      (M_ES_SMI|M_E_BADVERS)  /**< Protocol version bad */
#define SMI_E_PERM      (M_ES_SMI|M_E_BADPERM)  /**< User has no permission to execute a specific
                                                     procedure */
/** @} */

#define SMI_MINOPENREP  5                       /**< Minimum number of open replies for reply queues */
#define SMI_MAXOPENREP  256                     /**< Maximum number of open replies allowed for reply queues */

/* Define for SMI communication task priority. */
#define SMI_TSK_PRIO    118                     /**< Default priority for SMI handler tasks */

/* Define for SMI number of ethernet interfaces  */
#define SMI_ETH_ELEMENTS    4                   /**< Number of network statistics */

/**
 * @brief SMI Handle
 */
typedef struct
{
    MSG_Q_ID MsgId;                     /**< Message queue ID */
    UINT32  ModuleNb;                   /**< Module number for SMI */
    UINT32  MinVers;                    /**< Oldest supported RPC-Version */
    UINT32  MaxVers;                    /**< Newest supported RPC-Version */
    UINT32  Port;                       /**< Port number for communication */
    UINT32  LastIP;                     /**< IP address of last message */
    UINT16  LastXId;                    /**< Transaction ID of last message */
    UINT16  LastPort;                   /**< Port number of last message */
    SINT32  UdpSock;                    /**< UDP communications socket */
    LST_ID *TcpCon;                     /**< TCP communications socket in case of SMI client */
    UINT16  DelFlag;                    /**< !0 indicates SMI must be deleted */
    SINT16  SecurityLevel;              /**< Application security Level */
    UINT32  ActSession;                 /**< Session ID of actual message */
} SMI_ID;

/** @brief SMI Message */
typedef struct
{

    UINT32  XId;                        /**< Transaction identification */
    union                               
    {
        struct                          /**< Destination address */
        {
            UINT32  DstSrcIP;           /**< Number of CPU */
            UINT32  DstSrcModul;        /**< Number of module */
        } Rpc;
        struct                          /**< Remote-CPU using UDP */
        {
            UINT32  DstSrcIP;           /**< IP address */
            UINT16  DstSrcPort;         /**< Port number */
        } Udp;
        struct                          /**< Remote-CPU using TCP */
        {
            UINT32  DstSrcIP;           /**< IP address */
            UINT16  DstSrcSock;         /**< Socket number */
        } Tcp;
        struct                          /**< Remote-CPU using TCP */
        {
            UINT32  DstSrcIP;           /**< IP address */
            UINT32  SockInf;            /**< Session ID */
        } QSoap;
    } Adr;                              /**< Address of Destination/Source */
    UINT16  Type;                       /**< Type of message */
    UINT16  ProtVers;                   /**< Version of protocol */
    UINT32  ProcRetCode;                /**< Procedure number or return code */
    UINT32  DataLen;                    /**< Size of data block */
    CHAR   *Data;                       /**< Pointer to data block */
    CHAR    LocData[SMI_COPYLEN];       /**< Local data */
} SMI_MSG;

/** @brief Structure for SMI Reply List Functions */
typedef struct
{
    UINT32  Starttime;                  /**< Starttime in Ticks */
    UINT32  Timeout;                    /**< Timeout in Ticks */
    UINT32  XId;                        /**< Transaction ID of call */
    FUNCPTR ReplyFunc;                  /**< Function to be executed on reply */
    SMI_MSG Msg;                        /**< SMI message of call */
} SMI_OPENREPLY;

/** @brief Structure for SMI Reply List Functions */
typedef struct
{
    UINT32  Size;                       /**< Size of list */
    UINT32  Used;                       /**< Number of entries used */
    SINT32  LowestFree;                 /**< First unused entry */
    SINT32  HighestUsed;                /**< Last used entry */
    SMI_OPENREPLY Data[SMI_MINOPENREP]; /**< Array with entries */
} SMI_OPENREPLIES;

EXTERN SINT32 smi_ReplyTimeoutTicks;    /**< SMI reply timeout in ticks */
EXTERN SINT32 smi_ReplyTimeoutMicro;    /**< SMI reply timeout in us */

/** @} */

/**
 * @addtogroup SMI-API
 * @{
 */

/**
* @brief This function creates a new SMI instance.
*
* @note  For application specific software modules this function is called
*        automatically by the system software.
*
* As result, the ID of the SMI is returned, which must be passed as a parameter
* (`pSmiId`) for almost all succeeding functions.
*
* @param[in]  ModuleNb    Module number of the module that wants to communicate
*                         via SMI.
*                         The module number of a module can be determined
*                         by the function res_GetModNb().
*                         In case of `ModuleNb = 0`, the SMI automatically allocates
*                         the next available module number.
*
* @param[in]  MinVers     Minimum protocol version supported.
* @param[in]  MaxVers     Maximum protocol version supported.
*
* @retval     !0          Identification of the SMI.
* @retval     0           Error in function execution.
*
* #### Examples ####
* @snippet doc_smi_Create.c example
*/
SMI_ID *smi_Create(UINT32 ModuleNb, UINT32 MinVers, UINT32 MaxVers);

/**
* @brief This function deletes a SMI instance.
*
* @note  For application specific software modules this function is called
*        automatically by the system software.
*
* @param[in]  SmiId       Id of the SMI
*
* @see #smi_Create()
*
* #### Examples ####
* @snippet doc_smi_Delete.c example
*/
VOID smi_Delete(SMI_ID * SmiId);

/**
* @brief This function receives the incoming SMI calls and the SMI replies to
*        its own calls.
*
* If a call/reply is received then the whole #SMI_MSG structure is returned.
*
* @note  This function is out of date. Use #smi_Receive2() instead (recommended).
*
* @note  If the data range of a message is below a certain maximum size, data is
*        stored within the #SMI_MSG structure. Otherwise, an allocated buffer for
*        data will be created.
*
* @param[in]  SmiId       ID of the SMI
* @param[in]  Timeout     Number of ticks to wait for a message. The parameter can
*                         have the special values:
*                         - 0: Return immediately if a message has been received or not
*                         - -1: Wait forever
*                         - #smi_ReplyTimeoutTicks: Configured SMI ReplyTimeout
* @param[out] pMsg        Pointer to received message
*
* @retval     0           Ok
* @retval     -1          Timeout
* @retval     -2          Error in function
*
* @see #smi_Receive2()
*/
SINT32 smi_Receive(SMI_ID * SmiId, SMI_MSG * pMsg, SINT32 Timeout);

/**
* @brief This function receives the incoming SMI calls and the SMI replies to
*        its own calls.
*
* If a call/reply is received then the whole #SMI_MSG structure is returned.
*
* @note  If the data range of a message is below a certain maximum size, data is
*        stored within the #SMI_MSG structure. Otherwise, an allocated buffer for
*        data will be created.
*
* @param[in]  SmiId       ID of the SMI
* @param[in]  Timeout     Number of ticks to wait for a message. The parameter can
*                         have the special values:
*                         - 0: Return immediately if a message has been received or not
*                         - -1: Wait forever
*                         - #smi_ReplyTimeoutTicks: Configured SMI ReplyTimeout
* @param[out] pMsg        Pointer to received message
* @param[out] User        User session ID if the user is logged in.
*                         The session ID can be forwarded to the svi_MsgHandler2()
*                         function for the verification of the user permissions.
*
* @retval     0           Ok
* @retval     -1          Timeout
* @retval     -2          Error in function
* @see #smi_FreeData()
*
* #### Examples ####
* @snippet doc_smi_Receive.c example
*/
SINT32 smi_Receive2(SMI_ID * SmiId, SMI_MSG * pMsg, SINT32 Timeout, UINT32 * User);

/**
* @brief Allocates a new SMI data buffer in global partition and initializes
*        its bits to zero.
*
* The reason for this is the optional protection layer that separates the
* application and the system. In order for the data to be used by the receiver,
* it must be stored in a memory area that both have access to. In this case,
* partition 1 is allocated for this memory. The assigned memory can only be
* freed by the function smi_MemFree().
*
* @param[in]  Size        Size of the memory block in bytes
*
* @retval     !0          Pointer to allocated memory
* @retval     0           Not enough memory
*/
VOID *smi_MemAlloc(UINT32 Size);

/**
* @brief Free previously allocated SMI data buffer.
*
* This function is required if there is, in terms of time, a status between
* calling the function smi_MemAlloc() and e.g. the function smi_SendCall(),
* which prevents a SMI message from being sent, and if the assigned buffer
* must be freed. The functions smi_SendCall() and smi_SendReply() free the
* memory even when there is an error.
*
* @note  This function is not intended to free data received by using the function
*        #smi_Receive2(). Therefore the function smi_FreeData() exists.
*
* @param[in]  pBuff   Pointer to the SMI data buffer to be deallocated
*
* @see #smi_MemAlloc()
*/
VOID smi_MemFree(VOID * pBuff);

/**
* @brief This function frees the SMI communication user data (payload), that
*        is automatically assigned by the function #smi_Receive2().
*
* The function remains neutral for messages without user data. It also remains
* neutral if it is called multiple times for a message.
*
* @param[in]  pMsg        Pointer to the message
*
* #### Examples ####
* @snippet doc_smi_Receive.c example
*/
VOID smi_FreeData(SMI_MSG * pMsg);

/**
* @brief This function sends a SMI call.
*
* The data buffer must be allocated with the function smi_MemAlloc().
* The data buffer is freed by this function even if it returns error.
*
* The parameter `XId` is used to transfer a 16 bit number, which is then
* automatically returned in the corresponding SMI reply (RPC standard).
*
* If the communication partner has installed access control with security
* level >= 1, a valid authentication must also be transferred. Therefore,
* an additional pointer to an authentication byte stream, which provides
* the function smi_Login(), must be specified as well as the define
* #SMI_AUTH, which must be specified in the parameter `ProtVers`.
*
* @param[in]  SmiId       ID of the SMI
* @param[in]  CpuNb       IP address of the communication partner or
*                         #SMI_LOCALCPU for local communication
* @param[in]  XId         Transaction ID
* @param[in]  ModuleNb    Module number of destination module
* @param[in]  ProtVers    Protocol version and type (#SMI_UDP, #SMI_TCP, #SMI_QSOAP, #SMI_SSL)
* @param[in]  Proc        Procedure number
* @param[in]  Data        Pointer to allocated data buffer; 0 -> no data
* @param[in]  DataLen     Length of allocated data buffer; 0 -> no data
* @param[in]  pAuth       Pointer to authentication byte stream; 0 -> no authentication
*                         Only valid with ProtVers #SMI_AUTH
*
* @retval     0           OK
* @retval     <0          Error in function
*
* #### Examples ####
* @snippet doc_smi_SendCall.c example local
* @snippet doc_smi_SendCall.c example remote
*
* @see #smi_SendCCall()
*/
#ifdef SMI_LIB__C
SINT32 smi_SendCall(SMI_ID * SmiId, UINT32 CpuNb, UINT16 XId,
                    UINT32 ModuleNb, UINT32 ProtVers, UINT32 Proc,
                    VOID * Data, UINT32 DataLen, VOID * pAuth);
#else
SINT32 smi_SendCall(SMI_ID * SmiId, UINT32 CpuNb, UINT16 XId,
                    UINT32 ModuleNb, UINT32 ProtVers, UINT32 Proc,
                    VOID * Data, UINT32 DataLen, ...);
#endif

/**
* @brief This function sends a SMI call with short data size.
*
*  The maximum data size of such messages is defined by #SMI_COPYLEN (20 Bytes).
*  No allocated buffer has to exist for these messages because a pointer to a
*  data location is used.
*
*  The parameter `XId` is used to transfer a 16 bit number, which is then
*  automatically returned in the applicable SMI reply (RPC standard).
*
*  If the communication partner has installed access control with security
*  level >= 1, a valid authentication must also be transferred. Therefore,
*  an additional pointer to an authentication byte stream, which provides
*  the function smi_Login(), must be specified as well as the define
*  #SMI_AUTH, which must be specified in the parameter `ProtVers`.
*
* @param[in]  SmiId       ID of the SMI
* @param[in]  CpuNb       IP address of the communication partner or
*                         #SMI_LOCALCPU for local communication
* @param[in]  XId         Transaction ID
* @param[in]  ModuleNb    Module number of destination module
* @param[in]  ProtVers    Protocol version and type (#SMI_UDP, #SMI_TCP, #SMI_QSOAP, #SMI_SSL)
* @param[in]  Proc        Procedure number
* @param[in]  Data        Pointer to data buffer; 0 -> no data
* @param[in]  DataLen     Length of data buffer; 0 -> no data
* @param[in]  pAuth       Pointer to authentication byte stream; 0 -> no authentication
*                         Only valid with ProtVers #SMI_AUTH
*
* @retval     0           OK
* @retval     <0          Error in function
*
* @see #smi_SendCall()
*/
#ifdef SMI_LIB__C
SINT32 smi_SendCCall(SMI_ID * SmiId, UINT32 CpuNb, UINT16 XId,
                     UINT32 ModuleNb, UINT32 ProtVers, UINT32 Proc,
                     VOID * Data, UINT32 DataLen, VOID * pAuth);
#else
SINT32 smi_SendCCall(SMI_ID * SmiId, UINT32 CpuNb, UINT16 XId,
                     UINT32 ModuleNb, UINT32 ProtVers, UINT32 Proc,
                     VOID * Data, UINT32 DataLen, ...);
#endif /* SMI_LIB__C */

/**
* @brief This function sends a SMI reply to an (externally) received SMI request.
*
* The reply data buffer must be allocated with the function #smi_MemAlloc().
* The data buffer is freed by this function even if it returns error.
*
* @note  The data that was received with the function #smi_Receive2() must be freed
*        by smi_FreeData() before accessing the function smi_SendReply().
*
* @param[in]  SmiId       ID of the SMI
* @param[in]  pMsg        Pointer to SMI call returned by the function #smi_Receive2()
* @param[in]  Ret         Return value of SMI header in reply message:
*                         #SMI_E_OK, #SMI_E_PROC, #SMI_E_ARGS
* @param[in]  Data        Pointer to allocated data buffer; 0 -> no data
* @param[in]  DataLen     Length of allocated data buffer;  0 -> no data
*
* @retval     0           OK
* @retval     <0          Error in function
*
* @see #smi_SendCReply()
*
* #### Examples ####
* @snippet doc_smi_Receive.c example
*/
SINT32 smi_SendReply(SMI_ID * SmiId, SMI_MSG * pMsg, UINT32 Ret, VOID * Data, UINT32 DataLen);

/**
* @brief This function sends a SMI reply to an (externally) received SMI request
*        with short data size.
*
* The maximum data size of such messages is defined by #SMI_COPYLEN (20 Bytes).
* No allocated buffer has to exist for these messages because a pointer to a
* data location is used.
*
* @param[in]  SmiId       ID of the SMI
* @param[in]  pMsg        Pointer to SMI call returned by the function #smi_Receive2()
* @param[in]  Ret         Return value of SMI header in reply message:
*                         #SMI_E_OK, #SMI_E_PROC, #SMI_E_ARGS
* @param[in]  Data        Pointer to data buffer; 0 -> no data
* @param[in]  DataLen     Length of data buffer;  0 -> no data
*
* @retval     0           OK
* @retval     <0          Error in function
*
* @see #smi_SendReply()
*/
SINT32 smi_SendCReply(SMI_ID * SmiId, SMI_MSG * pMsg, UINT32 Ret, VOID * Data, UINT32 DataLen);

/**
* @brief This function returns the maximum size of a reply message.
*
* The maximum size depends on the route and protocol of the call message.
*
* The following cases exist:
* - Local communication: 65536 bytes
* - Remote communication:
*   + UDP: 2008 bytes
*   + TCP: 16344 bytes
*   + QSOAP: 8152 bytes
*   + SSL: 8152
*
* @note  The real size depends on the local and remote SMI configuration settings!
*
* @note  #SMI_RPCHDRLEN bytes are used for the SMI header.
*
* @param[in]  SmiId       ID of the SMI
* @param[in]  pMsg        Pointer to the buffer with the message of which the
*                         length is to be determined
*
* @return     Maximum size of the reply message
*
* #### Examples ####
* @snippet doc_smi_MaxReplyLen.c example
*/
UINT32 smi_GetMaxReplyLen(SMI_ID * SmiId, SMI_MSG * pMsg);

/**
* @brief This function returns the own module number.
*
* This number is required if a module must identify itself.
*
* @param[in]  SmiId       ID of the SMI
*
* @return     Module number
*/
UINT32 smi_GetModuleNb(SMI_ID * SmiId);

/**
* @brief This function can be used to end an existing connection and to free all
*        internal resources and used ports.
*
* With stream oriented connections (TCP), this function also closes the TCP
* connection. Connections are automatically established with the initial function
* access from smi_SendCall().
*
* @param[in]  SmiId       ID of the SMI
* @param[in]  HostAddr    IP address of the communication partner
* @param[in]  Prog        Program number
* @param[in]  Vers        Protocol version and type (#SMI_UDP, #SMI_TCP, #SMI_QSOAP, #SMI_SSL)
* @param[in]  Prot        Protocol can be #SYS_P_UDP or #SYS_P_TCP
*
* @retval     0           OK
* @retval     < 0         Error
*/
SINT32 smi_CloseConnection(SMI_ID * SmiId, UINT32 HostAddr, UINT32 Prog, UINT32 Vers, UINT32 Prot);

/**
* @brief This function redirects the reply message to another destination as
*        the call has been received from.
*
* @note This is only possible for UDP protocol.
*
* @param[in]  pMsg        Pointer to SMI call message
* @param[in]  Ip          IP address to send reply to
*
* @retval     0           OK
* @retval     -1          Error
*/
SINT32 smi_SetReplyIp(SMI_MSG * pMsg, UINT32 Ip);

/**
* @brief Enable SMI-UDP broadcast mode.
*
* This function only enables broadcast mode if UDP support is enabled. If UDP is
* not enabled (e.g. security level = 4) no action is performed and OK is returned.
*
* @param[in]  SmiId       ID of the SMI
*
* @retval     0           OK
* @retval     -1          Error
*/
SINT32 smi_EnableBroadcast(SMI_ID * SmiId);

/**
* @brief The function can be used for the login on another controller.
*
* It sends the SMI call #RES_PROC_LOGIN2 to the RES module and waits for its response.
* The maximum timeout is the configured SMI ReplyTimeout.
*
* @param[in]  SmiId       ID of the SMI
* @param[in]  CpuNb       IP address of the communication partner
* @param[in]  ProtVers    Protocol version and type (#SMI_UDP, #SMI_TCP, #SMI_QSOAP, #SMI_SSL)
* @param[in]  User        User name
* @param[in]  Password    Password (The password is transmitted encrypted (MD5))
* @param[out] Auth        Authentication byte stream (This must be transferred as
*                         parameter `pAuth` for other SMI calls)
*
* @retval     0           OK
* @retval     -1          Error in communication
* @retval     -2          Error in reply
* @see #smi_Logout()
*/
SINT32 smi_Login(SMI_ID * SmiId, UINT32 CpuNb, UINT32 ProtVers,
                 CHAR * User, CHAR * Password, UINT8 Auth[128]);

/**
* @brief The function can be used for the logout on another controller.
*
* It sends the SMI call #RES_PROC_LOGOUT to the RES module and waits for its response.
* The maximum timeout is the configured SMI ReplyTimeout.
*
* @param[in]  SmiId       ID of the SMI
* @param[in]  CpuNb       IP address of the communication partner
* @param[in]  ProtVers    Protocol version and type (#SMI_UDP, #SMI_TCP, #SMI_QSOAP, #SMI_SSL)
* @param[in]  Auth        Authentication byte stream from smi_Login()
*
* @retval     0           OK
* @retval     -1          Error in communication
* @retval     -2          Error in reply
*
* @see #smi_Login()
*/
SINT32 smi_Logout(SMI_ID * SmiId, UINT32 CpuNb, UINT32 ProtVers, UINT8 Auth[128]);

/**
* @brief This function returns the module number of any module on another controller.
*
* It sends the SMI call #RES_PROC_MODNB to the RES module and waits for its response.
* The maximum timeout is the configured SMI ReplyTimeout.
*
* @param[in]  SmiId       ID of the SMI
* @param[in]  CpuNb       IP address of the communication partner
* @param[in]  ProtVers    Protocol version and type (#SMI_UDP, #SMI_TCP, #SMI_QSOAP, #SMI_SSL)
* @param[in]  ModuleName  Module name of the queried module
* @param[out] ModuleNb    Determined module number
*
* @retval     0           OK
* @retval     -1          Error in communication
* @retval     -2          Error in reply
*/
SINT32 smi_GetDstModuleNb(SMI_ID * SmiId, UINT32 CpuNb, UINT32 ProtVers,
                          CHAR * ModuleName, UINT32 * ModuleNb);

/**
* @brief This function initializes the reply administration queue.
*
* It initializes memory of the desired size in the current application partition.
* Without this access, the reply administration cannot be used. If the reply
* administration queue is no longer required, the memory must be freed with the
* function #sys_MemFree() from the same task that initiated the reply administration.
*
* @param[in]  Size         Size is the maximum amount of entries in the queue and
*                          must be a value between 5 and 256.
*
* @retval     !0           Identification of reply administration queue
* @retval     0            Not enough memory
*/
SMI_OPENREPLIES *smi_ReplyQInit(UINT32 Size);

/**
* @brief This function inserts an open reply into the reply administration queue.
*
* If a reply is received, it can be processed and released from the queue with
* the function #smi_ReplyQCheck2(). Note that function #smi_ReplyQCheck() is called
* cyclically to detect timeouts.
*
* @param[in]  pOpenList   Return of the smi_ReplyQInit() function
* @param[in]  Timeout     Number of ticks until a timeout
* @param[in]  XId         Transaction ID of the expected reply.
*                         Using this ID, the entry in the list can later be identified.
* @param[in]  pMsg        Pointer to the SMI message of the request.
*                         The content of this structure is copied into the list
*                         and can be destroyed after this access.
* @param[in]  ReplyFunc   Pointer to the function which will be called at the
*                         arrival of the reply.
*
* @retval     0           OK, reply entered
* @retval     <0          Error, queue is full
*
* @see #smi_ReplyQInit()
*
* #### Examples ####
* @snippet doc_smi_ReplyQAdd.c example
*/
SINT smi_ReplyQAdd(SMI_OPENREPLIES * pOpenList, UINT32 Timeout,
                   UINT32 XId, SMI_MSG * pMsg, FUNCPTR ReplyFunc);

/**
* @brief This function executes an entry in the reply administration queue.
*
* It searches in the reply administration queue for entries of the transferred
* transaction ID and executes the appropriate reply-function if `XId` is identical.
* Only the application range (mask #SMI_USERXIDMSK) of the `XId` is compared.
*
* @param[in]  pOpenList   Return of the #smi_ReplyQInit() function
* @param[in]  XId         Transaction ID to be searched for in the reply
*                         administration queue.
* @param[in]  Parm        Can be selected freely and is passed to the reply
*                         function without change.
*
* @retval     0           OK, reply found, executed and removed from queue
* @retval     -1          Error, no entry in queue with this `XId`
*
* @see #smi_ReplyQInit()
* @see #smi_ReplyQAdd()
*
* #### Examples ####
* @snippet doc_smi_ReplyQExecute.c example
*/
SINT smi_ReplyQExecute(SMI_OPENREPLIES * pOpenList, UINT32 XId, SINT32 Parm);

/**
* @brief This function searches the reply administration queue for entries with
*        timeout and executes the appropriate reply function in case of a timeout.
*
* At the occurrence of the first timeout the function is terminated.
*
* @param[in]  pOpenList   Return of the #smi_ReplyQInit() function
* @param[in]  Parm        Can be selected freely and is passed to the reply
*                         function without change.
*
* @retval     0           OK, no timeout found
* @retval     -1          Error, a timeout found
*
* @see #smi_ReplyQInit()
* @see #smi_ReplyQAdd()
*
* #### Examples ####
* @snippet doc_smi_ReplyQCheck.c example
*/
SINT smi_ReplyQCheck(SMI_OPENREPLIES * pOpenList, SINT32 Parm);

/**
* @brief This function searches the reply administration queue for entries with
*        timeout and executes the appropriate reply function in case of a timeout.
*
* Compared to the function #smi_ReplyQCheck(), this function processes the
* complete list and returns the number of entries found with timeout.
*
* @param[in]  pOpenList       Return of the #smi_ReplyQInit() function
* @param[in]  Parm            Can be selected freely and is passed to the reply
*                             function without change.
*
* @retval     Number of entries with timeout
*
* @see #smi_ReplyQInit()
* @see #smi_ReplyQAdd()
*/
SINT smi_ReplyQCheck2(SMI_OPENREPLIES * pOpenList, SINT32 Parm);


/** @} */

#ifdef __cplusplus
}
#endif



#endif
