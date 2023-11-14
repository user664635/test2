#ifndef TYPE_H
#define TYPE_H

#include <float.h>
#include <stdint.h>

// typedef uint8_t u8;
// typedef uint16_t u16;
// typedef uint32_t u32;
// typedef uint64_t u64;
// typedef unsigned __int128 u128;

// typedef int8_t i8;
// typedef int16_t i16;
// typedef int32_t i32;
// typedef int64_t i64;
// typedef __int128 i128;

// typedef __fp16 f16;
// typedef float f32;
// typedef double f64;
// typedef long double f80;
// typedef __float128 f128;

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t
#define u128 unsigned __int128

#define i8 int8_t
#define i16 int16_t
#define i32 int32_t
#define i64 int64_t
#define i128 __int128

#define f16 __fp16
#define f32 float
#define f64 double
#define f80 long double
#define f128 __float128

// single bit access
typedef struct {
  u8 b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 1, b6 : 1, b7 : 1;
} bit8;

typedef union {
  bit8 bits;
  u8 byte;
} Bit8;

// hexdecimal number access
typedef struct {
  u8 h0 : 4, h1 : 4;
} hex2;

typedef union {
  hex2 hexs;
  u8 byte;
} Hex2;

typedef struct {
  u8 h0 : 4, h1 : 4, h2 : 4, h3 : 4;
} hex4;

typedef union {
  hex4 hexs;
  u16 word;
} Hex4;

typedef struct {
  u8 h0 : 4, h1 : 4, h2 : 4, h3 : 4, h4 : 4, h5 : 4, h6 : 4, h7 : 4;
} hex8;

typedef union {
  hex8 hexs;
  u32 dword;
} Hex8;

// byte access
typedef union {
  u8 bytes[2];
  u16 word;
} Byte2;

typedef union {
  u8 bytes[4];
  u32 dword;
} Byte4;

#endif
