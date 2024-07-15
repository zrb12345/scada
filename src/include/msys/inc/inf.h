/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     inf.h
* @author   Dornerm
* @brief    System Info Handler
*           This file contains all definitions and declarations exported by
*           the System Info Handler, that could be used by modules running on
*           another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef INF__H
#define INF__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>
#include <time.h>                       /* included for struct tm  */
#include <msys.h>
#if M_OS_VXWORKS
#include "msys_e.h"
#endif

/**
 * @name API
 * @{
 */


/**
 * @addtogroup INF-DEF
 * @{
 */

/**
 * @name Definitions
 * @{
 */

#define INF_PROTVERS    2   /**< RPC protocol version */
#define BOOT_LEN1       20  /**< Length of boot parameter */
#define BOOT_LEN2       30  /**< Length of boot parameter */
#define BOOT_LEN3       80  /**< Length of boot parameter */
#define IP_ADDR_LEN     20  /**< IP address string length */
#define NOT_AVAILABLE   0xFFFFFFFF   /**< Value not available */
#define MAX_CMND_SIZE   256 /**< Maximum size of shell command */
#define TASKGROUPS      10  /**< Number of task groups */

/**
 * @name Possible values for INF_SOBJINFO.Type and INF_DRVINFO.Type
 * @{
 */

#define INF_OT_ROM      1   /**< Object type ROM */
#define INF_OT_FILE     2   /**< Object type file */
#define INF_OT_DRIVER   3   /**< Object type driver */
#define INF_OT_FIRMWARE 4   /**< Object type firmware */
#define INF_OT_SERVICE  5   /**< Object type service */
/** @} */

/**
 * @name Possible values for INF_SOBJINFO.State and INF_DRVINFO.State
 * @{
 */

#define INF_OS_PRESENT  1   /**< Present and not in use */
#define INF_OS_IN_USE   2   /**< Loaded and in use */
/** @} */

/**
 * @name Possible values for INF_PROC_CPUUSAGE_C.Mode
 * @{
 */

#define INF_USAGE_CONTIN    1    /**< Continuous mode of measurement */
#define INF_USAGE_RESET     2    /**< Restart measurement afterwards */
/** @} */

/**
 * @name Possible values for INF_PROC_ALIVE_C.Mode
 * @{
 */

#define INF_NORMALMODE      0    /**< Normal (I am alive) command */
#define INF_APPSTATEMODE    1    /**< Returns the application state from RES */
#define INF_RESTART_APP     2    /**< Returns the application state and restart count */
/** @} */

/**
 * @name Possible error codes
 * @{
 */

#define INF_E_OK        M_E_OK   /**< @copybrief #M_E_OK */
#define INF_E_BADARGS   (M_ES_INF | M_E_BADARGS)     /**< @copybrief #M_E_BADARGS */
#define INF_E_SMODE     (M_ES_INF | M_E_SMODE)   /**< @copybrief #M_E_SMODE */
#define INF_E_NOMEM     (M_ES_INF | M_E_NOMEM)   /**< @copybrief #M_E_NOMEM */
#define INF_E_NOTSUPP   (M_ES_INF | M_E_NOTSUPP)     /**< @copybrief #M_E_NOTSUPP */
#define INF_E_NOOBJ     (M_ES_INF | M_E_NOOBJ)   /**< @copybrief #M_E_NOOBJ */
#define INF_E_TIMEOUT   (M_ES_INF | M_E_TIMEOUT3)    /**< @copybrief #M_E_TIMEOUT3 */
#define INF_E_BADINDEX  (M_ES_INF | M_E_BADINDEX)    /**< @copybrief #M_E_BADINDEX */
/** @} */
/** @} */

/**
 * @name Structures
 * @{
 */

typedef SYS_VERSION INF_VERSION;

/** @} */
/** @} */
/** @} */

/**
 * @name SMI
 * @{
 */


/**
 * @addtogroup INF-SMI
 * @{
 */

/**
 * @name Possible SMI Commands
 * @{
 */

/**
 * @brief This procedure can be used to query the list of IP-addresses
 *        for a CPU-alliance. A maximum of 3 CPUs can be used to make
 *        up a network by multi-processing or networking.
 *
 * @param[in]   #INF_CPUADDRLST_C
 * @param[out]  #INF_CPUADDRLST_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define INF_PROC_CPUADDRLST     100
/**
 * @brief This procedure can be used to query information about
 *        the CPU.
 *
 * @param[in]   #INF_CPUINFO_C
 * @param[out]  #INF_CPUINFO_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define INF_PROC_CPUINFO        102
/**
 * @brief This procedure can be used to query the complete information
 *        of all available system objects such as MBios, MBoot, MCore, MSys.
 *
 * @param[in]   #INF_SOBJINFOLST_C
 * @param[out]  #INF_SOBJINFOLST_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #INF_SOBJINFO
 */
