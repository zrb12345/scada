/**
 ********************************************************************************
 * @file     svi_e.h
 * @author   Schwennd
 *
 * @brief This file contains all definitions and declarations exported by
 *        the Standard Variable Interface Library for use by modules running
 *        on the same CPU.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
 *******************************************************************************/

#ifndef SVI_E__H
#define SVI_E__H

#ifdef __cplusplus
extern "C"
{
#if 0
}
#endif
#endif

#include <svi.h>
#include <smi_e.h>
#include <inetLib.h>

/**
 * @addtogroup SVI-DEF
 * @{
 */

/**
 * @name Definitions of SVI library function table index
 * @{
 */
#define SVI_NBOFFUNC            10      /**< Number of functions in SVI-Lib V1 */
#define SVI_NBOFFUNC2           11      /**< Number of functions in SVI-Lib V2 */

#define SVI_RESERVED            0       /**< Reserved, entry for signature */
#define SVI_GETVAL              1       /**< Read 32-bit value, see svi_GetVal() */
#define SVI_SETVAL              2       /**< Write 32-bit value, see svi_SetVal()*/
#define SVI_GETVALLST           3       /**< Read list of 32-bit values, see svi_GetValLst() */
#define SVI_SETVALLST           4       /**< Write list of 32-bit values, see svi_SetValLst() */
#define SVI_GETBLK              5       /**< Read block value, see svi_GetBlk() */
#define SVI_SETBLK              6       /**< Write block value, see svi_SetBlk() */
#define SVI_GETADDR             7       /**< Convert symbolic address to SVI machine address, see svi_GetAddr() */
#define SVI_GETPVINF            8       /**< Get list of symbolic names, see svi_GetPvInf() */
#define SVI_GETSERVINF          9       /**< Get SVI server info, see svi_GetSrvInf() */
#define SVI_GETVARINF           10      /**< Get SVI variable info, see svi_GetVarInf() */
/** @} */

/**
 * @anchor SVI_HT_
 * @name Definitions for initialization
 * @see svi_Init()
 * @{
 */
#define SVI_HT_DEF          0x00000000  /**< Normal default behavior for the library initialization */
#define SVI_HT_2LIB         0x00000001  /**< Type to call a 2nd svi_Init(), before releasing the 1st */
#define SVI_HT_NON          0x00000008  /**< Type to suppress page switching (if protection layer is managed by the r/w/entry/exit functions and global variables are accessible in all partitions) */
#define SVI_HT_GLOB         0x00000010  /**< Type to switch to Global partition before executing the read/write access */
#define SVI_HT_SYS          0x00000020  /**< Type to switch to System partition before executing the read/write access*/
#define SVI_HT_PLC          0x00000040  /**< Signals the SVI Handler is created for a PLC RTS application instance */
#define SVI_HT_256K         0x00000080  /**< Sets the maximum number of SVI variables to 256K */
#define SVI_HT_PAGE_MASK    (SVI_HT_NON | SVI_HT_GLOB | SVI_HT_SYS)

/** @} */

/**
 * @name Mode for markers
 * @see svi_AddMarkers()
 * @see svi_AddVirtMarkers()
 * @{
 */
#define SVI_HM_INT              0       /**< Internal usage of markers (not exported )*/
#define SVI_HM_EXP              1       /**< Format to export all entries of one marker type */
#define SVI_HM_NO_INUSE_LOCK    0x0010  /**< No consistency lock required at block access functions */
/** @} */

/**
 * @anchor SVI_HM_
 * @name Mode for variables
 * @see svi_AddGlobVar()
 * @see svi_AddVirtVar()
 * @{
 */
#define SVI_HM_NAME_ALLOC       0x0001  /**< Indicates that the Name of the variable is already static allocated by the SVI application instance (no copy is necessary) */
#define SVI_HM_UNIFIED_WRITE    0x0002  /**< Same prototype for all write functions */
#define SVI_HM_SV_FLAG          0x0004  /**< Activate the Service Flag in the machine address (internal used at field bus variables for shadowing) */
#define SVI_HM_NOPVINF          0x0008  /**< Specifies that the variable in svi_GetPvInf() will not be exported (the variable is not shown by the Device Manager) */
#define SVI_HM_NO_INUSE_LOCK    0x0010  /**< No consistency lock required at block access functions */
#define SVI_HM_ATOMIC_ACCESS    0x0080  /**< Support atomic block access functions */
/** @} */

/**
 * @name Possible size for atomic block access variables
 * @see svi_AddGlobVar()
 * @see svi_AddVirtVar()
 * @{
 */

#define SVI_ATOMIC_DATA_SIZE    2048    /**< Variables up to 2K can be atomic accessed */
#define SVI_ATOMIC_LOCK_SIZE     128    /**< Variables up to 128 bytes are locked by task lock, others by a semaphore */
/** @} */


/** Definition of SVI library function (returned by svi_GetLib()) */
typedef SINT32 (*SVI_FUNC)(void);


/** @brief SVI Variable */
typedef struct
{
    void *pAddr;            /**< Address of variable */
    UINT8 Format;           /**< Format of variable */
    UINT8 Mode;             /**< Mode of the variable */
    UINT16 Len;             /**< Length of variable */
    UINT16 Reserved;        /**< Reserve */
    UINT8 bVariableIsValid; /**< Flag if data is still valid (Online-Change, ReInit of SW-module) */
    UINT8 NameLen;          /**< String Length of symbolic name */
    CHAR *pName;            /**< Pointer to symbolic name of variable */
} SVI_VAR;

/** @brief SVI Marker variable, Type 1 */
typedef struct
{
    void *pAddr;            /**< Address of marker variable */
    UINT32 Type;            /**< Type of marker @ref SVI_VT_ */
    UINT32 Index;           /**< Index of marker variable */
    UINT32 *pLen;           /**< Size of address range */
} MARKER_VAR;

/** @brief SVI Marker variable, Type 2 */
typedef struct
{
    void *pAddr;            /**< Address of marker variable */
    UINT32 Type;            /**< Type of marker */
    union
    {
        UINT32 Index;       /**< Index of array marker variable */
        struct              /**< Destination address */
        {
            UINT16 Idx1;    /**< Marker index 1 (high index) */
            UINT16 Idx2;    /**< Marker index 2 (low index) */
        } W;
    } Adr;                  /**< Address of Destination/Source */
    UINT32 *pLen;           /**< Size of address range */
} MARKER_VAR2;

/** Definition of #SVI_VAR lock function */
typedef SINT32 (*SVI_FUNC_LOCK)(SVI_VAR *pVar, UINT32 UserParam);

/** Definition of #SVI_VAR unlock function */
typedef void (*SVI_FUNC_UNLOCK)(SVI_VAR *pVar, UINT32 UserParam);

/** Generic definition of virtual read function */
typedef SINT32 (*SVI_FUNC_READ)();

/** Generic definition of virtual write function */
typedef SINT32 (*SVI_FUNC_WRITE)();

/** Definition of #MARKER_VAR lock function */
typedef SINT32 (*SVI_FUNC_MARKER_LOCK)(MARKER_VAR *pVar, UINT32 UserParam);

/** Definition of #MARKER_VAR unlock function */
typedef void (*SVI_FUNC_MARKER_UNLOCK)(MARKER_VAR *pVar, UINT32 UserParam);

