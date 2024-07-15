/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     msys.h
* @author   Fritsche
* @brief    This file contains all global definitions and declarations
*           to modules running on another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef MSYS__H
#define MSYS__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @name Definitions
 * @{
 */


/**
 * @addtogroup SYS-GENERAL
 * @{
 */

/**
 * @name Definitions for various string length
 * @{
 */

#define M_PATHLEN           80   /**< Maximum size of path and file name without '\0' termination */
#define M_PATHLEN_A         ((M_PATHLEN + 1 + 3) & 0xfffffffc)   /**< M_PATHLEN + '\0' + aligned */
#define M_FILENAMELEN       12   /**< Maximum size of 8.3 file name without '\0' termination */
#define M_FILENAMELEN_A     ((M_FILENAMELEN + 1 + 3) & 0xfffffffc)   /**< M_FILENAMELEN + '\0' + aligned */
#define M_FILENAMELONGLEN   31   /**< Maximum size of file name with extension and without '\0' termination */
#define M_FILENAMELONGLEN_A ((M_FILENAMELONGLEN + 1 + 3) & 0xfffffffc)   /**< M_FILENAMELONGLEN + '\0' + aligned */
#define M_XFILENAMELEN      255  /**< Maximum size of long file name without '\0' termination */
#define M_XFILENAMELEN_A    ((M_XFILENAMELEN + 1 + 3) & 0xfffffffc)  /**< M_XFILENAMELEN + '\0' + aligned */
#define M_MODNAMELEN        8    /**< Maximum size of module name without '\0' termination */
#define M_MODNAMELEN_A      ((M_MODNAMELEN + 1 + 3) & 0xfffffffc)    /**< M_MODNAMELEN + '\0' + aligned */
#define M_CARDNAMELEN       20   /**< Maximum size of IO module without '\0' termination */
#define M_CARDNAMELEN_A     ((M_CARDNAMELEN + 1 + 3) & 0xfffffffc)   /**< M_CARDNAMELEN + '\0' + aligned */
#define M_FUNCNAMELEN       32   /**< Maximum size of function name without '\0' termination */
#define M_APPNAMELEN        20   /**< Maximum size of application name without '\0' termination */
#define M_APPNAMELEN_A      ((M_APPNAMELEN + 1 + 3) & 0xfffffffc)    /**< M_APPNAMELEN + '\0' + aligned */
#define M_UNAMELEN          19   /**< Maximum size of user name without '\0' termination */
#define M_UNAMELEN_A        20   /**< M_UNAMELEN + '\0' + aligned */
#define M_PWORDLEN          16   /**< Fixed size of password */
#define M_UNAMELEN2         63   /**< Maximum size of extended user name without '\0' termination */
#define M_UNAMELEN2_A       64   /**< M_UNAMELEN + '\0' + aligned */
#define M_PWORDLEN2         32   /**< Fixed size of extended password */
#define M_TSKNAMELEN        (1 + M_MODNAMELEN + 5)   /**< Maximum size of a task name (for example aMOTION_01) */
#define M_TSKNAMELEN_A      ((M_TSKNAMELEN + 1 + 3) & 0xfffffffc)    /**< M_TSKNAMELEN + '\0' + aligned */
#define M_VERSTRGLEN        15   /**< Example: V01.00.06 Alpha */
#define M_VERSTRGLEN_A      ((M_VERSTRGLEN + 1 + 3) & 0xfffffffc)    /**< M_VERSTRGLEN + '\0' + aligned */
#define M_IPADDRLEN         16   /**< Example: 255.255.255.255 */
#define M_IPADDRLEN_A       ((M_IPADDRLEN + 1 + 3) & 0xfffffffc)     /**< M_IPADDRLEN + '\0' + aligned */
#define M_SYMLEN            20   /**< Size entry name without '\0' termination */
#define M_SYMBLEN           256  /**< Size global symbol name without '\0' termination */
#define M_SYMBLEN_A         ((M_SYMBLEN + 1 + 3) & 0xfffffffc)   /**< M_SYMBLEN + '\0' + aligned */
/** @} */

/**
 * @name Timezone handling
 * @{
 */

#define M_TIME_LOCAL    0   /**< Use LOCAL time representation (default) */
#define M_TIME_UTC      1   /**< Use UTC time representation */
#define M_TIMEZONELEN   35  /**< Maximum size of timezone string without '\0' termination */
#define M_TIMEZONELEN_A 36  /**< M_TIMEZONELEN + '\0' + aligned */
/** @} */

/**
 * @name Protocol definitions
 * @{
 */

#define SYS_P_UDP       1   /**< Use UDP */
#define SYS_P_TCP       2   /**< Use TCP */
#define SYS_P_TCPSTREAM 3   /**< Use TCP-STREAM */
#define SYS_P_QSOAP     4   /**< Use Quick SOAP */
#define SYS_P_SSL       5   /**< Use SSL */
/** @} */

/**
 * @name Boot parameter definitions
 * @{
 */

#define M_BOOT_LEN1         20
#define M_BOOT_LEN2         30
#define M_BOOT_LEN3         80
#define M_BOOT_LEN4         50
#define M_BOOT_LEN5         40
#define M_BOOT_LEN6         160
#define M_FLG_NO_AUTOBOOT   0x0004   /**< Don't start autoboot sequence */
#define M_FLG_WDB           0x0200   /**< Use WDB agent */
#define M_FLG_NFSBOOT       0x1000   /**< Use NFS in stead of FTP */
/** @} */

/**
 * @name Possible tick sources
 * @{
 */

#define M_TICK_TIMER    0   /**< Timer tick source */
#define M_TICK_RTC      1   /**< RTC tick source */
/** @} */

/**
 * @name Possible boot modes
 * @{
 */

#define M_BM_NOMSYS     0x00000001   /**< No MSys */
#define M_BM_MSYSSTEP   0x00000002   /**< MSys module in single step */
#define M_BM_NOMCONF    0x00000010   /**< No MConfig.ini */
#define M_BM_MCONFSTEP  0x00000020   /**< MConfig.ini in single step */
#define M_BM_NODRV      0x00000100   /**< No IO module driver */
#define M_BM_DRVSTEP    0x00000200   /**< Driver in single step */
#define M_BM_TESTFWARE  0x00000400   /**< Test firmware on IO module */
#define M_BM_NOAPP      0x00001000   /**< No application modules */
#define M_BM_APPSTEP    0x00002000   /**< Application modules in single step */
#define M_BM_SRVSTEP    0x00010000   /**< Services in single step */
/** @} */

/**
 * @anchor M_VER_
 */
/**
 * @name Version types
 * @{
 */

#define M_VER_ALPHA     1   /**< Alpha-Version */
#define M_VER_BETA      2   /**< Beta-Version */
#define M_VER_RELEASE   3   /**< Release-Version */
/** @} */
/** @} */
/** @} */

/**
 * @name Structures
 * @{
 */


/**
 * @addtogroup SYS-GENERAL
 * @{
 */
/**
 * Structure for binary version code. Do not change values or size of this
 * structure. It is used for INF_VERSION and this is part of RPC call structures.
 */
typedef struct
{
    /**
     * The array Code contains the major version at index 0, the minor
     * version at index 1 and optional the alpha or beta number at index 2.
     * All version numbers are binary values. Release versions typically
     * have the alpha or beta number at index 2 set to 0 or 99.
     */
    UINT32  Code[3];
    /**
     * The element Type contains the code for alpha, beta or release version.
     * The Type codes are defined as @ref M_VER_, do not use any other code
     * outside this definition.
     */
    UINT32  Type;
} SYS_VERSION;

/**
 * @brief Boot parameters.
 */
typedef struct
{
    CHAR8   BootDev[M_BOOT_LEN1];    /**< Boot device code */
    CHAR8   HostName[M_BOOT_LEN1];   /**< Name of host */
    CHAR8   TargetName[M_BOOT_LEN1];     /**< Name of target */
    CHAR8   Ead[M_BOOT_LEN2];   /**< Ethernet internet addr */
    CHAR8   Bad[M_BOOT_LEN2];   /**< Backplane internet addr */
    CHAR8   Had[M_BOOT_LEN2];   /**< Host internet addr */
    CHAR8   Gad[M_BOOT_LEN2];   /**< Gateway internet addr */
    CHAR8   BootFile[M_BOOT_LEN3];   /**< Name of boot file */
    CHAR8   StartScript[M_BOOT_LEN3];    /**< Startup script, defined by user */
    CHAR8   User[M_BOOT_LEN1];  /**< User name */
    CHAR8   Passwd[M_BOOT_LEN1];     /**< Password */
    CHAR8   Other[M_BOOT_LEN3]; /**< Available for applications */
    SINT32  ProcNum;            /**< Processor number */
    SINT32  Flags;              /**< Configuration flags */
} BOOT_INFO;

/**
 * @brief VxWorks Boot-Parameters for MCore 1.x.
 *
 * @deprecated Do not use this type (it may change without notice).
 *             Use #BOOT_INFO instead.
 */
typedef struct
{
    CHAR8   bootDev[M_BOOT_LEN1];    /**< Boot device code */
    CHAR8   hostName[M_BOOT_LEN1];   /**< Name of host */
    CHAR8   targetName[M_BOOT_LEN1];     /**< Name of target */
    CHAR8   ead[M_BOOT_LEN2];   /**< Ethernet internet addr */
    CHAR8   bad[M_BOOT_LEN2];   /**< Backplane internet addr */
    CHAR8   had[M_BOOT_LEN2];   /**< Host internet addr */
    CHAR8   gad[M_BOOT_LEN2];   /**< Gateway internet addr */
    CHAR8   bootFile[M_BOOT_LEN3];   /**< Name of boot file */
    CHAR8   startupScript[M_BOOT_LEN3];  /**< Startup script, defined by user */
    CHAR8   usr[M_BOOT_LEN1];   /**< User name */
    CHAR8   passwd[M_BOOT_LEN1];     /**< Password */
    CHAR8   other[M_BOOT_LEN3]; /**< Available for applications */
    SINT32  procNum;            /**< Processor number */
    SINT32  flags;              /**< Configuration flags */
} BOOT_INFO_VXW;

/**
 * @brief VxWorks Boot-Parameters for MCore 2.x (VxWorks 5.4)
 *
 * @deprecated Do not use this type (it may change without notice).
 *             Use #BOOT_INFO instead.
 */
typedef struct
{
    CHAR8   bootDev[M_BOOT_LEN1];    /**< Boot device code */
    CHAR8   hostName[M_BOOT_LEN1];   /**< Name of host */
    CHAR8   targetName[M_BOOT_LEN1];     /**< Name of target */
    CHAR8   ead[M_BOOT_LEN4];   /**< Ethernet internet addr */
    CHAR8   bad[M_BOOT_LEN4];   /**< Backplane internet addr */
    CHAR8   had[M_BOOT_LEN2];   /**< Host internet addr */
    CHAR8   gad[M_BOOT_LEN2];   /**< Gateway internet addr */
    CHAR8   bootFile[M_BOOT_LEN3];   /**< Name of boot file */
    CHAR8   startupScript[M_BOOT_LEN3];  /**< Startup script, defined by user */
    CHAR8   usr[M_BOOT_LEN1];   /**< User name */
    CHAR8   passwd[M_BOOT_LEN1];     /**< Password */
    CHAR8   other[M_BOOT_LEN3]; /**< Available for applications */
    SINT32  procNum;            /**< Processor number */
    SINT32  flags;              /**< Configuration flags */
    SINT32  unitNum;            /**< Processor number */
} BOOT_INFO_VXW2;

/**
 * @brief VxWorks Boot-Parameters for MCore 3.x (VxWorks 5.5)
 *
 * @deprecated Do not use this type (it may change without notice).
 *             Use #BOOT_INFO instead.
 */
typedef struct
{
    CHAR8   bootDev[M_BOOT_LEN5];    /**< Boot device code */
    CHAR8   hostName[M_BOOT_LEN1];   /**< Name of host */
    CHAR8   targetName[M_BOOT_LEN1];     /**< Name of target */
    CHAR8   ead[M_BOOT_LEN4];   /**< Ethernet internet addr */
    CHAR8   bad[M_BOOT_LEN4];   /**< Backplane internet addr */
    CHAR8   had[M_BOOT_LEN2];   /**< Host internet addr */
    CHAR8   gad[M_BOOT_LEN2];   /**< Gateway internet addr */
    CHAR8   bootFile[M_BOOT_LEN6];   /**< Name of boot file */
    CHAR8   startupScript[M_BOOT_LEN6];  /**< Startup script, defined by user */
    CHAR8   usr[M_BOOT_LEN1];   /**< User name */
    CHAR8   passwd[M_BOOT_LEN1];     /**< Password */
    CHAR8   other[M_BOOT_LEN3]; /**< Available for applications */
    SINT32  procNum;            /**< Processor number */
    SINT32  flags;              /**< Configuration flags */
    SINT32  unitNum;            /**< Processor number */
} BOOT_INFO_VXW3;

/**
 * @brief VxWorks Boot-Parameters for MCore 4.x (VxWorks 7.0 )
 *
 * @deprecated Do not use this type (it may change without notice).
 *             Use #BOOT_INFO instead.
 */
typedef struct
{
    CHAR8   bootDev[M_BOOT_LEN5];    /**< Boot device code */
    CHAR8   hostName[M_BOOT_LEN1];   /**< Name of host */
    CHAR8   targetName[M_BOOT_LEN1];     /**< Name of target */
    CHAR8   ead[M_BOOT_LEN4];   /**< Ethernet internet addr */
    CHAR8   bad[M_BOOT_LEN4];   /**< Backplane internet addr */
    CHAR8   had[M_BOOT_LEN2];   /**< Host internet addr */
    CHAR8   gad[M_BOOT_LEN2];   /**< Gateway internet addr */
    CHAR8   bootFile[M_BOOT_LEN6];   /**< Name of boot file */
    CHAR8   startupScript[M_BOOT_LEN6];  /**< Startup script, defined by user */
    CHAR8   usr[M_BOOT_LEN1];   /**< User name */
    CHAR8   passwd[M_BOOT_LEN1];     /**< Password */
    CHAR8   other[M_BOOT_LEN3]; /**< Available for applications */
    CHAR8   reserve[M_BOOT_LEN3];    /**< Available for setting variables */
    SINT32  procNum;            /**< Processor number */
    SINT32  flags;              /**< Configuration flags */
    SINT32  unitNum;            /**< Processor number */
} BOOT_INFO_VXW4;

/**
 * @brief Timestamp structure.
 * This structure is compatible with \c {struct timespec}.
 */
typedef struct
{
    UINT32  Sec;                /**< Seconds since 1.1.1970 */
    SINT32  NSec;               /**< Nanoseconds (0 - 1,000,000,000) */
} TIMESTAMP;

/** @} */
/** @} */

/**
 * @name Error handling
 * @{
 */


/**
 * @addtogroup SYS-ERROR
 * @{
 */

/**
 * @name Error masks
 * @{
 */

#define M_E_SIGN    0x80000000   /**< Mask for an error */
#define M_E_TYPEMSK 0x0000ffff   /**< Mask for error cause */
#define M_E_SRCMSK  0x0fff0000   /**< Mask for error source */
/** @} */

/**
 * @anchor M_E_
 */
/**
 * @name Error codes
 * @{
 */

#define M_E_OK                          0    /**< O.K., no error */
#define M_E_INPROGRESS                  1    /**< Still in progress, no error */
#define M_E_CANCELED                    2    /**< Canceled by user, no error */
#define M_E_FAILED                      ((SINT32) 0x80000100)    /**< Unspecified error */
#define M_E_BADPROG                     ((SINT32) 0x80000101)    /**< SMI-Program not valid */
#define M_E_BADPROC                     ((SINT32) 0x80000102)    /**< SMI-Procedure not valid */
#define M_E_BADARGS                     ((SINT32) 0x80000103)    /**< SMI-Arguments not valid */
#define M_E_BADRPC                      ((SINT32) 0x80000104)    /**< SMI-Version not valid */
#define M_E_BADAUTH                     ((SINT32) 0x80000105)    /**< SMI-Authentication failed */
#define M_E_BADVERS                     ((SINT32) 0x80000106)    /**< SMI-Protocol version bad */
#define M_E_BADPERM                     ((SINT32) 0x80000107)    /**< SMI-Permission not valid */
#define M_E_PARM                        ((SINT32) 0x80000110)    /**< Parameter not valid */
#define M_E_NOFILE                      ((SINT32) 0x80000111)    /**< File not found */
#define M_E_FILEBIG                     ((SINT32) 0x80000112)    /**< File too big */
#define M_E_FILEEMPTY                   ((SINT32) 0x80000113)    /**< File is empty */
#define M_E_NOSEC                       ((SINT32) 0x80000114)    /**< Section not found */
#define M_E_NOGRP                       ((SINT32) 0x80000115)    /**< Group not found */
#define M_E_NOKEY                       ((SINT32) 0x80000116)    /**< Keyword not found */
#define M_E_ENDFILE                     ((SINT32) 0x80000117)    /**< End of file reached */
#define M_E_NOSEMA                      ((SINT32) 0x80000118)    /**< Problem with semTake */
#define M_E_NOPFSET                     ((SINT32) 0x80000119)    /**< Set not found */
#define M_E_NOPFUNIT                    ((SINT32) 0x80000120)    /**< Unit not found */
#define M_E_SMODE                       ((SINT32) 0x80000121)    /**< Not allowed in this SysMode */
#define M_E_INSTALL                     ((SINT32) 0x80000122)    /**< Module not installable */
#define M_E_NOMEM                       ((SINT32) 0x80000123)    /**< Not enough system memory */
#define M_E_NOTSUPP                     ((SINT32) 0x80000124)    /**< Function not supported */
#define M_E_NOMODNBR                    ((SINT32) 0x80000125)    /**< No module number assigned */
#define M_E_TIMEOUT1                    ((SINT32) 0x80000126)    /**< Timeout in reply queue */
#define M_E_TIMEOUT2                    ((SINT32) 0x80000127)    /**< No answer from SW-Module */
#define M_E_TIMEOUT3                    ((SINT32) 0x80000128)    /**< Timeout in reply queue */
#define M_E_NOMOD1                      ((SINT32) 0x80000129)    /**< Module not found */
#define M_E_NOMOD2                      ((SINT32) 0x8000012A)    /**< Module does not respond */
#define M_E_NOMOD3                      ((SINT32) 0x8000012B)    /**< Module not present any more */
#define M_E_NODELTSK                    ((SINT32) 0x8000012C)    /**< Module as task not present */
#define M_E_NOVXWOBJ                    ((SINT32) 0x8000012D)    /**< Module in VxWorks not present */
#define M_E_NOOBJ                       ((SINT32) 0x8000012E)    /**< Object not available */
#define M_E_BADINDEX                    ((SINT32) 0x8000012F)    /**< Index in request not valid */
#define M_E_BADADDR                     ((SINT32) 0x80000130)    /**< Address in request not valid */
#define M_E_USERID                      ((SINT32) 0x80000131)    /**< User-Id not valid */
#define M_E_LISTID                      ((SINT32) 0x80000132)    /**< List-Id not valid */
#define M_E_DUPUSER                     ((SINT32) 0x80000133)    /**< User already present */
#define M_E_NBELEM                      ((SINT32) 0x80000134)    /**< Too many list elements */
#define M_E_CBACK                       ((SINT32) 0x80000135)    /**< Callback-Address not valid */
#define M_E_BADELEM                     ((SINT32) 0x80000136)    /**< Object contains bad element */
#define M_E_BADNAME                     ((SINT32) 0x80000137)    /**< Name not valid */
#define M_E_CARDNB                      ((SINT32) 0x80000138)    /**< IO module number not valid */
#define M_E_DRVID                       ((SINT32) 0x80000139)    /**< Driver-ID not valid */
#define M_E_DUPRES                      ((SINT32) 0x8000013A)    /**< Resource already present */
#define M_E_FULL                        ((SINT32) 0x8000013B)    /**< Resource is full */
#define M_E_NOLIC                       ((SINT32) 0x8000013C)    /**< No license for SW-Module */
#define M_E_NOLICEXP                    ((SINT32) 0x8000013D)    /**< License expired */
#define M_E_WRONGVERS                   ((SINT32) 0x8000013E)    /**< Bad object/library version */
#define M_E_NOREAD                      ((SINT32) 0x80000140)    /**< No read permission */
#define M_E_NOWRITE                     ((SINT32) 0x80000141)    /**< No write permission */
#define M_E_BADREAD                     ((SINT32) 0x80000142)    /**< Read error in file */
#define M_E_BADWRITE                    ((SINT32) 0x80000143)    /**< Write error in file */
#define M_E_BADSEEK                     ((SINT32) 0x80000144)    /**< Search error in file */
#define M_E_BADCHECK                    ((SINT32) 0x80000145)    /**< Checksum not valid */
#define M_E_BADVXWLD                    ((SINT32) 0x80000146)    /**< Module not loadable under VxWorks */
#define M_E_BADMEMLD                    ((SINT32) 0x80000147)    /**< Module not loadable into memory */
#define M_E_NOLIBREG                    ((SINT32) 0x80000148)    /**< Library can not be registered */
#define M_E_EMPTY                       ((SINT32) 0x80000149)    /**< Resource is empty */
#define M_E_BADMODE                     ((SINT32) 0x8000014A)    /**< Mode not valid */
#define M_E_BADOBJ                      ((SINT32) 0x8000014B)    /**< Object not allowed */
#define M_E_LOCKED                      ((SINT32) 0x8000014C)    /**< Access to object is locked */
#define M_E_BADIPADDR                   ((SINT32) 0x8000014D)    /**< Object in use by other client */
#define M_E_NOENTRY                     ((SINT32) 0x8000014E)    /**< Function ???_Init is missing */
#define M_E_NOREG                       ((SINT32) 0x8000014F)    /**< Module can not be registered */
#define M_E_BADINIT                     ((SINT32) 0x80000150)    /**< Function ???_Init returns error */
#define M_E_DEVFULL                     ((SINT32) 0x80000151)    /**< Block-Device is full */
#define M_E_BADCOPY                     ((SINT32) 0x80000152)    /**< Copy error in file */
#define M_E_NOGLOBMEM                   ((SINT32) 0x80000153)    /**< Not enough global memory */
#define M_E_NOAPPMEM                    ((SINT32) 0x80000154)    /**< Not enough application memory */
#define M_E_SYSTEM1                     ((SINT32) 0x80000156)    /**< Internal system error 1 */
#define M_E_BADROUTE                    ((SINT32) 0x80000157)    /**< Gateway not valid */
#define M_E_BADLOGIN                    ((SINT32) 0x80000158)    /**< Login Name/Password not valid */
#define M_E_NOSIODEV                    ((SINT32) 0x80000159)    /**< Serial device is missing */
#define M_E_BADSIODEV                   ((SINT32) 0x8000015A)    /**< Serial device not valid */
#define M_E_DEVINUSE                    ((SINT32) 0x8000015B)    /**< Device already in use */
#define M_E_DEVMISS                     ((SINT32) 0x8000015C)    /**< Device not present */
#define M_E_NOMODEM                     ((SINT32) 0x8000015D)    /**< Modem not present */
#define M_E_NOUNIT                      ((SINT32) 0x8000015E)    /**< No more unit available */
#define M_E_BADMODEM                    ((SINT32) 0x8000015F)    /**< Modem not valid */
#define M_E_BADPPP1                     ((SINT32) 0x80000160)    /**< PPP init error */
#define M_E_BADPPP2                     ((SINT32) 0x80000161)    /**< PPP establish error */
#define M_E_BADSLIP                     ((SINT32) 0x80000162)    /**< SLIP init error */
#define M_E_BADPROTO                    ((SINT32) 0x80000163)    /**< Protocol not valid */
#define M_E_LNAMEMISS                   ((SINT32) 0x80000164)    /**< Local name is missing */
#define M_E_BADHOST                     ((SINT32) 0x80000165)    /**< Host name can not be set */
#define M_E_NOHOST                      ((SINT32) 0x80000166)    /**< Host does not respond */
#define M_E_BADGATE                     ((SINT32) 0x80000167)    /**< Gateway name can not be set */
#define M_E_NOGATE                      ((SINT32) 0x80000168)    /**< Gateway does not respond */
#define M_E_BADMOUNT                    ((SINT32) 0x80000169)    /**< Mount is bad */
#define M_E_BADTYPE                     ((SINT32) 0x8000016A)    /**< Wrong data type */
#define M_E_BADUMOUNT                   ((SINT32) 0x80000170)    /**< Unmount is bad */
#define M_E_NODELSYS                    ((SINT32) 0x80000171)    /**< SYS-Module can not be deleted */
#define M_E_BADPATH                     ((SINT32) 0x80000172)    /**< Path/Name not valid */
#define M_E_NOSYS1                      ((SINT32) 0x80000173)    /**< File MCore is missing */
#define M_E_NOSYS2                      ((SINT32) 0x80000174)    /**< File MSys is missing */
#define M_E_NOFTP                       ((SINT32) 0x80000175)    /**< No FTP-Server on host */
#define M_E_IPINUSE                     ((SINT32) 0x80000176)    /**< IP-Address already in use */
#define M_E_NOLOGIN                     ((SINT32) 0x80000177)    /**< Login from server denied */
#define M_E_NOMCONF                     ((SINT32) 0x80000178)    /**< No MConfig.ini on device */
#define M_E_UPDATE                      ((SINT32) 0x80000179)    /**< Firmware update not allowed */
#define M_E_BADFPROG                    ((SINT32) 0x8000017A)    /**< Programming flash failed */
#define M_E_BADVERIFY                   ((SINT32) 0x8000017B)    /**< Verify flash failed */
#define M_E_BADRANGE                    ((SINT32) 0x8000017C)    /**< Range not valid */
#define M_E_BADCPU                      ((SINT32) 0x8000017D)    /**< Not for this CPU */
#define M_E_OLDADDR                     ((SINT32) 0x8000017E)    /**< Address in request is old */
#define M_E_NOBLOCKDEV                  ((SINT32) 0x8000017F)    /**< Block Device not present */
#define M_E_BADFORMAT                   ((SINT32) 0x80000180)    /**< Error in formatting */
#define M_E_BADREOPEN                   ((SINT32) 0x80000181)    /**< Error in reopen after formatting */
#define M_E_BADDOSINI                   ((SINT32) 0x80000182)    /**< Error in DOS initialization */
#define M_E_BADBOOTSEC                  ((SINT32) 0x80000183)    /**< Boot sector not settable */
#define M_E_NOFORMAT                    ((SINT32) 0x80000184)    /**< Formatting not allowed */
#define M_E_OLDVERS1                    ((SINT32) 0x80000185)    /**< Old software version MCore */
#define M_E_OLDVERS2                    ((SINT32) 0x80000186)    /**< Old software version MSys */
#define M_E_OLDVERS3                    ((SINT32) 0x80000187)    /**< Old software version IO-Driver */
#define M_E_BADLOGDEV                   ((SINT32) 0x80000188)    /**< Log-Device not valid */
#define M_E_BADMEMINIT                  ((SINT32) 0x80000189)    /**< Error in Memory-Partition init */
#define M_E_BADPNCINIT                  ((SINT32) 0x8000018A)    /**< Error in Panic-Handler init */
#define M_E_BADWDGINIT                  ((SINT32) 0x8000018B)    /**< Error Watchdog-Handler init */
#define M_E_NOERRTOL                    ((SINT32) 0x8000018C)    /**< SW-Module not error tolerant */
#define M_E_BADTCKRATE                  ((SINT32) 0x8000018D)    /**< Tick rate too low */
#define M_E_BADSPAWN                    ((SINT32) 0x8000018E)    /**< Error in task spawn */
#define M_E_WDOGON                      ((SINT32) 0x8000018F)    /**< HW-Watchdog must be off */
#define M_E_INVSTATE                    ((SINT32) 0x80000190)    /**< Action in this state not allowed */
#define M_E_NODE                        ((SINT32) 0x80000191)    /**< Bad network/fieldbus node */
#define M_E_TIMEOUT                     ((SINT32) 0x80000192)    /**< Timeout in function call */
#define M_E_SWREBOOT                    ((SINT32) 0x80000193)    /**< Software reboot */
#define M_E_WDGREBOOT                   ((SINT32) 0x80000194)    /**< Watchdog reboot */
#define M_E_NOONLINE                    ((SINT32) 0x80000195)    /**< Online change not allowed */
#define M_E_DRVMISS                     ((SINT32) 0x80000196)    /**< Driver is missing */
#define M_E_BADDRV                      ((SINT32) 0x80000197)    /**< Driver not loadable */
#define M_E_BADSLOT                     ((SINT32) 0x80000198)    /**< Station or slot not valid */
#define M_E_BELOWMIN                    ((SINT32) 0x80000199)    /**< Number stations below minimum */
#define M_E_ABOVEMAX                    ((SINT32) 0x8000019A)    /**< Number stations above maximum */
#define M_E_STATMISS                    ((SINT32) 0x8000019B)    /**< Minimum one station is missing */
#define M_E_BADSESS                     ((SINT32) 0x8000019C)    /**< Session ID not valid */
#define M_E_BADUSER                     ((SINT32) 0x8000019D)    /**< Login user name not valid */
#define M_E_NOPWORD                     ((SINT32) 0x8000019E)    /**< Login password not present */
#define M_E_BADPWORD                    ((SINT32) 0x8000019F)    /**< Login password not valid */
#define M_E_BADTIME                     ((SINT32) 0x800001A0)    /**< Login time frame not valid */
#define M_E_NOTASK                      ((SINT32) 0x800001A1)    /**< Task does not exist */
#define M_E_NODEBUG                     ((SINT32) 0x800001A2)    /**< Task can not be debugged */
#define M_E_NOATTACH                    ((SINT32) 0x800001A3)    /**< Task is not attached */
#define M_E_NOBKPT                      ((SINT32) 0x800001A4)    /**< Breakpoint not set */
#define M_E_NOSYM                       ((SINT32) 0x800001A5)    /**< Symbol not found */
#define M_E_TSKMISS                     ((SINT32) 0x800001A6)    /**< Task name is missing */
#define M_E_NOSSTEP                     ((SINT32) 0x800001A7)    /**< Task not on breakpoint */
#define M_E_HAVECBACK                   ((SINT32) 0x800001A8)    /**< Callback already attached */
#define M_E_NOCBACK                     ((SINT32) 0x800001A9)    /**< Callback not attached */
#define M_E_HAVEBKPT                    ((SINT32) 0x800001AA)    /**< Breakpoint already set */
#define M_E_ALLBKPT                     ((SINT32) 0x800001AB)    /**< All breakpoints in use */
#define M_E_VARINUSE                    ((SINT32) 0x800001AC)    /**< Variable already in use */
#define M_E_MBTRANS                     ((SINT32) 0x800001AD)    /**< Signalising MB transfer in error for compatibility reasons */
#define M_E_NOBUFF                      ((SINT32) 0x800001AE)    /**< No buffer found */
#define M_E_BADRESTORE                  ((SINT32) 0x800001AF)    /**< Restoring device failed */
#define M_E_WEAKPWR                     ((SINT32) 0x800001B0)    /**< Weak power supply on a station */
#define M_E_BADCONFIG                   ((SINT32) 0x800001B1)    /**< Configuration data not valid */
#define M_E_BADFWARE                    ((SINT32) 0x800001B2)    /**< Firmware not for this module */
#define M_E_DOWNGRADE                   ((SINT32) 0x800001B3)    /**< Firmware down grade error */
#define M_E_MODMISS                     ((SINT32) 0x800001B4)    /**< Module is old or missing */
#define M_E_TNETINUSE                   ((SINT32) 0x800001B5)    /**< Telnet in use, no redirect */
#define M_E_NOSHELL                     ((SINT32) 0x800001B6)    /**< Shell not running, no redirect */
#define M_E_BADSNTP                     ((SINT32) 0x800001B7)    /**< SNTP client not started */
#define M_E_NOAPP                       ((SINT32) 0x800001B8)    /**< Service not available in boot mode NOAPP */
#define M_E_NETNB                       ((SINT32) 0x800001C0)    /**< Fieldbus network number not valid */
#define M_E_NODEID                      ((SINT32) 0x800001C1)    /**< Fieldbus network node id, mac id not valid */
#define M_E_DSIZE                       ((SINT32) 0x800001C2)    /**< Data size not valid, exceeds max size */
#define M_E_CMDTAG                      ((SINT32) 0x800001C3)    /**< Command tag not valid */
#define M_E_CMDARG                      ((SINT32) 0x800001C4)    /**< Command argument(s) not valid */
#define M_E_QUEUEFULL                   ((SINT32) 0x800001C5)    /**< Command/Event Queue overrun */
#define M_E_IOBUSFAIL                   ((SINT32) 0x800001C6)    /**< I/O Bus access fails (bad station) */
#define M_E_SLCLOGFULL                  ((SINT32) 0x800001C7)    /**< The logbook of the SLC reached a critical level */
#define M_E_BROKENWIRE                  ((SINT32) 0x800001C8)    /**< SERCOS: Broken wire */
#define M_E_DRIVEMISS                   ((SINT32) 0x800001C9)    /**< SERCOS: Missing drive */
#define M_E_STARTUPTMO                  ((SINT32) 0x800001CA)    /**< SERCOS: Timeout while waiting for startup phase */
#define M_E_FALLBACK                    ((SINT32) 0x800001D0)    /**< Fallback device was used for booting */
#define M_E_MCONFIGBAK                  ((SINT32) 0x800001D1)    /**< MConfig.ini not found, used .bak instead */
#define M_E_CONTIGFILE                  ((SINT32) 0x800001D2)    /**< Error creating contiguous file */
#define M_E_EXCEPTION                   ((SINT32) 0x800001D3)    /**< Exception signal occurred */
#define M_E_OFFLINE                     ((SINT32) 0x800001E0)    /**< No connection to device */
#define M_E_INITVAL                     ((SINT32) 0x800001E1)    /**< Init value error */
#define M_E_CHECKVAL                    ((SINT32) 0x800001E2)    /**< Check value error */
#define M_E_DRIVE                       ((SINT32) 0x800001E3)    /**< Drive specific error */
#define M_E_HARDWARE                    ((SINT32) 0x800001E4)    /**< Hardware error */
#define M_E_COMMUNIC                    ((SINT32) 0x800001E5)    /**< Communication error */
#define M_E_NOSETVAL                    ((SINT32) 0x800001E6)    /**< Cyclic setvalue monitoring error */
#define M_E_CYCLETIME                   ((SINT32) 0x800001E7)    /**< Cycle time monitoring error */
#define M_E_COLDCLIMATE                 ((SINT32) 0x800001E8)    /**< A module does not support cold climate */
#define M_E_ACCDENIED                   ((SINT32) 0x800001E9)    /**< Access denied */
#define M_E_BADUSERLVL                  ((SINT32) 0x800001EA)    /**< Weak user level (deprecated: replaced by M_E_ACCDENIED) */
#define M_E_XERR                        ((SINT32) 0x800001EB)    /**< VHD_LST_XERR code information */
#define M_E_REDULOCK                    ((SINT32) 0x800001F0)    /**< Write access allowed only on primary CPU */
#define M_E_RICONN                      ((SINT32) 0x800001F1)    /**< RI offline */
#define M_E_RINETREDU                   ((SINT32) 0x800001F2)    /**< RI not redundant */
#define M_E_LENGTH                      ((SINT32) 0x800001F3)    /**< Data length invalid */
#define M_E_APPNAME                     ((SINT32) 0x800001F4)    /**< Application name mismatch */
#define M_E_BLOCKNB                     ((SINT32) 0x800001F5)    /**< Number of blocks different */
#define M_E_BLOCKDIFF                   ((SINT32) 0x800001F6)    /**< Memory blocks different */
#define M_E_DEVREDU                     ((SINT32) 0x800001F7)    /**< Device not redundant */
#define M_E_DEVNETREDU                  ((SINT32) 0x800001F8)    /**< Device network not redundant */
#define M_E_APPERROR1                   ((SINT32) 0x800001F9)    /**< Application error1 */
#define M_E_APPERROR2                   ((SINT32) 0x800001FA)    /**< Application error2 */
#define M_E_APPERROR3                   ((SINT32) 0x800001FB)    /**< Application error3 */
#define M_E_APPFATAL                    ((SINT32) 0x800001FC)    /**< Application fatal error */
#define M_E_APPDONE                     ((SINT32) 0x800001FD)    /**< Application done error */
#define M_E_APPOVLOAD                   ((SINT32) 0x800001FE)    /**< Application overload */
#define M_E_CYCLEOVLOAD                 ((SINT32) 0x800001FF)    /**< Cycle overload */
#define M_E_BCHCMD                      ((SINT32) 0x80000200)    /**< BCH command error */
#define M_E_PRICONFLICT                 ((SINT32) 0x80000201)    /**< Primary assignment conflict */
#define M_E_SWITCHOVER                  ((SINT32) 0x80000202)    /**< Switchover command */
#define M_E_APPCS                       ((SINT32) 0x80000203)    /**< Application checksum mismatch */
#define M_E_STSWITCHOVER                ((SINT32) 0x80000204)    /**< Self test switchover command */
#define M_E_STRUN                       ((SINT32) 0x80000205)    /**< Self test run */
#define M_E_STERROR                     ((SINT32) 0x80000206)    /**< Self test error */
#define M_E_PROGRAM                     ((SINT32) 0x80000207)    /**< Programming error */
#define M_E_STID                        ((SINT32) 0x80000210)    /**< Self test ID not valid */
#define M_E_STRAM                       ((SINT32) 0x80000211)    /**< Self test RAM error */
#define M_E_STPLC                       ((SINT32) 0x80000212)    /**< Self test PLC error */
#define M_E_STCOM                       ((SINT32) 0x80000213)    /**< Self test COM error */
#define M_E_CRYPT_METADATA_METHOD       ((SINT32) 0x80000214)    /**< Cipher method not available */
#define M_E_CRYPT_METADATA_HASH         ((SINT32) 0x80000215)    /**< Couldn't create cipher hash */
#define M_E_CRYPT_CRYPT_EXISTS          ((SINT32) 0x80000216)    /**< No encryption layer found */
#define M_E_CRYPT_CRYPT_MASTERKEY       ((SINT32) 0x80000217)    /**< No masterkey available */
#define M_E_CRYPT_CRYPT_BOOTDEV         ((SINT32) 0x80000218)    /**< Boot partition can not be encrypted */
#define M_E_CRYPT_ALGORITHM_LOAD_LIB    ((SINT32) 0x80000219)    /**< Loading cipher library failed */
#define M_E_CRYPT_ALGORITHM_LIB_VERSION ((SINT32) 0x80000221)    /**< Cipher library version */
#define M_E_CRYPT_ALGORITHM_INIT_LIB    ((SINT32) 0x80000222)    /**< Init cipher library failed */
#define M_E_CRYPT_ALGORITHM_KEYLENGTH   ((SINT32) 0x80000223)    /**< Cipher strength not valid */
#define M_E_CRYPT_ALGORITHM_INIT        ((SINT32) 0x80000224)    /**< Init cipher algorithm failed */
#define M_E_CRYPT_ALGORITHM_CRYPT       ((SINT32) 0x80000225)    /**< Error encrypting data */
#define M_E_CRYPT_ALGORITHM_DECRYPT     ((SINT32) 0x80000226)    /**< Error decrypting data */
#define M_E_CRYPT_KEY_RECOVERYFILE      ((SINT32) 0x80000227)    /**< Recover key file not found */
#define M_E_CRYPT_KEY_RECOVERYFILECRC   ((SINT32) 0x80000228)    /**< Recovery key file crc error */
#define M_E_CRYPT_KEY_RECOVERYPASSWORD  ((SINT32) 0x80000229)    /**< Recovery password wrong */
#define M_E_CRYPT_NOPROGRESS            ((SINT32) 0x80000230)    /**< No Progress available */
#define M_E_CRYPT_UNKNOWN               ((SINT32) 0x80000231)    /**< Detailed reason unknown */
#define M_E_BADSNTPSERVER               ((SINT32) 0x80000232)    /**< Configuration of SNTP server not valid */
#define M_E_TASK_WDOG                   ((SINT32) 0x80000240)    /**< Error creating watchdog */
#define M_E_TASK_SEM                    ((SINT32) 0x80000241)    /**< Error creating/deleting semaphore */
#define M_E_TASK_PRIO                   ((SINT32) 0x80000242)    /**< Priority out of range (has to be between 1 and 255) */
#define M_E_TASK_OFFSET                 ((SINT32) 0x80000243)    /**< Offset does not match tick/snyc rate or is greater than cycle time */
#define M_E_TASK_CYCDIFF                ((SINT32) 0x80000244)    /**< Next possible cycle time does differ more than 25% from configured cycle time */
#define M_E_TASK_CYCTIME                ((SINT32) 0x80000245)    /**< Cycle time is too small */
#define M_E_TASK_ATTACH                 ((SINT32) 0x80000246)    /**< Error attaching aux/sync */
#define M_E_TASK_AUXOFF                 ((SINT32) 0x80000247)    /**< Auxiliary clock is turned off */
#define M_E_TASK_SOURCE                 ((SINT32) 0x80000248)    /**< Unknown task trigger source */
#define M_E_TASK_NOMAINFUNC             ((SINT32) 0x80000249)    /**< User main function is NULL */
#define M_E_TASK_NOPTP                  ((SINT32) 0x8000024A)    /**< PTP synchronization not activated */
#define M_E_RTC                         ((SINT32) 0x80000300)    /**< Error init RTC chip */
#define M_E_ETHER                       ((SINT32) 0x80000301)    /**< Error init Ethernet controller */
#define M_E_IP_ADDR                     ((SINT32) 0x80000302)    /**< IP-Address not valid */
#define M_E_TICKRATE                    ((SINT32) 0x80000303)    /**< Tick rate not valid */
#define M_E_CPUCLOCK                    ((SINT32) 0x80000304)    /**< CPU clock not valid */
#define M_E_NVMAKE                      ((SINT32) 0x80000305)    /**< NV-Ram create failed */
#define M_E_NVMISS                      ((SINT32) 0x80000306)    /**< NV-Ram not present */
#define M_E_NVEMPTY                     ((SINT32) 0x80000307)    /**< NV-Ram is empty */
#define M_E_NVNODOS                     ((SINT32) 0x80000308)    /**< NV-Ram no DOS file system */
#define M_E_RDMAKE                      ((SINT32) 0x80000309)    /**< Ram-Disk create failed */
#define M_E_BATTLOW                     ((SINT32) 0x8000030A)    /**< Battery voltage too low */
#define M_E_SIO                         ((SINT32) 0x8000030D)    /**< Error init SIO driver */
#define M_E_DUPIP                       ((SINT32) 0x8000030E)    /**< Duplicate ip address */
#define M_E_EHDOFLOW                    ((SINT32) 0x8000030F)    /**< Too much EHD entries in MCore */
#define M_E_BOOTPANIC                   ((SINT32) 0x80000310)    /**< Panic situation occurred during boot */
#define M_E_NVRAMSIG                    ((SINT32) 0x80000311)    /**< Invalid nvram signature */
#define M_E_NATFAIL                     ((SINT32) 0x80000312)    /**< NAT initialization failed */
#define M_E_SMART                       ((SINT32) 0x80000313)    /**< SMART self-test on CFC failed */
#define M_E_FILESYSTEM                  ((SINT32) 0x80000314)    /**< Error in DOS file system */
#define M_E_SHORTKEY                    ((SINT32) 0x80000315)    /**< MConfig.ini keyword too short */
#define M_E_MSYSINVALID                 ((SINT32) 0x80000316)    /**< MSys is invalid (checksum, not found, ...) */
#define M_E_SNTPSYNC                    ((SINT32) 0x80000317)    /**< SNTP synchronization failure */
#define M_E_BADSIOHANDSHAKE             ((SINT32) 0x80000318)    /**< Hardware handshake is not permitted (probably device is used as console) */
#define M_E_ALLREADYEXIST               ((SINT32) 0x80002001)    /**< Object already exist */
#define M_E_NOOBJECT                    ((SINT32) 0x80002002)    /**< Object not found */
#define M_E_SQLERROR                    ((SINT32) 0x80002003)    /**< SQL error occurred */
#define M_E_NOAHD                       ((SINT32) 0x80002004)    /**< SW-Module AHD is not installed */
#define M_E_NOSESSAV                    ((SINT32) 0x80002005)    /**< No session available */
/** @} */

/**
 * @brief The Error Source uses Bits 16 to 27 in the error code
 *        and has the predefined areas as below:
 * - 0x0001 to 0x00FF ... System Module in M1
 * - 0x0100 to 0x01FF ... System Module in PC-Software
 * - 0x0200 to 0x03FF ... SW-Module from Bachmann
 * - 0x0400 to 0x0FFF ... Reserved for customers
 */

/**
 * @name Error sources
 * @{
 */

#define M_ES_NO         0x00000000   /**< Unknown source */
#define M_ES_SVI        0x00010000   /**< SVI Functions */
#define M_ES_SMI        0x00020000   /**< SMI Functions */
#define M_ES_RES        0x00030000   /**< Resource Handler */
#define M_ES_MIO        0x00040000   /**< IO Handler */
#define M_ES_VHD        0x00050000   /**< Vis Handler */
#define M_ES_INF        0x00060000   /**< Info Handler */
#define M_ES_PLC        0x00070000   /**< PLC Runtime system */
#define M_ES_MOD        0x00080000   /**< Module Handler */
#define M_ES_CAN        0x00090000   /**< CAN Handler */
#define M_ES_PF         0x000A0000   /**< Profile Functions */
#define M_ES_SYS        0x000F0000   /**< System MSys */
#define M_ES_CORE       0x00100000   /**< System MCore */
#define M_ES_EHD        0x00110000   /**< Error Handler */
#define M_ES_PB         0x00120000   /**< Profibus Handler */
#define M_ES_DBG        0x00130000   /**< Debug Handler */
#define M_ES_DN         0x00140000   /**< DeviceNet Handler */
#define M_ES_RFS        0x00150000   /**< Remote File Server */
#define M_ES_SLC        0x00160000   /**< SLC Server */
#define M_ES_DMW        0x00170000   /**< Drive Middleware */
#define M_ES_SEM201     0x00180000   /**< SERCOS driver */
#define M_ES_UFB        0x00190000   /**< Unified fieldbus components */
#define M_ES_PN         0x001A0000   /**< Profinet */
#define M_ES_EC         0x001B0000   /**< EtherCAT */
#define M_ES_BCR        0x001C0000   /**< BCR2xx */
#define M_ES_ST         0x001D0000   /**< Self Test Module */
#define M_ESPC_TDLL     0x01010000   /**< TMANw32-DLL */
#define M_ESPC_PLCCOM   0x01020000   /**< PLCCOM-DLL */
#define M_ESPC_TCONF    0x01030000   /**< TargetManager EXE */
#define M_ESPC_PLCHWM   0x01040000   /**< PLCHWM-DLL */
#define M_ESPC_TVIEW    0x01050000   /**< TMAN-View */
#define M_ESPC_MMAN     0x01060000   /**< M-Manager */
#define M_ESPC_MPLC     0x01070000   /**< M-PLC */
#define M_ESPC_MIF      0x01080000   /**< M-Interface */
#define M_ESW_AHD       0x02010000   /**< AHD System SW Module */
#define M_ESW_LOGGER    0x02020000   /**< Logger System SW Module */
#define M_ES_EVT        0x02030000   /**< Event Logger */
#define M_ES_ETCP       0x02040000   /**< 60870-5 */
#define M_ES_DNP3       0x02050000   /**< DNP3 */
#define M_ES_ATEC       0x02060000   /**< ATEC */
/** @} */

/**
 * @name Boot errors
 * @{
 */

#define M_E_BOOT1   -1      /**< Fatal Error, abort immediately */
#define M_E_BOOT2   -2      /**< Soft Error, continue booting */
/** @} */
/** @} */
/** @} */

/**
 * @name Debug Handling
 * @{
 */


/**
 * @addtogroup SYS-DEBUG
 * @{
 */

/**
 * @name Debug masks
 * @{
 */

#define M_DBG1_MSK  0x00000001
#define M_DBG2_MSK  0x00000002
#define M_DBG3_MSK  0x00000004
/** @} */

/**
 * @name System debug modes
 * @{
 */

#define M_SMI_DBG1      0x00000001   /**< SMI debug mode */
#define M_SMI_DBG2      0x00000002   /**< SMI debug mode extended */
#define M_RES_DBG1      0x00000004   /**< Resource handler debug mode */
#define M_RES_DBG2      0x00000008   /**< Resource handler debug mode extended */
#define M_MIO_DBG1      0x00000010   /**< MIO debug mode */
#define M_MIO_DBG2      0x00000020   /**< MIO debug mode extended */
#define M_MOD_DBG1      0x00000040   /**< Module handler debug mode */
#define M_MOD_DBG2      0x00000080   /**< Module handler debug mode extended */
#define M_PLC_DBG1      0x00000100   /**< PLC runtime system (PLCSRV) debug mode */
#define M_PLC_DBG2      0x00000200   /**< PLC runtime system (PLCSRV) debug mode extended */
#define M_SYS_DBG1      0x00000400   /**< System boot debug mode */
#define M_SYS_DBG2      0x00000800   /**< System boot debug mode extended */
#define M_INF_DBG1      0x00001000   /**< Information handler debug mode */
#define M_SVI_DBG1      0x00002000   /**< SVI debug mode */
#define M_CAN_DBG1      0x00004000   /**< CAN server/driver debug mode */
#define M_CAN_DBG2      0x00008000   /**< CAN server/driver debug mode extended */
#define M_VHD_DBG1      0x00010000   /**< Visualization handler debug mode */
#define M_VHD_DBG2      0x00020000   /**< Visualization handler debug mode extended */
#define M_EHD_DBG1      0x00040000   /**< Error handler debug mode */
#define M_EHD_DBG2      0x00080000   /**< Error handler debug mode extended */
#define M_PB_DBG1       0x00100000   /**< ProfiBus server/driver debug mode */
#define M_PB_DBG2       0x00200000   /**< ProfiBus server/driver debug mode extended */
#define M_LOGIN_DBG1    0x00400000   /**< Login debug mode */
#define M_MODEM_DBG1    0x00800000   /**< Modem debug mode */
#define M_PROF_DBG1     0x01000000   /**< MConfig.ini debug mode */
#define M_PROF_DBG2     0x02000000   /**< MConfig.ini debug mode extended */
#define M_ENET_DBG1     0x04000000   /**< Ethernet controller debug mode */
#define M_ENET_DBG2     0x08000000   /**< Ethernet controller debug mode extended */
#define M_PCC_DBG1      0x10000000   /**< PC card debug mode */
#define M_PCC_DBG2      0x20000000   /**< PC card debug mode extended */
#define M_SVI_DBG2      0x40000000   /**< SVI debug mode extended */
#define M_ACC_DBG1      0x80000000   /**< ACCESS debug mode */
/** @} */

/**
 * @name Application debug modes
 * @{
 */

#define APP_DBG_INFO1   0x00000001   /**< Enable general Info */
#define APP_DBG_INFO2   0x00000002   /**< Enable more general Info */
#define APP_DBG_WRN1    0x00000004   /**< Enable general Warnings */
#define APP_DBG_WRN2    0x00000008   /**< Enable more general Warnings */
#define APP_DBG_CONF1   0x00000011   /**< Info on 'pf_' Functions */
#define APP_DBG_CONF2   0x00000022   /**< More Info on 'pf_' Functions */
#define APP_DBG_SMI1    0x00000041   /**< Info on SMI-Functions */
#define APP_DBG_SMI2    0x00000082   /**< More Info on SMI-Functions */
#define APP_DBG_SVI1    0x00000101   /**< Info on SVI-Functions */
#define APP_DBG_SVI2    0x00000202   /**< More Info on SVI-Functions */
#define APP_DBG_SPARE1  0x00000400   /**< Reserved */
#define APP_DBG_SPARE2  0x00000800   /**< Reserved */
#define APP_DBG_SPARE3  0x00001000   /**< Reserved */
#define APP_DBG_SPARE4  0x00002000   /**< Reserved */
#define APP_DBG_SPARE5  0x00004000   /**< Reserved */
#define APP_DBG_SPARE6  0x00008000   /**< Reserved */
/** @} */
/** @} */
/** @} */

#ifdef __cplusplus
}
#endif

#endif
