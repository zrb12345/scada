/**
********************************************************************************
* @file     Cpn_e.h
* @author   Bertel
*
* @brief Dieses File enthaelt alle Definitionen und Deklarationen
*        welche vom Modul exportiert werden, und von anderen Modulen auf
*        einer anderen CPU genutzt werden koennen.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef CPN_E__H                        /* Problemvermeidung bei mehr- */
#define CPN_E__H                        /* maligem Inkludieren des Files */

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/*--- Defines ---*/

#define CPN_INFOLEN_A       64          /* Laenge von Fehlerinfos; inkl '\0'*/

/* moegliche Werte fuer CPN_DSP.SegType */
#define CPN_S_FIRST         0x01
#define CPN_S_MID           0x02
#define CPN_S_LAST          0x04

/* moegliche Werte fuer den Kernelstatus (CPN_CMD_GETSTATE) */
#define CPN_KS_OK           0x0000
#define CPN_KS_BUSSOFF      0x0010
#define CPN_KS_ESTATSET     0x0021
#define CPN_KS_CANOVR       0x0022
#define CPN_KS_HPTXOVR      0x0023
#define CPN_KS_HPRXOVR      0x0024
#define CPN_KS_GUARDFAIL    0x0025

/* moegliche Kommandos fuer mio_DoCmd(); */
/* HINWEIS: die Kommandos muessen fuer alle Treiber, die ein CAN-Netzwerk */
/*      abbilden (cm202.m, me203.m,..), gleich sein. */
#define CPN_CMD_POLLFUNC    1
#define CPN_CMD_INTFUNC     2
#define CPN_CMD_RAMINF      3
#define CPN_CMD_SNDFUNC     4
#define CPN_CMD_RECFUNC     5
#define CPN_CMD_GETSTATE    6
#define CPN_CMD_GETEMY      7
#define CPN_CMD_GETDEVEMY   8
#define CPN_CMD_UPDATESW    MIO_CMD_UPDATESW
#define CPN_CMD_RDWRSDO     10
#define CPN_CMD_GETVARINF   11
#define CPN_CMD_GETVAR      12
#define CPN_CMD_SETVAR      13
#define CPN_CMD_SETDPRAM    14
#define CPN_CMD_RDWRSDOFILE 15
#define CPN_CMD_RDEMYLST    16
#define CPN_CMD_SETLOCAL    17
#define CPN_CMD_NETINIT     18
#define CPN_CMD_SETEMY      19
#define CPN_CMD_RESETEMY    20
#define CPN_CMD_SENDEMY     21
#define CPN_CMD_SETAPPREADY 22
#define CPN_CMD_HWCONSREQ   23
#define CPN_CMD_SENDMSG     24
#define CPN_CMD_ENABLERXMSG 25
#define CPN_CMD_RUNNOAPP    26
#define CPN_CMD_CALLRWSDO   27
#define CPN_CMD_DONERWSDO   28
#define CPN_CMD_NETDEINIT   29
#define CPN_CMD_LOGSTART    30
#define CPN_CMD_LOGSTOP     31
#define CPN_CMD_STATECHANGE 32

/* Command for C-Unit Tests */
#define CPN_CMD_TST_SMIRXMSG    1001    /* Simulate the receiving of a CAN Message */

/* moegliche Werte fuer CAN_CARD.Mode */
#define CPN_M_UNUSED        0           /* CAN-Anschluss nicht verwendet */
#define CPN_M_SINGLE        1           /* nicht mehr verwendet */
#define CPN_M_MASTER        1           /* CAN-Netzwerk mit Masterbetrieb */
#define CPN_M_DOUBLE        2           /* nicht mehr verwendet */
#define CPN_M_SLAVE         3           /* Netzwerk wird als Slave betrieben */
#define CPN_M_EXTSINGLE     4           /* nicht mehr verwendet */
#define CPN_M_LOCAL         0x8000      /* CANopen-Kernel lauft auf local auf MP */
#define CPN_M_MODMASK       0x000f      /* Maske fuer Kanalspezifschen Mode */
#define CPN_M_CHSHIFT       8           /* Mode Shift fuer 2ten Kanal */

/* Defintionen von WBE (CM202 Firmware) */

