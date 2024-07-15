/**
********************************************************************************
* @file     zip_e.h
* @author   Fritsche
*
* @brief This file contains all definitions and declarations exported by
*        the ZIP Library for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef ZIP_E__H
#define ZIP_E__H

#ifdef __cplusplus
extern  "C"
{
#endif

#include <mtypes.h>

/**
 * @addtogroup ZIP-DEF
 * @{
 */

/**
 * @brief ZIP-file handle
 */
typedef void *ZIP_FILE;
/** @} */

/**
 * @addtogroup ZIP-API
 * @{
 */

/**
 * @brief This function packs all files of a directory without subdirectories in
 *        ZIP-format.
 *
 * @param[in]  Directory   Name of directory that has to be packed.
 * @param[in]  ZipFileName Directory/Name of ZIP-file that has to be created.
 * <br>Example:
 * - ZipFileName "file.zip": In this case, a ZIP-file "file.zip" will be
 *   created in the boot directory.
 * - ZipFileName "/cfc0/folder/file.zip": In this case, a ZIP-file "file.zip"
 *   will be created in the directory "/cfc0/folder/".
 *
 * @retval     0       OK
 * @retval     -1      ZIP-file could not be created
 */
SINT32 zip_PackDirectory(char *Directory, char *ZipFileName);

/**
 * @brief This function packs all files of a directory and its subdirectories
 *        in ZIP-format.
 *
 * @param[in]  Directory               Name of directory that has to be packed.
 * @param[in]  ZipFileName             Directory/Name of ZIP-file that has to be created.
 * <br>Example:
 * - ZipFileName "file.zip": In this case, a ZIP-file "file.zip" will be
 *   created in the boot directory.
 * - ZipFileName "/cfc0/folder/file.zip": In this case, a ZIP-file "file.zip"
 *   will be created in the directory "/cfc0/folder/".
 * @param[in]  IncludeSubDirectories   Level of subdirectories to pack:
 * - -1: pack all subdirectories
 * - 0: pack just the current directory
 * - 1..n: number of subdirectory level
 *
 * @retval     0       OK
 * @retval     -1      ZIP-file could not be created
 */
SINT32 zip_PackDirectoryEx(char *Directory, char *ZipFileName, UINT32 IncludeSubDirectories);

/**
 * @brief This function packs all files of a directory and its subdirectories
 *        in ZIP-format.
 *
 * Difference to function zip_PackDirectoryEx(): One can choose, if the directory
 * structure will be adopted in the ZIP-archive or not.
 *
 * @param[in]  Directory               Name of directory that has to be packed.
 * @param[in]  ZipFileName             Directory/Name of ZIP-file that has to be created.
 * <br>Example:
 * - ZipFileName "file.zip": In this case, a ZIP-file "file.zip" will be
 *   created in the boot directory.
 * - ZipFileName "/cfc0/folder/file.zip": In this case, a ZIP-file "file.zip"
 *   will be created in the directory "/cfc0/folder/".
 * @param[in]  IncludeSubDirectories   Level of subdirectories to pack:
 * - -1: pack all subdirectories
 * - 0: pack just the current directory
 * - 1..n: number of subdirectory level
 * @param[in]  NoDirNames              Exclude directory-names:
 * - FALSE: The directory structure will not be adopted in the zip archive.
 *          The ZIP-archive just will contain all files of the directory and its
 *          subdirectories.
 * - TRUE: The directory structure will be adopted in the ZIP-archive.
 *
 * @retval     0       OK
 * @retval     -1      ZIP-file could not be created
 */
SINT32 zip_PackDirectoryEx2(char *Directory, char *ZipFileName, UINT32 IncludeSubDirectories,
                            BOOL8 NoDirNames);

