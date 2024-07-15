/**
********************************************************************************
* @file
* @author   J.Fritsche
*
* @brief This file contains all global definitions and declarations
*        for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef MSYS_E__H
#define MSYS_E__H

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef _ASMLANGUAGE

#ifndef __linux__
#include <dosFsLib.h>
#endif  /* __linux__ */

#include <signal.h>
#include <stdlib.h>                     /* ldiv_t */
#include <time.h>                       /* timespec */

#include <msys.h>
#include <msys_time_e.h>

#include <semLib.h>
#include <wdLib.h>

#endif                                  /* _ASMLANGUAGE */

/**
 * @addtogroup SYS-GENERAL
 * @{
 */

/**
 * @name Defines for CPU types
 * @{
 */
#define M_80386         0               /**< CPU is 80386 */
#define M_80486         1               /**< CPU is 80486 */
#define M_PENTIUM       2               /**< CPU is Pentium (P5) or K6 */
#define M_GEODE         3               /**< CPU is AMD Geode */
#define M_PENTIUM3      4               /**< CPU is Pentium3 (P6) or Via */
#define M_PENTIUM4      5               /**< CPU is Pentium4 (P7 */
#define M_ATOM          7               /**< CPU is Atom (see VX_X86CPU_ATOM) */
/** @} */

/**
 * @name Defines for CPU family
 * Defines for CPU type in variable sys_CpuFamily
 * @{
 */
#define M_MP2XX         1               /**< CPU is MP213, MP226 or MP240 */
#define M_ME203         2               /**< CPU is ME203, CS200 or ES200 */
#define M_MPC2XX        3               /**< CPU is MPC2xx, MX200, CPC2xx or MR20x */
#define M_WT3XX         4               /**< CPU is WT3xx or CT3xx */
#define M_MH2XX         5               /**< CPU is MH2xx or MC2xx */
/** @} */

/**
 * @name Defines for signals
 * Defines for Signals; Note, Signals 1 to 22 are predefined by VxWorks.
 * @{
 */
#define M_SIGRESTART    29              /**< Restart task, not used yet */
#define M_SIGEXCEPT     SIGUSR1         /**< CPU Exceptions 0..31 (Sig 30) */
#define M_SIGTIMEOUT    SIGUSR2         /**< Task exceeds maximum time (Sig 31) */
/** @} */

/**
 * @name Defines for directories
 * @see sys_GetDir()
 * @{
 */
#define M_DIR_BOOT  0                   /**< Root directory (boot-device). */
#define M_DIR_SYS   1                   /**< Directory (SysDir) System */
#define M_DIR_DRV   2                   /**< Directory (SysDir) Drivers */
#define M_DIR_APP   3                   /**< Directory (SysDir) Applications */
#define M_DIR_SRV   4                   /**< Directory (SysDir) Services */
#define M_DIR_NVOL  5                   /**< Directory (SysDir) NonVolatile */
#define M_DIR_TMP   6                   /**< Directory (SysDir) Temporary */
#define M_DIR_KEY   7                   /**< Directory (SysDir) Keys */
#define M_DIR_ETC   8                   /**< Directory (SysDir) Etc */
#define M_DIR_CLASS 9                   /**< Directory (SysDir) Classes */
#define M_DIR_KEY2  10                  /**< Directory (SysDir) Keys Backup */
/** @} */
/** @} end of SYS-GENERAL */

/**
 * @addtogroup SYS-PAGE-DEF
 * @{
 */

/**
 * @name Defines for Function sys_PageStateSet
 * @see sys_PageStateSet()
 * @{
 */
#define PAGE_NO_OPTION          0x00000000  /**< Nothing do be done. */
#define PAGE_PRESENT            0x00000001  /**< Memory page is present. */
#define PAGE_WRITABLE           0x00000002  /**< Set memory page writable. */
#define PAGE_WRITE_THROUGH      0x00000008  /**< Write through mode. */
#define PAGE_CACHE_DISABLE      0x00000018  /**< Disable caching for memory page (and write through). */
#define PAGE_ACCESSED           0x00000020  /**< Has been accessed; set by the CPU. */
#define PAGE_DIRTY              0x00000040  /**< Dirty flag; set by the CPU. */
/** @} */

/**
 * @name Defines for Paging of MMU (Protection layer)
 * @{
 */
#define PAGE_SIZE               4096        /**< Size of memory pages   */
#define PAGE_MASK               0xFFFFF000  /**< Memory page mask       */
#define PAGE_ALIGN              0x00000FFF  /**< Memory page alignment  */
/** @} */

/**
 * @name Defines for sys_MemPAlloc
 * @see sys_MemPAlloc()
 * @{
 */
#define SYS_SYS_PART            0       /**< System partition */
#define SYS_GLOB_PART           1       /**< Global data partition */
#define SYS_APP_PART            2       /**< Application partition */
#define MAX_APP_PART            63      /**< Maximum application partition */
#define MAX_PARTITION           64      /**< Maximum number of partitions */

#define SYS_SYS_PAGE            SYS_SYS_PART     /**< @deprecated Use SYS_SYS_PART */
#define SYS_GLOB_PAGE           SYS_GLOB_PART    /**< @deprecated Use SYS_GLOB_PART */
#define SYS_APP_PAGE            SYS_APP_PART     /**< @deprecated Use SYS_APP_PART */

/** @} */
/** @} end of SYS-PAGE-DEF */

/**
 * @addtogroup SYS-GENERAL
 * @{
 */

/**
 * @name Defines for sys_GoPanic
 * @see sys_GoPanic()
 * @{
 */
#define SYS_PFAILPANIC  0x0001          /**< Power fail */
#define SYS_IOPANIC     0x0002          /**< IO-Error */
#define SYS_APPPANIC    0x0004          /**< Fatal application error */
#define SYS_SYSPANIC    0x0008          /**< System internal error */
#define SYS_REBOOTPANIC 0x0010          /**< System internal error */
#define SYS_HWWDOGPANIC 0x0020          /**< Hardware watchdog */
#define SYS_ALLPANIC    (SYS_PFAILPANIC | SYS_IOPANIC | SYS_APPPANIC | SYS_SYSPANIC | SYS_REBOOTPANIC | SYS_HWWDOGPANIC)
/** @} */

/**
 * @name M1 IOTCL extensions - IO functions
 * @{
 */
#define FIOADDROPEN     100             /**< Listen read/write mem address */
#define FIOADDRGET      101             /**< Get last read/write mem address */
#define FIOADDRCLOSE    102             /**< Unlisten read/write mem address */
#define FIOMEMSTARTGET  103             /**< Get starting address of ram disk */
#define FIOMEMSIZEGET   104             /**< Get size of ram disk */
#define FIOVOLOPTGET    105             /**< Get volume options */
#define FIOVOLOPTSET    106             /**< Set volume options */
#define FIOCALLCHANGE   107             /**< Set disk change call-out */

#define FIORAWREAD      110             /**< Read from device in raw mode */
#define FIORAWWRITE     111             /**< Write to device in raw mode */
#define FIORAWERASE     112             /**< Erase block in raw mode */

#define FIOREADFUNCGET  115             /**< Get pointer to FuncMemRead */
#define FIOWRITEFUNCGET 116             /**< Get pointer to FuncMemWrite */
#define FIOPROGRESSGET  117             /**< Get formatting progress in bytes */
#define FIOERASECNTGET  118             /**< Get maximum erase count */
#define FIOPROGRFUNCGET 119             /**< Get ptr to FuncFormatProgress */
#define FIOERASEADDRGET 120             /**< Get pointer to MaxEraseCount */
#define FIOGETWRITEABLE 121             /**< Get write protect status */
#define FIOGETNOACCESS  122             /**< Get access state */
#define FIORAWBUFWRITE  123             /**< Write to device in raw buffered mode */
#define FIOMEMSIZEGET64 124             /**< Get size of memory 64Bit */
#define FIOFLUSHHWCACHE 125             /**< Flush drive cache for example CFC/CFast cache */

#define FIOFILEADDRGET  132             /**< Get memory address to file on ram/nvram from dosFs */
#define FIOISCONTIG     133             /**< Check if file is continuous (not fragmented) */
/** @} */

/**
 * @name M1 IOTCL extensions - Serial interface
 * @{
 */
#define SIO_MODEM_MODE          0x1100  /**< Modem at serial port */
#define SIO_STATIST_GET         0x1101  /**< Get error statistics */
#define SIO_STATIST_CLR         0x1102  /**< Clear error statistics */
#define SIO_LINE_SET            0x1103  /**< Set Line Control mode */
#define SIO_LINE_GET            0x1104  /**< Get Line Control mode */
#define SIO_MODEM_SET           0x1105  /**< Set Modem Control lines */
#define SIO_MODEM_GET           0x1106  /**< Get Modem Control/Status lines */
#define SIO_INFO_GET            0x1107  /**< Get UART Info */
#define SIO_USER_SET            0x1108  /**< Set exclusive user */
#define SIO_USER_GET            0x1109  /**< Get exclusive user */
#define SIO_USER_CLR            0x110A  /**< Clear exclusive user */
#define SIO_LINE_HOOK           0x110B  /**< Hook function for line changes */
#define SIO_LINE_HARG           0x110C  /**< Hook function argument */
#define SIO_MAXCYCLE_GET        0x110D  /**< Get maximum sio-Task cycle time */
#define SIO_MAXCYCLE_SET        0x110E  /**< Set maximum sio-Task cycle time */
#define SIO_CHAN_GET            0x110F  /**< Get the SIO_CHAN pointer */

/* more SIO_MODE Types */

#define SIO_MODE_TASK   0x0004          /**< Driver in task mode */
#define SIO_MODE_RS232  0x0000          /**< COM-Port in RS232 mode */
#define SIO_MODE_RS422  0x0010          /**< COM-Port in RS422 mode */
#define SIO_MODE_RS485  0x0020          /**< COM-Port in RS485 mode */
#define SIO_MODE_TTY    0x0040          /**< COM-Port in 20mA mode */
#define SIO_MODE_NONE   0x0000          /**< COM-Port no handshake */
#define SIO_MODE_HARDW  0x0100          /**< COM-Port use hardware handshake */
#define SIO_MODE_SOFTW  0x0200          /**< COM-Port use software handshake */
#define SIO_MODE_FSAFE  0x1000          /**< COM-Port in 485 failsafe mode */

/* SIO_MODEM_MODE Types */
#define SIO_MODEM_OFF   1               /**< No modem or off now */
#define SIO_MODEM_SIM1  2               /**< Simulate modem for connect */
#define SIO_MODEM_SIM2  3               /**< Simulate modem for hangup */

/* SIO_LINE_SET/_GET Types */
#define SIO_5BITS       0x0000          /**< Data length 5 bits */
#define SIO_6BITS       0x0001          /**< Data length 6 bits */
#define SIO_7BITS       0x0002          /**< Data length 7 bits */
#define SIO_8BITS       0x0003          /**< Data length 8 bits */
#define SIO_1STOP       0x0000          /**< 1 stop bit */
#define SIO_2STOP       0x0004          /**< 2 stop bits */
#define SIO_NOPARITY    0x0000          /**< No parity bit */
#define SIO_ODDPARITY   0x0008          /**< Odd parity bit */
#define SIO_EVNPARITY   0x0018          /**< Even parity bit */
#define SIO_1PARITY     0x0028          /**< Parity on, always 1 */
#define SIO_0PARITY     0x0038          /**< Parity on, always 0 */
#define SIO_BREAKON     0x0040          /**< Send break */
#define SIO_8N1         SIO_8BITS|SIO_NOPARITY|SIO_1STOP

/* SIO_LINE_SET/_GET Masks */
#define SIO_MASK_PARITY     0x0038
#define SIO_MASK_LENGTH     0x0003
#define SIO_MASK_STOPBITS   0x0004

/* SIO_MODEM_SET/_GET Types */
#define SIO_DTR         0x0001          /**< Output Data Terminal Ready */
#define SIO_RTS         0x0002          /**< Output Request to Send */

#define SIO_CTS_CHNG    0x0100          /**< Input Clear to Send changed */
#define SIO_DSR_CHNG    0x0200          /**< Input Data Set Ready changed */
#define SIO_RI_CHNG     0x0400          /**< Input Ring Indicator changed */
#define SIO_CD_CHNG     0x0800          /**< Input Carrier Detect changed */
#define SIO_CTS         0x1000          /**< Input Clear to Send status */
#define SIO_DSR         0x2000          /**< Input Data Set Ready status */
#define SIO_RI          0x4000          /**< Input Ring Indicator status */
#define SIO_CD          0x8000          /**< Input Carrier Detect status */
/** @} */

/* IOCTL definitions (NOTE: the same definitions are in MCORE, keep it synchronized */

/**
 * @name M1 IOTCL extensions - DOS
 * @{
 */
/* dosFs volume ioctl (FIOVOLOPTSET) */
#define DOS_PROP_READONLY   0x00000001  /**< Set volume property: read-only */
/* dosFs volume ioctl (FIOVOLOPTGET) */
#define DOS_PROP_PROPERTIES 0x00000000  /**< Get all volume properties (UINT32*) */
#define DOS_PROP_VOLSTART   0x00000001  /**< Get partition start block number (UINT32*) */
#define DOS_PROP_VOLEND     0x00000002  /**< Get partition end block number (UINT32*) */
/** @}*/

/**
 * @name Auxiliary Clock definitions
 * @{
 */
#define SYS_AUX_CONT    1               /**< Continuous interrupt */
#define SYS_AUX_SINGLE  2               /**< One single interrupt */
/** @}*/

/**
 * @name Some global task priorities
 * @{
 */
#define FILE_ACCESS_PRIO 253            /**< Priority for file access */
#define FORMATTING_PRIO  254            /**< Priority for formatting */
/** @}*/

/**
 * @name Watchdog definitions
 * @{
 */
#define WDOG_REB_UNKNOWN        0       /**< Unknown Reboot */
#define WDOG_REB_POWERFAIL      1       /**< Powerfail caused reboot */
#define WDOG_REB_PANIC          2       /**< Panic caused reboot */
#define WDOG_REB_WDOGKNOWN      3       /**< WDog caused known reboot */
#define WDOG_REB_WDOGUNKNOWN    4       /**< Unknown WDog reboot */

#define WDOG_INF_LEN            40      /**< Maximum info string length with \0 */
/** @}*/

/**
 * @name Others
 * @{
 */
#define STDOUT_BUF_SIZE 1024            /**< Size of console output buffer */
#define ERRNO_TEXT_LEN   20             /**< Text size for sys_GetErrnoText */
/** @}*/

/**
 * Macro for M1 pointer validation.
 * This macro returns TRUE if the pointer is valid otherwise FALSE.
 *
 * @warning This macro requires MSys V3.30.04 Beta or better!
 */
#define M_PTR_VALID(ptr)    (( ((UINT32)(ptr) >= (UINT32)0x1000) &&   \
                               ((UINT32)(ptr) <  (UINT32)sys_MemTop) ) ?  \
                               TRUE : FALSE)

/**
 * This macro returns TRUE if the pointer is invalid otherwise FALSE.
 *
 */
#define M_PTR_ZERO(ptr)    ( ((UINT32)(ptr) < (UINT32)0x1000) ? TRUE : FALSE)

#ifndef _ASMLANGUAGE

