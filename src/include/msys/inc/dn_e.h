/**
********************************************************************************
* @file     dn_e.h
* @author   Bertel
*
* @brief This file contains all definitions and declarations exported by
*        the DeviceNet Server for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef DN_E__H
#define DN_E__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mio.h>
#include <dn.h>

/*--- Defines ---*/

// DNM201 Event Interrupt Flags
#define DN_EV_SYSTEM    0x00010000 	// Statuswechsel beim Master (z.B. BusOff)                  
#define DN_EV_SCANNER   0x00020000  // Statuswechsel beim Slave (z.B. auch Heartbeat fails)                 
#define DN_EV_CONFIG    0x00040000  // Anwenderspezifische Konfiguration setzen                 
#define DN_EV_HBEAT     0x00080000  // Heartbeat bei einem Slave ausgefallen                
#define DN_EV_SHDOWN    0x00100000  // Shutdown Message empfangen               
#define DN_EV_ALLEVT    0x001f0000  // Alle moeglichen Events

// DNM201 Error Interrupt Flags
#define DN_E_ALLERR     (MIO_E_WATCHDOG | MIO_E_POWER | MIO_E_EXTERNAL)

/*--- Structures ---*/

/*--- Function Prototypes (dn_lib.c) ---*/

SINT32 dn_Ping(UINT32 NetNb, UINT32 *pRespTime);
SINT32 dn_PutCmd(UINT32 NetNb, UINT16 CmdTag, UINT8 *Data);
SINT32 dn_ExpReq(UINT32 NetNb, DN_REQ *pReq, DN_RESP *pResp, UINT32 Timeout);
SINT32 dn_ExpSet(UINT32 NetNb, UINT32 MacId, UINT32 Class, UINT32 Inst,
                 UINT32 Attr, UINT8 *pData, UINT32 Size, UINT32 Timeout);
SINT32 dn_ExpGet(UINT32 NetNb, UINT32 MacId, UINT32 Class, UINT32 Inst,
                 UINT32 Attr, UINT8 *pData, UINT32 *pSize, UINT32 Timeout);
SINT32 dn_GetState(UINT32 NetNb, UINT32 *pState);
SINT32 dn_SetState(UINT32 NetNb, UINT32 State);
SINT32 dn_GetNodeState(UINT32 NetNb, UINT32 MacId, UINT32 *pState);

/*--- Definition of Variables ---*/

#ifdef __cplusplus
}
#endif

#endif
