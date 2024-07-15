/**
********************************************************************************
* @file     str_e.h
* @author   Diem
*
* @brief This file contains all definitions and declarations exported by
*        the String Library for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef STR__H
#define STR__H

#ifdef __cplusplus
extern  "C"
{
#endif

#include <mtypes.h>

/**
 * @addtogroup STR-DEF
 * @{
 */

/**
 * @name Possible types for string conversion
 * @see str_ToNumber()
 * @{
 */
#define STR_UINT32	1                   /**< Unsigned integer type */
#define STR_SINT32	2                   /**< Signed integer type */
#define STR_REAL32	3                   /**< Floating point type */
/** @} */


/*--- Structures ---*/

/**
 * Helper structure for string conversion
 * @see str_ToNumber()
 */
typedef union
{
    UINT32  UInt;                       /**< Unsigned integer type */
    SINT32  SInt;                       /**< Signed integer type */
    REAL32  Flt;                        /**< Floating point type */
} STR_NUMBER;
/** @} */

/**
 * @addtogroup STR-API
 * @{
 */

/*--- Function Prototypes ---*/

/**
 * @brief This function converts the characters of a string into capital letters.
 *
 * @note The string must end with \0.
 *
 * @param[in,out]  pText   String which is to be converted into capital letters.
 *
 * <b>Example</b>
 * @snippet doc_lib_str.c str_ToUpper
 */
VOID str_ToUpper(CHAR *pText);

/**
 * @brief This function converts the characters of a string into
 *        lower case characters.
 *
 * @note The string must end with \0.
 *
 * @param[in,out]  pText   String which is to be converted into
 *                         lower case characters.
 *
 * <b>Example</b>
 * @snippet doc_lib_str.c str_ToUpper
 */
VOID str_ToLower(CHAR *pText);

/**
 * @brief This function converts a number represented as a string
 *        into a number.
 *
 * @deprecated Use functions of standard library instead:
 *  - atoi()
 *  - atol()
 *  - strtod()
 *  - strtol()
 *  - strtoul()
 *
 * Possible formats:
 * - Decimal number with/without sign (e.g. 12, -78, 0, ...)
 * - Hexadecimal number with/without sign (e.g. 0x78, 0XFF, -0x1, ...)
 * - Floating-point number `[-]ddd.ddd[E[+-]dd]` (e.g. -1.3, 0.45e3, -1.2E-2, ...)
 *
 * @note The function returns the determined number as a UINT32 value.
 *       If the format is floating-point, the returned value has to be casted (see "Example 2" below).
 *
 * Examples of conversions:
Text (pText)   | Determined value (pValue) | Determined type (pType) | Comment
-------------- | ------------------------- | ----------------------- | ----------------------
"123"          | 123                       | #STR_UINT32             |                        |
"+34"          | 34                        | #STR_SINT32             |                        |
"0x45"         | 69                        | #STR_UINT32             |                        |
"-0x20"        | -32                       | #STR_SINT32             |                        |
"12345678901"  | 4294967295                | #STR_UINT32             | highest UINT32 number
"+12345678901" | 2147483647                | #STR_SINT32             | highest SINT32 number
"-12345678901" | -2147483648               | #STR_SINT32             | highest SINT32 number
"1.23"         | 1.23                      | #STR_REAL32             |                        |
"+7.34"        | 7.34                      | #STR_REAL32             |                        |
"-.23E2"       | -23.0                     | #STR_REAL32             |                        |
 *
 * @warning Do not use special characters. In this case, the return value of the function
 *          and the return values of the parameters `pValue` and `pType` are unspecified.
 *
 * All spaces and tabs in front of the number will be skipped. The end of the
 * string can be any white space character (e.g. tab, space, \0, $, ...)
 *
 * @param[in]  pText   A number represented as a string, which is to be
 *                     converted into a real number.
 *                     Preceding the number may be spaces and tabulators,
 *                     as many as desired. The end of the number may be
 *                     marked with a random character that does not belong
 *                     to the number (tabulator, space, \0, $,...).
 * @param[out] pValue  Return of the real number.
 *                     If the pointer is not needed: specify `pValue = NULL`.
 * @param[out] pType   Return of the number type.
 *                     If the pointer is not needed: specify `pType = NULL`.
 *
 * @returns    The function returns the determined number as a 32-bit number,
 *             whereby for real values actually a real number is returned.
 *
 * <b>Example 1</b>
 * @snippet doc_lib_str.c str_ToNumber1
 * <b>Example 2</b>
 * @snippet doc_lib_str.c str_ToNumber2
 */
UINT32 str_ToNumber(CHAR *pText, VOID *pValue, UINT32 *pType);

