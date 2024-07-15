/*---------------------------------------------------------------------------
* Module:   OT1XX
* File:     OT1xx_e.h
*----------------------------------------------------------------------------
*
* Desc:     This file contains all definitions and declarations which 
*           are exported by the ot1xx service to other modules on the same CPU.
*
*----------------------------------------------------------------------------
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2008
*--------------------------------------------------------------------------*/

#ifndef OT1XX_E__H                        /* Avoid problems with multiple */
#define OT1XX_E__H                        /* including                    */

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/*--- Defines ---*/

#define OT_MNAME        "OTSRV"           /* OT service name              */

/* connect state values for doCmd MIO_CMD_GETCONNSTATE */
#define OT_STATE_DISCONNECT 0
#define OT_STATE_HELLO      1
#define OT_STATE_CONFI      2
#define OT_STATE_CON        3

/* diplay command modes for doCmd MIO_CMD_SETDISPLCONFIG */
#define OT_DISP_SLEEP     0
#define OT_DISP_BRIGHT    1
#define OT_DISP_CONTRAST  2

/* max length of font name for OT1xx */
#define OT_FONT_STRG_SIZE   32  /* max. string size of font name */

/* possible font styles */
#define OT_FONT_STYLE_PLAIN         1
#define OT_FONT_STYLE_BOLD          2
#define OT_FONT_STYLE_ITALIC        3
#define OT_FONT_STYLE_BOLDITALIC    4

/* possible drawing flags */
#define OT_DRAW_FLIP                0x1

/* SMI draw commands */
#define OT_PROC_LED              502
#define OT_PROC_GETEVENT         508

/* von 600 - 698 draw functions */
#define OT_PROC_MINDRAW          600

#define OT_PROC_ACTEVENT         602
#define OT_PROC_FLIPPAGE         608
#define OT_PROC_CLEARPAGE        610 
#define OT_PROC_SETFONT          612
#define OT_PROC_SETCOLOR         614

#define OT_PROC_DRAWPIXEL        616
#define OT_PROC_DRAWLINE         618      
#define OT_PROC_DRAWFILLEDRECT   620
#define OT_PROC_DRAWTEXT         622
#define OT_PROC_DRAWIMAGE        624

#define OT_PROC_DRAWTEXTBOX      630

#define OT_PROC_MAXDRAW          698

/* ot OT_DRAW_IMAGE compression values */ 
#define OT_COMP_NONE                0

/* ot OT_PROC_ACTEVENT event id values */ 
#define OT_EVENT_NONE               0
#define OT_EVENT_CONNECT            1
#define OT_EVENT_KEYRELEASED        2
#define OT_EVENT_KEYPRESSED         3
#define OT_EVENT_SLEEP              4

/* ot OT_PROC_ACTEVENT event flags */
#define OT_ACT_NONE             0x00
#define OT_ACT_CONNECT          0x01
#define OT_ACT_KEYPRESS         0x02
#define OT_ACT_KEYRELEASE       0x04
#define OT_ACT_SLEEP            0x08
#define OT_ACT_ALL              0xff    /* activate all events */

/*--- Structurs ---*/

/* smi OT_PROC_ACTEVENT structure */
typedef struct 
{
    UINT8 EventId;
    union {
        struct
        {
            UINT8   Modifier;   /* shift, alt alpha */
            UINT8   Spare;      /* Must be 0 for now */
            UINT16  KeyChar;    /* ascii code of char */
            UINT16  KeyCode;    /* scan code */
            UINT16  Spare2;     /* Must be 0 for now */
            UINT32  CardNb;     /* device id */
        } Key __attribute__ ((packed));
        struct
        {   
            UINT32  CardNb;     /* device id */
            UINT32	Spare1;     /* Must be 0 for now */
            UINT32  Spare2;     /* Must be 0 for now */
        } Connect __attribute__ ((packed));
        struct             
        {   
            /* no data */
            UINT32  Spare;     /* Must be 0 for now */
        	UINT32	Spare1;    /* Must be 0 for now */
        	UINT32  Spare2;    /* Must be 0 for now */    
        } Sleep __attribute__ ((packed));
    } Event;
} OT_SMI_EVENT __attribute__ ((packed));



