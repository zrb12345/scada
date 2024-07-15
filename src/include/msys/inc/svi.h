/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     svi.h
* @author   Huster
* @brief    Standard Variable Interface Library
*           This file contains all definitions and declarations exported by
*           the Standard Variable Interface Library, that could be used by
*           modules running on another CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef SVI__H
#define SVI__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

/**
 * @addtogroup SVI-DEF
 * @{
 */
#define SVI_MULTIBLKLEN 1960     /**< Defines */
#define SVI_PROTVERS    2   /**< Version of SMI-Protocol */
#define SVI_VERSION     1   /**< Old version of SVI */
#define SVI_VERSION2    2   /**< Current version of SVI */
#define SVI_SEPARATOR   '/' /**< Separator for symbolic SVI name */
#define SVI_ADDRLEN     63  /**< Size of symbolic name without '\0' termination */
#define SVI_ADDRLEN_A   ((SVI_ADDRLEN + 1 + 3) & 0xfffffffc)     /**< SVI_ADDRLEN + '\0' + aligned */
#define SVI_LOGVALLEN   80  /**< size of log write-value len without zero termination */
#define SVI_LOGVALLEN_A ((SVI_LOGVALLEN + 1 + 3) & 0xfffffffc)   /**< aligned length of #SVI_LOGVALLEN */
#define SVI_NOADDR      -1  /**< Invalid address */
#define SVI_MAXVARLEN   0xffff   /**< Maximum length of a SVI variable */

/**
 * @name Possible values for SVI_SERVINF.AddrType
 * @{
 */

#define SVI_CLASSA  0x0001  /**< Type class A address */
#define SVI_CLASSB  0x0002  /**< Type class B address */
/** @} */

/**
 * @name Defines for accessing SVI addresses as 32-bit values
 * @{
 */

#define SVI_CLASSA_MSK  0x80000000   /**< Mask for relevant bit range that defines class A address */
#define SVI_CLASSA_BIT  0x00000000   /**< Bit structure for class A addr. */
#define SVI_CLASSB_MSK  0xc0000000   /**< Mask for relevant bit range that defines class B address */
#define SVI_CLASSB_BIT  0x80000000   /**< that defines class B address */
#define SVI_CLASSA_VAL  0   /**< Value for SVI_ADDR.Ca.Class */
#define SVI_CLASSB_VAL  2   /**< Value for SVI_ADDR.Cb.Class */
/** @} */

/**
 * @anchor SVI_F_
 */
/**
 * @name Possible format definitions for SVI variables
 * @{
 */

#define SVI_F_IN                0x80     /**< Type is input (server view) */
#define SVI_F_OUT               0x40     /**< Type is output (server view) */
#define SVI_F_INOUT             0xc0     /**< Type is input and output */
#define SVI_F_BLK               0x20     /**< Block value */
#define SVI_F_HIDDEN            0x100    /**< Hidden service variable */
#define SVI_F_UNKNOWN           0x00     /**< Format unknown */
#define SVI_F_UINT1             0x01     /**< Bit value */
#define SVI_F_UINT8             0x02     /**< 8-bit unsigned integer */
#define SVI_F_SINT8             0x03     /**< 8-bit signed integer */
#define SVI_F_UINT16            0x04     /**< 16-bit unsigned integer */
#define SVI_F_SINT16            0x05     /**< 16-bit signed integer */
#define SVI_F_UINT32            0x06     /**< 32-bit unsigned integer */
#define SVI_F_SINT32            0x07     /**< 32-bit signed integer */
#define SVI_F_REAL32            0x08     /**< 32-bit float */
#define SVI_F_BOOL8             0x09     /**< Boolean value */
#define SVI_F_CHAR8             0x0a     /**< 8-bit character */
#define SVI_F_MIXED             0x0b     /**< mixed; for #SVI_F_BLK */
#define SVI_F_UINT64            0x0c     /**< 64-bit unsigned integer */
#define SVI_F_SINT64            0x0d     /**< 64-bit signed integer */
#define SVI_F_REAL64            0x0e     /**< 64-bit float */
#define SVI_F_CHAR16            0x0f     /**< 16-bit character (Unicode) */
#define SVI_F_STRINGLSTBASE     0x10     /**< base of String list type */
#define SVI_F_USTRINGLSTBASE    0x11     /**< base of Unicode String list type */
/** @} */

/**
 * @name Definition of block type SVI variable formats
 * @{
 */

