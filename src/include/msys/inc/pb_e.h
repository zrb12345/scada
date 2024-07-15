/**
********************************************************************************
* @file     pb_e.h
* @author   Fritsche
*
* @brief This file contains all definitions and declarations exported by
*        the Profibus Server for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef PB_E__H 
#define PB_E__H

#ifdef __cplusplus
extern "C" {
#endif

#include <pb.h>

/**
 * @addtogroup PROFIBUS-API
 * @{
 */

/* pb_main.c */

/**
 * @private
 * @brief Initializes the PB server module.
 * This function is internal called at startup.
 *
 * @retval  0           PB server successfully initialized
 * @retval  #M_E_BOOT2  initialization error
 */
SINT32 pb_Init(VOID);

/**
 * @private
 * @brief Deinstall the PB server module at boot error
 */
VOID pb_Deinit(VOID);

/* pb_lib.c */

/**
 * @brief Determines the network name from the DPM200 module number
 *
 * @param[in]  CardNb       DPM200 module number
 * @param[in]  pBuff        Pointer to the name buffer
 * @param[in]  BuffLen      Length of the buffer (#PB_NETNAMELEN_A required)
 * @param[out] pBuff        Configured or default network name
 *
 * @retval #PB_E_OK         Network name successfully returned
 * @retval #PB_E_FAILED     Wrong module number or buffer to small
 */
SINT32 pb_GetNetName(UINT32 CardNb, CHAR *pBuff, UINT32 BuffLen);

/**
 * @brief Determines the network number from the network name. The returned network
 * number has to be used as access handle with all other PB library functions.
 *
 * @param[in]  pNetName     Pointer to the network name
 * @param[out] pNetNumber   Pointer for returning the network number
 *
 * @retval #PB_E_OK         Network number successfully returned
 * @retval #PB_E_FAILED     Network with the passed name not found
 *
 * @note The returned network number starts with zero for the network of the
 *       first DPM200 module. Therefore, the returned access handle differs to
 *       the configured 'NetNb' in the MConfig.ini file! The 'NetNb' is used
 *       for generating default network names 'Net1', 'Net2' and 'Net3' if the
 *       optional 'NetName' keyword isn't configured.
 */
SINT32 pb_GetNetNumber(CHAR *pNetName, UINT32 *pNetNumber);

/**
 * @brief Returns the configuration filename (*.2bf) of the PB network
 *
 * @param[in]  NetNumber    Network number (returned by the pb_GetNetNumber())
 * @param[in]  pBuff        Pointer to the name buffer
 * @param[in]  BuffLen      Length of the buffer (#M_FILENAMELEN_A required)
 * @param[out] pBuff        Configuration filename
 *
 * @retval #PB_E_OK         Filename successfully returned
 * @retval #PB_E_FAILED     Wrong network number or buffer to small
 *
 * @note The filename is always returned in lowercase.
 */
SINT32 pb_GetCfgFileName(UINT32 NetNumber, CHAR *pBuff, UINT32 BuffLen);

/**
 * @brief Returns the actual user interface state of the PB network
 *
 * @param[in]  NetNumber    Network number (returned by the pb_GetNetNumber())
 * @param[out] pUSIFState   Pointer for returning the user interface state  (@ref PB_S_)
 *
 * @retval #PB_E_OK         User interface state successfully returned
 * @retval #PB_E_FAILED     Wrong network number
 * @retval #PB_E_TIMEOUT    Timeout during communication with the DPM202 module
 */
SINT32 pb_GetMode(UINT32 NetNumber, UINT32 *pUSIFState);

/**
 * @brief Function for setting a new user interface state for he PB network.
 *
 * @param[in]  NetNumber    Network number (returned by the pb_GetNetNumber())
 * @param[in]  USIFState    New user interface state  (@ref PB_S_)
 *
 * @retval #PB_E_OK         User interface state successfully returned
 * @retval #PB_E_FAILED     Wrong network number
 * @retval #PB_E_IV         Invalid USIFStat parameter passed
 * @retval #PB_E_NO         State change not possible at current module state
 * @retval #PB_E_TIMEOUT    Timeout during communication with the DPM202 module
 */
SINT32 pb_SetMode(UINT32 NetNumber, UINT32 USIFState);

