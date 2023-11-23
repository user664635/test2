#ifndef PRINT_H
#define PRINT_H

#include "def.h"

#ifndef print
#include <stdio.h>
#define print(str) fputs(str, stdout)
#define printc(x) putchar(x)
#define printn() putchar('\n')
#endif

#define putdigit(x) printc(x + '0')
#define printuint(digit)                                                       \
  if (x < 10) {                                                                \
    printc('0' + x);                                                           \
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
    printc('-');                                                               \
  }

#define printsign()                                                            \
  if (x < 0)                                                                   \
    printneg();

#define printint(digit)                                                        \
  printsign();                                                                 \
  printuint(digit);

static inline void printu8(fu8 x) { printuint(3); }
static inline void printi8(fi8 x) { printint(3); }
static inline void printu8n(fu8 x) {
  printu8(x);
  printn();
}
static inline void printi8n(fi8 x) {
  printi8(x);
  printn();
}

static inline void printu16(fu16 x) { printuint(5); }
static inline void printi16(fi16 x) { printint(5); }
static inline void printu16n(fu16 x) {
  printu16(x);
  printn();
}
static inline void printi16n(fi16 x) {
  printi16(x);
  printn();
}

static inline void printu32(fu32 x) { printuint(10); }
static inline void printi32(fi32 x) { printint(10); }
static inline void printu32n(fu32 x) {
  printu32(x);
  printn();
}
static inline void printi32n(fi32 x) {
  printi32(x);
  printn();
}

static inline void printu64(fu64 x) { printuint(20); }
static inline void printi64(fi64 x) { printint(20); }
static inline void printu64n(fu64 x) {
  printu64(x);
  printn();
}
static inline void printi64n(fi64 x) {
  printi64(x);
  printn();
}

#ifndef SDCC
static inline void printu128(u128 x) { printuint(39); }
static inline void printi128(i128 x) { printint(39); }
static inline void printu128n(u128 x) {
  printu128(x);
  printn();
}
static inline void printi128n(i128 x) {
  printi128(x);
  printn();
}
#endif

#define printfrac()                                                            \
  {                                                                            \
    printc('.');                                                               \
    fu8 trunc;                                                                 \
    while (x) {                                                                \
      x *= 10;                                                                 \
      trunc = x;                                                               \
      x -= trunc;                                                              \
      putdigit(trunc);                                                         \
    }                                                                          \
  }

#define FIX_MIN 0.001

#ifndef SDCC
static inline void printf16(f16 x) {
  f16part y = *(f16part *)&x;
  if (y.sign)
    printneg();
  if (y.exp != 31) {
    fu16 tmp = x;
    printu16(tmp);
    x -= tmp;
    if (x) {
      printc('.');
      fu32 frac = x * 1e10 + 0.5;
      char buf[11];
      memset(buf, '0', 10);
      fu8 i = 10, rem;
      while (1) {
        rem = frac % 10;
        frac /= 10;
        if (rem)
          break;
        --i;
      }
      buf[i] = 0;
      buf[--i] += rem;
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
  printn();
}
#endif

static inline void printf32(f32 x) {

  if (x < 10) {
    printc('0' + x);
    return;
  }
  char str[100];
  uint_fast8_t i = 0;
  for (; x; x /= 10)
    str[i++] = x - x / 10 + '0';
  while (i)
    printc(str[--i]);
}

#ifndef SDCC
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