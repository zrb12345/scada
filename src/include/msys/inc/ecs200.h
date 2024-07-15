/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     ecs200.h
* @author   schittlc
* @brief    EtherCAT Slave
*           This file contains all EtherCAT Slave definitions and declarations.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef ECS200__H
#define ECS200__H

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @name Defines
 * @{
 */


/**
 * @name Slave States defines
 * @{
 */

#define ECS_STATE_INIT      0x0001
#define ECS_STATE_PREOP     0x0002
#define ECS_STATE_BOOT      0x0003
#define ECS_STATE_SAFEOP    0x0004
#define ECS_STATE_OP        0x0008
#define ECS_STATE_UNKNOWN   0x0006
/** @} */

/**
 * @name Slave States defines
 * @{
 */

#define ALSTATUSCODE_NOERROR                0x00
#define ALSTATUSCODE_INVALIDALCONTROL       0x11     /**< Invalid req. state change */
#define ALSTATUSCODE_UNKNOWNALCONTROL       0x12     /**< Unknown requested state */
#define ALSTATUSCODE_BOOTNOTSUPP            0x13     /**< Boot-Mode not supported */
#define ALSTATUSCODE_INVALIDMBXCFGINPREOP   0x16     /**< Invalid MBX Config in PREOP */
#define ALSTATUSCODE_SMWATCHDOG             0x1B     /**< Watchdog Process Data expired */
#define ALSTATUSCODE_INVALIDSMOUTCFG        0x1D     /**< Invalid SyncM OUT Config */
#define ALSTATUSCODE_INVALIDSMINCFG         0x1E     /**< Invalid SyncM IN Config */
#define ALSTATUSCODE_INVALIDWDCFG           0x1F     /**< Invalid Watchdog Config */
#define ALSTATUSCODE_DCINVALIDSYNCCFG       0x30     /**< Invalid DC Sync Config */
#define ALSTATUSCODE_DCSYNC0CYCLETIME       0x36     /**< Invalid DC Sync0 Cycle Time */
/** @} */
/** @} */

#ifdef __cplusplus
}
#endif

#endif
