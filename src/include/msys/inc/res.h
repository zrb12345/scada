/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     res.h
* @author   Diem
* @brief    Resource Manager
*           This file contains all definitions and declarations exported by
*           the Resource Manager, that could be used by modules running on
*           another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef RES__H
#define RES__H

#ifdef __cplusplus
extern "C" {
#endif


#include <mtypes.h>
#include <msys.h>
#include <mio.h>
#include <inf.h>
#include <res_user.h>

/**
 * @addtogroup RES-DEF
 * @{
 */
/**
 * @brief RPC protocol version
 *
 * History:
 *  - V1: Initial version
 *  - V2: Switch to 64-bit SVI
 *  - V3: SMI-TCP support
 */
#define RES_PROTVERS    3
#define RES_UNLIMITUSR  0xffffffff   /**< Unlimited number of users */
#define RES_MNAMELEN    20  /**< Max size of resource names without '\0' termination */
#define RES_MNAMELEN_A  ((RES_MNAMELEN + 1 + 3) & 0xfffffffc)    /**< #RES_MNAMELEN + '\0' + aligned */
#define RES_MAX_LOGINS  32  /**< Max number of user logins */
#define IF_NAME_LEN     8   /**< Length of the interface name */

/**
 * @name Defines for SMI/RPC access.
 * @{
 */

#define RES_PROGNB  (SMI_BASEMODUL | SMI_NOMODCHECK)     /**< @brief RPC PROG number to access RES module. */
#define RES_PORTNB  SMI_BASEPORT     /**< @brief RPC PORT number to access RES module. */
/** @} */

/**
 * @name Possible memory/device types
 * @{
 */

#define RES_MT_UNKNOWN  0   /**< Unknown device type */
#define RES_MT_DRAM     1   /**< DRAM memory (/ram) */
#define RES_MT_SRAM     2   /**< SRAM memory (/nvram) */
#define RES_MT_FLASH    3   /**< PC-Card or Flash memory (/pcc, /flash) */
#define RES_MT_HD       4   /**< Hard disk drive (/ide) */
#define RES_MT_FD       5   /**< Floppy disk drive (/fd) */
#define RES_MT_FTP_HOST 6   /**< FTP mount (HOST:) */
#define RES_MT_NFS_HOST 7   /**< NFS mount  (HOST:) */
#define RES_MT_CFCARD   8   /**< CFC device (/cfc) */
#define RES_MT_USBBLK   9   /**< USB bulk device  (/usbBulk) */
#define RES_MT_TCVOL    10  /**< TrueCrypt volume */
#define RES_MT_DUMMY    20  /**< Dummy device (/dummy) */
/** @} */

/**
 * @name Possible values for RES_FNCINFO.Options
 * @{
 */

#define RES_O_FPU   1       /**< Function-Interface uses FPU */
/** @} */

/**
 * @name Possible values for RES_MEMINFO_C.Org, RES_MEMINFOLST_C.Org
 * @{
 */

#define RES_MO_FILE 1       /**< File type */
#define RES_MO_MEM  2       /**< Memory type */
/** @} */

/**
 * @anchor RES_S_
 */
/**
 * @name Possible states
 * @{
 */

#define RES_S_RUN       1   /**< Resource is OK and runs */
#define RES_S_ERROR     2   /**< Resource is in error */
#define RES_S_STOP      3   /**< Resource has been stopped */
#define RES_S_INIT      4   /**< Resource is being initialized */
#define RES_S_DEINIT    5   /**< Resource has been un-installed */
#define RES_S_EOI       6   /**< Resource waits for #SMI_PROC_ENDOFINIT */
#define RES_S_RESET     7   /**< Resource is in reset state */
#define RES_S_WARNING   8   /**< Resource is in warning state */
/** @} */

/**
 * @anchor RES_EXT_PING
 */
/**
 * @name Extended ping definitions
 * @{
 */

#define RES_FT_EQU          1    /**< Test for equal */
#define RES_FT_NOTEQU       2    /**< Test for not equal */
#define RES_RT_AUTO         1    /**< Reply depending on conformity */
#define RES_RT_IP           2    /**< Reply with particular IP-Address */
#define RES_RT_BROADCAST    3    /**< Reply with Broadcast */
#define RES_RM_NORMAL       0    /**< Reply #RES_EXTPING_R */
#define RES_RM_ALLAPP       1    /**< Reply #RES_EXTPING2_R */
#define RES_RM_PLCAPP       2    /**< Reply #RES_EXTPING2_R */
/** @} */

/**
 * @anchor RES_OS_
 */
/**
 * @name OS definitions
 * @{
 */

#define RES_OS_VXWORKS  0   /**< Operating system is VxWorks */
#define RES_OS_LINUX    1   /**< Operating system is Linux */
#define RES_OS_WINDOWS  2   /**< Operating system is Windows */
/** @} */

/**
 * @name Callback definitions
 * @{
 */

#define RES_CB_EHD  0x0001  /**< Remove EHD callback only */
#define RES_CB_VHD  0x0002  /**< Remove VHD callback only */
#define RES_CB_DBG  0x0004  /**< Remove DBG callback only */
#define RES_CB_ALL  0xFFFF  /**< Remove all callbacks */
/** @} */
/**
 * @brief Possible task states
 */
typedef enum
{
    RES_TS_RUNNING      = 1,    /**< Task is running */
    RES_TS_NOTRUNNING   = 2,    /**< Task is not running */
    RES_TS_INITIALIZING = 3,    /**< Task is in suspended-inactive state */
} RES_TS;


/**
 * @name License key types
 * @{
 */

#define RES_KEY_CFCSERIAL       0x01     /**< CFC serial number */
#define RES_KEY_CPUSERIAL       0x02     /**< CPU serial number */
#define RES_KEY_USBFLASHSERIAL  0x04     /**< USB flash serial number */
#define RES_KEY_USB             0x08     /**< USB stick serial number */
#define RES_KEY_VERSION         0x10     /**< Check module version */
#define RES_KEY_DEADLINE        0x20     /**< Check deadline */
/** @} */

/**
 * @name Defines for progress
 * @{
 */

#define RES_PROGRESS_S_IDLE         0    /**< Progress initial state */
#define RES_PROGRESS_S_RUNNING      1    /**< Progress is currently running */
#define RES_PROGRESS_S_CANCEL       2    /**< Progress cancelled but not yet acknowledged by progress source */
#define RES_PROGRESS_S_FINISHED     3    /**< Progress is finished */
#define RES_PROGRESS_OPT_CANCELABLE 0x02     /**< Progress can be cancelled by user */
/** @} */

/**
 * @name Defines for encryption
 * @{
 */

#define RES_CRYPT_FILENAMELEN       256  /**< Max filename length incl '\\0' */
#define RES_CRYPT_PASSWORDLEN       32   /**< Max password length incl '\\0' */
#define RES_CRYPT_DEVICENAMELEN     20   /**< Max device name length incl '\\0' */
#define RES_CRYPT_ALGORITHMNAMELEN  16   /**< Max algorithm name length incl '\\0' */
#define RES_CRYPT_MK_PASSWORDLEN    256  /**< Max password length incl '\\0' */
#define RES_CRYPT_VAULT_KEYLEN      64   /**< Max vault key ID length incl '\\0' */
#define RES_CRYPT_VAULT_SECLEN      256  /**< Max vault secret length incl '\\0' */
#define RES_CRYPT_TC_PASSWORDLEN    256  /**< Max password length for encrypted volume image incl '\\0' */
#define RES_CRYPT_TC_ALGNAMELEN     32   /**< Max algorithm name for encrypted volume image length incl '\\0' */
#define RES_CRYPT_TC_OPT_QUIET      0x01     /**< Quite mode (don't produce any output) */
#define RES_CRYPT_TC_OPT_CONTIG     0x02     /**< Create contiguous volume file */
/** @} */

/**
 * @name Error codes
 * @{
 */

#define RES_E_OK            M_E_OK   /**< @copybrief #M_E_OK */
#define RES_E_INPROGRESS    M_E_INPROGRESS   /**< @copybrief #M_E_INPROGRESS */
#define RES_E_CANCELED      M_E_CANCELED     /**< @copybrief #M_E_CANCELED */
#define RES_E_FAILED        (M_ES_RES | M_E_FAILED)  /**< @copybrief #M_E_FAILED */
#define RES_E_NAME          (M_ES_RES | M_E_BADNAME)     /**< @copybrief #M_E_BADNAME */
#define RES_E_FULL          (M_ES_RES | M_E_FULL)    /**< @copybrief #M_E_FULL */
#define RES_E_DUP           (M_ES_RES | M_E_DUPRES)  /**< @copybrief #M_E_DUPRES */
#define RES_E_NOLIC         (M_ES_RES | M_E_NOLIC)   /**< @copybrief #M_E_NOLIC */
#define RES_E_NOTSUPP       (M_ES_RES | M_E_NOTSUPP)     /**< @copybrief #M_E_NOTSUPP */
#define RES_E_BADARGS       (M_ES_RES | M_E_BADARGS)     /**< @copybrief #M_E_BADARGS */
#define RES_E_BADAUTH       (M_ES_RES | M_E_BADAUTH)     /**< @copybrief #M_E_BADAUTH */
#define RES_E_BADLOGIN      (M_ES_RES | M_E_BADLOGIN)    /**< @copybrief #M_E_BADLOGIN */
#define RES_E_BADSESS       (M_ES_RES | M_E_BADSESS)     /**< @copybrief #M_E_BADSESS */
#define RES_E_BADUSER       (M_ES_RES | M_E_BADUSER)     /**< @copybrief #M_E_BADUSER */
#define RES_E_NOPWORD       (M_ES_RES | M_E_NOPWORD)     /**< @copybrief #M_E_NOPWORD */
#define RES_E_BADPWORD      (M_ES_RES | M_E_BADPWORD)    /**< @copybrief #M_E_BADPWORD */
#define RES_E_BADTIME       (M_ES_RES | M_E_BADTIME)     /**< @copybrief #M_E_BADTIME */
#define RES_E_NOMEM         (M_ES_RES | M_E_NOMEM)   /**< @copybrief #M_E_NOMEM */
#define RES_E_NOMOD1        (M_ES_RES | M_E_NOMOD1)  /**< @copybrief #M_E_NOMOD1 */
#define RES_E_NOWRITE       (M_ES_RES | M_E_NOWRITE)     /**< @copybrief #M_E_NOWRITE */
#define RES_E_TIMEOUT2      (M_ES_RES | M_E_TIMEOUT2)    /**< @copybrief #M_E_TIMEOUT2 */
#define RES_E_PARM          (M_ES_RES | M_E_PARM)    /**< @copybrief #M_E_PARM */
#define RES_E_ACCDENIED     (M_ES_RES | M_E_ACCDENIED)   /**< @copybrief #M_E_ACCDENIED */
#define RES_E_BADINDEX      (M_ES_RES | M_E_BADINDEX)    /**< @copybrief #M_E_BADINDEX */
#define RES_E_BADNAME       (M_ES_RES | M_E_BADNAME)     /**< @copybrief #M_E_BADNAME */
/** @} */

/**
 * @name Module attributes
 * @{
 */

#define RES_SYS_ATTRIB          0x00000000   /**< Module is part of MSys */
#define RES_VXW_ATTRIB          0x00000001   /**< Module is a VxWorks object */
#define RES_LIB_ATTRIB          0x00000002   /**< Module is a library */
#define RES_PLC_ATTRIB          0x00000004   /**< Module is a PLC program */
#define RES_JAVA_ATTRIB         0x00000008   /**< Module is a Java program - deprecated since MSys V4.00R */
#define RES_REENT_ATTR          0x00000010   /**< Module is reentrant */
#define RES_NOCONF_ATTR         0x00000020   /**< Online configuration not allowed */
#define RES_NOINST_ATTR         0x00000040   /**< Online installation not allowed */
#define RES_NODINST_ATTR        0x00000080   /**< Online uninstall not allowed */
#define RES_ERRTOL_ATTR         0x00000100   /**< Load module on boot error */
#define RES_RETAIN_ATTR         0x00000200   /**< Retain variables in use */
#define RES_NZERORTN_ATTR       0x00000400   /**< No set to zero if inconsistent */
#define RES_DEBUGCODE_ATTR      0x00000800   /**< Debug code, extra instructions */
#define RES_DEBUGINFO_ATTR      0x00001000   /**< Debug information included */
#define RES_NOAINST_ATTR        0x00002000   /**< No installation at boot time */
#define RES_SYSTEM_ATTR         0x00004000   /**< Module is part of system */
#define RES_JAVACL_ATTR         0x00008000   /**< Module has own Java Class Loader - deprecated since MSys V4.00R */
#define RES_SRV_ATTRIB          0x00010000   /**< Module is a service program */
#define RES_SRVMIO_ATTRIB       0x00020000   /**< Module has a second cru for card configuration */
#define RES_REDU_ATTRIB         0x00040000   /**< Module is a redundant application */
#define RES_COMPONENT_ATTRIB    0x00080000   /**< Module is a component */
/** @} */
/** @} */

/**
 * @addtogroup RES-SMI
 * @{
 */

/**
 * @name SMI Commands
 * @{
 */

/**
 * @brief Get information about one module resource.
 *
 * This SMI call returns standard information about the software module specified
 * by #RES_MODINFO_C.AppName.
 *
 * @param[in]  #RES_MODINFO_C
 * @param[out] #RES_MODINFO_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Invalid module identification
 *
 * @see #RES_MODINFO
 */
#define RES_PROC_MODINFO                    104
/**
 * @brief Get information about all module resources.
 *
 * This SMI call returns information about all software modules as a list. The
 * list is sorted chronologically (by creation time).
 *
 * @note
 * Due to SMI reply size limitations, clients may need to iterate the list per index:
 *  - #RES_MODINFOLST_C.FirstIdx
 *  - #RES_MODINFOLST_C.LastIdx
 *
 * Use <tt>LastIdx = -1</tt> to request as many elements as possible.
 *
 * @param[in]  #RES_MODINFOLST_C
 * @param[out] #RES_MODINFOLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #RES_MODINFO
 */
#define RES_PROC_MODINFOLST                 106
/**
 * @brief Request module access (entry function).
 *
 * @param[in]  #RES_MODALLOC_C
 * @param[out] #RES_MODALLOC_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see res_ModAlloc()
 */
#define RES_PROC_MODALLOC                   108
/**
 * @brief Release module access (exit function).
 *
 * This SMI call releases explicit module access, previously requested via
 * #RES_PROC_MODALLOC.
 *
 * @param[in]  #RES_MODFREE_C
 * @param[out] #RES_MODFREE_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see res_ModFree()
 */
#define RES_PROC_MODFREE                    110
/**
 * @brief Get module number.
 *
 * This SMI call gets the module number and UDP/TCP ports for specified #RES_MODNB_C.AppName, to
 * communicate with. The module number corresponds to the program number in the SMI/RPC header.
 *
 * @param[in]  #RES_MODNB_C
 * @param[out] #RES_MODNB_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME
 */
#define RES_PROC_MODNB                      112
/**
 * @brief Get user list of module
 * @deprecated Obsolete SMI call (maybe removed in future versions)
 */
#define RES_PROC_MODUSER                    114
/**
 * @brief Get extended information about one module.
 *
 * This SMI call returns extended information about the software module specified
 * by #RES_MODXINFO_C.AppName.
 *
 * @param[in]  #RES_MODXINFO_C
 * @param[out] #RES_MODXINFO_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Invalid module identification
 *
 * @see #RES_MODXINFO
 */
#define RES_PROC_MODXINFO                   116
/**
 * @brief Get extended information about all modules.
 *
 * This SMI call returns extended information about all software modules as a list. The
 * list is sorted chronologically (by creation time).
 *
 * @note
 * Due to SMI reply size limitations, clients may need to iterate the list per index:
 *  - #RES_MODXINFOLST_C.FirstIdx
 *  - #RES_MODXINFOLST_C.LastIdx
 *
 * Use <tt>LastIdx = -1</tt> to request as many elements as possible.
 *
 * @param[in]  #RES_MODXINFOLST_C
 * @param[out] #RES_MODXINFOLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #RES_MODXINFO
 */
#define RES_PROC_MODXINFOLST                118
/**
 * @brief Get list of child tasks.
 *
 * This SMI call returns a list of child tasks for a given parent task, specified by
 * #RES_MODCHILDLST_C.ParentTaskId.
 *
 * @param[in]  #RES_MODCHILDLST_C
 * @param[out] #RES_MODCHILDLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #RES_MODTASKINFO
 */
#define RES_PROC_MODCHILDLST                120
/**
 * @brief Get list of tasks of a module.
 *
 * This SMI call returns a list of tasks for a given software module, specified by
 * #RES_MODTASKLST_C.AppName.
 *
 * @param[in]  #RES_MODTASKLST_C
 * @param[out] #RES_MODTASKLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #RES_MODTASKINFO
 */
#define RES_PROC_MODTASKLST                 122
/**
 * @brief Get information about memory/storage device <b>(deprecated)</b>
 *
 * This SMI call gets memory information about a given memory/storage device.
 *
 * @param[in]  #RES_MEMINFO_C
 * @param[out] #RES_MEMINFO_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #RES_MEMINFO
 * @deprecated Use #RES_PROC_MEMINFO64 instead
 */
#define RES_PROC_MEMINFO                    144
/**
 * @brief Get information about all memory/storage devices <b>(deprecated)</b>
 *
 * This SMI call gets memory information about a all memory/storage devices.
 *
 * @note
 * Due to SMI reply size limitations, clients may need to iterate the list per index:
 *  - #RES_MEMINFOLST_C.FirstIdx
 *  - #RES_MEMINFOLST_C.LastIdx
 *
 * Use <tt>LastIdx = -1</tt> to request as many elements as possible.
 *
 * @param[in]  #RES_MEMINFOLST_C
 * @param[out] #RES_MEMINFOLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #RES_MEMINFO64
 * @deprecated Use #RES_PROC_MEMINFOLST64 instead
 */
#define RES_PROC_MEMINFOLST                 146
/**
 * @brief Get information about memory/storage device (64-bit version).
 *
 * This SMI call gets memory information about a given memory/storage device.
 *
 * @param[in]  #RES_MEMINFO64_C
 * @param[out] #RES_MEMINFO64_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #RES_MEMINFO64
 */
#define RES_PROC_MEMINFO64                  148
/**
 * @brief Get information about all memory/storage devices (64-bit version).
 *
 * This SMI call gets memory information about all memory/storage devices.
 *
 * @note
 * Due to SMI reply size limitations, clients may need to iterate the list per index:
 *  - #RES_MEMINFOLST64_C.FirstIdx
 *  - #RES_MEMINFOLST64_C.LastIdx
 *
 * Use <tt>LastIdx = -1</tt> to request as many elements as possible.
 *
 * @param[in]  #RES_MEMINFOLST64_C
 * @param[out] #RES_MEMINFOLST64_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #RES_MEMINFO64
 */
#define RES_PROC_MEMINFOLST64               150
/**
 * @brief Get I/O resource information.
 *
 * This SMI call returns resource information about a given I/O card and channel
 * number.
 *
 * @param[in]  #RES_IOCDINFO_C
 * @param[out] #RES_IOCDINFO_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Invalid resource identification
 */
#define RES_PROC_IOCDINFO                   184
/**
 * @brief Get I/O resource information (list).
 *
 * This SMI call queries resource information about all available I/O channels.
 *
 * @note
 * Due to SMI reply size limitations, clients may need to iterate the list per index:
 *  - #RES_IOCDINFOLST_C.FirstIdx
 *  - #RES_IOCDINFOLST_C.LastIdx
 *
 * Use <tt>LastIdx = -1</tt> to request as many elements as possible.
 *
 * @param[in]  #RES_IOCDINFOLST_C
 * @param[out] #RES_IOCDINFOLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Invalid data range
 */
#define RES_PROC_IOCDINFOLST                186
/**
 * @brief Get I/O channel information.
 *
 * This SMI call returns state information about a given I/O card and channel
 * number.
 *
 * @param[in]  #RES_IOCHINFO_C
 * @param[out] #RES_IOCHINFO_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Invalid module identification
 */
#define RES_PROC_IOCHINFO                   188
/**
 * @brief Get I/O channel information (list).
 *
 * This SMI call queries state information about all available I/O channels.
 *
 * @note
 * Due to SMI reply size limitations, clients may need to iterate the list per index:
 *  - #RES_IOCHINFOLST_C.FirstIdx
 *  - #RES_IOCHINFOLST_C.LastIdx
 *
 * Use <tt>LastIdx = -1</tt> to request as many elements as possible.
 *
 * @param[in]  #RES_IOCHINFOLST_C
 * @param[out] #RES_IOCHINFOLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Invalid data range
 */
#define RES_PROC_IOCHINFOLST                190
/**
 * @brief Request I/0 channel access (entry function).
 *
 * @param[in]  #RES_IOALLOC_C
 * @param[out] #RES_IOALLOC_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @see res_IoAlloc()
 */
#define RES_PROC_IOALLOC                    192
/**
 * @brief Release I/O channel access (exit function).
 *
 * This SMI function releases explicit I/O access, previously requested via
 * #RES_PROC_IOALLOC.
 *
 * @param[in]  #RES_IOFREE_C
 * @param[out] #RES_IOFREE_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @see res_IoFree()
 */
#define RES_PROC_IOFREE                     194
/**
 * @brief Get user list of I/O resource
 * @todo KLFA Add detailed description.
 *
 * @param[in]  #RES_IOUSER_C
 * @param[out] #RES_IOUSER_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_IOUSER                     196
/**
 * @brief Get information about one library resource.
 *
 * This SMI call queries information about a library resource, specified by
 * #RES_LIBINFO_C.Name and version attributes.
 *
 * @param[in]  #RES_LIBINFO_C
 * @param[out] #RES_LIBINFO_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Library does not exist
 */
#define RES_PROC_LIBINFO                    224
/**
 * @brief Get information about all library resources.
 *
 * This SMI call queries information about all available library resources.
 *
 * @note
 * Due to SMI reply size limitations, clients may need to iterate the list per index:
 *  - #RES_LIBINFOLST_C.FirstIdx
 *  - #RES_LIBINFOLST_C.LastIdx
 *
 * Use <tt>LastIdx = -1</tt> to request as many elements as possible.
 *
 * @param[in]  #RES_LIBINFOLST_C
 * @param[out] #RES_LIBINFOLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Invalid data range
 */
#define RES_PROC_LIBINFOLST                 226
/**
 * @brief Check license key.
 *
 * This SMI call performs a license key check for a given software module.
 *
 * @param[in]  #RES_KEYCHECK_C
 * @param[out] #RES_KEYCHECK_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_KEYCHECK                   250
/**
 * @brief Get license key list.
 *
 * This SMI call gets the list of license keys. In addition to the license data,
 * information about whether the license is valid or not is returned.
 *
 * @note
 * Due to SMI reply size limitations, clients may need to iterate the list per index:
 *  - #RES_GETKEYLST_C.FirstIdx
 *  - #RES_GETKEYLST_C.LastIdx
 *
 * Use <tt>LastIdx = -1</tt> to request as many elements as possible. The range starts with index 1.
 *
 * @param[in]  #RES_GETKEYLST_C
 * @param[out] #RES_GETKEYLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #RES_KEYINFO
 */
#define RES_PROC_GETKEYLST                  252
/**
 * @brief Get application information.
 *
 * This SMI call returns system application information:
 * - application name
 * - application state
 * - system state
 *
 * @param[in]  #RES_APPINFO_C
 * @param[out] #RES_APPINFO_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #res_AppInfo()
 */
#define RES_PROC_APPINFO                    280
/**
 * @brief Get system information.
 *
 * This SMI call requests general system and login information, such as:
 * - CPU Hex switch value
 * - Restart counter
 * - Security level
 * - Date and time zone information
 * - etc.
 *
 * @param[in]  #RES_SYSINFO_C
 * @param[out] #RES_SYSINFO_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_SYSINFO                    282
/**
 * @brief Login user.
 *
 * This SMI call logs-in a user (specified by username + password) at the M1
 * controller. This call supports additional information about the client
 * software to be sent to the M1 controller:
 *  - tool name
 *  - tool main + sub version
 *
 * The password must either be sent as plain text or as binary MD5 hash, depending on
 * security settings.
 * - On security level 0 no login is required
 * - Use plain text password if the security level is 1 or a login checker module is installed.
 * - All other settings (security level > 1) require password as binary MD5 hash.
 *
 * If the login could be processed successfully - security information and
 * authentication data for all following SMI calls is returned:
 *  - Security level
 *  - User permissions
 *  - Opaque SMI/RPC authentication information (up to 128 bytes)
 *
 * @param[in]  #RES_LOGIN_C
 * @param[out] #RES_LOGIN_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_FAILED
 * @retval #RES_E_BADLOGIN Login rejected
 * @retval #RES_E_BADUSER  Login rejected (invalid username) <br>
 *                         Return value only exists if "Login Debug Mode" is set!
 * @retval #RES_E_BADPWORD Login rejected (invalid password) <br>
 *                         Return value only exists if "Login Debug Mode" is set!
 * @retval #RES_E_BADTIME  Login rejected (invalid time frame) <br>
 *                         Return value only exists if "Login Debug Mode" is set!
 *
 * @see #RES_PROC_LOGOUT
 * @deprecated Use #RES_PROC_LOGIN2 instead
 */
#define RES_PROC_LOGIN                      284
/**
 * @brief Logout user.
 *
 * @param[in]  #RES_LOGOUT_C
 * @param[out] #RES_LOGOUT_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_BADSESS Invalid user session
 */
#define RES_PROC_LOGOUT                     286
/**
 * @brief Notification for "client has rebooted" event.
 *
 * This SMI call can be used by any client to inform the M1 controller that the
 * client has rebooted. The M1 controller may remove all callbacks for this
 * particular client, indicated by the IP address.
 *
 * If the IP address is \c 0xFFFFFFFF and IP protocol is \c UDP, the IP
 * address from the actual transaction is used.
 *
 * @param[in]  #RES_CLNTREBOOT_C
 * @param[out] #RES_CLNTREBOOT_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_CLNTREBOOT                 288
/**
 * @brief  Extended login to M1 <b>(deprecated)</b>.
 * @deprecated This login function is not supported anymore and deactivated since MSys V4.0.
 *             Use standard login function #RES_PROC_LOGIN2 instead.
 */
#define RES_PROC_XLOGIN                     290
/**
 * @brief  Extended logout from M1 <b>(deprecated)</b>.
 * @deprecated This logout function is not supported anymore and deactivated since MSys V4.0.
 *             Use standard login function #RES_PROC_LOGOUT instead.
 */
#define RES_PROC_XLOGOUT                    292
/**
 * @brief Remove user.
 *
 * @param[in]  #RES_REMUSER_C
 * @param[out] #RES_REMUSER_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_REMUSER                    294
/**
 * @brief Request SVI write-access token.
 *
 * This SMI call requests exclusive access to the M1 controller. "AccessControl" must be
 * enabled on the M1 controller to use this SMI call.
 *
 * @param[in]  #RES_REQUESTACC_C
 * @param[out] #RES_REQUESTACC_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_FAILED    The function could not be executed properly,
 *                          or access control is deactivated.
 * @retval #RES_E_BADSESS   Invalid user session
 * @retval #RES_E_ACCDENIED Access denied
 * @retval #RES_E_NOMEM
 * @retval #RES_E_NOMOD1    Access control module not loaded
 * @retval #RES_E_TIMEOUT2  Access control module timeout on receive
 */
#define RES_PROC_REQUESTACC                 296
/**
 * @brief Release SVI write-access token.
 *
 * This SMI call releases exclusive access from the M1 controller. "AccessControl" must be
 * enabled on the M1 controller to use this SMI call.
 *
 * @param[in]  #RES_RELEASEACC_C
 * @param[out] #RES_RELEASEACC_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_FAILED    The function could not be executed properly,
 *                          or access control is deactivated.
 * @retval #RES_E_BADSESS   Invalid user session
 * @retval #RES_E_ACCDENIED Access denied
 * @retval #RES_E_NOMEM
 * @retval #RES_E_NOMOD1    Access control module not loaded
 * @retval #RES_E_TIMEOUT2  Access control module timeout on receive
 */
#define RES_PROC_RELEASEACC                 298
/**
 * @brief Get user data.
 *
 * This SMI calls requests user data/information about the actual client session.
 *
 * @param[in]  #RES_GETUSERDATA_C
 * @param[out] #RES_GETUSERDATA_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_BADSESS
 */
#define RES_PROC_GETUSERDATA                300
/**
 * @brief Get user-data list of all users logged in.
 *
 * This SMI call requests all user data/information about all actually logged in client
 * sessions.
 *
 * @note
 * Due to SMI reply size limitations, clients may need to iterate the list per index:
 *  - #RES_GETUSERDATALST_C.FirstIdx
 *  - #RES_GETUSERDATALST_C.LastIdx
 *
 * Use <tt>LastIdx = -1</tt> to request as many elements as possible.
 *
 * @param[in]  #RES_GETUSERDATALST_C
 * @param[out] #RES_GETUSERDATALST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_GETUSERDATALST             302
/**
 * @brief Login user.
 *
 * This SMI call logs-in a user (specified by username + password) at the M1
 * controller. This call supports additional information about the client
 * software to be sent to the M1 controller:
 *  - tool name
 *  - tool main + sub version
 *
 * The password must either be sent as plain text or as binary MD5 hash, depending on
 * security settings.
 * - On security level 0 no login is required
 * - Use plain text password if the security level is 1 or a login checker module is installed.
 * - All other settings (security level > 1) require password as binary MD5 hash.
 *
 * If the login could be processed successfully - security information and
 * authentication data for all following SMI calls is returned:
 *  - Security level
 *  - User permissions
 *  - Opaque SMI/RPC authentication information (up to 128 bytes)
 *
 * @param[in]  #RES_LOGIN2_C
 * @param[out] #RES_LOGIN2_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_FAILED
 * @retval #RES_E_BADLOGIN Login rejected
 * @retval #RES_E_BADUSER  Login rejected (invalid username) <br>
 *                         Return value only exists if "Login Debug Mode" is set!
 * @retval #RES_E_BADPWORD Login rejected (invalid password) <br>
 *                         Return value only exists if "Login Debug Mode" is set!
 * @retval #RES_E_BADTIME  Login rejected (invalid time frame) <br>
 *                         Return value only exists if "Login Debug Mode" is set!
 */
#define RES_PROC_LOGIN2                     304
/**
 * @brief Open SMI connection.
 *
 * This SMI call opens an explicit communication session to the M1 controller to
 * negotiate connection specific parameters:
 * - Session timeout [s]
 * - Session life time [s]
 * - Max. size of SMI data packages<br>
 *   Relevant for all following SMI calls/replies
 *
 * This call can be used on all security levels 0 - 4, the suggested call sequence is:
 * 1. #RES_PROC_OPEN
 * 2. #RES_PROC_LOGIN / #RES_PROC_LOGIN2
 * 3. Any other SMI call
 * 4. #RES_PROC_LOGOUT
 * 5. #RES_PROC_CLOSE
 *
 * If successful, authentication data to be used for all following SMI calls
 * is returned:
 *  - Opaque SMI/RPC authentication data (up to 128 bytes)
 *
 * @note
 * For "old" clients which do not know #RES_PROC_OPEN, an implicit connection session
 * is automatically created by the RES handler on login (and closed on logout).
 *
 * @param[in]  #RES_OPEN_C
 * @param[out] #RES_OPEN_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #RES_PROC_CLOSE
 * @see #RES_PROC_RENEW
 * @since MSys V3.95
 */
#define RES_PROC_OPEN                       306
/**
 * @brief Close SMI connection.
 *
 * This SMI call closes a previously opened connection session.
 *
 * @note
 * A potentially logged in user is logged out automatically.
 *
 * @param[in]  #RES_CLOSE_C
 * @param[out] #RES_CLOSE_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #RES_PROC_OPEN
 * @since MSys V3.95
 */
#define RES_PROC_CLOSE                      308
/**
 * @brief Reset SMI connection.
 *
 * This SMI call renews an established connection, created via #RES_PROC_OPEN to avoid
 * "Replay attacks" on unencrypted communication channels (SMI-UDP, SMI-TCP, SMI-QSOAP).
 * Depending on negotiated connection parameters (Session lifetime), periodic #RES_PROC_RENEW calls
 * must be sent from the client to the M1 controller. As recommendation, clients shall use
 * 75% of the session life time [s] as interval time.
 *
 * On each #RES_PROC_RENEW, a new randomly generated authentication token for SMI/RPC calls
 * is generated:
 *  - Opaque SMI/RPC authentication data (up to 128 bytes)
 *
 * Additionally application- and system-state information is returned in the reply. Thus this SMI call
 * can easily be used as replacement for #INF_PROC_ALIVE.
 *
 * @param[in]  #RES_RENEW_C
 * @param[out] #RES_RENEW_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #RES_PROC_OPEN
 * @since MSys V3.95
 */
#define RES_PROC_RENEW                      310
/**
 * @brief Get SMI connection information.
 *
 * This SMI call determines connection specific information:
 *  - Communication parameters
 *  - Statistical information (transfered data size)
 *
 * @param[in]  #RES_GETCONNINFO_C
 * @param[out] #RES_GETCONNINFO_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_BADSESS
 *
 * @see #RES_PROC_GETCONNINFOLST
 */
#define RES_PROC_GETCONNINFO                314
/**
 * @brief Get information about all SMI connections.
 *
 * This SMI call queries a connection information list about all connections.
 *
 * @param[in]  #RES_GETCONNINFOLST_C
 * @param[out] #RES_GETCONNINFOLST_R
 *
 * @note
 * Due to SMI reply size limitations, clients may need to iterate the list per index:
 *  - #RES_GETCONNINFOLST_C.FirstIdx
 *  - #RES_GETCONNINFOLST_C.LastIdx
 *
 * Use <tt>LastIdx = -1</tt> to request as many elements as possible.
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_GETCONNINFOLST             316
/**
 * @brief Extended SMI ping.
 *
 * This SMI call performs a SMI ping (broadcast) to locate M1 controllers.
 *
 * Depending on  #RES_EXTPING_C.Mode different structures are replied:
 * - #RES_RM_NORMAL => normal #RES_EXTPING_R reply
 * - #RES_RM_ALLAPP => read a #RES_EXTPING2_R
 * - #RES_RM_PLCAPP => read a #RES_EXTPING2_R
 *
 * @param[in]  #RES_EXTPING_C
 * @param[out] #RES_EXTPING_R or #RES_EXTPING2_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_EXTPING                    320
/**
 * @brief Set IP address.
 *
 * This SMI call sets the IP address + subnet mask for the Ethernet interface specified by
 * #RES_SETIP_C.OldIp.
 *
 * Requirements to successfully set the IP address:
 * - Security level must be 0
 * - CPU hex switch must be PROG
 *
 * @param[in]  #RES_SETIP_C
 * @param[out] #RES_SETIP_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_FAILED  Error setting IP address, or no Ethernet interface for \c OldIp found
 * @retval #RES_E_NOWRITE Invalid CPU Hex switch
 * @retval #RES_E_BADAUTH Security level <> 0
 */
#define RES_PROC_SETIP                      322
/**
 * @brief Flash CPU front LED.
 *
 * This SMI call advises princess aura to flash the CPU front LEDs.
 *
 * @note
 * UDP broadcast support!
 *
 * @param[in]  #RES_FLASHLED_C
 * @param[out] #RES_FLASHLED_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_FLASHLED                   324
/**
 * @brief Resolve network IP address.
 *
 * This SMI call resolves the IP address for a given M1 target name (host name).
 *
 * @note
 * This SMI call is intended to be used as UDP broadcast. If given #RES_NAMETOIP_C.TargetName does
 * not match the M1 target name, no SMI reply is sent!
 *
 * @param[in]  #RES_NAMETOIP_C
 * @param[out] #RES_NAMETOIP_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_NAMETOIP                   326
/**
 * @brief Get network interface information.
 *
 * This SMI call returns information about a given network interface:
 * - Interface unit
 * - Interface flags
 * - Interface MAC address
 * - IP address + subnet mask
 *
 * Use #RES_PROC_GETIFLST to get a list of available network interfaces.
 *
 * @param[in]  #RES_IFSHOW_C
 * @param[out] #RES_IFSHOW_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_BADNAME Interface not found
 */
#define RES_PROC_IFSHOW                     328
/**
 * @brief Get network interface list.
 *
 * This SMI call returns the list of available network interfaces, their interface
 * names and IP address. Use #RES_PROC_IFSHOW to get further interface information.
 *
 * @param[in]  #RES_GETIFLST_C
 * @param[out] #RES_GETIFLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_FAILED
 */
#define RES_PROC_GETIFLST                   330
/**
 * @brief Get serial number list.
 *
 * This SMI call gets a list of serial numbers (USB device serials).
 *
 * @param[in]  #RES_GETSERIALLST_C
 * @param[out] #RES_GETSERIALLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_GETSERIALLST               332
/**
 * @brief Checks master-key existence.
 * @param[in]  #RES_HASMASTERKEY_C
 * @param[out] #RES_HASMASTERKEY_R
 * @deprecated
 */
#define RES_PROC_HASMASTERKEY               334
/**
 * @brief Create new master-key.
 * @param[in]  #RES_CREATEMASTERKEY_C
 * @param[out] #RES_CREATEMASTERKEY_R
 * @deprecated
 */
#define RES_PROC_CREATEMASTERKEY            336
/**
 * @brief Restore master-key.
 * @param[in]  #RES_RESTOREMASTERKEY_C
 * @param[out] #RES_RESTOREMASTERKEY_R
 * @deprecated
 */
#define RES_PROC_RESTOREMASTERKEY           338
/**
 * @brief Encrypts a device.
 * @param[in]  #RES_ENCRYPTDEVICE_C
 * @param[out] #RES_ENCRYPTDEVICE_R
 * @deprecated
 */
#define RES_PROC_ENCRYPTDEVICE              340
/**
 * @brief Decrypts a device.
 * @param[in]  #RES_DECRYPTDEVICE_C
 * @param[out] #RES_DECRYPTDEVICE_R
 * @deprecated
 */
#define RES_PROC_DECRYPTDEVICE              342
/**
 * @brief Get available crypt algorithms.
 * @param[in]  #RES_CRYPTALGORITHMLIST_C
 * @param[out] #RES_CRYPTALGORITHMLIST_R
 * @deprecated
 */
#define RES_PROC_CRYPTALGORITHMLIST         344
/**
 * @brief Get the devices crypt information.
 * @param[in]  #RES_CRYPTMETADATA_C
 * @param[out] #RES_CRYPTMETADATA_R
 * @deprecated
 */
#define RES_PROC_CRYPTMETADATA              346
/**
 * @brief Checks if a device is encrypted.
 * @param[in]  #RES_ISENCRYPTED_C
 * @param[out] #RES_ISENCRYPTED_R
 * @deprecated
 */
#define RES_PROC_ISENCRYPTED                348
/**
 * @brief Check if controller can deal with master-keys.
 * @param[in]  #RES_CANHANDLEMASTERKEY_C
 * @param[out] #RES_CANHANDLEMASTERKEY_R
 * @deprecated
 */
#define RES_PROC_CANHANDLEMASTERKEY         350
/**
 * @brief Get progress information.
 * @param[in]  #RES_CRYPTPROGRESS_C
 * @param[out] #RES_CRYPTPROGRESS_R
 * @deprecated
 */
#define RES_PROC_CRYPTPROGRESS              352
/**
 * @brief Get information about configuration resource.
 *
 * This SMI call gets information about given configuration resource specified
 * by #RES_CFGINFO_C.Name and version identifier.
 *
 * Use #RES_PROC_CFGINFOLST to get a list of all configuration resources.
 *
 * @param[in]  #RES_CFGINFO_C
 * @param[out] #RES_CFGINFO_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 * @retval #RES_E_NAME Cannot find resource
 *
 * @see #RES_RESOURCEINFO
 */
#define RES_PROC_CFGINFO                    354
/**
 * @brief Get information about all configuration resources (listing).
 *
 * This SMI call gets a list of information about all configuration resources.
 *
 * @note
 * Due to SMI reply size limitations, clients may need to iterate the list per index:
 *  - #RES_CFGINFOLST_C.FirstIdx
 *  - #RES_CFGINFOLST_C.LastIdx
 *
 * Use <tt>LastIdx = -1</tt> to request as many elements as possible.
 *
 * @param[in]  #RES_CFGINFOLST_C
 * @param[out] #RES_CFGINFOLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_CFGINFOLST                 356
/**
 * @brief Get information about all component-applications (listing).
 * @todo BEBU Add detailed description.
 *
 * @param[in]  #RES_COMPAPPLST_C
 * @param[out] #RES_COMPAPPLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_COMPAPPINFOLST             358
/**
 * @brief Get information about all components of one component-application.
 * @todo BEBU Add detailed description.
 *
 * @param[in]  #RES_COMPLST_C
 * @param[out] #RES_COMPLST_R
 *
 * @return #RES_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define RES_PROC_COMPINFOLST                360
/**
 * @brief Get progress information.
 * @param[in]  #RES_PROGRESSGET_C
 * @param[out] #RES_PROGRESSGET_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 */
#define RES_PROC_PROGRESSGET                380
/**
 * @brief Delete progress.
 * @param[in]  #RES_PROGRESSDEL_C
 * @param[out] #RES_PROGRESSDEL_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 */
#define RES_PROC_PROGRESSDEL                382
/**
 * @brief Cancel a long-running process.
 * @param[in]  #RES_PROGRESSCANCEL_C
 * @param[out] #RES_PROGRESSCANCEL_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 */
#define RES_PROC_PROGRESSCANCEL             384
/**
 * @brief SCEP renew certificate.
 * @param[in]  #RES_SCEPRENEW_C
 * @param[out] #RES_SCEPRENEW_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 * @retval #RES_E_NOTSUPP
 */
#define RES_PROC_SCEPRENEW                  390
/**
 * @brief Set device Master-Key for a given password.
 * This call sets the device master-key which is derived from the given secret
 * password using a password-based key derivation function (PBKDF2).
 * @param[in]  #RES_CRYPT_MKSET_C
 * @param[out] #RES_CRYPT_MKSET_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 */
#define RES_PROC_CRYPT_MKSET                400
/**
 * @brief Delete device Master-Key.
 * This call deletes the Master-Key from the device.
 * @param[in]  #RES_CRYPT_MKDEL_C
 * @param[out] #RES_CRYPT_MKDEL_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 */
#define RES_PROC_CRYPT_MKDEL                402
/**
 * @brief Get Master-Key information.
 * @param[in]  #RES_CRYPT_MKINFO_C
 * @param[out] #RES_CRYPT_MKINFO_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED if failed
 */
#define RES_PROC_CRYPT_MKINFO               404
/**
 * @brief Add a secret value to the secure vault.
 * This call adds a new secret to the secure vault store. If an entry already
 * exists #RES_E_DUP is returned. A valid master-key must be set prior adding
 * a new secret.
 * @param[in]  #RES_CRYPT_VAULTADD_C
 * @param[out] #RES_CRYPT_VAULTADD_R
 * @retval #RES_E_OK
 * @retval #RES_E_DUP
 * @retval #RES_E_FAILED
 */
#define RES_PROC_CRYPT_VAULTADD             410
/**
 * @brief Get secret from the secure vault.
 * @param[in]  #RES_CRYPT_VAULTGET_C
 * @param[out] #RES_CRYPT_VAULTGET_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 */
#define RES_PROC_CRYPT_VAULTGET             412
/**
 * @brief Delete a secret from the secure vault.
 * This call deletes the secret value from the secure vault.
 * @param[in]  #RES_CRYPT_VAULTDEL_C
 * @param[out] #RES_CRYPT_VAULTDEL_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 */
#define RES_PROC_CRYPT_VAULTDEL             414
/**
 * @brief Makes a new encrypted volume image (TrueCrypt container file).
 * The actual creation is performed in a low-priority background task. Thus the calling
 * client need to update supplied progress information.
 *
 * @param[in]  #RES_CRYPT_TCVOLMAKE_C
 * @param[out] #RES_CRYPT_TCVOLMAKE_R
 * @retval #RES_E_OK
 * @retval #RES_E_INPROGRESS
 * @retval #RES_E_FAILED
 * @see RES_PROC_PROGRESSGET
 */
#define RES_PROC_CRYPT_TCVOLMAKE            420
/**
 * @brief Mount an encrypted volume image.
 * This call mounts an encrypted volume image (mount point, file path) with
 * the given password string.
 * @param[in]  #RES_CRYPT_TCVOLMOUNT_C
 * @param[out] #RES_CRYPT_TCVOLMOUNT_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 */
#define RES_PROC_CRYPT_TCVOLMOUNT           422
/**
 * @brief Unmount an encrypted volume image.
 * This call unmounts an encrypted volume image for a given mount point.
 * @param[in]  #RES_CRYPT_TCVOLUNMOUNT_C
 * @param[out] #RES_CRYPT_TCVOLUNMOUNT_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 */
#define RES_PROC_CRYPT_TCVOLUNMOUNT         424
/**
 * @brief Get supported algorithms.
 * This call returns a list of supported hash and cipher algorithms.
 * @param[in]  #RES_CRYPT_TCVOLGETALGORITHM_C
 * @param[out] #RES_CRYPT_TCVOLGETALGORITHM_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 */
#define RES_PROC_CRYPT_TCVOLGETALGORITHM    426
/**
 * @brief Add a private key to the secure key store.
 * This call adds a private key to the secure key store.
 * A valid master-key must be set prior adding a new secret.
 * The key file will be deleted after successful import.
 * @param[in]  #RES_CRYPT_PKEYADD_C
 * @param[out] #RES_CRYPT_PKEYADD_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 * @retval #RES_E_PARM
 * @retval #RES_E_NOTSUPP
 */
#define RES_PROC_CRYPT_PKEYADD              430
/**
 * @brief Delete a private key from the secure key store.
 * This call deletes a private key from the secure key store.
 * @param[in]  #RES_CRYPT_PKEYDEL_C
 * @param[out] #RES_CRYPT_PKEYDEL_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 * @retval #RES_E_NOTSUPP
 */
#define RES_PROC_CRYPT_PKEYDEL              432
/**
 * @brief Get private key information.
 * @param[in]  #RES_CRYPT_PKEYINFO_C
 * @param[out] #RES_CRYPT_PKEYINFO_R
 * @retval #RES_E_OK
 * @retval #RES_E_FAILED
 * @retval #RES_E_NOTSUPP
 */
#define RES_PROC_CRYPT_PKEYINFO             434
/** @} */
/**
 * @ingroup RES_MODULE
 * Information about a module
 */
typedef struct
{
    CHAR8   TypeName[M_MODNAMELEN_A];    /**< Module type string (for example "HVC","SPS") */
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Name of module instance */
    UINT32  AppIdx;             /**< Index of module instance */
    UINT32  AppPart;            /**< Memory partition module runs in */
    UINT32  MinVers;            /**< Oldest supported RPC-Version */
    UINT32  MaxVers;            /**< Newest supported RPC-Version */
    UINT32  MaxUser;            /**< Maximum number of concurrent users */
    UINT32  Attr;               /**< Attributes of module */
    UINT32  ModuleId;           /**< Module-Id as in VxWorks */
    UINT32  ActUser;            /**< Number of concurrent users */
    UINT32  State;              /**< Status of module */
    UINT32  ModuleNb;           /**< Module number for SMI */
} RES_MODINFO;

/**
 * Structure for the SMI-Call #RES_PROC_MODINFO
 */
typedef struct
{
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Name of module instance */
} RES_MODINFO_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MODINFO
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    RES_MODINFO Inf;            /**< Module information */
} RES_MODINFO_R;

