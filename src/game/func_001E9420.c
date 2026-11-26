#include "common.h"
typedef struct { char pad[0x38]; u32 w; s32 h; } O;
typedef struct { s32 a, b, c, d; } P;
extern u32 D_004BD380[];
u32 *func_001E9190(u32 *p, P *s, s32 n);
void sceGsSyncPath(s32, s32);

static inline u32 *setreg(u32 *p, u64 v, s32 reg) {
    p[0] = v & 0xFFFFFFFF;
    p[1] = v >> 32;
    p[2] = reg;
    p[3] = 0;
    return p + 4;
}

static inline u32 *tag(u32 *p) {
    p[0] = 0x8006;
    p[1] = 0x10000000;
    p[2] = 0xE;
    p[3] = 0;
    return p + 4;
}

void func_001E9420(O *o, s32 n) {
    P s;
    u32 a;
    u32 *p;
    s.a = 0;
    s.b = 0;
    s.c = o->w * 16;
    s.d = ((o->h * 2 + 31) / 32) << 9;
    a = (u32)D_004BD380 & 0x0FFFFFFF;
    p = (u32 *)(a | 0x20000000);
    p = tag(p);
    p = setreg(p, ((u64)(u32)(o->h << 1) << 48) | ((u64)o->w << 16), 0x40);
    p = func_001E9190(p, &s, n);
    setreg(p, ((u64)(u32)(o->h - 1) << 48) | ((u64)(u32)(o->w - 1) << 16), 0x40);
    *(volatile u32 *)0x1000A010 = a;
    *(volatile u32 *)0x1000A020 = 7;
    *(volatile u32 *)0x1000A000 = 0x101;
    sceGsSyncPath(0, 0);
}