/**
 * 80x86 CPU Register Set as defined in VxWorks
 *
 * @note
 * Do not change anything in this structure, must be the same as
 * REG_SET in VxWorks header file regsi86.h
 */
typedef struct
{
    UINT32  Edi;                        /**< General register */
    UINT32  Esi;                        /**< General register */
    UINT32  Ebp;                        /**< Frame pointer register */
    UINT32  Esp;                        /**< Stack pointer register */
    UINT32  Ebx;                        /**< General register */
    UINT32  Edx;                        /**< General register */
    UINT32  Ecx;                        /**< General register */
    UINT32  Eax;                        /**< General register */
    UINT32  Eflags;                     /**< Status register */
    UINT32  Eip;                        /**< Program counter */
    UINT32  TlsBase;                    /**< Thread specific data register */
} CPU_REG_SET;

/**
 * Structure for CPU time values for function sys_GetRunTime
 * @see sys_GetRunTime()
 */
typedef struct
{
    SINT64      CpuTimeTotal;           /**< Accumulated Cpu Time in Clocks */
    SINT64      TotalTime;              /**< Clocks since power up (100%) */
    UINT32      UnitsTime;              /**< Clocks per us (CPU MHz) */
    UINT32      Spare[2];               /**< Not used, 0 for now */
} SYS_RUNTIME;

/**
 * Structure for CPU time values for function sys_GetCpuUsage
 * @see sys_GetCpuUsage()
 */
typedef struct
{
    SINT64      CpuUsage100;            /**< Cpu Usage last 100 seconds */
    SINT64      CpuUsage1000;           /**< Cpu Usage last 1000 seconds */
    SINT64      CpuUsageTotal;          /**< Accumulated Cpu Time in Clocks */
    SINT64      TotalTime;              /**< Clocks since last reset (100%) */
    UINT32      Spare[4];               /**< Not used, 0 for now */
} SYS_CPUUSAGE;

/**
 * Structure for CPU time values for function sys_GetCycleTime
 * @see sys_GetCycleTime()
 */
typedef struct
{
    UINT32      RunCount;               /**< Number of CycleEnd() calls */
    UINT32      RunTimeMin;             /**< Minimum Run Time in us */
    UINT32      RunTimeMax;             /**< Maximum Run Time in us */
    UINT32      RunTimeAvg;             /**< Average Run Time in us */
    UINT32      CycleCount;             /**< Number of sys_CycleStart() calls */
    UINT32      CycleTimeMin;           /**< Minimum Cycle Time in us */
    UINT32      CycleTimeMax;           /**< Maximum Cycle Time in us */
    UINT32      CycleTimeAvg;           /**< Average Cycle Time in us */
} SYS_CYCLETIME;

/**
 * Structure for Extended CPU-Info returned in function sys_GetCpuInfo
 * @see sys_GetCpuInfo()
 */
typedef struct
{
    UINT32      CurrTemp;               /**< Current CPU temperature in % */
    UINT32      MinTemp;                /**< Minimum CPU temperature in % */
    UINT32      MaxTemp;                /**< Maximum CPU temperature in % */
    SYS_CPUUSAGE CpuUsage;              /**< Cpu Usage values */
    UINT32      UnitsTime;              /**< Clocks per us (CPU MHz) */
    UINT32      LastIdleTime;           /**< Time in us Idle last run */
    UINT32      MaxPccErases;           /**< Total count of erase/write cycles on the most used (worn) single PC-Card cell until now */
    UINT32      MaxFlashErases;         /**< Total count of erase/write cycles on the most used (worn) single flash cell until now */
    UINT32      StrayInterrupts;        /**< Number of stray interrupts */
    UINT32      SyncHigh;               /**< Sync High time in us */
    UINT32      SyncLow;                /**< Sync Low time in us */
    UINT32 VOLATILE *pSyncCount;        /**< Sync interrupts since boot */
    UINT32 VOLATILE *pAuxClkCount;      /**< Aux clocks since boot */
    BOOL8       PccPresent;             /**< PC-Card is present */
    BOOL8       PccPluggedIn;           /**< PC-Card is plugged in */
    BOOL8       PccWritable;            /**< No PC-Card write protection */
    BOOL8       PccCheckError;          /**< Error in boot check on PC-Card */
    BOOL8       FlashPresent;           /**< File Flash is present */
    BOOL8       FlashWritable;          /**< No Flash write protection */
    BOOL8       FlashCheckError;        /**< Error in boot check on Flash */
    BOOL8       NVRamSupplError;        /**< Error in NV-Ram supply */
    BOOL8       NVRamCheckError;        /**< Error in boot check on NV-Ram */
    BOOL8       StackCheckError;        /**< Stack overflow in one task */
    BOOL8       DRamCheckError;         /**< Checksum error in DRam */
    BOOL8       RTCError;               /**< Error in RTC value */
    BOOL8       SoftBootError;          /**< Soft boot error, M1 by run */
    BOOL8       HardBootError;          /**< Hard boot error, booting aborted */
    BOOL8       LongNameEnable;         /**< Long filenames ON/OFF */
    UINT8       TickSource;             /**< #M_TICK_TIMER, #M_TICK_RTC */
    UINT32      SntpTimestamp;          /**< SNTP time in seconds since 1970 */
    /* Below here added in MSys V2.00.31 Beta */
    UINT32      RebootReason;           /**< Reboot reason (see define WDOG_REB_UNKNOWN and others) */
    CHAR        RebootInf[WDOG_INF_LEN];/**< Reboot info text */
    /* Below here added in MSys V3.20.07 Beta */
    struct timespec SntpTimeRecv;       /**< Last received SNTP time */
    struct timespec SntpTimeCorr;       /**< Last received SNTP time maybe corrected by
                                         * "SntpMaxCorrection" and converted to local time. */
    UINT32 SntpMaxCorrection;           /**< Maximum allowed change per SNTP update in seconds */
} SYS_EXTCPUINFO;

/**
 * Structure for Serial IO-Info
 */
typedef struct
{
    BOOL8       TxBusy;                 /**< Tx-FIFO or shift register not empty */
    BOOL8       RxBusy;                 /**< Rx-FIFO or shift register not empty */
    BOOL8       EnhancedUart;           /**< Enhanced Uart */
    UINT8       ModemMode;              /**< Modem simulation mode */
    UINT32      FifoSize;               /**< Size of FIFOs in UART */
    UINT32      CycleTime;              /**< Ticks per cycle in TaskMode */
    UINT16      Variant;                /**< Variant of IO module */
    UINT16      DeviceID;               /**< Device Identification of UART */
    UINT32      Spare2;                 /**< Not used, 0 for now */
} SYS_SIOINFO;

/**
 * Structure for Serial IO-Statistic
 */
typedef struct
{
    UINT32      RxCount;                /**< Number of characters received */
    UINT32      TxCount;                /**< Number of characters sent */
    UINT32      ORunErrors;             /**< Overrun error count */
    UINT32      PariErrors;             /**< Parity error count */
    UINT32      FrameErrors;            /**< Framing error count */
    UINT32      BreakInterr;            /**< Break interrupts count */
    UINT32      FifoErrors;             /**< FIFO error count */
    UINT32      RxBuffOflow;            /**< Number overflows receive buffer */
} SYS_SIOSTAT;

/**
 * Structure for Ethernet Statistic
 */
typedef struct
{
    UINT32      InOverloadCount;        /**< Counter input data overloads */
    UINT32      OutOverloadCount;       /**< Counter output data overloads */
    UINT32      BcOverloadCount;        /**< Counter broadcast overloads */
    UINT32      InBytes100msPeak;       /**< In bytes peak load in 100 ms */
    UINT32      BcBytes100msPeak;       /**< Broadcast peak load in 100 ms */
    UINT32      OutBytes100msPeak;      /**< Out bytes peak load in 100 ms */

    UINT32      StartTicks10ms[10];     /**< Ticks at start counting */
    UINT32      InBytes10ms[10];        /**< In bytes last 10 ms */
    UINT32      BcBytes10ms[10];        /**< Broadcast bytes last 10 ms */
    UINT32      OutBytes10ms[10];       /**< Out bytes last 10 ms */

    UINT32      CurrIndex100s;          /**< Index to xx100s[] 0 .. 9 */
    UINT32      InPacks100s[10];        /**< In packets last 100 seconds */
    UINT32      InBytes100s[10];        /**< In bytes last 100 seconds */
    UINT32      BcPacks100s[10];        /**< Broadcast packets last 100 seconds */
    UINT32      BcBytes100s[10];        /**< Broadcast bytes last 100 seconds */
    UINT32      OutPacks100s[10];       /**< Out packets last 100 seconds */
    UINT32      OutBytes100s[10];       /**< Out bytes last 100 seconds */

    UINT32      InPacksTotal;           /**< In packets since reboot */
    SINT64      InBytesTotal;           /**< In bytes since reboot */
    UINT32      BcPacksTotal;           /**< Broadcasts since reboot */
    SINT64      BcBytesTotal;           /**< Broadcast bytes since reboot */
    UINT32      OutPacksTotal;          /**< Out packets since reboot */
    SINT64      OutBytesTotal;          /**< Out bytes since reboot */

    CHAR        DevName[4];             /**< Ethernet device name */
    UINT32      Unit;                   /**< Ethernet device unit number */
    UINT32      MaxBytesPerSec;         /**< Bytes per second 10M-1000M */

    UINT32      BcPacks10ms[10];        /**< Broadcast packs last 10 ms */
    UINT32      BcPacks100msPeak;       /**< Broadcast peak packets in 100 ms */
    UINT32      Spare1;                 /**< For future extensions */
    UINT32      Spare2;                 /**< For future extensions */
} SYS_ETHSTAT;

/**
 * Structure for CPU-Info returned in function sys_GetCpuInfo()
 */
typedef struct
{
    UINT32      CpuSwitch;              /**< Position of CPU-ID (Hex Switch) */
    UINT32      ProcNum;                /**< Processor number */
    UINT32      CpuClock;               /**< CPU Clock in MHz */
    UINT32      TickRate;               /**< Tick rate in ticks per second */
    UINT32      TimeSlice;              /**< Time slice in ticks */
    UINT32      TotalTicks;             /**< Ticks since power up */
    UINT32      AuxClkRate;             /**< Auxiliary clock rate in ticks/second */
    UINT32      RestartCount;           /**< Number restarts since reset NVRAM */
    UINT32      DebugMode;              /**< System Debug Mode */
    UINT32      SizeDRam;               /**< Size of system DRam */
    UINT32      SizeNVRam;              /**< Size of CMOS-Ram */
    UINT32      ProcType;               /**< Processor type, 0=386, 2=Pentium */
    SYS_EXTCPUINFO *pExtCpuInfo;        /**< Pointer to extended CPU info */
    SYS_ETHSTAT *pEthStatist;           /**< Pointer to Ethernet statistic */
    UINT32      Spare;                  /**< Not used, 0 for now */
} SYS_CPUINFO;

typedef UINT32 IDLE_ID; /**< ID of an idle task added function */
/** @} end of SYS-GENERAL */

/**
 * @addtogroup SYS-TASK-DEF
 * @{
 */

typedef struct SYS_TASK *SYS_TASK_HANDLE; /**< Task handle */

/**
 *  Specifies the time base of a task.
 */
typedef enum
{
    TRG_TICK,        /**< Task is triggered by tick.
                          All task started with time base tick are
                          phase-synchronous an can be delayed by an offset. */
    TRG_SYNC,        /**< Task is triggered by sync interrupt.
                          All task started with time base sync are
                          phase-synchronous an can be delayed by an offset. */
    TRG_AUX,         /**< Task is triggered by aux interrupt.
                          All task started with time base sync are
                          phase-synchronous but cannot be delayed by an offset. */
    TRG_EVENT,       /**< Task is triggered by event interrupt */
    TRG_ERROR,       /**< Task is triggered by error interrupt */
    TRG_FREE         /**< Task is free-wheeling */
} TASK_TRIGGER;

/**
 *  Specifies the behavior of cycle time regulation for time base #TRG_TICK.
 */
typedef enum
{
    REG_DEFAULT,         /**< Cycle time is regulated for small overruns.
                              Behavior of regulation:
                              - Overrun > 2 x cycle time -> missed cycles are skipped.
                              - Overrun < 2 x cycle time -> Try to catch the missed cycles
                                for the next 10 cycles. If the right phase is not reached
                                after this time, and there is still an overrun > cycle time,
                                the cycle is skipped.
                              - The 1st and 2nd cycle may have cycle overruns (initial cycles).
                                */
    REG_PTP,             /**< Cycle time is synchronized to PTP */
    REG_DETERMINISTIC    /**< Cycle time is deterministic (overruns <b>not accepted</b>).
                              If an overrun occurs, cycle will be skipped ->
                              wait for the next phase.
                           */
} TASK_TICK_REG;

/**
 * Struct of cycle overrun information
 */
typedef struct TASK_OVERRUN
{
    UINT32  NbOfContCycOverruns;   /**< Number of continuous cycles with an overrun*/
    UINT32  NbOfCycleOverruns;     /**< Total number of cycles with an overrun */
    UINT32  NbOfSkippedCycles;     /**< Total number of cycles skipped due to overrun */
} TASK_OVERRUN;

/**
 * @brief Structure for task information.
 */
typedef struct SYS_TASK_INFO
{
    SINT32          TaskId;             /**< ID returned by task spawn */
    TASK_TRIGGER    TaskTrigger;        /**< Tick, Sync, Aux, Event, Error or Free-wheeling
                                             @see #TASK_TRIGGER*/
    UINT32  WDogTime_us;                /**< WDogTime in us */
    union
    {
        struct
        {
            UINT32  ActCycTime_us;         /**< Cycle time in us (may differ from configured cycle time to match tick rate) */
            UINT32  ActOffset_us;          /**< Offset in us (may differ from configured cycle time to match tick rate) */
            UINT32  TicksPerCycle;         /**< Cycle time in ticks */
            UINT32  TicksOffset;           /**< Offset in Ticks */
            TASK_TICK_REG Regulation;      /**< Specifies if the task is regulated or if it is deterministic */
            TASK_OVERRUN  Overrun;         /**< Information of cycle overruns (only if #Regulation has the value #REG_DEFAULT) */
        } tick;
        struct
        {
            UINT32  ActCycTime_us;      /**< Cycle time in us (may differ from configured cycle time to match sync rate) */
            UINT32  ActOffset_us;       /**< Offset in us (may differ from configured cycle time to match sync rate) */
            UINT32  SyncPerCycle;       /**< Cycle time in sync periods */
            UINT32  SyncEdge;           /**< Sync edge selection */
            UINT32  OverrunCount;       /**< Number of cycle overruns */
        } sync;
        struct
        {
            UINT32  ActCycTime_us;     /**< Cycle time in us (may differ from configured cycle time to match aux rate) */
            UINT32  AuxPerCycle;       /**< Cycle time in aux */
            UINT32  Type;              /**< Mode for the process. Use #SYS_AUX_SINGLE for One-shot processing or #SYS_AUX_CONT for continuous. */
            UINT32  OverrunCount;      /**< Number of cycle overruns */
        } aux;
    };
} SYS_TASK_INFO;

/**
 * @brief Structure for task settings.
 */
