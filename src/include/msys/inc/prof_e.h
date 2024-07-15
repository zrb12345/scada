/**
********************************************************************************
* @file     prof_e.h
* @author   Diem
*
* @brief This file contains all definitions and declarations exported by
*        the Profile Library (reading configuration information out of
*        MCONFIG.INI) for use by modules running on the same CPU.
*
*        All profile functions are implemented in MCore.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef PROF_E__H
#define PROF_E__H

#ifdef __cplusplus
extern  "C"
{
#endif

#include <mtypes.h>

/**
 * @addtogroup SYS-PROF-DEF
 * @{
 */

/**
 * Maximum size of key without '\0' termination.
 * @see #PF_KEYLEN2
 */
#define PF_KEYLEN       15
/**
 * Maximum size of key without '\0' termination.
 * For \p MCore versions newer than V3.96 the key length has been increased to #PF_KEYLEN2.
 *
 * @since      MSys V3.96
 * @see #PF_KEYLEN
 */
#define PF_KEYLEN2      146
/**
 * Maximum size of key with '\0' termination (aligned)
 * @see #PF_KEYLEN2_A
 */
#define PF_KEYLEN_A     ((PF_KEYLEN  + 1 + 3) & 0xfffffffc)
/**
 * Maximum size of key with '\0' termination (aligned)
 * For \p MCore versions newer than V3.96 the key length has been increased to #PF_KEYLEN2_A.
 *
 * @since      MSys V3.96
 * @see #PF_KEYLEN_A
 */
#define PF_KEYLEN2_A    ((PF_KEYLEN2 + 1 + 3) & 0xfffffffc)

/**
 * @name Function codes for pf_Control()
 * @see pf_Control()
 * @{
 */
#define PF_RELOAD_FILE  1               /**< Marks the configuration file to be
                                             reloaded with the next get- or set- function */
#define PF_USE_FILE     2               /**< Opposite of #PF_USE_DEFAULTS. Configuration file will
                                             be considered when searching for a configuration.*/
#define PF_USE_DEFAULTS 3               /**< No configuration will be read from file. The provided
                                             parameter `Default` of each call will be returned instead.
                                             RetCode will be #PF_E_NOKEY. */
#define PF_FILE_LOADED  4               /**< Mark the currently loaded configuration as default
                                             configuration file.*/
/** @} */

/**
 * @name Predefined sections, groups and keywords for the control system
 * @{
 */