#define INF_PROC_SOBJINFOLST    104
/**
 * @brief This procedure can be used to query the complete information
 *        of all available I/O drivers such as DI216, DO216, etc.
 *
 * The information is retrieved from the driver files, not from the drivers loaded.
 *
 * @note Due to SMI reply size limitations, clients may need to iterate the list per index:
 *       - #INF_DRVINFOLST_C.FirstIdx
 *       - #INF_DRVINFOLST_C.LastIdx
 * @note If the complete list (maximum of 45 elements) should be queried by one single call,
 *       the parameters `FirstIdx` and `LastIdx` has to be set to 0.\n
 *       The parameter `FirstIdx` must not be set to 0 if the parameter `LastIdx` is greater than 0.
 *
 * @param[in]   #INF_DRVINFOLST_C
 * @param[out]  #INF_DRVINFOLST_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #INF_DRVINFO
 */
#define INF_PROC_DRVINFOLST     106
/**
 * @brief This procedure can be used to query all information about the logbook.
 *
 * The logbook is not transferred, this can be done via FTP-transfer.
 *
 * @param[in]   #INF_LOGINFO_C
 * @param[out]  #INF_LOGINFO_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define INF_PROC_LOGINFO        108
/**
 * @brief This procedure can be used to query a list of all tasks. The
 *        query of the entire list can require multiple queries.
 *
 * @note The performance of the M1 controller can be negatively influenced
 *       by querying the task list. The use of the VxWorks function
 *       taskIdListGet() temporarily locks rescheduling!
 *
 * @note Due to SMI reply size limitations, clients may need to iterate the list per index:
 *       - #INF_TASKINFOLST_C.FirstIdx
 *       - #INF_TASKINFOLST_C.LastIdx
 *
 * @param[in]   #INF_TASKINFOLST_C
 * @param[out]  #INF_TASKINFOLST_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #INF_TASKINFO
 */
#define INF_PROC_TASKINFOLST    110
/**
 * @brief This procedure can be used to query the current boot parameters used
 *        to boot up the M1 controller. These do not have to be identical with
 *        the boot parameters in NVRAM.
 *
 * @param[in]   #INF_BOOTINFO_C
 * @param[out]  #INF_BOOTINFO_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #BOOT_INFO
 */
#define INF_PROC_BOOTINFO       112
/**
 * @brief This procedure can be used to switch the measuring of the CPU
 *        run and cycle time on and off.
 *
 * @param[in]   #INF_TIMEONOFF_C
 * @param[out]  #INF_TIMEONOFF_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define INF_PROC_TIMEONOFF      114
/**
 * @brief This procedure can be used to query the name of the application. This
 *        is the entry in "[SYSTEM], (Application), Name" in the configuration file.
 *        If this entry does not exist in the configuration file, an empty string is
 *        returned as \p Name.
 *
 * @param[in]   #INF_APPNAME_C
 * @param[out]  #INF_APPNAME_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define INF_PROC_APPNAME        116
/**
 * @brief This procedure can be used to query a list of all I/O modules available
 *        on the M1 controller.
 *
 * @note Due to SMI reply size limitations, clients may need to iterate the list per index:
 *       - #INF_CARDINFOLST_C.FirstIdx
 *       - #INF_CARDINFOLST_C.LastIdx
 *
 * @param[in]   #INF_CARDINFOLST_C
 * @param[out]  #INF_CARDINFOLST_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #INF_CARDINFO
 */