/** Definition of virtual marker read function */
typedef SINT32 (*SVI_FUNC_MARKER_READ)(MARKER_VAR *pVar, UINT32 UserParam);

/** Definition of virtual marker write function */
typedef SINT32 (*SVI_FUNC_MARKER_WRITE)(MARKER_VAR *pVar, UINT32 UserParam);

/** @} End of SVI-TYP */

/**
 * @addtogroup SVI-API
 * @{
 */

/**
 * @brief With this function it is possible to read one global or virtual process
 *        variable or marker, with a basic data type up to 32-bit data length.
 *
 * @param[in]  pLib       Pointer to function library (returned by svi_GetLib())
 * @param[in]  Addr       SVI address of the desired process value (returned by svi_GetAddr())
 * @param[out] pValue     Pointer to the value read, with 32-bit data size.
 *
 * @retval SVI_E_OK       Process value successfully read
 * @retval SVI_E_PARM     Invalid function library parameter
 * @retval SVI_E_ADDR     Invalid address
 * @retval SVI_E_OLDADDR  Address of process value is no longer valid
 * @retval SVI_E_UNDEF    Variable has block data type (@ref SVI_F_BLK), use
 *                        svi_GetBlk() for reading
 * @retval SVI_E_FAILED   Operation not possible
 * @retval SVI_E_xx       Other SVI error codes are possibly returned by
 *                        the virtual read and/or locking function of the
 *                        SVI server.
 *
 * @note At global variables or markers, the function returns a signed extended
 *       32-bit value also at smaller basic data types. For this, `pValue`
 *       must point to a value with a data size of at least 32-bit.
 *
 * @note At virtual process values, the read function is responsible for sign
 *       extension and data consistency. It should always return consistent
 *       32-bit values.
 *
 * @note The SVI server is responsible for data consistency during access to
 *       process values (for example locking with semaphores).
 */
SINT32 svi_GetVal(SVI_FUNC *pLib, SVI_ADDR Addr, UINT32 *pValue);


/**
 * @brief With this function it is possible to write one global or virtual process
 *        variable or marker, with a basic data type up to 32-bit data length.
 *
 * @param[in]  pLib       Pointer to function library (returned by svi_GetLib())
 * @param[in]  Addr       SVI address of the desired process value (returned by svi_GetAddr())
 * @param[in]  Value      Value to be written
 *
 * @retval SVI_E_OK       Process value successfully written
 * @retval SVI_E_PARM     Invalid function library parameter
 * @retval SVI_E_ADDR     Invalid address
 * @retval SVI_E_OLDADDR  Address of process value is no longer valid
 * @retval SVI_E_UNDEF    Variable has block data type (@ref SVI_F_BLK), use
 *                        svi_SetBlk() for writing
 * @retval SVI_E_FAILED   Operation not possible, the module is in the
 *                        STOP or ERROR state
 * @retval SVI_E_WRITE    Write protected variable
 * @retval SVI_E_xx       Other SVI error codes are possibly returned by
 *                        the virtual write and/or locking function of the
 *                        SVI server
 *
 * @note The SVI server is responsible for data consistency during access to
 *       process values (for example locking with semaphores).
 */
SINT32 svi_SetVal(SVI_FUNC *pLib, SVI_ADDR Addr, UINT32 Value);

/**
 * @brief With this function it is possible to read a list of global and/or virtual
 *        process variables or markers, with basic data types up to 32-bit data
 *        length.
 *
 * @param[in]  pLib       Pointer to function library (returned by svi_GetLib())
 * @param[in]  pAddrLst   Pointer to the beginning of the list, containing the
 *                        SVI addresses of the desired process values for read
 * @param[in]  pValueLst  Pointer to an array of 32-bit variables, for returning
 *                        the read values
 * @param[in]  ListLen    List length, number of process values to be read
 * @param[out] pValueLst  Read values of the desired process variables
 *
 * @retval SVI_E_OK       Process values successfully read
 * @retval SVI_E_PARM     Invalid function library parameter
 * @retval SVI_E_ADDR     Invalid address
 * @retval SVI_E_OLDADDR  Address of process value is no longer valid
 * @retval SVI_E_UNDEF    Variable has block data type (@ref SVI_F_BLK), use
 *                        svi_GetBlk() for reading
 * @retval SVI_E_FAILED   Operation not possible, the module is in the
 *                        STOP or ERROR state
 * @retval SVI_E_xx       Other SVI error codes are possibly returned by
 *                        the virtual read and/or locking function of the
 *                        SVI server
 *
 * @note This list will be processed completely, even if it contains invalid
 *       addresses. The corresponding value in `pValueLst` remains unchanged in
 *       case of an invalid address.
 *
 * @note At global variables or markers, the function returns signed extended
 *       32-bit values also at smaller basic data types. For this, `pValueLst`
 *       must point to an array of 32-bit values.
 *
 * @note At virtual process values, the read function is responsible for sign
 *       extension and data consistency. It should always return consistent
 *       32-bit values.
 *
 * @note The SVI server is responsible for data consistency during access to
 *       process values (for example locking with semaphores).
 *
 */
SINT32 svi_GetValLst(SVI_FUNC *pLib, SVI_ADDR *pAddrLst, UINT32 *pValueLst, UINT32 ListLen);

/**
 * @brief With this function it is possible to write a list of global and/or virtual
 *        process variables or markers, with basic data types up to 32-bit data
 *        length.
 *
 * @param[in]  pLib       Pointer to function library (returned by svi_GetLib())
 * @param[in]  pAddrLst   Pointer to the beginning of the list, containing the
 *                        SVI addresses of the process values that are to be written
 * @param[in]  pValueLst  Pointer to an array of 32-bit variables, containing the
 *                        the write values
 * @param[in]  ListLen    List length, number of process values to be written
 *
 * @retval SVI_E_OK       Process values successfully written
 * @retval SVI_E_PARM     Invalid function library parameter
 * @retval SVI_E_ADDR     Invalid address
 * @retval SVI_E_OLDADDR  Address of process value is no longer valid
 * @retval SVI_E_UNDEF    Variable has block data type (@ref SVI_F_BLK), use
 *                        svi_GetBlk() for reading
 * @retval SVI_E_FAILED   Operation not possible, the module is in the
 *                        STOP or ERROR state
 * @retval SVI_E_WRITE    Write protected variable
 * @retval SVI_E_xx       Other SVI error codes are possibly returned by
 *                        the virtual write and/or locking function of the
 *                        SVI server
 *
 * @note This list will be processed completely, even if it contains invalid
 *       addresses.
 *
 * @note The SVI server is responsible for data consistency during access to
 *       process values (for example locking with semaphores).
 *
 */
SINT32 svi_SetValLst(SVI_FUNC *pLib, SVI_ADDR *pAddrLst, UINT32 *pValueLst, UINT32 ListLen);

