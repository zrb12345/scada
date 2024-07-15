/**
********************************************************************************
* @file     lst_e.h
* @author   Fritsche
*
* @brief This file contains all definitions and declarations exported by
*        the List Library for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef LST__H
#define LST__H

#ifdef __cplusplus
extern  "C"
{
#endif

#include <mtypes.h>

/**
 * @addtogroup LST-DEF
 * @{
 */

/**
 * @brief List node
 */
typedef struct lst_Node
{
    struct lst_Node *Next;              /**< Pointer to next list element */
    struct lst_Node *Prev;              /**< Pointer to previous list element */
    UINT8   Data[1];                    /**< Data field of element */
} LST_NODE;

/**
 * @brief List root
 */
typedef struct
{
    LST_NODE *Head;                     /**< Pointer to first list element */
    LST_NODE *Earth;                    /**< Optimization pointer */
    LST_NODE *Tail;                     /**< Pointer to last list element */
    UINT32  ElemSize;                   /**< Size of one element in bytes */
    UINT32  iPart;                      /**< Memory partition index */
} LST_ID;

/** @} */

/**
 * @ingroup LST-API
 * @defgroup LST-1 lst_
 * @details Functions for administration of normal and double-linked lists.
 *          Each element of the list is a list node.
 *          <br>These functions operate only in the current memory partition.
 * @{
 */

/**
 * @brief With this function, a new list is created.
 *
 * Principally, only the root of the list is created and initialized.
 * The parameter `ElemSize` specifies the size (in bytes) of the data-elements
 * that are to be managed. It is not necessary to indicate the element's length,
 * if the new elements are inserted exclusively using the functions
 * lst_AddDynHead(), lst_AddDynTail(), lst_AddDynPre() or lst_AddDynPost().
 *
 * @note The function lst_p_New() is equivalent to lst_New() when the memory
 *       from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  ElemSize    Size of element of list node.
 *
 * @retval     0   insufficient memory
 * @retval     !0  identifier for new list
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_New
 */
LST_ID *lst_New(UINT32 ElemSize);

/**
 * @brief With this function, an existing list with all its elements is deleted.
 *
 * After calling this function, the list-ID is invalid and must not be used
 * any more.
 *
 * @note The function lst_p_Del() is equivalent to lst_Del() when the memory
 *       from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed  in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_Del
 */
VOID lst_Del(LST_ID *LstId);

/**
 * @brief This function is used to create a new loose element which will
 *        later fit into the list `LstId`.
 *
 * The element is not inserted into the list. This function is useful,
 * if the filling of elements takes a long time and the list shall be used
 * by two tasks simultaneously. In this way only the insertion of the loose
 * element (e.g. lst_InsTail()) must be protected with semaphores.
 *
 * The size of the element is specified by the function lst_New().
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_NewNode() is equivalent to lst_NewNode() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_NewNode
 */
VOID *lst_NewNode(LST_ID *LstId);

/**
 * @brief This function is used to create a new loose element with a specific size.
 *
 * The element is not inserted into the list. This function is useful,
 * if the filling of elements takes a long time and the list shall be used
 * by two tasks simultaneously. In this way only the insertion of the loose
 * element (e.g. lst_InsTail()) must be protected with semaphores.
 *
 * This function is necessary for lists with elements of different length.
 * The element size transferred to the function lst_New() will be ignored.
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_NewDynNode() is equivalent to lst_NewDynNode() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  ElemSize    Size of new element
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_NewDynNode
 */
VOID *lst_NewDynNode(UINT32 ElemSize);

/**
 * @brief This function deletes the loose element `p_Data`.
 *
 * The function must not be used for elements, which are still inserted
 * in a list.
 *
 * @note The function lst_p_DelNode() is equivalent to lst_DelNode() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  p_Data  Pointer to element to delete
 *
 * <b>Example 1</b>
 * @snippet doc_lib_lst.c lst_NewNode
 * <b>Example 2</b>
 * @snippet doc_lib_lst.c lst_NewDynNode
 */
VOID lst_DelNode(VOID *p_Data);

/**
 * @brief With this function, a new element is inserted at the head of the
 *        list `LstId`.
 *
 * The size of the element is specified by the function lst_New().
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddHead() is equivalent to lst_AddHead() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_AddHead
 */
VOID *lst_AddHead(LST_ID *LstId);

/**
 * @brief With this function, a new element is inserted at the end of the
 *        list `LstId`.
 *
 * The size of the element is specified by the function lst_New().
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddTail() is equivalent to lst_AddTail() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_AddTail
 */
VOID *lst_AddTail(LST_ID *LstId);

/**
 * @brief With this function, a new element is inserted in front of the existing
 *        element `p_Data` in the list `LstId`.
 *
 * If zero is transmitted for `p_Data`, then the element is inserted at the
 * beginning of the list, which may be useful for the construction of sorted
 * lists.
 *
 * The size of the element is specified by the function lst_New().
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddPre() is equivalent to lst_AddPre() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 * @param[in]  p_Data  Pointer to existing element. The new element will be
 *                     inserted in front of that element.
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_AddPre
 */
VOID *lst_AddPre(LST_ID *LstId, VOID *p_Data);

/**
 * @brief With this function, a new element is inserted after the existing
 *        element `p_Data` in the list `LstId`.
 *
 * If zero is transmitted for `p_Data`, then the element is inserted at the
 * beginning of the list, which may be useful for the construction of sorted
 * lists.
 *
 * The size of the element is specified by the function lst_New().
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddPost() is equivalent to lst_AddPost() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 * @param[in]  p_Data  Pointer to existing element. The new element will be
 *                     inserted after that element.
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_AddPost
 */
VOID *lst_AddPost(LST_ID *LstId, VOID *p_Data);

/**
 * @brief With this function, the loose element `p_Data` is inserted at the
 *        head of the list `LstId`.
 *
 * Loose elements are only created with the functions lst_NewNode(),
 * lst_NewDynNode() or lst_Unlink*().
 *
 * @note The function lst_p_InsHead() is equivalent to lst_InsHead() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 * @param[in]  p_Data  Pointer to a loose element
 *
 * @retval     0   List destroyed
 * @retval     !0  Pointer to a loose element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_InsHead
 */
VOID *lst_InsHead(LST_ID *LstId, VOID *p_Data);