#define INF_PROC_CARDINFOLST    120
/**
 * @brief This procedure returns the console buffer.
 *
 * @note The shell must be directed to /tyMemory. See #MOD_PROC_LOCK.
 *
 * @param[in]   #INF_PROC_CONREAD_C
 * @param[out]  #INF_PROC_CONREAD_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define INF_PROC_CONREAD        122
/**
 * @brief This procedure sends a command to the shell.
 *
 * @note The shell must be directed to /tyMemory. See #MOD_PROC_LOCK.
 *
 * @param[in]   #INF_PROC_CONCMND_C
 * @param[out]  #INF_PROC_CONCMND_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define INF_PROC_CONCMND        124
/**
 * @brief This procedure is used by the Device Manager and other tools to
 *        inform the controller "I am alive". If locks are used with
 *        #MOD_PROC_LOCK, this function must be accessed periodically
 *        to keep the locks active.
 *
 * @param[in]   #INF_PROC_ALIVE_C
 * @param[out]  #INF_PROC_ALIVE_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define INF_PROC_ALIVE          126
/**
 * @brief This procedure can be used to query the CPU usage data. It is
 *        used by the Device Manager to display CPU idle or the CPU usage
 *        peak value.
 *
 * @param[in]   #INF_PROC_CPUUSAGE_C
 * @param[out]  #INF_PROC_CPUUSAGE_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define INF_PROC_CPUUSAGE       128
/**
 * @brief This procedure can be used to switch the measuring and monitoring
 *        of the CPU idle and peak usage on and off.
 *
 * @param[in]   #INF_CPUUSAGEONOFF_C
 * @param[out]  #INF_CPUUSAGEONOFF_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define INF_PROC_CPUUSAGEONOFF  130
/**
 * @brief This procedure can be used to query the complete information
 *        of all loaded software modules.
 *
 * @note Due to SMI reply size limitations, clients may need to iterate the list per index:
 *       - #INF_OBJINFOLST_C.FirstIdx
 *       - #INF_OBJINFOLST_C.LastIdx
 *
 * @param[in]   #INF_OBJINFOLST_C
 * @param[out]  #INF_OBJINFOLST_C
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #INF_OBJINFO
 */
#define INF_PROC_OBJINFOLST     132
/**
 * @brief This procedure can be used to query the boot path of MCore,
 *        MSys and configuration.
 *
 * @param[in]   #INF_BOOTINFO2_C
 * @param[out]  #INF_BOOTINFO2_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define INF_PROC_BOOTINFO2      134
/**
 * @brief This procedure can be used to query the complete information
 *        of all java libraries.
 *
 * @note Due to SMI reply size limitations, clients may need to iterate the list per index:
 *       - #INF_LIBINFOLST_C.FirstIdx
 *       - #INF_LIBINFOLST_C.LastIdx
 *
 * @param[in]   #INF_LIBINFOLST_C
 * @param[out]  #INF_LIBINFOLST_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #INF_LIBINFO
 * @deprecated since MSys 4.0
 */
#define INF_PROC_LIBINFOLST     136
/**
 * @brief This procedure can be used to query the complete information
 *        of all available services such as OPCUA, DNP3, etc.
 *
 * @note Due to SMI reply size limitations, clients may need to iterate the list per index:
 *       - #INF_SRVINFOLST_C.FirstIdx
 *       - #INF_SRVINFOLST_C.LastIdx
 *
 * @param[in]   #INF_SRVINFOLST_C
 * @param[out]  #INF_SRVINFOLST_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 *
 * @see #INF_SRVINFO
 */
#define INF_PROC_SRVINFOLST     138
/**
 * @brief This procedure can be used to query all configured directory paths.
 *
 * @param[in]   #INF_SYSCONFIG_C
 * @param[out]  #INF_SYSCONFIG_R
 *
 * @return #INF_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define INF_PROC_SYSCONFIG      140
/** @} */
/**
 * Structure for SMI-Reply
 */
typedef struct
{
    CHAR8   Name[M_CARDNAMELEN_A];   /**< Name of IO module */
    UINT32  CardNb;             /**< Number of IO module */
    UINT32  StationNb;          /**< Number of station */
    UINT32  SlotNb;             /**< Number of slot */
    UINT32  MaxChan;            /**< Maximum channels on IO module */
    UINT32  Mode;               /**< Mode of driver */
    UINT32  Type;               /**< Type of IO module (see \ref MIO_T_) */
    UINT32  State;              /**< Status of IO module */
    UINT16  BusType;            /**< 0=Local, else see \ref MIO_T_ */
    UINT16  NetNb;              /**< Network number */
} INF_CARDINFO;

/**
 * Structure for the SMI-Call #INF_PROC_CARDINFOLST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index to card list */
    UINT32  LastIdx;            /**< Last index to card list */
    UINT32  Filter;             /**< Not used, must be 0 */
} INF_CARDINFOLST_C;

/**
 * Structure for the SMI-Reply #INF_PROC_CARDINFOLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          Last;       /**< <> 0 last frame in list */
    UINT32          NbOfObj;    /**< Number of list elements */
    INF_CARDINFO    Inf[1];     /**< List with IO module information */
} INF_CARDINFOLST_R;

/**
 * Structure for SMI-Reply
 */
typedef struct
{
    SINT32  ProcNum;            /**< Processor number */
    UINT8   IPAddr[M_IPADDRLEN_A];   /**< IP address */
} INF_CPUADDR;

