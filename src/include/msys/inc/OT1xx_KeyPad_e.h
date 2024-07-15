/**
********************************************************************************
* @file     OT1xx_KeyPad_e.h
* @author   fusseneg
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef OT1XX_KEYPAD_E_H_                 /* Avoid problems with multiple */
#define OT1XX_KEYPAD_E_H_                 /* including                    */

#ifdef __cplusplus
extern "C" {
#endif

/* Event Modifiers */
#define OT_MOD_SHIFT      0x01 
#define OT_MOD_CTRL       0x02
#define OT_MOD_META       0x04
#define OT_MOD_ALT        0x08
#define OT_MOD_ALPHA      0x80

/* Event KeyCodes */
#define OT_CODE_F1          112 
#define OT_CODE_F2          113 
#define OT_CODE_F3          114 
#define OT_CODE_F4          115 
#define OT_CODE_F5          116 
#define OT_CODE_F6          117 
#define OT_CODE_F7          118 
#define OT_CODE_F8          119 
#define OT_CODE_F9          120 
#define OT_CODE_F10         121 
#define OT_CODE_F11         122 
#define OT_CODE_F12         123 


#define OT_CODE_PAGE_UP     33
#define OT_CODE_PAGE_DOWN   34  
#define OT_CODE_END         35
#define OT_CODE_HOME        36  
#define OT_CODE_LEFT        37
#define OT_CODE_UP          38
#define OT_CODE_RIGHT       39
#define OT_CODE_DOWN        40

#define OT_CODE_R_CTRL      0x8000      /* Right Ctrl */
#define OT_CODE_L_CTRL      0x8001      /* Left Ctrl */
#define OT_CODE_R_SHFT      0x8002      /* Right Shift */
#define OT_CODE_L_SHFT      0x8003      /* Left Shift */
#define OT_CODE_R_ALT       0x8004      /* Right Alt */
#define OT_CODE_L_ALT       0x8005      /* Left Alt */
#define OT_CODE_CAPS        0x8006      /* Caps */
#define OT_CODE_NUM         0x8007      /* Num */
#define OT_CODE_SCRL        0x8008      /* Scroll */
#define OT_CODE_PSCR        0x8009      /* Print Screen */
#define OT_CODE_ALFA        0x800A      /* Alpha Lock */
                             
/* Event KeyChars */
#define OT_CHAR_NONE        0x0000              /* No Key */
#define OT_CHAR_ESC         0x001B              /* Escape */
#define OT_CHAR_BKSP        0x0008              /* Backspace */
#define OT_CHAR_HTAB        0x0009              /* Horzontal Tab */
#define OT_CHAR_ENTR        0x000A              /* Enter */
#define OT_CHAR_SPAC        0x0020              /* Space */
#define OT_CHAR_PLUS        0x002B              /* Plus */
#define OT_CHAR_COMA        0x002C              /* , */
#define OT_CHAR_MINU        0x002D              /* Minus */
#define OT_CHAR_DEL         0x007F              /* Delete */
#define OT_CHAR_INS         0x009b              /* Insert */

#ifdef __cplusplus
}
#endif

#endif  /*OT1XX_KEYPAD_H_*/
