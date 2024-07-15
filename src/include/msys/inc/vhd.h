/**
********************************************************************************
* @file     vhd.h
* @author   Fritsche
*
* @brief This file contains all definitions and declarations exported by
*        the Visualization Handler Library, that could be used by modules
*        running on another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef VHD__H
#define VHD__H

#ifdef __cplusplus
extern  "C"
{
#if 0
}
#endif
#endif

#include <mtypes.h>
#include "svi.h"

/**
 * @addtogroup VHD-DEF
 * @{
 */

/** @brief Size of user name without '\0' termination */
#define VHD_UNAMELEN    40

/** @brief #VHD_UNAMELEN + '\0' + aligned */
#define VHD_UNAMELEN_A     ((VHD_UNAMELEN + 1 + 3) & 0xfffffffc)

/** @brief Invalid address (old definition) */
#define VHD_NOADDR      0xffffffff

/** @brief Separator character for symbolic SVI name */
#define VHD_SEPARATOR   '/'

/** @brief VHD-SMI protocol version */
#define VHD_PROTVERS    2

/**
 * @name Possible observation modes
 * @see #VHD_ADDLST_C.ObsMode
 * @{
 */

/**
 * @brief Value changes will be reported to the client automatically.
 */
#define VHD_SND_AUTO    0x0001

/**
 * @brief Value changes will be requested by the client explicitly.
 */
#define VHD_SND_REQ     0x0002

/**
 * @brief Value changes will be reported to the client automatically if enabled (trigger).
 * In addition to #VHD_SND_AUTO, the watch job starts/ends with
 * #VHD_PROC_STARTLST/#VHD_PROC_STOPLST
 */
#define VHD_SND_TRIGG   0x0004

#define VHD_REP_NORM    0x0100          /**< Answer without actual value */
#define VHD_REP_VAL     0x0200          /**< Answer with actual value */
/** @} */

/**
 * @name Possible report mode flags
 * @see #VHD_PROC_GETVALUE
 * @see #VHD_PROC_ADDLST
 * @{
 */
#define VHD_LST_NOSORT  0x0000          /**< List is not sorted */
#define VHD_LST_TSKSORT 0x0001          /**< List is sorted by task/software module */
#define VHD_LST_XERR    0x0010          /**< Report extended error information */
#define VHD_LST_MBTRANS 0x0020          /**< Signals a multiblock transfer */
/** @} */


/**
 * @brief Minimum allowed idle time [ms] before cleanup is performed (10 Minutes).
 * @see #VHD_NORMAL.MaxIdleTime
 */
#define VHD_MIN_IDLE_TIME 600000

/**
 * @name Address/value type definitions
 * Possible value types for the pre-coding data #VHD_EPREF.Type to define the adjacent element.
 *
 * Naming convention:
 * - BType ... base type
 * - RType ... compound type
 *
 * There are 2 different addressing types:
 *  - SVI address based types
 *  - Index based types
 * @{
 */
#define VHD_S_BTYPE     0               /**< Single BType (SVI-Address) */
#define VHD_L_BTYPE     1               /**< List of BTypes (SVI-Address) */
#define VHD_B_BTYPE     2               /**< Consecutive BTypes starting at a base type (SVI-Address) */
#define VHD_S_RTYPE     3               /**< Single RType (SVI-Address) */

#define VHD_SI_BTYPE    4               /**< Single index-based BType */
#define VHD_LI_BTYPE    5               /**< List of index-based BTypes */
#define VHD_BI_BTYPE    6               /**< Consecutive index-based BTypes starting at a base type */
#define VHD_SI_RTYPE    7               /**< Single index-based RType */
#define VHD_MAX_TYPE    7               /**< Max type code allowed */
/** @} */

/**
 * @anchor VHD_SM_
 * @name Possible session modes
 * @{
 */
#define VHD_SM_NORMAL    0              /**< Normal polling mode */
#define VHD_SM_CALLBACK  0x0001         /**< Callback mode */
#define VHD_SM_IDLEWATCH 0x0002         /**< Normal polling mode + idle watch */
/** @} */

/**
 * @anchor VHD_P_
 * @name Possible callback protocol types
 * @{
 */
#define VHD_P_UDP       SYS_P_UDP       /**< UDP protocol callback */
#define VHD_P_TCP       SYS_P_TCP       /**< TCP protocol callback */
/* @} */

/**
 * @anchor VHD_E_
 * @name Error codes
 * @{
 */
