/**
 ********************************************************************************
 * @file     ehd_e.h
 * @author   Stevic
 *
 * @brief This file contains all definitions and declarations exported by
 *        the Error Handler Server for use by modules running on the same CPU.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
 *******************************************************************************/

#ifndef EHD_E__H
#define EHD_E__H

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef _ASMLANGUAGE

#include <lst_e.h>

#endif                                  /* _ASMLANGUAGE */

#include <ehd.h>

#ifndef _ASMLANGUAGE

/**
 * @addtogroup EHD-API
 * @{
 */

/**
 * @brief Insert a new entry into an error list.
 *
 * An error entry is uniquely identified by the parameters (`pAppName`),
 * `SubNb` and `ErrorCode`.
 *
 * The parameter `pAppName` defines the name of the software module, which has
 * initiated the entry. With `pAppName` = 0 or `pAppName` = "", the application name
 * is taken from the caller. If the application name is not available, the name
 * of the task is used. If neither of both is available, then UNKNOWN is used.
 *
 * The parameters `SubNb` and `ErrorCode` specify the error. If any value other than NULL
 * is passed for the parameter `TimeStamp`, this value will be accepted as time-stamp,
 * otherwise the current system-time will be read and inserted. The type of processing for the entry is
 * specified more precisely with the parameter `Options`. Possible options are
 * #EHD_O_LOG, #EHD_O_GO and #EHD_O_DELEVT. The option #EHD_O_LOG generates an error
 * logbook entry, the option #EHD_O_GO treats the error as "comes/goes" and the
 * option #EHD_O_DELEVT generates a callback if the error is deleted via ehd_Remove()
 * function. This option is independent of the option #EHD_M_DELEVT that can be
 * specified in #EHD_PROC_ATTACHEVT. If optional data should also be attached to the
 * entry, it can be defined with `DataLen` and `pData`. The optional data of the function
 * is always copied to an internal memory location. If no data is desired then
 * `DataLen` and `pData` has to be set to NULL. The maximum length of the optional data is
 * #EHD_DATALEN. The function cuts off everything after that.
 *
 * @note If ehd_Insert() is called within the interrupt context and the parameter `TimeStamp` is 0,
 *       then 1.1.1970 00:00:00 will be used as the time stamp.
 *
 * @param[in]  ErrorType List to insert entry to. See #EHD_T_SYSERR and subsequent defines
 * @param[in]  pAppName  Tool name of entry producer (max. 8 characters); In case of NULL or ""
 *                       the name will be derived from the module or task name.
 * @param[in]  SubNb     Arbitrary sub error code
 * @param[in]  ErrorCode Arbitrary error code
 * @param[in]  TimeStamp Timestamp of entry; In case of 0 the actual time will be taken.
 * @param[in]  Options   Options of the entry. See #EHD_O_GO and subsequent defines
 * @param[in]  DataLen   Length of `pData` in bytes
 * @param[in]  pData     Optional data of entry
 *
 * @retval     #EHD_E_OK      Success
 * @retval     #EHD_E_ETYPE   Unknown error list
 * @retval     #EHD_E_FAILED  The function could not be executed properly
 */
SINT32 ehd_Insert(UINT32 ErrorType, CHAR * pAppName, UINT32 SubNb, UINT32 ErrorCode, UINT32 TimeStamp, UINT32 Options,
                   UINT32 DataLen, VOID * pData);

/**
 * @brief Remove an existing entry from an error list.
 *
 * The parameters has to match exactly the one of the existing entry.
 *
 * @note It is guaranteed that all inserted events are transfered to the attached callbacks,
 *       despite being removed in the meantime.
 *
 * @param[in]  ErrorType  List to remove entry from. See #EHD_T_SYSERR and subsequent defines
 * @param[in]  pAppName   Tool name of entry producer; In case of NULL or ""
 *                        the name will be derived from the module or task name.
 * @param[in]  SubNb      Sub error code
 * @param[in]  ErrorCode  Error code
 *
 * @retval     #EHD_E_OK       Success
 * @retval     #EHD_E_ETYPE    Unknown error list
 * @retval     #EHD_E_FOUND    Specified entry not found.
 * @retval     #EHD_E_FAILED   The function could not be executed properly.
 */
