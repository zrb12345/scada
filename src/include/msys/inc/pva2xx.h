/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     pva2xx.h
* @author   Pilavci
* @brief    PVA2XX specific structures and defines.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef PVA2XX__H
#define PVA2XX__H

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @addtogroup PVA2XX_DEF
 * @{
 */

#include <mtypes.h>

/**
 * @name Values used to reflect errors when parsing the parameter file
 * @{
 */

#define PVA_ER_CFG_OK               0x00000000   /**< No error while parsing the parameter file */
#define PVA_ER_CFG_FILEMISS         0x00000001   /**< Parameter file missing */
#define PVA_CURVE_NB                20   /**< curve number for the valve */
#define PVA_INT_NB                  1000     /**< Interpolated curve number for the valve */
#define PVA_LINEAR_INTERP_STR       "LINEAR"     /**< Linear Interpolation */
#define PVA_SPLINE_INTERP_STR       "SPLINE"     /**< Spline Interpolation */
#define PVA_LINEAR_INTERP           0    /**< Linear Interpolation */
#define PVA_SPLINE_INTERP           1    /**< Spline Interpolation */
#define PVA_UNDEFINED_POINT         -1   /**< used if rate point (whole PVA2XX_RATE struct) is not valid */
#define PVA2XX_MAXDITHERFREQ        500  /**< 500 Hz */
#define PVA2XX_MINDITHERFREQ        40   /**< 40 Hz */
#define PVA2XX_MAXDITHERAMPLITUDE   300  /**< Maximum dither percentage (30%) of the instantaneous current value, in 0.1% */
#define PVA2XX_MAXRAMPTIME          15000    /**< Maximum ramp time in ms (15000 ms) */
#define PVA2XX_MINRAMPTIME          1    /**< Minimum ramp time in ms (1 ms) */
#define PVA204_MAXCURRENT_CHAN      3000     /**< Maximum nominal current for one channel for PVA204 in mA */
#define PVA208_MAXCURRENT_CHAN      2500     /**< Maximum nominal current for one channel for PVA208 in mA */
#define PVA2XX_MAXCURRENT_SUM       8500     /**< Maximum nominal current for the module in mA */
/** @} */
/** @} */
/**
 * @cond PRIVATE
 * Structure for DoCmd-function MIO_CMD_PVA2XX_GET_INTERPOLATED_CURVE
 * @endcond
 */
typedef struct
{
    REAL64  cur1[PVA_INT_NB];   /**< Interpolated current data for coil 1 */
    REAL64  cur2[PVA_INT_NB];   /**< Interpolated current data for coil 2 */
} PVA2XX_INTERP;

/**
 * @cond PRIVATE
 * Structure for DoCmd-function MIO_CMD_PVA2XX_SETPID
 * @endcond
 */
typedef struct
{
    SINT16  KI[8];              /**< Integral part of PID parameter */
    SINT16  KP[8];              /**< Proportional part of PID parameter */
    SINT16  KD[8];              /**< Differential part of PID parameter */
} PVA2XX_PID;

/**
 * Structure for DoCmd-function #MIO_CMD_PVA2XX_SETINTERPOLATION / #MIO_CMD_PVA2XX_GETINTERPOLATION
 * Rate data structure used within PVA2XX_CURVE
 * @since V1.00 Release
 */
typedef struct
{
    SINT32  Flow;               /**< Flow rate of the valve; [0 - 1000] or #PVA_UNDEFINED_POINT; 0.1% of flow rate */
    SINT32  Current;            /**< Current ratio for the corresponding flow rate; [0 - 1000]; 0.1% of nominal current */
} PVA2XX_RATE;

/**
 * Structure for DoCmd-function MIO_CMD_PVA2XX_SETINTERPOLATION / MIO_CMD_PVA2XX_GETINTERPOLATION
 * @since V1.00 Release
 */
typedef struct
{
    SINT32      InterpolationType;   /**< The type of the interpolation, one of the PVA_INTERP_* constants; enum */
    UINT32      NomCurrent;     /**< Nominal current; [0 - 3000]; mA */
    PVA2XX_RATE Rate1[PVA_CURVE_NB];     /**< Curve values for the coil 1 (positive channel values, index  1 - 20 in characteristic curve) */
    PVA2XX_RATE Rate2[PVA_CURVE_NB];     /**< Curve values for the coil 2 (negative channel values, index 21 - 40 in characteristic curve) */
} PVA2XX_CURVE;

/**
 * Structure for DoCmd-function MIO_CMD_PVA2XX_SETDITHER / MIO_CMD_PVA2XX_GETDITHER
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  DitherFreq;         /**< Frequency of the dither signal; [#PVA2XX_MINDITHERFREQ - #PVA2XX_MAXDITHERFREQ]; Hz */
    UINT32  DitherAmpl;         /**< Dither percentage of the instantaneous current value; [0 -  #PVA2XX_MAXDITHERAMPLITUDE]; 0.1% */
} PVA2XX_DITHER;

