/**
********************************************************************************
* @file     vhd_e.h
* @author   Fritsche
*
* @brief This file contains all definitions and declarations exported by
*        the Visualization Handler for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef VHD_E__H
#define VHD_E__H

#ifdef __cplusplus
extern  "C"
{
#if 0
}
#endif
#endif

#include <vhd.h>

/**
 * @ingroup VHD-API
 * @brief Removes all VHD callback functions for a specific IP address.
 *
 * @param[in]  IPAddr  Specific IP-Address or @c 0 to remove all VHD callback
 *                     functions
 */
void vhd_RemoveAllCallbacks(UINT32 IPAddr);

/**
 * @ingroup VHD-DIAG
 * @brief Print list of VHD sessions to standard output.
 */
void vhd_ShowSession(void);

/**
 * @ingroup VHD-DIAG
 * @brief Print VHD monitoring lists to standard output.
 *
 * This function prints debug information about all monitoring lists for a
 * VHD session specified by `UserId`.
 *
 * @param[in]  UserId  User ID
 */
void vhd_ShowList(UINT32 UserId);

#ifdef __cplusplus
}
#endif

#endif
