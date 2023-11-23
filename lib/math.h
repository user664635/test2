#ifndef _MY_MATH_C_
#define _MY_MATH_C_

#include "def.h"


static inline fu8 logu8(fu8 x){
  fu8 y = 0;
  if (x >> 4)
    x >>= 4, y += 4;
  if (x >> 2)
    x >>= 2, y += 2;
  if (x >> 1)
    ++y;
  return y;
}

static inline fu8 logu16(fu16 x) {
  uint8_t y = 0;
  if (x >> 8)
    x >>= 8, y += 8;
  if (x >> 4)
    x >>= 4, y += 4;
  if (x >> 2)
    x >>= 2, y += 2;
  if (x >> 1)
    ++y;
  return y;
}

#endif
