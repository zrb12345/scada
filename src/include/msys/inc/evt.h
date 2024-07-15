/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     evt.h
* @author   ROIL
* @brief    Error Handler Server
*           This file contains all definitions and declarations exported by
*           the EVT Logger, that could be used by modules running on
*           another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef EVT__H
#define EVT__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>
#include "svi.h"
#include "msys.h"
#include "res.h"

/**
 * @addtogroup EVT-DEF
 * @{
 */

/**
 * @name General definitions
 * @{
 */

#define EVT_LNAMELEN        20   /**< Size of event log name */
#define EVT_LNAMELEN_A      ((EVT_LNAMELEN + 1 + 3) & 0xfffffffc)    /**< EVT_LNAMELEN + '\0' + aligned */
#define EVT_USERNAMELEN     M_UNAMELEN2  /**< Size of `Username` attribute */
#define EVT_USERNAMELEN_A   M_UNAMELEN2_A    /**< EVT_USERNAMELEN + '\0' + aligned */
#define EVT_SERIALNBLEN     10   /**< Size of `SerialNb` attribute */
#define EVT_SERIALNBLEN_A   ((EVT_SERIALNBLEN + 1 + 3) & 0xfffffffc)     /**< EVT_SERIALNBLEN + '\0' + aligned */
#define EVT_SOURCELEN       M_MODNAMELEN     /**< Size of `Source` attribute */
#define EVT_SOURCELEN_A     M_MODNAMELEN_A   /**< EVT_SOURCELEN + '\0' + aligned */
#define EVT_VARNAMELEN      (M_MODNAMELEN + 1 + SVI_ADDRLEN)     /**< Size of `VarName` attribute */
#define EVT_VARNAMELEN_A    ((EVT_VARNAMELEN + 1 + 3) & 0xfffffffc)  /**< EVT_VARNAMELEN + '\0' + aligned */
#define EVT_VALUELEN        31   /**< Size of `ValueOld`, `ValueNew` attributes */
#define EVT_VALUELEN_A      ((EVT_VALUELEN + 1 + 3) & 0xfffffffc)    /**< EVT_VALUELEN + '\0' + aligned */
#define EVT_TASKLEN         M_TSKNAMELEN     /**< Size of `Task` attribute */
#define EVT_TASKLEN_A       M_TSKNAMELEN_A   /**< EVT_TASKLEN + '\0' + aligned */
/** @} */

/**
 * @name Possible event logs
 * @{
 */

#define EVT_L_SECURITY  1   /**< Security events */
#define EVT_L_APP1      101 /**< Application log 1 */
#define EVT_L_APP2      102 /**< Application log 2 */
#define EVT_L_APP3      103 /**< Application log 3 */
#define EVT_L_APP4      104 /**< Application log 4 */
/** @} */

/**
 * @anchor EVT_P_
 */
/**
 * @name Possible values for event profile
 * @{
 */

#define EVT_P_NONE      0   /**< Event with no additional profile data */
#define EVT_P_USER      1   /**< Event with profile data #EVT_USER_DATA */
#define EVT_P_RESOURCE  2   /**< Event with profile data #EVT_RESOURCE_DATA */
/** @} */

/**
 * @anchor EVT_T_
 */
/**
 * @name Possible values for event type
 * @{
 */

#define EVT_T_INFO  0       /**< Type info */
#define EVT_T_WARN  1       /**< Type warning */
#define EVT_T_ERROR 2       /**< Type error */
/** @} */

/**
 * @name Possible values for session mode
 * @{
 */

#define EVT_M_ALL       0   /**< Both, already existing and new entries are delivered */
#define EVT_M_ONLYNEW   1   /**< Only new entries need to be delivered */
/** @} */

/**
 * @name Possible events
 * @{
 */