/**
 * Structure for the SMI-Call #INF_PROC_CPUADDRLST
 */
typedef struct
{
    SINT32  Parm;               /**< Not used, must be 0 */
} INF_CPUADDRLST_C;

/**
 * Structure for the SMI-Reply #INF_PROC_CPUADDRLST
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      CurrIndex;      /**< Index of actual CPU (0-2) */
    UINT32      NbOfObj;        /**< Number of list elements */
    INF_CPUADDR Inf[3];         /**< List of IP addresses */
} INF_CPUADDRLST_R;

/**
 * Structure for SMI-Call
 */
typedef struct
{
    UINT32      Type;           /**< CPU type (MP213,...) */
    UINT32      Variant;        /**< CPU variant (/E,/X,...) */
    UINT32      Revision;       /**< CPU revision */
    struct tm   ProdDate;       /**< Production date of CPU */
    UINT8       SerialNbr[12];  /**< Serial number 6.3 */
} INF_CPUIDREG;

/**
 * Structure for the SMI-Call #INF_PROC_CPUINFO
 */
typedef struct
{
    SINT32  Parm;               /**< Not used, must be 0 */
} INF_CPUINFO_C;

/**
 * Structure for the SMI-Reply #INF_PROC_CPUINFO
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          CpuSwitch;  /**< Position of CPU-ID */
    UINT32          ProcNum;    /**< Processor number */
    UINT32          CpuClock;   /**< CPU clock in MHz */
    UINT32          TickRate;   /**< Tick-Rate in ticks per second */
    UINT32          TimeSlice;  /**< Timeslice in ticks */
    UINT32          TotalTicks; /**< Ticks since power-up */
    UINT32          AuxClkRate; /**< Auxiliary clock rate in ticks/sec */
    UINT32          RestartCount;    /**< Number of restarts since reset NVRAM */
    UINT32          DebugMode;  /**< System debug mode */
    struct tm       DateTime;   /**< Date and time of RTC */
    UINT32          SizeDRam;   /**< Size DRAM in bytes */
    UINT32          SizeNVRam;  /**< Size CMOS-Ram in bytes */
    INF_CPUIDREG    CpuId;      /**< Info CPU-ID EEPROM */
    UINT32          PccProgEnable;   /**< No PC-card write protection if 1 */
    UINT32          BootMode;   /**< Boot modus */
    UINT32          StartDRam;  /**< Starting address DRAM */
    UINT32          StartNVRam; /**< Starting address CMOS-Ram */
    UINT32          SystemState;     /**< Status of System (\ref RES_S_) */
    UINT32          CpuSlotNb;  /**< CPU slot number */
    UINT32          FpgaVersion;     /**< FPGA version (MPC, MX, MIO Bus FPGA) */
    UINT32          McoreType;  /**< Type of MCore (MP, MXC, T, *.ALL) */
    UINT32          TickSource; /**< #M_TICK_TIMER, #M_TICK_RTC */
    UINT8           HwVariant;  /**< Hardware variant */
    UINT8           Spare[1];   /**< Not used, 0 for now */
    UINT16          AssemblyCode;    /**< Function code lower part */
    UINT32          FpgaVersion2;    /**< FPGA version (BachmannDevice FPGA) */
    UINT32          Spare1[11]; /**< Not used, 0 for now */
} INF_CPUINFO_R;

/**
 * Info of System Objects
 */
typedef struct
{
    CHAR8       Name[M_FILENAMELEN_A];   /**< Name of system object */
    INF_VERSION Vers;           /**< Version code of system object */
    UINT32      Type;           /**< Type of system object */
    UINT32      Start;          /**< Starting address of system object */
    UINT32      Size;           /**< Size of system object in bytes */
    UINT32      State;          /**< Status of system object */
} INF_SOBJINFO;

/**
 * Structure for the SMI-Call #INF_PROC_SOBJINFOLST
 */
typedef struct
{
    SINT32  Parm;               /**< Not used, must be 0 */
} INF_SOBJINFOLST_C;

/**
 * Structure for the SMI-Reply #INF_PROC_SOBJINFOLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfObj;    /**< Number of list elements */
    INF_SOBJINFO    Inf[1];     /**< List of system objects */
} INF_SOBJINFOLST_R;


#ifdef __OLD_DRVINFO_LST__
typedef struct
{
    SINT32      Parm;                   /**< Not used, must be 0 */
} INF_DRVINFOLST_C;
#endif /* __OLD_DRVINFO_LST__ */
/**
 * Info of an IO driver
 */