/**
 * Structure for the SMI-Call #RES_PROC_MODINFOLST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index to module list */
    UINT32  LastIdx;            /**< Last index to module list */
} RES_MODINFOLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MODINFOLST
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfMod;        /**< Number of list elements */
    RES_MODINFO Inf[1];         /**< List of module information */
} RES_MODINFOLST_R;

/**
 * @ingroup RES-RESOURCE
 * @brief Information about a module
 * @note This structure must be at least the size of #RES_MODUL
 */
typedef struct
{
    CHAR8       TypeName[M_MODNAMELEN_A];    /**< Module type string (for example "HVC","SPS") */
    CHAR8       AppName[M_MODNAMELEN_A];     /**< Name of module instance */
    UINT32      AppIdx;         /**< Index of module instance */
    UINT32      AppPart;        /**< Memory partition module runs in */
    UINT32      MinVers;        /**< Oldest supported RPC-Version */
    UINT32      MaxVers;        /**< Newest supported RPC-Version */
    UINT32      MaxUser;        /**< Maximum number of concurrent users */
    UINT32      Attr;           /**< Attributes of module */
    UINT32      ModuleId;       /**< Module-Id as in VxWorks */
    UINT32      ActUser;        /**< Number of concurrent users */
    UINT32      State;          /**< Status of module */
    UINT32      ModuleNb;       /**< Module number for SMI */
    UINT32      TaskId;         /**< Id of parent task */
    UINT16      PortNb;         /**< UDP port number */
    UINT16      TcpPortNb;      /**< TCP port number */
    UINT32      Checksum;       /**< Checksum of module object */
    SYS_VERSION Version;        /**< Version of module object */
    UINT32      Incarnation;    /**< Incarnation counter */
    UINT32      OwnTaskId;      /**< Own task Id */
    UINT32      Spare3[2];      /**< Not used, 0 for now */
} RES_MODXINFO;

