#ifndef MMATH_H
#define MMATH_H

#include "def.h"
#include <stdio.h>

#define LG2 0.30102999566398119521373889472449303

// devide x by 2^n and plus y
#define dx2py(n)                                                               \
  tmp = x >> n;                                                                \
  if (tmp)                                                                     \
  x = tmp, y += n

// devide x by 1en and plus y
#define dx10py(n)                                                              \
  tmp = x / 1e##n;                                                             \
  if (tmp)                                                                     \
  x = tmp, y += n

// multiply x by 1en and plus y
#define mx10py(n)                                                              \
  tmp = x * 1e##n##q;                                                          \
  if (tmp < 10)                                                                \
  x = tmp, y += n

static inline u8 logu8(u8 x) __attribute__((const));

static inline u8 logu8(u8 x) {
  u8 y = 0, tmp;
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
static inline u8 lgu8(u8 x) {
  u8 y = 0, tmp;
  dx10py(1);
  return y + (x / 10 > 0);
}

static inline u8 logu16(u16 x) {
  u8 y = 0, tmp;
  dx2py(8);
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
static inline u8 lgu16(u16 x) {
  u8 y = 0;
  u16 tmp;
  dx10py(2);
  dx10py(1);
  return y + (x / 10 > 0);
}

static inline u8 popcountu16(u16 x) {
  x -= x >> 1 & 0x5555;
  x = (x >> 2 & 0x3333) + (x & 0x3333);
  x = (((x >> 4) + x) & 0x0f0f);
  return (((x >> 8) + x) & 0x00ff);
}

static inline u8 logu32(u32 x) {
  u8 y = 0;
  u16 tmp;
  dx2py(16);
  dx2py(8);
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
static inline u8 lgu32(u32 x) {
  u8 y = 0;
  u16 tmp;
  dx10py(8);
  dx10py(4);
  dx10py(2);
  dx10py(1);
  return y + (x / 10 > 0);
}

static inline u8 popcountu32(u32 x) {
  x -= x >> 1 & 0x55555555;
  x = (x >> 2 & 0x33333333) + (x & 0x33333333);
  x = (((x >> 4) + x) & 0x0f0f0f0f);
  x = (((x >> 8) + x) & 0x00ff00ff);
  return (((x >> 16) + x) & 0x0000ffff);
}

static inline u8 logu64(u64 x) {
  u8 y = 0;
  u32 tmp;
  dx2py(32);
  dx2py(16);
  dx2py(8);
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
static inline u8 lgu64(u64 x) {
  u8 y = 0;
  u32 tmp;
  dx10py(16);
  dx10py(8);
  dx10py(4);
  dx10py(2);
  dx10py(1);
  return y + (x / 10 > 0);
}

static inline u8 logu128(u128 x) {
  u8 y = 0;
  u64 tmp;
  dx2py(64);
  dx2py(32);
  dx2py(16);
  dx2py(8);
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
static inline u8 lgu128(u128 x) {
  u8 y = 0;
  u64 tmp;
  dx10py(32);
  dx10py(16);
  dx10py(8);
  dx10py(4);
  dx10py(2);
  dx10py(1);
  return y + (x / 10 > 0);
}

static inline i8 logf16(f16 x) {
  f16part y = *(f16part *)&x;
  if (y.exp)
    return y.exp - 15;
  return logu16(y.frac) - 24;
}
static inline i8 lgf16(f16 x) {
  u8 y = 0, sign = 1;
  f16 tmp;
  if (x > 1)
    x = 1 / x, sign = 0;
  mx10py(8);
  mx10py(4);
  mx10py(2);
  mx10py(1);
  if (sign)
    y = -y;
  else
    --y;
  return y;
}

static inline i16 logf32(f32 x) {
  f32part y = *(f32part *)&x;
  if (y.exp)
    return y.exp - 127;
  return logu32(y.frac) - 149;
}
static inline i8 lgf32(f32 x) {
  u8 y = 0, sign = 1;
  f32 tmp;
  if (x > 1)
    x = 1 / x, sign = 0;
  mx10py(32);
  mx10py(16);
  mx10py(8);
  mx10py(4);
  mx10py(2);
  mx10py(1);
  if (sign)
    y = -y;
  else
    --y;
  return y;
}

static inline i16 logf64(f64 x) {
  f64part y = *(f64part *)&x;
  if (y.exp)
    return y.exp - 1023;
  return logu64(y.frac) - 1075;
}
static inline i16 lgf64(f64 x) {
  u16 y = 0;
  u8 sign = 1;
  f64 tmp;
  if (x > 1)
    x = 1 / x, sign = 0;
  mx10py(256);
  mx10py(128);
  mx10py(64);
  mx10py(32);
  mx10py(16);
  mx10py(8);
  mx10py(4);
  mx10py(2);
  mx10py(1);
  if (sign)
    y = -y;
  else
    --y;
  return y;
}

static inline i16 logf80(f80 x) {
  f80part y = *(f80part *)&x;
  if (y.exp)
    return y.exp - 16383;
  return logu64(y.frac) - 16445;
}
static inline i16 lgf80(f80 x) {
  i32 y = logf80(x);

  if (y < 0)
    --y;
  y *= 30103, y /= 100000;
  return y;
  // u16 y = 0;
  // u8 sign = 1;
  // f80 tmp;
  // if (x > 1)
  //   x = 1 / x, sign = 0;
  // mx10py(4096);
  // mx10py(2048);
  // mx10py(1024);
  // mx10py(512);
  // mx10py(256);
  // mx10py(128);
  // mx10py(64);
  // mx10py(32);
  // mx10py(16);
  // mx10py(8);
  // mx10py(4);
  // mx10py(2);
  // mx10py(1);
  // if (sign)
  //   y = -y;
  // else
  //   --y;
  // return y;
}

static inline i16 logf128(f128 x) {
  f128part y = *(f128part *)&x;
  if (y.exp)
    return y.exp - 16383;
  return logu128(y.frac) - 16494;
}
static inline i16 lgf128(f128 x) {
  u16 y = 0;
  u8 sign = 1;
  f80 tmp;
  if (x > 1)
    x = 1 / x, sign = 0;
  mx10py(4096);
  mx10py(2048);
  mx10py(1024);
  mx10py(512);
  mx10py(256);
  mx10py(128);
  mx10py(64);
  mx10py(32);
  mx10py(16);
  mx10py(8);
  mx10py(4);
  mx10py(2);
  mx10py(1);
  if (sign)
    y = -y;
  else
    --y;
  return y;
}

#endif
