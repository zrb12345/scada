/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     mod.h
* @author   Schwennd
* @brief    Module Handler
*           This file contains all definitions and declarations exported by
*           the Module Handler, that could be used by modules running on
*           another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef MOD__H
#define MOD__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>
#include <msys.h>
#include <time.h>
#include <lst_e.h>

/**
 * @addtogroup MOD-DEF
 * @{
 */

/**
 * @name Defines
 * @{
 */

#define MOD_PROTVERS    2   /**< @brief RPC protocol version */

/**
 * @name Possible values for MOD_FHEAD.FileType
 * @{
 */

#define MOD_IODRIVER    1   /**< Driver for M1 IO module */
#define MOD_REGULATOR   2   /**< Regulator (old definition) */
#define MOD_VXWMODULE   2   /**< VxWorks software module */
#define MOD_PLC1131     3   /**< PLC 1131 software module */
#define MOD_OTHER       4   /**< Other module */
#define MOD_PLCMLIB     5   /**< PLC library "plm"-file */
#define MOD_JAVAMODULE  6   /**< @deprecated since MSys 4.00R - Java software module */
#define MOD_SWSERVICE   7   /**< Software service */
#define MOD_OBJLIB      8   /**< VxWorks software library */
#define MOD_IOFW        9   /**< Logic and firmware file */
#define MOD_MTARGET     10  /**< M-Target software module */
/** @} */

/**
 * @name Possible values for MOD_ENTRY.Type
 * @{
 */

#define MOD_ENT_OBJ     1   /**< Object code of module */
#define MOD_ENT_CFG     2   /**< Config data of module */
#define MOD_ENT_LIB     3   /**< Library of module */
#define MOD_ENT_ATTR    4   /**< Attributes of module */
#define MOD_ENT_BCRU    5   /**< Binary configuration rule */
#define MOD_ENT_JAR     6   /**< Java archive of module  - deprecated since MSys 4.00R */
#define MOD_ENT_HLP     10  /**< Help info of module */
#define MOD_ENT_TXT     11  /**< Readme info of module */
#define MOD_ENT_SRC     12  /**< Source code of module (C/PLC...) */
#define MOD_ENT_LIBINT  13  /**< Internal PLC library, no object */
#define MOD_ENT_TGZ     14  /**< Packed C project source code */
#define MOD_ENT_LIBPLC  15  /**< External PLC library, *.plm */
#define MOD_ENT_SWREQ   16  /**< Software version requirement */
#define MOD_ENT_SDB     17  /**< 3S SDB file (symbol data description) */
#define MOD_ENT_LOGIC   19  /**< Logic file */
#define MOD_ENT_FIRMW   20  /**< Firmware */
#define MOD_ENT_XVD     21  /**< Extended validation description */
#define MOD_ENT_ZCRU    22  /**< Zipped CRU File */
#define MOD_ENT_MTAR    23  /**< M-Target project */
#define MOD_ENT_ZIP     24  /**< Zip archive (with any content) */
#define MOD_ENT_CIX     25  /**< Component interface XML */
#define MOD_ENT_CEX     26  /**< CRU extension XML */
#define MOD_ENT_CDI     100 /**< Card definition information */
#define MOD_ENT_USERDEF 200 /**< User definable objects */
/** @} */

/**
 * @name Possible values for MOD_ENTRY.Mode
 * @{
 */

#define MOD_NORMAL      1   /**< Object is in normal format (internal file) */
#define MOD_COMPACT     2   /**< Object is compressed (internal file) */
#define MOD_EXTERNAL    4   /**< Object is external (extra file) */
/** @} */

/**
 * @name Possible attribute definitions -> see structure MOD_ATTR later on
 * @{
 */

#define MOD_ATTR_REENTR     0x0001   /**< Module reentrant */
#define MOD_ATTR_NONLCFG    0x0002   /**< No online configuration allowed */
#define MOD_ATTR_NONLINST   0x0004   /**< No online installation allowed */
#define MOD_ATTR_NONLDEINST 0x0008   /**< No online uninstall allowed */
#define MOD_ATTR_ERRTOL     0x0010   /**< Load module on boot error */
#define MOD_ATTR_RETAIN     0x0020   /**< Retain variables in use */
#define MOD_ATTR_NZERORTN   0x0040   /**< No set to zero if inconsistent */
#define MOD_ATTR_DEBUGCODE  0x0080   /**< Debug code, extra instructions */
#define MOD_ATTR_DEBUGINFO  0x0100   /**< Debug information included */
#define MOD_ATTR_NAUTOINST  0x0200   /**< No installation at boot time */
#define MOD_ATTR_SYSTEM     0x0400   /**< Module is part of system */
#define MOD_ATTR_JAVACL     0x0800   /**< Module has own java class loader - deprecated since MSys 4.00R */
#define MOD_ATTR_SRVMIO     0x1000   /**< Service includes MIO functions */
#define MOD_ATTR_STDSYMBOLS 0x2000   /**< ELF object format has standard symbols */
/** @} */

/**
 * @name Possible values for MOD_SYSCFG_C.Status
 * @{
 */

#define MOD_CFG_CHANGE  1   /**< Change in group */
#define MOD_CFG_ADD     2   /**< Group has been added */
#define MOD_CFG_DELETE  3   /**< Group has been deleted */
/** @} */

/**
 * @name Possible values for MOD_COPYCFG_C.Mode
 * @{
 */

#define MOD_CFG_LOAD        1    /**< Load into ram disk /ram0 */
#define MOD_CFG_STORE       2    /**< Store onto boot device */
#define MOD_CFG_PROGRESS    3    /**< Inquire about the progress */
/** @} */

/**
 * @name Possible values for MOD_COPYFILE_C.Mode
 * @{
 */

#define MOD_FILE_CREATE     1    /**< Only create is allowed */
#define MOD_FILE_OWRITE     2    /**< Overwrite existing file */
#define MOD_FILE_PROGRESS   3    /**< Inquire about the progress */
#define MOD_FILE_MAXTASK    32   /**< Maximum of allowed copy file tasks */
/** @} */

/**
 * @name Possible values for MOD_LOCK_C.Mode
 * @{
 */

#define MOD_OBJ_LOCK    1   /**< Lock object for other hosts */
#define MOD_OBJ_UNLOCK  2   /**< Unlock object for all hosts */
/** @} */

/**
 * @name Possible values for MOD_LOCK_C.Object
 * @{
 */

#define MOD_OBJ_DBG 0       /**< Object is debugger */
#define MOD_OBJ_CFG 1       /**< Object is MConfig.ini */
#define MOD_OBJ_CON 2       /**< Object is console */
/** @} */

/**
 * @name Possible values for MOD_UPDATESW_C.Object
 * @{
 */