typedef struct
{
    CHAR8       Name[M_FILENAMELEN_A];   /**< Name of IO driver */
    INF_VERSION Vers;           /**< Version code of IO driver */
    UINT32      Type;           /**< Type of IO driver */
    UINT32      Size;           /**< Size of IO driver in bytes */
    UINT32      State;          /**< Status of IO driver */
} INF_DRVINFO;

/**
 * Structure for the SMI-Call #INF_PROC_DRVINFOLST
 */
typedef struct
{
    UINT16  FirstIdx;           /**< First index to driver list */
    UINT16  LastIdx;            /**< Last index to driver list */
} INF_DRVINFOLST_C;

/**
 * Structure for the SMI-Reply #INF_PROC_DRVINFOLST
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfObj;        /**< Number of list elements */
    INF_DRVINFO Inf[1];         /**< List of IO driver info */
} INF_DRVINFOLST_R;

/**
 * @deprecated Do not use
 */
typedef struct
{
    UINT8   NewLine[2];         /**< @deprecated Do not use */
    UINT8   Mark1;              /**< @deprecated Do not use */
    UINT8   LogCounter[5];      /**< @deprecated Do not use */
    UINT8   Mark2;              /**< @deprecated Do not use */
    UINT8   LogTicks[8];        /**< @deprecated Do not use */
    UINT8   Mark3;              /**< @deprecated Do not use */
    UINT8   LogTask[8];         /**< @deprecated Do not use */
    UINT8   Mark4;              /**< @deprecated Do not use */
    UINT8   DateTime[19];       /**< @deprecated Do not use */
    UINT8   Mark5;              /**< @deprecated Do not use */
    UINT8   Space;              /**< @deprecated Do not use */
    UINT8   Type;               /**< @deprecated Do not use */
    UINT8   Mark6;              /**< @deprecated Do not use */
    UINT8   Message[78];        /**< @deprecated Do not use */
} INF_LOGENTRY;

/**
 * Structure for the SMI-Call #INF_PROC_LOGINFO
 */
typedef struct
{
    SINT32  Parm;               /**< Not used, must be 0 */
} INF_LOGINFO_C;

/**
 * Structure for the SMI-Reply #INF_PROC_LOGINFO
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  LogCounter;         /**< Number of entries since boot */
    UINT32  LogFileSize;        /**< Maximum number of entries */
    UINT32  SizeOneLog;         /**< Size of one entry */
    CHAR8   Filename[M_PATHLEN_A];   /**< Path/Name of log file */
} INF_LOGINFO_R;


/**
 * @name SMI-Function INF_PROC_TASKINFOLST (Task Info List)
 * @{
 */

/**
 * Structure for CPU-Time
 */
typedef struct
{
    SINT64  RunTotal;           /**< RUNNING total time in clocks */
    UINT32  RunMin;             /**< Minimal run time in clocks */
    UINT32  RunMax;             /**< Maximum run time in clocks */
    UINT32  RunAvg;             /**< Average run time in clocks */
    UINT32  CycleMin;           /**< Minimal cycle time in clocks */
    UINT32  CycleMax;           /**< Maximum cycle time in clocks */
    UINT32  CycleAvg;           /**< Average cycle time in clocks */
} INF_CPUTIME;

/**
 * Structure for SMI-Reply
 */
typedef struct
{
    CHAR8       Name[M_TSKNAMELEN_A];    /**< Name of task */
    CHAR8       Status[12];     /**< Status string (READY, PEND ...) */
    UINT32      Priority;       /**< Priority (0 - 255) */
    UINT32      DelayTicks;     /**< Delay ticks if status=DELAY */
    UINT32      StackSize;      /**< Size of complete stack */
    UINT32      StackMargin;    /**< Size of stack reserve */
    UINT32      ErrorStatus;    /**< Actual error status */
    INF_CPUTIME Time;           /**< CPU-Time for this task */
} INF_TASKINFO;

/**
 * Structure for the SMI-Call #INF_PROC_TASKINFOLST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index to task list */
    UINT32  LastIdx;            /**< Last index to task list */
    UINT32  Spare;              /**< Spare, must be 0 */
} INF_TASKINFOLST_C;

/**
 * Structure for the SMI-Reply #INF_PROC_TASKINFOLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          Last;       /**< <> 0 last frame in list */
    SINT64          TotalTime;  /**< Clocks since power up (100%) */
    UINT32          UnitsTime;  /**< Clocks per us (CPU MHz) */
    UINT32          NbOfObj;    /**< Number of list elements */
    INF_TASKINFO    Inf[1];     /**< List of task information */
} INF_TASKINFOLST_R;

