/**
********************************************************************************
* @file     syslog_e.h
* @author   RENO
*
* @brief This file contains all definitions and declarations
*        for the syslog API.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef SYSLOG_E__H
#define SYSLOG_E__H

/**
 * @addtogroup SYS-SYSLOG-DEF
 * @{
 */

/**
 * @anchor SYSLOG_PRIO
 */
/**
 * @name Possible severity codes
 * @{
 */
#define SYSLOG_EMERG    0
#define SYSLOG_ALERT    1
#define SYSLOG_CRIT     2
#define SYSLOG_ERR      3
#define SYSLOG_WARNING  4
#define SYSLOG_NOTICE   5
#define SYSLOG_INFO     6
#define SYSLOG_DEBUG    7
/** @} * */

/**
 * @anchor SYSLOG_FACILITY
 */
/**
 * @name Possible facility codes
 * @{
 */
#define SYSLOG_KERN       (0 << 3)
#define SYSLOG_USER       (1 << 3)
#define SYSLOG_MAIL       (2 << 3)
#define SYSLOG_DAEMON     (3 << 3)
#define SYSLOG_AUTH       (4 << 3)
#define SYSLOG_SYSLOG     (5 << 3)
#define SYSLOG_LPR        (6 << 3)
#define SYSLOG_NEWS       (7 << 3)
#define SYSLOG_UUPC       (8 << 3)
#define SYSLOG_CRON       (9 << 3)
#define SYSLOG_AUTHPRIV   (10 << 3)
#define SYSLOG_FTP        (11 << 3)
/** @} * */

/**
 * @anchor LOG_MASK
 */

#define LOG_MASK(pri)   (1 << (pri))        /**< mask for one priority */


/**
 * @name Possible values for log/urgent mask
 * @{
 */
#define SYSLOG_MASK_ALL      0xFF   /**< Mask for all */
#define SYSLOG_MASK_EMERG    0x01   /**< Equates to: 1 << SYSLOG_EMERG */
#define SYSLOG_MASK_ALERT    0x02   /**< Equates to: 1 << SYSLOG_ALERT */
#define SYSLOG_MASK_CRIT     0x04   /**< Equates to: 1 << SYSLOG_CRIT */
#define SYSLOG_MASK_ERR      0x08   /**< Equates to: 1 << SYSLOG_ERR */
#define SYSLOG_MASK_WARNING  0x10   /**< Equates to: 1 << SYSLOG_WARNING */
#define SYSLOG_MASK_NOTICE   0x20   /**< Equates to: 1 << SYSLOG_NOTICE */
#define SYSLOG_MASK_INFO     0x40   /**< Equates to: 1 << SYSLOG_INFO */
#define SYSLOG_MASK_DEBUG    0x80   /**< Equates to: 1 << SYSLOG_DEBUG */
/** @} * */


/* current number of facilities */
#define LOG_NFACILITIES 64      /**< 0-62 are used by ipcom_syslog */
#define LOG_FACMASK 0x3f8       /**< mask to extract facility part */

#define LOG_FAC(p)  (((p) & LOG_FACMASK) >> 3) /**< facility of pri */

#define LOG_PRIMASK 0x07    /**< mask to extract priority part */

#define LOG_PRI(p)  ((p) & LOG_PRIMASK) /**< extract priority */

/** @} end of SYS-SYSLOG-DEF */

/**
 * @addtogroup SYS-SYSLOG-API
 * @{
 */

/**
 * @brief This function sets process attributes that affect subsequent calls to
 * syslog().
 *
 * @note The parameters `ident` and `logopt` are not used / not supported.
 *
 * The `facility` argument encodes a default facility to be assigned to all
 * messages that do not have an explicit facility already encoded.
 * The initial default facility is SYSLOG_USER.
 *
 * @param[in]  ident      Not used.
 * @param[in]  logopt     Not used.
 * @param[in]  facility   Default facility to be set (@ref SYSLOG_FACILITY).
 *
 * @see syslog() and closelog().
 */
void openlog(const CHAR *ident, SINT logopt, SINT facility);

/**
 * @brief This function unsets the process attributes.
 *
 * This routine resets process attributes, set by openlog(), to the default.
 * The default facility is SYSLOG_USER.
 *
 * @see syslog() and openlog().
 */
void closelog(void);

/**
 * @brief This function sends a message to a syslog server.
 *
 * The logged message includes a message header and a message body.
 * The message head contains a timestamp and a tag string.
 *
 * The message body is generated from the message and following arguments in
 * the same manner as if these were arguments to printf().
 *
 * Values of the `priority` argument are formed by OR'ing together
 * a severity-level value and an optional facility value.
 * If no facility value is specified, the current default facility value is used.
 *
 * @param[in]  priority      Priority of message (@ref SYSLOG_PRIO, @ref SYSLOG_FACILITY).
 * @param[in]  message       Message to send.
 * @param[in]  ...           Arguments for message.
 *
 * @see openlog(), closelog() and setlogmask().
 */
void syslog(SINT priority, CHAR *message, ...);

/**
 * @brief This function sets the log priority mask
 *
 * This function sets the log severity mask for the current process to `maskpri`
 * and returns the previous mask. If the `maskpri` argument is 0, the current
 * log mask is not modified. Calls by the current process to syslog() with
 * a severity not set in `maskpri` will be rejected. Calls by the current process to the
 * M1 logging functions and system internal syslog messages are not affected by the set
 * severity mask.
 * The default log mask (0xFF) allows all severities to be logged. A call to openlog() is not
 * required prior to calling setlogmask().
 *
 * @note A call to openlog() is not required prior to calling setlogmask().
 *
 * @param[in]  maskpri      Severity mask to be set (see @ref LOG_MASK / @ref SYSLOG_FACILITY).
 *
 * @returns Previous log severity mask.
 *
 * @see syslog().
 */
SINT setlogmask(SINT maskpri);

/** @} end of SYS-SYSLOG-API */
#endif
