/**
 ********************************************************************************
 * @file     crypt_vault_e.h
 * @author   faessler
 *
 * @brief This file contains the functions to handle the secure vault which
 *        stores passwords/secrets.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
 *******************************************************************************/

#ifndef _CRYPT_VAULT_E_H_
#define _CRYPT_VAULT_E_H_

#include <vxWorks.h>
#include <mtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup SYS-CRYPT-VAULT
 * @brief Secure vault.
 *
 * The secure vault stores key-secret pairs encrypted on the file system (AES-256-CBC). The key used for AES encryption
 * is derived from the M1 master-key using HKDF.
 *
 * Passwords that are stored in the vault are passwords that must be available in clear text, typically passwords that
 * are required in order to:
 *   - mount encrypted volumes
 *   - log in to other systems
 *
 * Each password is stored encrypted in a file, and each password is stored in a separate file. The file name is the key
 * identifier:
 * <pre>
 * /cfc0/etc/vault
 *   default   2016-11-29 07:22   16 Byte
 *   m1        2016-11-29 07:28  144 Byte
 * </pre>
 *
 * Use crypt_VaultAdd() to add a new password entry and crypt_VaultGet() to get the password value as cleartext.
 *
 * @see cryptVault.h
 * @since MBase 4.11 (VxWorks 7)
 * @{
 */

/** @brief Maximum key ID length incl \\0-termination. */
#define CRYPT_VAULT_KEYID_MAX 64

/** @brief Maximum secret length in bytes. */
#define CRYPT_VAULT_SECRET_MAX 256

/**
 * @brief Add/Import a secret into the secure vault store.
 *
 * @param[in] keyId     Key ID / alias
 * @param[in] secret    The secret password to store encrypted
 * @param[in] secretLen Length of the password
 *
 * @retval #OK
 * @retval #ERROR
 */
STATUS crypt_VaultAdd(const char *keyId, const char *secret, SINT secretLen);

/**
 * @brief Get a secret from the secure vault store.
 *
 * @param[in] keyId         Key ID / alias
 * @param[out] secret       Pointer to the buffer where to store the secret in
 * @param[in,out] secretLen Length of the secret buffer. The number of bytes placed into @p secret is set on success.
 *
 * @retval #OK
 * @retval #ERROR
 */
STATUS crypt_VaultGet(const char *keyId, char *secret, SINT *secretLen);

/**
 * @brief Delete a secret from the secure vault store.
 *
 * @param[in] keyId Key ID to delete
 *
 * @retval #OK
 * @retval #ERROR
 */
STATUS crypt_VaultDel(const char *keyId);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _H_CRYPT_VAULT_H_ */
