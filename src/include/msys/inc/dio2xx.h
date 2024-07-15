/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     dio2xx.h
* @author   Holl
* @brief    Structures, constants and commands of the DIO2XX Retrofit.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef DIO2XX__H
#define DIO2XX__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @name Defines
 * @{
 */
/** @} */

/**
 * @name Structures
 * @{
 */

/**
 * Structure to hold the PWM configuration for a DIO2xx.
 *  @see #MIO_CMD_SETPWMCFG
 *  @see #MIO_CMD_GETPWMCFG
 * @since V2.18 Release
 */
typedef struct
{
    UINT32  Enabled;            /**< 0 == disabled, !0 == enabled */
    UINT32  Period;             /**< Period duration, 1000us to 1080000us in 132us steps */
    UINT32  PulseWidth;         /**< Pulse width, 0% = 0; 100% = 32767 */
    UINT32  PullTime;           /**< Pull time, 0us to 2000000us in 135000us steps */
} DIO_PWMCFG;

/** @} */

/**
 * @name DoCmds
 * @{
 */

/** @} */

#ifdef __cplusplus
}
#endif

#endif
