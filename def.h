#ifndef DEF_H
#define DEF_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <tgmath.h>

#define SQRT5 2.23606797749978969640917366873127624q
#define SQRT1_5 0.44721359549995793928183473374625525q
#define PHI 1.61803398874989484820458683436563812q
#define PHI1 -0.61803398874989484820458683436563812q
#define PI 3.14159265358979323846264338327950288q

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

#define printneg()                                                             \
  {                                                                            \
    x = -x;                                                                    \
    putchar('-');                                                              \
  }

#define printsign()                                                            \
  if (x < 0)                                                                   \
    printneg();

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

static inline void printu128n(u128 x) {
  printu128(x);
  putchar('\n');
}
static inline void printi128n(i128 x) {
  printi128(x);
  putchar('\n');
}
static inline void printu64n(fu64 x) {
  printu64(x);
  putchar('\n');
}
static inline void printi64n(fi64 x) {
  printi64(x);
  putchar('\n');
}
static inline void printu32n(fu32 x) {
  printu32(x);
  putchar('\n');
}
static inline void printi32n(fi32 x) {
  printi32(x);
  putchar('\n');
}
static inline void printu16n(fu16 x) {
  printu16(x);
  putchar('\n');
}
static inline void printi16n(fi16 x) {
  printi16(x);
  putchar('\n');
}
static inline void printu8n(fu8 x) {
  printu8(x);
  putchar('\n');
}
static inline void printi8n(fi8 x) {
  printi8(x);
  putchar('\n');
}

typedef _Float16 f16;
typedef _Float32 f32;
typedef _Float64 f64;
typedef _Float64x f80;
typedef __float128 f128;

typedef struct {
  u16 frac : 10, exp : 5, sign : 1;
} f16part;

typedef _Float64 f64x2 __attribute__((vector_size(16)));

#define printfrac()                                                            \
  {                                                                            \
    putchar('.');                                                              \
    fu8 trunc;                                                                 \
    while (x) {                                                                \
      x *= 10;                                                                 \
      trunc = x;                                                               \
      x -= trunc;                                                              \
      putdigit(trunc);                                                         \
    }                                                                          \
  }

#define FIX_MIN 0.001

static inline void printf16(f16 x) {
  f16part y = *(f16part *)&x;
  if (y.sign)
    printneg();
  if (y.exp != 31) {
    fu16 tmp = x;
    printu16(tmp);
    x -= tmp;
    if (x) {
      putchar('.');
      fu32 frac = x * 1e10 + 0.5;
      char buf[11];
      memset(buf, '0', 10);
      fu8 i = 10,rem;
      while (1) {
        rem = frac % 10;
        frac /= 10;
        if (rem)
          break;
        --i;
      }
      buf[i] = 0;
      buf[--i] += rem ;
      while (frac) {
        buf[--i] += frac % 10;
        frac /= 10;
      }
      print(buf);
    }
    // printfrac();
    return;
  }
  if (y.frac) {
    print("nan");
    printu16(y.frac);
    return;
  }
  print("inf");
  return;
}
static inline void printf16n(f16 x) {
  printf16(x);
  putchar('\n');
}

static inline void printf32(f32 x) {

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

static inline void printf128(f128 x) {
  printsign();
  u128 y = *(u128 *)&x;
  print("(1+");
  printu128(y << 16 >> 16);
  print("/2^112)*2^");
  printi16((y >> 112) - 16383);
}

#endif
#endif