/**
 * Structure for the SMI-Call #RES_PROC_MODXINFO
 */
typedef struct
{
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Name of module instance */
} RES_MODXINFO_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MODXINFO
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    RES_MODXINFO    Inf;        /**< Module information */
} RES_MODXINFO_R;

/**
 * Structure for the SMI-Call #RES_PROC_MODXINFOLST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index to module list */
    UINT32  LastIdx;            /**< Last index to module list */
} RES_MODXINFOLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MODXINFOLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfMod;    /**< Number of list elements */
    RES_MODXINFO    Inf[1];     /**< List of module information */
} RES_MODXINFOLST_R;

/**
 * Task information structure.
 */
typedef struct
{
    UINT32  TaskId;             /**< Task ID */
    CHAR8   Name[M_TSKNAMELEN_A];    /**< Task Name */
    /**
     * @brief Task priority (0 - 255)
     * @since V3.95
     */
    UINT32  Priority;
    /**
     * @brief Task status
     * @since V3.95
     */
    UINT32  Status;
    /**
     * @brief Most recent task error status
     * @since V3.95
     */
    SINT32  ErrorStatus;
    UINT32  Spare;              /**< Reserved */
} RES_MODTASKINFO;

/**
 * Structure for the SMI-Call #RES_PROC_MODCHILDLST
 */