#define PF_S_SYSTEM     "SYSTEM"            /**< Definition for the predefined section `[SYSTEM]` */
#define PF_G_BOOTFILES  "BootFiles"         /**< Definition for the predefined group `(BootFiles)` */
#define PF_G_SYSDIRS    "SysDirs"           /**< Definition for the predefined group `(SysDirs)` */
#define PF_G_BOOTHOST   "BootHost"          /**< Definition for the predefined group `(BootHost)` */
#define PF_K_USERNAME   "UserName"          /**< Definition for the predefined keyword `UserName` */
#define PF_G_NET        "Network"           /**< Definition for the predefined group `(Network)` */
#define PF_G_SERV       "Server"            /**< Definition for the predefined group `(Server)` */
#define PF_G_SYSTIME    "SysTime"           /**< Definition for the predefined group `(SysTime)` */
#define PF_G_BLKDRV     "BlockDrivers"      /**< Definition for the predefined group `(BlockDrivers)` */
#define PF_G_DEBUG      "Debug"             /**< Definition for the predefined group `(Debug)` */
#define PF_K_BOOTMODE   "BootMode"          /**< Definition for the predefined keyword `BootMode` */
#define PF_G_SYSMODE    "SysMode"           /**< Definition for the predefined group `(SysMode)` */
#define PF_K_NOPFAIL    "NoPFailHandler"    /**< Definition for the predefined keyword `NoPFailHandler` */
#define PF_G_SYNC       "SyncRate"          /**< Definition for the predefined group `(SyncRate)` */
#define PF_G_SYNCCONFIG "SyncConfig"        /**< Definition for the predefined group `(SyncConfig)` */
#define PF_K_SYNCHIGH   "SyncHigh"          /**< Definition for the predefined keyword `SyncHigh` */
#define PF_K_SYNCLOW    "SyncLow"           /**< Definition for the predefined keyword `SyncLow` */
#define PF_K_SYNCPROD   "SyncProducer"      /**< Definition for the predefined keyword `SyncProducer` */
#define PF_K_SYNCDELHI  "SyncHighIntDelay"  /**< Definition for the predefined keyword `SyncHighIntDelay` */
#define PF_K_SYNCDELLO  "SyncLowIntDelay"   /**< Definition for the predefined keyword `SyncLowIntDelay` */
#define PF_K_SYNCMULTI  "SyncMultiplier"    /**< Definition for the predefined keyword `SyncMultiplier` */
#define PF_K_SYNCDELAY  "SyncSignalDelay"   /**< Definition for the predefined keyword `SyncSignalDelay` */
#define PF_K_SYNCDIFF   "SyncControlDiff"   /**< Definition for the predefined keyword `SyncControlDiff` */
#define PF_K_SYNCFAILB  "SyncFailBehavior"  /**< Definition for the predefined keyword `SyncFailBehavior` */
#define PF_G_PLCRTS     "PlcRts"            /**< Definition for the predefined group `(PlcRts)` */
#define PF_G_IOSYSTEM   "IO-System"         /**< Definition for the predefined group `(IO-System)` */
#define PF_K_EVTTSK     "EventIntTask"      /**< Definition for the predefined keyword `EventIntTask` */
#define PF_K_FBDELAY    "FastBusDelay"      /**< Definition for the predefined keyword `FastBusDelay` */
#define PF_G_RES        "ResHandler"        /**< Definition for the predefined group `(ResHandler)` */
#define PF_K_USRCHK     "UserCheck"         /**< Definition for the predefined keyword `UserCheck` */
#define PF_G_ERRORHD    "ErrorHandler"      /**< Definition for the predefined group `(ErrorHandler)` */
#define PF_K_TIMEMODE   "TimestampMode"     /**< Definition for the predefined keyword `TimestampMode` */
#define PF_K_LSTNAME    "ListName"          /**< Definition for the predefined keyword `ListName` */
#define PF_K_LSTLEN     "ListLen"           /**< Definition for the predefined keyword `ListLen` */
#define PF_K_LSTRETAIN  "ListRetain"        /**< Definition for the predefined keyword `(ListRetain)` */
#define PF_G_APP        "Application"       /**< Definition for the predefined group `(Application)` */
#define PF_K_APPNAME    "Name"              /**< Definition for the predefined keyword `Name` */

#define PF_S_DRIVERS    "DRIVERS"           /**< Definition for the predefined section `[DRIVERS]` */
#define PF_G_SIM        "Simulator"         /**< Definition for the predefined group `(Simulator)` */
#define PF_G_CARD       "Card"              /**< Definition for the predefined group `(Card)` */

#define PF_G_BASE       "BaseParms"         /**< Definition for the predefined group `(BaseParms)` */
#define PF_K_MNAME      "ModuleName"        /**< Definition for the predefined keyword `ModuleName` */
#define PF_K_MPATH      "ModulePath"        /**< Definition for the predefined keyword `ModulePath` */
#define PF_K_MINDEX     "ModuleIndex"       /**< Definition for the predefined keyword `ModuleIndex` */
#define PF_K_MPART      "Partition"         /**< Definition for the predefined keyword `Partition` */
#define PF_K_MPRIO      "Priority"          /**< Definition for the predefined keyword `Priority` */
#define PF_K_MDBG       "DebugMode"         /**< Definition for the predefined keyword `DebugMode` */
#define PF_K_DESC       "Description"       /**< Definition for the predefined keyword `Description` */
#define PF_K_SECLEVEL   "SecurityLevel"     /**< Definition for the predefined keyword `SecurityLevel` */

