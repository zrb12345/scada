/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     ehd.h
* @author   Fritsche
* @brief    Error Handler Server
*           This file contains all definitions and declarations exported by
*           the Error Hander Server, that could be used by modules running on
*           another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef EHD__H
#define EHD__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>
#include <msys.h>

/**
 * @addtogroup EHD-DEF
 * @{
 */
#define EHD_DATALEN     80  /**< Maximum size of additional info #EHD_ENTRY.Data */
#define EHD_LNAMELEN    20  /**< Size of error list name without '\0' termination */
#define EHD_LNAMELEN_A  ((EHD_LNAMELEN + 1 + 3) & 0xfffffffc)    /**< EHD_LNAMELEN + '\0' + aligned */
#define EHD_SVIVALUELEN 40  /**< Size of SVI value in byte @deprecated Not used. */

/**
 * @name Possible error types
 * @{
 */

#define EHD_T_SYSERR    1   /**< System error */
#define EHD_T_ERR       2   /**< Application error */
#define EHD_T_WRN       3   /**< Application warning */
#define EHD_T_INF       4   /**< Application info */
#define EHD_T_NBOFTYPES 10  /**< Only 4 are used by the system */
/** @} */

/**
 * @name Possible values for EHD_ENTRY.State
 * @{
 */

#define EHD_S_ACTIV     1   /**< Error comes */
#define EHD_S_DEACTIV   2   /**< Error goes */
#define EHD_S_DELETE    3   /**< Error is deleted */
/** @} */

/**
 * @name Possible options for error entries
 * @{
 */

#define EHD_O_LOG       0x0001   /**< Make log book entry as well */
#define EHD_O_GO        0x0010   /**< Add state "Comes/Goes" to entry */
#define EHD_O_DELEVT    0x0020   /**< Send event on delete */
#define EHD_O_TEXT      0x0040   /**< Mark data of entry to contain text */
/** @} */

/**
 * @name Possible values for EHD_ATTACHEVT_C.Mode
 * @{
 */

#define EHD_M_ONLYNEW   0x0001   /**< Ignore already inserted errors in list */
#define EHD_M_DELEVT    0x0002   /**< Send event on delete  @since V1.10 Release */
/** @} */

/**
 * @name Possible values for EHD_ATTACHEVT_C.Prot
 * @{
 */

#define EHD_P_UDP   SYS_P_UDP    /**< Call back using UDP @deprecated like #EHD_PROC_ATTACHEVT */
#define EHD_P_TCP   SYS_P_TCP    /**< Call back using TCP @deprecated like #EHD_PROC_ATTACHEVT */
/** @} */

/**
 * @name Possible error codes for EHD_*.RetCode
 * @{
 */

#define EHD_E_OK        M_E_OK   /**< @copybrief #M_E_OK */
#define EHD_E_ETYPE     (M_ES_EHD | M_E_LISTID)  /**< @copybrief #M_E_LISTID */
#define EHD_E_FOUND     (M_ES_EHD | M_E_NOOBJ)   /**< @copybrief #M_E_NOOBJ */
#define EHD_E_NOOBJ     (M_ES_EHD | M_E_NOOBJ)   /**< @copybrief #M_E_NOOBJ */
#define EHD_E_INACTIVE  (M_ES_EHD | M_E_INVSTATE)    /**< @copybrief #M_E_INVSTATE */
#define EHD_E_FAILED    (M_ES_EHD | M_E_FAILED)  /**< @copybrief #M_E_FAILED */
#define EHD_E_DUPCBACK  (M_ES_EHD | M_E_DUPRES)  /**< @copybrief #M_E_DUPRES */
/** @} */

#ifndef _ASMLANGUAGE
/**
 * Structure of one error entry.
 * @note All arbitrary fields together form a unique ID to identify an entry.
 */
typedef struct
{
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Arbitrary name of error producer */
    UINT32  SubNb;              /**< Arbitrary sub error code */
    UINT32  ErrorCode;          /**< Arbitrary error code */
    UINT32  TimeStamp;          /**< Timestamp in seconds since 1.1.1970 */
    UINT32  Options;            /**< Additional attributes. See #EHD_O_LOG and subsequent defines */
    UINT32  State;              /**< State of error.  See #EHD_S_ACTIV and subsequent defines */
    UINT32  DataLen;            /**< Size of optional data */
    UINT8   Data[1];            /**< Optional data */
} EHD_ENTRY;