/**
 * @brief With this function, the loose element `p_Data` is inserted at the end
 *        of the list `LstId`.
 *
 * Loose elements are only created with the functions lst_NewNode(),
 * lst_NewDynNode() or lst_Unlink*().
 *
 * @note The function lst_p_InsTail() is equivalent to lst_InsTail() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 * @param[in]  p_Data  Pointer to a loose element
 *
 * @retval     0   List destroyed
 * @retval     !0  Pointer to a loose element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_InsTail
 */
VOID *lst_InsTail(LST_ID *LstId, VOID *p_Data);

/**
 * @brief This function inserts the loose element `p_Data` in front of the element
 *        `p_RefData` of the list `LstId`.
 *
 * If zero is transmitted for `p_RefData` then the element is inserted at the end
 * of the list, which may be useful for the construction of sorted lists.
 *
 * Loose elements are only created with the functions lst_NewNode(),
 * lst_NewDynNode() or lst_Unlink*().
 *
 * @note The function lst_p_InsPre() is equivalent to lst_InsPre() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId           ID of the list returned by the function lst_New()
 * @param[in]  p_RefData       Pointer to existing element. The new element
 *                             will be inserted in front of that element.
 * @param[in]  p_Data          Pointer to a loose element
 *
 * @retval     0   List destroyed
 * @retval     !0  Pointer to a loose element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_InsPre
 */
VOID *lst_InsPre(LST_ID *LstId, VOID *p_RefData, VOID *p_Data);

/**
 * @brief This function inserts the loose element `p_Data` after the element
 *        `p_RefData` of the list `LstId`.
 *
 * If zero is transmitted for `p_RefData` then the element is inserted at the
 * beginning of the list, which may be useful for the construction of sorted
 * lists.
 *
 * Loose elements are only created with the functions lst_NewNode(),
 * lst_NewDynNode() or lst_Unlink*().
 *
 * @note The function lst_p_InsPost() is equivalent to lst_InsPost() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId           ID of the list returned by the function lst_New()
 * @param[in]  p_RefData       Pointer to existing element. The new element
 *                             will be inserted after that element.
 * @param[in]  p_Data          Pointer to a loose element
 *
 * @retval     0   List destroyed
 * @retval     !0  Pointer to a loose element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_InsPost
 */
VOID *lst_InsPost(LST_ID *LstId, VOID *p_RefData, VOID *p_Data);

/**
 * @brief This function is used to insert a new element with a specific size
 *        in the header of the list.
 *
 * This function is necessary for lists with elements of different length.
 * The element size transferred to the function lst_New() will be ignored.
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddDynHead() is equivalent to lst_AddDynHead() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId       ID of the list returned by the function lst_New()
 * @param[in]  ElemSize    Size of the new element
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_AddDynHead
 */
VOID *lst_AddDynHead(LST_ID *LstId, UINT32 ElemSize);

/**
 * @brief This function is used to insert a new element with a specific size
 *        at the end of the list `LstId`.
 *
 * This function is necessary for lists with elements of different length.
 * The element size transferred to the function lst_New() will be ignored.
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddDynTail() is equivalent to lst_AddDynTail() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId       ID of the list returned by the function lst_New()
 * @param[in]  ElemSize    Size of the new element
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_AddDynTail
 */
VOID *lst_AddDynTail(LST_ID *LstId, UINT32 ElemSize);

/**
 * @brief This function inserts a new element with a specific size in front of
 *        the element `p_Data` of the list `LstId`.
 *
 * If zero is transmitted for `p_Data`, then the element is inserted at the
 * end of the list, which may be useful for the construction of sorted lists.
 *
 * This function is necessary for lists with elements of different length.
 * The element size transferred to the function lst_New() will be ignored.
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddDynPre() is equivalent to lst_AddDynPre() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId       ID of the list returned by the function lst_New()
 * @param[in]  p_Data      Pointer to existing element. The new element
 *                         will be inserted in front of that element.
 * @param[in]  ElemSize    Size of the new element
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_AddDynPre
 */
VOID *lst_AddDynPre(LST_ID *LstId, VOID *p_Data, UINT32 ElemSize);

/**
 * @brief This function inserts a new element with a specific size after the
 *        element `p_Data` of the list `LstId`.
 *
 * If zero is transmitted for `p_Data`, then the element is inserted at the
 * beginning of the list, which may be useful for the construction of sorted
 * lists.
 *
 * This function is necessary for lists with elements of different length.
 * The element size transferred to the function lst_New() will be ignored.
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddDynPost() is equivalent to lst_AddDynPost() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId       ID of the list returned by the function lst_New()
 * @param[in]  p_Data      Pointer to existing element. The new element
 *                         will be inserted after that element.
 * @param[in]  ElemSize    Size of the new element
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_AddDynPost
 */
VOID *lst_AddDynPost(LST_ID *LstId, VOID *p_Data, UINT32 ElemSize);

/**
 * @brief With this function, the first element of the list `LstId` can be
 *        removed.
 *
 * The allocated memory will be released and the linking of the list will be
 * updated.
 * If the list is empty, calling this function has no effect.
 *
 * @note The function lst_p_RemHead() is equivalent to lst_RemHead() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_RemHead
 */
VOID lst_RemHead(LST_ID *LstId);

/**
 * @brief With this function, the last element of the list `LstId` can be removed.
 *
 * The allocated memory will be released and the linking of the list will be
 * updated.
 * If the list is empty, calling this function has no effect.
 *
 * @note The function lst_p_RemTail() is equivalent to lst_RemTail() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_RemTail
 */
VOID lst_RemTail(LST_ID *LstId);

/**
 * @brief With this function, the element `p_Data` can be removed.
 *
 * The allocated memory will be released and the linking of the list will be
 * updated.
 *
 * @note The function lst_p_RemNode() is equivalent to lst_RemNode() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @note After accessing this function, the parameter `p_Data` points to a
 *       free memory range and therefore must not be used further
 *       (alternative is lst_UnlinkNode()).
 *
 * @param[in]  p_Data  Pointer to element to delete
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_RemNode
 */
VOID lst_RemNode(VOID *p_Data);

/**
 * @brief With this function, the first element of the list `LstId` is removed and
 *        converted into a loose element.
 *
 * This element can be inserted into another list.
 *
 * @note The function lst_p_UnlinkHead() is equivalent to lst_UnlinkHead() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 *
 * @retval     0   list is empty
 * @retval     !0  Pointer on a remote element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_UnlinkHead
 */
