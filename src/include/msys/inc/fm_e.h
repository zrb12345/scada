/**
********************************************************************************
* @file     fm_e.h
* @author   Fusseneg
*
* @brief This file contains all definitions and declarations exported by
*        the File Library for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef FM__H
#define FM__H

#ifdef __cplusplus
extern "C" {
#endif

#include <lst_e.h>
#include <dirent.h>

/**
 * @addtogroup FM-DEF
 * @{
 */

/**
 * @brief Data for access to FTP directory.
 */
typedef struct
{
    LST_ID  *LstId;         /**< List of directory entries */
    UINT8   *ActNode;       /**< Actual node of list */
    UINT32  ActPos;         /**< Actual position in node */
} FM_FTP;

/**
 * @brief Data for access to local or NFS directory
 */
typedef struct
{
    DIR     *DirId;         /**< Id for access */
} FM_NFS;

/**
 * @brief Data for access to directory
 */
typedef struct
{
    UINT32  DirType;        /**< FM_T_FTPDIR, FM_T_NFSDIR */
    union
    {
    FM_FTP  Ftp;            /**< FTP data */
    FM_NFS  Nfs;            /**< NFS data */
    } un;                   /**< union including FTP and NFS data */
} FM_DIRID;

/**
 * @name Defines needed for output parameter of fm_GetNVFile()
 * @{
 */
#define FMNV_CREATED    0x0001  /**< The file was created new. */
#define FMNV_EXISTOK    0x0002  /**< The file existed, and is OK. */
#define FMNV_NOTEXIST   0x0004  /**< The given file did not exist. */
#define FMNV_TOOLONG    0x0008  /**< The given file Name was too long. */
#define FMNV_NOPTR      0x0010  /**< The sys_GetMemAddress() function returned no pointer for the file. */
#define FMNV_STATERR    0x0020  /**< Error occurred while reading the file's status information. */
#define FMNV_CORRUPT    0x0040  /**< File was corrupt - all data was reset to 0. */
#define FMNV_SIZEERR    0x0080  /**< The file's size did not equal the given size. */
#define FMNV_CRTERR     0x0100  /**< Create error - error occurred while creating file. */
/** @} */

#define MCONFIG_NAME    "mconfig.ini"   /**< Name of configuration file */
/** @} */

/**
 * @addtogroup FM-API
 * @{
 */

/**
 * @brief This function opens/creates a file in the Non Volatile Memory.
 *
 * - If the given file already exists:
 *   It is opened, and the size and checksum is tested. If not correct,
 *   the file is created new, and all data is set to 0.
 * - If the given file does not exist, it is created. All data is set to 0.
 *   A pointer is returned to the memory of the file that can be used as
 *   non volatile memory. The first 4 byte of that memory are used as checksum
 *   if requested.
 *
* @note This function is designed for system use. The caller must ensure, that the
*       protection layer is set to the system memory partition. This can be done
*       with the function pair sys_AppToSys() and sys_SysToApp().
 *
 * @param[in]  Name        The name of the file to be opened/created. No path information
 *                         is required, seeing that it is automatically added.
 *                          Exp: "plcsrv.rtn"
 * @param[in]  Size        The required size (storage amount) in bytes. This function
 *                         adds 4 bytes to this amount that are used for the checksum.
 *                         If the requested file is found and opened, it's size must
 *                         be = Size+4. If not, it is created new.
 * @param[in]  CreateNew   Indicates if the file must be created new if needed (Could
 *                         not be opened, size mismatched or checksum error).
 * @param[in]  CheckChkSum Indicates if the files checksum must be tested.
 * @param[in]  AppName     The application's name - needed for error and info outputs.
 *                         Exp: "PLCSRV"
 *
 * @param[out] pPtr        Pointer to the non volatile memory that can be used. The
 *                         first 4 byte of that memory are used as checksum if requested.
 * @param[out] RetFlags    Flags indicating what happened during the function. Can be a
 *                         combination of the following flags ORed together:
 * - #FMNV_CREATED:  @copybrief #FMNV_CREATED
 * - #FMNV_EXISTOK:  @copybrief #FMNV_EXISTOK
 * - #FMNV_NOTEXIST: @copybrief #FMNV_NOTEXIST
 * - #FMNV_TOOLONG:  @copybrief #FMNV_TOOLONG
 * - #FMNV_NOPTR:    @copybrief #FMNV_NOPTR
 * - #FMNV_STATERR:  @copybrief #FMNV_STATERR
 * - #FMNV_CORRUPT:  @copybrief #FMNV_CORRUPT
 * - #FMNV_SIZEERR:  @copybrief #FMNV_SIZEERR
 * - #FMNV_CRTERR:   @copybrief #FMNV_CRTERR
 *
 * @retval  0  File was opened/created successfully
 * @retval -1  Error - File could not be opened/created.
 *
 * <b>Example</b>
 * @snippet doc_lib_fm.c fm_GetNVFile
 */
