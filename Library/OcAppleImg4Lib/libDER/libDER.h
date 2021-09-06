/* Copyright (c) 2005-2007 Apple Inc. All Rights Reserved. */

/*
 * libDER.h - main header for libDER, a ROM-capable DER decoding library. 
 *
 * Created Nov. 4 2005 by dmitch
 */
 
#ifndef	_LIB_DER_H_
#define _LIB_DER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "libDER_config.h"
/*
 * Error returns generated by this library.
 */
typedef enum {
	DR_Success,
	DR_EndOfSequence,	/* end of sequence or set */
	DR_UnexpectedTag,	/* unexpected tag found while decoding */
	DR_DecodeError,		/* misc. decoding error (badly formatted DER) */
	DR_Unimplemented,	/* function not implemented in this configuration */
	DR_IncompleteSeq,	/* incomplete sequence */
	DR_ParamErr,		/* incoming parameter error */
	DR_BufOverflow		/* buffer overflow */
	/* etc. */
} DERReturn;

/* 
 * Primary representation of a block of memory.
 */
typedef struct {
	DERByte		*data;
	DERSize		length;
} DERItem;

/*
 * The structure of a sequence during decode or encode is expressed as 
 * an array of DERItemSpecs. While decoding or encoding a sequence, 
 * each item in the sequence corresponds to one DERItemSpec.
 */
typedef struct {
	DERSize			offset;			/* offset of destination DERItem */
	DERTag			tag;			/* DER tag */
	DERShort		options;		/* DER_DEC_xxx or DER_ENC_xxx */
} DERItemSpec;

/*
 * Macro to obtain offset of a DERDecodedInfo within a struct.
 * FIXME this is going to need reworking to avoid compiler warnings
 * on 64-bit compiles. It'll work OK as long as an offset can't be larger
 * than a DERSize, but the cast from a pointer to a DERSize may 
 * provoke compiler warnings. 
 */
#define DER_OFFSET(type, field) ((DERSize)(&((type *)0)->field))

#ifdef __cplusplus
}
#endif

#endif	/* _LIB_DER_H_ */