/* Fn Calass */

#define CMD_BIO_FnClass     0x0000      /* BB-BOIS Functions */
#define CMD_FPG_FnClass     0x0100      /* Flash-Programming Functions */
#define CMD_CAN_FnClass     0x0200      /* Genneral CM202 Functions */
#define CMD_DCF_FnClass     0x0300      /* Device-Configuration Functions */
#define CMD_DSP_FnClass     0x0400      /* CANopen Functions */
#define CMD_COP_FnClass     0x0500      /* CANopen Functions */

/* Function Call Code */

#define CMD_BIO_CommReset               (CMD_BIO_FnClass + 0x00)
#define CMD_BIO_InitExtAddrOffset       (CMD_BIO_FnClass + 0x01)
#define CMD_BIO_InitIntEnable           (CMD_BIO_FnClass + 0x02)

#define CMD_BIO_InitAliveCheck          (CMD_BIO_FnClass + 0x05)
#define CMD_BIO_SetRdyLed               (CMD_BIO_FnClass + 0x06)
#define CMD_BIO_SwitchLed               (CMD_BIO_FnClass + 0x07)
#define CMD_BIO_LockFirmware            (CMD_BIO_FnClass + 0x08)
#define CMD_BIO_CrashTest               (CMD_BIO_FnClass + 0x09)

#define CMD_DSP_DCF_DateiTransfer       (CMD_DSP_FnClass + 0x01)
#define CMD_DSP_CAN_InitChan            (CMD_DSP_FnClass + 0x02)
#define CMD_DSP_CAN_InitNode            (CMD_DSP_FnClass + 0x04)
#define CMD_DSP_COP_WriteSDO            (CMD_DSP_FnClass + 0x07)
#define CMD_DSP_COP_ReadSDO             (CMD_DSP_FnClass + 0x08)
#define CMD_DSP_COP_WriteSDO2           (CMD_DSP_FnClass + 0x17)
#define CMD_DSP_COP_ReadSDO2            (CMD_DSP_FnClass + 0x18)


#define CMD_CAN_InitCard                (CMD_CAN_FnClass + 0x01)
#define CMD_CAN_InitChan                (CMD_CAN_FnClass + 0x02)
#define CMD_CAN_InitNetwork             (CMD_CAN_FnClass + 0x03)
#define CMD_CAN_InitNode                (CMD_CAN_FnClass + 0x04)
#define CMD_CAN_SwitchLocal             (CMD_CAN_FnClass + 0x05)

#define CMD_COP_EnableSyncInt           (CMD_COP_FnClass + 0x01)
#define CMD_COP_DisableSyncInt          (CMD_COP_FnClass + 0x02)
#define CMD_COP_InitNetwork             (CMD_COP_FnClass + 0x03)
#define CMD_COP_StartNetwork            (CMD_COP_FnClass + 0x04)
#define CMD_COP_StartNode               (CMD_COP_FnClass + 0x05)
#define CMD_COP_StopNode                (CMD_COP_FnClass + 0x06)
#define CMD_COP_WriteSDO                (CMD_COP_FnClass + 0x07)
#define CMD_COP_ReadSDO                 (CMD_COP_FnClass + 0x08)
#define CMD_COP_GetNodeState            (CMD_COP_FnClass + 0x09)
#define CMD_COP_GetLocalNodeID          (CMD_COP_FnClass + 0x0a)
#define CMD_COP_GetEmergencyObj         (CMD_COP_FnClass + 0x0b)
#define CMD_COP_NmtCmd                  (CMD_COP_FnClass + 0x0c)
#define CMD_COP_LmtCmd                  (CMD_COP_FnClass + 0x0d)
#define CMD_COP_CanAttachEvent          (CMD_COP_FnClass + 0x0e)
#define CMD_COP_CanDetachEvent          (CMD_COP_FnClass + 0x0f)
#define CMD_COP_CanSendMsg              (CMD_COP_FnClass + 0x10)
#define CMD_COP_CanEnableRxMsg          (CMD_COP_FnClass + 0x11)
#define CMD_COP_CanWrSdo                (CMD_COP_FnClass + 0x12)
#define CMD_COP_CanRdSdo                (CMD_COP_FnClass + 0x13)

