#include "m2c.h"
typedef struct { u8 b[0x14]; } Fr;
typedef struct {
    u8 pad0[6];
    u8 n;
    u8 pad7[3];
    u16 fl;
    u8 v[6][0x10];
    u8 w[5][8];
    u8 pad94[4];
    Fr base[1];
} A;
void func_001631E0(s8 *, f32, u8 *, Fr *, Fr *, f32, s32);
void func_00163700(s8 *, f32, u8 *, Fr *, Fr *, f32, s32);

void func_00162490(s8 *dst, A *a, f32 t) {
    Fr *base;
    Fr *fr;
    u16 fl;

    base = a->base;
    fl = a->fl;
    fr = &base[a->n];
    if (fl & 0x1) {
        func_001631E0(dst, t, a->v[0], base, fr, 0.0f, 0);
    }
    if (fl & 0x2) {
        func_001631E0(dst + 0x10, t, a->v[1], base, fr, 0.0f, 0);
    }
    if (fl & 0x4) {
        func_001631E0(dst + 0x20, t, a->v[2], base, fr, 0.0f, 0);
    }
    if (fl & 0x8) {
        func_001631E0(dst + 0x30, t, a->v[3], base, fr, 0.0f, 0);
    }
    if (fl & 0x10) {
        func_001631E0(dst + 0x40, t, a->v[4], base, fr, 0.0f, 0);
    }
    if (fl & 0x20) {
        func_001631E0(dst + 0x50, t, a->v[5], base, fr, 0.0f, 0);
    }
    if (fl & 0x40) {
        func_00163700(dst + 0x60, t, a->w[0], base, fr, 0.0f, 0);
    }
    if (fl & 0x80) {
        func_00163700(dst + 0x64, t, a->w[1], base, fr, 0.0f, 0);
    }
    if (fl & 0x100) {
        func_00163700(dst + 0x68, t, a->w[2], base, fr, 0.0f, 0);
    }
    if (fl & 0x200) {
        func_00163700(dst + 0x6C, t, a->w[3], base, fr, 0.0f, 0);
    }
    if (fl & 0x400) {
        func_00163700(dst + 0x70, t, a->w[4], base, fr, 0.0f, 0);
    }
}