VOID *lst_UnlinkHead(LST_ID *LstId);

/**
 * @brief With this function, the last element of the list `LstId` is removed and
 *        converted into a loose element.
 *
 * This element can be inserted into another list.
 *
 * @note The function lst_p_UnlinkTail() is equivalent to lst_UnlinkTail() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 *
 * @retval     0   list is empty
 * @retval     !0  Pointer on a remote element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_UnlinkTail
 */
VOID *lst_UnlinkTail(LST_ID *LstId);

/**
 * @brief With this function, the element `p_Data` is removed from its list and
 *        converted into a loose element.
 *
 * This element can be inserted into another list.
 *
 * @note The function lst_p_UnlinkNode() is equivalent to lst_UnlinkNode() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 *  @param[in]  p_Data  Pointer to desired element
 *
 * @retval     0   list is empty
 * @retval     !0  Pointer on a remote element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_UnlinkNode
 */
VOID *lst_UnlinkNode(VOID *p_Data);

/**
 * @brief Makes a query whether the node is a loose one or not.
 *
 * @note The function lst_p_IsNodeFree() is equivalent to lst_IsNodeFree() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  p_Data  Pointer to the requesting element
 *
 * @retval     0  Node is not loose
 * @retval     1  Node is a loose one
 */
BOOL32  lst_IsNodeFree(VOID *p_Data);

#ifdef LST_MAIN
/**
 * @brief With this function, one can access an independent function `UserFunc`,
 *        which will be applied to each element of the list `LstId`.
 *
 * Besides the function-pointer a 32 bit long argument `arg` can be transmitted,
 * which will be passed to the independent function.
 * If the list is empty, calling this function has no effect.
 *
 * @note The function lst_p_WalkList() is equivalent to lst_WalkList() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId           ID of the list returned by the function lst_New()
 * @param[in]  UserFunc        Pointer to function which will be applied to
 *                             each element of the list `LstId`.
 * @param[in]  arg             Optional argument (of 4 byte) for function `UserFunc`.
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_WalkList
 */
VOID lst_WalkList(LST_ID *LstId, VOID(*UserFunc)(VOID *p_Data, UINT32 arg), UINT32 arg);

/**
 * @brief With this function, one can access an independent function `UserFunc`,
 *        which will be applied to each element of the list `LstId`.
 *
 * The run-through of the list `LstId` can be stopped by the return value of the function
 * `UserFunc`. To stop the run-through of the list `LstId`, the return value of
 * the function `UserFunc` has to be unequal zero.
 * Besides the function-pointer a 32 bit long argument `arg` can be transmitted,
 * which will be passed to the independent function.
 * If the list is empty, calling this function has no effect.
 *
 * @note The function lst_p_SearchList() is equivalent to lst_SearchList() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId           ID of the list returned by the function lst_New()
 * @param[in]  UserFunc        Pointer to function which will be applied to
 *                             each element of the list `LstId`.
 * @param[in]  arg             Optional argument (of 4 byte) for function `UserFunc`.
 *
 * @retval     0   List destroyed or run-through of list has not been stopped.
 * @retval     !0  Pointer to element; run-through of list has been stopped at
 *                 that element.
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_SearchList
 */
VOID *lst_SearchList(LST_ID *LstId, SINT32(*UserFunc)(VOID *p_Data, UINT32 arg), UINT32 arg);

/**
 * @brief With this function, one can access an independent function `UserFunc`,
 *        which will be applied to each element of the list `LstId`.
 *
 * The run-through of the list `LstId` can be stopped by the return value of the function
 * `UserFunc`. To stop the run-through of the list `LstId`, the return value of
 * the function `UserFunc` has to be unequal zero.
 * Besides the function-pointer two 32 bit long arguments `arg0` and `arg1` can be transmitted,
 * which will be passed to the independent function.
 * If the list is empty, calling this function has no effect.
 *
 * @param[in]  LstId           ID of the list returned by the function lst_New()
 * @param[in]  UserFunc        Pointer to function which will be applied to
 *                             each element of the list `LstId`.
 * @param[in]  arg0            Optional argument (of 4 byte) for function `UserFunc`.
 * @param[in]  arg1            Optional argument (of 4 byte) for function `UserFunc`.
 *
 * @retval     0   List destroyed or run-through of list has not been stopped.
 * @retval     !0  Pointer to element; run-through of list has been stopped at
 *                 that element.
 */
VOID *lst_SearchList2(LST_ID *LstId,
                        SINT32(*UserFunc)(VOID *p_Data, UINT32 arg0, UINT32 arg1),
                        UINT32 arg0, UINT32 arg1);
#else
VOID lst_WalkList(LST_ID *LstId, VOID(*UserFunc)(), ...);
VOID *lst_SearchList(LST_ID *LstId, SINT32(*UserFunc)(), ...);
VOID *lst_SearchList2(LST_ID *LstId, SINT32(*UserFunc)(), ...);
#endif

/**
 * @brief With this function, all elements of the list `LstId` can be deleted.
 *
 * The ID of list (`LstId`) stays valid.
 * If the list is empty, calling this function has no effect.
 *
 * @note The function lst_p_RemoveAll() is equivalent to lst_RemoveAll() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @note If the elements of the list `LstId` contain pointers to allocated memory,
 *       these pointers have to be freed first, to avoid memory leaks.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_RemoveAll
 */
VOID lst_RemoveAll(LST_ID *LstId);

/**
 * @brief With this function, one can get the next element after the element
 *        `p_Data`.
 *
 * @note The function lst_p_GetNext() is equivalent to lst_GetNext() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  p_Data  Pointer to reference element.
 *
 * @retval     0   no next element
 * @retval     !0  pointer to next element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_GetNext
 */
VOID *lst_GetNext(VOID *p_Data);

/**
 * @brief With this function, one can get the previous element of the element
 *        `p_Data`.
 *
 * @note The function lst_p_GetPrev() is equivalent to lst_GetPrev() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  p_Data  Pointer to reference element.
 *
 * @retval     0   no previous element
 * @retval     !0  pointer to previous element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_GetPrev
 */
VOID *lst_GetPrev(VOID *p_Data);

/**
 * @brief With this function, one can get the first element of the list `LstId`.
 *
 * @note The function lst_p_GetHead() is equivalent to lst_GetHead() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 *
 * @retval     0   List is empty or destroyed
 * @retval     !0  pointer to first element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_GetHead
 */
