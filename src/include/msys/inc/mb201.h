/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     mb201.h
* @author   Gau Michael
* @brief    Interface description for the mb201 module.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef MB201__H
#define MB201__H

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
 * Mbus specific information for channels
 * @since V1.03.01 Beta
 */
typedef struct
{
    REAL64  Scale;              /**< Scale factor for mio value */
    REAL64  Offset;             /**< Offset of mio value */
    UINT32  BaseSiUnit;         /**< Base unit as int value */
    CHAR8   BaseUnitStr[24];    /**< Base unit as text */
    UINT32  Spare[16];          /**< Spares */
} MBUS_CHAN_SCALE;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
