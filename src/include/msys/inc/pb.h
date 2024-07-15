/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     pb.h
* @author   Fritsche
* @brief    Profibus Server
*           This file contains all definitions and declarations exported by
*           the Profibus Server, that could be used by modules running on
*           another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef PB__H
#define PB__H

#ifdef __cplusplus
extern "C" {
#endif


#include <mtypes.h>

/**
 * @addtogroup PROFIBUS-DEF
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
#define PB_PROTVERS         2
#define PB_NETNAMELEN       20   /**< Size of network name  without '\0' termination */
#define PB_NETNAMELEN_A     ((PB_NETNAMELEN + 1 + 3) & 0xfffffffc)   /**< PB_NETNAMELEN + '\0' + aligned */
#define PB_NETNAME_PREFIX   "Net"    /**< Name prefix to build the default network name form the NetNbr Net[1..4] */
#define PB_MSTNAMELEN       32   /**< Size of DP master name (including the '\0' termination) */
#define PB_MAXNET           (3 + 1)  /**< Number of possible ProfiBus networks (3) */
#define PB_MINSLAVE         0    /**< First DP-Salve index address */
#define PB_MAXSLAVE         125  /**< Last  DP-Salve index address */
#define PB_GLOBALADR        127  /**< Multicast address */
#define PB_NOSLAVE          128  /**< Slave not configured */

/**
 * @anchor PB_CC_
 * @see pb_GlobalControl()
 * @see PB_GLOBALCONTROL_C.Command
 */
/**
 * @name Possible global control commands values
 * @{
 */

#define PB_CC_FREEZE    0x08     /**< Details see DIN 19245-3, page 83 */
#define PB_CC_UNFREEZE  0x04     /**< Details see DIN 19245-3, page 83 */
#define PB_CC_SYNC      0x20     /**< Details see DIN 19245-3, page 83 */
#define PB_CC_UNSYNC    0x10     /**< Details see DIN 19245-3, page 83 */
/** @} */

/**
 * @anchor PB_S_
 * @brief For more details see also DIN 19245-3, page 83.
 * @see pb_SetMode()
 * @see pb_GetMode()
 * @see PB_SETMODE_C.USIFState
 * @see PB_GETMODE_R.USIFState
 */
/**
 * @name Possible values for user interface state (operating mode) of the PB network
 * @{
 */

#define PB_S_OFFLINE    0   /**< OFFLINE state isn't currently supported by the DPM200 module */
#define PB_S_STOP       0x40     /**< STOP mode, no process data exchange */
#define PB_S_CLEAR      0x80     /**< CLEAR mode, process data exchange with zeros for all outputs */
#define PB_S_OPERATE    0xc0     /**< OPERATE mode, normal operating mode with process data exchange */
/** @} */

/**
 * @anchor PB_E_
 */
/**
 * @name Possible error codes for PB Library-Functions and PB_*.RetCode
 * @{
 */

#define PB_E_OK         (M_E_OK)     /**< @copybrief #M_E_OK */
#define PB_E_FAILED     (M_ES_PB | M_E_FAILED)   /**< @copybrief #M_E_FAILED */
#define PB_E_IV         (M_ES_PB | M_E_PARM)     /**< @copybrief #M_E_PARM */
#define PB_E_NO         (M_ES_PB | M_E_INVSTATE)     /**< @copybrief #M_E_INVSTATE */
#define PB_E_DS         (M_ES_PB | M_E_NODE)     /**< @copybrief #M_E_NODE */
#define PB_E_TIMEOUT    (M_ES_PB | M_E_TIMEOUT)  /**< @copybrief #M_E_TIMEOUT */
/** @} */
/** @} end group PROFIBUS-DEF */

/**
 * @addtogroup PROFIBUS-SMI
 * @{
 */

/**
 * @anchor PB_PROC_
 */
/**
 * @name Possible SMI Commands
 * @{
 */

/**
 * @brief Get network number
 *
 * @param[in]   #PB_GETNETNB_C
 * @param[out]  #PB_GETNETNB_R
 *
 * @return #PB_E_OK for success, or <tt>< 0</tt> in case of an error
 * @see pb_GetNetNumber()
 */
#define PB_PROC_GETNETNB        100
/**
 * @brief Set mode of user interface
 *
 * @param[in]   #PB_SETMODE_C
 * @param[out]  #PB_SETMODE_R
 *
 * @return #PB_E_OK for success, or <tt>< 0</tt> in case of an error
 * @see pb_SetMode()
 */
#define PB_PROC_SETMODE         102
/**
 * @brief Get mode of user interface
 *
 * @param[in]   #PB_GETMODE_C
 * @param[out]  #PB_GETMODE_R
 *
 * @return #PB_E_OK for success, or <tt>< 0</tt> in case of an error
 * @see pb_GetMode()
 */
#define PB_PROC_GETMODE         104
/**
 * @brief Send command to slave(s)
 *
 * @param[in]   #PB_GLOBALCONTROL_C
 * @param[out]  #PB_GLOBALCONTROL_R
 *
 * @return #PB_E_OK for success, or <tt>< 0</tt> in case of an error
 * @see pb_GlobalControl()
 */
#define PB_PROC_GLOBALCONTROL   106
/**
 * @brief Set new bus parameters
 *
 * @param[in]   #PB_LOADBUSPAR_C
 * @param[out]  #PB_LOADBUSPAR_R
 *
 * @return #PB_E_OK for success, or <tt>< 0</tt> in case of an error
 * @see pb_LoadBusPar()
 */
#define PB_PROC_LOADBUSPAR      108
/**
 * @brief Get actual bus parameters
 *
 * @param[in]   #PB_READBUSPAR_C
 * @param[out]  #PB_READBUSPAR_R
 *
 * @return #PB_E_OK for success, or <tt>< 0</tt> in case of an error
 * @see pb_ReadBusPar()
 */
#define PB_PROC_READBUSPAR      110
/**
 * @brief Data synchronization
 *
 * @param[in]   #PB_READBUSPAR_C
 * @param[out]  #PB_READBUSPAR_R
 *
 * @return #PB_E_OK for success, or <tt>< 0</tt> in case of an error
 * @see pb_Mark()
 */
#define PB_PROC_MARK            112
/** @} */
/** @} PROFIBUS-SMI */

/**
 * @addtogroup PROFIBUS-STR
 * @{
 */

/**
 * @name Structures
 * @{
 */

/**
 * Possible values for PB_BUSPAR.Baudrate
 */
typedef enum
{
    PB_BR_9_6KBIT   = 0,        /**< 9.6 kbit/s */
    PB_BR_19_2KBIT  = 1,        /**< 19.2 kbit/s */
    PB_BR_93_75KBIT = 2,        /**< 93.75 kbit/s */
    PB_BR_187_5KBIT = 3,        /**< 187.5 kbit/s */
    PB_BR_500KBIT   = 4,        /**< 500.0 kbit/s */
    PB_BR_1500KBIT  = 6,        /**< 1500.0 kbit/s */
    PB_BR_3MBIT     = 7,        /**< 3.0 Mbit/s */
    PB_BR_6MBIT     = 8,        /**< 6.0 Mbit/s */
    PB_BR_12MBIT    = 9,        /**< 12.0 Mbit/s */
} PB_BAUDCODE;

/**
 * Bus parameter data record
 */
typedef struct
{
    UINT32      Bus_Para_Len;   /**< Size of record inc. length */
    UINT32      FDL_Add;        /**< Address of master (0-125) */
    PB_BAUDCODE Baudrate;       /**< Baudrate */
    UINT32      TSL;            /**< Slot time */
    UINT32      Min_TSDR;       /**< Min. station delay responder */
    UINT32      Max_TSDR;       /**< Max. station delay responder */
    UINT32      TQUI;           /**< Quite time */
    UINT32      TSET;           /**< Setup time */
    UINT32      TTR;            /**< Target rotation time */
    UINT32      G;              /**< Gap factor */
    UINT32      HSA;            /**< Highest active station address */
    UINT32      max_retry_limit;     /**< Retries if error occurs */
    UINT32      Pb_Flag;        /**< auto_clear on/off */
    UINT32      Min_Slave_Intervall;     /**< Min. slave interval time */
    UINT32      Poll_Timeout;   /**< Poll timeout */
    UINT32      Data_Control_Time;   /**< Data control time */
    UINT32      Reserved[2];    /**< Preserved entries */
    UINT32      Master_User_Data_Len;    /**< Size of Master_User_Data */
    UINT8       Master_Class2_Name[PB_MSTNAMELEN];   /**< Name of the PB master (class 2) */
    UINT8       Master_User_Data[1];     /**< Producer specific extension to bus parameters */
} PB_BUSPAR;

/**
 * Structure for the SMI-Call #PB_PROC_GETNETNB
 */
typedef struct
{
    CHAR8   NetName[PB_NETNAMELEN_A];    /**< Network name */
} PB_GETNETNB_C;

/**
 * Structure for the SMI-Reply #PB_PROC_GETNETNB
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  NetNumber;          /**< Network number */
} PB_GETNETNB_R;

