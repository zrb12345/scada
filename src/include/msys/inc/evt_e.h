/**
********************************************************************************
* @file     evt_e.h
* @author   ROIL
*
* @brief This file contains all definitions and declarations exported by
*        the Error Handler Server for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef EVT_E__H
#define EVT_E__H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ASMLANGUAGE

#include <lst_e.h>

#endif					/* _ASMLANGUAGE */

#include <evt.h>

#ifndef _ASMLANGUAGE

/**
 * @addtogroup EVT-API
 * @{
 */

/**
 * @brief Signature for function to register a callback for receiving EVT events.
 *
 * This function will be called each time a new EVT event is inserted. If it returns
 * an error, the event will not be inserted into the EVT list at all.
 *
 * @param[in]  pRecord     New record that is inserted.
 * @param[in]  userPara    User parameter that was set when attaching the function.
 *
 * @return #EVT_E_OK for success, or <tt>< 0</tt> in case of an error.
 * @see evt_AttachEvent()
 */
typedef SINT32 (*EVT_ATTACH_FUNCPTR)(EVT_RECORD *pRecord, UINT32 userPara);

/**
 * @brief Signature for function to register a callback to be called for file flushing.
 *
 * This function will be called each time it is requested to close the current archive
 * and start a new one.
 * The function should not return before the flushing process has completed.
 * Its return code will be returned to the caller.
 *
 * @param[in]  userPara    User parameter that was set when attaching the function.
 *
 * @return #EVT_E_OK for success, or <tt>< 0</tt> in case of an error.
 * @see evt_AttachFlush()
 */
typedef SINT32 (*EVT_FLUSH_FUNCPTR)(UINT32 userPara);

/**
 * @brief Signature for function to register a callback to be called for file flushing.
 *
 * If this function is called the current archive should be closed and a new should be
 * started. After this function returns the closed archive must not be changed any more.
 * Its return code will be returned to the caller.
 *
 * @param[in]  userPara    User parameter that was set when attaching the function.
 *
 * @return #EVT_E_OK for success, or <tt>< 0</tt> in case of an error.
 * @see evt_AttachNewArchive()
 */
typedef SINT32 (*EVT_NEWARCHIVE_FUNCPTR)(UINT32 userPara);

#define EVT_RECORDSIZE (sizeof(EVT_RECORD) - 4)   /**< Real size of an EVT_RECORD */

/**
 * @brief Event entry structure
 */
typedef struct
{
    CHAR8       Source[EVT_SOURCELEN_A];     /**< Event source */
	UINT32      EventID;                     /**< Event ID */
	UINT32      CategoryID;                  /**< Event category ID */
	SINT32      RetCode;                     /**< Event return code @ref M_E_, @ref SVI_E_, 0=OK */
	TIMESTAMP   Timestamp;                   /**< Event timestamp (system clock) */
	SINT8       Type;                        /**< Event type @ref EVT_T_ */
	SINT8       Spare1[35];                  /**< Not used, 0 for now */
} EVT_ENTRY;

/**
 * @brief Get all current entries of a EVT log.
 *
 * The memory is allocated within this function but must be freed by the caller using
 * sys_MemFree().
 *
 * @param[in]  logID      ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 * @param[out] ppList     Pointer to store a log of entries
 * @param[out] pListLen   Number of entries returned.
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_LIST      Invalid logID
 * @retval     #EVT_E_FAILED    ERROR - see log book for details
 *
 * #### Example ####
 * @snippet doc_evt_ClientExample.c Client_without_state_snippet
 */
SINT32 evt_GetLog(UINT32 logID, EVT_RECORD **ppList, UINT32 *pListLen);

/**
 * @brief Get general information about an event log. This call is also valid
 *        if the event log is configured to be disabled.
 *
 * @param[in]  logID     ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 * @param[in,out] pInfo  Pointer to info data to be filled
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_LIST      Invalid `logID`
 */