typedef struct SYS_TASK_ATTRIBUTES
{
    CHAR    AppName[M_MODNAMELEN_A];    /**< Instance name of the software module that creates the task */
    CHAR    TaskName[M_TSKNAMELEN_A];   /**< Unique visible name for task */
    BOOL8   UseFPU;                     /**< The created task uses the FPU (Floating Point Unit) if #TRUE */
    UINT32  Priority;                   /**< Priority for this task */
    UINT32  WDogTime_us;                /**< WDogTime in us (0 if no watchdog desired) */
    UINT32  StackSize;                  /**< Stack size of this task in bytes */
    TASK_TRIGGER TaskTrigger;           /**< Tick, Sync, Aux, Event, Error or Free-wheeling */
    UINT32  Spare[4];                   /**< Not used, 0 for now */
    union
    {
        struct
        {
            UINT32  DesCycTime_us;       /**< Desired cycle time for this task in us */
            UINT32  DesOffset_us;        /**< Desired cycle time offset for this task in us */
            TASK_TICK_REG Regulation;    /**< Specifies if the task is regulated or if it is deterministic */
            UINT32  Spare[1];            /**< Not used, 0 for now */
        } tick;
        struct
        {
            UINT32  DesCycTime_us;       /**< Desired cycle time for this task in us */
            UINT32  DesOffset_us;        /**< Desired cycle time offset for this task in us */
            UINT32  SyncEdge;            /**< Sync edge selection */
            UINT32  Spare[1];            /**< Not used, 0 for now */
        } sync;
        struct
        {
            UINT32  DesCycTime_us;       /**< Desired cycle time for this task in us */
            UINT32  Type;                /**< Mode for the process. Use #SYS_AUX_SINGLE for One-shot processing or #SYS_AUX_CONT for continuous. */
            UINT32  Spare[1];            /**< Not used, 0 for now */
        } aux;
    };

    /** Function pointer to user init function of this task, called once before main function. */
    void (*pUserInitFunc)(SYS_TASK_HANDLE TaskHandle, void *pUserData);

    /** Function pointer to user main function of this task. */
    void (*pUserMainFunc)(SYS_TASK_HANDLE TaskHandle, void *pUserData);

    /** Function pointer to user deinit function of this task, called once before task is deleted. */
    void (*pUserDeinitFunc)(SYS_TASK_HANDLE TaskHandle, void *pUserData);

    void *pUserData; /**<  free for use */
} SYS_TASK_ATTRIBUTES;
/** @} end group SYS-TASK-DEF */

/**
 * @addtogroup SYS-GENERAL
 * @{
 */

#ifdef __GNUC__
#ifndef __LINUX

/* Defined in MCore */

/**
* @ingroup SYS-MCORE
* @brief Via this function the current CPU time in microseconds since power-up
*        can be determined. The value is derived from the CPU-clock-counter of
*        the CPU. After approximately 70 minutes, the counter starts again
*        from the beginning. However, for relative time-measurements this is no
*        problem, as long as all computation is done in #UINT32.
*
* @return     CPU-Time in microseconds
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c m_GetProcTime
*/
UINT32 m_GetProcTime(VOID);

/**
* @ingroup SYS-MCORE
* @brief Via this function, the current CPU-time as clocks since power-up
*       can be queried. The value is the number of CPU-clocks of the
*       CPU-clock-counter as 64-Bit value.
*
* @warning It is not recommended to use this function on the processor
*          modules ME203 and CS200. The value of CPU-clocks is calculated from
*          m_GetProcTime() and is therefore very time-intensive.
*
* @param[out] pCpuClocks   CPU-Time in clocks
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c m_GetProcTime2
*/
VOID m_GetProcTime2(UINT64 *pCpuClocks);

/**
* @ingroup SYS-MCORE
* @brief Disable one or more interrupts in the controller.
*
* @param[in]  Mask Mask of interrupts
*/
VOID m_IntDisable(UINT32 Mask);

/**
* @ingroup SYS-MCORE
* @brief Enable one or more interrupts in the controller.
*
* @param[in]  Mask Mask of interrupts
*/
VOID m_IntEnable(UINT32 Mask);

/**
* @ingroup SYS-API
* @brief This function copies a file from the source device to the destination
*       device. If the `TaskMode` parameter is set to 1, copying will be
*       performed as a low-priority task, since this process can take several
*       minutes.
*
* @param[in]  SourceFd        File descriptor for the source file
* @param[in]  DestFd          File descriptor for the destination file
* @param[in]  TaskMode        TRUE if a task is spawned in the background
*
* @retval     0   OK
* @retval     -1  No memory
* @retval     -2  Error upon reading the source file
* @retval     -3  Generic error
* @retval     -4  The destination device is full
*/
SINT32 sys_Copy(SINT32 SourceFd, SINT32 DestFd, BOOL8 TaskMode);

/**
* @ingroup SYS-API
* @brief This function copies a file from the source device to the destination
*       device. If the `TaskMode` parameter is set to 1, copying will be
*       performed as a low-priority task, since this process can take several
*       minutes.
*
*       The percentage progress (0-100%) is stored in the output variable
*       pProgress.
*
* @param[in]  SourceFd        File descriptor for the source file
* @param[in]  DestFd          File descriptor for the destination file
* @param[in]  TaskMode        TRUE if a task is spawned in the background
* @param[out] pProgress       Pointer to a location where the progress shall
*                             be written (0-100%)
*
* @retval     0   OK
* @retval     -1  No memory
* @retval     -2  Error upon reading the source file
* @retval     -3  Generic error
* @retval     -4  The destination device is full
*/
SINT32 sys_Copy2(SINT32 SourceFd, SINT32 DestFd, BOOL8 TaskMode, SINT32 *pProgress);

/**
* @ingroup SYS-API
* @brief This function formats a device: PC-Card, RamDisk, NVRam or an internal
*        flash (not the boot flash). If the `TaskMode` parameter is set to 1,
*        formatting will be performed as a low-priority task, since this process
*        can take several minutes.
*
* @param[in]  DeviceName      The name of the device
* @param[in]  Size            Total size in bytes. If 0, determine the size
*                             automatically
* @param[in]  TaskMode        TRUE if a task is spawned in the background
*
* @retval     >=0 = OK
* @retval     <0  = Error
*
* <b>Example</b><br>
* `-> sys_Format("/cfc0", 0, 1)`<br>
* `value = 0 = 0x0`
*/
SINT32 sys_Format(CHAR *DeviceName, UINT32 Size, BOOL8 TaskMode);

/**
* @ingroup SYS-API
* @brief This function formats a device: PC-Card, RamDisk, NVRam or an internal
*        flash (not the boot flash). Since this process can take several minutes,
*        this is done in a newly spawned low priority task.
*
* @param[in]  DeviceName      The name of the device
* @param[in]  Size            Total size in bytes. If 0, determine the size
*                             automatically
* @param[in]  TaskMode        TRUE if a task is spawned in the background
*
* @retval     >=0 = OK
* @retval     <0  = Error
*/
SINT64 sys_Format64(CHAR *DeviceName, UINT64 Size, BOOL8 TaskMode);

/**
* @ingroup SYS-API
* @brief This functon computes a lock mask that can be used with the function
*        sys_HwIntLockSet().
*
* @param[in]  Level           Defines the interrupts that are switched on
*
* The following interrupts are turned on or off depending on the level:
* Level | Tick | RTC | Sync | Event | Error | COM2 | COM1 | Ethernet
* ------|------|-----|------|-------|-------|------|------|---------
*  0    | ON   | ON  | ON   | ON    | ON    | ON   | ON   | ON
*  1    | ON   | ON  | ON   | ON    | ON    | ON   | ON   | OFF
*  2    | ON   | ON  | ON   | ON    | ON    | ON   | OFF  | OFF
*  3    | ON   | ON  | ON   | ON    | ON    | OFF  | OFF  | OFF
*  4    | ON   | ON  | ON   | ON    | OFF   | OFF  | OFF  | OFF
*  5    | ON   | ON  | ON   | OFF   | OFF   | OFF  | OFF  | OFF
*  6    | ON   | ON  | OFF  | ON    | OFF   | OFF  | OFF  | OFF
*  7    | ON   | ON  | OFF  | OFF   | OFF   | OFF  | OFF  | OFF
*  8    | ON   | OFF | OFF  | OFF   | OFF   | OFF  | OFF  | OFF
*  9    | OFF  | OFF | ON   | OFF   | OFF   | OFF  | OFF  | OFF
*  10   | OFF  | OFF | OFF  | ON    | OFF   | OFF  | OFF  | OFF
*
* @return     Interrupt lock-mask that must be passed when calling
*             sys_HwIntLockSet()
* @see sys_HwIntLockSet()
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_HwIntLockMaskGet
*/
UINT32 sys_HwIntLockMaskGet(UINT32 Level);

/**
* @ingroup SYS-API
* @brief This function determines the absolute address of a file in RAM (DRAM or
*        NVRAM).
*
* This address can be used for direct write and read access to
* the file. The file must have been created earlier with the complete
* size and must be contiguous. Simultaneous write access using absolute
* address and I/O-file is possible but does not make sense.
*
* @note This function is designed for system use. The caller must ensure, that the
*       protection layer is set to the system memory partition. This can be done
*       with the function pair sys_AppToSys() and sys_SysToApp() or by the
*       function sys_PageStateSet().
*
* @warning Writing beyond the file size will destroy other data in RAM.
*
* @param[in]  FileName Filename of the file whose address in RAM is to be
*             determined
*
* @retval     0       Address could not be found
* @retval     !0      Starting address of file in memory
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_GetMemAddress
*/
VOID *sys_GetMemAddress(CHAR *FileName);

/**
* @ingroup SYS-API
* @brief This function can be used to send an inseparable message to the console.
*
* The difference to the ANSI printf is that text lines of different
* tasks are not mixed. This function can be used in combination with the
* logger functions such as log_Info.
* sys_Printf() always outputs entire messages without interruption. In
* this way, messages are prevented from being mixed on the console if
* multiple tasks are used. A semaphore is used for this functionality,
* which can lead to unexpected waiting times of the caller task during
* multiple usage.
*
* @note sys_Printf() can only handle output strings that end up being less than
*       128 bytes in total size as the final string.
* @note sys_Printf() blocked if the buffer is full. If not desired, sys_Printf2()
*       can be used as an alternative. @see sys_Printf2()
* @note In the event of a buffer or message queue overload, the output may be
*       delayed on the console or information may be discarded.
*
* @param[in]  Format   Formating string
* @param[in]  ...      Arguments
*/
VOID sys_Printf(CHAR *Format, ...);

/**
* @ingroup SYS-API
* @brief Like sys_Printf(), this function can be used to send an inseparable
*        message to the console.
*
* The difference to sys_Printf() consists of the fact that if the buffer is full,
* messages will be rejected without waiting. sys_Printf2() always outputs entire
* messages without interruption. Inthis way, messages are prevented from being
* mixed on the console if multiple tasks are used. A semaphore is used for this
* functionality, which can lead to unexpected waiting times of the caller task
* during multiple usage.
*
* @note In the event of a buffer or message queue overload, the output may be
*      delayed on the console or information may be discarded.
*
* @param[in]  Format          Pointer auf Formatangabe
* @param[in]  ...     Argumente
*/
VOID sys_Printf2(CHAR *Format, ...);

/**
* @ingroup SYS-API
* @brief The function sys_CycleStart() informs the system that a cycle has
*       been started.
* For application programs that use this access, a statistic
* of the cycle time with minimum, maximum and average values can be
* determined by the system.
*
* @note The function has no effect, if time measurement has been deactivated by
*       either the setting of [SYSTEM], (SysMode), CpuTimeInfo = OFF or by the
*       function sys_CpuTimeInfoOff(). The function is therefore normally not
*       an additional time load for the user. The function sys_CycleEnd() is
*       the counterpart.
*
* @see sys_CycleEnd()
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_Cycle
*/
VOID sys_CycleStart(VOID);

/**
* @ingroup SYS-API
* @brief The function sys_CycleStart2() informs the system that a task has
*       become active.
* In contrast to function sys_CycleStart() this function cannot be used
* for cyclical, but event-driven tasks.
*
* @note For tasks with cycle times > 30 s, this function should be used as
*       well. There, a cycle time calculation does not make any sense.
*
* For application programs that use this access, a statistic of the runtimes
* with minimum, maximum and average values can be determined by the system.
* The cycle times are not calculated when using this function. The function
* sys_CycleEnd() is the counterpart.
*
* @see sys_CycleEnd()
*
* @note The function has no effect, if time measurement has been deactivated
* by either the setting of [SYSTEM], (SysMode), CpuTimeInfo = OFF or by the
* function sys_CpuTimeInfoOff(). The function is therefore normally not an
* additional time load for the user.
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_Cycle2
*/
VOID sys_CycleStart2(VOID);

/**
* @ingroup SYS-API
* @brief This functions reports to the system that a cycle has been completed.
*
* A statistic of the cycletime with minimum, maximum and average values can be
* determined by the system for application programs using this function together
* with sys_CycleStart().
* This function only takes effect if the function sys_CycleStart() had been used
* prior to calling it. No error occurs if sys_CycleEnd needs to be called
* before sys_CycleStart.
* The counterpart is sys_CycleStart().
*
* @note The function has no effect, if time measurement has been deactivated
* by either the setting of [SYSTEM], (SysMode), CpuTimeInfo = OFF or by the
* function sys_CpuTimeInfoOff(). The function is therefore normally not an
* additional time load for the user.
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_Cycle
*/
VOID sys_CycleEnd(VOID);

/**
* @ingroup SYS-API
* @brief This function can be used to request the total CPU-time of a task.
*
* The CPU-utilization of one particular task can be determined using this value.
* The values are computed since the activation of the task or since the
* latest reset of these values via sys_ResetCycleTime().
*
* @note The function returns 0 in CpuTimeTotal, if the cycle time measurement
* is deactivated by setting [SYSTEM], (SysMode), CpuTimeInfo = OFF or via the
* sys_CpuTimeInfoOff() function.
*
* @param[in]  TaskId     Task ID of the task whose data is to be queried.
*                        Zero may be passed as Task ID to specify the current task.
* @param[out] pRunTime   Pointer to a placeholder for the result.
*
* @retval     0  OK
* @retval     -1 Error, Invalid Task ID
* @retval     -2 The task has no cycle time administration
*               (not started using sys_TaskSpawn)
*/
SINT32 sys_GetRunTime(UINT32 TaskId, SYS_RUNTIME *pRunTime);

/**
* @ingroup SYS-API
* @brief This function can be used to determine the cycle data and the CPU
*        times of a task.
* The values are computed since the activation of the task or since the
* latest reset of the values via sys_ResetCycleTime().
*
* @note  If cycle timing has been disabled, either by setting [SYSTEM],
*       (SysMode), CpuTimeInfo = OFF or by the function sys_CpuTimeInfoOff(),
*       the returned values are not valid (minimum values = 0x7FFF'FFFF all
*       other values = 0).
*
* @param[in]  TaskId      Task ID of the task whose data is to be queried.
*                         Zero may be passed as Task ID to specify the current task.
* @param[out] pCycleTime  Pointer to a placeholder for the result.
*
* @retval     0  OK
* @retval     -1 Error, invalid Task ID
* @retval     -2 Task has no cycletime administration
*               (not started using sys_TaskSpawn)
*/
SINT32 sys_GetCycleTime(UINT32 TaskId, SYS_CYCLETIME *pCycleTime);