#define PF_G_PLCPARM    "PlcParms"          /**< Definition for the predefined keyword `PlcParms` */
#define PF_K_PARGSTR    "ArgumentStr"       /**< Definition for the predefined keyword `ArgumentStr` */
#define PF_K_PARGNUM    "ArgumentNum"       /**< Definition for the predefined keyword `ArgumentNum` */
#define PF_K_PSHRDRD    "SharedRetain"      /**< Definition for the predefined keyword `SharedRetain` */
#define PF_K_PRTNMRK    "RetainMarkers"     /**< Definition for the predefined keyword `RetainMarkers` */
#define PF_K_PEXCSTP    "ExceptionStop"     /**< Definition for the predefined keyword `ExceptionStop` */
#define PF_K_PEXCGOP    "ExceptionPanic"    /**< Definition for the predefined keyword `ExceptionPanic` */
#define PF_K_ARTISRVPRT "ARTISrvPort"       /**< Definition for the predefined keyword `ARTISrvPort` */
#define PF_K_SVICONS    "SVIConsistency"    /**< Definition for the predefined keyword `SVIConsistency` */
#define PF_K_STACKSIZE  "StackSize"         /**< Definition for the predefined keyword `StackSize` */
/** @} */

/**
 * @name Possible return codes
 * @{
 */
#define PF_E_OK         M_E_OK                        /**< @copybrief  M_E_OK */
#define PF_E_PARM       (M_ES_PF|M_E_PARM)            /**< @copybrief  M_E_PARM */
#define PF_E_NOFILE     (M_ES_PF|M_E_NOFILE)          /**< @copybrief  M_E_NOFILE */
#define PF_E_FILEBIG    (M_ES_PF|M_E_FILEBIG)         /**< @copybrief  M_E_FILEBIG */
#define PF_E_FILEEMPTY  (M_ES_PF|M_E_FILEEMPTY)       /**< @copybrief  M_E_FILEEMPTY */
#define PF_E_NOSEC      (M_ES_PF|M_E_NOSEC)           /**< @copybrief  M_E_NOSEC */
#define PF_E_NOGRP      (M_ES_PF|M_E_NOGRP)           /**< @copybrief  M_E_NOGRP */
#define PF_E_NOKEY      (M_ES_PF|M_E_NOKEY)           /**< @copybrief  M_E_NOKEY */
#define PF_E_ENDFILE    (M_ES_PF|M_E_ENDFILE)         /**< @copybrief  M_E_ENDFILE */
#define PF_E_NOSET      (M_ES_PF|M_E_NOPFSET)         /**< @copybrief  M_E_NOPFSET */
#define PF_E_NOUNIT     (M_ES_PF|M_E_NOPFUNIT)        /**< @copybrief  M_E_NOPFUNIT */
#define PF_E_SHORTKEY   (M_ES_PF|M_E_SHORTKEY)        /**< @copybrief  M_E_SHORTKEY */
/** @} */
/** @} end of SYS-PROF-DEF */

/**
 * @addtogroup SYS-PROF-API
 * @{
 */

/**
********************************************************************************
* @brief Return the configured value for the \p Keyword in the given \p Section
* and \p Group.
*
* The minimum length of the strings for \p Section, \p Group and \p Keyword is 3
* characters. There is no maximum length. The first 15 characters are
* significant, these must be unique.
*
* @param[in]  Section        Section where to look for keyword or NULL if it does
*                            not matter.
* @param[in]  Group          Group where to look for keyword or NULL if it does
*                            not matter
* @param[in]  Keyword        Keyword to look for. Must not be NULL.
*
* @param[in]  Default        Default value to be returned if keyword is not found.
* @param[out] Buffer         Memory where to store value of the keyword to.
*                            It is always NULL terminated.
* @param[in]  Size           Size of memory to store value to.
* @param[in]  StartLine      Line where to start to look for the keyword
* @param[in]  FileName       File where to search for the keyword or NULL
*                            to search in `mconfig.ini`.
*
* @retval  >=0              OK, Line number where the keyword is found
* @retval  #PF_E_PARM
* @retval  #PF_E_NOFILE
* @retval  #PF_E_FILEBIG
* @retval  #PF_E_FILEEMPTY
* @retval  #PF_E_NOSEC
* @retval  #PF_E_NOGRP
* @retval  #PF_E_NOKEY
* @retval  #PF_E_ENDFILE
* @retval  #PF_E_SHORTKEY
*******************************************************************************/
SINT32  pf_GetStrg(CHAR * Section, CHAR * Group, CHAR * Keyword, CHAR * Default,
                   CHAR * Buffer, SINT32 Size, SINT32 StartLine, CHAR * FileName);

