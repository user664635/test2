#ifndef DEF_H
#define DEF_H

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <tgmath.h>

typedef uint8_t u8;

typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef unsigned __int128 u128;
typedef size_t usize;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef __int128 i128;
typedef ssize_t isize;

typedef _Float16 f16;
typedef _Float32 f32;
typedef _Float64 f64;
typedef _Float64x f80;
typedef __float128 f128;

typedef _Float64 f64x2 __attribute__((vector_size(16)));

#define print(str) fputs(str, stdout)

#define printuint(digit)                                                       \
  if (x < 10) {                                                                \
    putchar('0' + x);                                                          \
    return;                                                                    \
  }                                                                            \
  char str[digit];                                                             \
  uint_fast8_t i = 0;                                                          \
  for (; x; x /= 10)                                                           \
    str[i++] = x % 10 + '0';                                                   \
  while (i)                                                                    \
  putchar(str[--i])

static inline void printu32(u32 x) { printuint(10); }

#endif