/**
 * @brief This function packs a file in ZIP-format.
 *
 * The directory structure of the file will be adopted in the ZIP-archive.
 *
 * @param[in]  File         Directory and name of file to pack
 *                          (e.g. "/cfc0/folder/file.txt").
 * @param[in]  ZipFileName  Directory/Name of ZIP-file that has to be created.
 * <br>Example:
 * - ZipFileName "file.zip": In this case, a ZIP-file "file.zip" will be
 *   created in the boot directory.
 * - ZipFileName "/cfc0/folder/file.zip": In this case, a ZIP-file "file.zip"
 *   will be created in the directory "/cfc0/folder/".
 *
 * @retval     0       OK
 * @retval     -1      ZIP-file could not be created
 */
SINT32 zip_PackFile(char *File, char *ZipFileName);

/**
 * @brief This function unpacks all files of a ZIP-archive to a destination folder.
 *
 * @note The destination folder does not have to exist before calling the function
 *       zip_UnpackFile(), it will be created.
 *
 * @param[in]  ZipFileName         Directory and/or name of ZIP-file.
 * - If the ZIP-file exists in the boot directory, one can use the name of the ZIP-File
 *   without path for ZipFileName (e.g. "file.zip").
 * - If the ZIP-file exists in another directory or in a subdirectory of the
 *   boot directory, one has to use the path and the name of the ZIP-file
 *   for ZipFileName (e.g. "/cfc0/folder/file.zip").
 * @param[in]  DestPath            Destination directory.
 * @param[in]  ExtractWithoutPath  With this flag one can decide, if the archive
 *                                 should be extracted with or without the packed path:
 * - TRUE: The files of the ZIP-archive will be unpacked without packed path.
 *         All files inside the ZIP-archive will be unpacked to `DestPath`.
 * - FALSE: The files of the ZIP-archive will be unpacked with packed path to
 *          `DestPath`.
 *
 * @retval     0       OK
 * @retval     -1      ZIP-archive could not be unpacked
 */
SINT32 zip_UnpackFile(char *ZipFileName, char *DestPath, BOOL ExtractWithoutPath);

/**
 * @brief This function creates a ZIP-archive.
 *
 * With the function zip_PackFilesAdd(), one can add files to the ZIP-archive
 * that has been created with the function zip_PackFilesInit().
 *
 * @note After adding desired files to the ZIP-archive it has to be closed by
 *       the function zip_PackFilesClose().
 *
 * @param[in]  ZipFileName   Path and/or name of ZIP-archive to create
 *                           (will be overwritten if already exists).
 * <br>Example:
 * - ZipFileName "file.zip": In this case, a ZIP-file "file.zip" will be
 *   created in the boot directory.
 * - ZipFileName "/cfc0/folder/file.zip": In this case, a ZIP-file "file.zip"
 *   will be created in the directory "/cfc0/folder/".
 *
 * @retval     !=0      Handle of ZIP-file (used for zip_PackFilesAdd())
 * @retval     NULL     ZIP-archive could not be created
 */
ZIP_FILE zip_PackFilesInit(char* ZipFileName);

/**
 * @brief This function adds a file to a ZIP-archive, that has been created by
 *        the function zip_PackFilesInit() before.
 *
 * @note After adding desired files to the ZIP-archive it has to be closed by
 *       the function zip_PackFilesClose().
 *
 * @param[in]  File    Path and/or name of the file to add to ZIP-archive.
 * <br>Example:
 * - ZipFileName "file.txt": In this case, the file "file.txt" will be
 *   searched in the boot directory and (if found) added to the ZIP-directory.
 * - ZipFileName "/cfc0/folder/file.txt": In this case, the file "file.txt"
 *   will be searched in the directory "/cfc0/folder/" and (if found) added to
 *   the ZIP-archive.
 * @param[in]  zf      ZipFile handle returned from the function zip_PackFilesInit()
 *
 * @retval     0       OK
 * @retval     <0      File could not be added to ZIP-archive
 */
SINT32 zip_PackFilesAdd(char *File, ZIP_FILE zf);

/**
 * @brief This function closes a ZIP-archive, that has been created by the
 *        function zip_PackFilesInit().
 *
 * @param[in]  zf      ZipFile handle returned from the function zip_PackFilesInit()
 *
 * @retval     0       OK
 * @retval     <0      ZIP-archive could not be closed
 */
SINT32 zip_PackFilesClose(ZIP_FILE zf);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
