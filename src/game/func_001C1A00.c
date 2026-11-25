#include "common.h"
#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { u8 pad[0x94]; u8 x94; } S390;
typedef struct { u8 pad[0x20]; f32 x20; f32 x24; } O18;
typedef struct {
    u8 pad0[0x18];
    O18 *x18;
    u8 pad1C[0x390 - 0x1C];
    S390 *x390;
    s8 x394;
    u8 pad395[0x39C - 0x395];
    u8 x39C;
    u8 pad39D[3];
    u8 x3A0;
    Flags8 f3A1;
    u8 pad3A2[0x3CD - 0x3A2];
    s8 x3CD;
    u8 pad3CE[2];
    f32 x3D0;
    u8 x3D4;
    u8 x3D5;
    u8 pad3D6[0xA];
    u16 x3E0[8];
} P;
typedef struct { u8 pad[0x54]; s16 x54; s16 x56; } T;
typedef struct { u8 pad[3]; u8 x3; } U;
typedef struct { u8 pad[0x2C]; f32 x2C; u32 x30; u32 x34; } K;
typedef struct { u8 b0:4; u8 f:3; u8 b7:1; } F30;
typedef struct { u16 h[6]; u8 padC[4]; u8 y[0x20]; F30 f30; u8 pad31[0xF]; } X;
extern Mtx D_001F2170;
u8 func_001A9450(void);
s32 func_001CCD90(s32);
T *func_001AFC40(s16);
s16 func_001CBC20(s16);
void func_001C6590(s32);
U *func_001D1E10(void);
void func_001CA930(void);
void func_001CBA80(s16, u8);
void func_001CA6F0(void);
s32 func_001D1E00(u8);
s32 func_001D1DD0(u8);
s8 *func_00169B50(s16, s32, s32, s32);
void func_00102A70(Mtx *, Mtx *);
void func_00102C20(Mtx *, Mtx *, f32);
void func_00102CC8(Mtx *, Mtx *, f32);
void func_00102A60(Vec *, void *);
void func_001677C0(s8 *, Mtx *);
void func_00167600(s8 *, Actor *);
void func_00123C40(void *, s32, s32);
void func_001CEBF0(X *, u8 *, s8);
s32 func_001CC250(s32);
void func_001672B0(s8 *, X *);
void func_001CA860(void);
static inline P *cur(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (P *)(D_002022E4->unk518 + 0x180);
}

void func_001C1A00(Actor *a0, K *a1) {
    P *s3;
    u32 m1;
    T *t;
    s16 r;
    u32 m2;
    s16 idx;
    s32 v;
    s32 k;
    s8 *o;
    P *c;
    X x;
    Mtx m;

    s3 = (P *)(a0->unk518 + 0x180);
    if (func_001A9450() < 2) m1 = 4; else m1 = 0x800;
    if (func_001A9450() < 2) m2 = 4; else m2 = 0x800;
    if (s3->f3A1.f.b7) {
        if (s3->x3D5 == 3) func_001C6590(6);
        return;
    }
    t = func_001AFC40(func_001CCD90(s3->x390->x94 & 1));
    idx = t->x54;
    r = func_001CBC20(idx);
    if (s3->x3D5 == 0) {
        if (func_001D1E10()->x3 > 0 || r > 0) {
            if (a1->x30 & m1) {
                func_001C6590(1);
                s3->x3D4 = 10;
                func_001CA930();
            }
        }
    } else if (s3->x3D5 == 3) {
    if (func_001D1E10()->x3 <= 0) {
        if (r <= 0) {
            func_001C6590(6);
        } else {
            func_001C6590(5);
            s3->x3D4 = 10;
            v = s3->x394;
            v = (v < r) ? v : r;
            func_001D1E10()->x3 = v;
            func_001CBA80(idx, func_001D1E10()->x3);
            func_001CA6F0();
        }
        return;
    }
    if (func_001D1E00(s3->x39C) && s3->x3D0 <= 0.17f) m2 = 0;
    if ((a1->x30 & m2) || (func_001D1DD0(s3->x39C) && (a1->x34 & m2))) {
        k = t->x56;
        if (k != 0) {
        o = func_00169B50(k, 0, 1, 0);
        if (o != 0) {
            func_00102A70(&m, &D_001F2170);
            func_00102C20(&m, &m, WRAP(-WRAP(s3->x18->x20)));
            func_00102CC8(&m, &m, WRAP(WRAP(s3->x18->x24)));
            func_00102A60(&m.m[3], s3->x18);
            m.m[3].w = 1.0f;
            func_001677C0(o, &m);
            func_00167600(o, a0);
            c = cur();
            if (c != 0) {
                func_00123C40(&x, 0, 0x40);
                func_001CEBF0(&x, x.y, c->x3CD);
                x.f30.f = func_001CC250(func_001CCD90(c->x390->x94 & 1));
            }
            if (s3->x39C == 11) {
                x.h[0] >>= 2;
                x.h[1] >>= 2;
                x.h[2] >>= 2;
                x.h[3] >>= 2;
                x.h[4] >>= 2;
                x.h[5] >>= 2;
            }
            func_001672B0(o, &x);
        }
        }
        func_001C6590(4);
        s3->x3D4 = 10;
        func_001D1E10()->x3--;
        c = cur();
        if (c != 0) {
            c->x3E0[0] = 0xFFFF; c->x3E0[1] = 0xFFFF; c->x3E0[2] = 0xFFFF; c->x3E0[3] = 0xFFFF;
            c->x3E0[4] = 0xFFFF; c->x3E0[5] = 0xFFFF; c->x3E0[6] = 0xFFFF; c->x3E0[7] = 0xFFFF;
        }
        func_001CA860();
    } else {
    if (func_001A9450() < 2) {
        if (!(a1->x2C <= 0.5f)) s3->x3D4--; else s3->x3D4 = 10;
    } else {
        s3->x3D4 = 10;
        if (a1->x30 & 0x400) s3->x3D4 = 0;
    }
    if (s3->x3D4 <= 0) func_001C6590(6);
    }
    }
}