typedef struct
{
    UINT32  ParentTaskId;       /**< Parent task ID */
} RES_MODCHILDLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MODCHILDLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    RES_MODTASKINFO ParentTask; /**< Parent task information */
    UINT32          NbOfChildTasks;  /**< Size of array ChildTask[] */
    RES_MODTASKINFO ChildTask[1];    /**< Child task information */
} RES_MODCHILDLST_R;

/**
 * Structure for the SMI-Call #RES_PROC_MODTASKLST
 */
typedef struct
{
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Name of module instance */
} RES_MODTASKLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MODTASKLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfModTasks;    /**< Size of array ModTask[] */
    UINT32          Spare[4];   /**< Not used, 0 for now */
    RES_MODTASKINFO ModTask[1]; /**< Information about each module task */
} RES_MODTASKLST_R;

/**
 * Structure for the SMI-Reply RES_PROC_MODALLOC; Version 2
 */
typedef struct
{
    SINT32  RetCode;            /**< Return code */
    UINT32  ModuleNb;           /**< Module number */
    UINT16  PortNb;             /**< Port number for UDP */
} RES_MODALLOC_R_2;

/**
 * Structure for the SMI-Call #RES_PROC_MODALLOC
 */
typedef struct
{
    UINT32  IPAddr;             /**< IP address of caller */
    UINT32  ModuleNb;           /**< Module number of caller */
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Name of module instance */
} RES_MODALLOC_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MODALLOC
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  ModuleNb;           /**< Module number */
    UINT16  PortNb;             /**< Port number for UDP */
    UINT16  TcpPortNb;          /**< Port number for TCP */
} RES_MODALLOC_R;

/**
 * Structure for the SMI-Call #RES_PROC_MODFREE
 */
typedef struct
{
    UINT32  IPAddr;             /**< IP address of caller */
    UINT32  ModuleNb;           /**< Module number of caller */
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Name of module instance */
} RES_MODFREE_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MODFREE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} RES_MODFREE_R;

/**
 * Structure for the SMI-Reply RES_PROC_MODNB; Version 2
 */
typedef struct
{
    SINT32  RetCode;            /**< Return code */
    UINT32  ModuleNb;           /**< Module number */
    UINT16  PortNb;             /**< Port number for UDP */
} RES_MODNB_R_2;

/**
 * Structure for the SMI-Call #RES_PROC_MODNB
 */
typedef struct
{
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Name of module instance */
} RES_MODNB_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MODNB
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  ModuleNb;           /**< Module number */
    UINT16  PortNb;             /**< Port number for UDP */
    UINT16  TcpPortNb;          /**< Port number for TCP */
} RES_MODNB_R;

/**
 * Informationen eines Benutzers
 */
typedef struct
{
    UINT32  IPAddr;             /**< IP address */
    UINT32  ModuleNb;           /**< Module number */
} RES_USRINFO;

/**
 * Structure for the SMI-Call #RES_PROC_MODUSER
 */
typedef struct
{
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Name of module instance */
} RES_MODUSER_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MODUSER
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfUser;       /**< Number of list elements */
    RES_USRINFO Inf[1];         /**< List of user information */
} RES_MODUSER_R;

/**
 * Info on storage device (32-bit size values).
 */
