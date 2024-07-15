/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     smi.h
* @author   Diem
* @brief    Standard Module Interface Library
*           This file contains all definitions and declarations exported by
*           the Standard Module Interface Library, that could be used by modules
*           running on another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef SMI__H
#define SMI__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>
#include <res_user.h>
#include <svi.h>

/**
 * @addtogroup SMI-DEF
 * @{
 */
#define SMI_LOCALCPU    0   /**< Address of local CPU */
#define SMI_STDPROTVERS 2   /**< Standard version for all RPC, that must be supported by all modules */
#define SMI_DESCLEN     79  /**< Maximum size of module description without '\0' termination */
#define SMI_DESCLEN_A   ((SMI_DESCLEN + 1 + 3) & 0xfffffffc)     /**< SMI_DESCLEN + '\0' + aligned */

/**
 * @name Defines for the elements of an SMI Module Number
 * @{
 */

#define SMI_BASEMODUL   0x20000000   /**< Base of module number (user RPC range as defined by SUN)) */
#define SMI_MAXMODUL    256 /**< Maximum number of modules */
#define SMI_MODIDXMASK  0x000000ff   /**< Mask for index part of module */
#define SMI_NOMODCHECK  0x00001000   /**< Bit to suppress the module number validation */
#define SMI_RCNTMASK    0x000fe000   /**< Mask for restart count */
#define SMI_RCNTPOS     13  /**< Bit position of SMI_RCNTMASK */
#define SMI_MODCNSTMSK  0xfff00fff   /**< Mask for fixed part of module number */
#define SMI_MODRANGEMSK 0xfff00f00   /**< Mask for fixed part of all module numbers */
/** @} */

/**
 * @name Defines for the Port Numbers
 * @{
 */

#define SMI_BASEPORT    3000     /**< Base port number */
#define SMI_TCPPORT     3500     /**< Port number for TCP socket */
#define SMI_QSOAPPORT   80  /**< Port number for QSOAP socket */
#define SMI_SSLPORT     443 /**< Port number for SSL socket */
/** @} */

/**
 * @name Defines for maximum SMI Message Sizes
 * @{
 */

#define SMI_TCPBUFFLEN      4096     /**< Minimum buffer length for a TCP message */
#define SMI_UDPBUFFLEN      2048     /**< Minimum buffer length for a UDP message */
#define SMI_QSOAPBUFFLEN    3072     /**< Minimum buffer length for a QSOAP message */
#define SMI_RPCHDRLEN       0x28     /**< Maximum size of RPC-Header, sizeof(RPC_MSG) */
#define SMI_DATALEN         (SMI_UDPBUFFLEN - SMI_RPCHDRLEN)     /**< Maximum size of of usable data */
#define SMI_UDP_RETRIES     5    /**< Number of UDP retries */
/** @} */

/**
 * @name Possible error codes for SMI_*_R.RetCode
 * @{
 */

#define SMI_E_OK        M_E_OK   /**< @copybrief #M_E_OK */
#define SMI_E_NAME      (M_ES_SMI | M_E_BADNAME)     /**< @copybrief #M_E_BADNAME */
#define SMI_E_FAILED    (M_ES_SMI | M_E_FAILED)  /**< @copybrief #M_E_FAILED */
#define SMI_E_PARM      (M_ES_SMI | M_E_PARM)    /**< @copybrief #M_E_PARM */
#define SMI_E_SUPPORT   (M_ES_SMI | M_E_NOTSUPP)     /**< @copybrief #M_E_NOTSUPP */
#define SMI_E_NOMEM     (M_ES_SMI | M_E_NOMEM)   /**< @copybrief #M_E_NOMEM */
#define SMI_E_NOMOD2    (M_ES_SMI | M_E_NOMOD2)  /**< @copybrief #M_E_NOMOD2 */
#define SMI_E_BADSESS   (M_ES_SMI | M_E_BADSESS)     /**< @copybrief #M_E_BADSESS */
#define SMI_E_FULLITER  (M_ES_SMI | M_E_FULL)    /**< At the moment too many iterative requests are pending. */
/** @} */

/**
 * @name Possible values for SMI_LICENSEEVENT_C.Event
 * @{
 */

