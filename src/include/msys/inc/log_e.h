/**
********************************************************************************
* @file     log_e.h
* @author   Fritsche
*
* @brief This file contains all definitions and declarations exported by
*        the Logging Library for use by modules running on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef LOG_E__H
#define LOG_E__H

#include <mtypes.h>
#include <inf.h>

#ifdef __cplusplus
extern  "C"
{
#endif

/**
* @addtogroup SYS-LOG-DEF
* @{
*/

#define SAME_LOGERR_MAXCOUNT	20      /**< Maximum number same type of error
                                             should be logged */
#define SAME_LOGGRP_MAXCOUNT	50      /**< Maximum number same group of error
                                             should be logged */

#define LOG_T_INFO        'I'           /**< Log message type: information  */
#define LOG_T_WRN         'W'           /**< Log message type: warning      */
#define LOG_T_ERR         'E'           /**< Log message type: error        */

/** @} End of SYS-LOG-DEF */

/**
* @addtogroup SYS-LOG-API
* @{
*/

/**
********************************************************************************
* @brief Flush log file.
*
* VxWorks messages without line termination stay in the buffer and will not be
* written to the log file until next output.
*
* This function forces the writing of those kind of VxWorks messages to the log
* file.
*
* @returns OK
*******************************************************************************/
SINT32 log_Flush(void);

/**
********************************************************************************
* @brief Via this function, an entry of any type can be made into the logbook,
*        without writing to the console.
*
* This function should be used only by program-parts that are not allowed to write
* to the console for time reasons (e.g. power-fail). The transfer parameter is a
* character string without arguments, without a line feed and with the type of
* input and an ":" at the beginning. The maximum length of the message and the
* type must not exceed 255 characters.
*
* @note This function is designed for system use. The caller must ensure, that the
*       protection layer is set to the system memory partition. This can be done
*       with the function pair #sys_AppToSys() and #sys_SysToApp().
*
* @param[in] Info            Text-String with type 'E:/W:/I:'
*
* #### Examples ####
* @code{.c}log_WriteLogFile("E:XXX_SHUTDOWN: Shutdown caused by power fail!");@endcode
*******************************************************************************/
void log_WriteLogFile(UINT8 Info[]);

/**
********************************************************************************
* @brief This functions enables/disables the logging output to the console.
*
* @note The messages are always added to the logbook.
*
* @param[in]  Enable    #TRUE - enable console;
*                       #FALSE - disable console
*******************************************************************************/
void log_EnableConsole(BOOL Enable);

/**
********************************************************************************
* @brief This function creates a copy of the logfile.
*
* @param[in]  pSrcName    Source file (path and name)
* @param[in]  pDestName   Destination file (path and name)
*
* @retval     0       OK
* @retval     -1      Error in file copy
*******************************************************************************/
SINT32 log_FileCopy(CHAR * pSrcName, CHAR * pDestName);

/**
********************************************************************************
* @brief Via this function an entry of the type <b>information</b> can be made
*        in the logbook.
*
* The formatting of the output is the same as the principle used for printf. As
* parameters, a maximum of 6 arguments, each 32 bits in length, are allowed, other
* parameters will be ignored. If 64-bit float values are transferred, 2 arguments
* are required. Therefore the maximum number of real or float values is 3. The
* maximum length of the message must not exceed 253 characters.

* The function writes the entry into the logbook and to the console. The logging
* is done in the context of the logger task. Therefore the execution depends on
* the priority of the logger task.
*
* @note In case of a message queue overload, the output may be delayed or information
*       may be discarded.
*
* @param[in]  Format        Format string
* @param[in]  ...           Format arguments
*
* #### Examples ####
* @code{.c}log_Info("XXX_SETRATE: Rate is %d.", xxx_Rate);@endcode
*******************************************************************************/
#ifdef LOG__C
void log_Info(UINT8 * Format, UINT32 Arg1, UINT32 Arg2, UINT32 Arg3,
              UINT32 Arg4, UINT32 Arg5, UINT32 Arg6);