VOID *lst_GetHead(LST_ID *LstId);

/**
 * @brief With this function, one can get the last element of the list `LstId`.
 *
 * @note The function lst_p_GetTail() is equivalent to lst_GetTail() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 *
 * @retval     0   List is empty or destroyed
 * @retval     !0  pointer to last element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_GetTail
 */
VOID *lst_GetTail(LST_ID *LstId);

/**
 * @brief With this function, one can get an element of the list `LstId` by its
 *        index `NodeIdx`.
 *
 * The first index of the list `LstId` has the index 0.
 *
 * @note The function lst_p_GetNodeByIdx() is equivalent to lst_GetNodeByIdx()
 *       when the memory from another partition is to be used.
 *        lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 * @param[in]  NodeIdx Index of desired element (0-n)
 *
 * @retval     0   No element with index `NodeIdx` or list destroyed
 * @retval     !0  Pointer to element with index `NodeIdx`
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_GetNodeByIdx
 */
VOID *lst_GetNodeByIdx(LST_ID *LstId, UINT32 NodeIdx);

/**
 * @brief With this function, the existence of the element `p_Data` in the list
 *        `LstId` can be tested, and if it does at which position it is located
 *        in the list.
 *
 * @note The function lst_p_FindNode() is equivalent to lst_FindNode() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 * @param[in]  p_Data  Pointer to element to find
 *
 * @retval     -1   Loose element does not exist or list destroyed
 * @retval     0-n  Index of the determined element
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_FindNode
 */
SINT32  lst_FindNode(LST_ID *LstId, VOID *p_Data);

/**
 * @brief With this function, the number of elements in the list `LstId` can be
 *        determined.
 *
 * @note The function lst_p_CountNodes() is equivalent to lst_CountNodes() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_New()
 *
 * @returns    Number of elements in list `LstId`
 *
 * <b>Example</b>
 * @snippet doc_lib_lst.c lst_CountNodes
 */
UINT32  lst_CountNodes(LST_ID *LstId);


/** @} */

/**
 * @ingroup LST-API
 * @defgroup LST-2 lst_p_
 * @details Functions for administration of normal and double-linked lists.
 *          Each element of the list is a list node.
 *          <br>The list can be placed at an arbitrary memory partition.
 *          <br>These functions can operate in any memory partition.
 * @{
 */

/*--- Definitions and Declarations for lst_p_xxx Library ---*/

/*--- Function Prototypes ---*/

/**
 * @brief With this function, a new list is created.
 *
 * Principally, only the root of the list is created and initialized.
 * The parameter `ElemSize` specifies the size (in bytes) of the data-elements
 * that are to be managed. It is not necessary to indicate the element's length,
 * if the new elements are inserted exclusively using the functions
 * lst_p_AddDynHead(), lst_p_AddDynTail(), lst_p_AddDynPre() or lst_p_AddDynPost().
 *
 * @note The function lst_p_New() is equivalent to lst_New() when the memory
 *       from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  iPart       Partition
 * @param[in]  ElemSize    Size of element of list node.
 *
 * @retval     0   insufficient memory
 * @retval     !0  identifier for new list
 *
 * @see Example code of lst_New()
 */
LST_ID *lst_p_New(UINT32 iPart, UINT32 ElemSize);

/**
 * @brief With this function, an existing list with all its elements is deleted.
 *
 * After calling this function, the list-ID is invalid and must not be used
 * any more.
 *
 * @note The function lst_p_Del() is equivalent to lst_Del() when the memory
 *       from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 *
 * @see Example code of lst_Del()
 */
VOID lst_p_Del(LST_ID *LstId);

/**
 * @brief This function is used to create a new loose element which will
 *        later fit into the list `LstId`.
 *
 * The element is not inserted into the list. This function is useful,
 * if the filling of elements takes a long time and the list shall be used
 * by two tasks simultaneously. In this way only the insertion of the loose
 * element (e.g. lst_p_InsTail()) must be protected with semaphores.
 *
 * The size of the element is specified by the function lst_p_New().
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_NewNode() is equivalent to lst_NewNode() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * @see Example code of lst_NewNode()
 */
VOID *lst_p_NewNode(LST_ID *LstId);

/**
 * @brief This function is used to create a new loose element with a specific size.
 *
 * The element is not inserted into the list. This function is useful,
 * if the filling of elements takes a long time and the list shall be used
 * by two tasks simultaneously. In this way only the insertion of the loose
 * element (e.g. lst_p_InsTail()) must be protected with semaphores.
 *
 * This function is necessary for lists with elements of different length.
 * The element size transferred to the function lst_p_New() will be ignored.
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_NewDynNode() is equivalent to lst_NewDynNode() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  iPart       Partition
 * @param[in]  ElemSize    Size of new element
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * @see Example code of lst_NewDynNode()
 */
VOID *lst_p_NewDynNode(UINT32 iPart, UINT32 ElemSize);

/**
 * @brief This function deletes the loose element `p_Data`.
 *
 * The function must not be used for elements, which are still inserted
 * in a list.
 *
 * @note The function lst_p_DelNode() is equivalent to lst_DelNode() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  iPart    Partition
 * @param[in]  p_Data   Pointer to element to delete
 *
 * @see Example code of lst_NewNode()
 * @see Example code of lst_NewDynNode()
 */
VOID lst_p_DelNode(UINT32 iPart, VOID *p_Data);

/**
 * @brief With this function, a new element is inserted at the head of the
 *        list `LstId`.
 *
 * The size of the element is specified by the function lst_p_New().
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddHead() is equivalent to lst_AddHead() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * @see Example code of lst_AddHead()
 */
VOID *lst_p_AddHead(LST_ID *LstId);

/**
 * @brief With this function, a new element is inserted at the end of the
 *        list `LstId`.
 *
 * The size of the element is specified by the function lst_p_New().
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddTail() is equivalent to lst_AddTail() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * @see Example code of lst_AddTail()
 */
VOID *lst_p_AddTail(LST_ID *LstId);

/**
 * @brief With this function, a new element is inserted in front of the existing
 *        element `p_Data` in the list `LstId`.
 *
 * If zero is transmitted for `p_Data`, then the element is inserted at the
 * beginning of the list, which may be useful for the construction of sorted
 * lists.
 *
 * The size of the element is specified by the function lst_p_New().
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddPre() is equivalent to lst_AddPre() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 * @param[in]  p_Data  Pointer to existing element. The new element will be
 *                     inserted in front of that element.
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * @see Example code of lst_AddPre()
 */