#define VHD_E_OK           M_E_OK                     /**< @copybrief #M_E_OK */
#define VHD_E_ADDR        (M_ES_VHD|M_E_BADADDR)      /**< Address of list element invalid */
#define VHD_E_USERID      (M_ES_VHD|M_E_USERID)       /**< @copybrief #M_E_USERID */
#define VHD_E_LISTID      (M_ES_VHD|M_E_LISTID)       /**< @copybrief #M_E_LISTID */
#define VHD_E_BADUSERLVL  (M_ES_VHD|M_E_BADUSERLVL)   /**< @copydoc #M_E_BADUSERLVL */
#define VHD_E_BADRANGE    (M_ES_VHD|M_E_BADRANGE)     /**< @copybrief #M_E_BADRANGE */
#define VHD_E_ACCDENIED   (M_ES_VHD|M_E_ACCDENIED)    /**< @copybrief #M_E_ACCDENIED */
#define VHD_E_DUPUSER     (M_ES_VHD|M_E_DUPUSER)      /**< @copybrief #M_E_DUPUSER */
#define VHD_E_NBELEM      (M_ES_VHD|M_E_NBELEM)       /**< @copybrief #M_E_NBELEM */
#define VHD_E_NOOBJ       (M_ES_VHD|M_E_NOOBJ)        /**< @copybrief #M_E_NOOBJ */
#define VHD_E_CBACK       (M_ES_VHD|M_E_CBACK)        /**< @copybrief #M_E_CBACK */
#define VHD_E_LIST        (M_ES_VHD|M_E_BADELEM)      /**< @copybrief #M_E_BADELEM */
#define VHD_E_FAILED      (M_ES_VHD|M_E_FAILED)       /**< @copybrief #M_E_FAILED */
#define VHD_E_NOWRITE     (M_ES_VHD|M_E_NOWRITE)      /**< @copybrief #M_E_NOWRITE */
#define VHD_E_NOREAD      (M_ES_VHD|M_E_NOREAD)       /**< @copybrief #M_E_NOREAD */
#define VHD_E_MBTRANS     (M_ES_VHD|M_E_MBTRANS)      /**< @copybrief #M_E_MBTRANS */
#define VHD_E_XERR        (M_ES_VHD|M_E_XERR)         /**< @copybrief #M_E_XERR */
/* @} */

/**
 * @name Errors returned in Int.Addr1
 * @{
 */
#define VHD_ER_ERROR    0xffffffff      /**< Element is bad, see Addr2 */
/** @} */

/**
 * @name Errors returned in Int.Addr2 if VHD_REP_XERR is set
 * @{
 */
#define VHD_ER_FAILED   SVI_E_FAILED    /**< @copybrief #SVI_E_FAILED */
#define VHD_ER_UNDEF    SVI_E_UNDEF     /**< @copybrief #SVI_E_UNDEF */
#define VHD_ER_ADDR     SVI_E_ADDR      /**< @copybrief #SVI_E_ADDR */
#define VHD_ER_WRITE    SVI_E_WRITE     /**< @copybrief #SVI_E_WRITE */
#define VHD_ER_OLDADDR  SVI_E_OLDADDR   /**< @copybrief #SVI_E_OLDADDR */
#define VHD_ER_NOMOD    SVI_E_NOMOD     /**< @copybrief #SVI_E_NOMOD */
/** @} */

#define VHD_CB_ADDLST   0               /**< Callback for #VHD_PROC_ADDLST */

/**
 * @brief VHD structure for SVI address (legacy).
 *
 * @deprecated Do not use #VHD_ADDR (old SVI-address definition).
 *             Use #SVI_ADDR instead.
 *
 * @internal
 * @note Only class B is implemented, do not use any other class!
 */
typedef union
{
    SVI_ADDR Addr;                      /**< SVI address */

    /** @brief Integer address (64 bit) */
    struct
    {
        UINT32  Addr1;                  /**< Address part 1 */
        UINT32  Addr2;                  /**< Address part 2 */
    } Int;

    /**
     * @brief Class B address structure
     */
    struct
    {
        UINT32  ObjectIdx;              /**< Index to object */
        UINT8   ObjectType;             /**< Type of object */
        UINT8   Reserved1;              /**< Reserved (must be 0)*/
        UINT8   Modul;                  /**< Module number */
        UINT8   Reserved2;              /**< Reserved (must be 0x10) */
    } Cb;
} VHD_ADDR;

/**
 * @brief Address definition for type #VHD_S_BTYPE
 */
typedef struct
{
    SVI_ADDR Addr;                      /**< Address */
} VHD_S_BT_ADDR;

/**
 * @brief Address/Value definition for type #VHD_S_BTYPE
 */
typedef struct
{
    SVI_ADDR Addr;                      /**< Address */
    UINT32  Value;                      /**< Value */
} VHD_S_BT_VAL;

/**
 * @brief Address definition for type #VHD_L_BTYPE (List of #VHD_S_BTYPE)
 */
typedef struct
{
    UINT32  NbOfElem;                   /**< Number of elements in address list */
    VHD_S_BT_ADDR Elem[1];              /**< Address list */
} VHD_L_BT_ADDR;

/**
 * @brief Address/Value definition for type #VHD_L_BTYPE (List of #VHD_S_BTYPE)
 */
typedef struct
{
    UINT32  NbOfElem;                   /**< Number of elements in element list */
    VHD_S_BT_VAL Elem[1];               /**< Address/Value list */
} VHD_L_BT_VAL;

/**
 * @brief Address definition for type #VHD_B_BTYPE
 */
typedef struct
{
    UINT32  NbOfElem;                   /**< Number of elements */
    SVI_ADDR Addr;                      /**< Address of #VHD_B_BTYPE  */
} VHD_B_BT_ADDR;

/**
 * @brief Address/Value definition for type #VHD_L_BTYPE
 */
typedef struct
{
    UINT32  NbOfElem;                   /**< Number of elements */
    SVI_ADDR Addr;                      /**< Address of  #VHD_L_BTYPE */
    UINT32  Value[1];                   /**< Values */
} VHD_B_BT_VAL;