/** @} */
/**
 * Structure for the SMI-Call #INF_PROC_BOOTINFO
 */
typedef struct
{
    SINT32  Parm;               /**< Not used, must be 0 */
} INF_BOOTINFO_C;

/**
 * Structure for the SMI-Reply #INF_PROC_BOOTINFO
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    CHAR8   BootDev[BOOT_LEN1]; /**< Boot device code */
    CHAR8   HostName[BOOT_LEN1];     /**< Name of host */
    CHAR8   TargetName[BOOT_LEN1];   /**< Name of target */
    CHAR8   Ead[BOOT_LEN2];     /**< Ethernet internet address */
    CHAR8   Bad[BOOT_LEN2];     /**< Backplane internet address */
    CHAR8   Had[BOOT_LEN2];     /**< Host internet address */
    CHAR8   Gad[BOOT_LEN2];     /**< Gateway internet address */
    CHAR8   BootFile[BOOT_LEN3];     /**< Name of boot file */
    CHAR8   StartScript[BOOT_LEN3];  /**< Startup script, defined by user */
    CHAR8   User[BOOT_LEN1];    /**< User name */
    CHAR8   Passwd[BOOT_LEN1];  /**< Password */
    CHAR8   Other[BOOT_LEN3];   /**< Available for applications */
    SINT32  ProcNum;            /**< Processor number */
    SINT32  Flags;              /**< Configuration flags */
} INF_BOOTINFO_R;

/**
 * Structure for the SMI-Call #INF_PROC_BOOTINFO2
 */
typedef struct
{
    SINT32  Parm;               /**< Not used, must be 0 */
} INF_BOOTINFO2_C;

/**
 * Structure for the SMI-Reply #INF_PROC_BOOTINFO2
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    CHAR8   BootDev[BOOT_LEN1]; /**< Boot device code */
    CHAR8   HostName[BOOT_LEN1];     /**< Name of host */
    CHAR8   CorePath[M_PATHLEN];     /**< Path of actual used CoreFile */
    CHAR8   MSysPath[M_PATHLEN];     /**< Path of actual used MSys */
    CHAR8   ConfigPath[M_PATHLEN];   /**< Path of actual used CopnfigFile */
    UINT32  CoreFallback;       /**< Core from BootDev(0) or Fallback(1) */
    UINT32  MSysFallback;       /**< MSys from BootDev(0) or Fallback(1) */
    UINT32  ConfigFallback;     /**< Config from BootDev(0) or Fallback(1) */
    UINT32  ConfigBackup;       /**< Config from *.ini(0) or *.bak(1) */
    UINT8   Spare[500];         /**< Not used, 0 for now */
} INF_BOOTINFO2_R;

/**
 * Information handover from Boot to Core - defined in Tornado/mConfig.h
 * legacy boot2core info
 */
typedef struct
{
    UINT32  TickRate;           /**< TickRate */
    UINT32  InvTickRate;        /**< Bitwise not of TickRate value */
    SINT32  Fallback;           /**< Fallback device is used */
    SINT32  InvFallback;        /**< Bitwise not of fallback value */
    UINT32  CheckSum;           /**< CRC32 of structure extension */
    UINT32  Boot2CoreVersion;   /**< Version of this structure (CRC32) */
    CHAR8   CorePath[M_PATHLEN];     /**< Path of actual used CoreFile (CRC32) */
    UINT32  CoreFallback;       /**< Core from BootDev(0)/Fallback(1) (CRC32) */
} BOOT2CORE_INFO_V2;

/**
 * Structure for the SMI-Call #INF_PROC_TIMEONOFF
 */
typedef struct
{
    SINT32  Parm;               /**< 0=OFF,1=ON,2=RESET,3=REQUEST */
} INF_TIMEONOFF_C;

/**
 * Structure for the SMI-Reply #INF_PROC_TIMEONOFF
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Status;             /**< Status after call (0/1) */
} INF_TIMEONOFF_R;

/**
 * Structure for the SMI-Call #INF_PROC_APPNAME
 */
typedef struct
{
    SINT32  Parm;               /**< Not used, must be 0 */
} INF_APPNAME_C;

/**
 * Structure for the SMI-Reply #INF_PROC_APPNAME
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    CHAR8   Name[M_APPNAMELEN_A];    /**< Name of application */
    UINT32  Spare1[20];         /**< Not used, 0 for now */
} INF_APPNAME_R;

