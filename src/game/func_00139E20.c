#include "m2c.h"
typedef struct { f32 x, y, z, w; } V;
typedef struct { u8 pad[0x10]; s32 v10; u8 pad14[0x2C]; u8 v40[0x14]; s32 v54; } T;
void func_001027B0(V *, void *, V *);
void func_001029D0(u8 *, s32, V *);
void func_001029E8(V *, u8 *, s32);
void func_001403D0(s8 *, V *);
s32 func_001A5AA0(s8 *, T *, void *);
s32 func_0013E780(s8 *);
f32 func_0013FC10(V *);
s8 *func_00140430(s8 *);
void func_00137730(s8 *, void *);

void func_00139E20(s8 *arg0) {
    u8 spA0[16];
    u8 sp70[48];
    V sp60;
    V sp50;
    T *s0;
    s8 *v0;
    v0 = M2C_FIELD(arg0, s8 **, 0x518);
    s0 = (T *)(v0 + 0x180);
    if (M2C_FIELD(v0, s32 *, 0x274) != 0 && func_001A5AA0(arg0, s0, sp70) != 0 && func_0013E780(arg0) != 0) {
        func_001029E8(&sp60, s0->v40, s0->v10 + 0x100);
        sp60.w = 1.0f;
        func_001027B0(&sp50, sp70, &sp60);
        func_001029D0(s0->v40, s0->v10 + 0x100, &sp50);
        func_001403D0(arg0, &sp60);
        sp60.w = 0.0f;
        func_001027B0(&sp50, sp70, &sp60);
        {
            f32 f = func_0013FC10(&sp50);
            M2C_FIELD(func_00140430(arg0), f32 *, 4) = f;
        }
        func_00137730(arg0, spA0);
    }
    if (func_0013E780(arg0) != 0) {
        s0->v54 = 0;
    }
}
