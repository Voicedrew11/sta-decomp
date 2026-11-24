#include "m2c.h"
typedef struct {
    u64 tbp0:14; u64 tbw:6; u64 psm:6; u64 tw:4; u64 th:4; u64 tcc:1; u64 tfx:2;
    u64 cbp:14; u64 cpsm:4; u64 csm:1; u64 csa:5; u64 cld:3;
} Tex0;
typedef struct { Tex0 t0; u64 t1; } Tex;
typedef struct { u64 key; u8 pad[4]; s16 xC; s16 xE; u8 pad2[8]; f32 x18, x1C, x20, x24; u8 pad3[8]; } ItemA;
typedef struct { f32 x0, x4, x8, xC, x10, x14, x18, x1C; Tex *x20; u16 x24, x26; s16 x28; } ItemB;
typedef struct {
    u8 pad0[4]; u32 count; u8 pad1[4]; s32 xC; s16 x10, x12; u8 pad2[4]; Tex0 x18; u64 x20; u8 pad3[4]; s32 x2C;
    ItemA a[8]; ItemB b[1];
} Obj;
Tex *func_00177AF0(u64, s32);

void func_001754C0(Obj *arg0, s32 arg1) {
    ItemB *b;
    ItemA *a;
    u32 i;
    for (i = 0; i < arg0->count; i++) {
        a = &arg0->a[i];
        b = &arg0->b[i];
        if (arg1 != 0) {
            b->x20 = func_00177AF0(a->key, arg0->x2C);
            b->x26 = 1 << b->x20->t0.th;
            b->x24 = 1 << b->x20->t0.tw;
        }
        b->x0 = 16.0f * (a->x20 * (f32)b->x24);
        b->x4 = 16.0f * (a->x24 * (f32)b->x26);
        *(s32 *)&b->x8 = 0x3F800000;
        *(s32 *)&b->xC = 0x3F800000;
        *(s32 *)&b->x10 = 0;
        *(s32 *)&b->x14 = 0;
        b->x18 = 16.0f * ((f32)b->x24 * a->x18);
        b->x1C = 16.0f * ((f32)b->x26 * a->x1C);
        b->x28 = 0;
        if (a->xC != 0 || a->xE != 0) b->x28 = 1;
        if (i == 0) {
            Tex *t = b->x20;
            s32 h = 1 << t->t0.th;
            s32 w = 1 << t->t0.tw;
            arg0->x10 = w;
            arg0->x12 = h;
            arg0->x18 = b->x20->t0;
            arg0->x18.psm = 0;
            arg0->x18.cbp = 0;
            arg0->x20 = b->x20->t1;
            arg0->xC = (w * h * 4 + 0xFF) / 256;
        }
    }
}