#define MOD_OBJ_ANY     0   /**< Object is any below */
#define MOD_OBJ_MBOOT1  1   /**< Object is MBOOT1 */
#define MOD_OBJ_MBOOT2  2   /**< Object is MBOOT2 */
#define MOD_OBJ_HXBIOS  3   /**< Object is HXBIOS */
#define MOD_OBJ_EXCORE  4   /**< Object is EXCORE */
#define MOD_OBJ_EXBIOS  5   /**< Object is EXBIOS */
#define MOD_OBJ_MPCBOOT 6   /**< Object is MPCBOOT */
#define MOD_OBJ_MPCBIOS 7   /**< Object is MPCBIOS */
#define MOD_OBJ_MXBOOT  8   /**< Object is MXBOOT */
#define MOD_OBJ_MXBIOS  9   /**< Object is MXBIOS */
#define MOD_OBJ_TBOOT   10  /**< Object is TBOOT */
#define MOD_OBJ_TBIOS   11  /**< Object is TBIOS */
#define MOD_OBJ_MX2BIOS 12  /**< Object is MX2BIOS */
#define MOD_OBJ_MHBOOT  13  /**< Object is MHBOOT */
#define MOD_OBJ_MHBIOS  14  /**< Object is MHBIOS */
#define MOD_OBJ_MCBOOT  15  /**< Object is MCBOOT */
#define MOD_OBJ_MCBIOS  16  /**< Object is MCBIOS */
/** @} */

/**
 * @name Possible values for MOD_XXXXX_R.Reboot
 * @{
 */

#define MOD_ONLINE  0       /**< Changed active immediately */
#define MOD_REBOOT  1       /**< Change active on next reboot */
#define MOD_RESTART 2       /**< Restart issued automatically */
/** @} */

/**
 * @name Possible values for MOD_PACKAGEUPDATE_C.Mode
 * @{
 */

#define MOD_PROG_UPDATE     1    /**< Program updates within package */
#define MOD_FORCE_UPDATE    2    /**< Force programming of updates */
#define MOD_GET_PROGRESS    3    /**< Inquire about the progress */
/** @} */

/**
 * @name Possible values for MOD_GETFILEINFO_C.Mode
 * @{
 */

#define MOD_GET_INFO    1   /**< Get attributes on file */
#define MOD_ERASE_INFO  2   /**< Erase attributes on file */
#define MOD_ERASE_ALL   3   /**< Erase all file attributes */
/** @} */

/**
 * @name Possible values for MOD_FORMAT_C.Mode
 * @{
 */

#define MOD_NORMALMODE  1   /**< Run formatting directly */
#define MOD_TASKMODE    2   /**< Run formatting as task */
/** @} */

/**
 * @name File Extensions
 * @{
 */

#define MOD_EXT ".m"        /**< Extension for module */
#define VER_EXT ".ver"      /**< Extension for version string */
/** @} */

/**
 * @name Possible values for MOD_DISKINFO.SmartStatus
 * @{
 */

#define SMART_UNKNOWN   0   /**< SMART info not supported by disk */
#define SMART_PASSED    1   /**< SMART overall-health self-assessment test passed */
#define SMART_FAILED    2   /**< SMART overall-health self-assessment test failed */
/** @} */

/**
 * @name Possible values for MOD_PARTINFO.Status
 * @{
 */

#define PART_IS_BOOTABLE    0x80     /**< A dos bootable partition (only 0x80 and 0x00 are valid) */
#define PART_NOT_BOOTABLE   0x00     /**< Not a bootable partition (only 0x80 and 0x00 are valid) */
/** @} */

/**
 * @name Possible values for MOD_PARTINFO.Type
 * @{
 */

#define PART_TYPE_FAT12     0x01     /**< FAT12 partition type */
#define PART_TYPE_FAT16     0x06     /**< FAT16 partition type */
#define PART_TYPE_FAT32     0x0b     /**< FAT32 partition type */
#define PART_TYPE_UNKNOWN   0x0  /**< UNKNOWN partition type */
/** @} */

/**
 * @name Possible values of MOD_PACKAGEUPDATE_R.Status
 * @{
 */

#define UPDATE_IN_PROGRESS  1    /**< Update is still running */
#define UPDATE_DONE         0    /**< Update done */
#define E_UPDATE_FAILED     -1   /**< Update failed, general error */
#define E_NOFILE            -2   /**< No file */
#define E_WRONG_MOD_TYPE    -10  /**< Wrong module type */
#define E_WRONG_MOD_VARIANT -11  /**< Wrong module variant */
#define E_UNKNOWN_DEVICE    -12  /**< Unknown design id in file */
#define E_RUNNING_ON_REF    -13  /**< MH2xx IO or BD device: jumper of FPGA reference is set */
#define E_WRONG_ID          -14  /**< MH2xx IO or BD device: design id of file doesn't match FPGA */
#define E_DOWNGRADE         -15  /**< Update is actually a down-grade -> new version is older */
#define E_NO_M86_SUPPORT    -16  /**< No support for m86 package update, only old update mechanism */
#define E_REQDRVVERSION     -17  /**< The required driver version is not present */
/** @} */

/**
 * @name Possible error codes for MOD_*.RetCode
 * @{
 */

