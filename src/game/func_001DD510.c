#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; u8 b[4]; } Col;
typedef struct { f32 x, y, z, w; } V4;
extern S D_001F39F0[] __attribute__((aligned(16)));
extern f32 D_002020D4;
extern s16 D_00202356;
extern s32 D_00201E4C;
void func_001875C0(s32, s32, f32, u32, f32, f32);
void func_00187960(f32, Col *);
void func_00181680(s32, V4 *, s8 *, void *, S *, s32);

void func_001DD510(s8 *a0, s32 a1, s32 a2) {
    S t __attribute__((aligned(16)));
    V4 v;
    Col col;

    t = D_001F39F0[0];
    t.x = *(f32 *)(a0 + 0x30);
    t.y = *(f32 *)(a0 + 0x34);
    col.w = 0x80808080;
    switch (a2) {
    case 0xC8:
        col.w = *(u32 *)(a0 + 0x2C);
        col.b[3] = col.b[3] * D_00202356 / 127;
        v.x = *(f32 *)(a0 + 0x0);
        v.z = *(f32 *)(a0 + 0x8);
        v.y = *(f32 *)(a0 + 0x4);
        v.w = *(f32 *)(a0 + 0xC);
        func_00187960(D_002020D4, &col);
        func_00181680(*(s32 *)(a0 + 0x28), &v, a0 + 0x10, &col, &t, a2);
        break;
    case 0xC9:
        col.b[3] = D_00202356;
        func_001875C0(D_00201E4C, 0, *(f32 *)(a0 + 0x38), col.w, *(f32 *)(a0 + 0x3C), 1.0f);
        break;
    }
}

