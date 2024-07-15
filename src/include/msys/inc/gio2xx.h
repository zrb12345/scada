/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     gio2xx.h
* @author   Jochum
* @brief    Interface description for the modules GIO212, AIO208 and AIO216
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef GIO2XX__H
#define GIO2XX__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @addtogroup GIO2XX_DEF
 * @{
 */

/**
 * @name Module modes
 * @{
 */

/**
 * @brief Run mode, process data and state update.
 *
 * The module performs cyclic update of process values, module and channel state.
 */
#define MIO_M_GIORUN    0x00000001
/**
 * @brief Stop mode, no process data or state update.
 *
 * Write to output channels will not be transmitted until the mode of the
 * module is set back to #MIO_M_GIORUN using mio_SetCardMode().
 *
 * @attention Do not relay on input values after changing a channel
 *            mode using mio_SetChanMode() in #MIO_M_GIOSTOP mode. You need
 *            to switch back to #MIO_M_GIORUN before using any value.
 */
#define MIO_M_GIOSTOP   0x00000002
/** @} */

/**
 * @name Specific modes (internal use only)
 * @{
 */

#define MIO_M_GIOSPECDOPUSHPULL         0x00000001   /**< Digital output push pull */
#define MIO_M_GIOSPECDOIOLINK           0x00000002   /**< IO-Link (set only per configuration) */
#define MIO_M_GIOSPECDOLOWSIDE          0x00000003   /**< Digital output low-side driver */
#define MIO_M_GIOSPECDOHIGHSIDE         0x00000004   /**< Digital output high-side driver */
#define MIO_M_GIOSPECVI_10V             0x00000001   /**< Voltage input -10V..10V */
#define MIO_M_GIOSPECVI_1V              0x00000002   /**< Voltage input -1V..1V */
#define MIO_M_GIOSPECVI_100mV           0x00000003   /**< Voltage input -100mV..100mV */
#define MIO_M_GIOSPECVI_10mV            0x00000004   /**< Voltage input -10mV..10mV */
#define MIO_M_GIOSPECVIRANGE1           0x00000005   /**< Voltage input -17.5mV..87.5mV */
#define MIO_M_GIOSPECVIRANGE2           0x00000006   /**< Voltage input -4.375mV..21.875mV */
#define MIO_M_GIOSPECVO                 0x00000001   /**< Voltage output */
#define MIO_M_GIOSPECVOEXT              0x00000002   /**< Extended voltage output (supply for sensors) */
#define MIO_M_GIOSPECCI_20mA            0x00000001   /**< Current input -20mA..20mA */
#define MIO_M_GIOSPECCI_4_20mA          0x00000002   /**< Current input 4mA..20mA */
#define MIO_M_GIOSPECCI_0_20mA          0x00000003   /**< Current input 0mA..20mA */
#define MIO_M_GIOSPECCO_0_20mA          0x00000001   /**< Current output 0mA..20mA */
#define MIO_M_GIOSPECCO_4_20mA          0x00000002   /**< Current output 4mA..20mA */
#define MIO_M_GIOSPECCO_0_2mA           0x00000003   /**< Current output 0mA..2mA */
#define MIO_M_GIOSPECCO_0_200uA         0x00000004   /**< Current output 0uA..200uA */
#define MIO_M_GIOSPECCNTEDGE            0x00000001   /**< Counter - Edge */
#define MIO_M_GIOSPECCNTTIMEPERIOD      0x00000002   /**< Counter - Time period */
#define MIO_M_GIOSPECCNTTIMEPULSE       0x00000003   /**< Counter - Time pulse */
#define MIO_M_GIOSPECCNTDUALEDGETRIG    0x00000001   /**< Dual counter - With trigger */
#define MIO_M_GIOSPECCNTDUALEDGERESET   0x00000002   /**< Dual counter - With reset */
#define MIO_M_GIOSPECCNTDUALEDGEGATE    0x00000003   /**< Dual counter - With gate */
#define MIO_M_GIOSPECCNTDUALEDGEDIR     0x00000004   /**< Dual counter - With direction control */
#define MIO_M_GIOSPECCNTDUALEDGETIME    0x00000005   /**< Dual counter - Time between pulses */
#define MIO_M_GIOSPECINC_1              0x00000001   /**< Dual counter - Increment single */
#define MIO_M_GIOSPECINC_2              0x00000002   /**< Dual counter - Increment dual */
#define MIO_M_GIOSPECINC_4              0x00000003   /**< Dual counter - Increment quat */
#define MIO_M_GIOSPECTEMO_J             0x00000001   /**< Thermo element type J */
#define MIO_M_GIOSPECTEMO_K             0x00000002   /**< Thermo element type K */
#define MIO_M_GIOSPECTEMO_T             0x00000003   /**< Thermo element type T */
#define MIO_M_GIOSPECTEMO_N             0x00000004   /**< Thermo element type N */
#define MIO_M_GIOSPECTEMO_E             0x00000005   /**< Thermo element type E */
#define MIO_M_GIOSPECTEMO_R             0x00000006   /**< Thermo element type R */
#define MIO_M_GIOSPECTEMO_S             0x00000007   /**< Thermo element type S */
#define MIO_M_GIOSPECTEMO_B             0x00000008   /**< Thermo element type B */
#define MIO_M_GIOSPECPT100_2            0x00000001   /**< Temperature sensor of type PT100 - 2 wire */
#define MIO_M_GIOSPECPT100_3            0x00000002   /**< Temperature sensor of type PT100 - 3 wire */
#define MIO_M_GIOSPECPT100_4            0x00000003   /**< Temperature sensor of type PT100 - 4 wire */
#define MIO_M_GIOSPECPT200_2            0x00000004   /**< Temperature sensor of type PT200 - 2 wire */
#define MIO_M_GIOSPECPT200_3            0x00000005   /**< Temperature sensor of type PT200 - 3 wire */
#define MIO_M_GIOSPECPT200_4            0x00000006   /**< Temperature sensor of type PT200 - 4 wire */
#define MIO_M_GIOSPECPT500_2            0x00000007   /**< Temperature sensor of type PT500 - 2 wire */
#define MIO_M_GIOSPECPT500_3            0x00000008   /**< Temperature sensor of type PT500 - 3 wire */
#define MIO_M_GIOSPECPT500_4            0x00000009   /**< Temperature sensor of type PT500 - 4 wire */
#define MIO_M_GIOSPECPT1000_2           0x0000000a   /**< Temperature sensor of type PT1000 - 2 wire */
#define MIO_M_GIOSPECPT1000_3           0x0000000b   /**< Temperature sensor of type PT1000 - 3 wire */
#define MIO_M_GIOSPECPT1000_4           0x0000000c   /**< Temperature sensor of type PT1000 - 4 wire */
#define MIO_M_GIOSPECMODES              0x0000000f   /**< Special modes */
/** @} */

/**
 * @name Base modes (internal use only)
 * @{
 */

#define MIO_M_GIOBASEDISABLED       0x00000000   /**< Disabled */
#define MIO_M_GIOBASEDIGINPUT       0x00000010   /**< Digital input */
#define MIO_M_GIOBASEDIGOUTPUT      0x00000020   /**< Digital output */
#define MIO_M_GIOBASEVOLTAGEIN      0x00000030   /**< Voltage input */
#define MIO_M_GIOBASEVOLTAGEOUT     0x00000040   /**< Voltage output */
#define MIO_M_GIOBASECURRENTIN      0x00000050   /**< Current input */
#define MIO_M_GIOBASECURRENTOUT     0x00000060   /**< Current output */
#define MIO_M_GIOBASEPWM            0x00000070   /**< Pulse with modulation */
#define MIO_M_GIOBASEPWMDUAL        0x00000080   /**< Pulse with modulation with two channels */
#define MIO_M_GIOBASECOUNTER        0x00000090   /**< Counter */
#define MIO_M_GIOBASECOUNTERCONTROL 0x000000a0   /**< Dual counter */
#define MIO_M_GIOBASEINC            0x000000b0   /**< Dual counter */
#define MIO_M_GIOBASETHERMELEMENT   0x000000c0   /**< Thermo element */
#define MIO_M_GIOBASETEMPSENS       0x000000d0   /**< Temperature sensor */
#define MIO_M_GIOBASEIOLINK         0x000000e0   /**< IO Link */
#define MIO_M_GIOBASEDIGOUTDUAL     0x000000f0   /**< Linked digital out */
#define MIO_M_GIOBASEFREQUENCY      0x00000110   /**< Frequency modulation */
#define MIO_M_GIOBASEMODES          0x000001f0   /**< Base modes */
/** @} */

/**
 * @name Specific modes for digital inputs and counters
 * @{
 */

#define MIO_M_GIOSPECDITYPE3    0x00000000   /**< Digital input type 3 */
#define MIO_M_GIOSPECDITYPE2    0x00000200   /**< Digital input type 2 */
#define MIO_M_GIOSPECDITYPE1    0x00000400   /**< Digital input type 1 */
#define MIO_M_GIOSPECDISOURCE   0x00000600   /**< Digital input type source */
#define MIO_M_GIOSPECDICMP      0x00000800   /**< Digital input type comparator */
#define MIO_M_GIOSPECDIMODES    0x00000e00   /**< Special modes for digital inputs */
/** @} */

/**
 * @name Global channel modes
 * @{
 */

#define MIO_M_GIODISABLED           (MIO_M_GIOBASEDISABLED)  /**< Channel is disabled */
#define MIO_M_GIODISOURCE           (MIO_M_GIOBASEDIGINPUT | MIO_M_GIOSPECDISOURCE)  /**< Digital input pull-up */
#define MIO_M_GIODITYPE1            (MIO_M_GIOBASEDIGINPUT | MIO_M_GIOSPECDITYPE1)   /**< Digital input type 1 */
#define MIO_M_GIODITYPE2            (MIO_M_GIOBASEDIGINPUT | MIO_M_GIOSPECDITYPE2)   /**< Digital input type 2 */
#define MIO_M_GIODITYPE3            (MIO_M_GIOBASEDIGINPUT | MIO_M_GIOSPECDITYPE3)   /**< Digital input type 3 */
#define MIO_M_GIODITYPECMP          (MIO_M_GIOBASEDIGINPUT | MIO_M_GIOSPECDICMP)     /**< Digital input type comparator */
#define MIO_M_GIODOPUSHPULL         (MIO_M_GIOBASEDIGOUTPUT | MIO_M_GIOSPECDOPUSHPULL)   /**< Digital output push pull */
#define MIO_M_GIODOIOLINK           (MIO_M_GIOBASEDIGOUTPUT | MIO_M_GIOSPECDOIOLINK)     /**< IO-Link (set only per configuration) */
#define MIO_M_GIODOLOWSIDE          (MIO_M_GIOBASEDIGOUTPUT | MIO_M_GIOSPECDOLOWSIDE)    /**< Digital output low-side driver */
#define MIO_M_GIODOHIGHSIDE         (MIO_M_GIOBASEDIGOUTPUT | MIO_M_GIOSPECDOHIGHSIDE)   /**< Digital output high-side driver */
#define MIO_M_GIOVI_10V             (MIO_M_GIOBASEVOLTAGEIN | MIO_M_GIOSPECVI_10V)   /**< Voltage input -10V..10V */
#define MIO_M_GIOVI_1V              (MIO_M_GIOBASEVOLTAGEIN | MIO_M_GIOSPECVI_1V)    /**< Voltage input -1V..1V */
#define MIO_M_GIOVI_100mV           (MIO_M_GIOBASEVOLTAGEIN | MIO_M_GIOSPECVI_100mV)     /**< Voltage input -100mV..100mV */
#define MIO_M_GIOVI_10mV            (MIO_M_GIOBASEVOLTAGEIN | MIO_M_GIOSPECVI_10mV)  /**< Voltage input -10mV..10mV */
#define MIO_M_GIOVIRANGE1           (MIO_M_GIOBASEVOLTAGEIN | MIO_M_GIOSPECVIRANGE1)     /**< Voltage input -17.5mV..87.5mV */
#define MIO_M_GIOVIRANGE2           (MIO_M_GIOBASEVOLTAGEIN | MIO_M_GIOSPECVIRANGE2)     /**< Voltage input -4.375mV..21.875mV */
#define MIO_M_GIOVO                 (MIO_M_GIOBASEVOLTAGEOUT | MIO_M_GIOSPECVO)  /**< Voltage output -10V..10V */
#define MIO_M_GIOVOEXT              (MIO_M_GIOBASEVOLTAGEOUT | MIO_M_GIOSPECVOEXT)   /**< Extended voltage output (supply for sensors) */
#define MIO_M_GIOCI_20mA            (MIO_M_GIOBASECURRENTIN | MIO_M_GIOSPECCI_20mA)  /**< Current input -20mA..20mA */
#define MIO_M_GIOCI_4_20mA          (MIO_M_GIOBASECURRENTIN | MIO_M_GIOSPECCI_4_20mA)    /**< Current input 4mA..20mA */
#define MIO_M_GIOCI_0_20mA          (MIO_M_GIOBASECURRENTIN | MIO_M_GIOSPECCI_0_20mA)    /**< Current input 0mA..20mA */
#define MIO_M_GIOCO_0_20mA          (MIO_M_GIOBASECURRENTOUT | MIO_M_GIOSPECCO_0_20mA)   /**< Current output 0mA..20mA */
#define MIO_M_GIOCO_4_20mA          (MIO_M_GIOBASECURRENTOUT | MIO_M_GIOSPECCO_4_20mA)   /**< Current output 4mA..20mA */
#define MIO_M_GIOCO_0_2mA           (MIO_M_GIOBASECURRENTOUT | MIO_M_GIOSPECCO_0_2mA)    /**< Current output 0mA..2mA */
#define MIO_M_GIOCO_0_200uA         (MIO_M_GIOBASECURRENTOUT | MIO_M_GIOSPECCO_0_200uA)  /**< Current output 0uA..200uA */
#define MIO_M_GIOCNTEDGE            (MIO_M_GIOBASECOUNTER | MIO_M_GIOSPECCNTEDGE)    /**< Counter - Edge */
#define MIO_M_GIOCNTTIMEPERIOD      (MIO_M_GIOBASECOUNTER | MIO_M_GIOSPECCNTTIMEPERIOD)  /**< Counter - Time period */
#define MIO_M_GIOCNTTIMEPULSE       (MIO_M_GIOBASECOUNTER | MIO_M_GIOSPECCNTTIMEPULSE)   /**< Counter - Time pulse */
#define MIO_M_GIOCNTDUALEDGETRIG    (MIO_M_GIOBASECOUNTERCONTROL | MIO_M_GIOSPECCNTDUALEDGETRIG)     /**< Pulse counter with trigger */
#define MIO_M_GIOCNTDUALEDGERESET   (MIO_M_GIOBASECOUNTERCONTROL | MIO_M_GIOSPECCNTDUALEDGERESET)    /**< Pulse counter with reset */
#define MIO_M_GIOCNTDUALEDGEGATE    (MIO_M_GIOBASECOUNTERCONTROL | MIO_M_GIOSPECCNTDUALEDGEGATE)     /**< Pulse counter with gate */
#define MIO_M_GIOCNTDUALEDGEDIR     (MIO_M_GIOBASECOUNTERCONTROL | MIO_M_GIOSPECCNTDUALEDGEDIR)  /**< Pulse counter with directional switch-over */
#define MIO_M_GIOCNTDUALEDGETIME    (MIO_M_GIOBASECOUNTERCONTROL | MIO_M_GIOSPECCNTDUALEDGETIME)
#define MIO_M_GIOCNTINC_1           (MIO_M_GIOBASEINC | MIO_M_GIOSPECINC_1)  /**< Incremental rotary encoder 1-fold */
#define MIO_M_GIOCNTINC_2           (MIO_M_GIOBASEINC | MIO_M_GIOSPECINC_2)  /**< Incremental rotary encoder 2-fold */
#define MIO_M_GIOCNTINC_4           (MIO_M_GIOBASEINC | MIO_M_GIOSPECINC_4)  /**< Incremental rotary encoder 4-fold */
#define MIO_M_GIOPWMPUSHPULL        (MIO_M_GIOBASEPWM | MIO_M_GIOSPECDOPUSHPULL)     /**< Pulse width modulation - push pull */
#define MIO_M_GIOPWMLOWSIDE         (MIO_M_GIOBASEPWM | MIO_M_GIOSPECDOLOWSIDE)  /**< Pulse width modulation - low-side driver */
#define MIO_M_GIOPWMHIGHSIDE        (MIO_M_GIOBASEPWM | MIO_M_GIOSPECDOHIGHSIDE)     /**< Pulse width modulation - high-side driver */
#define MIO_M_GIOPWMDUALPUSHPULL    (MIO_M_GIOBASEPWMDUAL | MIO_M_GIOSPECDOPUSHPULL)     /**< Pulse width modulation with second channel - push pull */
#define MIO_M_GIOPWMDUALLOWSIDE     (MIO_M_GIOBASEPWMDUAL | MIO_M_GIOSPECDOLOWSIDE)  /**< Pulse width modulation with second channel - low-side driver */
#define MIO_M_GIOPWMDUALHIGHSIDE    (MIO_M_GIOBASEPWMDUAL | MIO_M_GIOSPECDOHIGHSIDE)     /**< Pulse width modulation with second channel - high-side driver */
#define MIO_M_GIOTEMOELEM_J         (MIO_M_GIOBASETHERMELEMENT | MIO_M_GIOSPECTEMO_J)    /**< Thermo element type J */
#define MIO_M_GIOTEMOELEM_K         (MIO_M_GIOBASETHERMELEMENT | MIO_M_GIOSPECTEMO_K)    /**< Thermo element type K */
#define MIO_M_GIOTEMOELEM_T         (MIO_M_GIOBASETHERMELEMENT | MIO_M_GIOSPECTEMO_T)    /**< Thermo element type T */
#define MIO_M_GIOTEMOELEM_N         (MIO_M_GIOBASETHERMELEMENT | MIO_M_GIOSPECTEMO_N)    /**< Thermo element type N */
#define MIO_M_GIOTEMOELEM_E         (MIO_M_GIOBASETHERMELEMENT | MIO_M_GIOSPECTEMO_E)    /**< Thermo element type E */
#define MIO_M_GIOTEMOELEM_R         (MIO_M_GIOBASETHERMELEMENT | MIO_M_GIOSPECTEMO_R)    /**< Thermo element type R */
#define MIO_M_GIOTEMOELEM_S         (MIO_M_GIOBASETHERMELEMENT | MIO_M_GIOSPECTEMO_S)    /**< Thermo element type S */
#define MIO_M_GIOTEMOELEM_B         (MIO_M_GIOBASETHERMELEMENT | MIO_M_GIOSPECTEMO_B)    /**< Thermo element type B */
#define MIO_M_GIOPT100_2            (MIO_M_GIOBASETEMPSENS | MIO_M_GIOSPECPT100_2)   /**< Temperature sensor of type PT100 - 2 wire */
#define MIO_M_GIOPT100_3            (MIO_M_GIOBASETEMPSENS | MIO_M_GIOSPECPT100_3)   /**< Temperature sensor of type PT100 - 3 wire */
#define MIO_M_GIOPT100_4            (MIO_M_GIOBASETEMPSENS | MIO_M_GIOSPECPT100_4)   /**< Temperature sensor of type PT100 - 4 wire */
#define MIO_M_GIOPT200_2            (MIO_M_GIOBASETEMPSENS | MIO_M_GIOSPECPT200_2)   /**< Temperature sensor of type PT200 - 2 wire */
#define MIO_M_GIOPT200_3            (MIO_M_GIOBASETEMPSENS | MIO_M_GIOSPECPT200_3)   /**< Temperature sensor of type PT200 - 3 wire */
#define MIO_M_GIOPT200_4            (MIO_M_GIOBASETEMPSENS | MIO_M_GIOSPECPT200_4)   /**< Temperature sensor of type PT200 - 4 wire */
#define MIO_M_GIOPT500_2            (MIO_M_GIOBASETEMPSENS | MIO_M_GIOSPECPT500_2)   /**< Temperature sensor of type PT500 - 2 wire */
#define MIO_M_GIOPT500_3            (MIO_M_GIOBASETEMPSENS | MIO_M_GIOSPECPT500_3)   /**< Temperature sensor of type PT500 - 3 wire */
#define MIO_M_GIOPT500_4            (MIO_M_GIOBASETEMPSENS | MIO_M_GIOSPECPT500_4)   /**< Temperature sensor of type PT500 - 4 wire */
#define MIO_M_GIOPT1000_2           (MIO_M_GIOBASETEMPSENS | MIO_M_GIOSPECPT1000_2)  /**< Temperature sensor of type PT1000 - 2 wire */
#define MIO_M_GIOPT1000_3           (MIO_M_GIOBASETEMPSENS | MIO_M_GIOSPECPT1000_3)  /**< Temperature sensor of type PT1000 - 3 wire */
#define MIO_M_GIOPT1000_4           (MIO_M_GIOBASETEMPSENS | MIO_M_GIOSPECPT1000_4)  /**< Temperature sensor of type PT1000 - 4 wire */
#define MIO_M_GIOIOLINK             (MIO_M_GIOBASEIOLINK)    /**< IO Link */
#define MIO_M_GIODODUALPUSHPULL     (MIO_M_GIOBASEDIGOUTDUAL | MIO_M_GIOSPECDOPUSHPULL)  /**< Digital output with second channel - push pull */
#define MIO_M_GIODODUALLOWSIDE      (MIO_M_GIOBASEDIGOUTDUAL | MIO_M_GIOSPECDOLOWSIDE)   /**< Digital output with second channel - low-side driver */
#define MIO_M_GIODODUALHIGHSIDE     (MIO_M_GIOBASEDIGOUTDUAL | MIO_M_GIOSPECDOHIGHSIDE)  /**< Digital output with second channel - high-side driver */
#define MIO_M_GIOFRQHIGHSIDE        (MIO_M_GIOBASEFREQUENCY | MIO_M_GIOSPECDOHIGHSIDE)   /**< Frequency modulation push pull */
#define MIO_M_GIOFRQPUSHPULL        (MIO_M_GIOBASEFREQUENCY | MIO_M_GIOSPECDOPUSHPULL)   /**< Frequency modulation low side */
#define MIO_M_GIOFRQLOWSIDE         (MIO_M_GIOBASEFREQUENCY | MIO_M_GIOSPECDOLOWSIDE)    /**< Frequency modulation high side */
/** @} */

/**
 * @name Additional channel modes invert
 * @{
 */

#define MIO_M_GIOINVERT 0x00001000   /**< Invert the value */
/** @} */

/**
 * @name Combined channel modes
 * @{
 */

#define MIO_M_GIOPUSHPULL   0x00000000   /**< Inverted signal at combined outputs */
#define MIO_M_GIOPUSHPUSH   0x00002000   /**< Same output signal at combined channels */
/** @} */

/**
 * @name Additional channel modes - digital
 * @{
 */

#define MIO_M_GIOFAST       0x00004000   /**< Inputs/Outputs: use fast input/output */
#define MIO_M_GIODOPULSE    0x00008000   /**< Output only: use PWM to reduce output current */
/** @} */

/**
 * @name Additional channel modes - edge counter
 * @{
 */

#define MIO_M_GIOCNTUP              0x00000000   /**< Count up */
#define MIO_M_GIOCNTDOWN            0x00010000   /**< Count down */
#define MIO_M_GIOPOSEDGE            0x00020000   /**< Count rising edges */
#define MIO_M_GIONEGEDGE            0x00040000   /**< Count falling edges */
#define MIO_M_GIOBOTHEDGES          (MIO_M_GIOPOSEDGE | MIO_M_GIONEGEDGE)    /**< Count both edges */
#define MIO_M_GIORESETATREFERENCE   0x00080000   /**< Reset at reference */
/** @} */

/**
 * @name Additional channel modes - PWM
 * @{
 */

#define MIO_M_GIOPWMNOTLOCKED   0x00000000   /**< Simple PWM (not in locked antiphase mode) */
#define MIO_M_GIOPWMLOCKED      0x00100000   /**< PWM in locked antiphase mode */
/** @} */

/**
 * @name Additional channel modes - Thermo couples
 * @{
 */

#define MIO_M_GIOGROUNDED   0x00400000   /**< Use grounded junction probe */
/** @} */

/**
 * @name Special mode for CAN
 * @{
 */

#define MIO_M_GIOCANCONFIG  0x80000000   /**< Stop card before setting channel mode and start card again - only for CAN! */
/** @} */

/**
 * @name Additional channel modes - General
 * @{
 */

#define MIO_M_GIOSYNC       0x00200000   /**< Use Sync for channel */
#define MIO_M_GIOLIMITERROR 0x00800000   /**< Use limits as error */
#define MIO_M_GIOFIFO       0x01000000   /**< Use FIFO for measurement */
#define MIO_M_GIOFREQUENCY  0x02000000   /**< Frequency modulation */
#define MIO_M_GIOPULSE      0x04000000   /**< Pulse modulation */
/** @} */

/**
 * @name Analog input filter frequencies
 * @{
 */

#define MIO_GIO_AIFILTER_4kHz   0x0  /**< Filter Frequency 4kHz */
#define MIO_GIO_AIFILTER_2kHz   0x1  /**< Filter Frequency 2kHz */
#define MIO_GIO_AIFILTER_1kHz   0x2  /**< Filter Frequency 1kHz */
#define MIO_GIO_AIFILTER_500Hz  0x3  /**< Filter Frequency 500Hz */
#define MIO_GIO_AIFILTER_250Hz  0x4  /**< Filter Frequency 250Hz */
#define MIO_GIO_AIFILTER_125Hz  0x5  /**< Filter Frequency 125Hz */
#define MIO_GIO_AIFILTER_62_5Hz 0x6  /**< Filter Frequency 62.5Hz */
#define MIO_GIO_AIFILTER_31_2Hz 0x7  /**< Filter Frequency 31.2Hz */
#define MIO_GIO_AIFILTER_15_6Hz 0x8  /**< Filter Frequency 15.6Hz */
#define MIO_GIO_AIFILTER_7_8Hz  0x9  /**< Filter Frequency 7.8Hz */
#define MIO_GIO_AIFILTER_3_9Hz  0xa  /**< Filter Frequency 3.9Hz */
#define MIO_GIO_AIFILTER_1_9Hz  0xb  /**< Filter Frequency 1.9Hz */
#define MIO_GIO_AIFILTER_0_97Hz 0xc  /**< Filter Frequency 0.97Hz */
#define MIO_GIO_AIFILTER_0_50Hz 0xd  /**< Filter Frequency 0.50Hz */
/** @} */

/**
 * @name Possible spike filter values
 * @{
 */

#define MIO_GIO_SPIKEFILTER_OFF     0x0  /**< Spike filter OFF */
#define MIO_GIO_SPIKEFILTER_16us    0x1  /**< Spike filter 16us */
#define MIO_GIO_SPIKEFILTER_32us    0x2  /**< Spike filter 32us */
#define MIO_GIO_SPIKEFILTER_64us    0x3  /**< Spike filter 64us */
#define MIO_GIO_SPIKEFILTER_128us   0x4  /**< Spike filter 128us */
#define MIO_GIO_SPIKEFILTER_256us   0x5  /**< Spike filter 256us */
#define MIO_GIO_SPIKEFILTER_512us   0x6  /**< Spike filter 512us */
#define MIO_GIO_SPIKEFILTER_1ms     0x7  /**< Spike filter 1ms */
#define MIO_GIO_SPIKEFILTER_2ms     0x8  /**< Spike filter 2ms */
#define MIO_GIO_SPIKEFILTER_4ms     0x9  /**< Spike filter 4ms */
#define MIO_GIO_SPIKEFILTER_8ms     0xa  /**< Spike filter 8ms */
#define MIO_GIO_SPIKEFILTER_16ms    0xb  /**< Spike filter 16ms */
#define MIO_GIO_SPIKEFILTER_32ms    0xc  /**< Spike filter 32ms */
#define MIO_GIO_SPIKEFILTER_65ms    0xd  /**< Spike filter 65ms */
#define MIO_GIO_SPIKEFILTER_131ms   0xe  /**< Spike filter 131ms */
#define MIO_GIO_SPIKEFILTER_262ms   0xf  /**< Spike filter 262ms */
/** @} */

/**
 * @name Structures
 * @{
 */

/**
 * Structure for PWM settings
 */
typedef struct
{
    SINT32  Period;             /**< Period length in us */
    SINT32  PulseWidth;         /**< Pulse width (0% - 100% -> 0 - 65535) */
    SINT32  StartPulse;         /**< Start pulse time in us */
} GIO_DOPULSETIME;

/**
 * Structure for frequency FIFO mode
 * @since V3.03.00 Beta
 */
typedef struct
{
    UINT32  Period;             /**< Pulse period in ns */
    UINT32  PulseCount;         /**< Pulse counter */
} GIO_FIFOITEM;

/** @} */
/** @} */
#if M_OS_VXWORKS


/*
 * This part contains all abstract do commands of GIO2XX
 * @generated
 */
#include <mio_e.h>

/**
 * @ingroup GIO2XX_DoCmds
 * @def MIO_CMD_GIOGETNBRFIFOENTRIES
 * @code{.c} SINT32 mio_DoCmd(MIO_DRV *DrvId, UINT32 Chan, UINT32 Cmd, UINT32 *pNbEntries) @endcode
 *
 * @param[in]  DrvId            Module instance handle returned by the function mio_GetDrv().
 * @param[in]  Chan             Channel
 * @param[in]  Cmd              #MIO_CMD_GIOGETNBRFIFOENTRIES
 * @param[out] pNbEntries       Total number of FIFO nbEntries. Maximal FIFO depth is 1024.
 *
 * @retval #MIO_ER_OK OK
 * @retval other      Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
 *
 * @see #MIO_CMD_GIOADDFIFOENTRY
 * @see #MIO_CMD_GIOSTARTSTOPFIFO
 * @since V3.03.00 Beta
 */
static inline SINT32 gio2xx_GetNbrOfFifoEntries(void *DrvId, UINT32 Chan, UINT32  *nbEntries)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GIOGETNBRFIFOENTRIES, nbEntries);
	return (retValue);
}


