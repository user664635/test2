#ifndef MMATH_H
#define MMATH_H

#include "def.h"
#include <stdio.h>

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

static inline fu8 logu8(fu8 x) {
  fu8 y = 0, tmp;
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
static inline fu8 lgu8(fu8 x) {
  fu8 y = 0, tmp;
  dx10py(1);
  return y + (x / 10 > 0);
}

static inline fu8 logu16(fu16 x) {
  fu8 y = 0, tmp;
  dx2py(8);
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
static inline fu8 lgu16(fu16 x) {
  fu8 y = 0;
  fu16 tmp;
  dx10py(2);
  dx10py(1);
  return y + (x / 10 > 0);
}

static inline fu8 logu32(fu32 x) {
  fu8 y = 0;
  fu16 tmp;
  dx2py(16);
  dx2py(8);
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
static inline fu8 lgu32(fu32 x) {
  fu8 y = 0;
  fu16 tmp;
  dx10py(8);
  dx10py(4);
  dx10py(2);
  dx10py(1);
  return y + (x / 10 > 0);
}

static inline fu8 logu64(fu64 x) {
  fu8 y = 0;
  fu32 tmp;
  dx2py(32);
  dx2py(16);
  dx2py(8);
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
static inline fu8 lgu64(fu64 x) {
  fu8 y = 0;
  fu32 tmp;
  dx10py(16);
  dx10py(8);
  dx10py(4);
  dx10py(2);
  dx10py(1);
  return y + (x / 10 > 0);
}

static inline fu8 logu128(u128 x) {
  fu8 y = 0;
  fu64 tmp;
  dx2py(64);
  dx2py(32);
  dx2py(16);
  dx2py(8);
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
static inline fu8 lgu128(u128 x) {
  fu8 y = 0;
  fu64 tmp;
  dx10py(32);
  dx10py(16);
  dx10py(8);
  dx10py(4);
  dx10py(2);
  dx10py(1);
  return y + (x / 10 > 0);
}

static inline fi8 logf16(f16 x) {
  f16part y = *(f16part *)&x;
  if (y.exp)
    return y.exp - 15;
  return logu16(y.frac) - 24;
}

static inline fi16 logf32(f32 x) {
  f32part y = *(f32part *)&x;
  if (y.exp)
    return y.exp - 127;
  return logu32(y.frac) - 149;
}

static inline fi16 logf64(f64 x) {
  f64part y = *(f64part *)&x;
  if (y.exp)
    return y.exp - 1023;
  return logu64(y.frac) - 1075;
}

static inline fi16 logf80(f80 x) {
  f80part y = *(f80part *)&x;
  if (y.exp)
    return y.exp - 16383;
  return logu64(y.frac) - 16445;
}

static inline fi16 logf128(f128 x) {
  f128part y = *(f128part *)&x;
  if (y.exp)
    return y.exp - 16383;
  return logu128(y.frac) - 16494;
}

#endif