#define EVT_ID_SYS_BASE             0x0000   /**< Base ID for system specific events (0x0000 - 0x0FF) */
#define EVT_ID_SVI_BASE             0x0100   /**< Base ID for SVI specific events (0x0100 - 0x01FF) */
#define EVT_ID_SMI_BASE             0x0200   /**< Base ID for SMI specific events (0x0200 - 0x02FF) */
#define EVT_ID_MOD_BASE             0x0300   /**< Base ID for MOD specific events (0x0300 - 0x03FF) */
#define EVT_ID_FILE_BASE            0x0400   /**< Base ID for file specific events (0x0400 - 0x04FF) */
#define EVT_ID_RES_BASE             0x0500   /**< Base ID for RES specific events (0x0500 - 0x06FF) */
#define EVT_ID_SSL_BASE             0x0700   /**< Base ID for SSL specific events (0x0700 - 0x07FF) */
#define EVT_ID_RESERVED             0x1000   /**< Reserved for application specific system/security events (0x1000 - 0x1FFF) */
#define EVT_ID_SYSLOGIN             (EVT_ID_SYS_BASE + 1)    /**< Client called #RES_PROC_LOGIN/#RES_PROC_LOGIN2 function */
#define EVT_ID_SYSLOGOUT            (EVT_ID_SYS_BASE + 2)    /**< Client called #RES_PROC_LOGOUT function */
#define EVT_ID_SYSREQUESTACC        (EVT_ID_SYS_BASE + 3)    /**< Client called #RES_PROC_REQUESTACC function */
#define EVT_ID_SYSRELEASEACC        (EVT_ID_SYS_BASE + 4)    /**< Client called #RES_PROC_RELEASEACC function */
#define EVT_ID_SYSAUTOLOGOUT        (EVT_ID_SYS_BASE + 5)    /**< System called #RES_PROC_LOGOUT function */
#define EVT_ID_SVISETVAL            (EVT_ID_SVI_BASE + 1)    /**< Client called #SVI_PROC_SETVAL write function */
#define EVT_ID_SMIINIT              (EVT_ID_SMI_BASE + SMI_PROC_INIT)    /**< Client called #SMI_PROC_INIT of module */
#define EVT_ID_SMIDEINIT            (EVT_ID_SMI_BASE + SMI_PROC_DEINIT)  /**< Client called #SMI_PROC_DEINIT of module */
#define EVT_ID_SMIRESET             (EVT_ID_SMI_BASE + SMI_PROC_RESET)   /**< Client called #SMI_PROC_RESET of module */
#define EVT_ID_SMINEWCFG            (EVT_ID_SMI_BASE + SMI_PROC_NEWCFG)  /**< Client called #SMI_PROC_NEWCFG of module */
#define EVT_ID_SMIENDOFINIT         (EVT_ID_SMI_BASE + SMI_PROC_ENDOFINIT)   /**< Client called #SMI_PROC_ENDOFINIT of module */
#define EVT_ID_SMISTOP              (EVT_ID_SMI_BASE + SMI_PROC_STOP)    /**< Client called #SMI_PROC_STOP of module */
#define EVT_ID_SMIRUN               (EVT_ID_SMI_BASE + SMI_PROC_RUN)     /**< Client called #SMI_PROC_RUN of module */
#define EVT_ID_SMISETDBG            (EVT_ID_SMI_BASE + SMI_PROC_SETDBG)  /**< Client called #SMI_PROC_SETDBG of module */
#define EVT_ID_MODINSTALL           (EVT_ID_MOD_BASE + MOD_PROC_INSTALL)     /**< Client called #MOD_PROC_INSTALL */
#define EVT_ID_MODJAVAINSTALL       (EVT_ID_MOD_BASE + MOD_PROC_JAVAINSTALL)     /**< Client called #MOD_PROC_JAVAINSTALL */
#define EVT_ID_MODREMOVE            (EVT_ID_MOD_BASE + MOD_PROC_REMOVE)  /**< Client called #MOD_PROC_REMOVE */
#define EVT_ID_MODSYSCFG            (EVT_ID_MOD_BASE + MOD_PROC_SYSCFG)  /**< Client called #MOD_PROC_SYSCFG */
#define EVT_ID_MODSETTIME           (EVT_ID_MOD_BASE + MOD_PROC_SETTIME)     /**< Client called #MOD_PROC_SETTIME */
#define EVT_ID_MODSETTIMEZONE       (EVT_ID_MOD_BASE + MOD_PROC_SETTIMEZONE)     /**< Client called #MOD_PROC_SETTIMEZONE */
#define EVT_ID_MODSETDATE           (EVT_ID_MOD_BASE + MOD_PROC_SETDATE)     /**< Client called #MOD_PROC_SETDATE */
#define EVT_ID_MODSETBOOT           (EVT_ID_MOD_BASE + MOD_PROC_SETBOOT)     /**< Client called #MOD_PROC_SETBOOT */
#define EVT_ID_MODNVRESET           (EVT_ID_MOD_BASE + MOD_PROC_NVRESET)     /**< Client called #MOD_PROC_NVRESET */
#define EVT_ID_MODREBOOT            (EVT_ID_MOD_BASE + MOD_PROC_REBOOT)  /**< Client called #MOD_PROC_REBOOT */
#define EVT_ID_MODFORMAT            (EVT_ID_MOD_BASE + MOD_PROC_FORMAT)  /**< Client called #MOD_PROC_FORMAT */
#define EVT_ID_MODUPDATESW          (EVT_ID_MOD_BASE + MOD_PROC_UPDATESW)    /**< Client called #MOD_PROC_UPDATESW */
#define EVT_ID_MODRESETALL          (EVT_ID_MOD_BASE + MOD_PROC_RESETALL)    /**< Client called #MOD_PROC_RESETALL */
#define EVT_ID_MODFORMAT64          (EVT_ID_MOD_BASE + MOD_PROC_FORMAT64)    /**< Client called #MOD_PROC_FORMAT64 */
#define EVT_ID_MODPARTITIONDISK     (EVT_ID_MOD_BASE + MOD_PROC_PARTITIONDISK)   /**< Client called #MOD_PROC_PARTITIONDISK */
#define EVT_ID_COPYCFG              (EVT_ID_MOD_BASE + MOD_PROC_COPYCFG)     /**< Client called #MOD_PROC_COPYCFG */
#define EVT_ID_COPYCFG2             (EVT_ID_MOD_BASE + MOD_PROC_COPYCFG2)    /**< Client called #MOD_PROC_COPYCFG2 */
#define EVT_ID_CREATEMASTERKEY      (EVT_ID_RES_BASE + RES_PROC_CREATEMASTERKEY)     /**< Client called #RES_PROC_CREATEMASTERKEY */
#define EVT_ID_RESTOREMASTERKEY     (EVT_ID_RES_BASE + RES_PROC_RESTOREMASTERKEY)    /**< Client called #RES_PROC_RESTOREMASTERKEY */
#define EVT_ID_ENCRYPTDEVICE        (EVT_ID_RES_BASE + RES_PROC_ENCRYPTDEVICE)   /**< Client called #RES_PROC_ENCRYPTDEVICE */
#define EVT_ID_DECRYPTDEVICE        (EVT_ID_RES_BASE + RES_PROC_DECRYPTDEVICE)   /**< Client called #RES_PROC_DECRYPTDEVICE */
#define EVT_ID_CRYPTPROGRESS        (EVT_ID_RES_BASE + RES_PROC_CRYPTPROGRESS)   /**< Client called #RES_PROC_CRYPTPROGRESS */
#define EVT_ID_CRYPT_MKSET          (EVT_ID_RES_BASE + RES_PROC_CRYPT_MKSET)     /**< Client called #RES_PROC_CRYPT_MKSET */
#define EVT_ID_CRYPT_MKDEL          (EVT_ID_RES_BASE + RES_PROC_CRYPT_MKDEL)     /**< Client called #RES_PROC_CRYPT_MKDEL */
#define EVT_ID_CRYPT_VAULTADD       (EVT_ID_RES_BASE + RES_PROC_CRYPT_VAULTADD)  /**< Client called #RES_PROC_CRYPT_VAULTADD */
#define EVT_ID_CRYPT_VAULTDEL       (EVT_ID_RES_BASE + RES_PROC_CRYPT_VAULTDEL)  /**< Client called #RES_PROC_CRYPT_VAULTDEL */
#define EVT_ID_CRYPT_TCVOLMAKE      (EVT_ID_RES_BASE + RES_PROC_CRYPT_TCVOLMAKE)     /**< Client called #RES_PROC_CRYPT_TCVOLMAKE */
#define EVT_ID_CRYPT_TCVOLMOUNT     (EVT_ID_RES_BASE + RES_PROC_CRYPT_TCVOLMOUNT)    /**< Client called #RES_PROC_CRYPT_TCVOLMOUNT */
#define EVT_ID_CRYPT_TCVOLUNMOUNT   (EVT_ID_RES_BASE + RES_PROC_CRYPT_TCVOLUNMOUNT)  /**< Client called #RES_PROC_CRYPT_TCVOLUNMOUNT */
#define EVT_ID_CRYPT_PKEYADD        (EVT_ID_RES_BASE + RES_PROC_CRYPT_PKEYADD)   /**< Client called #RES_PROC_CRYPT_PKEYADD */
#define EVT_ID_CRYPT_PKEYDEL        (EVT_ID_RES_BASE + RES_PROC_CRYPT_PKEYDEL)   /**< Client called #RES_PROC_CRYPT_PKEYDEL */
#define EVT_ID_FILECREATE           (EVT_ID_FILE_BASE + 1)   /**< Create file */
#define EVT_ID_FILEWRITE            (EVT_ID_FILE_BASE + 2)   /**< Write to file */
#define EVT_ID_FILEREMOVE           (EVT_ID_FILE_BASE + 3)   /**< Remove file */
#define EVT_ID_FILERENAME           (EVT_ID_FILE_BASE + 4)   /**< Rename file/directory */
#define EVT_ID_FILESETTIME          (EVT_ID_FILE_BASE + 5)   /**< Set file time */
#define EVT_ID_FILEMKDIR            (EVT_ID_FILE_BASE + 6)   /**< Make directory */
#define EVT_ID_FILERMDIR            (EVT_ID_FILE_BASE + 7)   /**< Remove directory */
#define EVT_ID_SSL_ACCEPT           (EVT_ID_SSL_BASE + 1)    /**< SSL handshake (accept connection) */
#define EVT_ID_SSL_ACCEPTVERIFY     (EVT_ID_SSL_BASE + 2)    /**< SSL handshake (certificate verification) */
#define EVT_ID_SSL_RELOADSRVKEYS    (EVT_ID_SSL_BASE + 3)    /**< SSL server key and certificate exchange */
#define EVT_ID_SSL_RELOADCLTKEYS    (EVT_ID_SSL_BASE + 4)    /**< SSL client key and certificate exchange */
#define EVT_ID_SSL_RELOADCRL        (EVT_ID_SSL_BASE + 5)    /**< SSL CRL exchange */
/** @} */