/**
 * @ingroup GIO2XX_DoCmds
 * @def MIO_CMD_GIOGETFIFOVALUES
 * @code{.c} SINT32 mio_DoCmd(MIO_DRV *DrvId, UINT32 Chan, UINT32 Cmd, UINT32 nbEntries, UINT32 *nbrOfActEntries, UINT32 *Values) @endcode
 *
 * @param[in]  DrvId            Module instance handle returned by the function mio_GetDrv().
 * @param[in]  Chan             Channel
 * @param[in]  Cmd              #MIO_CMD_GIOGETFIFOVALUES
 * @param[in]  nbEntries        Number of requested items to return (number of elements in the array Values)
 * @param[out] nbrOfActEntries  Total number of read entries from FIFO
 * @param[out] Values[]         Returns the values in an given array of size nbEntries
 *
 * @retval #MIO_ER_OK OK
 * @retval other      Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
 * @since V3.03.00 Beta
 */
static inline SINT32 gio2xx_GetValuesFromFifo(void *DrvId, UINT32 Chan, UINT32 nbEntries, UINT32  *nbrOfActEntries, UINT32  *Values)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GIOGETFIFOVALUES, nbEntries, nbrOfActEntries, Values);
	return (retValue);
}


/**
 * @ingroup GIO2XX_DoCmds
 * @def MIO_CMD_GIOGETFIFOOVERFLOW
 * @code{.c} SINT32 mio_DoCmd(MIO_DRV *DrvId, UINT32 Chan, UINT32 Cmd, UINT32 *pNbOfOverflows) @endcode
 *
 * Reads the number of FIFO overflows. Reading the value also resets the counter
 * value at the same time.
 *
 * @param[in]  DrvId            Module instance handle returned by the function mio_GetDrv().
 * @param[in]  Chan             Channel
 * @param[in]  Cmd              #MIO_CMD_GIOGETFIFOOVERFLOW
 * @param[out] pNbOfOverflows   Number of values which couldn't be stored in FIFO
 *
 * @retval #MIO_ER_OK OK
 * @retval other      Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
 * @since V3.03.00 Beta
 */
