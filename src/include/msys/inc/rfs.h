/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     rfs.h
* @author   Jochum
* @brief    This file contains all definitions and declarations which were
*           exported by the module and can be used by other modules
*           on other CPU's.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef RFS__H
#define RFS__H

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>
#include <mtypes.h>

/**
 * @addtogroup RFS-DEF
 * @{
 */
#define RFS_PRIORITY    153 /**< RFS task priority */

/**
 * @anchor RFS_S_
 */
/**
 * @name File mode bit masks
 * @{
 */

#define RFS_S_IFMT      0xf000   /**< File type field */
#define RFS_S_IFIFO     0x1000   /**< Fifo */
#define RFS_S_IFCHR     0x2000   /**< Character special */
#define RFS_S_IFDIR     0x4000   /**< Directory */
#define RFS_S_IFBLK     0x6000   /**< Block special */
#define RFS_S_IFREG     0x8000   /**< Regular */
#define RFS_S_IFLNK     0xa000   /**< Symbolic link */
#define RFS_S_IFSOCK    0xc000   /**< Socket */
/** @} */

/**
 * @anchor RFS_O_
 */
/**
 * @name File open flags
 * @{
 */

#define RFS_O_RDONLY    0   /**< Open for reading only */
#define RFS_O_WRONLY    1   /**< Open for writing only */
#define RFS_O_RDWR      2   /**< Open for reading and writing */
/** @} */

/**
 * @name Possible errorcodes
 * @{
 */

#define RFS_E_OK            M_E_OK   /**< @copybrief #M_E_OK */
#define RFS_E_FAILED        (M_ES_RFS | M_E_FAILED)  /**< @copybrief #M_E_FAILED */
#define RFS_E_ERRFD         (M_ES_RFS | M_E_BADINDEX)    /**< @copybrief #M_E_BADINDEX */
#define RFS_E_STRING        (M_ES_RFS | M_E_BADNAME)     /**< @copybrief #M_E_BADNAME */
#define RFS_E_STRINGLEN     (M_ES_RFS | M_E_BADNAME)     /**< @copybrief #M_E_BADNAME */
#define RFS_E_NOHOST        (M_ES_RFS | M_E_FAILED)  /**< @copybrief #M_E_FAILED */
#define RFS_E_NOWRITE       (M_ES_RFS | M_E_NOWRITE)     /**< @copybrief #M_E_NOWRITE */
#define RFS_E_NOREAD        (M_ES_RFS | M_E_NOREAD)  /**< @copybrief #M_E_NOREAD */
#define RFS_E_NOMEM         (M_ES_RFS | M_E_NOMEM)   /**< @copybrief #M_E_NOMEM */
#define RFS_E_CONTIGFILE    (M_ES_RFS | M_E_CONTIGFILE)  /**< @copybrief #M_E_CONTIGFILE */
#define RFS_E_LOCKED        (M_ES_RFS | M_E_LOCKED)  /**< @copybrief #M_E_LOCKED */
/** @} */
/** @} */

/**
 * @addtogroup RFS-SMI
 * @{
 */

/**
 * @name SMI Commands
 * @{
 */

/**
 * @brief Get file attributes.
 *
 * This SMI function queries file/directory attributes. M1 local and
 * remote FTP mounts are supported.
 *
 * @param[in]   #RFS_GETATT_C
 * @param[out]  #RFS_GETATT_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RFS_E_NOREAD User has no read permission
 */
#define RFS_PROC_GETATT     100
/**
 * @brief Set last file access and modification time.
 *
 * This SMI function sets the last access and modification time of the file
 * specified by filename.
 *
 * @param[in]   #RFS_SETTIME_C
 * @param[out]  #RFS_SETTIME_C
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RFS_E_NOWRITE User has no write permission
 */