/**
 * @name Possible error codes
 * @{
 */

#define EVT_E_OK        M_E_OK   /**< @copybrief #M_E_OK */
#define EVT_E_FAILED    (M_ES_EVT | M_E_FAILED)  /**< @copybrief #M_E_FAILED */
#define EVT_E_LIST      (M_ES_EVT | M_E_LISTID)  /**< @copybrief #M_E_LISTID */
#define EVT_E_INACTIVE  (M_ES_EVT | M_E_INVSTATE)    /**< Log not configured to be active */
#define EVT_E_PARM      (M_ES_EVT | M_E_PARM)    /**< @copybrief #M_E_PARM */
#define EVT_E_FOUND     (M_ES_EVT | M_E_NOOBJ)   /**< @copybrief #M_E_NOOBJ */
#define EVT_E_ETYPE     (M_ES_EVT | M_E_CBACK)   /**< @copybrief #M_E_CBACK */
#define EVT_E_BUFFER    (M_ES_EVT | M_E_FULL)    /**< Write buffer of archiver is full */
#define EVT_E_BADINIT   (M_ES_EVT | M_E_BADINIT)     /**< Initialization failed */
#define EVT_E_DUPCBACK  (M_ES_EVT | M_E_DUPRES)  /**< @copybrief #M_E_DUPRES */
/** @} */