/**
 * Structure for the SMI-Call #INF_PROC_CONREAD
 */
typedef struct
{
    UINT32  RequestSize;        /**< Maximum size of buffer to return */
    UINT32  Spare;              /**< Spare, must be 0 */
} INF_PROC_CONREAD_C;

/**
 * Structure for the SMI-Reply #INF_PROC_CONREAD
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  TextSize;           /**< Size of buffer returned */
    UINT32  Spare;              /**< Spare, must be 0 */
    CHAR8   Text[1];            /**< Data buffer */
} INF_PROC_CONREAD_R;

/**
 * Structure for the SMI-Call #INF_PROC_CONCMND
 */
typedef struct
{
    CHAR8   Cmnd[MAX_CMND_SIZE];     /**< Command string, zero terminated */
} INF_PROC_CONCMND_C;

/**
 * Structure for the SMI-Reply #INF_PROC_CONCMND
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} INF_PROC_CONCMND_R;

typedef union
{
    struct
    {
        SINT32  RetCode;            /**< Return code */
    } M0;
    struct
    {
        SINT32  State;              /**< Application state (see \reef RES_S_) */
    } M1;
    struct
    {
        SINT16  State;              /**< Application state (see \reef RES_S_) */
        UINT16  Restarts;           /**< Restart count */
    } M2;
} INF_PROC_ALIVE_MODE;

/**
 * Structure for the SMI-Call #INF_PROC_ALIVE
 */
typedef struct
{
    UINT32  CallerIP;           /**< IP-Address of caller (0=Auto) */
    UINT32  SessionId;          /**< Identification of user session */
    UINT32  Mode;               /**< #INF_NORMALMODE, #INF_APPSTATEMODE and/or #INF_RESTART_APP */
    UINT32  LoginSessId;        /**< Identification of login session @deprecated not needed any more */
} INF_PROC_ALIVE_C;

/**
 * Structure for the SMI-Reply #INF_PROC_ALIVE
 */
typedef struct
{
    INF_PROC_ALIVE_MODE Mode;   /**< Structure containing RetCode, application state and restart count. */
} INF_PROC_ALIVE_R;

/**
 * Structure for the SMI-Call #INF_PROC_CPUUSAGE
 */
typedef struct
{
    /**
     * @brief Mode
     * Supported modes:
     * - #INF_USAGE_CONTIN for continuous measurement
     * - #INF_USAGE_RESET to restart measurement afterwards
     */
    SINT32  Mode;
    UINT32  Spare[2];           /**< Not used, 0 for now */
} INF_PROC_CPUUSAGE_C;

/**
 * Structure for the SMI-Reply #INF_PROC_CPUUSAGE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  UnitsTime;          /**< Clocks per us (CPU MHz) */
    SINT64  CpuUsage100;        /**< Cpu Usage last 100 seconds */
    SINT64  CpuUsage1000;       /**< Cpu Usage last 1000 seconds */
    SINT64  CpuUsageTotal;      /**< RUNNING total time in clocks */
    SINT64  TotalTime;          /**< Clocks since last reset (100%) */
    UINT32  Spare1[4];          /**< Not used, 0 for now */
    UINT32  TskGrpMaxRun[TASKGROUPS];    /**< Maximum time of task group in us */
    UINT32  TskGrpAllowed[TASKGROUPS];   /**< Allowed time of above (100%) */
    UINT32  Spare2[4];          /**< Not used, 0 for now */
} INF_PROC_CPUUSAGE_R;

/**
 * Structure for the SMI-Call #INF_PROC_CPUUSAGEONOFF
 */
typedef struct
{
    /**
     * @brief Parameter
     * - \c 0 ... OFF
     * - \c 1 ... ON
     * - \c 2 ... RESET
     * - \c 3 ... QUERY
     */
    SINT32  Parm;
} INF_CPUUSAGEONOFF_C;

/**
 * Structure for the SMI-Reply #INF_PROC_CPUUSAGEONOFF
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Status;             /**< Status after call (0/1) */
} INF_CPUUSAGEONOFF_R;

/**
 * Info of Object Info
 */
typedef struct
{
    CHAR8   Name[16];           /**< Object name */
    VOID*   ModuleId;           /**< VxWorks module id */
    SINT32  Format;             /**< Object module format */
    SINT32  Group;              /**< Group number, segment info MODULE_SEG_INFO */
    VOID*   TextAddr;           /**< Address of text segment */
    VOID*   DataAddr;           /**< Address of data segment */
    VOID*   BssAddr;            /**< Address of bss segment */
    SINT32  TextSize;           /**< Size of text segment */
    SINT32  DataSize;           /**< Size of data segment */
    SINT32  BssSize;            /**< Size of bss segment */
    UINT32  Spare[3];           /**< Not used for now */
} INF_OBJINFO;

