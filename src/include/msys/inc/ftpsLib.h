/**
********************************************************************************
* @file     ftpsLib.h
* @author   Dornerm
*
* @brief     FTPS-Library Defines und Funktionen.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef FTPS_LIB__H                     /* Avoid problems with multiple */
#define FTPS_LIB__H                     /* including */

#ifdef __cplusplus
extern  "C"
{
#if 0
}
#endif
#endif

#include <mtypes.h>
#include "sslsocket.h"                  /* SSL-Socket-Funktionen */

/**
 * @name Error codes
 * @{
 */
#define FTPS_PRELIM          1
#define FTPS_COMPLETE        2
#define FTPS_CONTINUE        3
#define FTPS_TRANSIENT       4
#define FTPS_ERROR           5
/** @} */


#define FTPS_DEBUG_OFF       0          /* Debug Meldungen */
#define FTPS_DEBUG_INCOMING  1
#define FTPS_DEBUG_OUTGOING  2
#define FTPS_DEBUG_ERRORS    4


#define FTPS_PORT_MODE       0          /**< FTP Port Mode */
#define FTPS_PASV_MODE       1          /**< FTP Passiv Mode */

#define FTPS_SSL_EXPL        0          /**< Explicit SSL Mode (Port 21) */
#define FTPS_SSL_IMPL        1          /**< Implicit SSL Mode (Port 990) */

EXTERN STATUS ftps_Hookup(VOID ** ctrlCon, UINT8 * host);
EXTERN STATUS ftps_Login(VOID * ctrlCon, UINT8 * user, UINT8 * passwd, UINT8 * account);
EXTERN SINT32 ftps_DataConnInit(VOID * ctrlCon);
EXTERN SINT32 ftps_DataConnInitPassiveMode(VOID * ctrlCon);
EXTERN SINT32 ftps_Command(VOID * ctrlCon, UINT8 * fmt, SINT32 arg1, SINT32 arg2,
                           SINT32 arg3, SINT32 arg4, SINT32 arg5, SINT32 arg6);
EXTERN STATUS ftps_DataConnGet(VOID ** dataCon, SINT32 dataSock);
EXTERN STATUS ftps_DataConnGetPassiveMode(VOID ** dataCon, SINT32 dataSock);
EXTERN SINT32 ftps_ReplyGet(VOID * ctrlCon, BOOL expecteof);
EXTERN STATUS ftps_Xfer(UINT8 * host, UINT8 * user, UINT8 * passwd, UINT8 * acct, UINT8 * cmd,
                        UINT8 * dirname, UINT8 * filename, VOID ** ctrlCon, VOID ** dataCon);
EXTERN VOID ftps_LibDebugOptionsSet(UINT32 debugLevel);


#ifdef __cplusplus
}
#endif

#endif