/**
 * @brief With this function it is possible to read global and/or virtual process
 *        variables or markers with the type of data block (@ref SVI_F_BLK format).
 *
 * @param[in]  pLib       Pointer to function library (returned by svi_GetLib())
 * @param[in]  Addr       SVI address of the desired process value (returned by svi_GetAddr())
 * @param[in]  pBuff      Pointer to the read buffer
 * @param[in]  pBuffLen   Length of the read buffer
 * @param[out] pBuff      Read data block
 * @param[out] pBuffLen   Length of the read data block
 *
 * @retval SVI_E_OK       Data block successfully read
 * @retval SVI_E_PARM     Invalid function library parameter
 * @retval SVI_E_ADDR     Invalid address
 * @retval SVI_E_OLDADDR  Address of process value is no longer valid
 * @retval SVI_E_VARINUSE A write access  to the process value is currently
 *                        in progress or the read access could not be consistency
 *                        complete (interrupted by a write process during
 *                        data block read)
 * @retval SVI_E_FAILED   Operation not possible, the module is in the
 *                        STOP or ERROR state
 * @retval SVI_E_xx       Other SVI error codes are possibly returned by
 *                        the virtual read and/or locking function of the
 *                        SVI server.
 *
 * @note After a successful function execution, the read buffer contains the
 *       read data with the exact data length, according to the data type of the
 *       desired process value. If a too small buffer is passed, the data will be
 *       truncated at the given length.
 *
 * @note No signed extension or padding with zeros up to 32 bits is made, when
 *       using this function for reading also non block type variables. This
 *       behavior differs to the svi_GetVal() function, who returns always a
 *       signed extended 32 bit value, also at smaller basic data types.
 *
 * @note The SVI server is responsible for data consistency during access to
 *       process values (for example locking with semaphores).
 */
SINT32 svi_GetBlk(SVI_FUNC *pLib, SVI_ADDR Addr, void *pBuff, UINT32 *pBuffLen);

/**
 * @brief With this function it is possible to write global and/or virtual process
 *        variables or markers with the type of data block (@ref SVI_F_BLK format).
 * Virtual variables of basic types (without block format) which was created
 * with mode @ref SVI_HM_UNIFIED_WRITE are also supported.
 *
 * @param[in]  pLib       Pointer to function library (returned by svi_GetLib())
 * @param[in]  Addr       SVI address of the desired process value (returned by svi_GetAddr())
 * @param[in]  pBuff      Pointer to the write buffer
 * @param[in]  BuffLen    Number of bytes to be written
 *
 * @retval SVI_E_OK       Data block successfully written
 * @retval SVI_E_PARM     Invalid function library parameter
 * @retval SVI_E_ADDR     Invalid address
 * @retval SVI_E_OLDADDR  Address of process value is no longer valid
 * @retval SVI_E_VARINUSE An other write access to the process value is
 *                        currently in progress.
 * @retval SVI_E_FAILED   Operation not possible, the module is in the
 *                        STOP or ERROR state
 * @retval SVI_E_WRITE    Write protected variable
 * @retval SVI_E_xx       Other SVI error codes are possibly returned by
 *                        the virtual write and/or locking function of the
 *                        SVI server
 *
 * @note The numbers of bytes for writing is limited by the data size of the
 *       process value. Excessive bytes will be truncated.
 *
 * @note For compatibility reasons it is also possible to use this function with
 *       standard variables of basic types (without mode @ref SVI_HM_UNIFIED_WRITE).
 *       In this case, the length of the write buffer should exactly match with
 *       the data type size. Missing bytes are not written, which can result in
 *       incorrect values.
 *
 * @note The SVI server is responsible for data consistency during access to
 *       process values (for example locking with semaphores).
 */
SINT32 svi_SetBlk(SVI_FUNC *pLib, SVI_ADDR Addr, void *pBuff, UINT32 BuffLen);

/**
 * @brief Returns the SVI function library entry point of the software module
 *        instance, whose function interface is to be used. The returned pointer
 *        is used for all further SVI library function calls.
 *
 * @param[in]  pAppName   Name of the application instance.
 *
 * @retval !0   Pointer to function interface
 * @retval 0    Software module instance not found
 *
 * @note The module name of the application instance is not case sensitive
 *
 * @see res_GetFuncLib()
 */
SVI_FUNC *svi_GetLib (CHAR *pAppName);

/**
 * @brief If a function interface is no longer needed, it will be announced using
 *        this function. After this, the function interface must not be used any more.
 *
 * @param[in]  pLib       Pointer to function library (returned by svi_GetLib())
 *
 * @retval 0    OK
 * @retval -1   Invalid function library parameter
 *
 * @see res_UngetFuncLib()
 */
SINT32 svi_UngetLib(SVI_FUNC *pLib);

/**
 * @brief Converts a symbolic address to the SVI machine address. The address is
 *        used at the SVI client read/write access functions.
 *
 * @param[in]  pLib       Pointer to function library (returned by svi_GetLib())
 * @param[in]  pName      Symbolic address of the process variable
 * @param[in]  pFormat    If the pointer points to the special code #SVI_F_EXTLEN,
 *                        also the data length of the variable is returned
 * @param[out] pAddr      SVI address of the desired process value. The SVI address
 *                        at pAddr is also changed in case of an error and is only
 *                        valid with return value #SVI_E_OK
 * @param[out] pFormat    SVI data format @ref SVI_F_ and direction (#SVI_F_IN, #SVI_F_OUT).
 *                        The high word (upper 16-Bits) contains the data length in bytes
 *                        if requested by #SVI_F_EXTLEN
 *
 * @retval SVI_E_OK       Success, valid address and format returned
 * @retval SVI_E_PARM     Invalid function library pointer
 * @retval SVI_E_OLDADDR  The function library of the module has turned to invalid state
 * @retval SVI_E_FAILED   Operation not possible, the module is in the STOP or ERROR state
 * @retval SVI_E_ADDR     Invalid index in symbolic address
 * @retval SVI_E_BADNAME  Symbolic address not found or invalid
 * @retval others         Access to own (old style) SVI server implementations may
 *                        provide also other (own) return values
 *
 * @note Since M-Sys V3.10, the machine address of an SVI variable will be retained,
 *       if the module instance reinitializes the SVI server (e.g. online change with
 *       an M-PLC software module) see also svi_ReInit().
 *       This does not apply in the following cases:
 *       - Compatibility setting < 3.10
 *       - Format or length of an SVI variable changes
 */
SINT32 svi_GetAddr(SVI_FUNC *pLib, const CHAR *pName, SVI_ADDR *pAddr, UINT32 *pFormat);

/**
 * @brief With this function it is possible to get information about all
 *        exported process variables of a SVI server. The information
 *        structure contains the symbolic address, the SVI format and data
 *        length in bytes of each variable. The query can be controlled
 *        by the parameters `StartIdx` and `pNbOfPv`. For example, if SVI servers
 *        holds a very large number of variables, the query can be split.
 *
 * @param[in]  pLib       Pointer to function library (returned by svi_GetLib())
 * @param[in]  StartIdx   Index of the first desired process variable (0-n)
 * @param[in]  pNbOfPv    Number of desired process variables
 * @param[in]  pPvInf     Pointer to process variables information buffer
 * @param[out] pPvInf     Buffer with the process variables information
 * @param[out] pNbOfPv    Number of read process variables information
 *
 * @retval SVI_E_OK       Information buffer successfully filled
 * @retval SVI_E_PARM     Invalid function library pointer
 * @retval SVI_E_OLDADDR  The function library of the module has turned to invalid state
 * @retval SVI_E_ADDR     The `StartIdx` parameter exceeds the available numbers of
 *                        process values of this SVI server
 *
 * @note This function is mainly used by the Variables View in the Device Manager
 *       and by the OPC server.
 *
 * @note With the svi_GetAddr() function symbolic addresses can be converted to
 *       SVI machine addresses, which is necessary for all SVI read/write access
 *       functions (e.g. svi_SetVal())
 *
 * @note Process variables which have been generated with mode #SVI_HM_NOPVINF are
 *       ignored and not added to `pPvInf` list.
 *
 * @note SVI Servers can also support the dynamic generation of generic
 *       SVI variables. This means, that variables are only generated, if they
 *       are used by an application. Generic variables will be generated, if
 *       the SVI machine address is requested with the svi_GetAddr() function.
 *       After this, such variables are also returned in `pPvInf` list.
 *
 */
