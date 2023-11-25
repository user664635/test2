#ifndef PRINT_H
#define PRINT_H

#include "def.h"

static inline void printu8(u8 x);
static inline void printi8(i8 x);
static inline void printu8n(u8 x);
static inline void printi8n(i8 x);

static inline void printu16(u16 x);
static inline void printi16(i16 x);
static inline void printu16n(u16 x);
static inline void printi16n(i16 x);

static inline void printu32(u32 x);
static inline void printi32(i32 x);
static inline void printu32n(u32 x);
static inline void printi32n(i32 x);

static inline void printu64(u64 x);
static inline void printi64(i64 x);
static inline void printu64n(u64 x);
static inline void printi64n(i64 x);

#ifndef SDCC
static inline void printu128(u128 x);
static inline void printi128(i128 x);
static inline void printu128n(u128 x);
static inline void printi128n(i128 x);

static inline void printu256(u256 x);
static inline void printi256(i256 x);
static inline void printu256n(u256 x);
static inline void printi256n(i256 x);

static inline void printu512(u512 x);
static inline void printi512(i512 x);
static inline void printu512n(u512 x);
static inline void printi512n(i512 x);
#endif

#include "impl/print.c"

#endif