#define SMI_LICENSE_PLUG    0    /**< License plug event */
#define SMI_LICENSE_PULL    1    /**< License pull event */
/** @} */

/**
 * @name System permissions
 * @{
 */

#define SMI_PERM_QUERYSYSINFO       0x0000000000000001LL     /**< Query system-information */
#define SMI_PERM_MEASURERUNTIME     0x0000000000000002LL     /**< Start/stop runtime-measurement */
#define SMI_PERM_EDITSWMODULE       0x0000000000000040LL     /**< Edit software module (#SMI_PROC_RUN, #SMI_PROC_RESET) */
#define SMI_PERM_SETDATETIME        0x0000000000000080LL     /**< Set system date and time */
#define SMI_PERM_FREAD              0x0000000000000100LL     /**< Read file (except MConfig.ini) */
#define SMI_PERM_FWRITE             0x0000000000000200LL     /**< Write file (except MConfig.ini) */
#define SMI_PERM_SVIREAD            0x0000000000000400LL     /**< Read SVI variables (except MIO inputs) */
#define SMI_PERM_SVIWRITE           0x0000000000000800LL     /**< Write SVI variables (except MIO outputs) */
#define SMI_PERM_INOUTREAD          0x0000000000004000LL     /**< Read MIO inputs */
#define SMI_PERM_INOUTWRITE         0x0000000000008000LL     /**< Write MIO outputs */
#define SMI_PERM_UPDATESYSSOFTWARE  0x0000000000020000LL     /**< Update system-software/write to 'sys' or 'drv'-directory */
#define SMI_PERM_UPDATEFIRMWARE     0x0000000000040000LL     /**< Update firmware */
#define SMI_PERM_REBOOT             0x0000000000080000LL     /**< Reboot */
#define SMI_PERM_READMCONFIG        0x0000000001000000LL     /**< Read MConfig.ini */
#define SMI_PERM_WRITEMCONFIG       0x0000000002000000LL     /**< Write MConfig.ini */
#define SMI_PERM_READCONSOLE        0x0000000004000000LL     /**< Read from console */
#define SMI_PERM_WRITECONSOLE       0x0000000008000000LL     /**< Write to console */
#define SMI_PERM_WRITETOBOOTDEV     0x0000000010000000LL     /**< Write to boot-device */
#define SMI_PERM_FORMAT             0x0000000020000000LL     /**< Format a device */
#define SMI_PERM_QUERYUSERINFO      0x0000000040000000LL     /**< Query user-information */
#define SMI_PERM_BROWSESVI          0x0000000080000000LL     /**< Browse svi-variables */
#define SMI_PERM_TELNET             0x0000000100000000LL     /**< Open telnet session */
#define SMI_PERM_WEBSERVER          0x0000000200000000LL     /**< Open web server session */
/** @} */

/**
 * @name Possible values for ProtVers in smi_SendCall
 * @{
 */

#define SMI_NOFREE      0x01000000   /**< Do not free 'Data' memory in smi_SendCall() after usage */
#define SMI_NOREPLY     0x20000000   /**< Do not send reply (only for TCP-Stream allowed) */
#define SMI_AUTH        0x40000000   /**< Additional authentication parameter in smi_SendCall() is supplied */
#define SMI_UDP         0x00000000   /**< Use UDP instead of TCP, see smi_SendCall() */
#define SMI_TCP         0x80000000   /**< Use TCP instead of UDP, see smi_SendCall() */
#define SMI_TCPSTREAM   0x00008000   /**< Use a TCP stream, this means the reply will be immediately received */
#define SMI_QSOAP       0x00004000   /**< Use bachmann proprietary SOAP as transport protocol (Quick SOAP) */
#define SMI_SSL         0x08000000   /**< Use SSL transport protocol */
#define SMI_PLAINTXTPWD 0x04000000   /**< Send plain text password */
#define SMI_PROTVERMASK 0x000000FF   /**< Mask for version in ProtVers */
/** @} */
/** @} */

/**
 * @addtogroup SMI-SMI
 * @{
 */

/**
 * @name SMI commands supported by each SW-Module
 * @{
 */