#define MOD_E_OK            M_E_OK   /**< @copybrief #M_E_OK */
#define MOD_E_INPROGRESS    M_E_INPROGRESS   /**< @copybrief #M_E_INPROGRESS */
#define MOD_E_SMODE         (M_ES_MOD | M_E_SMODE)   /**< @copybrief #M_E_SMODE */
#define MOD_E_INSTALL       (M_ES_MOD | M_E_INSTALL)     /**< @copybrief #M_E_INSTALL */
#define MOD_E_NOMEM         (M_ES_MOD | M_E_NOMEM)   /**< @copybrief #M_E_NOMEM */
#define MOD_E_NOTSUPP       (M_ES_MOD | M_E_NOTSUPP)     /**< @copybrief #M_E_NOTSUPP */
#define MOD_E_NOMODNBR      (M_ES_MOD | M_E_NOMODNBR)    /**< @copybrief #M_E_NOMODNBR */
#define MOD_E_TIMEOUT1      (M_ES_MOD | M_E_TIMEOUT1)    /**< @copybrief #M_E_TIMEOUT1 */
#define MOD_E_TIMEOUT2      (M_ES_MOD | M_E_TIMEOUT2)    /**< @copybrief #M_E_TIMEOUT2 */
#define MOD_E_NOMOD1        (M_ES_MOD | M_E_NOMOD1)  /**< @copybrief #M_E_NOMOD1 */
#define MOD_E_NOMOD2        (M_ES_MOD | M_E_NOMOD2)  /**< @copybrief #M_E_NOMOD2 */
#define MOD_E_NOMOD3        (M_ES_MOD | M_E_NOMOD3)  /**< @copybrief #M_E_NOMOD3 */
#define MOD_E_NODELTASK     (M_ES_MOD | M_E_NODELTSK)    /**< @copybrief #M_E_NODELTSK */
#define MOD_E_NOVXWOBJ      (M_ES_MOD | M_E_NOVXWOBJ)    /**< @copybrief #M_E_NOVXWOBJ */
#define MOD_E_NOFILE        (M_ES_MOD | M_E_NOFILE)  /**< @copybrief #M_E_NOFILE */
#define MOD_E_BADREAD       (M_ES_MOD | M_E_BADREAD)     /**< @copybrief #M_E_BADREAD */
#define MOD_E_BADSEEK       (M_ES_MOD | M_E_BADSEEK)     /**< @copybrief #M_E_BADSEEK */
#define MOD_E_BADWRITE      (M_ES_MOD | M_E_BADWRITE)    /**< @copybrief #M_E_BADWRITE */
#define MOD_E_BADCHECK      (M_ES_MOD | M_E_BADCHECK)    /**< @copybrief #M_E_BADCHECK */
#define MOD_E_NOREAD        (M_ES_MOD | M_E_NOREAD)  /**< @copybrief #M_E_NOREAD */
#define MOD_E_NOWRITE       (M_ES_MOD | M_E_NOWRITE)     /**< @copybrief #M_E_NOWRITE */
#define MOD_E_WRONGVERS     (M_ES_MOD | M_E_WRONGVERS)   /**< @copybrief #M_E_WRONGVERS */
#define MOD_E_BADVXWLD      (M_ES_MOD | M_E_BADVXWLD)    /**< @copybrief #M_E_BADVXWLD */
#define MOD_E_BADMEMLD      (M_ES_MOD | M_E_BADMEMLD)    /**< @copybrief #M_E_BADMEMLD */
#define MOD_E_NOLIBREG      (M_ES_MOD | M_E_NOLIBREG)    /**< @copybrief #M_E_NOLIBREG */
#define MOD_E_BADELEM       (M_ES_MOD | M_E_BADELEM)     /**< @copybrief #M_E_BADELEM */
#define MOD_E_NOKEY         (M_ES_MOD | M_E_NOKEY)   /**< @copybrief #M_E_NOKEY */
#define MOD_E_BADNAME       (M_ES_MOD | M_E_BADNAME)     /**< @copybrief #M_E_BADNAME */
#define MOD_E_BADMODE       (M_ES_MOD | M_E_BADMODE)     /**< @copybrief #M_E_BADMODE */
#define MOD_E_BADOBJ        (M_ES_MOD | M_E_BADOBJ)  /**< @copybrief #M_E_BADOBJ */
#define MOD_E_LOCKED        (M_ES_MOD | M_E_LOCKED)  /**< @copybrief #M_E_LOCKED */
#define MOD_E_BADIPADDR     (M_ES_MOD | M_E_BADIPADDR)   /**< @copybrief #M_E_BADIPADDR */
#define MOD_E_NOENTRY       (M_ES_MOD | M_E_NOENTRY)     /**< @copybrief #M_E_NOENTRY */
#define MOD_E_NOREG         (M_ES_MOD | M_E_NOREG)   /**< @copybrief #M_E_NOREG */
#define MOD_E_BADINIT       (M_ES_MOD | M_E_BADINIT)     /**< @copybrief #M_E_BADINIT */
#define MOD_E_DEVFULL       (M_ES_MOD | M_E_DEVFULL)     /**< @copybrief #M_E_DEVFULL */
#define MOD_E_BADCOPY       (M_ES_MOD | M_E_BADCOPY)     /**< @copybrief #M_E_BADCOPY */
#define MOD_E_NOGLOBMEM     (M_ES_MOD | M_E_NOGLOBMEM)   /**< @copybrief #M_E_NOGLOBMEM */
#define MOD_E_NOAPPMEM      (M_ES_MOD | M_E_NOAPPMEM)    /**< @copybrief #M_E_NOAPPMEM */
#define MOD_E_SYSTEM1       (M_ES_MOD | M_E_SYSTEM1)     /**< @copybrief #M_E_SYSTEM1 */
#define MOD_E_BADROUTE      (M_ES_MOD | M_E_BADROUTE)    /**< @copybrief #M_E_BADROUTE */
#define MOD_E_BADLOGIN      (M_ES_MOD | M_E_BADLOGIN)    /**< @copybrief #M_E_BADLOGIN */
#define MOD_E_NOUNIT        (M_ES_MOD | M_E_NOUNIT)  /**< @copybrief #M_E_NOUNIT */
#define MOD_E_NOSIODEV      (M_ES_MOD | M_E_NOSIODEV)    /**< @copybrief #M_E_NOSIODEV */
#define MOD_E_BADSIODEV     (M_ES_MOD | M_E_BADSIODEV)   /**< @copybrief #M_E_BADSIODEV */
#define MOD_E_DEVINUSE      (M_ES_MOD | M_E_DEVINUSE)    /**< @copybrief #M_E_DEVINUSE */
#define MOD_E_DEVMISS       (M_ES_MOD | M_E_DEVMISS)     /**< @copybrief #M_E_DEVMISS */
#define MOD_E_NOMODEM       (M_ES_MOD | M_E_NOMODEM)     /**< @copybrief #M_E_NOMODEM */
#define MOD_E_BADMODEM      (M_ES_MOD | M_E_BADMODEM)    /**< @copybrief #M_E_BADMODEM */
#define MOD_E_BADPPP1       (M_ES_MOD | M_E_BADPPP1)     /**< @copybrief #M_E_BADPPP1 */
#define MOD_E_BADPPP2       (M_ES_MOD | M_E_BADPPP2)     /**< @copybrief #M_E_BADPPP2 */
#define MOD_E_BADSLIP       (M_ES_MOD | M_E_BADSLIP)     /**< @copybrief #M_E_BADSLIP */
#define MOD_E_BADPROTO      (M_ES_MOD | M_E_BADPROTO)    /**< @copybrief #M_E_BADPROTO */
#define MOD_E_LNAMEMISS     (M_ES_MOD | M_E_LNAMEMISS)   /**< @copybrief #M_E_LNAMEMISS */
#define MOD_E_BADHOST       (M_ES_MOD | M_E_BADHOST)     /**< @copybrief #M_E_BADHOST */
#define MOD_E_NOHOST        (M_ES_MOD | M_E_NOHOST)  /**< @copybrief #M_E_NOHOST */
#define MOD_E_BADGATE       (M_ES_MOD | M_E_BADGATE)     /**< @copybrief #M_E_BADGATE */
#define MOD_E_NOGATE        (M_ES_MOD | M_E_NOGATE)  /**< @copybrief #M_E_NOGATE */
#define MOD_E_BADMOUNT      (M_ES_MOD | M_E_BADMOUNT)    /**< @copybrief #M_E_BADMOUNT */
#define MOD_E_BADUMOUNT     (M_ES_MOD | M_E_BADUMOUNT)   /**< @copybrief #M_E_BADUMOUNT */
#define MOD_E_NODELSYS      (M_ES_MOD | M_E_NODELSYS)    /**< @copybrief #M_E_NODELSYS */
#define MOD_E_BADPATH       (M_ES_MOD | M_E_BADPATH)     /**< @copybrief #M_E_BADPATH */
#define MOD_E_NOSYS1        (M_ES_MOD | M_E_NOSYS1)  /**< @copybrief #M_E_NOSYS1 */
#define MOD_E_NOSYS2        (M_ES_MOD | M_E_NOSYS2)  /**< @copybrief #M_E_NOSYS2 */
#define MOD_E_NOFTP         (M_ES_MOD | M_E_NOFTP)   /**< @copybrief #M_E_NOFTP */
#define MOD_E_IPINUSE       (M_ES_MOD | M_E_IPINUSE)     /**< @copybrief #M_E_IPINUSE */
#define MOD_E_NOLOGIN       (M_ES_MOD | M_E_NOLOGIN)     /**< @copybrief #M_E_NOLOGIN */
#define MOD_E_NOMCONF       (M_ES_MOD | M_E_NOMCONF)     /**< @copybrief #M_E_NOMCONF */
#define MOD_E_DUPRES        (M_ES_MOD | M_E_DUPRES)  /**< @copybrief #M_E_DUPRES */
#define MOD_E_UPDATE        (M_ES_MOD | M_E_UPDATE)  /**< @copybrief #M_E_UPDATE */
#define MOD_E_BADFPROG      (M_ES_MOD | M_E_BADFPROG)    /**< @copybrief #M_E_BADFPROG */
#define MOD_E_BADVERIFY     (M_ES_MOD | M_E_BADVERIFY)   /**< @copybrief #M_E_BADVERIFY */
#define MOD_E_BADRANGE      (M_ES_MOD | M_E_BADRANGE)    /**< @copybrief #M_E_BADRANGE */
#define MOD_E_BADCPU        (M_ES_MOD | M_E_BADCPU)  /**< @copybrief #M_E_BADCPU */
#define MOD_E_NOERRTOL      (M_ES_MOD | M_E_NOERRTOL)    /**< @copybrief #M_E_NOERRTOL */
#define MOD_E_WDOGON        (M_ES_MOD | M_E_WDOGON)  /**< @copybrief #M_E_WDOGON */
#define MOD_E_NOONLINE      (M_ES_MOD | M_E_NOONLINE)    /**< @copybrief #M_E_NOONLINE */
#define MOD_E_BADCONFIG     (M_ES_MOD | M_E_BADCONFIG)   /**< @copybrief #M_E_BADCONFIG */
#define MOD_E_MODMISS       (M_ES_MOD | M_E_MODMISS)     /**< @copybrief #M_E_MODMISS */
#define MOD_E_BADSNTP       (M_ES_MOD | M_E_BADSNTP)     /**< @copybrief #M_E_BADSNTP */
#define MOD_E_PARM          (M_ES_MOD | M_E_PARM)    /**< @copybrief #M_E_PARM */
#define MOD_E_NBELEM        (M_ES_MOD | M_E_NBELEM)  /**< @copybrief #M_E_NBELEM */
#define MOD_E_FULL          (M_ES_MOD | M_E_FULL)    /**< @copybrief #M_E_FULL */
#define MOD_E_LENGTH        (M_ES_MOD | M_E_LENGTH)  /**< @copybrief #M_E_LENGTH */
#define MOD_E_OLDDRV        (M_ES_MOD | M_E_OLDVERS3)    /**< @copybrief #M_E_OLDVERS3 */
#define MOD_E_BADHANDSHAKE  (M_ES_MOD | M_E_BADSIOHANDSHAKE)     /**< @copybrief #M_E_BADSIOHANDSHAKE */
/** @} */
/** @} */

