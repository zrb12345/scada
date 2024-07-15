/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     mio.h
* @author   Holl
* @brief    IO-Driver Handler
*           This file contains all definitions and declarations exported by
*           the IO-Driver Handler, that could be used by modules running on
*           another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef MIO__H
#define MIO__H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ASMLANGUAGE

#include <mtypes.h>
#include <time.h>
#include <svi.h>
#include <msys.h>
#include <ufb.h>

#endif                                  /* _ASMLANGUAGE */

/**
 * @addtogroup MIO-DEF
 * @{
 */
#define MIO_MAXCARDNB   32000    /**< Maximum card number */
#define MIO_MAXSCARD    16  /**< Maximum cards per station */
#define MIO_MAXNET      8   /**< @deprecated Maximum networks per fieldbus */
#define MIO_MAXSTATION  16  /**< Maximum stations per M1 */
#define MIO_MAXSLOT     (MIO_MAXSCARD * MIO_MAXSTATION)  /**< Total slots on controller */
#define MIO_PROTVERS    2   /**< Version of SMI-Protocol */
#define MIO_CNAMELEN    20  /**< Size of card name without '\0' termination */
#define MIO_CNAMELEN_A  ((MIO_CNAMELEN + 1 + 3) & 0xfffffffc)    /**< MIO_CNAMELEN + '\0' + aligned */
#define MIO_PRODNBLEN   10  /**< Size of serial number without '\0' termination */
#define MIO_PRODNBLEN_A ((MIO_PRODNBLEN + 1 + 3) & 0xfffffffc)   /**< MIO_PRODNBLEN + '\0' + aligned */
#define MIO_INFOLEN     199 /**< Size of card info */
#define MIO_INFOLEN_A   ((MIO_INFOLEN + 1 + 3) & 0xfffffffc)     /**< MIO_INFOLEN + '\0' + aligned */
#define MIO_ENT_CDI     100 /**< Internally used */

/**
 * @name Possible values for MIO_DRV.Mode
 * @{
 */

#define MIO_REAL        1   /**< IO-Module is present */
#define MIO_VIRTUAL     2   /**< IO-Module is virtual */
#define MIO_VIRTSIM     3   /**< @deprecated IO-Module has simulated values */
#define MIO_REALFB      4   /**< IO-Module at fieldbus */
#define MIO_VIRTUALRW   5   /**< Virtual IO-Module, writable inputs */
#define MIO_REALSRV     6   /**< IO-Module connected to a service */
#define MIO_VIRTUALSRV  7   /**< IO-Module connected to a service */
/** @} */

/**
 * @anchor MIO_T_
 */
/**
 * @name Possible I/O card types
 * @{
 */

#define MIO_T_MP213     1   /**< Module of type MP213 */
#define MIO_T_MP2XX     1   /**< Module of type MP2XX */
#define MIO_T_DI216     2   /**< Module of type DI216 */
#define MIO_T_DO216     3   /**< Module of type DO216 */
#define MIO_T_DI232     4   /**< Module of type DI232 */
#define MIO_T_DO232     5   /**< Module of type DO232 */
#define MIO_T_AI204     6   /**< Module of type AI204 */
#define MIO_T_AO202     7   /**< Module of type AO202 */
#define MIO_T_ISI202    8   /**< Module of type ISI202 */
#define MIO_T_AIO288    9   /**< Module of type AIO288 */
#define MIO_T_FBM201    10  /**< Module of type FM201 */
#define MIO_T_FBS202    11  /**< Module of type FS202 */
#define MIO_T_CM202     12  /**< Module of type CM202 */
#define MIO_T_BEM201    13  /**< Module of type BEM201 */
#define MIO_T_BES202    14  /**< Module of type BES202 */
#define MIO_T_ACR222    15  /**< Module of type ACR222 */
#define MIO_T_ME203     16  /**< Module of type ME203 */
#define MIO_T_CS200     17  /**< Module of type CS200 */
#define MIO_T_RS204     18  /**< Module of type RS204 */
#define MIO_T_DMS202    19  /**< Module of type DMS202 */
#define MIO_T_NT250     20  /**< Module of type NT250 */
#define MIO_T_DIO216    21  /**< Module of type DIO216 */
#define MIO_T_DI212     24  /**< Module of type DI212 */
#define MIO_T_DIO264_C  25  /**< Module of type DIO16/32/48/64_C */
#define MIO_T_BS2XX     26  /**< Bus module of type BS2XX */
#define MIO_T_FM21X     27  /**< Module of type FM211, FM212 */
#define MIO_T_FM2XX     27  /**< Module of type FM211, FM212, FM221, FM222 */
#define MIO_T_FS21X     28  /**< Module of type FS211, FS212 */
#define MIO_T_FS2XX     28  /**< Module of type FS211, FS212, FS221, FS222 */
#define MIO_T_ES200     29  /**< Module of type ES200 */
#define MIO_T_DPM200    30  /**< Module of type DPM200 */
#define MIO_T_CNT204    31  /**< Module of type CNT204 */
#define MIO_T_PTAI216   32  /**< Module of type PTAI216 */
#define MIO_T_PWM202    33  /**< Module of type PWM202 */
#define MIO_T_TCO216_C  34  /**< Module of type TCO216-C */
#define MIO_T_AO208     35  /**< Module of type AO208 */
#define MIO_T_DIO280    36  /**< Module of type DIO248/64/80 */
#define MIO_T_DIO2XX    36  /**< Module of type DIO248/64/80 */
#define MIO_T_TTL264    37  /**< Module of type TTL264 */
#define MIO_T_SEM201    38  /**< Module of type SEM201 */
#define MIO_T_IOP201    39  /**< Module of type IOP201 */
#define MIO_T_BSI200    40  /**< Module of type BSI200 (no drv) */
#define MIO_T_MTS200    41  /**< Module of type MTS200 (no drv) */
#define MIO_T_PCFS212   42  /**< Module of type PCFS212 */
#define MIO_T_DNM201    43  /**< Module of type DNM201 */
#define MIO_T_AI20XSI   44  /**< Module of type AI20X/SI */
#define MIO_T_AO20XSI   45  /**< Module of type AO20X/SI */
#define MIO_T_WT305E    46  /**< Module of type WT305e (no drv) */
#define MIO_T_EM203     47  /**< Module of type EM203 */
#define MIO_T_CT3XX     48  /**< Module of type CT3XX */
#define MIO_T_MPC2XX    49  /**< Module of type MPC2XX */
#define MIO_T_MX2XX     50  /**< Module of type MX2XX */
#define MIO_T_WT3XX     51  /**< Module of type WT3XX (no drv) */
#define MIO_T_PCM201    52  /**< Internal Module (no drv) */
#define MIO_T_DIO232    53  /**< Module of type DIO232 */
#define MIO_T_BET200    54  /**< Internal Module (no drv) */
#define MIO_T_PN201     55  /**< Module of type PN201 */
#define MIO_T_NT255     56  /**< Module of type NT255 */
#define MIO_T_MBM201    57  /**< Module of type Modbus Master */
#define MIO_T_WT2XX     58  /**< Module of type WT2XX (no drv) */
#define MIO_T_CT2XX     59  /**< Module of type CT2XX */
#define MIO_T_DA3284C   60  /**< Module of type DA3284C */
#define MIO_T_AIC2XX    61  /**< Module of type AIC2XX */
#define MIO_T_CAN       62  /**< Logical CAN Module */
#define MIO_T_ECAT201   63  /**< Module of type ECAT201 */
#define MIO_T_TI214     64  /**< Module of type TI214 */
#define MIO_T_EVALBOARD 65  /**< HW Evaluation Board */
#define MIO_T_PN23      66  /**< PCI module of type PN23 ProfiNet IRT */
#define MIO_T_OT100     67  /**< OT100 Terminal */
#define MIO_T_SLC284    68  /**< Module of type SLC284 */
#define MIO_T_SDI208    69  /**< Module of type SDI208 */
#define MIO_T_SDO204    70  /**< Module of type SDO204 */
#define MIO_T_IPX1400   71  /**< Module of type IPX1400 */
#define MIO_T_IPE1400   72  /**< Module of type IPE1400 */
#define MIO_T_IPD1400   73  /**< Module of type IPD1400 */
#define MIO_T_PES1400   74  /**< Module of type PES1400 */
#define MIO_T_IPEB1400  75  /**< Module of type IPEB1400 */
#define MIO_T_IPEK1400  76  /**< Module of type IPEK1400 */
#define MIO_T_ETH2X     77  /**< Module of type ETH2X */
#define MIO_T_DOR2XX    78  /**< Module of type DOR206 */
#define MIO_T_DMW200    79  /**< Module of Drive-Middleware */
#define MIO_T_SERCOS    80  /**< Module of Drive-Middleware */
#define MIO_T_AP211     81  /**< Module of type AP21X */
#define MIO_T_MH2XX     82  /**< Module of type MH2XX */
#define MIO_T_MMSCNLT   83  /**< Module of type MMS-Client */
#define MIO_T_SFS240C   84  /**< Module of type SFS240C */
#define MIO_T_FCS2XX    85  /**< Module of type FCS2xx */
#define MIO_T_CT1300    86  /**< Module of type CT1300 */
#define MIO_T_OT1300    87  /**< Module of type OT1300 */
#define MIO_T_AI208SI   88  /**< Module of type AI208/SI */
#define MIO_T_GMP232    89  /**< Module of type GMP232 */
#define MIO_T_BCP200    90  /**< Module of type BCP200 */
#define MIO_T_BCH200    91  /**< Module of type BCH200 */
#define MIO_T_EM213     92  /**< Module of type EM213 */
#define MIO_T_ECS200    93  /**< Module of type ECS200 */
#define MIO_T_BCP202    94  /**< Module of type BCP202 */
#define MIO_T_BCH202    95  /**< Module of type BCH202 */
#define MIO_T_BCR202    96  /**< Module of type BCR202 */
#define MIO_T_MC2XX     97  /**< Module of type MC2XX */
#define MIO_T_MB201     98  /**< Service of type MBUS */
#define MIO_T_GIO2XX    99  /**< Module of type GIO2XX */
#define MIO_T_GSP274    100 /**< Module of type GSP274 */
#define MIO_T_S60870_5  101 /**< Module of type IEC 60870-5-104 server */
#define MIO_T_AIO2XX    102 /**< Module of type AIO2XX */
#define MIO_T_SVMXXX    103 /**< Module of type SVMXXX */
#define MIO_T_OPCUAS    104 /**< Module of type OPCUAS */
#define MIO_T_BPC600    105 /**< Module of type BCP600 */
#define MIO_T_STMI3XX   106 /**< Module of type STMI3XX */
#define MIO_T_GM260     107 /**< Module of type GM260 */
#define MIO_T_CPC2XX    108 /**< CompactPLC of type CPC2xx */
#define MIO_T_CAIO284   109 /**< AIO284 for CPC2XX */
#define MIO_T_CISI2XX   110 /**< ISI2XX for CPC2XX */
#define MIO_T_CDIO2XX   111 /**< DIO2XX for CPC2XX */
#define MIO_T_GM2XX     112 /**< Module of type GM2XX (GM210 and GM230) */
#define MIO_T_OT1200    113 /**< Module of type OT1200 */
#define MIO_T_MR2XX     114 /**< Module of type MR2XX */
#define MIO_T_DIOXXC    115 /**< Module of type DIOxx-C Standalone CAN-Modules */
#define MIO_T_AIO2XXSI  116 /**< Module of type AIO2XX/SI */
#define MIO_T_DNP3      117 /**< Service of type DNP3 */
#define MIO_T_SCT202    118 /**< Module of type SCT202 */
#define MIO_T_GMP232X   119 /**< Module of type GMP232/X */
#define MIO_T_PVA2XX    120 /**< Module of type PVA2XX */
#define MIO_T_TSTDRV    254 /**< Generic ID for test drivers */
/** @} */

/**
 * Possible values for MIO_CARDINF.Variant and MIO_EXTCDINF.Variant
 */
/**
 * @name in case of type MIO_T_MP2XX
 * @{
 */

#define MIO_V_MP213     0   /**< Module of type MP213 */
#define MIO_V_MP226     1   /**< Module of type MP226 */
#define MIO_V_MP236     2   /**< Module of type MP236 */
#define MIO_V_MP240     3   /**< Module of type MP240 */
#define MIO_V_MP213EW   0x20     /**< Module of type MP213/EW */
#define MIO_V_MP226EW   0x21     /**< Module of type MP226/EW */
/** @} */

/**
 * @name in case of type MIO_T_ME203
 * @{
 */

#define MIO_V_ME203     0   /**< Module of type ME203 */
#define MIO_V_ME203N    1   /**< Module of type ME203/N */
#define MIO_V_ME203C    2   /**< Module of type ME203/C */
#define MIO_V_ME203CN   3   /**< Module of type ME203/CN */
#define MIO_V_ME203E    4   /**< Module of type ME203/E */
#define MIO_V_ME203EN   5   /**< Module of type ME203/EN */
#define MIO_V_ME203CNW  0x23     /**< Module of type ME203/CNW */
/** @} */

/**
 * @name WT/CT Version in case of type WT_TYPE_XXX for 200 and 300 series.
 * @{
 */

#define MIO_VF_DISPLAYMASK  0x0f     /**< Filter for display type */
#define MIO_VF_DIMMABLE     0x10     /**< Dimmable display */
#define MIO_VF_IRTOUCH      0x40     /**< IR Touch */
#define MIO_VF_ALARM        0x80     /**< Has extern alarm IOs */
#define MIO_V_WT305         0    /**< Module of type WT305 1/4 VGA */
#define MIO_V_WT306         1    /**< Module of type WT306 VGA */
#define MIO_V_WT310         2    /**< Module of type WT310 */
#define MIO_V_WT312         3    /**< Module of type WT312 */
#define MIO_V_WT315         4    /**< Module of type WT315 */
#define MIO_V_WT317         5    /**< Module of type WT317 */
#define MIO_V_WT319         6    /**< Module of type WT319 */
#define MIO_V_WT305V        7    /**< Module of type WT305V */
#define MIO_V_CT305         MIO_V_WT305  /**< Module of type CT305 1/4 VGA */
#define MIO_V_CT306         MIO_V_WT306  /**< Module of type CT306 VGA */
#define MIO_V_CT310         MIO_V_WT310  /**< Module of type CT310 */
#define MIO_V_CT312         MIO_V_WT312  /**< Module of type CT312 */
#define MIO_V_CT315         MIO_V_WT315  /**< Module of type CT315 */
#define MIO_V_CT317         MIO_V_WT317  /**< Module of type CT317 */
#define MIO_V_CT319         MIO_V_WT319  /**< Module of type CT319 */
#define MIO_V_CT305V        MIO_V_WT305V     /**< Module of type CT305 VGA */
#define MIO_V_WT205         MIO_V_WT305  /**< Module of type WT205 1/4 VGA */
#define MIO_V_WT205V        MIO_V_WT305V     /**< Module of type WT205 VGA */
#define MIO_V_CT205         MIO_V_WT205  /**< Module of type CT205 1/4 VGA */
#define MIO_V_CT205V        MIO_V_WT205V     /**< Module of type CT205 VGA */
#define MIO_V_CT205M        (MIO_V_CT205V | MIO_VF_DIMMABLE | MIO_VF_ALARM)
/** @} */

/**
 * @name in case of type MIO_T_MPC2XX
 * @{
 */

#define MIO_V_MPC240    0   /**< Module of type MPC240 */
#define MIO_V_MPC265    1   /**< Module of type MPC265 */
#define MIO_V_MPC270    2   /**< Module of type MPC270 */
#define MIO_V_MPC293    3   /**< Module of type MPC293 */
#define MIO_V_MPC240CW  0x20     /**< Module of type MPC240/CW */
#define MIO_V_MPC265CW  0x21     /**< Module of type MPC265/CW */
#define MIO_V_MPC270CW  0x22     /**< Module of type MPC270/CW */
#define MIO_V_MPC293CW  0x23     /**< Module of type MPC293/CW */
/** @} */

/**
 * @name in case of type MIO_T_MPC2XX (MPE2xx CPUs)
 * @{
 */

#define MIO_V_MPE2XX    0x10     /**< Module of type MPE2xx */
#define MIO_V_MPE240    0x10     /**< Module of type MPE240 */
#define MIO_V_MPE265    0x11     /**< Module of type MPE265 */
#define MIO_V_MPE270    0x12     /**< Module of type MPE270 */
/** @} */

/**
 * @name in case of type MIO_T_MX2XX
 * @{
 */

#define MIO_VF_MX2xx_N  0x01     /**< MX2xx bitmask: has integrated power supply */
#define MIO_VF_MX2xx_CW 0x20     /**< MX2xx bitmask: is a cold weather variant */
#define MIO_V_MX213     0x00     /**< MX2xx bitmask: Module of type MX213 */
#define MIO_V_MX213N    (MIO_V_MX213 | MIO_VF_MX2xx_N)
#define MIO_V_MX213CW   (MIO_V_MX213 | MIO_VF_MX2xx_CW)
#define MIO_V_MX213NCW  (MIO_V_MX213 | MIO_VF_MX2xx_N | MIO_VF_MX2xx_CW)
#define MIO_V_MX207     0x02     /**< MX2xx bitmask: Module of type MX207 */
#define MIO_V_MX207N    (MIO_V_MX207 | MIO_VF_MX2xx_N)
#define MIO_V_MX207CW   (MIO_V_MX207 | MIO_VF_MX2xx_CW)
#define MIO_V_MX207NCW  (MIO_V_MX207 | MIO_VF_MX2xx_N | MIO_VF_MX2xx_CW)
#define MIO_V_MX220     0x04     /**< MX2xx bitmask: Module of type MX220 */
#define MIO_V_MX220N    (MIO_V_MX220 | MIO_VF_MX2xx_N)
#define MIO_V_MX220CW   (MIO_V_MX220 | MIO_VF_MX2xx_CW)
#define MIO_V_MX220NCW  (MIO_V_MX220 | MIO_VF_MX2xx_N | MIO_VF_MX2xx_CW)
/** @} */

/**
 * @name in case of type MIO_T_MH2XX
 * @{
 */

#define MIO_V_MH212S    0   /**< Module of type MH212/S */
#define MIO_V_MH212     1   /**< Module of type MH212 */
/** @} */

/**
 * @name in case of type MIO_T_MC2XX
 * @{
 */

#define MIO_V_MC205 0       /**< Module of type MC205 (600MHz) */
#define MIO_V_MC210 1       /**< Module of type MC210 (1600MHz) */
/** @} */

/**
 * @name in case of type MIO_T_CPC2XX
 * @{
 */

#define MIO_V_CPC210    0x01     /**< Module of type CPC210 */
/** @} */

/**
 * @name in case of type MIO_T_MR2XX
 * @{
 */

#define MIO_V_MR201 0x00    /**< Module of type MR201 */
#define MIO_V_MR202 0x01    /**< Module of type MR202 */
/** @} */

/**
 * @name in case of type MIO_T_AI204 and MIO_T_AI20XSI
 * @{
 */

#define AI_MV_SI    0x10    /**< Variant code ID of the SI */
#define AI_MV_1CHAN 0       /**< 1 channel available */
#define AI_MV_2CHAN 1       /**< 2 channels available */
#define AI_MV_4CHAN 2       /**< 4 channels available */
#define AI_MV_CHMSK 0x03    /**< Mask for the variant code */
/** @} */

/**
 * @name in case of type MIO_T_AIC212
 * @{
 */

#define AIC_MV_SI   0x10    /**< Variant code ID of the SI */
/** @} */

/**
 * @name in case of type MIO_T_AIO288
 * @{
 */

#define AIO_MV_1214BIT  0   /**< 12 Bit AI and 14 Bit AO */
#define AIO_MV_1414BIT  1   /**< 14 Bit AI and 14 Bit AO */
#define AIO_MV_1416BIT  2   /**< 14 Bit AI and 16 Bit AO */
#define AIO_MV_MSK      0x0f     /**< Mask for variant code */
#define AIO_MV_GALV     0x10     /**< Galvanic isolation */
/** @} */

/**
 * @name in case of type MIO_T_AO202 and MIO_T_AO20XSI
 * @{
 */

#define AO_MV_1CHAN     0x0 /**< 1 channel available */
#define AO_MV_2CHAN     0x1 /**< 2 channels available */
#define AO_MV_SI_2CHAN  0x11     /**< 2 SI-channels available */
#define AO_MV_SI_4CHAN  0x12     /**< 4 SI-channels available */
#define AO_MV_SI        0x10     /**< 4 channels available */
#define AO_MV_CHMSK     0x13     /**< Channel mask for the variant code */
/** @} */

/**
 * @name in case of type MIO_T_BEM2xx
 * @{
 */

#define BEM_MV_LVDS 0x20    /**< Variant code of BEM211 */
/** @} */

/**
 * @name in case of type MIO_T_BES2xx
 * @{
 */

#define BES_MV_NOPS     0x01     /**< Without  power supply */
#define BES_MV_WDOG     0x10     /**< Inclusive watchdog and live-register */
#define BES_MV_LVDS     0x30     /**< New LVDS BES */
#define BES_MV_LVDS_JC  0x40     /**< New LVDS BES with jitter cleaner */
#define BES_MV_MSK      0x70     /**< Variant mask */
/** @} */

/**
 * @name in case of type MIO_T_CNT204
 * @{
 */

#define CNT_MV_PLAIN    0   /**< CNT204 */
#define CNT_MV_H        1   /**< CNT204/H - HTL Input level */
#define CNT_MV_R        2   /**< CNT204/R - RS422 Input level */
#define CNT_MV_MSK      0x03     /**< Mask for the variant code */
/** @} */

/**
 * @name in case of type MIO_T_DI232
 * @{
 */

#define DI_MV_FAST  0x01    /**< Fast inputs */
#define DI_MV_NPN   0x02    /**< NPN inputs */
/** @} */

/**
 * @name in case of type MIO_T_FCS2XX
 * @{
 */

#define FCS_MV_MSK  0x03    /**< Mask for the variant code */
/** @} */

/**
 * @name in case of type MIO_T_FM2XX
 * @{
 */

#define FM_MV_FM211     0   /**< 1 x full duplex via fibre optic cable */
#define FM_MV_FM212     1   /**< 2 x full duplex via fibre optic cable */
#define FM_MV_FM221     0x10     /**< 1 x full duplex via multimode cable */
#define FM_MV_FM222     0x11     /**< 2 x full duplex via multimode cable */
#define FM_MV_MSK       0x3 /**< Mask for the variant code */
#define FM_MV_MM_MSK    0x11
/** @} */

/**
 * @name in case of type MIO_T_FS2XX
 * @{
 */

#define FS_MV_FS211     0   /**< 1 x Full Duplex via fibre optic cable */
#define FS_MV_FS211N    1   /**< 1 x Full Duplex via fibre optic cable with power supply */
#define FS_MV_FS212     2   /**< 2 x Full Duplex via fibre optic cable */
#define FS_MV_FS212N    3   /**< 2 x Full Duplex via fibre optic cable with power supply */
#define FS_MV_FS221     0x10     /**< 1 x Full Duplex via multimode cable */
#define FS_MV_FS221N    0x11     /**< 1 x Full Duplex via multimode cable with power supply */
#define FS_MV_FS222     0x12     /**< 2 x Full Duplex via multimode cable */
#define FS_MV_FS222N    0x13     /**< 2 x Full Duplex via multimode cable with power supply */
#define FS_MV_MSK       0x03     /**< Mask for the variant code */
/** @} */

/**
 * @name in case of type MIO_T_GIO2XX and MIO_T_AIO2XX and MIO_T_AIO2XXSI
 * @{
 */

#define GIO_MV_MSK          0x0f     /**< Mask for variant code (Upper nibble is reserved for driver) */
#define GIO_MV_GIO212       0x01     /**< Module of type GIO212 */
#define AIO_MV_AIO208       0x01     /**< Module of type AI208 */
#define AIO_MV_AIO216       0x02     /**< Module of type AI216 */
#define AIO_MV_AIO202_SI    0x01     /**< Module of type AIO202/SI */
#define AIO_MV_AIO204_SI    0x02     /**< Module of type AIO204/SI */
#define AIO_MV_AIO208_SI    0x03     /**< Module of type AIO208/SI */
/** @} */

/**
 * @name in case of type MIO_T_GM2XX
 * @{
 */

#define GM2XX_MV_GM230  0x00     /**< Variant code GM230 */
#define GM2XX_MV_GM210  0x01     /**< Variant code GM210 */
/** @} */

/**
 * @name in case of type MIO_T_ISI2xx
 * @{
 */

#define MIO_V_ISI222            0x81     /**< Module of type ISI222 */
#define ISI202_MV_3MHZ          0x10     /**< 3MHz INC, no SSI, 12 bit AO */
#define ISI202_MV_5MHZ          0x30     /**< 5MHz INC, no SSI, 12 bit AO */
#define ISI202_MV_MHZMSK        0x30
#define ISI202_MV_12BIT         0x00     /**< Analog output with 12 Bit D/A */
#define ISI202_MV_14BIT         0x01     /**< Analog output with 14 Bit D/A */
#define ISI202_MV_MSK           0x0f     /**< Mask for the variant code */
#define ISI202_MV_3MHZ_NOSSI    0x10     /**< 3MHz, no SSI */
#define ISI222_MV_3MHZ          0x10     /**< 3MHZ ISI202, no SSI */
#define ISI222_MV_5MHZ          0x30     /**< 5MHz INC, no SSI, 12 bit AO */
#define ISI222_MV_8MHZ          0xC0     /**< 8MHz ISI222, no SSI */
#define ISI222_MV_MHZMSK        0xF0
#define ISI222_MV_14BIT         0x81     /**< Analog output with 14 Bit D/A */
#define ISI222_MV_MSK           0x0f     /**< Mask for the variant code */
/** @} */

/**
 * @name in case of type MIO_T_PCFS212
 * @{
 */

#define PCFS_MV_FS212   2   /**< 2 x Full Duplex via fibre optic cable */
/** @} */

/**
 * @name in case of type MIO_T_PTAI216
 * @{
 */

#define PTAI_MV_MSK 0x00    /**< Mask for the variant code */
/** @} */

/**
 * @name in case of type MIO_T_RS204
 * @{
 */

#define RS_MV_2852      0x01     /**< Enhanced UART (128 Byte FIFO) */
#define RS_MV_24MHZ     0x02     /**< 24 MHz Quartz */
#define RS_MV_FULL232   0x04     /**< COM1 is full RS232, no RS422 */
#define RS_MV_TTY       0x08     /**< COM2 is only TTY, no RS232/RS422 */
#define RS_MV_EXTPOW    0x10     /**< External power, galvanic isolation */
/** @} */

/**
 * @name in case of type MIO_T_TI214
 * @{
 */

#define TI_MV   0x00        /**< Variante TI214 */
#define TI_MV_2 0x01        /**< Variante TI214/2 */
/** @} */

/**
 * @name in case of type MIO_T_PVA2XX
 * @{
 */

#define PVA_MV_PVA204   0x00     /**< Module of type PVA204 */
#define PVA_MV_PVA208   0x01     /**< Module of type PVA208 */
/** @} */

/**
 * @name in case of type MIO_T_DIOXXC
 * @{
 */

#define MIO_V_DIO43C    0x00     /**< Module of type DIO43-C */
#define MIO_V_DIO62C    0x01     /**< Module of type DIO62-C */
/** @} */

/**
 * @name in case of type MIO_T_GM2XX
 * @{
 */

#define GM2XX_MV_MSK    0x0f     /**< Mask for variant code (Upper nibble is reserved for driver) */
#define MIO_V_GM230     0x00     /**< Module of type GM230 */
#define MIO_V_GM210     0x01     /**< Module of type GM210 */
/** @} */

/**
 * @name in case of type MIO_T_GMP232X
 * @{
 */

#define MIO_V_GMP232_1  0x01     /**< Module of type GMP232/1 */
#define MIO_V_GMP232_2  0x02     /**< Module of type GMP232/2 */
#define MIO_V_GMP232_3  0x03     /**< Module of type GMP232/3 */
#define MIO_V_GMP232_4  0x04     /**< Module of type GMP232/4 */
/** @} */

/**
 * @name Function codes
 * @{
 */

#define MIO_FC_MX220    140 /**< MX2xx with LX800 processor (>=140) */
#define MIO_FC_MX220_2  150 /**< MX2xx with SMSC LAN9420 Controller (>=150) */
/** @} */

/**
 * @anchor MIO_CATEG_
 */
/**
 * @name Possible values for MIO_CARDINF.Category, MIO_CHANINF.Category and MIO_EXTCDINF.Category
 * @{
 */

#define MIO_CATEG_DI        0x00000001   /**< Card/Chan with DI capability */
#define MIO_CATEG_DO        0x00000002   /**< Card/Chan with DO capability */
#define MIO_CATEG_AI        0x00000004   /**< Card/Chan with AI capability */
#define MIO_CATEG_AO        0x00000008   /**< Card/Chan with AO capability */
#define MIO_CATEG_INC       0x00000010   /**< Card/Chan with INC capability */
#define MIO_CATEG_SSI       0x00000020   /**< Card/Chan with SSI capability */
#define MIO_CATEG_DRIVE     0x00000040   /**< Card/Chan for drives */
#define MIO_CATEG_INTERFACE 0x00000080   /**< Card/Chan with an interface */
#define MIO_CATEG_COUNT     0x00000100   /**< Card/Chan with CNT capability */
#define MIO_CATEG_TRIGG     0x00000200   /**< Card/Chan with TRG capability */
#define MIO_CATEG_PWM       0x00000400   /**< Card/Chan with PWM capability */
#define MIO_CATEG_FREQ      0x00000800   /**< Card/Chan with FREQ capability */
#define MIO_CATEG_STAT      0x00001000   /**< Card/Chan with Status capability */
#define MIO_CATEG_CNTRL     0x00002000   /**< Card/Chan with Control capability */
#define MIO_CATEG_SERCOS    0x00004000   /**< Card/Chan with SERCOS capability */
#define MIO_CATEG_TIME      0x00008000   /**< Card/Chan with time measure capability */
#define MIO_CATEG_DIFF      0x00010000   /**< Card with time difference measure capability */
#define MIO_CATEG_VELOCITY  0x00020000   /**< Card with velocity measure capability */
#define MIO_CATEG_BES       0x04000000   /**< Card is bus extension slave */
#define MIO_CATEG_BEM       0x08000000   /**< Card is bus extension master */
#define MIO_CATEG_CPU       0x10000000   /**< CPU module */
#define MIO_CATEG_FBS       0x20000000   /**< Card with Fastbus slave capability */
#define MIO_CATEG_FBM       0x40000000   /**< Card with Fastbus master capability */
#define MIO_CATEG_FB        0x80000000   /**< Card with Fieldbus capability */
/** @} */