SINT32 svi_GetPvInf(SVI_FUNC *pLib, UINT32 StartIdx, UINT32 *pNbOfPv, SVI_PVINF *pPvInf);

/**
 * @brief With this function it is possible to read general information about
 *        the SVI server. The information structure contains the version, address
 *        class (obsolete information) and the number of exported markers and/or
 *        process variables.
 *
 * @param[in]  pLib       Pointer to function library (returned by svi_GetLib())
 * @param[in]  pServInf   Pointer to buffer
 * @param[out] pServInf   Information about the SVI server
 *
 * @retval SVI_E_OK       Information buffer successfully filled
 * @retval SVI_E_PARM     Invalid function library pointer
 * @retval SVI_E_OLDADDR  The function library of the module has turned to invalid state
 *
 * @note If the SVI server supports dynamic adding and/or generic process variables,
 *       the returned number of process variables represents the number of the exported
 *       variables which have been actually requested by the clients, not the maximum
 *       possible variables of this server.
 */
SINT32 svi_GetServInf(SVI_FUNC *pLib, SVI_SERVINF *pServInf);

/**
 * @brief This function returns some general information about a SVI marker variable.
 *
 * @param[in]  pLib       Pointer to function library (returned by svi_GetLib())
 * @param[in]  Addr       SVI address of the desired process value (returned by svi_GetAddr())
 * @param[in]  pVarInf    Pointer to buffer
 * @param[out] pVarInf    Information about the SVI variable
 *
 * @retval SVI_E_OK       Information buffer successfully filled
 * @retval SVI_E_PARM     Invalid function library pointer
 * @retval SVI_E_OLDADDR  The function library of the module has turned to invalid state
 * @retval SVI_E_ADDR     No valid marker address
 */
SINT32 svi_GetVarInf(SVI_FUNC *pLib, SVI_ADDR Addr, SVI_VARINF *pVarInf);

/**
 * @brief Determines the symbolic address (SVI name) from the SVI machine address.
 *
 * @param[in]  pLib       Pointer to function library (returned by svi_GetLib())
 * @param[in]  Addr       SVI address of the desired process value (returned by svi_GetAddr())
 * @param[out] pName      Symbolic address of the process variable. The buffer must
 *                        be at least #SVI_ADDRLEN_A long
 *
 * @retval SVI_E_OK       Symbolic address successfully returned
 * @retval SVI_E_FAILED   The function library does not support this function
 * @retval SVI_E_OLDADDR  The SVI machine address is no longer valid
 * @retval SVI_E_ADDR     Invalid SVI machine address
 *
 * @note The symbolic address does not include the module instance name of the SVI server.
 */
SINT32 svi_GetNameByAddr(SVI_FUNC *pLib, SVI_ADDR Addr, CHAR *pName);


/** @} End of SVI-API */

/**
 * @addtogroup SVI-HAND
 * @{
 */

/**
 * @brief Creates and initializes an SVI handler for a software module
 *        instance. This is the first function a user has to call. The
 *        function returns the Library handle, which has to be used for
 *        all other SVI handler functions (for example svi_AddGlobVar()).
 *
 * @param[in]  AppName     Name of the application instance.
 * @param[in]  Format      Predefined initialization type @ref SVI_HT_
 * @param[in]  fctp_Search @c NULL or optional search function for dynamically
 *                         adding variables .
 *
 * @retval >0  Handle for Library
 * @retval 0   An error has occurred (out of resources). The error reason is
 *             logged with the tag 'E:SVIHAN_INIT' followed by the error
 *             description.
 *
 * @note The optional search function is called within svi_GetAddr() function,
 *       if the desired symbolic address is not already in the variables list.
 *       If dynamically adding is supported, this function calls for example
 *       the svi_AddVirtVar() function to export the desired process variable.
 *       Normally, this pointer is zero.
 *
 * @note The special call with #SVI_HT_2LIB defines the creation of a second
 *       SVI handler before the first instance is deleted by the the svi_DeInit()
 *       function. This guarantees an 'online change' of variables without
 *       interruption.
 */
UINT32 svi_Init(CHAR * AppName, UINT32 Format, SINT32(*fctp_Search)());

/**
 * @brief This function is used to reinitialize the SVI handler. All existing
 *        variables (global, virtual and marker variables) are deleted. The
 *        incarnation counter is updated and all resources (e.g memory, semaphores)
 *        are reinitialized, according the state after svi_Init().
 *
 * @param[in]  Handle     Library handle (returned by svi_Init())
 *
 * @retval 0   OK, library successfully reinitialized
 * @retval -1  Error, invalid Library handle parameter, application instance not
 *             found or at least one client is currently accessing to this SVI handler.
 *
 * @note The function svi_ReInit() is a system function and may not be used by
 *       applications.
 */
UINT32 svi_ReInit(UINT32 Handle);

/**
 * @brief This function removes the SVI handler and frees up all resources.
 *
 * After calling this function, the concerned software module no longer
 * has a SVI library. The `Handle` parameter gets invalid and must not
 * be used anymore.
 *
 * @param[in]  Handle     Library handle (returned by svi_Init())
 *
 * @retval 0   OK, library successfully removed
 * @retval -1  Error, invalid Library handle parameter
 */
SINT32 svi_DeInit(UINT32 Handle);

/**
 * @ingroup SVI-ACCESS
 * @brief This Function updates the SVI rights and ranges. Depending on the
 *        configuration, it sends the SMI call #SMI_PROC_SETSVIACCESS to the access
 *        handler or evaluates the rights configuration in file MConfig.ini (of the
 *        respective module).
 *
 * @param[in]  Handle     Library handle (returned by svi_Init())
 *                        or @c NULL for all software modules
 *
 * @retval 0   OK, rights and ranges successfully applied
 * @retval -1  Error in customer specific SVI rights checker or invalid Library
 *             handle parameter
 * @retval -2  Error in applying value ranges
 * @retval -3  Error in applying access rights
 *
 * @note Since it is a blocking function, which can last several milliseconds,
 *       depending on the number of rights and variables, it has to be called
 *       already during the initialization and not during the runtime.
 *
 * @note The function is called by the PLC runtime environment or by the
 *       SVI providing software module.
 */
SINT32 svi_ApplyRights(UINT32 Handle);

