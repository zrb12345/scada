/**
********************************************************************************
* !! ATTENTION: This file was generated automatically and must not be edited!!
********************************************************************************
* @file     ahd.h
* @author   Bachmann electronic GmbH
* @brief    Archive Handler Server
*           This file contains all definitions and declarations which were
*           exported by the module and can be used by other modules
*           on other CPU's.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef AHD__H
#define AHD__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>
#include <msys.h>

/**
 * @name Defines
 * @{
 */


/**
 * @name Possible error codes of Software-Module
 * @{
 */

#define AHD_E_OK                (M_ESW_AHD | M_E_OK)     /**< Everything OK */
#define AHD_E_FAILED            (M_ESW_AHD | M_E_FAILED)     /**< General error */
#define AHD_E_ARCHIVE_EXIST     (M_ESW_AHD | M_E_ALLREADYEXIST)  /**< Archive exist already */
#define AHD_E_SQLERROR          (M_ESW_AHD | M_E_SQLERROR)   /**< SQL error occurred */
#define AHD_E_ARCHIVE_N_FOUND   (M_ESW_AHD | M_E_NOOBJECT)   /**< Archive not found */
#define AHD_E_NOMEM             (M_ESW_AHD | M_E_NOMEM)  /**< Not enough memory */
/** @} */

/**
 * @name Possible SMI's and SVI's
 * @{
 */

#define AHD_PROC_APPSTAT            100  /**< SVI example */
#define AHD_PROC_SELECTBI_SMI       102  /**< AHD select values */
#define AHD_PROC_GETARCHIVES_SMI    104  /**< AHD get archives */
#define AHD_PROC_INSERTVALUES_SMI   106  /**< AHD insert values */
#define AHD_PROC_CREATE_SMI         108  /**< create archive */
#define AHD_PROC_GETARCHIVECOL_SMI  110  /**< get all columns of an archive */
#define AHD_PROC_DELETEARCHIVE_SMI  112  /**< delete an archive */
#define AHD_PROC_DUMP_SMI           114  /**< dump all archives */
#define AHD_PROC_GETINFO_SMI        116  /**< get info of an archive */
#define AHD_PROC_SELECTCH_SMI       118  /**< select values as char array */
#define ARCHIVE_NAME_MAX_LENGTH     40
#define ARCHIVE_TITEL_MAX_LENGTH    68
#define ARCHIVE_QUERY_MAX_LENGTH    256  /**< PCL max string length = 255 */
#define ARCHIVE_INFINITE_LENGTH     0
#define ARCHIVE_PATH_LENGTH         256
#define AHD_NBOFFUNC                15
/** @} */
/** @} */

/**
 * @name Structures
 * @{
 */

/**
 * structure for the SMI-call ARCHIV_PROC_CREATEARCHIV
 */
typedef enum ArchiveTypes
{
    TYPE_INT,
    TYPE_REAL,
    TYPE_BOOL,
    TYPE_STRING,
    TYPE_NUMERIC,
    TYPE_TIME,                  /**< not supported yet */
} ArchiveDataType;

/**
 * structure for a column in the DB
 */
typedef struct
{
    CHAR8           Name[ARCHIVE_TITEL_MAX_LENGTH];
    ArchiveDataType Datatype;
    BOOL8           SingleValue;
    BOOL8           Spare[3];
} ListDev;

/**
 * Structure for the SMI-Call #AHD_PROC_CREATE_SMI
 */
typedef struct
{
    CHAR8   Name[ARCHIVE_NAME_MAX_LENGTH];
    UINT32  Volatile;
    UINT32  BufferLen;
    UINT32  HistoryLen;
    UINT32  SampleLen;
    UINT32  NbrOfElements;
    UINT32  Spare[3];
    ListDev ElementDefList[1];
} ARCHIVE_CREATEARCHIV_C;

/**
 * Structure for the SMI-Reply #AHD_PROC_CREATE_SMI
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} ARCHIVE_CREATEARCHIV_R;

/**
 * Structure for the SMI-Call #AHD_PROC_SELECTBI_SMI
 */