SINT32 evt_GetLogInfo(UINT32 logID, EVT_LOGINFO *pInfo);

/**
 * @brief Add a new security event with user data to the #EVT_L_SECURITY log.
 *
 * @param[in]  pEntry     Basic information of event
 * @param[in]  sessionID  `SessionID` returned by smi_Receive2() or found with
 *                        res_sec_GetUserLst() to derive additional user information.
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_BUFFER    If the write buffer of archiver is temporarily full
 * @retval     #EVT_E_FAILED    ERROR - see log book for details
 */
SINT32 evt_InsertSecEvent(EVT_ENTRY *pEntry, UINT32 sessionID);

/**
 * @brief Add a new application event to an application log.
 *
 * @param[in]  logID      ID of the concerned log. See #EVT_L_APP1 and subsequent defines.
 * @param[in]  pEntry     Event to insert.
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_LIST      Invalid logID
 * @retval     #EVT_E_BUFFER    If the write buffer of archiver is temporarily full
 * @retval     #EVT_E_FAILED    ERROR - see log book for details
 */
SINT32 evt_InsertAppEvent(UINT32 logID, EVT_ENTRY *pEntry);

/**
 * @brief This function registers a new session to get open EVT events.
 *
 * @note As the system allocates additional memory for each entry added to a session,
 *       the function evt_UpdateSession() must be called frequently in order
 *       to avoid extensive memory consumption.
 *       The session will be stopped if evt_UpdateSession() is not called within
 *       the configured timeout.
 *       The session will be stopped if the memory of the session becomes larger
 *       than the double of the configured logLen of the log.
 *
 * @param[in]  logID      ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 * @param[in]  mode       #EVT_M_ONLYNEW or #EVT_M_ALL
 * @param[in]  timeout    Timeout of the event list in ms
 * @param[in]  pReply     Memory where to put the reply
 * @param[out] pReply     Reply data
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_LIST      Invalid logID
 * @retval     #EVT_E_FAILED    ERROR - see log book for details
 *
 * @see evt_UpdateSession() for an example.
 */
SINT32 evt_StartSession(UINT32 logID, UINT32 mode, UINT32 timeout, EVT_STARTSESSION_R *pReply);

/**
 * @brief This function unregisters an existing session. All memory that is hold
 *        internally for this session is freed. Proceeding calls to the
 *        function evt_UpdateSession() will fail.
 *
 * @param[in]  logID      ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 * @param[in]  sessionID  Session ID received by evt_StartSession()
 * @param[in]  pReply     Memory where to put the reply
 * @param[out] pReply     Reply data
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_LIST      Invalid logID
 * @retval     #EVT_E_FOUND     If session has not been stared or already removed
 *
 * @see evt_UpdateSession() for an example.
 */
SINT32 evt_StopSession(UINT32 logID, UINT32 sessionID, EVT_STOPSESSION_R *pReply);

/**
 * @brief With this function a registered user fetches the open (until now unread)
 *        entries for his session.
 *
 * @note The function returns a copy of this memory that must be cleaned using
 *       sys_MemFree()
 *
 * @param[in]  logID             ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 * @param[in]  sessionID         Session ID received by 'evt_StartSession'
 * @param[in]  pReplyDataLen     Pointer to return length of reply
 * @param[in]  ppReply           Pointer for address of reply
 *
 * @param[out] pReplyDataLen     Length of reply in bytes
 * @param[out] ppReply           Allocated and filled reply
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_LIST      Invalid logID
 * @retval     #EVT_E_FOUND     If session has not been stared or already removed
 * @retval     #EVT_E_FAILED    ERROR - see log book for details
 *
 * #### Example ####
 * @snippet doc_evt_ClientExample.c Client_with_state_snippet
 */
SINT32 evt_UpdateSession(UINT32 logID, UINT32 sessionID,UINT32 *pReplyDataLen, EVT_UPDATESESSION_R **ppReply);