SINT32 fm_GetNVFile(const CHAR *Name, SINT32 Size, BOOL8 CreateNew,
                    BOOL8 CheckChkSum, const CHAR *AppName,
                    UINT32 *RetFlags, UINT32 **pPtr);

/**
 * @brief This function creates a file in the Non Volatile Memory.
 *
 * It writes the data into the file and calculates the checksum. The device
 * to use can be configured in the MConfig.ini file:
 * (SysDirs) / NonVolatile = xxx.
 *
 * @param[in]  Name        The name of the file to be created. No path information
 *                         is required, seeing that it is automatically added.
 *                         Exp: "plcsrv.rtn"
 * @param[in]  Data        Data to write.
 * @param[in]  Size        The required size (the storage amount) in bytes. This function
 *                         adds 4 bytes to this amount that are used for the checksum.
 * @param[in]  AddChkSum   Indicates if the files checksum must be added.
 * @param[in]  AppName     The application's name - needed for error and info outputs.
 *                         Exp: "PLCSRV"
 *
 * @retval      0  File was opened/created successfully
 * @retval     -1  Error - File could not be opened/created
 * @retval     -2  Checksum error
 */
SINT32 fm_WriteNVFile(const CHAR *Name, const UINT8 *Data, SINT32 Size,
                      BOOL8 AddChkSum, const CHAR *AppName);

/**
 * @brief This function copies an entire file.
 *
 * If the file names contain a relative path-specification
 * (e.g. ..\\tmp\\test.dat, readme.doc, ...), a search is performed
 * in the current directory. Pattern-indications for the file names
 * are not allowed. The file is copied in blocks of 16 kB.
 *
 * @param[in]  DstName Name of the target file.
 * @param[in]  SrcName Name of the source file.
 *
 * @retval      0  OK.
 * @retval     -1  Insufficient free memory or error at file access.
 * @retval     -2  Target device/target resource is not available.
 *
 * <b>Example</b>
 * @snippet doc_lib_fm.c fm_CopyFileByName
 */
SINT32 fm_CopyFileByName(CHAR *DstName, CHAR *SrcName);

/**
 * @brief This function copies data from one file to another.
 *
 * The source file and target file must already be open. The copying process
 * begins for the source and target-file from the current position.
 *
 * @note The basic function is identical to the function fm_CopyFileByName().
 *       However, there is an option to copy a specific file range.
 *
 * @param[in]  DstId   File handle of the target file.
 * @param[in]  SrcId   File handle of the source file.
 * @param[in]  Len     Transfer of the length of the range to be copied.
 *                     At transfer of the value -1, the entire file from
 *                     the current position will be copied.
 *
 * @retval      0  OK.
 * @retval     -1  Insufficient free memory or error at file access.
 *
 * <b>Example</b>
 * @snippet doc_lib_fm.c fm_CopyFileById
 */
SINT32 fm_CopyFileById(SINT32 DstId, SINT32 SrcId, SINT32 Len);

/**
 * @brief This function creates a contiguous file.
 *
 * The file will be checked and if necessary, it will be copied to /ram0
 * and created again with the option FIOCONTIG.
 *
 * @param[in]  FileName Name of file
 *
 * @retval     0   OK
 * @retval     -1  Error.
 */
SINT32 fm_CreateContigFile(CHAR *FileName);

/**
 * @brief This function calculates and writes the checksum of a file.
 *
 * @note The first 4 byte of the file are used as checksum.
 *
 * @param[in]  FileName    Name of file.
 *
 * @retval     0    OK
 * @retval    -1    Error at file access.
 */
SINT32 fm_WriteChecksumByName(CHAR *FileName);

/**
 * @brief This function tests the checksum of a file.
 *
 * @note The first 4 byte of the file are used as checksum.
 *
 * @param[in]  FileName    Name of file.
 *
 * @retval     1    OK
 * @retval     0    Checksum not fulfilled or error at file access.
 */
SINT32 fm_TestChecksumByName(CHAR *FileName);

