// mwcc=mwcps2-3.0b38-030307
/* MATCH with mwccps2 3.0b38 (addi range check); case 0x12E: ((volatile O *)o)->x38 fixes lwc1/lw order */
#include "common.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; u8 b[4]; } Col;
typedef struct { s32 x0; s32 x4; u8 pad8[8]; u8 a[0x10]; u8 b[0x10]; } Q;
typedef struct { u8 pad[0x54]; Q *q54; u8 pad58[4]; Q *q5C; } R;
typedef struct { u8 pad[4]; u16 x4; u8 pad6[4]; u16 xA; u8 padC[0x14]; u16 x20; u8 pad22[0x1A]; u8 x3C; u8 rest[0x53]; } E;
typedef struct { u8 pad[0x10]; u8 p10[0x18]; s32 x28; u8 c[4]; f32 x30, x34, x38, x3C; } O;
extern S D_001F3A90[] __attribute__((aligned(16)));
extern S D_001F3AB0[] __attribute__((aligned(16)));
extern s8 D_001FE748[];
extern s8 D_001FE750[];
extern s8 D_001FE758[];
extern s8 D_001FE760[];
extern s8 D_001FE768[];
extern s32 D_00202378;
extern s32 D_004BABB0[];
extern s32 D_004BABC8[];
extern s8 D_004BABE0[];
extern f32 D_004BABF4[];
extern f32 D_004BABF8[];
extern f32 D_004BAC0C[];
extern f32 D_004BAC10[];
extern u32 D_004BAC1C[];
void func_00181680(s32, void *, void *, void *, S *, s32);
void func_00183650(void *);
void func_001848A0(s32);
s32 func_00187130(s32, s32);
void func_001875C0(s8 *, s32, Col, f32, f32, f32);
R *func_00189020(s32);
u8 *func_001A97D0(s32);
s32 func_001AFBD0(s32);
E *func_001AFC90(void);
u8 *func_001CC3F0(s32);
s32 sprintf(s8 *, s8 *, ...);
s8 *strcpy(s8 *, s8 *);

static inline f32 u2f(u32 x) { return x; }

void func_001DDA20(O *o, s32 kind, u32 id, s32 a3) {
    s8 buf[256];
    S t __attribute__((aligned(16)));
    Col col;
    s32 n = (s16)a3;
    Q *q;
    s32 flag;
    E *e;
    s32 v;

    t = D_001F3A90[0];
    if (id < 300) {
        t.x = o->x30;
        t.y = o->x34;
        if (id == 0) {
            o->c[0] = 0x40;
            o->c[1] = 0x40;
            o->c[2] = 0x40;
        }
        func_00181680(o->x28, o, (u8 *)o + 0x10, o->c, &t, id);
        return;
    }
    switch (id) {
    case 300: {
        S t2 __attribute__((aligned(16)));
        t2 = D_001F3AB0[0];
        q = &func_00189020(0)->q54[kind + 15];
        col.w = 0x30808080;
        t2.x = o->x38;
        t2.y = o->x3C;
        func_00181680(q->x4, q->a, q->b, &col, &t2, id);
        break;
    }
    case 301:
        q = &func_00189020(0)->q5C[kind + 15];
        col.w = 0x30808080U;
        t.m[0] = 1.1f;
        t.m[3] = 1.0f;
        t.x = o->x38 - 5.0f;
        t.y = o->x3C - 4.0f;
        func_00181680(q->x4, q->a, q->b, &col, &t, id);
        break;
    }
    switch (kind) {
    case 0:
        switch (id) {
        case 10001:
            D_004BAC0C[0] = o->x38;
            D_004BAC10[0] = o->x3C;
            D_004BABF8[0] = D_004BABF4[0] = 1.25f;
            D_004BAC1C[0] = 0x80FFFFFF;
            func_00183650(D_004BABE0);
            break;
        }
        break;
    case 1:
        switch (id) {
        case 0x12F:
            if (n > 0) {
                v = 0;
                flag = 0;
                if (n != D_004BABB0[kind]) {
                    D_004BABC8[kind] = 0;
                    D_004BABB0[kind] = n;
                }
                if (D_004BABC8[kind] < 0x80)
                    D_004BABC8[kind] += 0x10;
                col.w = 0x80808080;
                switch (D_00202378) {
                case 0:
                    break;
                case 1:
                case 4:
                    v = *func_001A97D0(n);
                    flag = 1;
                    break;
                case -1:
                case 2:
                case 3:
                case 5:
                case 6:
                    v = *func_001CC3F0(n);
                    flag = 0;
                    break;
                }
                sprintf(buf, D_001FE748, v);
                if (func_001AFBD0(n) == 0) {
                    strcpy(buf, D_001FE750);
                } else if (func_001AFBD0(n) == 1) {
                    e = &func_001AFC90()[(s16)n];
                    switch (e->x20) {
                    case 5:
                    case 6:
                        strcpy(buf, D_001FE750);
                        break;
                    default:
                        func_001848A0(n);
                        break;
                    }
                } else {
                    func_001848A0(n);
                }
                if (func_00187130(n, flag))
                    col.w = 0x80404080;
                else
                    col.w = 0x80808080;
                func_001875C0(buf, 2, col, o->x38, o->x3C, 0.9f);
            }
            break;
        case 0x130:
            v = 0;
            if ((s16)n > 0) {
                e = &func_001AFC90()[a3];
                if (e->xA == 1) {
                    v = e->x3C;
                    switch (e->x20) {
                    case 5:
                    case 6:
                        v = 0;
                        break;
                    }
                } else if (e->xA == 2) {
                    v = e->x3C;
                }
                col.w = 0x80808080;
                if (v == 0)
                    strcpy(buf, D_001FE758);
                else
                    sprintf(buf, D_001FE760, v);
                func_001875C0(buf, 0, col, o->x38, o->x3C, 0.8f);
            }
            break;
        }
        break;
    case 2:
        switch (id) {
        case 0x12E:
            if ((s16)n > 0) {
                E *e2 = &func_001AFC90()[a3];
                if (n != D_004BABB0[kind]) {
                    D_004BABC8[kind] = 0;
                    D_004BABB0[kind] = n;
                }
                if (D_004BABC8[kind] < 0x80)
                    D_004BABC8[kind] += 0x10;
                col.w = 0x80808080;
                sprintf(buf, D_001FE768, (double)(u2f(e2->x4) / 10.0f));
                func_001875C0(buf, 2, col, ((volatile O *)o)->x38, o->x3C, 0.9f);
            }
            break;
        }
        break;
    }
}