/**
 * @brief Insert a C-callback to the specific event log.
 *
 * @note The C-callback is called directly (without buffering the events). The function
 * therefore may not remain blocked for a long time. Otherwise, this would be a problem
 * for the cycle time of the process inserting the event.
 *
 * Attachment of multiple callback functions per `logID` is possible.
 *
 * @param[in]  logID          ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 * @param[in]  pAppName       Name of the application that records the callback.
 * @param[in]  mode           Use #EVT_M_ONLYNEW to receive new events only or #EVT_M_ALL to receive all events.
 * @param[in]  pCallback      Pointer to the callback function that is called in the case of a new event.
 * @param[in]  userPara       User defined parameter that is passed without any change to the callback function.
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_LIST      Invalid logID
 * @retval     #EVT_E_ETYPE     Invalid function pointer or default logger active
 * @retval     #EVT_E_DUPCBACK  C-callback is already attached
 * @retval     #EVT_E_FAILED    ERROR - see log book for details
 *
 * #### Example ####
 * @snippet doc_evt_ArchiverExample.c Archiver_example_snippet
 * @see evt_DetachEvent()
 */
SINT32 evt_AttachEvent(UINT32 logID, CHAR *pAppName, UINT32 mode, EVT_ATTACH_FUNCPTR pCallback, UINT32 userPara);

/**
 * @brief Remove an already inserted C-callback of the specific event log.
 *
 * @param[in]  logID         ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 * @param[in]  pCallback     Pointer of the callback function that is registered.
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_ETYPE     Invalid function pointer
 * @retval     #EVT_E_FOUND     Callback not registered with this function
 * @retval     #EVT_E_LIST      Invalid logID
 * @retval     #EVT_E_FAILED    ERROR - see log book for details
 *
 * @see evt_AttachEvent()
 */
SINT32 evt_DetachEvent(UINT32 logID, EVT_ATTACH_FUNCPTR pCallback);

/**
 * @brief Register a callback that will be called each time the function evt_Flush()
 *        is called.
 *
 * The logger should use this function to write or handle all outstanding entries.
 * Consider that after return all outstanding entries are processed and a reboot
 * should be possible.
 *
 * @param[in]  logID          ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 * @param[in]  pCallback      Pointer to the callback function to be called.
 * @param[in]  userPara       User defined parameter that is passed without any change to the callback function.
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_LIST      Invalid logID
 * @retval     #EVT_E_ETYPE     Invalid function pointer or default logger active
 * @retval     #EVT_E_DUPCBACK  A C-callback is already attached and has to be detached first
 * @retval     #EVT_E_FAILED    ERROR - see log book for details
 *
 * @see evt_AttachEvent() for an example.
 */
SINT32 evt_AttachFlush(UINT32 logID, EVT_FLUSH_FUNCPTR pCallback, UINT32 userPara);

/**
 * @brief Unregisters a callback registered with #evt_AttachFlush().
 *
 * @param[in]  logID         ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 * @param[in]  pCallback     Pointer of the callback function to be called
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_LIST      Invalid logID
 * @retval     #EVT_E_ETYPE     Invalid function pointer
 * @retval     #EVT_E_FOUND     Callback not registered with this function
 * @retval     #EVT_E_FAILED    ERROR - see log book for details
 *
 * @see evt_AttachFlush()
 */
SINT32 evt_DetachFlush(UINT32 logID, EVT_FLUSH_FUNCPTR pCallback);

/**
 * @brief Force all outstanding events to be processed by the archiver.
 *
 * This function returns after the flush has been completed.
 *
 * @param[in]  logID    ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_LIST      Invalid logID
 * @retval     #EVT_E_FAILED    ERROR - see log book for details
 * @return     Return values not stated above are returned by the attached flush function
 */
SINT32 evt_Flush(UINT32 logID);

