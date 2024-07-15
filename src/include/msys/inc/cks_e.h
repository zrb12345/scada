/**
********************************************************************************
* @file     cks_e.h
* @author   Fritsche
*
* @brief This file contains all definitions and declarations exported by
*        the Checksum Library for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef CKS_E__H
#define CKS_E__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @addtogroup CKS-API
 * @{
 */

/**
 * @brief This function creates a 8-bit checksum based on the two's complement
 *        over a data range.
 *
 * @param[in]  pData     Pointer to data structure.
 * @param[in]  DataLen   Length of the data range in bytes.
 *                       The Function starts at the current data-position.
 *                       If a length is indicated which is not modulo 4,
 *                       then the missing bytes will be filled with zeros
 *                       by the function.
 *
 * @returns  Calculated 8 bit checksum
 *
 * @note The function does not ensure that there is no access beyond the
 *       data range. If value of `Datalen` is too big, data beyond data range
 *       will be accessed.
 *
 * <b>Example</b>
 * @snippet doc_lib_cks.c cks_Mem8TC
 */
UINT8 cks_Mem8TC(VOID *pData, UINT32 DataLen);

/**
 * @brief This function creates a 32-bit checksum based on the two's complement
 *        over a data range.
 *
 * @param[in]  pData     Pointer to data structure.
 * @param[in]  DataLen   Length of the data range in bytes.
 *                       The Function starts at the current data-position.
 *                       If a length is indicated which is not modulo 4,
 *                       then the missing bytes will be filled with zeros
 *                       by the function.
 *
 * @returns  Calculated 32 bit checksum
 *
 * @note The function does not ensure that there is no access beyond the
 *       data range. If value of `Datalen` is too big, data beyond data range
 *       will be accessed.
 *
 * <b>Example</b>
 * @snippet doc_lib_cks.c cks_Mem32TC
 */
UINT32 cks_Mem32TC(VOID *pData, UINT32 DataLen);

/**
 * @brief This function creates a 8-bit checksum based on the two's complement
 *        over a file range.
 *
 * @param[in]  FileId        ID of the file to be edited
 * @param[in]  DataLen       Length of the file range in bytes.
 *                           If a length is indicated which is not modulo 4,
 *                           then the missing bytes will be filled with zeros
 *                           by the function.
 *                           The function ensures that there is no access
 *                           beyond the file range.
 *                           The functions starts at the current file-position.
 * @param[out]   pChecksum   Return of the generated checksum.
 *
 * @retval     0   OK
 * @retval     <0  Insufficient free memory or error when reading the file.
 *
 * <b>Example</b>
 * @snippet doc_lib_cks.c cks_File8TC
 */
SINT32 cks_File8TC(SINT32 FileId, UINT32 DataLen, UINT8 *pChecksum);

/**
 * @brief This function creates a 32-bit checksum based on the two's complement
 *        over a file range.
 *
 * @param[in]  FileId        ID of the file to be edited.
 * @param[in]  DataLen       Length of the file range in bytes.
 *                           If a length is indicated which is not modulo 4,
 *                           then the missing bytes will be filled with zeros
 *                           by the function.
 *                           The function ensures that there is no access
 *                           beyond the file range.
 *                           The functions starts at the current file-position.
 * @param[out]   pChecksum   Return of the generated checksum
 *
 * @retval     0  OK
 * @retval     -1 Insufficient free memory or error when reading the file.
 *
 * <b>Example</b>
 * @snippet doc_lib_cks.c cks_File32TC
 */
SINT32 cks_File32TC(SINT32 FileId, UINT32 DataLen, UINT32 *pChecksum);

/** @} */

/*--- Definition of Variables ---*/

#ifdef __cplusplus
}
#endif

#endif
