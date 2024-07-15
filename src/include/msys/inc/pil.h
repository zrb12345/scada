/**
********************************************************************************
* @file     pil.h
* @author   STFU
*
* @brief This file contains all definitions and declarations exported by
*        the process image library.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef _PIL_H
#define _PIL_H

#include <mtypes.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @addtogroup PIL-DEF
 * @{
 */

/**
 * @name Debug Options
 */
#define PIL_DEBUG_ADD        0x0001 /**< Debugmode PIL AddCard */
#define PIL_DEBUG_OPT        0x0002 /**< Debugmode PIL Optimization Modes */
#define PIL_DEBUG_SCALEING   0x0004 /**< Debugmode PIL Scaled Cards */
/** @} */

typedef void *PIL_ID;           /**< Process image ID */

/**
 * @brief Information of a scaled channel
 */
typedef struct PIL_SCALEDCHAN
{
    UINT32  pil_Used:1;         /**< channel is used */
    UINT32  pil_Scaled:1;       /**< channel is scaled */
    UINT32  pil_ImageIn:1;      /**< is a process image input */
    UINT32  pil_ImageOut:1;     /**< is a Process image output */
    UINT16  pil_ConfSviType;    /**< configured SVI_F_* type of channel */
    UINT16  pil_ConfSviLen;     /**< data size */
} PIL_SCALEDCHAN;
/** @} */

/**
 * @addtogroup PIL-API
 * @{
 */

/**
 * @brief Create a new process image instance.
 *
 * @code{.c}
procImgId = pil_CreateProcessImage(pTask->pTaskInfo->Name,
                                   pTask->pTaskInfo->VxPriority, 0);
@endcode
 *
 * @param[in]  pAppName  Name of the application
 * @param[in]  Prio      Priority of hardware process image (task priority)
 * @param[in]  Options   Options for created process image (not in use)
 *
 * @retval     !NULL     Valid process image ID
 * @retval     NULL      Error
 */
PIL_ID pil_CreateProcessImage(const CHAR8 *pAppName, UINT32 Prio, UINT32 Options);

/**
 * @brief Delete an existing process image instance.
 *
 * @param[in]  ImgId         Process image ID returned by the function pil_CreateProcessImage()
 */
void pil_DeleteProcessImage(PIL_ID ImgId);

/**
 * @brief Initialize a process image of all configured cards and channels.
 *
 * @param[in]  ImgId         Process image ID returned by the function pil_CreateProcessImage()
 * @param[in]  BCRDrvId      NULL for non-redundancy process image.
 *                           If redundancy is used DrvId of BCR-Card.
 */
void pil_InitProcessImage(PIL_ID ImgId, void *BCRDrvId);

/**
 * @brief Read a process image of all configured cards and channels.
 *
 * @param[in]  ImgId         Process image ID returned by the function pil_CreateProcessImage()
 * @param[in]  BCRDrvId      NULL for non-redundancy process image.
 *                           If redundancy is used DrvId of BCR-Card.
 */
void pil_GetProcessImage(PIL_ID ImgId, void *BCRDrvId);

/**
 * @brief Write a process image of all configured cards and channels.
 *
 * @param[in]  ImgId         Process image ID returned by the function pil_CreateProcessImage()
 * @param[in]  BCRDrvId      NULL for non-redundancy process image.
 *                           If redundancy is used DrvId of BCR-Card.
 */
void pil_SetProcessImage(PIL_ID ImgId, void *BCRDrvId);

/**
 * @brief Add a MIO card to a process image instance.
 *
 * @code{.c}
pil_AddMioCard(procImgId, pTestItem->moduleNb, (UINT32*)pImageNew, ImageSize, NULL, 0)
@endcode
 *
 * @param[in]  ImgId         Process image ID returned by the function pil_CreateProcessImage()
 * @param[in]  CardNb        MIO card number
 * @param[out] pImageNew     Pointer to the process image data area. The size of this
 *                           area must be the number of all available channels of a card.
 *                           Every channels value is from data type SINT32.
 * @param[in]  ImageSize     Size of the pImageNew data area in bytes
 * @param[in]  pChanList     If NULL all channels are read and written while calling the
 *                           get and set function else a bit coded list of used channels
 *                           can be configured. Only the channels with high bit are read
 *                           or written.
 * @param[in]  ChanCou       Number of channels in pChanList
 * @param[in]  pChanList     Additional info for each channel
 * @param[in]  ImageSize     Number of channels in pChannelList the size of pChannelList
 *                           must be ('number of available channels' + 7) / 8 bytes.
 *
 * @retval     0             OK
 * @retval     <0            Error
 */
SINT32 pil_AddMioCard(PIL_ID ImgId, UINT32 CardNb, UINT32 *pImageNew,
                      UINT32 ImageSize, const UINT8 *pChanList, UINT32 ChanCou);

/**
 * @brief Add a MIO card to a process image instance with optional scaled values
 *
 * @param[in]  ImgId         Process image ID returned by the function pil_CreateProcessImage()
 * @param[in]  CardNb        MIO card number
 * @param[out] pImageNew     Pointer to the process image data area. The size of this
 *                           area must be the number of all available channels of a card.
 *                           Every channels value is from data type SINT32.
 * @param[in]  ImageSize     Size of the pImageNew data area in bytes
 *
 * @param[in]  pChanBitList  Only the channels with high bit are read
 *                           or written.
 * @param[in]  pChanList     Additional info for each channel
 * @param[in]  ChanCou       Number of channels in pChanList
 *
 * @retval     0             OK
 * @retval     <0            Error
 */
SINT32 pil_AddScaledCard(const PIL_ID ImgId, UINT32 CardNb, UINT32 *pImageNew,
                         UINT32 ImageSize, const UINT8 *pChanBitList,
                         const PIL_SCALEDCHAN *pChanList, UINT32 ChanCou);

/**
 * @brief Calculate the process image size of the driver with count of all channels
 *
 * @code{.c}
pil_GetDrvPiSize(DrvId, &cardInf, &drvSize, "PIL_")
@endcode
 *
 * @param[in]  DrvId         MIO driver Id
 * @param[in]  pCardInf      Card info
 * @param[out] pDrvSize      Size of process image
 * @param[in]  fn            String containing name of caller. Only used for log messages.
 *
 * @retval     0             OK
 * @retval     -1            Error
 */
SINT32 pil_GetDrvPiSize(const VOID *DrvId, const MIO_CARDINF *pCardInf,
                        UINT32 *pDrvSize, const CHAR *fn);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
