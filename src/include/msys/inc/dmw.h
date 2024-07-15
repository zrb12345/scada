/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     dmw.h
* @author
* @brief    This file contains required definitions and declarations which
*           allow special access to the Drive-Middleware.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef DMW__H
#define DMW__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mio_e.h>

/**
 * @name EHD Error Codes
 * @{
 */

#define DMW_EC_OK           0    /**< Everything OK */
#define DMW_EC_FAILED       (M_ES_DMW | M_E_FAILED)  /**< General error */
#define DMW_EC_PARAM        (M_ES_DMW | M_E_PARM)    /**< Wrong parameter */
#define DMW_EC_NOFILE       (M_ES_DMW | M_E_NOFILE)  /**< No file found */
#define DMW_EC_CARDNB       (M_ES_DMW | M_E_CARDNB)  /**< IO module number not valid */
#define DMW_EC_TIMEOUT      (M_ES_DMW | M_E_TIMEOUT)     /**< Timeout in function call */
#define DMW_EC_BADCONFIG    (M_ES_DMW | M_E_BADCONFIG)   /**< Configuration data not valid */
#define DMW_EC_QUEUEFULL    (M_ES_DMW | M_E_QUEUEFULL)   /**< Error queue overrun */
#define DMW_EC_OFFLINE      (M_ES_DMW | M_E_OFFLINE)     /**< No connection to device */
#define DMW_EC_INITVAL      (M_ES_DMW | M_E_INITVAL)     /**< Init value error */
#define DMW_EC_CHECKVAL     (M_ES_DMW | M_E_CHECKVAL)    /**< Check value error */
#define DMW_EC_DRIVE        (M_ES_DMW | M_E_DRIVE)   /**< Drive specific error */
#define DMW_EC_HARDWARE     (M_ES_DMW | M_E_HARDWARE)    /**< Hardware error */
#define DMW_EC_COMMUNIC     (M_ES_DMW | M_E_COMMUNIC)    /**< Communication error */
#define DMW_EC_NOSETVAL     (M_ES_DMW | M_E_NOSETVAL)    /**< Cyclic setpoint monitoring error */
#define DMW_EC_CYCLETIME    (M_ES_DMW | M_E_CYCLETIME)   /**< Cycle time monitoring error */
#define DMW_EC_DRIVETIMEOUT (M_ES_DMW | M_E_TIMEOUT2)    /**< Drive reaction timeout */
/** @} */

/**
 * @name MIO Error-Codes (mio_GetError())
 * @{
 */

#define DMW_E_BADCONFIG     MIO_E_BADCONFIG  /**< Configuration error */
#define DMW_E_COMMUNIC      0x00010000   /**< General communication error */
#define DMW_E_TIMEOUT       0x00020000   /**< Communication timeout error */
#define DMW_E_OFFLINE       0x00040000   /**< Drive is not responding */
#define DMW_E_HARDWARE      0x00080000   /**< Error on communication hardware */
#define DMW_E_DRIVE         0x00100000   /**< Drive specific error */
#define DMW_E_NOSETVAL      0x00200000   /**< Application specific error (setpoints missing) */
#define DMW_E_CYCLETIME     0x00400000   /**< Cycle time monitoring error */
#define DMW_E_STAMACH       0x00800000   /**< Error recognized by drive middleware state machine */
#define DMW_E_INIT          0x01000000   /**< Initialization error */
#define DMW_E_DRIVETIMEOUT  0x02000000   /**< Drive reaction timeout */
#define DMW_E_UNDEFINED     0x80000000   /**< Undefined error occurs */
#define DMW_E_ALLERROR      0x83ff0000   /**< All possible error bit's (reported by mio_AttachError() */
/** @} */

/*--- MIO Events ---*/
#define DMW_EV_BUSCYCLE     MIO_EV_VALUE                /* Cyclic process data event */
#define DMW_EV_ALLEVT       (DMW_EV_BUSCYCLE)           /* All possible events */

/*--- Fixed MIO channels of Drive-Middleware ---*/

/*--- Setpoint values ----*/
#define DMW_CHAN_CONTROL        1   /* 32-bit control word */
#define DMW_CHAN_SETPOSITION    2   /* Position set point */
#define DMW_CHAN_SETVELOCITY    3   /* Velocity set point */
#define DMW_CHAN_SETTORQUE      4   /* Torque set point */
#define DMW_CHAN_TORQUELIMIT    5   /* Torque limit set point */
#define DMW_CHAN_SETUSER_1      6   /* User specific configured set point 1 */
#define DMW_CHAN_SETUSER_2      7   /* User specific configured set point 2 */
#define DMW_CHAN_SETUSER_3      8   /* User specific configured set point 3 */
#define DMW_CHAN_SETUSER_4      9   /* User specific configured set point 4 */
#define DMW_CHAN_SETUSER_5     10   /* User specific configured set point 5 */
#define DMW_CHAN_SETUSER_6     11   /* User specific configured set point 6 */

