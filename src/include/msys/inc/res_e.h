/**
 ********************************************************************************
 * @file     res_e.h
 * @author   Holl
 *
 * @brief This file contains all definitions and declarations exported by
 *        the Resource Manager for use by modules running on the same CPU.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011-2015
 *******************************************************************************/

#ifndef RES_E__H
#define RES_E__H

#ifdef __cplusplus
extern "C"
{
#endif

#include <msys.h>
#include <smi_e.h>

#include <res.h>
#include <res_acc_e.h>
#include <res_sec_e.h>
#include <res_fnc_e.h>

/**
 * @addtogroup RES-DEF
 * @{
 */

/**
 * @name Definitions for SVI-Function Table indexes
 * @{
 */
#define RES_SVI_GETVAL          0
#define RES_SVI_SETVAL          1
#define RES_SVI_GETVALLST       2
#define RES_SVI_SETVALLST       3
#define RES_SVI_GETBLK          4
#define RES_SVI_SETBLK          5
#define RES_SVI_GETBLKLST       6
#define RES_SVI_SETBLKLST       7
#define RES_SVI_GETADDR         8
#define RES_SVI_GETPVINF        9
#define RES_SVI_GETADDRINF      10
/** @} */

#define RES_MAX_INTERFACES 25           /**< Maximum number of interfaces */

/**
 * Enumeration of resource types
 */
typedef enum RES_LISTS
{
    RES_L_NONE = 0, /**< Unspecified resource */
    RES_L_LIB = 1,  /**< Library resource */
    RES_L_CFG = 2,  /**< Configuration resource */
    RES_L_END = 3,  /**< Unspecified resource */
} RES_LISTS;

/**
 * @brief Network interface list.
 */
typedef struct
{
    RES_NETIF Interfaces[RES_MAX_INTERFACES]; /**< List of network interfaces */
} RES_IFLST;


/** @} */

/**
 * @brief Structure for information about a SW module
 * @ingroup RES-RESOURCE
 */
typedef struct
{
    CHAR        TypeName[M_MODNAMELEN_A];/**< Module type ("HVC", "SPS") */
    CHAR        AppName[M_MODNAMELEN_A]; /**< Name of module instance */
    UINT32      AppIdx;                  /**< Index of module instance */
    UINT32      AppPart;                 /**< Memory partition module runs in */
    UINT32      MinVers;                 /**< Oldest supported RPC-Version */
    UINT32      MaxVers;                 /**< Newest supported RPC-Version */
    UINT32      MaxUser;                 /**< Maximum number of concurrent users */
    UINT32      Attr;                    /**< Attributes of module */
    UINT32      ModuleId;                /**< Module-Id as in VxWorks */
    UINT32      ActUser;                 /**< Number of concurrent users */
    UINT32      State;                   /**< Status of module */
    SMI_ID      *SmiId;                  /**< Id for SMI communication */
    UINT32      TaskId;                  /**< Id of parent task */
    UINT32      FirstUser;               /**< Index to 1st user */
    UINT32      Checksum;                /**< Checksum of module object */
    SYS_VERSION Version;                 /**< Version of module object */
    UINT32      Incarnation;             /**< Incarnation counter of library */
    UINT32      OwnTaskId;               /**< Own task Id */
} RES_MODUL;


/**
 * @brief Software resource parameter structure.
 * @ingroup RES-RESOURCE
 */
typedef struct
{
    UINT32  addAttributes;               /**< Additional attributes */
    UINT32  spare[7];                    /**< Reserved */
} RES_MODINSERT_PARM;

/**
 * @brief I/O data structure.
 * @ingroup RES-RESOURCE
 */
typedef struct
{
    UINT32 MaxUser; /**< Maximum number of concurrent users */
} RES_IODATA;

/**
 * @brief I/O channel information structure.
 * @ingroup RES-RESOURCE
 */
typedef struct
{
    UINT32      MaxUser;                /**< Maximum number of concurrent users */
    UINT32      ActUser;                /**< Number of concurrent users */
    UINT32      State;                  /**< State of I/O card */
    UINT32      FirstUser;              /**< Index to 1st user */
} RES_IOCHAN;

/**
 * @brief I/O card information structure.
 * @ingroup RES-RESOURCE
 */
typedef struct
{
    UINT32      CardNb;                 /**< Logical number of I/O module */
    UINT32      Type;                   /**< Type of I/O module */
    UINT32      Attr;                   /**< Attributes of I/O module */
    UINT32      State;                  /**< State of I/O card */
    VOID        *DrvId;                 /**< Pointer to MIO_DRV */
    UINT32      NbOfChan;               /**< Size of list below */
    /*lint --e(43) Ignore Lint error 'Error 43 Vacuous type for variable */
    RES_IOCHAN Chan[0]; /**< List with channel information */
} RES_IOCARD;

/**
 * @brief Information about a component-application
 * @ingroup RES-COMPONENT
 */
typedef struct
{
    CHAR        AppName[M_FILENAMELONGLEN_A];   /**< Name of component-application */
    LST_ID      *pComponentLstId;               /**< List of components corresponding to component-application */
} RES_COMPONENTAPP;

/**
 * @brief Information about a component.
 * @ingroup RES-COMPONENT
 */
typedef struct
{
    CHAR        CompName[M_MODNAMELEN_A]; /**< Name of component */
} RES_COMPONENT;

/**
 * @brief Progress identifier/handle.
 * @ingroup RES-PROGRESS
 */
typedef SINT32 RES_PID;

/**
 * @brief Get the name and the IP address of all available network interfaces.
 * @ingroup RES-API
 *
 * @param[out] pLst Pointer where to return network interfaces
 *
 * @return Number of interfaces
 */
UINT32 res_GetIfList(RES_IFLST *pLst);

/**
 * @brief Get the serial-number of a specified `Device`.
 * @ingroup RES-API
 *
 * @param[in]     Device  Device Name
 * @param[out]    Buff    Pointer to buffer where to copy the serial number into
 * @param[in,out] BuffLen Length of buffer
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_PARM    Invalid buffer, or buffer too small
 * @retval #RES_E_NOTSUPP Device not supported
 */
SINT32 res_GetSerialNumber(CHAR *Device, CHAR *Buff, UINT32 *BuffLen);

/**
 * @brief Set system state.
 * @ingroup RES-API
 *
 * This function sets the system state.
 *
 * @see \ref RES_S_ for possible system states.
 *
 * @param[in]  State  System state to set
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_FAILED \c State not valid
 */
SINT32 res_SetSysState(UINT32 State);

/**
 * @brief Get system state.
 * @ingroup RES-API
 *
 * @see \ref RES_S_ for possible system states.
 *
 * @return System state
 * @see res_SetSysState()
 */
UINT32 res_GetSysState(VOID);

/**
 * @brief Set application state.
 * @ingroup RES-API
 *
 * This function sets the application state.
 *
 * @see \ref RES_S_ for possible application states.
 *
 * @param[in]  State  Application state to set
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_FAILED \c State not valid
 */
SINT32 res_SetAppState(UINT32 State);

/**
 * @brief Get application state.
 * @ingroup RES-API
 *
 * @see \ref RES_S_ for possible application states.
 *
 * @return Application state
 * @see res_SetAppState()
 */
UINT32 res_GetAppState(VOID);

/**
 * @brief Get system application information.
 * @ingroup RES-API
 *
 * This function returns system application information.
 *  - application name
 *  - application state
 *  - system state
 *
 * The application name is directly read from <tt>MConfig.ini</tt>:
 * @code{.unparsed}
 * [SYSTEM]
 *   (Application)
 *       Name            = Application_1         ;is used to describe an application
 * @endcode
 *
 * @param[out]  pInfo Pointer where to store application information
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_FAILED  Error
 *
 * @see #RES_PROC_APPINFO
 */
UINT32 res_AppInfo(RES_APPINFO *pInfo);

/**
 * @brief Register new software module resource.
 * @ingroup RES-RESOURCE
 *
 * This function registers a new <b>Software module</b> resource. This function is a must for
 * all software modules offering their services to others using SMI or function pointers. For
 * application specific software modules (e.g. controllers) the function is accessed by the
 * system software.
 *
 * The instance name and the instance number are required to identify the module type. If the
 * instance number is \c -1, an instance number unique for this module type is automatically assigned.
 * The parameter `AppPart` specifies the memory partition where the software module runs in.
 *
 * The range of supported SMI protocol versions is defined via parameters `MinVers` and `MaxVers`. If
 * a module is at the start of its life cycle, it is likely that only one version exists. In this
 * case the parameters `MinVers` and `MaxVers` probably have the value 1. The version number
 * always starts at 1. If both values, `MinVers` and `MaxVers` are \c 0, no SMI is created. Use res_ModParam()
 * to assign the SMI protocol later in time.
 *
 * The parameter `MaxUser` specifies the maximum number of simultaneous users of the software module. If
 * <tt>MaxUser = RES_UNLIMITUSR</tt> is set, a unlimited number of users is possible.
 *
 * Additional attributes can be passed using `Attr`, whereby these will not be interpreted by the software module.
 * The parameter `ModuleId` is used to store the value that was returned by VxWorks after loading the software module,
 * which only makes sense with application specific software modules.
 *
 * @param[in]  pTypeName  Software module type name (e.g. "APP")
 * @param[in]  pAppName   Software module instance name (e.g. "APP1", "MY_APP", ...
 * @param[in]  AppIdx     Software module application index <br>
 *                        Use \c -1 to generate index automatically
 * @param[in]  AppPart    Application memory partition
 * @param[in]  MinVers    Minimum supported SMI protocol version
 *                        Use \c 0 to specify SMI protocol version later via res_ModParam()
 * @param[in]  MaxVers    Maximum supported SMI protocol version
 *                        Use \c 0 to specify SMI protocol version later via res_ModParam()
 * @param[in]  MaxUser    Maximum number of allowed concurrent users<br>
 *                        Use #RES_UNLIMITUSR for unlimited number of users
 * @param[in]  Attr       Software module attributes
 * @param[in]  ModuleId   Software module ID (VxWorks specific ID)
 * @param[out] pSmiId     Pointer where to return the SMI-ID
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_DUP Duplicate, software module already exists
 *
 * @see res_ModParam()
 */
SINT32 res_ModInsert(CHAR *pTypeName, CHAR *pAppName, UINT32 AppIdx, UINT32 AppPart, UINT32 MinVers, UINT32 MaxVers,
                     UINT32 MaxUser, UINT32 Attr, UINT32 ModuleId, SMI_ID **pSmiId);

/**
 * @brief Set software module parameters.
 * @ingroup RES-RESOURCE
 *
 * This function sets additional parameters for an already registered software module.
 * The modules SMI is created if not already done in res_ModInsert().
 *
 * @param[in]  AppName    Software module instance name
 * @param[in]  MinVers    Minimum supported SMI protocol version
 * @param[in]  MaxVers    Maximum supported SMI protocol version
 * @param[in]  MaxUser    Maximum number of allowed concurrent users<br>
 *                        Use #RES_UNLIMITUSR for unlimited number of users
 * @param[out] pSmiId     Pointer where to return the SMI-ID
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Software module not existing
 *
 * #### Example ####
 *
 * @code{.c}
SMI_ID *smiId = 0;
SINT32  ret;

ret = res_ModParam("APP1", 2, 2, RES_UNLIMITUSR, &SmiId);
@endcode
 *
 * @see res_ModInsert()
 */
SINT32 res_ModParam(CHAR *AppName, UINT32 MinVers, UINT32 MaxVers, UINT32 MaxUser, SMI_ID **pSmiId);

/**
 * @brief Deletes an existing software module.
 * @ingroup RES-RESOURCE
 *
 * This function deletes an existing software module and frees all allocated resources.
 *
 * @param[in]  pAppName Software module instance name
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Software module not existing
 */
SINT32 res_ModDelete(CHAR *pAppName);

/**
 * @brief Get module number.
 * @ingroup RES-RESOURCE
 *
 * This function determines the SMI module number for a given software module.
 * The module number is essential to send/receive SMI messages to/from the
 * software module.
 *
 * @param[in]  pAppName Software module instance name
 * @param[out] pModuleNb  Pointer where to return the SMI module number
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Software module not existing
 */
SINT32 res_GetModNb(CHAR *pAppName, UINT32 *pModuleNb);

/**
 * @brief Get module control block.
 * @ingroup RES-RESOURCE
 *
 * This function gets direct access to the module control block of the software module
 * specified by `pAppName`.
 *
 * @note
 * This function is intended to be used by system software only. Client
 * applications shall use res_ModInfo()/res_ModXInfo() to get module
 * information.
 *
 * @param[in]  pAppName Software module instance name
 * @param[out] pModInfo Pointer where to return module information (pointer)
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Software module not existing
 *
 * @see res_ModInfo()
 * @see res_ModXInfo()
 */
SINT32 res_GetModCb(const CHAR *pAppName, RES_MODUL **pModInfo);

/**
 * @brief Determines existence of a given software module/library.
 * @ingroup RES-RESOURCE
 *
 * This function checks if a software module exists and compares the version
 * information.
 *
 * @param[in]  pName      Name of software/library module
 * @param[in]  pVersCode  3-digit version number UINT32[3]
 * @param[in]  VersType   Version type (#M_VER_RELEASE, #M_VER_BETA or #M_VER_ALPHA)
 *
 * @retval  0   module/library exists, given version is used
 * @retval  1   module/library exists, but newer version as given is used
 * @retval -1   module/library exists, but older version as given is used
 * @retval -2   module/library not existing
 * @retval -3   unspecified error (e.g. error in loading library)
 */
SINT32 res_ModTest(CHAR *pName, UINT32 *pVersCode, UINT32 VersType);

/**
 * @brief Request module access (entry function).
 * @ingroup RES-RESOURCE
 *
 * This function is intended to be used by SMI clients to request explicit module
 * access. A usage counter on the given software module is incremented on each
 * res_ModAlloc() and decremented on res_ModFree(). If the usage counter
 * exceeds the maximum allowed limit #RES_E_FULL is returned. The maximum number
 * of allowed users is specified during module creation:
 * - res_ModInsert() or
 * - res_ModParam()
 *
 * On success, this function returns SMI information to access the requested
 * software module:
 *  - SMI module number (`pModuleNb`)
 *  - SMI-UDP port (`pPortNb`)
 *
 * @param[in]  pAppName    pAppName Software module instance name
 * @param[in]  IPAddr      Client IP address
 * @param[in]  ModuleNb    Client SMI module number
 * @param[out] pModuleNb   Pointer where to return the SMI module number
 * @param[out] pPortNb     Pointer where to return the SMI-UDP port
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Software module not existing
 * @retval #RES_E_FULL Module access not possible (maximum number of concurrent
 *         users reached)
 *
 * @see res_ModFree()
 */
SINT32 res_ModAlloc(CHAR *pAppName, UINT32 *pModuleNb, UINT16 *pPortNb, UINT32 IPAddr, UINT32 ModuleNb);

/**
 * @brief Release module access (exit function).
 * @ingroup RES-RESOURCE
 *
 * This function releases explicit module access, previously requested via
 * res_ModAlloc().
 *
 * @param[in]  pAppName   Software module instance name
 * @param[in]  IPAddr     Client IP address
 * @param[in]  ModuleNb   Client SMI module number
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Software module not existing
 *
 * @see res_ModAlloc()
 */
SINT32 res_ModFree(CHAR *pAppName, UINT32 IPAddr, UINT32 ModuleNb);

/**
 * @brief Get module information.
 * @ingroup RES-RESOURCE
 *
 * This function returns the module information for the software module specified
 * by `AppName`.
 *
 * @param[in]  AppName Software module instance name
 * @param[out] pInfo   Pointer where to copy module information to
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Software module not existing
 *
 * @see res_ModXInfo()
 */
SINT32 res_ModInfo(CHAR *AppName, RES_MODINFO *pInfo);

/**
 * @brief Get module information list.
 * @ingroup RES-RESOURCE
 *
 * This function returns the module information for all available software
 * modules. Memory to hold information for all software modules is allocated
 * and returned via `ppList`.
 *
 * @note
 * Client applications have to free the returned list using sys_MemFree() after
 * usage.
 *
 * @param[out] ppList   Pointer to allocated information list
 * @param[out] pListLen Pointer where to return the list length, number of
 *                      module information.
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_FAILED
 */
SINT32 res_ModInfoLst(RES_MODINFO **ppList, UINT32 *pListLen);

/**
 * @brief Get extended module information.
 * @ingroup RES-RESOURCE
 *
 * This function returns the module information for the software module specified
 * by `AppName`.
 *
 * @param[in]  AppName Software module instance name
 * @param[out] pInfo   Pointer where to copy module information to
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Software module not existing
 */
SINT32 res_ModXInfo(CHAR *AppName, RES_MODXINFO *pInfo);

/**
 * @brief Get extended module information list.
 * @ingroup RES-RESOURCE
 *
 * This function returns the extended module information for all available software
 * modules. Memory to hold information for all software modules is allocated
 * and returned via `ppList`.
 *
 * @note
 * Client applications have to free the returned list using sys_MemFree() after
 * usage.
 *
 * @param[out] ppList   Pointer to allocated information list
 * @param[out] pListLen Pointer where to return the list length, number of
 *                      module information.
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_FAILED
 */
SINT32 res_ModXInfoLst(RES_MODXINFO **ppList, UINT32 *pListLen);

/**
 * @brief Set module state.
 * @ingroup RES-RESOURCE
 *
 * This function shall be used by software modules to notify the RES handler about
 * module state changes. The new state is set directly for the given software
 * module, no other action is performed.
 *
 * Possible module states:
 * - #RES_S_ERROR
 * - #RES_S_RUN
 * - #RES_S_INIT
 * - #RES_S_DEINIT
 * - #RES_S_STOP
 *
 * @param[in]  AppName Software module instance name
 * @param[in]  State   Module state to set
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Software module not existing
 */
SINT32 res_ModState(CHAR *AppName, UINT32 State);

/**
 * @brief With this function information about each component-application can be determined.
 * @ingroup RES-COMPONENT
 *
 * @note The memory of each element of ppCompAppInfoLst has to be freed by the caller.
 *
 * @param[out] ppCompAppInfoLst   Pointer to list of information of each
 *                                component-application
 *
 * @retval     #RES_E_OK
 * @retval     #RES_E_FAILED    Information about one (or more) component-application
 *                              could not be determined
 */
SINT32 res_GetCompAppInfoLst(RES_COMPAPPINFO **ppCompAppInfoLst);

/**
 * @brief With this function information about each component within a component-application
 *        can be determined.
 * @ingroup RES-COMPONENT
 *
 * @note The memory of each element of ppCompInfoLst has to be freed by the caller.
 *
 * @param[in]  pCompAppName    Name of component-application. Information about
 *                             components of this component-application will be
 *                             determined
 * @param[out] ppCompInfoLst   Pointer to list of information about each component
 *
 * @retval     #RES_E_OK
 * @retval     #RES_E_FAILED    Information about one (or more) components could
 *                              not be determined
 */
SINT32 res_GetCompInfoLst(CHAR *pCompAppName, RES_COMPINFO **ppCompInfoLst);

/**
 * @brief This function returns the number of component-applications.
 * @ingroup RES-COMPONENT
 *
 * @returns  Number of component-applications.
 */
UINT32 res_GetNbOfCompApp(void);

/**
 * @brief This function returns the number of components within a component-application.
 * @ingroup RES-COMPONENT
 *
 * @param CompAppName  Name of component-application.
 *
 * @returns  Number of components within a component-application.
 */
UINT32 res_GetNbOfComp(CHAR *CompAppName);

/**
 * @brief Register new software library.
 * @ingroup RES-RESOURCE
 *
 * This function registers a new library resource at the RES handler.
 *
 * <b>Example usage:</b>
 * @code{.c}
UINT32  VersCode[3]
UINT32  VersType;

VersCode[0] = 1;      // Version V1.05 Beta
VersCode[1] = 5;
VersCode[2] = 0;
VersType = M_VER_BETA;

if (res_LibInsert("SPSLIB1", 0, VersCode, VersType))
{
  sys_Printf("Cannot register library!\n");
}
@endcode
 *
 * @param[in]  pName      Resource name
 * @param[in]  Attr       Resource attributes
 * @param[in]  pVersCode  Resource version code (<tt>UINT32[3]</tt>)
 * @param[in]  VersType   Resource version type
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_DUP Resource already registered
 *
 * @see res_LibDelete()
 * @see res_LibTest()
 */
SINT32 res_LibInsert(CHAR *pName, UINT32 Attr, UINT32 *pVersCode, UINT32 VersType);

/**
 * @brief Deletes a library resource from the resource list.
 * @ingroup RES-RESOURCE
 *
 * This function removes the library specified by `pName` and given version
 * information.
 *
 * @param[in]  pName      Resource name
 * @param[in]  pVersCode  Resource version code (<tt>UINT32[3]</tt>)
 * @param[in]  VersType   Resource version type
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Resource does not exist
 */
SINT32 res_LibDelete(CHAR *pName, UINT32 *pVersCode, UINT32 VersType);

/**
 * @brief Determines existence of a given library resource.
 * @ingroup RES-RESOURCE
 *
 * @note
 * If more then one library with the same name is loaded, only the last loaded
 * library will be resolved for version comparison.
 *
 * @param[in]  pName      Resource name
 * @param[in]  pVersCode  Resource version code (<tt>UINT32[3]</tt>)
 * @param[in]  VersType   Resource version type
 *
 * @retval  0  resource exists, given version is used
 * @retval  1  resource exists, but newer version as given is used
 * @retval -1  resource exists, but older version as given is used
 */
SINT32 res_LibTest(CHAR *pName, UINT32 *pVersCode, UINT32 VersType);

/**
 * @brief Register new configuration resource.
 * @ingroup RES-RESOURCE
 *
 * This function registers a new configuration resource at the RES handler.
 *
 * <b>Example usage:</b>
 * @code{.c}
UINT32  VersCode[3]
UINT32  VersType;

VersCode[0] = 1;      // Version V1.10 Release
VersCode[1] = 10;
VersCode[2] = 3;
VersType = M_VER_RELEASE;

if (res_CfgInsert("TIMECFG", 0, VersCode, VersType))
{
  sys_Printf("Cannot register configuration!\n");
}
@endcode
 *
 * @param[in]  pName      Resource name
 * @param[in]  Attr       Resource attributes
 * @param[in]  pVersCode  Resource version code (<tt>UINT32[3]</tt>)
 * @param[in]  VersType   Resource version type
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_DUP Resource already registered
 *
 * @see res_CfgDelete()
 * @see res_CfgTest()
 */
SINT32 res_CfgInsert(CHAR *pName, UINT32 Attr, UINT32 *pVersCode, UINT32 VersType);

/**
 * @brief Deletes a configuration resource from the resource list.
 * @ingroup RES-RESOURCE
 *
 * This function removes the configuration specified by `pName` and given version
 * information.
 *
 * @param[in]  pName      Resource name
 * @param[in]  pVersCode  Resource version code (<tt>UINT32[3]</tt>)
 * @param[in]  VersType   Resource version type
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Resource does not exist
 */
SINT32 res_CfgDelete(CHAR *pName, UINT32 *pVersCode, UINT32 VersType);

/**
 * @brief Determines existence of a given configuration resource.
 * @ingroup RES-RESOURCE
 *
 * @note
 * If more then one configuration with the same name is loaded, only the last loaded
 * configuration will be resolved for version comparison.
 *
 * @param[in]  pName      Resource name
 * @param[in]  pVersCode  Resource version code (<tt>UINT32[3]</tt>)
 * @param[in]  VersType   Resource version type
 *
 * @retval  0  resource exists, given version is used
 * @retval  1  resource exists, but newer version as given is used
 * @retval -1  resource exists, but older version as given is used
 */
SINT32 res_CfgTest(CHAR *pName, UINT32 *pVersCode, UINT32 VersType);

/**
 * @brief Get configuration resource information.
 * @ingroup RES-RESOURCE
 *
 * @param[in]  pName      Resource name
 * @param[out] pVersCode  Pointer where to return version code (<tt>UINT32[3]</tt>)
 * @param[out] pVersType  Pointer where to return version type
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
SINT32 res_CfgGetInfo(CHAR *pName, UINT32 *pVersCode, UINT32 *pVersType);

/**
 * @brief Request I/O channel access (entry function).
 * @ingroup RES-RESOURCE
 *
 * This function is intended to be used by SMI clients to request explicit I/O
 * access. A usage counter on the given `CardNb` is incremented on each
 * res_IoAlloc() and decremented on res_IoFree(). If the usage counter
 * exceeds the maximum allowed limit #RES_E_FULL is returned. The maximum number
 * of allowed users is specified during I/O registration:
 * - res_IoInsert()
 *
 * On success, this function returns I/O driver ID (`DrvId`) for further access.
 *
 * @param[in]  CardNb          Card number
 * @param[in]  FirstChan       First channel to access (1-n)
 * @param[in]  LastChan        Last channel to access (1-n)
 * @param[in]  IPAddr          Client IP address
 * @param[in]  ModuleNb        Client module number
 * @param[out] DrvId           Pointer to I/O driver ID
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME I/O resource not found
 * @retval #RES_E_FULL I/O access not possible (maximum number of concurrent
 *                     users reached)
 *
 * @see res_IoFree()
 */
SINT32 res_IoAlloc(UINT32 CardNb, UINT32 FirstChan, UINT32 LastChan,
                   VOID **DrvId, UINT32 IPAddr, UINT32 ModuleNb);

/**
 * @brief Release I/O channel access (exit function).
 * @ingroup RES-RESOURCE
 *
 * This function releases explicit I/O access, previously requested via
 * res_IoAlloc().
 *
 * @param[in]  CardNb          Card number
 * @param[in]  FirstChan       First channel to access (1-n)
 * @param[in]  LastChan        Last channel to access (1-n)
 * @param[in]  IPAddr          Client IP address
 * @param[in]  ModuleNb        Client module number
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME    Invalid channel number or invalid module number
 * @retval #RES_E_FAILED  Channel cannot be freed
 *
 * @see res_IoAlloc()
 */
SINT32 res_IoFree(UINT32 CardNb, UINT32 FirstChan, UINT32 LastChan, UINT32 IPAddr, UINT32 ModuleNb);

/**
 * @brief Get I/O information.
 * @ingroup RES-RESOURCE
 *
 * This function gets direct access to I/O information specified by `CardNb`.
 *
 * @note
 * This function is intended to be used by system software only.
 *
 * @param[in]  CardNb  Card number
 *
 * @return Pointer to #RES_IOCARD or \c NULL if I/O resource not found
 */
RES_IOCARD *res_IoGetInfo(UINT32 CardNb);

/**
 * @addtogroup RES-PROGRESS
 * @{
 */

/**
 * @brief Create new progress.
 * This routine creates a new progress.
 *
 * Possible options:
 *  - #RES_PROGRESS_OPT_CANCELABLE ... @copybrief #RES_PROGRESS_OPT_CANCELABLE
 *
 * @note Intended to be called by a progress source
 * @param[in] Timeout Timeout in seconds or 0 for default timeout [30s]
 * @param[in] Options Additional progress options
 * @param[in] TotalTask Number of total tasks (1, 2, 3 ... n)
 * @return Progress ID or 0 in case of error
 */
RES_PID res_ProgressAdd(UINT32 Timeout, UINT32 Options, UINT32 TotalTask);

/**
 * @brief Begin progress task.
 * This routine notifies the begin of a new task and sets the total amount of work for this task.
 *
 * @note Intended to be called by a progress source
 * @param[in] Pid Progress Id
 * @param[in] Task Task number (1, 2, 3 ... n)
 * @param[in] TotalWork Total number of work units for this task, use @c 0 if total amount of work is not available.
 *
 * @retval #RES_E_OK
 * @retval #RES_E_CANCELED if progress canceled by user
 * @retval #RES_E_FAILED
 * @see res_ProgressCancel()
 */
SINT32 res_ProgressBegin(RES_PID Pid, UINT32 Task, UINT32 TotalWork);

/**
 * @brief Update work units.
 * This routine notifies that a given number of work unit has been completed.
 *
 * @note Intended to be called by a progress source
 * @param[in] Pid Progress Id
 * @param[in] Work Work units completed for actual task
 *
 * @retval #RES_E_OK
 * @retval #RES_E_CANCELED if progress canceled by user
 * @retval #RES_E_FAILED
 *
 * @see res_ProgressCancel()
 */
SINT32 res_ProgressWorked(RES_PID Pid, UINT32 Work);

/**
 * @brief Finish progress.
 * This routine finishes a progress and stores the given @p result code.
 *
 * The progress status is set to #RES_PROGRESS_S_FINISHED.
 *
 * Use following result codes:
 *  - #M_E_OK if process successfully finished
 *  - #M_E_CANCELED if process has been canceled
 *  - result < 0 (error code) if process failed
 *
 * @note Intended to be called by a progress source
 * @param[in] Pid Progress Id
 * @param[in] Result The result/error code
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 */
SINT32 res_ProgressFinish(RES_PID Pid, SINT32 Result);

/**
 * @brief Cancel progress.
 * This routine notifies the progress source to cancel the operation.
 *
 * @note Intended to be called by a progress client
 * @param[in] Pid Progress Id to cancel
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 * @retval #RES_E_NOTSUPP Cancel not supported by progress
 */
SINT32 res_ProgressCancel(RES_PID Pid);

/**
 * @brief Get progress information.
 * This routine returns actual progress information and updates the timeout trigger.
 * If @p Progress == NULL, this routine can be used to check if a progress with given @p Pid exists.
 *
 * @note Intended to be called by a progress client
 * @param[in] Pid Progress Id
 * @param[out] Progress Pointer where to write actual progress information to
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED if @p Pid not valid
 */
SINT32 res_ProgressGet(RES_PID Pid, RES_PROGRESS *Progress);

/**
 * @brief Delete progress.
 * @param[in] Pid Progress Id to delete
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 */
SINT32 res_ProgressDel(RES_PID Pid);

/**
 * @brief Print progress information to @c stdout.
 * @param[in] Pid Progress Id or 0 to print all progresses.
 * @return #OK or #ERROR
 */
STATUS res_ProgressShow(RES_PID Pid);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* RES_E__H */