VOID *lst_p_AddPre(LST_ID *LstId, VOID *p_Data);

/**
 * @brief With this function, a new element is inserted after the existing
 *        element `p_Data` in the list `LstId`.
 *
 * If zero is transmitted for `p_Data`, then the element is inserted at the
 * beginning of the list, which may be useful for the construction of sorted
 * lists.
 *
 * The size of the element is specified by the function lst_p_New().
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddPost() is equivalent to lst_AddPost() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 * @param[in]  p_Data  Pointer to existing element. The new element will be
 *                     inserted after that element.
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * @see Example code of lst_AddPost()
 */
VOID *lst_p_AddPost(LST_ID *LstId, VOID *p_Data);

/**
 * @brief With this function, the loose element `p_Data` is inserted at the
 *        head of the list `LstId`.
 *
 * Loose elements are only created with the functions lst_p_NewNode(),
 * lst_p_NewDynNode() or lst_p_Unlink*().
 *
 * @note The function lst_p_InsHead() is equivalent to lst_InsHead() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 * @param[in]  p_Data  Pointer to a loose element
 *
 * @retval     0   List destroyed
 * @retval     !0  Pointer to a loose element
 *
 * @see Example code of lst_InsHead()
 */
VOID *lst_p_InsHead(LST_ID *LstId, VOID *p_Data);

/**
 * @brief With this function, the loose element `p_Data` is inserted at the end
 *        of the list `LstId`.
 *
 * Loose elements are only created with the functions lst_p_NewNode(),
 * lst_p_NewDynNode() or lst_p_Unlink*().
 *
 * @note The function lst_p_InsTail() is equivalent to lst_InsTail() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 * @param[in]  p_Data  Pointer to a loose element
 *
 * @retval     0   List destroyed
 * @retval     !0  Pointer to a loose element
 *
 * @see Example code of lst_InsTail()
 */
VOID *lst_p_InsTail(LST_ID *LstId, VOID *p_Data);

/**
 * @brief This function inserts the loose element `p_Data` in front of the element
 *        `p_RefData` of the list `LstId`.
 *
 * If zero is transmitted for `p_RefData` then the element is inserted at the end
 * of the list, which may be useful for the construction of sorted lists.
 *
 * Loose elements are only created with the functions lst_p_NewNode(),
 * lst_p_NewDynNode() or lst_p_Unlink*().
 *
 * @note The function lst_p_InsPre() is equivalent to lst_InsPre() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId           ID of the list returned by the function lst_p_New()
 * @param[in]  p_RefData       Pointer to existing element. The new element
 *                             will be inserted in front of that element.
 * @param[in]  p_Data          Pointer to a loose element
 *
 * @retval     0   List destroyed
 * @retval     !0  Pointer to a loose element
 *
 * @see Example code of lst_InsPre()
 */
VOID *lst_p_InsPre(LST_ID *LstId, VOID *p_RefData, VOID *p_Data);

/**
 * @brief This function inserts the loose element `p_Data` after the element
 *        `p_RefData` of the list `LstId`.
 *
 * If zero is transmitted for `p_RefData` then the element is inserted at the
 * beginning of the list, which may be useful for the construction of sorted
 * lists.
 *
 * Loose elements are only created with the functions lst_p_NewNode(),
 * lst_p_NewDynNode() or lst_p_Unlink*().
 *
 * @note The function lst_p_InsPost() is equivalent to lst_InsPost() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId           ID of the list returned by the function lst_p_New()
 * @param[in]  p_RefData       Pointer to existing element. The new element
 *                             will be inserted after that element.
 * @param[in]  p_Data          Pointer to a loose element
 *
 * @retval     0   List destroyed
 * @retval     !0  Pointer to a loose element
 *
 * @see Example code of lst_InsPost()
 */
VOID *lst_p_InsPost(LST_ID *LstId, VOID *p_RefData, VOID *p_Data);

/**
 * @brief This function is used to insert a new element with a specific size
 *        in the header of the list.
 *
 * This function is necessary for lists with elements of different length.
 * The element size transferred to the function lst_p_New() will be ignored.
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddDynHead() is equivalent to lst_AddDynHead() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId       ID of the list returned by the function lst_p_New()
 * @param[in]  ElemSize    Size of the new element
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * @see Example code of lst_AddDynHead()
 */
VOID *lst_p_AddDynHead(LST_ID *LstId, UINT32 ElemSize);

/**
 * @brief This function is used to insert a new element with a specific size
 *        at the end of the list `LstId`.
 *
 * The element size stated during the creation of the list via lst_New(),
 * will be ignored with this function. This function is necessary for lists
 * with elements of different length.
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddDynTail() is equivalent to lst_AddDynTail() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId       ID of the list returned by the function lst_p_New()
 * @param[in]  ElemSize    Size of the new element
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * @see Example code of lst_AddDynTail()
 */
VOID *lst_p_AddDynTail(LST_ID *LstId, UINT32 ElemSize);

/**
 * @brief This function inserts a new element with a specific size in front of
 *        the element `p_Data` of the list `LstId`.
 *
 * If zero is transmitted for `p_Data`, then the element is inserted at the
 * end of the list, which may be useful for the construction of sorted lists.
 *
 * This function is necessary for lists with elements of different length.
 * The element size transferred to the function lst_p_New() will be ignored.
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddDynPre() is equivalent to lst_AddDynPre() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId       ID of the list returned by the function lst_p_New()
 * @param[in]  p_Data      Pointer to existing element. The new element
 *                         will be inserted in front of that element.
 * @param[in]  ElemSize    Size of the new element
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * @see Example code of lst_AddDynPre()
 */
VOID *lst_p_AddDynPre(LST_ID *LstId, VOID *p_Data, UINT32 ElemSize);

/**
 * @brief This function inserts a new element with a specific size after the
 *        element `p_Data` of the list `LstId`.
 *
 * If zero is transmitted for `p_Data`, then the element is inserted at the
 * beginning of the list, which may be useful for the construction of sorted
 * lists.
 *
 * This function is necessary for lists with elements of different length.
 * The element size transferred to the function lst_p_New() will be ignored.
 *
 * @note The allocated memory is not zeroed by the function.
 *
 * @note The function lst_p_AddDynPost() is equivalent to lst_AddDynPost() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId       ID of the list returned by the function lst_p_New()
 * @param[in]  p_Data      Pointer to existing element. The new element
 *                         will be inserted after that element.
 * @param[in]  ElemSize    Size of the new element
 *
 * @retval     0   Insufficient free memory or list is destroyed
 * @retval     !0  Pointer on a new element
 *
 * @see Example code of lst_AddDynPost()
 */
