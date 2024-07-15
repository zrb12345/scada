/**
 ********************************************************************************
 * @file     crypt_hash_e.h
 * @author   faessler
 *
 * @brief This file is a wrapper for the VxWorks 7 hash functions.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
 *******************************************************************************/

#ifndef _CRYPT_HASH_E_H_
#define _CRYPT_HASH_E_H_

#include <vxWorks.h>
#include <mtypes.h>

/**
 * @addtogroup SYS-CRYPT-HASH
 * @brief Cryptographic hash functions.
 *  - MD5
 *  - RIPEMD160
 *  - SHA1
 *  - SHA256
 *  - SHA385
 *  - SHA512
 *  - WHIRLPOOL
 *
 * Use crypt_HashInit(), crypt_HashUpdate(), crypt_HashFinal(), and crypt_HashCleanup() if the memory you need to hash
 * is divided into two or more segments. Note that each call to crypt_HashInit() must be matched by a
 * call to crypt_HashCleanup().
 *
 * A normal call sequence would be:
 * @code{.c}
 * CRYPT_HASH_CTX ctx;
 * UCHAR  digest[CRYPT_HASH_DIGEST_LEN_MAX];
 * SINT   digestLen = sizeof(digest);
 *
 * if (crypt_HashInit(&ctx, crypt_HashGetSha256()) == OK)
 * {
 *   crypt_HashUpdate(&ctx, data1, len1);
 *   crypt_HashUpdate(&ctx, data2, len2);
 *   crypt_HashUpdate(&ctx, data3, len3);
 *   crypt_HashFinal(&ctx, digest, &digestLen);
 *   crypt_HashCleanup(&ctx);
 * }
 * @endcode
 *
 * @see cryptHash.h
 * @since MBase 4.11 (VxWorks 7)
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name Definitions
 * @{
 */
#define CRYPT_HASH_SIZE_MD5 16       /**< MD5 digest size */
#define CRYPT_HASH_SIZE_RMD 20       /**< RIPEMD160 digest size */
#define CRYPT_HASH_SIZE_SHA1 20      /**< SHA1 digest size */
#define CRYPT_HASH_SIZE_SHA256 32    /**< SHA256 digest size */
#define CRYPT_HASH_SIZE_SHA384 48    /**< SHA384 digest size */
#define CRYPT_HASH_SIZE_SHA512 64    /**< SHA512 digest size */
#define CRYPT_HASH_SIZE_WHIRLPOOL 64 /**< WHIRLPOOL digest size */
#define CRYPT_HASH_SIZE_MAX 64       /**< Max digest size */
/** @} */

/** @brief Opaque hash method.*/
typedef struct CRYPT_HASH_METHOD_S CRYPT_HASH_METHOD;

/** @brief Hash context.*/
typedef struct CRYPT_HASH_CTX_S
{
    const CRYPT_HASH_METHOD *hash;  /**< Hash method */
    ULONG                    flags; /**< Internal flags */
    char *                   data;  /**< Internal data */
} CRYPT_HASH_CTX;

/**
 *
 * secHash - Calculate a hash digest
 *
 * This function can only be used if the data to hash is in one continuous buffer.
 * crypt_HashInit(), crypt_HashUpdate(), crypt_HashFinal() and crypt_HashCleanup() must be used if
 * the data to hash is stored in two or more buffers.
 *
 * @param[in] data          Pointer to the data that the will be included in the hash calculation
 * @param[in] len           Number of bytes to include in the hash calculation
 * @param[out] digest       Pointer to the buffer where the digest (or hash) data will be written
 * @param[in,out] digestLen Length of the digest output buffer. The number of bytes  placed into @p digest
 *                          is set on success.
 * @param[in] method        Controls the hash algorithm to use, e.g. use the return value of crypt_HashGetSha1().
 *
 * @return #OK if the hash was successfully calculated, #ERROR otherwise.
 */

STATUS crypt_Hash(const void *data, UINT len, UCHAR *digest, UINT *digestLen, const CRYPT_HASH_METHOD *method);

/**
 * @brief Initialize a hash context.
 *
 * This routine initializes a hash context. The hash algorithm to use is specified
 * by the method argument. For instance, in order to use SHA1, the return value of
 * crypt_HashGetSha1() should be used. Note that every successful
 * call to crypt_HashInit() must be matched with a call to crypt_HashCleanup().
 *
 * Once the hash context has been setup, call crypt_HashUpdate() to add data to the
 * hash calculation. Once all data has been added, call crypt_HashFinal() to get
 * the resulting hash value. And finally call crypt_HashCleanup() in order to free
 * any resources that has been allocated during the hash calculation.
 *
 * @param[in] ctx    Context to initialize
 * @param[in] method Hash method to use
 *
 * @retval #OK if the initialization is successful.
 * @retval #ERROR if the hash context could not be initialized.
 */