/**
 * @addtogroup MOD-SMI
 * @{
 */

/**
 * @name Possible SMI Commands
 * @{
 */

/**
 * @brief Install a software module.
 *
 * @param[in]   #MOD_INSTALL_C
 * @param[out]  #MOD_INSTALL_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_INSTALL            100
/**
 * @brief Install a java software module.
 *
 * @param[in]   #MOD_JAVAINSTALL_C
 * @param[out]  #MOD_JAVAINSTALL_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @deprecated The support for the java runtime was discontinued in MSys V4.00R.
 */
#define MOD_PROC_JAVAINSTALL        102
/**
 * @brief Remove a software module.
 *
 * @param[in]   #MOD_REMOVE_C
 * @param[out]  #MOD_REMOVE_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_REMOVE             106
/**
 * @brief Change the system configuration.
 *
 * @param[in]   #MOD_SYSCFG_C
 * @param[out]  #MOD_SYSCFG_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_SYSCFG             110
/**
 * @brief Copy the MConfig.ini from device to /ram0 or vice versa.
 *
 * @param[in]   #MOD_COPYCFG_C
 * @param[out]  #MOD_COPYCFG_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_COPYCFG            112
/**
 * @brief Lock or unlock an object.
 *
 * @param[in]   #MOD_LOCK_C
 * @param[out]  #MOD_LOCK_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_LOCK               114
/**
 * @brief Copy a file from device to /ram0 or vice versa.
 *
 * @param[in]   #MOD_COPYFILE_C
 * @param[out]  #MOD_COPYFILE_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_COPYFILE           116
/**
 * @brief Set the system time [UTC].
 *
 * @param[in]   #MOD_SETTIME_C
 * @param[out]  #MOD_SETTIME_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @since MSys V3.95
 */
#define MOD_PROC_SETTIME            122
/**
 * @brief Set the system timezone.
 *
 * @param[in]   #MOD_SETTIMEZONE_C
 * @param[out]  #MOD_SETTIMEZONE_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 * @since MSys V3.95
 */
