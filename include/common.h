#ifndef COMMON_H
#define COMMON_H

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
#ifdef __MWERKS__
typedef __int128 s128;
typedef unsigned __int128 u128;
#else
typedef int s128 __attribute__((mode(TI)));
typedef unsigned int u128 __attribute__((mode(TI)));
#endif

#ifndef NULL
#define NULL 0
#endif

/* m2c's accessor for a field of an unknown struct */
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
/* m2c's bit reinterpretation (a value conversion here: only for starting points) */
#define M2C_BITWISE(type, expr) ((type)(expr))

/* Types shared across the game code (from KiskarFisk's shadow-tower-abyss). */
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { Vec m[4]; } Mtx;

/* One flag byte; bN is the bitfield declared after N bits. */
typedef union {
    u8 b;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } f;
} Flags8;

typedef union {
    u8 b;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:2; } f;
} Flags8_6x2;

typedef union {
    u8 b;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:2; u8 b6:1; u8 b7:1; } f;
} Flags8_4x2;

#endif