#define CMD_FPG_Load                    (CMD_FPG_FnClass + 0x01)
#define CMD_FPG_Erase                   (CMD_FPG_FnClass + 0x02)
#define CMD_FPG_Prepare                 (CMD_FPG_FnClass + 0x03)
#define CMD_FPG_Prog                    (CMD_FPG_FnClass + 0x04)
#define CMD_FPG_Run                     (CMD_FPG_FnClass + 0x05)

/* result codes */

#define EC_Ok               0x0000  
#define EC_ResultValid      0x0000  
#define EC_ErrorResult      0xFFFF
#define EC_Error            0x8000

/* ----- error result codes --------| Err-Bit | Fn Calass ----| Er Number - */

#define EC_InvalidOffset                (EC_Error + CMD_BIO_FnClass + 0x01)
#define EC_OutOfMemory                  (EC_Error + CMD_BIO_FnClass + 0x02)

#define EC_DSP_FirstSegmentMissing      (EC_Error + CMD_DSP_FnClass + 0x01)
#define EC_DSP_BufferOverflow           (EC_Error + CMD_DSP_FnClass + 0x02)
#define EC_DSP_ProtokollError           (EC_Error + CMD_DSP_FnClass + 0x03)
#define EC_DSP_UnnownFunctionCode       (EC_Error + CMD_DSP_FnClass + 0x04)

#define EC_DCF_RangeNodeID              (EC_Error + CMD_DCF_FnClass + 0x01)
#define EC_DCF_NodeDoubleDefined        (EC_Error + CMD_DCF_FnClass + 0x02)
#define EC_DCF_MasterDoubleDefined      (EC_Error + CMD_DCF_FnClass + 0x03)
#define EC_DCF_ObjectNotSupported       (EC_Error + CMD_DCF_FnClass + 0x04)
#define EC_DCF_ObjectDoubleDefined      (EC_Error + CMD_DCF_FnClass + 0x05)
#define EC_DCF_ObjectInconsistent       (EC_Error + CMD_DCF_FnClass + 0x06)
#define EC_DCF_OutOfObjectMemSize       (EC_Error + CMD_DCF_FnClass + 0x07)
#define EC_DCF_OutOfObjectEntry         (EC_Error + CMD_DCF_FnClass + 0x08)
#define EC_DCF_OutOfMapEntry            (EC_Error + CMD_DCF_FnClass + 0x09)
                
#define EC_FPG_ProgramFail              (EC_Error + CMD_FPG_FnClass + 0x01)
#define EC_FPG_ProgramTimeout           (EC_Error + CMD_FPG_FnClass + 0x02)
#define EC_FPG_EraseTimeout             (EC_Error + CMD_FPG_FnClass + 0x03)
#define EC_FPG_WrongIntelHexLine        (EC_Error + CMD_FPG_FnClass + 0x04)
#define EC_FPG_WrongReccordSize         (EC_Error + CMD_FPG_FnClass + 0x05)
#define EC_FPG_WrongReccordType         (EC_Error + CMD_FPG_FnClass + 0x06)
#define EC_FPG_WrongReccordChecksum     (EC_Error + CMD_FPG_FnClass + 0x07)
#define EC_FPG_InternalStateError       (EC_Error + CMD_FPG_FnClass + 0x08)
#define EC_FPG_Prog_Size_Exceeded       (EC_Error + CMD_FPG_FnClass + 0x09)

#define EC_CAN_BaudrateNotSupported     (EC_Error + CMD_CAN_FnClass + 0x01)
#define EC_CAN_ModeNotSuported          (EC_Error + CMD_CAN_FnClass + 0x02)
#define EC_CAN_ChanNotSuported          (EC_Error + CMD_CAN_FnClass + 0x03)
#define EC_CAN_NodeNotSuported          (EC_Error + CMD_CAN_FnClass + 0x04)