/**
 * @brief Function for adding a global process variable to the variables list,
 *        for being exported as SVI variable.
 *
 * @param[in]  Handle     Library handle (returned by svi_Init())
 * @param[in]  Name       Symbolic address of the variable (excluding the software
 *                        module name) with a maximum string length of #SVI_ADDRLEN
 * @param[in]  Format     Predefined format of the variable (@ref SVI_F_)
 * @param[in]  Len        Data length in bytes (limit is #SVI_MAXVARLEN)
 * @param[in]  pAddr      Physical memory address of the variable
 * @param[in]  Mode       Predefined mode for the variable (@ref SVI_HM_)
 * @param[in]  UserParam  User defined parameter passed to the lock/unlock functions.
 * @param[in]  fLock      @c NULL or function to lock variable before read/write access
 * @param[in]  fUnlock    @c NULL or function to unlock variable after read/write access
 *
 * @retval  0  OK, global variable successfully exported
 * @retval >0  Handle of the SVI variable. The handle is returned in case of
 *             Mode #SVI_HM_ATOMIC_ACCESS and is used by the SVI application
 *             instance for svi_AtomicRead() and svi_AtomicWrite() function calls.
 * @retval -1  An error has occurred (wrong/mismatching parameters or out of resources),
 *             the error reason is logged with the tag 'E:SVIHAN_ADDGLOBVAR' followed by
 *             an error description.
 * @retval -2  Maximum numbers of possible variables reached, no more variables (global
 *             and/or virtual) could be added. The maximum is 64K or 256K variables
 *             depending on the Type Flag #SVI_HT_256K passed at svi_Init() call.
 *
 * @note The parameters `fLock`, `fUnlock` and `UserParam` are optional. They may be used,
 *       to realize an application specific locking of the process variables memory
 *       area, for consistent data update. If the function pointers are not @c NULL, the
 *       locking function is called within the SVI client read/write functions before
 *       accessing the process data memory, and the unlocking function afterwards.
 *
 * @note The return value of the function fLock() is tested. If it is less than zero
 *       (negative), the corresponding SVI access function (svi_GetXxx, svi_SetXxx) is
 *       not executed. The error code is returned unchanged for these functions.
 *       Only SVI errors may be used as the error code as specified under @ref SVI_E_
 *       in the svi.h file.
 */
SINT32 svi_AddGlobVar(UINT32 Handle, CHAR * Name, UINT32 Format, UINT32 Len,
                      void *pAddr, UINT32 Mode, UINT32 UserParam,
                      SVI_FUNC_LOCK fLock, SVI_FUNC_UNLOCK fUnlock);

/**
 * @brief Function for adding a virtual process variable to the variables list,
 *        for being exported as SVI variable. Virtual variables do not physically
 *        exist, they are represented by the passed read/write functions.
 *
 * @param[in]  Handle   Library handle (returned by svi_Init())
 * @param[in]  Name     Symbolic address of the variable (excluding the software
 *                      module name) with a maximum string length of #SVI_ADDRLEN
 * @param[in]  Format   Predefined format of the variable (@ref SVI_F_)
 * @param[in]  Len      Data length in bytes (limit is #SVI_MAXVARLEN)
 * @param[in]  Mode     Predefined mode for the variable (@ref SVI_HM_)
 * @param[in]  RPar1    1st user defined parameter passed to the read function
 * @param[in]  RPar2    2nd user defined parameter passed to the read function
 * @param[in]  WPar1    1st user defined parameter passed to the write function
 * @param[in]  WPar2    2nd user defined parameter passed to the write function
 * @param[in]  fRead    Function to read the value (prototype depending on #SVI_F_BLK)
 * @param[in]  fWrite   Function to write the value (prototype depending on #SVI_F_BLK
 *                      and #SVI_HM_UNIFIED_WRITE)
 *
 * @retval  0  OK, virtual variable successfully exported
 * @retval >0  Handle of the SVI variable. The handle is returned in case of
 *             Mode #SVI_HM_ATOMIC_ACCESS and is used by the SVI application
 *             instance for svi_AtomicRead() and svi_AtomicWrite() function calls.
 * @retval -1  An error has occurred (wrong/mismatching parameters or out of resources),
 *             the error reason is logged with the tag 'E:SVIHAN_ADDVIRTVAR' followed by
 *             an error description.
 * @retval -2  Maximum numbers of possible variables reached, no more variables (global
 *             and/or virtual) could be added. The maximum is 64K or 256K variables
 *             depending on the Type Flag #SVI_HT_256K passed at svi_Init() call.
 *
 * @note Depending on the data type format and the given mode, different function
 *       parameters must be used at the read/write functions:
 *       - For basic variables without block format, which are accessed by the
 *         svi_GetVal(), svi_GetValLst(), svi_SetVal() and svi_SetValLst() functions,
 *         the parameters according to the svi_fReadValPrototype() and
 *         svi_fWriteValPrototype() functions must be used.
 *       - For block type variables (#SVI_F_BLK), which are accessed by the
 *         svi_GetBlk() and svi_SetBlk() functions, the parameters according
 *         to the svi_fReadBlkPrototype() and svi_fWriteBlkPrototype() functions
 *         must be used.
 *       - For basic variables with the mode #SVI_HM_UNIFIED_WRITE you also have
 *         to use the parameters according to the svi_fWriteBlkPrototype() function.
 *         Such variables can be processed by the svi_SetVal() as well as the
 *         svi_SetBlk() function.
 */
SINT32 svi_AddVirtVar(UINT32 Handle, CHAR * Name, UINT32 Format, UINT32 Len,
                      UINT32 Mode, UINT32 RPar1, UINT32 RPar2, UINT32 WPar1,
                      UINT32 WPar2, SVI_FUNC_READ fRead, SVI_FUNC_WRITE fWrite);

/**
 * @brief   Prototype for the fRead() function for virtual variables, which are
 *          exported by the svi_AddVirtVar() function, with a basic data type
 *          (up to 32 bits) without the #SVI_F_BLK format flag set.
 *
 * @param[in]  RPar1      1st user defined read function parameter (freely available)
 * @param[in]  RPar2      2nd user defined read function parameter (freely available)
 * @param[in]  pValue     Pointer to store the read value
 * @param[in]  SvFlag     Specifies whether it is a service variable for which
 *                        the value should be read out from the cache
 * @param[in]  SessionId  Session ID of the user (i.e. in case of SMI calls)
 * @param[out] pValue     Contains the new read value, signed extended and/or
 *                        zero padded to 32 bit
 *
 * @retval SVI_E_OK       If value successfully read and stored in `pValue`
 * @retval SVI_E_xxx      If the value cannot be read, the function should return
 *                        one of the predefined SVI error codes (@ref SVI_E_).
 *                        The error code is returned unchanged by the svi_GetVal()
 *                        function to the caller.
 *
 * @note  As of MSys Version 3.70, the two parameters `SvFlag` and `SessionId` are
 *        transferred with the function. `SvFlag` is a boolean value and is
 *        therefore easy to distinguish from a pointer. These two parameters
 *        are optional and not mandatory.
 */
SINT32 svi_fReadValPrototype(UINT32 RPar1, UINT32 RPar2, UINT32 *pValue,
        BOOL32 SvFlag, UINT32 SessionId);