#define RFS_PROC_SETTIME    102
/**
 * @brief Get file system root devices.
 *
 * This SMI function returns a list of file system root devices, including:
 * - M1 local devices (e.g. @c \\cfc0, @c \\nvram0, ...)
 * - Remote FTP mounts (e.g. @c HOST:)
 *
 * @note
 * The returned list only contains accessible root devices (permission check)
 * for the actual calling user session.
 *
 * @param[in]   #RFS_GETFSROOT_C
 * @param[out]  #RFS_GETFSROOT_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RFS_PROC_GETFSROOT  104
/**
 * @brief Open file for further processing.
 *
 * This SMI function opens a file for the given operation flags and returns the
 * file handle required for later read/write operations:
 * - #RFS_PROC_READ
 * - #RFS_PROC_WRITE
 *
 * Opened files must be closed by the client via #RFS_PROC_CLOSE after usage.
 *
 * @note
 * Files located on remote FTP mounts need to be transfered to the local M1
 * first. Thus opening a remote file may last longer, depending on file size
 * and network bandwidth. Clients need to check the ready flag #RFS_OPEN_R.Ready.
 * If <tt>(Ready == 0)</tt> the transfer is still in progress, to determine the
 * transfer state use #RFS_PROC_FTPSTAT.
 *
 * @param[in]   #RFS_OPEN_C
 * @param[out]  #RFS_OPEN_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RFS_E_NOREAD User has no read permission
 * @retval #RFS_E_NOWRITE User has no write permission
 *
 * @see #RFS_PROC_CLOSE
 * @see #RFS_PROC_FTPSTAT
 */
#define RFS_PROC_OPEN       106
/**
 * @brief Close file.
 *
 * This SMI function closes a file, previously opened via #RFS_PROC_OPEN or
 * #RFS_PROC_CREAT.
 *
 * @note
 * Files located on remote FTP mounts need to be transfered from the M1 to the
 * remote target first. Thus closing a file may last longer, depending on file size
 * and network bandwidth. Clients need to check the ready flag #RFS_CLOSE_R.Ready.
 * If <tt>(Ready == 0)</tt> the transfer is still in progress, to determine the
 * transfer state use #RFS_PROC_FTPSTAT.
 *
 * @param[in]   #RFS_CLOSE_C
 * @param[out]  #RFS_CLOSE_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RFS_E_ERRFD Invalid file handle
 *
 * @see #RFS_PROC_OPEN
 * @see #RFS_PROC_FTPSTAT
 */
#define RFS_PROC_CLOSE      108
/**
 * @brief Read from file.
 *
 * This SMI function reads content from a file previously opened via
 * #RFS_PROC_OPEN.
 *
 * @param[in]   #RFS_READ_C
 * @param[out]  #RFS_READ_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RFS_E_ERRFD Invalid file descriptor
 *
 * @see #RFS_PROC_OPEN
 */
#define RFS_PROC_READ       110
/**
 * @brief Write to file.
 *
 * This SMI function writes data to a file previously opened via #RFS_PROC_OPEN
 * or #RFS_PROC_CREAT.
 *
 * @param[in]   #RFS_WRITE_C
 * @param[out]  #RFS_WRITE_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RFS_E_ERRFD Invalid file descriptor
 *
 * @see #RFS_PROC_OPEN
 * @see #RFS_PROC_CREAT
 */
#define RFS_PROC_WRITE      112
/**
 * @brief Create file.
 *
 * This SMI function creates a file and returns the
 * file handle required for later write operations:
 * - #RFS_PROC_WRITE
 * - #RFS_PROC_CLOSE
 *
 * Opened files must be closed by the client via #RFS_PROC_CLOSE after usage.
 *
 * @param[in]   #RFS_CREAT_C
 * @param[out]  #RFS_CREAT_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval RFS_E_NOWRITE User has no write permission
 *
 * @see #RFS_PROC_CLOSE
 */
#define RFS_PROC_CREAT      114
/**
 * @brief Remove file.
 *
 * This SMI function removes a file specified by file name.
 *
 * @param[in]   #RFS_REMOVE_C
 * @param[out]  #RFS_REMOVE_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RFS_PROC_REMOVE     116
/**
 * @brief Rename a file or a directory.
 *
 * This SMI function renames the specified file.
 *
 * @param[in]   #RFS_RENAME_C
 * @param[out]  #RFS_RENAME_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RFS_PROC_RENAME     118
/**
 * @brief Create directory.
 *
 * This SMI function creates a new directory.
 *
 * @param[in]   #RFS_MKDIR_C
 * @param[out]  #RFS_MKDIR_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval RFS_E_NOWRITE User has no write permission
 */
