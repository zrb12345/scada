/**
 ********************************************************************************
 * @file     mod_e.h
 * @author   Fritsche
 *
 * @brief This file contains all definitions and declarations exported by
 *        the Module Handler for use by modules running on the same CPU.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
 *******************************************************************************/

#ifndef MOD_E__H
#define MOD_E__H

#ifdef __cplusplus
extern "C"
{
#endif

#include <moduleLib.h>
#include <mod.h>

/**
 * @addtogroup MOD-API
 * @{
 */

/** Parameters returned from the module loader */
typedef struct
{
    UINT32 FileType;                    /**< Type of software module */
    UINT32 LenObj;                      /**< Size of object code */
    UINT32 IdObj;                       /**< VxWorks module ID of object code */
    void  *pObj;                        /**< Pointer to object in memory */
    UINT32 LenCfg;                      /**< Size of config data */
    void  *pCfg;                        /**< Pointer to config data */
    UINT32 LenAttr;                     /**< Size of attribute data */
    void  *pAttr;                       /**< Pointer to attribute data */
} MOD_LOAD;

typedef struct
{
    CHAR hostName[M_PATHLEN + 1];       /**< Any host name */
    CHAR localName[M_PATHLEN + 1];      /**< Any local name */
} MOD_HOSTNAME;

/** @brief List of classpath lib files */
EXTERN LST_ID *mod_LibLst;

/**
 * @brief This function locks the loading of software modules forever
 *        (up to the next reboot).
 *
 * @retval #TRUE  Success, no module loaded, loading process locked
 * @retval #FALSE Error, at least one module is loaded, loading process not locked
 */
BOOL8 mod_NoModules(void);

/**
 * @brief This function permits the loading of a module from the VxWorks shell.
 *
 * @param[in] ModuleName  Module name of the module to be loaded.<br>
 *             The parameter must be identical with the file name of the
 *             software module used in the file `MConfig.ini` of the keyword
 *             `ModuleName`, the ending `.m` is optional.
 *             The search is performed case-sensitively.
 *
 * @note If several software modules with the same name are in the file
 *       `MConfig.ini`, the first entry is always found. Multiple instantiation
 *       of software modules is therefore not possible using this console
 *       function.<br>
 *       If no module information could be found in the file `MConfig.ini`,
 *       default parameters are used and the module file must be in the
 *       current working directory.
 *
 * @retval     0       Module loaded
 * @retval     <0      Error
 */
SINT32 mod_LoadApp(const CHAR *ModuleName);

/**
 * @brief This function allows to unload a module from the VxWorks shell.
 *
 * The `ModuleName` of the module to be unloaded must be passed as parameter.
 *
 * @param[in]  ModuleName  Name of the module to be unloaded.
 *
 * @retval     0       Module unloaded
 * @retval     <0      Error
 */
SINT32 mod_UnloadApp(const CHAR *ModuleName);

/**
 * @brief This function determines the entry information for a specific entry
 *        in the module file.
 *
 * @param[in]  FileId          Id of opened file
 * @param[in]  EntryType       Type of desired entry
 * @param[out] pEntryInfo      Determined module information
 *
 * @retval     0       OK
 * @retval     -1      Module file not readable
 * @retval     -2      Entry not found
 */
SINT32 mod_GetEntryInfo(SINT32 FileId, UINT32 EntryType, MOD_ENTRY *pEntryInfo);

/**
 * @brief This function determines the header information of a module file.
 *
 * @param[in]  FileId          Id of opened
 * @param[out] pModInfo        Determined module information
 *
 * @retval     0       OK
 * @retval     -1      Module file not readable
 */
SINT32 mod_GetModInfo(SINT32 FileId, MOD_FHEAD *pModInfo);

/**
 * @brief This function loads a desired module entry into a buffer.
 *
 * The buffer is allocated by the function. The entry will be unpacked,
 * if it is packed inside the module file.
 *
 * @warning The caller has to free the allocated buffer.
 *
 * @param[in]  FileId          Id of opened file
 * @param[in]  EntryType       Type of desired entry
 * @param[out] ppBuffer        Pointer to allocated buffer
 *
 * @retval     0       OK
 * @retval     -1      Module file not readable
 * @retval     -2      Entry not found
 * @retval     -3      Entry not loadable
 */
SINT32 mod_LoadEntry(SINT32 FileId, UINT32 EntryType, void **ppBuffer);

/**
 * @brief This function tests, if a path is relative and renames the path
 *        (`PathName`) to an absolute path if it is relative.
 *
 * @param[in]  PathName    Path to test. Maximum size is M_PATHLEN.
 *
 * @retval  0 OK
 * @retval <0 Error, `PathName` is too long
 */
SINT32 RelToAbsDir(UINT8 *PathName);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