static inline SINT32 gio2xx_GetFifoOverflow(void *DrvId, UINT32 Chan, UINT32  *nbrOfOverflows)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GIOGETFIFOOVERFLOW, nbrOfOverflows);
	return (retValue);
}


/**
 * @ingroup GIO2XX_DoCmds
 * @def MIO_CMD_GIOFIFOFLUSH
 * @code{.c} SINT32 mio_DoCmd(MIO_DRV *DrvId, UINT32 Chan, UINT32 Cmd) @endcode
 *
 * @param[in]  DrvId            Module instance handle returned by the function mio_GetDrv().
 * @param[in]  Chan             Channel
 * @param[in]  Cmd              #MIO_CMD_GIOFIFOFLUSH
 *
 * @retval #MIO_ER_OK OK
 * @retval other      Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
 * @since V3.03.00 Beta
 */
static inline SINT32 gio2xx_FifoFlush(void *DrvId, UINT32 Chan)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GIOFIFOFLUSH);
	return (retValue);
}


/**
 * @ingroup GIO2XX_DoCmds
 * @def MIO_CMD_GIOFIFOREFVALUE
 * @code{.c} SINT32 mio_DoCmd(MIO_DRV *DrvId, UINT32 Chan, UINT32 Cmd, SINT32 *pFifoRefValue) @endcode
 *
 * @param[in]  DrvId            Module instance handle returned by the function mio_GetDrv().
 * @param[in]  Chan             Channel
 * @param[in]  Cmd              #MIO_CMD_GIOFIFOREFVALUE
 * @param[out] pFifoRefValue    FIFO reference value
 *
 * @retval #MIO_ER_OK OK
 * @retval other      Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
 * @since V3.03.00 Beta
 */