/**
********************************************************************************
* @brief Return the name of the preceding \p Section and \p Group of the passed line number.
*
* @param[out] Section        Section where to store found section name or Null if
*                            only group matters.
* @param[out] Group          Group where to store found group name or Null if
*                            only section matters.
* @param[in]  Size           Size of both - section and group - to store value to.
* @param[in]  LastLine       Line where to start to look for the keyword
* @param[in]  FileName       File where to search for the keyword or NULL
*                            to search in `mconfig.ini`.
*
* @retval  >=0              Success. Line number of section or group if \p Section is NULL.
* @retval  #PF_E_PARM
* @retval  #PF_E_NOFILE
* @retval  #PF_E_FILEBIG
* @retval  #PF_E_FILEEMPTY
* @retval  #PF_E_NOSEC      May also mean that the search has endet with no result
*                           (beginning of file was reached)
* @retval  #PF_E_NOGRP
* @retval  #PF_E_NOKEY
* @retval  #PF_E_ENDFILE    May also mean that the specified line number points
*                           behind the end of the file or file could not be loaded
* @retval  #PF_E_SHORTKEY
*******************************************************************************/
SINT32  pf_GetSecGrp(CHAR * Section, CHAR * Group, SINT32 Size, SINT32 LastLine, CHAR * FileName);

/**
********************************************************************************
* @brief Return the boolean value (#TRUE or #FALSE) for the \p Keyword in the
*        given \p Section and \p Group.
*
* The minimum length of the strings for \p Section, \p Group and \p Keyword is 3
* characters. There is no maximum length. The first 15 characters are
* significant, these must be unique.
*
* @param[in]  Section        Section where to look for keyword or NULL if it does
*                            not matter.
* @param[in]  Group          Group where to look for keyword or NULL if it does
*                            not matter
* @param[in]  Keyword        Keyword to look for. Must not be NULL.
* @param[in]  Default        Default value to be returned if keyword is not found.
* @param[out] Value          Memory where to store value of the keyword to.
* @param[in]  StartLine      Line where to start to look for the keyword
* @param[in]  FileName       File where to search for the keyword or NULL
*                            to search in `mconfig.ini`.
*
* @retval  >=0              OK, Line number where the keyword is found
* @retval  #PF_E_PARM
* @retval  #PF_E_NOFILE
* @retval  #PF_E_FILEBIG
* @retval  #PF_E_FILEEMPTY
* @retval  #PF_E_NOSEC
* @retval  #PF_E_NOGRP
* @retval  #PF_E_ENDFILE
* @retval  #PF_E_SHORTKEY
*******************************************************************************/
SINT32  pf_GetBool(CHAR * Section, CHAR * Group, CHAR * Keyword, BOOL8 Default,
                   BOOL8 * Value, SINT32 StartLine, CHAR * FileName);

/**
********************************************************************************
* @brief Return the configured integer value (32-bit) for the \p Keyword in the given
*        \p Section and \p Group.
*
* The minimum length of the strings for \p Section, \p Group and \p Keyword is 3
* characters. There is no maximum length. The first 15 characters are
* significant, these must be unique.
*
* @param[in]  Section        Section where to look for keyword or NULL if it does
*                            not matter.
* @param[in]  Group          Group where to look for keyword or NULL if it does
*                            not matter
* @param[in]  Keyword        Keyword to look for. Must not be NULL.
* @param[in]  Default        Default value to be returned if keyword is not found.
* @param[out] Value          Memory where to store value of the keyword to.
* @param[in]  StartLine      Line where to start to look for the keyword
* @param[in]  FileName       File where to search for the keyword or NULL
*                            to search within loaded `mconfig.ini`.
*
* @retval  >=0              OK, Line number where the keyword is found
* @retval  #PF_E_PARM
* @retval  #PF_E_NOFILE
* @retval  #PF_E_FILEBIG
* @retval  #PF_E_FILEEMPTY
* @retval  #PF_E_NOSEC
* @retval  #PF_E_NOGRP
* @retval  #PF_E_NOKEY
* @retval  #PF_E_ENDFILE
* @retval  #PF_E_SHORTKEY
*******************************************************************************/
SINT32  pf_GetInt(CHAR * Section, CHAR * Group, CHAR * Keyword, SINT32 Default,
                  SINT32 * Value, SINT32 StartLine, CHAR * FileName);
