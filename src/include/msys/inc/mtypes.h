/**
********************************************************************************
* @file   mtypes.h
* @author diem
* @author faessler
*
* @brief This file contains all possible type definitions, which are used
*        in the M1 system software.
*
* This way of definition has been chosen, in order to support different
* compilers, without any changes of source code. In addition, it makes code
* portable.
*
* Supported platforms:
*  - VxWorks 5.5, VxWorks 7
*  - Windows
*  - Linux
*
* Tested compiler:
*   - GCC VxWorks 2.95
*   - GCC VxWorks 4.1.2
*   - GCC Linux 4.9.2
*   - GCC Cygwin 6.3.0
*   - GCC Mingw32 5.3.0
*   - Visual Studio 6.0, 2010, 2015
*
* Recommendations:
*   - Windows: Include <windows.h> before <mtypes.h>
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2017
*******************************************************************************/

#ifndef MTYPES__H
#define MTYPES__H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Operating system defines
 */

#if defined(__linux__)
#define M_OS "linux"
#define M_OS_LINUX 1
#define M_HAS_STDINT 1

#elif defined(__CYGWIN__)
#define M_OS "cygwin"
#define M_OS_CYGWIN 1
#define M_HAS_STDINT 1

#elif defined(__MINGW32__)
#define M_OS "mingw"
#define M_OS_MINGW 1
#define M_HAS_STDINT 1

#elif defined(__vxworks) || defined(__GNUC__)
#define M_OS "vxworks"
#define M_OS_VXWORKS 1
#define M_HAS_STDINT 0

#endif

/* Data types */

#ifndef M_HAS_STDINT
#if defined(_MSC_VER) && (_MSC_VER >= 1600) /* Visual Studio 2010 */
#define M_HAS_STDINT 1
#else
#define M_HAS_STDINT 0
#endif
#endif

#if M_HAS_STDINT
#include <stdint.h>

typedef uint8_t  UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef uint64_t UINT64;
typedef int8_t   SINT8;
typedef int16_t  SINT16;
typedef int32_t  SINT32;
typedef int64_t  SINT64;
#elif M_OS_VXWORKS
#include <vxWorks.h>

typedef signed char       SINT8;
typedef short             SINT16;
typedef long              SINT32;
typedef long long         SINT64;

  /* Avoid mixing old and new header files (see BeTypes.h) */
#ifndef UINT64_ALREADY_DEFINED
#define UINT64_ALREADY_DEFINED
typedef unsigned long long UINT64;
# endif
#elif defined(_MSC_VER)
typedef unsigned char     UINT8;
typedef unsigned short    UINT16;
/* typedef unsigned long    UINT32; */
typedef unsigned __int64  UINT64;

typedef signed char       SINT8;
typedef short             SINT16;
typedef long              SINT32;
typedef __int64           SINT64;
#else
typedef unsigned __int8   UINT8;
typedef unsigned __int16  UINT16;
typedef unsigned __int32  UINT32;
typedef unsigned __int64  UINT64;

typedef __int8            SINT8;
typedef __int16           SINT16;
typedef __int32           SINT32;
typedef __int64           SINT64;
#endif

#if M_OS_VXWORKS
typedef signed int        SINT;

typedef unsigned char     BOOL8;
typedef unsigned short    BOOL16;
typedef unsigned long     BOOL32;

typedef float             REAL32;
typedef double            REAL64;
#ifdef __cplusplus
typedef char              CHAR;
typedef char              CHAR8;
typedef signed short      CHAR16;
#else
typedef unsigned char     CHAR;
typedef unsigned char     CHAR8;
typedef unsigned short    CHAR16;
# endif
#else
typedef signed int        SINT;
typedef unsigned char     UCHAR;
typedef unsigned short    USHORT;
typedef unsigned int      UINT;
typedef unsigned long     ULONG;

typedef int               BOOL;
typedef UINT8             BOOL8;
typedef UINT16            BOOL16;
typedef UINT32            BOOL32;

typedef float             REAL32;
typedef double            REAL64;

typedef char              CHAR;
typedef char              CHAR8;
typedef short             CHAR16;
#endif

#define VOID void

/* Function pointers */

#if !M_OS_VXWORKS
typedef int     (*FUNCPTR)();         /**< Pointer to function returning int */
typedef void    (*VOIDFUNCPTR)();     /**< Pointer to function returning void */
typedef double  (*DBLFUNCPTR)();      /**< Pointer to function returning double*/
typedef float   (*FLTFUNCPTR)();      /**< Pointer to function returning float */
#endif

typedef UINT    (*UINTFUNCPTR)();
typedef SINT    (*SINTFUNCPTR)();
typedef UINT8   (*UINT8FUNCPTR)();
typedef UINT16  (*UINT16FUNCPTR)();
typedef UINT32  (*UINT32FUNCPTR)();
typedef UINT64  (*UINT64FUNCPTR)();
typedef SINT8   (*SINT8FUNCPTR)();
typedef SINT16  (*SINT16FUNCPTR)();
typedef SINT32  (*SINT32FUNCPTR)();
typedef SINT64  (*SINT64FUNCPTR)();
typedef BOOL8   (*BOOL8FUNCPTR)();
typedef BOOL16  (*BOOL16FUNCPTR)();
typedef BOOL32  (*BOOL32FUNCPTR)();
typedef REAL32  (*REAL32FUNCPTR)();
typedef REAL64  (*REAL64FUNCPTR)();

/* Compiler specific storage classes */

#if defined(__GNUC__) || defined(_MSC_VER)
#define REG             register        /**< Register type variable */
#define MLOCAL          static          /**< Module local variable/function */
#define EXTERN          extern          /**< Imported variable or function */
#define IMPORT          extern          /**< Same as EXTERN */
#define EXPORT                          /**< Exported variable or function */
#define CONST           const           /**< Constant data */
#define VOLATILE        volatile        /**< Volatile data */

#define INTERRUPT                       /**< Function is an ISR */
#define ENUM            enum            /**< Enumeration type */
#define INLINE          inline          /**< Inline function */
#endif

/* Compiler specific attributes */

#ifdef __GNUC__
#define UNUSED __attribute__((unused))  /**< Element might be unused */
#define PACKED __attribute__((packed))  /**< Element shall be packed */
#else
#define UNUSED
#define PACKED
#endif

#if (__GNUC__ >= 3) && !defined(VXWORKS7)
#  define DEPRECATED(func) func __attribute__ ((deprecated))
#else
#  define DEPRECATED(func) func
#endif /* __GNUC__ >= 3 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MTYPES__H */