SINT32 ehd_Remove(UINT32 ErrorType, CHAR * pAppName, UINT32 SubNb, UINT32 ErrorCode);

/**
 * @brief Remove all existing entries from an error list.
 *
 * @param[in]  ErrorType  List to remove all entries from. See #EHD_T_SYSERR and subsequent defines
 * @param[in]  pAppName   Tool name of entry producer; In case of NULL or ""
 *                        the name will be derived from the module or task name;
 *                        In case of "*" all entries will be deleted,
 *
 * @retval     #EHD_E_OK       Success
 * @retval     #EHD_E_ETYPE    Unknown error list.
 * @retval     #EHD_E_FAILED   The function could not be executed properly.
 */
SINT32 ehd_RemoveAll(UINT32 ErrorType, CHAR * pAppName);

/**
 * @brief Mark an exiting error type as "Error is gone".
 *
 * If the mode "Renew the time stamp" is activated in the configuration ([SYSTEM] (ErrorHandler)
 * TimestampMode=Change) then the time stamp is updated by calling #ehd_SetStateGo().
 *
 * @note This state change only works for entries that are inserted with the option #EHD_O_GO.
 *
 * @param[in]  ErrorType  List that contains entry to change. See #EHD_T_SYSERR and subsequent defines
 * @param[in]  pAppName   Tool name of entry producer; In case of NULL or ""
 *                        the name will be derived from the module or task name.
 * @param[in]  SubNb      Sub error code
 * @param[in]  ErrorCode  Error code
 *
 * @retval     #EHD_E_OK       Success
 * @retval     #EHD_E_ETYPE    Unknown error list.
 * @retval     #EHD_E_FOUND    Specified entry not found
 * @retval     #EHD_E_FAILED   The function could not be executed properly. The entry is already
 *                            inactive. Either it was not entered with the option #EHD_O_GO, or
 *                            it has already been deactivated.
 *
 * #### Examples ####
 * @snippet doc_ehd_stateExample.c EHD entry SetStateGo
 * @see ehd_Insert()
 */
SINT32 ehd_SetStateGo(UINT32 ErrorType, CHAR * pAppName, UINT32 SubNb, UINT32 ErrorCode);

/**
 * @brief Temporarily disables the callback mechanism for all error lists.
 *
 * All currently pending and new error entries will be stored for later delivery
 * until the callback mechanism is enabled again.
 *
 * @retval     #EHD_E_OK      Success
 * @retval     #EHD_E_FAILED  Callbacks are already disabled.
 *
 * #### Examples ####
 * @snippet doc_ehd_DisableEventExample.c EHD ehd_DisableEventExample
 * @see #EHD_PROC_DISABLEEVENT
 * @see ehd_EnableEvent()
 */
SINT32 ehd_DisableEvent(VOID);

/**
 * @brief Enables the callback mechanism that was disabled using ehd_DisableEvent().
 *
 * All outstanding error entries will start to be delivered to their callbacks.
 *
 * @retval     #EHD_E_OK      Success
 * @retval     #EHD_E_FAILED  Callbacks are already enabled.
 *
 * #### Examples ####
 * @snippet doc_ehd_DisableEventExample.c EHD ehd_DisableEventExample
 * @see #EHD_PROC_ENABLEEVENT
 * @see ehd_DisableEvent()
 */
SINT32 ehd_EnableEvent(VOID);