/**
********************************************************************************
* @brief This function sets the processing of the profile functions to specific
*        special modes.
*
* The commands #PF_RELOAD_FILE and subsequent defines
* are used to control the way of reading the configuration. There are two use cases
* that can be controlled by these commands:
* - Use defaults: With #PF_USE_DEFAULTS the parameter `Default` of any get-function
*                 call will be returned and the configuration file will be ignored.
*                 This mode is left / disabled by calling #PF_RELOAD_FILE,
*                 #PF_USE_FILE or #PF_FILE_LOADED.
* - Change current default: The default configuration file is `mconfig.ini` that is used
*                 when a set- or get-function is called with `FileName`=NULL . Yet it
*                 is possible to change the default by first calling a set- or
*                 get-function with the desired default file (`FileName`) and then
*                 using the command #PF_FILE_LOADED. The default will be restored
*                 by the command #PF_RELOAD_FILE or by specifying the parameter `FileName`
*                 when calling any set- or get-function.
*
* @note Changing the above use cases can cause concurrency problems with other tasks reading
*       the configuration at the same time. It is save to be used in the INIT-phase when
*       the system is booting.
*
* @param[in]  FuncCode      Command to process. See #PF_RELOAD_FILE and subsequent defines.
*
* @retval  #PF_E_OK     OK, command successfully executed.
* @retval  #PF_E_PARM
*******************************************************************************/
SINT32  pf_Control(SINT32 FuncCode);

/**
********************************************************************************
* @brief Return the configured value for the \p Keyword in the given \p Section,
*        \p Group, \p Set and \p Unit.
*
* The minimum length of the strings for \p Section, \p Group and \p Keyword is 3
* characters. There is no maximum length. The first 15 characters are
* significant, these must be unique.
*
* Compared to pf_GetStrg() two additional hierarchy levels are supported.
*
* @note There are special rules about how this function searches for keywords,
*       see \ref SYS-PROF-EXT-RULES "Meaning of paramter `Set` and `Unit`".
*
* @param[in]  Section        Section where to look for keyword or NULL if it does
*                            not matter.
* @param[in]  Group          Group where to look for keyword or NULL if it does
*                            not matter
* @param[in]  Set            Set where to look for keyword or NULL if it does
*                            not matter
* @param[in]  Unit           Unit where to look for keyword or NULL if it does
*                            not matter
* @param[in]  Keyword        Keyword to look for. Must not be NULL.
* @param[in]  Default        Default value to be returned if keyword is not found.
* @param[out] Buffer         Memory where to store value of the keyword to.
*                            It is always NULL terminated.
* @param[in]  Size           Size of memory to store value to.
* @param[in]  StartLine      Line where to start to look for the keyword
* @param[in]  FileName       File where to search for the keyword or NULL
*                            to search in `mconfig.ini`.
*
* @retval  >=0              OK, Line number where the keyword is found
* @retval  #PF_E_PARM
* @retval  #PF_E_NOFILE
* @retval  #PF_E_FILEBIG
* @retval  #PF_E_FILEEMPTY
* @retval  #PF_E_NOSEC
* @retval  #PF_E_NOGRP
* @retval  #PF_E_NOKEY
* @retval  #PF_E_ENDFILE
* @retval  #PF_E_NOSET
* @retval  #PF_E_NOUNIT
* @retval  #PF_E_SHORTKEY
*******************************************************************************/
SINT32  pf_GetStrgExt(UINT8 * Section, UINT8 * Group, UINT8 * Set, UINT8 * Unit,
                      UINT8 * Keyword, UINT8 * Default, UINT8 * Buffer, SINT32 Size,
                      SINT32 StartLine, UINT8 * FileName);

