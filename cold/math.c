
#include "../lib/def.h"

#define swap(a, b) a ^= b, b ^= a, a ^= b

inline void reverse(char str[], int length) {
  int start = 0;
  int end = length - 1;
  while (start < end) {
    swap(str[start], str[end]);
    end--;
    start++;
  }
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