#define MOD_PROC_SETTIMEZONE        124
/**
 * @brief Set the system date and time [LOCAL].
 *
 * @param[in]   #MOD_SETDATE_C
 * @param[out]  #MOD_SETDATE_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_SETDATE            126
/**
 * @brief Get the boot parameters.
 *
 * @param[in]   #MOD_GETBOOT_C
 * @param[out]  #MOD_GETBOOT_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_GETBOOT            128
/**
 * @brief Set the boot parameters.
 *
 * @param[in]   #MOD_SETBOOT_C
 * @param[out]  #MOD_SETBOOT_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_SETBOOT            130
/**
 * @brief Reset the NVRAM at next boot.
 *
 * @param[in]   #MOD_NVRESET_C
 * @param[out]  #MOD_NVRESET_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_NVRESET            132
/**
 * @brief Reboot the M1.
 *
 * @param[in]   #MOD_REBOOT_C
 * @param[out]  #MOD_REBOOT_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_REBOOT             134
/**
 * @brief Format a device.
 *
 * @param[in]   #MOD_FORMAT_C
 * @param[out]  #MOD_FORMAT_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_FORMAT             136
/**
 * @brief Update the firmware of the CPU.
 *
 * @param[in]   #MOD_UPDATESW_C
 * @param[out]  #MOD_UPDATESW_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_UPDATESW           138
/**
 * @brief Get file information.
 *
 * @param[in]   #MOD_GETFILEINFO_C
 * @param[out]  #MOD_GETFILEINFO_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_GETFILEINFO        140
/**
 * @brief Stop all software modules.
 *
 * @param[in]   #MOD_RESETALL_C
 * @param[out]  #MOD_RESETALL_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_RESETALL           142
/**
 * @brief Get progress information.
 *
 * @param[in]   #MOD_PROGRESS_C
 * @param[out]  #MOD_PROGRESS_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_PROGRESS           144
/**
 * @brief Set the MConfig.ini path name.
 *
 * @param[in]   #MOD_SETCFG_C
 * @param[out]  #MOD_SETCFG_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_SETCFG             146
/**
 * @brief Check if a file name is valid.
 *
 * @param[in]   #MOD_CHECKFILENAME_C
 * @param[out]  #MOD_CHECKFILENAME_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_CHECKFILENAME      148
/**
 * @brief Copy the MConfig.ini from device to /ram0 or vice versa for multi user.
 *
 * @param[in]   #MOD_COPYCFG2_C
 * @param[out]  #MOD_COPYCFG2_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_COPYCFG2           150
/**
 * @brief Format a device with 64 bit parameters.
 *
 * @param[in]   #MOD_FORMAT64_C
 * @param[out]  #MOD_FORMAT64_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_FORMAT64           154
/**
 * @brief Get progress information with 64 bit parameters.
 *
 * @param[in]   #MOD_PROGRESS64_C
 * @param[out]  #MOD_PROGRESS64_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_PROGRESS64         156
/**
 * @brief Get the CFC device and partition information.
 *
 * @param[in]   #MOD_GETDEVICEPARAM_C
 * @param[out]  #MOD_GETDEVICEPARAM_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_GETDISKPARTINFO    158
/**
 * @brief Partition and format a CFC device.
 *
 * @param[in]   #MOD_PARTITIONDISK_C
 * @param[out]  #MOD_PARTITIONDISK_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_PARTITIONDISK      160
/**
 * @brief Program an update from m86 package file.
 *
 * @param[in]   #MOD_PACKAGEUPDATE_C
 * @param[out]  #MOD_PACKAGEUPDATE_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_PACKAGEUPDATE      162
/**
 * @brief Get the DOS file system volume information.
 *
 * @param[in]   #MOD_GETDOSFSINFO_C
 * @param[out]  #MOD_GETDOSFSINFO_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_GETDOSFSINFO       164
/**
 * @brief Copy a file for multi user.
 *
 * @param[in]   #MOD_COPYFILE2_C
 * @param[out]  #MOD_COPYFILE2_R
 *
 * @return #MOD_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MOD_PROC_COPYFILE2          166
/** @} */
/** @} */

/**
 * @name Structures
 * @{
 */

/**
 * Parameters for the installation of a software module
 */
typedef struct
{
    CHAR8   PathName[M_PATHLEN_A];   /**< Path and file name of module */
    CHAR8   TypeName[M_MODNAMELEN_A];    /**< Module type: "HVC", "SFT", ... */
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Application name of module */
    SINT32  AppIndex;           /**< Application index of module */
    UINT32  AppIdentity;        /**< Id number of application code */
    UINT32  MemPart;            /**< Memory partition it is loaded */
    SINT32  TskPrior;           /**< Task priority (0 - 255) */
    UINT32  DebugMode;          /**< Debug mode bitwise coded */
    CHAR8   ProfileName[M_PATHLEN_A];    /**< Name of config file, "" = MConfig.ini */
    SINT32  LineNbr;            /**< Line number in config file, 0 = start of file */
} MOD_CONF;


/**
 * @name Structures for the file format in a software module (*.m file)
 * @{
 */

/**
 * File header of a module
 */
typedef struct
{
    UINT32  FileType;           /**< Type of module: #MOD_VXWMODULE... */
    UINT32  MainVersion;        /**< Main version of file format */
    UINT32  SubVersion;         /**< Sub version of file format */
    UINT32  TimeDate;           /**< Date generated in seconds since 1970 */
    UINT32  VersType;           /**< Version type: #M_VER_ALPHA, ... */
    UINT32  VersCode[3];        /**< Version code of module */
    UINT32  CheckSize;          /**< Size for checksum */
    UINT32  nEntries;           /**< Number of objects */
    UINT32  OffEntryTable;      /**< Offset to object descriptor */
    UINT32  Checksum;           /**< Checksum of complete module */
} MOD_FHEAD;

/**
 * Object descriptor
 */
typedef struct
{
    UINT32  Type;               /**< Type of object */
    UINT32  Mode;               /**< Mode of object: #MOD_NORMAL, ... */
    UINT32  Len;                /**< Size of object */
    UINT32  OffEntry;           /**< Offset to object */
    UINT32  VersType;           /**< Version type: #M_VER_ALPHA, ... */
    UINT32  VersCode[3];        /**< Version code of object */
    CHAR8   EntryName[13];      /**< Filename of object */
    UINT8   Spare[3];           /**< Not used, 0 for now */
} MOD_ENTRY;

/**
 * Attribute data
 */
typedef struct
{
    BOOL8   Reentrant;          /**< Module reentrant */
    BOOL8   NoOnlineConfig;     /**< No online configuration allowed */
    BOOL8   NoOnlineInstall;    /**< No online installation allowed */
    BOOL8   NoOnlineDeinstall;  /**< No online uninstall allowed */
    BOOL8   ErrorTolerant;      /**< Load module on boot error */
    BOOL8   Retain;             /**< Retain variables in use */
    BOOL8   NoZeroRetain;       /**< No set to zero if inconsistent */
    BOOL8   DebugCode;          /**< Debug code, extra instructions */
    BOOL8   DebugInfo;          /**< Debug information included */
    BOOL8   NoAutoInstall;      /**< No installation at boot time */
    BOOL8   SystemModule;       /**< Module is part of system */
    BOOL8   JavaCLoader;        /**< Module has own java class loader - deprecated since MSys 4.00R */
    BOOL8   SrvMio;             /**< Service includes MIO functions */
    BOOL8   StdSymbols;         /**< ELF object format has standard symbols */
    BOOL8   IsComponent;        /**< Module is a component */
    UINT8   Spare2[17];         /**< Not used, 0 for now */
} MOD_ATTR;