/**
* @ingroup SYS-API
* @brief This function resets the cycle data and the CPU-times of a task.
*
* All minimum values are set to 0x7FFF'FFFF, all other values to 0.
* Zero may be transferred as Taskld to indicate the calling task.
* The calling of this function is the starting point for new cycle data.
*
* @param[in]  TaskId    Task ID of the task whose data is to be queried.
*                       Zero may be passed as Task ID to specify the current task.
*
* @retval     0  OK
* @retval     -1 Error, invalid Task ID
* @retval     -2 Task has no cycletime administration
*               (not started using sys_TaskSpawn)
*/
SINT32 sys_ResetCycleTime(UINT32 TaskId);

/**
* @ingroup SYS-API
* @brief This functions returns the current CPU-ID.
*
* @return   CPU-ID
*/
SINT32 sys_GetCpuId(VOID);

/**
* @ingroup SYS-API
* @brief This function can be used to request settings, statistics and
*        states of the CPU.
* The information below can be displayed using the sys_ShowCpuUsage or
* sys_ShowNetUsage() commands. Some of the values below depend on the system
* configuration in (SysMode) or (Monitoring). If, for example, network
* monitoring is disabled (NoWatchNetUsage = ON), the pointer pEthStatist will be zero.
*
* @param[out]  pCpuInfo   Pointer to a placeholder for the requested info
*
* @retval     >= 0  OK
* @retval     < 0   Error
*/
SINT32 sys_GetCpuInfo(SYS_CPUINFO *pCpuInfo);

/**
* @ingroup SYS-API
* @brief This function changes the LED state on the M1.
*
* @param[in]  Value   Bit mask for the LED states (1=green, 2=yellow, 4=red)
*/
VOID sys_SetLED(UINT8 Value);

/**
* @ingroup SYS-API
* @brief This function reads the state of the LEDs.
*
* @return   Bit mask for the LED states (1=green, 2=yellow, 4=red)
*/
UINT8 sys_GetLED(VOID);

/**
* @ingroup SYS-API
* @brief This function sets the LEDs in a blinking state.
*
* @param[in]  Value  Bit mask for the LED states (1=green, 2=yellow, 4=red)
*/
VOID sys_SetLEDFlash(UINT8 Value);

/**
* @ingroup SYS-API
* @brief This function gets the blinking state of the LEDs.
*
* @return   Bit mask for the LED states (1=green, 2=yellow, 4=red)
*/
UINT8 sys_GetLEDFlash(VOID);

/**
* @ingroup SYS-API
* @brief The function sys_CheckFpuOption() checks if the calling task is
*        allowed to use the coprocessor or not.
*
* If during the function call of sys_TaskSpawn() the option VX_FP_TASK is not
* specified, the contents of the coprocessor will not be saved and restored
* during task switching. Therefore, such a task may never use the co processor.
* This function can be used to check if this option has been set or not.
*
* @note The functions sys_CheckFpuOption() and sys_CheckFPUOption() are the same.
*
* @retval     0   Option VX_FP_TASK not set, co processor may not be used
* @retval     1   Option VX_FP_TASK set, co processor can be used
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_CheckFpuOption
*/
SINT32 sys_CheckFpuOption(VOID);

/**
* @ingroup SYS-API
* @copydoc  sys_CheckFpuOption()
*/
SINT32 sys_CheckFPUOption(VOID);

/**
* @ingroup SYS-API
* @brief This function can be used to convert a version string.
*
* A string of the type "Vaa.bb.cc ddd" gets converted to an integer array,
* whereas "aa" is the major version, "bb" the minor version, "cc" the optional
* alpha or beta version and "dd" the Alpha/Beta/Release string.
*
* If parsing of the string VersStrg fails all elements of the structure pVers
* will be zero.
*
* @param[out] pVers    Version structure
* @param[in]  VersStrg Version string (e.g. V1.02.05 Alpha, V2.12.08 Beta,
*                      V5.01 Release, V1.02)
*/
VOID sys_GetVersion(SYS_VERSION *pVers, UINT8 *VersStrg);

/**
* @ingroup SYS-API
* @brief This function reads the VxWorks version and converts it to a MSys version.
*
* The VxWorks version is always a release version and may have 2 or 3 parts.
* If only 2 parts are used, the last number in the MSys version will be 0,
* not 99.
*
* @param[out] pVers    Version structure
*
* @retval   0  OK
* @retval   -1 ERROR
*/
SINT32 sys_GetVxWorksVersion(SYS_VERSION *pVers);

/**
* @ingroup SYS-API
* @brief This function compares two versions.
*
* The function tells if the versions are identical or which version is older.
* Both parameters must be passed as SYS_VERSION structure. Use sys_GetVersion()
* to obtain such structures from strings.
*
* @param[in]  pVers       Version to be compared
* @param[in]  pReqVers    Reference version
*
* @retval     1 Version pVers is newer than the reference version pReqVers
* @retval     0 The two versions are identical
* @retval     -1 Version pVers is older than the reference version pReqVers
*/
SINT32 sys_CompVersion(const SYS_VERSION *pVers, const SYS_VERSION *pReqVers);

/**
* @ingroup SYS-API
* @brief This function retrieves the current CPU usage.
*
* It reads the CPU usage for three different time frames. The function returns
* valid information, if CPU usage monitoring is enabled (NoWatchCpuUsage = OFF).
*
* @param[out]  pCpuUsage   Pointer to Structure SYS_CPUUSAGE
*
* @retval     0    OK
* @retval     <0   Error
*/
SINT32 sys_GetCpuUsage(SYS_CPUUSAGE *pCpuUsage);

/**
* @ingroup SYS-PAGE-SWITCH
* @brief This function returns the user partition of the given task.
*
* @note MSys internally manages up to 64 partitions (0 to 63), whereby 0 is the system partition.
*
* @param[in]  TaskId     VxWorks Task ID
*
* @return     User partition (#SYS_SYS_PART, #SYS_GLOB_PART, ...)
*/
UINT32 sys_GetTaskUserPart(UINT32 TaskId);

/**
 @ingroup SYS-PAGE-SWITCH
* @brief This function returns the page ID of the given task.
*
* @param[in]  TaskId     VxWorks Task ID
*
* @return     User page ID
*/
UINT32 sys_GetTaskPageId(UINT32 TaskId);

/**
* @ingroup SYS-API
* @brief This function can be used to specify the maximum correction value
*  (time change in seconds) for the SNTP client.
*
* The parameter `MaxCorrection` can be used to specify the maximum number of
* seconds by which the real time clock (RTC) may be adjusted for each update
* cycle. It is thereby possible to adjust the real time clock to the reference
* time of the time server in small intervals .
* The cyclical time synchronization can also be stopped with the parameter
* value = 0. The cyclical time synchronization is resumed by a new function
* call with parameter value != 0, whereby the first cycle in operation mode
* SNTP polling is immediately started and run. This allows execution of the
* SNTP client to be controlled to prevent, for example, any influence on
* the runtime.
*
* @note In the configuration file MConfig.ini, the keyword MaxCorrection in
*       the [SntpClient] section can be used to specify a correcting value.
*
* @param[in]  MaxCorrection   Maximum change per SNTP-Update in Seconds.
*
*   Values | Description
*   -------|-----------
*   1 to 2147483647 | Specifies the maximum correction value and permits continuing cyclic updates
*   0 | Stops the cyclic updates
*   -1 to -2147483648 | An optional negative value deletes an existing limitation and permits continuing cyclic updates
*
* <b>Example</b><br>
* `// limits the maximal SNTP time correction to 3600 seconds`<br>
* `sys_SntpSetMaxCorrection(3600);`<br><br>
* `// stops the SNTP client`<br>
* `sys_SntpSetMaxCorrection(0);`<br><br>
* `// resumes the SNTP Client and resets the limitation`<br>
* `sys_SntpSetMaxCorrection(-1);`
*/
VOID sys_SntpSetMaxCorrection(SINT32 MaxCorrection);

/**
* @ingroup SYS-API
* @brief This function sets the IP address, subnet mask, and standard gateway
*        of the specified Ethernet interface.
* The Ethernet interface to be changed is specified by the parameter
* pInterface. If an interface is not available, ERROR will be returned.
*
* @param[in]  pInterfaceName      Name of interface to configure ("eth0", "eth1",
*                                 "em0", "em1")
* @param[in]  pInterfaceAddress   Internet address to assign to interface
*                                 ("x.x.x.x")
* @param[in]  NetMask             Subnet mask (e.g. 0xff000000)
* @param[in]  pGateway     Inet addr or name of gateway. If the name is used,
*                          a host with the given name must already be configured
*
* @retval     0     OK
* @retval     -1    ERROR
*
* <b>Example</b><br>
* `sys_SetIpAddress("eth0","10.204.70.20",0xFFFFC000,"10.204.127.254")`<br>
* The function call sets for the Ethernet interface eth0, the IP address
* 10.204.70.20, with subnet mask 0xFFFFC000 and standard gateway 10.204.127.254.<br>
* In addition, the boot parameter inet on Ethernet will be set to
* 10.204.70.20:ffffc000 and the entry NetAddress, in group [Network] in
* MConfig.ini will be set to 10.204.70.20:ffffc000.
*/
SINT32 sys_SetIpAddress(CHAR8 *pInterfaceName, CHAR8 *pInterfaceAddress,
                        UINT32 NetMask, CHAR8 *pGateway);

/**
* @ingroup SYS-API
* @brief This function adds a function to be executed by the idle task.
*
* @param[in]  fpExec        Job execution function
* @param[in]  ExecParm      Execution function call parameter
* @param[in]  Delay         > 0 minimum job delay time before next call (optional)
* @param[in]  nCycles       > 0 is a cycle terminated job (optional)
* @param[in]  pDisabled     Function execution is disabled (optional)
* @param[in]  pName         Job function name, as displayed by the show
*                           function (if NULL, the name is taken from the
*                           symbol table)
*
* @retval     !0            Job Id
* @retval     0             Invalid fpExec, invalid Job-List or out of memory
*/
IDLE_ID sys_AddIdleJob(VOIDFUNCPTR fpExec, UINT32 ExecParm,
                       UINT32 Delay, UINT32 nCycles, BOOL8 *pDisabled,
                       const CHAR *pName);

/**
* @ingroup SYS-API
* @brief This function removes a job from the idle task job list.
*
* It is ensured that no new call of the given job is made when this function
* returns. But note that a previously started execution of the job isn't
* handled.
*
* @param[in]  JobId   Id of the Job to remove
*
* @retval     #OK      Job found and successfully marked for removing
* @retval     #ERROR   Job with the given ID doesn't exists
*/
STATUS sys_RemoveIdleJob(IDLE_ID JobId);

/**
* @ingroup SYS-API
* @brief  This function assigns a maximum CPU usage to a task.
*
* If the CPU usage is too high, a delay will be performed in the function
* sys_CycleEnd() for the task, that the required usage will be reached.
* Depending on the settings, this delay might last from a few milliseconds to
* several seconds.
*
* @note When the function is called several times for the same task,
*       the last settings are used for the CPU usage monitoring.
*
* @param[in]  TaskId      ID of the task
* @param[in]  MaxCpuUsage Maximum CPU usage in percent.
*                         0 disables the CPU usage monitoring.
* @param[in]  TimePeriod  Time period in us, in which the system measures the usage.
*                         The value 0 causes the monitoring to be executed for the
*                         maximum running time of the corresponding task group.
*                         It must be in the range of 1000 to 100000000us.
* @param[in]  MaxDelay    When > 0, set a limit in ms for the maximum delay. If this
*                         parameter is used the required usage might be exceeded.
* @param[in]  Reserved    This parameter must be 0
*
* @retval     #OK
* @retval     #ERROR      Parameter error or swap hook error
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_SetMaxTaskCpuUsage
*/
SINT32 sys_SetMaxTaskCpuUsage(SINT32 TaskId, UINT32 MaxCpuUsage, UINT32 TimePeriod,
                              UINT32 MaxDelay, UINT32 Reserved);

/**
* @ingroup SYS-TASK-API
* @brief Check if the given task ID is valid.
*
* @param[in]  taskId  Task ID to verify
*
* @retval  #OK
* @retval  #ERROR if the task ID is invalid
* @since MSys V3.90
*/
SINT32 sys_TaskIdVerify(int taskId);


/* Defined in sys_main.c */

/**
* @ingroup SYS-API
* @brief This function returns the system security level (0 - 4).
*
* @return Security level
* @since MSys V4.00
*/
SINT32 sys_GetSecurityLevel();

/**
* @ingroup SYS-API
* @brief This function determines if access control is enabled.
*
* "Access-control" supports exclusive SVI write-access for remote users. If enabled, remote
* users need to request an "access token" before write operations are allowed.
*
* Access can be obtained by sending the SMI-call RES_PROC_REQUESTACC or by writing to the
* SVI-variable RES/CurrentUser/RequestAccess. Access can be released by sending the SMI-Call
* RES_PROC_RELEASEACC or by writing to the SVI-variable RES/CurrentUser/ReleaseAccess.
*
*"Access-control" can be Activated by setting [SYSTEM], (SysMode), AccessControl =
* TRUE.
*
* @retval #TRUE if access control is enabled
* @retval #FALSE otherwise
* @since MSys V4.00
*/
BOOL8 sys_GetAccessControl();

/**
* @ingroup SYS-API
* @brief This function returns the path of the system directory.
*
* During the boot process of the M1 controller, the paths to system files,
* hardware module drivers, application programs etc. are determined by means
* of the boot parameters and configuration settings (MConfig.ini).
* This function returns the absolute path to these system directories. The
* transfer pointer is also the return value. If Id is invalid or the system
* directory is missing, an empty string ('\0') is returned.
*
* Possible directory Id's:
* - #M_DIR_BOOT
* - #M_DIR_SYS
* - #M_DIR_DRV
* - #M_DIR_APP
* - #M_DIR_SRV
* - #M_DIR_NVOL
* - #M_DIR_TMP
* - #M_DIR_KEY
* - #M_DIR_KEY2
* - #M_DIR_ETC
* - #M_DIR_CLASS
*
* @param[in]  DirId  Directory id (M_DIR_*)
* @param[in]  pDest  Pointer for the return of the directory path (string)
* @param[in]  Num    Size of the return memory (number of characters)
*
* @return pDest is returned
* @since MSys V3.95
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_GetDir
*/
CHAR *sys_GetDir(SINT32 DirId, CHAR *pDest, SINT32 Num);


/* Defined in sys_errno.c */

/**
* @ingroup SYS-API
* @brief This function gets the errno of a task and generates the corresponding
*        error text.
*
* @param[in]    pText   Pointer to the error text
*
* @retval     Pointer to the error text
*/
CHAR *sys_GetErrnoText(CHAR *pText);


/* Defined in sys_page.c */