static inline SINT32 gio2xx_GetFifoReferenceValue(void *DrvId, UINT32 Chan, SINT32  *FifoRefValue)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GIOFIFOREFVALUE, FifoRefValue);
	return (retValue);
}


/**
 * @ingroup GIO2XX_DoCmds
 * @def MIO_CMD_GIOSTARTSTOPFIFO
 * @code{.c} SINT32 mio_DoCmd(MIO_DRV *DrvId, UINT32 Chan, UINT32 Cmd, BOOL32 Start) @endcode
 *
 * In frequency pulse count mode the start command writes 0xffffffff (infinite counts) as pulse count value
 * and the output starts to pulse with the given frequency.
 *
 * @param[in]  DrvId            Module instance handle returned by the function mio_GetDrv().
 * @param[in]  Chan             Channel
 * @param[in]  Cmd              #MIO_CMD_GIOSTARTSTOPFIFO
 * @param[in]  Start            Starts = TRUE/stops = FALSE the FIFO
 *
 * @retval #MIO_ER_OK OK
 * @retval other      Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
 *
 * @see #MIO_CMD_GIOADDFIFOENTRY
 * @see #MIO_CMD_GIOGETFIFOVALUES
 * @since V3.03.00 Beta
 */
static inline SINT32 gio2xx_StartStopFifo(void *DrvId, UINT32 Chan, BOOL32 Start)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GIOSTARTSTOPFIFO, Start);
	return (retValue);
}