#define EC_COP_UndefinedModule          (EC_Error + CMD_COP_FnClass + 0x81)
#define EC_COB_NmtCmdNotSuported        (EC_Error + CMD_CAN_FnClass + 0x82)
#define EC_COP_k_NO                     (EC_Error + CMD_COP_FnClass + 0x02)
#define EC_COP_k_SDO_STATE              (EC_Error + CMD_COP_FnClass + 0xfc)
#define EC_COP_k_INVALID_VALUE          (EC_Error + CMD_COP_FnClass + 0x0c)
#define EC_COP_k_ERR                    (EC_Error + CMD_COP_FnClass + 0x01)
#define EC_COP_k_SDO_TIMEOUT            (EC_Error + CMD_COP_FnClass + 0xfd)
#define EC_COP_k_NO_NMM                 (EC_Error + CMD_COP_FnClass + 0xfe)

#define SDO_HDL_ERR         -1
#define SDO_STATE_ERR       -2
#define SDO_TOGGLE_ERR      -3
#define SDO_LEN_ERR         -5
#define SDO_SEND_ERR        -6
#define SDO_ABORT_ERR       -7
#define SDO_TIMEOUT_ERR     -8

#define DPM_MEMORY_SIZE     2048        /* Max Dualport Memory Size  */
#define DPM_DATA_SIZE       (DPM_MEMORY_SIZE - sizeof(DPM_s_MIO_Reg))    
#define DPM_FID_SIZE        64          /* Function-Interface Data Size */
#define DPM_EID_SIZE        32          /* Event-Interface Data Size */


/*--- Strukturen ---*/

struct cpn_dsp                          /* Struktur vom Datensegmentierungs*/
{                                       /* Protokoll */
    UINT8       SegType;                /* 0x01 -> 1. Segment */
                                        /* 0x02 -> mittleres Segment */
                                        /* 0x04 -> letztes Segment */
    UINT8       SegLen;                 /* Laenge vom Segment (1-58) */
    UINT32      DataLen;                /* Gesamtlaenge der Daten */
    UINT8       Data[1];                /* die eigentlichen Daten */
} __attribute__ ((packed));

typedef struct cpn_dsp CPN_DSP;

typedef struct                          /* Struktur fuer die Init. der */
{                                       /* CAN-Karte */
    UINT16      Mode;
} CPN_CARD;

typedef struct                          /* Struktur fuer die Daten von */
{                                       /* optionalen Nodes */
    UINT8       NodeId;                 /* Id vom betroffenen Node */
    UINT8       Optional;               /* 1 -> Node muss in Bootphase */
                                        /* nicht vorhanden sein */
} CPN_OPTNODE;

typedef struct                          /* Struktur fuer die Init. eines */
{                                       /* Kanales der CM202 */
    UINT16      ChanNb;                 /* für welchen Kanal (0,1) */
    UINT16      Baudrate;               /* Baurate in kBit */
    UINT16      InhibitTime;            /* Verzoegerungszeit vom CAN-Master*/
                                        /* in us; 0 -> Defaultwert */
    UINT16      SdoTime;                /* Timeout fuer SDO-Transfer in ms */
    UINT16      NodeTime;               /* Timeout fuer Node Start/Stop(ms)*/
    UINT16      NbOfNode;               /* Anzahl der optionalen Nodes */
    CPN_OPTNODE Node[1];
} CPN_CHAN;

typedef struct DPM_s_MIO_Reg 
{
    UINT16 ErrFlgReg;                   /* Error-Interrupt Flag Reg. IFR */
    UINT16 KernelStateReg;              /* CANopen Kernel Status */
    UINT16 NmsStateReg;                 /* Netzwerkmanagement Status */
    UINT16 DPMLenReg;                   /* Groesse vom DP-Memory */
    UINT16 ResReg;                      /* FI Result register */

    union 
    {   // FI-Data-Buffer       
        UINT8   U8 [DPM_FID_SIZE]; 
        UINT16  U16[1]; 
        UINT32  U32[1];
        CHAR    SU8[1]; 
        SINT16  S16[1]; 
        SINT32  S32[1]; 
    } FID;
    union
    {   // Error-Int-Data-Buffer        
        UINT8   U8 [DPM_EID_SIZE]; 
        UINT16  U16[1]; 
        UINT32  U32[1]; 
        CHAR    SU8[1]; 
        SINT16  S16[1]; 
        SINT32  S32[1]; 
    } EID;
} DPM_s_MIO_Reg;