typedef struct
{
    CHAR8   Name[RES_MNAMELEN_A];    /**< Name of storage device */
    UINT32  Type;               /**< Type of storage device */
    UINT32  Org;                /**< Organisation of storage device */
    UINT32  Size;               /**< Total size in bytes */
    UINT32  Free;               /**< Bytes free */
    UINT32  State;              /**< Status of storage device */
} RES_MEMINFO;

/**
 * Structure for the SMI-Call #RES_PROC_MEMINFO
 */
typedef struct
{
    CHAR8   Name[RES_MNAMELEN_A];    /**< Name of storage device */
} RES_MEMINFO_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MEMINFO
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    RES_MEMINFO Inf;            /**< Storage device information */
} RES_MEMINFO_R;

/**
 * Info on storage device (64-bit size values).
 */
typedef struct
{
    CHAR8   Name[RES_MNAMELEN_A];    /**< Name of storage device */
    UINT32  Type;               /**< Type of storage device */
    UINT32  Org;                /**< Organisation of storage device */
    UINT64  Size;               /**< Total size in bytes */
    UINT64  Free;               /**< Bytes free */
    UINT32  State;              /**< Status of storage device */
    UINT32  MaxBlk;             /**< Max. available memory block */
    BOOL8   Encrypted;          /**< Is storage device encrypted */
    UINT8   EncryptInfo;        /**< additional encryption info, 1 - meta info broken */
    UINT16  Spare[17];          /**< Not used, 0 for now */
} RES_MEMINFO64;

/**
 * Structure for the SMI-Call #RES_PROC_MEMINFO64
 */
typedef struct
{
    CHAR8   Name[RES_MNAMELEN_A];    /**< Name of storage device */
    UINT32  Spare[4];           /**< Not used, 0 for now */
} RES_MEMINFO64_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MEMINFO64
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    RES_MEMINFO64   Inf;        /**< Storage device information */
} RES_MEMINFO64_R;

/**
 * Structure for the SMI-Call #RES_PROC_MEMINFOLST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index to memory list */
    UINT32  LastIdx;            /**< Last index to memory list */
} RES_MEMINFOLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MEMINFOLST
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfMem;        /**< Number of list elements */
    RES_MEMINFO Inf[1];         /**< List of memory information */
} RES_MEMINFOLST_R;

/**
 * Structure for the SMI-Call #RES_PROC_MEMINFOLST64
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index to memory list */
    UINT32  LastIdx;            /**< Last index to memory list */
} RES_MEMINFOLST64_C;

/**
 * Structure for the SMI-Reply #RES_PROC_MEMINFOLST64
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfMem;    /**< Number of list elements */
    RES_MEMINFO64   Inf[1];     /**< List of memory information */
} RES_MEMINFOLST64_R;

/**
 * @brief I/O card information
 */
typedef struct
{
    UINT32  CardNb;             /**< I/O card number */
    UINT32  Type;               /**< Type of I/O module */
    UINT32  Attr;               /**< Attribute of I/O module */
    VOID*   DrvId;              /**< Driver ID */
    UINT32  NbOfChan;           /**< Number of channels on I/O module */
    UINT32  State;              /**< Status of I/O module */
} RES_IOCDINFO;

/**
 * Structure for the SMI-Call #RES_PROC_IOCDINFO
 */
typedef struct
{
    UINT32  CardNb;             /**< I/O card number */
} RES_IOCDINFO_C;

/**
 * Structure for the SMI-Reply #RES_PROC_IOCDINFO
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    RES_IOCDINFO    Inf;        /**< Info about I/O module */
} RES_IOCDINFO_R;

/**
 * Structure for the SMI-Call #RES_PROC_IOCDINFOLST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index to channel list */
    UINT32  LastIdx;            /**< Last index to channel list */
} RES_IOCDINFOLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_IOCDINFOLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfCd;     /**< Number of list elements */
    RES_IOCDINFO    Inf[1];     /**< List of channel information */
} RES_IOCDINFOLST_R;

/**
 * @brief I/O channel information
 */
typedef struct
{
    UINT32  CardNb;             /**< I/O card number */
    UINT32  ChanNb;             /**< I/O channel number */
    UINT32  MaxUser;            /**< Maximum number of concurrent users */
    UINT32  ActUser;            /**< Actual number of concurrent users */
    UINT32  State;              /**< Channel state */
} RES_IOCHINFO;

/**
 * Structure for the SMI-Call #RES_PROC_IOCHINFO
 */
typedef struct
{
    UINT32  CardNb;             /**< I/O card number */
    UINT32  ChanNb;             /**< I/O channel number */
} RES_IOCHINFO_C;

/**
 * Structure for the SMI-Reply #RES_PROC_IOCHINFO
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    RES_IOCHINFO    Inf;        /**< Channel info */
} RES_IOCHINFO_R;

/**
 * Structure for the SMI-Call #RES_PROC_IOCHINFOLST
 */
typedef struct
{
    UINT32  CardNb;             /**< I/O card number */
    UINT32  FirstIdx;           /**< First index to channel list */
    UINT32  LastIdx;            /**< Last index to channel list */
} RES_IOCHINFOLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_IOCHINFOLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfCh;     /**< Number of list elements */
    RES_IOCHINFO    Inf[1];     /**< List of channel information */
} RES_IOCHINFOLST_R;

/**
 * Structure for the SMI-Call #RES_PROC_IOALLOC
 */
typedef struct
{
    UINT32  IPAddr;             /**< IP address of caller */
    UINT32  ModuleNb;           /**< Module number of caller */
    UINT32  CardNb;             /**< I/O card number */
    UINT32  FirstChan;          /**< Number of first channel */
    UINT32  LastChan;           /**< Number of last channel */
} RES_IOALLOC_C;

/**
 * Structure for the SMI-Reply #RES_PROC_IOALLOC
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    VOID*   DrvId;              /**< Driver-ID */
} RES_IOALLOC_R;

/**
 * Structure for the SMI-Call #RES_PROC_IOFREE
 */
typedef struct
{
    UINT32  IPAddr;             /**< IP address of caller */
    UINT32  ModuleNb;           /**< Module number of caller */
    UINT32  CardNb;             /**< I/O card number */
    UINT32  FirstChan;          /**< Number of first channel */
    UINT32  LastChan;           /**< Number of last channel */
} RES_IOFREE_C;

/**
 * Structure for the SMI-Reply #RES_PROC_IOFREE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} RES_IOFREE_R;

/**
 * Structure for the SMI-Call #RES_PROC_IOUSER
 */
typedef struct
{
    UINT32  CardNb;             /**< I/O card number */
    UINT32  ChanNb;             /**< I/O channel number */
} RES_IOUSER_C;

/**
 * Structure for the SMI-Reply #RES_PROC_IOUSER
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfUser;       /**< Number of list elements */
    RES_USRINFO Inf[1];         /**< List of user information */
} RES_IOUSER_R;

/**
 * Library information
 */
typedef struct
{
    CHAR8   Name[M_FILENAMELEN_A];   /**< Name of library */
    UINT32  Attr;               /**< Attributes of library */
    UINT32  VersCode[3];        /**< Version code of library */
    UINT32  VersType;           /**< Version type of library */
} RES_LIBINFO;

/**
 * Structure for the SMI-Call #RES_PROC_LIBINFO
 */
typedef struct
{
    CHAR8   Name[M_FILENAMELEN_A];   /**< Name of library */
    UINT32  VersCode[3];        /**< Version code of library */
    UINT32  VersType;           /**< Version type of library */
} RES_LIBINFO_C;

/**
 * Structure for the SMI-Reply #RES_PROC_LIBINFO
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    RES_LIBINFO Inf;            /**< Library information */
} RES_LIBINFO_R;

/**
 * Structure for the SMI-Call #RES_PROC_LIBINFOLST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index to library list */
    UINT32  LastIdx;            /**< Last index to library list */
} RES_LIBINFOLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_LIBINFOLST
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfLib;        /**< Number of list elements */
    RES_LIBINFO Inf[1];         /**< List of library information */
} RES_LIBINFOLST_R;

/**
 * Resource information
 */
typedef struct
{
    CHAR8   Name[M_FILENAMELEN_A];   /**< Name of resource */
    UINT32  Attr;               /**< Attributes of resource */
    UINT32  VersCode[3];        /**< Version code of resource */
    UINT32  VersType;           /**< Version type of resource */
} RES_RESOURCEINFO;

/**
 * Structure for the SMI-Call #RES_PROC_CFGINFO
 */
typedef struct
{
    CHAR8   Name[M_FILENAMELEN_A];   /**< Name of configuration */
    UINT32  VersCode[3];        /**< Version code of configuration */
    UINT32  VersType;           /**< Version type of configuration */
} RES_CFGINFO_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CFGINFO
 */
typedef struct
{
    SINT32              RetCode;     /**< Return Code */
    RES_RESOURCEINFO    Inf;    /**< Resource information */
} RES_CFGINFO_R;

/**
 * Structure for the SMI-Call #RES_PROC_CFGINFOLST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index to configuration list */
    UINT32  LastIdx;            /**< Last index to configuration list */
} RES_CFGINFOLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CFGINFOLST
 */
typedef struct
{
    SINT32              RetCode;     /**< Return Code */
    UINT32              NbOfLib;     /**< Number of list elements */
    RES_RESOURCEINFO    Inf[1]; /**< List of configuration information */
} RES_CFGINFOLST_R;

/**
 * Structure for the SMI-Call #RES_PROC_KEYCHECK
 */
typedef struct
{
    UINT32      Challenge;      /**< Challenge Request */
    CHAR8       Name[32];       /**< Module type */
    SYS_VERSION Version;        /**< Module version */
    UINT32      Spare[8];       /**< Reserved */
} RES_KEYCHECK_C;

/**
 * Structure for the SMI-Reply #RES_PROC_KEYCHECK
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Response;           /**< Challenge Response */
    UINT32  Option;             /**< Module specific option value */
    UINT32  Spare[8];           /**< Reserved */
} RES_KEYCHECK_R;

/**
 * @brief License key information structure.
 * @since V3.95 Release
 */
typedef struct
{
    CHAR8       Name[M_FILENAMELONGLEN_A];   /**< License key name */
    CHAR8       Path[M_PATHLEN_A];   /**< License key file path */
    UINT32      KeyVersion;     /**< License key version */
    /**
     * @brief License key type.
     *
     * Possible types:
     * - #RES_KEY_CFCSERIAL
     * - #RES_KEY_CPUSERIAL
     * - #RES_KEY_USBFLASHSERIAL
     * - #RES_KEY_USB
     * - #RES_KEY_VERSION
     * - #RES_KEY_DEADLINE
     */
    UINT32      Type;
    CHAR8       SerialNbr[32];  /**< Serial number */
    SYS_VERSION ModVersion;     /**< Module version */
    UINT32      Deadline;       /**< Deadline (s since 1970) */
    UINT32      Option;         /**< Module option */
    BOOL8       Valid;          /**< Flag indicating if license is valid */
    BOOL8       InUse;          /**< Flag indicating if license is in use */
    BOOL8       Spare0[2];      /**< Reserved */
    UINT32      Spare1[5];      /**< Reserved */
} RES_KEYINFO;

/**
 * Structure for the SMI-Call #RES_PROC_GETKEYLST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index to key list */
    UINT32  LastIdx;            /**< Last index to key list */
    UINT32  Spare[2];           /**< Reserved */
} RES_GETKEYLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_GETKEYLST
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfKeys;       /**< Number of list elements */
    UINT32      Spare[2];       /**< Reserved */
    RES_KEYINFO Inf[1];         /**< List of keys information */
} RES_GETKEYLST_R;

/**
 * @brief Application information structure
 *
 * Possible state values:
 * - #RES_S_RUN
 * - #RES_S_ERROR
 * - #RES_S_STOP
 * - #RES_S_INIT
 * - #RES_S_DEINIT
 * - #RES_S_EOI
 * - #RES_S_RESET
 * - #RES_S_WARNING
 *
 * @see RES_PROC_APPINFO
 */
typedef struct
{
    CHAR8   Name[M_APPNAMELEN_A];    /**< Name of application */
    UINT32  State;              /**< Application state */
    UINT32  SystemState;        /**< System state */
    UINT32  Spare[19];          /**< Reserved */
} RES_APPINFO;

/**
 * Structure for the SMI-Call #RES_PROC_APPINFO
 */
typedef struct
{
} RES_APPINFO_C;

/**
 * Structure for the SMI-Reply #RES_PROC_APPINFO
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    RES_APPINFO Inf;            /**< Application information */
} RES_APPINFO_R;

/**
 * Structure for SMI-Call
 */
typedef struct
{
    UINT32  Type;               /**< CPU type (MP213) */
    UINT32  Variant;            /**< CPU variant (/E,/X) */
    CHAR8   SerialNbr[12];      /**< 10-digit Serial Number */
} RES_CPUIDREG;

/**
 * Structure for the SMI-Call #RES_PROC_SYSINFO
 */
typedef struct
{
    UINT32  Parm;               /**< Not used, must be zero */
    UINT32  MainVers;           /**< Tool main version 0=not relevant */
    UINT32  SubVers;            /**< Tool sub version 0=not relevant */
    CHAR8   ToolName[M_MODNAMELEN_A];    /**< Name of tool (MMan, MPlc, etc.) */
} RES_SYSINFO_C;