/** @} */

/**
 * @addtogroup EHD-SMI
 * @{
 */

/**
 * @name Possible SMI Commands
 * @{
 */

/**
 * @brief Attach a SMI event callback.
 *
 * @details Adds a new error consumer to the given error list, who will be informed via SMI callback about changes. He
 * will be informed if a new entry is inserted, an entry state is changed or an entry is removed. The
 * consumer specifies the RPC call that will be used for callback.
 *
 * #### Usage ####
 * The entries transmitted to the callback function can be adjusted using #EHD_ATTACHEVT_C.Mode. By default,
 * all currently defined entries are transmitted directly after the activation of the callback. Nevertheless,
 * the bit #EHD_M_ONLYNEW specifies, that only new entries are reported, that happen after the callback
 * has been registered. If the bit #EHD_M_DELEVT is set, the error handler will send a callback, when entries
 * are deleted using ehd_Remove().
 *
 * @note In order to be informed about deleted entries with #EHD_M_DELEVT, it is necessary to insert an error
 *       entry with the option #EHD_O_DELEVT (see ehd_Insert());
 *
 * The parameter #EHD_ATTACHEVT_C.UserParam is freely available and will be passed on to the callback
 * function unchanged. Such it is possible for example to use one callback for several error types and
 * use the parameter to differ them from each other.
 *
 * @param[in]   #EHD_ATTACHEVT_C
 * @param[out]  #EHD_ATTACHEVT_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_ETYPE    Unknown error list
 * @retval      #EHD_E_FAILED   Unspecified error
 * @see #EHD_PROC_DETACHEVT
 * @see #EHD_NEWENTRY_C
 * @deprecated Use combination of #EHD_PROC_ADDEVTLIST, #EHD_PROC_GETEVTLIST and #EHD_PROC_REMOVEEVTLIST instead.
 */
#define EHD_PROC_ATTACHEVT      100
/**
 * @brief Detach a SMI event callback.
 * @details Removes a specific callback from the error list, it is attached to.
 *
 * #### Usage ####
 * All resources that have been bound by #EHD_PROC_ATTACHEVT will be released.
 *
 * @param[in]   #EHD_DETACHEVT_C
 * @param[out]  #EHD_DETACHEVT_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_FOUND    Specified callback not found.
 * @retval      #EHD_E_FAILED   Unspecified error
 * @see #EHD_PROC_ATTACHEVT
 * @see #EHD_NEWENTRY_C
 * @deprecated Use combination of #EHD_PROC_ADDEVTLIST, #EHD_PROC_GETEVTLIST and #EHD_PROC_REMOVEEVTLIST instead.
 */
#define EHD_PROC_DETACHEVT      102
/**
 * @brief Get general information about an error list.
 *
 * @param[in]   #EHD_GETLISTINFO_C
 * @param[out]  #EHD_GETLISTINFO_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_ETYPE    Unknown error list
 * @retval      #EHD_E_FAILED   Unspecified error
 */
#define EHD_PROC_GETLISTINFO    104
/**
 * @brief Read all entries of an error list.
 *
 * #### Usage ####
 * Not all of the entries will fit into one SMI reply. Therefore it is necessary to call this
 * SMI function repeatedly until #EHD_GETLIST_R.NbOfEntries returns less entries than
 * requested (#EHD_GETLIST_C.LastIdx minus #EHD_GETLIST_C.FirstIdx) and would fit into one call.
 *
 * The offset to iterate over entries is the same as used for #EHD_PROC_GETEVTLIST.
 *
 * @note As this call is stateless there might be redundant and missing entries
 *       in successive calls when new errors are inserted concurrently. For a
 * consistent query use #EHD_PROC_GETEVTLIST instead.
 *
 * @param[in]   #EHD_GETLIST_C
 * @param[out]  #EHD_GETLIST_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_ETYPE    Unknown error list
 * @retval      #EHD_E_FAILED   Unspecified error
 */
#define EHD_PROC_GETLIST        106
/**
 * @brief Insert an error into an error list
 *
 * #### Usage ####
 * For details on using see ehd_Insert() as all parameters will be passed on to
 * this function without any change.
 *
 * @param[in]   #EHD_INSERT_C
 * @param[out]  #EHD_INSERT_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_ETYPE    Unknown error list
 * @retval      #EHD_E_FAILED   Unspecified error
 */