/**
 * @brief   Prototype for the fWrite() function for virtual variables, which are
 *          exported by the svi_AddVirtVar() function, with a basic data type
 *          (up to 32 bits) without the #SVI_F_BLK format.
 *
 * @param[in]  WPar1      1st user defined write function parameter (freely available)
 * @param[in]  WPar2      2nd user defined write function parameter (freely available)
 * @param[in]  Value      New value for write
 *
 * @retval SVI_E_OK       If value successfully written
 * @retval SVI_E_xxx      If the value cannot be written, the function should return
 *                        one of the predefined SVI error codes (@ref SVI_E_).
 *                        The error code is returned unchanged by the svi_SetVal()
 *                        function to the caller.
 *
 * @note For basic variables with the mode #SVI_HM_UNIFIED_WRITE the fWrite() function
 *       is called with the parameters according to the svi_fWriteBlkPrototype().
 *
 */
SINT32 svi_fWriteValPrototype(UINT32 WPar1, UINT32 WPar2, UINT32 Value);

/**
 * @brief Prototype for the fRead() function for virtual variables, which are
 *        exported by the svi_AddVirtVar() function, with block format data
 *        types (#SVI_F_BLK). For block types, data lengths from 1 byte up to 64 kB
 *        are allowed.
 *
 * @param[in]  RPar1      1st user defined read function parameter (freely available)
 * @param[in]  RPar2      2nd user defined read function parameter (freely available)
 * @param[in]  pBuff      Pointer to the read buffer
 * @param[in]  pBuffLen   Pointer to the length of the read buffer (buffer size)
 * @param[in]  SvFlag     Specifies whether it is a service variable for which
 *                        the value should be read out from the cache
 * @param[in]  SessionId  Session ID of the user (i.e. in case of SMI calls)
 * @param[out] pBuff      Contains the new read read data (limited to the buffer size)
 * @param[out] pBuffLen   Contains the number of bytes stored in the read buffer
 *
 * @retval SVI_E_OK       If value successfully read and stored in pBuff
 * @retval SVI_E_xxx      If the value can't be read, the function should return
 *                        one of the predefined SVI error codes (@ref SVI_E_).
 *                        The error code is returned unchanged by the svi_GetBlk()
 *                        function to the caller.
 *
 * @note  As of MSys Version 3.70, the two parameters `SvFlag` and `SessionId` are
 *        transferred with the function. `SvFlag` is a boolean value and is
 *        therefore easy to distinguish from a pointer. These two parameters
 *        are optional and not mandatory.
 */
SINT32 svi_fReadBlkPrototype(UINT32 RPar1, UINT32 RPar2, UINT8 *pBuff, UINT32 *pBuffLen,
        BOOL32 SvFlag, UINT32 SessionId);

/**
 * @brief Prototype for the fWrite() function for virtual variables, which are
 *        exported by the svi_AddVirtVar() function, with block format data
 *        types (#SVI_F_BLK) or basic variables with mode #SVI_HM_UNIFIED_WRITE.
 *
 * For block types, data lengths from 1 byte up to 64 kB are allowed.
 *
 * @param[in]  WPar1      1st user defined write function parameter (freely available)
 * @param[in]  WPar2      2nd user defined write function parameter (freely available)
 * @param[in]  pBuff      Pointer to the write buffer
 * @param[in]  BuffLen    Data length for write
 * @param[in]  SvFlag     Specifies whether it is a service variable.
 * @param[in]  SessionId  Session ID of the user (i.e. in case of SMI calls)
 *
 * @retval SVI_E_OK       If data are successfully written
 * @retval SVI_E_xxx      If the data can't be written, the function should return
 *                        one of the predefined SVI error codes (@ref SVI_E_).
 *                        The error code is returned unchanged by the svi_SetBlk()
 *                        and/or svi_SetVal() function to the caller.
 *
 * @note  As of MSys Version 3.70, the two parameters `SvFlag` and `SessionId` are
 *        transferred with the function. `SvFlag` is a boolean value and is
 *        therefore easy to distinguish from a pointer. These two parameters
 *        are optional and not mandatory.
 */
SINT32 svi_fWriteBlkPrototype(UINT32 WPar1, UINT32 WPar2, UINT8 *pBuff, UINT32 BuffLen,
        BOOL32 SvFlag, UINT32 SessionId);

/**
 * @brief This function allows marker ranges to be exported as SVI variables.
 *
 * The symbolic address for a marker is predefined as Marker-Type/Index.
 * The parameters `fLock` and `fUnlock` allow functions for access control
 * (such as semaphores) to be used. The `fLock` function is called before the
 * marker variable is read and/or written and `fUnlock` after the variable
 * access. Both function pointers must be zero if not used.
 *
 * @param[in]  Handle       Library Handle (returned by svi_Init())
 * @param[in]  Type         Specifies the marker type as defined in @ref SVI_VT_.
 * @param[in]  Numb         Specifies the total number of markers, starting at the beginning.
 * @param[in]  pAddr        Physical memory address of the first marker.
 * @param[in]  NumbOfSetVal Specifies the number of set values (writable markers), starting at the beginning.
 * @param[in]  Mode         Defines the mode of the marker #SVI_HM_INT (internal) or #SVI_HM_EXP (exported)
 * @param[in]  UserParam    User defined parameter passed to the lock/unlock functions.
 * @param[in]  fLock        @c NULL or function to lock the variable before read/write access
 * @param[in]  fUnlock      @c NULL or function to unlock the variable after read/write access
 *
 * @retval  0  OK, marker range successfully exported
 * @retval -1  An error has occurred (wrong/mismatching parameters or out of resources),
 *             the error reason is logged with the tag 'SVIHAN_ADDMARKERS' followed by
 *             an error description.
 */
SINT32 svi_AddMarkers(UINT32 Handle, UINT32 Type, UINT32 Numb, void *pAddr,
                      UINT32 NumbOfSetVal, UINT32 Mode, UINT32 UserParam,
                      SVI_FUNC_MARKER_LOCK fLock, SVI_FUNC_MARKER_UNLOCK fUnlock);

/**
 * @brief Function for adding a virtual matrix markers and/or array markers.
 *
 * Virtual markers do not exist physically, they are represented by the
 * passed read/write functions. The symbolic address for a marker is
 * predefined as 'Marker-Type/high-index/low-index'.
  *
 * @param[in]  Handle      Library handle (returned by svi_Init())
 * @param[in]  Type        Specifies the marker type as defined in  @ref SVI_VT_.
 * @param[in]  StartL      Start index low matrix elements (low or 2nd index)
 * @param[in]  StartH      Start index high matrix elements (high or 1st index)
 * @param[in]  NumbL       Number low matrix elements (rows, low or 2nd index)
 * @param[in]  NumbH       Number high matrix elements (columns, high or 1st index)
 * @param[in]  Mode        Defines the mode of the marker #SVI_HM_INT (internal) or #SVI_HM_EXP (exported)
 * @param[in]  UserParam   User parameter passed to the read/write functions.
 * @param[in]  fRead       Function for read access to the marker area
 * @param[in]  fWrite      Function for write access to the marker area
 *
 * @retval  0  OK, virtual marker successfully exported
 * @retval -1  General error. Wrong SVI library handle, out of memory, conflict in marker
 *             type or overlapping range
 * @retval -2  `fWrite` function pointer missing
 * @retval -3  `fRead`  function pointer missing
 * @retval -4  `StartL` and/or `NumbL` parameter exceeds 16-Bit address limit
 * @retval -5  Unknown `Type` parameter (out of range #SVI_VT_MAX)
 * @retval -6  `StartH` and/or `NumbH` parameter exceeds 16-Bit address limit
 *
 * @note The return value of the function fRead() or fWrite() is tested. If it
 *       is less than zero (negative), the corresponding SVI access function
 *       (svi_GetXxx or svi_SetXxx) is not executed. The error code is returned
 *       unchanged for these functions. Only SVI errors may be used as the error
 *       code as specified under @ref SVI_E_ in the svi.h file.
 */