/**
 * @brief Adds a new error consumer to the given error list, who will be informed
 *        via C callback about changes.
 *
 * The consumer will be informed if a new entry is inserted, an entry state is changed or an
 * entry is removed. The consumer specifies the C function used for callback.
 * Attachment of multiple callback functions per `ErrorType` is possible.
 *
 * The entries transmitted to the callback function can be adjusted using `Mode`. By default,
 * all currently defined entries are transmitted directly after the activation of the callback. Nevertheless,
 * the bit #EHD_M_ONLYNEW specifies, that only new entries are reported, that happen after the callback
 * has been registered. If the bit #EHD_M_DELEVT is set, the error handler will send a callback, when entries
 * are deleted using ehd_Remove().
 *
 * @note In order to be informed about deleted entries with #EHD_M_DELEVT, it is necessary to insert an error
 *       entry with the option #EHD_O_DELEVT (see ehd_Insert());
 *
 * The parameter `UserParam` is freely available and will be passed on to the callback
 * function unchanged. Such it is possible for example to use one callback for several error types and
 * use the parameter to differ them from each other.
 *
 * The callback function has to be implemented like: `void (*AppFunc)(EHD_ENTRY *pEntry, UINT32 UserPara)`
 *
 * @warning The C-callback is called directly (without buffering the events). The function therefore
 *          may not remain blocked for a long time. Otherwise, this would be a problem
 *          for the cycle time of the entered process.
 *
 * @param[in]  pAppName  Application consuming the EHD entries
 * @param[in]  ErrorType List to attach to. See #EHD_T_SYSERR and subsequent defines
 * @param[in]  Mode      Flag to specify about which errors to be informed.
 *                        See #EHD_T_SYSERR and subsequent defines.
 * @param[in]  AppFunc   Function to use for callback.
 * @param[in]  UserPara  User defined parameter that will be passed directly to the callback function
 *
 * @retval     #EHD_E_OK        Success
 * @retval     #EHD_E_ETYPE     Unknown error list
 * @retval     #EHD_E_DUPCBACK  C-callback is already attached
 * @retval     #EHD_E_FAILED    The function could not be executed properly
 *
 * #### Examples ####
 * @snippet doc_ehd_CallbackExample.c EHD doc_ehd_ReceiveErrors
 * @see ehd_DetachEvent()
 */
SINT32 ehd_AttachEvent(CHAR * pAppName, UINT32 ErrorType, UINT32 Mode,
                       VOID(*AppFunc)(), UINT32 UserPara);

/**
 * @brief Removes a specific callback from the error list, it is attached to.
 *
 * All resources that have been bound by ehd_AttachEvent() will be released.
 * It is guaranteed that after the function is ended, the callback can no longer be
 * called. If the callback is active at the time of the ehd_DetachEvent-call then ending
 * the function ehd_DetachEvent() is delayed until the running callback has been
 * completed.
 *
 * @param[in]  ErrorType   List to detach from. See #EHD_T_SYSERR and subsequent defines
 * @param[in]  AppFunc     Function to use for callback.
 * @param[in]  UserPara    User defined parameter that will be passed directly to the callback function
 *
 * @retval     #EHD_E_OK          Success
 * @retval     #EHD_E_ETYPE       Unknown error list.
 * @retval     #EHD_E_FOUND       Specified call-back not found.
 * @retval     #EHD_E_FAILED      The function could not be executed properly.
 *
 *  #### Examples ####
 * @snippet doc_ehd_CallbackExample.c EHD doc_ehd_ReceiveErrors
 * @see ehd_AttachEvent()
 */

SINT32 ehd_DetachEvent(UINT32 ErrorType, VOID(*AppFunc), UINT32 UserPara);

/**
 * @brief Get general information about an error list.
 *
 * @param[in]     ErrorType  List to get info about. See #EHD_T_SYSERR and subsequent defines
 * @param[in,out] pInfo      Memory to store general Information at.
 *
 * @retval     #EHD_E_OK      Success
 * @retval     #EHD_E_ETYPE   Unknown error list.
 */
SINT32 ehd_GetListInfo(UINT32 ErrorType, EHD_LISTINFO * pInfo);

/**
 * @brief This function can be used to query all entries of an error list.
 *
 * Entries of the error list will be returned as byte stream, the necessary memory will
 * be assigned by the function from the current memory partition.
 *
 * @note After processing, the caller has to release the memory.
 *
 * Due to the different data lengths of the returned #EHD_ENTRY list, the start of the
 * next entry is given by the calculation `pNextEntry = pCurrentEntry + sizeof (EHD_ENTRY) - 4 + pCurrentEntry.DataLen`.\n
 * For data lengths that cannot be divided by 4, the automatic byte alignment of the
 * compiler must be checked.
 *
 * @todo Example for ehd_GetList
 *
 * @param[in]      ErrorType  List to get list for. See #EHD_T_SYSERR and subsequent defines.
 * @param[in, out] ppList     Returned list entries
 * @param[in, out] pListLen   Number of entries returned in `pListLen`
 *
 * @retval     #EHD_E_OK      Success
 * @retval     #EHD_E_ETYPE   Unknown error list.
 * @retval     #EHD_E_FAILED  The function could not be executed properly.
 */