VOID *lst_p_AddDynPost(LST_ID *LstId, VOID *p_Data, UINT32 ElemSize);

/**
 * @brief With this function, the first element of the list `LstId` can be
 *        removed.
 *
 * The allocated memory will be released and the linking of the list will be
 * updated.
 * If the list is empty, calling this function has no effect.
 *
 * @note The function lst_p_RemHead() is equivalent to lst_RemHead() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 *
 * @see Example code of lst_RemHead()
 */
VOID lst_p_RemHead(LST_ID *LstId);

/**
 * @brief With this function, the last element of the list `LstId` can be removed.
 *
 * The allocated memory will be released and the linking of the list will be
 * updated.
 * If the list is empty, calling this function has no effect.
 *
 * @note The function lst_p_RemTail() is equivalent to lst_RemTail() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 *
 * @see Example code of lst_RemTail()
 */
VOID lst_p_RemTail(LST_ID *LstId);

/**
 * @brief With this function, the element `p_Data` can be removed.
 *
 * The allocated memory will be released and the linking of the list will be
 * updated.
 *
 * @note The function lst_p_RemNode() is equivalent to lst_RemNode() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @note After accessing this function, the parameter `p_Data` points to a
 *       free memory range and therefore must not be used further
 *       (alternative is lst_UnlinkNode()).
 *
 * @param[in]  iPart    Partition
 * @param[in]  p_Data   Pointer to element to delete
 *
 * @see Example code of lst_RemNode()
 */
VOID lst_p_RemNode(UINT32 iPart, VOID *p_Data);

/**
 * @brief With this function, the first element of the list `LstId` is removed and
 *        converted into a loose element.
 *
 * This element can be inserted into another list.
 *
 * @note The function lst_p_UnlinkHead() is equivalent to lst_UnlinkHead() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 *
 * @retval     0   list is empty
 * @retval     !0  Pointer on a remote element
 *
 * @see Example code of lst_UnlinkHead()
 */
VOID *lst_p_UnlinkHead(LST_ID *LstId);

/**
 * @brief With this function, the last element of the list `LstId` is removed and
 *        converted into a loose element.
 *
 * This element can be inserted into another list.
 *
 * @note The function lst_p_UnlinkTail() is equivalent to lst_UnlinkTail() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 *
 * @retval     0   list is empty
 * @retval     !0  Pointer on a remote element
 *
 * @see Example code of lst_UnlinkTail()
 */
VOID *lst_p_UnlinkTail(LST_ID *LstId);

/**
 * @brief With this function, the element `p_Data` is removed from its list and
 *        converted into a loose element.
 *
 * This element can be inserted into another list.
 *
 * @note The function lst_p_UnlinkNode() is equivalent to lst_UnlinkNode() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 *  @param[in]  p_Data  Pointer to desired element
 *
 * @retval     0   list is empty
 * @retval     !0  Pointer on a remote element
 *
 * @see Example code of lst_UnlinkNode()
 */
VOID *lst_p_UnlinkNode(VOID *p_Data);

/**
 * @brief Makes a query whether the node is a loose one or not.
 *
 * @note The function lst_p_IsNodeFree() is equivalent to lst_IsNodeFree() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  p_Data  Pointer to the requesting element
 *
 * @retval     0  Node is not loose
 * @retval     1  Node is a loose one
 */
BOOL32 lst_p_IsNodeFree(VOID *p_Data);

#ifdef LST_P_MAIN
/**
 * @brief With this function, one can access an independent function `UserFunc`,
 *        which will be applied to each element of the list `LstId`.
 *
 * Besides the function-pointer a 32 bit long argument `arg` can be transmitted,
 * which will be passed to the independent function.
 * If the list is empty, calling this function has no effect.
 *
 * @note The function lst_p_WalkList() is equivalent to lst_WalkList() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId           ID of the list returned by the function lst_p_New()
 * @param[in]  UserFunc        Pointer to function which will be applied to
 *                             each element of the list `LstId`.
 * @param[in]  arg             Optional argument (of 4 byte) for function `UserFunc`.
 *
 * @see Example code of lst_WalkList()
 */
VOID lst_p_WalkList(LST_ID *LstId, VOID(*UserFunc)(VOID *p_Data, UINT32 arg), UINT32 arg);

/**
 * @brief With this function, one can access an independent function `UserFunc`,
 *        which will be applied to each element of the list `LstId`.
 *
 * The run-through of the list `LstId` can be stopped by the return value of the function
 * `UserFunc`. To stop the run-through of the list `LstId`, the return value of
 * the function `UserFunc` has to be unequal zero.
 * Besides the function-pointer a 32 bit long argument `arg` can be transmitted,
 * which will be passed to the independent function.
 * If the list is empty, calling this function has no effect.
 *
 * @note The function lst_p_SearchList() is equivalent to lst_SearchList() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId           ID of the list returned by the function lst_p_New()
 * @param[in]  UserFunc        Pointer to function which will be applied to
 *                             each element of the list `LstId`.
 * @param[in]  arg             Optional argument (of 4 byte) for function `UserFunc`.
 *
 * @retval     0   List destroyed or run-through of list has not been stopped.
 * @retval     !0  Pointer to element; run-through of list has been stopped at
 *                 that element.
 *
 * @see Example code of lst_SearchList()
 */
VOID *lst_p_SearchList(LST_ID *LstId, SINT32(*UserFunc)(VOID *p_Data, UINT32 arg), UINT32 arg);
#else
VOID lst_p_WalkList(LST_ID *LstId, VOID(*UserFunc)(), ...);
VOID *lst_p_SearchList(LST_ID *LstId, SINT32(*UserFunc)(), ...);
#endif

/**
 * @brief With this function, all elements of the list `LstId` can be deleted.
 *
 * The ID of list (`LstId`) stays valid.
 * If the list is empty, calling this function has no effect.
 *
 * @note The function lst_p_RemoveAll() is equivalent to lst_RemoveAll() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @note If the elements of the list `LstId` contain pointers to allocated memory,
 *       these pointers have to be freed first, to avoid memory leaks.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 *
 * @see Example code of lst_RemoveAll()
 */