/**
 * Structure for DoCmd-function MIO_CMD_PVA2XX_SETRAMP / MIO_CMD_PVA2XX_GETRAMP
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  RampRiseA;          /**< Actual ramp time for rising edge for coil 1; [RampLimitRiseA <= RampRiseA <= 15000]; msec */
    UINT32  RampFallA;          /**< Actual ramp time for falling edge for coil 1; [RampLimitFallA <= RampFallA <= 15000]; msec */
    UINT32  RampRiseB;          /**< Actual ramp time for rising edge for coil 2; [RampLimitRiseB <= RampRiseB <= 15000]; msec */
    UINT32  RampFallB;          /**< Actual ramp time for falling edge for coil 2; [RampLimitFallB <= RampFallB <= 15000]; msec */
} PVA2XX_RAMP;

/**
 * Structure for DoCmd-function MIO_CMD_PVA2XX_GETRAMP_LIMIT
 * @since V1.00 Release
 */
typedef struct
{
    UINT32  RampLimitRiseA;     /**< Minimum ramp time for rising edge for coil 1; 1 msec */
    UINT32  RampLimitFallA;     /**< Minimum ramp time for falling edge for coil 1; 1 msec */
    UINT32  RampLimitRiseB;     /**< Minimum ramp time for rising edge for coil 2; 1 msec */
    UINT32  RampLimitFallB;     /**< Minimum ramp time for falling edge for coil 2; 1 msec */
} PVA2XX_RAMP_LIMITS;



/*
 * This part contains all abstract do commands of PVA2XX
 * @generated
 */
#include <mio_e.h>

