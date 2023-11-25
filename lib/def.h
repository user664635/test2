#ifndef DEF_H
#define DEF_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>

// #define SQRT5 2.23606797749978969640917366873127624q
// #define SQRT1_5 0.44721359549995793928183473374625525q
// #define PHI 1.61803398874989484820458683436563812q
// #define PHI1 -0.61803398874989484820458683436563812q
// #define PI 3.14159265358979323846264338327950288q

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef size_t usize;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
// typedef ssize_t isize;

typedef struct {
  uint8_t b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 1, b6 : 1, b7 : 1;
} bit8;

typedef struct {
  uint8_t h0 : 4, h1 : 4, h2 : 4, h3 : 4;
} hex4;


typedef float f32;
typedef double f64;
typedef long double f80;

#ifndef SDCC
typedef __int128 i128;
typedef __uint128_t u128;

typedef _BitInt(256) i256;
typedef unsigned _BitInt(256) u256;
typedef _BitInt(512) i512;
typedef unsigned _BitInt(512) u512;
typedef _BitInt(1024) i1k;
typedef unsigned _BitInt(1024) u1k;
typedef _BitInt(2048) i2k;
typedef unsigned _BitInt(2048) u2k;
typedef _BitInt(4096) i4k;
typedef unsigned _BitInt(4096) u4k;
typedef _BitInt(8192) i8k;
typedef unsigned _BitInt(8192) u8k;

typedef _Float16 f16;
typedef __float128 f128;

typedef _Complex _Float16 c16;
typedef _Complex float c32;
typedef _Complex double c64;
typedef _Complex long double c80;
typedef __float128 _Complex c128;

typedef struct {
  u16 frac : 10, exp : 5, sign : 1;
} f16part;
typedef struct {
  u32 frac : 23, exp : 8, sign : 1;
} f32part;
typedef struct {
  u64 frac : 52, exp : 11, sign : 1;
} f64part;
typedef struct {
  u64 frac;
  u16 exp : 15, sign : 1;
} f80part;
typedef struct {
  u128 frac : 112, exp : 15, sign : 1;
} f128part;

typedef f64 f64x2 __attribute__((vector_size(16)));
typedef f32 f32x2 __attribute__((vector_size(8)));

#endif
#endif