#ifndef _ASMLANGUAGE
/**
 * @since V3.80 Release
 */
typedef struct
{
    CHAR8       Source[EVT_SOURCELEN_A];     /**< Event source */
    UINT32      EventID;        /**< Event ID */
    UINT32      CategoryID;     /**< Event category ID */
    SINT32      RetCode;        /**< System return code @ref M_E_ , indicates success true/false */
    TIMESTAMP   Timestamp;      /**< Event time stamp (LOCAL/UTC) */
    UINT32      Reserved;       /**< Must not be used */
    UINT32      RecordID;       /**< Event record ID */
    SINT32      TimezoneOffset; /**< Timestamp offset in seconds to GMT ( 0 ... GMT) */
    SINT8       Type;           /**< Event type @ref EVT_T_ */
    SINT8       Spare2[3];      /**< Must be 0 for now */
    CHAR8       SerialNb[EVT_SERIALNBLEN_A];     /**< System serial number 6.3 */
    UINT32      Spare3[10];     /**< Must be 0 for now */
} EVT_EVENT;

/**
 * @since V3.80 Release
 */
typedef struct
{
    UINT32  UserIP;             /**< IP of user in hex format */
    SINT32  UserSession;        /**< Login session id of user */
    CHAR8   UserName[EVT_USERNAMELEN_A];     /**< Login name of user */
    UINT8   UserGroup;          /**< Group of user */
    UINT8   UserLevel;          /**< Group level of user */
    UINT8   Spare1[2];          /**< Needed for byte alignment */
    SINT64  UserSysPerm;        /**< System rights of user */
    SINT64  UserAppPerm;        /**< Application rights of user */
    CHAR8   UserTool[M_MODNAMELEN_A];    /**< Tool that has logged in */
    SINT32  Spare2[2];          /**< Must be 0 for now */
} EVT_USER_DATA;