/**
 * @brief This function is used to ping a software module. This function is also a RPC
 *        standard by Sun Microsystems GmbH.
 */
#define SMI_PROC_NULL       0
/**
 * @brief This function is used to initialise a software module.
 *
 * @param[in]   #SMI_INIT_C
 * @param[out]  #SMI_INIT_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_NAME
 * @retval #SMI_E_FAILED
 * @retval #SMI_E_SUPPORT
 * @retval #SMI_E_NOMEM
 */
#define SMI_PROC_INIT       2
/**
 * @brief This function is used to force a running software module to delete itself.
 *
 * @param[in]   #SMI_DEINIT_C
 * @param[out]  #SMI_DEINIT_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_NAME
 * @retval #SMI_E_FAILED
 * @retval #SMI_E_SUPPORT
 * @retval #SMI_E_NOMEM
 */
#define SMI_PROC_DEINIT     4
/**
 * @brief This function is used to reset a running software module.
 *
 * @param[in]   #SMI_RESET_C
 * @param[out]  #SMI_RESET_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_NAME
 * @retval #SMI_E_FAILED
 * @retval #SMI_E_SUPPORT
 * @retval #SMI_E_NOMEM
 */
#define SMI_PROC_RESET      6
/**
 * @brief This function is used to inform a software module about a new configuration.
 *        If an online configuration does not make sense, #SMI_E_SUPPORT is returned.
 *
 * @param[in]   #SMI_NEWCFG_C
 * @param[out]  #SMI_NEWCFG_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_NAME
 * @retval #SMI_E_FAILED
 * @retval #SMI_E_SUPPORT
 * @retval #SMI_E_NOMEM
 */
#define SMI_PROC_NEWCFG     8
/**
 * @brief This function is used to request a software module to return its information.
 *
 * If the function is executed properly (RetCode = #SMI_E_OK), all information of the
 * desired module is returned. The information consists of the instance name, a short
 * description, the version information and the current status (#RES_S_RUN or #RES_S_ERROR).
 *
 * @param[in]   #SMI_GETINFO_C
 * @param[out]  #SMI_GETINFO_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_NAME
 * @retval #SMI_E_FAILED
 * @retval #SMI_E_SUPPORT
 * @retval #SMI_E_NOMEM
 */
#define SMI_PROC_GETINFO    10
/**
 * @brief This message is used to inform a software module that all components are
 *        installed and are able to communicate (their SMI and SVI do exist) and the
 *        application can be started. This mechanism reduces dependency during booting.
 *
 * @param[in]   #SMI_ENDOFINIT_C
 * @param[out]  #SMI_ENDOFINIT_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_NAME
 * @retval #SMI_E_FAILED
 * @retval #SMI_E_SUPPORT
 * @retval #SMI_E_NOMEM
 */
#define SMI_PROC_ENDOFINIT  14
/**
 * @brief This function is used to set the debug mode of a software module.
 *
 * @param[in]   #SMI_SETDBG_C
 * @param[out]  #SMI_SETDBG_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_NAME
 * @retval #SMI_E_FAILED
 * @retval #SMI_E_SUPPORT
 * @retval #SMI_E_NOMEM
 */
#define SMI_PROC_SETDBG     16
/**
 * @brief This function is used to stop a software module. In the STOP state,
 *        the software module only answers standard SMI messages and passive
 *        SVI functions.
 *
 * @param[in]   #SMI_STOP_C
 * @param[out]  #SMI_STOP_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_NAME
 * @retval #SMI_E_FAILED
 * @retval #SMI_E_SUPPORT
 * @retval #SMI_E_NOMEM
 */
#define SMI_PROC_STOP       18
/**
 * @brief This function is used to restart a stopped software module.
 *
 * @param[in]   #SMI_RUN_C
 * @param[out]  #SMI_RUN_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_NAME
 * @retval #SMI_E_FAILED
 * @retval #SMI_E_SUPPORT
 * @retval #SMI_E_NOMEM
 */
#define SMI_PROC_RUN        20
/** @} */

/**
 * @name SMI commands used by special SW-Modules
 * @{
 */