/**
 * @brief Address definition for type #VHD_S_RTYPE
 */
typedef struct
{
    UINT32  ElemLen;                    /**< Number of elements */
    SVI_ADDR Addr;                      /**< Address of #VHD_S_RTYPE */
} VHD_S_RT_ADDR;

/**
 * @brief Address/Value definition for type #VHD_S_RTYPE
 */
typedef struct
{
    UINT32  ElemLen;                    /**< Number of elements */
    SVI_ADDR Addr;                      /**< Address of #VHD_S_RTYPE */
    UINT8   Value[1];                   /**< List of values */
} VHD_S_RT_VAL;

/**
 * @brief Address structure for single  #VHD_SI_BTYPE
 */
typedef struct
{
    SVI_ADDR Addr;                      /**< Address of #VHD_SI_BTYPE */
} VHD_SI_BT_ADDR;

/**
 * @brief Value structure for single  #VHD_SI_BTYPE
 */
typedef struct
{
    SINT32  Index;                      /**< Index */
    UINT32  Value;                      /**< Value of #VHD_SI_BTYPE */
} VHD_SI_BT_VAL;

/**
 * @brief Address structure for #VHD_LI_BTYPE (list of  #VHD_SI_BTYPE)
 */
typedef struct
{
    UINT32  NbOfElem;                   /**< Number of elements */
    VHD_SI_BT_ADDR Elem[1];             /**< List of address elements */
} VHD_LI_BT_ADDR;

/**
 * @brief Value structure for #VHD_LI_BTYPE (list of  #VHD_SI_BTYPE)
 */
typedef struct
{
    UINT32  NbOfElem;                   /**< Number of elements */
    VHD_SI_BT_VAL Elem[1];              /**< List of value elements */
} VHD_LI_BT_VAL;

/**
 * @brief Address structure for type #VHD_BI_BTYPE
 */
typedef struct
{
    UINT32  NbOfElem;                   /**< Number of elements */
    SVI_ADDR Addr;                      /**< Single address */
} VHD_BI_BT_ADDR;

/**
 * @brief Value structure for type #VHD_BI_BTYPE
 */
typedef struct
{
    UINT32  NbOfElem;                   /**< Number of elements */
    SINT32  Index;                      /**< Address of 1st BTYPE */
    UINT32  Value[1];                   /**< List of values */
} VHD_BI_BT_VAL;

/**
 * @brief Address structure for single #VHD_SI_RTYPE
 */
typedef struct
{
    UINT32  ElemLen;                    /**< Size of element */
    SVI_ADDR Addr;                      /**< Address */
} VHD_SI_RT_ADDR;

/**
 * @brief Value structure for single #VHD_SI_RTYPE
 */
typedef struct
{
    UINT32  ElemLen;                    /**< Size of element */
    SINT32  Index;                      /**< Address of RTYPE */
    UINT8   Value[1];                   /**< Value */
} VHD_SI_RT_VAL;

/**
 * @brief Precoding for each element in a VHD data stream.
 *
 * Possible type definitions:
 * - #VHD_S_BTYPE .. @copybrief VHD_S_BTYPE
 * - #VHD_L_BTYPE .. @copybrief VHD_L_BTYPE
 * - #VHD_B_BTYPE .. @copybrief VHD_B_BTYPE
 * - #VHD_S_BTYPE .. @copybrief VHD_S_BTYPE
 * - #VHD_SI_BTYPE .. @copybrief VHD_SI_BTYPE
 * - #VHD_LI_BTYPE .. @copybrief VHD_LI_BTYPE
 * - #VHD_BI_BTYPE .. @copybrief VHD_BI_BTYPE
 * - #VHD_SI_BTYPE .. @copybrief VHD_SI_BTYPE
 */
typedef struct
{
    UINT32  Type;                       /**< Type of element */
} VHD_EPREF;

/**
 * @brief Session callback information
 */
typedef struct
{
    UINT32  IPAddr;                     /**< Callback IP address */
    UINT32  ProgNb;                     /**< Callback SMI program number */
    UINT32  ProtVers;                   /**< Callback SMI protocol version */
    UINT32  Prot;                       /**< Callback SMI protocol type (#VHD_P_UDP, #VHD_P_TCP) */
    UINT32  ProcNb;                     /**< Callback SMI procedure number */
} VHD_CBACK;

/**
 * @brief Session information (normal mode, polling mode)
 */
typedef struct
{
    UINT32  MaxIdleTime;                /**< Maximum idle time [ms] */
    UINT32  Spare[4];                   /**< Reserved (must be 0) */
} VHD_NORMAL;

/** @} */


/**
 * @addtogroup VHD-SMI
 * @{
 */


/**
 * @name SMI commands
 * @{
 */

