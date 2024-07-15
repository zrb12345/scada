/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file
* @author   Gmeiner
* @brief    This file contains all the definitions and declarations
*           which are exported from the module, and which can be used by other modules
*           on the another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef SCT202__H
#define SCT202__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @addtogroup SCT202_DEF
 * @{
 */

/**
 * @name Defines
 * @{
 */


/**
 * @name Latch Source
 * @{
 */

#define SCT202_LATCH_SRC_SDI    0x00000000   /**< Use SDI of the channel group as latch trigger source */
#define SCT202_LATCH_SRC_CNTR   0x00000001   /**< Use counter of the channel group as latch trigger source */
/** @} */

/**
 * @name Latch Edge
 * @{
 */

#define SCT202_LATCH_EDGE_RISING    0x00000000   /**< Use rising edge for latch trigger */
#define SCT202_LATCH_EDGE_FALLING   0x00000001   /**< Use falling edge for latch trigger */
/** @} */

/**
 * @name Signals
 * @{
 */

/**
 * Mask to check if the signal at SDI 1 is active.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_SDI1      0x00000001
/**
 * Mask to check if the signal at SDI 2 is active.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_SDI2      0x00000002
/**
 * Mask to check if the signal at SDO 1 is active.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_SDO1      0x00000004
/**
 * Mask to check if the signal at SDO 2 is active.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_SDO2      0x00000008
/**
 * Mask to check if the signal at CNT 1 is active.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_CNT1      0x00000010
/**
 * Mask to check if the signal at CNT 2 is active.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_CNT2      0x00000020
/**
 * Mask to check if the software reference signal for INC 1 is active. This signal is set by the
 * safe application only.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_SW_INC1   0x00000100
/**
 * Mask to check if the software reference signal for INC 2 is active. This signal is set by the
 * safe application only.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_SW_INC2   0x00000200
/**
 * Mask to check if the software reference signal for CNT 1 is active. This signal is set by the
 * safe application only.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_SW_CNT1   0x00000400
/**
 * Mask to check if the software reference signal for CNT 2 is active. This signal is set by the
 * safe application only.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_SW_CNT2   0x00000800
/**
 * Mask to check if software reference enable for INC 1 is active. This signal is set by the
 * safe application only.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_EN_REF1   0x00001000
/**
 * Mask to check if software reference enable for INC 2 is active. This signal is set by the
 * safe application only.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_EN_REF2   0x00002000
/**
 * Mask to check if software reference enable for CNT 1 is active. This signal is set by the
 * safe application only.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_EN_REF3   0x00004000
/**
 * Mask to check if software reference enable for CNT 2 is active. This signal is set by the
 * safe application only.
 * @see MIO_CMD_SCT202_GETSIGNALS
 */
#define SCT202_SIGNAL_EN_REF4   0x00008000
/** @} */
/** @} */
/** @} */

/**
 * @addtogroup SCT202_DoCmds
 * @{
 */
#if M_OS_VXWORKS


/*
 * This part contains all abstract do commands of SCT202
 * @generated
 */
#include <mio_e.h>

/**
 * @brief Set latch configuration of an incremental or counter channel
 *
 * @param[in]  DrvId Driver handle returned by the function mio_GetDrv().
 * @param[in]  Chan  Channel number (1-4)
 * @param[in]  src   Latch source (#SCT202_LATCH_SRC_SDI, #SCT202_LATCH_SRC_CNTR)
 * @param[in]  edge  Latch edge (#SCT202_LATCH_EDGE_RISING, #SCT202_LATCH_EDGE_FALLING)
 *
 * @note This function wraps the #MIO_CMD_SCT202_SETLATCHCFG DoCmd. For more detailed information
 *       see #MIO_CMD_SCT202_SETLATCHCFG.
 *
 * @see MIO_CMD_SCT202_SETLATCHCFG
 * @see sct202_GetLatchConfiguration
 * @see MIO_CMD_GETSTRB
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @since V1.07.05 Beta
 */
static inline SINT32 sct202_SetLatchConfiguration(void *DrvId, UINT32 Chan, UINT32 src, UINT32 edge)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_SCT202_SETLATCHCFG, src, edge);
	return (retValue);
}


/**
 * @brief Read latch configuration of an incremental or counter channel
 *
 * @param[in]  DrvId  Driver handle returned by the function mio_GetDrv().
 * @param[in]  Chan  Channel number (1-4)
 * @param[out] pSrc  Pointer to store current latch source
 * @param[out] pEdge Pointer to store current latch edge
 *
 * @note This function wraps the #MIO_CMD_SCT202_GETLATCHCFG DoCmd. For more detailed information
 *       see #MIO_CMD_SCT202_GETLATCHCFG.
 *
 * @see MIO_CMD_SCT202_GETLATCHCFG
 * @see sct202_SetLatchConfiguration
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @since V1.07.05 Beta
 */
static inline SINT32 sct202_GetLatchConfiguration(void *DrvId, UINT32 Chan, UINT32  *pSrc, UINT32  *pEdge)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_SCT202_GETLATCHCFG, pSrc, pEdge);
	return (retValue);
}


/**
 * @brief Read current signals
 *
 * @param[in]  DrvId  Driver handle returned by the function mio_GetDrv().
 * @param[in]  Chan  Channel number (0)
 * @param[out] pSignals Pointer to store current signals
 *
 * @note This function wraps the #MIO_CMD_SCT202_GETSIGNALS DoCmd. For more detailed information
 *       see #MIO_CMD_SCT202_GETSIGNALS.
 *
 * @see MIO_CMD_SCT202_GETSIGNALS
 *
 * @retval #MIO_ER_OK If successful.
 * @retval #MIO_ER_FAIL or one of the similar defines
 * @since V1.07.17 Beta
 */
static inline SINT32 sct202_GetSignals(void *DrvId, UINT32 Chan, UINT32  *pSignals)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_SCT202_GETSIGNALS, pSignals);
	return (retValue);
}


#endif /*M_OS_VXWORKS*/
/** @} */

#ifdef __cplusplus
}
#endif

#endif