/** @} */
/**
 * Structure for the SMI-Call #MOD_PROC_INSTALL
 */
typedef struct
{
    MOD_CONF    Conf;           /**< Base parameters from MConfig.ini */
} MOD_INSTALL_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_INSTALL
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MOD_INSTALL_R;

/**
 * Structure for the SMI-Call #MOD_PROC_JAVAINSTALL
 */
typedef struct
{
    MOD_CONF    Conf;           /**< Base parameters from MConfig.ini */
    CHAR8       MainClass[M_PATHLEN_A];  /**< Class with main function */
} MOD_JAVAINSTALL_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_JAVAINSTALL
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MOD_JAVAINSTALL_R;

/**
 * Structure for the SMI-Call #MOD_PROC_REMOVE
 */
typedef struct
{
    CHAR8   AppName[M_MODNAMELEN_A];     /**< Application name of module */
} MOD_REMOVE_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_REMOVE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MOD_REMOVE_R;

/**
 * Structure for the SMI-Call #MOD_PROC_SYSCFG
 */
typedef struct
{
    CHAR8   Section[16];        /**< Name of section with change */
    CHAR8   Group[16];          /**< Name of group with change */
    SINT32  Status;             /**< #MOD_CFG_CHANGE, #MOD_CFG_ADD,... */
    SINT32  LineNbr;            /**< Line number with change, 0 = start of file */
} MOD_SYSCFG_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_SYSCFG
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Reboot;             /**< 0 = online change, 1 = reboot */
    SINT32  LineNbr;            /**< Line number with error, 0 = not defined */
} MOD_SYSCFG_R;

/**
 * Structure for the SMI-Call #MOD_PROC_COPYCFG
 */
typedef struct
{
    SINT32  Mode;               /**< #MOD_CFG_LOAD, #MOD_CFG_STORE */
} MOD_COPYCFG_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_COPYCFG
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MOD_COPYCFG_R;

/**
 * Structure for the SMI-Call #MOD_PROC_COPYCFG2
 */
typedef struct
{
    SINT32  Mode;               /**< #MOD_CFG_LOAD, #MOD_CFG_STORE, #MOD_CFG_PROGRESS */
    UINT32  HandleId;           /**< Id of CopyCfg handle */
    UINT32  URef;               /**< Unique reference number */
    UINT32  Spare;              /**< Not used, 0 for now */
    CHAR8   FileName[M_PATHLEN_A];   /**< Filename of MConfig.123 instance */
    CHAR8   Spare2[92];         /**< Not used, 0 for now */
} MOD_COPYCFG2_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_COPYCFG2
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  HandleId;           /**< Id of CopyCfg handle */
    UINT32  URef;               /**< Unique reference number */
    UINT8   Progress;           /**< Copy progress 0-100% */
    UINT8   CfgFileLock;        /**< FileCopy already active Unl/Rd/Wr */
    UINT8   InOperation;        /**< Operation still active TRUE/FALSE */
    UINT8   Spare[1];           /**< Not used, 0 for now */
    CHAR8   FileName[M_PATHLEN_A];   /**< Filename of MConfig.123 instance */
    CHAR8   Spare2[92];         /**< Not used, 0 for now */
} MOD_COPYCFG2_R;

/**
 * Structure for the SMI-Call #MOD_PROC_COPYFILE
 */
typedef struct
{
    SINT32  Mode;               /**< #MOD_FILE_CREATE, #MOD_FILE_OWRITE */
    CHAR8   SourceName[M_PATHLEN_A];     /**< Path/Name of source file */
    CHAR8   DestName[M_PATHLEN_A];   /**< Path/Name of destination file */
} MOD_COPYFILE_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_COPYFILE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  FileSize;           /**< Size required on destination */
} MOD_COPYFILE_R;

/**
 * Structure for the SMI-Call #MOD_PROC_COPYFILE2
 */
typedef struct
{
    SINT32  Mode;               /**< #MOD_FILE_CREATE, #MOD_FILE_OWRITE, #MOD_FILE_PROGRESS */
    CHAR8   SourceName[M_PATHLEN_A];     /**< Path/Name of source file */
    CHAR8   DestName[M_PATHLEN_A];   /**< Path/Name of destination file */
    UINT32  Id;                 /**< CopyFileId */
} MOD_COPYFILE2_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_COPYFILE2
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Id;                 /**< CopyFileId */
    SINT32  FileSize;           /**< Size required on destination */
    SINT8   Progress;           /**< Copy progress 0-100% */
    UINT8   Spare[7];           /**< Not used, 0 for now */
} MOD_COPYFILE2_R;

/**
 * Structure for the SMI-Call #MOD_PROC_LOCK
 */
typedef struct
{
    SINT32  Mode;               /**< #MOD_OBJ_LOCK, #MOD_OBJ_UNLOCK */
    SINT32  Object;             /**< #MOD_OBJ_CFG, #MOD_OBJ_CON */
    UINT32  CallerIP;           /**< IP address of caller */
    UINT32  SessionId;          /**< Identification of user session */
} MOD_LOCK_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_LOCK
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MOD_LOCK_R;

/**
 * Structure for the SMI-Call #MOD_PROC_SETTIME
 */
typedef struct
{
    TIMESTAMP   TimeUtc;        /**< System time [UTC] */
    UINT32      Spare[32];      /**< Not used, 0 for now */
} MOD_SETTIME_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_SETTIME
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MOD_SETTIME_R;

/**
 * Structure for the SMI-Call #MOD_PROC_SETTIMEZONE
 */
typedef struct
{
    CHAR8   TimeZone[M_TIMEZONELEN_A];   /**< System timezone */
    BOOL8   Remanent;           /**< Save remanently in MConfig.ini */
    BOOL8   Spare1[3];          /**< Not used, 0 for now */
    UINT32  Spare2[31];         /**< Not used, 0 for now */
} MOD_SETTIMEZONE_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_SETTIMEZONE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MOD_SETTIMEZONE_R;

/**
 * Structure for the SMI-Call #MOD_PROC_SETDATE
 */
typedef struct
{
    struct tm   DateTime;       /**< Date and time of RTC */
} MOD_SETDATE_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_SETDATE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MOD_SETDATE_R;

/**
 * Structure for the SMI-Call #MOD_PROC_GETBOOT
 */
