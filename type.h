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

typedef struct {
  u8 b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 1, b6 : 1, b7 : 1;
} bit8;

typedef union {
  bit8 bits;
  u8 byte;
} Bit8;

#endif