#define SVI_F_STRINGLST     (SVI_F_BLK | SVI_F_STRINGLSTBASE)
#define SVI_F_USTRINGLST    (SVI_F_BLK | SVI_F_USTRINGLSTBASE)
#define SVI_F_STRING        (SVI_F_BLK | SVI_F_CHAR8)    /**< String type */
#define SVI_F_USTRING       (SVI_F_BLK | SVI_F_CHAR16)   /**< Unicode String type */
/** @} */

/**
 * @name Mask definitions
 * @{
 */

#define SVI_F_TYPEMSK       0x3f     /**< Mask for data type */
#define SVI_F_SUBTYPEMSK    0x1f     /**< Mask for elementary data types */
/** @} */

/**
 * @name Definition for extended format reply
 * @{
 */

#define SVI_F_EXTLEN    0x24680000   /**< Magic number used in GetAddr */
/** @} */

/**
 * @anchor SVI_E_
 */
/**
 * @name Possible error codes for SVI-Functions
 * @{
 */

#define SVI_E_OK            M_E_OK   /**< O.K. */
#define SVI_E_UNDEF         (M_ES_SVI | M_E_NOTSUPP)     /**< @copybrief #M_E_NOTSUPP */
#define SVI_E_ADDR          (M_ES_SVI | M_E_BADADDR)     /**< @copybrief #M_E_BADADDR */
#define SVI_E_WRITE         (M_ES_SVI | M_E_NOWRITE)     /**< @copybrief #M_E_NOWRITE */
#define SVI_E_READ          (M_ES_SVI | M_E_NOREAD)  /**< @copybrief #M_E_NOREAD */
#define SVI_E_FAILED        (M_ES_SVI | M_E_FAILED)  /**< @copybrief #M_E_FAILED */
#define SVI_E_OLDADDR       (M_ES_SVI | M_E_OLDADDR)     /**< @copybrief #M_E_OLDADDR */
#define SVI_E_NOMOD         (M_ES_SVI | M_E_NOMOD1)  /**< @copybrief #M_E_NOMOD1 */
#define SVI_E_BADNAME       (M_ES_SVI | M_E_BADNAME)     /**< @copybrief #M_E_BADNAME */
#define SVI_E_PARM          (M_ES_SVI | M_E_PARM)    /**< @copybrief #M_E_PARM */
#define SVI_E_VARINUSE      (M_ES_SVI | M_E_VARINUSE)    /**< @copybrief #M_E_VARINUSE */
#define SVI_E_MBTRANS       (M_ES_SVI | M_E_MBTRANS)     /**< @copybrief #M_E_MBTRANS */
#define SVI_E_MBNOBUFF      (M_ES_SVI | M_E_NOBUFF)  /**< @copybrief #M_E_NOBUFF */
#define SVI_E_NOMEM         (M_ES_SVI | M_E_NOMEM)   /**< @copybrief #M_E_NOMEM */
#define SVI_E_BADUSERLVL    (M_ES_SVI | M_E_BADUSERLVL)  /**< @copybrief #M_E_BADUSERLVL */
#define SVI_E_BADRANGE      (M_ES_SVI | M_E_BADRANGE)    /**< @copybrief #M_E_BADRANGE */
#define SVI_E_ACCDENIED     (M_ES_SVI | M_E_ACCDENIED)   /**< @copybrief #M_E_ACCDENIED */
#define SVI_E_DSIZE         (M_ES_SVI | M_E_DSIZE)   /**< @copybrief #M_E_DSIZE */
#define SVI_E_REDULOCK      (M_ES_SVI | M_E_REDULOCK)    /**< @copybrief #M_E_REDULOCK */
#define SVI_E_BADTYPE       (M_ES_SVI | M_E_BADTYPE)     /**< @copybrief #M_E_BADTYPE */
#define SVI_E_DLEN          (M_ES_SVI | M_E_LENGTH)  /**< @copybrief #M_E_LENGTH */
/** @} */

/**
 * @anchor SVI_VT_
 */
/**
 * @name Variable types
 * @{
 */

#define SVI_VT_SV   0       /**< Symbolic value, any type */
#define SVI_VT_MX   1       /**< Marker Bit, 1-bit value */
#define SVI_VT_MB   2       /**< Marker Byte, 8-bit integer */
#define SVI_VT_MD   3       /**< Marker DWord, 32-bit integer */
#define SVI_VT_MR   4       /**< Marker Float, 32-bit float */
#define SVI_VT_MW   5       /**< Marker Word, 16-bit integer */
#define SVI_VT_ML   6       /**< Marker Long, 64-bit integer */
#define SVI_VT_ME   7       /**< Marker Real, 64-bit float */
#define SVI_VT_GD   8       /**< Global DWord, 32-bit integer */
#define SVI_VT_RD   9       /**< Retain DWord, 32-bit integer */
#define SVI_VT_MAX  9       /**< Max SVI-handler defined marker */
/** @} */

