/**
 ********************************************************************************
 * @file     res_sec_e.h
 * @author   Faessler
 *
 * @brief This header contains all definitions for the RES security function.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011-2015
 *******************************************************************************/

#ifndef RES_SEC_E__H
#define RES_SEC_E__H

#include <mtypes.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @addtogroup RES-SEC
 * @{
 */

/**
 * @brief Get the users system permissions (64 bit encoded value).
 *
 * This function returns the actual user permissions. If no security level is
 * setup (security level = 0) all permission bits are set to 1.
 * If no user session for \p SessionId could be found \c all bits are \c 0, thus
 * \c 0 is returned.
 *
 * @param[in] SessionId User session ID
 *
 * @return System permissions
 */
UINT64 res_sec_GetPermissions(SINT32 SessionId);

/**
 * @brief Get list of all available (logged in) user session IDs.
 *
 * @param[out] pDest  Pointer to destination array
 * @param[in]  Count  Size of output array (Maximum number of elements)
 *
 * @retval Number of session IDs returned in \p pDest
 * @retval #RES_E_FAILED if \p pDest is \c NULL
 */
SINT32 res_sec_GetUserLst(UINT32 *pDest, UINT32 Count);

/**
 * @brief Get user information for given user session ID.
 *
 * This function returns a copy of the specified user information.
 *
 * @param[in]  SessionId   User session ID
 * @param[out] pUserData   Pointer where to copy user data information to
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_BADSESS Invalid session ID
 */
SINT32 res_sec_GetUserData(UINT32 SessionId, RES_USER_DATA *pUserData);

/**
 * @brief Sets the users session active flag.
 *
 * This function sets the users session active flag to grant/refuse modifying
 * access for certain system resources:
 * - SVI write access <br>
 *   For now, only SVI write access is restricted.
 *
 * This function is intended to be used by customer specific "Access Checker"
 * implementations to realize a token based access system.
 *
 * @note
 * If "Access Control" is not enabled, this function always returns #RES_E_FAILED.
 *
 * @param[in]  SessionId   User session ID
 * @param[in]  Active      \c TRUE to grant access, \c FALSE otherwise
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_FAILED  Access control not enabled
 * @retval #RES_E_BADSESS Invalid session ID
 *
 * @see #res_sec_GetActiveUser()
 */
SINT32 res_sec_SetActiveUser(UINT32 SessionId, BOOL8 Active);

/**
 * @brief Determine users session active flag.
 *
 * @param[in]  SessionId   User session ID
 * @param[out] pActive     Pointer where to store the active flag
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_BADSESS Invalid session ID
 *
 * @see #res_sec_SetActiveUser()
 */
SINT32 res_sec_GetActiveUser(UINT32 SessionId, BOOL8 *pActive);

/**
 * @brief Removes the user for the given \p SessionId.
 *
 * @param[in]  SessionId   User session ID
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_BADSESS Invalid session ID
 */
SINT32 res_sec_RemUser(UINT32 SessionId);

/**
 * @brief Determines if access control is enabled and the token is free.
 *
 * The behavior of this function depends on following security settings:
 * - \c SecurityLevel
 * - \c AccessControl
 * - \c AccessMandatory
 *
 * If \c SecurityLevel is 0 or \c AccessControl is disabled always #TRUE is returned.
 * If \c AccessControl is enabled and \c AccessMandatory is set always #FALSE is returned (request access is required).
 * Otherwise the active flag of all currently logged in users is checked.
 *
 * @retval #TRUE Access token is free, SVI write access is allowed
 * @retval #FALSE Access control is enabled and the token is not free, a remote user has to request access first
 *
 * @see RES_PROC_REQUESTACC
 * @see res_sec_AccessTokenUsed()
 */
BOOL8 res_sec_AccessTokenFree(void);

/**
 * @brief Determines if access control is enabled and an user is active.
 *
 * The behavior of this function depends on following security settings:
 * - \c SecurityLevel
 * - \c AccessControl
 *
 * If \c SecurityLevel is 0 or \c AccessControl is disabled always #FALSE is returned.
 * Otherwise the active flag of all currently logged in users is checked.
 *
 * @retval #TRUE Access control is enabled and at least one user is active
 * @retval #FALSE Access control is disabled or no user is active
 */
BOOL8 res_sec_AccessTokenUsed(void);

/**
 * @brief Sets the active visualization user <b>(deprecated)</b>.
 *
 * @note No action is performed!
 *
 * @param[in] pCurrentVisUser
 *
 * @deprecated This function is not supported anymore (since V3.70), use
 *             #res_sec_SetActiveUser() instead.
 */
VOID res_SetActiveVisUser(CHAR *pCurrentVisUser);

/**
 * @brief Gets the active visualization user <b>(deprecated)</b>.
 *
 * @note No action is performed!
 *
 * @param[out] pCurrentVisUser
 *
 * @deprecated This function is not supported anymore (since V3.70), use
 *             #res_sec_GetActiveUser() instead.
 */
VOID res_GetActiveVisUser(CHAR *pCurrentVisUser);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* RES_SEC_E__H */