/*--- Actual values ---*/
#define DMW_CHAN_STATUS         12  /* 32-bit status word */
#define DMW_CHAN_ACTPOSITION    13  /* Actual position */
#define DMW_CHAN_ACTVELOCITY    14  /* Actual velocity */
#define DMW_CHAN_ACTTORQUE      15  /* Actual torque */
#define DMW_CHAN_POSERROR       16  /* Following position error */
#define DMW_CHAN_ACTUSER_1      17  /* User specific actual value 1 */
#define DMW_CHAN_ACTUSER_2      18  /* User specific actual value 2 */
#define DMW_CHAN_ACTUSER_3      19  /* User specific actual value 3 */
#define DMW_CHAN_ACTUSER_4      20  /* User specific actual value 4 */
#define DMW_CHAN_ACTUSER_5      21  /* User specific actual value 5 */
#define DMW_CHAN_ACTUSER_6      22  /* User specific actual value 6 */

/*--- Internal setpoint values ---*/
#define DMW_CHAN_SAMPLINGTIME   23  /* Sampling interval in us (nominal bus cycle time) */
#define DMW_CHAN_CYCLETIME      24  /* Actual bus cycle time in us */
#define DMW_CHAN_CYCLECOUNT     25  /* Number of cycles */
#define DMW_CHAN_ACTIVECHAN     26  /* Bit-mask of active channels */
#define DMW_CHAN_SETTINGS       27  /* Settings concerning operation modes and event source */

#define DMW_CHAN_ERRORCNT       28  /* Error counter set point values not set in cycle */

/*--- Controlword bits ---*/
#define DMW_CHAN_STARTSWITCHON  29  /* Control.Bit.StartSwitchOn */
#define DMW_CHAN_FINISHSWITCHON 30  /* Control.Bit.FinishSwitchOn */
#define DMW_CHAN_RESETFAULT     31  /* Control.Bit.ResetFault */
#define DMW_CHAN_SETMODE        32  /* Control.Bit.Mode */
#define DMW_CHAN_STARTHOMING    33  /* Control.Bit.StartHoming */
#define DMW_CHAN_FINISHHOMING   34  /* Control.Bit.FinishHoming */

/*--- Statusword bits ----*/
#define DMW_CHAN_READY          35  /* Status.Bit.Ready */
#define DMW_CHAN_SUBSTATE       36  /* Status.Bit.SubState */
#define DMW_CHAN_ENABLED        37  /* Status.Bit.Enabled */
#define DMW_CHAN_FAULTSTATE     38  /* Status.Bit.FaultState */
#define DMW_CHAN_WARNING        39  /* Status.Bit.Warning */
#define DMW_CHAN_MODE           40  /* Status.Bit.Mode */
#define DMW_CHAN_HOMING         41  /* Status.Bit.Homing */

/*--- Configuration setting bits ---*/
#define DMW_CHAN_TORQUE         42  /* Setting.Bit.Torque */
#define DMW_CHAN_VELOCITY       43  /* Setting.Bit.Velocity */
#define DMW_CHAN_POSITION       48  /* Setting.Bit.Position */
#define DMW_CHAN_FEEDFORWARD    45  /* Setting.Bit.FeedForward */
#define DMW_CHAN_BUSTYPE        46  /* Setting.Bit.BusType */
#define DMW_CHAN_EVENTSOURCE    47  /* Setting.Bit.EventSource */
#define DMW_CHAN_EVENTCARD      48  /* Setting.Bit.EventCard */

/*--- Homing parameters ---*/
#define DMW_CHAN_HOMINGMETHOD   49  /* Homing method */
#define DMW_CHAN_HOMINGOFFSET   50  /* Homing offset */
#define DMW_CHAN_HOMINGTORQUE   51  /* Homing torque */
#define DMW_CHAN_HOMINGVEL_1    52  /* Homing velocity 1 */
#define DMW_CHAN_HOMINGVEL_2    53  /* Homing velocity 2 */
#define DMW_CHAN_HOMINGACCEL    54  /* Homing acceleration */
#define DMW_CHAN_HOMINGSETPOS   55  /* Homing set position */

/*--- Simulation mode control channels ---*/
#define DMW_CHAN_MAXVELOCITY    56  /* Velocity factor */
#define DMW_CHAN_VELFILTER      57  /* Velocity filter constant */
#define DMW_CHAN_SIMOPTION      58  /* Simulation option */