STATUS crypt_HashInit(CRYPT_HASH_CTX *ctx, const CRYPT_HASH_METHOD *method);

/**
 * @brief Add data to a hash calculation.
 *
 * This function adds data to a hash calculation. It can be called multiple times
 * in order to add several memory segments to the calculation
 *
 * @param[in] ctx   Hash context
 * @param[in] data  Array of bytes
 * @param[in] count Number of bytes
 *
 * @return #OK is the data was successfully added, #ERROR otherwise.
 */
STATUS crypt_HashUpdate(CRYPT_HASH_CTX *ctx, const void *data, UINT count);

/**
 * @brief Finalize a hash calculation.
 * Completes the hash computation by performing final operations such as padding.
 *
 * @param[in] ctx           Hash context
 * @param[out] digest       Output buffer to store the digest
 * @param[in,out] digestLen Length of the digest output buffer. The number of bytes placed into @p digest
 *                          is set on success.
 *
 * @return #OK if the hash value was successfully written to @p digest, #ERROR otherwise.
 */
STATUS crypt_HashFinal(CRYPT_HASH_CTX *ctx, UCHAR *digest, UINT *digestLen);

/**
 * @brief Copy a hash context
 *
 * This function makes a copy of a hash context. The hash context state is copied
 * too. This means that if data is added to a hash context by calling crypt_HashUpdate()
 * this data will be included in the hash calculation of the hash context copy too.
 * Note that crypt_HashCleanup() must be called on the copy too.
 *
 * @param[in] dest The destination context
 * @param[in] src  The source context
 *
 * @return #OK if the context was successfully copied, #ERROR otherwise.
 */
STATUS crypt_HashCopy(CRYPT_HASH_CTX *dest, const CRYPT_HASH_CTX *src);

/**
 * @brief Cleans up a hash context
 * This function frees up any resources tied to the hash context.
 * @param[in] ctx Hash context
 */
void crypt_HashCleanup(CRYPT_HASH_CTX *ctx);

/**
 * @brief Get MD5 hash.
 * @return pointer to hash method or @c NULL if not available
 */
const CRYPT_HASH_METHOD *crypt_HashGetMd5(void);

/**
 * @brief Get RIPEMD160 hash.
 * @return pointer to hash method or @c NULL if not available
 */
const CRYPT_HASH_METHOD *crypt_HashGetRmd(void);

/**
 * @brief Get SHA1 hash.
 * @return pointer to hash method or @c NULL if not available
 */
const CRYPT_HASH_METHOD *crypt_HashGetSha1(void);

/**
 * @brief Get SHA256 hash.
 * @return pointer to hash method or @c NULL if not available
 */
const CRYPT_HASH_METHOD *crypt_HashGetSha256(void);

/**
 * @brief Get SHA384 hash.
 * @return pointer to hash method or @c NULL if not available
 */
const CRYPT_HASH_METHOD *crypt_HashGetSha384(void);

/**
 * @brief Get SHA512 hash.
 * @return pointer to hash method or @c NULL if not available
 */
const CRYPT_HASH_METHOD *crypt_HashGetSha512(void);

/**
 * @brief Get WHIRLPOOL hash.
 * @return pointer to hash method or @c NULL if not available
 */
const CRYPT_HASH_METHOD *crypt_HashGetWhirlpool(void);

/**
 * @brief Get hash method by name.
 * Example names
 *   - MD5
 *   - RMD, RIPEMD160
 *   - SHA1" SHA256, SHA384, SHA512
 *   - WHIRLPOOL
 * @param[in] name Requested hash name
 * @return pointer to hash method or @c NULL if not available
 */
const CRYPT_HASH_METHOD *crypt_HashGet(const char *name);

/**
 * @brief Get digest size in bytes.
 * @param[in] method Hash method
 * @return digest length in bytes or 0 if @p method not valid
 */
SINT crypt_HashSize(const CRYPT_HASH_METHOD *method);

/**
 * @brief Get message block size in bytes.
 * @param[in] method Hash method
 * @return message block size in bytes or 0 if @p method not valid
 */
SINT crypt_HashBlockSize(const CRYPT_HASH_METHOD *method);

/**
 * @brief Print information about supported hash functions to @c stdout.
 * @return #OK for success, #ERROR otherwise
 */
STATUS crypt_ShowHash(void);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _CRYPT_HASH_E_H_ */
