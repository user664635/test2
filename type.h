#ifndef TYPE_H
#define TYPE_H

#include <float.h>
#include <tgmath.h>
#include <stdint.h>




// single bit access
typedef struct {
  uint8_t b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 1, b6 : 1, b7 : 1;
} bit8;

typedef union {
  bit8 bits;
  uint8_t byte;
} Bit8;

// hexdecimal number access
typedef struct {
  uint8_t h0 : 4, h1 : 4;
} hex2;

typedef union {
  hex2 hexs;
  uint8_t byte;
} Hex2;

typedef struct {
  uint8_t h0 : 4, h1 : 4, h2 : 4, h3 : 4;
} hex4;

typedef union {
  hex4 hexs;
  uint16_t word;
} Hex4;

typedef struct {
  uint8_t h0 : 4, h1 : 4, h2 : 4, h3 : 4, h4 : 4, h5 : 4, h6 : 4, h7 : 4;
} hex8;

typedef union {
  hex8 hexs;
  uint32_t dword;
} Hex8;

// byte access
typedef union {
  uint8_t bytes[2];
  uint16_t word;
} Byte2;

typedef union {
  uint8_t bytes[4];
  uint32_t dword;
} Byte4;

typedef union {
  uint8_t bytes[8];
  uint64_t qword;
} Byte8;

// word access
typedef union {
  uint16_t words[2];
  uint32_t dword;
} Word2;

typedef union {
  uint16_t words[4];
  uint64_t qword;
} Word4;

// dward access
typedef union {
  uint32_t dwords[2];
  uint64_t qword;
} Dword2;

// typedef union {
//   uint32_t dwords[4];
//   u128 oword;
// } Dword4;

// // qward access
// typedef union {
//   uint64_t qwords[2];
//   u128 oword;
// } Qword2;

#endif
