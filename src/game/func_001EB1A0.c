#include "common.h"
typedef struct { s32 count; s32 max_count; s32 init_count; s32 wait_threads; u32 attr; u32 option; } SemaParam;
typedef struct { s64 x0; s64 x8; s32 x10; s32 x14; } E;
typedef struct { u64 a; u64 b; } T;
typedef struct { u32 x0; u32 x4; s32 x8; s32 xC; s32 x10; s32 x14; s32 x18; u8 pad[0x24]; s32 x40; s32 x44; s64 x48; E *x50; s32 x54; s32 x58; s32 x5C; } O;
s32 CreateSema(SemaParam *);
void DIntr(void);
void EIntr(s32, s32);
s32 func_001EB1A0(void *o0, u32 addr0, void *tags0, s32 n, E *e, s32 cnt) {
    u32 t;
    O *o;
    s32 addr;
    T *tags;
    s32 i;
    SemaParam sp;
    s32 a;
    s32 b;
    o = o0;
    tags = tags0;
    t = (u32)tags0 & 0x0FFFFFFF;
    addr = addr0;
    o->x0 = addr;
    o->x4 = t | 0x20000000;
    o->x8 = n;
    o->xC = 0;
    o->x10 = 0;
    o->x14 = 0;
    o->x18 = n << 11;
    o->x44 = 1;
    o->x48 = 0;
    o->x50 = e;
    o->x54 = cnt;
    o->x58 = 0;
    o->x5C = 0;
    for (i = 0; i < cnt; i++) {
        o->x50[i].x0 = -1;
        o->x50[i].x8 = -1;
        o->x50[i].x10 = 0;
        o->x50[i].x14 = 0;
    }
    sp.init_count = 1;
    sp.max_count = 1;
    o->x40 = CreateSema(&sp);
    for (i = 0; i < o->x8; i++) {
        tags[i].a = ((u64)(u32)addr << 32) | 0x30000080;
        addr += 0x800;
    }
    tags[i].a = ((u64)t << 32) | 0x20000000;
    *(volatile s32 *)0x1000B420 = 0;
    *(volatile s32 *)0x1000B410 = o->x0 & 0x0FFFFFFF;
    *(volatile s32 *)0x1000B430 = o->x4 & 0x0FFFFFFF;
    DIntr();
    b = *(s32 *)0x1000F520;
    a = b | 0x10000;
    *(s32 *)0x1000F590 = a;
    *(s32 *)0x1000B400 = 5;
    *(s32 *)0x1000F590 = (s32) (*(s32 *)0x1000F520 & 0xFFFEFFFF);
    EIntr(a, b);
    return 1;
}
