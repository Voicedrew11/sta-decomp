#include "common.h"
typedef struct {
    u64 FBP : 9;
    u64 FBW : 6;
    u64 PSM : 5;
    u64 p0 : 12;
    u64 DBX : 11;
    u64 DBY : 11;
    u64 p1 : 10;
} DispFb;
typedef struct {
    u64 pmode;
    u64 smode2;
    DispFb dispfb;
    u64 display;
    u64 bgcolor;
    u32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
} Env;
extern s32 D_002023EC;
extern s32 D_002023F0;
extern s32 D_002023F4;
extern s32 D_002023F8;
extern s32 D_002023FC;
/* .bss, from the top down (CodeWarrior writes it in reverse) */
u32 D_004BD540[0x60];
extern s16 D_004BE0D4[];
extern s16 D_004BE0D6[];
extern s16 D_004BE0D8[];
void sceGsSyncV(s32);
void sceGsResetGraph(s16, s16, s16, s16);
void sceGsSetDefDispEnv(Env *, s16, s16, s16, s16, s16);
void FlushCache(s32);
void sceGsPutDispEnv(Env *);
void sceGsSyncPath(s32, s32);

static inline u32 *setreg(u32 *p, u64 v, s32 reg) {
    p[0] = v & 0xFFFFFFFF;
    p[1] = v >> 32;
    p[2] = reg;
    p[3] = 0;
    return p + 4;
}

static inline u32 *tag(u32 *p) {
    p[0] = 0x8007;
    p[1] = 0x10000000;
    p[2] = 0xE;
    p[3] = 0;
    return p + 4;
}

void func_001E9AA0(Env *o, s32 a1, s32 a2, s32 w, s32 h, s32 a5, s32 a6) {
    s32 h2;
    s32 w64;
    u32 a;
    u32 *p;

    D_002023EC = 0;
    D_002023F0 = 0;
    D_002023F4 = 0;
    D_002023F8 = 0;
    D_002023FC = 0;
    o->f28 = 0;
    h2 = h / 2;
    w64 = (w + 63) / 64 * 64;
    o->f2C = (w64 * ((h2 + 31) / 32 * 32)) >> 11;
    o->f30 = a1;
    o->f34 = a2;
    o->f38 = w;
    o->f3C = h;
    o->f40 = a5;
    o->f44 = a6;
    sceGsSyncV(0);
    sceGsResetGraph(0, 1, D_004BE0D4[0], 1);
    sceGsSetDefDispEnv(o, 0, w, h2, D_004BE0D6[0], D_004BE0D8[0]);
    o->dispfb.FBW = w64 / 64;
    FlushCache(0);
    sceGsSyncV(0);
    sceGsPutDispEnv(o);
    a = (u32)D_004BD540 & 0x0FFFFFFF;
    p = (u32 *)(((u32)D_004BD540 & 0x0FFFFFFF) | 0x20000000);
    p = tag(p);
    p = setreg(p, 1, 0x1A);
    p = setreg(p, (u64)o->f28 | ((u64)(u32)((o->f38 + 63) / 64 * 64 / 64) << 16), 0x4C);
    p = setreg(p, (u64)o->f28 | ((u64)0x3A << 24) | ((u64)1 << 32), 0x4E);
    p = setreg(p, 0x30000, 0x47);
    p = setreg(p, 0, 0x18);
    p = setreg(p, ((u64)(u32)(o->f3C - 1) << 48) | ((u64)(u32)(o->f38 - 1) << 16), 0x40);
    setreg(p, 5, 8);
    *(volatile u32 *)0x1000A010 = a;
    *(volatile u32 *)0x1000A020 = 8;
    *(volatile u32 *)0x1000A000 = 0x101;
    sceGsSyncPath(0, 0);
}
