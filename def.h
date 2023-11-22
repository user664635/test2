#ifndef DEF_H
#define DEF_H

#include <stdint.h>
#include <stdio.h>
#include <tgmath.h>

#define PHI 1.61803398874989484820458683436563812
#define PHI1 -0.61803398874989484820458683436563812
#define PI 3.14159265358979323846264338327950288

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
typedef ssize_t isize;

typedef int_fast8_t fi8;
typedef int_fast16_t fi16;
typedef int_fast32_t fi32;
typedef int_fast64_t fi64;

typedef int_least8_t li8;
typedef int_least16_t li16;
typedef int_least32_t li32;
typedef int_least64_t li64;

#ifndef SDCC
typedef unsigned __int128 u128;
typedef __int128 i128;
typedef _Float16 f16;
typedef _Float32 f32;
typedef _Float64 f64;
typedef _Float64x f80;
typedef __float128 f128;

typedef _Float64 f64x2 __attribute__((vector_size(16)));

#define print(str) fputs(str, stdout)
#define putdigit(x) putchar(x + '0')
#define printuint(digit)                                                       \
  if (x < 10) {                                                                \
    putchar('0' + x);                                                          \
    return;                                                                    \
  }                                                                            \
  char str[digit];                                                             \
  uint_fast8_t i = 0;                                                          \
  for (; x; x /= 10)                                                           \
    str[i++] = x % 10;                                                         \
  while (i)                                                                    \
  putdigit(str[--i])

#define printsign()                                                            \
  if (x < 0) {                                                                 \
    x = -x;                                                                    \
    putchar('-');                                                              \
  }

#define printint(digit)                                                        \
  printsign();                                                                 \
  printuint(digit);

static inline void printu128(u128 x) { printuint(39); }
static inline void printi128(i128 x) { printint(39); }
static inline void printu64(fu64 x) { printuint(20); }
static inline void printi64(fi64 x) { printint(20); }
static inline void printu32(fu32 x) { printuint(10); }
static inline void printi32(fi32 x) { printint(10); }
static inline void printu16(fu16 x) { printuint(5); }
static inline void printi16(fi16 x) { printint(5); }
static inline void printu8(fu8 x) { printuint(3); }
static inline void printi8(fi8 x) { printint(3); }

#define F16MAX 65504
static inline void printf16(f16 x) {
  printsign();
  if (x <= F16MAX) {
    fi16 trunc = x;
    printu16(trunc);
    putchar('.');
    while (x) {
      x -= trunc;
      x *= 10;
      trunc = x;
      putdigit(trunc);
    }
  } else if (x > F16MAX)
    print("inf");
  else
    print("nan");
  putchar('\n');
}

static inline void printf32(float x) {

  if (x < 10) {
    putchar('0' + x);
    return;
  }
  char str[100];
  uint_fast8_t i = 0;
  for (; x; x /= 10)
    str[i++] = x - x / 10 + '0';
  while (i)
    putchar(str[--i]);
}

#endif
#endif