/* smi OT_PROC_FLIPPAGE and OT_PROC_CLEARPAGE structures */
typedef struct 
{
    UINT8   VisuId;     /* Text mode visu id */
    UINT8   Data[0];
} OT_SMI_HDR __attribute__ ((packed));



/* smi OT_PROC_SETCOLOR structure */
typedef struct
{
    UINT8   VisuId;     /* Text mode visu id */
    UINT8   Spare;      /* Must be 0 for now */
    UINT16  Color;      /* color code */
} OT_SMI_SETCOLOR __attribute__ ((packed));


/* smi OT_PROC_DRAWPIXEL structure */
typedef struct
{
    UINT8   VisuId;     /* Text mode visu id */
    UINT8   Spare;      /* Must be 0 for now */
    UINT16  X;          /* x end coordinate */
    UINT16  Y;          /* y end coordinate */
} OT_SMI_DRAWPIXEL __attribute__ ((packed));

/* smi OT_PROC_ACTEVENT structures */
typedef struct
{
    UINT8   VisuId;     /* Text mode visu id */
    BOOL8   SetEvent;   /* 1 activate, 0 deactivate events */
    UINT16  EventMask;  /* event mask */ 
} OT_SMI_ACTEVENT __attribute__ ((packed));


/* smi  OT_PROC_DRAWLINE and OT_PROC_DRAWFILLEDRECT structures */
typedef struct
{
    UINT8   VisuId;     /* Text mode visu id */
    UINT8   Spare;      /* Must be 0 for now */
    UINT16  X1;         /* x start coordinate */
    UINT16  Y1;         /* y start coordinate */
    UINT16  X2;         /* x end coordinate */
    UINT16  Y2;         /* y end coordinate */
} OT_SMI_DRAWLINE, OT_SMI_DRAWFILLEDRECT __attribute__ ((packed));

/* smi OT_PROC_DRAWTEXT structure */
typedef struct
{
    UINT8   VisuId;     /* Text mode visu id */
    UINT8   Spare;      /* Must be 0 for now */
    UINT16  X;          /* x start coordinate */
    UINT16  Y;          /* y start coordinate */
    CHAR    Strg[0];    /* text to draw in UTF-8 encoded */
} OT_SMI_DRAWTEXT __attribute__ ((packed));

/* smi OT_PROC_DRAWIMAGE structure */
typedef struct
{
    UINT8   VisuId;     /* Text mode visu id */
    UINT8   Comp;       /* compression */
    UINT16  X;          /* x start coordinate */
    UINT16  Y;          /* y start coordinate */
    UINT16  W;          /* width of image */
    UINT16  H;          /* height of image */
    CHAR    Data[0];    /* image data */
} OT_SMI_DRAWIMAGE __attribute__ ((packed));

/* smi OT_PROC_DRAWTEXTBOX structure */
typedef struct
{
    UINT8   VisuId;     /* Text mode visu id */
    UINT8   Flag;       /* Drawing flags */
    UINT16  X1;         /* x start rectangle coordinate */
    UINT16  Y1;         /* y start rectangle coordinate */
    UINT16  X2;         /* x end rectangle coordinate */
    UINT16  Y2;         /* y end rectangle coordinate */
    UINT16  Xt;         /* x start text coordinate */
    UINT16  Yt;         /* y start text coordinate */
    CHAR    Strg[0];    /* text to draw in UTF-8 encoded */
} OT_SMI_DRAWTEXTBOX __attribute__ ((packed));

/* smi OT_PROC_SETFONT structure */
typedef struct 
{
    UINT8   VisuId;     /* Text mode visu id */
    UINT8   FontId;
} OT_SMI_SETFONT __attribute__ ((packed));


/* smi OT_PROC_LED structure */
typedef struct 
{
    UINT8   VisuId;     /* Text mode visu id */
    UINT8   SetLed;     /* 0 turn off, 1 turn on LED */
    UINT16  LedMask;    /* Led id */
} OT_SMI_LED __attribute__ ((packed));

/* OT_FONT_TABLE structure for DoCmd MIO_CMD_READFONTLIST */
typedef struct 
{
    CHAR    Name[OT_FONT_STRG_SIZE];
    UINT16  Style;
    UINT16  Size;    
} OT_FONT_TABLE;


/*--- Function prototypes ---*/


/*--- Variable definitions ---*/


#ifdef __cplusplus
}
#endif

#endif
