/**
 ********************************************************************************
 * @file    res_fnc_e.h
 * @author  Diem
 * @author  Faessler
 *
 * @brief This header contains all public definitions for the RES function
 *        library.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011-2015
 *******************************************************************************/

#ifndef RES_FNC_E__H
#define RES_FNC_E__H

#include <mtypes.h>

#ifdef __cplusplus
extern  "C"
{
#endif

/**
 * @addtogroup RES-FNC
 * @{
 */

/** @brief Definition of a single library function. */
typedef SINT32(*RES_FL_FUNC) (void);

#define RES_FNC_GLOB    0                 /**< Index of GLOBAL partition flag */
#define RES_FNC_CNT     1                 /**< Index of usage counter */

#define RES_RNC_NBPRE   2                 /**< Number of leading values (for internal use only) */

#define RES_FL_SVI_1    1                 /**< Definition for SVI-Library V1 */
#define RES_FL_SVI      2                 /**< Definition for SVI-Library V2 */
#define RES_FL_SVILEN   10                /**< Number of functions in SVI-Library */

/**
 * @name User function library definitions
 * @{
 */
#define RES_FL_USER     100               /**< Definition for 1st User-Library */
#define RES_FL_MAXUSER  0xffff            /**< Definition for last User-Library */

#define RES_FL_USER1    (RES_FL_USER)     /**< Predefined User-Library 1 */
#define RES_FL_USER2    (RES_FL_USER + 1) /**< Predefined User-Library 2 */
#define RES_FL_USER3    (RES_FL_USER + 2) /**< Predefined User-Library 3 */
#define RES_FL_USER4    (RES_FL_USER + 3) /**< Predefined User-Library 4 */
#define RES_FL_USER5    (RES_FL_USER + 5) /**< Predefined User-Library 5 */
/* @} */

/**
 * @name Possible flags
 * @{
 */

/**
 * @brief Flag: Do not check for existing function library.
 * Always creates/allocates a new library.
 *
 * @see res_NewFuncLib()
 */
#define RES_FL_NOCHK    0x40000000

/**
 * @brief Flag: Data shall be allocated in GLOBAL (1) memory partition.
 * If this flag is not set, data is allocated in the SYSTEM (0) memory partition
 * per default.
 *
 * @see res_NewFuncLib()
 */
#define RES_FL_GLOB     0x80000000

/**@brief Mask to remove #RES_FL_GLOB and #RES_FL_NOCHK */
#define RES_FL_MASK     0x00FFFFFF

/** @} */

/**
 * @brief Create new function library.
 *
 * This function creates a new function library, accessible for other software modules.
 *
 * As a function interface is connected to a software module, it is registered using the instance name of the module.
 * To manage multiple function interfaces for each module, the parameter `Type` can be used to specify differentiations.
 *
 * In the case of some function interfaces fixed types exist (e.g. #RES_FL_SVI).
 * The user defined area of the type number begins with #RES_FL_USER and ends with #RES_FL_MAXUSER.
 * If write access is made to global data within the function interface and if all of this data is located in the GLOB partition,
 * the type specification can be accessed using #RES_FL_GLOB (e.g. #RES_FL_SVI | #RES_FL_GLOB),
 * whereby switching will not be necessary with an active protective layer (this will result in better performance).
 *
 * Additionally, the table of function pointers and the number of entries must be passed.
 * Note that the table of function pointers will copy from the resource handler to a separate memory range.
 *
 * To enable the server for the function interface to include its own management information,
 * the 1st entry in the table for each definition is reserved for this information and will thereby
 * not be processed by the resource handler.
 *
 * @param[in]  pAppName    Instance name of software module providing the function library.
 * @param[in]  Type        Type of function library, supported optional flags are:
 *                          - #RES_FL_NOCHK
 *                          - #RES_FL_GLOB
 * @param[in]  NbOfFunc    Number of library functions
 * @param[in]  pLib        Pointer to library function table
 *
 * @retval  0 OK
 * @retval -1 The function could not be executed properly.
 *
 * @see res_DelFuncLib()
 */
SINT32  res_NewFuncLib(const CHAR * pAppName, UINT32 Type, UINT32 NbOfFunc, RES_FL_FUNC *pLib);

/**
 * @brief Get function library.
 *
 * This function returns the requested function library and increments the usage
 * counter on it.
 *
 * For identification purposes, the instance name (not case sensitive) of the
 * software module whose function interface shall be used, is passed.
 *
 * Use res_UngetFuncLib() if the function library is not needed anymore.
 *
 * @param[in]  pAppName    Instance name of software module providing the function library
 * @param[in]  Type        Function interface type
 *
 * @return Pointer to function library or \c NULL if interface does not exist
 *
 * @see res_UngetFuncLib()
 */
RES_FL_FUNC *res_GetFuncLib(const CHAR * pAppName, UINT32 Type);

/**
 * @brief Delete function library.
 *
 * This function removes a function library and frees all allocated resources
 * after last usage.
 *
 * @param[in]  pLib Pointer to function library previously passed to #res_NewFuncLib()
 *
 * @retval  0 OK
 * @retval -1 The function could not be executed properly.
 *
 * @see res_NewFuncLib()
 */
SINT32  res_DelFuncLib(const RES_FL_FUNC *pLib);

/**
 * @brief Unget function library.
 *
 * This function decrements the usage counter on the given function library and frees
 * allocated resources if not needed anymore.
 *
 * @note
 * After calling this function, the function interface must not be used any more.
 *
 * @param[in] pLib Pointer to function library returned by res_GetFuncLib()
 *
 * @retval  0 OK
 * @retval -1 Function library not existing
 *
 * @see res_GetFuncLib()
 */
SINT32  res_UngetFuncLib(RES_FL_FUNC *pLib);

/**
 * @brief Mark entry into library function.
 *
 * This function marks the entry into a library function and performs proper
 * switching of the memory protection layer.
 *
 * Each invocation increments the internal usage counter.
 *
 * Use:
 *  - res_EntryFuncLib() to mark entry into library function
 *  - res_ExitFuncLib() to mark exit of library function
 *
 * If \c pLib is \p NULL, no action is performed and \c 0 is returned.
 *
 * @note
 * Call this function as first command inside a library function.
 *
 * @param[in] pLib Pointer to function library returned by res_GetFuncLib()
 *
 * @retval >0 Previous memory-page ID
 * @retval  0 Invalid `pLib`, or no switch of memory-page necessary.
 *
 * @see res_ExitFuncLib()
 */
UINT32  res_EntryFuncLib(RES_FL_FUNC *pLib);

/**
 * @brief Mark exit from library function.
 *
 * This function marks the exit from a library function and performs proper
 * switching to the memory-page specified by `PageId`.
 *
 * Each invocation decrements the internal usage counter.
 *
 * Use:
 *  - res_EntryFuncLib() to mark entry into library function
 *  - res_ExitFuncLib() to mark exit of library function
 *
 * If `pLib` is \c NULL, no action is performed.
 *
 * @note
 * Call this function as last command inside a library function.
 *
 * @param[in] pLib Pointer to function library returned by res_GetFuncLib()
 * @param[in] PageId The memory-page ID returned by res_EntryFuncLib()
 *
 * @see res_ExitFuncLib()
 */
void    res_ExitFuncLib(RES_FL_FUNC *pLib, UINT32 PageId);

/**
 * @brief Print out debug information of function libraries.
 *
 * This function prints out debug information for all registered function libraries
 * to \c stdout.
 *
 * <b>Example output:</b>
 * <pre>
 * -> res_ShowFuncLib()
 *
 * AppName State LibCnt FctCnt pOrgLib pLib   Type Glob NbFunc
 * ------- ----- ------ ------ ------- ------ ---- ---- ------
 * TEST    1     0      0      664cf0  664c7c 2    0    10
 * IO-TEST 1     0      0      62e338  66c274 2    0    10
 * VHD     1     0      0      6b662c  6d6fa0 2    0    10
 * </pre>
 *
 * Column    | Description
 * --------- | --------------
 * State     | 1 ... Library is OK, 2 ... Library has been removed by owner, but is still in use
 * LibCnt    | Number of modules that are currently using this library
 * FctCnt    | Number of modules that are currently in the library function
 * pOrgLib   | Pointer to the original function library passed to res_NewFuncLib()
 * pLib      | Pointer of the internal copy of the library
 * Type      | Type of library
 * Glob      | 0 ... Library needs page switching, 1 ... Library needs no page switching
 * NbFunc    | Number of functions in the library
 *
 * @return Always returns \c 0
 */
SINT32    res_ShowFuncLib(void);

/* @} */

#ifdef __cplusplus
}
#endif

#endif /* RES_FNC_E__H */