/**
 * @anchor MIO_FLG_
 */
/**
 * @name Possible values for MIO_CARDINF.Flags, MIO_CHANINF.Flags and MIO_EXTCDINF.Flags
 * @{
 */

#define MIO_FLG_READ        0x00000001   /**< Card/Chan is readable */
#define MIO_FLG_WRITE       0x00000002   /**< Card/Chan is writable */
#define MIO_FLG_RW          0x00000003   /**< Card/Chan is read-/writable */
#define MIO_FLG_ERROR       0x00000004   /**< Card/Chan has error interrupt */
#define MIO_FLG_EVENT       0x00000008   /**< Card/Chan has event interrupt */
#define MIO_FLG_SELECT      0x00000010   /**< Card/Chan has function for select */
#define MIO_FLG_BADIO       0x00000400   /**< Card has been deactivated because of fastbus break down */
#define MIO_FLG_FNLED       0x00000800   /**< Card has function for LED flashing */
#define MIO_FLG_BCHECK      0x00001000   /**< Card supports IO-Bus check */
#define MIO_FLG_ACHECK      0x00002000   /**< Card supports Alive check */
#define MIO_FLG_WDOG        0x00004000   /**< Card has watchdog to be triggered */
#define MIO_FLG_FRMWARE     0x00008000   /**< Card has firmware or updatable logic on it */
#define MIO_FLG_FIFOFLUSH   0x00010000   /**< Driver supports MPC FIFO flush */
#define MIO_FLG_COMPATIBLE  0x00020000   /**< Card in compatibility mode */
#define MIO_FLG_IDREG       0x00040000   /**< Card has functions for Read/Write IdReg over DoCmd */
#define MIO_FLG_PNP         0x00080000   /**< Card is hotplug able */
#define MIO_FLG_CUSTOMERID  0x00100000   /**< Customer ID */
#define MIO_FLG_SVAR        0x00200000   /**< Card has service variables */
#define MIO_FLG_HWPIREADY   0x00400000   /**< Card is ready for hardware process image */
#define MIO_FLG_HWPISUPP    0x00800000   /**< Card supports hardware process image */
#define MIO_FLG_FIFOVAR     0x01000000   /**< Card supports variable FIFO flush address */
#define MIO_FLG_CHPISUPP    0x02000000   /**< Card supports selected channel process image */
/** @} */

/**
 * @name Possible values for MIO_EXTCDINF.Attribute and MIO_GETBPINF_R.Attribute
 * @{
 */

#define MIO_ATTR_NODRV  0x0080   /**< Attribute no driver required */
/** @} */

/**
 * @name Possible values for MIO_X2CHANINFO.ExtChFlags and MIO_CHAN_RANGE.ExtChFlags
 * @{
 */

#define MIO_EXTFLG_NOTPRESENT   0x0001   /**< Channel is no present at module */
#define MIO_EXTFLG_DISABLED     0x0002   /**< Channel is disabled */
#define MIO_EXTFLG_PROCIMG_NO   0x0004   /**< Channel is not part of process image */
#define MIO_EXTFLG_PROCIMG_IN   0x0008   /**< Channel is a process image input */
#define MIO_EXTFLG_PROCIMG_OUT  0x0010   /**< Channel is a process image output */
/** @} */

/**
 * @name Possible values for MIO_DOCMD_C.ParamDesc
 * @{
 */

#define MIO_P_VAL       0x80000000   /**< Parameter passed as value */
#define MIO_P_REF       0x00000000   /**< Parameter passed as pointer */
#define MIO_P_IN        0x40000000   /**< Input parameter */
#define MIO_P_OUT       0x20000000   /**< Output parameter */
#define MIO_P_INOUT     0x60000000   /**< Input/Output parameter */
#define MIO_P_LENMSK    0x0000ffff   /**< Mask for size */
/** @} */

/**
 * @name Name of possible Signal Types; die name part of the symbolic SVI address
 * @{
 */

#define MIO_TN_DI           "DI"     /**< Digital input */
#define MIO_TN_DO           "DO"     /**< Digital output */
#define MIO_TN_AI           "AI"     /**< Analog input */
#define MIO_TN_AO           "AO"     /**< Analog Output */
#define MIO_TN_INC          "INC"    /**< INC input */
#define MIO_TN_SSI          "SSI"    /**< SSI input */
#define MIO_TN_COUNT        "CNT"    /**< Counter input */
#define MIO_TN_TRIGG        "TRG"    /**< Trigger input */
#define MIO_TN_PWM          "PWM"    /**< Pulse width output */
#define MIO_TN_FREQ         "FRQ"    /**< Frequency output */
#define MIO_TN_STAT         "STA"    /**< Status input */
#define MIO_TN_CNTRL        "CTL"    /**< Control output */
#define MIO_TN_DRIVE        "DRV"    /**< Drive type */
#define MIO_TN_SERCOS       "SER"    /**< SERCOS type */
#define MIO_TN_INTERFACE    "IF"     /**< Interface type */
#define MIO_TN_TIME         "TM"     /**< Time measure */
#define MIO_TN_VELOCITY     "VEL"    /**< Velocity measure */
/** @} */

/**
 * @anchor MIO_Return_Codes
 */

/**
 * @name Possible return codes from MIO functions
 * @{
 */

#define MIO_ER_OK               0    /**< No error */
#define MIO_ER_FAIL             -1   /**< General error */
#define MIO_ER_BADCHAN          -2   /**< Channel not valid */
#define MIO_ER_BADMODE          -3   /**< Mode or Type not valid */
#define MIO_ER_BUSY             -4   /**< Device is busy */
#define MIO_ER_BADTEST          -5   /**< HwTest failed */
#define MIO_ER_BADCMD           -6   /**< Command not supported */
#define MIO_ER_BADIDREG         -7   /**< ID Register not valid */
#define MIO_ER_BADCONF          -8   /**< Bad configuration */
#define MIO_ER_BADPARM          -9   /**< Bad parameter */
#define MIO_ER_TIMEOUT          -10  /**< Timeout */
#define MIO_ER_BADFUNC          -11  /**< Function not supported */
#define MIO_ER_BADWRITE         -12  /**< Error in write */
#define MIO_ER_NOWRITE          -13  /**< Write on input channel */
#define MIO_ER_BADCALIB         -14  /**< Bad calibration data */
#define MIO_ER_BADPLAUS         -15  /**< Plausibility test failed */
#define MIO_ER_BADREAD          -16  /**< Error in read */
#define MIO_ER_REBOOT           -17  /**< Reboot is required */
#define MIO_ER_DISABLED         -18  /**< Channel is disabled */
#define MIO_ER_WRONGSTATE       -19  /**< Invalid state for this function */
#define MIO_ER_BADCARD          -20  /**< Card not valid */
#define MIO_ER_BUSFAIL          -21  /**< Bus error */
#define MIO_ER_NODATA           -22  /**< No data available */
#define MIO_ER_OUTOFMEM         -23  /**< No memory available */
#define MIO_ER_NOFPTASK         -24  /**< No floating point operations allowed */
#define MIO_ER_MODNOTINIT       -25  /**< Module is not initialized */
#define MIO_ER_BADHANDLE        -26  /**< Bad handle */
#define MIO_ER_LSTINFPGAFULL    -27  /**< The list in the FPGA is full */
#define MIO_ER_WRONGITEMSIZE    -28  /**< The DMA item has a wrong size */
#define MIO_ER_SEMCREATE        -29  /**< Error creating a semaphore */
#define MIO_ER_SEMTAKE          -30  /**< Error / Timeout taking a semaphore */
#define MIO_ER_WRONGMEMAREA     -31  /**< Wrong memory area passed to function */
#define MIO_ER_BADALIGNMENT     -32  /**< Bad alignment */
#define MIO_ER_UPDATELISTFULL   -33  /**< Update list is full */
#define MIO_ER_WRONGPRIO        -34  /**< Wrong priority */
#define MIO_ER_CHANNOTMAPPED    -35  /**< Channel is not mapped */
#define MIO_ER_NOPIDRVID        -36  /**< A process image module handle was expected but not given */
#define MIO_ER_HANDLEINUSE      -37  /**< The actual handle is already in use */
#define MIO_ER_BIOSFAIL         -38  /**< BIOS on module not running */
#define MIO_ER_DOWNGRADE        -39  /**< Software downgrade */
#define MIO_ER_BADFIRMWARE      -40  /**< Firmware doesn't fit on module */
#define MIO_ER_BADTYPE          -41  /**< Module type and software type are not compatible */
#define MIO_ER_NOAPP            -42  /**< Application not found/registered */
#define MIO_ER_NOSCALEINF       -43  /**< No scale information given for that channel */
#define MIO_ER_WRONGFUNCTYPE    -44  /**< Wrong function type */
#define MIO_ER_NOTPRESENT       -45  /**< Channel does not exist */
#define MIO_ER_OVERFLOW         -46  /**< Channel value overflow */
#define MIO_ER_POWER            -47  /**< Power failure */
/** @} */

/**
 * @anchor MIO_E_
 */

/**
 * @name Possible error codes from: mio_GetError()
 * @{
 */

#define MIO_E_OK            0    /**< No error */
#define MIO_E_BADSTATION    0x00000001   /**< Module is on Bad Station */
#define MIO_E_POWER         0x00000002   /**< External/internal power failure */
#define MIO_E_BROKENWIRE    0x00000004   /**< Open In/Out circuit */
#define MIO_E_SHORTCIRC     0x00000008   /**< Short In/Out circuit */
#define MIO_E_TEMPTOOHI     0x00000010   /**< Temperature too high */
#define MIO_E_DECODER       0x00000020   /**< Decoder/Encoder error */
#define MIO_E_CHANDISABLED  0x00000040   /**< Channel is disabled */
#define MIO_E_BADCONFIG     0x00000080   /**< Configuration not valid */
#define MIO_E_WATCHDOG      0x00000100   /**< Internal watchdog error */
#define MIO_E_EXTERNAL      0x00000200   /**< External error */
#define MIO_E_DEAD          0x00000400   /**< Module alive test failed */
#define MIO_E_OUTDISABLED   0x00000800   /**< Output is disabled */
#define MIO_E_VOLTAGETOHI   0x00001000   /**< External voltage too high */
#define MIO_E_VOLTAGETOLO   0x00002000   /**< External voltage too low */
#define MIO_E_CURRENTTOHI   0x00004000   /**< Output current too high */
#define MIO_E_BADPROFILE    0x00008000   /**< Profile not valid */
#define MIO_E_SYSTEM        0x0000ffff   /**< Generic errors */
#define MIO_E_USER          0xffff0000   /**< Driver specific error */
/** @} */

/**
 * @name Possible driver specific error for SSI input
 * @{
 */

#define MIO_E_CLOCK 0x00010000   /**< Bad SSI clock signal */
/** @} */

/**
 * @name Possible driver specific error for DIO2XX module
 * @{
 */

#define MIO_E_PWFMODULE 0x00020000   /**< Power fail complete module */
#define MIO_E_PHASE     0x00040000   /**< Phase error */
/** @} */

/**
 * @name Possible driver specific error for PWM202 module
 * @{
 */

#define MIO_E_MAXCURRENT    0x00040000   /**< Maximum current reached */
/** @} */

/**
 * @name Possible driver specific error for PCFS212 module
 * @{
 */

#define MIO_E_TRANSMIT  0x00100000   /**< Data transmission error */
#define MIO_E_PCIRESET  0x00200000   /**< PCI-Reset */
/** @} */

/**
 * @name Possible driver specific error for AI204/SI module
 * @{
 */

#define MIO_E_POSRANGE      0x00400000   /**< Value above maximum */
#define MIO_E_NEGRANGE      0x00800000   /**< Value below minimum */
#define MIO_E_MONITORING    0x01000000   /**< Monitoring error! */
/** @} */

/**
 * @name Possible driver specific error for Safety modules
 * @{
 */

#define MIO_E_SAFETYGENERR  0x00010000   /**< General module error */
/** @} */

/**
 * @name Possible driver specific errors for MBM201 modules
 * @{
 */

#define MIO_E_CONNECTION        MIO_E_DEAD   /**< No connection */
#define MIO_E_EXCEPTION         0x00010000   /**< Modbus exception */
#define MIO_E_CYCLETIMETOOLONG  0x00020000   /**< Cycle time too long */
#define MIO_E_CRCERROR          0x00040000   /**< CRC error */
/** @} */

/**
 * @name Possible driver specific errors/warning for FM2XX/FS2XX, FCS2XX modules
 * @{
 */

#define MIO_WRN_LINE_A  0x00010000   /**< FO Line A RX Power has critical level */
#define MIO_E_LINE_A    0x00020000   /**< FO Line A RX Power is below critical level */
#define MIO_WRN_LINE_B  0x00100000   /**< FO Line B RX Power has critical level */
#define MIO_E_LINE_B    0x00200000   /**< FO Line B RX Power is below critical level */
#define MIO_E_TRIGGER_A 0x01000000   /**< FO Line A user defined triggervalue */
/** @} */

/**
 * @name GMP232 specific error interrupts
 * @{
 */

#define MIO_E_U_MIN         0x00010000   /**< Chan 0, 1-3 Voltage below limit */
#define MIO_E_U_MAX         0x00020000   /**< Chan 0, 1-3 Voltage above limit */
#define MIO_E_I_MAX         0x00040000   /**< Chan 0, 4-6 Current limit exceeded */
#define MIO_E_THD_U_MAX     0x00080000   /**< Chan 0, 1-3 THD limit exceeded */
#define MIO_E_TDD_I_MAX     0x00100000   /**< Chan 0, 4-6 TDD limit exceeded */
#define MIO_E_ASYM_U_MAX    0x00200000   /**< Chan 0 Asymmetric voltage limit exceeded */
#define MIO_E_ASYM_I_MAX    0x00400000   /**< Chan 0 Asymmetric current exceeded */
#define MIO_E_F_IN_MIN      0x00800000   /**< Chan 0, 7 Frequency limit exceeded */
#define MIO_E_F_IN_MAX      0x01000000   /**< Chan 0, 7 Frequency limit exceeded */
#define MIO_E_F_MID_MIN     0x02000000   /**< Chan 0, 7 Frequency limit exceeded */
#define MIO_E_F_MID_MAX     0x04000000   /**< Chan 0, 7 Frequency limit exceeded */
#define MIO_E_F_OUT_MIN     0x08000000   /**< Chan 0, 7 Frequency limit exceeded */
#define MIO_E_F_OUT_MAX     0x10000000   /**< Chan 0, 7 Frequency limit exceeded */
#define MIO_E_VECTORJMP     0x20000000   /**< Chan 0, Vector Jump Error */
#define MIO_E_ROCOF_MAX     0x40000000   /**< Chan 0 ROCOF Error */
#define MIO_E_FRT           0x80000000   /**< Chan 0, 1-3 Fault Ride Through Error */
#define MIO_E_MSK_GMP232    0xffff0000   /**< For all other error bits see generic MIO errors */
#define GMP_E_MSK           MIO_E_MSK_GMP232     /**< @deprecated Replaced by MIO_E_MSK_GMP232 */
/** @} */

/**
 * @name GSP274 specific error interrupts - GSP274 supports the GMP232 errors too
 * @{
 */

#define MIO_E_NSP_UDECPROTLT    0x00000010   /**< Limit U<  in 0.1% of Un, default 80.0% */
#define MIO_E_NSP_UINCPROTGT    0x00000020   /**< Limit U>  in 0.1% of Un, default 110.0% */
#define MIO_E_NSP_UINCPROTGTGT  0x00000040   /**< Limit U>> in 0.1% of Un, default 115.0% */
#define MIO_E_NSP_FDECPROTLT    0x00000100   /**< Limit f<  in 0.1Hz of Un, default 47.5Hz */
#define MIO_E_NSP_FINCPROTGT    0x00000200   /**< Limit f>  in 0.1Hz of Un, default 51.5Hz */
#define MIO_E_QUPCC             0x00001000   /**< QU PCC (point of common coupling) */
#define MIO_E_QUGEN             0x00002000   /**< QU GEN */
#define MIO_E_SYNCALARM         0x00004000   /**< Synchronisation alarm */
#define MIO_E_ISLANDEDGRDDET    0x00008000   /**< Islanded grid detection */
#define MIO_E_MSK_GSP274        0xfffff370   /**< For all other error bits see generic MIO errors */
/** @} */

/**
 * @name GMP232X specific error interrupts
 * @{
 */

#define MIO_E_NEGSYS_HI     0x00000008   /**< Negative system blocking upper limit */
#define MIO_E_V_LO1         0x00000010   /**< Voltage lower limit 1 */
#define MIO_E_V_LO2         0x00000020   /**< Voltage lower limit 2 */
#define MIO_E_V_LO3         0x00000200   /**< Voltage lower limit 3 */
#define MIO_E_V_HI1         0x00001000   /**< Voltage upper limit 1 */
#define MIO_E_V_HI2         0x00002000   /**< Voltage upper limit 2 */
#define MIO_E_V_HI3         0x00004000   /**< Voltage upper limit 3 */
#define MIO_E_VFRT1         0x00008000   /**< Voltage FRT 1 */
#define MIO_E_VFRT2         0x00010000   /**< Voltage FRT 2 */
#define MIO_E_VFRT3         0x00020000   /**< Voltage FRT 3 */
#define MIO_E_VFRT4         0x00040000   /**< Voltage FRT 4 */
#define MIO_E_I_HI1         0x00080000   /**< Current upper limit 1 */
#define MIO_E_I_HI2         0x00100000   /**< Current upper limit 2 */
#define MIO_E_I_HI3         0x00200000   /**< Current upper limit 3 */
#define MIO_E_QU_GEN1       0x00400000   /**< QU limit 1 */
#define MIO_E_QU_GEN2       0x00800000   /**< QU limit 2 */
#define MIO_E_FFRT1         0x01000000   /**< Frequency FRT 1 */
#define MIO_E_FFRT2         0x02000000   /**< Frequency FRT 2 */
#define MIO_E_F_HI3         0x04000000   /**< Frequency upper limit 3 */
#define MIO_E_F_HI2         0x08000000   /**< Frequency upper limit 2 */
#define MIO_E_F_HI1         0x10000000   /**< Frequency upper limit 1 */
#define MIO_E_F_LO3         0x20000000   /**< Frequency lower limit 3 */
#define MIO_E_F_LO2         0x40000000   /**< Frequency lower limit 2 */
#define MIO_E_F_LO1         0x80000000   /**< Frequency lower limit 1 */
#define MIO_E_MSK_GMP232X   0xFFFFF238   /**< For all other error bits see generic MIO errors */
/** @} */

/**
 * @name ECS200 specific error and event interrupts
 * @{
 */

#define MIO_E_ECSGENERR 0x00010000   /**< General module error */
#define MIO_EV_ECSSYNC0 0x00010000   /**< SYNC0 Event */
#define MIO_EV_ECSSYNC1 0x00020000   /**< SYNC1 Event */
/** @} */

/**
 * @name GIO212, AIO216 and AIO208 specific error interrupts
 * @{
 */

#define MIO_E_LOWERRANGE    0x00010000   /**< Lowerrange exceeded */
#define MIO_E_UPPERRANGE    0x00020000   /**< Upperrange exceeded */
/** @} */

/**
 * @name Possible driver specific errors for RS204 module
 * @{
 */

#define MIO_E_POWER_UART1   0x00010000   /**< Powerfail UART1 */
#define MIO_E_POWER_UART2   0x00020000   /**< Powerfail UART2 */
#define MIO_E_POWER_UART3   0x00040000   /**< Powerfail UART3 */
#define MIO_E_POWER_UART4   0x00080000   /**< Powerfail UART4 */
/** @} */

/**
 * @name Possible values to configure the source of an event interrupt
 * @{
 */

#define MIO_POS_EDGE    0x0 /**< Obsolete use MIO_M_POSEDGE */
#define MIO_NEG_EDGE    0x1 /**< Obsolete use MIO_M_NEGEDGE */
#define MIO_BOTH_EDGES  0x2 /**< Obsolete use MIO_M_BOTHEDGES */
/** @} */

/**
 * @anchor MIO_M_
 */

/**
 * Possible values for MIO_SETCHMOD_C.Mode and MIO_GETCHMOD_C.Mode
 */
/**
 * @name in case of digital input output
 * @{
 */

#define MIO_M_IN        0x0001   /**< Channel is input */
#define MIO_M_OUT       0x0002   /**< Channel is output */
#define MIO_M_INOUTMSK  0x0003   /**< Mask for IN and OUT */
#define MIO_M_POSEDGE   0x0010   /**< MIO_EV_VALUE trigger condition */
#define MIO_M_NEGEDGE   0x0020   /**< MIO_EV_VALUE trigger condition */
#define MIO_M_BOTHEDGES 0x0030   /**< MIO_EV_VALUE trigger condition */
#define MIO_M_UNUSED    0x0800   /**< Channel is not used */
/** @} */

/**
 * @name in case of analog input
 * @{
 */

#define MIO_M_10V       0x0001   /**< -10V ... +10V */
#define MIO_M_PT100     0x0002   /**< Pt100 temperature input */
#define MIO_M_1V        0x0003   /**< -1V  ... +1V */
#define MIO_M_20MA      0x0004   /**< 0mA  ... 20mA */
#define MIO_M_04_20MA   0x0005   /**< 4mA  ... 20mA */
#define MIO_M_PM20MA    0x0006   /**< -20  ... 20mA */
#define MIO_M_VRANGEMSK 0x0007   /**< Mask for voltage range */
#define MIO_M_PT100_2   MIO_M_PT100  /**< PT100 2 Leitertechnik */
#define MIO_M_PT100_3   0x0020   /**< PT100 3 Leitertechnik */
#define MIO_M_PT1000    0x0040   /**< PT1000 2 Leitertechnik */
#define MIO_M_PT1000_2  0x0040   /**< PT1000 2 Leitertechnik */
#define MIO_M_PT1000_3  0x0080   /**< PT1000 3 Leitertechnik */
#define MIO_M_THERMO_J  0x0100   /**< Thermoelement Type J */
#define MIO_M_THERMO_K  0x0200   /**< Thermoelement Type K */
#define MIO_M_THERMO_N  0x0400   /**< Thermoelement Type N */
#define MIO_M_THERMO_S  0x0800   /**< Thermoelement Type S */
/** @} */

/**
 * @name in case of analog input on AI204
 * @{
 */

#define MIO_M_FILT333HZ 0x00000000   /**< Filter with 333 Hz */
#define MIO_M_FILT4KHZ  0x00000010   /**< Filter with 4 KHz */
#define MIO_M_NOTMPCOMP 0x00000020   /**< Temperature compensation OFF */
#define MIO_M_FILT50HZ  0x00000040   /**< 50 Hz frequency */
#define MIO_M_FILT60HZ  0x00000080   /**< 60 Hz frequency */
#define MIO_M_SAMPLE1   0x0000   /**< 1 time sampling */
#define MIO_M_SAMPLE8   0x0100   /**< 8 times sampling */
#define MIO_M_SAMPLE16  0x0200   /**< 16 times sampling */
#define MIO_M_SAMPLE32  0x0300   /**< 32 times sampling */
#define MIO_M_SAMPEMSK  0x0300   /**< mask for sampling */
/** @} */

/**
 * @name in case of analog input on AIC212
 * @{
 */

#define MIO_M_50KHZ 0x00010000   /**< 50 kHz sample rate */
#define MIO_M_25KHZ 0x00020000   /**< 25 kHz sample rate */
#define MIO_M_12KHZ 0x00040000   /**< 12.5 kHz sample rate */
#define MIO_M_6KHZ  0x00080000   /**< 6.25 kHz sample rate */
/** @} */

/**
 * @name in case of INC input
 * @{
 */

#define MIO_M_INTERPOL0 0x00000000   /**< SCI-Interpolation 0 */
#define MIO_M_INTERPOL1 0x00000010   /**< SCI-Interpolation 1 */
#define MIO_M_INTERPOL2 0x00000020   /**< SCI-Interpolation 2 */
#define MIO_M_INTERPOL3 0x00000030   /**< SCI-Interpolation 3 */
#define MIO_M_INTERPMSK 0x00000030   /**< Mask for interpolation */
#define MIO_M_AUTOLD    0x00001000   /**< Autoreload in reference compare */
/** @} */

/**
 * @name in case of SSI input
 * @{
 */

#define MIO_M_VR        0x0002   /**< V/R output to high */
#define MIO_M_SET       0x0004   /**< Set output to high */
#define MIO_M_NOPRTY    0x0000   /**< No parity */
#define MIO_M_EVEN      0x0200   /**< Even parity */
#define MIO_M_ODD       0x0400   /**< Odd parity */
#define MIO_M_PARIMSK   0x0600   /**< Mask for parity */
#define MIO_M_BIN       0x0000   /**< Binary data format */
#define MIO_M_GRAY      0x0800   /**< Gray-Code data format */
/** @} */

/**
 * @name in case of combined INC/SSI inputs on ISI2xx
 * @{
 */

#define MIO_M_SSI           0x00000001   /**< Synchronous serial mode */
#define MIO_M_SYNC          0x00000008   /**< Sync-Input/Output enable */
#define MIO_M_FASTPFAIL     0x00002000   /**< Fast Power-Fail enable */
#define MIO_M_LATHOME_R     0x00004000   /**< Latch into reference at home */
#define MIO_M_LATHOME_S     0x00008000   /**< Latch into strobe at home */
#define MIO_M_LATTRIG_S     0x00010000   /**< Latch into trig at home */
#define MIO_M_CONTINUOUS    0x00020000   /**< Continuous homing */
#define unusedMode1         0x00040000
#define unusedMode2         0x00080000
#define MIO_M_GATETIME      0x00100000   /**< Measure gatetime */
#define MIO_M_PERIOD        0x00200000   /**< Measure period */
#define MIO_M_AUTO          (MIO_M_GATETIME | MIO_M_PERIOD)  /**< Auto determine GATE or PERIOD */
/** @} */

/**
 * @name in case of counter input on CNT204 (same as on ISI2xx)
 * @{
 */

#define MIO_M_INC       0x00000000   /**< Incremental mode */
#define MIO_M_COUNT     0x00000002   /**< Counter mode */
#define MIO_M_TRIGG     0x00000003   /**< Trigger mode */
#define MIO_M_CNTMODMSK 0x00000003   /**< Mask for CNT mode */
#define MIO_M_PULSEDIR  0x00000000   /**< Pulse-Direction-Mode */
#define MIO_M_SINGLE    0x00000040   /**< 1-time counting */
#define MIO_M_DOUBLE    0x00000080   /**< 2-time counting */
#define MIO_M_QUAD      0x000000c0   /**< 4-time counting */
#define MIO_M_INCMODMSK 0x000000c0   /**< Mask for INC mode */
#define MIO_M_RESET     0x00000100   /**< Activate search home */
#define MIO_M_NOZERO    0x00000200   /**< Ignore encoder zero */
#define MIO_M_NOHOME    0x00000400   /**< Ignore home signal */
/** @} */

/**
 * @name in case of CNT204
 * @{
 */

#define MIO_M_CNTTIME   0x0800   /**< Measure time between counts */
#define MIO_M_INCTIME   0x1000   /**< Measure time between increments */
#define MIO_M_DIFFTIME  0x2000   /**< Measure time difference */
/** @} */

/**
 * @name in case of ACR222
 * @{
 */

#define MIO_M_CHANNELS      0x0001   /**< Module in Channel mode */
#define MIO_M_CANOBJECTS    0x0002   /**< Module Can-Objects mode */
#define MIO_M_ACRMODMSK     0x0003   /**< Mask for mode above */
/** @} */

/**
 * @name in case of ACR222
 * @{
 */

#define MIO_M_PROF_LIN      0x0000   /**< Linear profile mode */
#define MIO_M_PROF_SIN      0x0001   /**< Sin square profile mode */
#define MIO_M_PROF_PARAB    0x0002   /**< Parabolic profile mode */
#define MIO_M_PROF_FREQ     0x0003   /**< Frequency mode */
#define MIO_M_ACRPROFMSK    0x0003   /**< Mask for profile mode */
#define MIO_M_POS_ABS       0x0000   /**< Absolute positioning */
#define MIO_M_POS_REL       0x0020   /**< Relative positioning */
#define MIO_M_ACRPOSMSK     0x0020   /**< Mask for positioning */
#define MIO_M_CNT_ENCOD     0x0000   /**< Counter is encoder */
#define MIO_M_CNT_PULSE     0x0040   /**< Counter is pulse generator */
#define MIO_M_ACRCNTMSK     0x0040   /**< Mask for counter */
#define MIO_M_REF_NORMAL    0x0080   /**< Reference with Null and Home */
#define MIO_M_REF_ZERO      0x0100   /**< Use encoder Zero only */
#define MIO_M_REF_HOME      0x0180   /**< Use home signal only */
#define MIO_M_ACRREFMSK     0x0180   /**< Mask for find reference */
/** @} */

/**
 * @name in case of a DMS202
 * @{
 */

#define MIO_M_2MV       0x0001   /**< Input range is 2mV */
#define MIO_M_4MV       0x0002   /**< Input range is 4mV */
#define MIO_M_8MV       0x0004   /**< Input range is 8mV */
#define MIO_M_16MV      0x0008   /**< Input range is 16mV */
#define MIO_M_AUTOR     0x000f   /**< Auto range */
#define MIO_M_DMSRANMSK 0x000f   /**< Mask for DMS range */
/** @} */

/**
 * @name in case of a PWM202
 * @{
 */

#define MIO_M_BRAKE     0x0000   /**< PWM brake on */
#define MIO_M_OPERATE   0x0001   /**< PWM running */
#define MIO_M_RUNMSK    0x0001   /**< Mask for PWM modes operate */
#define MIO_M_PWM       0x0000   /**< SMA/LAP PWM-control is active */
#define MIO_M_CONTROL   0x0002   /**< SMA/LAP I-control is active */
#define MIO_M_CONTMSK   0x0002   /**< Mask for PWM- or I-control */
#define MIO_M_RESLO     0x0000   /**< 5.0 A AD-converter resolution */
#define MIO_M_RESHI     0x0004   /**< 1.5 A AD-Converter resolution */
#define MIO_M_RESMSK    0x0004   /**< Resolution mask */
#define MIO_M_SMA       0x0000   /**< Sign/Magnitude control setting */
#define MIO_M_LAP       0x0008   /**< Locked antiphase control setting */
#define MIO_M_MODEMSK   0x0008   /**< Mask for PWM- or I-control */
#define MIO_M_OPEN      0x0000   /**< no shorting open switches */
#define MIO_M_UPPER     0x0010   /**< shorting using upper switches */
#define MIO_M_LOWER     0x0020   /**< shorting using lower switches */
#define MIO_M_BRAKEMSK  0x0030   /**< Mask for PWM modes brakes */
#define MIO_M_EDGE      0x0000   /**< Pulse width switch align edge */
#define MIO_M_CENTER    0x0040   /**< Pulse width switch align center */
#define MIO_M_ALIGNMSK  0x0040   /**< Mask for PWM mode others */
#define MIO_M_PRESCAL   0x0080   /**< 256us prescale active not applicable */
#define MIO_M_PRESCMSK  0x0080   /**< Mask for prescale */
#define MIO_M_PWMUSRMSK (MIO_M_ALIGNMSK | MIO_M_BRAKEMSK | MIO_M_MODEMSK | MIO_M_CONTMSK | MIO_M_RUNMSK | MIO_M_RESMSK)
/** @} */

