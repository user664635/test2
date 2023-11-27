#include "../def.h"

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

u8 logu8(u8 x) {
  u8 y = 0, tmp;
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
u8 lgu8(u8 x) {
  u8 y = 0, tmp;
  dx10py(1);
  return y + (x / 10 > 0);
}

u8 logu16(u16 x) {
  u8 y = 0, tmp;
  dx2py(8);
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
u8 lgu16(u16 x) {
  u8 y = 0;
  u16 tmp;
  dx10py(2);
  dx10py(1);
  return y + (x / 10 > 0);
}

u8 logu32(u32 x) {
  u8 y = 0;
  u16 tmp;
  dx2py(16);
  dx2py(8);
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
u8 lgu32(u32 x) {
  u8 y = 0;
  u16 tmp;
  dx10py(8);
  dx10py(4);
  dx10py(2);
  dx10py(1);
  return y + (x / 10 > 0);
}

u8 logu64(u64 x) {
  u8 y = 0;
  u32 tmp;
  dx2py(32);
  dx2py(16);
  dx2py(8);
  dx2py(4);
  dx2py(2);
  return y + (x >> 1);
}
u8 lgu64(u64 x) {
  u8 y = 0;
  u32 tmp;
  dx10py(16);
  dx10py(8);
  dx10py(4);
  dx10py(2);
  dx10py(1);
  return y + (x / 10 > 0);
}

u8 logu128(u128 x) {
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
u8 lgu128(u128 x) {
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

// f16d decf16(f16 x){
//   if (x >= 10){

//   }
// }

i16 logf128(f128 x) {
  f128part y = *(f128part *)&x;
  if (y.exp)
    return y.exp - 16383;
  return logu128(y.frac) - 16494;
}
i16 lgf128(f128 x) {
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

u128 powu64(u64 x, u8 n) {
  u128 y = 1;
  while (1) {
    if (n & 1)
      y *= x;
    n >>= 1;
    if (!n)
      return y;
    x *= x;
  }
}

u64 C(u32 n, u32 k) {
  if (k > n >> 1)
    k = n - k;
  if (!k)
    return 1;
  u64 res = n, tmp = k;
  while (k > 1) {
    res *= --n;
    tmp *= --k;
  }
  return res / tmp;
}