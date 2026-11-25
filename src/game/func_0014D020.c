#include "actor.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { Vec m[4]; } Mtx;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct { u8 pad[0x188]; Bits f188; } S90;
typedef struct { u8 pad[0x20]; f32 x20; u8 pad24[4]; f32 x28; u8 pad2C[0x14]; } Info;
typedef struct {
    Vec pos;
    u8 pad10[0x40];
    Vec v50;
    f32 x60;
    f32 x64;
    f32 x68;
    u8 pad6C[0x1C];
    f32 x88;
    u8 pad8C[4];
    S90 *p90;
    u8 pad94[0x2C];
    Mtx xC0;
    u8 pad100[0x14];
    Bits f114;
} Obj;
Actor *func_001472A0(Obj *, f32, f32, s8 *, f32, s32);
void func_00102A60(void *, void *);
void func_00102A70(void *, void *);
void func_00145F40(Actor *, f32 *, s32);
void func_00102CC8(f32, Mtx *, void *);
void func_001027B0(Vec *, Mtx *, Vec *);
void func_001029D0(Vec *, Vec *, void *);
s32 func_001470F0(Vec *, Vec *, s32, s32, s32, Vec *);
void func_00146600(Actor *, Info *);
void func_00146140(Mtx *, f32, f32);
extern s8 D_001F2150[];
extern s8 D_001F2160[];
extern s32 D_001F2170[];
static inline f32 u2f(u32 x) { return x; }

void func_0014D020(Obj *a) {
    f32 ang;
    Vec p;
    Vec e;
    Mtx m;
    Vec hit;
    Vec lo;
    Vec hi;
    Info s;
    Mtx q;
    f32 dy;
    f32 deg;
    Actor *r;
    s32 ok;
    s32 ok2;
    f32 x;
    s8 *base;

    deg = 0.0f;
    x = a->x60;
    deg = (a->x64 != deg) ? 0.01745f * a->x64 : deg;
    dy = a->x68;
    base = D_002022E4 ? D_002022E4->unk518 + 0x20 : D_001F2150;
    r = func_001472A0(a, x, deg, base, 0.0f, 0);
    if (r) {
        func_00102A60(&p, r ? r->unk518 + 0x90 : D_001F2160);
    } else {
        func_00102A60(&e, &a->v50);
        e.w = 1.0f;
        func_00145F40(D_002022E4, &ang, 0);
        func_00102CC8((3.1415927f + ang) - (f32)(s32)((3.1415927f + ang) * 0.15915494f) * 6.2831855f + ((3.1415927f + ang) < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f, &m, D_001F2170);
        func_001027B0(&e, &m, &e);
        ok = 0;
        if (D_002022E4 && D_002022E4->unk518) {
            ok = 1;
        }
        func_001029D0(&e, &e, ok ? D_002022E4->unk518 + 0x1C0 : D_001F2160);
        func_00102A60(&p, &e);
    }
    ok2 = 0;
    if (D_002022E4 && D_002022E4->unk518) {
        ok2 = 1;
    }
    func_00102A70(&lo, ok2 ? D_002022E4->unk518 + 0x1C0 : D_001F2160);
    func_00102A60(&hi, &p);
    hi.y += dy;
    if (func_001470F0(&lo, &hi, 1, 0x22, 0, &hit)) {
        a->x88 = u2f(a->f114.b1 = 0);
        a->p90->f188.b2 = 0;
    }
    func_00102A60(a, &hi);
    func_00146600(D_002022E4, &s);
    func_00146140(&q, s.x20, s.x28);
    func_00102A70(&a->xC0, &q);
}
