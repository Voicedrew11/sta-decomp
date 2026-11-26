#include "actor.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { s32 x0; s32 x4; u8 pad8[0x24]; f32 x2C; f32 x30; f32 x34; f32 x38; Col x3C; } E;
typedef struct { u32 n; E *e; } L;
typedef struct { u8 pad[0x28]; f32 x28; } P;
typedef struct { s32 x0; P *p; } T;
typedef struct { u8 pad[8]; f32 x8; u8 padC[4]; } F;
typedef struct { u8 pad[0x394]; s8 x394; s8 x395; s8 x396; s8 x397; } S;
extern F D_004A2CE0[];
extern F D_004A28E0[];
extern s8 D_001FD408[];
extern s8 D_001FD410[];
extern s8 D_001FD418[];
extern s8 D_001FD420[];
extern f32 D_001F3060[];
extern f32 D_001F3070[];
extern s32 D_002021D8;
extern s32 D_002021DC;
extern f32 D_002021C4;
extern f32 D_002021C8;
s16 *func_001C9BA0(void);
void func_0019B8D0(void);
s32 func_001C9BF0(void);
void func_00182C10(E *, T *);
void func_0019BBE0(E *, T *, s32);
void func_001875C0(f32, s8 *, f32, f32, s32, u32);
void func_00187680(f32, s8 *, f32, f32, s32, s32, u32);
f32 func_00187770(f32, f32, f32);
void func_001256E0(s8 *, s8 *, ...);
#define O o