SINT32 svi_AddVirtMarkers(UINT32 Handle, UINT32 Type, UINT32 StartL, UINT32 StartH,
                          UINT32 NumbL, UINT32 NumbH, UINT32 Mode, UINT32 UserParam,
                          SVI_FUNC_MARKER_READ fRead,SVI_FUNC_MARKER_WRITE fWrite);

/**
 * @deprecated Use of svi_MsgHandler2() is recommend.
 *
 * @brief Compatible function which wraps svi_MsgHandler2().
 *
 * @param[in]  Handle   Library handle (returned by svi_Init())
 * @param[in]  pMsg     SMI message structure, received with the smi_Receive() function
 * @param[in]  pSmiId   Unique SMI identification of this application instance,
 *                      returned by res_ModInsert()
 */
void svi_MsgHandler(UINT32 Handle, SMI_MSG *pMsg, SMI_ID *pSmiId);

/**
 * @brief Handles the incoming SMI messages (RPCs see @ref SVI_PROC_)
 *
 * @param[in]  Handle   Library handle (returned by svi_Init())
 * @param[in]  pMsg     SMI message structure, received with the smi_Receive2() function.
 * @param[in]  pSmiId   Unique SMI identification of this application instance,
 *                      returned by res_ModInsert()
 * @param[in]  User     User's SessionId to verify access permissions,
 *                      forwarded from smi_Receive2()
 *
 * @note This function processes all SMI message accesses (RPCs) related to SVI.
 *       The user program does not need to have any other SMI code in order to
 *       export SVI through SMI.
 */
void svi_MsgHandler2(UINT32 Handle, SMI_MSG *pMsg, SMI_ID *pSmiId, UINT32 User);

/**
 * @brief This function changes the state of the SVI handler to 'data invalid',
 *        in order to ensure, that SVI clients no longer have access to the
 *        handler by SVI client function calls.
 *
 * @param[in]  Handle    Library handle (returned by svi_Init())
 */
void svi_SetDataInvalid(UINT32 Handle);

/**
 * @ingroup  SVI-API
 * @brief This function determines the name of the application module instance.
 *
 * @param[in]  pLib       Pointer to function library (returned by svi_GetLib())
 *
 * @return Application name or '(none)' if name cannot be resolved.
 */
CHAR *svi_GetClientsName(SINT32(**pLib) ());

/**
 * @ingroup SVI-ACCESS
 * @brief This function sets the required read and write levels for a SVI variable.
 *
 * @param[in]  AppName     Name of the software module
 * @param[in]  Name        Symbolic address of the variable (excluding the software
 *                         module name). An asterisk character * can be used as wildcard,
 *                         to set the rights of several variables. * may occur only at the
 *                         end, all leading characters are interpreted as the variable name.
 * @param[in]  ReadLevel   Array with the required read levels or @c NULL, if no read
 *                         permission check is required.
 * @param[in]  WriteLevel  Array with the required write levels or @c NULL, if no write
 *                         permission check is required.
 * @param[in]  ElemCount   Number of array elements
 *
 * @retval <0              Number of configured variables
 *
 * @retval SVI_E_FAILED    Error, wrong compatibility-mode (>= 3.10 is required) or
 *                         function is not supported (old style function library)
 * @retval SVI_E_PARM      Invalid parameters (number of elements without any arrays given)
 * @retval SVI_E_NOMOD     Software module not found
 * @retval SVI_E_BADNAME   The variable was not found
 * @retval SVI_E_OLDADDR   The variable is no longer valid
 * @retval SVI_E_NOMEM     Insufficient memory
 *
 * @note The array index corresponds to the user group. Thus, the first array element
 *       specifies which level the user must at least have if he belongs to group 0.
 *
 * @note If a user group is not intended for the array, (user group higher than the
 *       highest array index), the members of this group will get no access.
 *
 * @note The rights configuration of an SVI variable remains as is regardless of
 *       whether the software module is uninstalled and then reinstalled.
 *       If necessary, reset SVI variable.

 *       Examples for parameters `AppName` and `Name`:
 *          - Set the rights of all RES variables:
 *            @c svi_SetVarRights("RES", \"@b *\", ...)
 *          - Set the rights of all RES/NET variables:
 *            @c svi_SetVarRights("RES", \"NET/@b *\", ...)
 *          - Set the rights of all RES/NET/eth0 variables:
 *            @c svi_SetVarRights("RES", \"NET/eth0/@b *\". ...)
 *          - Set the rights of RES/NET/eth0/Cur100m and RES/NET/eth0/Cur100s variables:
 *            @c svi_SetVarRights("RES", "NET/eth0/Curr*", ...)
 *
 *       Examples of `ReadLevel` parameter: @n
 *
 *       An array of bytes must be transferred in the parameter `ReadLevel`. It is
 *       recommended to keep the length of the array the same size as the number of
 *       user groups. The first array element determines the level required for
 *       group 0, and the second array element determines the level required for
 *       group 1 etc. If the user has level 0, Read-Level 1 is required and the user
 *       is not granted access. @n
 *
 *       Assuming the following user and groups are defined:
 *       User   | Group | Level
 *       :------|:-----:|:----:
 *       User 0 |   0   |   0
 *       User 1 |   1   |   0
 *       User 2 |   1   |   0
 *
 *       In the example, the user groups 0, 1 and 2 are used and different values for
 *       `ReadLevel` are transferred. The line read permission indicates which user
 *       group receives @b read @b permission (r) or does not receive read permission (x).
 *
 *       Read level and result               | Var 1   |  Var 2  | Var 3   | Var 4   | Var 5
 *       :-----------------------------------|:-------:|:-------:|:-------:|:-------:|:------
 *       @b ReadLevel array for the variables| {0,0,1} | {1,1,1} | {0,0,2} | {1,0  } | NULL
 *       Read permission for User 0, 1, 2    |  r,r,x  |  x,x,x  |  r,r,x  |  x,r,x  | r,r,r
 *
 *       The parameter `WriteLevel` is to be handled in the same way as `ReadLevel`. @n
 */
SINT32 svi_SetVarRights(CHAR * AppName, CHAR * Name, UINT8 * ReadLevel,
                        UINT8 * WriteLevel, UINT16 ElemCount);

/**
 * @ingroup SVI-ACCESS
 * @brief Get the configured access-rights of a variable.
 *
 * If the read or write level is not configured, the array is filled with 0.
 * The filling uses the configured size, limited to the size specified
 * in the parameter `ElemCount`, when exceeds.
 *
 * @param[in]  AppName     Name of the software module
 * @param[in]  Name        Symbolic address of the variable (excluding the software
 *                         module name)
 * @param[in]  ReadLevel   Array for returning the read levels
 * @param[in]  WriteLevel  Array for returning the write levels
 * @param[in]  ElemCount   Length of the arrays
 *
 * @retval >=0             Number of elements
 * @retval SVI_E_FAILED    Error, wrong compatibility-mode (>= 3.10 is required) or
 *                         function is not supported (old style function library)
 * @retval SVI_E_PARM      Invalid parameters
 * @retval SVI_E_NOMOD     Software module not found
 * @retval SVI_E_BADNAME   The variable was not found
 * @retval SVI_E_OLDADDR   The variable is no longer valid
 */