/**
 * Structure for the SMI-Reply #RES_PROC_SYSINFO
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          CpuSwitch;  /**< Actual CPU-ID (hex switch) */
    UINT32          ProcNum;    /**< Processor number */
    UINT32          RestartCount;    /**< Restarts since NVRAM reset */
    UINT32          IPAddr;     /**< IP address in Intel format */
    RES_CPUIDREG    CpuId;      /**< CPU-ID register (EEPROM) */
    SYS_VERSION     VersMCore;  /**< Version of MCore */
    SYS_VERSION     VersMSys;   /**< Version of MSys */
    CHAR8           AppName[M_APPNAMELEN_A];     /**< Name of application */
    UINT32          SecurityLevel;   /**< Required security level */
    UINT32          LoginRequired;   /**< M1 requires login if != 0 */
    struct tm       DateTime;   /**< Date and Time of RTC */
    UINT32          LoginChecker;    /**< M1 uses a login checker module if != 0 */
    BOOL8           AccessControl;   /**< True if access-control is enabled */
    BOOL8           AccessHandler;   /**< M1 uses a access handler module if True */
    BOOL8           Spare0[2];  /**< Spare, is zero for now */
    UINT32          AppState;   /**< Status of application @ref RES_S_ */
    UINT32          SysState;   /**< Status of system @ref RES_S_ */
    SINT32          SessionLifeTime;     /**< Lifetime of session token [s] */
    UINT16          TimeBase;   /**< System time base (LOCAL/UTC) */
    UINT16          Spare1;     /**< Spare, is zero for now */
    CHAR8           TimeZone[M_TIMEZONELEN_A];   /**< System time zone name */
    SINT32          TimeOffset; /**< System time zone offset in seconds to UTC */
    TIMESTAMP       TimeUtc;    /**< Current system time [UTC] */
    UINT32          Spare2[2];  /**< Spare, is zero for now */
} RES_SYSINFO_R;

/**
 * Structure for the SMI-Call #RES_PROC_LOGIN
 */
typedef struct
{
    UINT32  Parm;               /**< Not used, must be zero */
    UINT32  MainVers;           /**< Tool main version 0=not relevant */
    UINT32  SubVers;            /**< Tool sub version 0=not relevant */
    CHAR8   ToolName[M_MODNAMELEN_A];    /**< Name of tool (MMan, MPlc, etc.) */
    CHAR8   UserName[M_UNAMELEN_A];  /**< User name (ASCII) */
    UINT8   Password[M_PWORDLEN];    /**< User password as ASCII plain text or binary MD5 hash */
} RES_LOGIN_C;

/**
 * Structure for the SMI-Reply #RES_PROC_LOGIN
 */
typedef struct
{
    SINT32                  RetCode;     /**< Return Code */
    UINT32                  SecurityLevel;   /**< System security level */
    RES_LOGIN_PERMISSIONS   Permissions;     /**< @brief User permissions */
    UINT32                  AuthLen;     /**< Opaque SMI/RPC authentication length */
    UINT8                   Authent[128];    /**< Opaque SMI/RPC authentication (up to 128 bytes) */
} RES_LOGIN_R;

/**
 * Structure for the SMI-Call #RES_PROC_LOGIN2
 */
typedef struct
{
    UINT32  UserParm;           /**< User parameter passed to checker */
    UINT32  MainVers;           /**< Tool main version 0=not relevant */
    UINT32  SubVers;            /**< Tool sub version 0=not relevant */
    CHAR8   ToolName[M_MODNAMELEN_A];    /**< Name of tool (MMan, MPlc, etc.) */
    CHAR8   UserName[M_UNAMELEN2_A];     /**< User name (ASCII) */
    UINT8   Password[M_PWORDLEN2];   /**< User password as ASCII plain text or binary MD5 hash */
    BOOL8   Local;              /**< Login on local controller (ignore password) */
    BOOL8   Spare1[3];          /**< Reserved */
    UINT32  Spare2;             /**< Reserved */
    UINT32  Spare3;             /**< Reserved */
    UINT32  Spare4;             /**< Reserved */
    UINT32  Spare5;             /**< Reserved */
} RES_LOGIN2_C;

/**
 * Structure for the SMI-Reply #RES_PROC_LOGIN2
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          SecurityLevel;   /**< System security level */
    UINT32          Spare1;     /**< Reserved */
    RES_USER_ACCESS UserAcc;    /**< User information (group, level, permissions) */
    UINT32          AuthLen;    /**< Opaque SMI/RPC authentication length */
    UINT8           Authent[128];    /**< Opaque SMI/RPC authentication (up to 128 bytes) */
    UINT8           UserData[128];   /**< Additional user data returned by login checker */
    UINT8           Reserv[128];     /**< Reserved */
} RES_LOGIN2_R;

/**
 * Structure for the SMI-Call #RES_PROC_XLOGIN
 */
typedef struct
{
    UINT32  UserParm;           /**< User parameter passed to checker */
    CHAR8   UserName[M_UNAMELEN_A];  /**< User name in readable ASCII */
    CHAR8   Password[M_PWORDLEN];    /**< Password scrambled or not */
    CHAR8   SwModName[M_MODNAMELEN_A];   /**< Name of login checker module */
} RES_XLOGIN_C;

/**
 * Structure for the SMI-Reply #RES_PROC_XLOGIN
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  SecurityLevel;      /**< required security level */
    UINT32  AuthLen;            /**< Size of authentication */
    UINT8   Authent[128];       /**< Authentication 8 to 128 bytes */
    UINT8   UserData[128];      /**< User data returned by checker */
} RES_XLOGIN_R;

/**
 * Structure for the SMI-Call #RES_PROC_LOGOUT
 */
typedef struct
{
    UINT32  Parm;               /**< Not used, must be zero */
    UINT8   Authent[128];       /**< @deprecated Authentication 8 to 128 bytes */
} RES_LOGOUT_C;

/**
 * Structure for the SMI-Reply #RES_PROC_LOGOUT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} RES_LOGOUT_R;

/**
 * Structure for the SMI-Call #RES_PROC_XLOGOUT
 */
typedef struct
{
    UINT32  UserParm;           /**< User parameter passed to checker */
    CHAR8   UserName[M_UNAMELEN_A];  /**< User name in readable ASCII */
    CHAR8   SwModName[M_MODNAMELEN_A];   /**< Name of login checker module */
    UINT8   Authent[128];       /**< Authentication 8 to 128 bytes */
    UINT8   UserData[128];      /**< User data returned by checker */
} RES_XLOGOUT_C;

/**
 * Structure for the SMI-Reply #RES_PROC_XLOGOUT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} RES_XLOGOUT_R;

/**
 * Structure for the SMI-Call #RES_PROC_REMUSER
 */
typedef struct
{
    UINT32  SessionId;          /**< SessionId of user to remove */
    /**
     * @brief Username to remove
     * @deprecated Not used anymore (since V3.95)
     */
    CHAR8   UserName[M_UNAMELEN_A];
} RES_REMUSER_C;

/**
 * Structure for the SMI-Reply #RES_PROC_REMUSER
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} RES_REMUSER_R;

/**
 * Structure for the SMI-Call #RES_PROC_CLNTREBOOT
 */
typedef struct
{
    UINT32  IPAddr;             /**< Client IP address */
    /**
     * @brief Mode flags to indicate which callbacks to remove:
     * - #RES_CB_EHD
     * - #RES_CB_VHD
     * - #RES_CB_DBG
     * - #RES_CB_ALL
     */
    UINT32  Mode;
    UINT32  Spare[2];           /**< Not used, 0 for now */
} RES_CLNTREBOOT_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CLNTREBOOT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Reserved[3];        /**< Not used, 0 for now */
} RES_CLNTREBOOT_R;

/**
 * Structure for the SMI-Call #RES_PROC_EXTPING
 */
typedef struct
{
    UINT32  IpFilter;           /**< @brief Filter to address only particular IP ranges */
    /**
     * @brief Type filter (RES_FT_*)
     * - #RES_FT_EQU
     * - #RES_FT_NOTEQU
     */
    UINT32  FilterType;
    /**
     * @brief Type of Reply-Message (RES_RT_*)
     * - #RES_RT_AUTO
     * - #RES_RT_IP
     * - #RES_RT_BROADCAST
     */
    UINT32  ReplyType;
    /**
     * @brief Request mode (RES_RM_*)
     * - #RES_RM_NORMAL
     * - #RES_RM_ALLAPP
     * - #RES_RM_PLCAPP
     */
    UINT32  Mode;
    UINT8   Reserved[12];       /**< Reserved */
} RES_EXTPING_C;

/**
 * Structure for the SMI-Reply #RES_PROC_EXTPING
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    CHAR8   ProdNb[MIO_PRODNBLEN_A];     /**< Serial number with 10 digits */
    UINT32  VersCode[3];        /**< MSys version code */
    UINT32  VersType;           /**< MSys version type */
    CHAR8   TargetName[BOOT_LEN1];   /**< Target name */
    /**
     * @brief Request mode (RES_RM_*)
     * - #RES_RM_NORMAL
     * - #RES_RM_ALLAPP
     * - #RES_RM_PLCAPP
     */
    UINT32  Mode;
    UINT8   Dhcp;               /**< Target uses \c DHCP */
    /**
     * @brief Operating system type (RES_OS_*)
     * - #RES_OS_LINUX
     * - #RES_OS_VXWORKS
     * - #RES_OS_WINDOWS
     */
    UINT8   OpSystem;
    UINT8   Reserved[2];        /**< Reserved */
    UINT32  Type;               /**< CPU type (MP213) */
    UINT32  Variant;            /**< CPU variant */
} RES_EXTPING_R;

/**
 * Information about a module
 */
typedef struct
{
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Name of module instance */
    UINT32  State;              /**< Status of module */
    UINT32  Attr;               /**< Attributes of module */
} RES_MODNAME;

/**
 * @brief Structure for the SMI-Reply #RES_PROC_EXTPING
 */
typedef struct
{
    SINT32      RetCode;                /**< Return code */
    CHAR8       ProdNb[MIO_PRODNBLEN_A];     /**< 10-digit serial number */
    UINT32      VersCode[3];    /**< Version code of MSys */
    UINT32      VersType;       /**< Version type of MSys */
    CHAR8       TargetName[BOOT_LEN1];   /**< Name of Target */
    /**
     * @brief Request mode (RES_RM_*)
     * - #RES_RM_NORMAL
     * - #RES_RM_ALLAPP
     * - #RES_RM_PLCAPP
     */
    UINT32      Mode;
    UINT8       Dhcp;           /**< Using DHCP? */
    UINT8       OpSystem;       /**< @brief Operating system on device (see \ref RES_OS_) */
    UINT8       Reserved[2];    /**< Not used, 0 for now */
    UINT32      Type;           /**< CPU type */
    UINT32      Variant;        /**< CPU variant */
    UINT32      NbOfApp;        /**< Number of list elements */
    RES_MODNAME Inf[1];         /**< List of application modules */
} RES_EXTPING2_R;

/**
 * Structure for the SMI-Call #RES_PROC_SETIP
 */
typedef struct
{
    CHAR8   ProdNb[MIO_PRODNBLEN_A];     /**< 10 digit serial number */
    UINT32  OldIp;              /**< Old IP address (Motorola format) */
    UINT32  NewIp;              /**< New IP address (Motorola format) */
    UINT32  SubnetMask;         /**< New subnet mask (Intel format) */
    UINT8   Reserved[12];       /**< Reserved */
} RES_SETIP_C;

/**
 * Structure for the SMI-Reply #RES_PROC_SETIP
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT8   Reserved[16];       /**< Reserved */
} RES_SETIP_R;

/**
 * Structure for the SMI-Call #RES_PROC_FLASHLED
 */
typedef struct
{
    CHAR8   ProdNb[MIO_PRODNBLEN_A];     /**< 10 digit serial number */
    UINT8   Reserved[16];       /**< Reserved */
} RES_FLASHLED_C;

/**
 * Structure for the SMI-Reply #RES_PROC_FLASHLED
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT8   Reserved[16];       /**< Reserved */
} RES_FLASHLED_R;

/**
 * Structure for the SMI-Call #RES_PROC_NAMETOIP
 */
typedef struct
{
    CHAR8   TargetName[BOOT_LEN1];   /**< Target name */
    UINT8   Reserved[16];       /**< Reserved */
} RES_NAMETOIP_C;

/**
 * Structure for the SMI-Reply #RES_PROC_NAMETOIP
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  IpAddr;             /**< Target IP address */
    UINT8   Reserved[16];       /**< Reserved */
} RES_NAMETOIP_R;

/**
 * Structure for the SMI-Call #RES_PROC_IFSHOW
 */
typedef struct
{
    CHAR8   IfName[IF_NAME_LEN];     /**< Interface Name "eth0", "em0" */
    UINT8   Spare[8];           /**< Reserved */
} RES_IFSHOW_C;

/**
 * Structure for the SMI-Reply #RES_PROC_IFSHOW
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Unit;               /**< Interface unit (0, 1, 2) */
    UINT32  Mtu;                /**< Interface MTU size */
    UINT32  Flags;              /**< Interface flags */
    UINT32  IpAddress_1;        /**< IP address 1 */
    UINT32  SubnetMask_1;       /**< IP subnet mask 1 */
    UINT32  IpAddress_2;        /**< IP address 2 */
    UINT32  SubnetMask_2;       /**< IP subnet mask 2 */
    UINT32  IpAddress_3;        /**< IP address 3 */
    UINT32  SubnetMask_3;       /**< IP subnet mask 3 */
    CHAR8   IfName[IF_NAME_LEN];     /**< Interface name (same as call) */
    UINT8   MacAddress[6];      /**< MAC Address */
    UINT8   Spare1[2];          /**< Reserved */
    UINT8   Spare2[24];         /**< Reserved */
} RES_IFSHOW_R;

/**
 * Structure for the SMI-Call #RES_PROC_REQUESTACC
 */
typedef struct
{
    UINT32  UserParm;           /**< User parameter */
    UINT32  Spare2;             /**< Reserved */
    UINT32  Spare3;             /**< Reserved */
    UINT32  Spare4;             /**< Reserved */
} RES_REQUESTACC_C;