/**
 * Structure for the SMI-Call #PB_PROC_SETMODE
 */
typedef struct
{
    UINT32  NetNumber;          /**< Selection of network */
    UINT32  USIFState;          /**< New status of user interface (@ref PB_S_) */
} PB_SETMODE_C;

/**
 * Structure for the SMI-Reply #PB_PROC_SETMODE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} PB_SETMODE_R;

/**
 * Structure for the SMI-Call #PB_PROC_GETMODE
 */
typedef struct
{
    UINT32  NetNumber;          /**< Selection of network */
} PB_GETMODE_C;

/**
 * Structure for the SMI-Reply #PB_PROC_GETMODE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  USIFState;          /**< Actual status of user interface (@ref PB_S_) */
} PB_GETMODE_R;

/**
 * Structure for the SMI-Call #PB_PROC_GLOBALCONTROL
 */
typedef struct
{
    UINT32  NetNumber;          /**< Selection of network */
    UINT32  RemoteAddr;         /**< Target Slave address 0..125 or multicast address 127 */
    UINT32  Command;            /**< Command to send (@ref PB_CC_) */
    UINT32  GroupSelect;        /**< Selection of group for multicast */
} PB_GLOBALCONTROL_C;

/**
 * Structure for the SMI-Reply #PB_PROC_GLOBALCONTROL
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} PB_GLOBALCONTROL_R;

/**
 * Structure for the SMI-Call #PB_PROC_LOADBUSPAR
 */
