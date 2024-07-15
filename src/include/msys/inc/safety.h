/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     safety.h
* @author   Jochum
* @brief    Interface description for the safety modules SLC284, SDI208 and
*           SDO204.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef SAFETY__H
#define SAFETY__H

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
 * Safety specific channel information
 * @since V1.03.01 Beta
 */
typedef struct
{
    BOOL32  TactActive;         /**< Test tact active for that channel */
    UINT32  SafeDelayTime;      /**< Safe delay time in ms */
} SAFETY_CHANNEL;

/**
 * Safety specific information for channels on a safety module
 * @since V1.03.01 Beta
 */
typedef struct
{
    UINT32          OutTactTime;     /**< Output tact time in ms */
    UINT32          InTactTime; /**< Input tact time in ms */
    UINT32          NbChans;    /**< Number of channels on the module */
    SAFETY_CHANNEL  Channels[24];    /**< Channel information */
} SAFETY_CHANNEL_INFO;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
