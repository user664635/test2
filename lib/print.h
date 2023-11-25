#ifndef PRINT_H
#define PRINT_H

#include "def.h"

#ifndef print
#include <stdio.h>
#define prints(str) fputs(str, stdout)
#define printc(x) putchar(x)
#define printn() putchar('\n')
#endif

#define printsn(str) prints(str), printn()

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

static inline void printu8(u8 x) { printuint(3); }
static inline void printi8(i8 x) { printint(3); }
static inline void printu8n(u8 x) {
  printu8(x);
  printn();
}
static inline void printi8n(i8 x) {
  printi8(x);
  printn();
}

static inline void printu16(u16 x) { printuint(5); }
static inline void printi16(i16 x) { printint(5); }
static inline void printu16n(u16 x) {
  printu16(x);
  printn();
}
static inline void printi16n(i16 x) {
  printi16(x);
  printn();
}

static inline void printu32(u32 x) { printuint(10); }
static inline void printi32(i32 x) { printint(10); }
static inline void printu32n(u32 x) {
  printu32(x);
  printn();
}
static inline void printi32n(i32 x) {
  printi32(x);
  printn();
}

static inline void printu64(u64 x) { printuint(20); }
static inline void printi64(i64 x) { printint(20); }
static inline void printu64n(u64 x) {
  printu64(x);
  printn();
}
static inline void printi64n(i64 x) {
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

static inline void printu256(u256 x) { printuint(78); }

#endif

#define printfrac()                                                            \
  {                                                                            \
    printc('.');                                                               \
    u8 trunc;                                                                  \
    while (x) {                                                                \
      x *= 10;                                                                 \
      trunc = x;                                                               \
      x -= trunc;                                                              \
      putdigit(trunc);                                                         \
    }                                                                          \
  }

#define FIX_MIN 0.001

#ifndef SDCC
// static inline void printf16(f16 x) {
//   f16part y = *(f16part *)&x;
//   if (y.sign)
//     printneg();
//   if (y.exp != 31) {
//     u16 tmp = x;
//     printu16(tmp);
//     x -= tmp;
//     if (x) {
//       printc('.');
//       u32 frac = x * 1e10 + 0.5;
//       char buf[11];
//       memset(buf, '0', 10);
//       u8 i = 10, rem;
//       while (1) {
//         rem = frac % 10;
//         frac /= 10;
//         if (rem)
//           break;
//         --i;
//       }
//       buf[i] = 0;
//       buf[--i] += rem;
//       while (frac) {
//         buf[--i] += frac % 10;
//         frac /= 10;
//       }
//       prints(buf);
//     }
//     // printfrac();
//     return;
//   }
//   if (y.frac) {
//     prints("nan");
//     printu16(y.frac);
//     return;
//   }
//   prints("inf");
//   return;
// }
// static inline void printf16n(f16 x) {
//   printf16(x);
//   printn();
// }
#endif

// static inline void printf32(f32 x) {

//   if (x < 10) {
//     printc('0' + x);
//     return;
//   }
//   char str[100];
//   uint_fast8_t i = 0;
//   for (; x; x /= 10)
//     str[i++] = x - x / 10 + '0';
//   while (i)
//     printc(str[--i]);
// }

#ifndef SDCC
static inline void printf128(f128 x) {
  printsign();
  u128 y = *(u128 *)&x;
  prints("(1+");
  printu128(y << 16 >> 16);
  prints("/2^112)*2^");
  printi16((y >> 112) - 16383);
}
#endif

#endif