#elif defined(LOG_DO_PARAMETER_CHECK)
void log_Info(char *Format, ...) __attribute__ ((format(printf, 1, 2)));
#else
void log_Info(CHAR * Format, ...);
#endif

/**
********************************************************************************
* @brief Via this function an entry of the type <b>information</b> can be made
*        in the logbook.
*
* The formatting of the output is the same as the principle used for printf. As
* parameters, a maximum of 6 arguments, each 32 bits in length, are allowed, other
* parameters will be ignored. If 64-bit float values are transferred, 2 arguments
* are required. Therefore the maximum number of real or float values is 3. The
* maximum length of the message must not exceed 253 characters.

* The function writes the entry into the logbook and to the console. The logging
* is done within the function call, without using the logger task. This is much
* slower, but has the advantage, that at the end of the function, the entry is in
* the logbook.
*
* @param[in]  Format        Format string
* @param[in]  ...           Format arguments
*
* #### Examples ####
* @code{.c}log_Info2("XXX_SETRATE: Rate is %d.", xxx_Rate);@endcode
*******************************************************************************/
#ifdef LOG__C
void log_Info2(UINT8 * Format, UINT32 Arg1, UINT32 Arg2, UINT32 Arg3,
               UINT32 Arg4, UINT32 Arg5, UINT32 Arg6);
#elif defined(LOG_DO_PARAMETER_CHECK)
void log_Info2(char *Format, ...) __attribute__ ((format(printf, 1, 2)));
#else
void log_Info2(CHAR * Format, ...);
#endif

/**
********************************************************************************
* @brief Via this function an entry of the type <b>error</b> can be made
*        in the logbook.
*
* The formatting of the output is the same as the principle used for printf. As
* parameters, a maximum of 6 arguments, each 32 bits in length, are allowed, other
* parameters will be ignored. If 64-bit float values are transferred, 2 arguments
* are required. Therefore the maximum number of real or float values is 3. The
* maximum length of the message must not exceed 253 characters.
*
* The function writes the entry into the logbook and to the console. The logging
* is done in the context of the logger task. Therefore the execution depends on
* the priority of the logger task.
*
* @note In case of a message queue overload, the output may be delayed or information
*       may be discarded.
*
* @param[in]  Format        Format string
* @param[in]  ...           Format arguments
*
* #### Examples ####
* @code{.c}log_Err("XXX_SETRATE: Rate is %d.", xxx_Rate);@endcode
*******************************************************************************/
#ifdef LOG__C
void log_Err(UINT8 * Format, UINT32 Arg1, UINT32 Arg2, UINT32 Arg3,
             UINT32 Arg4, UINT32 Arg5, UINT32 Arg6);
#elif defined(LOG_DO_PARAMETER_CHECK)
void log_Err(char *Format, ...) __attribute__ ((format(printf, 1, 2)));
#else
void log_Err(CHAR * Format, ...);
#endif

/**
********************************************************************************
* @brief Via this function an entry of the type <b>error</b> can be made
*        in the logbook.
*
* The formatting of the output is the same as the principle used for printf. As
* parameters, a maximum of 6 arguments, each 32 bits in length, are allowed, other
* parameters will be ignored. If 64-bit float values are transferred, 2 arguments
* are required. Therefore the maximum number of real or float values is 3. The
* maximum length of the message must not exceed 253 characters.

* The function writes the entry into the logbook and to the console. The logging
* is done within the function call, without using the logger task. This is much
* slower, but has the advantage, that at the end of the function, the entry is in
* the logbook.
*
* @param[in]  Format        Format string
* @param[in]  ...           Format arguments
*
* #### Examples ####
* @code{.c}log_Err2("XXX_SETRATE: Rate is %d.", xxx_Rate);@endcode
*******************************************************************************/
#ifdef LOG__C
void log_Err2(UINT8 * Format, UINT32 Arg1, UINT32 Arg2, UINT32 Arg3,
              UINT32 Arg4, UINT32 Arg5, UINT32 Arg6);