/**
 * @ingroup GIO2XX_DoCmds
 * @def MIO_CMD_GIOSETPULSECOUNT
 * @code{.c} SINT32 mio_DoCmd(MIO_DRV *DrvId, UINT32 Chan, UINT32 Cmd, UINT32 PulseCount) @endcode
 *
 * @param[in]  DrvId            Module instance handle returned by the function mio_GetDrv().
 * @param[in]  Chan             Channel
 * @param[in]  Cmd              #MIO_CMD_GIOSETPULSECOUNT
 * @param[in]  PulseCount       Pulse counter, 0 no pulse is generated<br>
 *                              0xffffffff endless pulse generation
 *
 * @retval #MIO_ER_OK OK
 * @retval other      Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
 * @since V3.03.00 Beta
 */
static inline SINT32 gio2xx_SetPulseCount(void *DrvId, UINT32 Chan, UINT32 PulseCount)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GIOSETPULSECOUNT, PulseCount);
	return (retValue);
}


/**
 * @ingroup GIO2XX_DoCmds
 * @def MIO_CMD_GIOGETPULSECOUNT
 * @code{.c} SINT32 mio_DoCmd(MIO_DRV *DrvId, UINT32 Chan, UINT32 Cmd, UINT32 *PulseCount) @endcode
 *
 * @param[in]  DrvId            Module instance handle returned by the function mio_GetDrv().
 * @param[in]  Chan             Channel
 * @param[in]  Cmd              #MIO_CMD_GIOGETPULSECOUNT
 * @param[out] PulseCount       Pulse counter
 *
 * @retval #MIO_ER_OK OK
 * @retval other      Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
 * @since V3.03.00 Beta
 */