#define RFS_PROC_MKDIR      120
/**
 * @brief Remove directory.
 *
 * This SMI function removes a directory. The directory is removed
 * only if it is empty.
 *
 * @param[in]   #RFS_RMDIR_C
 * @param[out]  #RFS_RMDIR_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval RFS_E_NOWRITE User has no write permission
 */
#define RFS_PROC_RMDIR      122
/**
 * @brief List directory content.
 *
 * This SMI function gets the content of a directory.
 *
 * In case of FTP mount, following FTP servers are supported:
 * - M1 FTP server
 * - FileZilla server
 * - Windows FTP server
 *
 * @param[in]   #RFS_LISTDIR_C
 * @param[out]  #RFS_LISTDIR_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RFS_PROC_LISTDIR    124
/**
 * @brief Copy file.
 *
 * This SMI function creates a 'remote' copy of a file.
 *
 * @param[in]   #RFS_COPY_C
 * @param[out]  #RFS_COPY_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RFS_PROC_COPY       126
/**
 * @brief Get file transfer status information.
 *
 * This SMI function determines the current status of an FTP transfer, initiated
 * via:
 * - #RFS_PROC_OPEN
 * - #RFS_PROC_CLOSE
 *
 * @note
 * The parameters #RFS_FTPFILESTATINF_R.Length and #RFS_FTPFILESTATINF_R.Offset
 * are only set as long the transfer is in progress.
 * Older versions of MCore (< 3.21.02 Beta) miss transfer status information.
 * Thus \c Length and \c Offset are both set to \c -1.
 * The \c Ready flag is set in every case.
 *
 * @param[in]   #RFS_FTPFILESTATINF_C
 * @param[out]  #RFS_FTPFILESTATINF_R
 *
 * @return #RFS_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RFS_E_ERRFD Invalid file descriptor
 */
#define RFS_PROC_FTPSTAT    128
/** @} */
/**
 * @brief RFS file attributes.
 */
typedef struct
{
    UINT16      FileMode;       /**< File mode, see @ref RFS_S_ for possible bit masks */
    UINT16      DosFileAtt;     /**< File attribute byte (dosFs only) */
    struct tm   ModTime;        /**< Last modified time (filesystem timestamp) */
    UINT32      Size;           /**< File size in terms of bytes */
} RFS_ATTRIB;

/**
 * @todo Doc me
 */
typedef struct
{
    UINT32      sizeOfItem;     /**< Size of the Item (sizeof(RFS_LISTDIR_ITEM) + NameLen - 1) */
    RFS_ATTRIB  Attrib;         /**< File attributes */
    UINT32      NameLen;        /**< File name length (including terminating zero) */
    CHAR8       Name[1];        /**< File name */
} PACKED RFS_LISTDIR_ITEM;

/**
 * Structure for the SMI-Call #RFS_PROC_GETATT
 */
typedef struct
{
    SINT32  NameLen;            /**< Length of name (including terminating zero) */
    SINT32  Spare[2];           /**< Must be 0 for now */
    CHAR8   Name[1];            /**< Absolute path to file */
} RFS_GETATT_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_GETATT
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    SINT32      Spare[3];       /**< Must be 0 for now */
    RFS_ATTRIB  Attributes;     /**< File attributes */
} RFS_GETATT_R;

/**
 * Structure for the SMI-Call #RFS_PROC_SETTIME
 */
typedef struct
{
    SINT32      NameLen;        /**< Length of name (including terminating zero) */
    struct tm   Actime;         /**< Set the access time (file system time) */
    struct tm   ModTime;        /**< Set the modification time (file system time) */
    SINT32      Spare[2];       /**< Must be 0 for now */
    CHAR8       Name[1];        /**< Absolute path to file or directory */
} RFS_SETTIME_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_SETTIME
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Spare[2];           /**< Must be 0 for now */
} RFS_SETTIME_R;

/**
 * Structure for the SMI-Call #RFS_PROC_GETFSROOT
 */
typedef struct
{
    SINT32  Spare[2];           /**< Must be 0 for now */
} RFS_GETFSROOT_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_GETFSROOT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  NbOfRootDev;        /**< Number of root devices */
    SINT32  NameLen;            /**< Total length of name-list (including terminating zeroes) */
    SINT32  Spare[2];           /**< Must be 0 for now */
    CHAR8   Name[1];            /**< Zero terminated name-list of root devices */
} RFS_GETFSROOT_R;