/**
 * @since V3.80 Release
 */
typedef struct
{
    UINT32  UserIP;             /**< IP of user in hex format */
    SINT32  UserSession;        /**< Login session id of user */
    CHAR8   UserName[EVT_USERNAMELEN_A];     /**< Login name of user */
    UINT8   UserGroup;          /**< Group of user */
    UINT8   UserLevel;          /**< Group level of user */
    UINT8   Spare1[2];          /**< Needed for byte alignment */
    SINT64  UserSysPerm;        /**< System rights of user */
    SINT64  UserAppPerm;        /**< Application rights of user */
    CHAR8   UserTool[M_MODNAMELEN_A];    /**< Tool that has logged in */
    SINT32  Spare2[2];          /**< Must be 0 for now */
    CHAR8   Resource[EVT_VARNAMELEN_A];  /**< Resource name */
    UINT16  Format;             /**< Value format of Resource (for example: for SVI @ref SVI_F_) */
    UINT8   ValueLenOld;        /**< Number of bytes in `ValueOld` */
    UINT8   ValueLenNew;        /**< Number of bytes in `ValueNew` */
    UINT8   ValueOld[EVT_VALUELEN_A];    /**< Old value in binary */
    UINT8   ValueNew[EVT_VALUELEN_A];    /**< New value in binary */
} EVT_RESOURCE_DATA;

/**
 * @since V3.80 Release
 */