#elif defined(LOG_DO_PARAMETER_CHECK)
void log_Err2(char *Format, ...) __attribute__ ((format(printf, 1, 2)));
#else
void log_Err2(CHAR * Format, ...);
#endif

/**
********************************************************************************
* @brief Via this function an entry of the type <b>warning</b> can be made
*        in the logbook.
*
* The formatting of the output is the same as the principle used for printf. As
* parameters, a maximum of 6 arguments, each 32 bits in length, are allowed, other
* parameters will be ignored. If 64-bit float values are transferred, 2 arguments
* are required. Therefore the maximum number of real or float values is 3. The
* maximum length of the message must not exceed 253 characters.

* The function writes the entry into the logbook and to the console. The logging
* is done in the context of the logger task. Therefore the execution depends on
* the priority of the logger task.
*
* @note In case of a message queue overload, the output may be delayed or information
*       may be discarded.
*
* @param[in]  Format        Format string
* @param[in]  ...           Format arguments
*
* #### Examples ####
* @code{.c}log_Wrn("XXX_SETRATE: Rate is %d.", xxx_Rate);@endcode
*******************************************************************************/
#ifdef LOG__C
void log_Wrn(UINT8 * Format, UINT32 Arg1, UINT32 Arg2, UINT32 Arg3,
             UINT32 Arg4, UINT32 Arg5, UINT32 Arg6);
#elif defined(LOG_DO_PARAMETER_CHECK)
void log_Wrn(char *Format, ...) __attribute__ ((format(printf, 1, 2)));
#else
void log_Wrn(CHAR * Format, ...);
#endif

/**
********************************************************************************
* @brief Via this function an entry of the type <b>warning</b> can be made
*        in the logbook.
*
* The formatting of the output is the same as the principle used for printf. As
* parameters, a maximum of 6 arguments, each 32 bits in length, are allowed, other
* parameters will be ignored. If 64-bit float values are transferred, 2 arguments
* are required. Therefore the maximum number of real or float values is 3. The
* maximum length of the message must not exceed 253 characters.

* The function writes the entry into the logbook and to the console. The logging
* is done within the function call, without using the logger task. This is much
* slower, but has the advantage, that at the end of the function, the entry is in
* the logbook.
*
* @param[in]  Format        Format string
* @param[in]  ...           Format arguments
*
* #### Examples ####
* @code{.c}log_Wrn2("XXX_SETRATE: Rate is %d.", xxx_Rate);@endcode
*******************************************************************************/
#ifdef LOG__C
void log_Wrn2(UINT8 * Format, UINT32 Arg1, UINT32 Arg2, UINT32 Arg3,
              UINT32 Arg4, UINT32 Arg5, UINT32 Arg6);
#elif defined(LOG_DO_PARAMETER_CHECK)
void log_Wrn2(char *Format, ...) __attribute__ ((format(printf, 1, 2)));
#else
void log_Wrn2(CHAR * Format, ...);
#endif

/**
********************************************************************************
* @brief Via this function an entry of <b>any type</b> can be made
*        in the logbook.
*
* This function differs from the other log functions in terms of the free choice
* of the type (E, W, or I is not generate automatically). The caller must specify
* the type and special character ":" in the message. Any desired types can be used.
*
* The formatting of the output is the same as the principle used for printf. As
* parameters, a maximum of 6 arguments, each 32 bits in length, are allowed, other
* parameters will be ignored. If 64-bit float values are transferred, 2 arguments
* are required. Therefore the maximum number of real or float values is 3. The
* maximum length of the message must not exceed 253 characters.

* The function writes the entry into the logbook and to the console. The logging
* is done in the context of the logger task. Therefore the execution depends on
* the priority of the logger task.
*
* @note In case of a message queue overload, the output may be delayed or information
*       may be discarded.
*
* @param[in]  Format        Format string
* @param[in]  ...           Format arguments
*
* #### Examples ####
* @code{.c}log_User("A:XXX_SETRATE: Rate is %d.", xxx_Rate);@endcode
*******************************************************************************/
#ifdef LOG__C
void log_User(UINT8 * Format, UINT32 Arg1, UINT32 Arg2, UINT32 Arg3,
              UINT32 Arg4, UINT32 Arg5, UINT32 Arg6);