/**
 * Structure for the SMI-Call #RFS_PROC_OPEN
 */
typedef struct
{
    SINT32  NameLen;            /**< File name length (including terminating zero) */
    /**
     * @brief File open flags
     * - #RFS_O_RDONLY ... @copybrief #RFS_O_RDONLY
     * - #RFS_O_WRONLY ... @copybrief #RFS_O_WRONLY
     * - #RFS_O_RDWR ... @copybrief #RFS_O_RDWR
     */
    UINT32  Flags;
    SINT32  Spare[2];           /**< Must be 0 for now */
    CHAR8   Name[1];            /**< Absolute file/directory path */
} RFS_OPEN_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_OPEN
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  FileHandleIdx;      /**< File handle */
    /**
     * @brief File ready flag
     * - \c 0 ... File not opened (transfer in progress)
     * - \c 1 ... File opened
     */
    SINT32  Ready;
    SINT32  Spare[1];           /**< Must be 0 for now */
} RFS_OPEN_R;

/**
 * Structure for the SMI-Call #RFS_PROC_CLOSE
 */
typedef struct
{
    SINT32  FileHandleIdx;      /**< File handle returned by the call #RFS_PROC_OPEN or #RFS_PROC_CREAT */
    SINT32  Spare[2];           /**< Must be 0 for now */
} RFS_CLOSE_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_CLOSE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    /**
     * @brief File ready flag
     * - \c 0 ... File not closed (transfer in progress)
     * - \c 1 ... File closed
     */
    SINT32  Ready;
    SINT32  Spare[2];           /**< Must be 0 for now */
} RFS_CLOSE_R;

/**
 * Structure for the SMI-Call #RFS_PROC_READ
 */
typedef struct
{
    SINT32  FileHandleIdx;      /**< File handle returned by the call #RFS_PROC_OPEN */
    SINT32  Offset;             /**< File offset */
    SINT32  Count;              /**< Data size to read in bytes */
    SINT32  Spare[2];           /**< Must be 0 for now */
} RFS_READ_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_READ
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  DataLen;            /**< Number of data bytes read */
    SINT32  Spare[2];           /**< Must be 0 for now */
    UINT8   Data[1];            /**< Block of data read */
} RFS_READ_R;

/**
 * Structure for the SMI-Call #RFS_PROC_WRITE
 */
typedef struct
{
    SINT32  FileHandleIdx;      /**< File handle returned by the call #RFS_PROC_OPEN or #RFS_PROC_CREAT */
    SINT32  Offset;             /**< File offset */
    SINT32  Count;              /**< Data size to write in bytes */
    SINT32  Spare[2];           /**< Must be 0 for now */
    UINT8   Data[1];            /**< Block of data to write */
} RFS_WRITE_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_WRITE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Count;              /**< Data size actually written in bytes */
    SINT32  Spare[2];           /**< Must be 0 for now */
} RFS_WRITE_R;

/**
 * Structure for the SMI-Call #RFS_PROC_CREAT
 */
typedef struct
{
    SINT32  NameLen;            /**< File name length (including terminating zero) */
    /**
     * @brief File open flags
     * - #RFS_O_RDONLY ... @copybrief #RFS_O_RDONLY
     * - #RFS_O_WRONLY ... @copybrief #RFS_O_WRONLY
     * - #RFS_O_RDWR ... @copybrief #RFS_O_RDWR
     */
    UINT32  Flags;
    SINT32  Spare[2];           /**< Must be 0 for now */
    CHAR8   Name[1];            /**< Absolute file/directory path */
} RFS_CREAT_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_CREAT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  FileHandleIdx;      /**< File Handle */
    SINT32  Spare[2];           /**< Must be 0 for now */
} RFS_CREAT_R;

/**
 * Structure for the SMI-Call #RFS_PROC_REMOVE
 */
typedef struct
{
    SINT32  NameLen;            /**< File name length (including terminating zero) */
    SINT32  Spare[2];           /**< Must be 0 for now */
    CHAR8   Name[1];            /**< Absolute file path */
} RFS_REMOVE_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_REMOVE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Spare[1];           /**< Must be 0 for now */
} RFS_REMOVE_R;

