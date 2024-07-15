/**
********************************************************************************
* @file     svi_client.h
* @author   bertel
*
* @brief This file contains all definitions and declarations exported by the
*        SVI Client Handler Library for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2015
*******************************************************************************/

#ifndef SVICLIENT__H
#define SVICLIENT__H

#ifdef __cplusplus
extern  "C"
{
#endif

#include <time.h>
#include <svi_e.h>

/**
 * @addtogroup SVI-CLIENT
 * @{
 *     @addtogroup SVI-CLIENT-DEF
 *     @{
 */

/**
 * @anchor SVI_CLM_
 * @name Definitions for Client's behavior at initialization
 * @see svi_ClientCreate()
 * @{
 */
#define SVI_CLM_WR_DATA_CHG         0x10    /**< SVI client signals that that a new value was read at last read operation (SVI_CLIENT_VAR.Flags field) */
#define SVI_CLM_RD_DATA_CHG         0x20    /**< SVI client signals that that a new value was written at last write operation (SVI_CLIENT_VAR.Flags field) */
#define SVI_CLM_DATA_CHANGE         0x30    /**< SVI client signals that that a new value was read or written at last read/write operation (SVI_CLIENT_VAR.Flags field) */
#define SVI_CLM_TIMESTAMP           0x40    /**< SVI client delivers time-stamp information for value changes */
#define SVI_CLM_RETRY               0x80    /**< Do a retry if the SVI read function returns #SVI_E_VARINUSE */
#define SVI_CLM_EXACT_LENGTH_CHK    0x100   /**< Do an exact length check with length set in SVI_CLIENT_VAR.Len field, without the flag the given length is checked for greater than or equal to */
/**
 * @brief All valid mode bits, used internal for parameter check
 */
#define SVI_CLM_VALID_MODES     (SVI_CLM_RETRY | SVI_CLM_TIMESTAMP | SVI_CLM_DATA_CHANGE | SVI_CLM_EXACT_LENGTH_CHK)
/** @} */

/**
 * @name Definitions for Client's behavior at read/write operations
 * @see svi_ClientRead()
 * @see svi_ClientWrite()
 * @{
 */
#define SVI_CLM_WR_UPDATE       0x01    /**< Forces to write all variables (no check for value changes) */
#define SVI_CLM_RD_SVFLAG       0x02    /**< Controls the service variable read mode, read from shadow or field bus */
/** @} */

/**
 * @anchor SVI_CLF_
 * @name Client's control flags
 * Used for adding variables and read/write operations (SVI_CLIENT_VAR.Flags field)
 * @see SVI_CLIENT_VAR
 * @see svi_ClientAddVar()
 * @see svi_ClientWrite()
 * @see svi_ClientRead()
 * @{
 */
#define SVI_CLF_WR_UPDATE       0x01    /**< Forces to write a variable (no check for value changes) */
#define SVI_CLF_RD_SVFLAG       0x02    /**< Controls the service variable read mode, read from shadow or field bus */
#define SVI_CLF_WR_DISABLED     0x04    /**< Disables write operation at function call svi_ClientWrite() */
#define SVI_CLF_RD_DISABLED     0x08    /**< Disables read operation at function call svi_ClientRead() */
#define SVI_CLF_DATA_CHANGE     0x10    /**< [out] Signals that a new value was read at the last read operation */
#define SVI_CLF_VAL_ALLOC       0x80    /**< [in] Signals that client allocates the data memory in pVar->pValue */
#define SVI_CLF_ADD_CHECK       0x9f    /**< Valid flags for adding, checked when calling the function svi_ClientAddVar() */

/** @} */

/**
 * @anchor SVI_CBF_
 * @name Definitions for Client's state change callback function behavior
 * @see svi_ClientAssignCbf()
 * @see svi_ClientRead()
 * @see svi_ClientWrite()
 * @{
 */
#define SVI_CBF_ADDR_ERROR      0x01    /**< The call back function is called only on SVI address errors changes (missing variables #SVI_E_ADDR, #SVI_E_OLDADDR) */
#define SVI_CBF_GENERAL_ERROR   0x02    /**< The call back function is called at any error state change except #SVI_E_VARINUSE */
#define SVI_CBF_VARINUSE_ERROR  0x04    /**< The call back function is called also at #SVI_E_VARINUSE errors */
#define SVI_CBF_ALL_ERRORS      (SVI_CBF_ADDR_ERROR | SVI_CBF_GENERAL_ERROR | SVI_CBF_VARINUSE_ERROR) /**< All possible error state changes */
#define SVI_CBF_WR_DATA_CHG     0x10    /**< The call back function is called if a new value was written */
#define SVI_CBF_RD_DATA_CHG     0x20    /**< The call back function is called if a new value was read */
#define SVI_CBF_DATA_CHANGE     0x30    /**< The call back function is called if a new value was read or written */
#define SVI_CBF_MODES_CHECK     0x37    /**< All valid call back function control modes (checked at svi_ClientAssignCbf() call) */

/** @} */


typedef struct SVI_CLIENT *SVI_CLIENT_HANDLE;   /**< SVI Client Handle, returned by svi_ClientCreate() and used at all further SVI Client function calls */
typedef UINT32 SVI_CLIENT_VAR_HANDLE;           /**< SVI Client Variable Handle, returned in SVI_CLIENT_VAR.Handle by svi_ClientAddVar(), must be used at all variable specific functions */

/**
 * @brief SVI variable access data struct, used by the client application
 * @see svi_ClientAddVar()
 * @see svi_ClientGetErrorVar()
 */
typedef struct
{
    SVI_CLIENT_VAR_HANDLE Handle;   /**< [out]    Handle for this variable, used with variable specific functions */
    VOID  *pValue;                  /**< [in,out] Pointer to the data used at read/write function calls */
    SINT32 RetCode;                 /**< [out]    Return-Code of the executed read/write function call */
    UINT16 Len;                     /**< [in,out] Read/write data length in bytes */
    UINT8  Format;                  /**< [in,out] SVI specific type format @ref SVI_F_ if set client will check type format */
    UINT8  Flags;                   /**< [in,out] Adding and read/write operation control flags @ref SVI_CLF_ */
    VOID  *pReserved;               /**< Extensions point, reserved for future extensions */
} SVI_CLIENT_VAR;                   /**< Read write access data of a client variable */

/** @brief Definition client variable state change callback function.
 *
 *  This function is called within the svi_ClientRead() and/or svi_ClientWrite()
 *  function for each variable, at which one of the assigned state change has
 *  occurred.
 *
 * @param[in]  ClientHandle SVI client handle, returned by svi_ClientCreate()
 * @param[in]  pVar         Concerning SVI variable, at which the matching state change has occurred
 * @param[in]  UserParam    Forwarded user parameter, passed at svi_ClientAssignCbf()
 * @see svi_ClientAssignCbf()
 */
typedef void (*SVI_CLIENT_CBF)(SVI_CLIENT_HANDLE ClientHandle, SVI_CLIENT_VAR *pVar, UINT32 UserParam);

/** @} */

/**
 * @brief Creates an SVI client handle. This handle is used as parameter for all
 *        further SVI client function calls.
 *
 * @param[in]  ClientMode    Controls the client behavior (@ref SVI_CLM_)
 * @param[in]  SessionId     Client session-id passed to svi_GetXxx() and
 *                           svi_SetXxx() functions
 *
 * @retval     NULL          Invalid ClientMode, Out of resources
 * @retval     other         SVI client handle successfully created
 *
 */
SVI_CLIENT_HANDLE svi_ClientCreate(UINT32 ClientMode, UINT32 SessionId);

/**
* @brief Removes the SVI client handle. All allocated resources are freed.
*        A further SVI client function call with this handle results an error.
*
* @param[in]  ClientHandle  SVI client handle to remove
*
* @retval #SVI_E_OK      SVI client successfully removed
* @retval #SVI_E_PARM    The given ClientHandle is not valid
*
*/
SINT32 svi_ClientDelete(SVI_CLIENT_HANDLE ClientHandle);

/**
* @brief Checks the SVI addresses of the client objects. If an invalid address
*        gets valid, the client read/write access list will be updated and the
*        client object state is set to valid.
*
* @param[in]  ClientHandle  SVI client handle or NULL for all
*
* @retval #SVI_E_OK      No active or invalid clients found
* @retval #SVI_E_PARM    The given `ClientHandle` is not valid
* @retval #SVI_E_ADDR    At least on client variable has no address
*
*/
SINT32 svi_ClientConnect(SVI_CLIENT_HANDLE ClientHandle);

/**
* @brief Assigns a new Session Id to a client. This Id is used for all further
*        calls of the functions svi_ClientRead() and svi_ClientWrite().
*
* @param[in]  ClientHandle  SVI client handle
* @param[in]  SessionId     New user's session-id
*
* @retval #SVI_E_OK      `SessionId` successfully assigned
* @retval #SVI_E_PARM    The given `ClientHandle` is not valid
* @retval #RES_E_BADSESS `SessionId` not valid or user is not logged in
*
*/
SINT32 svi_ClientAssignSessionId(SVI_CLIENT_HANDLE ClientHandle, UINT32 SessionId);

/**
 * @brief Function for applying a callback function to the SVI client. Dependent
 *        on the given call mode parameter, the applied function is called, if
 *        a matching state change at one of the added SVI variables occurs. The
 *        state change will be detected with every call of the svi_ClientRead()
 *        and/or svi_ClientWrite() function, and is executed at the same
 *        context (memory partition and priority) as the calling client
 *        application task.
 *
 * @param[in]  ClientHandle     SVI client handle
 * @param[in]  CbfCallMode      Controls the CBF calling behavior (@ref SVI_CBF_)
 * @param[in]  StateChangeCbf   State change callback function pointer or NULL
 *                              for deactivating the callback mechanism
 * @param[in]  UserParam        User parameter passed at each callback function
 *                              call
 *
 * @retval #SVI_E_OK     Callback function successfully assigned to the SVI client
 * @retval #SVI_E_PARM   Invalid `ClientHandle`, `CbfCallMode` or the `StateChangeCbf`
 *                       pointer parameter passed
 */
SINT32 svi_ClientAssignCbf(SVI_CLIENT_HANDLE ClientHandle, UINT32 CbfCallMode,
                           SVI_CLIENT_CBF StateChangeCbf, UINT32 UserParam);

/**
* @brief Adds a SVI variable to the SVI client.
*
* If the variable is valid (valid SVI address was found), `pVar` returns the
* variable informations data:
*  - pVar->RetCode = #SVI_E_OK;
*  - pVar->Len is set to the data length in bytes
*  - pVar->Format is set to the SVI format type e.g. #SVI_F_UINT16|#SVI_F_INOUT
*  - pVar->pValue is set to data pointer if the pVar->Flag = #SVI_CLF_VAL_ALLOC
*    was set at call time
*
* Otherwise:
*  - pVar->RetCode = #SVI_E_ADDR if the server or variable was not found
*  - pVar->RetCode = #SVI_E_OLDADDR if the server or variable address got
*          invalid
*  - pVar->RetCode = #SVI_E_ACCDENIED access denied with the actual client
*          session id
*
* In all of these cases the background monitoring for this variable is activated
* to check until the address and/or rights get valid.
*
* @param[in]     ClientHandle  SVI client handle
* @param[in]     pName         Symbolic address of variable
* @param[in,out] pVar          Pointer to data for read/write access processing
*
* @retval #SVI_E_OK          Variable successfully added to the SVI client
* @retval #SVI_E_PARM        Invalid ClientHandle or one of the pointers pName, pVar, pVar->pValue
*                            or the given pVar->Flags is not valid
* @retval #SVI_E_BADNAME     Invalid symbolic address (e.g module name not found, name to long)
* @retval #SVI_E_DLEN        The given data length (passed pVar->Len) is too small for this variable
* @retval #SVI_E_FAILED      Out of resources
*/
SINT32 svi_ClientAddVar(SVI_CLIENT_HANDLE ClientHandle, CHAR *pName, SVI_CLIENT_VAR *pVar);

/**
* @brief Deletes a SVI variable in the SVI client. The allocated resources for
*        this variable are freed. A further SVI client function call with this
*        handle results an error.
*
* @param[in]  ClientHandle  SVI client handle
* @param[in]  Handle        Handle of the SVI-Variable to delete

* @retval #SVI_E_OK      Variable successfully deleted
* @retval #SVI_E_PARM    The given `ClientHandle` or `Handle` parameter is not valid
* @retval #SVI_E_FAILED  Variable already deleted
*/
SINT32 svi_ClientDeleteVar(SVI_CLIENT_HANDLE ClientHandle, SVI_CLIENT_VAR_HANDLE Handle);

/**
* @brief Reads all SVI variables actually added to the SVI client. The values
*        and read results are returned in the given SVI_CLIENT_VAR structure.
*        Depending on the client handle creation mode, also the change states
*        and time stamps are updated with each function call. The read values
*        are internal shadowed and used for comparing with the values at the
*        next next SVI client read/write function call.
*
*        For write only variables (#SVI_F_IN only) the last successfully written
*        value is returned without an error.
*
*        If the Flag #SVI_CLF_RD_DISABLED is set in the #SVI_CLIENT_VAR structure
*        the read processing is skipped for this variable.
*
* @param[in]  ClientHandle  SVI client handle
* @param[in]  ReadMode      Controls the read behavior on service variables
*                           (#SVI_CLF_RD_SVFLAG)
*
* @retval #SVI_E_OK      All client variables successfully read
* @retval #SVI_E_PARM    The given ClientHandle is not valid
* @retval #SVI_E_FAILED  At least one variable is invalid or the read
*                        function returns an error. The error code is returned
*                        in the `RetCode` field of the erroneous variable.
*/
SINT32 svi_ClientRead(SVI_CLIENT_HANDLE ClientHandle, UINT32 ReadMode);

/**
* @brief Writes the SVI variables actually added to the SVI client. The value
*        and size fields of the #SVI_CLIENT_VAR structure are compared with the
*        internal stored values of the last SVI client read/write function call.
*        Only if the values (or size at block types) differs, the write at this
*        variable is really executed.
*
*        If a variable is not readable (#SVI_F_IN only) the last written value
*        is taken for compare.
*
*        Calls with write mode #SVI_CLM_WR_UPDATE simply write all writable
*        variables, without doing a compare.
*
*        If the #SVI_CLF_WR_UPDATE is set in the Flags field, this writable
*        variable will be written without doing a compare.
*
*        If the Flag #SVI_CLF_WR_DISABLED is set in the #SVI_CLIENT_VAR structure
*        the write processing is skipped for this variable.
*
*        If a variable is not writable (#SVI_F_OUT only) the write operation is
*        skipped.
*
* @param[in]  ClientHandle  SVI client handle
* @param[in]  WriteMode     Controls the write behavior, write only changed
*                           values or all variables (#SVI_CLM_WR_UPDATE)
*
* @retval #SVI_E_OK      All client variables successfully read
* @retval #SVI_E_PARM    The given `ClientHandle` is not valid
* @retval #SVI_E_FAILED  At least one variable is invalid or the write
*                        function returns an error. The error code is returned
*                        in the `RetCode` field of the erroneous variable.
*/
SINT32 svi_ClientWrite(SVI_CLIENT_HANDLE ClientHandle, UINT32 WriteMode);

/**
* @brief Reads the specified SVI variable added to the SVI client. The value
*        and read results are returned in the given #SVI_CLIENT_VAR structure.
*        Depending on the client handle creation mode, also the change state
*        and time stamp are updated with this function call. The read value
*        will be internal shadowed and used for comparing with the values at
*        the next SVI client read/write function calls.
*
*        The Flag #SVI_CLF_RD_DISABLED is ignored within this function call.
*
* @param[in]  ClientHandle  SVI client handle
* @param[in]  Handle        Handle of the SVI-Variable
* @param[in]  ReadMode      Controls the read behavior on service variables
*                           (#SVI_CLF_RD_SVFLAG)
*
*
* @retval #SVI_E_OK      Client variables successfully read
* @retval #SVI_E_PARM    Invalid ClientHandle or Handle parameter passed
* @retval #SVI_E_FAILED  The variable is invalid (address or length fail)
*                        or the SVI read function returns an error. The
*                        error code is returned in the RetCode field of the
*                        erroneous variable.
*/
SINT32 svi_ClientReadVar(SVI_CLIENT_HANDLE ClientHandle, SVI_CLIENT_VAR_HANDLE Handle,
                         UINT32 ReadMode);

/**
* @brief Writes a specified SVI variable added to the SVI client. The value
*        and data length fields in the #SVI_CLIENT_VAR structure are compared
*        with the internal stored value of the last SVI client read or write
*        function call. Only if the value (or size at block types) differs,
*        the write at this variable is really executed.
*
*        The Flag #SVI_CLF_WR_DISABLED is ignored within this function call.
*
*        If a variable is not readable (#SVI_F_IN only) the last written value
*        is taken for compare.
*
*        A call ignores the comparison result and just writes the variable if:
*        - write mode is #SVI_CLM_WR_UPDATE
*        - #SVI_CLF_WR_UPDATE flag is set in in #SVI_CLIENT_VAR
*
* @param[in]  ClientHandle  SVI client handle
* @param[in]  Handle        Handle of the SVI-Variable
* @param[in]  WriteMode     Controls the write behavior: write only, changed
*                           values or force writing (#SVI_CLM_WR_UPDATE)
*
* @retval #SVI_E_OK      Client variables successfully written
* @retval #SVI_E_PARM    Invalid `ClientHandle` or `Handle` parameter passed
* @retval #SVI_E_FAILED  The variable is invalid (address or length fail)
*                        or the SVI write function returns an error. The
*                        error code is returned in the `RetCode` field of the
*                        erroneous variable.
*/
SINT32 svi_ClientWriteVar(SVI_CLIENT_HANDLE ClientHandle, SVI_CLIENT_VAR_HANDLE Handle,
                          UINT32 WriteMode);

/**
* @brief Returns information of a SVI variable in client variable list.
*
* @param[in]  ClientHandle  SVI client handle
* @param[in]  Handle        Handle of the SVI-Variable in the client list
* @param[out] pPvInf        Pointer to return the requested information structure
*
* @retval #SVI_E_OK      Success, valid information is returned
* @retval #SVI_E_PARM    The given `ClientHandle` or `Handle` parameter is not valid
* @retval #SVI_E_ADDR    SVI-Server or symbolic variable does not exist
* @retval #SVI_E_DLEN    Wrong length was passed for this variable
* @retval #SVI_E_BADTYPE Wrong SVI-Format was passed for this variable.
* @retval #SVI_E_FAILED  Unexpected state of this variable (should never occur)
*/
SINT32 svi_ClientGetPvInf(SVI_CLIENT_HANDLE ClientHandle, SVI_CLIENT_VAR_HANDLE Handle,
                          SVI_PVINF *pPvInf);

/**
* @brief Returns the pointer to all erroneous variables in subsequent order.
*
* This function can be called after a svi_ClientRead() or svi_ClientWrite()
* function call, if the called function returns the error #SVI_E_FAILED.
* With each function call the index of the next erroneous variable is
* returned. If no more errors are found, the function returns NULL.
*
* @param[in]     ClientHandle   SVI client handle
*
* @retval     NULL          No (more) errors found or client not valid
* @retval     others        Pointer to the (next) erroneous variable
*/
SVI_CLIENT_VAR *svi_ClientGetErrorVar(SVI_CLIENT_HANDLE ClientHandle);

/**
* @brief Returns the actual time stamp of a SVI variable added to the SVI client.
*
* @param[in]  ClientHandle  SVI client handle
* @param[in]  Handle        Handle of the SVI-Variable
* @param[out] pTimestamp    Pointer to return the time stamp
*
* @retval #SVI_E_OK      Success, the actual time stamp is returned
* @retval #SVI_E_PARM    The given `ClientHandle`, `Handle` or `pTimestamp`
*                        parameter is not valid
* @retval #SVI_E_FAILED  Time stamp processing is not activated for this Client
*/
SINT32 svi_ClientGetTimestamp(SVI_CLIENT_HANDLE ClientHandle, SVI_CLIENT_VAR_HANDLE Handle,
                              struct timespec *pTimestamp);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