/**
 * @brief This function is used to get the status of the mapping (component manager).
 *
 * @param[in]   #SMI_GETMAPINFOLST_C
 * @param[out]  #SMI_GETMAPINFOLST_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_PROC
 * @retval #SMI_E_FAILED
 * @retval #SMI_E_PARM
 */
#define SMI_PROC_GETMAPINFOLST  78
/**
 * @brief This function is used to send a license event to a software module.
 *
 * @note The reply of the software module is not evaluated.
 *
 * @param[in]   #SMI_LICENSEEVENT_C
 * @param[out]  #SMI_LICENSEEVENT_R
 *
 * @retval #SMI_E_OK
 */
#define SMI_PROC_LICENSEEVENT   80
/**
 * @brief This function is used to call a software module (access checker) to update
 *        the SVI rights and ranges.
 *
 * The access checker must update all rights or the rights of the mentioned module
 * with the functions #svi_SetVarRights() and #svi_SetVarRange().
 *
 * When loading a software module or during a PLC online change, a call with the
 * respective module name is sent. During the boot process, after all modules are loaded,
 * the system sends a call with empty module name, representing all modules.
 *
 * @param[in]   #SMI_SETSVIACCESS_C
 * @param[out]  #SMI_SETSVIACCESS_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_FAILED
 */
#define SMI_PROC_SETSVIACCESS   82
/**
 * @brief This function is used to call a software module (login checker) from the function
 *        #RES_PROC_LOGIN2, #RES_PROC_LOGIN or #RES_PROC_XLOGIN.
 *
 * @note This function is called with system compatibility >= 370.
 *
 * If the Local parameter in UserAuth is set, this is a login of a local service and the
 * password must not be checked.
 *
 * The software module must respond within a certain time. Half of the time ReplyTimeout
 * specified under the group (SmiHandler) is used as the timeout value. The other half
 * is intended for the higher ranking function #RES_PROC_LOGIN2, #RES_PROC_LOGIN or
 * #RES_PROC_XLOGIN.
 *
 * If the parameter `RetCode` = #RES_E_OK, the user settings, permissions and additional
 * user data are returned.
 *
 * @note In order to impede a brute-force attack, the login checker can deliver a DelayTime
 *       at RetCode != #RES_E_OK to the system. The login response is sent after the duration
 *       of this time. At DelayTime = 0, the system does this automatically.
 *
 * @param[in]   #SMI_XLOGIN2_C
 * @param[out]  #SMI_XLOGIN2_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_PROC
 * @retval #SMI_E_FAILED
 */
#define SMI_PROC_XLOGIN2        84
/**
 * @brief This function is used to call a software module (access checker) from the
 *        function #RES_PROC_REQUESTACC.
 *
 * The request of active write access is forwarded to the access checker. The
 * user's session ID is received via the function #smi_Receive2(). User data can be
 * requested using the session ID with the function #res_sec_GetUserData(), and write
 * access is activated/deactivated with the function #res_sec_SetActiveUser().
 *
 * @param[in]   #SMI_XREQUESTACC_C
 * @param[out]  #SMI_XREQUESTACC_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_FAILED
 */
#define SMI_PROC_XREQUESTACC    86
/**
 * @brief This function is used to call a software module (access checker) from the
 *        function #RES_PROC_RELEASEACC.
 *
 * The withdrawal of the active write access is forwarded to the access manager. The
 * user's session ID is received via the function #smi_Receive2(). User data can be
 * requested using the session ID with the function #res_sec_GetUserData(), and write
 * access is activated/deactivated with the function #res_sec_SetActiveUser().
 *
 * @param[in]   #SMI_XRELEASEACC_C
 * @param[out]  #SMI_XRELEASEACC_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_FAILED
 */
#define SMI_PROC_XRELEASEACC    88
#define SMI_PROC_TESTSUITE      90   /**< @brief This function is used in the test suite. */
/**
 * @brief This call is sent by the system to a login checker module (if available).
 *
 * It is used to notify the login checker that the connection to the client
 * still exists. At least one call is sent in a maximum 15 second cycle.
 *
 * @note The reply of the login checker module is not evaluated.
 *
 * @param[in]   #SMI_ALIVE_C
 * @param[out]  #SMI_ALIVE_R
 *
 * @retval #SMI_E_OK
 */
