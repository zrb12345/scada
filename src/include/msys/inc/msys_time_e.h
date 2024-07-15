/**
 ********************************************************************************
 * @file     msys_time_e.h
 * @author   Faessler
 *
 * @brief This header contains all public definitions for the system time
 *        functions.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2014
 *******************************************************************************/

#ifndef MSYS_TIME_E__H
#define MSYS_TIME_E__H

#include <mtypes.h>
#include <time.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @addtogroup SYS-TIME
 * @{
 */

/**
 * @brief Gets the actual system time base.
 *
 * @retval #M_TIME_UTC
 * @retval #M_TIME_LOCAL
 *
 * @since MSys V3.95
 */
SINT32 sys_GetTimeBase(VOID);

/**
 * @brief Get the current system time in seconds/nanos since epoch (UTC).
 *
 * This function returns the system time in seconds and nanoseconds since
 * 1970-01-01 00:00:00 UTC.
 *
 * @param[out] pNanos  Returns the nanosecond part (optionally)
 *
 * @return system time in seconds since epoch
 *
 * @since MSys V3.95
 *
 * <b>Example</b><br>
 * `UINT32 sec;`<br>
 * `UINT32 nanos;`<br><br>
 * `sec = sys_Time(&nanos);`<br>
 * `printf("Current Timestamp = %lu.%09lu UTC", sec, nanos);`
 */
time_t sys_Time(UINT32 *pNanos);

/**
 * @brief Get the current time from the system clock (UTC/LOCAL).
 *
 * This function returns the system clock in seconds since 1970-01-01 00:00:00.
 * Depending on the system time base, the returned value is either UTC or
 * LOCAL time.
 *
 * @param[out] pNanos  Returns the nanosecond part (optionally)
 *
 * @return current time from the system clock
 *
 * @since MSys V3.95
 *
 * <b>Example</b><br>
 * `UINT32 sec;`<br>
 * `UINT32 nanos;`<br><br>
 * `sec = sys_Clock(&nanos);`<br>
 * `printf("Current Clock = %u.%09u", sec, nanos);`
 */
time_t sys_Clock(UINT32 *pNanos);

/**
 * @brief Get a monotonous time as seconds from a specified time older than the
 *        start of the system.
 *
 * This time is guaranteed to be monotonous even if the "wall clock" time goes
 * back.
 *
 * @param[out]  pNanos  Returns the nanosecond part (optionally)
 *
 * @return current monotonous time
 *
 * @since MSys V3.95
 *
 * <b>Example</b><br>
 * `UINT32 uptime`<br><br>
 * `uptime = sys_ClockMonotonic(NULL);`<br>
 * `printf("System uptime = %lu", uptime);`
 */
time_t sys_ClockMonotonic(UINT32 *pNanos);

/**
 * @brief Get the current time from the system clock (UTC/LOCAL).
 *
 * This function returns the system clock in seconds since 1970-01-01 00:00:00.
 * Depending on the system time base, the returned value is either UTC or
 * LOCAL time.
 *
 * @param[out] pClock  A pointer to a \p timespec structure to store the time
 *
 * @retval #OK
 * @retval #ERROR
 *
 * @since MSys V3.95
 */
SINT32 sys_GetClock(struct timespec *pClock);

/**
 * @brief Get the resolution of the system clock.
 *
 * This function gets the clock resolution in nanoseconds.
 * If \p pClockRes is non-NULL, the resolution is stored in the location pointed to.
 * Resolution is always assumed to be less than 1 second, only the \p tv_nsec
 * field is filled in.
 *
 * @param[out] pClockRes   A pointer to a \p timespec structure to store the
 *                         resolution.
 *
 * @retval #OK
 * @retval #ERROR
 *
 * @since MSys V3.95
 */
SINT32 sys_GetClockRes(struct timespec *pClockRes);

/**
 * @brief Get a monotonous time from a specified time older than the start of
 *        the system.
 *
 * This time is guaranteed to be monotonous even if the "wall clock" time goes
 * back.
 *
 * @param[out] pClock  A pointer to a \p timespec structure
 *
 * @retval #OK
 * @retval #ERROR
 *
 * @since MSys V3.95
 */
SINT32 sys_GetClockMonotonic(struct timespec *pClock);

/**
 * @brief Set the system time.
 *
 * This routing adjusts the system clocks to the time specified. Given time
 * value represents seconds and nanoseconds since 1970-01-01 00:00:00 UTC.
 *
 * Following clocks are adjusted:
 * - Software clock (CLOCK_REALTIME)
 * - Hardware clock (CLOCK_RTCNANO)
 *
 * @attention
 * This function may utilize the CPU for several milliseconds on the context of the calling task!<br>
 * This behavior depends on the configuration of the controller and it's actual state. Do not use
 * this function in time critical applications.
 *
 * @param[in] pTime  Pointer to a \p timespec structure
 *
 * @retval #OK
 * @retval #ERROR
 *
 * @see sys_GetTime()
 * @since MSys V3.95
 */
SINT32 sys_SetTime(const struct timespec *pTime);

/**
 * @brief Get the current system time in seconds/nanos since epoch (UTC).
 *
 * This function returns the system time in seconds and nanoseconds since
 * 1970-01-01 00:00:00 UTC.
 *
 * @param[out] pTime Pointer to a \p timespec structure to store the time
 *
 * @retval #OK
 * @retval #ERROR
 *
 * @see sys_SetTime()
 * @since MSys V3.95
 *
 * <b>Example</b><br>
 * `struct timespec now;`<br><br>
 * `sys_GetTime(&now);`<br>
 * `printf("Current Timestamp = %lu.%09ld UTC", now.tv_sec, tv_nsec);`
 */
SINT32 sys_GetTime(struct timespec *pTime);

/**
 * @brief Set the system date & time (local time representation).
 *
 * This function sets system time to the local time specified.
 *
 * @param[in] pDate  Pointer to local calendar time
 * @param[in] pNanos Additional nano seconds (optionally)
 *
 * @retval #OK
 * @retval #ERROR
 *
 * @see sys_GetLocalTime()
 * @since MSys V3.95
 *
 * <b>Example</b>
 * @snippet doc_sys_msys_time.c sys_SetLocalTime
 */
SINT32 sys_SetLocalTime(struct tm *pDate, UINT32 *pNanos);

/**
 * @brief Get the current date & time (local time representation).
 *
 * This function returns the current time expressed for the local timezone.
 *
 * @param[out] pDate  Pointer to \p tm structure
 * @param[out] pNanos Returns the nanosecond part (optionally)
 *
 * @retval #OK
 * @retval #ERROR
 *
 * @see sys_SetLocalTime()
 * @since MSys V3.95
 */
SINT32 sys_GetLocalTime(struct tm *pDate, UINT32 *pNanos);

/**
 * @brief Set the system timezone (temporarily).
 *
 * This function sets the system timezone specified by given \p timezone string.
 * Supported formats are:
 *  - Fixed offset using GMT/UTC prefix + offset to UTC ("UTC+01:00")
 *  - Olson timezone format ("Europe/Vienna")
 *
 * Format: \p [GMT][UTC][+-]hh[:mm]
 *  - hh ... Offset in hours to GMT
 *  - mm ... Additional offset in minutes
 * <br>
 * Olson timezone format supports daylight saving time based on tz database
 * files.
 *
 * @param[in]      pTimeZone The timezone string
 *
 * @retval #OK
 * @retval #ERROR
 *
 * @see sys_GetTimeZone()
 * @since MSys V3.95
 *
 * <b>Example</b>
 * @snippet doc_sys_msys_time.c sys_SetTimeZone
 */
SINT32 sys_SetTimeZone(const CHAR *pTimeZone);

/**
 * @brief Set the system timezone (remanently).
 *
 * This function sets the system timezone specified by given \p timezone string
 * and updates MConfig.ini to store changes remanently.
 *
 * @param[in]  pTimeZone The timezone string
 * @param[in]  Remanent  TRUE to update MConfig.ini
 *
 * @retval #OK
 * @retval #ERROR
 *
 * @see sys_SetTimeZone()
 * @see sys_GetTimeZone()
 * @since MSys V3.95
 */
SINT32 sys_SetTimeZoneRem(const CHAR *pTimeZone, BOOL8 Remanent);

/**
 * @brief Get the current system timezone (zone name + offset).
 *
 * @param[out]   pBuff   Pointer to write the timezone string to
 * @param[in]    BuffLen Length of \p destination buffer (number of chars)
 *
 * @return Current timezone offset in seconds to UTC
 *
 * @see sys_SetTimeZone()
 * @since  MSys V3.95
 *
 * <b>Example</b>
 * @snippet doc_sys_msys_time.c sys_GetTimeZone
 */
SINT32 sys_GetTimeZone(CHAR *pBuff, SINT32 BuffLen);

/**
 * @brief Get the current system timezone offset in seconds to UTC.
 *
 * @retval Current timezone offset in seconds to UTC
 *
 * @see sys_SetTimeZone()
 * @since  MSys V3.95
 */
SINT32 sys_GetTimeOffset();

/**
 * @brief Convert the time in seconds since epoch (UTC) into broken-down time
 *        representation, expressed as a UTC time.
 *
 * This function is functionally identical to the ANSI <tt>gmtime_r()</tt>
 * function.
 *
 * For a local time alternative see sys_LocalTime().
 *
 * @param[in]  pTime    Pointer to seconds since epoch [UTC], if \p pTime is \c NULL
 *                      the current system time is used for the conversion.
 * @param[out] pResult  Pointer to return structure (broken down time)
 *
 * @retval #OK
 * @retval #ERROR
 *
 * @see sys_LocalTime()
 */
SINT32 sys_GmTime(const time_t *pTime, struct tm *pResult);

/**
 * @brief Convert the time in seconds since epoch (UTC) into broken-down time
 *        representation, expressed for the local timezone.
 *
 * This function wraps the ANSI <tt>localtime_r()</tt> function and
 * determines additional offset information which is returned if requested:
 *  - effective GMT offset (incl. DST saving)
 *  - effective DST offset
 *
 * Offset values represent seconds.
 *
 * @param[in]  pTime    Pointer to seconds since epoch [UTC], if \p pTime is \c NULL
 *                      the current system time is used for the conversion.
 * @param[out] pResult  Pointer to return structure (broken down time),
 *                      \c NULL allowed
 * @param[out] pGmtOff  Pointer where to return the GMT offset,
 *                      \c NULL allowed
 * @param[out] pDstOff  Pointer where to return the DST offset part,
 *                      \c NULL allowed
 *
 * @retval #OK
 * @retval #ERROR
 *
 * @see sys_GmTime()
 */
SINT32 sys_LocalTime(const time_t *pTime, struct tm *pResult, SINT32 *pGmtOff, SINT32 *pDstOff);

/**
 * @brief Convert the time in seconds since epoch (UTC) into broken-down time
 *        representation, expressed for the local timezone (standard time).
 *
 * Compared to sys_LocalTime(), this function always returns standard/winter time
 * and thus compensates potential daylight saving time.
 *
 * The returned offset value represent seconds to UTC.
 *
 * @param[in]  pTime    Pointer to seconds since epoch [UTC], if \p pTime is \c NULL
 *                      the current system time is used for the conversion.
 * @param[out] pResult  Pointer to return structure (broken down time),
 *                      \c NULL allowed
 * @param[out] pGmtOff  Pointer where to return the GMT offset,
 *                      \c NULL allowed
 *
 * @retval #OK
 * @retval #ERROR
 *
 * @see sys_GmTime()
 * @see sys_LocalTime()
 */
SINT32 sys_LocalTimeStd(const time_t *pTime, struct tm *pResult, SINT32 *pGmtOff);

/**
 * @brief Print system clock information to standard output.
 *
 * @return Always returns #OK
 * @since  MSys V4.00
 */
STATUS sys_ShowClock();

/**
 * @brief Print system time information to standard output.
 *
 * This function prints information about system time, timezone settings and
 * the system clock to standard output.
 *
 * @return Always returns #OK
 * @since  MSys V3.95
 *
 * <b>Example of output</b><br>
 * <code><pre>
Time Information
----------------
Timebase             : UTC
Timezone             : GMT+02:00
Timezone offset      : +02:00
Current time         : Fri, 23 May 2014 08:40:40 UTC
Current time local   : Fri, 23 May 2014 10:40:40 GMT+02:00
Daylight saving time : FALSE
System uptime        : 0 Days, 20 Hours, 28 Minutes, 49 Seconds

CPU Information
---------------
TickSource        : TIMER
SysClkRate        : 5000 Ticks/s
SysAuxRate        : 8192 Ticks/s
Sync H/L          : 200/200
CpuRate           : 433MHz
CpuProc1          : 714954861 us
CpuProc2          : 31924829720860 us

C#                               Counter  Resolution    Deviation
-----------------------------------------------------------------
Clock (RTC)       : 1400834440.297566907         2ns     0
Clock (REALTIME)  : 1400834440.300185075         2ns    +0.002618s
Clock (MONOTONIC) :      73729.398891963         2ns
 * </pre></code>
 *
 */
STATUS sys_ShowTime();

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* MSYS_TIME_E__H */