#define EHD_PROC_INSERT         108
/**
 * @brief Remove an error from an error list
 *
 * #### Usage ####
 * For details on using see ehd_Remove() as all parameters will be passed on to
 * this function without any change.
 *
 * @param[in]   #EHD_REMOVE_C
 * @param[out]  #EHD_REMOVE_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_ETYPE    Unknown error list
 * @retval      #EHD_E_FOUND    Specified entry not found.
 * @retval      #EHD_E_FAILED   Unspecified error
 */
#define EHD_PROC_REMOVE         110
/**
 * @brief Remove all errors of an error list.
 *
 * #### Usage ####
 * For details on using see ehd_RemoveAll() as all parameters will be passed on to
 * this function without any change.
 *
 * @param[in]   #EHD_REMOVEALL_C
 * @param[out]  #EHD_REMOVEALL_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_ETYPE    Unknown error list
 * @retval      #EHD_E_FAILED   Unspecified error
 */
#define EHD_PROC_REMOVEALL      112
/**
 * @brief Mark an error as gone.
 *
 * #### Usage ####
 * For details on using see ehd_SetStateGo() as all parameters will be passed on to
 * this function without any change.
 *
 * @param[in]   #EHD_SETSTATEGO_C
 * @param[out]  #EHD_SETSTATEGO_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_ETYPE    Unknown error list
 * @retval      #EHD_E_FAILED   Unspecified error
 */
#define EHD_PROC_SETSTATEGO     114
/**
 * @brief Disable all callbacks.
 * @details Temporary disables the callback mechanism for all error lists.
 *
 * #### Usage ####
 * All currently pending and new error entries will be stored for later delivery
 * until the callback mechanism is enabled again.
 *
 * @param[in]   #EHD_DISABLEEVENT_C
 * @param[out]  #EHD_DISABLEEVENT_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_FAILED   Unspecified error
 * @see #EHD_PROC_ENABLEEVENT
 * @see ehd_DisableEvent()
 */
#define EHD_PROC_DISABLEEVENT   116
/**
 * @brief Enable all callbacks.
 * @details Enables the callback mechanism that was disabled using #EHD_PROC_DISABLEEVENT.
 *
 * #### Usage ####
 * All outstanding error entries will start to be delivered to their callbacks.
 *
 * @param[in]   #EHD_ENABLEEVENT_C
 * @param[out]  #EHD_ENABLEEVENT_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_FAILED   Unspecified error
 * @see #EHD_PROC_DISABLEEVENT
 * @see ehd_EnableEvent()
 */
#define EHD_PROC_ENABLEEVENT    118
/**
 * @brief Get detailed information about a callback.
 * @details Returns the details of RPC callbacks that are registered using #EHD_PROC_ATTACHEVT.
 *
 * #### Usage ####
 * It is possible to register several callbacks to one error list. Therefore it is necessary to
 * call this function and increase #EHD_GETCBINFO_C.ServListIdx several times until
 * #EHD_GETCBINFO_R.RetCode is set to #EHD_E_NOOBJ.
 *
 * See #EHD_ATTACHEVT_C to interpret the returned information.
 *
 * @param[in]   #EHD_GETCBINFO_C
 * @param[out]  #EHD_GETCBINFO_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_ETYPE    Unknown error list
 * @retval      #EHD_E_NOOBJ    No more call-back elements. #EHD_GETCBINFO_C.ServListIdx is too big.
 * @retval      #EHD_E_FAILED   Unspecified error
 * @deprecated As #EHD_PROC_ATTACHEVT is deprecated this function has no use any more.
 */
#define EHD_PROC_GETCBINFO      120
/**
 * @brief Adds a new event list to an error-list
 * @details The returned UserId can be used to poll for new
 * or changed error entries that will be buffered in this event list.
 *
 * #### Usage ####
 * The event list will be ended if
 * - it is ended with the ehd_RemoveEvtList() function.
 * - it does not poll the event list within the specified timeout (in ms).
 * - the consumer continuously reads fewer entries than written and the event list exceeds twice the
 *   size of the error list size.
 *
 * @param[in]   #EHD_ADDEVTLIST_C
 * @param[out]  #EHD_ADDEVTLIST_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_ETYPE    Unknown error list
 * @retval      #EHD_E_FAILED   Unspecified error
 *
 * #### Examples ####
 * @snippet doc_ehd_useEventListExample.c Attaching to error list
 * @see #EHD_PROC_REMOVEEVTLIST
 */
