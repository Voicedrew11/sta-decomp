#include "common.h"
typedef struct { u8 pad[0xBA]; u16 xBA; u8 xBC; } D;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; } F;
typedef struct { u8 pad[0x20]; s32 x20; u8 pad24[0x64]; s16 x88; s16 x8A; u8 pad8c[0x158 - 0x8C]; D *x158; u8 pad15c[0x1D8 - 0x15C]; F x1D8; } O;
void func_001541E0(f32);
void func_0016B280(void);
void func_001B37F0(O *, void *);
s32 func_001B3F30();
s32 func_001B3F80();
static inline f32 u2f(u32 x) { return x; }

void func_001B3FD0(O *o) {
    o->x88 = 0;
    o->x8A = 0;
    if (!o->x1D8.b2 && !o->x1D8.b3) {
    func_001541E0(u2f(o->x158->xBA));
    if (o->x158->xBC & 1) func_001B37F0(o, func_001B3F30);
    func_001B37F0(o, func_001B3F80);
    func_0016B280();
    if (o->x20) o->x20--;
    }
}