/**
 * @brief Start VHD session.
 *
 * This SMI function starts a new VHD client session. This is the entry function,
 * needed prior any subsequent VHD SMI functions are called.
 *
 * Required call parameters:
 *  - Name ... Session name used as identifier
 *  - Delay time ... waiting time after an observation cycle.<br>
 *    If <tt>DelayTime = 0</tt> then 300 ms is used as default value. The minimum
 *    supported delay time is 100 ms.
 *  - Session mode + mode specific information
 *
 *  Supported session modes:
 * - #VHD_SM_NORMAL ... @copybrief #VHD_SM_NORMAL
 * - #VHD_SM_IDLEWATCH ... @copybrief #VHD_SM_IDLEWATCH
 * - #VHD_SM_CALLBACK ... @copybrief #VHD_SM_CALLBACK
 *
 * In normal mode, clients may enable #VHD_SM_IDLEWATCH to cleanup orphaned sessions
 * automatically. On each session creation, a timeout check is performed. The minimum
 * timeout interval is 10 minutes.
 *
 * @note
 * Callback mode is still supported for legacy clients but should not be used anymore.<br>
 * New project/clients are advised to use #VHD_SM_NORMAL mode only!
 *
 * On success, the @c UserId as session identifier is returned. The @c UserId is
 * required for all subsequent VHD calls.
 *
 * @param[in] #VHD_STARTSESS_C
 * @param[out] #VHD_STARTSESS_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_FAILED
 * @retval #VHD_E_DUPUSER
 * @retval #VHD_E_CBACK
 */
#define VHD_PROC_STARTSESS      102

/**
 * @brief Stop VHD session.
 *
 * This SMI call stops a VHD session and frees all allocated resources and
 * connections. All monitoring lists are stopped if not already.
 *
 * @param[in]   #VHD_STOPSESS_C
 * @param[out]  #VHD_STOPSESS_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_USERID
 */
#define VHD_PROC_STOPSESS       104

/**
 * @brief Reset VHD session.
 *
 * This SMI call resets the session back to creation time - as if #VHD_PROC_STARTSESS
 * would have been called.
 *
 * @par
 * All monitoring lists are released!
 *
 * @note
 * Due to TCP/IP transmission, new actual values of the just deleted monitoring
 * lists may still be repeatedly sent to a user via callback, even though
 * #VHD_PROC_RESETSESS has been finished correctly.
 *
 * @param[in]   #VHD_RESETSESS_C
 * @param[out]  #VHD_RESETSESS_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_USERID
 */
#define VHD_PROC_RESETSESS      106

/**
 * @brief Get session information.
 *
 * This SMI function gets general session information. As session identifier
 * both, user name and user ID can be used.
 *
 * @param[in]   #VHD_GETSESSINF_C
 * @param[out]  #VHD_GETSESSINF_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_USERID
 */
#define VHD_PROC_GETSESSINF     108

/**
 * @brief Get/Read variable values.
 *
 * This SMI call reads the actual values for the given list of SVI variables
 * addresses. The list of SVI addresses (input parameter) and the list of the
 * actual read values (output parameter) are byte stream oriented.
 *
 * The individual actual values are requested from the target task via SVI.
 * The requested list is processed completely, even if some SVI variables
 * do not exist!
 *
 * Required call parameters:
 * - User ID as session identifier
 * - Report mode
 * - List of elements to read
 *
 * Supported report modes:
 * - #VHD_LST_NOSORT ... @copybrief #VHD_LST_NOSORT
 * - #VHD_LST_TSKSORT ... @copybrief #VHD_LST_TSKSORT
 * - #VHD_LST_XERR ... @copybrief #VHD_LST_XERR <br>
 *   Enables extended error reporting
 *
 * <b>Extended error reporting</b><br>
 * Reporting of individual error codes can be enabled in #VHD_GETVALUE_C.ReportMode
 * using #VHD_LST_XERR. In this report mode, \c Addr2 contains the detailed error code
 * in case of an error (return value of underlying SVI function). If #VHD_LST_XERR
 * is not set, the error code in @c Addr2 is always `-1` (general error).
 *
 * @note
 * The requested values are returned as binary element stream. A valid byte stream
 * follows for the return values #VHD_E_OK and #VHD_E_ADDR. <br>
 * For all other return values, only @c RetCode is relevant.
 *
 * @param[in]   #VHD_GETVALUE_C
 * @param[out]  #VHD_GETVALUE_R for single reply or
 * @param[out]  #VHD_GETXVALUE_R for multiblock transfer reply
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_FAILED
 * @retval #VHD_E_USERID
 * @retval #VHD_E_LIST
 * @retval #VHD_E_ADDR
 * @retval #VHD_E_MBTRANS Indicates a multiblock transfer
 */
#define VHD_PROC_GETVALUE       110

/**
 * @brief Set/Write variable values.
 *
 * This SMI call writes a list of set values to specified SVI variables. The list of
 * address/value pairs is passed as a binary byte stream. The set values are
 * transferred to the target task via SVI. The set value list is processed completely.
 * The addresses of not accepted target values are returned in the reply.
 *
 * <b>Extended error reporting</b><br>
 * Reporting of individual error codes can be enabled via @c ReportMode = #VHD_LST_XERR.
 * In this report mode, \c Addr2 contains the detailed error code in case of an error
 * (return value of underlying SVI function). If #VHD_LST_XERR is not set, the error
 * code in @c Addr2 is always `-1` (general error).
 *
 * <b>Multiblock transfer</b><br>
 * Multiblock transfer is needed if clients need to set process values that
 * exceed the maximum SMI packet size. Use @c ReportMode = #VHD_LST_MBTRANS to
 * indicate a multiblock transfer and set @c NbOfElem = 0.
 *
 * @param[in]   #VHD_SETVALUE_C
 * @param[out]  #VHD_SETVALUE_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @return #VHD_E_FAILED
 * @retval #VHD_E_USERID
 * @retval #VHD_E_NOWRITE
 */