typedef struct
{
    EVT_EVENT   Event;          /**< Basic event information */
    UINT32      Profile;        /**< Event profile id, @ref EVT_P_ */
    UINT32      DataLen;        /**< Size of additional event data */
    SINT8       Data[1];        /**< Profile dependent event data */
} EVT_RECORD;

/**
 * @since V3.80 Release
 */
typedef struct
{
    CHAR8   LogName[EVT_LNAMELEN_A];     /**< Name of event log */
    /**
     * True if the log is enabled
     * and can be accessed
     */
    BOOL8   LogEnabled;
    SINT8   Spare1[3];          /**< Must be 0 for now */
    UINT32  LogLen;             /**< Max. number of entries in the log list */
    UINT32  LogActLen;          /**< Actual number of entries in the log list */
    BOOL8   FileEnabled;        /**< Indicates whether the log uses the system archiver */
    BOOL8   FileBufferRetain;   /**< Whether the archiver allocates its buffer in NVRAM */
    SINT8   Spare2[2];          /**< Must be 0 for now */
    SINT32  FileBufferSize;     /**< The buffer size of the archiver */
    CHAR8   FilePath[M_PATHLEN_A];   /**< Path where the archive files are stored */
    SINT32  FileCnt;            /**< Maximum file number of the archiver */
    SINT32  FileSize;           /**< Actual size of one single archive file */
    UINT32  Spare3[29];         /**< Must be 0 for now */
} EVT_LOGINFO;

/** @} */

/**
 * @addtogroup EVT-SMI
 * @{
 */

/**
 * @name SMI commands
 * @{
 */

/**
 * @brief Request configuration and status information of an event list.
 *
 * @param[in]   #EVT_GETLOGINFO_C
 * @param[out]  #EVT_GETLOGINFO_R
 * @retval      #EVT_E_OK
 * @retval      #EVT_E_FAILED
 * @retval      #EVT_E_INACTIVE  Log is not enabled
 * @retval      #EVT_E_LIST      Invalid logID
 */
#define EVT_PROC_GETLOGINFO     104
/**
 * @brief Registers a caller as a consumer of an event log.
 *
 * @note The number of sessions is limited to 10.
 *
 * @param[in]   #EVT_STARTSESSION_C
 * @param[out]  #EVT_STARTSESSION_R
 * @retval      #EVT_E_OK
 * @retval      #EVT_E_FAILED
 * @retval      #EVT_E_INACTIVE  Log is not enabled
 * @retval      #EVT_E_LIST      Invalid logID
 *
 * @see #EVT_PROC_STOPSESSION
 * @see #EVT_PROC_UPDATESESSION
 */
#define EVT_PROC_STARTSESSION   122
/**
 * @brief Ends a registered consumer session.
 *
 * @param[in]   #EVT_STOPSESSION_C
 * @param[out]  #EVT_STOPSESSION_R
 * @retval      #EVT_E_OK
 * @retval      #EVT_E_FOUND     If session has not been stared or already removed
 * @retval      #EVT_E_INACTIVE  Log is not enabled
 * @retval      #EVT_E_LIST      Invalid logID
 *
 * @see #EVT_PROC_STARTSESSION
 */
#define EVT_PROC_STOPSESSION    124
/**
 * @brief Poll for new events of the given session.
 *
 * See evt_UpdateSession() to see how to handle the reply.
 *
 * @param[in]   #EVT_UPDATESESSION_C
 * @param[out]  #EVT_UPDATESESSION_R
 * @retval      #EVT_E_OK
 * @retval      #EVT_E_FOUND     If session has not been stared or already removed
 * @retval      #EVT_E_INACTIVE  Log is not enabled
 * @retval      #EVT_E_LIST      Invalid logID
 * @retval      #EVT_E_FAILED
 *
 * @see #EVT_PROC_STARTSESSION
 */