#define EHD_PROC_ADDEVTLIST     122
/**
 * @brief Removes an event list of an error list.
 * @details Removes an event list added with #EHD_PROC_ADDEVTLIST. All resources that have been
 * bound by this event list will be released.
 *
 * @param[in]   #EHD_REMOVEEVTLIST_C
 * @param[out]  #EHD_REMOVEEVTLIST_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_ETYPE    Unknown error list
 * @retval      #EHD_E_FAILED   Unspecified error
 *
 * #### Examples ####
 * @snippet doc_ehd_useEventListExample.c Detaching from error list
 * @see #EHD_PROC_ADDEVTLIST
 */
#define EHD_PROC_REMOVEEVTLIST  124
/**
 * @brief Gets outstanding entries of an event list
 * @details Poll for changes in an event list added with #EHD_PROC_ADDEVTLIST.
 *
 * #### Usage ####
 * Not all of the entries will fit into one SMI reply. Therefore it is necessary to call this
 * SMI function repeatedly until #EHD_GETEVTLIST_R.NbOfOpenEvents is 0.
 *
 * @param[in]   #EHD_GETEVTLIST_C
 * @param[out]  #EHD_GETEVTLIST_R
 * @retval      #EHD_E_OK
 * @retval      #EHD_E_ETYPE    Unknown error list
 * @retval      #EHD_E_FOUND    Specified entry not found
 * @retval      #EHD_E_FAILED   Unspecified error
 *
 * #### Examples ####
 * @snippet doc_ehd_useEventListExample.c Reading from error list
 * ...
 * @snippet doc_ehd_useEventListExample.c Reading from error list content
 * @see #EHD_PROC_ADDEVTLIST
 */
#define EHD_PROC_GETEVTLIST     126
/** @} */
/**
 * Structure for the SMI-Call #EHD_PROC_ATTACHEVT
 */
typedef struct
{
    UINT32  ErrorType;          /**< List to attach to. See #EHD_T_SYSERR and subsequent defines */
    UINT32  IPAddr;             /**< IP Address of user (passed on to smi_SendCall()). */
    UINT32  ProgNb;             /**< SMI program number of user (passed on to smi_SendCall()). */
    UINT32  ProtVers;           /**< SMI protocol version of user (passed on to smi_SendCall()). */
    UINT32  Prot;               /**< SMI protocol type (passed on to  smi_SendCall()). */
    UINT32  ProcNb;             /**< SMI procedure number (passed on to smi_SendCall()). */
    /**
     * Flag to specify about which errors to be informed.
     *   See #EHD_M_ONLYNEW and subsequent defines.
     */
    UINT32  Mode;
    UINT32  UserParam;          /**< User parameter that will be added to the sent data #EHD_NEWENTRY_C */
} EHD_ATTACHEVT_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_ATTACHEVT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  CallbackId;         /**< A unique identifier of the attached callback */
} EHD_ATTACHEVT_R;

/**
 * Structure for the SMI-Call #EHD_PROC_DETACHEVT
 */
typedef struct
{
    UINT32  CallbackId;         /**< Unique identifier of the callback returned by #EHD_PROC_ATTACHEVT */
} EHD_DETACHEVT_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_DETACHEVT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} EHD_DETACHEVT_R;

/**
 * Structure for the call back SMI of #EHD_PROC_ATTACHEVT
 *
 * The specific PROC number is registered with the call #EHD_PROC_ATTACHEVT and
 * user specific.
 *
 * @see #EHD_PROC_ATTACHEVT
 * @deprecated Use combination of #EHD_PROC_ADDEVTLIST, #EHD_PROC_GETEVTLIST and #EHD_PROC_REMOVEEVTLIST instead.
 */
typedef struct
{
    /**
     * Optional parameter copied from
     * EHD_ATTACHEVT_C.UserParam
     */
    UINT32  UserParam;
    UINT32  NbOfEntries;        /**< Size of list */
    UINT8   Data[1];            /**< Byte stream of EHD_ENTRY elements */
} EHD_NEWENTRY_C;