#define VHD_PROC_SETVALUE       112

/**
 * @brief Create monitoring list to observe process values.
 *
 * This SMI function prompts the VHD to observe SVI variable value changes.
 * The monitoring interval is defined by #VHD_PROC_STARTSESS.
 *
 * There is only one monitoring task per VHD session. The actual values are
 * requested from the target task via SVI. The monitoring list will be processed
 * completely, even in case of underlying SVI errors.
 *
 * <b>Callback mode</b><br>
 * In case of value changes, all values belonging to a monitoring list are packaged
 * as a byte stream and transmitted to the user as Callback. In this case, the VHD
 * becomes a client and the user-side becomes a server. The callback mode is initialized
 * via #VHD_PROC_STARTSESS.
 * The list of addresses of the actual values (input parameter) and the list with
 * the actual values themselves (output parameter) are byte streams. If during the observation,
 * SVI addresses become invalid, it will not be reported by the callback.
 *
 * <b>Multiblock transfer</b><br>
 * Multiblock transfer is signaled by setting @c ReportMode = #VHD_LST_MBTRANS.
 * Multiblock transfer is not supported in case of callback mode.
 *
 * <b>Observation mode</b><br>
 * The observation mode (bit-coded) defines the notification type how value changes are
 * reported:<br>
 * - #VHD_SND_AUTO ... @copybrief #VHD_SND_AUTO <br>
 *   Report asynchronously in callback mode, monitoring starts immediately.
 * - #VHD_SND_TRIGG ... @copybrief #VHD_SND_TRIGG <br>
 *   Report asynchronously in callback mode, monitoring needs to be started/stopped
 *   using #VHD_PROC_STARTLST/#VHD_PROC_STOPLST. Initially the monitoring is
 *   stopped.
 * - #VHD_SND_REQ ... @copybrief #VHD_SND_REQ <br>
 *   Report on client request only. Thus clients can call #VHD_PROC_GETUPD to receive
 *   value changes on this monitoring list.
 *
 * @param[in]   #VHD_ADDLST_C
 * @param[out]  #VHD_ADDLST_R for standard reply or
 * @param[out]  #VHD_ADDXLST_R for multiblock transfer reply
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_LIST
 * @retval #VHD_E_NBELEM
 * @retval #VHD_E_CBACK
 */
#define VHD_PROC_ADDLST         114

/**
 * @brief Delete monitoring list.
 *
 * This SMI function deletes one or more monitoring lists previously created via
 * #VHD_PROC_ADDLST.
 *
 * <b>Callback mode</b><br>
 * In case of callback mode, after deleting a monitoring list, it is still
 * possible that clients receive outstanding callback calls.
 *
 * @param[in]   #VHD_DELLST_C
 * @param[out]  #VHD_DELLST_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_FAILED
 * @retval #VHD_E_USERID
 * @retval #VHD_E_LISTID One or more list ID(s) not valid
 */
#define VHD_PROC_DELLST         116

/**
 * Get update.
 *
 * This SMI function queries changes in a monitoring list, previously created via
 * #VHD_PROC_ADDLST. This function returns all changed process values since
 * last #VHD_PROC_GETUPD call. The process values are returned as packed byte
 * stream.
 *
 * <b>Multiblock transfer</b><br>
 * If the SMI reply exceeds the maximum SMI package size, multiblock transfer is
 * needed which is signaled as return code #VHD_E_MBTRANS. In this case, the update
 * must be received via #SVI_PROC_GETMULTIBLK instead.
 *
 * <b>Callback mode</b><br>
 * This update function is not supported in callback mode.
 *
 * @param[in]   #VHD_GETUPD_C
 * @param[out]  #VHD_GETUPD_R for standard reply
 * @param[out]  #VHD_GETXUPD_R for multiblock transfer reply
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_FAILED
 * @retval #VHD_E_USERID
 * @retval #VHD_E_LISTID
 * @retval #VHD_E_MBTRANS
 */
#define VHD_PROC_GETUPD         118

/**
 * @brief Get process variable addresses.
 *
 * This SMI function resolves SVI variable names (symbolic address) to 64-bit
 * machine addresses + SVI format information. As input, a zero-terminated list
 * of SVI variable names is passed. As output, a list of #VHD_ADDRINF information
 * is returned:
 * @code{.c}
typedef struct
{
    SVI_ADDR Addr;
    UINT32   Format;
} VHD_ADDRINF; @endcode
 *
 * <b>Error handling</b><br>
 * Invalid SVI variables which can not be resolved are marked with #VHD_NOADDR:
 * @code{.c}
VHD_ADDRINF.Addr.Int.Addr1 = VHD_NOADDR
VHD_ADDRINF.Addr.Int.Addr2 = VHD_NOADDR or SVI_E_*
VHD_ADDRINF.Format = ignore in case of error @endcode
 *
 * Possible error cause:
 * - Requested SVI variable name or software module not existing
 * - Permission denied (user level, no access allowed)
 *
 * @param[in]   #VHD_GETADDR_C
 * @param[out]  #VHD_GETADDR_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_FAILED
 * @retval #VHD_E_USERID
 * @retval #VHD_E_ADDR
 */
