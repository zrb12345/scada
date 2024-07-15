/**
********************************************************************************
* @file     wav.h
* @author   Holl
*
* @brief This file contains the wav file header structures.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef WAV__H
#define WAV__H

#ifdef __cplusplus
extern "C" {
#endif

#include <mtypes.h>

#define WAVE_TYPE_PCM       0x0001      /**< Used at FMTCHUNK.Type */

#define RIFFID              0x46464952  /**< 'RIFF' - LITTLEENDIAN */
#define WAVEID              0x45564157  /**< 'WAVE' - LITTLEENDIAN */
#define FMTID               0x20746d66  /**< 'fmt ' - LITTLEENDIAN */
#define DATAID              0x61746164  /**< 'data' - LITTLEENDIAN */

#define FMTLEN              16          /**< FMTCHUNK.Len */
#define WAVEHDRLEN          44          /**< Length of all wave headers */

/**
 * Riff-Header - First header in file.
 */
typedef struct RiffHdr
{
    SINT32  RiffId;             /**< Containing 'RIFF' */
    SINT32  Size;               /**< Filesize - 8 */
    SINT32  WaveId;             /**< Containing 'WAVE' */
} RIFFHDR;

/**
 * The fmt chunk describes the sample rate.
 */
typedef struct FmtChunk
{
    SINT32  FmtId;              /**< Conatining 'fmt ' */
    SINT32  Length;             /**< Length of remaining fmt-header (16 Bytes) */
    UINT16  Type;               /**< Sample format - WAVE_TYPE_xxx */
    UINT16  Channels;           /**< 1 = mono, 2 = stereo */
    SINT32  SamplesPerSec;      /**< Sample rate (like 44100) */
    SINT32  BytesPerSec;        /**< SamplesPerSec * BlockAlign */
    UINT16  BlockAlign;         /**< Channels * BitPerSample / 8 */
    UINT16  BitsPerSample;      /**< Bits per sample (8, 16 or 24) */
} FMTCHUNK;

/**
 * The Data-Chunk contains the sample data.
 */
typedef struct DataChunk
{
    SINT32     DataId;             /**< Containing 'data' */
    SINT32     Length;             /**< Length in bytes */
} DATACHUNK;

/**
 * Represents a wave file in memory.
 */
typedef struct WaveFile
{
    RIFFHDR     RiffHdr;           /**< Riff-Header - First header in file. */
    FMTCHUNK    FmtHdr;            /**< Description of the sample rate. */
    DATACHUNK   DataHdr;           /**< Sample data information */
} WAVEFILE;


#ifdef __cplusplus
}
#endif

#endif /* WAV__H */
