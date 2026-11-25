#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; u8 b[4]; } Col;
typedef struct { u8 pad[4]; s32 x4; u8 pad8[8]; u8 x10[0x10]; u8 x20[0x10]; } Q;
typedef struct { u8 p0[0x54]; Q *x54; u8 p58[4]; Q *x5C; } G;
typedef struct { u8 pad[4]; u16 x4; u8 pad6[0x1A]; u16 x20; u8 pad22[0x1A]; u8 x3C; u8 pad3D[0x53]; } E;
typedef struct { u8 pad[0x14]; f32 x14; f32 x18; u8 pad1C[0x10]; f32 x2C; f32 x30; u8 pad34[8]; u32 x3C; } H;
extern S D_001F2F60[] __attribute__((aligned(16)));
extern s8 D_001FD368[];
extern s8 D_001FD370[];
extern s8 D_001FD378[];
extern s8 D_001FD380[];
extern s32 D_00202190;
extern H D_004A13F0;
void func_00181680(s32, void *, void *, void *, S *, s32);
G *func_00189020(s32);
void func_001256E0(s8 *, s8 *, ...);
void func_00125CE8(s8 *, s8 *);
void func_001875C0(f32, f32, f32, s8 *, s32, u32);
void func_00183650(H *);
E *func_001AFC90(void);
s32 func_001AFBD0(s16);
double func_0011F8C0(f32);

static inline f32 u2f(u32 x) { return x; }

void func_001973F0(s8 *o, s32 sel, u32 id, s16 n) {
    S t __attribute__((aligned(16))) = D_001F2F60[0];
    s8 buf[0x100] = {0};
    Col col;
    s32 k = n;
    Q *q;
    E *e;
    E *r;

    if (id < 300) {
        t.x = *(f32 *)(o + 0x30);
        t.y = *(f32 *)(o + 0x34);
        if (id == 0) {
            o[0x2C] = 0x40;
            o[0x2D] = 0x40;
            o[0x2E] = 0x40;
        }
        func_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, id);
        return;
    }
    if (id == 500) {
        q = &func_00189020(0)->x54[19];
        col.w = 0x30808080;
        t.x = *(f32 *)(o + 0x38);
        t.y = *(f32 *)(o + 0x3C);
        func_00181680(q->x4, q->x10, q->x20, &col, &t, id);
    }
    if (id == 0x1F5) {
        col.w = 0x80808080;
        func_001256E0(buf, D_001FD368, D_00202190);
        func_001875C0(*(f32 *)(o + 0x38), *(f32 *)(o + 0x3C), 0.9f, buf, 2, col.w);
    }
    switch (id) {
    case 0x12C:
        q = &func_00189020(0)->x54[sel + 15];
        col.w = 0x30808080;
        t.x = *(f32 *)(o + 0x38);
        t.y = *(f32 *)(o + 0x3C);
        func_00181680(q->x4, q->x10, q->x20, &col, &t, id);
        break;
    case 0x12D:
        q = &func_00189020(0)->x5C[sel + 15];
        t.m[3] = 1.0f;
        col.w = 0x30808080;
        t.m[0] = 1.1f;
        t.x = *(f32 *)(o + 0x38) - 5.0f;
        t.y = *(f32 *)(o + 0x3C) - 4.0f;
        func_00181680(q->x4, q->x10, q->x20, &col, &t, id);
        break;
    }
    switch (sel) {
    case 0:
        switch (id) {
        case 0x2711:
            D_004A13F0.x2C = *(f32 *)(o + 0x38);
            D_004A13F0.x30 = *(f32 *)(o + 0x3C);
            D_004A13F0.x3C = 0x80FFFFFF;
            D_004A13F0.x14 = 1.25f;
            D_004A13F0.x18 = 1.25f;
            func_00183650(&D_004A13F0);
            break;
        }
        break;
    case 1:
        switch (id) {
        case 0x12F:
            if (n > 0) {
                e = func_001AFC90() + n;
                if (func_001AFBD0(k) == 0) {
                    func_00125CE8(buf, D_001FD370);
                } else if (func_001AFBD0(k) == 1) {
                    r = func_001AFC90() + k;
                    func_001256E0(buf, D_001FD378, r->x3C);
                    if (r->x20 == 6 || r->x20 == 5) {
                        func_00125CE8(buf, D_001FD370);
                    }
                } else {
                    func_001256E0(buf, D_001FD378, e->x3C);
                }
                col.w = 0x80808080;
                func_001875C0(*(f32 *)(o + 0x38) - 20.0f, *(f32 *)(o + 0x3C) - 4.0f, 0.9f, buf, 0, col.w);
            }
            break;
        case 0x130:
            break;
        }
        break;
    case 2:
        switch (id) {
        case 0x12E:
            if (n > 0) {
                e = func_001AFC90();
                col.w = 0x80808080;
                func_001256E0(buf, D_001FD380, func_0011F8C0(u2f(e[n].x4) / 10.0f));
                func_001875C0(*(f32 *)(o + 0x38) - 20.0f, *(f32 *)(o + 0x3C) - 4.0f, 0.9f, buf, 2, col.w);
            } else {
                col.w = 0x80808080;
                func_00125CE8(buf, D_001FD370);
                func_001875C0(*(f32 *)(o + 0x38) - 20.0f, *(f32 *)(o + 0x3C) - 4.0f, 0.9f, buf, 2, col.w);
            }
            break;
        }
        break;
    }
}