#define VHD_PROC_GETADDR        120

/**
 * @brief Reset monitoring list.
 *
 * This SMI function resets one or more monitoring lists previously created
 * via #VHD_PROC_ADDLST to its initial state. As result, all values of the
 * monitoring list are returned within the next monitoring cycle or the
 * next #VHD_PROC_GETUPD.
 *
 * @param[in]   #VHD_RESETLST_C
 * @param[out]  #VHD_RESETLST_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_FAILED
 * @retval #VHD_E_USERID
 * @retval #VHD_E_LISTID
 */
#define VHD_PROC_RESETLST       122

/**
 * @brief Start monitoring list.
 *
 * This SMI function starts the observation of a monitoring list to detect value
 * changes. The monitoring list needs to be created via #VHD_PROC_ADDLST first.
 *
 * Following observation modes support starting/stopping:
 * - #VHD_SND_AUTO ... @copybrief #VHD_SND_AUTO
 * - #VHD_SND_TRIGG ... @copybrief #VHD_SND_TRIGG
 *
 * The monitoring lists to start are passed as an array. The complete list will
 * be processed in any case, even in case of invalid list IDs.
 *
 * @note
 * After starting, all values of the list are returned in the first monitoring
 * cycle.
 *
 * @param[in]  #VHD_STARTLST_C
 * @param[out] #VHD_STARTLST_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_FAILED
 * @retval #VHD_E_USERID
 * @retval #VHD_E_LISTID
 *
 * @see #VHD_PROC_STOPLST
 */
#define VHD_PROC_STARTLST       124

/**
 * @brief Stop monitoring list.
 *
 * This SMI function stops the observation of a monitoring list.
 *
 * @param[in]   #VHD_STOPLST_C
 * @param[out]  #VHD_STOPLST_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_FAILED
 * @retval #VHD_E_LISTID
 * @retval #VHD_E_USERID
 *
 * @see #VHD_PROC_STARTLST
 */
#define VHD_PROC_STOPLST        126

/**
 * @brief Get callback information
 *
 * This SMI function returns information for a VHD callback, either for specified
 * `UserId` or given index (if `UserId`  is `0xFFFFFFFF`).
 *
 * @param[in]   #VHD_GETCBINFO_C
 * @param[out]  #VHD_GETCBINFO_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_FAILED
 * @retval #VHD_E_CBACK
 * @retval #VHD_E_NOOBJ No more callback elements or session found
 */
#define VHD_PROC_GETCBINFO      128

/**
 * @brief Start monitoring of an element.
 *
 * This SMI function enables the monitoring of an element in the monitoring list.
 * Use this function only after #VHD_PROC_STOPELEM.
 *
 * @param[in]  #VHD_STARTELEM_C
 * @param[out] #VHD_STARTELEM_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_USERID
 * @retval #VHD_E_LISTID
 * @retval #VHD_E_NBELEM Invalid element index (out of bounds)
 */
#define VHD_PROC_STARTELEM      130

/**
 * @brief Stop monitoring of an element.
 *
 * This SMI function disables the monitoring of an element in the monitoring list.
 * Use #VHD_PROC_STARTELEM to re-activate monitoring.
 *
 * @param[in]  #VHD_STOPELEM_C
 * @param[out] #VHD_STOPELEM_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_USERID
 * @retval #VHD_E_LISTID
 * @retval #VHD_E_NBELEM Invalid element index (out of bounds)
 */
#define VHD_PROC_STOPELEM       132

/**
 * @brief Get process variable addresses (extended version).
 *
 * This SMI function resolves SVI variable names (symbolic address) to 64-bit
 * machine addresses + SVI format information. As input, a zero-terminated list
 * of SVI variable names is passed. As output, a list of #VHD_XADDRINF information
 * is returned:
 * @code{.c}
typedef struct
{
    SVI_ADDR Addr;
    UINT16   Format;
    UINT16   ValLen;
} VHD_XADDRINF; @endcode
 *
 * <b>Error handling</b><br>
 * Invalid SVI variables which can not be resolved are marked with #VHD_NOADDR:
 * @code{.c}
VHD_XADDRINF.Addr.Int.Addr1 = VHD_NOADDR
VHD_XADDRINF.Addr.Int.Addr2 = VHD_NOADDR or SVI_E_*
VHD_XADDRINF.Format = ignore in case of error
VHD_XADDRINF.ValLen = ignore in case of error @endcode
 *
 * Possible error cause:
 * - Requested SVI variable name or software module not existing
 * - Permission denied (user level, no access allowed)
 *
 * @param[in]   #VHD_GETXADDR_C
 * @param[out]  #VHD_GETXADDR_R
 *
 * @return #VHD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #VHD_E_FAILED
 * @retval #VHD_E_USERID
 * @retval #VHD_E_ADDR
 */
#define VHD_PROC_GETXADDR       134

/** @} */

/**
 * @brief Structure for the SMI-Call #VHD_PROC_STARTSESS.
 */