/**
 * Structure for the SMI-Reply #RES_PROC_REQUESTACC
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare1;             /**< Reserved */
    UINT32  Spare2;             /**< Reserved */
    UINT32  Spare3;             /**< Reserved */
    UINT32  Spare4;             /**< Reserved */
} RES_REQUESTACC_R;

/**
 * Structure for the SMI-Call #RES_PROC_RELEASEACC
 */
typedef struct
{
    UINT32  UserParm;           /**< User parameter */
    UINT32  Spare2;             /**< Reserved */
    UINT32  Spare3;             /**< Reserved */
    UINT32  Spare4;             /**< Reserved */
} RES_RELEASEACC_C;

/**
 * Structure for the SMI-Reply #RES_PROC_RELEASEACC
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare1;             /**< Reserved */
    UINT32  Spare2;             /**< Reserved */
    UINT32  Spare3;             /**< Reserved */
    UINT32  Spare4;             /**< Reserved */
} RES_RELEASEACC_R;

/**
 * Structure for the SMI-Call #RES_PROC_GETUSERDATA
 */
typedef struct
{
    UINT32  Spare1;             /**< Reserved */
    UINT32  Spare2;             /**< Reserved */
    UINT32  Spare3;             /**< Reserved */
    UINT32  Spare4;             /**< Reserved */
} RES_GETUSERDATA_C;

/**
 * Structure for the SMI-Reply #RES_PROC_GETUSERDATA
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          Spare1;     /**< Reserved */
    UINT32          Spare2;     /**< Reserved */
    UINT32          Spare3;     /**< Reserved */
    RES_USER_DATA   UserData;   /**< User data */
} RES_GETUSERDATA_R;

/**
 * Structure for the SMI-Call #RES_PROC_GETUSERDATALST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index of info list */
    UINT32  LastIdx;            /**< Last index of info list */
    UINT32  Spare1;             /**< Reserved */
    UINT32  Spare2;             /**< Reserved */
} RES_GETUSERDATALST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_GETUSERDATALST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          MaxElem;    /**< number of available elements */
    UINT32          NbOfElem;   /**< Size of list below */
    UINT32          Spare1;     /**< Reserved */
    UINT32          Spare2;     /**< Reserved */
    RES_USER_DATA   UserData[1];     /**< List of user information */
} RES_GETUSERDATALST_R;

/**
 * Network interface description structure.
 */
typedef struct
{
    CHAR8   IfName[IF_NAME_LEN];     /**< Interface name */
    UINT32  IpAddress;          /**< Interface IP address */
} RES_NETIF;

/**
 * Structure for the SMI-Call #RES_PROC_GETIFLST
 */
typedef struct
{
    UINT32  Spare[2];           /**< Reserved */
} RES_GETIFLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_GETIFLST
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfElem;       /**< Number of interfaces found */
    UINT32      Spare;          /**< Reserved */
    RES_NETIF   IfLst[1];       /**< Interface list */
} RES_GETIFLST_R;

/**
 * Structure for the SMI-Call #RES_PROC_OPEN
 */
typedef struct
{
    SINT32  ReqSessionTimeout;  /**< Requested session timeout [s] */
    SINT32  ReqSessionLifeTime; /**< Requested session lifetime [s] */
    SINT32  ReqSmiSize;         /**< Requested SMI message size [bytes] */
    UINT8   Spare[128];         /**< Reserved */
} RES_OPEN_C;

/**
 * Structure for the SMI-Reply #RES_PROC_OPEN
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  RevSessionTimeout;  /**< Revised session timeout [s] */
    SINT32  RevSessionLifeTime; /**< Revised session lifetime [s] */
    SINT32  RevSmiSize;         /**< Revised SMI message size [bytes] */
    UINT8   Spare[128];         /**< Reserved */
    UINT32  AuthLen;            /**< Authentication size */
    UINT8   Authent[128];       /**< Authentication 8 to 128 bytes */
} RES_OPEN_R;

/**
 * Structure for the SMI-Call #RES_PROC_CLOSE
 */
typedef struct
{
    UINT32  Spare[8];           /**< Reserved */
} RES_CLOSE_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CLOSE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[8];           /**< Reserved */
} RES_CLOSE_R;

/**
 * Structure for the SMI-Call #RES_PROC_RENEW
 */
typedef struct
{
    BOOL8   ReqAuthRenew;       /**< Request authentication renewal */
    BOOL8   ReqSpare[19];       /**< Reserved */
    UINT8   Spare[128];         /**< Reserved */
} RES_RENEW_C;

/**
 * Structure for the SMI-Reply #RES_PROC_RENEW
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    BOOL8   RevAuthRenew;       /**< Revised authentication renewal */
    BOOL8   RevSpare[19];       /**< Reserved */
    UINT32  RestartCount;       /**< Restarts since NVRAM reset */
    /**
     * Application state:
     * - #RES_S_RUN
     * - #RES_S_ERROR
     * - #RES_S_STOP
     * - #RES_S_INIT
     * - #RES_S_DEINIT
     * - #RES_S_EOI
     * - #RES_S_RESET
     * - #RES_S_WARNING
     */
    UINT32  AppState;
    /**
     * System state:
     * - #RES_S_RUN
     * - #RES_S_ERROR
     * - #RES_S_STOP
     * - #RES_S_INIT
     * - #RES_S_DEINIT
     * - #RES_S_EOI
     * - #RES_S_RESET
     * - #RES_S_WARNING
     */
    UINT32  SysState;
    UINT8   Spare[128];         /**< Reserved */
    UINT32  AuthLen;            /**< Opaque authentication length */
    UINT8   Authent[128];       /**< Opaque authentication data (8 to 128 bytes) */
} RES_RENEW_R;

/**
 * Connection information structure.
 *
 * @see #RES_PROC_GETCONNINFO
 * @see #RES_PROC_GETCONNINFOLST
 * @since V3.95 Release
 */
typedef struct
{
    UINT32      ConnId;         /**< Connection ID */
    UINT32      UserId;         /**< User ID or \c 0x0 if not logged in */
    TIMESTAMP   Timestamp;      /**< Timestamp of creation */
    TIMESTAMP   TimeAlive;      /**< Timestamp of last alive */
    UINT32      ClientIp;       /**< Client IP address */
    UINT8       Spare0[32];     /**< Reserved */
    SINT32      SessionTimeout; /**< Session timeout [s] */
    SINT32      SessionLifeTime;     /**< Session lifetime [s] */
    UINT8       Spare1[32];     /**< Reserved */
    /**
     * SMI Type, one of the following:
     * - #SMI_F_UDP
     * - #SMI_F_TCP
     * - #SMI_F_QSOAP
     * - #SMI_F_SSL
     */
    UINT32      SmiType;
    UINT32      SmiSize;        /**< Max SMI message size in bytes */
    UINT32      SmiRcvdCalls;   /**< Number of received calls */
    UINT64      SmiRcvdBytes;   /**< Number of received bytes */
    UINT32      SmiSentReplies; /**< Number of sent replies */
    UINT64      SmiSentBytes;   /**< Number of sent bytes */
    UINT8       Spare2[64];     /**< Reserved */
} RES_CONN_INFO;

/**
 * Structure for the SMI-Call #RES_PROC_GETCONNINFO
 */
typedef struct
{
    UINT32  Spare[4];           /**< Reserved */
} RES_GETCONNINFO_C;

/**
 * Structure for the SMI-Reply #RES_PROC_GETCONNINFO
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          Spare[4];   /**< Reserved */
    RES_CONN_INFO   ConnInfo;   /**< Connection information */
} RES_GETCONNINFO_R;

/**
 * Structure for the SMI-Call #RES_PROC_GETCONNINFOLST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index of info list */
    UINT32  LastIdx;            /**< Last index of info list */
    UINT32  Spare[2];           /**< Reserved */
} RES_GETCONNINFOLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_GETCONNINFOLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          MaxElem;    /**< Number of available elements */
    UINT32          NbOfElem;   /**< Size of list below */
    UINT32          Spare[2];   /**< Reserved */
    RES_CONN_INFO   ConnInfo[1];     /**< List of connection information */
} RES_GETCONNINFOLST_R;

/**
 * Serial information
 * @since V3.95 Release
 */
typedef struct
{
    CHAR8   Name[RES_MNAMELEN_A];    /**< Name of storage device */
    CHAR8   SerialNbr[32];      /**< Serial number */
    UINT8   Spare[32];          /**< Reserved */
} RES_SERIAL_INFO;

/**
 * Structure for the SMI-Call #RES_PROC_GETSERIALLST
 */
typedef struct
{
    UINT32  Spare[5];           /**< Reserved */
} RES_GETSERIALLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_GETSERIALLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfElem;   /**< Size of list below */
    UINT32          Spare[2];   /**< Reserved */
    RES_SERIAL_INFO Inf[1];     /**< List of serial number information */
} RES_GETSERIALLST_R;

/**
 * Structure for the SMI-Call #RES_PROC_HASMASTERKEY
 */
typedef struct
{
    UINT32  Spare;              /**< Reserved */
} RES_HASMASTERKEY_C;

/**
 * Structure for the SMI-Reply #RES_PROC_HASMASTERKEY
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    BOOL32  hasMasterKey;       /**< Return TRUE or FALSE */
    UINT32  Spare[3];           /**< Reserved */
} RES_HASMASTERKEY_R;

/**
 * Structure for the SMI-Call #RES_PROC_CREATEMASTERKEY
 */
typedef struct
{
    CHAR8   FilePath[RES_CRYPT_FILENAMELEN];     /**< Recovery file path */
    CHAR8   Password[RES_CRYPT_PASSWORDLEN];     /**< Recovery file password */
    UINT32  Spare[4];           /**< Reserved */
} RES_CREATEMASTERKEY_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CREATEMASTERKEY
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[3];           /**< Reserved */
} RES_CREATEMASTERKEY_R;

/**
 * Structure for the SMI-Call #RES_PROC_RESTOREMASTERKEY
 */
typedef struct
{
    CHAR8   FilePath[RES_CRYPT_FILENAMELEN];     /**< Recovery file path */
    CHAR8   Password[RES_CRYPT_PASSWORDLEN];     /**< Recovery file password */
    UINT32  deleteRecoveryFile; /**< Delete recovery file after successful restore */
    UINT32  Spare[4];           /**< Reserved */
} RES_RESTOREMASTERKEY_C;

/**
 * Structure for the SMI-Reply #RES_PROC_RESTOREMASTERKEY
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[3];           /**< Reserved */
} RES_RESTOREMASTERKEY_R;

/**
 * Structure for the SMI-Call #RES_PROC_ENCRYPTDEVICE
 */
typedef struct
{
    CHAR8   Device[RES_CRYPT_DEVICENAMELEN];     /**< Device name */
    UINT32  Algorithm;          /**< Encryption algorithm */
    UINT32  KeepData;           /**< Keep data or format */
    UINT32  Spare[10];          /**< Reserved */
} RES_ENCRYPTDEVICE_C;

/**
 * Structure for the SMI-Reply #RES_PROC_ENCRYPTDEVICE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[3];           /**< Reserved */
} RES_ENCRYPTDEVICE_R;

/**
 * Structure for the SMI-Call #RES_PROC_DECRYPTDEVICE
 */
typedef struct
{
    CHAR8   Device[RES_CRYPT_DEVICENAMELEN];     /**< Device name */
    UINT32  KeepData;           /**< Keep data or format */
    UINT32  Spare[10];          /**< Reserved */
} RES_DECRYPTDEVICE_C;

/**
 * Structure for the SMI-Reply #RES_PROC_DECRYPTDEVICE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[3];           /**< Reserved */
} RES_DECRYPTDEVICE_R;

typedef struct
{
    UINT32  Algorithm;          /**< Algorithm */
    CHAR8   Name[RES_CRYPT_ALGORITHMNAMELEN];    /**< Algorithm name */
} RES_CRYPTALGO;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPTALGORITHMLIST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index to algorithm list */
    UINT32  LastIdx;            /**< Last index to algorithm list */
    UINT32  Spare[4];           /**< Reserved */
} RES_CRYPTALGORITHMLIST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPTALGORITHMLIST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          Spare[40];  /**< Reserved */
    UINT32          Last;       /**< <> 0 last frame in list */
    UINT32          Count;      /**< Elements in the following list */
    RES_CRYPTALGO   Algorithms[1];   /**< The list of algorithms */
} RES_CRYPTALGORITHMLIST_R;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPTMETADATA
 */
typedef struct
{
    CHAR8   Device[RES_CRYPT_DEVICENAMELEN];     /**< Device name */
    UINT32  Spare[3];           /**< Reserved */
} RES_CRYPTMETADATA_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPTMETADATA
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Algorithm;          /**< Encryption algorithm */
    CHAR8   Name[RES_CRYPT_ALGORITHMNAMELEN];    /**< Encryption algorithm name */
    UINT32  Spare[10];          /**< Reserved */
} RES_CRYPTMETADATA_R;

/**
 * Structure for the SMI-Call #RES_PROC_ISENCRYPTED
 */
typedef struct
{
    CHAR8   Device[RES_CRYPT_DEVICENAMELEN];     /**< Device name */
    UINT32  Spare;              /**< Reserved */
} RES_ISENCRYPTED_C;

/**
 * Structure for the SMI-Reply #RES_PROC_ISENCRYPTED
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    BOOL32  IsEncrypted;        /**< Returns TRUE or FALSE */
    UINT32  Spare[3];           /**< Reserved */
} RES_ISENCRYPTED_R;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPTPROGRESS
 */
