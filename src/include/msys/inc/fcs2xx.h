/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     fcs2xx.h
* @author   kesslerm
* @brief    This file contains global definitions for the FCS2XX module.
* @ingroup  FCS2XX_DRV
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef FCS2XX__H
#define FCS2XX__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @name Defines
 * @{
 */

#define FCS_LINK_DOWN   0x0 /**< Link up */
#define FCS_LINK_UP     0x1 /**< Link down */
#define FCS_DUPLEX_HALF 0x0 /**< Half Duplex */
#define FCS_DUPLEX_FULL 0x1 /**< Full Duplex */
#define FCS_SPEED_10    0x00     /**< Speed 10 MBit */
#define FCS_SPEED_100   0x01     /**< Speed 100 MBit */
#define FCS_SPEED_1000  0x02     /**< Speed 1000 MBit */
/** @} */

/**
 * @name Structures
 * @{
 */

/**
 * This typedef contains the base values to scale the
 * fibre diagnostic values.
 */
typedef struct
{
    UINT32  RxPwrWarn;          /**< RX Power Warning */
    UINT32  RxPwrError;         /**< RX Power Error */
    UINT32  RxPwrMax;           /**< RX Power Max */
    UINT32  TxPwrMax;           /**< TX Power Max */
} FCS_FO_SCALEVALUES_T;

/**
 * This typedef is needed to configure mirroring.
 */

typedef struct
{
    UINT16  MirrorCaptPortNbr;  /**< Portnumber of capture port. */
    UINT16  MirrorSrcPorts;     /**< Portnumbers of mirror port.
                                   Bit 0 is Port 1 and so on.
                                   A Port is selected as source when
                                   the corresponding Bit is set. */
} FCS_MIRRORCFG_T;
/** @} */

#ifdef __cplusplus
}
#endif

#endif