typedef struct DPM_s_DPM 
{       
    DPM_s_MIO_Reg MIO_Reg; 
    UINT8         DPM_Data[DPM_DATA_SIZE];
    UINT16        TestMemSize;
} DPM_s_DPM;


struct cpn_emy                          /* Daten einer Emergency Message */
{                                       /* gemaess CiA 405 Standard */
    UINT16      NodeId;
    UINT16      ErrorCode;
    UINT8       ErrorRegister;
    UINT8       ErrorField[5];
} __attribute__ ((packed));             /* CRID#38760 avoid problem with Bug in GCC V4.1.2 */
                                        /* concerns also all the following typedefs   */
typedef struct cpn_emy CPN_EMY;

typedef struct                          /* Datenstruktur fuer 'SDO lesen/ */
{                                       /* schreiben' */
    UINT16      NodeId;                 /* Knotennummer (1-127) */
    UINT16      Index;                  /* Objektindex */
    UINT16      SubIndex;               /* Objektsubindex */
    UINT16      Length;                 /* Laenge vom Objekt */
    UINT8       Data[0];                /* gelesene/zu schreibende Daten */
} CPN_C_RWSDO;

struct cpn_c_rwsdo2                     /* Datenstruktur fuer 'SDO lesen/ */
{                                       /* schreiben' 32-Bit DSize field */
    UINT16      NodeId;
    UINT16      Index;
    UINT16      SubIndex;
    UINT32      Length;
    UINT8       Data[0];
} __attribute__ ((packed));

typedef struct cpn_c_rwsdo2 CPN_C_RWSDO2;

typedef struct                          /* Datenstruktur fuer Fehlerinfo */
{                                       /* bei SDO-Zugriff (von CM202) */
    SINT16      ErrorCode;              /* allgemeiner Fehlercode */
    UINT8       ErrorInfo[8];           /* Detailinfo zu Fehler */
} CPN_C_SDOERR;

typedef union                           /* Send und Receive fuer SDO Call */
{
    CPN_C_RWSDO  Snd;
    CPN_C_SDOERR Rec;
} CPN_C_SDOCALL;

typedef union                           /* Send und Receive fuer SDO Call */
{                                       /* 32-Bit DSize field */
    CPN_C_RWSDO2 Snd;
    CPN_C_SDOERR Rec;
} CPN_C_SDOCALL2;

typedef struct                          /* Daten fuer 'Start/Stop Node' */
{
    UINT16      NodeId;
} CPN_C_SSNODE;

typedef struct                          /* Error fuer 'Start/Stop Node' */
{
    UINT8       Info[CPN_INFOLEN_A];
} CPN_C_NODEERR;

struct cpn_c_nmtcmd                     /* Nmt-Command senden */
{                               
    UINT16      NodeId;                 /* 1 - 64 */
    UINT16      Cmd;                    /* z.B. Reset Node */
    UINT16      Value;                  /* z.B. Sync-Period */
} __attribute__ ((packed));

typedef struct cpn_c_nmtcmd CPN_C_NMTCMD;

struct cpn_c_lmtmsg                     /* Lmt-Message daten */
{                               
    UINT8  cs;                          /* Command Specifier */
    UINT8  buffer[7];                   /* additional cmd data */
} __attribute__ ((packed));

typedef struct cpn_c_lmtmsg CPN_C_LMTMSG;

struct cpn_c_lmtcmd                     /* Lmt-Command senden */
{                               
    UINT16       RespTime;              /* 16-Bit in mS */
    CPN_C_LMTMSG LmtMsg;                /* z.B. Cfg Module ID */
} __attribute__ ((packed));

typedef struct cpn_c_lmtcmd CPN_C_LMTCMD;

struct cpn_c_emcmsg                     /* Emy-Message senden */
{                               
    UINT16      EmyErrorCode;           /* Defined in DS-301 */
    UINT8       ErrorRegiser;           /* Defined in DS-301 */
    UINT8       ErrorField[5];          /* Additional Info */
} __attribute__ ((packed));

typedef struct cpn_c_emcmsg CPN_C_EMYMSG;

/*--- Funktionsprototyping ---*/

/*--- Variablendefinitionen ---*/

#ifdef __cplusplus
}
#endif

#endif
