/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     res_user.h
* @author   DASC
* @brief    Resource Manager User Data
*           This file contains all definitions and declarations for
*           user-related data.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef RES_USER__H
#define RES_USER__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>
#include "msys.h"

/**
 * @addtogroup RES-DEF
 * @{
 */

#define RES_MAXUSERGROUP    255  /**< maximal allowed user group */
#define RES_MAXUSERLEVEL    254  /**< maximal allowed user level */
typedef union
{
#ifdef GNU_COMPILER_T22
        SINT64 __64;
        UINT32 __32[2];
#else
    SINT64  _64;
    SINT32  _32[2];
#endif
} RES_LOGIN_PERMISSIONS;

/**
 * @brief User authentication/session information.
 */
typedef struct
{
    CHAR8       ToolName[M_MODNAMELEN_A];    /**< Toolname */
    CHAR8       UserName[M_UNAMELEN2_A];     /**< Username */
    TIMESTAMP   LoginTimeStamp; /**< Timestamp of login */
    TIMESTAMP   LastAlive;      /**< Timestamp of last SMI usage */
    UINT32      IPAddr;         /**< Client IP address */
    BOOL8       Active;         /**< \c TRUE if user is active (Access Control) */
    BOOL8       Local;          /**< \c TRUE if local login */
    UINT16      ServerPort;     /**< Server port number */
    TIMESTAMP   LastActivity;   /**< Timestamp of last activity (e.g. SVI write operation) */
    UINT32      Spare1[2];      /**< Reserved */
    UINT32      LoginSessId;    /**< User login session ID */
} RES_USER_AUTH;

/**
 * @brief User access/permission information.
 */
typedef struct
{
    UINT8   Group;              /**< User group (0-255) */
    UINT8   Level;              /**< User level (0-254) */
    UINT8   Priority;           /**< User priority (0-255) */
    UINT8   Spare0;             /**< Reserved */
    /**
     * @brief System permissions
     */
    union
    {
        SINT64  __64;               /**< 64-bit value */
        UINT32  __32[2];            /**< Lo/Hi value (32-bit) */
    } SysPerm;
    /**
     * @brief Application permissions
     */
    union
    {
        SINT64  __64;               /**< 64-bit value */
        UINT32  __32[2];            /**< Lo/Hi value (32-bit) */
    } AppPerm;
    SINT32  AppData;            /**< Application specific data */
    UINT32  Spare1[3];          /**< Reserved */
} RES_USER_ACCESS;

/**
 * @brief User data (User access + authentication information)
 */
typedef struct
{
    RES_USER_ACCESS Acc;        /**< Access/Permission information */
    RES_USER_AUTH   Auth;       /**< Authentication information */
} RES_USER_DATA;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
