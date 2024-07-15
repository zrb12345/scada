/**
********************************************************************************
* @file     res_acc_e.h
* @author   Faessler
*
* @brief This header contains all definitions for the RES security function.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2015
*******************************************************************************/

#ifndef RES_ACC_E__H
#define RES_ACC_E__H

#include <mtypes.h>

#ifdef __cplusplus
extern  "C"
{
#endif

/**
 * @addtogroup RES-ACC
 * @{
 */

/**
 * @name Options for path rights
 * @see res_SetPathRights()
 * @see res_GetPathRights()
 * @{
 */
#define RES_ACC_NORMAL     0x0000       /**< Default options */
#define RES_ACC_ANONYMUSER 0x0001       /**< Accept anonymous user */
/** @} */


/**
********************************************************************************
* @brief Set access rights for a file or directory path.
*
* This function sets the access rights (read/write permission) for a single file
* or a complete directory hierarchy (including sub-directories and files).
*
* @note
* Since FAT16/32 doesn't natively support file access permissions, a separate list is to be
* managed to store permissions:
* - Performance drawback compared to native support
* - Standard ANSI file operations to not support path rights, rights need to
*   be checked manually.
*
* Each user is assigned a group and a level. Access to a file is only granted
* if the users level is greater or equal than the configured level (for the specific group).
*
* <b>Example usage</b>
* @code{.c}
* UINT8  rl[2] = { 10, 20 };
* UINT8  wl[2] = { 10, 20 };
*
* // Set system folder permissions
* res_SetPathRights("/cfc0/sys/", rl, wl, 2, RES_ACC_NORMAL);
*
* // Set app folder permissions (disable read checks)
* res_SetPathRights("/cfc0/app/", NULL, wl, 2, RES_ACC_NORMAL);
*
* // Delete permission entry for system folder
* res_SetPathRights("/cfc0/sys/", NULL, NULL, 0, RES_ACC_NORMAL);
* @endcode
*
* @param[in]  PathName    File or Directory path
* @param[in]  ReadLevel   Array of read levels or \c NULL to disable any read checks
* @param[in]  WriteLevel  Array of write levels or \c NULL to disable any write checks
* @param[in]  ElemCount   Number of elements in \p ReadLevel and \p WriteLevel
* @param[in]  Options     Additional options (#RES_ACC_NORMAL, #RES_ACC_ANONYMUSER).
*
* @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
*
* @see res_GetPathRights()
*******************************************************************************/
SINT32 res_SetPathRights(CHAR *PathName, UINT8 *ReadLevel, UINT8 *WriteLevel,
                         UINT16 ElemCount, UINT32 Options);

/**
********************************************************************************
* @brief Get actual access rights for a file or directory path.
*
* This function returns the access rights (read/write permission) for a single file
* or a directory.
*
* Each user is assigned a group and a level. Access to a file is only granted
* if the users level is greater or equal than the configured level (for the specific group).
*
* <b>Example usage</b>
* @code{.c}
* UINT8  rl[16];  // Read levels for max. 16 groups
* UINT8  wl[16];  // Write levels for max. 16 groups
* UINT32 options;
*
* // Determine root permissions (boot device)
* res_GetPathRights("/", rl, wl, 16, &options);
*
* // Determine system folder permissions
* res_GetPathRights("/cfc0/sys/", rl, wl, 16, &options);
* @endcode
*
* @param[in]  PathName    Directory (or file) path
* @param[in]  ReadLevel   Pointer where to write the "read levels" to
*                         or \c NULL if no read levels should be returned
* @param[in]  WriteLevel  Pointer where to write the "write levels" to
*                         or \c NULL if no read levels should be returned
* @param[in]  ElemCount   Number of elements in arrays
* @param[in]  Options     Pointer where to write options to
*                         or \c NULL if no options should be returned
*
* @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
*
* @see res_SetPathRights()
*******************************************************************************/
SINT32 res_GetPathRights(CHAR *PathName, UINT8 *ReadLevel, UINT8 *WriteLevel,
                         UINT16 ElemCount, UINT32 *Options);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* RES_ACC_E__H */