/**
 * Structure for reply to the call back SMI
 *
 * @note The callback has to reply with a valid reply (`RetCode` = #EHD_E_OK). Otherwise
 *       no further events will be delivered and the callback will be detached.
 *
 * @see #EHD_PROC_ATTACHEVT
 */
typedef struct
{
    SINT32      RetCode;                /**< Return code. See #EHD_PROC_ATTACHEVT for values.*/
    UINT32  CallbackId;         /**< Unique identifier of the callback returned by #EHD_PROC_ATTACHEVT */
} EHD_NEWENTRY_R;

/**
 * Structure for detailed information about an error list
 */
typedef struct
{
    CHAR8   Name[EHD_LNAMELEN_A];    /**< Name of error list */
    UINT32  MaxLength;          /**< Maximum number of entries in the error list */
    UINT32  ActLength;          /**< Actual number of entries in the error list */
    UINT32  NbOfOpenErrors;     /**< Number of active errors that are not marked as inactive with #EHD_O_GO */
} EHD_LISTINFO;

/**
 * Structure for the SMI-Call #EHD_PROC_GETLISTINFO
 */
typedef struct
{
    UINT32  ErrorType;          /**< List to get information for. See #EHD_T_SYSERR and subsequent defines. */
} EHD_GETLISTINFO_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_GETLISTINFO
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    EHD_LISTINFO    Inf;        /**< Detailed information requested */
} EHD_GETLISTINFO_R;

/**
 * Structure for the SMI-Call #EHD_PROC_GETLIST
 */
typedef struct
{
    UINT32  ErrorType;          /**< List to insert entry to. See #EHD_T_SYSERR and subsequent defines */
    UINT32  FirstIdx;           /**< First index to error list */
    UINT32  LastIdx;            /**< Last index to error list */
} EHD_GETLIST_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_GETLIST
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfEntries;    /**< Number of list elements */
    EHD_ENTRY   Entry[1];       /**< Error entries */
} EHD_GETLIST_R;

/**
 * Structure for the SMI-Call #EHD_PROC_INSERT
 */
typedef struct
{
    UINT32  ErrorType;          /**< List to insert entry to. See #EHD_T_SYSERR and subsequent defines */
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Application name of module reporting the error */
    UINT32  SubNb;              /**< Subcode of error entry to insert */
    UINT32  ErrorCode;          /**< Code of error entry to insert */
    UINT32  TimeStamp;          /**< Timestamp in seconds since 1970 of error entry to insert */
    /**
     * Options of error entry to insert.
     *   See #EHD_O_LOG and subsequent defines.
     */
    UINT32  Options;
    UINT32  Spare[4];           /**< Has to be 0 for now */
    UINT32  DataLen;            /**< Size of Data below of error entry to insert */
    UINT8   Data[EHD_DATALEN];  /**< User data up to 80 bytes of error entry to insert */
} EHD_INSERT_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_INSERT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} EHD_INSERT_R;

/**
 * Structure for the SMI-Call #EHD_PROC_REMOVE
 */
typedef struct
{
    UINT32  ErrorType;          /**< List to remove entry from. See #EHD_T_SYSERR and subsequent defines */
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Application name of module that reported the error */
    UINT32  SubNb;              /**< Subcode of error entry to remove */
    UINT32  ErrorCode;          /**< Code of error entry to remove */
    UINT32  Spare[4];           /**< Has to be 0 for now */
} EHD_REMOVE_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_REMOVE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} EHD_REMOVE_R;

/**
 * Structure for the SMI-Call #EHD_PROC_REMOVEALL
 */
typedef struct
{
    UINT32  ErrorType;          /**< List to remove all entries from. See #EHD_T_SYSERR and subsequent defines */
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Application name of module that reported the errors */
    UINT32  Spare[4];           /**< Has to be 0 for now */
} EHD_REMOVEALL_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_REMOVEALL
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} EHD_REMOVEALL_R;

/**
 * Structure for the SMI-Call #EHD_PROC_SETSTATEGO
 */
