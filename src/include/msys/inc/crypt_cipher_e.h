/**
 ********************************************************************************
 * @file     crypt_cipher_e.h
 * @author   faessler
 *
 * @brief This file is a wrapper for the VxWorks 7 cipher functions.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
 *******************************************************************************/

#ifndef _CRYPT_CIPHER_E_H_
#define _CRYPT_CIPHER_E_H_

#include <vxWorks.h>
#include <mtypes.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @addtogroup SYS-CRYPT-CIPHER
 * @brief Cryptographic cipher functions for encryption/decryption.
 *  - AES 128, 192, 256 supporting different modes (CBC, CTR, ECB)
 *  - BLOWFISH (CBC)
 *
 * @see cryptCipher.h
 * @since MBase 4.11 (VxWorks 7)
 * @{
 */

/**
 * @name Definitions
 * @{
 */
#define CRYPT_CIPHER_DECR 0            /**< Decrypt mode */
#define CRYPT_CIPHER_ENCR 1            /**< Encrypt mode*/
#define CRYPT_CIPHER_MAX_BLOCK_SIZE 32 /**< Maximum block size */
#define CRYPT_CIPHER_AES_BLOCK_SIZE 16 /**< Block size for AES ciphers */
/** @} */

/**
 * @name Control types
 * @see crypt_CipherCtrl()
 * @{
 */
#define CRYPT_CIPHER_CTRL_SET_PADDING 1 /**< Enable/disable padding */
#define CRYPT_CIPHER_CTRL_GET_PADDING 2 /**< Get padding */
#define CRYPT_CIPHER_CTRL_GET_IV 5      /**< Get pointer to initialization vector*/
#define CRYPT_CIPHER_CTRL_SET_IV 6      /**< Set initialization vector */
/** @} */

struct CRYPT_CIPHER_CTX_ST;

/** @brief Opaque cipher method. */
typedef struct CRYPT_CIPHER_METHOD_S CRYPT_CIPHER_METHOD;

/** @brief Cipher context. */
typedef struct CRYPT_CIPHER_CTX_S
{
    const CRYPT_CIPHER_METHOD *cipher;  /**< The cipher */
    ULONG                      flags;   /**< Internal flags */
    void *                     ctxData; /**< Internal data */
    /** @brief Place to store temporary bytes when cipherUpdate input is not a full block */
    UCHAR cache[CRYPT_CIPHER_MAX_BLOCK_SIZE];
    /** @brief Number of bytes currently stored in cache */
    UINT cachedBytes;
    /** @brief Place to temporarily store the last decrypted block when padding is used */
    UCHAR finalCache[CRYPT_CIPHER_MAX_BLOCK_SIZE];
    /** @brief Number of bytes currently stored in cache */
    UINT finalCachedBytes;
} CRYPT_CIPHER_CTX;

/**
 * @brief Initialize a cipher context.
 *
 * This function initializes a cipher context. After the context has been initialized
 * it can be used to encrypt/decrypt data using the crypt_CipherUpdate() function. The
 * context will by default be setup for PKCS padding. See crypt_CipherCtrl() for how to
 * disable PKCS padding.
 * Note that a context that has been successfully initialized must be freed by calling
 * crypt_CipherCleanup().
 *
 * @param[in] ctx    Pointer to cipher context that will be initialized
 * @param[in] method Method controlling what encryption algorithm to use,
 *                   e.g. the return value of crypt_CipherGetAes128Cbc().
 * @param[in] key    Pointer to the encryption key.
 *                   It is the responsibility of the caller to ensure that the @p key is sufficiently long.
 * @param[in] iv     Initialization vector, required by some algorithms/modes.
 *                   It is the responsibility of the caller to ensure that the @p iv is sufficiently long.
 * @param[in] encr   A non-zero value means that the context will be used for encryption,
 *                   otherwise it will be setup for decryption.
 *
 * @return #OK if the context was successfully initialized, #ERROR if it failed.
 */
STATUS crypt_CipherInit(CRYPT_CIPHER_CTX *ctx, const CRYPT_CIPHER_METHOD *method, const UCHAR *key, const UCHAR *iv,
                        SINT encr);

/**
 * @brief Encrypt or decrypt data.
 *
 * This function encrypts or decrypts data. If data is to be encrypted or decrypted,
 * and what encryption algorithm to use is specified in the initialization of ctx.
 * see crypt_CipherInit.
 * Note that the number of bytes written to out can be both larger or smaller than
 * @p inLen, when PKCS padding is enabled for block ciphers. At most, the output length
 * can differ by one block from the input length.
 * If a block cipher is used without padding, then the input length must be a multiple
 * of the block size.
 *
 * @param[in] ctx        Pointer to cipher context
 * @param[out] out       Pointer to buffer where the output will be stored
 * @param[in,out] outLen Pointer to an integer where the output length will be stored
 * @param[in] in         Pointer to input data
 * @param[in] inLen      Number of input bytes
 *
 * @return #OK if the encryption/decryption was successful, #ERROR otherwise
 */
STATUS crypt_CipherUpdate(CRYPT_CIPHER_CTX *ctx, UCHAR *out, SINT *outLen, const UCHAR *in, SINT inLen);

/**
 * @brief Finalize encryption/decryption.
 *
 * This function finalizes an encryption/decryption operation consisting of a
 * sequence of crypt_CipherInit(), crypt_CipherUpdate(), crypt_CipherUpdate() ..., crypt_CipherFinal().
 * The main reason why this function is needed, is to handle PKCS padding.
 *
 * @param[in] ctx         Pointer to cipher context
 * @param[out] out        Pointer to buffer where the output will be stored
 * @param[in, out] outLen Pointer to an integer where the output length will be stored
 *
 * @return #OK on success, #ERROR otherwise
 */
STATUS crypt_CipherFinal(CRYPT_CIPHER_CTX *ctx, UCHAR *out, SINT *outLen);

/**
 * @brief Perform ioctl-like operations on a #CRYPT_CIPHER_CTX.
 *
 * This function is used to perform ioctl-like operations on a #CRYPT_CIPHER_CTX.
 * The following operations are defined:
 *  - #CRYPT_CIPHER_CTRL_SET_PADDING: enable/disable PKCS padding. @p arg should be of type @p SINT.
 *    0 disables padding, a non-zero value enables padding.
 *  - #CRYPT_CIPHER_CTRL_GET_PADDING: get PKCS padding setting. @p arg should be of type @c SINT*.
 *    The integer will be set to zero if padding is disabled, and one if padding is enabled.
 *  - #CRYPT_CIPHER_CTRL_GET_IV: get a pointer to the initialization vector. @p arg should be of type UCHAR**
 *  - #CRYPT_CIPHER_CTRL_SET_IV: set the initialization vector. @p arg should be of type UCHAR*
 *
 * @param[in] ctx  Pointer to cipher context
 * @param[in] type Type of operation
 * @param[in] arg  Argument
 * @param[in] len  Length of argument
 *
 * @return #OK if the operation was successfully performed, #ERROR otherwise
 */
STATUS crypt_CipherCtrl(CRYPT_CIPHER_CTX *ctx, SINT type, void *arg, UINT *len);

/**
 * @brief Cleanup an initialized context.
 * This function cleans up an initialized context.
 *
 * @param[in] ctx Pointer to cipher context
 *
 * @return #OK if the operation was successfully performed, #ERROR otherwise
 */

STATUS crypt_CipherCleanup(CRYPT_CIPHER_CTX *ctx);

/**
 * @brief Copies a cipher context.
 * This function copies a cipher context. The state, e.g. working IV, is included in the copy.
 *
 * @param[in] dest Pointer to destination context
 * @param[in] src  Pointer to source context
 *
 * @return #OK if the operation was successfully performed, #ERROR otherwise
 */
STATUS crypt_CipherCopy(CRYPT_CIPHER_CTX *dest, const CRYPT_CIPHER_CTX *src);

/**
 * @brief Return the provider of the AES 128 CBC encryption algorithm.
 *
 * This function returns the method for the provider of the AES 128 CBC encryption algorithm.
 * The method is used in a call to crypt_CipherInit() to initialize an encryption/decryption
 * context.
 *
 * @return The method for AES 128 CBC encryption algorithm
 */
const CRYPT_CIPHER_METHOD *crypt_CipherGetAes128Cbc(void);

/**
 * @brief Return the provider of the AES 128 CTR encryption algorithm.
 * This function returns the method for the provider of the AES 128 CTR encryption algorithm.
 * The method is used in a call to crypt_CipherInit() to initialize an encryption/decryption
 * context.
 * @return The method for AES 128 CTR encryption algorithm
 */
const CRYPT_CIPHER_METHOD *crypt_CipherGetAes128Ctr(void);

/**
 * @brief Return the provider of the AES 128 ECB encryption algorithm.
 * This function returns the method for the provider of the AES 128 ECB encryption algorithm.
 * The method is used in a call to crypt_CipherInit() to initialize an encryption/decryption
 * context.
 * @return The method for AES 128 ECB encryption algorithm
 */
const CRYPT_CIPHER_METHOD *crypt_CipherGetAes128Ecb(void);

/**
 * @brief Return the provider of the AES 192 CBC encryption algorithm.
 * This function returns the method for the provider of the AES 192 CBC encryption algorithm.
 * The method is used in a call to crypt_CipherInit() to initialize an encryption/decryption
 * context.
 * @return The method for AES 192 CBC encryption algorithm
 */
const CRYPT_CIPHER_METHOD *crypt_CipherGetAes192Cbc(void);

/**
 * @brief Return the provider of the AES 192 CTR encryption algorithm.
 * This function returns the method for the provider of the AES 192 CTR encryption algorithm.
 * The method is used in a call to crypt_CipherInit() to initialize an encryption/decryption
 * context.
 * @return The method for AES 192 CTR encryption algorithm
 */
const CRYPT_CIPHER_METHOD *crypt_CipherGetAes192Ctr(void);

/**
 * @brief Return the provider of the AES 256 CBC encryption algorithm.
 * This function returns the method for the provider of the AES 256 CBC encryption algorithm.
 * The method is used in a call to crypt_CipherInit() to initialize an encryption/decryption
 * context.
 * @return The method for AES 256 CBC encryption algorithm
 */
const CRYPT_CIPHER_METHOD *crypt_CipherGetAes256Cbc(void);

/**
 * @brief Return the provider of the AES 256 CTR encryption algorithm.
 * This function returns the method for the provider of the AES 256 CTR encryption algorithm.
 * The method is used in a call to crypt_CipherInit() to initialize an encryption/decryption
 * context.
 * @return The method for AES 256 CTR encryption algorithm
 */
const CRYPT_CIPHER_METHOD *crypt_CipherGetAes256Ctr(void);

/**
 * @brief Return the provider of the AES 256 ECB encryption algorithm.
 * This function returns the method for the provider of the AES 256 ECB encryption algorithm.
 * The method is used in a call to crypt_CipherInit() to initialize an encryption/decryption
 * context.
 * @return The method for AES 256 ECB encryption algorithm
 */
const CRYPT_CIPHER_METHOD *crypt_CipherGetAes256Ecb(void);

/**
 * @brief Return the provider of the Blowfish CBC encryption algorithm.
 * This function returns the method for the provider of the Blowfish CBC encryption algorithm.
 * The method is used in a call to crypt_CipherInit() to initialize an encryption/decryption
 * context.
 * @return The method for Blowfish CBC encryption algorithm
 */
const CRYPT_CIPHER_METHOD *crypt_CipherGetBlowfishCbc(void);

/**
 * @brief Get the encryption provider for a given cipher name.
 * Example names:
 *   - AES-128-CBC, AES-128-CTR, AES_128-ECB
 *   - AES-256-CBC, AES-256-CTR, AES-256-ECB
 *   - BLOWFISH-CBC
 * @param[in] name Requested cipher name
 * @return The method for the encryption algorithm or @c NULL if no algorithm for @p name is found.
 */
const CRYPT_CIPHER_METHOD *crypt_CipherGet(const char *name);

/**
 * @brief Print information about supported ciphers to @c stdout.
 * @return #OK for success, #ERROR otherwise
 */
STATUS crypt_ShowCipher(void);

/** @} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _CRYPT_CIPHER_E_H_ */
