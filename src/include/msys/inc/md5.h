/**
********************************************************************************
* @file     md5.h
* @author   khueny
*
* @brief    This file contains the definitions and declarations of
*           the Message-Digest Algorithm 5 (MD5)
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef MD5_H
#define MD5_H

#ifdef __cplusplus
extern  "C"
{
#endif

#ifdef __GNUC__
#include <vxWorks.h>
#endif                                  // __GNUC__
#include <mtypes.h>

/**
 * @addtogroup MD5-DEF
 * @{
 */

/**
 * @brief Context
 */
typedef struct MD5Context
{
    UINT32  buf[4];   /**< Parameter provided for an internal algorithm */
    UINT32  bits[2];  /**< Parameter provided for an internal algorithm */
    UINT8   in[64];   /**< Parameter provided for an internal algorithm */
} MD5_CTX;
/** @} */

/**
 * @addtogroup MD5-API
 * @{
 */

/**
 * @brief This function initializes the structure MD5_CTX for calculation
 *        of the checksum in accordance with message digest algorithm 5 (MD5).
 *
 * @param[in,out] context   Pointer to the structure MD5_CTX
 *
 * @note The structure does not need to be initialized. This occurs
 *       automatically when executing the function MD5Init().
 *       The parameters are provided for an internal algorithm and therefore
 *       will not be described in more detail.
 *       @code{.c}
typedef struct MD5Context
{
   UINT32 buf[4];
   UINT32 bits[2];
   UINT8  in[64];
} MD5_CTX;
@endcode
 *
 * <b>Example</b>
 * @snippet doc_lib_md5.c MD5Init
 */
VOID MD5Init(MD5_CTX *context);

/**
 * @brief  This function updates the content of structure MD5_CTX.
 *
 * Prior to this function the function MD5Init() must be executed.
 * After updating the structure MD5_CTX, the result of the message digest
 * algorithm 5 (MD5) can be read out via the function MD5Final().
 *
 * @param[in] context        Pointer to the structure MD5_CTX
 * @param[in] buf            Pointer to the buffer memory via which the
 *                           checksum should be calculated
 * @param[in] len            Length of the transferred buffer memory
 *
 * @note The structure does not need to be initialized. This occurs
 *       automatically when executing the function MD5Init().
 *       The parameters are provided for an internal algorithm and therefore
 *       will not be described in more detail.
 *       @code{.c}
typedef struct MD5Context
{
   UINT32 buf[4];
   UINT32 bits[2];
   UINT8  in[64];
} MD5_CTX;
@endcode
 *
 * <b>Example</b>
 * @snippet doc_lib_md5.c MD5Init
 */
VOID MD5Update(MD5_CTX *context, const UINT8 *buf, UINT32 len);

/**
 * @brief This function returns the result of the message digest
 *        algorithm 5 (MD5).
 *
 * Prior to this function the functions MD5Init() and MD5Update() must be
 * executed.
 *
 * @param[in]  context        Pointer to the structure MD5_CTX
 * @param[out] digest         Calculated MD5 sum with a length of 16 bytes
 *                            or 128 bits
 *
 * @note The structure does not need to be initialized. This occurs
 *       automatically when executing the function MD5Init().
 *       The parameters are provided for an internal algorithm and therefore
 *       will not be described in more detail.
 *       @code{.c}
typedef struct MD5Context
{
   UINT32 buf[4];
   UINT32 bits[2];
   UINT8  in[64];
} MD5_CTX;
@endcode
 *
 * <b>Example</b>
 * @snippet doc_lib_md5.c MD5Init
 */
VOID MD5Final(UINT8 digest[16], MD5_CTX *context);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* !MD5_H */
