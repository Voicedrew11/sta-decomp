#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; u8 b[4]; } Col;
typedef struct { u8 b0:1; u8 b1:1; u8 r:6; u8 pad[3]; } E;
typedef struct { s32 sel; s32 x4; s32 x8; f32 xC; f32 x10; s32 x14; E e[2]; } M;
typedef struct { u8 p0[0xAC]; s8 *xAC; } G;
extern M D_004A1050;
extern S D_001F2A50[] __attribute__((aligned(16)));
extern s8 D_001FCDC8[];
void func_00181680(s32, s8 *, s8 *, void *, S *, s32);
f32 func_0011DA18(f32);
f32 func_0011D850(f32);
G *func_00189020(s32);
void func_001256E0(s8 *, s8 *, ...);
void func_001875C0(s8 *, s32, u32, f32, f32, f32);

void func_0018D420(s8 *o, s32 sel, u32 id) {
    S t __attribute__((aligned(16)));
    Col col;
    s8 *p;

    t = D_001F2A50[0];
    if (id < 500) {
        t.x = *(f32 *)(o + 0x30);
        t.y = *(f32 *)(o + 0x34);
        func_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, id);
        return;
    }
    switch (id) {
    case 500:
        if (sel == D_004A1050.sel) {
            o[0x2C] = (s32)(64.0f + func_0011D850(64.0f * func_0011DA18(D_004A1050.x10)));
            o[0x2D] = (s32)(64.0f + func_0011D850(64.0f * func_0011DA18(D_004A1050.x10)));
            o[0x2E] = (s32)(64.0f + func_0011D850(64.0f * func_0011DA18(D_004A1050.x10)));
        } else {
            o[0x2C] = 0x40;
            o[0x2D] = 0x40;
            o[0x2E] = 0x40;
            o[0x2F] = 0x40;
        }
        if (D_004A1050.e[sel].b0) {
            t.x = *(f32 *)(o + 0x30);
            t.y = *(f32 *)(o + 0x34);
            func_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, id);
        }
        break;
    case 0x226:
        p = func_00189020(0)->xAC;
        col.w = 0x30808080;
        t.m[0] = 1.0f;
        t.m[3] = 1.0f;
        t.x = *(f32 *)(o + 0x38);
        t.y = *(f32 *)(o + 0x3C);
        col.w = (sel == D_004A1050.sel) ? 0x40808000 : 0x30808080;
        func_00181680(*(s32 *)(p + 4), p + 0x10, p + 0x20, &col, &t, id);
        {
        s8 buf[16] = {0};
        col.w = 0x80808080;
        if (D_004A1050.xC < 0.0f) {
            col.b[3] = 0;
        } else if (D_004A1050.xC <= 128.0f) {
            col.b[3] = col.b[3] * (s32)D_004A1050.xC / 128.0f;
        }
        func_001256E0(buf, D_001FCDC8, sel + 1);
        func_001875C0(buf, 0, col.w, 8.0f + t.x, 4.0f + t.y, 1.0f);
        }
        break;
    }
}
