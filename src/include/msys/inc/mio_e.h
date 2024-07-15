/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     mio_e.h
* @author   Kuen
* @brief    This file contains all definitions and declarations exported by
*           the IO-Driver Handler for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef MIO_E__H
#define MIO_E__H


#ifdef __cplusplus
extern  "C"
{
#endif

#ifndef _ASMLANGUAGE

#include <semLib.h>

#include <lst_e.h>
#include <msys_e.h>

#endif                                  /* _ASMLANGUAGE */

#include <mio.h>

/**
 * @addtogroup MIO-DEF
 * @{
 */

/**
 * @name Defines
 * @{
 */

#define MIO_BUSID               0x80000000   /**< Read ID-Register from backplane */
#define MIO_CARDSIGN            0xa5     /**< Signature in ID-Register */
#define MIO_DRVSIGN             0x7664314D   /**< Signature in device driver */
#define MIO_PIDRVID_SIGNATURE   0xFF00FF00

/**
 * @name Possible values for parameter flags of functions mio_PiGetDrvByHandle and mio_PiGetDrv
 * @{
 */

#define MIO_PI_FLAGS_NONE   0    /**< No flags used */
/** @} */

/**
 * @name Possible values for MIO_DRV.ExtVersion
 * @{
 */

#define MIO_EXTVER_1    1
#define MIO_EXTVER_2    2
#define MIO_EXTVER_3    3
#define MIO_EXTVER_4    4
/** @} */

/**
 * @name Possible type of Event Interrupts; mio_EnableEvent(), mio_DisableEvent()
 * @{
 */

#define MIO_EV_VALUE        0x00000001   /**< Event on change of value */
#define MIO_EV_REFERENCE    0x00000002   /**< Event at reference point */
#define MIO_EV_RESET        0x00000004   /**< Event home done */
#define MIO_EV_LATCHSTRB    0x00000010   /**< Latch into strobe register done */
#define MIO_EV_LATCHREF     0x00000020   /**< Latch into reference register done */
#define MIO_EV_LATCHSTRBOV  0x00000040   /**< Latch strobe overwritten */
#define MIO_EV_LATCHREFLOS  0x00000080   /**< Latch reference register lost */
#define MIO_EV_DATARDY      0x00000100   /**< New data available */
#define MIO_EV_SYSTEM       0x0000ffff   /**< Generic events */
#define MIO_EV_USER         0xffff0000   /**< Driver specific events */
/** @} */

/**
 * @name Possible driver specific event interrupts for PCFS
 * @{
 */

#define MIO_EV_APP1 0x00010000   /**< First application defined event */
#define MIO_EV_APP2 0x00020000   /**< Second application defined event */
/** @} */

/**
 * @name Possible driver specific events for AI208/SI module
 * @{
 */

#define MIO_EV_POSRANGE 0x00400000   /**< Value above maximum */
#define MIO_EV_NEGRANGE 0x00800000   /**< Value below minimum */
/** @} */

/**
 * @name GMP232 / GSP274 specific event flags. There values match the error constants (MIO_E_).
 * @{
 */

#define MIO_EV_U_MIN            0x00010000   /**< Chan 0, 1-3 */
#define MIO_EV_U_MAX            0x00020000   /**< Chan 0, 1-3 */
#define MIO_EV_HARMONICS        0x00040000   /**< Chan 0, 1-6 */
#define MIO_EV_SCOPEREADY       0x00080000   /**< Chan 0, Scope ready event (common) */
#define MIO_EV_I_MAX            0x00100000   /**< Chan 0, 4-6 */
#define MIO_EV_SYNCSCOPEREADY   0x00200000   /**< Scope ready event (channel specific) */
#define MIO_EV_ALARMSCOPEREADY  0x00400000   /**< Scope ready event (common) */
#define MIO_EV_FEEDBACK         0x00800000   /**< Feedback event */
/** @} */

/**
 * @name GMP232X specific event flags. None of them are shared with the standard GMP232.
 * @{
 */

#define MIO_EV_QU_PCC1      0x00000002   /**< QU PCC1 */
#define MIO_EV_QU_PCC2      0x00000004   /**< QU PCC2 */
#define MIO_EV_ANYZERO      0x00000010   /**< Any voltage zero crossing */
#define MIO_EV_P1ZERO       0x00000020   /**< Phase 1 voltage positive zero crossing */
#define MIO_EV_SCOPE        0x00000040   /**< Scope event */
#define MIO_EV_HEARTBEAT    0x00000080   /**< Heartbeat (module health check) */
#define MIO_EV_REV_POWER1   0x00000100   /**< Reverse power 1 */
#define MIO_EV_REV_POWER2   0x00000200   /**< Reverse power 2 */
#define MIO_EV_HARM_U       0x00008000   /**< Voltage harmonics */
#define MIO_EV_U_ASYM1      0x00010000   /**< Voltage asymmetry 1 */
#define MIO_EV_U_ASYM2      0x00020000   /**< Voltage asymmetry 2 */
#define MIO_EV_THD_U        0x00040000   /**< Voltage THD */
#define MIO_EV_I_ASYM1      0x00080000   /**< Current asymmetry 1 */
#define MIO_EV_I_ASYM2      0x00100000   /**< Current asymmetry 2 */
#define MIO_EV_HARM_I       0x00200000   /**< Current harmonics */
#define MIO_EV_VECTORJUMP1  0x00400000   /**< Vector jump 1 */
#define MIO_EV_VECTORJUMP2  0x00800000   /**< Vector jump 2 */
#define MIO_EV_TDD_I        0x01000000   /**< TDD */
#define MIO_EV_DIRCURRENT1  0x02000000   /**< Directional overcurrent 1 */
#define MIO_EV_DIRCURRENT2  0x04000000   /**< Directional overcurrent 2 */
#define MIO_EV_ROCOF        0x08000000   /**< ROCOF */
#define MIO_EV_MAX_POWER1   0x10000000   /**< Maximal power 1 */
#define MIO_EV_MAX_POWER2   0x20000000   /**< Maximal power 2 */
#define MIO_EV_MANUAL_REL1  0x40000000   /**< State of manual relay 1 */
#define MIO_EV_MANUAL_REL2  0x80000000   /**< State of manual relay 2 */
/** @} */

/**
 * @name Possible driver specific events for dio2xx module
 * @{
 */

#define MIO_EV_OVERFLOW 0x02000000   /**< Value overflow */
/** @} */

/**
 * @name Possible driver specific events for gio212, aio216 and aio208 modules
 * @{
 */

#define MIO_EV_REFERENCE2   0x00010000   /**< Second reverence value reached */
#define MIO_EV_LOWERLIMIT   0x00020000   /**< Lower limit reached */
#define MIO_EV_UPPERLIMIT   0x00040000   /**< Upper limit reached */
#define MIO_EV_CNTNEWVALUE  0x00200000   /**< New counter value */
/** @} */

/**
 * @name Possible driver specific events for sct202 module
 * @{
 */

#define MIO_EV_OVERSPEED    0x00010000   /**< Chan 1-4 */
#define MIO_EV_STAGNATION   0x00020000   /**< Chan 1-4 */
/** @} */

/**
 * @name Possible type of Sync-Interrupts
 * @{
 */

#define MIO_SYNC_IN     0x01     /**< Interrupt at sync IN */
#define MIO_SYNC_OUT    0x02     /**< Interrupt at sync OUT */
#define MIO_SYNC_EXTINT 0x20000000   /**< External sync interrupt IN */
/** @} */

/**
 * @name Possible type of IO-Interrupts
 * @{
 */

#define MIO_EVENT_INT   0x01     /**< Is event interrupt */
#define MIO_ERROR_INT   0x02     /**< Is error interrupt */
/** @} */

/**
 * @name Possible origin FLAGS for a call of mio_DisableCard
 * @{
 */

#define MIO_ORIGIN_INIT         0x0001   /**< Driver initialization */
#define MIO_ORIGIN_SIMINIT      0x0002   /**< Virtual mode initialization */
#define MIO_ORIGIN_BADSTATION   0x0004   /**< Lost substation */
/** @} */

/**
 * @name List of Driver Functions
 * @{
 */

#define MIO_F_INIT              0
#define MIO_F_SIGNATURE         0
#define MIO_F_DEINIT            1
#define MIO_F_RESET             2
#define MIO_F_SETCHANMODE       3
#define MIO_F_GETCHANMODE       4
#define MIO_F_SETCARDMODE       5
#define MIO_F_GETCARDMODE       6
#define MIO_F_SETVALUE          7
#define MIO_F_GETVALUE          8
#define MIO_F_SETVALUES         9
#define MIO_F_GETVALUES         10
#define MIO_F_SETSELECT         11
#define MIO_F_GETSELECT         12
#define MIO_F_GETERROR          13
#define MIO_F_GETNEXTERR        14
#define MIO_F_ATTACHEVENT       15
#define MIO_F_DETACHEVENT       16
#define MIO_F_ATTACHERROR       17
#define MIO_F_DETACHERROR       18
#define MIO_F_GETCARDINF        19
#define MIO_F_GETCHANINF        20
#define MIO_F_SIMULATE          21   /**< @deprecated Deprecated since MSys 4.00 */
#define MIO_F_PROCEVENT         22
#define MIO_F_PROCERROR         23
#define MIO_F_DOCMD             24
#define MIO_F_GETPROCIMGFUNCS   25
#define MIO_F_SETPACKEDVALUES   26
#define MIO_F_GETPACKEDVALUES   27
#define MIO_F_RESETALLINT       28
#define MIO_F_INITVIRTUAL       29
#define MIO_F_GETBLK            30
#define MIO_F_SETBLK            31
#define MIO_F_SIGNATURE2        32
#define MIO_F_GETCHANRANGE      33
/** @} */

/**
 * @name Function table configuration
 * @{
 */

#define MIO_MAXENTRIES  26  /**< Size of function table up to MSys V1.07 */
#define MIO_MAXENTRIES2 32  /**< Size of function table after MSys V1.07 */
/** @} */

/**
 * @name Bit coded hardware variants (stored in element HwVariant of structure MIO_IDREG2)
 * @{
 */

#define MIO_HV_NONE             0x00     /**< No special hardware variant used */
#define MIO_HV_COLDCLIMATE      0x01     /**< Hardware might be used in cold climate */
#define MIO_HV_EXTPOWERSUPPLY   0x02     /**< 230V power supply */
#define MIO_HV_COMPACT          0x04     /**< Module is part of a compact PLC */
/** @} */

#ifndef _ASMLANGUAGE

/*--- Structures ---*/

/**
 * Data of an Application ISR
 */
typedef struct
{
    UINT32  IntId;                      /**< ID for application ISR */
    UINT32  Source;                     /**< Channel of interest */
    UINT32  AppEvent;                   /**< Mask for application interrupt */
    UINT32  HwEvent;                    /**< Mask for hardware interrupt */
    UINT32  LastHwEvent;                /**< Mask for last hardware interrupt */
    UINT32  UserParam;                  /**< User parameter passed through */
    VOID (*AppIsr) ();                  /**< Pointer to application ISR */
} MIO_ISR;

/**
 * Extended driver data 1
 */
typedef struct
{
    SINT32  Power;                      /**< Power consumption/production in mW */
    CHAR   *DrvName;                    /**< Name of driver file */
} MIO_EXTDRV;

/**
 * Extended driver data 2
 */
typedef struct
{
    SINT32  Power;                      /**< Power consumption/production in mW */
    CHAR   *DrvName;                    /**< Name of driver file */
    /* NOTE up to here must be the same as MIO_EXTDRV, below here must be the same as in
       MIO_EXTCDINF */
    SINT32  Current_5V;                 /**< 5V current sink/source in mA */
    SINT32  Current_P15V;               /**< +15V current sink/source in mA */
    SINT32  Current_M15V;               /**< -15V current sink/source in mA */
    SINT32  Space;                      /**< Used in MIO_EXTCDINF */
    BOOL8   RedundantRead;              /**< Redundant read of data if TRUE */
    BOOL8   WriteVerify;                /**< Write verify of data if TRUE */
    BOOL8   BusCheck;                   /**< BUSCHECK supported if TRUE */
    BOOL8   AliveCheck;                 /**< ALIVECHECK supported if TRUE */
} MIO_EXTDRV2;

/**
 * Extended driver data 3
 */
typedef struct
{
    SINT32  Power;                      /**< Power consumption/production in mW */
    CHAR   *DrvName;                    /**< Name of driver file */
    SINT32  Current_5V;                 /**< 5V current sink/source in mA */
    SINT32  Current_P15V;               /**< +15V current sink/source in mA */
    SINT32  Current_M15V;               /**< -15V current sink/source in mA */
    SINT32  Space;                      /**< Used in MIO_EXTCDINF */
    BOOL8   RedundantRead;              /**< Redundant read of data if TRUE */
    BOOL8   WriteVerify;                /**< Write verify of data if TRUE */
    BOOL8   BusCheck;                   /**< BUSCHECK supported if TRUE */
    BOOL8   AliveCheck;                 /**< ALIVECHECK supported if TRUE */
    /* NOTE up to here must be the same as MIO_EXTDRV2! */
    SINT32  BusType;                    /**< Fieldbus only - type of master */
    UINT8   NetNb;                      /**< Fieldbus only - net number */
    UINT8   StationNb;                  /**< Fieldbus only - number of station */
    UINT16  Spare2;                     /**< Align it to 32 bit */
    UINT32  Spare3[5];                  /**< Some space for the future */
} MIO_EXTDRV3;

/**
 * Enumeration for net modes
 */
typedef enum MIO_NETMODE
{
    MIO_NETMODE_UNKNOWN = 0,
    MIO_NETMODE_MASTER = 1,
    MIO_NETMODE_SLAVE = 2,
    MIO_NETMODE_MASTER_SLAVE = 3,
    MIO_NETMODE_LOGICAL = 4
} MIO_NETMODE;

/**
 * Extended driver data 4
 */
typedef struct
{
    SINT32  Power;                      /**< Power consumption/production in mW */
    CHAR   *DrvName;                    /**< Name of driver file */
    SINT32  Current_5V;                 /**< 5V current sink/source in mA */
    SINT32  Current_P15V;               /**< +15V current sink/source in mA */
    SINT32  Current_M15V;               /**< -15V current sink/source in mA */
    SINT32  Space;                      /**< Used in MIO_EXTCDINF */
    BOOL8   RedundantRead;              /**< Redundant read of data if TRUE */
    BOOL8   WriteVerify;                /**< Write verify of data if TRUE */
    BOOL8   BusCheck;                   /**< BUSCHECK supported if TRUE */
    BOOL8   AliveCheck;                 /**< ALIVECHECK supported if TRUE */
    SINT32  BusType;                    /**< Fieldbus only - type of master */
    UINT8   NetNb;                      /**< Fieldbus only - net number */
    UINT8   StationNb;                  /**< Fieldbus only - number of station */
    /* NOTE up to here must be the same as MIO_EXTDRV3! */
    UINT8   NetMode;                    /**< Fieldbus only - MIO_NETMODE */
    BOOL8   FirmBackup;                 /**< Firmware can be recovered */
    UINT32  Spare3[5];                  /**< Some space for the future */
} MIO_EXTDRV4;

/**
 * Minimum data for each IO module
 */
typedef struct
{
    SINT32  CardNb;                     /**< Logical number of IO module */
    SINT32  Mode;                       /**< Mode of IO module: #MIO_REAL, #MIO_VIRTUAL, ... */
    SINT32  State;                      /**< Status of driver: #RES_S_RUN, ... */
    UINT32  EventIsrLen;                /**< Number attached event ISR's */
    MIO_ISR *EventIsr;                  /**< List of event ISR's */
    UINT32  ErrorIsrLen;                /**< Number attached error ISR's */
    MIO_ISR *ErrorIsr;                  /**< List of error ISR's */
    SINT32  Type;                       /**< Type of IO module (@ref MIO_T_) */
    SINT32  Variant;                    /**< Variant of IO module */
    SINT32  Version;                    /**< Hardware version of IO module */
    SINT32  Category;                   /**< Category of IO module (@ref MIO_CATEG_) */
    SINT32  Flags;                      /**< Capabilities of IO module */
    UINT32  MaxChan;                    /**< Maximum channels on IO module */
    SINT32  SlotNb;                     /**< Physical slot number (1-255) */
    SINT16  PreSlots;                   /**< Slots occupied before */
    SINT16  PostSlots;                  /**< Slots occupied after */
    UINT32  Settings;                   /**< Enable module dependent functionality */
    CHAR   *Name;                       /**< Name of IO module */
    CHAR   *Info;                       /**< Info to IO module */
    SINT32 (**EntryTable) ();           /**< Table of driver functions */
    UINT32  ExtVersion;                 /**< Extended driver version */
    MIO_EXTDRV *pExt;                   /**< Pointer to extended driver data */
} MIO_DRV;

/**
 * Range information of channel
 */
typedef struct
{
    UINT32  DispMode;                   /**< Display Mode: UFB_DISP_MODE (default: UFB_DISP_MODE_RAW_DEZ) */
    UINT32  Range;                      /**< Range code of channel (#MIO_R_NONE, #MIO_R16_20MA, ...) */
    REAL64  Scale;                      /**< Scaling factor (default: 1.0) */
    REAL64  Offset;                     /**< Offset (default: 0.0) */
    REAL32  MeasuringMin;               /**< Measuring range minimum (for example AI208 = -25mA) */
    REAL32  MeasuringMax;               /**< Measuring range maximum (for example AI208 = +25mA) */
    REAL32  ConfigMin;                  /**< Scaled minimum value (for example AI208 = +4mA) */
    REAL32  ConfigMax;                  /**< Scaled maximum value (for example AI208 = +20mA) */
    SINT64  RawMin;                     /**< Raw minimum value (for example AI208 = 0) */
    SINT64  RawMax;                     /**< Raw maximum value (for example AI208 = 65535) */
    UINT32  len;                        /**< Size of raw value in bytes (normally 4) */
    UINT32  Format;                     /**< SVI format of value (normally #SVI_F_SINT32) */
    UINT32  BaseSiUnit;                 /**< SI-Unit: UFB_SIUNIT (default: UFB_SIUNIT_NONE) */
    CHAR    BaseUnitStr[12];            /**< Physical unit base optional text (for example "V", "RPM", "A" ATTENTION: NOT "mA") */
    SINT32  BasePrefixFactor;           /**< Exponent to the base 10 of the unit (for example -3 for mA) */
    UINT16  ExtChFlags;                 /**< Extended channel flags (MIO_EXTFLG_*) */
    UINT16  Spare[31];                  /**< Spare for future extension */
} MIO_CHAN_RANGE;

/**
 * @internal
 * Data for process image in PLC
 */
typedef struct
{
    VOID   *DrvId;                      /**< Pointer to #MIO_DRV */
    UINT32 *pCardImageNew;              /**< Image with new values */
    UINT32 *pCardImageRef;              /**< Copy of above */
    UINT32  ImageProcFlags;             /**< Image flags, see MIO_xxxIMG_* */
    VOID   *pInfoData;
    /**< Additional information:
     *   - When containing CAN data, it points to the CANOBJDESCHEADER in
     *     the *.M file's configuration data.
     *   - When containing Profibus data, it points to the PBNETHEADER in
     *     the *.M file's configuration data.
     */
    UINT8  *pChannels;                  /**< Array with selected channels */
} MIO_CARD_ITEM;

/**
 * @internal
 * Structure for mio_GetProcImgFuncs
 */
typedef struct
{
    VOIDFUNCPTR pfnGetProcImg;          /**< Image read function */
    VOIDFUNCPTR pfnSetProcImg;          /**< Image write function */
    VOIDFUNCPTR pfnInitProcImg;         /**< Image init Function */
    UINT32  ImageProcFlags;             /**< Flags for structure #MIO_CARD_ITEM */
} MIO_IMGFNDATA;

/**
 * Structure for IO-module ID-register first block from byte 0 to byte 19
 */
typedef struct
{
    UINT8   ModVerType:3;               /**< Version Type code: #MIO_VER_RELEASE, ... */
    UINT8   Spare1:3;                   /**< Filled with zero */
    UINT8   Reserved:2;                 /**< Must be zero */
    UINT8   Signature;                  /**< Must be #MIO_CARDSIGN */
    UINT8   Checksum;                   /**< Checksum over ID-Register */
    UINT8   ModType;                    /**< Type of IO module (@ref MIO_T_) */
    UINT8   ModVariant;                 /**< Variant of IO module */
    UINT8   ModVersion;                 /**< Hardware version of IO module */
    UINT8   DrvVersion;                 /**< Required driver version */
    UINT8   Attribute;                  /**< Attributes for internal use */
    UINT16  ProdDay:5;                  /**< Production: Day [1,31] */
    UINT16  ProdMonth:4;                /**< Production: Month [1,12] */
    UINT16  ProdYear:7;                 /**< Production: Year since 1970 */
    CHAR    ProdNb[MIO_PRODNBLEN];      /**< Production: Serial number 10-digits */
} MIO_IDREG;

/**
 * Structure for IO-module ID-register second block from byte 20 to 49.<br>
 * Starting in MSys V1.10
 */
typedef struct __attribute__ ((__packed__))
{
    UINT8   Version;                    /**< Byte 20 - Block format, must be 1 for now */
    UINT8   Checksum;                   /**< Byte 21 - Checksum over this block */
    UINT16  AssemblyCode;               /**< Byte 22 - Function code lower part */
    UINT16  Internal[2];                /**< Byte 24 - For internal use only */
    UINT8   HwVariant;                  /**< Byte 28 - Bit coded hardware variant (#MIO_HV_NONE, ...) */
    MIO_VERS PackageVers;               /**< Byte 29 - Package version (since MSys 3.90) */
    UINT32  PartNumber;                 /**< Byte 33 - Part number (since MSys 3.90) */
    UINT8   Core[9];                    /**< Byte 37 - Reserved for MCore internal usage (since MSys 3.95) */
    UINT8   Spare2[4];                  /**< Byte 46 - Fill it up to 30, zero for now */
} MIO_IDREG2;

/**
 * Structure for error data on ACR222
 */
typedef struct
{
    UINT16  Index;                      /**< Index to object with error */
    UINT16  SubIndex;                   /**< Subindex to object with error */
    UINT16  AddCode;                    /**< These 3 codes are defined in */
    UINT8   ErrorCode;                  /**< "CiA DS 301" Chapter "The Service  Data Object"*/
    UINT8   ErrorClass;                 /**< "CiA DS 301" Chapter "The Service  Data Object"*/
} MIO_ACRERR;

/**
 * Structure for error statistic
 */
typedef struct
{
    UINT32  BusCheckCalls;              /**< Number of IO-Bus check calls */
    UINT32  BadBusChecks;               /**< Number of IO-Bus check fails */
    UINT32  BadRetainChecks;            /**< Number of retain check fails */
    UINT32  BadShdChecks;               /**< Number of shadow check fails */
    UINT32  AliveCheckCalls;            /**< Number of alive check calls */
    UINT32  BadAliveChecks;             /**< Number of alive check fails */
    UINT32  WriteRetries;               /**< Number of write retries */
    UINT32  WriteFails;                 /**< Number of write fails */
    UINT32  PlausibleFails;             /**< Number of plausibility fails */
    UINT32  ReadFails;                  /**< Number of read fails */
    UINT32  Spare[2];                   /**< Filled with zero */
} MIO_ERRSTATIST;

typedef VOID *MIO_PIHANDLE;             /**< MIO process image handle */

typedef const VOID *MIO_CHANSCALE_ID;   /**< ID for fast channel scaling */

/** Typedef for scaling (see #mio_SetScaleFct) */
typedef SINT32(*MIO_SCALEFCT) (const void *pData, const void *pRawVal, void *pScaledVal);
/** Typedef for inverse scaling (see #mio_SetScaleFct) */
typedef SINT32(*MIO_INVSCALEFCT) (const void *pData, void *pRawVal, const void *pScaledVal);

/** @} */

/**
 * @addtogroup MIO-API
 * @{
 */

/*--- Function Prototypes ---*/

/**
********************************************************************************
* @brief Read extended information of an I/O module or the CPU.
*
* This function is similar to the function mio_GetCardInf(), but has an
* extended return structure (#MIO_EXTCDINF).<br>
* If zero is passed as `CardNb`, the extended data of the CPU is returned.
*
* @param[in]  CardNb    Module number:
*                        -  0   .. CPU
*                        -  1-n .. I/O module
* @param[out] pCardInf  Extended card information
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @see mio_GetExtCardInf2()
* @see mio_GetCardInf()
*
* <b>Example</b>
* @snippet doc_mio_GetExtCardInf.c mio_GetExtCardInf
*******************************************************************************/
SINT32 mio_GetExtCardInf(UINT32 CardNb, MIO_EXTCDINF *pCardInf);

/**
********************************************************************************
* @brief Read more extended information of an I/O module or the CPU.
*
* This function is similar to the function mio_GetExtCardInf(), but has an
* extended return structure (#MIO_EXTCDINF2).<br>
* If zero is passed as `CardNb`, the extended data of the CPU is
* returned.
*
* @param[in]  CardNb    Module number:
*                        -  0 .. CPU
*                        -  1-n .. I/O module
* @param[out] pCardInf  Extended card information
*
* @see mio_GetExtCardInf()
* @see mio_GetCardInf()
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_GetExtCardInf2(UINT32 CardNb, MIO_EXTCDINF2 *pCardInf);


/**
********************************************************************************
* @brief Read the value of a channel.
*
* @note Since speed is important in most cases when accessing the I/O,
* practically no tests concerning the parameter validity and module state are
* performed. It is recommended to use the functions mio_GetError() or
* mio_AttachError() for detecting channel and module errors.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (1-n).
* @param[out] pValue    Transfer of the value buffer.<br>
*                       The read values are always returned as a 32-bit value,
*                       also for digital inputs or analog inputs with 16-bit
*                       width. Analog values are calibrated online if necessary.
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_GetValue.c mio_GetValue
*******************************************************************************/
SINT32 mio_GetValue(void *DrvId, UINT32 Chan, SINT32 *pValue);

/**
********************************************************************************
* @brief Write the value of a channel.
*
* @note Since speed is important in most cases when accessing the I/O,
* practically no tests concerning the parameter validity and module state are
* performed. It is recommended to use the functions mio_GetError() or
* mio_AttachError() for detecting channel and module errors.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (1-n).
* @param[in]  Value     Transfer of the new value.<br>
*                       The new value is always transferred as a signed value,
*                       even for digital or analog outputs with little data.
*                       Analog values are calibrated online prior to writing if
*                       necessary.<br>
*                       <b>Note:</b> When the range is exceeded for the relevant
*                       channel, the permissible threshold (minimum or maximum)
*                       is automatically transferred as a value without an error
*                       being reported.
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_SetValue.c mio_SetValue
*******************************************************************************/
SINT32 mio_SetValue(void *DrvId, UINT32 Chan, SINT32 Value);

/**
********************************************************************************
* @brief Read all channel values of an I/O module.
*
* @note Since speed is important in most cases when accessing the I/O,
*       practically no tests concerning the parameter validity and module state
*       are performed. It is recommended to use the functions mio_GetError()
*       or mio_AttachError() for detecting channel and module errors.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[out] pValue    Transfer of the value buffer.<br>
*                       The value buffer must be large enough in order to be able
*                       to include the values of all channels.<br>
*                       The read values are always returned in the available buffer
*                       as 32-bit values, also for digital inputs or analog inputs
*                       with less data. Every channel value is stored as a separate
*                       value in the array, even if the channel values are stored
*                       compressed on the module, for example digital I/O module.
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_GetValues.c mio_GetValues
*******************************************************************************/
SINT32 mio_GetValues(void *DrvId, SINT32 *pValue);

/**
********************************************************************************
* @brief Write all channel values of an I/O module.
*
* @note Since speed is important in most cases when accessing the I/O,
*       practically no tests concerning the parameter validity and module state
*       are performed. It is recommended to use the functions mio_GetError()
*       or mio_AttachError() for detecting channel and module errors.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  pValue    Transfer of an array with the new channel values.<br>
*                       New values are always transferred as a signed 32-bit value,
*                       even for digital or analog outputs with less data.
*                       Analog values are calibrated online prior to writing if
*                       necessary.<br>
*                       <b>Note:</b> When the range is exceeded for the relevant
*                       channel, the permissible threshold (minimum or maximum) is
*                       automatically transferred as a value without an error
*                       being reported.
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @snippet doc_mio_SetValues.c mio_SetValues
*******************************************************************************/
SINT32 mio_SetValues(void *DrvId, SINT32 *pValue);

/**
********************************************************************************
* @brief Read the values of more channels in a compressed format.
*
* This function is a special version of the function mio_GetValues(). A sub-area
* of channels can be specified (only for digital input/output modules).
* The read values are always returned in the available buffer as bit values
* in packed format. The lower channels occupy the lower bits, for example channel 1
* goes to bit 0, channel 2 goes to bit 1, etc.
*
* @param[in]     DrvId       Module instance handle returned by the function mio_GetDrv().
* @param[in,out] pValue      Transfer of the value buffer.<br>
*                            The value buffer must be large enough to be able to include
*                            the values of the desired channels.
* @param[in]     StartChan   Channel, starting at which the values should be read.<br>
*                            Only each 16th channel may be used as start channel,
*                            e. g. 1, 17, 33, etc.<br>
*                            Pay attention to the channel limit.
* @param[in]     ChanCount   Number of the channels to read.<br>
*                            `ChanCount` must always be a multiple of 16,
*                            e. g. 16, 32, 48 etc.<br>
*                            Pay attention to the channel limit
*
* @note The exceptions when specifying `StartChan` and `ChanCount` are modules
*       that do not have a multiple of 16 or less than 16 channels
*       (e. g. DOR206, D1212). In this case: `ChanCount` equals the number of
*       channels.
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @snippet doc_mio_GetPackedValues.c mio_GetPackedValues
*******************************************************************************/
SINT32 mio_GetPackedValues(void *DrvId, SINT32 *pValue, UINT32 StartChan, UINT32 ChanCount);

/**
********************************************************************************
* @brief Write the values of more channels in a compressed format.

* This function is a special version of the function mio_SetValues().
* The difference is that the passed values are in a packed format and that a
* sub-range of channels can be specified. This is only available for digital
* input/output modules.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  pValue    Transfer of the value buffer.<br>
*                       The values in the buffer are always in compressed format.
*                       The lower channels occupy the lower bits, e. g. channel 1
*                       goes to bit 0, channel 2 goes to bit 1, etc.
* @param[in]  StartChan Channel, starting at which the values should be written.<br>
*                       Only each 16th channel may be used as start channel,
*                       e. g. 1, 17, 33, etc.<br>
*                       Pay attention to the channel limit.
* @param[in]  ChanCount Number of channels to be written.<br>
*                       ChanCount must always be a multiple of 16, e. g. 16, 32, 48 etc.<br>
*                       Pay attention to the channel limit.
*
* @note The exceptions when specifying `StartChan` and `ChanCount` are modules
*       that do not have a multiple of 16 or less than 16 channels (e. g. DOR206, D1212).
*       In this case: `ChanCount` equals the number of channels.
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @snippet doc_mio_SetPackedValues.c mio_SetPackedValues
*******************************************************************************/
SINT32 mio_SetPackedValues(void *DrvId, SINT32 *pValue, UINT32 StartChan, UINT32 ChanCount);

/**
********************************************************************************
* @brief Get the current error state of either an entire I/O module or one channel
*        of an I/O module.
*
* This function is supported by every module driver, even if the module itself
* has no error register.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (0-n).<br>
*                       If the error state of the module (`Chan` = 0) is tested,
*                       the error codes of all channels will be linked with OR.
*                       If the error state of a particular channel (`Chan` = 1 to n)
*                       is requested, and module specific errors (for example powerfail)
*                       exist, these errors are added to the channel's error state.
* @param[out] pError    The error information is returned in the form of a 32-bit
*                       bit mask (see @ref MIO_E_).<br>
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @snippet doc_mio_GetError.c mio_GetError
*******************************************************************************/
SINT32 mio_GetError(void *DrvId, UINT32 Chan, UINT32 *pError);

/**
********************************************************************************
* @brief This function goes through all registered I/O modules (according to the
*        ascending module number) and channels and returns the first error found.
*
* For each further function call of mio_GetNextError(), the respectively next
* buffered error is returned and deleted from the buffer. In that way it is
* possible to work through all errors.<br>
* This function is particularly helpful for applications using querying,
* such as PLC programs. The PLC program cannot attach its own interrupt service
* routine, but should have knowledge of all errors.<br>
* The buffer is realized in the system as a card list, in which all occurring
* and previously reported errors are collected and listed by module.
* If AppIsrs are reported for corresponding errors, they are automatically
* called and the entry in the module list is deleted. If there are no reports,
* the error remains until it is retrieved with mio_GetNextError().
*
* @note Only modules/channels which have previously been registered with
*       the function mio_AttachError() will be checked. When invoking the
*       function mio_AttachError(), the parameters `AppIsr` and `UserPara`
*       must be `0/`
*
* @param[in]  SessId       Session ID returned by the function mio_StartErrorSession()
* @param[in]  pCard/pChan  Transfer of the start position of the search procedure <br>
*                          For `*pCard = 1` and `*pChan = -1` the search will start
*                          at the first channel of the first I/O module. <br>
*                          If `*pCard = 3` and `*pChan = 6` then module number 3
*                          and channel number 7 will be tested first.<br>
*                          With `*pChan = 0`, the entire module is specified.<br>
*                          `*pChan` is incremented by 1 upon transfer. *
* @param[out] pError       If an error was found, pCard and pChan will return
*                          the number of the module/channel. The error information
*                          is returned in the form of a 32-bit bit mask (see @ref MIO_E_).<br>
*                          If no error has been found, *pCard and *pChan will
*                          be set to -1.<br>
*
* @retval     0       OK, no error found
* @retval     1       OK, error found
* @retval     other   Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_GetNextError.c mio_GetNextError
*******************************************************************************/
SINT32 mio_GetNextError(SINT32 SessId, UINT32 *pCard, UINT32 *pChan, UINT32 *pError);

/**
********************************************************************************
* @brief Get the mode of a channel.
*
* @note With configurable channels the function returns the current configured
*       mode of the specified channel.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (1-n).
* @param[out] pMode     The mode is returned as a 32-bit value, and its meaning
*                       depends on the module.<br>
*                       For a list of the defined modes (<b>MIO_M_*</b>) see mio.h.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_GetChanMode.c mio_GetChanMode
*******************************************************************************/
SINT32 mio_GetChanMode(void *DrvId, UINT32 Chan, UINT32 *pMode);

/**
********************************************************************************
* @brief Set the mode of a channel.
*
* @note Activated channel modes are overwritten by calling the function
*       mio_SetChanMode().
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (1-n).
* @param[in]  Mode      Transfer of the new mode.<br>
*                       The meaning of the mode depends on the module.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_SetChanMode.c mio_SetChanMode
*******************************************************************************/
SINT32 mio_SetChanMode(void *DrvId, UINT32 Chan, UINT32 Mode);

/**
********************************************************************************
* @brief Get the selection information of a channel.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (1-n).
* @param[out] pSelect   If the channel is enabled, the value 1 will be returned, otherwise 0.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @see mio_SetSelect()
*
* <b>Example</b>
* @snippet doc_mio_GetSelect.c mio_GetSelect
********************************************************************************/
SINT32 mio_GetSelect(void *DrvId, UINT32 Chan, UINT32 *pSelect);

/**
********************************************************************************
* @brief Set the selection information of all channels or one channel
*        of an I/O module.
*
* The channels can be excepted from the error interrupt handling.
* Also mio_GetError() returns no error if the channels are disabled.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (0-n).<br>
*                       When the value is set to 0, the function is executed on all channels.
* @param[in]  Select    Transfer of the new selection information.<br>
*                       - `Select` = <b>0</b>: The respective channel is disabled.
*                       - `Select` = <b>1</b>: The respective channel is enabled
*
* @note Disabled channels can continue to be read/written:
*       - Read mio_GetValue()/mio_GetValues()
*       - Write with mio_SetValue()/mio_SetValues()
*
* The configuration parameters DisableChanX at system start, call mio_SetSelect()
* with the parameter `Select` = <b>0</b>.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @see mio_GetSelect()
*
* <b>Example</b>
* @snippet doc_mio_GetSelect.c mio_GetSelect
*******************************************************************************/
SINT32 mio_SetSelect(void *DrvId, UINT32 Chan, UINT32 Select);

/**
********************************************************************************
* @brief Get the mode of an I/O module.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[out] pMode     The mode is returned as a 32-bit value, and its meaning
*                       depends on the module (see @ref MIO_M_).
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_GetCardMode.c mio_GetCardMode
*******************************************************************************/
SINT32 mio_GetCardMode(void *DrvId, UINT32 *pMode);

/**
********************************************************************************
* @brief Set the mode of an I/O module.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Mode      Transfer of the new mode.<br>
*                       The meaning of the mode depends on the module (see @ref MIO_M_).
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_SetCardMode.c mio_SetCardMode
*******************************************************************************/
SINT32 mio_SetCardMode(void *DrvId, UINT32 Mode);

/**
********************************************************************************
* @brief Attach an event handling interrupt service routine.
*
* In order for the function mio_AttachEvent() to be used, an event session needs
* to be started by the function mio_StartEventSession().<br>
* For each `SessId` any number of channels and event processing can be
* integrated, however always only one event per channel (`Chan`).<br>
* If an additional event with the same `SessId` is signaled for a channel that
* is already integrated, then the old event processing will be overwritten.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  SessId    Session ID returned by the function mio_StartEventSession()
* @param[in]  Chan      The number of the channel (0-n).<br>
*                       The event handler is called, when on the specified channel,
*                       one of the events transferred in the parameter `Event` occurs.<br>
*                       When the value is set to 0, the function is executed on all channels.
* @param[in]  Event     Transfer of the event for which event processing `AppIsr` is
*                       to be called.<br>
*                       The events (for example #MIO_EV_VALUE) depend on the module and
*                       the channel. Combinations are possible.
* @param[in]  AppIsr    Transfer of the interrupt service routine (event processing).<br>
*                       <b>Note</b>: Event processing needs to be programmed for the
*                       specific user.
* @param[in]  UserPara  The parameter can be used freely by the application
*                       and is directly passed to the `AppIsr` function.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @note A `SessId = -1` is reserved only for internal use.
*
* @see Example of function mio_StartEventSession().
*******************************************************************************/
SINT32 mio_AttachEvent(void *DrvId, SINT32 SessId, UINT32 Chan,
                        UINT32 Event, VOID(*AppIsr) (), UINT32 UserPara);

/**
********************************************************************************
* @brief Detach an event handler interrupt service routine.
*
* This function is the counterpart of the function mio_AttachEvent().<br>
* When the function mio_StopEventSession() is invoked, all existing event
* handlers are removed automatically.
*
* @note The execution of this function may take several 100 us.<br>
*       It's use in interrupt service functions is not recommended.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  SessId    Session ID returned by the function mio_StartEventSession()
* @param[in]  Chan      The number of the channel (0-n).
* @param[in]  Event     The parameter `Event` is must have the same value as used in the
*                       function mio_AttachEvent(). It depends on the driver if this
*                       parameter is checked or not.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @note A `SessId = -1` is reserved only for internal use.
*
* @see Example of function mio_StartEventSession().
********************************************************************************/
SINT32 mio_DetachEvent(void *DrvId, SINT32 SessId, UINT32 Chan, UINT32 Event);

/**
********************************************************************************
* @brief Attach an error handling interrupt service routine.
*
* In order for the function mio_AttachError() to be used, an error session needs
* to be started by the function mio_StartErrorSession().
*
* @note Only one error handling can be integrated per channel (`Chan`) and
*       session (`SessId`). If an error handling is already installed, it will
*       be overwritten by the new one.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  SessId    Session ID returned by the function mio_StartErrorSession()
* @param[in]  Chan      The number of the channel (0-n).<br>
*                       Error handling is called up when one of the bit-coded errors
*                       transferred in the parameter `Error` occurs on the indicated channel.<br>
*                       When the value is set to 0, the function is executed on all channels.
* @param[in]  Error     Transfer of the error code for which the `AppIsr` is to be
*                       called (combinations are possible).<br>
*                       See header file mio.h<br>
*                       <b>Note</b>: Even if the parameter Error is transferred
*                       with 0xffffffff, the driver only evaluates the flags
*                       supported by the driver.
* @param[in]  AppIsr    Transfer of the interrupt service routine (event processing).<br>
*                       If errors are not to be processed by the error handler but
*                       by polling via the function mio_GetNextError(),
*                       `AppIsr = 0` must be specified for the parameter.<br>
*                       <b>Note</b>: Error handling needs to be programmed for the
*                       specific user.
* @param[in]  UserPara  The parameter can be used freely by the application
*                       and is directly passed to the `AppIsr` function.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @note A `SessId = -1` is reserved only for internal use.
*
* @see Example of function mio_StartErrorSession().
*******************************************************************************/
SINT32 mio_AttachError(void *DrvId, SINT32 SessId, UINT32 Chan,
                        UINT32 Error, VOID(*AppIsr) (), UINT32 UserPara);

/**
********************************************************************************
* @brief Detach an error handling interrupt service routine.
*
* This function is the counterpart of the function mio_AttachError().<br>
* If the function mio_StopErrorSession() is accessed, all existing error
* handlers are automatically detached.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  SessId    Session ID returned by the function mio_StartErrorSession()
* @param[in]  Chan      The number of the channel (0-n).
* @param[in]  Error     The parameter `Error` must have the same value as used in the
*                       function mio_AttachError(). It depends on the driver if this
*                       parameter is checked or not.
*
* @retval  #MIO_ER_OK    OK
* @retval  other         Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @note A `SessId = -1` is reserved only for internal use.
*
* @see Example of function mio_StartErrorSession().
*******************************************************************************/
SINT32 mio_DetachError(void *DrvId, SINT32 SessId, UINT32 Chan, UINT32 Error);

/**
********************************************************************************
* @brief Get general information of an I/O module.
*
* The returned information describes the actual status of the module.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[out] CardInf   Module information.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_GetCardInf.c mio_GetCardInf
*******************************************************************************/
SINT32 mio_GetCardInf(const void *DrvId, MIO_CARDINF *CardInf);

/**
********************************************************************************
* @brief Get general information of a channel.
*
* The returned information describes the current state of a channel.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (1-n).
* @param[out] ChanInf   Channel information.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_GetChanInf.c mio_GetChanInf
*******************************************************************************/
SINT32 mio_GetChanInf(const void *DrvId, UINT32 Chan, MIO_CHANINF *ChanInf);

/**
********************************************************************************
* @brief Set an I/O module to the same status as after power-on.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_Reset.c mio_Reset
*******************************************************************************/
SINT32 mio_Reset(void *DrvId);

/**
********************************************************************************
* @brief Call an I/O module specific function.
*
* @note Depending on the module and function command, the function mio_DoCmd()
*       may take several seconds to be executed.<br>
*       Accessing function mio_DoCmd() in interrupt service routines or any
*       other timely restricted functions should be avoided.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (0-n).
* @param[in]  Cmd       Transfer of the ID of the command to be executed (for example MIO_CMD_SETREF).<br>
*                       A detailed description of each mio_DoCmd function can be found
*                       in the chapter "Module-Specific Functions" of the corresponding
*                       modules documentation.
*
* @retval  #MIO_ER_OK        OK
* @retval  #MIO_ER_BADCHAN   Module-specific function cannot be executed with the transferred channel
* @retval  #MIO_ER_BADCMD    Module-specific function is not supported by the driver
* @retval  other             Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example 1</b><br>
* The following example demonstrates the function call mio_DoCmd with an
* additional UINT32 parameter.
* @snippet doc_mio_DoCmd.c MIO_CMD_SETREF

* <b>Example 2</b><br>
* The following example demonstrates how to supply a profile structure to an
* ACR222 module through the function MIO_CMD_SETPROF.
* @snippet doc_mio_DoCmd.c MIO_CMD_SETPROF
*******************************************************************************/
SINT32 mio_DoCmd(void *DrvId, UINT32 Chan, UINT32 Cmd, ...);

/**
********************************************************************************
* @brief This function provides the read/write function and flag for the
*        treatment of a card in the PLC process image.
*
* @param[in]     DrvId        The driver ID is determined by the function mio_GetDrv().
* @param[in]     PlcImgFlags  Flags regarding the process image.
* @param[in,out] pImgFnData   Pointer to information buffer.<br>
*                             Among others, following cases are possible:<br>
*                             <b>Card DI</b>: Read-function, no write-function
*                             (sets `*pCardImageNew`).<br>
*                             <b>Card DO</b>: Read-function and write-function
*                             (`*pCardImageNew` and `*pCardImageRef`)<br>
*                             <b>Card DO + CYCLE0</b>: Write-function (sets actual
*                             values in `*pCardImageNew` and `*pCardImageRef`)<br>
*                             <b>Cards A...</b>: Depends on ability of card/driver.
*
* @retval  0       OK
* @retval  !0      Error
*******************************************************************************/
SINT32  mio_GetProcImgFuncs(VOID *DrvId, UINT32 PlcImgFlags, MIO_IMGFNDATA *pImgFnData);

/**
********************************************************************************
* @brief    This method is used to avoid that MIO drivers try to access the
*           memory range of the I/O bus in special situations like virtual mode,
*           sub station connection loss or in simulation mode.
*
* @param[in]  DrvId     Module instance handle.
* @param[in]  Origin    Bit mask to inform about the reason for this function to
*                       be called.
*                       MIO_ORIGIN_INIT: Called by the Init-function of the
*                       driver. This call is used to initialize internal memory
*                       which will be used to redirect I/O bus memory access to
*                       in case of a function call with parameter
*                       MIO_ORIGIN_SIMINIT or MIO_ORIGIN_BADSTATION.
*                       MIO_ORIGIN_SIMINIT: Called by the Init-function of the
*                       driver in case of simulation mode. Every I/O bus memory
*                       access will be redirected to the memory allocated during
*                       the call with flag MIO_ORIGIN_INIT.
*                       MIO_ORIGIN_BADSTATION: The CPU has lost the connection
*                       to the sub station of the particular module. Every
*                       I/O bus memory access will be redirected to the memory
*                       allocated in during the call with flag MIO_ORIGIN_INIT.
*
* @retval #MIO_ER_OK    If successful.
* @retval MIO_ER_*      For all these return codes see #MIO_ER_FAIL and
*                       following defines.
*******************************************************************************/
SINT32  mio_InitVirtual(VOID *DrvId, UINT32 Origin);

/**
********************************************************************************
* @brief Read a block value of a channel.
*
* This function is used to read a value greater 32 bit, strings or arrays.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (1-n).
* @param[out] pValue    Pointer to the channel value.
* @param[in]  pLen      Pointer to the length of the data to be read.
* @param[out] pLen      Pointer to the number of bytes actually read.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @see mio_SetBlk()
*
* <b>Example</b>
* @snippet doc_mio_GetBlk.c mio_GetBlk
*******************************************************************************/
SINT32 mio_GetBlk(void *DrvId, UINT32 Chan, VOID *pValue, UINT32 *pLen);

/**
********************************************************************************
* @brief Write the block value of a channel.
*
* This function is used to write a value greater 32 bit, strings or arrays.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (1-n).
* @param[in]  pValue    Transfer of the value buffer.
* @param[in]  Len       Transfer of the length of the value buffer.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @see mio_GetBlk()
*
* <b>Example</b>
* @snippet doc_mio_SetBlk.c mio_SetBlk
*******************************************************************************/
SINT32 mio_SetBlk(void *DrvId, UINT32 Chan, const VOID *pValue, UINT32 Len);

/**
********************************************************************************
* @brief Get the range information of an I/O module.
*
* @param[in]  DrvId         Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan          The number of the channel (1-n).
* @param[out] pChanRange    Structure containing range information
*
* @retval     #MIO_ER_OK        OK
* @retval     #MIO_ER_BADCHAN   Channel is invalid
* @retval     #MIO_ER_BADFUNC   Function not supported by module
* @retval     #MIO_ER_NOFPTASK  Called task does not support floating point operations
* @retval     other             Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_GetChanRange.c mio_GetChanRange
*******************************************************************************/
SINT32 mio_GetChanRange(void *DrvId, UINT32 Chan, MIO_CHAN_RANGE *pChanRange);


/**
********************************************************************************
* @brief To ensure fast access to an I/O module, the function mio_GetDrv()
*        must be invoked first in order to get a driver ID (DrvId) for access.
*
* This ID can be used for all further accesses to this I/O module.
*
* @param[in]  CardNb  Number of desired I/O module
*
* @retval     !0      Module instance handle
* @retval     0       No module with this number
*
* @see mio_GetDrvByName()
*
* <b>Example</b>
* @snippet doc_mio_GetDrv.c mio_GetDrv
*******************************************************************************/
VOID *mio_GetDrv(UINT32 CardNb);

/**
********************************************************************************
* @brief This function does the same as the function mio_GetDrv(),
*        the difference being that the driver ID is formed directly from the
*        logical address.
*
* The logical address may have the following formats:
* - MIO/ (Signal type /) Module number / Channel number / Value number
* - MIO/ (Signal type /) Module number / Channel number / Value number (only SEM201)
* - MIO/ (Signal type /) Module number / Channel number
* - MIO/ Symbolic channel name " " Any string
* - MIO/ Symbolic channel name
*
* For example:
* - MIO/AO/4/9
* - MIO/INC/24/1
* - MIO/14/32
* - MIO/Position_Switch7
*
* SEM201:
* - MIO/SER/6/5/1
* - MIO/SER/6/4/POSCMD
*
* Module specific (for example DMW):
* - MIO/DRV/200
* - MIO/Drive_1
*
* SMC:
* - "MIO/AO/15/3 pos" (arbitrary string after number of channel, separated by one whitespace)
*
* The parameter `pName` is used to transfer the pointer to the logical address.
* Everything after a space character in parameter pName will be ignored.
* The driver ID (`pDrvId`), the optional signal type (`pType`), the module number
* (`pCardNb`), the channel number (`pChanNb`) and the final position of the
* address (`pNext`) are returned from this address.<br>
* If no signal type is specified in the logical address, the actual signal type
* will be returned without checking in parameter `*pType`. Is a signal type
* specified, a comparison with the actual signal type will also be made.<br>
* The parameter `pNext` enables efficient processing of application specific
* specifications, which follow the address (separated by spaces).<br>
* If certain return information (`pDrvId, pType, pCardNb, pChanNb` or `pNext`) is
* not needed, a Null pointer can be passed for the parameter.<br>
* With fieldbus modules that have more than one value per channel (for example
* SEM201), the parameter `pChanNb` contains the defined value number in the high
* word.<br>
* In the case of the SEM201 module, the logical address may contain a
* value string. All possible strings are defined in the headerfile `sem201.h`.
* The string is converted into a corresponding value number which is returned
* in the higher ranking word of the parameter `pChanNb`.
*
* @param[in]  pName     Name of channel
* @param[out] pDrvId    Module instance handle
* @param[out] pType     Type of channel (see @ref MIO_CATEG_)
* @param[out] pCardNb   Card number of I/O module
* @param[out] pChanNb   Channel number
* @param[out] pNext     Pointer to the end of name (next element)
*
* @note If the information of an output parameter (`pDrvID, pType, pCardNb, pChanNb` or `pNext`)
*       is not needed, a NULL-pointer can be transferred.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @see mio_GetDrv()
*
* <b>Example</b>
* @snippet doc_mio_GetDrvByName.c mio_GetDrvByName
*******************************************************************************/
SINT32 mio_GetDrvByName(CHAR *pName, VOID **pDrvId, UINT32 *pType,
                        UINT32 *pCardNb, UINT32 *pChanNb, CHAR **pNext);

/**
********************************************************************************
* @brief This function goes through all registered I/O modules (according to the
*        ascending module number) and calls the `UserFunc` for each module.
*
* @param[in]  UserFunc    Transfer of the function to be used.<br>
*                         The specified function is accessed once for
*                         each available I/O module.<br>
*                         Parameter of UserFunc:
*                         - DrvId: Transfer of the driver ID
*                         - CardNb: Transfer of the module number
*                         - Param: Transfer of the user parameter
* @param[in]  Param       The parameter can be used freely by the application
*                         and is directly passed to the `UserFunc` function.
*
* <b>Example</b>
* @snippet doc_mio_WalkCardList.c mio_WalkCardList
*******************************************************************************/
#ifdef MIO_MAIN
VOID    mio_WalkCardList(VOID(*UserFunc) (void *DrvId, UINT32 CardNb, UINT32 Param), UINT32 Param);
#else
VOID    mio_WalkCardList(VOID(*UserFunc) (), ...);
#endif


/**
********************************************************************************
* @brief This function makes it possible to determine the module that
*        previously occurred in the topology on a bus expansion module
*        (FS2xx or BES21x).
*
* @param[in]  DrvId           Module instance handle returned by the function mio_GetDrv().
* @param[out] pParentCardNb   CardNb of parent
* @param[out] pParentChan     Channel of parent (1,2)
*
* @retval #MIO_ER_OK     OK
* @retval #MIO_ER_FAIL   No higher-level module found.
*******************************************************************************/
SINT32 mio_GetParent(void *DrvId, UINT32 *pParentCardNb, UINT32 *pParentChan);


/**
********************************************************************************
* @brief Initiate the coupling of an asynchronous event in a channel.
*
* Thus after removal of a crashed software module, the associated event handling
* (event handlers) can also be removed. This function must be called up before
* the functions mio_AttachEvent(), or mio_DetachEvent() can be used.
*
* @note It is possible to start multiple sessions, to which also the same errors
* of a module can be assigned.
*
* @param[in]  pAppName     Instance name of the calling software module
*
* @retval     >=0     Session ID for the treatment of MIO event interrupts.
* @retval     other   Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_StartEventSession.c mio_StartEventSession
*******************************************************************************/
SINT32 mio_StartEventSession(CHAR *pAppName);

/**
********************************************************************************
* @brief This function removes all event handlers belonging to the
*        transferred session ID, and that are still installed.
*
* This function is the counterpart to mio_StartEventSession() and allows the
* termination of MIO event handling. The attached application service routines
* will be removed.
*
* @note The execution of this function may take more than 100 ms.
*       It's use in interrupt service functions is not recommended.
*
* @param[in]  SessId    Session ID returned by the function mio_StartEventSession()
*
* @retval     #MIO_ER_OK       OK
* @retval     #MIO_ER_FAIL     Error handler was not correctly started
* @retval     #MIO_ER_BADPARM  Invalid Session ID
* @retval     other            Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @see Example of mio_StartEventSession()
*******************************************************************************/
SINT32 mio_StopEventSession(SINT32 SessId);

/**
********************************************************************************
* @brief Initiate the coupling of an asynchronous error in a channel.
*
* Thus after removal of a crashed software module, the associated error handling
* (error handlers) can also be removed. This function must be called before
* the functions mio_AttachError(), mio_DetachError() or mio_GetNextError() can
* be used.
*
* @note It is possible to start multiple sessions, to which also the same errors
*       of a module can be assigned.
*
* @param[in]  pAppName     Instance name of the calling software module
*
* @retval     >=0     Session ID for the treatment of MIO error interrupts.
* @retval     other   Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_StartErrorSession.c mio_StartErrorSession
*******************************************************************************/
SINT32 mio_StartErrorSession(CHAR *pAppName);

/**
********************************************************************************
* @brief This function removes all error handlers belonging to the
*        transferred session ID, and that are still installed.
*
* This function is the counterpart to mio_StartErrorSession() and allows
* the termination of MIO error handling. The attached application service routines
* will be removed.
*
* @param[in]  SessId    Session ID returned by the function mio_StartErrorSession()
*
* @retval     #MIO_ER_OK       OK
* @retval     #MIO_ER_FAIL     Error handler was not correctly startet
* @retval     #MIO_ER_BADPARM  Invalid Session ID
* @retval     other            Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @see Example of mio_StartErrorSession()
*******************************************************************************/
SINT32 mio_StopErrorSession(SINT32 SessId);

/**
********************************************************************************
* @brief Initiate the coupling to the MIO sync interrupt.
*
* Thus after removal of a crashed software module, the associated sync handling
* (sync handlers) can also be removed. This function must be called before the functions
* mio_AttachSync(), mio_AttachSyncExt() and mio_DetachSync() can be used.
* The counterpart to this function is mio_StopSyncSession().
*
* @note     It is possible to start multiple sessions.
*
* @param[in]  pAppName  Instance name of the calling software module
*
* @retval  >0      Session ID for the treatment of MIO sync interrupts.
* @retval  other   Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @see mio_StopSyncSession()
*
* <b>Example</b>
* @snippet doc_mio_StartSyncSession.c mio_StartSyncSession
*******************************************************************************/
SINT32 mio_StartSyncSession(CHAR *pAppName);

/**
********************************************************************************
* @brief This function removes all error handlers belonging to the
*        transferred session ID, and that are still installed.
*
* This function is the counterpart to mio_StartSyncSession() and allows
* the termination of MIO sync handling. The attached application service routines
* will be removed.
*
* @param[in]  SessId  Session ID returned by the function mio_StartSyncSession()
*
* @retval #MIO_ER_OK        OK
* @retval #MIO_ER_FAIL      Error handler was not correctly started.
* @retval #MIO_ER_BADPARM   Invalid session ID
* @retval other             Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @see mio_StartSyncSession()
*******************************************************************************/
SINT32 mio_StopSyncSession(SINT32 SessId);

/**
********************************************************************************
* @brief Attach a MIO sync interrupt service routine.
*
* This sync handling is invoked with every Sync-IN and/or Sync-OUT interrupt,
* depending on the parameter `Type`.
*
* @note     There is a more enhanced function mio_AttachSyncExt() available
*           as well. This functions differ only in the parameter `SyncIdx`.
*
* @note     If both edges (#MIO_SYNC_IN | #MIO_SYNC_OUT) are attached, this
*           will be performed internally using two separate attaches.
*           With appropriate detaching by the parameter Type
*           (#MIO_SYNC_IN | #MIO_SYNC_OUT), both interrupt service routines
*           `AppIsr` are removed again. By using the mio_ShowSync() function
*           it is made apparent that internally two separate interrupt service
*           routine AppIsr() have been engaged.
*
* @warning  No switching of the protective layer is done by the sync handler.
*           If an application attaches a routine that accesses protected memory,
*           the protective layer must be switched over beforehand using
*           sys_AppToSys(). VxWorks calls do not require switchover.
*
* @param[in]  SessId    Session ID returned by the function mio_StartSyncSession().<br>
*                       The function mio_AttachSync() may be used multiple times
*                       per session.
* @param[in]  Type      This parameter contains the bit coded Sync edge that
*                       is responsible for calling (#MIO_SYNC_IN or
*                       #MIO_SYNC_OUT). Furthermore, there is the
*                       #MIO_SYNC_EXTINT flag (only for PROFINET(R) necessary)
*                       in the Type parameter, which signalizes that the present
*                       interrupt was triggered from the external SYNC signal
*                       and not through internal generation.
* @param[in]  Counter   Specifies of how many sync interrupts of the desired
*                       type must occur until the sync handler is called. Use 1 to be called on
*                       every sync interrupt of the desired type.
* @param[in]  AppIsr    Pointer to applications interrupt service routine
*                       which should be called on SYNC interrupts. This service
*                       routine must use the following function prototype:
*                       `VOID AppIsr(UINT32 UserPara, UINT32 Type)`
* @param[in]  UserParam This parameter can be used freely by the application
*                       and is directly passed to the `AppIsr` function.
*
* @retval #MIO_ER_OK    OK
* @retval other         Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @note A `SessId = -1` is reserved only for internal use.
*
* @see mio_AttachSyncExt()
* @see mio_DetachSync()
* @see mio_StartSyncSession()
*******************************************************************************/
SINT32 mio_AttachSync(SINT32 SessId, UINT32 Type, UINT32 Counter,
                       VOID(*AppIsr) (), UINT32 UserParam);

/**
********************************************************************************
* @brief    Attach a MIO sync interrupt service routine.
*
* This sync handling is invoked with every Sync-IN and/or Sync-OUT interrupt,
* depending on the parameter `Type`.
*
* This function supports additional features compared to the
* function mio_AttachSync(). Detaching is determined by the function
* mio_DetachSync().
*
* @image html mio_AttachSyncExt_Pic1.png "SYNC timing"
*
* @warning  No switching of the protective layer is done by the sync handler.
*           If an application attaches a routine that accesses protected memory,
*           the protective layer must be switched over beforehand using
*           sys_AppToSys(). VxWorks calls do not require switchover.
*
* @note     If both edges (#MIO_SYNC_IN | #MIO_SYNC_OUT) are attached, this
*           will be performed internally using two separate attaches.
*           With appropriate detaching by the parameter Type
*           (#MIO_SYNC_IN | #MIO_SYNC_OUT), both interrupt service routines
*           AppIsr are removed again. By using the mio_ShowSync() function
*           it is made apparent that internally two separate interrupt service
*           routine AppIsr() have been engaged.
*
* @param[in]  SessId    Session ID returned by the function mio_StartSyncSession().<br>
*                       The function mio_AttachSync() may be used multiple times
*                       per session.
* @param[in]  Type      This parameter contains the bit coded Sync edge that
*                       is responsible for calling (#MIO_SYNC_IN or
*                       #MIO_SYNC_OUT).
* @param[in]  Counter   Specifies of how many sync interrupts of the desired
*                       type must occur until the sync handler is called. Use 1 to be called on
*                       every sync interrupt of the desired type.
* @param[in]  SyncIdx   If the parameter Counter has a value > 1, the
*                       parameter SyncIdx, allows the user to define after
*                       how much Sync Interrupts the Sync Handler should
*                       be called. This functionality is useful when several
*                       sync handlers are attached and these are to be
*                       called at different times.
*                       The parameter `SyncIdx` must be lower than the
*                       parameter `Counter`.
* @param[in]  AppIsr    Pointer to applications interrupt service routine
*                       which will be called on SYNC interrupts. This service
*                       routine must use the following function prototype:
*                       `VOID AppIsr(UINT32 UserParam, UINT32 Type)`
*                       One or more of the following flags may be set in parameter `Type`
*                       #MIO_SYNC_IN or #MIO_SYNC_OUT. Furthermore, there is the
*                       #MIO_SYNC_EXTINT flag (only for PROFINET(R) necessary),
*                       which signalizes that the present interrupt was triggered from the
*                       external SYNC signal and not through internal generation.
* @param[in]  UserParam This parameter can be used freely by the application
*                       and is directly passed to the `AppIsr` function.
*
* @retval  #MIO_ER_OK  OK
* @retval  other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @note A `SessId = -1` is reserved only for internal use.
*
* @see mio_AttachSync()
* @see mio_DetachSync()
* @since  MSys V3.20
*
* <b>Example</b>
* @snippet doc_mio_AttachSyncExt.c mio_AttachSyncExt
*******************************************************************************/
SINT32 mio_AttachSyncExt(SINT32 SessId, UINT32 Type, UINT32 Counter,
                          UINT32 SyncIdx, VOID(*AppIsr) (), UINT32 UserParam);

/**
********************************************************************************
* @brief Detach a MIO sync interrupt service routine.
*
* This function is the counterpart of the functions mio_AttachSync() and
* mio_AttachSyncExt(). To delete an existing entry, the same parameters as for
* the function mio_AttachSync() or mio_AttachSyncExt () must be passed.
*
* @param[in]  SessId    Session ID returned by the function mio_StartSyncSession().
* @param[in]  Type      Must be the value as it was used for the related mio_AttachSync()
*                       or mio_AttachSyncExt().
* @param[in]  Counter   Must be the value as it was used for the related mio_AttachSync()
*                       or mio_AttachSyncExt().
* @param[in]  AppIsr    Must be the application function as it was used for the related
*                       mio_AttachSync() or mio_AttachSyncExt().
* @param[in]  UserParam Must be the value as it was used for the related mio_AttachSync()
*                       or mio_AttachSyncExt().
*
* @retval #MIO_ER_OK  OK
* @retval other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @see mio_AttachSync()
* @see mio_AttachSyncExt()
* @see mio_StartSyncSession()
*******************************************************************************/
SINT32 mio_DetachSync(SINT32 SessId, UINT32 Type, UINT32 Counter,
                       VOID(*AppIsr) (), UINT32 UserParam);


/**
********************************************************************************
* @brief Create a new process image handle.
*
* Using this handle, a hardware process image can be configured and updated.
* A process image handle can be deleted by the function mio_PiRemoveHandle().
*
* @param[in]  pAppName         Name of the application (used for debugging)
* @param[out] pPiHandle        Where to store the process image handle
* @param[in]  Priority         Task priority
* @param[in]  CallBackFctRead  Callback function to be called when the
*                              reading update has finished.
* @param[in]  UserParamRead    User parameter to be passed to the read
*                              callback function.
* @param[in]  CallBackFctWrite Callback function to be called when the
*                              writting update has finished.
* @param[in]  UserParamWrite   User parameter to be passed to the write
*                              callback function.
*
* If callback functions are transferred (`CallBackFctRead` or `CallBackFctWrite`),
* the update functions (mio_PiUpdateIn() and mio_PiUpdateOut()) do not block;
* instead, the callback function is invoked with the appropriate parameter
* (`UserParamRead` or `UserParamWrite`) upon completion of the update.<br>
* If no callback functions are to be invoked, then NULL must be transferred as
* function pointer.
*
* @retval     #MIO_ER_OK    OK
* @retval     other         Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example 1 (without interrupt synchronization)</b>
* @snippet doc_mio_PiHandle1.c mio_PiHandle1
* <b>Example 2 (with interrupt synchronization)</b>
* @snippet doc_mio_PiHandle2.c mio_PiHandle2
* <br>
*******************************************************************************/
SINT32 mio_PiCreateHandle(const CHAR *pAppName, MIO_PIHANDLE *pPiHandle,
                          SINT32 Priority, VOID(*CallBackFctRead) (UINT32 UserParamRead),
                          UINT32 UserParamRead,
                          VOID(*CallBackFctWrite) (UINT32 UserParamWrite),
                          UINT32 UserParamWrite);

/**
********************************************************************************
* @brief Remove a process image handle.
*
* No update of this handle may be active when this function is invoked.<br>
* After invoking this function, neither the process image handle nor a module
* handle created with this process image handle may be used.
*
* @param[in]  PiHandle    Process image handle returned by the function mio_PiCreateHandle()
*
* @see Examples of function mio_PiCreateHandle()
* <br><br>
*******************************************************************************/
VOID mio_PiRemoveHandle(MIO_PIHANDLE PiHandle);

/**
********************************************************************************
* @brief Change the priority of the process image update.
*
* The priority is set by the function mio_PiCreateHandle() when creating
* the process image handle. This function should be used only when changing
* the priority at a later time.
*
* @param[in]  PiHandle    Process image handle returned by the function mio_PiCreateHandle()
* @param[in]  Priority    New priority of the update
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @snippet doc_mio_PiSetPriority.c mio_PiSetPriority
* <br>
*******************************************************************************/
SINT32 mio_PiSetPriority(MIO_PIHANDLE PiHandle, SINT32 Priority);

/**
********************************************************************************
* @brief Get a module handle (PiDrvId) that can be used to access the
*        process image of a module.
*
* Using this handle, it is possible to access the process image of the module.
* The module handle generated can be used with all driver functions just like
* the "original" module handle. Dereferencing is not permitted.<br>
* If the parameter `ConfigAllChannels` is set (TRUE), then all of the module's
* channels are configured for the process image automatically, If this is not
* desired, individual channels can be configured later by the function mio_PiConfigChan().
*
* @param[in]  PiHandle          Process image handle returned by the function mio_PiCreateHandle()
* @param[in]  DrvId             Module instance handle returned by the function mio_GetDrv().
* @param[in]  ConfigAllChannels Configure all channels if set
* @param[in]  flags             Additional flags passed to the driver.<br>
*                               #MIO_PI_FLAGS_NONE (0) must be transferred.
*
* @retval  0    Error, the module handle could not be created.
*               The module may not support the process image mode.
* @retval  !0   ID for access to I/O module
*
* @see Examples of function mio_PiCreateHandle()
* <br><br>
*******************************************************************************/
VOID *mio_PiGetDrvByHandle(MIO_PIHANDLE PiHandle, MIO_DRV *DrvId,
                           UINT32 ConfigAllChannels, UINT32 flags);

/**
********************************************************************************
* @brief Get a module handle (PiDrvId) that can be used to access the
*        process image of a module.
*
* Using this handle, it is possible to access the process image of the module.
* The module handle generated can be used with all driver functions just like
* the "original" module handle. Dereferencing is not permitted.<br>
* If the parameter `ConfigAllChannels` is set (TRUE), then all of the module's
* channels are configured for the process image automatically, If this is not
* desired, individual channels can be configured later by the function mio_PiConfigChan().
*
* @param[in]  PiHandle          Process image handle returned by the function mio_PiCreateHandle()
* @param[in]  CardNb            Module number to get the handle from
* @param[in]  ConfigAllChannels Configure all channels if set
* @param[in]  flags             Additional flags passed to the driver.<br>
*                               #MIO_PI_FLAGS_NONE (0) must be transferred.
*
* @retval     0    Error, the module handle could not be created.
*                  The module may not support the process image mode.
* @retval     !0   ID for access to I/O module
*
* @see Examples of function mio_PiCreateHandle().
* <br><br>
*******************************************************************************/
VOID *mio_PiGetDrv(MIO_PIHANDLE PiHandle, SINT32 CardNb,
                   UINT32 ConfigAllChannels, UINT32 flags);

/**
********************************************************************************
* @brief Add an individual channel to the process image of an application.
*
* @param[in]  pPiDrvId    Process image module handle returned by the function
*                         mio_PiGetDrvByHandle() or mio_PiGetDrv().
* @param[in]  Chan        The number of the channel (0-n).<br>
*                         To add all of the module's channels to the process
*                         image, the value 0 must be transferred (see also
*                         parameter `ConfigAllChannels` for the functions
*                         mio_PiGetDrvByHandle() and mio_PiGetDrv()).
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @see Example 1 of function mio_PiCreateHandle().
* <br><br>
*******************************************************************************/
SINT32 mio_PiConfigChan(VOID *pPiDrvId, UINT32 Chan);

/**
********************************************************************************
* @brief Initiate a process image update of the inputs.
*
* This function blocks until the update completes or returns immediately
* depending on the transferred callback function `CallBackFctRead` to the
* function mio_PiCreateHandle():
* - <b>Callback function specified:</b> The function returns immediately  and
*   after the input values have been updated, the callback function is invoked.
* - <b>No callback function specified:</b> The function blocks until the
*   update completes or the timeout has expired and only then returns to the caller.
*
* @param[in]  PiHandle       Process image handle returned by the function mio_PiCreateHandle()
* @param[in]  timeoutTicks   Timeout in ticks (-1 = WAIT_FOREVER, 0 = NO_WAIT)
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @see Examples of function mio_PiCreateHandle()<br><br>
*******************************************************************************/
SINT32 mio_PiUpdateIn(MIO_PIHANDLE PiHandle, SINT32 timeoutTicks);

/**
********************************************************************************
* @brief Initiate a process image update of the outputs.
*
* This function blocks until the update completes or returns immediately
* depending on the transferred callback function `CallBackFctWrite` to the
* function mio_PiCreateHandle():
* - <b>Callback function specified:</b> The function returns immediately and
*   after the output values have been updated, the callback function is invoked.
* - <b>No callback function specified:</b> The function blocks until the
*   update completes or the timeout has expired and only then returns to the caller.
*
* @param[in]  PiHandle       Process image handle returned by the function mio_PiCreateHandle()
* @param[in]  timeoutTicks   Timeout in ticks (-1 = WAIT_FOREVER, 0 = NO_WAIT)
*
* @retval   #MIO_ER_OK   OK
* @retval   other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @see Examples of function mio_PiCreateHandle()<br><br>
*******************************************************************************/
SINT32 mio_PiUpdateOut(MIO_PIHANDLE PiHandle, SINT32 timeoutTicks);


/**
********************************************************************************
* @brief Calculate the scaled value of a channel from the given raw value
*        with result type REAL64.
*
* @note The raw value must have at least 4 bytes.
*
* @param[in]  DrvId         Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan          The number of the channel (1-n).
* @param[in]  pRawVal       Pointer to the value to be scaled
* @param[out] pScaledValue  Return of the scaled value
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_CalcScaledValueR64(void *DrvId, UINT32 Chan, const void *pRawVal,
                              REAL64 *pScaledValue);

/**
********************************************************************************
* @brief Calculate the scaled value of a channel from the given raw value
*        with result type REAL64.
*
* @note The raw value must have at least 4 bytes.
*
* @param[in]  scaleId       Scale ID returned by the function mio_GetChanScaleId()
* @param[in]  pRawVal       Pointer to the value to be scaled
* @param[out] pScaledValue  Return of the scaled value
*
* @retval   #MIO_ER_OK   OK
* @retval   other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_CalcScaledValueR64ById(MIO_CHANSCALE_ID scaleId, const void *pRawVal,
                                  REAL64 *pScaledValue);

/**
********************************************************************************
* @brief Calculate the scaled value of a channel from the given raw value
*        with result type SINT32.
*
* @note The raw value must have at least 4 bytes.
*
* @param[in]  DrvId         Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan          The number of the channel (1-n).
* @param[in]  pRawVal       Pointer to the value to be scaled
* @param[out] pScaledValue  Return of the scaled value
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_CalcScaledValueS32(void *DrvId, UINT32 Chan, const void *pRawVal,
                              SINT32 *pScaledValue);

/**
********************************************************************************
* @brief Calculate the scaled value of a channel from the given raw value
*        with result type SINT32.
*
* @note The raw value must have at least 4 bytes.
*
* @param[in]  scaleId       Scale ID returned by the function mio_GetChanScaleId()
* @param[in]  pRawVal       Pointer to the value to be scaled
* @param[out] pScaledValue  Return of the scaled value
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_CalcScaledValueS32ById(MIO_CHANSCALE_ID scaleId, const void *pRawVal,
                                  SINT32 *pScaledValue);

/**
********************************************************************************
* @brief Calculate the raw value of a channel from the given scaled value
*        with result type REAL64.
*
* @param[in]  DrvId         Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan          The number of the channel (1-n).
* @param[out] pRawVal       Return of the raw value
* @param[in]  scaledValue   Scaled value for the back-calculation
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_CalcRawValueR64(void *DrvId, UINT32 Chan, void *pRawVal, REAL64 scaledValue);

/**
********************************************************************************
* @brief Calculate the raw value of a channel from the given scaled value
*        with result type REAL64.
*
* @param[in]  scaleId       Scale ID returned by the function mio_GetChanScaleId()
* @param[out] pRawVal       Return of the raw value
* @param[in]  scaledValue   Scaled value for the back-calculation
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_CalcRawValueR64ById(MIO_CHANSCALE_ID scaleId, void *pRawVal, REAL64 scaledValue);

/**
********************************************************************************
* @brief Calculate the raw value of a channel from the given scaled value
*        with result type SINT32.
*
* @param[in]  DrvId         Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan          The number of the channel (1-n).
* @param[out] pRawVal       Return of the raw value
* @param[in]  scaledValue   Scaled value for the back-calculation
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_CalcRawValueS32(void *DrvId, UINT32 Chan, void *pRawVal, SINT32 scaledValue);

/**
********************************************************************************
* @brief Calculate the raw value of a channel from the given scaled value
*        with result type SINT32.
*
* @param[in]  scaleId       Scale ID returned by the function mio_GetChanScaleId()
* @param[out] pRawVal       Return of the raw value
* @param[in]  scaledValue   Scaled value for the back-calculation
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_CalcRawValueS32ById(MIO_CHANSCALE_ID scaleId, void *pRawVal, SINT32 scaledValue);

/**
********************************************************************************
* @brief Get the scaled value of a channel if the target data type of the scaling
*        is #REAL64.
*
* @note Use of the function mio_GetScaledValueR64ById() is recommended.
*
* @param[in]  DrvId        Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan         The number of the channel (1-n).
* @param[out] pScaledValue Return of the scaled value
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_GetScaledValueR64(void *DrvId, UINT32 Chan, REAL64 *pScaledValue);

/**
********************************************************************************
* @brief Get the scaled value of a channel using the channel scale ID.
*
* This function makes it possible to access the scaled channel value more
* quickly than with the mio_GetScaledValueR64() function. In order to use this
* function, the target data type of the channel scaling must be #REAL64.
*
* @param[in]  DrvId         Module instance handle returned by the function mio_GetDrv().
* @param[in]  scaleId       Scale ID returned by the function mio_GetChanScaleId()
* @param[out] pScaledValue  Return of the scaled value
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_GetScaledValueR64ById(void *DrvId, MIO_CHANSCALE_ID scaleId, REAL64 *pScaledValue);

/**
********************************************************************************
* @brief Set the scaled value of a channel if the target data type of the scaling
*        is #REAL64.
*
* @note Use of the function mio_SetScaledValueR64ById() is recommended.
*
* @param[in]  DrvId        Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan         The number of the channel (1-n).
* @param[out] scaledValue  Scaled value that is to be set
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_SetScaledValueR64(void *DrvId, UINT32 Chan, REAL64 scaledValue);

/**
********************************************************************************
* @brief Set the scaled value of a channel using the channel scale ID.
*
* This function makes it possible to access the scaled channel value more
* quickly than with the mio_SetScaledValueR64() function. In order to use this
* function, the target data type of the channel scaling must be #REAL64.
*
* @param[in]  DrvId        Module instance handle returned by the function mio_GetDrv().
* @param[in]  scaleId       Scale ID returned by the function mio_GetChanScaleId()
* @param[out] scaledValue  Scaled value that is to be set
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_SetScaledValueR64ById(void *DrvId, MIO_CHANSCALE_ID scaleId, REAL64 scaledValue);

/**
********************************************************************************
* @brief Get the scaled value of a channel if the target data type of the scaling
*        is #SINT32.
*
* @note Use of the function mio_GetScaledValueS32ById() is recommended.
*
* @param[in]  DrvId        Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan         The number of the channel (1-n).
* @param[out] pScaledValue Return of the scaled value
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_GetScaledValueS32(void *DrvId, UINT32 Chan, SINT32 *pScaledValue);

/**
********************************************************************************
* @brief Get the scaled value of a channel using the channel scale ID.
*
* This function makes it possible to access the scaled channel value more
* quickly than with the mio_GetScaledValueS32() function. In order to use
* this function, the target data type of the channel scaling must be #SINT32.
*
* @param[in]  DrvId         Module instance handle returned by the function mio_GetDrv().
* @param[in]  scaleId       Scale ID returned by the function mio_GetChanScaleId()
* @param[out] pScaledValue  Return of the scaled value
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_GetScaledValueS32ById(void *DrvId, MIO_CHANSCALE_ID scaleId, SINT32 *pScaledValue);

/**
********************************************************************************
* @brief Set the scaled value of a channel if the target data type of the scaling
*        is #SINT32.
*
* @note Use of the function mio_SetScaledValueS32ById() is recommended.
*
* @param[in]  DrvId        Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan         The number of the channel (1-n).
* @param[out] scaledValue  Scaled value that is to be set
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_SetScaledValueS32(void *DrvId, UINT32 Chan, SINT32 scaledValue);

/**
********************************************************************************
* @brief Set the scaled value of a channel using the channel scale ID.
*
* This function makes it possible to access the scaled channel value more
* quickly than with the mio_SetScaledValueS32() function. In order to use
* this function, the target data type of the channel scaling must be #SINT32.
*
* @param[in]  DrvId         Module instance handle returned by the function mio_GetDrv().
* @param[in]  scaleId       Scale ID returned by the function mio_GetChanScaleId()
* @param[out] scaledValue   Scaled value that is to be set
*
* @retval   #MIO_ER_OK  OK
* @retval   other       Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_SetScaledValueS32ById(void *DrvId, MIO_CHANSCALE_ID scaleId, SINT32 scaledValue);

/**
********************************************************************************
* @brief Get a channel ID which can be used to read or write the scaled value
*        of the channel more efficiently than it would be possible by indicating
*        the channel number.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (1-n).
* @param[out] pScaleId  Storage location of the scale ID
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* @see Functions mio_GetScaledValueR64ById(), mio_GetScaledValueS32ById(),
*      mio_SetScaledValueR64ById() and mio_SetScaledValueS32ById().
*******************************************************************************/
SINT32 mio_GetChanScaleId(void *DrvId, UINT32 Chan, MIO_CHANSCALE_ID *pScaleId);

/**
********************************************************************************
* @brief Set an user-specific function for calculating the scaling or
*        the inverse scaling.
*
* @note Scaling functions that have already been set are overwritten for this
*       channel.
*
* @param[in]  DrvId        Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan         The number of the channel (1-n).
* @param[in]  scaleFct     Scaling function
* @param[in]  invScaleFct  Inverse scaling functions for calculating the scaled
*                          value back to the raw value
* @param[in]  pData        Data pointer that is passed to the scaling function
*                          and the inverse scaling function
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_SetScaleFct(void *DrvId, UINT32 Chan, MIO_SCALEFCT scaleFct,
                       MIO_INVSCALEFCT invScaleFct, void *pData);

/**
********************************************************************************
* @brief Get channel scaling target type format and length information.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (1-n).
* @param[out] pFormat   Where to place the format (SVI_F_*)
* @param[out] pLen      Where to place the length of the channel
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_ScaleGetChanFormat(void *DrvId, UINT32 Chan, UINT32 *pFormat, UINT32 *pLen);

/**
********************************************************************************
* @brief Set channel scaling unit.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  Chan      The number of the channel (1-n).
* @param[in]  pUnit     New Unit of scaled value. <br>Max unit length are 12 characters.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*******************************************************************************/
SINT32 mio_ScaleSetChanUnit(void *DrvId, UINT32 Chan, CHAR *pUnit);


/*--- Macros for SEM201 ---*/

/**
********************************************************************************
* @brief With the function mio_GetSercValue(), any desired SERCOS value is read.
*
* As opposed to the function mio_GetValue(), with which only the primary SERCOS
* (`ValId = 0`) can be read.
*
* @note The mio_GetSercValue() is not a function on its own. The
* mio_GetSercValue() is a macro defined in the header file sem201.h that ends
* in the function mio_GetValue(). The parameter `ValId` is packed into the
* higher ranking word of the parameter `Channel`.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  ValId     Indicates the number of the cyclic actual value.<br>
*                       Possible values: 1 to 20<br>
*                       The assignment of the parameter `ValId` to a SERCOS value
*                       is made by configuration in `MConfig.ini` file.
* @param[in]  Channel   The parameter `Channel` is the node number on the Sercos bus.
* @param[out] pValue    Transfer of the value buffer<br>
*                       The read values are always returned as a 32-bit value,
*                       also for digital inputs or analog inputs with 16-bit width.
*                       Analog values are calibrated online if necessary.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_GetSercValue.c mio_GetSercValue
*******************************************************************************/
#define mio_GetSercValue(DrvId, ValId, Channel, pValue) \
        mio_GetValue(DrvId, ((ValId)<<16) + ((Channel) & 0xFFFF), pValue)

/**
********************************************************************************
* @brief With the function mio_SetValue() the primary Sercos value (ValId = 0)
*        can be written.
*
* Special function, in order to write any Sercos value through the additional
* parameter `ValId`.
*
* @note mio_SetSercValue is not an autonomous function, but rather it is a
* macro defined in the header file `sem201.h`, that ends in the function
* mio_SetValue(). `ValId` is compressed in the higher value word of `Channel`.
*
* @param[in]  DrvId     Module instance handle returned by the function mio_GetDrv().
* @param[in]  ValId     Indicates the number of the cyclic actual value.<br>
*                       Possible values: 1 to 20<br>
*                       The assignment of the parameter `ValId` to a SERCOS value
*                       is made by configuration in `MConfig.ini` file.
* @param[in]  Channel   The parameter `Channel` is the node number on the Sercos bus.
* @param[out] Value     Transfer of the new value<br>
*                       The new value is always transferred as a signed value,
*                       even for digital or analog outputs with little data.
*                       Analog values are calibrated online prior to writing if
*                       necessary.
*
* @retval  #MIO_ER_OK   OK
* @retval  other        Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
*
* <b>Example</b>
* @snippet doc_mio_SetSercValue.c mio_SetSercValue
*******************************************************************************/
#define mio_SetSercValue(DrvId, ValId, Channel, Value) \
        mio_SetValue(DrvId, ((ValId)<<16) + ((Channel) & 0xFFFF), Value)

/*--- Macros for IOP201 ---*/

#define mio_GetIopValue(DrvId, Channel, Angle, pValue) \
        mio_GetValue(DrvId, (Angle << 16) | Channel, pValue) /**< Macro for IOP201 */


/*--- Definition of Variables ---*/

EXTERN SINT32 mio_MinStations;          /**< Minimum number of stations */
EXTERN SINT32 mio_MaxStations;          /**< Minimum number of stations */
EXTERN UINT32 mio_BadStations;          /**< Unusable stations bit coded */
EXTERN BOOL8 mio_PiUseProcImg;          /**< Variable to check if the process image is used */
EXTERN UINT32 mio_CpuSlotNb;            /**< CPU slot number */


#endif /* _ASMLANGUAGE */

/** @} */

#ifdef __cplusplus
}
#endif
/** @} */

#endif