typedef struct
{
    UINT32      NetNumber;      /**< Selection of network */
    PB_BUSPAR   BusPar;         /**< Bus parameter set */
} PB_LOADBUSPAR_C;

/**
 * Structure for the SMI-Reply #PB_PROC_LOADBUSPAR
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} PB_LOADBUSPAR_R;

/**
 * Structure for the SMI-Call #PB_PROC_READBUSPAR
 */
typedef struct
{
    UINT32  NetNumber;          /**< Selection of network */
} PB_READBUSPAR_C;

/**
 * Structure for the SMI-Reply #PB_PROC_READBUSPAR
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    PB_BUSPAR   BusPar;         /**< Bus parameter set */
} PB_READBUSPAR_R;

/**
 * Mark information data
 */
typedef struct
{
    UINT32  Dia;                /**< TRUE if no data exchange */
    UINT32  CycleTime;          /**< Cycle Time in us */
} PB_MARKINFO;

/**
 * Structure for the SMI-Call #PB_PROC_MARK
 */
typedef struct
{
    UINT32  NetNumber;          /**< Selection of network */
} PB_MARK_C;

/**
 * Structure for the SMI-Reply #PB_PROC_MARK
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    PB_MARKINFO MarkInfo;       /**< Info of mark command */
} PB_MARK_R;


/**
 * ProfiBus process data object description
 * The structure below is used in the PLC Process Image Function of all PB
 * module drivers (returned by mio_GetProcImgFuncs()).
 */
