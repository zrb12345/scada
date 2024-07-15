/**
 ********************************************************************************
 * @file     crypt_tcvol_e.h
 * @author   faessler
 *
 * @brief This file contains all functions to create, mount and unmount
 *        encrypted volumes (TrueCrypt).
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
 *******************************************************************************/

#ifndef _CRYPT_TCVOL_E_H_
#define _CRYPT_TCVOL_E_H_

#include <vxWorks.h>
#include <mtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup SYS-CRYPT-TCVOL
 * @brief TrueCrypt volumes.
 *
 * TrueCrypt encrypted container files can be be mounted/unmounted via supplied functions:
 *  - crypt_TcVolMount()
 *  - crypt_TcVolUnmount()
 *
 * Encrypted container files can be created using crypt_TcVolCreate() for an existing file.
 *
 * @see cryptTcVol.h
 * @since MBase 4.11 (VxWorks 7)
 * @{
 */

/**
 * @brief Mount an encrypted volume image.
 * This routine mounts an encrypt volume image with specific password.
 *
 * @param[in] mountPoint The mount point (example "/crypt0")
 * @param[in] imageName  File path to encrypted volume image (example "/cfc0/crypt0.tc")
 * @param[in] password   The encryption password
 *
 * @return #OK for success, #ERROR otherwise
 */
STATUS crypt_TcVolMount(const char *mountPoint, const char *imageName, const char *password);

/**
 * @brief Unmount an encrypted volume image.
 * This routine unmounts an encrypt volume image for a specific mount point.
 *
 * @param[in] mountPoint The mount point (e.g. "/crypt0")
 *
 * @return #OK for success, #ERROR otherwise
 */
STATUS crypt_TcVolUnmount(const char *mountPoint);

/**
 * @brief Create an encrypt volume image (TrueCrypt header).
 * This routine creates the TrueCrypt header for a given file to be used as encrypted volume.
 *
 * Supported hash algorithms:
 *  - SHA-512
 *  - RIPEMD-160
 *  - WHIRLPOOL
 *
 * Supported cipher:
 *  - AES-256-XTS
 *
 * @param[in] imageName File path where to create the volume file (e.g. "/cfc0/crypt01.tc")
 * @param[in] hash      Hash algorithm to use (example "SHA-512")
 * @param[in] cipher    Encryption algorithm to use (example "AES-256-XTS")
 * @param[in] password  The encryption password
 * @return #OK for success, #ERROR otherwise
 */
STATUS crypt_TcVolCreate(const char *imageName, const char *hash, const char *cipher, const char *password);

/**
 * @brief Show volume information (stdout).
 * This routine shows volume information, e.g. encrypt method name, volume size ...
 *
 * @param[in] mountPoint The mount point (example "/crypt0")
 * @return #OK for success, #ERROR otherwise
 */
STATUS crypt_ShowTcVol(const char *mountPoint);

/**
 * @brief Determine if encrypted volume exists and is mounted.
 *
 * @param[in] mountPoint The mount point (example "/crypt0")
 * @return #OK if volume is mounted, #ERROR otherwise
 */
STATUS crypt_TcVolCheck(const char *mountPoint);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _H_CRYPT_TCVOL_H_ */
