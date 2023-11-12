#ifndef _MY_MATH_C_
#define _MY_MATH_C_

#include "type.h"

#define swap(a, b) a ^= b, b ^= a, a ^= b

char *u16toax(u16 x, char str[]) {
  register u8 tmp;
  Hex4 y = {.word = x};
  tmp = y.hexs.h0, str[3] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = y.hexs.h1, str[2] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = y.hexs.h2, str[1] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = y.hexs.h3, str[0] = tmp > 9 ? tmp + '7' : tmp + '0';
  str[4] = 0;
  return str;
}

char *u12toax(u16 x, char str[]) {
  register u8 tmp;
  tmp = x & 0xf, str[2] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = x >> 4 & 0xf, str[1] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = x >> 8 & 0xf, str[0] = tmp > 9 ? tmp + '7' : tmp + '0';
  str[3] = 0;
  return str;
}

char *u8toax(register u8 x, char str[]) {
  register u8 tmp;
  tmp = x & 0xf, str[1] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = x >> 4 & 0xf, str[0] = tmp > 9 ? tmp + '7' : tmp + '0';
  str[2] = 0;
  return str;
}

void reverse(char str[], int length) {
  int start = 0;
  int end = length - 1;
  while (start < end) {
    swap(str[start], str[end]);
    end--;
    start++;
  }
}

char *u32toa(u32 x, char str[]) {
  if (!x)
    return "0";
  register u8 i = 0, rem;

  while (x) {
    rem = x % 10;
    str[i++] = rem + '0';
    x /= 10;
  }

  str[i] = 0;
  reverse(str, i);
  return str;
}

char *u32toak(u32 x, char str[]) {
  x /= 1000;
  if (!x)
    return "0k";
  register u8 i = 0, rem;
  while (x) {
    rem = x % 10;
    str[i++] = rem + '0';
    x /= 10;
  }

  str[i] = 0;
  reverse(str, i);
  str[i++] = 'k';
  return str;
}

char *u32toaM(u32 x, char str[]) {
  x /= 1000000;
  if (!x)
    return "0M";
  register u8 i = 0, rem;
  while (x) {
    rem = x % 10;
    str[i++] = rem + '0';
    x /= 10;
  }

  str[i] = 0;
  reverse(str, i);
  str[i++] = 'M';
  return str;
}

char *u16toa(u16 x, char str[]) {
  if (!x)
    return "0";
  register u8 i = 0, rem;
  while (x) {
    rem = x % 10;
    str[i++] = rem + '0';
    x /= 10;
  }

  str[i] = 0;
  reverse(str, i);
  return str;
}

char *u8toa(register u8 x, char str[]) {
  if (!x)
    return "0";
  register u8 i = 0, rem;
  while (x) {
    rem = x % 10;
    str[i++] = rem + '0';
    x /= 10;
  }

  str[i] = 0;
  reverse(str, i);
  return str;
}

char *ttoa(u16 t, char *str) {
  u16 frac;
  register u8 i = 0, rem, trunc = t >> 4;
  frac = (t & 0xf) * 625;

  while (frac) {
    rem = frac % 10;
    str[i++] = rem + '0';
    frac /= 10;
  }
  while (i < 4)
    str[i++] = '0';
  str[i++] = '.';
  while (trunc) {
    rem = trunc % 10;
    str[i++] = rem + '0';
    trunc /= 10;
  }

  str[i] = 0;
  reverse(str, i);
  return str;
}

u8 logu4(register u8 x) {
  register u8 y = 0;
  if (x >> 2)
    x >>= 2, y += 2;
  if (x >> 1)
    ++y;
  return y;
}

u8 logu16(u16 x) {
  register u8 y = 0;
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

u8 log16u32(u32 x) {
  register u8 y = 0;
  if (x >> 16)
    x >>= 16, y += 4;
  if (x >> 8)
    x >>= 8, y += 2;
  if (x >> 4)
    ++y;
  return y;
}

void splitu32(u32 x, u16 y[]) {
  register u8 log = (log16u32(x) + 1) >> 1 << 2;
  y[1] = x >> log;
  y[0] = x & ((1 << log) - 1);
}

u32 hex2dec(u32 x) {
  u32 y = 0;
  register u8 n = 0;
  while (x) {
    y |= x % 10 << n;
    x /= 10, n += 4;
  }
  return y;
}

#endif