/**
* @ingroup SYS-TASK-API
* @brief This function creates and starts a new task.
*
* It is similar to the VxWorks function taskSpawn, with the exception of the
* additional parameter `pAppName`, which contains the name of the application.
* Application programs must use this function instead of taskSpawn in order
* to have the protection mechanism working and to ensure that correct module
* administration is executed.
*
* @note Within a software module, the main task must be started first with
* this function. The subtasks (subsequent tasks) must be started after this
* main task. It is also the main task's responsibility to remove its sub tasks
* when getting uninstalled.
*
* If during the function call of sys_TaskSpawn() the option VX_FP_TASK is
* not specified, the contents of the coprocessor will not be saved and restored
* during task switching. Therefore, such a task may not use the coprocessor.
*
* @warning Starting with MSys V3.80, using the co-processor without the option
* VX_FP_TASK causes an exception 7. It is generally recommended to use the
* option VX_FP_TASK. Otherwise, it must be ensured that the coprocessor is not
* used (also applicable to all functions called in this task).
*
* @param[in]  pAppName String with the instance name of the application. The
*                      instance name may have a maximum of 8 characters
* @param[in] pTskName  String with the name of the task. The task name may have
*                      a maximum of 14 characters
* @param[in] Priority  VxWorks task priority with a value between 0 and 255.
*                      During priority allocation, the principles of M1 must be observed.
* @param[in] Options   VxWorks task options. For applications, only the option
*                      VX_FP_TASK is relevant
* @param[in] StackSize Size of the task stack. If the stack is too small, a
*                      stack overflow may occur
* @param[in] EntryPt   Entry point for the task. The
*                      prototype of this function is defined below.
* @param[in] Arg1,Arg2,Arg3,Arg4,Arg5,Arg6,Arg7,Arg8,Arg9
*                       Arguments for the task entry point function
*
* Syntax of the EntryPt function:\n
* @code{.c}
SINT32 (*EntryPt) (SINT32 Arg1, SINT32 Arg2, SINT32 Arg3,
                   SINT32 Arg4, SINT32 Arg5, SINT32 Arg6,
                   SINT32 Arg7, SINT32 Arg8, SINT32 Arg9, 0);
 @endcode
* @retval     Task-ID or ERROR, see VxWorks documentation taskSpawn
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_TaskSpawn
*/
#ifdef SYS__C
SINT32 sys_TaskSpawn(const CHAR *pAppName, const CHAR *pTskName, SINT32 Priority,
                     SINT32 Options, SINT32 StackSize, FUNCPTR EntryPt,
                     SINT32 Arg1, SINT32 Arg2, SINT32 Arg3, SINT32 Arg4,
                     SINT32 Arg5, SINT32 Arg6, SINT32 Arg7, SINT32 Arg8,
                     SINT32 Arg9);
#else
SINT32 sys_TaskSpawn(const CHAR *pAppName, const CHAR *pTskName, SINT32 Priority,
                     SINT32 Options, SINT32 StackSize, FUNCPTR EntryPt, ...);
#endif

/**
* @ingroup SYS-PAGE-MEM
* @brief Allocate memory of the given size from the application-partition.
*
* Application programs must use sys_MemAlloc() instead of malloc() in order to
* have the protection mechanism working. Use sys_MemFree() to free memory again.
*
* @note If the protection layer is set to SYSTEM or the CPU does not support memory protection
*       (e.g. ME203, CS200), memory from the system partition will automatically be allocated.
*
* @param[in]  Size    Size of memory to allocate in bytes.
*
* @retval     0       Memory could not be allocated
* @retval     !0      Pointer to the allocated memory
*
* @see sys_MemFree()
* @see sys_MemXAlloc()
* @see sys_MemPAlloc()
* @see sys_MemXPAlloc()
* @see sys_MemXPCalloc()
* @see sys_MemXRealloc()
* @see sys_MemPAlignedAlloc()
*/
VOID *sys_MemAlloc(UINT32 Size);

/**
* @ingroup SYS-PAGE-MEM
* @brief Releases memory with the starting-address `pBuff` from the application partition.
*
* If the protection layer is set to SYSTEM, then the memory is automatically released
* from the system partition.
* Application programs must use this function instead of free(), in order to have the
* protection mechanism working.
*
* @param[in]  pBuff   Pointer of memory to free.
*
* @see sys_MemAlloc()
*/
VOID sys_MemFree(VOID *pBuff);

/**
* @ingroup SYS-PAGE-MEM
* @brief Allocate memory from the application partition.
*
* The function sys_MemXAlloc() is identical to sys_MemAlloc(), except that the partition information
* is stored in the allocated header. This partition information will be used by sys_MemXFree() to free
* the memory from the correct partition.
*
* @note For CPUs without memory protection (e.g. ME203, CS200) the memory will be allocated
*       from the system partition.
*
* @param[in]  Size    Size of memory to allocate in bytes.
*
* @retval     0       Memory could not be allocated
* @retval     !0      Pointer to the allocated memory

* @see sys_MemXFree()
* @see sys_MemXPAlloc()
* @see sys_MemXPCalloc()
* @see sys_MemXRealloc()
*/
VOID *sys_MemXAlloc(UINT32 Size);

/**
* @ingroup SYS-PAGE-MEM
* @brief Change the size of a previously allocated memory.
*
* This function changes the size of a previously allocated memory passed in `pOld` to
* the `NewSize` and returns the new block of memory. The memory is copied into a
* different memory region if the new size is bigger that the old size.
*
* The function sys_MemXRealloc() is identical to sys_MemXPRealloc(), except
* that the partition information is not passed.
*
* @note This function can only be applied to memory areas that have been
*       allocated using sys_MemXAlloc().
*
* @note If the allocated memory is decreased, the remaining memory is released only if the
*       option "ReallocSmaller" is set for this partition in MConfig.ini otherwise the `pOld` will
*       be returned and all the previously allocated memory remains allocated.
*
* @param[in]  pOld    Pointer to memory to increase/decrease.
* @param[in]  NewSize New size of data to be allocated.
*
* @retval     0       Memory could not be allocated
* @retval     !0      Pointer to the reallocated memory
*
* @see sys_MemXFree()
* @see sys_MemXAlloc()
*/
VOID *sys_MemXRealloc(VOID *pOld, UINT32 NewSize);

/**
* @ingroup SYS-PAGE-MEM
* @brief Allocate memory from the specified partition.
*
* The function sys_MemXPAlloc() is identical to sys_MemPAlloc(), except that the partition information
* is stored in the allocated header. This partition information will be used by sys_MemXFree() to free
* the memory from the correct partition.
*
* @param[in]  iPart   Partition where to allocate memory. Limited by #MAX_PARTITION.
* @param[in]  Size    Size of memory to allocate in bytes.
*
* @retval     0       Memory could not be allocated
* @retval     !0      Pointer to the allocated memory
*
* @see sys_MemXFree()
* @see sys_MemXPRealloc()
*/
VOID *sys_MemXPAlloc(UINT32 iPart, UINT32 Size);

/**
* @ingroup SYS-PAGE-MEM
* @brief Change the size of a previously allocated memory.
*
* This function changes the size of a previously allocated memory passed in `pOld` to
* the `NewSize` in the partition specified by the parameter `iPart` and returns the
* new block of memory. The memory is copied into a different memory region if the
* new size is bigger that the old size.
*
* @note This function can only be applied to memory areas that have been
*       allocated using sys_MemXPAlloc().
*
* @note If the allocated memory is decreased, the remaining memory is released only if the
*       option "ReallocSmaller" is set for this partition in MConfig.ini otherwise the `pOld` will
*       be returned and all the previously allocated memory remains allocated.
*
* @param[in]  iPart   Partition where to realloc memory. Limited by #MAX_PARTITION.
* @param[in]  pOld    Pointer to memory to increase/decrease.
* @param[in]  NewSize New size of data to be allocated.
*
* @retval     0       Memory could not be allocated
* @retval     !0      Pointer to the reallocated memory
*
* @see sys_MemXFree()
* @see sys_MemXPAlloc()
*/
VOID *sys_MemXPRealloc(UINT32 iPart, VOID *pOld, UINT32 NewSize);

/**
* @ingroup SYS-PAGE-MEM
* @brief Allocate memory element array from the specified partition.
*
* This function allocates a block of memory for a data range given by the size that contains
* `ElementNum` elements of size `ElementSize` from the partition specified by the
* parameter `iPart`. The allocated block is set to zero. This partition information
* will be used by sys_MemXFree() to free the memory from the correct partition.
*
* @param[in]  iPart           Partition where to allocate memory. Limited by #MAX_PARTITION.
* @param[in]  ElementNum      Number of elements to allocate.
* @param[in]  ElementSize     Size of one element to allocate.
*
* @retval     0       Memory could not be allocated
* @retval     !0      Pointer to the allocated memory
*
* @see sys_MemXFree()
*/
VOID *sys_MemXPCalloc(UINT32 iPart, UINT32 ElementNum, UINT32 ElementSize);

/**
* @ingroup SYS-PAGE-MEM
* @brief Release memory allocated with sys_MemXAlloc() or sys_MemXPAlloc().
*
* Releases the memory from the corresponding partition using the starting address
* `pBuff`. The memory to be released must have been allocated using the functions
* sys_MemXAlloc() or sys_MemXPAlloc().
*
* @param[in]  pBuff    Pointer of memory to free.
*/
VOID sys_MemXFree(VOID *pBuff);

/**
* @ingroup SYS-PAGE-MEM
* @brief Allocate memory from the specified partition.
*
* This function allocates a memory with the `Size` from the partition specified by
* the parameter `iPart`.
* This function is necessary if an application program wants to allocate memory from
* a partition other than the default partition. It is similar to the VxWorks function
* memPartAlloc().
*
* @param[in]  iPart   Partition where to allocate memory. Limited by #MAX_PARTITION.
* @param[in]  Size    Size of memory to allocate in bytes.
*
* @retval     0       Memory could not be allocated
* @retval     !0      Pointer to the allocated memory
*
* @see sys_MemPFree()
* @see sys_MemPAlignedAlloc()
*/
VOID *sys_MemPAlloc(UINT32 iPart, UINT32 Size);

/**
* @ingroup SYS-PAGE-MEM
* @brief Allocate memory from the specified partition.
*
* This function allocates a memory with the `Size` from the partition specified by
* the parameter `iPart`. The allocated memory begins with a memory address that can
* be divided equally by the alignment. Alignment must be a power of 2.
*
* @param[in]  iPart      Partition where to allocate memory. Limited by #MAX_PARTITION.
* @param[in]  Size       Size of memory to allocate in bytes.
* @param[in]  Alignment  Alignment of memory to allocate. Must be a power of 2.
*
* @retval     0       Memory could not be allocated
* @retval     !0      Pointer to the allocated memory
*
* @see sys_MemPFree()
* @see sys_MemPAlignedAlloc()
*/
VOID *sys_MemPAlignedAlloc(UINT32 iPart, UINT32 Size, UINT32 Alignment);

/**
* @ingroup SYS-PAGE-MEM
* @brief Release memory allocated with sys_MemPAlloc().
*
* Releases the memory from the corresponding partition using the starting address
* `pBuff`. The memory to be released must have been allocated using the function
* sys_MemPAlloc().
*
* @param[in]  iPart    Partition where to allocate memory. Limited by #MAX_PARTITION.
* @param[in]  pBuff    Pointer of memory to free.
*/
VOID sys_MemPFree(UINT32 iPart, VOID *pBuff);

/**
* @ingroup SYS-PAGE-MEM
* @brief Get the ID of a partition.
*
* The returned ID can be used as a parameter for VxWorks functions (memPartX...)
*
* @note The partition `iPart` is not identical to the partition ID of memPartAlloc.
*       MSys internally manages up to 64 partitions (0 to 63), whereby 0 is the system partition.
*
* @param[in]  iPart   Partition to get ID for. Limited by #MAX_PARTITION.
*
* @retval     !0      ID of partition
* @retval     0       Partition not found.
*/
UINT32 sys_MemPartId(UINT32 iPart);

/**
* @ingroup SYS-PAGE-MEM
* @brief Get the size of a partition.
*
* @param[in]  iPart   Partition to get size for. Limited by #MAX_PARTITION.
*
* @retval     !0      Size of partition in bytes.
* @retval     0       Partition not found.
*/
UINT32 sys_MemPartSize(UINT32 iPart);

/**
* @ingroup SYS-PAGE-SWITCH
* @brief Determines the page ID of the partition, specified by the parameter `iPart`.
*
* This function is normally used only in system programs.
*
* @param[in]  iPart   Partition to get ID for. Limited by #MAX_PARTITION.
*
* @retval     !0      Page ID of the partition.
* @retval     0       Partition not found.
*/
UINT32 sys_PageIdPart(UINT32 iPart);

/**
* @ingroup SYS-PAGE-SWITCH
* @brief Determines the current page ID of the task, specified by the parameter `TaskId`.
*
* This function is normally used only in system programs.
*
* @param[in]  TaskId  Task ID or zero for own task
*
* @retval     !0      Page ID of the task.
* @retval     0       Partition not found.
*/
UINT32 sys_PageIdTask(UINT32 TaskId);

/**
* @ingroup SYS-PAGE-SWITCH
* @brief This function can be used to change the protection behavior of a particular
*        application address range.
*
* `Mask` is used to remove attributes from the desired memory block and `State` is used
* to set attributes to a memory block.
*
* @note
* The parameters `MemStart` and `MemLen` will be page aligned. The starting address is set to
* the next higher 4 kB limit and the ending address to the next lower 4 kB limit.
* The page status is therefore changed only for whole 4 kB blocks which are within the stated range.
*
* @param[in]  PageId    ID returned by the function sys_PageIdTask() or sys_PageIdPart().
* @param[in]  MemStart  The starting address.
* @param[in]  MemLen    Size in bytes.
* @param[in]  Mask      Used to remove attributes from the desired memory block
*                       (see #PAGE_NO_OPTION and #PAGE_WRITABLE).
* @param[in]  State     Used to set attributes to a memory block
*                       (see #PAGE_NO_OPTION and #PAGE_WRITABLE).
*
* @retval     0         Status has changed.
* @retval     -1        Error, Page ID not valid.
* @retval     -2        Error, page does not exist in the PageDir.
* @retval     -3        Error, page does not exist in the PageTable.
* @retval     -4        Error, `MemStart` does not exist in the PageTable.
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_GetMemAddress
*/
SINT32 sys_PageStateSet(UINT32 PageId, UINT32 MemStart, UINT32 MemLen, UINT32 Mask, UINT32 State);

/**
* @ingroup SYS-PAGE-MEM
* @brief Get the maximum size of an available memory block of a partition.
*
* @param[in]  iPart   Partition to get size for. Limited by #MAX_PARTITION.
*
* @retval     !0      Size of largest available memory block in Byte.
* @retval     0       Partition not found.
*/
UINT32 sys_MemPartSizeMaxBlk(UINT32 iPart);

/**
* @ingroup SYS-PAGE-MEM
* @brief Get the available memory of a partition.
*
* @param[in]  iPart   Partition to get size for. Limited by #MAX_PARTITION.
*
* @retval     !0      Available memory in Byte.
* @retval     0       Partition not found.
*/
UINT32 sys_MemPartSizeFree(UINT32 iPart);

/**
* @ingroup SYS-PAGE-MEM
* @brief Get the size of a partition (including BlockPool partitions).
*
* In contrast to the function sys_MemPartSize(), the partition is not checked
* here. This makes it possible to read out the size of the partitions managed as
* BlockPool as well.
*
* @param[in]  iPart   Partition to get size for. Limited by #MAX_PARTITION.
*
* @retval     !0      Size of partition in bytes.
* @retval     0       Partition not found.
*/
UINT32 sys_MemPartSizeAll(UINT32 iPart);


/* Defined in sys_exc.c */