/**
 * @brief This function compares characters of two strings without regard to case.
 *
 * @see Microsoft stricmp().
 *
 * @param[in] s1   Null-terminated string to compare.
 * @param[in] s2   Null-terminated string to compare.
 *
 * @retval     <0   string1 (s1) less than string2 (s2)
 * @retval     0    string1 (s1) identical to string2 (s2)
 * @retval     >0   string1 (s1) greater than string2 (s2)
 */
SINT32 str_CmpNoCase(const CHAR *s1, const CHAR *s2);

/**
 * @brief This function compares characters of two strings without regard to case.
 *
 * @see Microsoft strnicmp()
 *
 * @param[in] s1       Null-terminated string to compare.
 * @param[in] s2       Null-terminated string to compare.
 * @param[in] count    Number of characters to compare.
 *
 * @retval     <0   string1 (s1) less than string2 (s2)
 * @retval     0    string1 (s1) identical to string2 (s2)
 * @retval     >0   string1 (s1) greater than string2 (s2)
 */
SINT32 str_CmpNoCase2(const CHAR *s1, const CHAR *s2, size_t count);

/**
 * @brief This function removes leading and trailing spaces (isspace) in string.
 *
 * \<Space\> includes:
 *  - '&nbsp;'  (0x20) space (SPC)
 *  - '\\t' (0x09) horizontal tab (TAB)
 *  - '\\n' (0x0a) newline (LF)
 *  - '\\v' (0x0b) vertical tab (VT)
 *  - '\\f' (0x0c) feed (FF)
 *  - '\\r' (0x0d) carriage return (CR)
 *
 * @note The content of the string is modified.
 *
 * @param[in,out]  str  C String to trim
 *
 * @return Pointer to original C String *
 * @since MSys V4.00
 */
CHAR *str_Trim(CHAR *str);

/**
 * @brief This function removes leading spaces (isspace) in string.
 *
 * \<Space\> includes:
 *  - '&nbsp;'  (0x20) space (SPC)
 *  - '\\t' (0x09) horizontal tab (TAB)
 *  - '\\n' (0x0a) newline (LF)
 *  - '\\v' (0x0b) vertical tab (VT)
 *  - '\\f' (0x0c) feed (FF)
 *  - '\\r' (0x0d) carriage return (CR)
 *
 * @note The content of the string is modified.
 *
 * @param[in,out]  str        C String to trim
 *
 * @return Pointer to original C String
 * @since MSys V4.00
 */
CHAR *str_TrimLeft(CHAR *str);

/**
 * @brief This function removes trailing spaces (isspace) in string.
 *
 * \<Space\> includes:
 *  - '&nbsp;'  (0x20) space (SPC)
 *  - '\\t' (0x09) horizontal tab (TAB)
 *  - '\\n' (0x0a) newline (LF)
 *  - '\\v' (0x0b) vertical tab (VT)
 *  - '\\f' (0x0c) feed (FF)
 *  - '\\r' (0x0d) carriage return (CR)
 *
 * @note The content of the string is modified.
 *
 * @param[in,out]  str        C String to trim
 *
 * @return Pointer to original C String
 * @since MSys V4.00
 */
CHAR *str_TrimRight(CHAR *str);

#ifndef VXWORKS7 /* strtoll and strtoull are defined in stdlib.h */ 
/**
 * @brief This function converts a string to a long long integer (ANSI).
 *
 * The strtoll() function works just like the strtol() function but returns a
 * long long integer value.
 *
 * @param[in]      nptr    String to convert
 * @param[in,out]  endptr  Pointer to final string
 * @param[in]      base    Radix (0, 2..36)
 *
 * @retval     !0 The converted value.
 * @retval     0  No conversion could be performed; errno is set to EINVAL
 * @retval     LLONG_MIN Correct value is outside the range of representable values;
 *             errno is set to ERANGE.
 * @retval     LLONG_MAX Correct value is outside the range of representable values;
 *             errno is set to ERANGE.
 */
SINT64 strtoll(const CHAR *nptr, CHAR **endptr, SINT32 base);

/**
 * @brief This function converts a string to a unsigned long long integer (ANSI).
 *
 * The strtoull() function works just like the strtoul() function but returns a
 * unsigned long long integer value.
 *
 * @param[in]      nptr    String to convert
 * @param[in,out]  endptr  Pointer to final string
 * @param[in]      base    Radix (0, 2..36)
 *
 * @retval     !0 The converted value.
 * @retval     0  No conversion could be performed; errno is set to EINVAL
 * @retval     ULLONG_MAX Correct value is outside the range of representable values;
 *             errno is set to ERANGE.
 */
UINT64 strtoull(const CHAR *nptr, CHAR **endptr, SINT32 base);
#endif
/** @} */

#ifdef __cplusplus
}
#endif

#endif
