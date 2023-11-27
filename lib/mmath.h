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

#define rotl8(x) __builtin_rotateleft8(x)
#define rotl16(x) __builtin_rotateleft16(x)
#define rotl32(x) __builtin_rotateleft32(x)
#define rotl64(x) __builtin_rotateleft64(x)
#define rotr8(x) __builtin_rotateright8(x)
#define rotr16(x) __builtin_rotateright16(x)
#define rotr32(x) __builtin_rotateright32(x)
#define rotr64(x) __builtin_rotateright64(x)

#define ffsu16(x) __builtin_ffs(x)
#define ffsu32(x) __builtin_ffsl(x)
#define ffsu64(x) __builtin_ffsll(x)

// #define clzu16(x) __builtin_clz(x)
// #define clzu32(x) __builtin_clzl(x)
// #define clzu64(x) __builtin_clzll(x)

#define ctzu16(x) __builtin_ctz(x)
#define ctzu32(x) __builtin_ctzl(x)
#define ctzu64(x) __builtin_ctzll(x)

// #define clrsbu16(x) __builtin_clrsb(x)
// #define clrsbu32(x) __builtin_clrsbl(x)
// #define clrsbu64(x) __builtin_clrsbll(x)

#define popcnt16(x) __popcnt16(x)
#define popcnt32(x) __builtin_popcountl(x)
#define popcnt64(x) __builtin_popcountll(x)

#define parityu16(x) __builtin_parity(x)
#define parityu32(x) __builtin_parityl(x)
#define parityu64(x) __builtin_parityll(x)

#define isnan(x) __builtin_isnan(x)
#define isinf(x) __builtin_isinf(x)
#define lgf32(x) __builtin_log10f(x)
#define flr32(x) __builtin_floorf(x)

#define e10f32(x) __builtin_powf(10, x)

static inline i16 logf128(f128 x) __attribute__((const));
static inline i16 lgf128(f128 x) __attribute__((const));

#include "impl/mmath.c"

#endif
