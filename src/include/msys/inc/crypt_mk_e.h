/**
 ********************************************************************************
 * @file     crypt_mk_e.h
 * @author   faessler
 *
 * @brief This file contains master-key functions to handle encryption keys.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
 *******************************************************************************/

#ifndef _CRYPT_MK_E_H_
#define _CRYPT_MK_E_H_

#include <vxWorks.h>
#include <mtypes.h>

#include "crypt_hash_e.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup SYS-CRYPT-MK
 * @brief Master-key handling.
 *
 * The master-key is used as system wide key to derive specific encryption keys (secure vault store, application specific
 * keys).
 *
 * The 8-byte master-key (stored per CPU) is derived from a single password string using PBKDF2.
 * For a given password always the same master-key value is generated. Thus the salt and count inputs for
 * PBKDF2 are fixed.
 *
 * <pre>
 * Definition:
 *   pbkdf2(password, salt, count, hash, len)
 *
 * master-key generation:
 *   mk[8] = pbkdf2(password, SHA1("<bachmann>"), 1001, SHA256, 8)
 * </pre>
 * @see cryptMk.h
 * @since MBase 4.11 (VxWorks 7)
 * @{
 */

/** @brief Maximum length of master-key password incl '\\0'.*/
#define CRYPT_MK_PASSWORD_MAX 256

/**
 * @brief Set the master-key (derived from @p password) to the M1 device.
 * This routine derives a master-key using a password-based key derivation function (PBKDF2).
 * The derived master-key is stored on the M1 device.
 *
 * @param[in] password The master-key password
 * @return #OK or #ERROR
 *
 * @see crypt_MkDel()
 * @see crypt_Mkdf()
 * @since MBase 4.11 (VxWorks 7)
 */
STATUS crypt_MkSet(const char *password);

/**
 * @brief Delete master-key from the M1 device.
 * This routine deletes the master-key from the corresponding ID-registers (factory reset).
 * @return #OK or #ERROR
 * @since MBase 4.11 (VxWorks 7)
 */
STATUS crypt_MkDel(void);

/**
 * @brief Determines if the M1 device has a valid master-key.
 * @return #OK if master-key is valid, #ERROR otherwise
 * @since MBase 4.11 (VxWorks 7)
 */
STATUS crypt_MkValid(void);

/**
 * @brief Derive encryption key (from master-key) using HKDF.
 * This routine derives a custom encryption key based on the device master-key. For the same master-key
 * and equal input parameters, always the same output key is generated.
 *
 * @param[in]  hash    Hash method to use, one of SHA1, SHA224, SHA256, SHA384, SHA512
 * @param[in]  salt    The optional salt value (a non-secret random value);
 *                     if not provided (salt == NULL), it is set internally
 *                     to a string of DigestLen(hash) zeros.
 * @param[in]  saltLen The length of the salt value.  (Ignored if salt == NULL.)
 * @param[in]  info    The optional context and application specific information.
 *                     If info == NULL or a zero-length string, it is ignored.
 * @param[in]  infoLen The length of the optional context and application specific information,
 *                     ignored if info == NULL.
 * @param[out] okm     Where the output keying material is stored
 * @param[out] okmLen  The length of the buffer to hold @p okm,
 *                     okmLen must be <= 255 * crypt_HashDigestSize(hash)
 * @return #OK for success, #ERROR on failure
 * @since MBase 4.11 (VxWorks 7)
 */
STATUS crypt_Mkdf(const CRYPT_HASH_METHOD *hash, const UCHAR *salt, SINT saltLen, const UCHAR *info, SINT infoLen,
                  UCHAR *okm, UINT okmLen);

/**
 * @brief Print master-key information to stdout.
 * @since MBase 4.11 (VxWorks 7)
 * @return #OK or #ERROR
 */
STATUS crypt_ShowMk(void);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _CRYPT_MK_E_H_ */