typedef struct
{
    CHAR8   Name[VHD_UNAMELEN_A];       /**< Name of user */
    /**
     * @brief Pause in [ms] between last and first observation list.
     * Use @c 0 for default value
     */
    UINT32  DelayTime;
    UINT32  SessionMode;                /**< Session mode @ref VHD_SM_ */
    union
    {
        VHD_NORMAL Normal;              /**< Normal polling mode information */
        VHD_CBACK Callback;             /**< Callback mode information */
    } un;                               /**< Union for additional information depending on \c SessionMode */
} VHD_STARTSESS_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_STARTSESS.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    UINT32  UserId;                     /**< User ID for session identification */
} VHD_STARTSESS_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_STOPSESS.
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
} VHD_STOPSESS_C;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_STOPSESS.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
} VHD_STOPSESS_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_RESETSESS.
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
} VHD_RESETSESS_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_RESETSESS.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
} VHD_RESETSESS_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_GETSESSINF
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID or \c 0 if not used */
    CHAR8   Name[VHD_UNAMELEN_A];       /**< User Name or '\0' if not used */
} VHD_GETSESSINF_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_GETSESSINF.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    CHAR8   Name[VHD_UNAMELEN_A];       /**< User name */
    UINT32  UserId;                     /**< User ID */
    /**
     * @brief Timestamp of starting time in seconds since 01.01.1970
     */
    UINT32  StartTime;
} VHD_GETSESSINF_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_SETVALUE (Standard call).
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
    UINT32  ReportMode;                 /**< Reporting mode */
    UINT32  NbOfElem;                   /**< Number of list elements */
    UINT8   ElemList[1];                /**< List of elements */
} VHD_SETVALUE_C;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_SETVALUE (Multiblock transfer call).
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
    UINT32  ReportMode;                 /**< Reporting mode */
    UINT32  NbOfElem;                   /**< Number of list elements */
    UINT32  TotalLen;                   /**< Total length of the transfer */
    /* (address + data) */
    UINT32  NbOfMBElem;                 /**< Number of elements in the multiblock transfer */
} VHD_SETXVALUE_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_SETVALUE (Standard reply).
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    UINT32  NbOfElem;                   /**< Size of list with invalid SVI addresses */
    SVI_ADDR InvElemList[1];            /**< List of invalid SVI addresses */
} VHD_SETVALUE_R;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_SETVALUE (Extended error reply).
 * Structure for ReportMode #VHD_LST_XERR
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    UINT32  NbOfElem;                   /**< Number of list elements */
    UINT8   ElemList[1];                /**< List of elements */
} VHD_SETXERRVALUE_R;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_SETVALUE (Multiblock transfer reply).
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    UINT32  BufferId;                   /**< Multiblock buffer ID */
} VHD_SETXVALUE_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_GETVALUE (Standard call).
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
    UINT32  ReportMode;                 /**< Reporting mode */
    UINT32  NbOfElem;                   /**< Number of list elements */
    UINT8   ElemList[1];                /**< List of elements */
} VHD_GETVALUE_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_GETVALUE (Standard reply).
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    UINT32  NbOfElem;                   /**< Number of list elements */
    UINT8   ElemList[1];                /**< List of elements */
} VHD_GETVALUE_R;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_GETVALUE (Multiblock transfer reply).
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    UINT32  Reserved;                   /**< Reserved*/
    UINT32  NbOfElem;                   /**< Number of list elements */
    UINT32  BufferId;                   /**< Multiblock buffer ID */
    UINT32  NbOfBuffElem;               /**< Number of elements in the multiblock buffer */
} VHD_GETXVALUE_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_ADDLST.
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
    /**
     * @brief Observation mode
     * - #VHD_SND_AUTO ... @copybrief VHD_SND_AUTO
     * - #VHD_SND_REQ ... @copybrief VHD_SND_REQ
     * - #VHD_SND_TRIGG ... @copybrief VHD_SND_TRIGG
     */
    UINT32  ObsMode;
    UINT32  ReportMode;                 /**< Reporting mode */
    UINT32  UserParam;                  /**< User parameter passed back in */
    /* callback unchanged */
    UINT32  NbOfElem;                   /**< Number of list elements */
    UINT8   ElemList[1];                /**< List of elements */
} VHD_ADDLST_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_ADDLST (Standard reply).
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    UINT32  ListId;                     /**< ID of created observation list */
    UINT32  NbOfElem;                   /**< Number of list elements */
    union
    {
        UINT8   ElemList[1];            /**< List of elements */
        SVI_ADDR InvElemList[1];        /**< List of invalid addresses */
    } un;                               /**< Compound union */
} VHD_ADDLST_R;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_ADDLST (Multiblock transfer reply).
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    SINT32  Reserved;                   /**< Reserved */
    UINT32  ListId;                     /**< ID of created observation list */
    UINT32  NbOfElem;                   /**< Number of list elements */
    UINT32  BufferId;                   /**< ID of the multiblock buffer */
} VHD_ADDXLST_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_DELLST.
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
    UINT32  NbOfId;                     /**< Number of monitoring IDs in list */
    UINT32  ListId[1];                  /**< List of monitoring IDs */
} VHD_DELLST_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_DELLST.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
} VHD_DELLST_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_RESETLST.
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
    UINT32  NbOfId;                     /**< Number of IDs in list */
    UINT32  ListId[1];                  /**< List of IDs to be reset */
} VHD_RESETLST_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_RESETLST.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
} VHD_RESETLST_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_STARTLST.
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
    UINT32  NbOfId;                     /**< Number of IDs in list */
    UINT32  ListId[1];                  /**< List of IDs to be started */
} VHD_STARTLST_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_STARTLST.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
} VHD_STARTLST_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_STOPLST.
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
    UINT32  NbOfId;                     /**< Number of IDs in list */
    UINT32  ListId[1];                  /**< List of IDs to be stopped */
} VHD_STOPLST_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_STOPLST.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
} VHD_STOPLST_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_STARTELEM.
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
    UINT32  ListId;                     /**< List-ID for element */
    UINT32  Index;                      /**< Index of element in list */
} VHD_STARTELEM_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_STARTELEM.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
} VHD_STARTELEM_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_STOPELEM.
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
    UINT32  ListId;                     /**< List-ID for element */
    UINT32  Index;                      /**< Index of element in list */
} VHD_STOPELEM_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_STOPELEM.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
} VHD_STOPELEM_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_GETUPD.
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
    UINT32  ListId;                     /**< ID of observation list */
} VHD_GETUPD_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_GETUPD (Standard reply).
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    UINT32  NbOfElem;                   /**< Number of list elements */
    UINT8   ElemList[1];                /**< List of elements */
} VHD_GETUPD_R;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_GETUPD (Multiblock transfer reply).
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    SINT32  Reserved;                   /**< Reserved */
    UINT32  NbOfElem;                   /**< Number of list elements */
    UINT32  BufferId;                   /**< ID of the multiblock buffer */
} VHD_GETXUPD_R;

