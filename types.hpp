/***********************************************************************************
 **
 ** Atari++ emulator (c) 2002 THOR-Software, Thomas Richter
 **
 ** $Id: types.hpp,v 1.18 2021/08/16 10:31:01 thor Exp $
 **
 ** In this module: Thor's pecularities, my type definitions
 **********************************************************************************/

#pragma once

//MBG: normalize stuff

#include <stdint.h>

#define NULL 0

#define INIT(X) = X

//MBG: interesting
#ifdef HAS_CONST_CAST
#define TOCHAR(a) const_cast<char *>(a)
#define TOUBYTE(a) const_cast<UBYTE *>(a)
#else
#define TOCHAR(a) a
#define TOUBYTE(a) a
#endif

typedef int8_t  BYTE;
typedef uint8_t UBYTE;
typedef int16_t  WORD;
typedef uint16_t UWORD;
typedef int32_t  LONG;
typedef uint32_t ULONG;
typedef int64_t  QUAD;
typedef uint64_t UQUAD;

/// Emulation specific types
// An address, as used by the emulator. We use here int 
// for speed reasons.
typedef int ADR;

//MBG: interesting

/// Compiler __attributes__
// Checks whether the compiler has the __attribute__
// extension available. If so, we can use additional type 
// checks for some varar-dic methods.
#if HAS_ATTRIBUTES
#define PRINTF_STYLE __attribute__ (( format(printf,2,3) ))
#define LONG_PRINTF_STYLE(fmt,args) __attribute__ (( format(printf,fmt,args) ))
#else
#define PRINTF_STYLE
#define LONG_PRINTF_STYLE(fmt,args)
#endif