/**
 * @name Bachmann reserved marker types
 * @{
 */

#define SVI_VT_PLC_RD   19  /**< Retain DWord used in Smi_plc.pld */
#define SVI_VT_MBA      21  /**< Mixed Block Array */
#define SVI_VT_MC       22  /**< CNC Data Marker, 32-bit float */
#define SVI_VT_MP       23  /**< Profile Marker, 32-bit float */
#define SVI_VT_MO       24  /**< Optional Marker, 32-bit float */
#define SVI_VT_PLC_GD   35  /**< Global DWord used in Smi_plc.pld */
/** @} */

/**
 * @name Old obsolete marker types
 * @{
 */

#define SVI_T_MX    1       /**< 1-bit value */
#define SVI_T_MB    2       /**< 8-bit integer */
#define SVI_T_MW    3       /**< 32-bit integer */
#define SVI_T_MR    4       /**< 32-bit float */
#define SVI_T_MS    5       /**< 16-bit integer */
#define SVI_T_ML    6       /**< 64-bit integer */
#define SVI_T_ME    7       /**< 64-bit float */
/** @} */

/**
 * @name Types of multi block buffers
 * @{
 */

#define SVI_MBT_SVISET  1   /**< Set a SVI value */
#define SVI_MBT_SVIGET  2   /**< Get a SVI value */
#define SVI_MBT_VHDGET  3   /**< Get VHD variables */
#define SVI_MBT_VHDSET  4   /**< Set VHD variables */
/** @} */
/** @} */

/**
 * @addtogroup SVI-SMI
 * @{
 */

/**
 * @name Possible SMI commands
 * @anchor SVI_PROC_
 * @{
 */
#define SVI_PROC_GETVAL         10000    /**< Read 32-bit value */
#define SVI_PROC_SETVAL         10002    /**< Write 32-bit value */
#define SVI_PROC_GETVALLST      10004    /**< Read list of 32-bit values */
#define SVI_PROC_SETVALLST      10006    /**< Write list of 32-bit values */
#define SVI_PROC_GETBLK         10008    /**< Read block of values */
#define SVI_PROC_SETBLK         10010    /**< Write block of values */
#define SVI_PROC_GETADDR        10012    /**< Get SVI machine address */
#define SVI_PROC_GETPVINF       10014    /**< Get list of symbolic names */
#define SVI_PROC_GETSERVINF     10016    /**< Get SVI server info */
#define SVI_PROC_GETMULTIBLK    10018    /**< Read block of values > 2kb */
#define SVI_PROC_SETMULTIBLK    10020    /**< Set block of values > 2kb */
#define SVI_PROC_GETXADDR       10022    /**< Get SVI machine address with more information */
/** @} */
/**
 * Structure of an SVI address
 */
typedef union
{
    /**
     * For access in two 32 bit values
     */
    struct
    {
        UINT32  Addr1;              /**< 1st 32-bit */
        UINT32  Addr2;              /**< 2nd 32-bit */
    } Int;

    struct                              /**< Structure in case of class A */
    {
        UINT16  Idx1;
        UINT16  Idx2;
        UINT8   Type;
        UINT8   Node;
        UINT8   Net;
        UINT8   Desc  : 7;
        UINT8   Class : 1;
    } Ca;                               /**< Class A type @deprecated Class A is an old
                                             definition and is only used up to MSys V1.07,
                                             starting with MSys V1.08 all field bus variables
                                             use class B. */

    struct
    {
        UINT16  Idx1;                   /**< 1st SVI-handler address */
        UINT16  Idx2;                   /**< 2nd SVI-handler address */
        UINT8   Type   : 6;             /**< Type code @ref SVI_VT_ */
        UINT8   SvFlag : 1;             /**< Service Flag (no auto read) */
        UINT8   Flag3  : 1;             /**< Used by VHD for inactive */
        UINT8   Format;                 /**< Format code @ref SVI_F_ */
        UINT8   Desc;                   /**< Used by VHD for task descr.*/
        UINT8   Incarnation : 6;        /**< Incarnation counter */
        UINT8   Class       : 2;        /**< Class definition field */
    } Cb;                               /**< Class B type */

    struct
    {
        UINT16  volatile *pRam;         /**< value address 16-Bit aligned */
        UINT8   Type   : 6;             /**< Type code @ref SVI_VT_ */
        UINT8   SvFlag : 1;             /**< Service Flag (no auto read) */
        UINT8   Flag3  : 1;             /**< Used by VHD for inactive */
        UINT8   Format;                 /**< Format code @ref SVI_F_ */
        UINT8   Desc;                   /**< Used by VHD for task descr.*/
        UINT8   Info  : 6;              /**< Type dep. info bitpos, len sign */
        UINT8   Class : 2;              /**< Class definition field */
    } CbC;                              /**< Class B-CAN type */

    struct
    {
        UINT16  volatile *pRam;         /**< value address 16-Bit aligned */
        UINT8   Type   : 6;             /**< Type code @ref SVI_VT_ */
        UINT8   SvFlag : 1;             /**< Service Flag (no auto read) */
        UINT8   Flag3  : 1;             /**< Used by VHD for inactive */
        UINT8   Format;                 /**< Format code @ref SVI_F_ */
        UINT8   Desc;                   /**< Used by VHD for task descr.*/
        UINT8   Info  : 6;              /**< Type dep. info bitpos, len sign */
        UINT8   Class : 2;              /**< Class definition field */
    } CbP;                              /**< Class B-PB type */
} SVI_ADDR;