typedef struct
{
    CHAR8   Name[ARCHIVE_NAME_MAX_LENGTH];
    SINT32  FirstId;
    SINT32  LastId;
    SINT32  MaxLen;
} ARCHIVE_SELECTBI_C;

/**
 * Structure for the SMI-Reply #AHD_PROC_SELECTBI_SMI
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Col;
    SINT32  Row;
    SINT32  NbOfLists;
    UINT64  LastId;
    REAL32  Values[1];
} ARCHIVE_SELECTBI_R;

/**
 * Structure for the SMI-Call #AHD_PROC_SELECTCH_SMI
 */
typedef struct
{
    CHAR8   Name[ARCHIVE_NAME_MAX_LENGTH];
    SINT32  FirstId;
    SINT32  LastId;
    SINT32  MaxLen;
} ARCHIVE_SELECTCH_C;

/**
 * Structure for the SMI-Reply #AHD_PROC_SELECTCH_SMI
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    SINT32  Col;
    SINT32  Row;
    SINT32  NbOfLists;
    UINT64  LastId;
    CHAR8   Values[1];
} ARCHIVE_SELECTCH_R;

/**
 * SMI structure for get all archives
 */
typedef struct
{
    CHAR8   Archive[ARCHIVE_NAME_MAX_LENGTH];
} ARCHIVE_TITELS;

/**
 * Structure for the SMI-Call #AHD_PROC_GETARCHIVES_SMI
 */
typedef struct
{
} ARCHIVE_GETARCHIVES_C;

/**
 * Structure for the SMI-Reply #AHD_PROC_GETARCHIVES_SMI
 */
typedef struct
{
    SINT32          RetCode;    /**< Return Code */
    UINT32          NbOfLists;
    ARCHIVE_TITELS  Archives[1];
} ARCHIVE_GETARCHIVES_R;

/**
 * Structure for the SMI-Call #AHD_PROC_GETARCHIVECOL_SMI
 */
typedef struct
{
    CHAR8   Archive[ARCHIVE_NAME_MAX_LENGTH];
} ARCHIVE_GETARCHIVECOL_C;

/**
 * Structure for the SMI-Reply #AHD_PROC_GETARCHIVECOL_SMI
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT32  NbOfLists;
    ListDev Columns[1];
} ARCHIVE_GETARCHIVECOL_R;

/**
 * Structure for the SMI-Call #AHD_PROC_DELETEARCHIVE_SMI
 */
typedef struct
{
    CHAR8   Archive[ARCHIVE_NAME_MAX_LENGTH];
} ARCHIVE_DELARCHIVE_C;

/**
 * Structure for the SMI-Reply #AHD_PROC_DELETEARCHIVE_SMI
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} ARCHIVE_DELARCHIVE_R;

/**
 * Structure for the SMI-Call #AHD_PROC_DUMP_SMI
 */
typedef struct
{
    CHAR8   Path[ARCHIVE_PATH_LENGTH];
    UINT32  Spare[3];
} ARCHIVE_DUMPARCHIVES_C;

/**
 * Structure for the SMI-Reply #AHD_PROC_DUMP_SMI
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} ARCHIVE_DUMPARCHIVES_R;

/**
 * Structure for the SMI-Call #AHD_PROC_INSERTVALUES_SMI
 */
typedef struct
{
    CHAR8   Name[ARCHIVE_NAME_MAX_LENGTH];
    CHAR8   Titles[ARCHIVE_QUERY_MAX_LENGTH];
    CHAR8   Values[ARCHIVE_QUERY_MAX_LENGTH];
} ARCHIVE_INSERT_C;

/**
 * Structure for the SMI-Reply #AHD_PROC_INSERTVALUES_SMI
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
} ARCHIVE_INSERT_R;

/**
 * Structure for the SMI-Call #AHD_PROC_GETINFO_SMI
 */
typedef struct
{
    CHAR8   Name[ARCHIVE_NAME_MAX_LENGTH];
} ARCHIVE_GETINFO_C;

/**
 * Structure for the SMI-Reply #AHD_PROC_GETINFO_SMI
 */
typedef struct
{
    SINT32  RetCode;            /**< Return Code */
    UINT64  NbOfLists;
    UINT64  LastId;
    UINT32  Spare[10];
} ARCHIVE_GETINFO_R;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