/**
 * Structure for the SMI-Call #INF_PROC_OBJINFOLST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index of object list */
    UINT32  LastIdx;            /**< Last index of object list */
    UINT32  Spare[6];           /**< Not used, must be 0 */
} INF_OBJINFOLST_C;

/**
 * Structure for the SMI-Reply #INF_PROC_OBJINFOLST
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      Last;           /**< Number of available objects */
    UINT32      NbOfObj;        /**< Number of list elements */
    UINT32      Spare[3];       /**< Not used for now */
    INF_OBJINFO Inf[1];         /**< List of system objects */
} INF_OBJINFOLST_R;

/**
 * Info of a zip or jar file
 */
typedef struct
{
    CHAR8       Name[M_FILENAMELONGLEN_A];   /**< Name of jar file */
    CHAR8       Path[M_PATHLEN_A];   /**< Path of file */
    CHAR8       Vendor[64];     /**< Vendor code from manifest with \0 */
    SYS_VERSION Vers;           /**< Version code from manifest */
    UINT32      Size;           /**< Size of file in bytes */
    UINT32      Spare;          /**< Not used, must be 0 */
} INF_LIBINFO;

/**
 * Structure for the SMI-Call #INF_PROC_LIBINFOLST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index of object list */
    UINT32  LastIdx;            /**< Last index of object list */
    UINT32  Filter;             /**< Not used, must be 0 */
    UINT32  Spare;              /**< Not used, must be 0 */
} INF_LIBINFOLST_C;

/**
 * Structure for the SMI-Reply #INF_PROC_LIBINFOLST
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfLibs;       /**< Number of list elements */
    INF_LIBINFO Inf[1];         /**< List of libraries info */
} INF_LIBINFOLST_R;

/**
 * Info of an service
 */
typedef struct
{
    CHAR8       Name[M_FILENAMELEN_A];   /**< Name of service */
    INF_VERSION Vers;           /**< Version code of service */
    UINT32      Type;           /**< Type of service */
    UINT32      Size;           /**< Size of service in bytes */
    UINT32      State;          /**< Status of service */
    UINT32      Spare;          /**< Not used, must be 0 */
} INF_SRVINFO;

/**
 * Structure for the SMI-Call #INF_PROC_SRVINFOLST
 */
typedef struct
{
    UINT32  FirstIdx;           /**< First index to service list */
    UINT32  LastIdx;            /**< Last index to service list */
    UINT32  Spare;              /**< Not used, must be 0 */
} INF_SRVINFOLST_C;

/**
 * Structure for the SMI-Reply #INF_PROC_SRVINFOLST
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfObj;        /**< Number of list elements */
    INF_SRVINFO Inf[1];         /**< List of service info */
} INF_SRVINFOLST_R;

/**
 * Structure for the SMI-Call #INF_PROC_SYSCONFIG
 */
typedef struct
{
    UINT32  Spare[5];           /**< Not used, must be 0 */
} INF_SYSCONFIG_C;

/**
 * Structure for the SMI-Reply #INF_PROC_SYSCONFIG
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    BOOL8   LongFileName;       /**< Long file names */
    BOOL8   AppDev;             /**< Application development allowed */
    BOOL8   Spare1[2];          /**< Not used, 0 for now */
    CHAR8   DirSys[M_PATHLEN_A];     /**< System directory */
    CHAR8   DirDrv[M_PATHLEN_A];     /**< Driver directory */
    CHAR8   DirSrv[M_PATHLEN_A];     /**< Service directory */
    CHAR8   DirApp[M_PATHLEN_A];     /**< Application directory */
    CHAR8   DirClasses[M_PATHLEN_A];     /**< Classes directory - deprecated since MSys 4.00R */
    CHAR8   DirNVol[M_PATHLEN_A];    /**< Non volatile directory */
    CHAR8   DirTmp[M_PATHLEN_A];     /**< Temp directory */
    CHAR8   DirKeys[M_PATHLEN_A];    /**< Keys directory */
    CHAR8   DirEtc[M_PATHLEN_A];     /**< Configuration directory */
    CHAR8   DirKeys2[M_PATHLEN_A];   /**< Keys backup directory */
    UINT32  Spare2[58];         /**< Not used, 0 for now */
} INF_SYSCONFIG_R;

/** @} */
/** @} */

#ifdef __cplusplus
}
#endif

#endif
