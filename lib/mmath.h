#ifndef MMATH_H
#define MMATH_H

#include "def.h"

#define LG2 0.30102999566398119521373889472449303

static inline u8 logu8(u8 x) __attribute__((const));
static inline u8 lgu8(u8 x) __attribute__((const));
static inline u8 logu16(u16 x) __attribute__((const));
static inline u8 lgu16(u16 x) __attribute__((const));
static inline u8 logu32(u32 x) __attribute__((const));
static inline u8 lgu32(u32 x) __attribute__((const));
static inline u8 logu64(u64 x) __attribute__((const));
static inline u8 lgu64(u64 x) __attribute__((const));
static inline u8 logu128(u128 x) __attribute__((const));
static inline u8 lgu128(u128 x) __attribute__((const));

#define popcnt16(x) __builtin_popcount(x)
#define popcnt32(x) __builtin_popcountl(x)
#define popcnt64(x) __builtin_popcountll(x)

static inline u8 logu8(u8 x) __attribute__((const));

#include "impl/mmath.c"

#endif