#define SMI_PROC_ALIVE          92
/**
 * @brief This function is used to call a software module (login checker) from the function
 *        #RES_PROC_LOGIN2, #RES_PROC_LOGIN or #RES_PROC_XLOGIN.
 *
 * @note This function is only called with system compatibility < 370 or when the
 *       login checker replies the #SMI_PROC_XLOGIN2 call with the error #SMI_E_PROC.
 *
 * The software module must respond within a certain time. Half of the time ReplyTimeout
 * specified under the group (SmiHandler) is used as the timeout value. The other half
 * is intended for the higher ranking function #RES_PROC_LOGIN2, #RES_PROC_LOGIN or
 * #RES_PROC_XLOGIN.
 *
 * @param[in]   #SMI_XLOGIN_C
 * @param[out]  #SMI_XLOGIN_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_PROC
 * @retval #SMI_E_FAILED
 * @deprecated See #SMI_PROC_XLOGIN2.
 */
#define SMI_PROC_XLOGIN         94
/**
 * @brief This SMI function is used to call a software module (login checker) from the
 *        function #RES_PROC_XLOGOUT or #RES_PROC_LOGOUT.
 *
 * @param[in]   #SMI_XLOGOUT_C
 * @param[out]  #SMI_XLOGOUT_R
 *
 * @retval #SMI_E_OK
 * @retval #SMI_E_PROC
 * @retval #SMI_E_FAILED
 */
#define SMI_PROC_XLOGOUT        96
#define SMI_PROC_NULL2          98   /**< @brief This function is used to ping a software module. No reply is expected. */
/** @} */
/**
 * Structure for the SMI-Call #SMI_PROC_INIT
 */
typedef struct
{
    CHAR8   Name[M_MODNAMELEN_A];    /**< Name of module instance */
} SMI_INIT_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_INIT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} SMI_INIT_R;

/**
 * Structure for the SMI-Call #SMI_PROC_DEINIT
 */
typedef struct
{
    CHAR8   Name[M_MODNAMELEN_A];    /**< Name of module instance */
} SMI_DEINIT_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_DEINIT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} SMI_DEINIT_R;

/**
 * Structure for the SMI-Call #SMI_PROC_RESET
 */
typedef struct
{
    CHAR8   Name[M_MODNAMELEN_A];    /**< Name of module instance */
} SMI_RESET_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_RESET
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} SMI_RESET_R;

/**
 * Structure for the SMI-Call #SMI_PROC_NEWCFG
 */
typedef struct
{
    CHAR8   Name[M_MODNAMELEN_A];    /**< Name of module instance */
} SMI_NEWCFG_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_NEWCFG
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} SMI_NEWCFG_R;

/**
 * Structure for the SMI-Call #SMI_PROC_GETINFO
 */
typedef struct
{
    CHAR8   Name[M_MODNAMELEN_A];    /**< Name of module instance */
} SMI_GETINFO_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_GETINFO
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    CHAR8   Name[M_MODNAMELEN_A];    /**< Name of module instance */
    CHAR8   Desc[SMI_DESCLEN_A];     /**< Description of module */
    UINT32  VersType;           /**< Version type; #M_VER_ALPHA, etc. */
    UINT32  VersCode[3];        /**< Version code */
    /**
     * Status of module; possible is
     * RES_S_RUN, RES_S_ERROR, etc.
     */
    UINT32  State;
    UINT32  DebugMode;          /**< Bit image of debug mode */
} SMI_GETINFO_R;

/**
 * Enumeration for the SMI-Reply #SMI_COMPCHINFO.Type
 */
typedef enum
{
    OutChan = 0,                /**< Variable of type out */
    InChan  = 1,                /**< Variable of type in */
} CHANTYPE;

/**
 * Sub-Structure for the SMI-Reply #SMI_GETMAPINFOLST_R.ChLst
 */
typedef struct
{
    UINT32      State;          /**< Status of channel */
    CHANTYPE    Type;           /**< Type of channel (in/out) */
    CHAR8       CompVarName[SVI_ADDRLEN_A];  /**< Name of variable (Component Manager) */
    CHAR8       MapVarName[SVI_ADDRLEN_A];   /**< Name of mapped variable */
} SMI_COMPCHINFO;