/**
 * @name in case of a SLC284, SDO204, SDI208
 * @{
 */

#define MIO_M_SAFETY_ERROR          0x00000001   /**< Safety module in error status */
#define MIO_M_SAFETY_PROG           0x00000002   /**< Safety module in programming mode */
#define MIO_M_SAFETY_TEST           0x00000004   /**< Safety module in test mode */
#define MIO_M_SAFETY_SAFE           0x00000008   /**< Safety module in safe mode */
#define MIO_M_SAFETY_WAITFORSAFE    0x00000010   /**< Safety module waiting for safe mode */
#define MIO_M_SAFETY_BIOS           0x00000020   /**< Safety module only Bios active */
#define MIO_M_SAFETY_SAFEDELAY      0x00000040   /**< Safety module in safe delay mode */
#define MIO_M_SAFETY_GOLDEN_REF     0x00000080   /**< Safety module in golden reference mode (FPGA only) */
/** @} */

/**
 * @name in case of a PVA2XX
 * @{
 */

#define MIO_M_PVA_UNIPOLAR      0x0001   /**< Half-Bridge */
#define MIO_M_PVA_BIPOLAR       0x0002   /**< H-Bridge */
#define MIO_M_PVA_UNIPOLAR2COIL 0x0004   /**< Unipolar with 2 coils */
#define MIO_M_PVA_UNUSED        0x0800   /**< Channel is not used */
/** @} */

/**
 * @name Possible values for MIO_XCHANINFO.Range
 * @{
 */

#define MIO_R_NONE      0x0000   /**< No range, no size */
#define MIO_R16_10V     0x0001   /**< 16 Bits, -10V ... +10V */
#define MIO_R16_PT100   0x0002   /**< 16 Bits, temp in 1/10 Kelvin */
#define MIO_R16_1V      0x0003   /**< 16 Bits, -1V  ... +1V */
#define MIO_R16_20MA    0x0004   /**< 16 Bits, 0mA  ... 20mA */
#define MIO_R16_04_20MA 0x0005   /**< 16 Bits, 4mA  ... 20mA */
#define MIO_R16_DMS     0x0008   /**< 16 Bits, 0mV  ... 16mV */
#define MIO_R16_SPZENT  0x0009   /**< 16 Bits, -100% ... +100% */
#define MIO_R16_UPZENT  0x000A   /**< 16 Bits, 0%  ... 100% */
#define MIO_R16_S5A     0x000B   /**< 16 Bits, -5A ... +5A */
#define MIO_R16_U15A    0x000C   /**< 16 Bits, 0A ... +1.5A */
#define MIO_R32_UINT    0x0100   /**< 32 Bits, 0 ... 4294967295 */
#define MIO_R32_SINT    0x0101   /**< 32 Bits, -2147483648 ... +2147483647 */
#define MIO_R32_XINT    0x0102   /**< 32 Bits, Hex 0 ... 0xFFFFFFFF */
#define MIO_R32_FREQ    0x0103   /**< 32 Bits, -262143 ... +262143 */
#define MIO_R64_SINT    0x0201   /**< 64 Bits, -2**63 ... +2**63 */
#define MIO_R_BIG       0x1000   /**< > 64 Bits, value invalid */
#define MIO_R16_PT1000  0x2000   /**< 16 Bits, temp in 1/10 Kelvin */
/** @} */

/**
 * @anchor MIO_VER_
 */
/**
 * @name Possible type of IO module version as used in MIO_IDREG->ModVerType
 * @{
 */

#define MIO_VER_UNKNOWN     0    /**< Unknown type of version */
#define MIO_VER_TESTSAMPLE  1    /**< Test specimen version */
#define MIO_VER_PROTOTYPE   2    /**< Prototype version */
#define MIO_VER_ENGINEERING 3    /**< Engineering or production internal version */
#define MIO_VER_ZEROSERIES  4    /**< Zero Series version */
#define MIO_VER_RELEASE     5    /**< Release version */
/** @} */

/**
 * @name Possible values for MIO_UPDATESW_C.Mode
 * @{
 */

#define MIO_UFW_XREPLY      0x0001   /**< Use extended reply */
#define MIO_UFW_DOWNGRADE   0x0002   /**< Force downgrade */
#define MIO_UFW_TASKMODE    0x0004   /**< Perform update as task */
#define MIO_UFW_M86MODE     0x0008   /**< Use new package mode */
/** @} */

/**
 * @name Possible error codes for MIO_*.RetCode
 * @{
 */

#define MIO_E_CARDNB    (M_ES_MIO | M_E_CARDNB)  /**< @copybrief #M_E_CARDNB */
#define MIO_E_DRVID     (M_ES_MIO | M_E_DRVID)   /**< @copybrief #M_E_DRVID */
#define MIO_E_FAILED    (M_ES_MIO | M_E_FAILED)  /**< @copybrief #M_E_FAILED */
#define MIO_E_NOFILE    (M_ES_MIO | M_E_NOFILE)  /**< @copybrief #M_E_NOFILE */
#define MIO_E_UPDATE    (M_ES_MIO | M_E_UPDATE)  /**< @copybrief #M_E_UPDATE */
#define MIO_E_BADFWARE  (M_ES_MIO | M_E_BADFWARE)    /**< @copybrief #M_E_BADFWARE */
#define MIO_E_DOWNGRADE (M_ES_MIO | M_E_DOWNGRADE)   /**< @copybrief #M_E_DOWNGRADE */
#define MIO_E_PARM      (M_ES_MIO | M_E_PARM)    /**< @copybrief #M_E_PARM */
#define MIO_E_BADTYPE   (M_ES_MIO | M_E_BADTYPE)     /**< @copybrief #M_E_BADTYPE */
#define MIO_E_NOMEM     (M_ES_MIO | M_E_NOMEM)   /**< @copybrief #M_E_NOMEM */
/** @} */
/** @} */

/**
 * @addtogroup MIO-SMI
 * @{
 */

/**
 * @name Possible SMI Commands
 * @{
 */

/**
 * @brief Get driver ID
 *
 * @param[in]   #MIO_GETDRV_C
 * @param[out]  #MIO_GETDRV_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETDRV         100
/**
 * @brief Get one IO value
 *
 * @param[in]   #MIO_GETVAL_C
 * @param[out]  #MIO_GETVAL_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETVALUE       102
/**
 * @brief Set one IO value
 *
 * @param[in]   #MIO_SETVAL_C
 * @param[out]  #MIO_SETVAL_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_SETVALUE       104
/**
 * @brief Get many IO values
 *
 * @param[in]   #MIO_GETVALUES_C
 * @param[out]  #MIO_GETVALUES_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETVALUES      106
/**
 * @brief Set many IO values
 *
 * @param[in]   #MIO_SETVALUES_C
 * @param[out]  #MIO_SETVALUES_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_SETVALUES      108
/**
 * @brief Get large IO values
 *
 * @param[in]   #MIO_GETBLK_C
 * @param[out]  #MIO_GETBLK_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETBLK         110
/**
 * @brief Set large IO values
 *
 * @param[in]   #MIO_SETBLK_C
 * @param[out]  #MIO_SETBLK_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_SETBLK         112
/**
 * @brief Get error code
 *
 * @param[in]   #MIO_GETERROR_C
 * @param[out]  #MIO_GETERROR_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETERROR       114
/**
 * @brief Set channel mode
 *
 * @param[in]   #MIO_SETCHMOD_C
 * @param[out]  #MIO_SETCHMOD_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_SETCHMOD       118
/**
 * @brief Get channel mode
 *
 * @param[in]   #MIO_GETCHMOD_C
 * @param[out]  #MIO_GETCHMOD_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETCHMOD       120
/**
 * @brief Set card mode
 *
 * @param[in]   #MIO_SETCDMOD_C
 * @param[out]  #MIO_SETCDMOD_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_SETCDMOD       122
/**
 * @brief Get card mode
 *
 * @param[in]   #MIO_GETCDMOD_C
 * @param[out]  #MIO_GETCDMOD_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETCDMOD       124
/**
 * @brief Set channel selection
 *
 * @param[in]   #MIO_SETSELECT_C
 * @param[out]  #MIO_SETSELECT_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_SETSELECT      126
/**
 * @brief Get channel selection
 *
 * @param[in]   #MIO_GETSELECT_C
 * @param[out]  #MIO_GETSELECT_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETSELECT      128
/**
 * @brief Get card information
 *
 * @param[in]   #MIO_GETCDINF_C
 * @param[out]  #MIO_GETCDINF_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETCDINF       130
/**
 * @brief Get channel information
 *
 * @param[in]   #MIO_GETCHINF_C
 * @param[out]  #MIO_GETCHINF_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETCHINF       132
/**
 * @brief Reset IO module
 *
 * @param[in]   #MIO_RESET_C
 * @param[out]  #MIO_RESET_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_RESET          134
/**
 * @brief Get extended card information
 *
 * @param[in]   #MIO_GETEXTCDINF_C
 * @param[out]  #MIO_GETEXTCDINF_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETEXTCDINF    136
/**
 * @brief Update firmware on IO module
 *
 * @param[in]   #MIO_UPDATESW_C
 * @param[out]  #MIO_UPDATESW_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_UPDATESW       138
/**
 * @brief Execute card specific command
 *
 * @param[in]   #MIO_DOCMD_C
 * @param[out]  #MIO_DOCMD_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_DOCMD          140
/**
 * @brief Get symbolic name of channel
 *
 * @param[in]   #MIO_GETCHNAMES_C
 * @param[out]  #MIO_GETCHNAMES_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETCHNAMES     142
/**
 * @brief Get station list
 *
 * @param[in]   #MIO_GETSTATIONLST_C
 * @param[out]  #MIO_GETSTATIONLST_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETSTATIONLST  144
/**
 * @brief Get backplane information
 *
 * @param[in]   #MIO_GETBPINF_C
 * @param[out]  #MIO_GETBPINF_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETBPINF       146
/**
 * @brief Get extended info on all IO channels
 *
 * @param[in]   #MIO_XCHANINFOLST_C
 * @param[out]  #MIO_XCHANINFOLST_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_XCHANINFOLST   148
/**
 * @brief Get types of all IO channels
 *
 * @param[in]   #MIO_GETCHTYPES_C
 * @param[out]  #MIO_GETCHTYPES_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETCHTYPES     150
/**
 * @brief Get extended info on all IO channels 2
 *
 * @param[in]   #MIO_X2CHANINFOLST_C
 * @param[out]  #MIO_X2CHANINFOLST_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_X2CHANINFOLST  152
/**
 * @brief Get IO statistic
 *
 * @param[in]   #MIO_GETIOSTAT_C
 * @param[out]  #MIO_GETIOSTAT_C
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETIOSTAT      154
/**
 * @brief Get progress
 *
 * @param[in]   #MIO_PROGRESS_C
 * @param[out]  #MIO_PROGRESS_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_PROGRESS       156
/**
 * @brief Get channel monitor information
 *
 * @param[in]   #MIO_CHANMONITOR_C
 * @param[out]  #MIO_CHANMONITOR_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_CHANMONITOR    158
/**
 * @brief Get information of scaled channel
 *
 * @param[in]   #MIO_CHANSCALEINV_C
 * @param[out]  #MIO_CHANSCALEINV_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_CHANSCALEINV   160
/**
 * @brief Set a scaled value
 *
 * @param[in]   #MIO_SETSCALEDVALUE_C
 * @param[out]  #MIO_SETSCALEDVALUE_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_SETSCALEDVALUE 162
/**
 * @brief Get extended card information 2
 *
 * @param[in]   #MIO_GETEXTCDINF2_C
 * @param[out]  #MIO_GETEXTCDINF2_R
 *
 * @return #MIO_E_OK for success, or <tt>< 0</tt> in case of an error
 */
#define MIO_PROC_GETEXTCDINF2   164
/** @} */

/**
 * @name Possible values for MIO_PROGRESS_R.Status
 * @{
 */

#define PROGRESS_UNKNOWN    0x00
#define PROGRESS_WORK       0x01
#define PROGRESS_DONE       0x02
#define PROGRESS_FAILED     0x04
/** @} */

/**
 * @name Possible values for mio_GetProcImgFuncs() "PlcImgFlags":
 * @{
 */

#define MIO_PLCIMG_CYCLE0   0x00010000   /**< PLC cycle time is 0 */
#define MIO_PLCIMG_PARTIAL  0x00020000   /**< Partial Process Image */
#define MIO_CANIMG_WHOLENET 0x00100000   /**< Whole CAN network */
#define MIO_DPMIMG_DEINIT   0x00200000   /**< Project deleted */
/** @} */

/**
 * Below are all codes for mio_DoCmd listed
 */
/**
 * @name Possible commands for the IO module ISI2xx with SSI inputs
 * @{
 */

#define MIO_CMD_SETFREQUENCY    2    /**< Set SSI clock rate */
#define MIO_CMD_SETFREQ         2    /**< Set SSI clock rate */
#define MIO_CMD_SETDLEN         3    /**< Set SSI data length */
#define MIO_CMD_SETINTERVAL     6    /**< Set SSI clock pause in us */
/** @} */

/**
 * @name Possible commands for IO modules
 * @{
 */

#define MIO_CMD_SETREF  1   /**< Set reference value */
#define MIO_CMD_GETREF  22  /**< Get reference register value */
/** @} */

/**
 * @name Possible commands for the IO module ISI2xx/CNT204/ACR222 with INC inputs
 * @{
 */

#define MIO_CMD_ZINIT           5    /**< OBSOLETE - Do not use! */
#define MIO_CMD_GETZINIT        5    /**< Read home signal */
#define MIO_CMD_GETHOMESTATE    5    /**< Same as MIO_CMD_ZINIT */
#define MIO_CMD_GETRST          7    /**< Read search home status */
#define MIO_CMD_ENABLERST       12   /**< Activate search home */
#define MIO_CMD_DISABLERST      13   /**< De-activate search home */
#define MIO_CMD_GETSTRB         21   /**< Get strobe register value */
#define MIO_CMD_GETACT          23   /**< Get actual counter value (CNT) */
#define MIO_CMD_GETSTRBSTAT     24   /**< Get strobe status (only CNT) */
#define MIO_CMD_GETINPSTAT      25   /**< Get input status (only CNT) */
#define MIO_CMD_GETZEROSTAT     26   /**< Read encoder zero signal (CNT) */
/** @} */

/**
 * @name Possible commands for the IO module ISI2xx/CNT204
 * @{
 */

#define MIO_CMD_RESET           4    /**< Reset complete INC/SSI chip */
#define MIO_CMD_SETFILTER       20   /**< Set filter frequency */
#define MIO_CMD_GETFREQUENCY    27   /**< Get internal frequency */
#define MIO_CMD_SETINCFILTER    28   /**< Set filter for inputs configured as INC */
#define MIO_CMD_GETINCFILTER    29   /**< Get filter for inputs configured as INC */
#define MIO_CMD_GETZEROBITS     30   /**< Just for internal tests */
#define MIO_CMD_SETZEROBITS     31   /**< Just for internal tests */
/** @} */

/**
 * @name Possible commands for the IO module ACR222 in CAN-Objects Mode and CNT204 in time measurement mode
 * @{
 */

#define MIO_CMD_GETVAL  10  /**< Read specific value */
/** @} */

/**
 * @name Possible commands for the IO module ACR222 in CAN-Objects Mode
 * @{
 */

#define MIO_CMD_SETVAL      11   /**< Write specific value */
#define MIO_CMD_GETACTVAL   14   /**< Read actual value */
#define MIO_CMD_GETSETVAL   15   /**< Write set value */
#define MIO_CMD_GETNEWSET   16   /**< Conditional read */
/** @} */

/**
 * @name Possible commands for the IO module ACR222 in Channel Mode
 * @{
 */

#define MIO_CMD_SETPROF             17   /**< Set Profile */
#define MIO_CMD_GETPROF             18   /**< Get Profile */
#define MIO_CMD_SETQUICKDECEL       19   /**< Set Quick Deceleration */
#define MIO_CMD_GETQUICKDECEL       20   /**< Get Quick Deceleration */
#define MIO_CMD_SETHOME             21   /**< Set Home Parameters */
#define MIO_CMD_GETHOME             22   /**< Get Home Parameters */
#define MIO_CMD_SETCOMMONSETTINGS   23   /**< Set Common Settings */
#define MIO_CMD_GETCOMMONSETTINGS   24   /**< Get Common Settings */
#define MIO_CMD_SETDRIVEDATA        27   /**< Set Drive Data */
#define MIO_CMD_GETDRIVEDATA        28   /**< Get Drive Data */
#define MIO_CMD_SETRESOLUTION       29   /**< Set Resolution */
#define MIO_CMD_GETRESOLUTION       30   /**< Get Resolution */
#define MIO_CMD_SETERRORWINDOW      31   /**< Set Error Window */
#define MIO_CMD_GETERRORWINDOW      32   /**< Get Error Window */
#define MIO_CMD_SETMAXFREQ          33   /**< Set Maximum Frequency */
#define MIO_CMD_GETMAXFREQ          34   /**< Set Maximum Frequency */
#define MIO_CMD_GETSWITCHSTATE      35
#define MIO_CMD_GETSTATEHIST        36
#define MIO_CMD_SWITCHTOCHANNELS    37
/** @} */

/**
 * @name Possible commands for the IO module AIO288
 * @{
 */

#define MIO_CMD_AIO288_GETVAL   MIO_CMD_GETVAL   /**< Read temperature on a PT100/Pt1000 input */
/** @} */

/**
 * @name Internal ISI2xx command
 * @{
 */

#define MIO_CMD_SSISINGLESHOT   38
/** @} */

/**
 * @name Possible commands for the IO module CM202, ACR222, DPM200
 * @{
 */

#define MIO_CMD_UPDATESW    9    /**< Update firmware on module */
/** @} */

/**
 * @name Possible commands for the IO module FM2xx and FS2xx
 * @{
 */

#define MIO_CMD_TRIGWDOG    30   /**< Trigger watchdog */
#define MIO_CMD_CLRINT      31   /**< Clear event interrupt */
/** @} */

/**
 * @name Possible commands for the IO module DPM200
 * @{
 */

#define MIO_CMD_SETPARAMETER    40   /**< Set network parameters */
#define MIO_CMD_SETMODE         41   /**< Set mode for user interface */
#define MIO_CMD_GETMODE         42   /**< Set mode on user interface */
#define MIO_CMD_MARK            43   /**< Wait for token */
#define MIO_CMD_LOADBUSPAR      44   /**< Load bus parameters */
#define MIO_CMD_READBUSPAR      45   /**< Read bus parameters */
#define MIO_CMD_GLOBALCTRL      46   /**< New mode for slave(s) */
#define MIO_CMD_SETRAWPARAM     47   /**< Set network parameters per file */
/** @} */

/**
 * @name Possible commands for IO modules
 * @{
 */

#define MIO_CMD_READIDREG       48   /**< Read Id register via DoCmd */
#define MIO_CMD_WRITEIDREG      49   /**< Write Id register via DoCmd */
#define MIO_CMD_GETVERSION      50   /**< Get driver and firmware version */
#define MIO_CMD_BUSCHECK        51   /**< Do hardware check on IO-bus */
#define MIO_CMD_ALIVECHECK      52   /**< Do alive check on IO-module */
#define MIO_CMD_GETERRCODE      53   /**< Get error code from IO-module */
#define MIO_CMD_GETERRSTATIST   54   /**< Get module error statistics */
#define MIO_CMD_NEWCONFIG       55   /**< New configuration for IO-module */
#define MIO_CMD_SETRDYLED       56   /**< Set RDY-LED for FW IO-module */
#define MIO_CMD_INTSYSRUNNING   57   /**< Interrupt-System is now running */
#define MIO_CMD_GETERRCNT       58   /**< Query error counter */
#define MIO_CMD_GETPROGRESS     59   /**< Query progress */
/** @} */

/**
 * @name Possible commands for the IO module AI204/X
 * @{
 */

#define MIO_CMD_TEMPCOMP        60   /**< Start temperature compensation */
#define MIO_CMD_GETTEMP         74   /**< Get actual card temperature */
#define MIO_CMD_AI204_TEMPCOMP  MIO_CMD_TEMPCOMP     /**< Start temperature compensation */
#define MIO_CMD_AI204_GETTEMP   MIO_CMD_GETTEMP  /**< Get actual card temperature */
/** @} */

/**
 * @name Possible commands for IO modules
 * @{
 */

#define MIO_CMD_SETPP   70  /**< Set pulse period duration uS */
#define MIO_CMD_GETPP   71  /**< Get pulse period duration uS */
/** @} */

/**
 * @name Possible commands for the IO module PWM202
 * @{
 */

#define MIO_CMD_SETOP           72   /**< Set operation mode on/off */
#define MIO_CMD_GETOP           73   /**< Get operation mode */
#define MIO_CMD_SETPAR_BASE     80
#define MIO_CMD_SETPAR_TS       (80 + 0)     /**< Set controller sample time */
#define MIO_CMD_SETPAR_PR       (80 + 1)     /**< Set controller proportional range */
#define MIO_CMD_SETPAR_TI       (80 + 2)     /**< Set controller integration time */
#define MIO_CMD_SETPAR_TD       (80 + 3)     /**< Set controller differentation time */
#define MIO_CMD_GETPAR_BASE     90
#define MIO_CMD_GETPAR_TS       (90 + 0)     /**< Get controller sample time */
#define MIO_CMD_GETPAR_PR       (90 + 1)     /**< Get controller proportional range */
#define MIO_CMD_GETPAR_TI       (90 + 2)     /**< Get controller integration time */
#define MIO_CMD_GETPAR_TD       (90 + 3)     /**< Get controller differentiation time */
#define MIO_CMD_MAXCURRENT      100  /**< Maximum current */
#define MIO_CMD_CURRENTRES      101  /**< Current resolution */
#define MIO_CMD_LOADTYPE        102  /**< Set load current */
#define MIO_CMD_GETMAXCURRENT   103  /**< Get maximum current */
#define MIO_CMD_GETLOADTYPE     104  /**< Get load current */
#define MIO_CMD_GETCURRENTRES   105  /**< Get current resolution */
/** @} */

/**
 * @name Possible commands for the IO module PCFS212
 * @{
 */

#define MIO_CMD_GETDATABLK  110  /**< Read data block */
#define MIO_CMD_SETDATABLK  111  /**< Write data block */
#define MIO_CMD_PCIINT      112  /**< Generate a PCI interrupt */
/** @} */

/**
 * @name Possible commands for the IO module CNT204 with time mode support
 * @{
 */

#define MIO_CMD_LOSTTIMEVAL     120  /**< Query if a value has been lost */
#define MIO_CMD_NEWTIMEVAL      121  /**< Query if a new value is available */
#define MIO_CMD_RESETSTRBSTAT   122  /**< Reset strobe status */
/** @} */

/**
 * @name Possible commands for the IO module NT255 with IdRegister
 * @{
 */

#define MIO_CMD_POWERMARGIN 130  /**< Set power supply calculation */
/** @} */

/**
 * @name Parameters for MIO_CMD_GETACTIVELEVEL
 * @{
 */

#define MIO_HIGHACTIVE  0x0001   /**< Static level "1" */
#define MIO_LOWACTIVE   0x0002   /**< Static level "0" */
/** @} */

/**
 * @name Common commands for the IO module DIO2XX
 * @{
 */

#define MIO_CMD_GETFILTER       140  /**< Read filter configuration */
#define MIO_CMD_GETPWMCFG       420  /**< Read PWM configuration of DO channel */
#define MIO_CMD_SETPWMCFG       421  /**< Write PWM configuration of DO channel */
#define MIO_CMD_GETPINLEVELS    422  /**< Read pin levels of DIO channels */
#define MIO_CMD_SETTIMEOUT      423  /**< Write the timeout period of a counter channel */
#define MIO_CMD_GETTIMEOUT      424  /**< Read the timeout period of a counter channel */
/** @} */

/**
 * @name Possible commands for IO modules
 * @{
 */

#define MIO_CMD_SIMERROR    148  /**< Simulate an error interrupt */
#define MIO_CMD_SIMEVENT    149  /**< Simulate an event interrupt */
/** @} */

/**
 * @name Possible commands for the IO module ISI2xx
 * @{
 */

#define MIO_CMD_GETFREQ                 143  /**< Read the frequency of the clock line for the SSI encoder */
#define MIO_CMD_GETINTERVAL             144  /**< Read the clock pause in [us] */
#define MIO_CMD_GETDLEN                 145  /**< Read the set number of bits (0 to 32) of the data word of an SSI encoder */
#define MIO_CMD_GETRESETVALUE           146  /**< Select the SET register */
#define MIO_CMD_SETRESETVALUE           147  /**< Write the SET register */
#define MIO_CMD_SETACTIVE               150
#define MIO_CMD_GETENCRES               151  /**< Read the set values for monitoring the encoder resolution */
#define MIO_CMD_SETENCRES               152  /**< Enable or disable the monitoring of the encoder resolution */
#define MIO_CMD_GETGATETIME             153  /**< Read the gate time, which is measured in [us] and used for velocity measurement */
#define MIO_CMD_SETGATETIME             154  /**< Allow to configuration of the gate time */
#define MIO_CMD_GETDISTANCEREF          155  /**< Read the reference register's automatic incrementation offset value */
#define MIO_CMD_SETDISTANCEREF          156  /**< Set the reference register's automatic incrementation offset value */
#define MIO_CMD_CONFIGNULLEDGE          157  /**< Allows the evaluation of the encoder's zero pulse with a positive or negative edge */
#define MIO_CMD_GETNULLEDGE             158  /**< Allows the query of for which edge the zero pulse of the encoder is evaluated */
#define MIO_CMD_ENABLENULL              159  /**< Allows to disable the wire break detection of the zero pulse of the encoder */
#define MIO_CMD_ISNULLENABLED           160  /**< Query whether the wire break detection is enabled on the zero pulse of the encoder */
#define MIO_CMD_ISRESETPENDING          161
#define MIO_CMD_GETACTIVELEVEL          162  /**< Read the level at which the initiator input shall be active */
#define MIO_CMD_SETACTIVELEVEL          163  /**< Define the level at which the initiator input shall be active */
#define MIO_CMD_SETTESTMODE             164  /**< Read the frequency of the clock line for the SSI encoder */
#define MIO_CMD_ISI2XX_DISABLERST       MIO_CMD_DISABLERST   /**< Allows to disable the referencing */
#define MIO_CMD_ISI2XX_ENABLERST        MIO_CMD_ENABLERST    /**< Allows to enable the referencing */
#define MIO_CMD_ISI2XX_SETREF           MIO_CMD_SETREF   /**< Set reference value */
#define MIO_CMD_ISI2XX_GETREF           MIO_CMD_GETREF   /**< Get reference register value */
#define MIO_CMD_ISI2XX_GETRST           MIO_CMD_GETRST   /**< Read the state of the encoder referencing */
#define MIO_CMD_ISI2XX_GETSTRB          MIO_CMD_GETSTRB  /**< Read strobe register value */
#define MIO_CMD_ISI2XX_RESET            MIO_CMD_RESET    /**< Reset complete INC/SSI chip */
#define MIO_CMD_ISI2XX_SETDLEN          MIO_CMD_SETDLEN  /**< Set SSI data length */
#define MIO_CMD_ISI2XX_GETDLEN          MIO_CMD_GETDLEN  /**< Read the set number of bits (0 to 32) of the data word of an SSI encoder */
#define MIO_CMD_ISI2XX_SETFREQ          MIO_CMD_SETFREQ  /**< Set SSI clock rate */
#define MIO_CMD_ISI2XX_GETFREQ          MIO_CMD_GETFREQ  /**< Read the frequency of the clock line for the SSI encoder */
#define MIO_CMD_ISI2XX_SETINTERVAL      MIO_CMD_SETINTERVAL  /**< Set SSI clock pause in us */
#define MIO_CMD_ISI2XX_GETINTERVAL      MIO_CMD_GETINTERVAL  /**< Read the clock pause in [us] */
#define MIO_CMD_ISI2XX_SETFILTER        MIO_CMD_SETFILTER    /**< Set filter frequency */
#define MIO_CMD_ISI2XX_GETFILTER        MIO_CMD_GETFILTER    /**< Read filter configuration */
#define MIO_CMD_ISI2XX_ZINIT            MIO_CMD_ZINIT    /**< OBSOLETE - Do not use! */
#define MIO_CMD_ISI2XX_GETVAL           MIO_CMD_GETVAL   /**< Read specific value */
#define MIO_CMD_ISI2XX_GETENCRES        MIO_CMD_GETENCRES    /**< Read the set values for monitoring the encoder resolution */
#define MIO_CMD_ISI2XX_SETENCRES        MIO_CMD_SETENCRES    /**< Enable or disable the monitoring of the encoder resolution */
#define MIO_CMD_ISI2XX_GETZEROSTAT      MIO_CMD_GETZEROSTAT  /**< Read encoder zero signal */
#define MIO_CMD_ISI2XX_GETGATETIME      MIO_CMD_GETGATETIME  /**< Read the gate time, which is measured in [us] and used for velocity measurement */
#define MIO_CMD_ISI2XX_SETGATETIME      MIO_CMD_SETGATETIME  /**< Allow to configuration of the gate time */
#define MIO_CMD_ISI2XX_GETNULLEDGE      MIO_CMD_GETNULLEDGE  /**< Allows the query of for which edge the zero pulse of the encoder is evaluated */
#define MIO_CMD_ISI2XX_ENABLENULL       MIO_CMD_ENABLENULL   /**< Allows to disable the wire break detection of the zero pulse of the encoder */
#define MIO_CMD_ISI2XX_ISNULLENABLED    MIO_CMD_ISNULLENABLED    /**< Query whether the wire break detection is enabled on the zero pulse of the encoder */
#define MIO_CMD_ISI2XX_SETACTIVELEVEL   MIO_CMD_SETACTIVELEVEL   /**< Define the level at which the initiator input shall be active */
#define MIO_CMD_ISI2XX_GETACTIVELEVEL   MIO_CMD_GETACTIVELEVEL   /**< Read the level at which the initiator input shall be active */
#define MIO_CMD_ISI2XX_GETRESETVALUE    MIO_CMD_GETRESETVALUE    /**< Select the SET register */
#define MIO_CMD_ISI2XX_SETRESETVALUE    MIO_CMD_SETRESETVALUE    /**< Write the SET register */
#define MIO_CMD_ISI2XX_GETDISTANCEREF   MIO_CMD_GETDISTANCEREF   /**< Read the reference register's automatic incrementation offset value */
#define MIO_CMD_ISI2XX_SETDISTANCEREF   MIO_CMD_SETDISTANCEREF   /**< Set the reference register's automatic incrementation offset value */
#define MIO_CMD_ISI2XX_CONFIGNULLEDGE   MIO_CMD_CONFIGNULLEDGE   /**< Allows the evaluation of the encoder's zero pulse with a positive or negative edge */
/** @} */

