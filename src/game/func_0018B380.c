#include "m2c.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct { s32 x0; s32 x4; u8 pad8[8]; f32 x10; f32 x14; f32 x18; s32 x1C; } P;
extern S D_001F29F0 __attribute__((aligned(16)));
extern s8 D_001FCCF0[];
extern s8 D_001FCCF8[];
void func_00181680(s32, s8 *, s8 *, Col *, S *, u32);
void func_001875C0(f32, f32, f32, s8 *, s32, Col);
void sprintf(s8 *, s8 *, ...);
s8 *func_00195B10(s32);
s32 strlen(s8 *);
void func_00123A88(s8 *, s8 *, s32);
static inline void cat(s8 *d, s8 *s) { s32 n = strlen(s); func_00123A88(d + strlen(d), s, n + 1); }

void func_0018B380(s8 *a0, s32 a1, u32 a2, P *a3) {
    s8 buf[0x400];
    S t __attribute__((aligned(16)));
    Col col;
    s8 *s;

    col.w = 0x80808080;
    col.c.a = col.c.a * a3->x1C / 127;
    if (a2 < 500) {
        t = D_001F29F0;
        t.x = *(f32 *)(a0 + 0x30);
        t.y = *(f32 *)(a0 + 0x34);
        col = *(Col *)(a0 + 0x2C);
        col.c.a = col.c.a * a3->x1C / 127;
        func_00181680(*(s32 *)(a0 + 0x28), a0, a0 + 0x10, &col, &t, a2);
        return;
    }
    if (a3->x1C < 64) return;
    switch (a2) {
    case 500:
        sprintf(buf, D_001FCCF0);
        s = func_00195B10(a3->x0);
        if (s != 0) cat(buf, s);
        func_001875C0(*(f32 *)(a0 + 0x38) + a3->x14, *(f32 *)(a0 + 0x3C) + a3->x18, a3->x10, s, 1, col);
        break;
    case 501:
        sprintf(buf, D_001FCCF0);
        if (a3->x4 == 1) {
            cat(buf, func_00195B10(100));
            func_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9166667f, buf, 1, col);
        } else if (a3->x4 == 3 || a3->x4 == 4) {
            cat(buf, func_00195B10(0x67));
            func_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9166667f, buf, 1, col);
        }
        break;
    case 502:
        sprintf(buf, D_001FCCF8);
        if (a3->x4 == 1) {
            cat(buf, func_00195B10(0x65));
            func_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9166667f, buf, 1, col);
        } else if (a3->x4 == 3) {
            cat(buf, func_00195B10(0x66));
            func_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9166667f, buf, 1, col);
        }
        if (a3->x4 == 4) {
            cat(buf, func_00195B10(0x68));
            func_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9166667f, buf, 1, col);
        }
        break;
    case 503:
        if (a3->x4 == 2) {
            sprintf(buf, D_001FCCF0);
            cat(buf, func_00195B10(0x67));
            func_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.9166667f, buf, 1, col);
        }
        break;
    }
}