/**
 * @brief This function registers a callback that will be called if the logger
 *        needs to close the current archive. The logger should use this function
 *        to close an archive - so that it will not be touched any more afterwards.
 *        Consider that after this function returns the archive file can be copied.
 *
 * @param[in]  logID          ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 * @param[in]  pCallback      Pointer of the callback function to be called.
 * @param[in]  userPara       User defined parameter that is passed without any change to the callback function.
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_LIST      Invalid logID
 * @retval     #EVT_E_ETYPE     Invalid function pointer or default logger active
 * @retval     #EVT_E_DUPCBACK  A C-callback is already attached and has to be detached first
 * @retval     #EVT_E_FAILED    ERROR - see log book for details
 *
 * @see evt_NewArchive()
 * @see evt_AttachEvent() for an example.
 */
SINT32 evt_AttachNewArchive(UINT32 logID, EVT_NEWARCHIVE_FUNCPTR pCallback, UINT32 userPara);

/**
 * @brief Unregisters a callback registered with evt_AttachNewArchive().
 *
 * @param[in]  logID         ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 * @param[in]  pCallback     Pointer of the callback function to be called
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled; not detached
 * @retval     #EVT_E_LIST      Invalid logID; not detached
 * @retval     #EVT_E_ETYPE     Invalid function pointer;  not detached
 * @retval     #EVT_E_FOUND     Callback not registered with this function; not detached
 * @retval     #EVT_E_FAILED    ERROR - see log book for details; not detached
 *
 * @see evt_AttachNewArchive()
 */
SINT32 evt_DetachNewArchive(UINT32 logID, EVT_NEWARCHIVE_FUNCPTR pCallback);

/**
 * @brief This function causes a new archive to be started.
 *
 * The #evt_AttachNewArchive() callback is called in the context of this caller.
 * After the function returns, the created archive will not change any more.
 *
 * @param[in]  logID            ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled
 * @retval     #EVT_E_LIST      Invalid logID
 * @retval     #EVT_E_FAILED    ERROR - see log book for details
 * @return     Return values not stated above are returned by the attached newArchive function
 *
 * @see #evt_AttachNewArchive()
 */
SINT32 evt_NewArchive(UINT32 logID);

/**
 * @brief This method should be used by archivers to make archived events
 *        available again after system reboot. By calling this function it is possible to
 *        append old events that have been inserted before a reboot. In order to
 *        keep the proper sequence of event entries, events with the highest RecordID
 *        should be appended first.
 *        As long as there is space, the events will be appended to the end of the
 *        event buffer. If no space is left the method will return with an error to
 *        indicate that no more old events can be appended any more.
 *
 * @note  To guarantee that event lists of clients are in sequence, only use this
 *        function when the system is in __init__ state. See
 *        <a href="§D-BA-0000039_8_4EBB8227_29§">§D-BA-0000039_8_4EBB8227_29_lab§</a>
 *
 * @param[in]  logID       ID of the concerned log. See #EVT_L_SECURITY and subsequent defines.
 * @param[in]  pRecord     Record to be appended at the end of the event list.
 *
 * @retval     #EVT_E_OK        OK
 * @retval     #EVT_E_INACTIVE  Log is not enabled; not inserted
 * @retval     #EVT_E_LIST      Invalid logID; not inserted
 * @retval     #EVT_E_BUFFER    If there is no space left for this old event
 * @retval     #EVT_E_BADINIT   If the system is not in the initialization phase
 * @retval     #EVT_E_PARM      If the parameter is not valid
 * @retval     #EVT_E_FAILED    ERROR - see log book for details; not inserted
 *
 * @see evt_AttachEvent() for an example.
 */
SINT32 evt_AppendBuffer(UINT32 logID, EVT_RECORD *pRecord);


/** @} */


#endif					/* _ASMLANGUAGE */

#ifdef __cplusplus
}
#endif

#endif
