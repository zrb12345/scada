/**
********************************************************************************
* @file     sys_excDump_e.h
* @author   WIKU
*
* @brief    Public header of the Exception Dump Provider
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2013
*******************************************************************************/

#ifndef SYS_EXCDUMP_E__H                  /* Avoid problems with multiple includes */
#define SYS_EXCDUMP_E__H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @addtogroup SYS-EXC-DEF
* @{
*/

/*--- Structures ---*/

/** System exception data structure used to transfer detailed exception information into
 *  exception hook functions (see sys_ExcHookAdd()).
 */
typedef struct
{
    /* Registers */
    UINT32 RegEAX;                      /**< Intel specific CPU register EAX */
    UINT32 RegEBX;                      /**< Intel specific CPU register EBX */
    UINT32 RegECX;                      /**< Intel specific CPU register ECX */
    UINT32 RegEDX;                      /**< Intel specific CPU register EDX */
    UINT32 RegESI;                      /**< Intel specific CPU register ESI */
    UINT32 RegEDI;                      /**< Intel specific CPU register EDI */
    UINT32 RegEBP;                      /**< Intel specific CPU register EBP */
    UINT32 RegESP;                      /**< Intel specific CPU register ESP */
    UINT32 RegEIP;                      /**< Intel specific CPU register EIP */
    UINT32 RegCS;                       /**< Intel specific CPU register CS */
    UINT32 RegCR0;                      /**< Intel specific CPU register CR0 */
    UINT32 ExcId;                       /**< Exception Id */
    UINT32 ErrorCode;                   /**< Error code */
    UINT32 ErrorFlags;                  /**< Error flags */

    /* Additional exception data */
    SINT32 TaskId;                      /**< Task ID of the last running task */
    CHAR TaskName[M_SYMBLEN_A];         /**< Name of the last running task */
    UINT32 BadAddress;                  /**< Last accessed address */
    UINT32 PageId;                      /**< Active page ID of the last running task */
    UINT32 PrevSymbolAddress;           /**< Address of the last symbol before the instruction pointer (\p RegEIP) */
    CHAR PrevSymbolName[M_SYMBLEN_A];   /**< Name of the last known (global) symbol before the instruction pointer (\p RegEIP) */
} SYS_EXCDATA;

/** @} End of SYS-FWALL-MAC */

/*--- Function Prototypes ---*/

/**
* @addtogroup SYS-EXC-API
* @{
*/

/**
********************************************************************************
* @brief Register a hook function that will be called in case of an exception.
*
* @param[in]  HookFunc      Pointer to function that shall be called
* @param[in]  pUserData     Pointer to user defined data which will be handed over
*                           unchanged to the \p HookFunc in case of an exception.
* @param[out] pHookId       Pointer for the new HookId
*
* @retval     0             OK, hook added
* @retval     -1            Error, could not add the hook
*
* #### Examples ####
* @snippet doc_sys_ExcDump.c example
*******************************************************************************/
SINT32 sys_ExcHookAdd(VOID (*HookFunc)(const SYS_EXCDATA *pExcData, VOID *pUserData),
                      VOID *pUserData, UINT32 *pHookId);

/**
********************************************************************************
* @brief Deletes an existing exception hook.
*
* @param[in]  HookId        ID of the hook
*
* #### Examples ####
* @snippet doc_sys_ExcDump.c example
*******************************************************************************/
void sys_ExcHookDelete(UINT32 HookId);

/** @} */

#ifdef __cplusplus
}
#endif

#endif  /* SYS_EXCDUMP_E__H */
