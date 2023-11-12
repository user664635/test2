#ifndef KEY_H
#define KEY_H

#include "../type.h"

#ifndef KEY
static volatile u8 KEY;
#endif

inline u16 key16(void) {
  Hex4 key;
  KEY = 0b11101111, key.hexs.h0 = KEY;
  KEY = 0b11011111, key.hexs.h1 = KEY;
  KEY = 0b10111111, key.hexs.h2 = KEY;
  KEY = 0b01111111, key.hexs.h3 = KEY;
  return key.word;
}

#endif