typedef struct
{
    UINT16  number;     /**< ProfiBus Object number(0 based offset) */

    /**
     * Bit coded object type
     * - Bit 7   Consistent
     * - Bit 6   Format @n
     *       0/1 = Byte-/Word structure
     * - Bit 5-4 Input/Output @n
     *       00 = Empty @n
     *       01 = Input @n
     *       10 = Output @n
     *       11 = Input/Output(Not possible!!!!!)
     * - Bit 3-2 Analog/Digital @n
     *       00 = Not specified if analog or digital @n
     *       01 = Analog @n
     *       10 = Digital
     */
    UINT8   type;

    /**
     * Bit coded object flags
     * - Bit 6   Motorola/Intel format @n
     *       0  = Intel format @n
     *       1  = Motorola format
     * - Bit 5   Array of objects/Single object @n
     *       0  - Single object @n
     *       1  - Array of objects
     * - Bit 4-0 The Data type of the object(PBTYP_xxx) @n
     *       0  - PBTYP_Undefined  (No type defined) @n
     *       2  - PBTYP_Integer8   (INT8) @n
     *       3  - PBTYP_Unsigned8  (UINT8) @n
     *       4  - PBTYP_Integer16  (INT16) @n
     *       5  - PBTYP_Unsigned16 (UINT16) @n
     *       8  - PBTYP_Integer32  (INT32) @n
     *       9  - PBTYP_Unsigned32 (UINT32) @n
     *       10 - PBTYP_Real       (32 bit) @n
     *       11 - PBTYP_LReal      (64 bit)
     */
    UINT16  flags;

    /**
     * DP-RAM address
     * The Objects address as calculated in the pb2bf::Decode2bfFile() function
     * is the object offset in the input or output address area.
     */
    UINT16  dpAdr;
    UINT8   len;        /**< The length of the object, in bytes */
    UINT32  paOffset;   /**< Offset of this object in the ProfiBus PA */
} PBOBJENTRY;

/**
 * ProfiBus diagnose data object description
 */
typedef struct
{
    /**
     * 0:     This is the DP-Masters Dialog data
     * 1-125: Gives the 'Slave address' of the slave whose Dialog data this is.
     */
    UINT8   number;
    UINT8   len;            /**< The length of the object, in bytes */
    UINT32  paOffset;       /**< Offset of this object in the Profibus PA */
} PBDIAGENTRY;

/**
 * ProfiBus slave data header description
 */
typedef struct
{
    UINT16  size;           /**< Size of this structure AND the data to follow (PBOBJENTRY) structures */
    UINT16  slaveAdr;       /**< Slave address 1-125 (as given in the *.2BF file) */
    UINT16  nObjEntries;    /**< Objects contained in this slave */
    UINT32  reserve1;       /**< Reserved */
    UINT32  reserve2;       /**< Reserved */
} PBSLVHEADER;

/**
 * ProfiBus diagnostic data header description
 */
typedef struct
{
    UINT16  size;           /**< Size of this structure AND the data to follow (PBDIAGENTRY) structures */
    UINT16  nDiagEntries;   /**< The number of PBDIAGENTRY structures to follow this structure. */
    UINT32  reserve1;       /**< Reserved */
    UINT32  reserve2;       /**< Reserved */
} PBDIAGHEADER;

/**
 * ProfiBus network data header description
 */
typedef struct
{
    UINT16  size;           /**< Size of this structure AND the data to follow (PBSLVHEADER and PBOBJENTRY) structures */
    UINT16  netNumber;      /**< The net number of the ProfiBus is the 'Card number' as given in M-PLC */

    /**
     * Slaves contained in this Net
     * - 0:     There is no PBSLVHEADER structure after this structure
     * - 1-125: The number of PBSLVHEADER structures to follow
     */
    UINT16  nSlvEntries;

    /**
     * States if there is dialog data to follow
     * - 0: There is no PBDIAGHEADER structure after this structure
     * - 1: This structure is followed by a PBDIAGHEADER structure
     */
    UINT8   bDiagData;

    UINT32  pSrvData;       /**< DPM200 Server Data for the process-image- working-lists */
    UINT32  ulNetNum : 2;   /**< ProfiBus network number (since V3.50.01) */
    UINT32  VerCou : 8;     /**< Version counter */
    UINT32  Spare : 22;     /**< Reserved */
} PBNETHEADER;
/** @} */
/** @} PROFIBUS-STR */

#ifdef __cplusplus
}
#endif

#endif