/**
 * @brief This function assembles a path from multiple individual parts.
 *
 * The advantage of this function is that a random number of parts can be
 * specified and that the buffer length is monitored.
 *
 * @param[in]  BuffLen Transfer of the length of the target buffer.
 *                     The terminating zero must also be considered.
 * @param[in]  Name    Listing of any number of strings that should be assembled
 *                     to form a path. The list must be terminated with 0.
 * @param[out] Buff    Transfer of the target buffer.
 *
 * @retval     0   OK
 * @retval     -1  Buffer to small
 *
 * @note fm_MakePath(Buff, sizeof(Buff), "A:\", "Dir1\", "Dir2\Dir3", "\", "readme", 0);
 *       <br>-> Buff = "A:\Dir1\Dir2\Dir3\readme"
 */
SINT32 fm_MakePath(CHAR *Buff, UINT32 BuffLen, CHAR *Name, ...);

/**
 * @brief This function tests whether the given path is absolute or relative.
 *
 * If the path is relative it is changed to absolute by adding the boot
 * directory (place where the MConfig.ini is located) as the working
 * directory.
 *
 * @param[in]  pRelFile     Pointer to the source of data (relative or absolute path).
 * @param[in]  maxLen       Maximum number of chars that can be stored in `pAbsFile`
 *                          including null-termination.
 * @param[out] pAbsFile     Absolute file path.
 *
 * @retval     0        OK.
 * @retval     -1       Path cannot be made absolute.
 */
SINT32 fm_MakeAbsoluteBootPath(CHAR *pRelFile, CHAR *pAbsFile, SINT maxLen);

/**
 * @brief This function returns the device name of a file path.
 *
 *  If the device is not found an empty string is returned.
 *
 *  examples:
 *
 *  path: "/cfc0/app/"
 *  <br>function provides: "/cfc0"
 *
 *  path: "HOST:app/"
 *  <br>function provides: "HOST:"
 *
 * @param[in]  Path         File path
 * @param[in]  BuffLen      Buffer length
 * @param[out] Buff         Device name
 *
 * @retval     0   OK
 * @retval     -1  `BuffLen` too short
 */
SINT32 fm_GetDeviceName(const CHAR *Path, CHAR *Buff, UINT32 BuffLen);

/**
 * @brief This function returns the file name and extension of a file path.
 *
 * If the last character of Path is a slash an empty string is returned.
 *
 *  examples:
 *
 *  path: "/cfc0/app/tst.m"
 *  <br>function provides: "tst.m"
 *
 *  path: "/cfc0/app/"
 *  <br>function provides: ""
 *
 * @param[in]  Path         File path
 * @param[in]  BuffLen      Buffer length
 * @param[out] Buff         File name
 *
 * @retval     0   OK
 * @retval     -1  `BuffLen` too short
 */
SINT32 fm_GetFileName(const CHAR *Path, CHAR *Buff, UINT32 BuffLen);

/**
 * @brief This function returns the directory name of a file path.
 *
 * Subsequent calls remove on directory level per call ("/cfc0/app" -> "/cfc0" -> "").
 * If the Path consists only of a device (e.g. /cfc0) an empty string is returned.
 *
 *  examples:
 *
 *  path: "/cfc0/app/tst.m"
 *  <br>function provides: "/cfc0/app"
 *
 *  path: "/cfc0/app"
 *  <br>function provides: "/cfc0"

 *  path: "/cfc0"
 *  <br>function provides: ""
 *
 * @param[in]  Path         File path
 * @param[in]  BuffLen      Buffer length
 * @param[out] Buff         Directory name
 *
 * @retval     0   OK
 * @retval     -1  `BuffLen` too short
 */
SINT32 fm_GetDirName(const CHAR *Path, CHAR *Buff, UINT32 BuffLen);

/**
 * @brief This function returns the file extension of a file path.
 *
 * If no extension is found, an empty string is returned.
 *
 *  examples:
 *
 *  path: "/cfc0/app/tst.m"
 *  <br>function provides: ".m"
 *
 *  path: "/cfc0/app"
 *  <br>function provides: ""
 *
 * @param[in]  Path         File path
 * @param[in]  BuffLen      Buffer length
 * @param[out] Buff         File extension
 *
 * @retval     0   OK
 * @retval     -1  `BuffLen` too short
 */
SINT32 fm_GetFileExtension(const CHAR *Path, CHAR *Buff, UINT32 BuffLen);