/**
 * @name Possible commands for the IO module CISI2XX
 * @{
 */

#define MIO_CMD_CISI2XX_DISABLERST      MIO_CMD_DISABLERST   /**< Allows to disable the referencing */
#define MIO_CMD_CISI2XX_ENABLERST       MIO_CMD_ENABLERST    /**< Allows to enable the referencing */
#define MIO_CMD_CISI2XX_SETREF          MIO_CMD_SETREF   /**< Set reference value */
#define MIO_CMD_CISI2XX_GETREF          MIO_CMD_GETREF   /**< Get reference register value */
#define MIO_CMD_CISI2XX_GETRST          MIO_CMD_GETRST   /**< Read the state of the encoder referencing */
#define MIO_CMD_CISI2XX_GETSTRB         MIO_CMD_GETSTRB  /**< Read strobe register value */
#define MIO_CMD_CISI2XX_RESET           MIO_CMD_RESET    /**< Reset complete INC/SSI chip */
#define MIO_CMD_CISI2XX_SETDLEN         MIO_CMD_SETDLEN  /**< Set SSI data length */
#define MIO_CMD_CISI2XX_GETDLEN         MIO_CMD_GETDLEN  /**< Read the set number of bits (0 to 32) of the data word of an SSI encoder */
#define MIO_CMD_CISI2XX_SETFREQ         MIO_CMD_SETFREQ  /**< Set SSI clock rate */
#define MIO_CMD_CISI2XX_GETFREQ         MIO_CMD_GETFREQ  /**< Read the frequency of the clock line for the SSI encoder */
#define MIO_CMD_CISI2XX_SETINTERVAL     MIO_CMD_SETINTERVAL  /**< Set SSI clock pause in us */
#define MIO_CMD_CISI2XX_GETINTERVAL     MIO_CMD_GETINTERVAL  /**< Read the clock pause in [us] */
#define MIO_CMD_CISI2XX_SETFILTER       MIO_CMD_SETFILTER    /**< Set filter frequency */
#define MIO_CMD_CISI2XX_GETFILTER       MIO_CMD_GETFILTER    /**< Read filter configuration */
#define MIO_CMD_CISI2XX_ZINIT           MIO_CMD_ZINIT    /**< OBSOLETE - Do not use! */
#define MIO_CMD_CISI2XX_GETVAL          MIO_CMD_GETVAL   /**< Read specific value */
#define MIO_CMD_CISI2XX_GETENCRES       MIO_CMD_GETENCRES    /**< Read the set values for monitoring the encoder resolution */
#define MIO_CMD_CISI2XX_SETENCRES       MIO_CMD_SETENCRES    /**< Enable or disable the monitoring of the encoder resolution */
#define MIO_CMD_CISI2XX_GETZEROSTAT     MIO_CMD_GETZEROSTAT  /**< Read encoder zero signal */
#define MIO_CMD_CISI2XX_GETGATETIME     MIO_CMD_GETGATETIME  /**< Read the gate time, which is measured in [us] and used for velocity measurement */
#define MIO_CMD_CISI2XX_SETGATETIME     MIO_CMD_SETGATETIME  /**< Allow to configuration of the gate time */
#define MIO_CMD_CISI2XX_GETNULLEDGE     MIO_CMD_GETNULLEDGE  /**< Allows the query of for which edge the zero pulse of the encoder is evaluated */
#define MIO_CMD_CISI2XX_ENABLENULL      MIO_CMD_ENABLENULL   /**< Allows to disable the wire break detection of the zero pulse of the encoder */
#define MIO_CMD_CISI2XX_ISNULLENABLED   MIO_CMD_ISNULLENABLED    /**< Query whether the wire break detection is enabled on the zero pulse of the encoder */
#define MIO_CMD_CISI2XX_SETACTIVELEVEL  MIO_CMD_SETACTIVELEVEL   /**< Define the level at which the initiator input shall be active */
#define MIO_CMD_CISI2XX_GETACTIVELEVEL  MIO_CMD_GETACTIVELEVEL   /**< Read the level at which the initiator input shall be active */
#define MIO_CMD_CISI2XX_GETRESETVALUE   MIO_CMD_GETRESETVALUE    /**< Select the SET register */
#define MIO_CMD_CISI2XX_SETRESETVALUE   MIO_CMD_SETRESETVALUE    /**< Write the SET register */
#define MIO_CMD_CISI2XX_GETDISTANCEREF  MIO_CMD_GETDISTANCEREF   /**< Read the reference register's automatic incrementation offset value */
#define MIO_CMD_CISI2XX_SETDISTANCEREF  MIO_CMD_SETDISTANCEREF   /**< Set the reference register's automatic incrementation offset value */
#define MIO_CMD_CISI2XX_CONFIGNULLEDGE  MIO_CMD_CONFIGNULLEDGE   /**< Allows the evaluation of the encoder's zero pulse with a positive or negative edge */
/** @} */

/**
 * @name Possible commands for the IO modules DIO248, DIO264 and DIO280 (DIO2XX)
 * @{
 */

#define MIO_CMD_DIO2XX_GETPWMCFG        MIO_CMD_GETPWMCFG    /**< Write PWM configuration of DO channel */
#define MIO_CMD_DIO2XX_SETPWMCFG        MIO_CMD_SETPWMCFG    /**< Write PWM configuration of DO channel */
#define MIO_CMD_DIO2XX_GETFILTER        MIO_CMD_GETFILTER    /**< Get filter time */
#define MIO_CMD_DIO2XX_SETFILTER        MIO_CMD_SETFILTER    /**< Set filter time */
#define MIO_CMD_DIO2XX_GETPINLEVELS     MIO_CMD_GETPINLEVELS     /**< Read pin levels of DIO channels */
#define MIO_CMD_DIO2XX_GETSTRB          MIO_CMD_GETSTRB  /**< Reads the strobe register */
#define MIO_CMD_DIO2XX_SETGATETIME      MIO_CMD_SETGATETIME  /**< Set the gate time used for #MIO_M_GATETIME */
#define MIO_CMD_DIO2XX_GETGATETIME      MIO_CMD_GETGATETIME  /**< Get the gate time used for #MIO_M_GATETIME */
#define MIO_CMD_DIO2XX_ENABLERST        MIO_CMD_ENABLERST    /**< Activate counter referencing through the INIT signal */
#define MIO_CMD_DIO2XX_DISABLERST       MIO_CMD_DISABLERST   /**< Disable counter referencing through the INIT signal */
#define MIO_CMD_DIO2XX_GETRST           MIO_CMD_GETRST   /**< Read the state of the encoder referencing */
#define MIO_CMD_DIO2XX_CONFIGNULLEDGE   MIO_CMD_CONFIGNULLEDGE   /**< Select INIT pulse edge */
#define MIO_CMD_DIO2XX_GETNULLEDGE      MIO_CMD_GETNULLEDGE  /**< Read selected INIT pulse edge */
#define MIO_CMD_DIO2XX_SETRESETVALUE    MIO_CMD_SETRESETVALUE    /**< Set value to be used at INIT pulse edge */
#define MIO_CMD_DIO2XX_GETRESETVALUE    MIO_CMD_GETRESETVALUE    /**< Read the value to be used at INIT pulse edge */
#define MIO_CMD_DIO2XX_SETTIMEOUT       MIO_CMD_SETTIMEOUT   /**< Write the timeout period of a counter channel */
#define MIO_CMD_DIO2XX_GETTIMEOUT       MIO_CMD_GETTIMEOUT   /**< Read the timeout period of a counter channel */
/** @} */

/**
 * @name Possible commands for the IO modules DIO216 and DIO232
 * @{
 */

#define MIO_CMD_DIO216_32_SETFILTER MIO_CMD_SETFILTER    /**< Set filter time */
#define MIO_CMD_DIO216_32_GETFILTER MIO_CMD_GETFILTER    /**< Get filter time */
/** @} */

/**
 * @name Possible commands for the IO module CDIO2XX
 * @{
 */

#define MIO_CMD_CDIO2XX_GETPWMCFG       MIO_CMD_GETPWMCFG    /**< Write PWM configuration of DO channel */
#define MIO_CMD_CDIO2XX_SETPWMCFG       MIO_CMD_SETPWMCFG    /**< Write PWM configuration of DO channel */
#define MIO_CMD_CDIO2XX_GETFILTER       MIO_CMD_GETFILTER    /**< Get filter time */
#define MIO_CMD_CDIO2XX_SETFILTER       MIO_CMD_SETFILTER    /**< Set filter time */
#define MIO_CMD_CDIO2XX_GETPINLEVELS    MIO_CMD_GETPINLEVELS     /**< Read pin levels of DIO channels */
#define MIO_CMD_CDIO2XX_GETSTRB         MIO_CMD_GETSTRB  /**< Reads the strobe register */
#define MIO_CMD_CDIO2XX_SETGATETIME     MIO_CMD_SETGATETIME  /**< Set the gate time used for #MIO_M_GATETIME */
#define MIO_CMD_CDIO2XX_GETGATETIME     MIO_CMD_GETGATETIME  /**< Get the gate time used for #MIO_M_GATETIME */
#define MIO_CMD_CDIO2XX_ENABLERST       MIO_CMD_ENABLERST    /**< Activate counter referencing through the INIT signal */
#define MIO_CMD_CDIO2XX_DISABLERST      MIO_CMD_DISABLERST   /**< Disable counter referencing through the INIT signal */
#define MIO_CMD_CDIO2XX_GETRST          MIO_CMD_GETRST   /**< Read the state of the encoder referencing */
#define MIO_CMD_CDIO2XX_CONFIGNULLEDGE  MIO_CMD_CONFIGNULLEDGE   /**< Select INIT pulse edge */
#define MIO_CMD_CDIO2XX_GETNULLEDGE     MIO_CMD_GETNULLEDGE  /**< Read selected INIT pulse edge */
#define MIO_CMD_CDIO2XX_SETRESETVALUE   MIO_CMD_SETRESETVALUE    /**< Set value to be used at INIT pulse edge */
#define MIO_CMD_CDIO2XX_GETRESETVALUE   MIO_CMD_GETRESETVALUE    /**< Read the value to be used at INIT pulse edge */
/** @} */

/**
 * @name Possible commands for the IO module AI20X/SI
 * @{
 */

#define MIO_CMD_READCALIB               61   /**< Read Calibration Data */
#define MIO_CMD_GETEVENT                62   /**< Read event flags */
#define MIO_CMD_SETMINMAXEVENT          63   /**< Set event configuration */
#define MIO_CMD_GETMINMAXEVENT          64   /**< Get event configuration */
#define MIO_CMD_SETMINMAXERROR          65   /**< Set error configuration */
#define MIO_CMD_GETMINMAXERROR          66   /**< Get error configuration */
#define MIO_CMD_AI20X_SETMINMAXEVENT    MIO_CMD_SETMINMAXEVENT   /**< Set event configuration */
#define MIO_CMD_AI20X_GETMINMAXEVENT    MIO_CMD_GETMINMAXEVENT   /**< Get event configuration */
#define MIO_CMD_AI20X_SETMINMAXERROR    MIO_CMD_SETMINMAXERROR   /**< Set error configuration */
#define MIO_CMD_AI20X_GETMINMAXERROR    MIO_CMD_GETMINMAXERROR   /**< Get error configuration */
#define MIO_CMD_AI20X_GETFILTER         MIO_CMD_GETFILTER    /**< Reads filter frequency of the digital input filter */
#define MIO_CMD_AI20X_SETFILTER         MIO_CMD_SETFILTER    /**< Sets frequency of the digital input filter */
/** @} */

/**
 * @name Possible commands for the CNT204
 * @{
 */

#define MIO_CMD_CNT204_DISABLERST       MIO_CMD_DISABLERST   /**< De-activate search home */
#define MIO_CMD_CNT204_ENABLERST        MIO_CMD_ENABLERST    /**< Activate search home */
#define MIO_CMD_CNT204_GETACT           MIO_CMD_GETACT   /**< Get actual counter value (CNT) */
#define MIO_CMD_CNT204_GETFILTER        MIO_CMD_GETFILTER    /**< Read filter configuration */
#define MIO_CMD_CNT204_GETFREQUENCY     MIO_CMD_GETFREQUENCY     /**< Get internal frequency */
#define MIO_CMD_CNT204_GETINCFILTER     MIO_CMD_GETINCFILTER     /**< Get filter for inputs configured as INC */
#define MIO_CMD_CNT204_GETINPSTAT       MIO_CMD_GETINPSTAT   /**< Get input status (only CNT) */
#define MIO_CMD_CNT204_GETREF           MIO_CMD_GETREF   /**< Get reference register value */
#define MIO_CMD_CNT204_GETSTRB          MIO_CMD_GETSTRB  /**< Get strobe register value */
#define MIO_CMD_CNT204_GETSTRBSTAT      MIO_CMD_GETSTRBSTAT  /**< Get strobe status */
#define MIO_CMD_CNT204_GETVAL           MIO_CMD_GETVAL   /**< Read specific value */
#define MIO_CMD_CNT204_GETZEROSTAT      MIO_CMD_GETZEROSTAT  /**< Read encoder zero signal */
#define MIO_CMD_CNT204_LOSTTIMEVAL      MIO_CMD_LOSTTIMEVAL  /**< Query if a value has been lost */
#define MIO_CMD_CNT204_NEWTIMEVAL       MIO_CMD_NEWTIMEVAL   /**< Query if a new value is available */
#define MIO_CMD_CNT204_RESETSTRBSTAT    MIO_CMD_RESETSTRBSTAT    /**< Reset strobe status */
#define MIO_CMD_CNT204_SETFILTER        MIO_CMD_SETFILTER    /**< Set filter frequency */
#define MIO_CMD_CNT204_SETINCFILTER     MIO_CMD_SETINCFILTER     /**< Set filter for inputs configured as INC */
#define MIO_CMD_CNT204_SETREF           MIO_CMD_SETREF   /**< Set reference value */
#define MIO_CMD_CNT204_ZINIT            MIO_CMD_ZINIT    /**< Read state of initiator */
#define MIO_CMD_CNT204_GETRST           MIO_CMD_GETRST   /**< Reads the state of the encoder referencing */
/** @} */

/**
 * @name Possible commands for the driver ECAT201
 * @{
 */

#define MIO_CMD_DCRESET         170  /**< Obsolete */
#define MIO_CMD_STOPMASTER      171  /**< Stop EtherCAT master */
#define MIO_CMD_STARTMASTER     172  /**< Start EtherCAT master */
#define MIO_CMD_RAWCMD          173  /**< Send raw EtherCAT command */
#define MIO_CMD_SDOREAD         174  /**< Read SDO (CoE) */
#define MIO_CMD_SDOWRITE        175  /**< Write SDO (CoE) */
#define MIO_CMD_GETOBJDICT      176  /**< Get object dictionary (CoE) */
#define MIO_CMD_GETOBJDESC      177  /**< Get object description (CoE) */
#define MIO_CMD_GETOBJENTRY     178  /**< Get object entry (CoE) */
#define MIO_CMD_GETEMCY         179  /**< Get emergency (CoE) */
#define MIO_CMD_GETMASTERSTATE  180  /**< Get master state */
#define MIO_CMD_SETMASTERSTATE  181  /**< Set master state */
#define MIO_CMD_GETSLAVESTATE   182  /**< Get slave state */
#define MIO_CMD_SETSLAVESTATE   183  /**< Set slave state */
#define MIO_CMD_SETDATAVALID    184  /**< Set data valid now (DMW200) */
#define MIO_CMD_GETCYCLEERROR   185  /**< Get cycle error (DMW200) */
#define MIO_CMD_RESETCYCLEERROR 186  /**< Reset cycle error (DMW200) */
#define MIO_CMD_GETCYCLETIME    187  /**< Get cycle time configuration (DMW200) */
#define MIO_CMD_EXCLUDESLAVE    188  /**< Exclude slave from configuration */
#define MIO_CMD_GETALIASADDR    189  /**< Get slave alias address */
#define MIO_CMD_SETALIASADDR    190  /**< Set slave alias address */
#define MIO_CMD_FILEREAD        191  /**< Read file (FoE) (not yet supported) */
#define MIO_CMD_FILEWRITE       192  /**< Write file (FoE) */
/** @} */

/**
 * @name Possible commands for the service OT1xx
 * @{
 */

#define MIO_CMD_READCONFIG      252  /**< @deprecated use now MIO_CMD_READIDREG */
#define MIO_CMD_WRITECONFIG     253  /**< @deprecated use now MIO_CMD_WRITEIDREG */
#define MIO_CMD_READFONTLIST    254
#define MIO_CMD_WRITEFONTLIST   255
#define MIO_CMD_GETHWINFO       256
#define MIO_CMD_WRITESTARTPAGE  257
#define MIO_CMD_DELSTARTPAGE    258
#define MIO_CMD_GETCONNSTATE    259
#define MIO_CMD_TESTFLASH       260  /**< only for RUNIN!! */
#define MIO_CMD_TESTRAM         261  /**< only for RUNIN!! */
#define MIO_CMD_SETDISPLCONFIG  262
#define MIO_CMD_READOPDATA      263
#define MIO_CMD_RESETOPDATA     264  /**< only for RUNIN!! */
/** @} */

/**
 * @name Possible commands for the IO module DOR2xx
 * @{
 */

#define MIO_CMD_GETSWITCHCOUNT      281  /**< Returns the number of switch cycles. */
#define MIO_CMD_RESETSWITCHCOUNT    282
/** @} */

/**
 * @name Possible commands for the driver PN201 / PN23
 * @{
 */

#define MIO_CMD_RECREAD         300
#define MIO_CMD_RECWRITE        301
#define MIO_CMD_GETERRSTAT      302
#define MIO_CMD_RESETERRSTAT    303
#define MIO_CMD_SETERROR        304
#define MIO_CMD_GETDIAGALARM    305
/** @} */

/**
 * @name Possible commands for IO modules
 * @{
 */

#define MIO_CMD_PICONFIGURE         320  /**< Process image: Configure the process image */
#define MIO_CMD_PIINIT              321  /**< Process image: Initialize process image of driver */
#define MIO_CMD_PIDEINIT            322  /**< Process image: Free resources used by the process image */
#define MIO_CMD_PIGETCONFIGURE      323  /**< Process image: Check if a channel is configured */
#define MIO_CMD_GETCARDADDR         350  /**< Unit test: Return the card address */
#define MIO_CMD_SETCARDADDR         351  /**< Unit test: Override the card address */
#define MIO_CMD_SETCALIB            352  /**< Unit test: Override the card calibrations */
#define MIO_CMD_SETVERIFYERR        370  /**< Set a write verify error */
#define MIO_CMD_GET_MODULE_WARNINGS 380  /**< Return Module specific warnings */
#define MIO_CMD_UPDATESW_M86        381  /**< Update m86 file on module */
#define MIO_CMD_NEWCONFIG_FILE      382  /**< Reads configuration from given file */
/** @} */

/**
 * @name Possible commands for the software module BCH200
 * @{
 */

#define MIO_CMD_UPDATEDATA  400
#define MIO_CMD_GETSLVINFO  401
/** @} */

/**
 * @name Possible commands for the driver DMW200
 * @{
 */

#define MIO_CMD_PARMINITCHK 500  /**< Initialize and check drive parameters */
/** @} */

/**
 * @name Parameters for MIO_CMD_UPDATEDATA
 * @{
 */

#define MIO_UPDATE_IN   0x01
#define MIO_UPDATE_OUT  0x02
#define MIO_UPDATE_ALL  (MIO_UPDATE_IN | MIO_UPDATE_OUT)
/** @} */

/**
 * Possible commands for all
 */
/**
 * @name Parameters for MIO_CMD_START
 * @{
 */

#define MIO_START_NOW   0x0001   /**< Start immediately */
#define MIO_START_HOME  0x0002   /**< Start with referencing of counter */
#define MIO_START_REF   0x0004   /**< Start with reference value of channel 13 */
#define MIO_START_SYNC  0x0008   /**< Start on next sync-interrupt */
/** @} */

/**
 * @name Parameters for MIO_CMD_GETSTATUS
 * @{
 */

#define MIO_IDLE        0x0001   /**< Module is in idle operation */
#define MIO_EXPORTING   0x0002   /**< Recording is being exported */
#define MIO_RECORDING   0x0004   /**< Recording is in progress */
#define MIO_READING     0x0008   /**< Recording is being read */
#define MIO_BUSY        0x0010
/** @} */

/**
 * @name Possible commands for the IO module AIC212
 * @{
 */

#define MIO_CMD_EXPORTVALUES            200  /**< Export an already completed recording in a *.zip file. */
#define MIO_CMD_SIMULATEVALUES          201  /**< Simulate measurement data in virtual operation mode. */
#define MIO_CMD_START                   202  /**< Start recording of activated channels. */
#define MIO_CMD_STOP                    203  /**< Stop recording. */
#define MIO_CMD_SETTEMPDIR              204  /**< Set the directory for temporary export files. */
#define MIO_CMD_GETTEMPDIR              205  /**< Get the directory for temporary export files. */
#define MIO_CMD_SETCOMPRESSION          206  /**< Set the compression level of *.zip-files for export. */
#define MIO_CMD_GETCOMPRESSION          207  /**< Read the compression level of *.zip-files for export. */
#define MIO_CMD_SETRECORDLEN            208  /**< Set the record data size. */
#define MIO_CMD_GETRECORDLEN            209  /**< Get record data size. */
#define MIO_CMD_GETSTATUS               210  /**< Get current state of the module. */
#define MIO_CMD_GETVALUES               211  /**< Get the channel values after a recording. */
#define MIO_CMD_OPEN                    212  /**< Open a zip file to read. */
#define MIO_CMD_CLOSE                   213  /**< Close a zip file (opened with #MIO_CMD_OPEN). */
#define MIO_CMD_READSAMPLES             214  /**< Read channel values from a zip file (opened with #MIO_CMD_OPEN). */
#define MIO_CMD_READHEADER              215  /**< Read record headers from a file (opened with #MIO_CMD_OPEN). */
#define MIO_CMD_GETMEMSIZE              216  /**< Get the size of the memory installed on the AIC212. */
#define MIO_CMD_AIC212_CLOSE            MIO_CMD_CLOSE    /**< Close a zip file (opened with #MIO_CMD_AIC212_OPEN). */
#define MIO_CMD_AIC212_DISABLERST       MIO_CMD_DISABLERST   /**< Disable referencing, deactivate zeroing. */
#define MIO_CMD_AIC212_ENABLERST        MIO_CMD_ENABLERST    /**< Enable referencing, activate zeroing. */
#define MIO_CMD_AIC212_EXPORTVALUES     MIO_CMD_EXPORTVALUES     /**< Export an already completed recording in a *.zip file. */
#define MIO_CMD_AIC212_GETACT           MIO_CMD_GETACT   /**< Get actual counter value (CNT). */
#define MIO_CMD_AIC212_GETCOMPRESSION   MIO_CMD_GETCOMPRESSION   /**< Read the compression level of *.zip-files for export. */
#define MIO_CMD_AIC212_GETFILTER        MIO_CMD_GETFILTER    /**< Read filter frequency of the digital input filter. */
#define MIO_CMD_AIC212_GETFREQUENCY     MIO_CMD_GETFREQUENCY     /**< Get the internal frequency of a module. */
#define MIO_CMD_AIC212_GETINPSTAT       MIO_CMD_GETINPSTAT   /**< Read the status of counter inputs. */
#define MIO_CMD_AIC212_GETMEMSIZE       MIO_CMD_GETMEMSIZE   /**< Get the size of the memory installed on the AIC212. */
#define MIO_CMD_AIC212_GETRECORDLEN     MIO_CMD_GETRECORDLEN     /**< Get record data size. */
#define MIO_CMD_AIC212_GETREF           MIO_CMD_GETREF   /**< Get the reference value. */
#define MIO_CMD_AIC212_GETRST           MIO_CMD_GETRST   /**< Read state of encoder referencing. */
#define MIO_CMD_AIC212_GETSTATUS        MIO_CMD_GETSTATUS    /**< Get current state of the module. */
#define MIO_CMD_AIC212_GETSTRB          MIO_CMD_GETSTRB  /**< Get strobe register value. */
#define MIO_CMD_AIC212_GETSTRBSTAT      MIO_CMD_GETSTRBSTAT  /**< Get strobe status (CNT). */
#define MIO_CMD_AIC212_GETTEMPDIR       MIO_CMD_GETTEMPDIR   /**< Get the directory for temporary export files. */
#define MIO_CMD_AIC212_GETVALUES        MIO_CMD_GETVALUES    /**< Get the channel values after a recording. */
#define MIO_CMD_AIC212_GETZEROSTAT      MIO_CMD_GETZEROSTAT  /**< Read encoder zero signal (CNT). */
#define MIO_CMD_AIC212_OPEN             MIO_CMD_OPEN     /**< Open a zip file to read. */
#define MIO_CMD_AIC212_READHEADER       MIO_CMD_READHEADER   /**< Read record headers from a file (opened with #MIO_CMD_AIC212_OPEN). */
#define MIO_CMD_AIC212_READSAMPLES      MIO_CMD_READSAMPLES  /**< Read channel values from a zip file (opened with #MIO_CMD_AIC212_OPEN). */
#define MIO_CMD_AIC212_RESETSTRBSTAT    MIO_CMD_RESETSTRBSTAT    /**< Reset the status of the strobe register. */
#define MIO_CMD_AIC212_SETCOMPRESSION   MIO_CMD_SETCOMPRESSION   /**< Set the compression level of *.zip-files for export. */
#define MIO_CMD_AIC212_SETFILTER        MIO_CMD_SETFILTER    /**< Set the frequency of the digital input filter. */
#define MIO_CMD_AIC212_SETRECORDLEN     MIO_CMD_SETRECORDLEN     /**< Set the record data size. */
#define MIO_CMD_AIC212_SETREF           MIO_CMD_SETREF   /**< Set the reference value. */
#define MIO_CMD_AIC212_SETTEMPDIR       MIO_CMD_SETTEMPDIR   /**< Set the directory for temporary export files. */
#define MIO_CMD_AIC212_SIMULATEVALUES   MIO_CMD_SIMULATEVALUES   /**< Simulate measurement data in virtual operation mode. */
#define MIO_CMD_AIC212_START            MIO_CMD_START    /**< Start recording of activated channels. */
#define MIO_CMD_AIC212_STOP             MIO_CMD_STOP     /**< Stop recording. */
#define MIO_CMD_AIC212_ZINIT            MIO_CMD_ZINIT    /**< Read the status of counter inputs. */
/** @} */

/**
 * @name Possible commands for the IO module DMS202
 * @{
 */

#define MIO_CMD_DMSBASE         1000
#define MIO_CMD_PEEKRW          (MIO_CMD_DMSBASE + 0)
#define MIO_CMD_PEEKRO          (MIO_CMD_DMSBASE + 1)
#define MIO_CMD_SETCHMODE       (MIO_CMD_DMSBASE + 2)
#define MIO_CMD_SETCHFILTER     (MIO_CMD_DMSBASE + 3)
#define MIO_CMD_GETSYSERR       (MIO_CMD_DMSBASE + 4)
#define MIO_CMD_START_M         (MIO_CMD_DMSBASE + 5)
#define MIO_CMD_STOP_M          (MIO_CMD_DMSBASE + 6)
#define MIO_CMD_CHSELECT        (MIO_CMD_DMSBASE + 7)
#define MIO_CMD_SETSAMPTIM      (MIO_CMD_DMSBASE + 8)
#define MIO_CMD_SETSYNCMST      (MIO_CMD_DMSBASE + 9)
#define MIO_CMD_SETSYNCSLV      (MIO_CMD_DMSBASE + 10)
#define MIO_CMD_SETCALACCESS    (MIO_CMD_DMSBASE + 11)
#define MIO_CMD_INITCAL         (MIO_CMD_DMSBASE + 12)
#define MIO_CMD_SETCALRANGE     (MIO_CMD_DMSBASE + 13)
#define MIO_CMD_STORECALLO      (MIO_CMD_DMSBASE + 14)
#define MIO_CMD_STORECALHI      (MIO_CMD_DMSBASE + 15)
#define MIO_CMD_CALCGO          (MIO_CMD_DMSBASE + 16)
#define MIO_CMD_STORECHCAL      (MIO_CMD_DMSBASE + 17)
#define MIO_CMD_SETCDAC         (MIO_CMD_DMSBASE + 18)
#define MIO_CMD_SETODAC         (MIO_CMD_DMSBASE + 19)
#define MIO_CMD_SETDEFCAL       (MIO_CMD_DMSBASE + 20)
#define MIO_CMD_SETFACCAL       (MIO_CMD_DMSBASE + 21)
#define MIO_CMD_CAL2EEPROM      (MIO_CMD_DMSBASE + 22)
#define MIO_CMD_RDCALSTRUCT     (MIO_CMD_DMSBASE + 23)
#define MIO_CMD_RDCALDATA       (MIO_CMD_DMSBASE + 24)
#define MIO_CMD_WRCALSTRUCT     (MIO_CMD_DMSBASE + 25)
#define MIO_CMD_WRCALDATA       (MIO_CMD_DMSBASE + 26)
#define MIO_CMD_ZEROCALIB       (MIO_CMD_DMSBASE + 27)
#define MIO_CMD_OFFSETCAL       (MIO_CMD_DMSBASE + 28)
#define MIO_CMD_TSTRESTOREEEP   (MIO_CMD_DMSBASE + 29)
#define MIO_CMD_TSTREADEEP      (MIO_CMD_DMSBASE + 30)
#define MIO_CMD_WRITEEEP        (MIO_CMD_DMSBASE + 31)
#define MIO_CMD_READMEM         (MIO_CMD_DMSBASE + 32)
#define MIO_CMD_WRITEMEM        (MIO_CMD_DMSBASE + 33)
#define MIO_CMD_TSTERASEEEP     (MIO_CMD_DMSBASE + 34)
#define MIO_CMD_TSTWDOG         (MIO_CMD_DMSBASE + 35)
#define MIO_CMD_READADC         (MIO_CMD_DMSBASE + 36)
#define MIO_CMD_RDANALOGST      (MIO_CMD_DMSBASE + 37)
#define MIO_CMD_RDACTCALDATA    (MIO_CMD_DMSBASE + 38)
#define MIO_CMD_ZEROCALTMP      (MIO_CMD_DMSBASE + 39)
#define MIO_CMD_OFFSETCALTMP    (MIO_CMD_DMSBASE + 40)
/** @} */

