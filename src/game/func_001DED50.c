#include "common.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; u8 b[4]; } Col;
typedef struct { s32 x0; s32 x4; u8 pad[8]; s8 x10[0x10]; s8 x20[0x10]; } E;
typedef struct { u8 p0[0x34]; E *x34; } G;
extern S D_001F3A50[] __attribute__((aligned(16)));
extern s8 D_001FE798[];
extern s8 D_001FE7A0[];
extern s8 D_001FE7D0[];
extern s8 D_001FE7D8[];
extern s8 D_001FE7E0[];
extern s8 D_001FE7E8[];
extern s8 D_001FE7F0[];
extern s8 D_001FE7F8[];
extern f32 D_002020D4;
extern f32 D_0020235C;
extern f32 D_00202364;
extern f32 D_00202368;
extern f32 D_0020236C;
extern f32 D_00202370;
extern u32 D_00202378;
extern s8 D_004BAA70[];
f32 cosf(f32);
f32 sinf(f32);
void func_00181680(s32, s8 *, s8 *, void *, S *, s32);
void func_00187960(f32, void *);
G *func_00189020(s32);
s16 func_001CBA30(void);
void func_001875C0(f32, f32, f32, s8 *, s32, Col);
void sprintf(s8 *, s8 *, ...);
void strcpy(s8 *, s8 *);

typedef struct { u8 p0[0x10]; s8 x10[0x18]; s32 x28; Col c; f32 x30, x34, x38, x3C; } O;
void func_001DED50(O *o, s32 sel, u32 id, u32 n) {
    Col c1;
    Col c2;
    S t __attribute__((aligned(16)));
    E *e;
    s32 k;

    t = D_001F3A50[0];
    D_0020235C += 0.1f;
    if (id < 2000) {
        t.x = o->x30;
        t.y = o->x34;
        if (id == 0) {
            o->c.b[0xC - 0xC] = 0x40;
            o->c.b[0xD - 0xC] = 0x40;
            o->c.b[0xE - 0xC] = 0x40;
        }
        switch (D_00202378) {
        case 0:
        case 1:
            break;
        case 2:
            if (id == 0x1FD) return;
            break;
        case 3:
            if (sel == 100) return;
            break;
        case 4:
            if (sel == 100) return;
            break;
        case 5:
            if (id == 0x1FD) return;
            if (sel == 100) return;
            break;
        case 6:
            if (id == 0x1FB) return;
            if (id == 0x1FC) return;
            if (id == 0x1FD) return;
            if (sel == 100) return;
            break;
        }
        func_00181680(o->x28, (s8 *)o, o->x10, &o->c, &t, id);
    }
    if (n == id - 1500) {
        D_00202368 = 32.0f + o->x38 + 75.0f * sinf(0.1f * D_0020235C);
        D_00202364 = 32.0f + o->x3C + 75.0f * cosf(0.1f * D_0020235C);
        e = func_00189020(6)->x34;
        t.x = o->x38;
        t.y = o->x3C;
        t.m[3] = 1.0f;
        t.m[0] = 1.0f;
        func_00187960(D_002020D4, &o->c);
        func_00181680(e->x4, e->x10, e->x20, &o->c, &t, id);
    }
    if (n == id - 500) {
        D_00202370 = 32.0f + o->x38 + 75.0f * sinf(3.14f + 0.1f * D_0020235C);
        D_0020236C = 32.0f + o->x3C + 75.0f * cosf(3.14f + 0.1f * D_0020235C);
        if (n != 4) {
            D_00202368 = 32.0f + o->x38 + 75.0f * sinf(0.1f * D_0020235C);
            D_00202364 = 32.0f + o->x3C + 75.0f * cosf(0.1f * D_0020235C);
        }
        k = 0;
        switch (n) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            k = 0;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            k = 1;
            break;
        }
        e = &func_00189020(6)->x34[k];
        t.x = o->x38;
        t.y = o->x3C;
        t.m[3] = 1.0f;
        t.m[0] = 1.0f;
        func_00187960(D_002020D4, &o->c);
        func_00181680(e->x4, e->x10, e->x20, &o->c, &t, id);
    }
    if (id == 5000) {
        c1.w = 0x80808080;
        c1.b[3] = o->c.b[3] * 2;
        switch (D_00202378) {
        case 0:
            break;
        case 1:
            strcpy(D_004BAA70, D_001FE7D0);
            break;
        case 2:
            strcpy(D_004BAA70, D_001FE7D8);
            break;
        case 3:
            strcpy(D_004BAA70, D_001FE7E0);
            break;
        case 4:
            strcpy(D_004BAA70, D_001FE7E8);
            break;
        case 5:
            strcpy(D_004BAA70, D_001FE7F0);
            break;
        case 6:
            strcpy(D_004BAA70, D_001FE7F8);
            break;
        }
        func_001875C0(o->x38, o->x3C, 0.9f, D_004BAA70, 0, c1);
    }
    if (sel == 100) {
        c2.w = 0x80808080;
        c2.b[3] = o->c.b[3] * 2;
        if (id == 100) {
            func_001875C0(o->x38, o->x3C, 0.9f, D_001FE798, 0, c2);
        }
        if (id == 0x65) {
            sprintf(D_004BAA70, D_001FE7A0, func_001CBA30());
            func_001875C0(o->x38, o->x3C, 0.9f, D_004BAA70, 2, c2);
        }
    }
}