void func_0019A920(L *l, T *t) {
    f32 o = 0.0f;

    s16 *fp;
    S *s;
    u32 i;
    s32 id;
    u8 j;
    E *e;
    Col col;
    s8 buf1[0x100];
    s8 buf2[0x100];

    fp = func_001C9BA0();
    func_0019B8D0();
    if (func_001C9BF0()) {
        s = (S *)(D_002022E4->unk518 + 0x180);
    } else {
        return;
    }
    for (i = 0; i < l->n; i++) {
        id = l->e[i].x4;
        if (id == 5000) {
            for (j = 0; j < s->x394; j++) {
                l->e[i].x34 = 1.2f;
                l->e[i].x38 = 1.2f;
                l->e[i].x2C = 28 + j * 13;
                l->e[i].x30 = 16 + (j % 2) * 2;
                l->e[i].x3C.w = 0x80FFFFFF;
                func_00182C10(&l->e[i], &t[j % 3 + 8]);
            }
            for (j = 0; j < s->x396; j++) {
                l->e[i].x34 = 1.2f;
                l->e[i].x38 = 1.2f;
                l->e[i].x2C = 28 + j * 13;
                l->e[i].x30 = 16 + (j % 2) * 2;
                l->e[i].x3C.w = 0x80FFFFFF;
                D_004A2CE0[j].x8 += 16.0f;
                if (D_004A2CE0[j].x8 > 128.0f) D_004A2CE0[j].x8 = 128.0f;
                l->e[i].x3C.c.a = (s32)D_004A2CE0[j].x8;
                func_00182C10(&l->e[i], &t[j % 3 + 5]);
            }
            for (; j < s->x394; j++) {
                l->e[i].x34 = 1.2f;
                l->e[i].x38 = 1.2f;
                l->e[i].x2C = 28 + j * 13;
                l->e[i].x30 = 16 + (j % 2) * 2;
                l->e[i].x3C.w = 0x80FFFFFF;
                D_004A2CE0[j].x8 -= 16.0f;
                if (D_004A2CE0[j].x8 < 0.0f) D_004A2CE0[j].x8 = 0.0f;
                l->e[i].x3C.c.a = (s32)D_004A2CE0[j].x8;
                func_00182C10(&l->e[i], &t[j % 3 + 5]);
            }
        }
        if (id == 6000) {
            for (j = 0; j < s->x395; j++) {
                l->e[i].x34 = 1.2f;
                l->e[i].x38 = 1.2f;
                l->e[i].x2C = 28 + j * 13;
                l->e[i].x30 = 69 - (j % 2) * 2;
                l->e[i].x3C.w = 0x80FFFFFF;
                func_00182C10(&l->e[i], &t[j % 3 + 14]);
            }
            for (j = 0; j < s->x397; j++) {
                l->e[i].x34 = 1.2f;
                l->e[i].x38 = 1.2f;
                l->e[i].x2C = 28 + j * 13;
                l->e[i].x30 = 69 - (j % 2) * 2;
                l->e[i].x3C.w = 0x80FFFFFF;
                D_004A28E0[j].x8 += 16.0f;
                if (D_004A28E0[j].x8 > 128.0f) D_004A28E0[j].x8 = 128.0f;
                l->e[i].x3C.c.a = (s32)D_004A28E0[j].x8;
                func_00182C10(&l->e[i], &t[j % 3 + 11]);
            }
            for (; j < s->x395; j++) {
                l->e[i].x34 = 1.2f;
                l->e[i].x38 = 1.2f;
                l->e[i].x2C = 28 + j * 13;
                l->e[i].x30 = 69 - (j % 2) * 2;
                l->e[i].x3C.w = 0x80FFFFFF;
                D_004A28E0[j].x8 -= 16.0f;
                if (D_004A28E0[j].x8 < 0.0f) D_004A28E0[j].x8 = 0.0f;
                l->e[i].x3C.c.a = (s32)D_004A28E0[j].x8;
                func_00182C10(&l->e[i], &t[j % 3 + 11]);
            }
        }
        if (id == 3000) {
            l->e[i].x2C = 33.0f;
            col = l->e[i].x3C;
            col.c.a = (s32)D_001F3060[0];
            func_001875C0(O + l->e[i].x2C, D_001FD408, O + l->e[i].x30, 1.0f, 0, col.w);
        }
        if (id == 3010) {
            func_001256E0(buf1, D_001FD410, D_002021D8);
            col = l->e[i].x3C;
            col.c.a = (s32)D_001F3060[0];
            func_00187680(O + (l->e[i].x2C - 120.0f), buf1, O + l->e[i].x30, 1.0f, 0, 16, col.w);
            func_001256E0(buf1, D_001FD418, fp[0]);
            func_00187680(O + (l->e[i].x2C - 36.0f), buf1, O + l->e[i].x30, 1.0f, 0, 16, col.w);
        }
        if (id == 4000) {
            l->e[i].x2C = 28.0f;
            col = l->e[i].x3C;
            col.c.a = (s32)D_001F3070[0];
            func_001875C0(l->e[i].x2C, D_001FD420, l->e[i].x30, 1.0f, 0, col.w);
        }
        if (id == 4010) {
            func_001256E0(buf2, D_001FD410, D_002021DC);
            col = l->e[i].x3C;
            col.c.a = (s32)D_001F3070[0];
            func_00187680(l->e[i].x2C - 120.0f, buf2, l->e[i].x30, 1.0f, 0, 16, col.w);
            func_001256E0(buf2, D_001FD418, fp[1]);
            func_00187680(l->e[i].x2C - 36.0f, buf2, l->e[i].x30, 1.0f, 0, 16, col.w);
        }
        if (id == 1010) {
            D_002021C4 = func_00187770(D_002021C4, (f32)fp[2] / (f32)fp[0], 4.0f);
            l->e[i].x3C.w = 0x80A0A0A0;
            l->e[i].x34 = D_002021C4;
            t[l->e[i].x0].p->x28 = 170.0f * D_002021C4;
            func_00182C10(&l->e[i], &t[l->e[i].x0]);
        }
        if (id == 2010) {
            D_002021C8 = func_00187770(D_002021C8, (f32)fp[3] / (f32)fp[1], 4.0f);
            l->e[i].x3C.w = 0x80A0A0A0;
            l->e[i].x34 = D_002021C8;
            t[l->e[i].x0].p->x28 = 170.0f * D_002021C8;
            func_00182C10(&l->e[i], &t[l->e[i].x0]);
        }
        if (id == 1000) {
            l->e[i].x3C.w = 0x80A0A0A0;
            func_00182C10(&l->e[i], &t[l->e[i].x0]);
        }
        if (id == 2000) {
            l->e[i].x3C.w = 0x80A0A0A0;
            func_00182C10(&l->e[i], &t[l->e[i].x0]);
        }
        if (id == 0) {
            func_00182C10(&l->e[i], &t[l->e[i].x0]);
        }
        func_0019BBE0(&l->e[i], &t[l->e[i].x0], id);
    }
}