static inline SINT32 gio2xx_GetPulseCount(void *DrvId, UINT32 Chan, UINT32  *PulseCount)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GIOGETPULSECOUNT, PulseCount);
	return (retValue);
}


/**
 * @ingroup GIO2XX_DoCmds
 * @def MIO_CMD_GIOSETPERIOD
 * @code{.c} SINT32 mio_DoCmd(MIO_DRV *DrvId, UINT32 Chan, UINT32 Cmd, UINT32 Period) @endcode
 *
 * @param[in]  DrvId            Module instance handle returned by the function mio_GetDrv().
 * @param[in]  Chan             Channel
 * @param[in]  Cmd              #MIO_CMD_GIOSETPERIOD
 * @param[in]  Period           Pulse period in ns, 0 no pulse generation, minimum: 8000ns
 *
 * @retval #MIO_ER_OK OK
 * @retval other      Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
 * @since V3.03.00 Beta
 */
static inline SINT32 gio2xx_SetPulsePeriod(void *DrvId, UINT32 Chan, UINT32 Period)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GIOSETPERIOD, Period);
	return (retValue);
}


/**
 * @ingroup GIO2XX_DoCmds
 * @def MIO_CMD_GIOGETPERIOD
 * @code{.c} SINT32 mio_DoCmd(MIO_DRV *DrvId, UINT32 Chan, UINT32 Cmd, UINT32 *Period) @endcode
 *
 * @param[in]  DrvId            Module instance handle returned by the function mio_GetDrv().
 * @param[in]  Chan             Channel
 * @param[in]  Cmd              #MIO_CMD_GIOGETPERIOD
 * @param[out] Period           Pulse period in ns
 *
 * @retval #MIO_ER_OK OK
 * @retval other      Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
 * @since V3.03.00 Beta
 */