/**
********************************************************************************
* @brief Return the configured integer value (32-bit) for the \p Keyword in given
*        the \p Section, \p Group, \p Set and \p Unit.
*
* The minimum length of the strings for \p Section, \p Group and \p Keyword is 3
* characters. There is no maximum length. The first 15 characters are
* significant, these must be unique.
*
* Compared to pf_GetInt() two additional hierarchy levels are supported.
*
* @note There are special rules about how this function searches for keywords,
*       see \ref SYS-PROF-EXT-RULES "Meaning of paramter `Set` and `Unit`".
*
* @param[in]  Section        Section where to look for keyword or NULL if it does
*                            not matter.
* @param[in]  Group          Group where to look for keyword or NULL if it does
*                            not matter
* @param[in]  Set            Set where to look for keyword or NULL if it does
*                            not matter
* @param[in]  Unit           Unit where to look for keyword or NULL if it does
*                            not matter
* @param[in]  Keyword        Keyword to look for. Must not be NULL.
* @param[in]  Default        Default value to be returned if keyword is not found.
* @param[out] Value          Memory where to store value of the keyword to.
* @param[in]  StartLine      Line where to start to look for the keyword
* @param[in]  FileName       File where to search for the keyword or NULL
*                            to search in `mconfig.ini`.
*
* @retval  >=0              OK, Line number where the keyword is found
* @retval  #PF_E_PARM
* @retval  #PF_E_NOFILE
* @retval  #PF_E_FILEBIG
* @retval  #PF_E_FILEEMPTY
* @retval  #PF_E_NOSEC
* @retval  #PF_E_NOGRP
* @retval  #PF_E_NOKEY
* @retval  #PF_E_ENDFILE
* @retval  #PF_E_NOSET
* @retval  #PF_E_NOUNIT
* @retval  #PF_E_SHORTKEY
*******************************************************************************/
SINT32  pf_GetIntExt(UINT8 * Section, UINT8 * Group, UINT8 * Set, UINT8 * Unit,
                     UINT8 * Keyword, SINT32 Default, SINT32 * Value, SINT32 StartLine,
                     UINT8 * FileName);

/**
********************************************************************************
* @brief Return the boolean value (#TRUE or #FALSE) for the \p Keyword in the
*        given \p Section, \p Group, \p Set and \p Unit.
*
* The minimum length of the strings for \p Section, \p Group and \p Keyword is 3
* characters. There is no maximum length. The first 15 characters are
* significant, these must be unique.
*
* Compared to pf_GetBool() two additional hierarchy levels are supported.
*
* @note There are special rules about how this function searches for keywords,
*       see \ref SYS-PROF-EXT-RULES "Meaning of paramter `Set` and `Unit`".
*
* @param[in]  Section        Section where to look for keyword or NULL if it does
*                            not matter.
* @param[in]  Group          Group where to look for keyword or NULL if it does
*                            not matter
* @param[in]  Set            Set where to look for keyword or NULL if it does
*                            not matter
* @param[in]  Unit           Unit where to look for keyword or NULL if it does
*                            not matter
* @param[in]  Keyword        Keyword to look for. Must not be NULL.
* @param[in]  Default        Default value to be returned if keyword is not found.
* @param[out] Value          Memory where to store value of the keyword to.
* @param[in]  StartLine      Line where to start to look for the keyword
* @param[in]  FileName       File where to search for the keyword or NULL
*                            to search in `mconfig.ini`.
*
* @retval  >=0              OK, Line number where the keyword is found
* @retval  #PF_E_PARM
* @retval  #PF_E_NOFILE
* @retval  #PF_E_FILEBIG
* @retval  #PF_E_FILEEMPTY
* @retval  #PF_E_NOSEC
* @retval  #PF_E_NOGRP
* @retval  #PF_E_NOKEY
* @retval  #PF_E_ENDFILE
* @retval  #PF_E_NOSET
* @retval  #PF_E_NOUNIT
* @retval  #PF_E_SHORTKEY
*******************************************************************************/
SINT32  pf_GetBoolExt(UINT8 * Section, UINT8 * Group, UINT8 * Set, UINT8 * Unit,
                      UINT8 * Keyword, BOOL8 Default, BOOL8 * Value, SINT32 StartLine,
                      UINT8 * FileName);