VOID lst_p_RemoveAll(LST_ID *LstId);

/**
 * @brief With this function, one can get the next element after the element
 *        `p_Data`.
 *
 * @note The function lst_p_GetNext() is equivalent to lst_GetNext() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  p_Data  Pointer to reference element.
 *
 * @retval     0   no next element
 * @retval     !0  pointer to next element
 *
 * @see Example code of lst_GetNext()
 */
VOID *lst_p_GetNext(VOID *p_Data);

/**
 * @brief With this function, one can get the previous element of the element
 *        `p_Data`.
 *
 * @note The function lst_p_GetPrev() is equivalent to lst_GetPrev() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  p_Data  Pointer to reference element.
 *
 * @retval     0   no previous element
 * @retval     !0  pointer to previous element
 *
 * @see Example code of lst_GetPrev()
 */
VOID *lst_p_GetPrev(VOID *p_Data);

/**
 * @brief With this function, one can get the first element of the list `LstId`.
 *
 * @note The function lst_p_GetHead() is equivalent to lst_GetHead() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 *
 * @retval     0   List is empty or destroyed
 * @retval     !0  pointer to first element
 *
 * @see Example code of lst_GetHead()
 */
VOID *lst_p_GetHead(LST_ID *LstId);

/**
 * @brief With this function, one can get the last element of the list `LstId`.
 *
 * @note The function lst_p_GetTail() is equivalent to lst_GetTail() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 *
 * @retval     0   List is empty or destroyed
 * @retval     !0  pointer to last element
 *
 * @see Example code of lst_GetTail()
 */
VOID *lst_p_GetTail(LST_ID *LstId);

/**
 * @brief With this function, one can get an element of the list `LstId` by its
 *        index `NodeIdx`.
 *
 * The first index of the list `LstId` has the index 0.
 *
 * @note The function lst_p_GetNodeByIdx() is equivalent to lst_GetNodeByIdx()
 *       when the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 * @param[in]  NodeIdx Index of desired element (0-n)
 *
 * @retval     0   No element with index `NodeIdx` or list destroyed
 * @retval     !0  Pointer to element with index `NodeIdx`
 *
 * @see Example code of lst_GetNodeByIdx()
 */
VOID *lst_p_GetNodeByIdx(LST_ID *LstId, UINT32 NodeIdx);

/**
 * @brief With this function, the existence of the element `p_Data` in the list
 *        `LstId` can be tested, and if it does at which position it is located
 *        in the list.
 *
 * @note The function lst_p_FindNode() is equivalent to lst_FindNode() when the
 *       memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions may not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 * @param[in]  p_Data  Pointer to element to find
 *
 * @retval     -1   Loose element does not exist or list destroyed
 * @retval     0-n  Index of the determined element
 *
 * @see Example code of lst_FindNode()
 */
SINT32 lst_p_FindNode(LST_ID *LstId, VOID *p_Data);

/**
 * @brief With this function, the number of elements in the list `LstId` can be
 *        determined.
 *
 * @note The function lst_p_CountNodes() is equivalent to lst_CountNodes() when
 *       the memory from another partition is to be used.
 *       lst_p_*() and lst_*() functions must not be mixed in an application.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_p_New()
 *
 * @returns    Number of elements in list `LstId`
 *
 * @see Example code of lst_CountNodes()
 */
UINT32 lst_p_CountNodes(LST_ID *LstId);

/** @} */



/**
 * @addtogroup LST-DEF
 * @{
 */

/**
 * @brief Node for one block element
 */
typedef struct lst_b_Node
{
    struct lst_b_Node *Next;            /**< Pointer to next block element */
    struct lst_b_Node *Prev;            /**< Pointer to previous block element */
    UINT32  NbOfElem;                   /**< Number of elements in this block */
    UINT8   Data[1];                    /**< Data field of element */
} LST_B_NODE;

/**
 * @brief Root for blocked list
 */
typedef struct
{
    LST_B_NODE *Head;                   /**< Pointer to first block element */
    LST_B_NODE *Earth;                  /**< Optimization pointer (see Docu) */
    LST_B_NODE *Tail;                   /**< Pointer to last list element */
    UINT32  NbOfElem;                   /**< Number of elements in each block */
    UINT32  ElemSize;                   /**< Size of one element in bytes */
} LST_B_ID;

/** @} */

/**
 * @ingroup LST-API
 * @defgroup LST-3 lst_b_
 * @details Functions for administration of blocked and double-linked lists.
 *          Blocked means, that not each element of the list is a node.
 *          Several elements of a list are merged to a block and this
 *          block is a node.
 *          <br>These kind of lists does not enable re-sort of single elements.
 * @{
 */

/**
 * @brief With this function, a new list is created.
 *
 * @param[in]  NbOfElem        Number of elements per list node.
 * @param[in]  ElemSize        Size of one element
 *
 * @retval     0   insufficient memory
 * @retval     !0  identifier for new list
 */
LST_B_ID *lst_b_New(UINT32 NbOfElem, UINT32 ElemSize);

/**
 * @brief With this function, an existing list with all its elements is deleted.
 *
 * After calling this function, the list-ID is invalid and must not be used
 * any more.
 *
 * @param[in]  LstId   ID of the list to be deleted
 */
VOID lst_b_Del(LST_B_ID *LstId);

/**
 * @brief With this function, a new element is inserted at the end of the
 *        list `LstId`.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_b_New()
 *
 * @retval     0    insufficient memory or list is destroyed
 * @retval     !0   Pointer on a new element
 */
VOID *lst_b_AddTail(LST_B_ID *LstId);

#ifdef LST_MAIN
/**
 * @brief With this function, one can access an independent function `UserFunc`,
 *        which will be applied to each element of the list `LstId`.
 *
 * Besides the function-pointer a 32 bit long argument `arg` can be transmitted,
 * which will be passed to the independent function.
 * If the list is empty, calling this function has no effect.
 *
 * @param[in]  LstId           ID of the list returned by the function lst_b_New()
 * @param[in]  UserFunc        Pointer to function which will be applied to
 *                             each element of the list `LstId`.
 * @param[in]  arg             Optional argument (of 4 byte) for function `UserFunc`.
 */
