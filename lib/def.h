#ifndef DEF_H
#define DEF_H

#include <math.h>
#include <stdint.h>
#include <string.h>

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

typedef uint_fast8_t fu8;
typedef uint_fast16_t fu16;
typedef uint_fast32_t fu32;
typedef uint_fast64_t fu64;

typedef uint_least8_t lu8;
typedef uint_least16_t lu16;
typedef uint_least32_t lu32;
typedef uint_least64_t lu64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
// typedef ssize_t isize;

typedef int_fast8_t fi8;
typedef int_fast16_t fi16;
typedef int_fast32_t fi32;
typedef int_fast64_t fi64;

typedef int_least8_t li8;
typedef int_least16_t li16;
typedef int_least32_t li32;
typedef int_least64_t li64;

typedef struct {
  uint8_t b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 1, b6 : 1, b7 : 1;
} bit8;

typedef struct {
  uint8_t h0 : 4, h1 : 4, h2 : 4, h3 : 4;
} hex4;

#ifdef SDCC
#define f32 float
#else
typedef unsigned __int128 u128;
typedef __int128 i128;

typedef _Float16 f16;
typedef _Float32 f32;
typedef _Float64 f64;
typedef _Float64x f80;
typedef __float128 f128;

typedef struct {
  u16 frac : 10, exp : 5, sign : 1;
} f16part;

typedef _Float64 f64x2 __attribute__((vector_size(16)));
#endif
#endif