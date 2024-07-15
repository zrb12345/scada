/**
********************************************************************************
* @file     sslsocket.h
* @author   Dorner
*
* @brief This file contains the SSL library definitions.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2013
*******************************************************************************/

#ifndef SSLSOCKET_H__
#define SSLSOCKET_H__

#ifdef __cplusplus
extern  "C"
{
#if 0
}
#endif
#endif

#include "mtypes.h"

#define SSLSOCKET_EOF           0x1
#define SSLSOCKET_CLOSE_NOTIFY  0x2

/**
 * @name SSL function library (index)
 * @{
 */
#define SSL_F_INIT          0
#define SSL_F_DEINIT        1
#define SSL_F_ACCEPT        2
#define SSL_F_CONNECT       3
#define SSL_F_READ          4
#define SSL_F_WRITE         5
#define SSL_F_CLOSE         6
#define SSL_F_FIONREAD      7
#define SSL_F_NB            8
/** @} */

#define SSL_BADCOMMAND    -10

SINT32  ssl_Init(SINT32(*(ssl_LibFct[SSL_F_NB])) ());
SINT32  ssl_Deinit(void);
CHAR   *ssl_GetVersion(void);

SINT32  ssl_Accept(void **sslConn, SINT32 fd);
SINT32  ssl_Connect(void **sslConn, SINT32 fd);
SINT32  ssl_Read(void *sslConn, UINT8 * buf, SINT32 len, SINT32 * status);
SINT32  ssl_ReadWithTimeout(void *sslConn, UINT8 * buf, SINT32 len, SINT32 * status,
                            SINT32 Timeout);
SINT32  ssl_Write(void *sslConn, UINT8 * buf, SINT32 len, SINT32 * status);
SINT32  ssl_Close(void *sslConn);
SINT32  ssl_Fionread(void *sslConn);

/**
 * @name Functions for key handling
 * @since SSL V1.10
 */
SINT32  ssl_ReloadSrvKeys(CHAR * keyFile, CHAR * certFile, CHAR * CAFiles);
SINT32  ssl_ReloadSrvKeysMem(CHAR * keyBuf, UINT32 keyLen,
                             CHAR * certBuf, UINT32 certLen, CHAR * CAFilesBuf, UINT32 CAFilesLen);
SINT32  ssl_ReloadCltKeys(CHAR * keyFile, CHAR * certFile, CHAR * CAFiles);
SINT32  ssl_ReloadCltKeysMem(CHAR * keyBuf, UINT32 keyLen,
                             CHAR * certBuf, UINT32 certLen, CHAR * CAFilesBuf, UINT32 CAFilesLen);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* SSLSOCKET_H__ */