/**
 * @name Possible commands for the IO module IOP201
 * @{
 */

#define MIO_CMD_IOPBASE     2000
#define MIO_CMD_SETCONTREG  (MIO_CMD_IOPBASE + 1)
#define MIO_CMD_INITCOMM    (MIO_CMD_IOPBASE + 2)
#define MIO_CMD_SETSTATE    (MIO_CMD_IOPBASE + 3)    /**< Sets the state */
#define MIO_CMD_GETSTATE    (MIO_CMD_IOPBASE + 4)    /**< Reads the state */
#define MIO_CMD_GETDATAPTR  (MIO_CMD_IOPBASE + 5)
#define MIO_CMD_GETDATA     (MIO_CMD_IOPBASE + 6)
/** @} */

/**
 * @name internal test functions
 * @{
 */

#define MIO_CMD_TSTRUNIN    (MIO_CMD_IOPBASE + 0x0401)
#define MIO_CMD_TSTSETIOP   (MIO_CMD_IOPBASE + 0x0402)
#define MIO_CMD_TSTSIMIOP   (MIO_CMD_IOPBASE + 0x0403)
#define MIO_CMD_TSTREADIOP  (MIO_CMD_IOPBASE + 0x0404)
#define MIO_CMD_TSTWRITEIOP (MIO_CMD_IOPBASE + 0x0405)
#define MIO_CMD_TSTLOOPBACK (MIO_CMD_IOPBASE + 0x0406)
/** @} */

/**
 * @name Possible commands for the driver MBM201
 * @{
 */

#define MIO_CMD_MBMBASE         3000
#define MIO_CMD_SENDMBMESSAGE   (MIO_CMD_MBMBASE + 1)
#define MIO_CMD_CHANGEPOLLRATE  (MIO_CMD_MBMBASE + 2)
#define MIO_CMD_GETPOLLRATE     (MIO_CMD_MBMBASE + 3)
#define MIO_CMD_GETMBMCHANINF   (MIO_CMD_MBMBASE + 4)
/** @} */

/**
 * @name Possible commands for UFB Modules
 * @{
 */

#define MIO_CMD_UFB_BASE            4000
#define MIO_CMD_UFB_CONTAINER       (MIO_CMD_UFB_BASE + 1)
#define MIO_CMD_UFB_ADDSVAR         (MIO_CMD_UFB_BASE + 2)
#define MIO_CMD_UFB_GETCUSTOMERID   (MIO_CMD_UFB_BASE + 10)
#define MIO_CMD_UFB_SETCUSTOMERID   (MIO_CMD_UFB_BASE + 11)
/** @} */

/**
 * @name Possible commands for CAN drivers, when running in NativeCAN Mode
 * @{
 */

#define MIO_CMD_CAN_BASE        5000
#define MIO_CMD_CAN_RECEIVE     (MIO_CMD_CAN_BASE + 1)   /**< Polling for the CAN message queue (received and/or sent messages) */
#define MIO_CMD_CAN_SEND        (MIO_CMD_CAN_BASE + 2)   /**< Put a Message into the transmit queue for sending to the CAN bus */
#define MIO_CMD_CAN_START       (MIO_CMD_CAN_BASE + 3)   /**< Start the SJA1000 CAN Controller with the configured mode */
#define MIO_CMD_CAN_RESET       (MIO_CMD_CAN_BASE + 4)   /**< Resets the SJA1000 CAN Controller (receive and transmit is stopped) */
#define MIO_CMD_CAN_BAUDRATE    (MIO_CMD_CAN_BASE + 5)   /**< Set a new CAN Bit-Rate (10..1000 kBit/s) this command is also available for CANopen */
#define MIO_CMD_CAN_STATE       (MIO_CMD_CAN_BASE + 6)   /**< Get the status informations of the CAN-Network */
/** @} */

/**
 * @name Possible commands for safety drivers
 * @{
 */

#define MIO_CMD_SAFETYBASE              6000
#define MIO_CMD_SAFETYSENDSTR           (MIO_CMD_SAFETYBASE + 1)     /**< Send string */
#define MIO_CMD_SAFETYRECVSTR           (MIO_CMD_SAFETYBASE + 2)     /**< Receive string */
#define MIO_CMD_SAFETYSENDBIN           (MIO_CMD_SAFETYBASE + 3)     /**< Send binary */
#define MIO_CMD_SAFETYRECVBIN           (MIO_CMD_SAFETYBASE + 4)     /**< Receive binary */
#define MIO_CMD_SAFETYSENDCMD           (MIO_CMD_SAFETYBASE + 5)     /**< Send command */
#define MIO_CMD_SAFETYSENDFILE          (MIO_CMD_SAFETYBASE + 6)     /**< Send file */
#define MIO_CMD_SAFETYRECVFILE          (MIO_CMD_SAFETYBASE + 7)     /**< Receive file */
#define MIO_CMD_SAFETYFILESTAT          (MIO_CMD_SAFETYBASE + 8)     /**< Get file statistic */
#define MIO_CMD_SAFETYSENDRECVBIN       (MIO_CMD_SAFETYBASE + 9)     /**< Send and receive binary */
#define MIO_CMD_SAFETYUSERLOGIN         (MIO_CMD_SAFETYBASE + 10)    /**< User login */
#define MIO_CMD_SAFETYUSERLOGOUT        (MIO_CMD_SAFETYBASE + 11)    /**< User logout */
#define MIO_CMD_SAFETYUSERSHOWACT       (MIO_CMD_SAFETYBASE + 12)    /**< Show actual user */
#define MIO_CMD_SAFETYDOWNLOADNEWPRO    (MIO_CMD_SAFETYBASE + 13)    /**< Download a new SLC program */
#define MIO_CMD_SAFETYGETUID            (MIO_CMD_SAFETYBASE + 14)    /**< Get the unique ID of a safety module */
#define MIO_CMD_SAFETYASSIGNMODULES     (MIO_CMD_SAFETYBASE + 15)    /**< Assign modules */
#define MIO_CMD_SAFETYDBGRUN            (MIO_CMD_SAFETYBASE + 16)    /**< Run in debug mode */
#define MIO_CMD_SAFETYDBGSTOP           (MIO_CMD_SAFETYBASE + 17)    /**< Stop in debug mode */
#define MIO_CMD_ERASEUSERPROGRAM        (MIO_CMD_SAFETYBASE + 18)    /**< Erase the user program of a SLC */
#define MIO_CMD_SETUID                  (MIO_CMD_SAFETYBASE + 19)    /**< Set the unique ID of the module (internal use only) */
#define MIO_CMD_GETNBFREELOGITEMS       (MIO_CMD_SAFETYBASE + 20)    /**< Return the number of free logbook items */
#define MIO_CMD_GETERRORCODE            (MIO_CMD_SAFETYBASE + 21)    /**< Get the actual error code */
#define MIO_CMD_PERFORMEXTMEMTST        (MIO_CMD_SAFETYBASE + 22)    /**< Test the external memories */
#define MIO_CMD_SAFETYGETVERSION_B      (MIO_CMD_SAFETYBASE + 23)    /**< Get the version of the second processor */
#define MIO_CMD_SAFETYMEASWDGTIME       (MIO_CMD_SAFETYBASE + 24)    /**< Measure the watchdog time of the two processors (internal use only) */
#define MIO_CMD_SAFETYGETCHANINF        (MIO_CMD_SAFETYBASE + 25)    /**< Get safety specific channel information */
#define MIO_CMD_SAFETYGETPROGRAMCRC     (MIO_CMD_SAFETYBASE + 26)    /**< Get the checksums of a SLC program (scripts) */
/** @} */

/**
 * @name Possible commands for the IO module TI214
 * @{
 */

#define MIO_CMD_TIBASE          7000
#define MIO_CMD_SETAVERAGING    (MIO_CMD_TIBASE + 1)     /**< Determines the number of measurement values for averaging. */
#define MIO_CMD_GETAVERAGING    (MIO_CMD_TIBASE + 2)     /**< Reads the number of measurement values for averaging. */
/** @} */

/**
 * @name Possible commands for the IO module AP211
 * @{
 */

#define MIO_CMD_APBASE          7100
#define MIO_CMD_SETGAIN         (MIO_CMD_APBASE + 1)     /**< write gain */
#define MIO_CMD_GETGAIN         (MIO_CMD_APBASE + 2)     /**< read gain */
#define MIO_CMD_SETOFFSET       (MIO_CMD_APBASE + 3)     /**< write offset */
#define MIO_CMD_GETOFFSET       (MIO_CMD_APBASE + 4)     /**< read offset */
#define MIO_CMD_SETCYCLECFG     (MIO_CMD_APBASE + 5)     /**< write cycle configuration */
#define MIO_CMD_GETCYCLECFG     (MIO_CMD_APBASE + 6)     /**< read cycle configuration */
#define MIO_CMD_SETHYSTERESIS   (MIO_CMD_APBASE + 7)     /**< write hysteresis */
#define MIO_CMD_GETHYSTERESIS   (MIO_CMD_APBASE + 8)     /**< read hysteresis */
#define MIO_CMD_GETCOUNT        (MIO_CMD_APBASE + 9)     /**< read count */
#define MIO_CMD_READFIFO        (MIO_CMD_APBASE + 10)    /**< read FIFO values */
#define MIO_CMD_SIMFIFO         (MIO_CMD_APBASE + 11)    /**< simulate FIFO values */
#define MIO_CMD_GETSUM          (MIO_CMD_APBASE + 12)    /**< read sum values */
/** @} */

/**
 * @name Possible commands for the IO module FX2XX
 * @{
 */

#define MIO_CMD_FMBASE          7200
#define MIO_CMD_GETSUPPLY       (MIO_CMD_FMBASE + 1)     /**< Transceiver Supply */
#define MIO_CMD_GETTXBIAS       (MIO_CMD_FMBASE + 2)     /**< TX Bias */
#define MIO_CMD_GETTXPOWER      (MIO_CMD_FMBASE + 3)     /**< TX Output Power */
#define MIO_CMD_GETRXPOWER      (MIO_CMD_FMBASE + 4)     /**< RX Output Power */
#define MIO_CMD_GETSCALEVALUES  (MIO_CMD_FMBASE + 5)     /**< Get scale Values for Fibre Diagnosis */
#define MIO_CMD_SETSCALEVALUES  (MIO_CMD_FMBASE + 6)     /**< Set scale Values for Fibre Diagnosis */
#define MIO_CMD_GETTHRESHOLD    (MIO_CMD_FMBASE + 7)     /**< Get FO thresholds */
#define MIO_CMD_GETCABLETYPE    (MIO_CMD_FMBASE + 8)     /**< Get configured (jumper) cable type */
#define MIO_CMD_REINITFM        (MIO_CMD_FMBASE + 20)    /**< For internal use only: Reinit Fastbus master */
#define MIO_CMD_RESETFM         (MIO_CMD_FMBASE + 21)    /**< For internal use only: Resets Fastbus master */
/** @} */

/**
 * @name Commands for the IO module FCS2XX
 * @{
 */

#define MIO_CMD_FCSBASE             7300
#define MIO_CMD_DIAG_GET_LNK        (MIO_CMD_FCSBASE + 1)    /**< Get the link status for a port */
#define MIO_CMD_DIAG_GET_DUPLEX     (MIO_CMD_FCSBASE + 2)    /**< Get the duplexity for a port */
#define MIO_CMD_DIAG_GET_SPEED      (MIO_CMD_FCSBASE + 3)    /**< Get the speed for a port */
#define MIO_CMD_DIAG_BAD_TRAFFIC_IN (MIO_CMD_FCSBASE + 4)    /**< Get the sum of bytes of bad Frames for a port */
#define MIO_CMD_DIAG_TRAFFIC_IN     (MIO_CMD_FCSBASE + 5)    /**< Get the sum of bytes of good incoming Frames for a port */
#define MIO_CMD_DIAG_TRAFFIC_OUT    (MIO_CMD_FCSBASE + 6)    /**< Get the sum of bytes of outgoing Frames for a port */
#define MIO_CMD_SETTRIGGERVALUES    (MIO_CMD_FCSBASE + 7)    /**< Write the interrupt level value */
#define MIO_CMD_SETRESETCAPABILITY  (MIO_CMD_FCSBASE + 8)    /**< Set modules reset capability */
#define MIO_CMD_GETRESETCAPABILITY  (MIO_CMD_FCSBASE + 9)    /**< Get modules reset capability */
#define MIO_CMD_GETMIRRORCFG        (MIO_CMD_FCSBASE + 10)   /**< Get Mirror Configuration */
#define MIO_CMD_SETMIRRORCFG        (MIO_CMD_FCSBASE + 11)   /**< Set Mirror Configuration */
/** @} */

/**
 * @name Possible commands for the IO module GMP232
 * @{
 */

#define MIO_CMD_GMPBASE             7400
#define MIO_CMD_SYNCTIME            (MIO_CMD_GMPBASE + 1)    /**< Synchronize the internal clock (only used internally) */
#define MIO_CMD_PROCESSINIFILE      (MIO_CMD_GMPBASE + 2)    /**< Processes the parameter file (only used internally) */
#define MIO_CMD_SETFREQUENCYWINDOW  (MIO_CMD_GMPBASE + 3)    /**< Sets the frequency window */
#define MIO_CMD_GETFREQUENCYWINDOW  (MIO_CMD_GMPBASE + 4)    /**< Reads the frequency window range */
#define MIO_CMD_SETRUNTHROUGH       (MIO_CMD_GMPBASE + 5)    /**< Activates the run through mode */
#define MIO_CMD_GETRUNTHROUGH       (MIO_CMD_GMPBASE + 6)    /**< Reads the current run through mode setting */
#define MIO_CMD_GETSCOPE            (MIO_CMD_GMPBASE + 7)    /**< Reads the scope data */
#define MIO_CMD_SETSCOPECFG         (MIO_CMD_GMPBASE + 8)    /**< Sets the scope configuration */
#define MIO_CMD_GETSCOPECFG         (MIO_CMD_GMPBASE + 9)    /**< Returns the Scope configuration created via MIO_CMD_SETSCOPECFG. */
#define MIO_CMD_GETSCOPESTATE       (MIO_CMD_GMPBASE + 10)   /**< Returns the state of the Scope status machine. */
#define MIO_CMD_EXPORTSCOPE         (MIO_CMD_GMPBASE + 11)   /**< Exports the scope data */
#define MIO_CMD_TAKESCOPELOCK       (MIO_CMD_GMPBASE + 12)   /**< Takes the scope lock */
#define MIO_CMD_GIVESCOPELOCK       (MIO_CMD_GMPBASE + 13)   /**< Gives the previously taken scope lock */
#define MIO_CMD_SETSTATUE           (MIO_CMD_GMPBASE + 14)   /**< Sets the module state */
#define MIO_CMD_DELETEALARMHISTORY  (MIO_CMD_GMPBASE + 15)   /**< Deletes the alarm history entries */
#define MIO_CMD_GETALARMHISTORY     (MIO_CMD_GMPBASE + 16)   /**< Reads the alarm history */
#define MIO_CMD_TAKEHISTORYLOCK     (MIO_CMD_GMPBASE + 17)   /**< Takes the lock for the history */
#define MIO_CMD_GIVEHISTORYLOCK     (MIO_CMD_GMPBASE + 18)   /**< Gives the previously taken history lock */
#define MIO_CMD_SETFRT              (MIO_CMD_GMPBASE + 19)   /**< Sets the FRT table values (Fault Ride Through) of the voltage inputs. */
#define MIO_CMD_GETFRT              (MIO_CMD_GMPBASE + 20)   /**< Returns the FRT table values (Fault Ride Through). */
#define MIO_CMD_GETPREINITERROR     (MIO_CMD_GMPBASE + 21)   /**< Reads the pre initialization error */
#define MIO_CMD_SETLIMITCFG         (MIO_CMD_GMPBASE + 22)   /**< Specifies the generation conditions for event or error interrupts at over voltage or under voltage. */
#define MIO_CMD_GETLIMITCFG         (MIO_CMD_GMPBASE + 23)   /**< Reads the generation conditions for event or error interrupts at overvoltage or undervoltage. */
#define MIO_CMD_GETCONFIG           (MIO_CMD_GMPBASE + 24)   /**< Reads the module configuration */
#define MIO_CMD_GETSELECTEDVALUES   (MIO_CMD_GMPBASE + 25)   /**< Reads the selected values */
#define MIO_CMD_SETHARMONICSLIMIT   (MIO_CMD_GMPBASE + 26)   /**< Configures the event interrupt for the factor between the harmonics. */
#define MIO_CMD_GETHARMONICSLIMIT   (MIO_CMD_GMPBASE + 27)   /**< Reads the configuration of the event interrupt for the factor between the harmonics. */
#define MIO_CMD_GETHARMONICS        (MIO_CMD_GMPBASE + 28)   /**< Reads the harmonic values */
#define MIO_CMD_SETVECTORJMPLIMIT   (MIO_CMD_GMPBASE + 29)   /**< Specifies the generation conditions at vector jump error interrupts. */
#define MIO_CMD_GETVECTORJMPLIMIT   (MIO_CMD_GMPBASE + 30)   /**< Reads the generation conditions at vector jump error interrupts. */
#define MIO_CMD_GETSTATISTICS       (MIO_CMD_GMPBASE + 31)   /**< Reads statistic values */
#define MIO_CMD_RESETSTATISTICS     (MIO_CMD_GMPBASE + 32)   /**< Resets statistic values */
#define MIO_CMD_RESETRELAY          (MIO_CMD_GMPBASE + 34)   /**< Resets the relay to default state */
#define MIO_CMD_GETRELAISMAPPING    (MIO_CMD_GMPBASE + 35)
#define MIO_CMD_SETRELEAISMAPPING   (MIO_CMD_GMPBASE + 36)
#define MIO_CMD_GETSIMDATA          (MIO_CMD_GMPBASE + 37)   /**< Reads the simulated data */
#define MIO_CMD_SETSIMDATA          (MIO_CMD_GMPBASE + 38)   /**< Sets the simulated data */
#define MIO_CMD_SETENERGY           (MIO_CMD_GMPBASE + 39)   /**< Sets the energy to a given value */
#define MIO_CMD_GETENERGY           (MIO_CMD_GMPBASE + 40)   /**< Reads the energy values */
#define MIO_CMD_EXITTIMERTASK       (MIO_CMD_GMPBASE + 41)   /**< For internal use only! */
#define MIO_CMD_GETPHASEANGLES      (MIO_CMD_GMPBASE + 42)   /**< Reads the phase angle values */
#define MIO_CMD_FORCERELAY          (MIO_CMD_GMPBASE + 43)   /**< Forces the relay into the given state */
#define MIO_CMD_GETNBSTATISTICS     (MIO_CMD_GMPBASE + 44)   /**< Reads number of statistics */
#define MIO_CMD_DISPSTATISTICS      (MIO_CMD_GMPBASE + 46)   /**< Reads statistic information with some extra information */
#define MIO_CMD_GETVECTORDIAGRAM    (MIO_CMD_GMPBASE + 47)   /**< Reads vector diagram */
#define MIO_CMD_SETRELAYCFG         (MIO_CMD_GMPBASE + 48)   /**< Sets Relay Configuration */
#define MIO_CMD_GETRELAYCFG         (MIO_CMD_GMPBASE + 49)   /**< Reads Relay Configuration */
#define MIO_CMD_TRIGGERSCOPE        (MIO_CMD_GMPBASE + 50)   /**< Triggers the scope (manually) */
#define MIO_CMD_GETPREINITEVENT     (MIO_CMD_GMPBASE + 51)   /**< Reads the pre initialization event */
#define MIO_CMD_EXPORTSCOPEINTASK   (MIO_CMD_GMPBASE + 52)   /**< Exports the scope data in a task */
#define MIO_CMD_SETROCOFLIMIT       (MIO_CMD_GMPBASE + 53)   /**< Specifies the generation conditions of an ROCOF error interrupt */
#define MIO_CMD_GETROCOFLIMIT       (MIO_CMD_GMPBASE + 54)   /**< Reads the generation conditions of ROCOF error interrupt */
#define MIO_CMD_SETASYMLIMIT        (MIO_CMD_GMPBASE + 55)   /**< Specifies the generation conditions of a voltage/current asymmetry error interrupt. */
#define MIO_CMD_GETASYMLIMIT        (MIO_CMD_GMPBASE + 56)   /**< Reads the generation conditions of a voltage/current asymmetry error interrupt */
#define MIO_CMD_SETENERGYREAL       (MIO_CMD_GMPBASE + 57)   /**< REAL64 version of MIO_CMD_SETENERGY */
#define MIO_CMD_GETENERGYREAL       (MIO_CMD_GMPBASE + 58)   /**< REAL64 version of MIO_CMD_GETENERGY */
#define MIO_CMD_GETSAMPLES          (MIO_CMD_GMPBASE + 59)   /**< Reads a certain number of sample values */
#define MIO_CMD_GETLATESTSAMPLE     (MIO_CMD_GMPBASE + 60)   /**< Reads the latest available sample value */
#define MIO_CMD_SETSAMPLECFG        (MIO_CMD_GMPBASE + 61)   /**< Configuration of the sample values */
#define MIO_CMD_GETSAMPLECFG        (MIO_CMD_GMPBASE + 62)   /**< Reads configuration of the sample values */
#define MIO_CMD_GETHIGHRESANGLES    (MIO_CMD_GMPBASE + 63)   /**< Reads high resolution angles */
/** @} */

/**
 * @name Possible commands for the IO module ECS200
 * @{
 */

#define MIO_CMD_ECSBASE         7500
#define MIO_CMD_GETSLAVEINFO    (MIO_CMD_ECSBASE + 1)
/** @} */

/**
 * @name Possible commands for the IO module MBUS
 * @{
 */

#define MIO_CMD_MBUS_BASE       7600
#define MIO_CMD_MBUS_GETSCALE   (MIO_CMD_MBUS_BASE + 1)
/** @} */

/**
 * @name Possible commands for the IO module GSP274 (some are also for other grid modules)
 * @{
 */

