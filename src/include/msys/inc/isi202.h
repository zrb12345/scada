/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     isi202.h
* @author   Holl
* @brief    This file contains all the definitions and declarations
*           which are exported from the module, and which can be used by other modules
*           on the another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef ISI202__H
#define ISI202__H

#ifdef __cplusplus
extern "C" {
#endif


#include <mtypes.h>
#include <mio.h>

/**
 * @addtogroup ISI2XX_DEF
 * @{
 */

/**
 * @name Possible channel modes
 * @{
 */

#define ISI_M_INC       MIO_M_INC    /**< Incremental Mode */
#define ISI_M_SSI       MIO_M_SSI    /**< Synchronous serial mode */
#define ISI_M_VR        MIO_M_VR     /**< V/R Output on high */
#define ISI_M_SET       MIO_M_SET    /**< Set Output on high */
#define ISI_M_SYNC      MIO_M_SYNC   /**< Sync-Input/Output enable */
#define ISI_M_INTERPOL0 MIO_M_INTERPOL0  /**< SCI-Interpolation 0 */
#define ISI_M_INTERPOL1 MIO_M_INTERPOL1  /**< SCI-Interpolation 1 */
#define ISI_M_INTERPOL2 MIO_M_INTERPOL2  /**< SCI-Interpolation 2 */
#define ISI_M_INTERPOL3 MIO_M_INTERPOL3  /**< SCI-Interpolation 3 */
#define ISI_M_SINGLE    MIO_M_SINGLE     /**< Single count */
#define ISI_M_DOUBLE    MIO_M_DOUBLE     /**< Doubel count */
#define ISI_M_QUAD      MIO_M_QUAD   /**< Quad count */
#define ISI_M_RESET     MIO_M_RESET  /**< Referencing to zero turn on */
#define ISI_M_NOPRTY    MIO_M_NOPRTY     /**< no Parity */
#define ISI_M_EVEN      MIO_M_EVEN   /**< even parity */
#define ISI_M_ODD       MIO_M_ODD    /**< odd parity */
#define ISI_M_BIN       MIO_M_BIN    /**< binary data format */
#define ISI_M_GRAY      MIO_M_GRAY   /**< Gray-Code data format */
#define ISI_M_AUTOLD    MIO_M_AUTOLD     /**< Autoreload with ReferenceCompare */
/** @} */

/**
 * @name ISI-specific error
 * @{
 */

#define ISI_E_CLOCK MIO_E_CLOCK  /**< Fraction of the SSI clock line */
/** @} */

/**
 * @name Available commands
 * @{
 */

#define ISI_CMD_SETREF      MIO_CMD_SETREF   /**< Set reference value */
#define ISI_CMD_SETFREQ     MIO_CMD_SETFREQ  /**< Set SSI-clock rate */
#define ISI_CMD_SETDLEN     MIO_CMD_SETDLEN  /**< Set SSI word size */
#define ISI_CMD_RESET       MIO_CMD_RESET    /**< Reset the INC/SSI modules of the both channels */
#define ISI_CMD_ZINIT       MIO_CMD_ZINIT    /**< Read zero initiator */
#define ISI_CMD_SETINTERVAL MIO_CMD_SETINTERVAL  /**< Set clock break in us */
/** @} */
/** @} */

#ifdef __cplusplus
}
#endif

#endif
