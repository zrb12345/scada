/**
********************************************************************************
* @file     scep_e.h
* @author   dorner
*
* @brief    SCEP (Simple Certificate Enrollment Protocol) declarations.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2017
*******************************************************************************/

#ifndef __SCEP_E_H__                            /* Avoid multiple inclusion */
#define __SCEP_E_H__

#ifdef __cplusplus
extern  "C"
{
#endif

#include <mtypes.h>

/**
 * @addtogroup SYS-SCEP-DEF
 * @{
 */

/*--- Defines ---*/

/**
 * @anchor SYS_SCEP_ER_
 */
#define SYS_SCEP_ER_OK                           0   /**< Ok */
#define SYS_SCEP_ER_FAILED                      -1   /**< Failed */
#define SYS_SCEP_ER_INVALID_ARG                 -2   /**< Invalid arguments */
#define SYS_SCEP_ER_TIMEOUT                     -3   /**< Timeout */
#define SYS_SCEP_ER_NO_MEMORY                   -4   /**< No memory */
#define SYS_SCEP_ER_SERVER_UNAVAILABLE          -5   /**< Server unavailable */
#define SYS_SCEP_ER_WRONG_URL                   -6   /**< Wrong URL */
#define SYS_SCEP_ER_WRONG_DN                    -7   /**< Wrong DN */
#define SYS_SCEP_ER_WRONG_SAN                   -8   /**< Wrong SAN */
#define SYS_SCEP_ER_WRONG_KEY                   -9   /**< Wrong key */
#define SYS_SCEP_ER_HTTP_SERVER_ERROR           -10  /**< HTTP server error */
#define SYS_SCEP_ER_REQ_FAILURE_PENDING         -11  /**< Request failure pending */
#define SYS_SCEP_ER_REQ_FAILURE_BAD_ALGH        -12  /**< Request failure bad algh */
#define SYS_SCEP_ER_REQ_FAILURE_BAD_MSG_CHECK   -13  /**< Request failure bad msg check */
#define SYS_SCEP_ER_REQ_FAILURE_BAD_REQUEST     -14  /**< Request failure bad request */
#define SYS_SCEP_ER_REQ_FAILURE_BAD_TIME        -15  /**< Request failure bad time */
#define SYS_SCEP_ER_REQ_FAILURE_BAD_CERT_ID     -16  /**< Request failure bad cert id */
#define SYS_SCEP_ER_TLS_CONNECT                 -17  /**< TLS connect error */
#define SYS_SCEP_ER_DISABLED                    -18  /**< SCEP disabled */
/** @} */

/** @} end of SYS-SCEP-DEF */

/**
 * @addtogroup SYS-SCEP-API
 * @{
 */

/**
 * @brief This function sets SCEP options.
 *
 * @param[in] UseSsl           Use secure connection to the SCEP server
 * @param[in] AcceptSelfSigned Accept self signed CA certificates
 * @param[in] FinterprintSHA1  Use legacy fingerprint algorithm SHA-1 (instead of SHA-256)
 * @param[in] Reserved         0 (not used yet)
 *
 * @retval #SYS_SCEP_ER_OK     OK
 * @retval other               Error (@ref SYS_SCEP_ER_ "Possible return codes from SCEP functions)
 *
 * @since MBase 4.20 (VxWorks 7)
 */
SINT32 sys_scep_SetOptions(BOOL8 UseSsl, BOOL8 AcceptSelfSigned, BOOL8 FinterprintSHA1, UINT32 Reserved);

/**
 * @brief This function sets the challenge password in the vault store.
 *
 * @note A previous password is overwritten.
 *
 * @note The key id is 'ScepPassword'.
 *
 * @param[in] pPassword        Challenge password (NULL deletes an existing password)
 *
 * @retval #SYS_SCEP_ER_OK     OK
 * @retval other               Error (@ref SYS_SCEP_ER_ "Possible return codes from SCEP functions)
 *
 * @since MBase 4.20 (VxWorks 7)
 */
SINT32 sys_scep_SetPassword(char *pPassword);

/**
 * @brief This function starts the renew of the certificate.
 *
 * @note This function only works when SCEP is configured!
 *
 * @param[in]  ForceGetCert    Get certificate with challenge (do not use previous certificate)
 *
 * @retval #SYS_SCEP_ER_OK     OK
 * @retval other               Error (@ref SYS_SCEP_ER_ "Possible return codes from SCEP functions)
 *
 * @since MBase 4.20 (VxWorks 7)
 */
SINT32 sys_scep_StartRenew(BOOL8 ForceGetCert);

/**
 * @brief This function generates a RSA key.
 *
 * @note The key data must be freed with free()!
 *
 * @param[in] KeySize          Key size
 * @param[in] pKeyData         Pointer to pointer where to write RSA key in DER format
 * @param[in] pKeyLen          Pointer to length of RSA key
 *
 * @retval #SYS_SCEP_ER_OK     OK
 * @retval other               Error (@ref SYS_SCEP_ER_ "Possible return codes from SCEP functions)
 *
 * @since MBase 4.20 (VxWorks 7)
 */
SINT32 sys_scep_RsaGenerateKey(SINT32 KeySize, UINT8 **pKeyData, SINT32 *pKeyLen);

/**
 * @brief This function requests the CA certificate(s) from the SCEP server.
 *
 * @param[in] pServerName      Server host name or ip address
 * @param[in] pServerURL       Server http script path
 * @param[in] pFingerprint     CA certificate fingerprint (NULL for no check)
 * @param[in] pCACertFile      File to write certificate to
 * @param[in] Retries          Number of retries for the case the server does not respond
 * @param[in] Interval         Interval between retries in seconds
 *
 * @retval #SYS_SCEP_ER_OK     OK
 * @retval other               Error (@ref SYS_SCEP_ER_ "Possible return codes from SCEP functions)
 *
 * @since MBase 4.20 (VxWorks 7)
 */
SINT32 sys_scep_GetCaCert(char *pServerName, char *pServerURL, UINT8 *pFingerprint,
                          char *pCACertFile, SINT32 Retries, SINT32 Interval);

/**
 * @brief This function requests a certificate from the SCEP server.
 *
 * @note Use this function for the initial certificate request.
 *
 * @param[in] pServerName      Server host name or ip address
 * @param[in] pServerURL       Server http script path
 * @param[in] pDN              Distinguished name in the format /type0=value0/type1=value1/type2=...
 * @param[in] pSAN             Subject alternative name in the format type0:value0,type1:value1,type2:...
 *                             (NULL for no subject alternative name)
 * @param[in] pCACertFile      CA/RA certificate file
 * @param[in] pKeyData         Key data in DER format
 * @param[in] KeyLen           Length of key data
 * @param[in] pCertFile        File to write certificate to
 * @param[in] pChallenge       Challenge password (NULL for no challenge)
 * @param[in] Retries          Number of retries for the case the server does not respond
 * @param[in] Interval         Interval between retries in seconds
 *
 * @retval #SYS_SCEP_ER_OK     OK
 * @retval other               Error (@ref SYS_SCEP_ER_ "Possible return codes from SCEP functions)
 *
 * @see sys_scep_RsaGenerateKey()
 *
 * @since MBase 4.20 (VxWorks 7)
 */
SINT32 sys_scep_GetCert(char *pServerName, char *pServerURL, char *pDN, char *pSAN,
                        char *pCACertFile, char *pChallenge,
                        UINT8 *pKeyData, SINT32 KeyLen, char *pCertFile,
                        SINT32 Retries, SINT32 Interval);

/**
 * @brief This function requests a new certificate from the SCEP server.
 *
 * @note Use this function for all further certificate request.
 *
 * @param[in] pServerName      Server host name or ip address
 * @param[in] pServerURL       Server http script path
 * @param[in] pDN              Distinguished name in the format /type0=value0/type1=value1/type2=...
 * @param[in] pSAN             Subject alternative name in the format type0:value0,type1:value1,type2:...
 *                             (NULL for no subject alternative name)
 * @param[in] pCACertFile      CA/RA certificate file
 * @param[in] pKeyData         Key data in DER format
 * @param[in] KeyLen           Length of key data
 * @param[in] pCertFile        File to write certificate to
 * @param[in] pSignerCertFile  Signer certificate file
 * @param[in] pSignerKeyData   Signer key data in DER format
 * @param[in] pSignerKeyLen    Length of the signer key data
 * @param[in] Retries          Number of retries for the case the server does not respond
 * @param[in] Interval         Interval between retries in seconds
 *
 * @retval #SYS_SCEP_ER_OK     OK
 * @retval other               Error (@ref SYS_SCEP_ER_ "Possible return codes from SCEP functions)
 *
 * @see sys_scep_RsaGenerateKey()
 *
 * @since MBase 4.20 (VxWorks 7)
 */
SINT32 sys_scep_RenewCert(char *pServerName, char *pServerURL, char *pDN, char *pSAN,
                          char *pCACertFile, UINT8 *pKeyData, SINT32 KeyLen, char *pCertFile,
                          char *pSignerCertFile, UINT8 *pSignerKeyData, SINT32 pSignerKeyLen,
                          SINT32 Retries, SINT32 Interval);

/** @} end of SYS-SCEP-API */

#ifdef __cplusplus
}
#endif

#endif  /* __SCEP_E_H__ */
