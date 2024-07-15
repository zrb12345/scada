/**
 ********************************************************************************
 * @file     crypt_keystore_e.h
 * @author   dorner
 *
 * @brief This file contains the functions to handle the secure key store which
 *        stores private keys.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2017
 *******************************************************************************/

#ifndef _CRYPT_KEYSTORE_E_H_
#define _CRYPT_KEYSTORE_E_H_

#include <vxWorks.h>
#include <mtypes.h>

#include <openssl/evp.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup SYS-CRYPT-KEYSTORE
 * @brief Secure key store.
 *
 * The secure key stores key-secret pairs encrypted on the file system (AES-256-CBC). The key used for AES encryption
 * is derived from the M1 master-key using HKDF.
 *
 * Each key is stored encrypted in a file. The file name is the key identifier:
 * <pre>
 * /cfc0/etc/keys
 *   M1PrivKey  2017-05-29 09:22   952 Byte
 * </pre>
 *
 * Use crypt_KeyStoreAdd() to add a new private key and crypt_KeyStoreGet() to get the private key.
 *
 * @since MBase 4.20 (VxWorks 7)
 * @{
 */

/**
 * @brief Add/Import a key into the secure key store.
 *
 * @param[in] keyId     Key ID / alias
 * @param[in] key       The key to store encrypted
 *
 * @retval #OK
 * @retval #ERROR
 */
STATUS crypt_KeyStoreAdd(const char *keyId, const EVP_PKEY *key);

/**
 * @brief Get a key from the secure key store.
 *
 * @param[in]  keyId    Key ID / alias
 * @param[out] key      Private key
 *
 * @retval #OK
 * @retval #ERROR
 */
STATUS crypt_KeyStoreGet(const char *keyId, EVP_PKEY **key);

/**
 * @brief Delete a key from the secure key store store.
 *
 * @param[in] keyId     Key ID to delete
 *
 * @retval #OK
 * @retval #ERROR
 */
STATUS crypt_KeyStoreDel(const char *keyId);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _H_CRYPT_KEYSTORE_H_ */