static inline SINT32 gio2xx_GetPulsePeriod(void *DrvId, UINT32 Chan, UINT32  *Period)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GIOGETPERIOD, Period);
	return (retValue);
}


/**
 * @ingroup GIO2XX_DoCmds
 * @def MIO_CMD_GIOADDFIFOENTRY
 * @code{.c} SINT32 mio_DoCmd(MIO_DRV *DrvId, UINT32 Chan, UINT32 Cmd, const GIO_FIFOITEM *pFifoItem) @endcode
 *
 * Adds a single FIFO entry. Frequency and corresponding pulse count
 * has to be set therefore. Because of the two values which are written into
 * the FIFO, the FIFO count increases by two with each #MIO_CMD_GIOADDFIFOENTRY call.
 *
 * @param[in] DrvId            Module instance handle returned by the function mio_GetDrv().
 * @param[in] Chan             Channel
 * @param[in] Cmd              #MIO_CMD_GIOADDFIFOENTRY
 * @param[in] pFifoItem        Period and Pulse counter structure<br>
 *                             Period: 0 no pulse is generated, minimum: 8000ns<br>
 *                             Pulse counter: 0xffffffff endless pulse generation
 *
 * @retval #MIO_ER_OK OK
 * @retval other      Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
 *
 *
 * @see #MIO_CMD_GIOSTARTSTOPFIFO
 * @see #MIO_CMD_GIOGETNBRFIFOENTRIES
 * @since V3.03.00 Beta
 */
