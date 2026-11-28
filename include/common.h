#ifndef COMMON_H
#define COMMON_H

#include "types.h"

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

/* One byte of single-bit flags (Flags8 is the same in a union with the byte). */
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits8;

#endif
