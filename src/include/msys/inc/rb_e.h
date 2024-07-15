/**
********************************************************************************
* @file     rb_e.h
* @author   Lang
*
* @brief Dieses File enthaelt alle Definitionen und Deklarationen
*        welche vom Modul exportiert werden..
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef RB__H                           /* Problemvermeidung bei mehr- */
#define RB__H                           /* maligem Inkludieren des Files */

#ifdef __cplusplus
extern  "C"
{
#endif

#include <lst_e.h>

/**
 * @addtogroup RB-DEF
 * @{
 */

/**
 * @name Possible modes for ringbuffer
 * @{
 */
#define RB_M_CONST  1                   /**< Ringbuffer with elements of constant size */
#define RB_M_DYN    2                   /**< Ringbuffer with elements of dynamic size
                                             @attention Not yet implemented! */
/** @} */

/**
 * @brief Ringbuffer root
 */
typedef struct
{
    UINT32  Count;                      /**< Number of elements in the ring buffer */
    UINT32  ElemSize;                   /**< Size of one element */
    UINT32  BlockSize;                  /**< Number of elements per block */
    UINT32  Mode;                       /**< Mode of ring buffer */
    CHAR   *pGet;                       /**< Pointer to actual Get-Block */
    UINT32  GetIdx;                     /**< Index of actual Get-Block-Element */
    CHAR   *pPut;                       /**< Pointer to actual Put-Block */
    UINT32  PutIdx;                     /**< Index of actual Put-Block-Element */
    LST_ID *BlockLstId;                 /**< Pointer to list of blocks */
} RB_ID;
/** @} */

/**
 * @addtogroup RB-API
 * @{
 */

/**
 * @brief This function creates a new ring buffer.
 *
 * @param[in]  BlockSize   Size of ring buffer
 * @param[in]  ElemSize    Size of element of a list node
 * @param[in]  Mode        Mode of ring buffer (#RB_M_CONST or #RB_M_DYN)
 *
 * @retval     0     Insufficient memory
 * @retval     !0    Pointer to ID of ring buffer
 */
RB_ID *rb_New(UINT32 BlockSize, UINT32 ElemSize, UINT32 Mode);

/**
 * @brief This function deletes a ring buffer.
 *
 * @param[in]  RbId  Pointer to ID of ring buffer
 */
VOID rb_Del(RB_ID *RbId);

/**
 * @brief This function puts a new element into a ring buffer.
 *
 * @param[in]  RbId  Pointer to ID of ring buffer
 * @param[in]  Data  Pointer to element to put into the ring buffer
 *
 * @retval     -1    Not enough space in ring buffer.
 * @retval     0     Element has been put to ring buffer
 */
SINT32 rb_Put(RB_ID *RbId, VOID *Data);

/**
 * @brief This function reads the oldest element of a ring buffer.
 *
 * @param[in]  RbId  Pointer to ID of ring buffer
 * @param[in]  Data  Pointer to read buffer
 * @param[out] Data  Read data
 *
 * @retval     -1    No element in ring buffer
 * @retval     0     element successfully read
 */
SINT32 rb_Get(RB_ID *RbId, VOID *Data);

/**
 * @brief This function determines the number of elements in a ring buffer.
 *
 * @param[in]  RbId  Pointer to ID of ring buffer
 *
 * @returns    Number of elements in the ring buffer
 */
UINT32 rb_GetCount(RB_ID *RbId);

/**
 * @brief This function calls an independent function for each element
 *        of the ring buffer starting with the oldest element.
 *
 * The run-through of the ring buffer can be stopped by a return value unequal
 * zero of the function `UserFunc`.
 *
 * @param[in]  RbId      Pointer to ID of ring buffer
 * @param[in]  UserFunc  Pointer to function which will be applied to
 *                       each element of the ring buffer.
 * @param[in]  arg       The parameter can be used freely by the application
 *                       and is directly passed to the `UserFunc` function.
 *
 * @retval     0     Run-through of ring buffer has not been stopped.
 * @retval     !0    Pointer to element; run-through of ring buffer has been
 *                   stopped at that element.
 */
#ifdef RB_MAIN
VOID *rb_Walk2Head(RB_ID *RbId, SINT32(*UserFunc) (VOID *p_Data, UINT32 arg), UINT32 arg);
#else
VOID *rb_Walk2Head(RB_ID *RbId, SINT32(*UserFunc) (), ...);
#endif

/** @} */

#ifdef __cplusplus
}
#endif

#endif