#define EVT_PROC_UPDATESESSION  126
/**
 * @brief Archive all events that have not been processed until now.
 *
 * @param[in]   #EVT_FLUSH_C
 * @param[out]  #EVT_FLUSH_R
 * @retval      #EVT_E_OK
 * @retval      #EVT_E_INACTIVE  Log is not enabled
 * @retval      #EVT_E_LIST      Invalid logID
 * @retval      #EVT_E_FAILED
 * @return      Return values not stated above are returned by the attached flush function
 */
#define EVT_PROC_FLUSH          128
/** @} */
/**
 * Structure for the SMI-Call #EVT_PROC_GETLOGINFO
 */
typedef struct
{
    UINT32  LogID;              /**< ID of the concerned log. See #EVT_L_SECURITY and subsequent defines. */
} EVT_GETLOGINFO_C;

/**
 * Structure for the SMI-Reply #EVT_PROC_GETLOGINFO
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    EVT_LOGINFO Inf;            /**< Information about EVT list */
} EVT_GETLOGINFO_R;

/**
 * Structure for the SMI-Call #EVT_PROC_STARTSESSION
 */
typedef struct
{
    UINT32  LogID;              /**< ID of the concerned log. See #EVT_L_SECURITY and subsequent defines. */
    /**
     * Time in ms after that the session is
     * removed, if the entries are not fetched
     * via the SMI-function #EVT_PROC_UPDATESESSION.
     */
    UINT32  Timeout;
    UINT32  Mode;               /**< Session mode #EVT_M_ALL or #EVT_M_ONLYNEW. */
    UINT32  Spare[1];           /**< Must be 0 for now */
} EVT_STARTSESSION_C;

/**
 * Structure for the SMI-Reply #EVT_PROC_STARTSESSION
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  SessionID;          /**< Session ID */
    UINT32  Spare[2];           /**< Must be 0 for now */
} EVT_STARTSESSION_R;

/**
 * Structure for the SMI-Call #EVT_PROC_STOPSESSION
 */
typedef struct
{
    UINT32  LogID;              /**< ID of the concerned log. See #EVT_L_SECURITY and subsequent defines. */
    UINT32  SessionID;          /**< Session ID returned by #EVT_PROC_STARTSESSION */
    UINT32  Spare[2];           /**< Must be 0 for now */
} EVT_STOPSESSION_C;

/**
 * Structure for the SMI-Reply #EVT_PROC_STOPSESSION
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[2];           /**< Must be 0 for now */
} EVT_STOPSESSION_R;

/**
 * Structure for the SMI-Call #EVT_PROC_UPDATESESSION
 */
typedef struct
{
    UINT32  LogID;              /**< ID of the concerned log. See #EVT_L_SECURITY and subsequent defines. */
    UINT32  SessionID;          /**< Session ID returned by #EVT_PROC_STARTSESSION */
    UINT32  Spare[4];           /**< Must be 0 for now */
} EVT_UPDATESESSION_C;

/**
 * Structure for the SMI-Reply #EVT_PROC_UPDATESESSION
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      Spare[4];       /**< Must be 0 for now */
    UINT32      NbOfOpenEntries;     /**< Number of entries open -> not fetched with this call */
    UINT32      NbOfEntries;    /**< Number of entries in reply */
    EVT_RECORD  Entries[1];     /**< Event entries */
} EVT_UPDATESESSION_R;

/**
 * Structure for the SMI-Call #EVT_PROC_FLUSH
 */
typedef struct
{
    UINT32  LogID;              /**< ID of the concerned log. See #EVT_L_SECURITY and subsequent defines. */
    UINT32  Spare[20];          /**< Must be 0 for now */
} EVT_FLUSH_C;

/**
 * Structure for the SMI-Reply #EVT_PROC_FLUSH
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[20];          /**< Must be 0 for now */
} EVT_FLUSH_R;

#endif                                  /* _ASMLANGUAGE */
/** @} */

#ifdef __cplusplus
}
#endif

#endif
