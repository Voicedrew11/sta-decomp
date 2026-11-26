#include "common.h"
typedef struct { f32 v[4]; } V4;
typedef struct { f32 m[8]; } V8;
typedef struct { u8 pad[4]; u32 x4; f32 x8; f32 xC; V4 v; V8 m; } Src;
typedef struct { u8 a; u8 b0:1; u8 b1:1; } W;
typedef union { u32 w; W f; } WU;
typedef struct { V4 v; V8 m; WU w; u8 pad[0xC]; } Dst;
typedef struct { u8 pad[0x30]; Vec p; u8 pad40[0x10]; u8 x50; u8 pad51[0x2F]; } El;
typedef struct {
    s32 x0;
    u8 pad4[0x6A];
    u16 x6E;
    u8 pad70[0x110];
    El *x180;
    u8 pad184[0x54];
    u8 x1D8;
} Ent;
typedef struct {
    u8 pad[0x188];
    u8 pad188[2];
    u8 b0:1;
    u8 b1:1;
} N;
typedef struct {
    Vec p;
    u8 pad10[0x40];
    f32 x50;
    u8 pad54[0xC];
    f32 x60, x64, x68, x6C;
    u8 pad70[0x20];
    N *x90;
    u8 pad94[0x14];
    f32 xA8;
    u8 padAC[4];
    u16 xB0[8];
    u8 padC0[0x54];
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1;
} O;
extern s32 D_00201E80;
extern f32 D_001F2160[];
s8 *func_001A5460(s32 *);
void func_00163C80(O *, Mtx *);
void sceVu0CopyVector(void *, void *);
void func_00123A88(void *, void *, s32);
f32 func_00146940(void *, Vec *);
void func_001B7CC0(s32, s32);
s32 func_0013EE40(s8 *);
u16 func_0013E110(s8 *);
Src *func_001A8360(s32);
void memset(void *, s32, s32);
s32 func_001675D0(N *);
void func_0013BA60(s32, void *, s8 *, s32);

void func_00149810(O *o, f32 dt) {
    f32 t;
    s32 it;
    Vec pos;
    u16 ta[8];
    Dst d;
    u16 tb[8];
    Mtx m;
    u16 id;
    s32 first;
    s32 i;
    El *el;
    s32 j;
    Ent *e;
    Ent ***pp;
    s8 *a;

    it = 0;
    a = func_001A5460(&it);
    if (o->b5) {
        func_00163C80(o, &m);
        sceVu0CopyVector(&pos, &m.m[3]);
    } else {
        sceVu0CopyVector(&pos, o);
    }
    func_00123A88(&t, &o->xA8, 4);
    first = (t == 0.0f);
    t += dt;
    if (o->x50 <= t) {
        t = 0.0f;
    }
    func_00123A88(&o->xA8, &t, 4);
    if (!first) return;
    {
        if (o->x64 == 2.0f) {
            for (i = 0, pp = (Ent ***)(&D_00201E80 + 2); i < 2; i++, pp++) {
                if (*pp != 0 && ((e = **pp)->x1D8 & 1)) {
                    for (j = 0; j < e->x6E; j++) {
                        el = &e->x180[j];
                        if (!(el->x50 & 3)) {
                            if (func_00146940(&el->p, &pos) < o->x60) {
                                func_001B7CC0(e->x0, j);
                            }
                        }
                    }
                }
            }
        }
        if (o->x64 == 2.0f) return;
        {
            while (a) {
                if (*(u16 *)a == 0 && o->x64 == 1.0f) goto next;
                if (*(u16 *)a != 0 && o->x64 == 0.0f) goto next;
                if (func_0013EE40(a)) goto next;
                if (o->x6C == 0.0f) {
                    id = func_0013E110(a);
                    sceVu0CopyVector(ta, o->xB0);
                    for (j = 0; j < 8; j++) {
                        if (id == ta[j]) {
                            id = 0xFFFF;
                            break;
                        }
                    }
                    if (id == 0xFFFF) goto next;
                }
                if (func_00146940(a ? (void *)(*(s32 *)(a + 0x518) + 0x90) : D_001F2160, &pos) < o->x60) {
                    if (o->x90->b1) {
                        e = (Ent *)((s8 *)o->x90 + 0xE80);
                    } else {
                        e = (Ent *)func_001A8360((s32)o->x68);
                        memset(&d, 0, 0x40);
                        if (e) {
                            d.v = ((Src *)e)->v;
                            d.m = ((Src *)e)->m;
                            d.w.w = ((Src *)e)->x4;
                            d.w.f.b1 = 1;
                        }
                        e = (Ent *)&d;
                    }
                    func_0013BA60(func_001675D0(o->x90), e, a, 0);
                    id = func_0013E110(a);
                    sceVu0CopyVector(tb, o->xB0);
                    for (j = 0; j < 8; j++) {
                        if (tb[j] == 0xFFFF || id == tb[j]) {
                            tb[j] = id;
                            break;
                        }
                    }
                    sceVu0CopyVector(o->xB0, tb);
                }
            next:
                a = func_001A5460(&it);
            }
        }
    }
}
