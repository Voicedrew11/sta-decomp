#include "actor.h"
typedef struct { u8 pad[8]; u16 id; u8 pad2[2]; f32 xC; f32 x10; f32 x14; } Mdl;
typedef struct { u8 pad0[0x30]; f32 x30; u8 pad34[0x2C]; Vec v60; } S18;
typedef struct { u8 pad0[0x280]; Vec v280; u8 pad290[0x3C0 - 0x290]; Vec v3C0; u8 pad3D0[0x20]; f32 x3F0; f32 x3F4; f32 x3F8; } S2C;
typedef struct { u8 pad0[0x94]; u8 b0:1; } S390;
typedef struct {
    u8 pad0[0xC];
    s32 *xC;
    u8 pad10[8];
    S18 *x18;
    u8 pad1C[0xC];
    Mdl *x28;
    S2C *x2C;
    u8 pad30[0x380 - 0x30];
    f32 x380;
    u8 pad384[0x390 - 0x384];
    S390 *x390;
    u8 pad394[0x39C - 0x394];
    u8 x39C;
    u8 pad39D[4];
    u8 a0:5; u8 a5:1; u8 a6:2;
    u8 pad3A2[0x3AD - 0x3A2];
    s8 x3AD;
    s8 x3AE;
    u8 pad3AF[0x3CC - 0x3AF];
    u8 x3CC;
    u8 x3CD;
    u8 x3CE;
    u8 x3CF;
    u8 pad3D0[4];
    u8 x3D4;
    u8 x3D5;
    u8 c0:1; u8 c1:1; u8 c2:1; u8 c3:1; u8 c4:1; u8 c5:1; u8 c6:1; u8 c7:1;
    u8 d0:1; u8 d1:2;
} P;
extern Mtx D_001F2170;
f32 func_00173F70(s32, u16);
s32 func_001D1DD0(u8);
s32 func_00125538(void);
void func_00171B70(Mdl *, u16, f32);
void sceVu0RotMatrixX(Mtx *, Mtx *, f32);
void sceVu0CopyMatrix(void *, void *);
s32 func_001A9440(void);
void sceVu0MulMatrix(Vec *, Mtx *, Vec *);
void func_00171540(Mdl *, Mtx *);
s32 func_001D1D50(u8);
s32 func_001D1DA0(u8);
void func_001C6250(Actor *);
void func_001C5FB0(Actor *);
void func_001C6470(Actor *);
void func_001CA950(void);
void func_0012DA80(void);
void func_001CEDC0(s32);
void func_001CE7D0(P *, s32);
void func_0019A840(void);
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

void func_001C5750(Actor *a, f32 dt) {
    Mtx m1;
    Mtx m2;
    P *p;
    s32 r;
    f32 lim;
    s32 *h;

    p = (P *)(a->unk518 + 0x180);
    h = p->xC;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    if (p->d1 < 2) {
        lim = func_00173F70(*h, p->x28->id);
        p->x28->x10 = p->x28->xC;
        if (p->d0) {
            p->x28->xC -= dt * p->x28->x14;
            if (p->c7) {
                if (p->x28->xC < 0.0f) {
                    do {
                        p->x28->xC += lim;
                    } while (p->x28->xC < 0.0f);
                }
            } else if (p->x28->xC < 0.0f) {
                p->x28->xC = 0.0f;
                p->d1++;
            }
        } else {
            p->x28->xC += dt * p->x28->x14;
            if (p->c7) {
                while (p->x28->xC > lim) {
                    p->x28->xC -= lim;
                }
            } else if (!(p->x28->xC <= lim)) {
                p->x28->xC = lim;
                p->d1++;
            }
        }
    }
    if (func_001D1DD0(p->x39C) && p->x3D5 == 4) {
        r = func_00125538() % 2;
        p->x3AD = r * -(func_00125538() % 2);
        r = func_00125538() % 2;
        p->x3AE = r * -(func_00125538() % 2);
    }
    func_00171B70(p->x28, p->x28->id, p->x28->xC);
    p->x2C->x3F4 += 25.0f;
    p->x2C->x3F8 += -5.0f;
    p->x2C->x3F0 += p->x3AD;
    p->x2C->x3F4 += p->x3AE;
    sceVu0RotMatrixX(&m1, &D_001F2170, WRAP(WRAP(-1.0f * p->x18->x30)));
    m1.m[3].w = 1.0f;
    sceVu0CopyMatrix(&m2, &D_001F2170);
    if (func_001A9440()) {
        if (p->a5) {
            m2.m[3].y += 2.0f * p->x380;
        } else {
            m2.m[3].y += p->x380;
        }
    }
    if (p->x390->b0) {
        p->x2C->v3C0.x *= -1.0f;
    }
    sceVu0MulMatrix(&p->x2C->v3C0, &m1, &p->x2C->v3C0);
    sceVu0MulMatrix(&p->x2C->v3C0, &m2, &p->x2C->v3C0);
    sceVu0CopyMatrix(&p->x2C->v280, &p->x18->v60);
    func_00171540(p->x28, &D_001F2170);
    if (func_001D1D50(p->x39C)) {
        if (func_001D1DA0(p->x39C)) {
            func_001C6250(a);
        } else {
            func_001C5FB0(a);
        }
    } else {
        func_001C6470(a);
    }
    if (p->c3 && p->x3D5 == 0) {
        p->x390->b0 ^= 1;
        p->c3 = 0;
        p->c4 = 1;
        p->x3D4 = 0;
        p->x3CC = 0;
        p->x3CD = 0;
        p->x3CE = 0;
        p->x3CF = 0;
        func_001CA950();
        func_0012DA80();
        func_001CEDC0(3);
        func_001CE7D0(p, 1);
        func_0019A840();
    }
}