/*--- Development test channels ----*/
#define DMW_CHAN_SEMCTRL        59  /* Sercos control word */
#define DMW_CHAN_SEMSETVAL      60  /* Sercos set point value */
#define DMW_CHAN_SEMSTAT        61  /* Sercos status word */
#define DMW_CHAN_SEMACTVAL      62  /* Sercos actual value */

/*--- Ranges of fixed Set-/Actvalue channels ---*/
#define DMW_SV_START            DMW_CHAN_CONTROL
#define DMW_SV_END              DMW_CHAN_SETUSER_6
#define DMW_AV_START            DMW_CHAN_STATUS
#define DMW_AV_END              DMW_CHAN_ACTUSER_6
#define DMW_AVI_START           DMW_CHAN_SAMPLINGTIME
#define DMW_AVI_END             DMW_CHAN_SETTINGS

/*--- Configured operation modes ---*/
#define DMW_OP_TORQUE       0x01    /* Torque control possible */
#define DMW_OP_VELOCITY     0x02    /* Velocity control possible */
#define DMW_OP_POSITION     0x04    /* Position control possible */
#define DMW_OP_FEEDFORWARD  0x08    /* Feed forward activated (SERCOS) */

/*--- Bit masks for status and control word ---*/
#define DMW_MSK_CTRLDMW     0x0000FFFF /* Control bits defined by DMW */
#define DMW_MSK_CTRLUSER    0xFFFF0000 /* User defined control bits */
#define DMW_MSK_STATDMW     0x0000FFFF /* Status bits defined by DMW */
#define DMW_MSK_STATUSER    0xFFFF0000 /* User defined status bits */

/* Control-/Statusword and cyclic setpoint/actual value structures */

typedef enum _DMW_CTRL_MODE_        /* Possible operation modes in the controlword */
{
    DMW_CTRL_MODE_OFF = 0,          /* No operation mode selected */
    DMW_CTRL_MODE_TOR = 1,          /* Torque control */
    DMW_CTRL_MODE_VEL = 2,          /* Velocity control */
    DMW_CTRL_MODE_POS = 3,          /* Position control */
} DMW_CTRL_MODE;

typedef union _DMW_STATUS_          /* Device status */
{
    struct
    {
        UINT32 Ready        : 1;    /* 0 Not ready to switch-on */
                                    /* 1 Ready to switch on (Power on etc...) */
        UINT32 SubState     : 2;    /* 0 Switch-on/Homing/Switch-off not active (Status in 'Enabled' reached) */
                                    /* 1 Switch-on (find commutation)/Homing move active */
                                    /* 2 case switch-on: evt. find commutation done, drive stopped, actual position can be taken */
                                    /*   case homing: set zero-point, drive stopped, setpoint position can be taken */
                                    /* 3 Switch-on/Homing/Switch-off done; transition to 'operation enabled' */
        UINT32 Enabled      : 1;    /* 0 Switched-off or switch-off active */
                                    /* 1 Switched-on or switch-on active */
        UINT32 FaultState   : 2;    /* 0 No fault */
                                    /* 1 Fault occurred, drive active */
                                    /* 2 Fault occurred, drive stopped */
                                    /* 3 Fault acknowledged, transition to 'no fault' */
        UINT32 Warning      : 1;    /* 0 No warning */
                                    /* 1 Warning exist */
        UINT32 Reserved1    : 1;    /* Reserved for extensions */
        UINT32 Mode         : 4;    /* Actual operation mode */
        UINT32 Homing       : 1;    /* 0 Normal operation (depending on operation mode) */
                                    /* 1 Homing */
        UINT32 Reserved2    : 3;    /* Reserved for extensions */
        UINT32 UserBits     : 16;   /* User configurable bits from the statusword of the drive */
    } Bit;                          /* Bit-access (Status.Bit.Ready) */
    UINT32 Word;                    /* Word-access (Status.Word) */
} DMW_STATUS;

/* Configured fieldbus types (Setting.BusType) */
typedef enum _DMW_BUSTYPE_          /* Possible fieldbus types */
{
    DMW_BT_SERCOS,
    DMW_BT_ECAT,
    DMW_BT_CANOPEN,
    DMW_BT_PROFIDRIVE
} DMW_BUSTYPE;

