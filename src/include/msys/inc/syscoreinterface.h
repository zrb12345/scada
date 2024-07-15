/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     sysCoreInterface.h
* @author   Fritsche
* @brief    Additional bachmann functions for VxW core.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef SYSCOREINTERFACE__H
#define SYSCOREINTERFACE__H

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @name SCI Return Codes
 * @{
 */

#define SCI_OK                  0    /**< OK */
#define SCI_GENERAL_ERROR       -1   /**< general error */
#define SCI_UNKNOWN_COMMAND     -2   /**< unknown command in SCI */
#define SCI_UNSUPPORTED_COMMAND -3   /**< unsupported command in SCI */
#define SCI_BAD_CALL_POINTER    -4   /**< invalid pointer to call parameter */
#define SCI_BAD_REPLY_POINTER   -5   /**< invalid pointer to reply parameter */
#define SCI_1ST_CALL_PARAM_BAD  -11  /**< 1st parameter in call struct bad */
#define SCI_2ND_CALL_PARAM_BAD  -12  /**< 2nd parameter in call struct bad */
#define SCI_3RD_CALL_PARAM_BAD  -13  /**< 3rd parameter in call struct bad */
#define SCI_4TH_CALL_PARAM_BAD  -14  /**< 4th parameter in call struct bad */
#define SCI_5TH_CALL_PARAM_BAD  -15  /**< 5th parameter in call struct bad */
#define SCI_UNSUPPORTED_IN_CORE -99  /**< the core doesn't support SCI */
/** @} */

/**
 * @name SCI Core Types
 * @{
 */

#define CTYPE_UNDEF         0x00000000   /**< undefined */
#define CTYPEALL_IMAGE      0x00001000   /**< Bit for .ALL Images */
#define CTYPE_MCORE         0x00000001   /**< VxWorks */
#define CTYPE_MCORE_ALL     0x00001001   /**< VxWorks.all */
#define CTYPE_MCORE_EX      0x00000002   /**< VxWorks.ex */
#define CTYPE_MXCCORE       0x00000003   /**< MxCCore */
#define CTYPE_MXCCORE_ALL   0x00001003   /**< MxCCore.all */
#define CTYPE_MPCORE        0x00000004   /**< MpCore */
#define CTYPE_MPCORE_ALL    0x00001004   /**< MpCore.all */
#define CTYPE_TCORE         0x00000005   /**< TCore */
#define CTYPE_TCORE_ALL     0x00001005   /**< TCore.all */
#define CTYPE_MHCORE        0x00000006   /**< MhCore */
#define CTYPE_MHCORE_ALL    0x00001006   /**< MhCore (.all) */
#define CTYPE_MCCORE        0x00000007   /**< McCore */
#define CTYPE_MCCORE_ALL    0x00001007   /**< McCore (.all) */
#define CTYPE_MCOS          0x00000008   /**< McOS */
/** @} */

#ifdef __cplusplus
}
#endif

#endif