/**
 * @brief This function opens a directory, which may be accessible either
 *        locally or through NFS, for a search procedure.
 *
 * @param[in]  PathName   Path to the desired directory.
 *
 * @retval     !0  ID of directory-list
 * @retval     0   the directory could not be opened, or insufficient memory
 *
 * @note For the concluding search procedure, only the content that is present
 *       at the time the fm_OpenDir() function is called, is visible.
 *       Subsequent changes to the directory will not be considered.
 *
 * <b>Example</b>
 * @snippet doc_lib_fm.c fm_OpenDir
 */
FM_DIRID *fm_OpenDir(CHAR *PathName);

/**
 * @brief  This function opens a directory that is accessible through FTP
 *         for a search procedure.
 * 
 *  The function internally builds the connection to the FTP-server,
 *  reads its directory-content and stores the data locally in the memory.
 *  At the end the connection is closed again. The subsequent fm_ReadDir() calls
 *  are based on the data in the local memory.
 *
 *  @note For the concluding search procedure, only the content that is present
 *        at the time the fm_OpenFtpDir() function is called, is visible.
 *        Subsequent changes to the FTP directory will not be considered.
 *
 * @param[in]  PathName  Path of the desired directory.
 * @param[in]  Host      Transfer of the name or the IP address of the FTP
 *                       server (e.g. "192.9.250.14").
 * @param[in]  User      Transfer of the user name for login on the FTP server.
 * @param[in]  Passwd    Transfer of password for login on the FTP server.
 *
 * @retval     !0 ID of directory-list
 * @retval     0  Error (host-connection, directory, buffer))
 *
 * @note For the example, the login specifications are taken from the
 *       M1 boot-configuration.
 *
 * <b>Example</b>
 * @snippet doc_lib_fm.c fm_OpenFtpDir
 */
FM_DIRID *fm_OpenFtpDir(CHAR *PathName, CHAR *Host, CHAR *User, CHAR *Passwd);

/**
 * @brief This function opens a directory that is accessible through FTP
 *        for reading.
 *
 * The request is executed with "LIST" for long format.
 *
 * @param[in]  PathName   Path of the desired directory.
 * @param[in]  Host       Transfer of the name or the IP address of the FTP
 *                        server (e.g. "192.9.250.14").
 * @param[in]  User       Transfer of the user name for login on the FTP server.
 * @param[in]  Passwd     Transfer of password for login on the FTP server.
 *
 * @retval     !0  ID of directory-list
 * @retval     0   Error (host-connection, directory, buffer)
 */
FM_DIRID *fm_OpenFtpDirLong(CHAR *PathName, CHAR *Host, CHAR *User,
            CHAR *Passwd);

/**
 * @brief This function reads step by step a previously opened directory.
 *
 * In the process only the name of the directory entry is read without any
 * additional details, e.g. date, size, etc.
 *
 * @param[in]      DirId    ID of the directory list returned by the function
 *                          fm_OpenDir(), fm_OpenFtpDir() or fm_OpenFtpDirLong().
 * @param[in,out]  pBuff    Address of the target buffer.
 * @param[in]      BuffLen  Size of the target buffer.
 *
 * @retval     0   OK
 * @retval     -1  Buffer too small, or no further entries available.
 *
 * <b>Example 1</b>
 * @snippet doc_lib_fm.c fm_OpenDir
 * <b>Example 2</b>
 * @snippet doc_lib_fm.c fm_OpenFtpDir
 */
SINT32 fm_ReadDir(FM_DIRID *DirId, CHAR *pBuff, UINT32 BuffLen);

/**
 * @brief This function terminates the access to a directory.
 *
 * After calling this function, the directory-ID is invalid and must not be used
 * any more.
 *
 * @param[in]  DirId   ID of the directory list returned by the function
 *                     fm_OpenDir(), fm_OpenFtpDir() or fm_OpenFtpDirLong().
 *
 * <b>Example 1</b>
 * @snippet doc_lib_fm.c fm_OpenDir
 * <b>Example 2</b>
 * @snippet doc_lib_fm.c fm_OpenFtpDir
 */
VOID fm_CloseDir(FM_DIRID *DirId);

/**
 * @brief This function tests, if a certain entry exists on a local directory
 *        or NFS remote directory.
 *
 * @note The compare is NOT case sensitive!
 *
 * @param[in]  PathName   Path of the desired directory.
 * @param[in]  EntryName  Name of entry to search for.
 *
 * @retval     0   Entry not found
 * @retval     1   Entry found
 */
SINT32 fm_TestDirEntry(CHAR *PathName, CHAR *EntryName);