/* Configured fieldbus synchronisation modes (Setting.EventSource) */
typedef enum _DMW_EVTSRC_               /* Possible fieldbus synchronisation modes */
{
    DMW_EVT_TIMER      = 0,             /* Free-wheeling timer */
    DMW_EVT_SYNC_IN    = MIO_SYNC_IN,   /* IO-bus SYNC_IN interrupt */
    DMW_EVT_SYNC_OUT   = MIO_SYNC_OUT,  /* IO-bus SYNC_OUT interrupt */
    DMW_EVT_SYNC_INOUT = MIO_SYNC_IN | MIO_SYNC_OUT,
    DMW_EVT_EVENT_INT  = 4              /* Event interrupt (e.g. SEM201 modules) */
} DMW_EVTSRC;

typedef union _DMW_SETTING_         /* Drive-Middleware settings */
{
    struct
    {
        UINT32 Torque       : 1;    /* 0 Torque control not configured */
                                    /* 1 Torque control available */
        UINT32 Velocity     : 1;    /* 0 Velocity control not configured */
                                    /* 1 Velocity control available */
        UINT32 Position     : 1;    /* 0 Position control not configured */
                                    /* 1 Position control available */
        UINT32 FeedForward  : 1;    /* 0 Feed forward not configured/activated */
                                    /* 1 Position control with feed forward available (Sercos) */
        UINT32 Reserved     : 4;    /* Reserved for extensions */

        UINT32 BusType      : 4;    /* Fieldbus type (e.g. Sercos, EtherCAT) */
        UINT32 EventSource  : 4;    /* Event source for the bus-/control cycle */
        UINT32 EventCard    : 16;   /* Event card number */
    } Bit;                          /* Bit access (Config.Bit.Position) */
    UINT32 Word;                    /* Word access (Config.Word) */
} DMW_SETTING;

typedef struct _DMW_ACTVAL_         /* Actual value data structure */
{
    DMW_STATUS  Status;             // 32-bit statusword */
    SINT32      Position;           /* Actual position */
    SINT32      Velocity;           /* Actual velocity */
    SINT32      Torque;             /* Actual torque */
    SINT32      PosError;           /* Position following error */

    SINT32      UserChannel[6];     /* User specific configured actual values */

    UINT32      SamplingTime;       /* Sampling interval in us (nominal bus cycle time) */
    UINT32      CycleTime;          /* Actual bus cycle time in us */
    UINT32      CycleCount;         /* Number of cycles */
    UINT32      ActiveChan;         /* Bit-mask of active channels */
    DMW_SETTING Setting;            /* Configuration information */

} DMW_ACTVAL;

typedef union _DMW_CONTROL_         /* Device control */
{
    struct
    {
        UINT32 StartSwitchOn  : 1;  /* 0->1 Start switch-on drive */
                                    /* 1->0 Switch-off drive */
        UINT32 FinishSwitchOn : 1;  /* 0->1 Finish switch-on drive */
        UINT32 ResetFault     : 1;  /* 0->1 Acknowledge fault */
        UINT32 Reserved1      : 1;  /* Reserved for extensions */
        UINT32 Mode           : 4;  /* Set operation mode */
        UINT32 StartHoming    : 1;  /* 0->1 Start homing */
                                    /* 1->0 Abort homing */
        UINT32 FinishHoming   : 1;  /* 0->1 Finish homing */
        UINT32 Reserved2      : 5;  /* Reserved for extensions */
        UINT32 ToggleBit      : 1;  /* Force the PLC to take over the setpoints */
        UINT32 UserBits       : 16; /* User configurable bits */
    } Bit;                          /* Bit access (Control.Bit.Enable) */
    UINT32 Word;                    /* Word access (Control.Word) */
} DMW_CONTROL;

typedef struct _DMW_SETVAL_         /* Setpoint value data structure */
{
    DMW_CONTROL Control;            /* 32-bit controlword */
    SINT32      Position;           /* Position setpoint */
    SINT32      Velocity;           /* Velocity setpoint */
    SINT32      Torque;             /* Torque setpoint */
    SINT32      TorqueLimit;        /* Torque limit setpoint */

    SINT32      UserChannel[6];     /* User specific configured setpoints */

    UINT32      Reserved[5];        /* Reserved for internal extensions */
} DMW_SETVAL;


/*--- Prototyping ---*/

MLOCAL SINT32 mio_RdActVal(MIO_DRV *DrvId, DMW_ACTVAL *pActVal);
MLOCAL SINT32 mio_WrSetVal(MIO_DRV *DrvId, DMW_SETVAL *pSetVal);
MLOCAL SINT32 mio_RdSetVal(MIO_DRV *DrvId, DMW_SETVAL *pSetVal);

MLOCAL SINT32 mio_GetParmName(MIO_DRV *DrvId, UINT32 Parm, CHAR *Name);
MLOCAL SINT32 mio_GetParmNr(MIO_DRV *DrvId, CHAR *Name, UINT32 *pParNr);

