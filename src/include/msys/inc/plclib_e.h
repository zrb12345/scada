/**
********************************************************************************
* @file     plclib_e.h
* @author   dasc
*
* @brief This file contains all definitions and declarations exported by the 
*        PLC-RTS which are needed by external-libraries for use by modules 
*        running on the same CPU. 
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2013
*******************************************************************************/

#ifndef PLC_LIB_PUBLIC_H_
#define PLC_LIB_PUBLIC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <msys.h>
#include <mtypes.h>

/*--- Defines ---*/

/**
 * @name Possible Hook Types
 * @see plc_HookAdd()
 * @see plc_HookAddExt()
 * @{
 */
#define HOOK_AFTER_SVIREINIT            0x01    /**< Attached function is called after svi-reinit. Add with plc_HookAdd */
#define HOOK_AFTER_SVIINIT              0x02    /**< Attached function is called after svi-init. Add with plc_HookAddExt */
#define HOOK_STATE_TRANSITION_EOI_RUN   0x03    /**< Attached function is called at SMI_PROC_ENDOFINIT before LZS_START. Add with plc_HookAddExt */
/** @} */

/**
 * Version of PLC_EXTLIBCONFIG
 */
#define PLC_VER_EXTLIBCONFIG_V1    1   // MSYS 3.90 R

/**
 * plc-project handle
 */
#ifndef PLCPROJ
typedef VOID PLCPROJ;
#endif

/*
 * external memory free-function
 */
typedef SINT32 (*PLCFREEFN)(PLCPROJ *proj, BOOL32 bSysPart, VOID *vpMem);

/*--- Structures ---*/

/**
 * Structures for xx_PlcDllPrepareEx(...)
 */
typedef struct {
    UINT8       Name[M_MODNAMELEN_A];   // library-name
    UINT32      version;                // library-version
} PLC_LIBINFO;

typedef struct {
    UINT32 VersionStruct;               // version of this structure
    UINT32 LibHandle;                   // library-handle
    UINT32 BufferSize;                  // function return buffer-size
    UINT32 Spare[3];                    // reserved
} PLC_EXTLIBCONFIG;

/*--- External Library Function Prototypes ---*/
EXTERN PLCPROJ *libplc_GetProjectSelf(VOID);
CHAR *libplc_GetProjectName(PLCPROJ *pProject);
EXTERN VOID **libplc_GetProjMem(PLCPROJ *pProject, UINT32 LibHandle);
EXTERN VOID *libplc_memAlloc(UINT32 MemSize, BOOL32 bSysPart, PLCPROJ *pProject, PLCFREEFN pfnDestructor);
EXTERN SINT32 libplc_memFree(VOID *pMemory);
EXTERN UINT8 *libplc_GetStringBuffer(PLCPROJ *project);
EXTERN CHAR *libplc_GetInstanceName(PLCPROJ *pProject, UINT8 *pInst);

/**
 * @brief With this function you can register a HOOK_AFTER_SVIINIT hook.
 *
 * @param[in]  pProject     Pointer to plc-project
 * @param[in]  Type         Type of Hook. With this function you can only register
 *                          the HOOK_AFTER_SVIREINIT type.
 * @param[in]  pFunc        Function pointer to your user function.
 * @param[in]  arg          Argument passed to your user function.
 *
 * @return #OK for success, or <tt>< 0</tt> in case of an error
 * @retval #ERROR You cannot register this type of hook with this function.
 *
 * @see #plc_HookAddExt()
 */
extern SINT32 plc_HookAdd(void *pProject, UINT32 Type, VOIDFUNCPTR pFunc, UINT32 arg);

/**
 * @brief With this function you can register a hook with return value.
 *
 * @param[in]  pProject     Pointer to plc-project
 * @param[in]  Type         Type of Hook. With this function you can register all types
 *                          of hooks except the HOOK_AFTER_SVIREINIT type.
 * @param[in]  UserFunc     Function pointer with return value to your user function.
 * @param[in]  arg          Argument passed to your user function.
 *
 * @return #OK for success, or <tt>< 0</tt> in case of an error
 * @retval #ERROR You cannot register this type of hook with this function.
 *
 * @see #plc_HookAdd()
 */
extern SINT32 plc_HookAddExt(void *pProject, UINT32 Type, SINT32(*UserFunc) (void *pProject, UINT32 arg), UINT32 arg);

#ifdef __cplusplus
}
#endif

#endif /* PLC_LIB_PUBLIC_H_ */