/**
* @ingroup SYS-EXC-API
* @brief This function installs a signal handler for Pentium exceptions
*        0 to 31.
*
* If an exception occurs (CPU exception interrupt, for example protection
* fault), the system software sends the signal #M_SIGEXCEPT to the
* corresponding task. As a result, the program execution immediately jumps in
* the signal handler. If a task has no signal handler installed,
* the task will be suspended.
* Signal handlers are not inherited between tasks, every task must install its
* own handler.
* Exception signal handlers can, depending on the application, restart the task
* of a task-group or of a module. In some cases it may be useful to have an
* orderly shutdown of the system.
*
* @note If an exception handler is installed by a software module using this
* function, then the software module is also responsible for setting the system
* status and CPU LEDs accordingly when the exception occurs. The operating
* system is no longer responsible for this.
* The signal handler `pHandler` will be called in the context of the task
* that called the function sys_ExcSigSet().
*
* @param[in]  pHandler   Pointer to the signal handler function
*
* @retval     #OK
* @retval     #ERROR if pHandler is NULL
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_ExcSigSet
*/
SINT32 sys_ExcSigSet(VOIDFUNCPTR pHandler);

/**
* @ingroup SYS-EXC-API
* @brief This function uninstalls a signal handler for the Pentium Exceptions
*        0 to 31.
* The function is intended to be used for the de-installation of modules.
*
* @retval    #OK Always return OK
*/
SINT32 sys_ExcSigReset(VOID);

/**
* @ingroup SYS-API
* @brief This function stops the given task.
*
* The function sys_StopApp() is called and the given task is suspended.
*
* @param[in]  TaskId    Id of task to stop
*/
VOID sys_StopTask(UINT32 TaskId);

/**
* @ingroup SYS-API
* @brief This function sets the system state and the application state to #RES_S_ERROR.
*/
VOID sys_StopApp(VOID);


/* Defined in sys_pnc.c */

/**
* @ingroup SYS-API
* @brief This function installs a signal handler for the panic process.
*
* The address of the panic handler and an optional 32 bit value are passed as
* parameters.
* After the panic situation has occurred (power failure, I/O error or
* application error), the system software (the mPANIC task respectively) will
* call all installed panic signal handlers.
* The panic signal handler may only be installed once per module (module oriented).
* If subsequent tasks exist, they will be notified by the preceding task of the
* module.
* The purpose of the panic signal handler is to perform final safety actions,
* e.g. close all files in the NVRAM.
*
* The panic source and an optional 32-bit parameter will be transferred to
* the panic handler as parameters.
*
* @note The signal handler `pHandler` will be called in the context of the task
* that called the function sys_PanicSigSet().

* @param[in]  pHandler   Pointer to the signal handler
* @param[in]  ...      Optional user parameter
*
* @retval     #OK
* @retval     #ERROR <br>
*
* <b>Example 1</b>
* @snippet doc_sys_msys_e.c sys_PanicSigSet1
*
* <b>Example 2 (without optional parameter)</b>
* @snippet doc_sys_msys_e.c sys_PanicSigSet2
*/
#ifdef SYS_PNC__C
    SINT32 sys_PanicSigSet(VOIDFUNCPTR pHandler, UINT32 Param);
#else
    SINT32 sys_PanicSigSet(VOIDFUNCPTR pHandler, ...);
#endif

/**
* @ingroup SYS-API
* @deprecated This function is only needed for compatibility reasons.
*             It was replaced by sys_PanicSigSet.
*
* @param[in]  pHandler   Pointer to the signal handler function
*
* @retval     #OK
*/
SINT32 sys_PFailSigSet(VOIDFUNCPTR pHandler);

/**
* @ingroup SYS-API
* @brief This function uninstalls a signal handler for the panic process.
*
* In case of a panic situation, this task will not be informed. The function
* is intended for the uninstallation of modules.
*
* @retval     #OK
* @retval     #ERROR
*/
SINT32 sys_PanicSigReset(VOID);

/**
* @ingroup SYS-API
* @deprecated This function is only needed for compatibility reasons.
*             It was replaced by sys_PanicSigSet.
*
* @retval     #OK
*/
SINT32 sys_PFailSigReset(VOID);

/**
* @ingroup SYS-API
* @brief The application can use this function to start the panic processing.
*
* During the function call, the panic task (which always has a higher priority
* than the application) immediately becomes active. When the controller is
* rebooted, the file /nvram0/panic.txt is searched for, and if it exists,
* issued as reboot cause.
*
* @param[in]  Mode   Only the value #SYS_APPPANIC is allowed for
*                    application programs
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_GoPanic
*/
VOID sys_GoPanic(UINT32 Mode);

/**
* @ingroup SYS-API
* @brief Like sys_GoPanic() only that an extra error message can be set.
*
* @param[in]  Mode   Only the value #SYS_APPPANIC is allowed for
*                    application programs
* @param[in]  PanicText    Error text
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_GoPanic2
*/
VOID sys_GoPanic2(UINT32 Mode, CHAR PanicText[]);

/**
* @ingroup SYS-API
* @brief This function determines the panic source in a panic situation.
*
* This function is useful in the shutdown task to set a specific reaction
* to different causes.
*
* @return Current panic mode. Possible values, see table below
*
* Panic mode       | Value  | Description
* -----------------|--------|-------------
* #SYS_PFAILPANIC  | 0x0001 | Interrupt of the supply voltage
* #SYS_IOPANIC     | 0x0002 | Serious error on the I/O bus of the controller
* #SYS_APPPANIC    | 0x0004 | Panic triggered by application program
* #SYS_SYSPANIC    | 0x0008 | Internal system error (software watchdog in an application, reboot on exception, exception in ISR)
* #SYS_REBOOTPANIC | 0x0010 | Reboot hooks prevented an orderly reboot within a specified period of time
* #SYS_HWWDOGPANIC | 0x0020 | Hardware watchdog
*/
UINT32 sys_GetPanicMode(VOID);

/**
* @ingroup SYS-API
* @brief This function is used to declare the calling task as a shutdown task.
*
* However, only 1 shutdown task can be active at a time. The panic modes that
* are to activate the shutdown task can be specified as parameters. At the end
* of the function execution, the task is suspended and only activated at the
* occurrence of a panic-situation.
*
* @param[in]  PanicMode   The panic mode by which the task is activated
*
* @retval     0       OK
* @retval     -1      Error
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_ShutDown
*/
SINT32 sys_ShutDownWait(UINT32 PanicMode);

/**
* @ingroup SYS-API
* @brief Using this function, the shutdown task reports the end of its
*        shutdown actions.
*
* The function performs a suspend of the shutdown task and activates the panic
* handler. Only after this function call the panic handler will reset the
* I/O-bus and stop the CPU.
*
* @retval     0       OK
* @retval     -1      Error
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_ShutDown
*/
SINT32 sys_ShutDownEnd(VOID);

/**
* @ingroup SYS-API
* @brief Using this function, a shutdown task can be declared again as
*        a standard task.
*
* The task is not activated by this function but cancelled from the system
* internal administration.
*
* @retval     0       OK
* @retval     -1      Error
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_ShutDown
*/
SINT32 sys_ShutDownRemove(VOID);


/* Defined in sys_wdog.c */

/**
* @ingroup SYS-WDOG
* @brief This function creates a new software watchdog, but does not yet
*        start it.
* The user must transfer the name of the instance and the desired
* period of time in microseconds (minimum 50 us).
* The returned watchdog ID has to be used for the further watchdog functions.
*
* @param[in]  pAppName   Instance name of the module
* @param[in]  WatchTime  Time interval in us
*
* @retval     !0      ID of created watchdog
* @retval     0       Watchdog could not be created
*                     (insufficient memory, invalid parameter)
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_Wdog
* @see sys_WdogTrigg()
*/
UINT32 sys_WdogCreate(const CHAR *pAppName, UINT32 WatchTime);

/**
* @ingroup SYS-WDOG
* @brief The watchdog is started with the first use of this function.
*
* Afterwards the function has to be called cyclically in time periods,
* shorter than the time stated in sys_WdogCreate(). Otherwise a
* a hardware reset will be executed within approx. 60 ms.
*
* @note The task to be monitored is saved for later processing.
*
* @param[in]  WdogId  ID of a watchdog
*
* @retval     0       Error or watchdog time has expired
* @retval     !0      Delta time since last call of this function in us
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_Wdog
*/
UINT32 sys_WdogTrigg(UINT32 WdogId);

/**
* @ingroup SYS-WDOG
* @brief This function allows the watchdog timeout value to be set to
*        a new value.
* The value in `WatchTime` specifies the new desired time-period in microseconds
* (>= 50 us).
*
* @param[in]  WdogId     ID of a watchdog
* @param[in]  WatchTime  Time interval in us
*
* @retval     #OK        Time interval set
* @retval     #ERROR     Invalid parameter
*/
SINT32 sys_WdogReconfig(UINT32 WdogId, UINT32 WatchTime);

/**
* @ingroup SYS-WDOG
* @brief This function deactivates a software watchdog, which, therefore,
*        no longer needs to be triggered cyclically.
* The corresponding software watchdog will be reactivated when sys_WdogTrigg()
* is called.
*
* @param[in]  WdogId  ID of a watchdog
*
* <b>Example</b><br>
* `sys_WdogDisable(WdogId);`<br>
* `taskSuspend(0);`<br>
* `sys_WdogTrigg(WdogId);`<br>
*/
VOID sys_WdogDisable(UINT32 WdogId);

/**
* @ingroup SYS-WDOG
* @brief This function deactivates all software watchdogs.
*/
VOID sys_WdogDisableAll(VOID);

/**
* @ingroup SYS-WDOG
* @brief This function activates all software watchdogs.
*/
VOID sys_WdogEnableAll(VOID);

/**
* @ingroup SYS-WDOG
* @brief This function removes an existing software watchdog without triggering
*        a hardware reset.
*
* @param[in]  WdogId  ID of the watchdog
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_Wdog
*/
VOID sys_WdogDelete(UINT32 WdogId);

/**
* @ingroup SYS-WDOG
* @brief A targeted reboot via the hardware watchdog can be initiated with the
*        function sys_WdogRelease().
*
* After calling this function, the hardware watchdog is no longer triggered,
* so that a reboot is initiated and cannot be cancelled. The time for the
* reboot can last between a few microseconds and 120 ms. If the hardware
* watchdog is disabled, this is enabled explicitly.
*/
VOID sys_WdogRelease(VOID);

/**
* @ingroup SYS-WDOG
* @brief This function installs the signal handler #M_SIGTIMEOUT for the
*        watchdog timeout.
*
* If a software watchdog cycle overrun occurs, this signal handler is called
* to inform the application of a cycle overrun. It is up to the application to
* make the changes necessary for ensuring that no further cycle overruns occur.
* If overruns still exist after three calls of the signal handler, the
* software watchdog will do a panic reboot.
*
* Possibilities to repair a cycle overrun are:
* 1. Change cycle time and increase the watchdog time via the function
* sys_WdogReconfig()
* 2. Shorten code execution by going through shorter loops
*
* @note This function needs to be called by the same task as the function
* sys_WdogTrigg(). The signal handler `pHandler` will be called in the context
* of the task that called the function sys_WdogSigSet().
*
* @param[in]  pHandler    Pointer to signal handler function
*
* @retval     #OK    This function always returns OK
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_WdogSigSet
*/
SINT32 sys_WdogSigSet(VOIDFUNCPTR pHandler);

/**
* @ingroup SYS-WDOG
* @brief This function uninstalls the signal handler #M_SIGTIMEOUT for the
*        watchdog timeout.
*
* @note This function needs to be called by the same task as the function
*       sys_WdogTrigg().
*
* @retval     #OK    This function always returns OK
*/
SINT32 sys_WdogSigReset(VOID);

/**
* @ingroup SYS-WDOG
* @brief This function retrieves the watchdog ID of a task.
*
* @param[in]  TaskId ID of the given task
*
* @retval     !0 ID of watchdog
* @retval     0 If the task with the given id has no watchdog
*/
UINT32 sys_GetWdogId(UINT32 TaskId);


/* Defined in sys_aux.c */

/**
 * @ingroup SYS-API
* @brief This function introduces linking to the Auxiliary Clock Interrupt.
*
* It must be called prior to the use of sys_AttachAux() or sys_DetachAux().
* The instance name of the software module must be passed as parameter.
* The purpose of this function is to be able to remove the
* auxiliary clock handlers of a software module as well, if an abnormally
* terminated software module has been removed.
*
* @param[in]  pAppName   Instance name of the module that attaches to Aux
*
* @retval     >=0     Session ID for the treatment of Sync-interrupts
* @retval     <0      Error, auxiliary interrupt not enabled (AuxRate = 0)
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_AuxSession
*/
SINT32 sys_StartAuxSession(CHAR *pAppName);

/**
* @ingroup SYS-API
* @brief This function is the counterpart to sys_StartAuxSession() and allows
*        the termination of an Auxiliary Clock Interrupt session.
* This function is used to remove all Auxiliary Clock handlers belonging to
* this session ID (SessId) that are still installed.
*
* @param[in]  SessId      Session ID returned by the function sys_StartAuxSession()
*
* @retval     #MIO_ER_OK     OK
* @retval     #MIO_ER_FAIL   Auxilary clock was not correctly started or there
*                            is not enough free memory
* @retval     #MIO_ER_BADPARM  Invalid Session ID
*
* <b>Example</b>
* @see Example of sys_StartAuxSession().
*/
SINT32 sys_StopAuxSession(SINT32 SessId);   // Use return value only on MSys >= 3.30R

/**
* @ingroup SYS-API
* @brief This function can be used to register an own auxiliary clock handler.
*
* This auxiliary clock handler is called on every RTC clock interrupt. The
* auxiliary clock rate is configurable using the formula (SysTime) / AuxRate = n.
* sys_StartAux() must be called prior to the use of sys_AttachAux() to create a
* Session ID.
* The function sys_AttachAux() can be called repeatedly per session using
* different `AppIsr` functions.
* sys_StopAux() must be called to terminate a Session.
*
* @note The Aux interrupt handler doesn't toggle the memory protection layer.
* If an application installs a routine that accesses protected memory, the
* protection mechanism must be switched off. VxWorks calls do not require
* such a switch.
*
* @note The Aux handler (AppIsr) is invoked in the context of an interrupt
* and for this reason the runtime should be minimized.
*
* @param[in]  SessId      Session ID returned by the function sys_StartAuxSession()
* @param[in]  Type        Mode for the process. Use #SYS_AUX_SINGLE for
*             \b One-shot processing or #SYS_AUX_CONT for \b continuous
*             \b processing.
*             In \b One-shot mode, the function is only called once. In
*             order to activate it again, the sys_AttachAux() function must
*             be called again
* @param[in]  Counter    Number of Aux interrupts that must occur before the
*                        Aux handler is triggered
* @param[in]  AppIsr     Pointer to the ISR function
* @param[in]  UserParam  This parameter is passed directly to the handler
*                        function `AppIsr`
*
* @retval     0   OK
* @retval     <0  Error, auxiliary interrupt not enabled (AuxRate = 0)
*
* <b>Example</b>
* @see Example of sys_StartAuxSession().
*/
SINT32 sys_AttachAux(SINT32 SessId, UINT32 Type, UINT32 Counter,
                     VOID (*AppIsr)(), UINT32 UserParam);