#define MIO_CMD_GSP_BASE                        7700
#define MIO_CMD_SETDICFG                        (MIO_CMD_GSP_BASE + 1)   /**< Configures one of the 2 DIChannel groups */
#define MIO_CMD_GETDICFG                        (MIO_CMD_GSP_BASE + 2)   /**< Reads the configuration of a DIChannel group */
#define MIO_CMD_GETIECVALUES                    (MIO_CMD_GSP_BASE + 3)   /**< Reads the IEC measured values. */
#define MIO_CMD_SETSYNCCFG                      (MIO_CMD_GSP_BASE + 4)   /**< Configures one of the two synchronization units. */
#define MIO_CMD_GETSYNCCFG                      (MIO_CMD_GSP_BASE + 5)   /**< Reads the configuration of one of the two synchronization units. */
#define MIO_CMD_SYNC                            (MIO_CMD_GSP_BASE + 6)   /**< Start/stop synchronisation */
#define MIO_CMD_GETSYNCSTATE                    (MIO_CMD_GSP_BASE + 7)   /**< Returns the synchronization state. */
#define MIO_CMD_SETQULIMIT                      (MIO_CMD_GSP_BASE + 8)   /**< Sets the QU-limit (limit value for the reactive power direction under voltage) */
#define MIO_CMD_GETQULIMIT                      (MIO_CMD_GSP_BASE + 9)   /**< Reads the QU-limit (limit value for the reactive power direction under voltage) */
#define MIO_CMD_OPENBREAKER                     (MIO_CMD_GSP_BASE + 10)  /**< Open breaker */
#define MIO_CMD_GETNSPPROTECTION                (MIO_CMD_GSP_BASE + 11)  /**< Reads the actual state of the NS protection (acive/deactive) */
#define MIO_CMD_SETNSPPROTECTION                (MIO_CMD_GSP_BASE + 12)  /**< Placeholder not used yet */
#define MIO_CMD_SETNSPCFG                       (MIO_CMD_GSP_BASE + 13)  /**< Set NSP configuration */
#define MIO_CMD_GETNSPCFG                       (MIO_CMD_GSP_BASE + 14)  /**< Reads the current NS configuration */
#define MIO_CMD_GETNSPSTATUS                    (MIO_CMD_GSP_BASE + 15)  /**< Returns the current status of the NS configuration */
#define MIO_CMD_GETNSPHISTORY                   (MIO_CMD_GSP_BASE + 16)  /**< Reads NSP history */
#define MIO_CMD_DELETENSPHISTORY                (MIO_CMD_GSP_BASE + 17)  /**< Delete NSP history */
#define MIO_CMD_TAKENSPHISTORYLOCK              (MIO_CMD_GSP_BASE + 18)  /**< Take lock for NSP history */
#define MIO_CMD_GIVENSPHISTORYLOCK              (MIO_CMD_GSP_BASE + 19)  /**< Gives lock for NSP history */
#define MIO_CMD_SETINHIBITCFG                   (MIO_CMD_GSP_BASE + 20)  /**< Sets the inhibit error/event mask */
#define MIO_CMD_GETINHIBITCFG                   (MIO_CMD_GSP_BASE + 21)  /**< Reads out error/event inhibit flags. */
#define MIO_CMD_SETALARMCFG                     (MIO_CMD_GSP_BASE + 22)  /**< Configures one of the 2 relay groups */
#define MIO_CMD_GETALARMCFG                     (MIO_CMD_GSP_BASE + 23)  /**< Reads the alarm configuration */
#define MIO_CMD_RESETALARM                      (MIO_CMD_GSP_BASE + 24)  /**< Resets one of the digital outputs (DO) */
#define MIO_CMD_GETHISTORYTOTAL                 (MIO_CMD_GSP_BASE + 25)  /**< Reads the history total counts */
#define MIO_CMD_GETNSPHISTORYTOTAL              (MIO_CMD_GSP_BASE + 26)  /**< Reads the NSP history total counts */
#define MIO_CMD_GETCONFIG_EXT                   (MIO_CMD_GSP_BASE + 27)  /**< Reads the module extended configuration (requires package version >= 1.04R) */
#define MIO_CMD_GETSYNCCFG_EXT                  (MIO_CMD_GSP_BASE + 28)  /**< Reads the extend configuration of one of the two synchronization units (requires package version >= 1.04R) */
#define MIO_CMD_SETSYNCCFG_EXT                  (MIO_CMD_GSP_BASE + 29)  /**< Configures one of the two synchronization units with extended coniguration data (requires package version >= 1.04R) */
#define MIO_CMD_SETSYNCINHIBITCFG               (MIO_CMD_GSP_BASE + 30)  /**< Sets the synchronization inhibit error/event mask (requires package version >= 1.04R) */
#define MIO_CMD_GETSYNCINHIBITCFG               (MIO_CMD_GSP_BASE + 31)  /**< Reads out synchronization error/event inhibit flags (requires package version >= 1.04R) */
#define MIO_CMD_GSP274_DELETEALARMHISTORY       MIO_CMD_DELETEALARMHISTORY   /**< Deletes the alarm history entries */
#define MIO_CMD_GSP274_DELETENSPHISTORY         MIO_CMD_DELETENSPHISTORY     /**< Deletes NSP history */
#define MIO_CMD_GSP274_GETALARMHISTORY          MIO_CMD_GETALARMHISTORY  /**< Reads the alarm history */
#define MIO_CMD_GSP274_GETNSPCFG                MIO_CMD_GETNSPCFG    /**< Reads the current NS configuration */
#define MIO_CMD_GSP274_GETNSPHISTORY            MIO_CMD_GETNSPHISTORY    /**< Reads NSP history */
#define MIO_CMD_GSP274_GETNSPPROTECTION         MIO_CMD_GETNSPPROTECTION     /**< Reads the actual state of the NS protection (acive/deactive) */
#define MIO_CMD_GSP274_GETNSPSTATUS             MIO_CMD_GETNSPSTATUS     /**< Returns the current status of the NS configuration */
#define MIO_CMD_GSP274_GIVEHISTORYLOCK          MIO_CMD_GIVEHISTORYLOCK  /**< Gives the previously taken history lock */
#define MIO_CMD_GSP274_GIVENSPHISTORYLOCK       MIO_CMD_GIVENSPHISTORYLOCK   /**< Gives lock for NSP history */
#define MIO_CMD_GSP274_SETNSPCFG                MIO_CMD_SETNSPCFG    /**< Set NSP configuration */
#define MIO_CMD_GSP274_TAKEHISTORYLOCK          MIO_CMD_TAKEHISTORYLOCK  /**< Takes the lock for the history */
#define MIO_CMD_GSP274_TAKENSPHISTORYLOCK       MIO_CMD_TAKENSPHISTORYLOCK   /**< Take lock for NSP history */
#define MIO_CMD_GSP274_GETHISTORYTOTAL          MIO_CMD_GETHISTORYTOTAL  /**< Reads the history total counts (requires package version >= 1.04R) */
#define MIO_CMD_GSP274_GETNSPHISTORYTOTAL       MIO_CMD_GETNSPHISTORYTOTAL   /**< Reads the NSP history total counts (requires package version >= 1.04R) */
#define MIO_CMD_GSP274_GETASYMLIMIT             MIO_CMD_GETASYMLIMIT     /**< Reads the generation conditions of a voltage/current asymmetry error interrupt */
#define MIO_CMD_GSP274_GETFREQUENCYWINDOW       MIO_CMD_GETFREQUENCYWINDOW   /**< Reads the frequency window range */
#define MIO_CMD_GSP274_GETFRT                   MIO_CMD_GETFRT   /**< Returns the FRT table values (Fault Ride Through). */
#define MIO_CMD_GSP274_GETHARMONICSLIMIT        MIO_CMD_GETHARMONICSLIMIT    /**< Reads the configuration of the event interrupt for the factor between the harmonics. */
#define MIO_CMD_GSP274_GETINHIBITCFG            MIO_CMD_GETINHIBITCFG    /**< Reads out error/event inhibit flags. */
#define MIO_CMD_GSP274_GETLIMITCFG              MIO_CMD_GETLIMITCFG  /**< Reads the generation conditions for event or error interrupts at overvoltage or undervoltage. */
#define MIO_CMD_GSP274_GETQULIMIT               MIO_CMD_GETQULIMIT   /**< Reads the QU-limit (limit value for the reactive power direction under voltage) */
#define MIO_CMD_GSP274_GETROCOFLIMIT            MIO_CMD_GETROCOFLIMIT    /**< Reads the generation conditions of ROCOF error interrupt */
#define MIO_CMD_GSP274_GETVECTORJMPLIMIT        MIO_CMD_GETVECTORJMPLIMIT    /**< Reads the generation conditions at vector jump error interrupts. */
#define MIO_CMD_GSP274_SETASYMLIMIT             MIO_CMD_SETASYMLIMIT     /**< Specifies the generation conditions of a voltage/current asymmetry error interrupt. */
#define MIO_CMD_GSP274_SETFREQUENCYWINDOW       MIO_CMD_SETFREQUENCYWINDOW   /**< Sets the frequency window */
#define MIO_CMD_GSP274_SETFRT                   MIO_CMD_SETFRT   /**< Sets the FRT table values (Fault Ride Through) of the voltage inputs. */
#define MIO_CMD_GSP274_SETHARMONICSLIMIT        MIO_CMD_SETHARMONICSLIMIT    /**< Configures the event interrupt for the factor between the harmonics. */
#define MIO_CMD_GSP274_SETINHIBITCFG            MIO_CMD_SETINHIBITCFG    /**< Sets the inhibit event/error mask */
#define MIO_CMD_GSP274_SETLIMITCFG              MIO_CMD_SETLIMITCFG  /**< Specifies the generation conditions for event or error interrupts at over voltage or under voltage. */
#define MIO_CMD_GSP274_SETQULIMIT               MIO_CMD_SETQULIMIT   /**< Sets the QU-limit (limit value for the reactive power direction under voltage) */
#define MIO_CMD_GSP274_SETROCOFLIMIT            MIO_CMD_SETROCOFLIMIT    /**< Specifies the generation conditions of an ROCOF error interrupt */
#define MIO_CMD_GSP274_SETVECTORJMPLIMIT        MIO_CMD_SETVECTORJMPLIMIT    /**< Specifies the generation conditions at vector jump error interrupts. */
#define MIO_CMD_GSP274_SETSYNCINHIBITCFG        MIO_CMD_SETSYNCINHIBITCFG    /**< Sets the synchronization inhibit error/event mask (requires package version >= 1.04R) */
#define MIO_CMD_GSP274_GETSYNCINHIBITCFG        MIO_CMD_GETSYNCINHIBITCFG    /**< Reads out synchronization error/event inhibit flags (requires package version >= 1.04R) */
#define MIO_CMD_GSP274_EXPORTSCOPE              MIO_CMD_EXPORTSCOPE  /**< Exports the scope data */
#define MIO_CMD_GSP274_EXPORTSCOPEINTASK        MIO_CMD_EXPORTSCOPEINTASK    /**< Exports the scope data in a task */
#define MIO_CMD_GSP274_GETSCOPE                 MIO_CMD_GETSCOPE     /**< Reads the scope data */
#define MIO_CMD_GSP274_GETSCOPECFG              MIO_CMD_GETSCOPECFG  /**< Returns the Scope configuration created via MIO_CMD_SETSCOPECFG. */
#define MIO_CMD_GSP274_GETSCOPESTATE            MIO_CMD_GETSCOPESTATE    /**< Returns the state of the Scope status machine. */
#define MIO_CMD_GSP274_GIVESCOPELOCK            MIO_CMD_GIVESCOPELOCK    /**< Gives the previously taken scope lock */
#define MIO_CMD_GSP274_SETSCOPECFG              MIO_CMD_SETSCOPECFG  /**< Sets the scope configuration */
#define MIO_CMD_GSP274_TAKESCOPELOCK            MIO_CMD_TAKESCOPELOCK    /**< Takes the scope lock */
#define MIO_CMD_GSP274_TRIGGERSCOPE             MIO_CMD_TRIGGERSCOPE     /**< Triggers the scope (manually) */
#define MIO_CMD_GSP274_GETEVENT                 MIO_CMD_GETEVENT     /**< Returns the event status of the module. */
#define MIO_CMD_GSP274_GETHARMONICS             MIO_CMD_GETHARMONICS     /**< Reads the harmonic values */
#define MIO_CMD_GSP274_GETIECVALUES             MIO_CMD_GETIECVALUES     /**< Reads the IEC measured values. */
#define MIO_CMD_GSP274_GETPHASEANGLES           MIO_CMD_GETPHASEANGLES   /**< Reads the phase angle values */
#define MIO_CMD_GSP274_GETSELECTEDVALUES        MIO_CMD_GETSELECTEDVALUES    /**< Reads the selected values */
#define MIO_CMD_GSP274_GETVALUES                MIO_CMD_GETVALUES    /**< Read all the values in GSP_VALUES structure */
#define MIO_CMD_GSP274_GETVECTORDIAGRAM         MIO_CMD_GETVECTORDIAGRAM     /**< Returns the data necessary to present the vector diagram. */
#define MIO_CMD_GSP274_GETSYNCCFG               MIO_CMD_GETSYNCCFG   /**< Reads the configuration of one of the two synchronization units. */
#define MIO_CMD_GSP274_GETSYNCSTATE             MIO_CMD_GETSYNCSTATE     /**< Returns the synchronization state. */
#define MIO_CMD_GSP274_SETSYNCCFG               MIO_CMD_SETSYNCCFG   /**< Configures one of the two synchronization units. */
#define MIO_CMD_GSP274_SYNC                     MIO_CMD_SYNC     /**< Start/stop synchronization */
#define MIO_CMD_GSP274_GETSYNCCFG_EXT           MIO_CMD_GETSYNCCFG_EXT   /**< Reads the extend configuration of one of the two synchronization units (requires package version >= 1.04R) */
#define MIO_CMD_GSP274_SETSYNCCFG_EXT           MIO_CMD_SETSYNCCFG_EXT   /**< Configures one of the two synchronization units with extended coniguration data (requires package version >= 1.04R) */
#define MIO_CMD_GSP274_DISPSTATISTICS           MIO_CMD_DISPSTATISTICS   /**< Reads statistic information with some extra information */
#define MIO_CMD_GSP274_GETNBSTATISTICS          MIO_CMD_GETNBSTATISTICS  /**< Returns the number of available statistics values. */
#define MIO_CMD_GSP274_GETSTATISTICS            MIO_CMD_GETSTATISTICS    /**< Reads statistic values */
#define MIO_CMD_GSP274_RESETSTATISTICS          MIO_CMD_RESETSTATISTICS  /**< Resets statistic values */
#define MIO_CMD_GSP274_GETENERGY                MIO_CMD_GETENERGY    /**< Reads the energy values in UINT64 format */
#define MIO_CMD_GSP274_GETENERGYREAL            MIO_CMD_GETENERGYREAL    /**< Reads the energy values in REAL64 format */
#define MIO_CMD_GSP274_SETENERGY                MIO_CMD_SETENERGY    /**< Sets the energy to a given value in UINT64 format */
#define MIO_CMD_GSP274_SETENERGYREAL            MIO_CMD_SETENERGYREAL    /**< Sets energy to a given value in REAL64 format */
#define MIO_CMD_GSP274_GETCONFIG                MIO_CMD_GETCONFIG    /**< Reads the module configuration */
#define MIO_CMD_GSP274_GETPREINITERROR          MIO_CMD_GETPREINITERROR  /**< Reads the pre initialization error */
#define MIO_CMD_GSP274_GETPREINITEVENT          MIO_CMD_GETPREINITEVENT  /**< Reads the pre initialization event */
#define MIO_CMD_GSP274_PROCESSINIFILE           MIO_CMD_PROCESSINIFILE   /**< Processes the parameter file (only used internally) */
#define MIO_CMD_GSP274_GETRUNTHROUGH            MIO_CMD_GETRUNTHROUGH    /**< Reads the current run through mode setting */
#define MIO_CMD_GSP274_GETSTATE                 MIO_CMD_GETSTATE     /**< Returns the state of the state machine. */
#define MIO_CMD_GSP274_SETSTATE                 MIO_CMD_SETSTATE     /**< Sets the state of the state machine. */
#define MIO_CMD_GSP274_GETCONFIG_EXT            MIO_CMD_GETCONFIG_EXT    /**< Reads the module extended configuration (requires package version >= 1.04R) */
#define MIO_CMD_GSP274_FORCERELAY               MIO_CMD_FORCERELAY   /**< Forces the relay into the given state */
#define MIO_CMD_GSP274_GETALARMCFG              MIO_CMD_GETALARMCFG  /**< Reads the configuration of a relay group. */
#define MIO_CMD_GSP274_GETDICFG                 MIO_CMD_GETDICFG     /**< Reads the configuration of a DIChannel group */
#define MIO_CMD_GSP274_GETSIMDATA               MIO_CMD_GETSIMDATA   /**< Returns the configured simulation data */
#define MIO_CMD_GSP274_GETSWITCHCOUNT           MIO_CMD_GETSWITCHCOUNT   /**< Returns the number of switch cycles of the relay channels */
#define MIO_CMD_GSP274_RESETALARM               MIO_CMD_RESETALARM   /**< Resets one of the digital outputs (DO). */
#define MIO_CMD_GSP274_SETALARMCFG              MIO_CMD_SETALARMCFG  /**< Configures one of the 2 relay groups */
#define MIO_CMD_GSP274_SETDICFG                 MIO_CMD_SETDICFG     /**< Configures one of the 2 DIChannel groups */
#define MIO_CMD_GSP274_SETSIMDATA               MIO_CMD_SETSIMDATA   /**< Sets the simulated data */
#define MIO_CMD_GSP274_VRW_SETVALUES            8005     /**< Set all values in GSP_VALUES structure in virtualRW mode (#MIO_CMD_GSP274_VRW_SETVALUES = #MIO_CMD_VRW_SETVALUES) */
#define MIO_CMD_GSP274_VRW_SETSELECTEDVALUES    8006     /**< Set desired values in GSP_VALUES structure in virtualRW mode (#MIO_CMD_GSP274_VRW_SETSELECTEDVALUES = #MIO_CMD_VRW_SETSELECTEDVALUES) */
/** @} */

/**
 * @name Possible commands for the IO modules GIO2XX and AIO2XX
 * @{
 */

#define MIO_CMD_GIOBASE                 7800
#define MIO_CMD_GIOSETDOPULSE           (MIO_CMD_GIOBASE + 1)    /**< Set the digital output pulse times */
#define MIO_CMD_GIOGETDOPULSE           (MIO_CMD_GIOBASE + 2)    /**< Read the digital output pulse times */
#define MIO_CMD_GIOSETAIFILTER          (MIO_CMD_GIOBASE + 3)    /**< Set the analog input filter frequency */
#define MIO_CMD_GIOGETAIFILTER          (MIO_CMD_GIOBASE + 4)    /**< Read the analog input filter frequency */
#define MIO_CMD_GIOSETSPIKEFILTER       (MIO_CMD_GIOBASE + 5)    /**< Set the spike filter value */
#define MIO_CMD_GIOGETSPIKEFILTER       (MIO_CMD_GIOBASE + 6)    /**< Read the spike filter value */
#define MIO_CMD_GIOSETLIMITS            (MIO_CMD_GIOBASE + 7)    /**< Set analog input limits */
#define MIO_CMD_GIOGETLIMITS            (MIO_CMD_GIOBASE + 8)    /**< Read analog input limits */
#define MIO_CMD_GIOGETCHIPTEMP          (MIO_CMD_GIOBASE + 9)    /**< Read chip temperature */
#define MIO_CMD_GIOSETCOLDJUNCTEMP      (MIO_CMD_GIOBASE + 10)   /**< Set cold junction temperature */
#define MIO_CMD_GIOGETCOLDJUNCTEMP      (MIO_CMD_GIOBASE + 11)   /**< Read last set cold junction temperature */
#define MIO_CMD_GIOSETPWMRUNMODE        (MIO_CMD_GIOBASE + 12)   /**< Set the PWM run mode */
#define MIO_CMD_GIOGETPWMRUNMODE        (MIO_CMD_GIOBASE + 13)   /**< Read the PWM run mode */
#define MIO_CMD_GIOSETFILTERHB          (MIO_CMD_GIOBASE + 14)   /**< Activate or deactivate halfband filter */
#define MIO_CMD_GIOGETFILTERHB          (MIO_CMD_GIOBASE + 15)   /**< Get halfband filter setting */
#define MIO_CMD_GIOSETFILTERITP         (MIO_CMD_GIOBASE + 16)   /**< Activate or deactivate filter interpolation */
#define MIO_CMD_GIOGETFILTERITP         (MIO_CMD_GIOBASE + 17)   /**< Get filter interpolation setting */
#define MIO_CMD_GIOSETGROUNDED          (MIO_CMD_GIOBASE + 18)   /**< Activate or deactivate grounded measurement */
#define MIO_CMD_GIOGETGROUNDED          (MIO_CMD_GIOBASE + 19)   /**< Get activated or deactivated grounded measurement */
#define MIO_CMD_GIOGETNBRFIFOENTRIES    (MIO_CMD_GIOBASE + 20)   /**< Get number of FIFO entries in counter and frequency modulation mode */
#define MIO_CMD_GIOGETFIFOVALUES        (MIO_CMD_GIOBASE + 21)   /**< Get stored counter values from the FIFO in counter mode */
#define MIO_CMD_GIOGETFIFOOVERFLOW      (MIO_CMD_GIOBASE + 22)   /**< Get number of overflows in the counter FIFO in counter mode */
#define MIO_CMD_GIOFIFOFLUSH            (MIO_CMD_GIOBASE + 23)   /**< Flushes the FIFO in counter and frequency modulation mode */
#define MIO_CMD_GIOFIFOREFVALUE         (MIO_CMD_GIOBASE + 24)   /**< Get the reference value when FIFO started in counter mode */
#define MIO_CMD_GIOSTARTSTOPFIFO        (MIO_CMD_GIOBASE + 25)   /**< Starts/stops the FIFO in frequency modulation mode */
#define MIO_CMD_GIOSETPULSECOUNT        (MIO_CMD_GIOBASE + 26)   /**< Sets the pulse counter in frequency modulation mode */
#define MIO_CMD_GIOGETPULSECOUNT        (MIO_CMD_GIOBASE + 27)   /**< Gets the pulse counter in frequency modulation mode */
#define MIO_CMD_GIOSETPERIOD            (MIO_CMD_GIOBASE + 28)   /**< Sets the period in ns in pulse modulation mode */
#define MIO_CMD_GIOGETPERIOD            (MIO_CMD_GIOBASE + 29)   /**< Gets the period in ns in pulse modulation mode */
#define MIO_CMD_GIOADDFIFOENTRY         (MIO_CMD_GIOBASE + 30)   /**< Add a single FIFO entry in FIFO mode */
#define MIO_CMD_GIOSETPTCURRENT         (MIO_CMD_GIOBASE + 31)   /**< Set PT current */
#define MIO_CMD_GIOGETPTCURRENT         (MIO_CMD_GIOBASE + 32)   /**< Get PT current */
#define MIO_CMD_GIOSTARTSTOPFIFOEXT     (MIO_CMD_GIOBASE + 33)   /**< Starts/stops various channels using the FIFO for measurements */
#define MIO_CMD_GIOCFGCYCLICACTIONS     (MIO_CMD_GIOBASE + 88)   /**< For internal use only: Activate / deactivate automatic configuration */
#define MIO_CMD_GIODEACVALIDATION       (MIO_CMD_GIOBASE + 89)   /**< For internal use only: Deactivates the config validation */
#define MIO_CMD_GIOREADCOLDJUNCTEMP     (MIO_CMD_GIOBASE + 90)   /**< For internal use only: Read cold junction temperature from module sensors */
#define MIO_CMD_GIOWRITEASICDATA        (MIO_CMD_GIOBASE + 91)   /**< For internal use only: Write data to the ASIC */
#define MIO_CMD_GIOREADASICDATA         (MIO_CMD_GIOBASE + 92)   /**< For internal use only: Read data from the ASIC */
#define MIO_CMD_GIOWRITEI2CDATA         (MIO_CMD_GIOBASE + 93)   /**< For internal use only: Write data to a I2C device */
#define MIO_CMD_GIOREADI2CDATA          (MIO_CMD_GIOBASE + 94)   /**< For internal use only: Read data from a I2C device */
#define MIO_CMD_GIOCYCLICACTION         (MIO_CMD_GIOBASE + 95)   /**< For internal use only: Perform cyclic actions */
#define MIO_CMD_GIOWRITEEEPROM          (MIO_CMD_GIOBASE + 96)   /**< For internal use only: Write data to the EEPROM */
#define MIO_CMD_GIOREADEEPROM           (MIO_CMD_GIOBASE + 97)   /**< For internal use only: Read data from the EEPROM */
#define MIO_CMD_GIOSETSPISPEED          (MIO_CMD_GIOBASE + 98)   /**< For internal use only: Set the clockrate of the SPI bus */
#define MIO_CMD_GIOSETALLOCID           (MIO_CMD_GIOBASE + 99)   /**< For internal use only: Sets the internal alloc id */
/** @} */

/**
 * @name Possible commands for the IO module STMI3XX
 * @{
 */

#define MIO_CMD_STMI_BASE       7900
#define MIO_CMD_SETTRIGGERMODE  (MIO_CMD_STMI_BASE + 1)
#define MIO_CMD_GETDATAPACKET   (MIO_CMD_STMI_BASE + 2)
/** @} */

/**
 * @name Possible commands for the IO module GM2XX and GM260
 * @{
 */

#define MIO_CMD_GM2XX_BASE                      8000
#define MIO_CMD_RUNENERGYMEAS                   (MIO_CMD_GM2XX_BASE + 1)     /**< Enable/disable the energy measurement */
#define MIO_CMD_ISENERGYMEAS                    (MIO_CMD_GM2XX_BASE + 2)     /**< Get Info whether the energy measurement is active */
#define MIO_CMD_SETENERGY_MP                    (MIO_CMD_GM2XX_BASE + 3)     /**< Set only one measuring point */
#define MIO_CMD_SETENERGYREAL_MP                (MIO_CMD_GM2XX_BASE + 4)     /**< Set only one measuring point, REAL version */
#define MIO_CMD_VRW_SETVALUES                   (MIO_CMD_GM2XX_BASE + 5)     /**< Set all values in virtualRW mode */
#define MIO_CMD_VRW_SETSELECTEDVALUES           (MIO_CMD_GM2XX_BASE + 6)     /**< Set desired values in virtualRW mode */
#define MIO_CMD_GETVALUES2                      (MIO_CMD_GM2XX_BASE + 7)     /**< Read all the values in GM260_VALUES2 structure */
#define MIO_CMD_GETSELECTEDVALUES2              (MIO_CMD_GM2XX_BASE + 8)     /**< Read the selected values in GM260_VALUES2 structure */
#define MIO_CMD_VRW_SETVALUES2                  (MIO_CMD_GM2XX_BASE + 9)     /**< Set all values in GM260_VALUES2 structure in virtualRW mode */
#define MIO_CMD_VRW_SETSELECTEDVALUES2          (MIO_CMD_GM2XX_BASE + 10)    /**< Set desired values in GM260_VALUES2 structure in virtualRW mode */
#define MIO_CMD_GM260_GETVALUES                 MIO_CMD_GETVALUES    /**< Read all the values in GM260_VALUES structure */
#define MIO_CMD_GM260_GETSELECTEDVALUES         MIO_CMD_GETSELECTEDVALUES    /**< Read the selected values in GM260_VALUES structure */
#define MIO_CMD_GM260_GETVALUES2                MIO_CMD_GETVALUES2   /**< Read all the values in GM260_VALUES2 structure */
#define MIO_CMD_GM260_GETSELECTEDVALUES2        MIO_CMD_GETSELECTEDVALUES2   /**< Read the selected values in GM260_VALUES2 structure */
#define MIO_CMD_GM260_VRW_SETVALUES             MIO_CMD_VRW_SETVALUES    /**< Set all values in GM260_VALUES structure in virtualRW mode */
#define MIO_CMD_GM260_VRW_SETSELECTEDVALUES     MIO_CMD_VRW_SETSELECTEDVALUES    /**< Set desired values in GM260_VALUES structure in virtualRW mode */
#define MIO_CMD_GM260_VRW_SETVALUES2            MIO_CMD_VRW_SETVALUES2   /**< Set all values in GM260_VALUES2 structure in virtualRW mode */
#define MIO_CMD_GM260_VRW_SETSELECTEDVALUES2    MIO_CMD_VRW_SETSELECTEDVALUES2   /**< Set desired values in GM260_VALUES2 structure in virtualRW mode */
#define MIO_CMD_GM260_SETENERGY                 MIO_CMD_SETENERGY    /**< Set energy on both measuring points */
#define MIO_CMD_GM260_SETENERGY_MP              MIO_CMD_SETENERGY_MP     /**< Set energy on only one measuring point */
#define MIO_CMD_GM260_GETENERGY                 MIO_CMD_GETENERGY    /**< Read energy on both measuring points */
#define MIO_CMD_GM260_SETENERGYREAL             MIO_CMD_SETENERGYREAL    /**< Set energy on both measuring points, REAL version */
#define MIO_CMD_GM260_SETENERGYREAL_MP          MIO_CMD_SETENERGYREAL_MP     /**< Set energy on only one measuring point, REAL version */
#define MIO_CMD_GM260_GETENERGYREAL             MIO_CMD_GETENERGYREAL    /**< Read energy on both measuring points, REAL version */
#define MIO_CMD_GM260_RUNENERGYMEAS             MIO_CMD_RUNENERGYMEAS    /**< Enable/disable the energy measurement */
#define MIO_CMD_GM260_ISENERGYMEAS              MIO_CMD_ISENERGYMEAS     /**< Get Info whether the energy measurement is active */
#define MIO_CMD_GM260_GETCONFIG                 MIO_CMD_GETCONFIG    /**< Reads the module configuration */
#define MIO_CMD_GM260_GETVERSION                MIO_CMD_GETVERSION   /**< Get driver and firmware version */
#define MIO_CMD_GM260_ALIVECHECK                MIO_CMD_ALIVECHECK   /**< Do alive check on IO-module */
#define MIO_CMD_GM260_BUSCHECK                  MIO_CMD_BUSCHECK     /**< Do hardware check on IO-bus */
#define MIO_CMD_GM260_GETERRSTATIST             MIO_CMD_GETERRSTATIST    /**< Get module error statistics */
#define MIO_CMD_GM260_NEWCONFIG                 MIO_CMD_NEWCONFIG    /**< New configuration for IO-module */
#define MIO_CMD_GM260_INTSYSRUNNING             MIO_CMD_INTSYSRUNNING    /**< Interrupt-System is now running */
#define MIO_CMD_GM260_GETPROGRESS               MIO_CMD_GETPROGRESS  /**< Query progress */
#define MIO_CMD_GM260_UPDATESW_M86              MIO_CMD_UPDATESW_M86     /**< Update m86 file on module */
#define MIO_CMD_GM260_PICONFIGURE               MIO_CMD_PICONFIGURE  /**< Process image: Configure the process image */
#define MIO_CMD_GM260_PIINIT                    MIO_CMD_PIINIT   /**< Process image: Initialize process image of driver */
#define MIO_CMD_GM260_PIDEINIT                  MIO_CMD_PIDEINIT     /**< Process image: Free resources used by the process image */
#define MIO_CMD_GM260_PIGETCONFIGURE            MIO_CMD_PIGETCONFIGURE   /**< Process image: Check if a channel is configured */
#define MIO_CMD_GM2XX_GETVALUES                 MIO_CMD_GETVALUES    /**< Read all the values in GM2XX_VALUES structure */
#define MIO_CMD_GM2XX_GETSELECTEDVALUES         MIO_CMD_GETSELECTEDVALUES    /**< Read the selected values in GM2XX_VALUES structure */
#define MIO_CMD_GM2XX_VRW_SETVALUES             MIO_CMD_VRW_SETVALUES    /**< Set all values in GM2XX_VALUES structure in virtualRW mode */
#define MIO_CMD_GM2XX_VRW_SETSELECTEDVALUES     MIO_CMD_VRW_SETSELECTEDVALUES    /**< Set desired values in GM2XX_VALUES structure in virtualRW mode */
#define MIO_CMD_GM2XX_SETENERGY                 MIO_CMD_SETENERGY    /**< Set energy on both measuring points */
#define MIO_CMD_GM2XX_GETENERGY                 MIO_CMD_GETENERGY    /**< Read energy on both measuring points */
#define MIO_CMD_GM2XX_SETENERGYREAL             MIO_CMD_SETENERGYREAL    /**< Set energy on both measuring points, REAL version */
#define MIO_CMD_GM2XX_GETENERGYREAL             MIO_CMD_GETENERGYREAL    /**< Read energy on both measuring points, REAL version */
#define MIO_CMD_GM2XX_RUNENERGYMEAS             MIO_CMD_RUNENERGYMEAS    /**< Enable/disable the energy measurement */
#define MIO_CMD_GM2XX_ISENERGYMEAS              MIO_CMD_ISENERGYMEAS     /**< Get Info whether the energy measurement is active */
#define MIO_CMD_GM2XX_GETCONFIG                 MIO_CMD_GETCONFIG    /**< Reads the module configuration */
/** @} */

/**
 * @name Possible commands for the IO module GMP232X
 * @{
 */