VOID lst_b_WalkList(LST_B_ID *LstId, VOID(*UserFunc)(VOID *p_Data, UINT32 arg), UINT32 arg);

/**
 * @brief With this function, one can access an independent function `UserFunc`,
 *        which will be applied to each element of the list `LstId`.
 *
 * The run-through of the list `LstId` can be stopped by the return value of the function
 * `UserFunc`. To stop the run-through of the list `LstId`, the return value of
 * the function `UserFunc` has to be unequal zero.
 * Besides the function-pointer a 32 bit long argument `arg` can be transmitted,
 * which will be passed to the independent function.
 * If the list is empty, calling this function has no effect.
 *
 * @param[in]  LstId           ID of the list returned by the function lst_b_New()
 * @param[in]  UserFunc        Pointer to function which will be applied to
 *                             each element of the list `LstId`.
 * @param[in]  arg             Optional argument (of 4 byte) for function `UserFunc`.
 *
 * @retval     0   List destroyed or run-through of list has not been stopped.
 * @retval     !0  Pointer to element; run-through of list has been stopped at
 *                 that element.
 */
VOID *lst_b_SearchList(LST_B_ID *LstId,
                         SINT32(*UserFunc)(VOID *p_Data, UINT32 arg), UINT32 arg);
#else
VOID lst_b_WalkList(LST_B_ID *LstId, VOID(*UserFunc)(), ...);
VOID *lst_b_SearchList(LST_B_ID *LstId, SINT32(*UserFunc)(), ...);
#endif

/**
 * @brief With this function, one can get an element of the list `LstId` by its
 *        index `NodeIdx`.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_b_New()
 * @param[in]  NodeIdx Index of desired element (0-n)
 *
 * @retval     0       No element with index `NodeIdx` or list destroyed
 * @retval     !0      Pointer to element with index `NodeIdx`
 */
VOID *lst_b_GetNodeByIdx(LST_B_ID *LstId, UINT32 NodeIdx);

/**
 * @brief With this function, all elements of the list `LstId` can be deleted.
 *
 * The ID of list (`LstId`) stays valid.
 * If the list is empty, calling this function has no effect.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_b_New()
 */
VOID lst_b_RemoveAll(LST_B_ID *LstId);

/** @} */

/**
 * @addtogroup LST-DEF
 * @{
 */

/**
 * @brief Node for one block element
 */
typedef struct lst_bl_Node
{
    struct lst_bl_Node *Next;           /**< Pointer to next block element */
    struct lst_bl_Node *Prev;           /**< Pointer to previous block element */
    UINT32  NbOfElem;                   /**< Number of elements in this block */
    UINT32  Data[1];                    /**< Data field of element */
} LST_BL_NODE;

/**
 * @brief Root for blocked list
 */
typedef struct
{
    LST_BL_NODE *Head;                  /**< Pointer to first block element */
    LST_BL_NODE *Earth;                 /**< Optimization pointer (see Docu) */
    LST_BL_NODE *Tail;                  /**< Pointer to last list element */
    UINT32  NbOfElem;                   /**< Number of LONG-elements in block */
} LST_BL_ID;
/** @} */

/**
 * @ingroup LST-API
 * @defgroup LST-4 lst_bl_
 * @details Functions for administration of blocked and double-linked lists
 *          of elements of size of 4 byte.
 *          Blocked means, that not each element of the list is a node.
 *          Several elements of a list are merged to a block and this
 *          block is a node.
 *          <br>These kind of lists does not enable re-sort of single elements.
 * @{
 */

/**
 * @brief With this function, a new list is created.
 *
 * @param[in]  NbOfElem    Number of 4byte-elements per list node.
 *
 * @retval     0       insufficient memory
 * @retval     !0      identifier for new list
 */
LST_BL_ID *lst_bl_New(UINT32 NbOfElem);

/**
 * @brief With this function, an existing list with all its elements is deleted.
 *
 * After calling this function, the list-ID is invalid and must not be used
 * any more.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_bl_New()
 */
VOID lst_bl_Del(LST_BL_ID *LstId);

/**
 * @brief With this function, a new 4byte-element is inserted at the end of the
 *        list `LstId`.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_bl_New()
 * @param[in]  Elem    new element
 *
 * @retval     0       Element successfully added to list `LstId`
 * @retval     !0      Insufficient free memory or list is destroyed
 */
SINT32 lst_bl_AddTail(LST_BL_ID *LstId, UINT32 Elem);

#ifdef LST_MAIN

/**
 * @brief With this function, one can access an independent function `UserFunc`,
 *        which will be applied to each element of the list `LstId`.
 *
 * The run-through of the list `LstId` can be stopped by the return value of the function
 * `UserFunc`. To stop the run-through of the list `LstId`, the return value of
 * the function `UserFunc` has to be unequal zero.
 * Besides the function-pointer a 32 bit long argument `arg` can be transmitted,
 * which will be passed to the independent function.
 * If the list is empty, calling this function has no effect.
 *
 * @param[in]  LstId           ID of the list returned by the function lst_bl_New()
 * @param[in]  UserFunc        Pointer to function which will be applied to
 *                             each element of the list `LstId`.
 * @param[in]  arg             Optional argument (of 4 byte) for function `UserFunc`.
 *
 * @retval     0       List destroyed or run-through of list has not been stopped.
 * @retval     !0      Pointer to element; run-through of list has been stopped at
 *                     that element.
 */
VOID *lst_bl_SearchList(LST_BL_ID *LstId,
                        SINT32(*UserFunc)(VOID *p_Data, UINT32 arg), UINT32 arg);
#else
VOID *lst_bl_SearchList(LST_BL_ID *LstId, SINT32(*UserFunc)(), ...);
#endif

/**
 * @brief This function searches an element in the list `LstId`.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_bl_New()
 * @param[in]  Element Element to search for.
 *
 * @retval     0       Element not found
 * @retval     !0      Pointer to element.
 */
VOID *lst_bl_QuickSearchList(LST_BL_ID *LstId, UINT32 Element);

/**
 * @brief With this function, all elements of the list `LstId` can be deleted.
 *
 * The ID of list (`LstId`) stays valid.
 * If the list is empty, calling this function has no effect.
 *
 * @param[in]  LstId   ID of the list returned by the function lst_bl_New()
 */
VOID lst_bl_RemoveAll(LST_BL_ID *LstId);

/** @} */


#ifdef __cplusplus
}
#endif

#endif