/**
 * @ingroup PVA2XX_DoCmds
 * @brief Activate or deactivate the PWM output (PWM run mode) on the hardware for the desired channel.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[in]  runMode      New run mode (true or false)
 *
 * @retval     MIO_ER_*     Common error
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_SetPwmRunMode(void *DrvId, UINT32 Chan, UINT32 runMode)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_SETPWMRUNMODE, runMode);
	return (retValue);
}


/**
 * @ingroup PVA2XX_DoCmds
 * @brief Reads the state of the PWM output (PWM run mode) whether activated or deactivated.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[out] pRunMode     Where to return the run mode
 *
 * @retval     MIO_ER_*     Common error
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_GetPwmRunMode(void *DrvId, UINT32 Chan, UINT32  *pRunMode)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_GETPWMRUNMODE, pRunMode);
	return (retValue);
}


/**
 * @ingroup PVA2XX_DoCmds
 * @brief Sets the Characteristic curve and calculate the interpolation for the desired channel.
 * The interpolated current values (1000 values for each channel) are written to the hardware.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[in]  pCurveSet    Characteristic data to be set
 *
 * @retval     MIO_ER_*     Common error
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_SetInterpolation(void *DrvId, UINT32 Chan, PVA2XX_CURVE *pCurveSet)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_SETINTERPOLATION, pCurveSet);
	return (retValue);
}


/**
 * @ingroup PVA2XX_DoCmds
 * @brief Reads the Characteristic curve for the desired channel.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[out] pCurve       Characteristic data to be read
 *
 * @retval     MIO_ER_*     Common error
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_GetInterpolation(void *DrvId, UINT32 Chan, PVA2XX_CURVE *pCurve)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_GETINTERPOLATION, pCurve);
	return (retValue);
}


/**
 * @ingroup PVA2XX_DoCmds
 * @brief The contents of the template files are copied in to the channel structure and to the module.
 * The parameter "pFileName" is the absolute or relative path of the template file.
 * The template file must be in *.pvt format.
 * The mode parameter in the template file must be the same with the channel mode.
 * Template files can be also loaded to a channel with a WEBMI application.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[in]  pFileName    Name of the template file
 *
 * @retval     MIO_ER_*     Common error
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_ReadTemplateToChan(void *DrvId, UINT32 Chan, const CHAR8 *pFileName)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_READTEMPLATETOCHAN, pFileName);
	return (retValue);
}


/**
 * @ingroup PVA2XX_DoCmds
 * @brief Saves the current configuration in to the parameter file.
 * The parameter "pFilePath" is the absolute or relative path of the parameter file.
 * If null or an empty string is specified, then the parameter file which configured in mconfig.ini is used. The parameter file must be in *.pva format.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  pFilePath    Path of parameter file; if NULL or an empty string: file configured in mconfig.ini (ParameterFile) is used
 *
 * @retval     MIO_ER_*     Common error
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_WriteParamFile(void *DrvId, const CHAR8 *pFilePath)
{
	SINT32 retValue = mio_DoCmd(DrvId, 0, MIO_CMD_PVA2XX_WRITEPARAMFILE, pFilePath);
	return (retValue);
}


/**
 * @ingroup PVA2XX_DoCmds
 * @brief Reads the configuration from the parameter file and writes to the hardware.
 * The parameter "pFilePath" is the absolute or relative path of the parameter file.
 * If null or an empty string is specified, then the parameter file which configured in mconfig.ini is used. The parameter file must be in *.pva format.
 * Via parameter pRetPVA a detailed error message is provided.
 * The content of the parameter file must be correct. If any parameter is not correct, then no new parameter is taken,
 * the old parameters are maintained.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  pFilePath    Path of parameter file (max. 40 chars); if NULL or an empty string: file configured in mconfig.ini (ParameterFile) is used
 * @param[out] pRetPVA      Additional error code.
 * Value                             | Description
 * --------------------------------  | ------------------------------------------
 *  0x00000000  #PVA_ER_CFG_OK       | No error while parsing the parameter file
 *  0x00000001  #PVA_ER_CFG_FILEMISS | Parameter file missing
 *
 * @retval     MIO_ER_*     Common error
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_ReadParamFile(void *DrvId, const CHAR8 *pFilePath, UINT32  *pRetPVA)
{
	SINT32 retValue = mio_DoCmd(DrvId, 0, MIO_CMD_PVA2XX_READPARAMFILE, pFilePath, pRetPVA);
	return (retValue);
}


/**
 * @ingroup PVA2XX_DoCmds
 * @brief Writes the dither frequency and dither percentage of the instantaneous current value to the hardware.
 * The unit of the frequency is Hz. It can be adjusted between 40 Hz and 500 Hz
 * The dither percenatage of the instantaneous current value can be adjusted between 0% and 30%.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[in]  pDither      Amplitude and the frequency values for the dither
 *
 * @retval     MIO_ER_*     Common error
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_SetDither(void *DrvId, UINT32 Chan, PVA2XX_DITHER *pDither)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_SETDITHER, pDither);
	return (retValue);
}


/**
 * @ingroup PVA2XX_DoCmds
 * @brief Reads the configured dither frequency and dither percentage of the instantaneous current value.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[out] pDither      Amplitude and the frequency values for the dither
 *
 * @retval     MIO_ER_*     Common error
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_GetDither(void *DrvId, UINT32 Chan, PVA2XX_DITHER *pDither)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_GETDITHER, pDither);
	return (retValue);
}


/**
 * @ingroup PVA2XX_DoCmds
 * @brief Writes the current ramp time values of the PWM-signal (ramp times for rising and falling edge) for the desired channel.
 * The unit of the ramp time value is ms. It can be adjusted between 1 ms to 15000 ms.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[in]  pRamp        Ramp time to be set
 *
 * @retval     MIO_ER_*     Common error
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_SetRamp(void *DrvId, UINT32 Chan, PVA2XX_RAMP *pRamp)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_SETRAMP, pRamp);
	return (retValue);
}


/**
 * @ingroup PVA2XX_DoCmds
 * @brief Reads the current ramp time values of the PWM-signal (ramp times for rising and falling edge) for the desired channel.
 * The unit of the ramp time value is ms.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[out] pRamp        Ramp time to be read
 *
 * @retval     MIO_ER_*     Common error
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_GetRamp(void *DrvId, UINT32 Chan, PVA2XX_RAMP *pRamp)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_GETRAMP, pRamp);
	return (retValue);
}


/**
 * @ingroup PVA2XX_DoCmds
 * @brief Reads the configured minimum ramp time values of the PWM-signal.
 * The unit of the ramp time value is ms.
 * - Minimum ramp time value for falling edge
 * - Minimum ramp time value for rising edge
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[out] pRampLimits  Maximum and minimum Ramp time to be read
 *
 * @retval     MIO_ER_*     Common error
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_GetRampLimits(void *DrvId, UINT32 Chan, PVA2XX_RAMP_LIMITS *pRampLimits)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_GETRAMP_LIMIT, pRampLimits);
	return (retValue);
}


/**
 * @cond PRIVATE
 * @ingroup PVA2XX_DoCmds
 * @brief This DoCmd is not for customers but for internal purposes. Reads the interpolated curve (flow rate and current rates each 1000 pieces) for the desired channel.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[out] pIntCurve    Interpolated curve
 *
 * @retval     MIO_ER_*     Common error
 * @endcond
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_Get_Interpolated_Curve(void *DrvId, UINT32 Chan, PVA2XX_INTERP *pIntCurve)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_GET_INTERPOLATED_CURVE, pIntCurve);
	return (retValue);
}


/**
 * @cond PRIVATE
 * @ingroup PVA2XX_DoCmds
 * @brief This DoCmd is not for customers but for internal purposes. Writes the desired pwm frequency for the valve to the hardware.
 * The frequency is specified by the parameter FreqPwm in Hz unit. It can be adjusted between 10kHz and 50kHz.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[in]  FreqPwm      Desired PWM frequency to be set for the valve
 *
 * @retval     MIO_ER_*     Common error
 * @endcond
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_SetPwmFreq(void *DrvId, UINT32 Chan, UINT32 FreqPwm)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_SETPWMFREQ, FreqPwm);
	return (retValue);
}


/**
 * @cond PRIVATE
 * @ingroup PVA2XX_DoCmds
 * @brief This DoCmd is not for customers but for internal purposes. Reads the configured pwm frequency for the valve.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[out] pFreqPwm     Configured PWM frequency for the valve
 *
 * @retval     MIO_ER_*     Common error
 * @endcond
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_GetPwmFreq(void *DrvId, UINT32 Chan, UINT32  *pFreqPwm)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_GETPWMFREQ, pFreqPwm);
	return (retValue);
}


/**
 * @cond PRIVATE
 * @ingroup PVA2XX_DoCmds
 * @brief This DoCmd is not for customers but for internal purposes. Sets the PID parameter to the hardware.
 * @param[in]  DrvId        Device Control Block
 * @param[in]  Chan         Channel number
 * @param[in]  pPID         PID parameter to be written in the hardware
 *
 * @retval     MIO_ER_*     Common error
 * @endcond
 * @since V1.00 Release
 */
static inline SINT32 pva2xx_SetPid(void *DrvId, UINT32 Chan, PVA2XX_PID *pPID)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_PVA2XX_SETPID, pPID);
	return (retValue);
}



#endif
