#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct { u8 r, g, b, a; } Col;
extern S D_001F3100[] __attribute__((aligned(16)));
extern s8 D_001FD5B0[];
extern s8 D_004A3150[];
extern u8 D_004A329C[];
extern s32 D_002021E0;
extern s32 D_002021EC;
void func_001875C0(f32, f32, f32, s32, s32, Col);
void func_00181680(s32, s8 *, s8 *, void *, S *, s32);
void func_00182EF0(s32, s32, s32, s32, f32, f32, f32);
void sprintf(s8 *, s8 *, s32);

void func_0019CB90(s8 *a0, s32 a1, u32 a2) {
    S t __attribute__((aligned(16)));
    Col col;

    if (a2 < 300) {
        t = D_001F3100[0];
        t.x = *(f32 *)(a0 + 0x30);
        t.y = *(f32 *)(a0 + 0x34);
        func_00181680(*(s32 *)(a0 + 0x28), a0, a0 + 0x10, a0 + 0x2C, &t, a2);
        return;
    }
    if ((D_004A329C[0] & 1) && D_002021E0 + 300 == a2) {
        func_00182EF0(*(f32 *)(a0 + 0x38) - 6.0f, *(f32 *)(a0 + 0x3C), 171.0f + *(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.0f, 0.0f, 128.0f);
    }
    if (a2 == 500) {
        sprintf(D_004A3150, D_001FD5B0, D_002021EC);
        *(u32 *)&col = 0x80808080;
        func_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 1.1f, (s32)D_004A3150, 2, col);
    }
}
