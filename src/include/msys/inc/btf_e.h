/**
********************************************************************************
* @file     btf_e.h
* @author   Diem
*
* @brief Dieses File enthaelt alle Definitionen und Deklarationen
*        welche vom Modul exportiert werden.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef BTF_E__H
#define BTF_E__H

#ifdef __cplusplus
extern  "C"
{
#endif

#include <mtypes.h>

/**
 * @addtogroup BTF-DEF
 * @{
 */

/**
 * @brief Id of a bit field.
 */
typedef struct
{
    UINT32  NbOfElem;  /**< Size of bit field */
    UINT8   Field[1];  /**< Bit field */
} BTF_ID;
/** @} */

/**
 * @addtogroup BTF-API
 * @{
 */

/**
 * @brief This function creates a new bit field and returns an Id for the created
 *        bit field.
 *
 * This Id is needed as parameter for all other btf_* functions.
 *
 * @param[in]    NbOfElem    Size of bit field
 *
 * @retval     !0 Id of created bit field
 * @retval     0  Out of memory
 */
BTF_ID *btf_New(UINT32 NbOfElem);

/**
 * @brief This function frees a bit field.
 *
 * @param[in]    BtfId    Id of bit field to free
 */
VOID btf_Del(BTF_ID *BtfId);

/**
 * @brief This function resets complete bit field to value 0.
 *
 * @param[in]    BtfId    Id of bit field
 */
VOID btf_ResetAll(BTF_ID *BtfId);

/**
 * @brief This function sets complete bit field to value 1.
 *
 * @param[in]    BtfId    Id of bit field
 */
VOID btf_SetAll(BTF_ID *BtfId);

/**
 * @brief This function sets back one bit of bit field to value 0.
 *
 * @param[in]  BtfId    Id of bit field
 * @param[in]  ElemIdx  Index of Bit to reset (0 - n)
 */
VOID btf_Reset(BTF_ID *BtfId, UINT32 ElemIdx);

/**
 * @brief This function sets one bit of bit field to value 1.
 *
 * @param[in]  BtfId      Id of bit field
 * @param[in]  ElemIdx    Index of Bit to set (0 - n)
 */
VOID btf_Set(BTF_ID *BtfId, UINT32 ElemIdx);

/**
 * @brief This function gets the actual value of one bit of bit field.
 *
 * @param[in]  BtfId    Id of bit field
 * @param[in]  ElemIdx  Index bit to get (0 - n)
 *
 * @retval     1    Bit is set
 * @retval     0    Bit is reset
 */
UINT32 btf_Get(BTF_ID *BtfId, UINT32 ElemIdx);

/**
 * @brief This function searches the first set bit, starting from a start index.
 *
 * Search in wrap around style.
 *
 * @note If the start index is n, n+1 is the first tested bit and n-1 is the
 *       last tested bit.
 *
 * @param[in]  BtfId     Id of bit field
 * @param[in]  StartIdx  Index of start bit (0 - n)
 *
 * @retval     !-1   Index of next set bit.
 * @retval     -1    No set bit found.
 */
SINT32 btf_FindSet(BTF_ID *BtfId, UINT32 StartIdx);

/**
 * @brief This function searches the first reset bit, starting from a start index.
 *
 * Search in wrap around style.
 *
 * @note If the start index is n, n+1 is the first tested bit and n-1 is the
 *       last tested bit.
 *
 * @param[in]  BtfId     Id of bit field
 * @param[in]  StartIdx  Index of start bit (0 - n)
 *
 * @retval     !-1   Index of next reset bit.
 * @retval     -1    No reset bit found.
 */
SINT32 btf_FindReset(BTF_ID *BtfId, UINT32 StartIdx);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
