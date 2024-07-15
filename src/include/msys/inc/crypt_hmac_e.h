/**
 ********************************************************************************
 * @file     crypt_hmac_e.h
 * @author   faessler
 *
 * @brief This file is a wrapper for the VxWorks 7 HMAC functions.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
 *******************************************************************************/

#ifndef _CRYPT_HMAC_E_H_
#define _CRYPT_HMAC_E_H_

#include <vxWorks.h>
#include <mtypes.h>

#include "crypt_hash_e.h"

/**
 * @addtogroup SYS-CRYPT-HMAC
 * @brief Hash Message Authentication Code.
 * HMAC is a key MAC (Message Authentication Code), used for message authentication.
 *
 * The HMAC API can be used to calculate an HMAC on a consecutive memory area. If the
 * memory is divided into multiple chunks crypt_HmacInit(), crypt_HmacUpdate() and crypt_HmacFinal()
 * must be used.
 *
 * @see cryptHmac.h
 * @since MBase 4.11 (VxWorks 7)
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Maximum block size. */
#define CRYPT_HMAC_MAX_BLOCK 128

/** @brief HMAC context.*/
typedef struct CRYPT_HMAC_CTX_S
{
    CRYPT_HASH_CTX hashCtx;                      /**< Hash context */
    UCHAR          k_ipad[CRYPT_HMAC_MAX_BLOCK]; /**< Outer padding */
    UCHAR          k_opad[CRYPT_HMAC_MAX_BLOCK]; /**< Inner padding */
    UINT           keyLen;                       /**< Key length */
} CRYPT_HMAC_CTX;

/**
 * @brief Initialize a #CRYPT_HMAC_CTX with the given @p key.
 *
 * Initialize a #CRYPT_HMAC_CTX. Must be called before crypt_HmacUpdate() and crypt_HmacFinal() can be called.
 *
 * @param[in] ctx    HMAC context to initialize
 * @param[in] key    The key
 * @param[in] keyLen Size of key (bytes)
 * @param[in] hash   The hash method to use for the HMAC
 * @return #OK if successful, #ERROR otherwise
 */
STATUS crypt_HmacInit(CRYPT_HMAC_CTX *ctx, const UCHAR *key, SINT keyLen, const CRYPT_HASH_METHOD *hash);

/**
 * @brief Add message data to an HMAC calculation.
 *
 * crypt_HmacUpdate() can be called repeatedly in order to add multiple chunks of data
 * to an HMAC calculation.
 *
 * @param[in] ctx     HMAC context
 * @param[in] data    Data to add
 * @param[in] dataLen Size of data (bytes)
 *
 * @return #OK if successful, #ERROR otherwise.
 */
STATUS crypt_HmacUpdate(CRYPT_HMAC_CTX *ctx, const UCHAR *data, UINT dataLen);

/**
 * @brief Finalize an HMAC calculation.
 *
 * Finalize an HMAC calculation. @p hmacLen must be at least as long as the hash
 * output length.
 *
 * @param[in] ctx         HMAC context
 * @param[out] hmac       Output buffer where to store the HMAC digest
 * @param[in,out] hmacLen Length of the output buffer. The number of bytes placed into @p hmac is set on success.
 *
 * @return #OK if successful, #ERROR otherwise
 */
STATUS crypt_HmacFinal(CRYPT_HMAC_CTX *ctx, UCHAR *hmac, UINT *hmacLen);

/**
 * @brief Cleans up a #CRYPT_HMAC_CTX.
 * This function frees up any resources tied to the HMAC context.
 * @param[in] ctx HMAC context
 */
void crypt_HmacCleanup(CRYPT_HMAC_CTX *ctx);

/**
 * @brief Calculate an HMAC.
 *
 * This function calculates an HMAC on a consecutive memory area.
 * @param[in] key         The key
 * @param[in] keyLen      Size of key (bytes)
 * @param[in] data        Data to add
 * @param[in] dataLen     Size of data (bytes)
 * @param[out] hmac       Output buffer where to store the HMAC digest.
 * @param[in,out] hmacLen Length of the digest output buffer. The number of bytes
 *                        placed into @p hmac is set on success.
 * @param[in] hash        The hash method to use for the HMAC
 * @return #OK if successful, #ERROR otherwise
 */
STATUS crypt_Hmac(const UCHAR *key, SINT keyLen, const UCHAR *data, UINT dataLen, UCHAR *hmac, UINT *hmacLen,
                  const CRYPT_HASH_METHOD *hash);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _CRYPT_HMAC_E_H_ */
