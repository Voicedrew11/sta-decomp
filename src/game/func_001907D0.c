#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; u8 b[4]; } Col;
extern S D_001F2CB0[] __attribute__((aligned(16)));
extern s32 D_001F2BB0[];
extern s8 D_001FCFE8[][13];
extern u8 D_004A1077[];
u32 func_00125E00(s32);
void func_00181680(s32, s8 *, s8 *, void *, S *, s32);
void func_001874F0(f32, f32, f32, s32, s32, s32, u32);
void func_001875C0(f32, f32, f32, s32, s32, u32);

void func_001907D0(s8 *o, s32 unused, u32 id, s8 *p) {
    S t __attribute__((aligned(16)));
    Col col;
    s32 k;
    s32 dx;
    s32 *str;
    f32 sc;
    s32 on;

    on = *(s32 *)(p + 8);
    t = D_001F2CB0[0];
    if (on != 0) {
        if (id < 200) {
            t.x = *(f32 *)(o + 0x30);
            t.y = *(f32 *)(o + 0x34);
            func_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, 0);
        } else if (id == 301) {
            if (D_004A1077[0] == 0 || D_004A1077[0] == 1) {
                t.x = *(f32 *)(o + 0x30);
                t.y = *(f32 *)(o + 0x34);
                func_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, 0);
            }
        } else if (id == 300) {
            if ((u32)(D_004A1077[0] - 2) <= 2 || D_004A1077[0] == 5) {
                t.x = *(f32 *)(o + 0x30);
                t.y = *(f32 *)(o + 0x34);
                func_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, 0);
            }
        } else {
            k = D_001FCFE8[D_004A1077[0]][id];
            dx = -2;
            if (k == 16) {
                sc = 0.95f;
            } else {
                sc = 1.0f;
            }
            col.w = 0x80808080;
            col.b[3] = *(u8 *)(o + 0x2F) * 2;
            *(f32 *)(o + 0x3C) += 1.0f;
            str = &D_001F2BB0[k];
            if (func_00125E00(*str) > 8) {
                if (k == 1) {
                    dx = -3;
                }
                if (k == 4 || k == 5) {
                    dx = -7;
                }
                func_001874F0(*(f32 *)(o + 0x38), *(f32 *)(o + 0x3C), sc, dx, *str, 1, col.w);
            } else {
                func_001875C0(*(f32 *)(o + 0x38), *(f32 *)(o + 0x3C), 1.0f, *str, 1, col.w);
            }
        }
    }
}