#define MIO_CMD_GMP232XBASE                     8100
#define MIO_CMD_GMP232X_SYNCTIME                (MIO_CMD_GMP232XBASE + 1)    /**< Synchronize the internal clock (only used internally) */
#define MIO_CMD_GMP232X_GETMODULETIME           (MIO_CMD_GMP232XBASE + 2)    /**< Reads the current module time */
#define MIO_CMD_GMP232X_SETMODULETIME           (MIO_CMD_GMP232XBASE + 3)    /**< Overwrites the current module time with a given value (only used internally) */
#define MIO_CMD_GMP232X_PROCESSPARAMFILE        (MIO_CMD_GMP232XBASE + 4)    /**< Processes the parameter file (only used internally) */
#define MIO_CMD_GMP232X_GETRUNTHROUGH           (MIO_CMD_GMP232XBASE + 5)    /**< Reads the current run through mode setting */
#define MIO_CMD_GMP232X_GETEVENT                (MIO_CMD_GMP232XBASE + 8)    /**< Reads the events status */
#define MIO_CMD_GMP232X_SETLIMIT_FREQ           (MIO_CMD_GMP232XBASE + 9)    /**< Set frequency limit */
#define MIO_CMD_GMP232X_GETLIMIT_FREQ           (MIO_CMD_GMP232XBASE + 10)   /**< Reads frequency limit */
#define MIO_CMD_GMP232X_SETLIMIT_VFRT           (MIO_CMD_GMP232XBASE + 11)   /**< Sets the voltage FRT limit */
#define MIO_CMD_GMP232X_GETLIMIT_VFRT           (MIO_CMD_GMP232XBASE + 12)   /**< Reads the voltage FRT limit */
#define MIO_CMD_GMP232X_SETLIMIT_FFRT           (MIO_CMD_GMP232XBASE + 13)   /**< Sets the frequency FRT limit */
#define MIO_CMD_GMP232X_GETLIMIT_FFRT           (MIO_CMD_GMP232XBASE + 14)   /**< Reads the frequency FRT limit */
#define MIO_CMD_GMP232X_SETLIMIT_VOLTAGE        (MIO_CMD_GMP232XBASE + 15)   /**< Sets the voltage limit */
#define MIO_CMD_GMP232X_GETLIMIT_VOLTAGE        (MIO_CMD_GMP232XBASE + 16)   /**< Reads the configured voltage limit */
#define MIO_CMD_GMP232X_SETLIMIT_QU             (MIO_CMD_GMP232XBASE + 17)   /**< Sets the QU limit to the given configuration */
#define MIO_CMD_GMP232X_GETLIMIT_QU             (MIO_CMD_GMP232XBASE + 18)   /**< Reads the QU limit values */
#define MIO_CMD_GMP232X_SETLIMIT_VECTORJUMP     (MIO_CMD_GMP232XBASE + 19)   /**< Sets the vector jump limit */
#define MIO_CMD_GMP232X_GETLIMIT_VECTORJUMP     (MIO_CMD_GMP232XBASE + 20)   /**< Reads the vector jump limit */
#define MIO_CMD_GMP232X_SETLIMIT_HARMONICS      (MIO_CMD_GMP232XBASE + 21)   /**< Sets the harmonic limit */
#define MIO_CMD_GMP232X_GETLIMIT_HARMONICS      (MIO_CMD_GMP232XBASE + 22)   /**< Reads the harmonic limit */
#define MIO_CMD_GMP232X_SETLIMIT_I              (MIO_CMD_GMP232XBASE + 23)   /**< Sets the current limit */
#define MIO_CMD_GMP232X_SETLIMIT_THDTDD         (MIO_CMD_GMP232XBASE + 24)   /**< Sets the THD TDD limit */
#define MIO_CMD_GMP232X_SETLIMIT_ASYM           (MIO_CMD_GMP232XBASE + 25)   /**< Sets the asymmetry limit */
#define MIO_CMD_GMP232X_SETLIMIT_ROCOF          (MIO_CMD_GMP232XBASE + 26)   /**< Sets the ROCOF limit */
#define MIO_CMD_GMP232X_SETLIMIT_MAX_POWER      (MIO_CMD_GMP232XBASE + 27)   /**< Sets the maximal power limit */
#define MIO_CMD_GMP232X_SETLIMIT_REVERSE_POWER  (MIO_CMD_GMP232XBASE + 28)   /**< Sets the reverse power limit */
#define MIO_CMD_GMP232X_SETLIMIT_DIR_CURRENT    (MIO_CMD_GMP232XBASE + 29)   /**< Sets the directional overcurrent limit */
#define MIO_CMD_GMP232X_GETLIMIT_I              (MIO_CMD_GMP232XBASE + 30)   /**< Reads the current limit */
#define MIO_CMD_GMP232X_GETLIMIT_THDTDD         (MIO_CMD_GMP232XBASE + 31)   /**< Reads the THD TDD limit */
#define MIO_CMD_GMP232X_GETLIMIT_ASYM           (MIO_CMD_GMP232XBASE + 32)   /**< Reads the asymmetry limit */
#define MIO_CMD_GMP232X_GETLIMIT_ROCOF          (MIO_CMD_GMP232XBASE + 33)   /**< Reads the ROCOF limit */
#define MIO_CMD_GMP232X_GETLIMIT_MAX_POWER      (MIO_CMD_GMP232XBASE + 34)   /**< Reads the maximal power limit */
#define MIO_CMD_GMP232X_GETLIMIT_REVERSE_POWER  (MIO_CMD_GMP232XBASE + 35)   /**< Reads the reverse power limit */
#define MIO_CMD_GMP232X_GETLIMIT_DIR_CURRENT    (MIO_CMD_GMP232XBASE + 36)   /**< Reads the directional current limit */
#define MIO_CMD_GMP232X_GETLIMIT_SINGLE_STATUS  (MIO_CMD_GMP232XBASE + 37)   /**< Reads the status of a single limit */
#define MIO_CMD_GMP232X_GETLIMIT_STATUS         (MIO_CMD_GMP232XBASE + 38)   /**< Reads the status of all limits */
#define MIO_CMD_GMP232X_GETMEANVALUE_RANGED     (MIO_CMD_GMP232XBASE + 40)   /**< Reads mean values between a certain range (or a single one) */
#define MIO_CMD_GMP232X_GETMEANVALUE_INDEXED    (MIO_CMD_GMP232XBASE + 41)   /**< Read certain mean values (or a single one) */
#define MIO_CMD_GMP232X_GET_FRMS_FCS            (MIO_CMD_GMP232XBASE + 42)   /**< Reads FRMS FCS values */
#define MIO_CMD_GMP232X_GET_TRMS_HCS            (MIO_CMD_GMP232XBASE + 43)   /**< Reads TRMS HCS values */
#define MIO_CMD_GMP232X_GET_FRMS_FCC            (MIO_CMD_GMP232XBASE + 44)   /**< Reads FRMS FCC values */
#define MIO_CMD_GMP232X_GET_TRMS_HCC            (MIO_CMD_GMP232XBASE + 45)   /**< Reads TRMS HCC values */
#define MIO_CMD_GMP232X_GETPOWERS_FRMS_FCS      (MIO_CMD_GMP232XBASE + 46)   /**< Reads the FRMS FCS power values */
#define MIO_CMD_GMP232X_GETPOWERS_FRMS_FCC      (MIO_CMD_GMP232XBASE + 47)   /**< Reads the FRMS FCC power values */
#define MIO_CMD_GMP232X_GETPOWERS_TRMS_HCS      (MIO_CMD_GMP232XBASE + 48)   /**< Reads the TRMS HCS power values */
#define MIO_CMD_GMP232X_GETPOWERS_TRMS_HCC      (MIO_CMD_GMP232XBASE + 49)   /**< Reads the TRMS HCC power values */
#define MIO_CMD_GMP232X_GETPHASE_REF            (MIO_CMD_GMP232XBASE + 50)   /**< Reads the phase angle reference values */
#define MIO_CMD_GMP232X_GETPHASE                (MIO_CMD_GMP232XBASE + 51)   /**< Reads the phase angle values */
#define MIO_CMD_GMP232X_GETROCOF_ROTDIR         (MIO_CMD_GMP232XBASE + 52)   /**< Reads ROCOF rotation direction values */
#define MIO_CMD_GMP232X_GETPOWERFACTOR          (MIO_CMD_GMP232XBASE + 53)   /**< Reads the powerfactor values */
#define MIO_CMD_GMP232X_GETASYM                 (MIO_CMD_GMP232XBASE + 54)   /**< Reads the asymmetric data values */
#define MIO_CMD_GMP232X_GETSYM_COMPONENTS       (MIO_CMD_GMP232XBASE + 55)   /**< Reads the symmetric components */
#define MIO_CMD_GMP232X_SETENERGY               (MIO_CMD_GMP232XBASE + 56)   /**< Sets the energy to a given value */
#define MIO_CMD_GMP232X_GETENERGY               (MIO_CMD_GMP232XBASE + 57)   /**< Reads the energy values */
#define MIO_CMD_GMP232X_SETSCOPECFG             (MIO_CMD_GMP232XBASE + 60)   /**< Sets the scope configuration */
#define MIO_CMD_GMP232X_GETSCOPECFG             (MIO_CMD_GMP232XBASE + 61)   /**< Reads the scope configuration */
#define MIO_CMD_GMP232X_TAKESCOPELOCK           (MIO_CMD_GMP232XBASE + 62)   /**< Takes the scope lock */
#define MIO_CMD_GMP232X_GIVESCOPELOCK           (MIO_CMD_GMP232XBASE + 63)   /**< Gives the previously taken scope lock */
#define MIO_CMD_GMP232X_TRIGGERSCOPE            (MIO_CMD_GMP232XBASE + 64)   /**< Triggers the scope (manually) */
#define MIO_CMD_GMP232X_EXPORTSCOPE             (MIO_CMD_GMP232XBASE + 65)   /**< Exports the scope data */
#define MIO_CMD_GMP232X_EXPORTSCOPEINTASK       (MIO_CMD_GMP232XBASE + 66)   /**< Exports the scope data in a task */
#define MIO_CMD_GMP232X_GETSCOPE                (MIO_CMD_GMP232XBASE + 67)   /**< Reads the scope data */
#define MIO_CMD_GMP232X_GETSCOPESTATE           (MIO_CMD_GMP232XBASE + 68)   /**< Reads the scope state */
#define MIO_CMD_GMP232X_GETHARMONICS            (MIO_CMD_GMP232XBASE + 69)   /**< Reads the harmonic values */
#define MIO_CMD_GMP232X_SETSTATE                (MIO_CMD_GMP232XBASE + 70)   /**< Sets the module state */
#define MIO_CMD_GMP232X_GETSTATE                (MIO_CMD_GMP232XBASE + 71)   /**< Reads the current module state */
#define MIO_CMD_GMP232X_SETSAMPLECFG            (MIO_CMD_GMP232XBASE + 72)   /**< Sets the sample value configuration */
#define MIO_CMD_GMP232X_GETSAMPLECFG            (MIO_CMD_GMP232XBASE + 73)   /**< Reads the sample value configuration */
#define MIO_CMD_GMP232X_GETSAMPLES              (MIO_CMD_GMP232XBASE + 74)   /**< Reads a given number of sample values */
#define MIO_CMD_GMP232X_GETLATESTSAMPLE         (MIO_CMD_GMP232XBASE + 75)   /**< Reads the latest written (most recent) sample value */
#define MIO_CMD_GMP232X_SETINHIBITCFG           (MIO_CMD_GMP232XBASE + 76)   /**< Sets the the inhibit configuration */
#define MIO_CMD_GMP232X_GETINHIBITCFG           (MIO_CMD_GMP232XBASE + 77)   /**< Reads the the inhibit configuration */
#define MIO_CMD_GMP232X_TAKEHISTORYLOCK         (MIO_CMD_GMP232XBASE + 78)   /**< Takes the lock for the history */
#define MIO_CMD_GMP232X_GIVEHISTORYLOCK         (MIO_CMD_GMP232XBASE + 79)   /**< Gives the previously taken history lock */
#define MIO_CMD_GMP232X_GETALARMHISTORY         (MIO_CMD_GMP232XBASE + 80)   /**< Reads the alarm history */
#define MIO_CMD_GMP232X_DELETEALARMHISTORY      (MIO_CMD_GMP232XBASE + 81)   /**< Deletes the alarm history entries */
#define MIO_CMD_GMP232X_SETCONFIG               (MIO_CMD_GMP232XBASE + 82)   /**< Sets the module configuration */
#define MIO_CMD_GMP232X_GETCONFIG               (MIO_CMD_GMP232XBASE + 83)   /**< Reads the module configuration */
#define MIO_CMD_GMP232X_GETSIMDATA              (MIO_CMD_GMP232XBASE + 84)   /**< Reads the simulated data */
#define MIO_CMD_GMP232X_SETSIMDATA              (MIO_CMD_GMP232XBASE + 85)   /**< Sets the simulation data */
#define MIO_CMD_GMP232X_RESETSTATISTICS         (MIO_CMD_GMP232XBASE + 88)   /**< Resets all statistic data values */
#define MIO_CMD_GMP232X_SETRELAYCFG             (MIO_CMD_GMP232XBASE + 90)   /**< Sets the relay configuration */
#define MIO_CMD_GMP232X_GETRELAYCFG             (MIO_CMD_GMP232XBASE + 91)   /**< Reads the relay configuration */
#define MIO_CMD_GMP232X_FORCERELAY              (MIO_CMD_GMP232XBASE + 92)   /**< Forces the relay into the given state */
#define MIO_CMD_GMP232X_RESETRELAY              (MIO_CMD_GMP232XBASE + 93)   /**< Resets the relay to default state */
#define MIO_CMD_GMP232X_GETSWITCHCOUNT          (MIO_CMD_GMP232XBASE + 94)   /**< Reads the switch count of each relay */
#define MIO_CMD_GMP232X_GETPHI_UI_S             (MIO_CMD_GMP232XBASE + 95)   /**< Optimized variant with phi values for U and I */
#define MIO_CMD_GMP232X_GETBULK_SYMCOMPONENTS   (MIO_CMD_GMP232XBASE + 96)   /**< Reads a collection of relevant values regarding relevant symmetric components */
#define MIO_CMD_GMP232X_GETBULK_FRMS_FCS        (MIO_CMD_GMP232XBASE + 97)   /**< Reads a collection of relevant FRMS FCS values */
#define MIO_CMD_GMP232X_GETBULK_FRMS_FCC        (MIO_CMD_GMP232XBASE + 98)   /**< Reads a collection of relevant FRMS FCC values */
#define MIO_CMD_GMP232X_GETBULK_TRMS_HCS        (MIO_CMD_GMP232XBASE + 99)   /**< Reads a collection of relevant TRMS HCS values */
#define MIO_CMD_GMP232X_GETBULK_THD_TDD         (MIO_CMD_GMP232XBASE + 100)  /**< Reads a collection of relevant THD and TDD values */
#define MIO_CMD_GMP232X_SETRUNTHROUGH           (MIO_CMD_GMP232XBASE + 101)  /**< Enables or disables Runthrough mode (not yet implemented) */
#define MIO_CMD_GMP232X_VRW_SETSWITCHCOUNT      (MIO_CMD_GMP232XBASE + 102)  /**< Sets the switch count to the given values (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETFRMS_FCS         (MIO_CMD_GMP232XBASE + 103)  /**< Sets the FRMS FCS values (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETFRMS_FCC         (MIO_CMD_GMP232XBASE + 104)  /**< Sets the FRMS FCC values (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETTRMS_HCS         (MIO_CMD_GMP232XBASE + 105)  /**< Sets the TRMS HCS values (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETTRMS_HCC         (MIO_CMD_GMP232XBASE + 106)  /**< Sets the TRMS HCC values (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETPHASE_REF        (MIO_CMD_GMP232XBASE + 107)  /**< Sets the phase reference values (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETPHASE            (MIO_CMD_GMP232XBASE + 108)  /**< Sets the frequency phase values (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETROCOF_ROTDIR     (MIO_CMD_GMP232XBASE + 109)  /**< Sets the ROCOF rotation direction (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETPOWERFACTOR      (MIO_CMD_GMP232XBASE + 110)  /**< Sets the powerfactor values (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETASYM             (MIO_CMD_GMP232XBASE + 111)  /**< Sets the asymmetric values (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETSYM_COMPONENTS   (MIO_CMD_GMP232XBASE + 112)  /**< Sets the symmetric components (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETPOWERS_FRMS_FCS  (MIO_CMD_GMP232XBASE + 113)  /**< Sets the FRMS FCS power values (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETPOWERS_FRMS_FCC  (MIO_CMD_GMP232XBASE + 114)  /**< Sets the FRMS FCC power values (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETPOWERS_TRMS_HCS  (MIO_CMD_GMP232XBASE + 115)  /**< Sets the TRMS HCS power values (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_VRW_SETPOWERS_TRMS_HCC  (MIO_CMD_GMP232XBASE + 116)  /**< Sets the TRMS HCC power values (only in VIRTUALRW mode) */
#define MIO_CMD_GMP232X_GETRAWFFT_100           (MIO_CMD_GMP232XBASE + 160)  /**< Reads raw FFT values up to the 99th harmonic (only used internally) */
#define MIO_CMD_GMP232X_SETCALIB                (MIO_CMD_GMP232XBASE + 161)  /**< Sets the calibration data of the module (only used internally) */
#define MIO_CMD_GMP232X_GETCALIB                (MIO_CMD_GMP232XBASE + 162)  /**< Reads the calibration data of the module (only used internally) */
#define MIO_CMD_GMP232X_SETFIRCFG               (MIO_CMD_GMP232XBASE + 163)  /**< Sets the operating mode of the FIR filter (only used internally) */
#define MIO_CMD_GMP232X_GETFIRCFG               (MIO_CMD_GMP232XBASE + 164)  /**< Reads the operating mode of the FIR filter (only used internally) */
#define MIO_CMD_GMP232X_GETPENDINGSAMPLES       (MIO_CMD_GMP232XBASE + 165)  /**< Reads all pending samples beginning from a given start index */
#define MIO_CMD_GMP232X_GETPHASE_REF_S          (MIO_CMD_GMP232XBASE + 166)  /**< Optimized variant to read the phase angle reference values */
#define MIO_CMD_GMP232X_GETHIRESTIME            (MIO_CMD_GMP232XBASE + 167)  /**< Reads the high resolution timestamp (synchronous to sample value timestamp) */
#define MIO_CMD_GMP232X_GETSTATISTIC_RANGED     (MIO_CMD_GMP232XBASE + 168)  /**< Reads statistic values between a certain range (or a single one) */
#define MIO_CMD_GMP232X_GETSTATISTIC_INDEXED    (MIO_CMD_GMP232XBASE + 169)  /**< Reads certain statistic values (or a single one) */
#define MIO_CMD_GMP232X_RESETAVERAGER           (MIO_CMD_GMP232XBASE + 170)  /**< Resets mean averagers (a single one or multiple at once) */
#define MIO_CMD_GMP232X_SETMEANCFG              (MIO_CMD_GMP232XBASE + 171)  /**< Sets the mean configuration */
#define MIO_CMD_GMP232X_GETMEANCFG              (MIO_CMD_GMP232XBASE + 172)  /**< Reads the mean configuration */
#define MIO_CMD_GMP232X_GETMEANVALUECONFIGURED  (MIO_CMD_GMP232XBASE + 173)  /**< Reads all previously configured mean values */
#define MIO_CMD_GMP232X_SETLIMIT_RELAYCFG       (MIO_CMD_GMP232XBASE + 174)  /**< Sets the limit relay configuration */
#define MIO_CMD_GMP232X_GETLIMIT_RELAYCFG       (MIO_CMD_GMP232XBASE + 175)  /**< Reads the limit relay configuration */
#define MIO_CMD_GMP232X_SETLIMIT_SCOPECFG       (MIO_CMD_GMP232XBASE + 176)  /**< Sets the limit scope configuration */
#define MIO_CMD_GMP232X_GETLIMIT_SCOPECFG       (MIO_CMD_GMP232XBASE + 177)  /**< Reads the limit scope configuration */
#define MIO_CMD_GMP232X_SETCONFIG_EXT           (MIO_CMD_GMP232XBASE + 178)  /**< Sets the module configuration (extended version) */
#define MIO_CMD_GMP232X_GETCONFIG_EXT           (MIO_CMD_GMP232XBASE + 179)  /**< Reads the module configuration (extended version) */
#define MIO_CMD_GMP232X_SETMANUALRELAY          (MIO_CMD_GMP232XBASE + 180)  /**< Sets the manual relay */
#define MIO_CMD_GMP232X_GETMANUALRELAY          (MIO_CMD_GMP232XBASE + 181)  /**< Reads the manual relay */
#define MIO_CMD_GMP232X_GETCFGCHECKSUM          (MIO_CMD_GMP232XBASE + 182)  /**< Reads the configuration checksum */
#define MIO_CMD_GMP232X_GETHISTORYTOTAL         (MIO_CMD_GMP232XBASE + 183)  /**< Reads the total number of history entries (optimized variant) */
#define MIO_CMD_GMP232X_SETLIMIT_NEGSYS         (MIO_CMD_GMP232XBASE + 184)  /**< Sets the negative system configuration (used for MIO_CMD_GMP232X_SETLIMIT_VECTORJUMP) */
#define MIO_CMD_GMP232X_GETLIMIT_NEGSYS         (MIO_CMD_GMP232XBASE + 185)  /**< Reads the negative system configuration (used for MIO_CMD_GMP232X_GETLIMIT_VECTORJUMP) */
#define MIO_CMD_GMP232X_GETLIMIT_INUSE          (MIO_CMD_GMP232XBASE + 186)  /**< Reads back the usage pattern of limit functions (only used internally) */
#define MIO_CMD_GMP232X_GETERROR                (MIO_CMD_GMP232XBASE + 187)  /**< Reads error state of module (including limit errors) */
#define MIO_CMD_GMP232X_GETAUTOSTART            (MIO_CMD_GMP232XBASE + 188)  /**< Reads the AutoStart setting of the module */
/** @} */

/**
 * @name Possible commands for the IO module SCT202
 * @{
 */

#define MIO_CMD_SCT202_BASE         8300
#define MIO_CMD_SCT202_SETLATCHCFG  (MIO_CMD_SCT202_BASE + 1)
#define MIO_CMD_SCT202_GETLATCHCFG  (MIO_CMD_SCT202_BASE + 2)
#define MIO_CMD_SCT202_GETSIGNALS   (MIO_CMD_SCT202_BASE + 3)
/** @} */

/**
 * @name Possible commands for the IO module PVA2XX
 * @{
 */

#define MIO_CMD_PVA2XXBASE                      8400
#define MIO_CMD_PVA2XX_SETPWMFREQ               (MIO_CMD_PVA2XXBASE + 1)     /**< For internal use only: Sets the PWM frequency */
#define MIO_CMD_PVA2XX_GETPWMFREQ               (MIO_CMD_PVA2XXBASE + 2)     /**< For internal use only: Reads the configured PWM frequency */
#define MIO_CMD_PVA2XX_SETDITHER                (MIO_CMD_PVA2XXBASE + 3)     /**< Sets the Dither values */
#define MIO_CMD_PVA2XX_GETDITHER                (MIO_CMD_PVA2XXBASE + 4)     /**< Reads the configured Dither values */
#define MIO_CMD_PVA2XX_SETRAMP                  (MIO_CMD_PVA2XXBASE + 5)     /**< Sets the ramp time */
#define MIO_CMD_PVA2XX_GETRAMP                  (MIO_CMD_PVA2XXBASE + 6)     /**< Reads the configured ramp time */
#define MIO_CMD_PVA2XX_SETINTERPOLATION         (MIO_CMD_PVA2XXBASE + 7)     /**< Sets the characteristic curve */
#define MIO_CMD_PVA2XX_GETINTERPOLATION         (MIO_CMD_PVA2XXBASE + 8)     /**< Reads the characteristic curve */
#define MIO_CMD_PVA2XX_READTEMPLATETOCHAN       (MIO_CMD_PVA2XXBASE + 9)     /**< Sets the template data to the channels */
#define MIO_CMD_PVA2XX_WRITEPARAMFILE           (MIO_CMD_PVA2XXBASE + 10)    /**< Saves the current configuration in to the parameter file */
#define MIO_CMD_PVA2XX_READPARAMFILE            (MIO_CMD_PVA2XXBASE + 11)    /**< Reads the current configuration from the parameter file */
#define MIO_CMD_PVA2XX_GETRAMP_LIMIT            (MIO_CMD_PVA2XXBASE + 12)    /**< Reads the maximal and minimal ramp time */
#define MIO_CMD_PVA2XX_GET_INTERPOLATED_CURVE   (MIO_CMD_PVA2XXBASE + 13)    /**< For internal use only: Reads the interpolated curve data */
#define MIO_CMD_PVA2XX_SETPID                   (MIO_CMD_PVA2XXBASE + 15)    /**< For internal use only: Sets the PID parameters to the Hardware */
#define MIO_CMD_PVA2XX_SETPWMRUNMODE            (MIO_CMD_PVA2XXBASE + 16)    /**< Set the PWM run mode */
#define MIO_CMD_PVA2XX_GETPWMRUNMODE            (MIO_CMD_PVA2XXBASE + 17)    /**< Read the PWM run mode */
#define MIO_CMD_PVA2XX_READCALIB                (MIO_CMD_READCALIB)  /**< Reads the calibration data from ID register and writes it in to the module. */
/** @} */

/**
 * @name Example offset values for the IO module DMS202 offset calibration
 * @{
 */

#define MIO_DMS_OFF_0MV 0x0000   /**< 0mV Offset, input range  0mV...+16mV */
#define MIO_DMS_OFF_1MV 0x0800   /**< 1mV Offset, input range -1mV...+15mV */
#define MIO_DMS_OFF_2MV 0x1000   /**< 2mV Offset, input range -2mV...+14mV */
#define MIO_DMS_OFF_3MV 0x1800   /**< 3mV Offset, input range -3mV...+13mV */
#define MIO_DMS_OFF_4MV 0x2000   /**< 4mV Offset, input range -4mV...+12mV */
#define MIO_DMS_OFF_8MV 0x4000   /**< 8mV Offset, input range -8mV...+8mV */
/** @} */

/**
 * @anchor MIO_AI_FILTERS
 */
/**
 * @name AI208/SI specific filter constants
 * @{
 */

#define MIO_AI_FILTER_2553  0x0  /**< Cut-off frequency 2553.13 Hz */
#define MIO_AI_FILTER_1277  0x1  /**< Cut-off frequency 1277.06 Hz */
#define MIO_AI_FILTER_639   0x2  /**< Cut-off frequency 638.52 Hz */
#define MIO_AI_FILTER_319   0x3  /**< Cut-off frequency 319.26 Hz */
#define MIO_AI_FILTER_160   0x4  /**< Cut-off frequency 159.63 Hz */
#define MIO_AI_FILTER_80    0x5  /**< Cut-off frequency 79.81 Hz */
#define MIO_AI_FILTER_40    0x6  /**< Cut-off frequency 39.91 Hz */
#define MIO_AI_FILTER_20    0x7  /**< Cut-off frequency 19.95 Hz */
#define MIO_AI_FILTER_10    0x8  /**< Cut-off frequency 9.98 Hz */
#define MIO_AI_FILTER_5     0x9  /**< Cut-off frequency 4.99 Hz */
#define MIO_AI_FILTER_2     0xa  /**< Cut-off frequency 2.49 Hz */
/** @} */

/**
 * @name DataTypes for PLC Process Image
 * @{
 */

#define MIO_PLC_FLAG        0x100    /**< Export in PLC process image */
#define MIO_PLC_TYP_IN      0x20
#define MIO_PLC_TYP_OUT     0x40
#define MIO_PLC_TYP_INOUT   0x60
#define MIO_PLC_TYP_UNDEF   0    /**< BYTE in M-PLC */
#define MIO_PLC_TYP_U1      1    /**< BOOL in M-PLC (only 0 and 1 allowed) */
#define MIO_PLC_TYP_S8      2    /**< SINT in M-PLC */
#define MIO_PLC_TYP_U8      3    /**< BYTE in M-PLC */
#define MIO_PLC_TYP_S16     4    /**< INT in M-PLC */
#define MIO_PLC_TYP_U16     5    /**< WORD in M-PLC */
#define MIO_PLC_TYP_S32     6    /**< DINT in M-PLC */
#define MIO_PLC_TYP_U32     7    /**< DWORD in M-PLC */
#define MIO_PLC_TYP_R32     8    /**< REAL in M-PLC, 4 byte floating point value */
#define MIO_PLC_TYP_R64     9    /**< LREAL in M-PLC, 8 byte floating point value */
/** @} */
#define MIO_SYNC_MINLEN 50  /**< Minimum duration of high/low phase from Sync pulse in us */
#ifndef _ASMLANGUAGE

/**
 * @name The next 2 structures describe the *.cdi element in the *.m File
 * @{
 */

typedef struct
{
    UINT16  CardType;           /**< Type of card */
    /**
     * Variant of card; 0 -> all
     * !0 -> variant code + 1
     */
    UINT16  CardVariant;
    CHAR8   CardName[MIO_CNAMELEN_A];    /**< Name of card */
} MIO_CARD;

/**
 * List of cards supported by the device driver
 */
typedef struct
{
    UINT32      NbOfCard;       /**< Number of cards */
    MIO_CARD    Card[1];        /**< List of cards */
} MIO_CARDLST;

/** @} */
/**
 * Version code, do not change values or size of this structure,
 * used for MIO_CMD_GETVERSION .
 */
typedef union
{
    /**
     * HW version
     */
    struct
    {
        UINT8   TestVer;            /**< Testversion */
        UINT8   Revision;           /**< Revision number */
        UINT16  Design;             /**< Hardware design number */
    } VerHW;
    UINT32  Ver32;              /**< 32-Bit Version */
} LOGIC_VERSION;

/**
 * Short version format structure
 */
typedef union MIO_VERS
{
    /**
     * Version information
     */
    struct
    {
        UINT8   Major;              /**< Major Version        V.xx.xx */
        UINT8   Minor;              /**< Minor Version        x.VV.xx */
        UINT8   SubMin;             /**< Sub-Minor Version    x.xx.VV */
        UINT8   Type;               /**< #M_VER_ALPHA, #M_VER_BETA or #M_VER_RELEASE */
    } Ver;
    UINT32  Ver32;              /**< 32-Bit Version */
} MIO_VERS;

/**
 * Structure for I/O module versions (used in #MIO_CMD_GETVERSION)
 */
typedef struct MIO_VERSION
{
    SYS_VERSION     Driver;     /**< Version of MIO-Driver */
    SYS_VERSION     Fware;      /**< Version of Firmware */
    SYS_VERSION     Bios;       /**< Version of BIOS */
    LOGIC_VERSION   Logic;      /**< Logic version (since MSys 3.90) */
    LOGIC_VERSION   Logic2;     /**< Logic version (since MSys 4.10) */
    UINT8           Spare[8];   /**< Not used, 0 for now */
} MIO_VERSION;

/**
 * Structure for the SMI-Call #MIO_PROC_GETDRV
 */
typedef struct
{
    UINT32  CardNb;             /**< Card number */
} MIO_GETDRV_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETDRV
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  DrvId;              /**< ID for card access */
} MIO_GETDRV_R;

/**
 * Structure for the SMI-Call #MIO_PROC_GETVALUE
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
    UINT32  ChanNb;             /**< Requested channel number 1-n */
} MIO_GETVAL_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETVALUE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Value;              /**< Actual value */
} MIO_GETVAL_R;

/**
 * Structure for the SMI-Call #MIO_PROC_SETVALUE
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
    UINT32  ChanNb;             /**< Requested channel number 1-n */
    SINT32  Value;              /**< Value to use */
} MIO_SETVAL_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_SETVALUE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MIO_SETVAL_R;

/**
 * Structure for the SMI-Call #MIO_PROC_GETVALUES
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
} MIO_GETVALUES_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETVALUES
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Values[1];          /**< Actual values */
} MIO_GETVALUES_R;

/**
 * Structure for the SMI-Call #MIO_PROC_SETVALUES
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
    SINT32  Values[1];          /**< List of values */
} MIO_SETVALUES_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_SETVALUES
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MIO_SETVALUES_R;

/**
 * Structure for the SMI-Call #MIO_PROC_GETBLK
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
    UINT32  ChanNb;             /**< Requested channel number 1-n */
    UINT32  BuffLen;            /**< Size of block to read */
} MIO_GETBLK_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETBLK
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  BuffLen;            /**< Size of block read */
    UINT8   Buff[1];            /**< Actual block */
} MIO_GETBLK_R;

/**
 * Structure for the SMI-Call #MIO_PROC_SETBLK
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
    UINT32  ChanNb;             /**< Requested channel number 1-n */
    UINT32  BuffLen;            /**< Size of block to write */
    UINT8   Buff[1];            /**< Contents of block */
} MIO_SETBLK_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_SETBLK
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MIO_SETBLK_R;

/**
 * Structure for the SMI-Call #MIO_PROC_GETERROR
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
    UINT32  ChanNb;             /**< Requested channel number 1-n */
} MIO_GETERROR_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETERROR
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Error;              /**< Error code */
} MIO_GETERROR_R;

/**
 * Structure for the SMI-Call #MIO_PROC_GETCHMOD
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
    UINT32  ChanNb;             /**< Requested channel number 1-n */
} MIO_GETCHMOD_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETCHMOD
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Mode;               /**< Actual channel mode */
} MIO_GETCHMOD_R;

/**
 * Structure for the SMI-Call #MIO_PROC_SETCHMOD
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
    UINT32  ChanNb;             /**< Requested channel number 1-n */
    UINT32  Mode;               /**< Channel mode to set */
} MIO_SETCHMOD_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_SETCHMOD
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MIO_SETCHMOD_R;

/**
 * Structure for the SMI-Call #MIO_PROC_GETCDMOD
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
} MIO_GETCDMOD_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETCDMOD
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Mode;               /**< Actual card mode */
} MIO_GETCDMOD_R;

/**
 * Structure for the SMI-Call #MIO_PROC_SETCDMOD
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
    UINT32  Mode;               /**< Card mode to set */
} MIO_SETCDMOD_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_SETCDMOD
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MIO_SETCDMOD_R;

/**
 * Structure for the SMI-Call #MIO_PROC_SETSELECT
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
    UINT32  ChanNb;             /**< Requested channel number 1-n */
    UINT32  Select;             /**< Select info; 1->selected */
} MIO_SETSELECT_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_SETSELECT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MIO_SETSELECT_R;

/**
 * Structure for the SMI-Call #MIO_PROC_GETSELECT
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
    UINT32  ChanNb;             /**< Requested channel number 1-n */
} MIO_GETSELECT_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETSELECT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Select;             /**< Select info; 1->selected */
} MIO_GETSELECT_R;

/**
 * Information of IO module
 */
typedef struct
{
    UINT32  CardNb;             /**< Number of IO module */
    SINT32  Type;               /**< Type of IO module (@ref MIO_T_) */
    SINT32  Variant;            /**< Variant of IO module */
    SINT32  Category;           /**< Category of IO module (@ref MIO_CATEG_) */
    SINT32  Flags;              /**< Capabilities of IO module (@ref MIO_FLG_) */
    UINT32  MaxChan;            /**< Maximum channels on IO module */
} MIO_CARDINF;

/**
 * Structure for the SMI-Call #MIO_PROC_GETCDINF
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
} MIO_GETCDINF_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETCDINF
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    MIO_CARDINF Inf;            /**< IO module info list */
} MIO_GETCDINF_R;

/**
 * Info on one channel
 */
typedef struct
{
    SINT32  Category;           /**< Category of IO channel (@ref MIO_CATEG_) */
    SINT32  Flags;              /**< Capabilities of IO channel (@ref MIO_FLG_) */
} MIO_CHANINF;

/**
 * Info on one channel
 * ATTN: This structure is ONLY used by the SEM201 Module!
 *       Do not use this structure in a new project/driver (CRID#27826)!
 */