MLOCAL SINT32 mio_RdParmVal(MIO_DRV *DrvId, UINT32 Parm, UINT32 *pVal);
MLOCAL SINT32 mio_WrParmVal(MIO_DRV *DrvId, UINT32 Parm, UINT32 Val);

MLOCAL SINT32 mio_RdParm(MIO_DRV *DrvId, UINT32 Parm, VOID *pData, UINT32 *pLen);
MLOCAL SINT32 mio_RdParmPoll(MIO_DRV *DrvId, UINT32 Parm, VOID *pData, UINT32 *pLen, SINT32 *pResult);
MLOCAL SINT32 mio_RdParmCbf(MIO_DRV *DrvId, UINT32 Parm, VOID *pData, UINT32 *pLen, VOID (*AppCbf)(UINT32 UsrPar, SINT32 Result), UINT32 UsrPar);
MLOCAL SINT32 mio_WrParm(MIO_DRV *DrvId, UINT32 Parm, VOID *pData, UINT32 Len);
MLOCAL SINT32 mio_WrParmPoll(MIO_DRV *DrvId, UINT32 Parm, VOID *pData, UINT32 Len, SINT32 *pResult);
MLOCAL SINT32 mio_WrParmCbf(MIO_DRV *DrvId, UINT32 Parm, VOID *pData, UINT32 Len, VOID (*AppCbf)(UINT32 UsrPar, SINT32 Result), UINT32 UsrPar);


/*--- Inline functions ---*/
#include <dmw_i.h>

#ifdef __cplusplus
}
#endif

#endif

#ifdef ___IN_EXAMPLE_C___

/*
** Example C-application for the Drive-Middleware!
** NOTE:
** - This is only a symbolic example code.
** - There are no checks implemented (function return values).
** - Further the my_Control() function has to be implemented.
*/

/* Callback function for axis synchronisation */

MLOCAL SEM_ID my_SyncSignal;    /* Semaphore to trigger main routine */

VOID my_EventCbf(VOID *DrvId, UINT32 Chan, UINT32 Event, UINT32 UsrPar)
{
    static UINT32 AllAxis = 0;  /* Static variable to keep events */

    /* ATTENTION: This instruction must be implemented non-interruptible */
    AllAxis |= UsrPar;

    if (AllAxis == 0x07)        /* Events for all axis received? */
    {
        AllAxis = 0;            /* Reset for next cycle */
        semGive(my_SyncSignal); /* Trigger application */
    }
}

/* Control algorithm for synchronous axes */
VIOD my_Control(DMW_ACTVAL *pAv, DMW_SETVAL *pSv)
{
    /* Calculate new setpoints... */
}

/* Example initialisation and control loop */
VOID my_Main(VOID)
{
    DMW_ACTVAL Av[3];   /* Actual values of the 3 axes */
    DMW_SETVAL Sv[3];   /* Setpoint values of the 3 axes */

    SINT32 SessId;

    /*--- Get the Drive-Middleware drivers for the axes. ---*/
    MIO_DRV *DrvId_1 = mio_GetDrv(1);
    MIO_DRV *DrvId_2 = mio_GetDrv(2);
    MIO_DRV *DrvId_3 = mio_GetDrv(3);

    /*--- Create semaphore for control cycle ---*/
    my_SyncSignal = semBCreate(SEM_Q_PRIORITY, SEM_EMPTY);

    /*--- Start event-session ---*/
    SessId = mio_StartEventSession("SMC1");

    /*--- Attach to bus cycle for the axes. */
    mio_AttachEvent(DrvId_1, SessId, 0, MIO_EV_VALUE, my_EventCbf, 0x01);
    mio_AttachEvent(DrvId_2, SessId, 0, MIO_EV_VALUE, my_EventCbf, 0x02);
    mio_AttachEvent(DrvId_3, SessId, 0, MIO_EV_VALUE, my_EventCbf, 0x04);

    for (;;) /* Control cycle */
    {
        semTake(my_SyncSignal);

        /*--- Read actual values ---*/
        mio_RdActVal(DrvId_1, &Av[0]);
        mio_RdActVal(DrvId_2, &Av[1]);
        mio_RdActVal(DrvId_3, &Av[2]);

        /*--- Calculate new setpoints for all axes ---*/
        my_Control(Av, Sv);

        /*--- Write setpoint values ---*/
        mio_WrSetVal(DrvId_1, &Sv[0]);
        mio_WrSetVal(DrvId_2, &Sv[1]);
        mio_WrSetVal(DrvId_3, &Sv[2]);
    }
}

#endif