/**
 * Structure for the SMI-Call #SMI_PROC_GETMAPINFOLST
 */
typedef struct
{
    UINT32  StartIdx;           /**< Start index to channel list */
    UINT32  Spare1[4];          /**< Must be 0 for now */
} SMI_GETMAPINFOLST_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_GETMAPINFOLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfInCh;   /**< Number of list elements Input channels */
    UINT32          NbOfOutCh;  /**< Number of list elements Output channels */
    UINT32          NbOfRetCh;  /**< Number of returned channels by call */
    UINT32          Spare1[4];  /**< Must be 0 for now */
    SMI_COMPCHINFO  ChLst[1];   /**< List of channel informations */
} SMI_GETMAPINFOLST_R;

/**
 * Structure for the SMI-Call #SMI_PROC_ENDOFINIT
 */
typedef struct
{
    CHAR8   Name[M_MODNAMELEN_A];    /**< Name of module instance */
} SMI_ENDOFINIT_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_ENDOFINIT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} SMI_ENDOFINIT_R;

/**
 * Structure for the SMI-Call #SMI_PROC_SETDBG
 */
typedef struct
{
    CHAR8   Name[M_MODNAMELEN_A];    /**< Name of module instance */
    UINT32  DebugMode;          /**< Bit image of debug mode */
} SMI_SETDBG_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_SETDBG
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} SMI_SETDBG_R;

/**
 * Structure for the SMI-Call #SMI_PROC_STOP
 */
typedef struct
{
    CHAR8   Name[M_MODNAMELEN_A];    /**< Name of module instance */
} SMI_STOP_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_STOP
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} SMI_STOP_R;

/**
 * Structure for the SMI-Call #SMI_PROC_RUN
 */
typedef struct
{
    CHAR8   Name[M_MODNAMELEN_A];    /**< Name of module instance */
} SMI_RUN_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_RUN
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} SMI_RUN_R;


typedef struct                          /**< Structure for the SMI-Reply */
{                                       /**< Dummy reply for TCP-stream */
    SINT32      RetCode;                /**< Return code */
    UINT32      Spare1;                 /**< Must be 0 for now */
    UINT32      Spare2;                 /**< Must be 0 for now */
} SMI_DUMMY_R;
/**
 * Structure for the SMI-Call #SMI_PROC_ALIVE
 */
typedef struct
{
    UINT32  IpAddress;          /**< IP address of client */
    UINT32  LoginSessId;        /**< Identification of login session */
    BOOL8   Internal;           /**< Generated internal */
    UINT8   Spare1[3];          /**< Must be 0 for now */
    CHAR8   UserName[M_UNAMELEN_A];  /**< User name in readable ASCII */
} SMI_ALIVE_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_ALIVE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare1;             /**< Must be 0 for now */
    UINT32  Spare2;             /**< Must be 0 for now */
} SMI_ALIVE_R;

/**
 * Structure for the SMI-Call #SMI_PROC_XLOGIN
 */
typedef struct
{
    UINT32  UserParm;           /**< User parameter passed to checker */
    UINT32  IpAddress;          /**< IP address of client */
    UINT32  LoginSessId;        /**< Identification of login session */
    UINT32  Spare1;             /**< Must be 0 for now */
    CHAR8   UserName[M_UNAMELEN_A];  /**< User name in readable ASCII */
    CHAR8   Password[M_PWORDLEN];    /**< password */
} SMI_XLOGIN_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_XLOGIN
 */
typedef struct
{
    SINT32                  RetCode;     /**< Return Code */
    RES_LOGIN_PERMISSIONS   Permissions;     /**< User's permission bits */
    UINT8                   UserData[128];   /**< User data returned by checker */
} SMI_XLOGIN_R;

/**
 * Structure for the SMI-Call #SMI_PROC_XLOGIN2
 */
