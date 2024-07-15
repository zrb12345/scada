/*---------------------------------------------------------------------------
* Modul: Wireshark Sniffer specific defines/prototypes
* Rev:  $Author: MAAB $ $Date: 14.07.14 8:55 $
*----------------------------------------------------------------------------
*
* Desc: Header file for Wireshark sniffer functionality.
*       
*----------------------------------------------------------------------------
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2014
*---------------------------------------------------------------------------*/

#ifndef IFCAPTURE__H
#define IFCAPTURE__H

#ifdef __cplusplus
extern "C" {
#endif

/*--- Defines ---*/

#define MAX_CAPTURE_IFS 3


/*--- Function prototypes ---*/

extern SINT32 sys_CaptureStart(const char *ifName, int ifUnit, int traceBufferInByte, const char *filename);
extern SINT32 sys_CaptureStop(const char *ifName, int ifUnit);
extern SINT32 sys_ExportCaptureToFile(const char *ifName, int ifUnit, const char *filename);

#ifdef __cplusplus
}
#endif

#endif  /* IFCAPTURE__H */