typedef struct
{
    CHAR8   Device[RES_CRYPT_DEVICENAMELEN];     /**< Device name */
    UINT32  Spare[4];           /**< Reserved */
} RES_CRYPTPROGRESS_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPTPROGRESS
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  fullSize;           /**< Complete amount */
    UINT32  doneSize;           /**< Amount already done */
    UINT32  Spare[3];           /**< Reserved */
} RES_CRYPTPROGRESS_R;

/**
 * Structure for the SMI-Call #RES_PROC_CANHANDLEMASTERKEY
 */
typedef struct
{
    UINT32  Spare;              /**< Reserved */
} RES_CANHANDLEMASTERKEY_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CANHANDLEMASTERKEY
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    BOOL32  canHandleMasterKey; /**< Returns TRUE or FALSE */
    UINT32  Spare[3];           /**< Reserved */
} RES_CANHANDLEMASTERKEY_R;

/**
 * Information list about component applications
 * @ingroup RES-COMPONENT
 */
typedef struct
{
    CHAR8   AppName[M_FILENAMELONGLEN_A];    /**< Name of component-application */
    UINT32  State;              /**< Status of component-application (RES_S_RUN or RES_S_ERROR) */
    UINT32  NbOfComp;           /**< Number of components of component-application */
    UINT32  Spare[4];           /**< Reserved */
} RES_COMPAPPINFO;

/**
 * Structure for the SMI-Call #RES_PROC_COMPAPPINFOLST
 */
typedef struct
{
    UINT32  StartIdx;           /**< Start index to component-application list */
    UINT32  Spare[4];           /**< Reserved */
} RES_COMPAPPLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_COMPAPPINFOLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfApp;    /**< Number of component-applications */
    UINT32          NbOfRetApp; /**< Number of returned component-applications by call */
    UINT32          Spare[4];   /**< Reserved */
    RES_COMPAPPINFO Inf[1];     /**< List component-application information */
} RES_COMPAPPLST_R;

/**
 * Information list about components of an application
 */
typedef struct
{
    CHAR8   CompName[M_MODNAMELEN_A];    /**< Name of component instance */
    UINT32  State;              /**< Status of component (@ref RES_S_) */
    UINT32  Spare[4];           /**< Reserved */
} RES_COMPINFO;

/**
 * Structure for the SMI-Call #RES_PROC_COMPINFOLST
 */
typedef struct
{
    CHAR8   AppName[M_FILENAMELONGLEN_A];    /**< Name of component-application instance */
    UINT32  StartIdx;           /**< Start index to component list */
    UINT32  Spare[4];           /**< Reserved */
} RES_COMPLST_C;

/**
 * Structure for the SMI-Reply #RES_PROC_COMPINFOLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfComp;   /**< Number of components */
    UINT32          NbOfRetComp;     /**< Number of returned components by call */
    UINT32          Spare[4];   /**< Reserved */
    RES_COMPINFO    Inf[1];     /**< List of component information */
} RES_COMPLST_R;

/**
 * Progress information.
 * @ingroup RES-PROGRESS
 * @since V4.11 Release
 */
typedef struct
{
    /**
     * @brief Progress status.
     *  - #RES_PROGRESS_S_IDLE ... @copybrief #RES_PROGRESS_S_IDLE
     *  - #RES_PROGRESS_S_RUNNING ... @copybrief #RES_PROGRESS_S_RUNNING
     *  - #RES_PROGRESS_S_CANCEL ... @copybrief #RES_PROGRESS_S_CANCEL
     *  - #RES_PROGRESS_S_FINISHED ... @copybrief #RES_PROGRESS_S_FINISHED
     */
    UINT32  Status;
    /**
     * @brief Progress option flags.
     *  - #RES_PROGRESS_OPT_CANCELABLE ... @copybrief #RES_PROGRESS_OPT_CANCELABLE
     */
    UINT32  Options;
    SINT32  Result;             /**< @brief Progress result code. */
    UINT32  Spare1[4];          /**< Reserved */
    UINT32  Task;               /**< @brief Actual task number */
    UINT32  TotalTask;          /**< @brief Total number of tasks or @c 0 if not available. */
    UINT32  Work;               /**< @brief Actual number of work units completed */
    UINT32  TotalWork;          /**< @brief Total number of work units or @c 0 if not available */
    UINT32  Spare2[5];          /**< Reserved */
} RES_PROGRESS;

/**
 * Structure for the SMI-Call #RES_PROC_PROGRESSGET
 */
typedef struct
{
    SINT32  Pid;                /**< Progress ID */
} RES_PROGRESSGET_C;

/**
 * Structure for the SMI-Reply #RES_PROC_PROGRESSGET
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    RES_PROGRESS    Progress;   /**< Updated progress information */
} RES_PROGRESSGET_R;

/**
 * Structure for the SMI-Call #RES_PROC_PROGRESSDEL
 */
typedef struct
{
    SINT32  Pid;                /**< Progress ID */
} RES_PROGRESSDEL_C;

/**
 * Structure for the SMI-Reply #RES_PROC_PROGRESSDEL
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} RES_PROGRESSDEL_R;

/**
 * Structure for the SMI-Call #RES_PROC_PROGRESSCANCEL
 */
typedef struct
{
    SINT32  Pid;                /**< Progress ID */
} RES_PROGRESSCANCEL_C;

/**
 * Structure for the SMI-Reply #RES_PROC_PROGRESSCANCEL
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} RES_PROGRESSCANCEL_R;

/**
 * Structure for the SMI-Call #RES_PROC_SCEPRENEW
 */
typedef struct
{
    BOOL8   ForceGetCert;       /**< Get certificate with challenge; do not use local certificate */
    UINT8   Spare0[3];          /**< Not used, must be 0 for now */
    UINT32  Spare[4];           /**< Not used, must be 0 for now */
} RES_SCEPRENEW_C;

/**
 * Structure for the SMI-Reply #RES_PROC_SCEPRENEW
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Pid;                /**< Progress ID */
    UINT32  Spare[3];           /**< Not used, must be 0 for now */
} RES_SCEPRENEW_R;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPT_MKSET
 */
typedef struct
{
    CHAR8   Password[RES_CRYPT_MK_PASSWORDLEN];  /**< Master-key password */
    UINT32  Spare[8];           /**< Not used, must be 0 for now */
} RES_CRYPT_MKSET_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPT_MKSET
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[3];           /**< Not used, must be 0 for now */
} RES_CRYPT_MKSET_R;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPT_MKDEL
 */
typedef struct
{
    UINT32  Spare[8];           /**< Not used, must be 0 for now */
} RES_CRYPT_MKDEL_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPT_MKDEL
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} RES_CRYPT_MKDEL_R;

/**
 * Master-Key information.
 * @ingroup RES-CRYPT
 * @since V4.11 Release
 */
typedef struct
{
    BOOL8   Valid;              /**< Flag indicating if a master-key is set and valid */
    BOOL8   Spare1[3];          /**< Not used, must be 0 for now */
    UINT8   Spare2[512];        /**< Not used, must be 0 for now */
} RES_MKINFO;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPT_MKINFO
 */
typedef struct
{
    UINT32  Spare[8];           /**< Not used, must be 0 for now */
} RES_CRYPT_MKINFO_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPT_MKINFO
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    RES_MKINFO  Info;           /**< Master-Key information. */
} RES_CRYPT_MKINFO_R;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPT_VAULTADD
 */
typedef struct
{
    CHAR8   KeyId[RES_CRYPT_VAULT_KEYLEN];   /**< Key ID (0-terminated string) */
    CHAR8   Secret[RES_CRYPT_VAULT_SECLEN];  /**< Secret value (0-terminated string) */
    UINT32  Spare[8];           /**< Not used, must be 0 for now */
} RES_CRYPT_VAULTADD_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPT_VAULTADD
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} RES_CRYPT_VAULTADD_R;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPT_VAULTGET
 */
typedef struct
{
    CHAR8   KeyId[RES_CRYPT_VAULT_KEYLEN];   /**< Key ID / alias (0-terminated string) */
    UINT32  Spare[8];           /**< Not used, must be 0 for now */
} RES_CRYPT_VAULTGET_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPT_VAULTGET
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    CHAR8   Secret[RES_CRYPT_VAULT_SECLEN];  /**< Secret value (0-terminated string) */
    UINT32  Spare[8];           /**< Not used, must be 0 for now */
} RES_CRYPT_VAULTGET_R;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPT_VAULTDEL
 */
typedef struct
{
    CHAR8   KeyId[RES_CRYPT_VAULT_KEYLEN];   /**< Key ID / alias (0-terminated string) */
    UINT32  Spare[8];           /**< Not used, must be 0 for now */
} RES_CRYPT_VAULTDEL_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPT_VAULTDEL
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} RES_CRYPT_VAULTDEL_R;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPT_TCVOLMAKE
 */
typedef struct
{
    CHAR8   ImageName[M_PATHLEN_A];  /**< File path where to create the volume image (e.g. "/cfc0/crypt01.tc") */
    UINT32  ImageSize;          /**< Volume image size in bytes. */
    UINT32  Options;            /**< Option flags */
    UINT32  Spare1[8];          /**< Not used, must be 0 for now */
    CHAR8   Hash[RES_CRYPT_TC_ALGNAMELEN];   /**< Hash algorithm (example "SHA512") */
    CHAR8   Cipher[RES_CRYPT_TC_ALGNAMELEN];     /**< Encryption algorithm (example "AES-256-XTS") */
    CHAR8   Password[RES_CRYPT_TC_PASSWORDLEN];  /**< Encryption password */
    UINT32  Spare2[64];         /**< Not used, must be 0 for now */
} RES_CRYPT_TCVOLMAKE_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPT_TCVOLMAKE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Pid;                /**< Progress ID */
    UINT32  Spare[2];           /**< Not used, must be 0 for now */
} RES_CRYPT_TCVOLMAKE_R;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPT_TCVOLMOUNT
 */
typedef struct
{
    CHAR8   MountPoint[RES_MNAMELEN_A];  /**< Mount point, name of device (example "/crypt01") */
    CHAR8   ImageName[M_PATHLEN_A];  /**< File path to encrypted volume image (example "/cfc0/crypt01.tc") */
    CHAR8   Password[RES_CRYPT_TC_PASSWORDLEN];  /**< Encryption password */
    UINT32  Spare[8];           /**< Not used, must be 0 for now */
} RES_CRYPT_TCVOLMOUNT_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPT_TCVOLMOUNT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Pid;                /**< Progress ID */
    UINT32  Spare[2];           /**< Not used, must be 0 for now */
} RES_CRYPT_TCVOLMOUNT_R;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPT_TCVOLUNMOUNT
 */
typedef struct
{
    CHAR8   MountPoint[RES_MNAMELEN_A];  /**< Mount point, name of device (example "/crypt01") */
    UINT32  Spare[8];           /**< Not used, must be 0 for now */
} RES_CRYPT_TCVOLUNMOUNT_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPT_TCVOLUNMOUNT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[3];           /**< Not used, must be 0 for now */
} RES_CRYPT_TCVOLUNMOUNT_R;

/**
 * Algorithm name
 * @since V4.11 Release
 */
typedef struct
{
    CHAR8   Name[RES_CRYPT_TC_ALGNAMELEN];   /**< Algorithm name */
} RES_CRYPT_TC_ALGORITHM;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPT_TCVOLGETALGORITHM
 */
typedef struct
{
    UINT32  Spare[8];           /**< Not used, must be 0 for now */
} RES_CRYPT_TCVOLGETALGORITHM_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPT_TCVOLGETALGORITHM
 */
typedef struct
{
    SINT32                  RetCode;     /**< Return Code */
    UINT32                  CountHash;   /**< Elements in the following list */
    RES_CRYPT_TC_ALGORITHM  ListHash[1];     /**< List of supported hash algorithm */
    UINT32                  CountCipher;     /**< Elements in the following list */
    RES_CRYPT_TC_ALGORITHM  ListCipher[1];   /**< List of supported cipher algorithm */
    UINT32                  Spare[16];   /**< Not used, must be 0 for now */
} RES_CRYPT_TCVOLGETALGORITHM_R;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPT_PKEYADD
 */
typedef struct
{
    CHAR8   KeyId[RES_CRYPT_VAULT_KEYLEN];   /**< Key ID (0-terminated string) */
    CHAR8   KeyFile[M_PATHLEN_A];    /**< Key file path */
    CHAR8   Password[64];       /**< PEM password */
    UINT32  Spare[8];           /**< Not used, must be 0 for now */
} RES_CRYPT_PKEYADD_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPT_PKEYADD
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[3];           /**< Not used, must be 0 for now */
} RES_CRYPT_PKEYADD_R;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPT_PKEYDEL
 */
typedef struct
{
    CHAR8   KeyId[RES_CRYPT_VAULT_KEYLEN];   /**< Key ID (0-terminated string) */
    UINT32  Spare[4];           /**< Not used, must be 0 for now */
} RES_CRYPT_PKEYDEL_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPT_PKEYDEL
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[3];           /**< Not used, must be 0 for now */
} RES_CRYPT_PKEYDEL_R;

/**
 * Structure for the SMI-Call #RES_PROC_CRYPT_PKEYINFO
 */
typedef struct
{
    CHAR8   KeyId[RES_CRYPT_VAULT_KEYLEN];   /**< Key ID (0-terminated string) */
    UINT32  Spare[4];           /**< Not used, must be 0 for now */
} RES_CRYPT_PKEYINFO_C;

/**
 * Structure for the SMI-Reply #RES_PROC_CRYPT_PKEYINFO
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Type;               /**< Key type (0=RSA) */
    UINT32  Size;               /**< Size in bits */
    UINT32  Spare2[5];          /**< Not used, must be 0 for now */
} RES_CRYPT_PKEYINFO_R;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