/**
********************************************************************************
* @brief Sets the given \p Value in the given \p Section and \p Group to the
*        specified configuration file.
*
* If there are spaces or tabs included in the assigned string, the string is
* automatically given inverted commas.
*
* For \p Section and \p Group set to NULL can be used as a placeholder. The \p Keyword
* must always have a value. The line number of the line where the \p Keyword was
* found, is returned after the successful search. In the case that the \p Keyword
* does not exist, an error code will be returned.
*
* The minimum length of the strings for \p Section, \p Group and \p Keyword is 3
* characters. There is no maximum length. The first 15 characters are
* significant, these must be unique.
*
* @param[in]  Section        Section where to write keyword or NULL if it does
*                            not matter.
* @param[in]  Group          Group where to look keyword or NULL if it does
*                            not matter
* @param[in]  Keyword        Keyword to write to. Must not be NULL.
*
* @param[in]  Value          NULL terminated string that contains the value to write.
* @param[in]  StartLine      Line where to start to look for the keyword
* @param[in]  FileName       File where to search for the keyword or NULL
*                            to search in `mconfig.ini`.
*
* @retval  >=0              OK, Line number where the keyword is found
* @retval  #PF_E_PARM
* @retval  #PF_E_NOFILE
* @retval  #PF_E_FILEBIG
* @retval  #PF_E_FILEEMPTY
* @retval  #PF_E_NOSEC
* @retval  #PF_E_NOGRP
* @retval  #PF_E_NOKEY
* @retval  #PF_E_ENDFILE
* @retval  #PF_E_SHORTKEY
*******************************************************************************/
SINT32  pf_SetStrg(UINT8 * Section, UINT8 * Group, UINT8 * Keyword,
                   UINT8 * Value, SINT32 StartLine, UINT8 * FileName);

/**
********************************************************************************
* @brief Sets the given \p Value in the given \p Section, \p Group, \p Set and \p Unit
*        to the specified configuration file.
*
* If there are spaces or tabs included in the assigned string, the string is
* automatically given inverted commas.
*
* For \p Section and \p Group set to NULL can be used as a placeholder. The \p Keyword
* must always have a value. The line number of the line where the \p Keyword was
* found, is returned after the successful search. In the case that the \p Keyword
* does not exist, an error code will be returned.
*
* The minimum length of the strings for \p Section, \p Group and \p Keyword is 3
* characters. There is no maximum length. The first 15 characters are
* significant, these must be unique.
*
* Compared to pf_SetStrg() two additional hierarchy levels are supported.
*
* @note There are special rules about how this function searches for keywords,
*       see \ref SYS-PROF-EXT-RULES "Meaning of paramter `Set` and `Unit`".
*
* @param[in]  Section        Section where to write keyword or NULL if it does
*                            not matter.
* @param[in]  Group          Group where to write keyword or NULL if it does
*                            not matter
* @param[in]  Set            Set where to write keyword or NULL if it does
*                            not matter
* @param[in]  Unit           Unit where to write keyword or NULL if it does
*                            not matter
* @param[in]  Keyword        Keyword to write to. Must not be NULL.
*
* @param[in]  Value          NULL terminated string that contains the value to write.
* @param[in]  StartLine      Line where to start to look for the keyword
* @param[in]  FileName       File where to search for the keyword or NULL
*                            to search in `mconfig.ini`.
*
* @retval  >=0              OK, Line number where the keyword is found
* @retval  #PF_E_PARM
* @retval  #PF_E_NOFILE
* @retval  #PF_E_FILEBIG
* @retval  #PF_E_FILEEMPTY
* @retval  #PF_E_NOSEC
* @retval  #PF_E_NOGRP
* @retval  #PF_E_NOKEY
* @retval  #PF_E_ENDFILE
* @retval  #PF_E_NOSET
* @retval  #PF_E_NOUNIT
* @retval  #PF_E_SHORTKEY
*******************************************************************************/
SINT32  pf_SetStrgExt(UINT8 * Section, UINT8 * Group, UINT8 * Set, UINT8 * Unit,
                      UINT8 * Keyword, UINT8 * Value, SINT32 StartLine, UINT8 * FileName);

/** @} end of SYS-PROF-API */

#ifdef __cplusplus
}
#endif

#endif