typedef struct
{
    UINT32  Category;           /**< Category of channel (@ref MIO_CATEG_) */
    UINT16  Flags;              /**< Capability of IO channel (@ref MIO_FLG_) */
    UINT16  MaxValues;          /**< Max index for IO channel values */
} MIO_CHANINF2;

/**
 * Structure for the SMI-Call #MIO_PROC_GETCHINF
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
    UINT32  ChanNb;             /**< Requested channel number 1-n */
} MIO_GETCHINF_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETCHINF
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    MIO_CHANINF Inf;            /**< Channel info */
} MIO_GETCHINF_R;

/**
 * Detailed information of a dedicated channel
 */
typedef struct
{
    UINT32      ChanNb;         /**< Number of IO channel */
    UINT32      MaxUser;        /**< Maximum number of concurrent users */
    UINT32      ActUser;        /**< Number of concurrent users */
    SINT32      State;          /**< If mio_GetError() reports an error for this channel, `State` contains (-Error) otherwise #RES_S_RUN. */
    MIO_CHANINF ChInf;          /**< Category and flags of channel */
    UINT32      Range;          /**< Range code of channel */
    SINT32      Value;          /**< Actual value */
    UINT32      Spare[2];       /**< Not used, 0 for now */
} MIO_XCHANINFO;

/**
 * Structure for the SMI-Call #MIO_PROC_XCHANINFOLST
 */
typedef struct
{
    UINT32  CardNb;             /**< Number of IO module */
    UINT32  FirstIdx;           /**< First index to channel list */
    UINT32  LastIdx;            /**< Last index to channel list */
} MIO_XCHANINFOLST_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_XCHANINFOLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfCh;     /**< Number of list elements */
    MIO_XCHANINFO   Inf[1];     /**< List of channel informations */
} MIO_XCHANINFOLST_R;

/**
 * Detailed information of a dedicated channel
 */
typedef struct
{
    UINT32      ChanNb;         /**< Number of IO channel */
    UINT32      MaxUser;        /**< Maximum number of concurrent users */
    UINT32      ActUser;        /**< Number of concurrent users */
    SINT32      State;          /**< If mio_GetError() reports an error for this channel, `State` contains (-Error) otherwise #RES_S_RUN. */
    MIO_CHANINF ChInf;          /**< Category and flags of channel */
    UINT32      Range;          /**< Range code of channel */
    SINT64      Value;          /**< Actual value */
    UINT16      Len;            /**< Size of value in bytes */
    UINT16      Format;         /**< SVI format type of value */
    REAL32      Scale;          /**< Scaling factor */
    REAL32      Offset;         /**< Offset */
    REAL32      Min;            /**< Minimum value */
    REAL32      Max;            /**< Maximum value */
    UINT8       Spare[8];       /**< Not used, 0 for now */
    UINT16      ExtChFlags;     /**< Extended channel flags (MIO_EXTFLG_*) */
    UINT8       DispMode;       /**< Display mode: UFB_DISP_MODE */
    UINT8       SiUnit;         /**< Si-Units:  UFB_SIUNIT */
    CHAR8       UnitStr[12];    /**< Unit optional text ("V", "uA"...) */
} MIO_X2CHANINFO;

/**
 * Structure for the SMI-Call #MIO_PROC_X2CHANINFOLST
 */
typedef struct
{
    UINT32  CardNb;             /**< Number of IO module */
    UINT32  FirstIdx;           /**< First index to channel list */
    UINT32  LastIdx;            /**< Last index to channel list */
} MIO_X2CHANINFOLST_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_X2CHANINFOLST
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfCh;     /**< Number of list elements */
    MIO_X2CHANINFO  Inf[1];     /**< List of channel informations */
} MIO_X2CHANINFOLST_R;

/**
 * Structure for the SMI-Call #MIO_PROC_RESET
 */
typedef struct
{
    UINT32  DrvId;              /**< ID for card access */
} MIO_RESET_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_RESET
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MIO_RESET_R;

/**
 * Extended card info
 * @since V1.02 Release
 */
typedef struct
{
    UINT32      CardNb;         /**< Number of IO module */
    SINT32      StationNb;      /**< Number of station (1-16) */
    SINT32      SlotNb;         /**< Number of slot (1-16) */
    SINT32      PreSlots;       /**< Slots before occupied */
    SINT32      PostSlots;      /**< Slots after occupied */
    SINT32      Mode;           /**< Mode of device driver */
    /**
     * Status of card.
     * `State` contains #RES_S_ERROR if mio_GetError() reports an error for this card,
     * or #RES_S_WARNING if #MIO_CMD_GET_MODULE_WARNINGS reports a warning for this card
     * otherwise #RES_S_RUN.
     * Element `ExStateInfo` may contain additional information.
     */
    SINT32      State;
    SINT32      Type;           /**< Type of IO module (@ref MIO_T_) */
    SINT32      Variant;        /**< Variant of IO module */
    SINT32      Category;       /**< Category of IO module (@ref MIO_CATEG_) */
    SINT32      Flags;          /**< Capabilities of IO module (@ref MIO_FLG_) */
    UINT32      MaxChan;        /**< Maximum channels on IO module */
    SINT32      Version;        /**< Function code upper part */
    SINT32      DrvVersion;     /**< Required driver version */
    UINT32      Attribute;      /**< Attributes for internal use */
    struct tm   ProdTime;       /**< Production date and time */
    CHAR8       ProdNb[MIO_PRODNBLEN_A];     /**< Serial number 10-digits */
    CHAR8       Name[MIO_CNAMELEN_A];    /**< Name of IO module */
    CHAR8       Info[MIO_INFOLEN_A];     /**< Info block */
    CHAR8       DrvName[M_FILENAMELEN_A];    /**< Name of device driver */

    /*
     * Below here added in MSys V1.08
     */
    SINT32      Power;          /**< Power consumption in mW */
    SINT32      Current_5V;     /**< 5V Current sink/source in mA */
    SINT32      Current_P15V;   /**< +15V Current sink/source in mA */
    SINT32      Current_M15V;   /**< -15V Current sink/source in mA */
    SINT32      ModVerType;     /**< Version type code @ref MIO_VER_ */
    BOOL8       RedundantRead;  /**< Redundant read of data if TRUE */
    BOOL8       WriteVerify;    /**< Write verify of data if TRUE */
    BOOL8       BusCheck;       /**< BUSCHECK supported if TRUE */
    BOOL8       AliveCheck;     /**< ALIVECHECK supported if TRUE */
    UINT16      AssemblyCode;   /**< Function code lower part */
    UINT8       HwVariant;      /**< Hardware variant */
    UINT8       Reserved1[1];   /**< Not used, 0 for now */
    UINT32      Settings;       /**< Flags for module depending functionalities */
    MIO_VERS    Fware;          /**< Firmware version */
    /**
     * Extended state information related to element `State`.
     * `ExStateInfo` contains (-Error) if mio_GetError() reports an error for this card
     * (`State` is #RES_S_ERROR in this case).
     * `ExStateInfo` contains (-Warning) if #MIO_CMD_GET_MODULE_WARNINGS reports a warning
     * (`State` is #RES_S_WARNING in this case).
     * Otherwise `ExStateInfo` contains #MIO_ER_OK
     * (`State` is #RES_S_RUN in this case).
     */
    UINT32      ExStateInfo;
} MIO_EXTCDINF;

/**
 * Structure for the SMI-Call #MIO_PROC_GETEXTCDINF
 */
typedef struct
{
    UINT32  CardNb;             /**< Number of card */
} MIO_GETEXTCDINF_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETEXTCDINF
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    MIO_EXTCDINF    Inf;        /**< Card info as above */
} MIO_GETEXTCDINF_R;

/**
 * Extended card info 2
 * @since V3.90 Release
 */
typedef struct
{
    UINT32      CardNb;         /**< Number of IO module */
    SINT32      StationNb;      /**< Number of station (1-16) */
    SINT32      SlotNb;         /**< Number of slot (1-16) */
    SINT32      PreSlots;       /**< Slots before occupied */
    SINT32      PostSlots;      /**< Slots after occupied */
    SINT32      Mode;           /**< Mode of device driver */
    /**
     * Status of card.
     * `State` contains #RES_S_ERROR if mio_GetError() reports an error for this card,
     * or #RES_S_WARNING if #MIO_CMD_GET_MODULE_WARNINGS reports a warning for this card
     * otherwise #RES_S_RUN.
     * Element `ExStateInfo` may contain additional information.
     */
    SINT32      State;
    SINT32      Type;           /**< Type of IO module (@ref MIO_T_) */
    SINT32      Variant;        /**< Variant of IO module */
    SINT32      Category;       /**< Category of IO module (@ref MIO_CATEG_) */
    SINT32      Flags;          /**< Capabilities of IO module (@ref MIO_FLG_) */
    UINT32      MaxChan;        /**< Maximum channels on IO module */
    SINT32      Version;        /**< Function code upper part */
    SINT32      DrvVersion;     /**< Required driver version */
    UINT32      Attribute;      /**< Attributes for internal use */
    struct tm   ProdTime;       /**< Production date and time */
    CHAR8       ProdNb[MIO_PRODNBLEN_A];     /**< Serial number 10-digits */
    CHAR8       Name[MIO_CNAMELEN_A];    /**< Name of IO module */
    CHAR8       Info[MIO_INFOLEN_A];     /**< Info block */
    CHAR8       DrvName[M_FILENAMELEN_A];    /**< Name of device driver */
    SINT32      Power;          /**< Power consumption in mW */
    SINT32      Current_5V;     /**< 5V Current sink/source in mA */
    SINT32      Current_P15V;   /**< +15V Current sink/source in mA */
    SINT32      Current_M15V;   /**< -15V Current sink/source in mA */
    SINT32      ModVerType;     /**< Version type code @ref MIO_VER_ */
    BOOL8       RedundantRead;  /**< Redundant read of data if TRUE */
    BOOL8       WriteVerify;    /**< Write verify of data if TRUE */
    BOOL8       BusCheck;       /**< BUSCHECK supported if TRUE */
    BOOL8       AliveCheck;     /**< ALIVECHECK supported if TRUE */
    UINT16      AssemblyCode;   /**< Function code lower part */
    UINT8       HwVariant;      /**< Hardware variant */
    UINT8       Reserved1[1];   /**< Not used, 0 for now */
    UINT32      Settings;       /**< Flags for module depending functionalities */

    /**
     * Till here the structure is exactly the same as MIO_EXTCDINF.
     */
    /**
     * Extended state information related to element `State`.
     * `ExStateInfo` contains (-Error) if mio_GetError() reports an error for this card
     * (`State` is #RES_S_ERROR in this case).
     * `ExStateInfo` contains (-Warning) if #MIO_CMD_GET_MODULE_WARNINGS reports a warning
     * (`State` is #RES_S_WARNING in this case).
     * Otherwise `ExStateInfo` contains #MIO_ER_OK
     * (`State` is #RES_S_RUN in this case).
     */
    UINT32      ExStateInfo;
    MIO_VERSION Versions;       /**< Versions of this module (FW, Logic, ...) */
    MIO_VERS    PackageVers;    /**< Package version */
    UINT32      PartNumber;     /**< Part number (0 if not available) */
    BOOL8       FirmBackup;     /**< Firmware can be recovered */
    UINT8       Spare1[3];      /**< Align it to 32 bit */
    UINT32      Spare[29];      /**< Not used, 0 for now */
} MIO_EXTCDINF2;

/**
 * Structure for the SMI-Call #MIO_PROC_GETEXTCDINF2
 */
typedef struct
{
    UINT32  CardNb;             /**< Number of card */
    UINT32  Spare[10];          /**< Not used, 0 for now */
} MIO_GETEXTCDINF2_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETEXTCDINF2
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    MIO_EXTCDINF2   Inf;        /**< Card info 2 as above */
} MIO_GETEXTCDINF2_R;

/**
 * Structure for the SMI-Call #MIO_PROC_UPDATESW
 */
typedef struct
{
    UINT32  CardNb;             /**< Number of IO module (1-n) */
    UINT32  Mode;               /**< Mode as under MIO_UFW_XXX */
    CHAR8   FileName[M_PATHLEN_A];   /**< Path/Name of new firmware */
} MIO_UPDATESW_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_UPDATESW
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} MIO_UPDATESW_R;

/**
 * Same as above with MIO_UFW_XREPLY set
 */
typedef struct
{
    SINT32      RetCode;        /**< Return code */
    SYS_VERSION OldFware;       /**< Module firmware version */
    SYS_VERSION NewFware;       /**< New firmware version */
    UINT32      Spare[4];       /**< Not used, 0 for now */
} MIO_UPDATESW_XR;

/**
 * Structure for the SMI-Call #MIO_PROC_PROGRESS
 */
typedef struct
{
    UINT32  CardNb;             /**< Number of IO module (1-n) */
    UINT32  Spare[3];           /**< Not used, 0 for now */
} MIO_PROGRESS_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_PROGRESS
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Status;             /**< Status code */
    UINT32  DoneSize;           /**< Size done in bytes */
    UINT32  DeviceSize;         /**< Total size in bytes */
    UINT32  Spare[2];           /**< Not used, 0 for now */
} MIO_PROGRESS_R;

/**
 * Structure for the SMI-Call #MIO_PROC_DOCMD
 */
typedef struct
{
    VOID*       DrvId;          /**< ID for card access */
    UINT32      ChanNb;         /**< Channel number */
    UINT32      Cmd;            /**< Command */
    UINT32      NbOfParam;      /**< Number of parameters */
    UINT32      ParamDesc[1];   /**< Parameters itself */
    /* UINT32   ParamData[1]; */
} MIO_DOCMD_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_DOCMD
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  RetValue;           /**< Return Value of command MIO_PROC_DOCMD */
    UINT32  ParamData[1];       /**< Return data of function */
} MIO_DOCMD_R;

typedef struct
{
    UINT32  ChanNb;             /**< Number of channel 1-n */
    CHAR8   Name[SVI_ADDRLEN_A];     /**< Symbolic name */
} MIO_CHNAME;

/**
 * Structure for the SMI-Call #MIO_PROC_GETCHNAMES
 */
typedef struct
{
    UINT32  CardNb;             /**< Number of IO module (1-n) */
    UINT32  StartChanNb;        /**< First channel 1-n */
    UINT32  EndChanNb;          /**< Last channel (incl.) */
} MIO_GETCHNAMES_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETCHNAMES
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfNames;      /**< Size of list */
    MIO_CHNAME  NameLst[1];     /**< List of symbolic name */
} MIO_GETCHNAMES_R;

typedef struct
{
    UINT32  ChanNb;             /**< Number of channel 1-n */
    UINT32  DataType;           /**< Data type of channel */
    UINT32  Length;             /**< Data type length */
    UINT32  Reserved;           /**< Not used */
} MIO_CHTYPE;

/**
 * Structure for the SMI-Call #MIO_PROC_GETCHTYPES
 */
typedef struct
{
    UINT32  CardNb;             /**< Number of IO module (1-n) */
    UINT32  StartChanNb;        /**< First channel 1-n */
    UINT32  EndChanNb;          /**< Last channel (incl.) */
} MIO_GETCHTYPES_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETCHTYPES
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfTypes;      /**< Size of list */
    MIO_CHTYPE  TypeLst[1];     /**< List of type info */
} MIO_GETCHTYPES_R;

typedef struct
{
    UINT16  ParentStation;      /**< Info to parent station */
    UINT16  ParentSlot;
    UINT16  ParentChan;
    UINT16  ChildSlot;          /**< Slave station is in slot */
    UINT16  ChildChan;          /**< Parent is connected on channel */
    UINT16  StationNb;          /**< Station number */
    UINT8   Reserved[16];       /**< Not used, 0 for now */
    UINT32  NbOfBackplane;      /**< Number of Backplanes on station */
} MIO_STATION;

/**
 * Structure for the SMI-Call #MIO_PROC_GETSTATIONLST
 */
typedef struct
{
} MIO_GETSTATIONLST_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETSTATIONLST
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfStations;   /**< Size of list */
    MIO_STATION StationLst[1];  /**< List of station info */
} MIO_GETSTATIONLST_R;

/**
 * Structure for the SMI-Call #MIO_PROC_GETBPINF
 */
typedef struct
{
    UINT32  StationNb;          /**< Requested station number (1-16) */
    UINT32  BackplaneNb;        /**< Requested backplane (1-16) */
} MIO_GETBPINF_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETBPINF
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    SINT32      Type;           /**< Type of IO module (@ref MIO_T_) */
    SINT32      Variant;        /**< Variant of IO module */
    SINT32      Version;        /**< HW version of IO module */
    UINT32      Attribute;      /**< Attributes for internal use */
    struct tm   ProdTime;       /**< Production date and time */
    CHAR8       ProdNb[MIO_PRODNBLEN_A];     /**< Serial number 10-digits */
    CHAR8       Name[MIO_CNAMELEN_A];    /**< Name of backplane */
    CHAR8       Info[MIO_INFOLEN_A];     /**< Info block */
    UINT8       Reserved[48];   /**< Not used, 0 for now */
} MIO_GETBPINF_R;

/**
 * Structure for the SMI-Call #MIO_PROC_GETIOSTAT
 */
typedef struct
{
    UINT32  CardNb;             /**< Number of IO module (1-n) */
    UINT32  Spare;              /**< Must be 0 for now */
} MIO_GETIOSTAT_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_GETIOSTAT
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  BusCheckCalls;      /**< Number of IO-Bus Check calls */
    UINT32  BadBusChecks;       /**< Number of IO-Bus Check fails */
    UINT32  BadRetainChecks;    /**< Number of Retain Check fails */
    UINT32  BadShdChecks;       /**< Number of Shadow Check fails */
    UINT32  AliveCheckCalls;    /**< Number of Alive Check calls */
    UINT32  BadAliveChecks;     /**< Number of Alive Check fails */
    UINT32  WriteRetries;       /**< Number of Write Retries */
    UINT32  WriteFails;         /**< Number of Write fails */
    UINT32  PlausibleFails;     /**< Number of Plausibility fails */
    UINT32  ReadFails;          /**< Number of Read fails */
    UINT32  Events;             /**< Number of event interrupts */
    UINT32  UnknownEvents;      /**< Number of unkown event interrupts */
    UINT32  Errors;             /**< Number of error interrupts */
    UINT32  UnknownErrors;      /**< Number of unkown error interrupts */
    UINT32  Spare[6];           /**< Must be 0 for now */
} MIO_GETIOSTAT_R;

/**
 * @since V3.85.04 Beta
 */
typedef struct
{
    UINT32      ChanNb;         /**< Actual Channel number */
    UINT32      MaxUser;        /**< Maximum number of concurrent users */
    UINT32      ActUser;        /**< Number of concurrent users */
    UINT32      ErrorStatus;    /**< Actual error status flags (@ref MIO_E_) */
    UINT16      ExtChFlags;     /**< Extended channel flags (MIO_EXTFLG_*) */
    BOOL8       ReadError;      /**< Channel has read error */
    UINT8       Spare1;         /**< Must be 0 for now */
    MIO_CHANINF ChInf;          /**< Category and flags of channel */
    /**
     * Structure containing information about raw value
     */
    struct
    {
        UINT32  Len;                /**< Size of value in bytes */
        UINT32  Format;             /**< SVI format type of value */
        SINT64  Value;              /**< Actual value */
    } RawVal;
    /**
     * Structure containing range information
     */
    struct
    {
        UINT32  Range;              /**< Range code of channel */
        REAL64  Factor;             /**< Scaling factor */
        REAL64  Offset;             /**< Offset */
        REAL64  Min;                /**< Minimum value */
        REAL64  Max;                /**< Maximum value */
        UINT32  SiUnit;             /**< Si-Units: UFB_SIUNIT */
        CHAR8   UnitStr[12];        /**< Unit optional text ("V", "uA"...) */
    } RangeInf;
    /**
     * Structure containing scaling information
     */
    struct
    {
        UINT32  Format;             /**< SVI format type of value (#SVI_F_UNKNOWN for no scaling) */
        SINT32  ScaledValue_S32;    /**< Scaled value when using type SINT32 */
        REAL64  ScaledValue_R64;    /**< Scaled value when using type REAL64 */
    } Scale;
    UINT32      Spare2[8];      /**< Must be 0 for now */
} MIO_CHANMONITOR_ITEM;

/**
 * Structure for the SMI-Call #MIO_PROC_CHANMONITOR
 */
typedef struct
{
    UINT32  CardNb;             /**< Number of IO module (1-32000) */
    UINT32  StartChan;          /**< Start channel */
    UINT32  NbChans;            /**< Number of channels requested */
} MIO_CHANMONITOR_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_CHANMONITOR
 */
typedef struct
{
    SINT32                  RetCode;     /**< Return Code */
    UINT32                  NbChans;     /**< Number of channels returned */
    UINT32                  CardNb;  /**< CardNb returned */
    MIO_CHANMONITOR_ITEM    Channels[1];     /**< Requested channel data */
} MIO_CHANMONITOR_R;

/**
 * @since V3.85.04 Beta
 */
typedef struct
{
    UINT32  ChanNb;             /**< Actual Channel number */
    UINT32  Format;             /**< SVI format type of value (#SVI_F_UNKNOWN for no scaling) */
    UINT32  Len;                /**< Length of the scaled value */
    CHAR8   ScaledName[SVI_ADDRLEN_A];   /**< Name of the scaled value */
    CHAR8   ScaleUnit[12];      /**< Target unit of scaling */
    UINT32  Spare[6];           /**< Must be 0 for now */
} MIO_CHANSCALEINF_ITEM;

/**
 * Structure for the SMI-Call #MIO_PROC_CHANSCALEINV
 */
typedef struct
{
    UINT32  CardNb;             /**< Number of IO module (1-32000) */
    UINT32  StartChan;          /**< Start channel */
    UINT32  NbChans;            /**< Number of channels requested */
} MIO_CHANSCALEINV_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_CHANSCALEINV
 */
typedef struct
{
    SINT32                  RetCode;     /**< Return Code */
    UINT32                  NbChans;     /**< Number of channels returned */
    MIO_CHANSCALEINF_ITEM   Channels[1];     /**< Requested channel data */
} MIO_CHANSCALEINV_R;

/**
 * Structure for the SMI-Call #MIO_PROC_SETSCALEDVALUE
 */
typedef struct
{
    UINT32  CardNb;             /**< Number of IO module (1-32000) */
    UINT32  ChanNb;             /**< Channel number */
    UINT32  Format;             /**< SVI format type of value */
    SINT32  ScaledValue_S32;    /**< Scaled value when using type SINT32 */
    REAL64  ScaledValue_R64;    /**< Scaled value when using type REAL64 */
} MIO_SETSCALEDVALUE_C;

/**
 * Structure for the SMI-Reply #MIO_PROC_SETSCALEDVALUE
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  RetVal;             /**< Return code of mio_SetScaledValue*() function (@ref MIO_Return_Codes) */
} MIO_SETSCALEDVALUE_R;


/**
 * @name Structures for the IO module ACR222 DoCommand
 * @{
 */

typedef struct
{
    UINT32  Method;             /**< Profile type */
    UINT32  FirstSearchVelocity;     /**< Speed for search switch INC/sec */
    UINT32  SecondSearchVelocity;    /**< Speed for search zero in INC/sec */
    UINT32  Acceleration;       /**< Ramp Up and Down in INC/sec2 */
    UINT32  Spare[2];           /**< Must be 0 for now */
} MIO_ACR_HOME;

typedef struct
{
    UINT32  Type;               /**< Profile type */
    UINT32  StartVelocity;      /**< Starting frequency in INC/sec */
    UINT32  MaxVelocity;        /**< Maximum frequency in INC/sec */
    UINT32  Acceleration;       /**< Ramp Up in INC/sec2 */
    UINT32  Deceleration;       /**< Ramp Down in INC/sec2 */
    UINT32  SShapedArea;        /**< Pulses for none linear area */
    UINT32  MidVelocity;        /**< Middle frequency in INC/sec */
    UINT32  FirstProfilePos;    /**< Position to change profile */
    UINT32  Spare[3];           /**< Must be 0 for now */
} MIO_ACR_PROFILE;

typedef struct
{
    UINT32  OutPolarity;        /**< Polarity bit filed for outputs */
    UINT32  InPolarity;         /**< Polarity bit filed for inputs */
    UINT32  PulsePulseMode;     /**< Polarity bit filed pulse signal */
    UINT32  Spare;              /**< Must be 0 for now */
} MIO_ACR_DRVDATA;

typedef struct
{
    UINT32  Encoder;            /**< Encoder resolution */
    UINT32  Motor;              /**< Motor resolution normal */
    UINT32  MicroMotor;         /**< Motor resolution for micro stepping */
    UINT32  Spare;              /**< Must be 0 for now */
} MIO_ACR_RESOLUTION;

/** @} */

/**
 * @name Structures for the IO module IOP201 DoCommand
 * @{
 */

/**
 * IOP201 Control register definition
 */
typedef union
{
    struct
    {
        UINT16 SystemCal    : 1;        /**< en-/disables system calibrations */
        UINT16 ToggleBit    : 1;        /**< toggle bit (application read control) */
        UINT16 Direction    : 2;        /**< direction bits (bit's are exclusive valid) */
        UINT16 Ready        : 1;        /**< application ready starts/stops data reading */
        UINT16 Range        : 2;        /**< Measurement ranges (0 - 3) */
        UINT16 AngleOffset  : 9;        /**< Angle offset setting possible range 0-359?*/
    } Bits;                             /**< Control register Bit access */
    UINT16  Reg;                /**< Control register 16-Bit word access */
} MIO_IOP_CONTROL;

/**
 * IOP201 Status register definition
 */
typedef union
{
    struct
    {                                   /* external status bits (measurement unit) */
        UINT16 DataValid    : 1;        /**< Measurement unit signals data valid for reading */
        UINT16 ToggleBit    : 1;        /**< toggle bit (application read control)  */
        UINT16 Direction    : 2;        /**< direction bits (bit's are exclusive valid) */
        UINT16 Ready        : 1;        /**< application ready starts/stops data reading */
        UINT16 Range        : 2;        /**< Measurement ranges (0 - 3) */
        UINT16 MemBlock     : 1;        /**< actual memory block 0 / 1 */

                                        /* firmware specific status bits */
        UINT16 TimeoutFail  : 1;        /**< M1 event interrupt acknowledge timeouts */
        UINT16 DataFail     : 1;        /**< Measurement unit signals 'data not valid' */
        UINT16 ToggleFail   : 1;        /**< toggle bit not altered between two interrpts */
        UINT16 CommFail     : 1;        /**< read or write error on IOP201 interface */
        UINT16 Reserve      : 2;        /**< reserved for other errors */
        UINT16 ReadFail     : 1;        /**< CommFail: no external ready signal received */
        UINT16 WriteFail    : 1;        /**< CommFail: error read back control reg after write */
    } Bits;                             /**< Status register Bit access */
    UINT16  Reg;                /**< Status register 16-Bit word access */
} MIO_IOP_STATE;

/**
 * IOP201 Mode register definition (extends the
 * 16-Bit hardware control/state register)
 */
typedef union
{
    struct
    {
        UINT16 TestRead     : 1;        /**< reads data also if no data valid bit is set */
        UINT16 IntAckOnErr  : 1;        /**< set interrupt acknowledge signal on comm error */
        UINT16 IntAckOnly   : 1;        /**< set interrupt acknowledge signal, no control word */
        UINT16 Reserve      : 12;       /**< reserved for future use */
        UINT16 NoLogError   : 1;        /**< suppress log error entries if function fails */
    } Bits;                             /**< Mode register Bit access */
    UINT16  Reg;                /**< Mode register 16-Bit word access */
} MIO_IOP_MODE;

/**
 * IOP201 Control-Mode register definition used
 * for MIO_CMD_SETCONTREG, MIO_CMD_INITCOMM and
 */
typedef union
{
    struct
    {                                   /* external control bits (measurement unit) */
        UINT32 SystemCal    : 1;        /**< en-/disables system calibrations */
        UINT32 ToggleBit    : 1;        /**< toggle bit (application read control) */
        UINT32 Direction    : 2;        /**< direction bits (bit's are exclusive valid) */
        UINT32 Ready        : 1;        /**< application ready starts/stops data reading */
        UINT32 Range        : 2;        /**< Measurement ranges (0 - 3) */
        UINT32 AngleOffset  : 9;        /**< Angle offset setting possible range 0-359?*/

                                        /* internal firmware specific control/mode bits */
        UINT16 TestRead     : 1;        /**< reads data also if no data valid bit is set */
        UINT16 IntAckOnErr  : 1;        /**< set interrupt acknowledge signal on comm error */
        UINT16 IntAckOnly   : 1;        /**< set interrupt acknowledge signal, no control word */
        UINT16 Reserve      : 12;       /**< reserved for future use */
        UINT16 NoLogError   : 1;        /**< suppress log error entries if function fails */
    } Bits;                             /**< Control-Mode register bit access */
    UINT32  Reg;                /**< Control-Mode register 32-Bit word access */
} MIO_IOP_CONTMODE;

/**
 * IOP201 measurement data struct definition
 */
typedef struct
{
    UINT32  CycleCount;         /**< Data read cycle count for consistency check */
    UINT16  ControlReg;         /**< Control reg write to IOP before data reading */
    UINT16  StatusReg;          /**< Status reg read back immediately */
    UINT32  CycleTime;          /**< Cycle time in uS since last zero point crossover */
    UINT16  Data[360 * 16];     /**< Measurement data for all possible channels */
} MIO_IOP_DATA;

/**
 * AP211 get/set hysteresis
 */
typedef struct mio_hysteresis
{
    SINT32  Rise;               /**< Hysteresis rise value */
    SINT32  Fall;               /**< Hysteresis fall value */
} MIO_HYSTERESIS;

/**
 * AP211 get/set cycle configuration
 */
typedef struct mio_ap_cyclecfg
{
    SINT32  IgnHigh;            /**< Firing pulse */
    SINT32  IgnLow;             /**< Firing pulse */
    SINT32  OpHigh;             /**< Pulse pattern */
    SINT32  OpLow;              /**< Pulse pattern */
    UINT32  Count;              /**< Pulse pattern duration */
} MIO_AP_CYCLECFG;

typedef struct mio_ap_count
{
    UINT32  MicroWavePower;
    UINT32  Optical;
} MIO_AP_COUNT;

typedef struct
{
    UINT32  RxPwrWarn;          /**< Upper threshold for Warning in % */
    UINT32  RxPwrError;         /**< Lower threshold for Error in % */
} MIO_FO_THRESHOLD;

/**
 * Min-max data structure
 */
typedef struct mio_minmax
{
    SINT32  Min;                /**< Minimum value */
    SINT32  Max;                /**< Maximum value */
} MIO_MINMAX;

/** @} */
#endif                                  /* _ASMLANGUAGE */
/** @} */

#ifdef __cplusplus
}
#endif

#endif
