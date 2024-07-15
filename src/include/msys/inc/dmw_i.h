/**
********************************************************************************
* @file     dmw_i.h
* @author   
*
* @brief This file contains the Inline functions which allow special access to
*        mio_DoCmd's of the the Drive Middleware.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef DMW_I__H           /* Avoid problems in case of multiple includes */
#define DMW_I__H           /* Avoid problems in case of multiple includes */

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>
#include <mio_e.h>
#include <dmw.h>

/*--- Defines ---*/

#define DMW_CMD_RDACTVAL    1   // Istwert Datansatz lesen  
#define DMW_CMD_WRSETVAL    2   // Sollwert Datensatz schreiben
#define DMW_CMD_RDSETVAL    3   // Sollwert Datensatz schreiben
#define DMW_CMD_RDPARM      4   // Einzelner Parameter lesen
#define DMW_CMD_WRPARM      5   // Einzelner Parameter schreiben
#define DMW_CMD_GETPARMNAME 6   // Parameter-Name aus Nummer ermitteln
#define DMW_CMD_GETPARMNR   7   // Parameter-Nummer aus Name ermitteln

/*--- Structures ---*/

typedef enum DMW_CMDMODE        // Moegliche Funktionsabarbeitungs-Modi
{
    DMW_CMD_WAIT = 0,           // Blockierender Aufruf 
    DMW_CMD_POLL = 1,           // Nichtblockierender Aufruf, Result polling  
    DMW_CMD_CBF  = 2,           // Nichtblockierender Aufruf, Callback-Funktion
} DMW_CMDMODE;

/*--- Inline function for of mio_DoCmd's ---*/

MLOCAL INLINE SINT32 mio_RdActVal(MIO_DRV *DrvId, DMW_ACTVAL *pActVal)
{  
    return (mio_DoCmd(DrvId, 0, DMW_CMD_RDACTVAL, pActVal));
}

MLOCAL INLINE SINT32 mio_WrSetVal(MIO_DRV *DrvId, DMW_SETVAL *pSetVal)
{  
    return (mio_DoCmd(DrvId, 0, DMW_CMD_WRSETVAL, pSetVal));
}

MLOCAL INLINE SINT32 mio_RdSetVal(MIO_DRV *DrvId, DMW_SETVAL *pSetVal)
{  
    return (mio_DoCmd(DrvId, 0, DMW_CMD_RDSETVAL, pSetVal));
}

MLOCAL INLINE SINT32 mio_RdParmVal(MIO_DRV *DrvId, UINT32 Parm, UINT32 *pVal)
{
    UINT32 Len = 4;
    return (mio_DoCmd(DrvId, Parm, DMW_CMD_RDPARM, pVal, &Len, DMW_CMD_WAIT));
}

MLOCAL INLINE SINT32 mio_WrParmVal(MIO_DRV *DrvId, UINT32 Parm, UINT32 Val)
{
    return (mio_DoCmd(DrvId, Parm, DMW_CMD_WRPARM, &Val, 4, DMW_CMD_WAIT));
}

MLOCAL INLINE SINT32 mio_RdParm(MIO_DRV *DrvId, UINT32 Parm, VOID *pData, UINT32 *pLen)
{
    return (mio_DoCmd(DrvId, Parm, DMW_CMD_RDPARM, pData, pLen, DMW_CMD_WAIT));
}

MLOCAL INLINE SINT32 mio_RdParmPoll(MIO_DRV *DrvId, UINT32 Parm, VOID *pData, UINT32 *pLen, SINT32 *pResult)
{
    return (mio_DoCmd(DrvId, Parm, DMW_CMD_RDPARM, pData, pLen, DMW_CMD_POLL, pResult));
}

MLOCAL INLINE SINT32 mio_RdParmCbf(MIO_DRV *DrvId, UINT32 Parm, VOID *pData, UINT32 *pLen, VOID (*AppCbf)(UINT32 UsrPar, SINT32 Result), UINT32 UsrPar)
{
    return (mio_DoCmd(DrvId, Parm, DMW_CMD_RDPARM, pData, pLen, DMW_CMD_CBF, AppCbf, UsrPar));
}

MLOCAL INLINE SINT32 mio_WrParm(MIO_DRV *DrvId, UINT32 Parm, VOID *pData, UINT32 Len)
{
    return (mio_DoCmd(DrvId, Parm, DMW_CMD_WRPARM, pData, Len, DMW_CMD_WAIT));
}

MLOCAL INLINE SINT32 mio_WrParmPoll(MIO_DRV *DrvId, UINT32 Parm, VOID *pData, UINT32 Len, SINT32 *pResult)
{
    return (mio_DoCmd(DrvId, Parm, DMW_CMD_WRPARM, pData, Len, DMW_CMD_POLL, pResult));
}

MLOCAL INLINE SINT32 mio_WrParmCbf(MIO_DRV *DrvId, UINT32 Parm, VOID *pData, UINT32 Len, VOID (*AppCbf)(UINT32 UsrPar, SINT32 Result), UINT32 UsrPar)
{
    return (mio_DoCmd(DrvId, Parm, DMW_CMD_WRPARM, pData, Len, DMW_CMD_CBF, AppCbf, UsrPar));
}

MLOCAL INLINE SINT32 mio_GetParmName(MIO_DRV *DrvId, UINT32 Parm, CHAR *Name)
{
    return (mio_DoCmd(DrvId, Parm, DMW_CMD_GETPARMNAME, Name));
}

MLOCAL INLINE SINT32 mio_GetParmNr(MIO_DRV *DrvId, CHAR *Name, UINT32 *pParNr)
{
    return (mio_DoCmd(DrvId, 0, DMW_CMD_GETPARMNR, Name, pParNr));
}

#ifdef __cplusplus
}
#endif

#endif // DMW_I__H