SINT32 svi_GetVarRights(CHAR * AppName, CHAR * Name, UINT8 * ReadLevel,
                        UINT8 * WriteLevel, UINT16 ElemCount);

/**
 * @ingroup SVI-ACCESS
 * @brief Set the allowed minimum and maximum value for a variable.
 *
 * To prevent the `Min` and/or `Max` parameters from being checked at
 * remote write access, you can use the constant @c NaN as parameter value.
 *
 * @param[in]  AppName     Name of the software module
 * @param[in]  Name        Symbolic address of the variable (excluding the software
 *                         module name)
 * @param[in]  Min         Minimum value
 * @param[in]  Max         Maximum value
 *
 * @retval SVI_E_OK        OK, range successfully configured
 * @retval SVI_E_FAILED    Error, wrong compatibility-mode (>= 3.10 is required) or
 *                         function is not supported (old style function library)
 * @retval SVI_E_NOMEM     Insufficient memory
 * @retval SVI_E_PARM      Invalid parameters (`Min` > `Max` or variable with unsupported data type)
 * @retval SVI_E_NOMOD     Software module not found
 * @retval SVI_E_BADNAME   The variable was not found.
 * @retval SVI_E_OLDADDR   The variable is no longer valid.
 *
 * @note For the check of parameters `Min` and `Max`, a security level > 0 is required,
 *       because the value range check only considers SVI write access per remote.
 *
 * @note When configuring the `Min` and `Max` parameters for SVI variables with
 *       data types @c UINT64 or @c SINT64, rounding errors can occur. The parameters
 *       are rounded to the next @c REAL64 value that can be represented.
 *
 * @note The value range configuration of an SVI variable remains as is regardless
 *       of whether the software module is uninstalled and then reinstalled.
 *       If necessary, reset SVI variable.
 *
 * @see SMI_PROC_SETSVIACCESS
 */
SINT32 svi_SetVarRange(CHAR * AppName, CHAR * Name, REAL64 Min, REAL64 Max);

/**
 * @ingroup SVI-ACCESS
 * @brief Get the minimum and maximum value of a variable.
 *
 * @param[in]  AppName     Name of the software module
 * @param[in]  Name        Symbolic address of the variable (excluding the software
 *                         module name)
 * @param[out] Min         Minimum value
 * @param[out] Max         Maximum value
 *
 * @retval SVI_E_OK        OK, values successfully returned
 * @retval SVI_E_FAILED    Error, wrong compatibility-mode (>= 3.10 is required) or
 *                         function is not supported (old style function library)
 * @retval SVI_E_PARM      Invalid parameter's
 * @retval SVI_E_NOMOD     Software module not found
 * @retval SVI_E_BADNAME   The variable was not found.
 * @retval SVI_E_OLDADDR   The variable is no longer valid.
 *
 @note If a value is not configured for the parameter, a constant is supplied
       with the value @c NaN (BeTypes.h). The function @b IsNaN (private/mathP.h)
       can be used to check the value @c NaN.
 */
SINT32 svi_GetVarRange(CHAR * AppName, CHAR * Name, REAL64 * Min, REAL64 * Max);

/**
 * @brief This function copies n bytes from memory area `pSource` to memory area
 *        `pDest` on unbreakable manner. The memory areas must not overlap.
 *        Depending on `Handle` parameter the SVI server specific or the system
 *        global (`Handle` = 0) mutual exclusion semaphore is used to protect the
 *        memcpy() function call.
 *
 * @param[in]  Handle    Library handle (returned by svi_Init()) or 0
 * @param[in]  pSource   Pointer to the source of data to be copied
 * @param[in]  Len       Number of bytes to be copied
 * @param[out] pDest     Pointer to the destination area where the content is to
 *                       be copied
 *
 * @retval SVI_E_OK        Data successfully copied
 * @retval SVI_E_FAILED    Operation not possible (out of resources)
 */
SINT32 svi_AtomicCopy(UINT32 Handle, VOID *pDest, VOID *pSource, UINT32 Len);

/**
 * @brief This function reads an SVI block variable like svi_GetBlk() does it.
 *
 * The function must be used by the SVI server application for a consistent
 * data exchange with the SVI client applications. Only if the server and
 * the client applications use the same locking method, data consistency
 * is given.
 *
 * @param[in]  VarHandle Handle of the SVI variable (returned by svi_AddGlobVar(),
 *                       svi_AddVirtVar())
 * @param[in]  pBuff     Pointer to the read buffer
 * @param[in]  pBuffLen  Length of the reading block
 * @param[out] pBuff     Read block
 * @param[out] pBuffLen  Length of the read block
 *
 * @retval SVI_E_OK      Data successfully read
 * @retval SVI_E_FAILED  Operation not possible
 */
SINT32 svi_AtomicRead(SINT32 VarHandle, VOID *pBuff, UINT32 *pBuffLen);

/**
 * @brief This function writes an SVI block variable like svi_SetBlk() does it.
 *
 * The function must be used by the SVI server application for a consistent
 * data exchange with the SVI client applications. Only if the server and
 * the client applications use the same locking method, data consistency
 * is given.
 *
 * @param[in]  VarHandle Handle of the SVI variable (returned by svi_AddGlobVar(),
 *                       svi_AddVirtVar())
 * @param[in]  pBuff     Pointer to the write buffer
 * @param[in]  BuffLen   Length of the write block
 *
 * @retval SVI_E_OK      Data successfully written
 * @retval SVI_E_FAILED  Operation not possible
 */
SINT32 svi_AtomicWrite(SINT32 VarHandle, VOID *pBuff, UINT32 BuffLen);

/** @} */

/**
 * @private
 * @brief Inserts a buffer into the svi_GetMultiBlkLst list.
 *
 * @param[in]  Id          Unique buffer ID
 * @param[in]  Type        Type of buffer data
 * @param[in]  BuffLen     Buffer length
 * @param[in]  Buff        Pointer to buffer
 * @param[in]  NbOfElem    Number of elements
 *
 * @retval 0   OK
 * @retval 1  ERROR
 */
SINT32 svi_InsertGetBuffer(UINT32 Id, UINT32 Type, UINT32 BuffLen, UINT8 * Buff, UINT32 NbOfElem);

/**
 * @private
 * @brief Inserts a buffer into the svi_SetMultiBlkLst list.
 *
 * @param[in]  Id          Unique buffer ID
 * @param[in]  Type        Type of buffer data
 * @param[in]  BuffLen     Buffer length
 * @param[in]  Buff        Pointer to buffer
 * @param[in]  Offset      Offset in the real mem of the var (mostly 0)
 * @param[in]  pAddr       SVI_ADDR of the var to set
 * @param[in]  NbOfElem    Number of the elements of the buffer (VHD)
 *
 * @retval 0   OK
 * @retval 1  ERROR
 */
SINT32 svi_InsertSetBuffer(UINT32 Id, UINT32 Type, UINT32 BuffLen,
                           UINT8 * Buff, SVI_ADDR *pAddr, UINT32 Offset, UINT32 NbOfElem);


#ifdef __cplusplus
}
#endif

#endif