/**
 * @brief With this function, an application program can synchronize with the
 * profibus interface. The function is returning to the caller, after one fully
 * profibus token cycle was executed by the DP master. This means, that all
 * activated DP slaves were at least once addressed since function-call.
 *
 * The function execution is only possible at a DP Masters in the operating
 * modes @b CLEAR and  @b OPERATE (see @ref PB_S_).
 *
 * According to the Profibus DP specification, this function is mainly used for
 * compliance with waiting times (slave delay settings) after executing one of
 * the global control commands @b SYNC/UNSYNC or @b FREEZE/UNFREEZE.
 * Since these delays are already automatically maintained by the DPM200
 * firmware, an application can use this function for other purposes, for
 * example synchronize with the bus-cycle and/or determine the cycle time,
 * if necessary.
 *
 * @param[in]  NetNumber    Network number (returned by the pb_GetNetNumber())
 * @param[out] pMarkInfo    Pointer for returning the mark information data
 *
 * @retval #PB_E_OK         Mark successfully executed and data returned
 * @retval #PB_E_FAILED     Wrong network number
 * @retval #PB_E_NO         Execution not possible at current module state, Master
 *                          in @b OFFLINE or @b STOP mode or if no Master is activated
 *                          (Slave only)
 * @retval #PB_E_TIMEOUT    Timeout during communication with the DPM202 module
 *
 * @note The parameter CycleTime is a BE specific extension in the PB_MARKINFO
 *       structure, which is not defined in the Profibus DP specification. The
 *       parameter provides the approximate data cycle time in microseconds
 *       (1-2 cycles accuracy).
 */
SINT32 pb_Mark(UINT32 NetNumber, PB_MARKINFO *pMarkInfo);

/**
 * @brief With this function, a new bus parameter set can be loaded.
 *
 * @param[in]  NetNumber    Network number (returned by the pb_GetNetNumber())
 * @param[in]  pBusPar      Pointer to the new parameter set
 *
 * @retval #PB_E_OK         New bus parameters successfully loaded
 * @retval #PB_E_FAILED     Wrong network number
 * @retval #PB_E_IV         Invalid parameter set passed
 * @retval #PB_E_NO         Execution not possible at current module state
 * @retval #PB_E_TIMEOUT    Timeout during communication with the DPM202 module
 *
 * @note This function is not supported currently by the DPM200 firmware
 */
SINT32 pb_LoadBusPar(UINT32 NetNumber, PB_BUSPAR *pBusPar);

/**
 * @brief Returns the actual bus parameter set of the PB network
 *
 * @param[in]  NetNumber    Network number (returned by the pb_GetNetNumber())
 * @param[in]  pBusPar      Pointer to the bus parameter buffer
 * @param[in]  Length       Buffer length (sizeof(#PB_BUSPAR) required)
 * @param[out] pBusPar      Actual bus parameter set of the PB network
 *
 * @retval #PB_E_OK         User interface state successfully returned
 * @retval #PB_E_FAILED     Wrong network number or invalid Length given
 * @retval #PB_E_TIMEOUT    Timeout during communication with the DPM202 module
 */
SINT32 pb_ReadBusPar(UINT32 NetNumber, PB_BUSPAR *pBusPar, UINT32 Length);

/**
 * @brief This function sends a global control command (@ref PB_CC_) to one specific
 * or a group of DP slaves.
 *
 * The @b RemoteAddr parameter selects the DP slaves(s) for which the command is
 * determined. Addresses within the range 1..123 addressing a single DP slave and
 * the multicast address 127 (#PB_GLOBALADR) one or multiple DB slave groups.
 *
 * In case of multicast addressing the @b GroupSelect parameter is used for selecting
 * the target groups. For Group 0 (all groups according DP specification), the
 * value 255 has to be passed.
 *
 * @param[in]  NetNumber    Network number (returned by the pb_GetNetNumber())
 * @param[in]  RemoteAddr   Target slave address 0-123 or multicast address 127
 * @param[in]  Command      Control command see  @ref PB_CC_
 * @param[in]  GroupSelect  Target slave group(s) used with multicast addressing
 *
 * @retval #PB_E_OK         Control command successfully sent
 * @retval #PB_E_FAILED     Wrong network number
 * @retval #PB_E_NO         Execution not possible at current module state or
 *                          invalid command
 * @retval #PB_E_DS         DP Slave station disconnected or not part of the
 *                          logical token circuit of this DP master.
 * @retval #PB_E_TIMEOUT    Timeout during communication with the DPM202 module
 */
SINT32 pb_GlobalControl(UINT32 NetNumber, UINT32 RemoteAddr, UINT32 Command,
                        UINT32 GroupSelect);

/** @} End of PROFIBUS-API */

#ifdef __cplusplus
}
#endif

#endif