/**
 * Info to an SVI variable also known as Process Value
 */
typedef struct
{
    CHAR8   Name[SVI_ADDRLEN_A];     /**< Symbolic name */
    UINT16  Format;             /**< Format of variable */
    UINT16  Len;                /**< Size of variable */
} SVI_PVINF;

/**
 * Info to an SVI server
 */
typedef struct
{
    UINT32  Version;            /**< Version of supported SVI */
    UINT32  AddrType;           /**< Type of address class used by this server */
    UINT32  NbOfPv;             /**< Number of exported SVI variables */
} SVI_SERVINF;

/**
 * Info to an SVI variable
 */
typedef struct
{
    UINT32  StartL;             /**< Start index low matrix elements (low or 2nd index) */
    UINT32  StartH;             /**< Start index high matrix elements (high or 1st index) */
    UINT32  NumbL;              /**< Number low matrix elements (low or 2nd index) */
    UINT32  NumbH;              /**< Number high matrix elements (high or 1st index) */
    UINT32  Reserved[4];        /**< Not used, 0 for now */
} SVI_VARINF;

/**
 * Structure for the SMI-Call #SVI_PROC_GETVAL
 */
typedef struct
{
    SVI_ADDR    Addr;           /**< SVI address of value to read */
} SVI_GETVAL_C;

/**
 * Structure for the SMI-Reply #SVI_PROC_GETVAL
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Value;              /**< Actual value */
} SVI_GETVAL_R;

/**
 * Structure for the SMI-Call #SVI_PROC_SETVAL
 */
typedef struct
{
    SVI_ADDR    Addr;           /**< SVI address of value to write */
    UINT32      Value;          /**< Set value */
} SVI_SETVAL_C;

/**
 * Structure for the SMI-Reply #SVI_PROC_SETVAL
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} SVI_SETVAL_R;

/**
 * Structure for the SMI-Call #SVI_PROC_GETVALLST
 */
typedef struct
{
    UINT32      ListLen;        /**< Number of SVI addresses */
    SVI_ADDR    Addr[1];        /**< List of SVI addresses */
} SVI_GETVALLST_C;

/**
 * Structure for the SMI-Reply #SVI_PROC_GETVALLST
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Value[1];           /**< List of actual values */
} SVI_GETVALLST_R;

/**
 * Structure for the SMI-Call #SVI_PROC_SETVALLST
 */
typedef struct
{
    UINT32      ListLen;        /**< Number of SVI addresses/values */
    SVI_ADDR    Addr[1];        /**< List of SVI addresses */
} SVI_SETVALLST_C;

/**
 * Structure for the SMI-Reply #SVI_PROC_SETVALLST
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} SVI_SETVALLST_R;

/**
 * Structure for the SMI-Call #SVI_PROC_GETBLK
 */
typedef struct
{
    SVI_ADDR    Addr;           /**< SVI address of block to read */
    UINT32      BuffLen;        /**< Size of block to read */
} SVI_GETBLK_C;

/**
 * Structure for the SMI-Reply #SVI_PROC_GETBLK
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  BuffLen;            /**< Size of block read */
    UINT8   Buff[1];            /**< Actual block */
} SVI_GETBLK_R;

/**
 * Structure for the SMI-Reply SVI_PROC_GETBLK (multiblock reply)
 */
