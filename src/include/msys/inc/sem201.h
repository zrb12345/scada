/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     sem201.h
* @author   Diem
* @brief    This file contains required definitions and declarations which
*           allow special access to the SEM201 module.
*           The module SEM201 implements the following standard MIO-Functions:
*           + mio_GetError
*           + mio_GetNextErr
*           + mio_GetCardInf
*           + mio_GetCardMode
*           + mio_SetCardMode
*           + mio_GetChanInf
*           + mio_GetChanMode
*           + mio_SetChanMode
*           + mio_DoCmd
*           + mio_GetValue
*           + mio_SetValue
*           + mio_AttachEvent
*           + mio_DetachEvent
*           + mio_AttachError
*           + mio_DetachError
*           Additional to the standard MIO-Functions the following two
*           functions are implemented:
*           + mio_SetSercValue(DrvId, ValId, Channel, Value)
*           + mio_GetServValue(DrvId, ValId, Channel, pValue)
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef SEM201__H
#define SEM201__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @addtogroup SEM201_DEF
 * @{
 */

/**
 * @name Defines for SEM201 modules
 * @{
 */

#define SEM_MAXCYCVAL   20  /**< Maximum cyclical values per channel */
/** @} */

/**
 * @name Possible commands for the IO module SEM201 (DoCmd's)
 * @{
 */

#define MIO_BASE                2000     /**< Base value for SERCOS DoCmd's */
#define MIO_CMD_RAMINF          (MIO_BASE + 0)   /**< Get DP-RAM information */
#define MIO_CMD_GETSETVALUELIST (MIO_BASE + 1)   /**< Get list of configured set values */
#define MIO_CMD_GETACTVALUELIST (MIO_BASE + 2)   /**< Get list of configured actual values */
#define MIO_CMD_GETTRANSPOWER   (MIO_BASE + 3)   /**< Get optical transmission power */
#define MIO_CMD_SETCOMPHASE     (MIO_BASE + 4)   /**< Set requested communication phase */
#define MIO_CMD_GETCOMPHASE     (MIO_BASE + 5)   /**< Get current communication phase */
#define MIO_CMD_GETBAUDRATE     (MIO_BASE + 6)   /**< Get SERCOS baud rate */
#define MIO_CMD_GETTIMING       (MIO_BASE + 7)   /**< Get SERCOS timings */
#define MIO_CMD_GETSERVICECHAN  (MIO_BASE + 9)   /**< Get value(s) using service channel */
#define MIO_CMD_SETSERVICECHAN  (MIO_BASE + 10)  /**< Set value(s) using service channel */
#define MIO_CMD_GETATTRIBUTE    (MIO_BASE + 11)  /**< Get Attribute of IDN */
#define MIO_CMD_GETERRORMSG     (MIO_BASE + 12)  /**< Get text of SERCOS error code */
#define MIO_CMD_GETCONTROLWORD  (MIO_BASE + 13)  /**< Get content of the SERCOS control word */
#define MIO_CMD_SETCONTROLWORD  (MIO_BASE + 14)  /**< Set content of the SERCOS control word */
#define MIO_CMD_GETSTATUSWORD   (MIO_BASE + 15)  /**< Get content of the status word */
#define MIO_CMD_GETCMDSTATUS    (MIO_BASE + 16)  /**< Get status of command function */
#define MIO_CMD_GETCTRL16       (MIO_BASE + 17)  /**< For internal use only */
#define MIO_CMD_SETCHANVALID    (MIO_BASE + 18)  /**< Confirm (validation) of channel set values */
#define MIO_CMD_GETERRCOUNTER   (MIO_BASE + 19)  /**< Get consistency error counter */
#define MIO_CMD_RESETERRCOUNTER (MIO_BASE + 20)  /**< Get consistency error counter */
#define MIO_CMD_GET_ASYNC_SC    (MIO_BASE + 21)  /**< Get value(s) using asynchronous service channel transfer */
#define MIO_CMD_SET_ASYNC_SC    (MIO_BASE + 22)  /**< Set value(s) using asynchronous service channel transfer */
#define MIO_CMD_QUERY_ASYNC_SC  (MIO_BASE + 23)  /**< Test if asynchronous service channel transfer finished */
#define MIO_CMD_GETSTATUS16     (MIO_BASE + 24)  /**< For internal use only */
#define MIO_CMD_SETCTRL16       (MIO_BASE + 25)  /**< For internal use only */
/** @} */

/**
 * @anchor SEM201_OP_Modes
 */

/**
 * @name Possible values for MIO_SETCHMOD_C.Mode and MIO_GETCHMOD_C.Mode in case of SEM201
 * @{
 */

#define MIO_M_MAINOPMODE    0x0000   /**< Main operation mode of the SERCOS drive (see IDN 00032) */
#define MIO_M_SECOPMODE1    0x0001   /**< Secondary operation mode 1 of the SERCOS drive (see IDN0033) */
#define MIO_M_SECOPMODE2    0x0002   /**< Secondary operation mode 2 of the SERCOS drive (see IDN0034) */
#define MIO_M_SECOPMODE3    0x0003   /**< Secondary operation mode 3 of the SERCOS drive (see IDN0035) */
#define MIO_M_SECOPMODE4    0x0004   /**< Secondary operation mode 4 of the SERCOS drive (see IDN0284) */
#define MIO_M_SECOPMODE5    0x0005   /**< Secondary operation mode 5 of the SERCOS drive (see IDN0285) */
#define MIO_M_SECOPMODE6    0x0006   /**< Secondary operation mode 6 of the SERCOS drive (see IDN0286) */
#define MIO_M_SECOPMODE7    0x0007   /**< Secondary operation mode 7 of the SERCOS drive (see IDN0287) */
/** @} */

/**
 * @name Possible driver specific error codes for SEM201 module
 * @{
 */

#define SEM_E_MSTMISS       0x00100000   /**< SERCOS Master-sync telegram (MST) not within the time frame */
#define SEM_E_DRIVEMISS     0x00200000   /**< SERCOS drive is not responding */
#define SEM_E_INITTIMEOUT   0x00010000   /**< Timeout while initialization */
#define SEM_E_SERCDPRFAIL   0x00020000   /**< Error in SERCOS-ASIC DP-RAM */
#define SEM_E_ASICFAIL      0x00040000   /**< General SERCOS-ASIC failure */
#define SEM_E_C1D           0x00080000   /**< Class 1 diagnostic error */
/** @} */

/**
 * @anchor SEM201_Element_Values
 */

/**
 * @name Possible SERCOS element values
 * @{
 */

#define SEM_SC_IDN      1   /**< Service Channel Element 1: Idn (Indent number) */
#define SEM_SC_NAME     2   /**< Service Channel Element 2: Name */
#define SEM_SC_ATTRIB   3   /**< Service Channel Element 3: Attribute */
#define SEM_SC_UNIT     4   /**< Service Channel Element 4: Unit */
#define SEM_SC_MINVAL   5   /**< Service Channel Element 5: Minimum value */
#define SEM_SC_MAXVAL   6   /**< Service Channel Element 6: Maximum value */
#define SEM_SC_OPVAL    7   /**< Service Channel Element 7: Operation data */
/** @} */

/**
 * @name Possible values for MIO_SETCDMOD_C.Mode and MIO_GETCDMOD_C.Mode in case of SEM201
 * @{
 */

#define MIO_M_SERCOS        0x0001   /**< Normal SERCOS operation mode */
#define MIO_M_CONT_BRIGHT   0x0002   /**< Module test mode (turns the transmitter diode on permanently) */
#define MIO_M_ZEROBIT       0x0004   /**< Module test mode (sends a zero bit stream) */
#define MIO_M_EVENTINT      0x0008   /**< Synchronization via MIO event interrupt */
#define MIO_M_BUSSYNC       0x0010   /**< Synchronization via IO-Bus-sync interrupt */
/** @} */

/**
 * @name Important bits of the drive status word
 * @{
 */

#define SEM_STAT_C1D    0x2000   /**< Class 1 Diagnostic (Drive shut down error) */
/** @} */

/**
 * @name Possible values for MIO
 * @{
 */

#define SEM_STR_POSCMD  "POSCMD"     /**< Position command value              IDN00047 */
#define SEM_STR_POSFBK1 "POSFBK1"    /**< Position feedback value1 (motor)    IDN00051 */
#define SEM_STR_POSFBK2 "POSFBK2"    /**< Position feedback value2 (external) IDN00053 */
#define SEM_STR_VELCMD  "VELCMD"     /**< Velocity command value              IDN00036 */
#define SEM_STR_VELFBK  "VELFBK"     /**< Velocity feedback value 1           IDN00040 */
#define SEM_STR_VELFBK1 "VELFBK1"    /**< Velocity feedback value 1           IDN00040 */
#define SEM_STR_VELFBK2 "VELFBK2"    /**< Velocity feedback value 2           IDN00156 */
#define SEM_STR_TORCMD  "TORCMD"     /**< Torque command value                IDN00080 */
#define SEM_STR_TORFBK  "TORFBK"     /**< Torque feedback value               IDN00084 */
#define SEM_VAL_POSCMD  47  /**< Position command value              IDN00047 */
#define SEM_VAL_POSFBK1 51  /**< Position feedback value1 (motor)    IDN00051 */
#define SEM_VAL_POSFBK2 53  /**< Position feedback value2 (external) IDN00053 */
#define SEM_VAL_VELCMD  36  /**< Velocity command value              IDN00036 */
#define SEM_VAL_VELFBK  40  /**< Velocity feedback value 1           IDN00040 */
#define SEM_VAL_VELFBK1 40  /**< Velocity feedback value 1           IDN00040 */
#define SEM_VAL_VELFBK2 156 /**< Velocity feedback value 2           IDN00156 */
#define SEM_VAL_TORCMD  80  /**< Torque command value                IDN00080 */
#define SEM_VAL_TORFBK  84  /**< Torque feedback value               IDN00084 */
/** @} */

/**
 * @name Structures for SEM201 modules
 * @{
 */

/**
 * Structure for DoCmd-functions #MIO_CMD_GETSETVALUELIST and #MIO_CMD_GETACTVALUELIST.
 * List of set/actual values per channel. The structure is defined in the file sem201.h.
 */
typedef struct
{
    UINT8   Count;              /**< Number of set/actual values of the current channel */
    UINT8   Size[SEM_MAXCYCVAL];     /**< Data size in bytes of each set/actual value */
    UINT16  ValList[SEM_MAXCYCVAL];  /**< Indent number of each set/actual value */
} SEM_CYCVAL_LIST;

/**
 * Structure for DoCmd-function #MIO_CMD_GETTIMING.
 * The structure is defined in the file sem201.h.
 */
typedef struct
{
    UINT16  t1min;              /**< Shortest AT transmission starting time */
    UINT16  t1;                 /**< AT transmission starting time */
    UINT16  t5;                 /**< Minimum feedback processing time */
    UINT16  t4;                 /**< Feedback acquisition capture point */
    UINT16  tATMT;              /**< Transmit/receive transition time */
    UINT16  tATAT;              /**< Transmit to transmit recovery time */
    UINT16  tMTSY;              /**< Receive to receive recovery time */
    UINT16  t2;                 /**< MDT transmission starting time */
    UINT16  tMTSG;              /**< Command value proceeding time */
    UINT16  t3;                 /**< Command value valid time */
    UINT16  MDTLen;             /**< Length of MDT */
    UINT16  MDTAddr;            /**< Position of data record in MDT */
    UINT16  tNcyc;              /**< Control unit cycle time */
    UINT16  tScyc;              /**< Communication cycle time */
    UINT16  SLKN;               /**< Slave arrangement */
    UINT16  MaxSyncLow;         /**< Maximum value for SyncLow (in microseconds) */
} SEM_TIMING;

/**
 * Structure for DoCmd-function #MIO_CMD_GETATTRIBUTE.
 * The structure is defined in the file sem201.h.
 */
typedef struct
{
    UINT32  Attrib;             /**< Whole Attribute                 (Bits 31- 0) */
    BOOL8   Bit31;              /**< Reserved                    (Bit 31) */
    BOOL8   ReadOnlyCP4;        /**< Read only in CP4                    (Bit 30) */
    BOOL8   ReadOnlyCP3;        /**< Read only in CP3                    (Bit 29) */
    BOOL8   ReadOnlyCP2;        /**< Read only in CP2                    (Bit 28) */
    UINT8   DecPoint;           /**< Places after the decimal point  (Bits 27-24) */
    BOOL8   Bit23;              /**< Reserved                    (Bit 23) */
    /**
     * Data type and display format    (Bits 22-20)
     *  Value  | Data type          | Display format
     * ------- | -------------------|----------------------
     *  0      | binary number      | binary
     *  1      | unsigned integer   | unsigned decimal
     *  2      | integer            | signed decimal
     *  3      | unsigned integer   | hexadecimal
     *  4      | extended char      | text
     *  5      | unsigned integer   | IDN
     *  6      | float number       | signed decimal with exponent
     */
    UINT8   DispForm;
    BOOL8   ProcCmd;            /**< Is it an procedure command          (Bit 19) */
    /**
     * Data length                     (Bits 18-16)
     *  Value  | Data type and length
     * ------- | ----------------------------------------
     *  1      | operation data is 2 bytes long
     *  2      | operation data is 4 bytes long
     *  3      | operation data is 8 bytes long
     *  4      | variable length (1 byte data strings)
     *  5      | variable length (2 byte data strings)
     *  6      | variable length (4 byte data strings)
     *  7      | variable length (8 byte data strings)
     */
    UINT8   DataLen;
    UINT16  ConvFactor;         /**< Conversion factor               (Bits 15- 0) */
} SEM_ATTRIBUTE;

/**
 * Structure for DoCmd-function #MIO_CMD_GETCONTROLWORD and #MIO_CMD_SETCONTROLWORD.
 * The structure is defined in the file sem201.h.
 */
typedef struct
{
    BOOL8   DriveOn;            /**< Drive ON/OFF                        (Bit 15) */
    BOOL8   EnableDrive;        /**< Enable drive                        (Bit 14) */
    BOOL8   HaltRestart;        /**< Halt/restart drive                  (Bit 13) */
    BOOL8   Bit12;              /**< Reserved                    (Bit 12) */
    BOOL8   IPOSYNC;            /**< Control unit synchronization bit    (Bit 10) */
    UINT8   OpMode;             /**< Operation mode (see @ref SEM201_OP_Modes "SERCOS Operation Modes") (Bits 11,9,8) */
    BOOL8   RTCtrl2;            /**< Real-time control bit 2 (IDN00302)  (Bit  7) */
    BOOL8   RTCtrl1;            /**< Real-time control bit 1 (IDN00300)  (Bit  6) */
    BOOL8   ReadWrite;          /**< Read / Write                        (Bit  1) */
    BOOL8   MHS;                /**< MHS (Master Handshake)              (Bit  0) */
} SEM_CTRLWORD;

/**
 * Structure for DoCmd-function #MIO_CMD_GETSTATUSWORD.
 * The structure is defined in the file sem201.h.
 */
typedef struct
{
    /**
     * Ready to operate                (Bits 15-14)
     *  Value  | State
     * ------- | ----------------------------------
     *  00     | Drive not ready for power up
     *  01     | Drive logic ready for main power on
     *  10     | Drive ready and main power applied
     *  11     | Drive ready to operate
     */
    UINT8   OpReady;
    BOOL8   DriveShutDown;      /**< Drive shut down due to error        (Bit 13) */
    BOOL8   ChangedC2D;         /**< Change bit for C2D                  (Bit 12) */
    BOOL8   ChangedC3D;         /**< Change bit for C3D                  (Bit 11) */
    UINT8   OpMode;             /**< Actual operation mode (see @ref SEM201_OP_Modes "SERCOS Operation Modes")  (Bits 10- 8) */
    BOOL8   RTStatus2;          /**< Real-time status bit 2 (IDN00306)    (Bit 7) */
    BOOL8   RTStatus1;          /**< Real-time status bit 1 (IDN00304)    (Bit 6) */
    BOOL8   ProcCmdChg;         /**< Procedure command change bit         (Bit 5) */
    BOOL8   Bit4;               /**< Reserved (new actual values) (Bit 4) */
    BOOL8   CmdValProc;         /**< Status command value processing      (Bit 3) */
    BOOL8   SCError;            /**< Error in service channel             (Bit 2) */
    BOOL8   Busy;               /**< Busy                                 (Bit 1) */
    BOOL8   AHS;                /**< AHS (Axis Handshake)                 (Bit 0) */
} SEM_STATUSWORD;

/** @} */
/** @} */

#ifdef __cplusplus
}
#endif

#endif
