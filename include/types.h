/* Base integer and float types, and m2c's helper macros. */
#ifndef TYPES_H
#define TYPES_H

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

#endif