typedef struct
{
    UINT32  ErrorType;          /**< List in which to change entry. See #EHD_T_SYSERR and subsequent defines */
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Application name of module */
    UINT32  SubNb;              /**< Subcode of error */
    UINT32  ErrorCode;          /**< Code of error */
    UINT32  Spare[4];           /**< Has to be 0 for now */
} EHD_SETSTATEGO_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_SETSTATEGO
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} EHD_SETSTATEGO_R;

/**
 * Structure for the SMI-Call #EHD_PROC_DISABLEEVENT
 */
typedef struct
{
    UINT32  Spare;              /**< Has to be 0 for now */
} EHD_DISABLEEVENT_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_DISABLEEVENT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} EHD_DISABLEEVENT_R;

/**
 * Structure for the SMI-Call #EHD_PROC_ENABLEEVENT
 */
typedef struct
{
    UINT32  Spare;              /**< Has to be 0 for now */
} EHD_ENABLEEVENT_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_ENABLEEVENT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} EHD_ENABLEEVENT_R;

/**
 * Structure for the SMI-Call #EHD_PROC_GETCBINFO
 */
typedef struct
{
    UINT32  ErrorType;          /**< List for which to get callback info. See #EHD_T_SYSERR and subsequent defines */
    UINT32  ServListIdx;        /**< Select a specific callback among all registered (0..x) */
    UINT32  Spare[2];           /**< Has to be 0 for now */
} EHD_GETCBINFO_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_GETCBINFO
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  IPAddr;             /**< IP address of user */
    UINT32  ProgNb;             /**< SMI program number of user */
    UINT32  ProtVers;           /**< SMI protocol version of user */
    /**
     * SMI protocol type.
     * See #EHD_P_UDP and subsequent defines.
     */
    UINT32  Prot;
    UINT32  ProcNb;             /**< SMI procedure number */
    UINT32  UserParam;          /**< User parameter */
    UINT32  CallbackId;         /**< Unique identifier of the callback returned by #EHD_PROC_ATTACHEVT */
    UINT32  Spare[4];           /**< Has to be 0 for now */
} EHD_GETCBINFO_R;

/**
 * Structure for the SMI-Call #EHD_PROC_ADDEVTLIST
 */
typedef struct
{
    UINT32  ErrorType;          /**< List to add event list to. See #EHD_T_SYSERR and subsequent defines */
    /**
     * Timeout in ms after which the event list will be removed, if the
     * entries are not fetched via the SMI-Function EHD_PROC_GETEVTLIST
     */
    UINT32  Timeout;
    UINT32  Spare[2];           /**< Has to be 0 for now */
} EHD_ADDEVTLIST_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_ADDEVTLIST
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  UserId;             /**< User-Id as an unique identifier of the created event list */
    UINT32  Spare[2];           /**< Has to be 0 for now */
} EHD_ADDEVTLIST_R;

/**
 * Structure for the SMI-Call #EHD_PROC_REMOVEEVTLIST
 */
typedef struct
{
    UINT32  ErrorType;          /**< List of the event list to remove. See #EHD_T_SYSERR and subsequent defines */
    UINT32  UserId;             /**< User-Id of event list to remove returned by #EHD_PROC_ADDEVTLIST */
    UINT32  Spare[2];           /**< Has to be 0 for now */
} EHD_REMOVEEVTLIST_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_REMOVEEVTLIST
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[2];           /**< Has to be 0 for now */
} EHD_REMOVEEVTLIST_R;

/**
 * Structure for the SMI-Call #EHD_PROC_GETEVTLIST
 */
typedef struct
{
    UINT32  ErrorType;          /**< List of event list to poll. See #EHD_T_SYSERR and subsequent defines */
    UINT32  UserId;             /**< User-Id of event list to poll for updates returned by #EHD_PROC_ADDEVTLIST */
    UINT32  Spare[2];           /**< Has to be 0 for now */
} EHD_GETEVTLIST_C;

/**
 * Structure for the SMI-Reply #EHD_PROC_GETEVTLIST
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      Spare[3];       /**< Has to be 0 for now */
    UINT32      NbOfOpenEvents; /**< Number of open events that still need to be fetched. */
    UINT32      NbOfEntries;    /**< Number of list elements */
    EHD_ENTRY   Entry[1];       /**< Error entries */
} EHD_GETEVTLIST_R;

#endif                                  /* _ASMLANGUAGE */
/** @} */

#ifdef __cplusplus
}
#endif

#endif
