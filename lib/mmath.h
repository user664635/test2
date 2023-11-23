#ifndef MMATH_H
#define MMATH_H

#include "def.h"

// devide x by 2^exp and plus y
#define dxpy(exp)                                                              \
  if (x >> exp)                                                                \
  x >>= exp, y += exp

static inline fu8 logu8(fu8 x) {
  fu8 y = 0;
  dxpy(4);
  dxpy(2);
  return y + (x >> 1);
}

static inline fu8 logu16(fu16 x) {
  fu8 y = 0;
  dxpy(8);
  dxpy(4);
  dxpy(2);
  return y + (x >> 1);
}

static inline fu8 logu32(fu32 x) {
  fu8 y = 0;
  dxpy(16);
  dxpy(8);
  dxpy(4);
  dxpy(2);
  return y + (x >> 1);
}

static inline fu8 logu64(fu64 x) {
  fu8 y = 0;
  dxpy(32);
  dxpy(16);
  dxpy(8);
  dxpy(4);
  dxpy(2);
  return y + (x >> 1);
}

static inline fu8 logu128(u128 x) {
  fu8 y = 0;
  dxpy(64);
  dxpy(32);
  dxpy(16);
  dxpy(8);
  dxpy(4);
  dxpy(2);
  return y + (x >> 1);
}

#endif