/**
* @ingroup SYS-API
* @brief This function is the counterpart of sys_AttachAux() and removes an
*        auxiliary clock handler.
*
* To delete an existing entry, the same parameters as in the case of
* sys_AttachAux() must be passed. If sys_StopAuxSession() is called, all
* existing Aux handlers are automatically detached.
*
* @param[in]  SessId      Session ID returned by the function sys_StartAuxSession()
* @param[in]  AppIsr      Pointer to the ISR function
*
* @retval     0    OK
* @retval     <0   Error
*
* <b>Example</b>
* @see Example of sys_StartAuxSession().
*/
SINT32 sys_DetachAux(SINT32 SessId, VOID (*AppIsr)());


/* Defined in sys_alib.s */

/**
* @ingroup SYS-PAGE-SWITCH
* @brief This function switches the protection mechanism of the CPU from
*        application to system.
*
* The entire memory range available can be written after this function call.
*
* @warning This function disables the protection mechanisms.
*          As soon as the system access authorization is not needed any more,
*          the protection mechanism must be restored with sys_SysToApp().
*
* @return  Current page ID of the application (that must be passed on when
*          calling sys_SysToApp()).
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_AppToSys
*/
UINT32 sys_AppToSys(VOID);

/**
* @ingroup SYS-PAGE-SWITCH
* @brief This function switches the protection mechanism of the CPU from system
*        back to application.
*
* After calling this function, the system memory (program and data range
* outside of the application-partition) can only be read. A protection fault
* will occur if a write access is attempted.
* The page ID of the application that was received from sys_AppToSys() must be
* transferred as the parameter.
* This function is the counterpart of sys_AppToSys().
*
* @param[in] PageId  PageId of the application which was received from
*                    sys_AppToSys()
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_AppToSys
*/
VOID sys_SysToApp(UINT32 PageId);

/**
* @ingroup SYS-PAGE-SWITCH
* @brief This function switches the protection mechanism of the CPU from
*        application to global.
*
* After calling this function, the global-memory (partition 1) and all
* applications (partition 2 and higher) can be written.
*
* @return  Current page ID of the application (that must be passed on when
*          calling sys_GlobToApp()).
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_AppToGlob
*/
UINT32 sys_AppToGlob(VOID);

/**
* @ingroup SYS-PAGE-SWITCH
* @brief This function switches the protection mechanism of the CPU from
*        global back to application.
*
* After calling this function, only the "global" memory (global data
* range for all applications) can be read. A protection fault will occur
* if a write access is attempted.
* This function is the counterpart of sys_AppToGlob().
*
* @param[in] PageId  PageId of the application which was received from
*                    sys_AppToGlob()
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_AppToGlob
*/
VOID sys_GlobToApp(UINT32 PageId);

/**
 * @ingroup SYS-API
* @brief This function turns off interrupts.
*
* @return CPU-Flags
*/
UINT32 sys_HwIntLock(VOID);

/**
 * @ingroup SYS-API
* @brief This function turns on interrupts.
*
* <b>Parameters</b>
* <pre>      [in] CPU-Flags</pre>
*/
VOID sys_HwIntUnlock(UINT32);

/**
 * @ingroup SYS-API
* @brief This function can be used to lock one or more hardware interrupts
*        temporarily.
*
* In case of determinism, some routines should not be interrupted by
* time uncritical interrupts. An execution of these interrupts can then be
* postponed using this function.
*
* @note  Locking of interrupts may only be done for a short period of time,
*        never for longer than 200 us.
*
* @param[in] Maske   Setting the hardware interrupts.
*                    Mask is determined via the sys_HwIntLockMaskGet() function.
*
* @return Mask of interrupts which have been locked.
*         This mask must be passed when calling sys_HwIntLockRestore().
*
* @note The return mask is different from the call mask and they must not be
*       confused.
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_HwIntLockSet
*/
UINT32 sys_HwIntLockSet(UINT32 Maske);

/**
 * @ingroup SYS-API
* @brief This function can be used to restore the interrupt lock layer.
*
* This is the counterpart of the function sys_HwIntLockSet().
*
* @param[in] Maske   Restore interrupt-disable level
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c sys_HwIntLockSet
*/
VOID sys_HwIntLockRestore(UINT32 Maske);

/**
 * @ingroup SYS-API
* @brief Reads byte-value IO-mapped.
*
* @param[in] Address   Address of IO
*
* @return   Byte-value of address
*/
UINT8 sys_InByte(UINT32 Address);

/**
 * @ingroup SYS-API
* @brief Writes byte-value IO-mapped.
*
* @param[in] Address   Address of IO
* @param[in] Data      Byte-value to write
*/
VOID sys_OutByte(UINT32 Address, UINT8 Data);

/**
 * @ingroup SYS-API
* @brief Reads byte-value memory-mapped.
*
* @param[in] Address   Address memory position
*
* @return   Byte-value of address
*/
UINT8 sys_MemReadByte(UINT32 Address);

/**
 * @ingroup SYS-API
* @brief Writes byte-value memory-mapped.
*
* @param[in] Address   Address of memory position
* @param[in] Data      Byte-value to write
*/
VOID sys_MemWriteByte(UINT32 Address, UINT8 Data);

/**
 * @ingroup SYS-API
* @brief This function determines the quotient and the remainder from a
*        signed 64 bit dividend and a 32 bit divisor.
*
* Quotient and remainder each are 32 bit values. Therefore it is a division
* of SINT64 / UINT32 = SINT32. This 64-bit operation does not exist in VxWorks.
*
* @note The quotient must be presentable in a 32-bit value (31 bits plus sign),
*       otherwise this function generates an exception.
*
* @param[in]  numer     Transfer of the dividend.
* @param[in]  denom     Transfer of the divisor.
* @param[out] pDivStr   Return of the result.
*                       The result is defined as in the VxWorks function div_r().
*                       The structure ldiv_t is defined in stdlib.h.
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c llsdiv_r
*/
VOID llsdiv_r(SINT64 numer, UINT32 denom, ldiv_t *pDivStr);

/**
 * @ingroup SYS-API
* @brief This function determines the quotient and the remainder from an
*        unsigned 64 bit dividend and a 32 bit divisor.
*
* Quotient and remainder each are 32 bit values. Therefore it is a division
* of UINT64 / UINT32 = UINT32. This 64-bit operation does not exist in VxWorks.
* This function is like llsdiv_r() for dividends without a sign.
*
* @note The quotient must be presentable in a 32-bit value (31 bits plus sign),
*       otherwise this function generates an exception.
*
* @param[in]  numer     Transfer of the dividend.
* @param[in]  denom     Transfer of the divisor.
* @param[out] pDivStr   Return of the result.
*                       The result is defined as in the VxWorks function div_r().
*                       The structure ldiv_t is defined in stdlib.h.
*
* <b>Example</b>
* @snippet doc_sys_msys_e.c lludiv_r
*/
VOID lludiv_r(UINT64 numer, UINT32 denom, ldiv_t *pDivStr);


/* Defined in sys_reboot.c */

/**
 * @ingroup SYS-API
* @brief This function performs a reboot via the VxWorks function reboot().
* If the system freezes during the VxWorks reboot, a maximum time of 5 seconds
* is monitored in this function. After this maximum time has expired, a hard
* reboot is initiated via the M1 hardware.
*
* @note It is recommended to always use this function instead of the VxWorks
* function reboot().
*/
VOID sys_Reboot(VOID);


/* Defined in sys_task.c */

/**
 * @ingroup SYS-TASK-API
* @brief This function creates a new task.
*
* This function creates a task with a specified trigger source
* (tick, sync, aux, event or error) or a free-wheeling task, but it does
* <b>not</b> start the task. The created task can be started by the
* function sys_TaskStart().<br>
* The cycle time of a task can be specified for trigger source tick,
* sync and aux. <br>
* Furthermore this function can create a watchdog for the created
* task (for trigger source tick, sync, aux and free-wheeling). <br>
*
* @see #SYS_TASK_ATTRIBUTES for all configurable parameters.
*
*  @note If a cycle time is configured (tick/sync/aux), and the cycle time does not match the
*        tick rate / sync rate / aux rate, the cycle time is increased to the next possible value.
*        If the increased cycle time differs more than 25% from the configured cycle time, the
*        function fails.
*
*  @note If an offset is configured (tick/sync), and the offset does not match the
*        tick rate / sync rate, the offset time is increased to the next possible value.
*        If the increased offset time differs more than 25% from the configured offset, the
*        function fails and returns an error code.
*        If the configured offset (or the increased offset in case of configured
*        offset that does not match tick rate / sync rate) is greater than the
*        configured cycle time, the function fails.
*
* @param[in]   pTaskAttr     Transfer of the task configuration.
* @param[out]  pTaskHandle   Task handle.
*
* @retval #M_E_OK               Task has been successfully created (not started)
* @retval #M_E_PARM             Invalid parameter
* @retval #M_E_TASK_WDOG        Watchdog could not be created
* @retval #M_E_TASK_SEM         Semaphore could not be created
* @retval #M_E_TASK_PRIO        Priority is out of range (has to be between 1 and 255)
* @retval #M_E_TASK_SOURCE      Unknown task trigger source
* @retval #M_E_TASK_OFFSET      Invalid offset:
*                               - Configured offset is greater than cycle time or
*                               - Configured offset does not match tick/sync rate
*                                 and next possible offset does differ more than 25% from configured cycle time or
*                               - Configured offset does not match tick/sync rate and
*                                 next possible cycle time is greater than configured cycle time
* @retval #M_E_TASK_CYCDIFF     Configured cycle time does not match tick/sync rate and
*                               next possible cycle time does differ more than 25% from configured cycle time
* @retval #M_E_TASK_CYCTIME     Cycle time is too small
* @retval #M_E_BADCONFIG        System sync configuration invalid (in case of #TRG_SYNC)
* @retval #M_E_BADSESS          Could not start sync/aux/event/error session
* @retval #M_E_TASK_ATTACH      Could not attach to sync/aux
* @retval #M_E_TASK_AUXOFF      Auxiliary clock is turned off (in case of #TRG_AUX)
* @retval #M_E_TASK_NOMAINFUNC  No user main function for task (`pUserMainFunc = NULL`)
* @retval #M_E_TASK_NOPTP       Task can not be synchronized to PTP because
*                               PTP synchronization is not activated
*
* @see sys_TaskStart(), sys_TaskDelete(), sys_TaskAttachEvent(), sys_TaskAttachError(),
*      sys_TaskDetachEvent(), sys_TaskDetachError(), sys_TaskGetInfo().
*/
SINT32 sys_TaskCreate(const SYS_TASK_ATTRIBUTES *pTaskAttr, SYS_TASK_HANDLE *pTaskHandle);

/**
 * @ingroup SYS-TASK-API
* @brief This function starts a task that has been created by the function
*        sys_TaskCreate().
*
* @note Within a software module, the main task must be started first.
*       The subtasks (subsequent tasks) must be started after this main task.
*       It is also the main task's responsibility to remove its sub tasks when
*       getting uninstalled.
*
* If during the function call of sys_TaskStart() the parameter `UseFPU` of the
* structure #SYS_TASK_ATTRIBUTES has not been set to #TRUE for creating the task
* handle via the function sys_TaskCreate(), the contents of the coprocessor will
* not be saved and restored during task switching. Therefore, such a task may not
* use the coprocessor.
*
* @warning Starting with MSys V3.80, using the coprocessor without the parameter
* `UseFPU` set #TRUE causes an exception 7. It is generally recommended to set the
* parameter `UseFPU` to #TRUE. Otherwise, it must be ensured that the coprocessor
* is not used (also applicable to all functions called in this task).
*
* Compared to the function sys_TaskSpawn(), this function can start a task
* with a specified trigger source (tick, sync, aux, event, error or free-wheeling),
* cycle time, watchdog, etc.
*
* @param[in]  taskHandle     Transfer of the task handle that has been returned
*                            by the function sys_TaskCreate().
*
* @retval #M_E_OK            Task has been successfully started
* @retval #M_E_PARM          Invalid parameter
* @retval #M_E_BADSPAWN      Error spawning task
*
* @see sys_TaskCreate()
*/
SINT32 sys_TaskStart(SYS_TASK_HANDLE taskHandle);

/**
 * @ingroup SYS-TASK-API
* @brief This function stops a task that has been created by the function
*        sys_TaskCreate() and started by the function sys_TaskStart().
*
* To resume a task that has been stopped by this function, use function
* sys_TaskResume().
*
*  @note A task that has been stopped by this function <b>cannot</b> be resumed
*  by the function sys_TaskStart(). The function sys_TaskStart() does only the
*  first start of the task created by sys_TaskCreate().
*
* @param[in]  taskHandle     Transfer of the task handle that has been returned
*                            by the function sys_TaskCreate().
*
* @retval #M_E_OK      Task has been successfully stopped
* @retval #M_E_PARM    Invalid parameter
* @retval #M_E_FAILED  Task already stopped
*
* @see sys_TaskCreate()
* @see sys_TaskResume()
*/
SINT32 sys_TaskStop(SYS_TASK_HANDLE taskHandle);

/**
 * @ingroup SYS-TASK-API
* @brief This function resumes a task that has been stopped by the function
*        sys_TaskStop().
*
* @param[in]  taskHandle     Transfer of the task handle that has been returned
*                            by the function sys_TaskCreate().
*
* @retval #M_E_OK      Task has been successfully resumed.
* @retval #M_E_PARM    Invalid parameter
* @retval #M_E_FAILED  Task already running.
*
* @see sys_TaskCreate()
* @see sys_TaskStop()
*/
SINT32 sys_TaskResume(SYS_TASK_HANDLE taskHandle);

/**
 * @ingroup SYS-TASK-API
* @brief This function attaches a task that has been created by the function
*        sys_TaskCreate() to a MIO event.
*
* The specified task is polled every time the specified event (`EventNb`) occurs.
*
* For each task handle (`taskHandle`) any number of channels and event processing
* can be integrated, however always only one event per channel (`ChanNb`).
*
* @note If an additional event with the same task handle is signaled for a channel
*       that is already integrated, then the old event processing will be overwritten.
*
* @param[in]  taskHandle   Transfer of the task handle that has been returned
*                          by the function sys_TaskCreate().
* @param[in]  DrvId        The driver ID is determined by the function mio_GetDrv().
* @param[in]  ChanNb       The number of the channel on which the function
*                          is executed.<br>
*                          The event handler is called, when, on the specified
*                          channel, one of the events transferred in the
*                          parameter `EventNb` occurs.<br>
*                          At `Chan = 0` the function is executed on all channels.
* @param[in]  EventNb      Transfer of the event for which event processing is
*                          to be called.<br>
*                          The events (e.g. #MIO_EV_VALUE) depend on the module
*                          and the channel. Combinations are possible.
*
* @retval #M_E_OK          Event has been successfully attached
* @retval #M_E_PARM        Invalid parameter
* @retval #M_E_FAILED      Event could not be attached
*
* @see sys_TaskDetachEvent()
*/
SINT32 sys_TaskAttachEvent(SYS_TASK_HANDLE taskHandle, void* DrvId, UINT32 ChanNb, UINT32 EventNb);