typedef struct
{
    SINT32  Mode;               /**< Must be 0 for now */
} MOD_GETBOOT_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_GETBOOT
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    BOOT_INFO   Boot;           /**< Boot parameters */
} MOD_GETBOOT_R;

/**
 * Structure for the SMI-Call #MOD_PROC_SETBOOT
 */
typedef struct
{
    BOOT_INFO   Boot;           /**< Boot parameters */
} MOD_SETBOOT_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_SETBOOT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Reboot;             /**< 0 = online change, 1 = reboot */
} MOD_SETBOOT_R;

/**
 * Structure for the SMI-Call #MOD_PROC_NVRESET
 */
typedef struct
{
    SINT32  Mode;               /**< 0 = /nvram0, 1 = /nvram1 */
} MOD_NVRESET_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_NVRESET
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Reboot;             /**< 0 = online change, 1 = reboot */
} MOD_NVRESET_R;

/**
 * Structure for the SMI-Call #MOD_PROC_REBOOT
 */
typedef struct
{
    SINT32  Mode;               /**< Must be 0 for now */
} MOD_REBOOT_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_REBOOT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MOD_REBOOT_R;

/**
 * Structure for the SMI-Call #MOD_PROC_FORMAT
 */
typedef struct
{
    CHAR8   DeviceName[M_PATHLEN_A];     /**< Name of device: "/cfc0" */
    UINT32  DeviceSize;         /**< Required size, 0 = default */
    UINT32  Mode;               /**< #MOD_NORMALMODE, #MOD_TASKMODE */
} MOD_FORMAT_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_FORMAT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Reboot;             /**< 0=online, 1=reboot, 2=reset */
    UINT32  DeviceSize;         /**< Formatted size */
} MOD_FORMAT_R;

/**
 * Structure for the SMI-Call #MOD_PROC_FORMAT64
 */
typedef struct
{
    CHAR8   DeviceName[M_PATHLEN_A];     /**< Name of device: "/cfc0" */
    UINT64  DeviceSize;         /**< Required size, 0 = default */
    UINT32  Mode;               /**< #MOD_NORMALMODE, #MOD_TASKMODE */
    UINT32  Spare[32];          /**< Not used, 0 for now */
} MOD_FORMAT64_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_FORMAT64
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Reboot;             /**< 0=online, 1=reboot, 2=reset */
    UINT64  DeviceSize;         /**< Formatted size */
} MOD_FORMAT64_R;

/**
 * dosFs info element
 */
typedef struct
{
    CHAR8   FatType[16];        /**< FAT12, FAT16, FAT32 (usually up to 8 characters) */
    CHAR8   BootVolumeLabel[16];     /**< PBR volume label (usually up to 11 characters) */
    UINT32  VolumeId;           /**< Hex: volume Id */
    UINT32  TotalSectors;       /**< Total number of sectors */
    UINT32  BytesPerSector;     /**< Usually 512 bytes */
    UINT32  SectorsPerCluster;  /**< Number of sectors per cluster, usually 1, 2, 4,..., 128 */
    UINT32  ReservedSectors;    /**< Number of reserved sectors, sectors before first FAT table */
    UINT32  SectorsPerFat;      /**< Number of sectors per FAT copy */
    UINT32  FatTables;          /**< Number of FAT table copies, usually 2 */
    UINT32  HiddenSectors;      /**< Number of hidden sectors, partition offset from sector 0 */
    UINT32  DataStartSector;    /**< First data cluster starts at sector number (relative) */
    UINT32  Properties;         /**< DOS file system volume/partition properties */
    UINT32  Spare[46];          /**< Not used, 0 for now */
} MOD_DOSFSINFO;

/**
 * Structure for the SMI-Call #MOD_PROC_GETDOSFSINFO
 */
typedef struct
{
    CHAR8   VolumeName[M_PATHLEN_A];     /**< Name of volume: /cfc0, /cfc0_2, /flash0, ... */
    UINT32  Spare[43];          /**< Not used, 0 for now */
} MOD_GETDOSFSINFO_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_GETDOSFSINFO
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    MOD_DOSFSINFO   FsInfo;     /**< File system information (like dosFsShow) */
    UINT32          Spare[63];  /**< Not used, 0 for now */
} MOD_GETDOSFSINFO_R;


/**
 * @name SMI-Function MOD_PROC_GETDISKPARTINFO
 * @{
 */

/**
 * disk information element
 */
typedef struct
{
    CHAR8   ModelName[48];      /**< Model name */
    CHAR8   SerialNumber[32];   /**< Controller serial number */
    CHAR8   FirmwareRevison[16];     /**< Firmware revision */
    UINT32  SmartStatus;        /**< #SMART_UNKNOWN, #SMART_PASSED, #SMART_FAILED */
    CHAR8   spare[156];         /**< Not used, 0 for now */
} MOD_DISKINFO;

/**
 * partition information element
 */
typedef struct
{
    UINT32  Offset;             /**< (hex) start sector of partition */
    UINT32  Size;               /**< (hex) number of sectors in partition */
    UINT32  Status;             /**< #PART_IS_BOOTABLE, #PART_NOT_BOOTABLE or invalid entry */
    UINT32  Type;               /**< #PART_TYPE_FAT12, #PART_TYPE_FAT16, #PART_TYPE_FAT32, or #PART_TYPE_UNKNOWN */
    UINT32  Spare[4];           /**< Not used, 0 for now */
} MOD_PARTINFO;

/**
 * Structure for the SMI-Call #MOD_PROC_GETDISKPARTINFO
 */
typedef struct
{
    CHAR8   DeviceName[M_PATHLEN_A];     /**< Name of device: "/cfc0" or "/cfc1" */
    /**
     * specify amount of information in reply:
     * 0 = disk size (sectors and sector-size)
     * 1 = additionally disk name, serial, revision
     * 2 >= additionally partitioning information
     */
    UINT32  InfoDetail;
    UINT32  Spare[42];          /**< Not used, 0 for now */
} MOD_GETDEVICEPARAM_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_GETDISKPARTINFO
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          Sectors;    /**< (hex) total number of sectors on disk */
    UINT32          SectorSize; /**< (hex) bytes per sector (almost always 512 byte) */
    UINT32          Spare[16];  /**< Not used, 0 for now */
    MOD_DISKINFO    DiskInfo;   /**< Disk name, serial, revision */
    UINT32          NbPart;     /**< Number of primary- and logical-partition entries */
    /**
     * List of max. 16 partition information elements
     * (primary and logical partitions (within extended)
     */
    MOD_PARTINFO    PartEntry[16];
    UINT32          Spare2[44]; /**< Not used, 0 for now */
} MOD_GETDEVICEPARAM_R;