/**
 * Structure for the SMI-Call #RFS_PROC_RENAME
 */
typedef struct
{
    SINT32  OldNameLen;         /**< Old file name length (including terminating zero) */
    SINT32  NewNameLen;         /**< New file name length (including terminating zero) */
    SINT32  Spare[2];           /**< Must be 0 for now */
    /**
     * Absolute path to file to copy from ('\0' terminated)
     * Absolute path to the new file, ('\0' terminated)
     */
    CHAR8   Names[1];
} RFS_RENAME_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_RENAME
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Spare[1];           /**< Must be 0 for now */
} RFS_RENAME_R;

/**
 * Structure for the SMI-Call #RFS_PROC_MKDIR
 */
typedef struct
{
    SINT32  DirNameLen;         /**< Directory name length (including terminating zero) */
    SINT32  Spare[2];           /**< Must be 0 for now */
    CHAR8   DirName[1];         /**< Absolute directory path */
} RFS_MKDIR_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_MKDIR
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Spare[2];           /**< Must be 0 for now */
} RFS_MKDIR_R;

/**
 * Structure for the SMI-Call #RFS_PROC_RMDIR
 */
typedef struct
{
    SINT32  DirNameLen;         /**< Length of name (including terminating zero) */
    SINT32  Spare[2];           /**< Must be 0 for now */
    CHAR8   DirName[1];         /**< Absolute path */
} RFS_RMDIR_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_RMDIR
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Spare[2];           /**< Must be 0 for now */
} RFS_RMDIR_R;

/**
 * Structure for the SMI-Call #RFS_PROC_LISTDIR
 */
typedef struct
{
    SINT32  DirNameLen;         /**< Directory name length (including terminating zero) */
    SINT32  Offset;             /**< Directory offset (0 = start at first entry) */
    UINT32  MaxNbItems;         /**< Maximum number of entries to return */
    SINT32  Spare[3];           /**< Must be 0 for now */
    CHAR8   DirName[1];         /**< Absolute directory path */
} RFS_LISTDIR_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_LISTDIR
 */
typedef struct
{
    SINT32              RetCode;     /**< Return Code */
    UINT32              NbItems;     /**< Number of returned directory entries */
    /**
     * @brief End of directory reached
     * - \c 0 ... No
     * - \c 1 ... Yes, end of directory reached
     */
    SINT32              EndOfDir;
    SINT32              Spare[3];    /**< Must be 0 for now */
    RFS_LISTDIR_ITEM    Items[1];    /**< List of directory entries */
} RFS_LISTDIR_R;

/**
 * Structure for the SMI-Call #RFS_PROC_COPY
 */
typedef struct
{
    SINT32  SrcNameLen;         /**< Source file name length (including terminating zero) */
    SINT32  DestNameLen;        /**< Destination file name length (including terminating zero) */
    SINT32  Spare[2];           /**< Must be 0 for now */
    /**
     * Absolute path to source file ('\0' terminated)
     * Absolute path to destination file ('\0' terminated)
     */
    CHAR8   Names[1];
} RFS_COPY_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_COPY
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Spare[1];           /**< Must be 0 for now */
} RFS_COPY_R;

/**
 * Structure for the SMI-Call #RFS_PROC_FTPSTAT
 */
typedef struct
{
    SINT32  FileNameLen;        /**< Length of file name (including terminating zero) */
    SINT32  FileHandleIdx;      /**< File handle returned by the call #RFS_PROC_OPEN or #RFS_PROC_CREAT */
    SINT32  Spare[4];           /**< Must be 0 for now */
    CHAR8   FileName[1];        /**< Absolute path to file */
} RFS_FTPFILESTATINF_C;

/**
 * Structure for the SMI-Reply #RFS_PROC_FTPSTAT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    /**
     * @brief File ready for further access
     * - \c 0 ... No, transfer not finished yet
     * - \c 1 ... Yes, transfer finished
     */
    SINT32  Ready;
    SINT32  Length;             /**< Actual size of file */
    SINT32  Offset;             /**< Actual offset of file */
    SINT32  Spare[4];           /**< Must be 0 for now */
} RFS_FTPFILESTATINF_R;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
