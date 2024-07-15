/**
 ********************************************************************************
 * @file     crypt_kdf_e.h
 * @author   faessler
 *
 * @brief HKDF key derivation functions.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
 *******************************************************************************/

#ifndef _CRYPT_KDF_E_H_
#define _CRYPT_KDF_E_H_

#include <vxWorks.h>
#include <mtypes.h>

#include "crypt_hash_e.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup SYS-CRYPT-KDF
 * @brief Key derivation functions.
 *
 * Key derivation functions are used to derive keys from secret passwords or passphrases:
 *  - crypt_Hkdf() <br>
 *    HMAC-based Extract-and-Expand Key Derivation Function
 *  - crypt_Pbkdf2Hmac() <br>
 *    Password-Based Key Derivation Function 2
 *
 * @see cryptKdf.h
 * @{
 */

/** @brief Maximum SHA digest size in bytes . */
#define CRYPT_HKDF_SHA_MAXSIZE (CRYPT_HASH_SIZE_SHA512)

/**
 * @brief HKDF Extract function.
 * This function will perform HKDF extraction (RFC5869).
 *
 * @param[in]  hash    Hash Template, one of SHA1, SHA224, SHA256, SHA384, SHA512
 * @param[in]  salt    The optional salt value (a non-secret random value);
 *                     if not provided (salt == NULL), it is set internally
 *                     to a string of crypt_HashLen(hash) zeros.
 * @param[in]  saltLen The length of the salt value.  (Ignored if salt == NULL.)
 * @param[in]  ikm     Input keying material.
 * @param[in]  ikmLen  The length of the input keying material.
 * @param[out] prk     Array where the HKDF extraction is to be stored.
 *                     Must be equal or larger than crypt_HashLen(hash);
 * @return #OK for success, #ERROR if failed
 */
STATUS crypt_HkdfExtract(const CRYPT_HASH_METHOD *hash, const UCHAR *salt, SINT saltLen, const UCHAR *ikm, SINT ikmLen,
                         UCHAR prk[CRYPT_HKDF_SHA_MAXSIZE]);

/**
 * @brief HKDF Expand function.
 * This function will perform HKDF expansion (RFC5869).
 *
 * @param[in]  hash    Which hash function to use, one of SHA1, SHA224, SHA256, SHA384, SHA512
 * @param[in]  prk     The pseudo-random key to be expanded; either obtained
 *                     directly from a cryptographically strong, uniformly
 *                     distributed pseudo-random number generator, or as the output from crypt_HkdExtract().
 * @param[in]  prkLen  The length of the pseudo-random key in prk; should at least be equal to crypt_HashLen(hash).
 * @param[in]  info    The optional context and application specific information.
 *                     If info == NULL or a zero-length string, it is ignored.
 * @param[in]  infoLen The length of the optional context and application specific information
 *                     (ignored if info == NULL)
 * @param[out] okm     Where the output keying material is stored
 * @param[in]  okmLen  The length of the buffer to hold @p okm, okmLen must be <= 255 * crypt_HashLen(hash)
 *
 * @return #OK for success, #ERROR if failed
 */
STATUS crypt_HkdfExpand(const CRYPT_HASH_METHOD *hash, const UCHAR *prk, SINT prkLen, const UCHAR *info, SINT infoLen,
                        UCHAR *okm, SINT okmLen);

/**
 * @brief HMAC-based Extract-and-Expand Key Derivation Function.
 * This function will generate keying material using HKDF (RFC5869).
 *
 * @param[in]  hash    Hash method to use, one of SHA1, SHA224, SHA256, SHA384, SHA512
 * @param[in]  salt    The optional salt value (a non-secret random value);
 *                     if not provided (salt == NULL), it is set internally
 *                     to a string of crypt_HashLen(hash) zeros.
 * @param[in]  saltLen The length of the salt value.  (Ignored if salt == NULL.)
 * @param[in]  ikm     Input keying material.
 * @param[in]  ikmLen  The length of the input keying material.
 * @param[in]  info    The optional context and application specific information.
 *                     If info == NULL or a zero-length string, it is ignored.
 * @param[in]  infoLen The length of the optional context and application specific
 *                     information.  (Ignored if info == NULL.)
 * @param[out] okm     Where the output keying material is stored
 * @param[in]  okmLen  The length of the buffer to hold @p okm, okmLen must be <= 255 * crypt_HashLen(hash)
 *
 * @return #OK for success, #ERROR if failed
 * @see crypt_HkdfExtract()
 * @see crypt_HkdfExpand()
 */
STATUS crypt_Hkdf(const CRYPT_HASH_METHOD *hash, const UCHAR *salt, SINT saltLen, const UCHAR *ikm, SINT ikmLen,
                  const UCHAR *info, SINT infoLen, UCHAR *okm, SINT okmLen);

/**
 * @brief PKCS5 Password-based key derivation function 2.0.
 *
 * PKCS5 Password-based key derivation function 2.0, RFC 2898
 *
 * @param[in] hash method for the hash function to use for the HMAC operations. This is typically
 *            the return value of a crypt_HashGet<alg> function, e.g. crypt_HashGetSha1()
 * @param[in]  pw      Password used to to generate keying material
 * @param[in]  pwLen   Length of the @p pw argument
 * @param[in]  salt    Pointer to salt
 * @param[in]  saltLen Length of salt argument
 * @param[in]  c       Iteration count
 * @param[out] dkLen   Intended length in octets for the derived key
 * @param[out] dk      Where the derived key is stored
 * @return #OK on success, #ERROR otherwise
 * @see https://www.ietf.org/rfc/rfc2898.txt
 */
STATUS crypt_Pbkdf2Hmac(const CRYPT_HASH_METHOD *hash, const char *pw, SINT pwLen, const UCHAR *salt, SINT saltLen,
                        SINT c, SINT dkLen, UCHAR *dk);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _CRYPT_KDF_E_H_ */