/**
 * @brief SMI-Call structure for VHD Callback.
 */
typedef struct
{
    UINT32  ListId;                     /**< ID of observation list */
    UINT32  UserParam;                  /**< User defined parameter, see VHD_ADDLST_C.UserParam */
    UINT32  NbOfElem;                   /**< Number of list elements */
    UINT8   ElemList[1];                /**< List of elements */
} VHD_NEWUPD_C;

/**
 * @brief SMI-Reply structure for VHD Callback.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    UINT32  UserId;                     /**< User ID */
    UINT32  ListId;                     /**< ID of the observation list */
} VHD_NEWUPD_R;

/**
 * @brief VHD address information structure.
 */
typedef struct
{
    /** @brief SVI address or error (@c -1) if variable name not existing */
    SVI_ADDR Addr;
    UINT32  Format;                     /**< SVI variable format (@ref SVI_F_) */
} VHD_ADDRINF;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_GETADDR.
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
    UINT32  NbOfPath;                   /**< Number of addresses */
    /**
     * @brief Character-Stream of SVI variable names.
     * Zero-terminated list of SVI variable names.
     */
    CHAR8   Path[1];
} VHD_GETADDR_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_GETADDR.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    UINT32  NbOfAddr;                   /**< Number of addresses */
    VHD_ADDRINF AddrInf[1];             /**< List of address info */
} VHD_GETADDR_R;

/**
 * @brief VHD address information structure (extended information).
 */
typedef struct
{
    /** @brief SVI address or error (@c -1) if variable name not existing */
    SVI_ADDR Addr;
    UINT16  Format;                     /**< Format (@ref SVI_F_) */
    UINT16  ValLen;                     /**< Byte length of a single value */
} VHD_XADDRINF;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_GETXADDR.
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID */
    UINT32  NbOfPath;                   /**< Number of addresses */
    /**
     * @brief Character-Stream of SVI variable names.
     * Zero-terminated list of SVI variable names.
     */
    CHAR8   Path[1];
} VHD_GETXADDR_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_GETXADDR.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    UINT32  NbOfAddr;                   /**< Number of entries */
    VHD_XADDRINF AddrInf[1];            /**< List of address information */
} VHD_GETXADDR_R;

/**
 * @brief Structure for the SMI-Call #VHD_PROC_GETCBINFO.
 */
typedef struct
{
    UINT32  UserId;                     /**< User ID or -1 */
    /**
     * @brief Element in callback list (0..x) only required if <tt>UserId = -1</tt>
     */
    UINT32  ServListIdx;
    UINT32  Spare[2];                   /**< Reserved */
} VHD_GETCBINFO_C;

/**
 * @brief Structure for the SMI-Reply #VHD_PROC_GETCBINFO.
 */
typedef struct
{
    SINT32  RetCode;                    /**< Return code */
    UINT32  IPAddr;                     /**< IP Address of user */
    UINT32  ProgNb;                     /**< SMI program number of user */
    UINT32  ProtVers;                   /**< SMI protocol version of user */
    UINT32  Prot;                       /**< Protocol type (#VHD_P_UDP, #VHD_P_TCP) */
    UINT32  ProcNb;                     /**< SMI procedure number */
    UINT32  UserParam;                  /**< Reserved, not used yet */
    UINT32  CallbackId;                 /**< Callback ID */
    UINT32  Spare[4];                   /**< Reserved */
} VHD_GETCBINFO_R;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
