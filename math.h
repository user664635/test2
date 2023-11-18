#ifndef _MY_MATH_C_
#define _MY_MATH_C_

#include "type.h"

#define swap(a, b) a ^= b, b ^= a, a ^= b

inline char *u32toax(uint32_t x, char str[]) {
  uint8_t tmp;
  Hex8 y = {.dword = x};
  tmp = y.hexs.h0, str[7] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = y.hexs.h1, str[6] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = y.hexs.h2, str[5] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = y.hexs.h3, str[4] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = y.hexs.h4, str[3] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = y.hexs.h5, str[2] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = y.hexs.h6, str[1] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = y.hexs.h7, str[0] = tmp > 9 ? tmp + '7' : tmp + '0';
  str[8] = 0;
  return str;
}

inline char *u16toax(uint16_t x, char str[]) {
  uint8_t tmp;
  Hex4 y = {.word = x};
  tmp = y.hexs.h0, str[3] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = y.hexs.h1, str[2] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = y.hexs.h2, str[1] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = y.hexs.h3, str[0] = tmp > 9 ? tmp + '7' : tmp + '0';
  str[4] = 0;
  return str;
}

inline char *u12toax(uint16_t x, char str[]) {
  uint8_t tmp;
  tmp = x & 0xf, str[2] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = x >> 4 & 0xf, str[1] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = x >> 8 & 0xf, str[0] = tmp > 9 ? tmp + '7' : tmp + '0';
  str[3] = 0;
  return str;
}

inline char *u8toax(uint8_t x, char str[]) {
  uint8_t tmp;
  tmp = x & 0xf, str[1] = tmp > 9 ? tmp + '7' : tmp + '0';
  tmp = x >> 4 & 0xf, str[0] = tmp > 9 ? tmp + '7' : tmp + '0';
  str[2] = 0;
  return str;
}

inline void reverse(char str[], int length) {
  int start = 0;
  int end = length - 1;
  while (start < end) {
    swap(str[start], str[end]);
    end--;
    start++;
  }
}

inline char *u32toa(uint32_t x, char str[]) {
  if (!x)
    return "0";
  uint8_t i = 0, rem;

  while (x) {
    rem = x % 10;
    str[i++] = rem + '0';
    x /= 10;
  }

  str[i] = 0;
  reverse(str, i);
  return str;
}

inline char *u32toak(uint32_t x, char str[]) {
  x /= 1000;
  if (!x)
    return "0k";
  uint8_t i = 0, rem;
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

inline char *u32toaM(uint32_t x, char str[]) {
  x /= 1000000;
  if (!x)
    return "0M";
  uint8_t i = 0, rem;
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

inline char *u16toa(uint16_t x, char str[]) {
  if (!x)
    return "0";
  uint8_t i = 0, rem;
  while (x) {
    rem = x % 10;
    str[i++] = rem + '0';
    x /= 10;
  }

  str[i] = 0;
  reverse(str, i);
  return str;
}

inline char *u8toa(uint8_t x, char str[]) {
  if (!x)
    return "0";
  uint8_t i = 0, rem;
  while (x) {
    rem = x % 10;
    str[i++] = rem + '0';
    x /= 10;
  }

  str[i] = 0;
  reverse(str, i);
  return str;
}

inline char *ttoa(uint16_t t, char *str) {
  uint16_t frac;
  uint8_t i = 0, rem, trunc = t >> 4;
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

inline uint8_t logu4(uint8_t x) {
  uint8_t y = 0;
  if (x >> 2)
    x >>= 2, y += 2;
  if (x >> 1)
    ++y;
  return y;
}

inline uint8_t logu16(uint16_t x) {
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

inline uint8_t log16u32(uint32_t x) {
  uint8_t y = 0;
  if (x >> 16)
    x >>= 16, y += 4;
  if (x >> 8)
    x >>= 8, y += 2;
  if (x >> 4)
    ++y;
  return y;
}

inline void splitu32(uint32_t x, uint16_t y[]) {
  uint8_t log = (log16u32(x) + 1) >> 1 << 2;
  y[1] = x >> log;
  y[0] = x & ((1 << log) - 1);
}

inline uint32_t hex2dec(uint32_t x) {
  uint32_t y = 0;
  uint8_t n = 0;
  while (x) {
    y |= x % 10 << n;
    x /= 10, n += 4;
  }
  return y;
}

#endif