typedef struct
{
    UINT32          UserParm;   /**< User parameter passed to checker */
    RES_USER_AUTH   UserAuth;   /**< @copybrief RES_USER_AUTH */
    CHAR8           Password[M_PWORDLEN2];   /**< password */
    UINT32          Spare1;     /**< Must be 0 for now */
    UINT32          Spare2;     /**< Must be 0 for now */
} SMI_XLOGIN2_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_XLOGIN2
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    RES_USER_ACCESS UserAcc;    /**< @copybrief RES_USER_ACCESS */
    UINT32          DelayTime;  /**< Delay time in ms (0=auto) */
    UINT32          Spare2;     /**< Must be 0 for now */
    UINT8           UserData[128];   /**< User data returned by checker */
} SMI_XLOGIN2_R;

/**
 * Structure for the SMI-Call #SMI_PROC_XREQUESTACC
 */
typedef struct
{
    UINT32  UserParm;           /**< User parameter */
    UINT32  Spare2;             /**< Must be 0 for now */
    UINT32  Spare3;             /**< Must be 0 for now */
    UINT32  Spare4;             /**< Must be 0 for now */
} SMI_XREQUESTACC_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_XREQUESTACC
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare1;             /**< Must be 0 for now */
    UINT32  Spare2;             /**< Must be 0 for now */
    UINT32  Spare3;             /**< Must be 0 for now */
    UINT32  Spare4;             /**< Must be 0 for now */
} SMI_XREQUESTACC_R;

/**
 * Structure for the SMI-Call #SMI_PROC_XRELEASEACC
 */
typedef struct
{
    UINT32  UserParm;           /**< User parameter */
    UINT32  Spare2;             /**< Must be 0 for now */
    UINT32  Spare3;             /**< Must be 0 for now */
    UINT32  Spare4;             /**< Must be 0 for now */
} SMI_XRELEASEACC_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_XRELEASEACC
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare1;             /**< Must be 0 for now */
    UINT32  Spare2;             /**< Must be 0 for now */
    UINT32  Spare3;             /**< Must be 0 for now */
    UINT32  Spare4;             /**< Must be 0 for now */
} SMI_XRELEASEACC_R;

/**
 * Structure for the SMI-Call #SMI_PROC_SETSVIACCESS
 */
typedef struct
{
    CHAR8   ModName[M_MODNAMELEN_A];     /**< Name of module instance */
    UINT32  Spare1;             /**< Must be 0 for now */
    UINT32  Spare2;             /**< Must be 0 for now */
    UINT32  Spare3;             /**< Must be 0 for now */
    UINT32  Spare4;             /**< Must be 0 for now */
} SMI_SETSVIACCESS_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_SETSVIACCESS
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare1;             /**< Must be 0 for now */
    UINT32  Spare2;             /**< Must be 0 for now */
    UINT32  Spare3;             /**< Must be 0 for now */
    UINT32  Spare4;             /**< Must be 0 for now */
} SMI_SETSVIACCESS_R;

/**
 * Structure for the SMI-Call #SMI_PROC_LICENSEEVENT
 */
typedef struct
{
    UINT32  Event;              /**< License event (SMI_LICENSE_xx) */
    UINT32  Spare1;             /**< Must be 0 for now */
    UINT32  Spare2;             /**< Must be 0 for now */
    UINT32  Spare3;             /**< Must be 0 for now */
    UINT32  Spare4;             /**< Must be 0 for now */
} SMI_LICENSEEVENT_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_LICENSEEVENT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare1;             /**< Must be 0 for now */
    UINT32  Spare2;             /**< Must be 0 for now */
    UINT32  Spare3;             /**< Must be 0 for now */
    UINT32  Spare4;             /**< Must be 0 for now */
} SMI_LICENSEEVENT_R;

/**
 * Structure for the SMI-Call #SMI_PROC_XLOGOUT
 */
typedef struct
{
    UINT32  UserParm;           /**< User parameter passed to checker */
    UINT32  IpAddress;          /**< IP address of client */
    UINT32  LoginSessId;        /**< Identification of login session */
    UINT8   Spare1[152];        /**< Must be 0 for now */
} SMI_XLOGOUT_C;

/**
 * Structure for the SMI-Reply #SMI_PROC_XLOGOUT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare1;             /**< Must be 0 for now */
    UINT32  Spare2;             /**< Must be 0 for now */
} SMI_XLOGOUT_R;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