#elif defined(LOG_DO_PARAMETER_CHECK)
void log_User(char *Format, ...) __attribute__ ((format(printf, 1, 2)));
#else
void log_User(CHAR * Format, ...);
#endif

/**
********************************************************************************
* @brief Via this function an entry of <b>any type</b> can be made
*        in the logbook.
*
* This function differs from the other log functions in terms of the free choice
* of the type (E, W, or I is not generate automatically). The caller must specify
* the type and special character ":" in the message. Any desired types can be used.
*
* The formatting of the output is the same as the principle used for printf. As
* parameters, a maximum of 6 arguments, each 32 bits in length, are allowed, other
* parameters will be ignored. If 64-bit float values are transferred, 2 arguments
* are required. Therefore the maximum number of real or float values is 3. The
* maximum length of the message must not exceed 253 characters.

* The function writes the entry into the logbook and to the console. The logging
* is done within the function call, without using the logger task. This is much
* slower, but has the advantage, that at the end of the function, the entry is in
* the logbook.
*
* @param[in]  Format        Format string
* @param[in]  ...           Format arguments
*
* #### Examples ####
* @code{.c}log_User2("A:XXX_SETRATE: Rate is %d.", xxx_Rate);@endcode
*******************************************************************************/
#ifdef LOG__C
void log_User2(UINT8 * Format, UINT32 Arg1, UINT32 Arg2, UINT32 Arg3,
               UINT32 Arg4, UINT32 Arg5, UINT32 Arg6);
#elif defined(LOG_DO_PARAMETER_CHECK)
void log_User2(char *Format, ...) __attribute__ ((format(printf, 1, 2)));
#else
void log_User2(CHAR * Format, ...);
#endif

/**
********************************************************************************
* @brief Register a hook function that will be called in case of log messages
*        of type log_Info(), log_Wrn(), log_Err() and log_User().
*
* @note This function does <b>not</b> register a hook function for log messages
*       of type log_Info2(), log_Wrn2(), log_Err2() or log_User2()!
*
* The parameter `Type` of the hook function specifies the type of the log
* message:
* - `Type` = #LOG_T_INFO: Log message of type log_Info()
* - `Type` = #LOG_T_WRN: Log message of type log_Wrn()
* - `Type` = #LOG_T_ERR: Log message of type log_Err()
* -  Other values: User defined type.
*
* The parameter `Info` of the hook function contains the logging text.<br>
* The return value of the hook function indicates, if the log message will be
* written to the log file (return value is #TRUE) or not (return value is #FALSE).
*
* @note A log message only will be written to the log file, if all registered
*       hook functions return #TRUE.
*
* @param[in]   HookFunc        Pointer to function that shall be called
* @param[in]   pUserData       Pointer to user defined data
* @param[out]  pHookId         Pointer to the new HookId
*
* @retval OK     Hook function successfully registered.
* @retval ERROR  Error registering hook function.
*
*******************************************************************************/
SINT32 sys_LogHookAdd(BOOL8 (*HookFunc)(const UINT8 Type, const UINT8 *Info, VOID *pUserData),
                      VOID *pUserData, UINT32 *pHookId);

/**
********************************************************************************
* @brief Deletes an existing hook
*
* @note       lst_p_Rem... may randomly raise an error if the given item does
*             not exist, which may through an EXC14 if NULL pointer protection
*             is empty. To avoid this we look at the existing elements to
*             verify if the given item really exists.
*
* @param[in]  HookId        ID of the hook
*******************************************************************************/
void sys_LogHookDelete(UINT32 HookId);
/** @} */

#ifdef __cplusplus
}
#endif

#endif
