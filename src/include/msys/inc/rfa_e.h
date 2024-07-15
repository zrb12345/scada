/**
 ********************************************************************************
 * @file     rfa_e.h
 * @author   Dorner
 *
 * @brief This file contains all definitions and declarations exported by
 *        the File Library for use by modules running on the same CPU.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2014
 *******************************************************************************/

#ifndef RFA__H
#define RFA__H

#ifdef __cplusplus
extern  "C"
{
#endif

#include <time.h>

#include <mtypes.h>

/**
 * @addtogroup RFA-DEF
 * @{
 */

/** 
 * @name Protocols
 * @{
 */
#define RFA_PROTOCOL_FTP       1       /**< FTP */
#define RFA_PROTOCOL_FTPS      2       /**< FTPS */
/** @} */

/**
 * @name Error codes
 * @anchor RFA_ERR_
 * @{
 */
#define RFA_ERR_HANDLEINVAL    -1       /**< Invalid RFA handle */
#define RFA_ERR_HANDLEINUSE    -2       /**< Handle already in use */
#define RFA_ERR_BADPARM        -3       /**< Bad parameter */
#define RFA_ERR_NOREADPERM     -4       /**< No read permission */
#define RFA_ERR_NOWRITEPERM    -5       /**< No write permission */
#define RFA_ERR_HOOKUP         -6       /**< Connect error */
#define RFA_ERR_LOGIN          -7       /**< Login error */
#define RFA_ERR_CONN           -8       /**< Connection error */
#define RFA_ERR_DATACONN       -9       /**< Data connection error */
#define RFA_ERR_CMDRSP         -10      /**< Command response error */
#define RFA_ERR_READ           -11      /**< Read error */
#define RFA_ERR_WRITE          -12      /**< Write error */
#define RFA_ERR_OPENDIR        -13      /**< Open directory */
/** @} */

/** RFA login handle */
typedef struct _RFA_LOGINID_ *RFA_LOGINHANDLE;
/** RFA file handle */
typedef struct _RFA_FILEID_ *RFA_FILEHANDLE;
/** RFA directory handle */
typedef struct _RFA_DIRID_ *RFA_DIRHANDLE;

/** Error structure returned in rfa_GetError() */
typedef struct
{
    SINT32  Error;                      /**< Error code (@ref RFA_ERR_) */
    SINT32  SpecError;                  /**< Specific error information */
    SINT32  Spare[5];                   /**< Not used, 0 for now */
} RFA_ERR;

/** File attributes returned in rfa_GetAttr() */
typedef struct
{
    UINT32  Size;                       /**< File size in bytes */
    struct tm ModTime;                  /**< File modification time */
    SINT32  Spare[10];                  /**< Not used, 0 for now */
} RFA_FILEATTR;
/** @} */

/**
 * @addtogroup RFA-API
 * @{
 */

/**
* @brief This functions returns extended error information concerning the cause
*        of the last error of a login session. The error information includes
*        the complete FTP code, may be queried as often as required and remains
*        valid until a new error status is available.
*
* @param[in]  LoginHandle   Login handle generated with the function rfa_Login()
* @param[out] pErrInfo      Pointer to structure #RFA_ERR
*
* @since MSys V3.95
*/
void rfa_GetError(RFA_LOGINHANDLE LoginHandle, RFA_ERR *pErrInfo);

/**
* @brief This function creates a login handle and tries to establish a control
*        connection to the FTP server.
*
* @param[in]  Host          Host IP address or host name
* @param[in]  User          User name
* @param[in]  Password      Password
* @param[in]  Account       The account is passed unchanged as a string to the
*                           server. Required by some FTP servers, but the M1-FTP
*                           server does not use this.
* @param[in]  Protocol      Allowed values for protocol:
*                           - #RFA_PROTOCOL_FTP
*                           - #RFA_PROTOCOL_FTPS
*
* @retval     !=0           Login handle for all other function calls.
* @retval     NULL          No memory available.
*
* @since MSys V3.95
*/
RFA_LOGINHANDLE rfa_Login(CHAR *Host, UINT8 *User, UINT8 *Password,
                          UINT8 *Account, UINT32 Protocol);

/**
* @brief This function terminates the connection to the FTP server and frees all
*        allocated resources. The login handle as well as any file handles that
*        might still be open are no longer valid.
*
* @param[in]  LoginHandle   Login handle generated with the function rfa_Login()
*
* @retval     0             OK
* @retval     -1            Error (for more information, see function rfa_GetError())
*
* @see rfa_Login()
* @since MSys V3.95
*/
SINT32 rfa_Logout(RFA_LOGINHANDLE LoginHandle);

/**
* @brief This function opens or creates a file on the FTP server and returns a
*        file handle for subsequent write or read accesses.
*
* @param[in]  LoginHandle   Login handle generated with the function rfa_Login()
* @param[in]  pFileName     File path and name on the server
* @param[in]  Flags         POSIX Flags: @b O_RDONLY, @b O_WRONLY, @b O_RDWR, @b O_CREAT
* @param[in]  Mode          Not in use. Always value 0.
*
* @retval     !=0           File handle for all other function calls
* @retval     NULL          Error (for more information, see function rfa_GetError())
*
* @since MSys V3.95
*/

RFA_FILEHANDLE rfa_Open(RFA_LOGINHANDLE LoginHandle, CHAR *pFileName, UINT32 Flags, UINT32 Mode);

/**
* @brief This function creates a file on the FTP server and returns a file handle
*        for subsequent write accesses.
*
* @param[in]  LoginHandle   Login handle generated with the function rfa_Login()
* @param[in]  pFileName     File path and name on the server
* @param[in]  Flags         POSIX Flags: @b O_WRONLY, @b O_RDWR
* @param[in]  Mode          Not in use. Always value 0.
*
* @retval     !=0           File handle for all other function calls
* @retval     NULL          Error (for more information, see function rfa_GetError())
*
* @since MSys V3.95
*/
RFA_FILEHANDLE rfa_Create(RFA_LOGINHANDLE LoginHandle, CHAR *pFileName, UINT32 Flags, UINT32 Mode);

/**
* @brief This function terminates the data connection to the FTP server and frees
*        all allocated resources. The `FileHandle` is no longer valid.
*
* @param[in]  FileHandle    File handle generated with the function rfa_Open().
*
* @retval     0             OK
* @retval     -1            Error (for more information, see function rfa_GetError())
*
* @see rfa_Open()
* @since MSys V3.95
*/
SINT32 rfa_Close(RFA_FILEHANDLE FileHandle);

/**
* @brief This function reads the data into the memory `pBuffer` from a file
*        previously opened on the FTP server.
*
* @note  The data is not buffered, i.e. it is read directly from the FTP data
*        connection.
*
* @param[in]  FileHandle    File handle generated with the function rfa_Open()
* @param[in]  Size          Length of the data buffer
* @param[out] pBuffer       Pointer to data buffer
*
* @retval     >0            Number of bytes read
* @retval     0             End of file reached
* @retval     -1            Error (for more information, see function rfa_GetError())
*
* @see rfa_Open()
* @since MSys V3.95
*/
SINT32 rfa_Read(RFA_FILEHANDLE FileHandle, void *pBuffer, UINT32 Size);

/**
* @brief This function writes the data from the memory `pBuffer` into a file
*        previously created on the FTP server.
*
* @note  The data is not buffered, i.e. it is sent directly via the FTP data
*        connection.
*
* @param[in]  FileHandle    File handle generated with the function rfa_Open()
* @param[in]  pBuffer       Pointer to data buffer
* @param[in]  Size          Length of the data buffer
*
* @retval     >=0           Number of bytes written
* @retval     -1            Error (for more information, see function rfa_GetError())
*
* @see rfa_Open()
* @since MSys V3.95
*/
SINT32 rfa_Write(RFA_FILEHANDLE FileHandle, void *pBuffer, UINT32 Size);

/**
* @brief This function can be used for renaming a file on the FTP server.
*
* @param[in]  LoginHandle   Login handle generated with the function rfa_Login()
* @param[in]  pOldName      Old file name as path on the FTP server
* @param[in]  pNewName      New file name as path on the FTP server
*
* @retval     0             OK
* @retval     -1            Error (for more information, see function rfa_GetError())
*
* @since MSys V3.95
*/
SINT32 rfa_Rename(RFA_LOGINHANDLE LoginHandle, CHAR *pOldName, CHAR *pNewName);

/**
* @brief This function can be used for deleting a file on the FTP server.
*
* @param[in]  LoginHandle   Login handle generated with the function rfa_Login()
* @param[in]  pFileName     File path and name on the FTP server
*
* @retval     0             OK
* @retval     -1            Error (for more information, see function rfa_GetError())
*
* @since MSys V3.95
*/
SINT32 rfa_Remove(RFA_LOGINHANDLE LoginHandle, CHAR *pFileName);

/**
* @brief This function returns the attribute of a file on the FTP server
*        (for example size, change date).
*
* @param[in]  LoginHandle   Login handle generated with the function rfa_Login()
* @param[in]  pFileName     File path and name on the FTP server
* @param[out] pAttr         Pointer to structure #RFA_FILEATTR
*
* @retval     0             OK
* @retval     -1            Error (for more information, see function rfa_GetError())
*
* @since MSys V3.95
*/
SINT32 rfa_GetAttr(RFA_LOGINHANDLE LoginHandle, CHAR *pFileName, RFA_FILEATTR *pAttr);

/**
* @brief This function changes the working directory on the FTP server.
*        All subsequent function calls use this directory.
*
* @note All directory handles of the login handle must be closed before
*       changing the directory.
*
* @param[in]  LoginHandle   Login handle generated with the function rfa_Login()
* @param[in]  pDirName      Directory name on the FTP server
*
* @retval     0             OK
* @retval     -1            Error (for more information, see function rfa_GetError())
*
* @since MSys V4.10
*/
SINT32 rfa_ChangeDir(RFA_LOGINHANDLE LoginHandle, CHAR *pDirName);

/**
* @brief This function reads out a directory on the FTP server and makes it
*        available for subsequent read accesses via a directory handle.
*
* The functions rfa_MakeDir(), rfa_RenameDir(), rfa_RemoveDir() also
* relate to this directory.
*
* @param[in]  LoginHandle   Login handle generated with the function rfa_Login()
* @param[in]  pDirName      Directory name on the FTP server
* @param[in]  LongList      Long or short listing
*
* @retval     !=0           Directory handle for all other directory function calls
* @retval     NULL          Error (for more information, see function rfa_GetError())
*
* @since MSys V3.95
*/
RFA_DIRHANDLE rfa_OpenDir(RFA_LOGINHANDLE LoginHandle, CHAR *pDirName, BOOL8 LongList);

/**
* @brief This function frees all allocated resources. The `DirHandle` is no longer valid.
*
* @param[in]  DirHandle     Directory handle generated with the function rfa_OpenDir()
*
* @retval     0             OK
* @retval     -1            Error (for more information, see function rfa_GetError())
*
* @see rfa_OpenDir()
* @since MSys V3.95
*/
SINT32 rfa_CloseDir(RFA_DIRHANDLE DirHandle);

/**
* @brief This function copies a directory entry into the memory `pBuffer` from the
*        directory read via the function rfa_OpenDir().
*
* @param[in]  DirHandle     Directory handle generated with the function rfa_OpenDir()
* @param[in]  Size          Length of the data buffer
* @param[out] pBuffer       Pointer to data buffer
*
* @retval     0             OK
* @retval     -1            Error (for more information, see function rfa_GetError())
*
* @see rfa_OpenDir()
* @since MSys V3.95
*/
SINT32 rfa_ReadDir(RFA_DIRHANDLE DirHandle, CHAR *pBuffer, UINT32 Size);

/**
* @brief This function creates a new directory in the directory opened via
*        rfa_OpenDir().
*
* @param[in]  DirHandle     Directory handle generated with the function rfa_OpenDir()
* @param[in]  pDirName      Directory name on the FTP server in the directory
*                           opened previously
*
* @retval     0             OK
* @retval     -1            Error (for more information, see function rfa_GetError())
*
* @see rfa_OpenDir()
* @since MSys V3.95
*/
SINT32 rfa_MakeDir(RFA_DIRHANDLE DirHandle, CHAR *pDirName);

/**
* @brief This function renames a directory in the directory opened via
*        rfa_OpenDir().
*
* @param[in]  DirHandle     Directory handle generated with the function rfa_OpenDir()
* @param[in]  pOldName      Old directory name on the FTP server in the directory
*                           opened previously
* @param[in]  pNewName      New directory name on the FTP server in the directory
*                           opened previously
*
* @retval     0             OK
* @retval     -1            Error (for more information, see function rfa_GetError())
*
* @see rfa_OpenDir()
* @since MSys V3.95
*/
SINT32 rfa_RenameDir(RFA_DIRHANDLE DirHandle, CHAR *pOldName, CHAR *pNewName);

/**
* @brief This function removes a directory from the directory opened via rfa_OpenDir().
*
* @param[in]  DirHandle     Directory handle generated with the function rfa_OpenDir()
* @param[in]  pDirName      Directory name on the FTP server in the directory
*                           opened previously.
*
* @retval     0             OK
* @retval     -1            Error (for more information, see function rfa_GetError())
*
* @see rfa_OpenDir()
* @since MSys V3.95
*/
SINT32 rfa_RemoveDir(RFA_DIRHANDLE DirHandle, CHAR *pDirName);

/**
* @brief Prints FTP connection information to standard output.
*
* @since MSys V3.95
*/
void rfa_Show();

/** @} */

#ifdef __cplusplus
}
#endif

#endif