/** @} */
/**
 * Structure for the SMI-Call #MOD_PROC_PARTITIONDISK
 */
typedef struct
{
    CHAR8   DeviceName[M_PATHLEN_A];     /**< Name of device: "/cfc0" or "/cfc1" */
    UINT32  NbPart;             /**< Specify number of primary partitions to create (1-4) */
    UINT32  Spare;              /**< Not used, 0 for now */
    UINT32  Size2;              /**< Partition Size2 in %, valid range 0-99% */
    UINT32  Size3;              /**< Partition Size3 in %, valid range 0-98% */
    UINT32  Size4;              /**< Partition Size4 in %, valid range 0-97% */
    UINT32  Type1;              /**< Must be PART_TYPE_FAT16 or PART_TYPE_FAT32 */
    UINT32  Type2;              /**< Must be PART_TYPE_FAT16 or PART_TYPE_FAT32 */
    UINT32  Type3;              /**< Must be PART_TYPE_FAT16 or PART_TYPE_FAT32 */
    UINT32  Type4;              /**< Must be PART_TYPE_FAT16 or PART_TYPE_FAT32 */
    UINT32  ForcePartitioning;  /**< !!! Only for test !!! If TRUE, ignore running applications and partition disk! */
    UINT32  Spare2[97];         /**< Not used, 0 for now */
} MOD_PARTITIONDISK_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_PARTITIONDISK
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Spare[63];          /**< Not used, 0 for now */
} MOD_PARTITIONDISK_R;

/**
 * Structure for the SMI-Call #MOD_PROC_UPDATESW
 */
typedef struct
{
    UINT32  CardNb;             /**< Must be 0 for now */
    UINT32  Object;             /**< Use define #MOD_OBJ_ANY for auto detection or use of the similar defines to specify the object type exactly. */
    CHAR8   FileName[M_PATHLEN_A];   /**< Path/Name of new software */
} MOD_UPDATESW_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_UPDATESW
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Reboot;             /**< See defines #MOD_ONLINE, #MOD_REBOOT or #MOD_RESTART */
} MOD_UPDATESW_R;

/**
 * Structure for the SMI-Call #MOD_PROC_PACKAGEUPDATE
 */
typedef struct
{
    SINT32  Mode;               /**< #MOD_PROG_UPDATE, #MOD_FORCE_UPDATE, #MOD_GET_PROGRESS */
    CHAR8   FileName[M_PATHLEN_A];   /**< Absolute path/name of m86 package file */
    UINT32  CardNb;             /**< Not used, 0 for now */
    UINT32  Spare[41];          /**< Not used, 0 for now */
} MOD_PACKAGEUPDATE_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_PACKAGEUPDATE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Status;             /**< Sub/file specific status codes - OK or error code */
    UINT64  DoneSize;           /**< Size done in bytes - overall progress */
    UINT64  WholeSize;          /**< Total size in bytes - overall progress */
    UINT64  DoneSize2;          /**< Size done in bytes - sub/file progress */
    UINT64  WholeSize2;         /**< Total size in bytes - sub/file progress */
    UINT32  DoneElements;       /**< Completed number of elements/files */
    UINT32  TotalElements;      /**< Total number of elements/files */
    CHAR8   ElementName[16];    /**< Filename/object currently in progress */
    UINT32  Spare[48];          /**< Not used, 0 for now */
} MOD_PACKAGEUPDATE_R;

/**
 * Structure for the SMI-Call #MOD_PROC_GETFILEINFO
 */
typedef struct
{
    SINT32  Mode;               /**< #MOD_GET_INFO, #MOD_ERASE_INFO, ... */
    CHAR8   RemotePath[M_PATHLEN_A];     /**< Path of file: /cfc0/app/ */
    CHAR8   RemoteName[M_FILENAMELEN_A];     /**< Name of file: hvc.m */
} MOD_GETFILEINFO_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_GETFILEINFO
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  TimeStamp;          /**< Timestamp, 0 = not available */
    UINT32  FileSize;           /**< Size of file, 0 = not available */
    UINT32  Spare[2];           /**< Not used, 0 for now */
} MOD_GETFILEINFO_R;

/**
 * Structure for the SMI-Call #MOD_PROC_RESETALL
 */
typedef struct
{
    SINT32  Mode;               /**< 0 = reply, 1 = no reply */
} MOD_RESETALL_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_RESETALL
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MOD_RESETALL_R;

/**
 * Structure for the SMI-Call #MOD_PROC_PROGRESS
 */
typedef struct
{
    CHAR8   DeviceName[M_PATHLEN_A];     /**< Name of device i.e. "/cfc0" */
    UINT32  Spare;              /**< Must be 0 for now */
} MOD_PROGRESS_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_PROGRESS
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Reboot;             /**< 0=online, 1=reboot, 2=reset */
    UINT32  DoneSize;           /**< Size done in bytes */
    UINT32  DeviceSize;         /**< Total size in bytes */
} MOD_PROGRESS_R;

/**
 * Structure for the SMI-Call #MOD_PROC_PROGRESS64
 */
typedef struct
{
    CHAR8   DeviceName[M_PATHLEN_A];     /**< Name of device i.e. "/cfc0" */
    UINT32  Spare[32];          /**< Must be 0 for now */
} MOD_PROGRESS64_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_PROGRESS64
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Reboot;             /**< 0=online, 1=reboot, 2=reset */
    UINT64  DoneSize;           /**< Size done in bytes */
    UINT64  WholeSize;          /**< Total size in bytes */
    UINT32  Spare[32];          /**< Must be 0 for now */
} MOD_PROGRESS64_R;

/**
 * Structure for the SMI-Call #MOD_PROC_SETCFG
 */
typedef struct
{
    CHAR8   DeviceName[M_PATHLEN_A];     /**< Name of device i.e. "/cfc0/" */
    UINT32  Spare;              /**< Must be 0 for now */
} MOD_SETCFG_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_SETCFG
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MOD_SETCFG_R;

/**
 * Structure for the SMI-Call #MOD_PROC_CHECKFILENAME
 */
typedef struct
{
    SINT32  Mode;               /**< Not used, 0 for now */
    CHAR8   FileName[M_XFILENAMELEN_A];  /**< Name of file to check */
    UINT32  Spare[4];           /**< Not used, 0 for now */
} MOD_CHECKFILENAME_C;

/**
 * Structure for the SMI-Reply #MOD_PROC_CHECKFILENAME
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    CHAR8   FileName[M_XFILENAMELEN_A];  /**< Valid file name */
    SINT32  ErrCode;            /**< Extended error code */
    UINT32  Spare[3];           /**< Not used, 0 for now */
} MOD_CHECKFILENAME_R;

/** @} */
/** @} */

#ifdef __cplusplus
}
#endif

#endif