SINT32 ehd_GetList(UINT32 ErrorType, EHD_ENTRY ** ppList, UINT32 * pListLen);

/**
 * @brief Removes all callbacks of a specific IP address.
 *
 * @param[in]  IPAddr  Address of callbacks to remove; 0 for all
 */
void ehd_RemoveAllCallbacks(UINT32 IPAddr);

/**
 * @brief Adds an event list to an error list.
 *
 * This returned UserId can be used to poll for new
 * or changed error entries that will be stored in a so called event list.
 *
 * The event list will be ended if
 * - it is ended with the #ehd_RemoveEvtList() function.
 * - it does not poll the event list within the specified `Timeout` (in ms).
 * - the consumer continuously reads fewer entries than written and the event list exceeds twice the
 *   size of the error list size.
 *
 * @param[in]  ErrorType     List to add to. See #EHD_T_SYSERR and subsequent defines.
 * @param[in]  Timeout       Timeout in ms
 * @param[in,out]  pReply    Pointer to reply to write results to.
 *
 * @retval     #EHD_E_OK          Success
 * @retval     #EHD_E_ETYPE       Unknown error list.
 * @retval     #EHD_E_FAILED      The function could not be executed properly.
 * @see ehd_RemoveEvtList()
 * @see ehd_GetEvtList()
 */
SINT32 ehd_AddEvtList(UINT32 ErrorType, UINT32 Timeout, EHD_ADDEVTLIST_R * pReply);

/**
 * @brief Removes an event list added with ehd_AddEvtList().
 *
 *  All resources that have been bound by this event list will be released.
 *
 * @param[in]  ErrorType     List to remove from. See #EHD_T_SYSERR and subsequent defines.
 * @param[in]  UserId        User-Id of event list to poll for updates returned by #ehd_AddEvtList()
 * @param[in,out]  pReply    Pointer to reply to write results to.
 *
 * @retval     #EHD_E_OK       Success
 * @retval     #EHD_E_ETYPE    Unknown error list.
 * @retval     #EHD_E_FAILED   The function could not be executed properly.
 * @see ehd_AddEvtList()
 */
SINT32 ehd_RemoveEvtList(UINT32 ErrorType, UINT32 UserId, EHD_REMOVEEVTLIST_R * pReply);

/**
 * @brief Poll for changes in an event list added with ehd_AddEvtList().
 *
 * @note Use `sys_MemFree(*ppReply)` to release the memory that has been allocated by this function.
 *
 * The data will be stored in an allocated buffer. As an error entry may have additional
 * data of variable length, the individual entries are stored as byte stream (see example of #EHD_PROC_GETEVTLIST).
 *
 * @param[in]  ErrorType         List to get list from. See #EHD_T_SYSERR and subsequent defines.
 * @param[in]  UserId            ID of event list to poll for updates returned by ehd_AddEvtList()
 * @param[in]  CallType          Has to be set to 1.
 * @param[in]  MaxReplyDataLen   The maximum data length returned for `pReplyDataLen` in bytes
 * @param[out] pReplyDataLen     Actually returned data length for `pReplyDataLen`.
 * @param[in, out]  ppReply      Pointer to return address of results.
 *
 * @retval     #EHD_E_OK       Success.
 * @retval     #EHD_E_ETYPE    Unknown error list.
 * @retval     #EHD_E_FAILED   The function could not be executed properly.
 */
SINT32 ehd_GetEvtList(UINT32 ErrorType, UINT32 UserId, UINT32 CallType,
                      UINT32 MaxReplyDataLen, UINT32 * pReplyDataLen, EHD_GETEVTLIST_R ** ppReply);

/** @} */

#endif /* _ASMLANGUAGE */

#ifdef __cplusplus
}
#endif

#endif