/**
 * @brief This function tests, if a certain entry exists on a FTP directory.
 *
 * @note The compare is NOT case sensitive!
 *
 * @param[in]  PathName   Path of the desired directory. ("/" for root!)
 * @param[in]  Host       Transfer of the name or the IP address of the FTP
 *                        server (e.g. "192.9.250.14").
 * @param[in]  User       Transfer of the user name for login on the FTP server.
 * @param[in]  Passwd     Transfer of password for login on the FTP server.
 * @param[in]  EntryName  Name of entry to search for.
 *
 * @retval     0   Entry not found
 * @retval     1   Entry found
 */
SINT32 fm_TestFtpDirEntry(CHAR *PathName, CHAR *Host, CHAR *User,
                          CHAR *Passwd, CHAR *EntryName);

/**
 * @brief This function tests a file for validity.
 *
 * Depending on the VxWorks version and configuration, the file name must
 * be DOS 8.3 or Windows conform. This function tests the transferred name
 * and returns OK or error and a possible valid name.
 *
 * @note Every invalid character in the transferred parameter `CallerName`,
 *       e.g. like \ / : * ? " < > |) is replaced by the character ~ in the
 *       returned name and an error is returned. The function only checks
 *       file names, it does not check complete path information. Long file
 *       names (255 characters) starting with a dot are allowed.
 *
 * @param[in]  CallerName File name to check.
 * @param[out] ValidName  Allowed file name.
 *
 * @retval     0   OK
 * @retval     <0  Error, correct name is returned in `ValidName`.
 *
 * <b>Example</b>
 * @snippet doc_lib_fm.c fm_TestFileName
 */
SINT32 fm_TestFileName(CHAR *CallerName, CHAR *ValidName);

/**
 * @brief  This function deletes a local directory or NFS remote directory
 *         with all sub directories and files.
 *
 * If an error occurs, deletion stops.
 *
 * @param[in]  Name    Name of directory to be deleted.
 *                     The name has to be terminated with slash and
 *                     null-pointer. ("/cfc0/.../")*
 *
 * @retval     0   OK
 * @retval     -1  Directory cannot be opened.
 * @retval     -2  File info (stat) cannot be read.
 * @retval     -3  File cannot be deleted.
 * @retval     -4  Directory cannot be deleted.
*/
SINT32 fm_DelPath(CHAR *Name);

/**
 * @brief This function creates a directory on a FTP server.
 *
 * @param[in]  DirName    Path of the directory to be created.
 * @param[in]  Host       Transfer of the name or the IP address of the
 *                        FTP server (e.g. "192.9.250.14").
 * @param[in]  User       Transfer of the user name for login on the FTP server.
 * @param[in]  Passwd     Transfer of password for login on the FTP server.
 *
 * @retval     0   OK
 * @retval     -1  An error has occurred
 *
 * <b>Example</b>
 * @snippet doc_lib_fm.c fm_MkFtpDir
 */
SINT32 fm_MkFtpDir(CHAR *DirName, CHAR *Host, CHAR *User, CHAR *Passwd);

/**
 * @brief This function deletes a directory on a FTP server.
 *
 * @param[in]  DirName    Path of the directory to be deleted.
 * @param[in]  Host       Transfer of the name or the IP address of the
 *                        FTP server (e.g. "192.9.250.14").
 * @param[in]  User       Transfer of the user name for login on the FTP server.
 * @param[in]  Passwd     Transfer of password for login on the FTP server.
 *
 * @retval     0    OK
 * @retval     -1   An error has occurred
 *
 * <b>Example</b>
 * @snippet doc_lib_fm.c fm_RmFtpDir
 */
SINT32 fm_RmFtpDir(CHAR *DirName, CHAR *Host, CHAR *User, CHAR *Passwd);

/**
 * @brief This function renames a directory or a file on a FTP server.
 *
 * @param[in]  OldName   Old (current) name of the file or of the directory.
 * @param[in]  NewName   New name of the file or directory.
 * @param[in]  Host      Transfer of the name or the IP address of the
 *                       FTP server (e.g. "192.9.250.14").
 * @param[in]  User      Transfer of the user name for login on the FTP server.
 * @param[in]  Passwd    Transfer of password for login on the FTP server.
 *
 * @retval     0   OK
 * @retval     -1  An error has occurred
 *
 * <b>Example</b>
 * @snippet doc_lib_fm.c fm_FtpRename
 */
SINT32 fm_FtpRename(CHAR *OldName, CHAR *NewName, CHAR *Host, CHAR *User,
                    CHAR *Passwd);

/** @} */

/*--- Definition of Variables ---*/

#ifdef __cplusplus
}
#endif

#endif