/**
 * @ingroup SYS-TASK-API
* @brief This function attaches a task that has been created by the function
*        sys_TaskCreate() to an MIO error event.
*
* The specified task is polled every time the specified error (`ErrorNb`) occurs.
*
* @note Only one error handling can be integrated per channel (`ChanNb`).
*       If an error handling is already installed, it will be overwritten by
*       the new one.
*
* @param[in]  taskHandle   Transfer of the task handle that has been returned
*                          by the function sys_TaskCreate().
* @param[in]  DrvId        The driver ID is determined by the function mio_GetDrv().
* @param[in]  ChanNb       The number of the channel on which the function
*                          is executed.<br>
*                          Error handling is called up when one of the bit-coded
*                          errors transferred in the parameter `ErrorNb` occurs
*                          on the indicated channel.<br>
*                          When the value is set to 0, the function is executed
*                          on all channels.
* @param[in]  ErrorNb      Transfer of the error code for which the interrupt
*                          service routine is to be called (combinations are possible).<br>
*                          See header file mio.h<br>
*                          <b>Note:</b> Even if the parameter `ErrorNb` is
*                          transferred with `0xffffffff`, the driver only evaluates
*                          the flags supported by the driver.
*
* @retval #M_E_OK          Error has been successfully attached
* @retval #M_E_PARM        Invalid parameter
* @retval #M_E_FAILED      Error could not be attached
*
* @see sys_TaskDetachError()
*/
SINT32 sys_TaskAttachError(SYS_TASK_HANDLE taskHandle, void* DrvId, UINT32 ChanNb, UINT32 ErrorNb);

/**
 * @ingroup SYS-TASK-API
* @brief An event handler that has been attached by the function sys_TaskAttachEvent()
*        can be removed by the function sys_TaskDetachEvent().
*
* This function is the counterpart of the function sys_TaskAttachEvent().
* When the function sys_TaskDelete() is invoked, all existing event handlers are
* removed automatically.
*
* @param[in]  taskHandle   Transfer of the task handle that has been returned
*                          by the function sys_TaskCreate().
* @param[in]  DrvId        The driver ID is determined by the function mio_GetDrv().
* @param[in]  ChanNb       The number of the channel on which the function is executed.
* @param[in]  EventNb      The parameter `EventNb` must have the same value as used in the
*                          function sys_TaskAttachEvent(). It depends on the driver if this
*                          parameter is checked or not.
*
* @retval #M_E_OK          Event has been successfully detached
* @retval #M_E_PARM        Invalid parameter
* @retval #M_E_FAILED      Event could not be detached
*
* @see sys_TaskAttachEvent()
*/
SINT32 sys_TaskDetachEvent(SYS_TASK_HANDLE taskHandle, void* DrvId, UINT32 ChanNb, UINT32 EventNb);

/**
 * @ingroup SYS-TASK-API
* @brief An error handling that has been attached by the function sys_TaskAttachError()
*        can be removed using the function sys_TaskDetachError().
*
* This function is the counterpart of the function sys_TaskAttachError().
* If the function sys_TaskDelete() is called, all existing error handlers
* are automatically detached.
*
* @param[in]  taskHandle   Transfer of the task handle that has been returned
*                          by the function sys_TaskCreate().
* @param[in]  DrvId        The driver ID is determined by the function mio_GetDrv().
* @param[in]  ChanNb       The number of the channel on which the function is executed.
* @param[in]  ErrorNb      The parameter `ErrorNb` must have the same value as used in the
*                          function sys_TaskAttachError(). It depends on the driver if this
*                          parameter is checked or not.
*
* @retval #M_E_OK          Error has been successfully detached
* @retval #M_E_PARM        Invalid parameter
* @retval #M_E_FAILED      Error could not be detached
*
* @see sys_TaskAttachError()
*/
SINT32 sys_TaskDetachError(SYS_TASK_HANDLE taskHandle, void* DrvId, UINT32 ChanNb, UINT32 ErrorNb);

/**
 * @ingroup SYS-TASK-API
* @brief This function deletes a task that has been created by the function
*        sys_TaskCreate().
*
* If the task is triggered by sync, aux, event or error, the corresponding
* session is stopped.
* If a watchdog was configured for this task, the watchdog is deleted.
*
* @param[in]  taskHandle    Transfer of the task handle that has been returned
*                           by the function sys_TaskCreate().
*
* @retval #M_E_OK      Task has been successfully deleted
* @retval #M_E_FAILED  Task could not be deleted
*
*/
SINT32 sys_TaskDelete(SYS_TASK_HANDLE taskHandle);

/**
* @ingroup SYS-TASK-API
* @brief This function gets information about a task that has been created by
*        the function sys_TaskCreate().
*
* @param[in]  taskHandle    Transfer of the task handle that has been returned
*                           by the function sys_TaskCreate().
* @param[out]  pTaskInfo    Pointer to task information.
*
* @retval #M_E_OK             Getting task information successfully done
* @retval #M_E_PARM           Invalid parameter
*
*/
SINT32 sys_TaskGetInfo(SYS_TASK_HANDLE taskHandle, SYS_TASK_INFO *pTaskInfo);

/*--- Definition of Variables ---*/

/* Defined in MCore */
EXTERN BOOL8  m_RealTarget;             /**< TRUE on M1, FALSE on PC */
EXTERN UINT32 m_RestartCount;           /**< Number of restarts since reset */
EXTERN UINT32 m_CpuClockRate;           /**< CPU clock rate in MHz */
EXTERN BOOL8  m_PccProgEnable;          /**< TRUE if no write protection */
EXTERN SINT32 m_DebugMode;              /**< DebugMode from MConfig.ini */
EXTERN SINT32 m_BootMode;               /**< BootMode from MConfig.ini */
EXTERN UINT32 m_MyInetAddr;             /**< 1st IP-Address (Intel format) */
EXTERN UINT32 m_MyInetAddr2;            /**< 2nd IP-Address (Intel format) */
EXTERN UINT32 m_NvRamStart;             /**< Start of NV-Ram file system */
EXTERN UINT32 m_NvRamSize;              /**< Size NV-Ram file system */

EXTERN CHAR   m_MCoreVersion[M_VERSTRGLEN]; /**< Version string of MCore */
EXTERN BOOT_INFO_VXW m_BootParams;      /**< Boot parameters */

/**
 * @brief CPU type
 * @see #M_80486
 * @see #M_PENTIUM
 * @see #M_PENTIUM3
 * @see #M_PENTIUM4
 */
EXTERN SINT32 sysProcessor;

/* Defined in MSys */
EXTERN CHAR   *sys_MemTop;              /**< Top of physical memory (DRAM) */
EXTERN BOOL8  sys_AppDevOn;             /**< Applications development allowed */
EXTERN BOOL8  sys_RebootOnExc;          /**< Reboot on exception */
EXTERN BOOL8  sys_SysDevOn;             /**< System development allowed */
EXTERN BOOL8  sys_CpuTimeInfo;          /**< CPU time measurement ON */
EXTERN BOOL8  sys_PccPresent;           /**< Device /pcc0 present */
EXTERN BOOL8  sys_FlashPresent;         /**< Device /flash0 present */
EXTERN BOOL8  sys_WindViewOn;           /**< WindView is in use */
EXTERN BOOL8  sys_BootError;            /**< System Boot Error if TRUE */
EXTERN SINT32 sys_Compatibility;        /**< M-Base version compatibility */
EXTERN UINT32 sys_CpuHwVers;            /**< CPU hardware version */
EXTERN UINT32 sys_CpuType;              /**< CPU type code \ref MIO_T_ */
EXTERN UINT32 sys_CpuVariant;           /**< CPU variant code MIO_V_ */
EXTERN UINT32 sys_CpuFamily;            /**< CPU family code */
EXTERN UINT32 sys_TotalMemory;          /**< Total available Memory */
EXTERN CHAR   *sys_MSysVersion;         /**< Pointer to MSys version string */

EXTERN CHAR   sys_LogFileName[M_PATHLEN + 1];    /**< Path to logfile */
EXTERN CHAR   sys_LogBackupPath[M_PATHLEN + 1];  /**< Path to logfile backup */

EXTERN SYS_VERSION sys_MSysVers;        /**< MSys integer version codes */
EXTERN SYS_VERSION sys_MCoreVers;       /**< MCore integer version codes */
EXTERN SYS_VERSION sys_MBios;           /**< MBios integer version codes */
EXTERN SYS_VERSION sys_MBoot;           /**< MBoot integer version codes */

/**
 * @ingroup SYS-MCORE
 * @deprecated Use sys_Clock()
 *
 * @brief With this function, the seconds elapsed since 1.1.1970 can be determined.
 *
 * This function uses RTC.
 *
 * @note This functions does not convert time zones. Seconds are corresponding
 *       to local time.<br>
 *       In case of ISR the function m_TimeRtc() returns 0, because determining
 *       RTC is not possible.
 *
 * @retval !0   Seconds since 1.1.1970
 * @retval 0    Error
 *
 */
DEPRECATED(UINT32 m_TimeRtc(VOID));

/**
 * @ingroup SYS-MCORE
 * @deprecated Use sys_Clock()
 *
 * @brief With this function, the seconds and nanoseconds elapsed since
 *        1.1.1970 can be determined.
 *
 * This function uses RTC. The necessary structure "timespec" is defined in time.h.
 *
 * @note The function m_TimeRtcNano() is available since M-Base 3.70.<br>
 *       Reading of nanoseconds is possible on modules MC2xx and MH2xx.
 *       Nanoseconds are zero on modules MPC2xx, MX2xx and WT.<br>
 *       This functions does not convert time zones. Seconds and nanoseconds
 *       are corresponding to local time.
 *
 * @param [out] tm  Structure, containing seconds and nanoseconds since 1.1.1970
 *
 * <b>Example</b>
 * @snippet doc_sys_msys_e.c m_TimeRtcNano
 */
DEPRECATED(VOID m_TimeRtcNano(struct timespec *tm));

/**
 * @ingroup SYS-MCORE
 * @deprecated Use sys_GetLocalTime()
 *
 * @brief With this function, the actual date and time can be determined from
 *        RTC-Chip.
 *
 *  The necessary structure "tm" is defined in time.h. The elements tm_yday and
 *  tm_isdst of that structure are not in use and their values are always set to
 *  -1.
 *
 * @note In case of ISR the function m_ReadRtc() returns ERROR and the RTC is
 *       not determined.
 *
 * @param [out] pDateTime  Structure, containing actual date and time.
 *
 * @retval #OK
 * @retval #ERROR <br>
 *
 * <b>Example</b>
 * @snippet doc_sys_msys_e.c m_ReadRtc
 */
DEPRECATED(SINT32 m_ReadRtc(struct tm *pDateTime));

/**
 * @ingroup SYS-MCORE
 * @deprecated Use sys_GetLocalTime()
 *
 * @brief With this function, the actual date, time and nanoseconds can be
 *        determined from RTC-Chip.
 *
 *  The necessary structure "tm" is defined in time.h. The elements tm_yday and
 *  tm_isdst of that structure are not in use and their values are always set to
 *  -1.
 *
 * @note The function m_TimeRtcNano() is available since M-Base 3.70.<br>
 *       Reading of nanoseconds is possible on modules MC2xx and MH2xx.
 *       Nanoseconds are zero on modules MPC2xx, MX2xx and WT.
 *
 * @param [out] pDateTime  Structure, containing actual date and time.
 * @param [out] nsec       Nanoseconds.
 *
 * @retval #OK
 * @retval #ERROR <br>
 *
 * <b>Example</b>
 * @snippet doc_sys_msys_e.c m_ReadRtcNano
 */
DEPRECATED(SINT32 m_ReadRtcNano(struct tm *pDateTime, UINT32 *nsec));

/**
 * @ingroup SYS-MCORE
 * @deprecated Use sys_SetLocalTime()
 *
 * @brief With this function, the date and time on the RTC-Chip can be set.
 *
 *  The necessary structure "tm" is defined in time.h. The elements tm_yday and
 *  tm_isdst of that structure are not in use and do not have to be set.
 *
 * @note Depending on the used operating system, the following behaviors can occur:
 *       - If date earlier than 1.1.2000 is set, it may happen that 100 years
 *         are added to this date.
 *       - If a date later than 31.12.2099 is set,  it may happen that 100 years
 *         are subtracted from this date.
 * @note This is not a mistake in the program!<br>
 *       In case of ISR the function m_WriteRtc() returns ERROR and the RTC is not set.
 *
 * @param [in] pDateTime  Structure, containing date and time to be set.
 *
 * @retval #OK
 * @retval #ERROR <br>
 *
 * <b>Example</b>
 * @snippet doc_sys_msys_e.c m_WriteRtc
 */
DEPRECATED(SINT32 m_WriteRtc(struct tm *pDateTime));

/**
 * @ingroup SYS-MCORE
 * @deprecated Use sys_SetLocalTime()
 *
 * @brief With this function, the date, time and nanoseconds on the RTC-Chip
 *        can be set.
 *
 *  The necessary structure "tm" is defined in time.h. The elements tm_yday and
 *  tm_isdst of that structure are not in use and do not have to be set.
 *
 * @note The function m_WriteRtcNano() is available since M-Base 3.70.<br>
 *       Writing of nanoseconds is possible on modules MC2xx and MH2xx.
 *       Nanoseconds are ignored on modules MPC2xx, MX2xx and WT.
 *
 * @param [in]  pDateTime  Structure, containing date and time to be set.
 * @param [in]  nsec       Nanoseconds.
 *
 * @retval #OK
 * @retval #ERROR <br>
 *
 * <b>Example</b>
 * @snippet doc_sys_msys_e.c m_WriteRtcNano
 */
DEPRECATED(SINT32 m_WriteRtcNano(struct tm *pDateTime, UINT32 *nsec));

/**
 * @brief Name of active VHD user
 * @deprecated Not supported anymore (V4.00)
 */
DEPRECATED(EXTERN CHAR sys_CurrentVisUser[M_UNAMELEN_A]);

/**
 * @brief Directory (SysDir) System
 * @deprecated Use sys_GetDir()
 */
DEPRECATED(EXTERN CHAR m_DirSys[M_PATHLEN + 1]);

/**
 * @brief Directory (SysDir) Drivers
 * @deprecated Use sys_GetDir()
 */
DEPRECATED(EXTERN CHAR m_DirDrv[M_PATHLEN + 1]);

/**
 * @brief Directory (SysDir) Services
 * @deprecated Use sys_GetDir()
 */
DEPRECATED(EXTERN CHAR m_DirSrv[M_PATHLEN + 1]);

/**
 * @brief Directory (SysDir) Applications
 * @deprecated Use sys_GetDir()
 */
DEPRECATED(EXTERN CHAR m_DirApp[M_PATHLEN + 1]);

/**
 * @brief Directory (SysDir) NonVolatile
 * @deprecated Use sys_GetDir()
 */
DEPRECATED(EXTERN CHAR m_DirNVol[M_PATHLEN + 1]);

/**
 * @brief Directory (SysDir) Temporary
 * @deprecated Use sys_GetDir()
 */
DEPRECATED(EXTERN CHAR m_DirTmp[M_PATHLEN + 1]);

/**
 * @brief Directory (SysDir) Keys
 * @deprecated Use sys_GetDir()
 */
DEPRECATED(EXTERN CHAR m_DirKeys[M_PATHLEN + 1]);

/**
 * @brief Directory (SysDir) Keys Backup
 * @deprecated Use sys_GetDir()
 */
DEPRECATED(EXTERN CHAR m_DirKeys2[M_PATHLEN + 1]);

/** @} end of SYS-GENERAL */

#endif                                  /* __LINUX */

#endif                                  /* __GNUC__ */

#endif                                  /* _ASMLANGUAGE */

#ifdef __cplusplus
}
#endif

#endif                                  /* MSYS_E__H */