static inline SINT32 gio2xx_AddFifoEntry(void *DrvId, UINT32 Chan, GIO_FIFOITEM *FifoItem)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GIOADDFIFOENTRY, FifoItem);
	return (retValue);
}


/**
 * @ingroup GIO2XX_DoCmds
 * @def MIO_CMD_GIOSETPTCURRENT
 * @code{.c} SINT32 mio_DoCmd(MIO_DRV *DrvId, UINT32 Chan, UINT32 Cmd, UINT32 Current) @endcode
 *
 * @param[in]  DrvId            Module instance handle returned by the function mio_GetDrv().
 * @param[in]  Chan             Channel
 * @param[in]  Cmd              #MIO_CMD_GIOSETPTCURRENT
 * @param[in]  Current          Current in digits (digit value depends on current mode used by PT)
 *
 * @retval #MIO_ER_OK OK
 * @retval other      Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
 * @since V3.03.00 Beta
 */
static inline SINT32 gio2xx_SetPtCurrent(void *DrvId, UINT32 Chan, UINT32 Current)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GIOSETPTCURRENT, Current);
	return (retValue);
}


/**
 * @ingroup GIO2XX_DoCmds
 * @def MIO_CMD_GIOGETPTCURRENT
 * @code{.c} SINT32 mio_DoCmd(MIO_DRV *DrvId, UINT32 Chan, UINT32 Cmd, UINT32 *Current) @endcode
 *
 * @param[in]  DrvId            Module instance handle returned by the function mio_GetDrv().
 * @param[in]  Chan             Channel
 * @param[in]  Cmd              #MIO_CMD_GIOGETPTCURRENT
 * @param[out] Current          Current in digits (digit value depends on current mode used by PT)
 *
 * @retval #MIO_ER_OK OK
 * @retval other      Error (@ref MIO_Return_Codes "Possible return codes from MIO functions")
 * @since V3.03.00 Beta
 */
static inline SINT32 gio2xx_GetPtCurrent(void *DrvId, UINT32 Chan, UINT32  *Current)
{
	SINT32 retValue = mio_DoCmd(DrvId, Chan, MIO_CMD_GIOGETPTCURRENT, Current);
	return (retValue);
}


#endif /*M_OS_VXWORKS*/

#ifdef __cplusplus
}
#endif

#endif