typedef struct
{
    SINT32  RetCode;            /**< Return code */
    UINT32  BuffLen;            /**< Size of block to read */
    UINT32  BufferId;           /**< Id of the multiblock buffer */
} SVI_GETXBLK_R;

/**
 * Structure for the SMI-Call #SVI_PROC_GETMULTIBLK
 */
typedef struct
{
    UINT32  Offset;             /**< Offset of the block to read */
    UINT32  BufferId;           /**< ID of the buffer to read */
} SVI_GETMULTIBLK_C;

/**
 * Structure for the SMI-Reply #SVI_PROC_GETMULTIBLK
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Offset;             /**< Offset of the block in byte */
    UINT32  BlockLen;           /**< Length of the transfered block */
    UINT32  NbOfElem;           /**< Number of elements in the buffer */
    UINT8   Buff[1];            /**< Actual block */
} SVI_GETMULTIBLK_R;

/**
 * Structure for the SMI-Call #SVI_PROC_SETBLK
 */
typedef struct
{
    SVI_ADDR    Addr;           /**< SVI address of block to write */
    UINT32      BuffLen;        /**< Size of block to write */
    UINT8       Buff[1];        /**< Contents of block */
} SVI_SETBLK_C;

/**
 * Structure for the SMI-Reply #SVI_PROC_SETBLK
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} SVI_SETBLK_R;

/**
 * Structure for the SMI-Reply SVI_PROC_SETBLK (multiblock reply)
 */
typedef struct
{
    SINT32  RetCode;            /**< Return code */
    UINT32  BufferId;           /**< Id of the MB buffer */
} SVI_SETXBLK_R;

/**
 * Structure for the SMI-Call #SVI_PROC_SETMULTIBLK
 */
typedef struct
{
    UINT32  Offset;             /**< Offset of the block in bytes */
    UINT32  BlockLen;           /**< Length of the block */
    UINT32  RemBytes;           /**< Remaining bytes to set */
    UINT32  BufferId;           /**< ID of the buffer to write */
    UINT8   Buff[1];            /**< Actual block */
} SVI_SETMULTIBLK_C;

/**
 * Structure for the SMI-Reply #SVI_PROC_SETMULTIBLK
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  Type;               /**< Type of the multiblock transfer */
    UINT32  Offset;             /**< Offset of the block just set */
    UINT32  BlockLen;           /**< Length of the transfered block */
    UINT32  NbOfElem;           /**< Number of following elements */
    UINT8   Elem[1];            /**< Elements returned by write */
} SVI_SETMULTIBLK_R;

/**
 * Structure for the SMI-Call #SVI_PROC_GETADDR
 */
typedef struct
{
    CHAR8   Name[1];            /**< Symbolic name */
} SVI_GETADDR_C;

/**
 * Structure for the SMI-Reply #SVI_PROC_GETADDR
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    SVI_ADDR    Addr;           /**< SVI machine address */
    UINT32      Format;         /**< SVI format information */
} SVI_GETADDR_R;

/**
 * Structure for the SMI-Call #SVI_PROC_GETPVINF
 */
typedef struct
{
    UINT32  StartIdx;           /**< Index to start with (0-n) */
    UINT32  NbOfPv;             /**< Number of SVI variables */
} SVI_GETPVINF_C;

/**
 * Structure for the SMI-Reply #SVI_PROC_GETPVINF
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    UINT32      NbOfPv;         /**< Number of SVI variables */
    SVI_PVINF   Inf[1];         /**< List to SVI variable info */
} SVI_GETPVINF_R;

/**
 * Structure for the SMI-Call #SVI_PROC_GETSERVINF
 */
typedef struct
{
} SVI_GETSERVINF_C;

/**
 * Structure for the SMI-Reply #SVI_PROC_GETSERVINF
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    SVI_SERVINF Inf;            /**< Info about SVI server */
} SVI_GETSERVINF_R;

/**
 * Structure for the SMI-Call #SVI_PROC_GETXADDR
 */
typedef struct
{
    CHAR8   Name[1];            /**< Symbolic name */
} SVI_GETXADDR_C;

/**
 * Structure for the SMI-Reply #SVI_PROC_GETXADDR
 */
typedef struct
{
    SINT32      RetCode;        /**< Return Code */
    SVI_ADDR    Addr;           /**< SVI machine address */
    UINT16      Format;         /**< SVI format information */
    UINT16      ValLen;         /**< SVI size in bytes */
    UINT32      Spare[5];       /**< Not used, 0 for now */
} SVI_GETXADDR_R;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
