#include "actor.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; } Bits;
typedef struct { u128 q[4]; } Res;
typedef struct {
    Vec pos;
    u8 pad10[0x40];
    Vec v50;
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    u8 pad70[4];
    f32 x74;
    u8 pad78[0x10];
    f32 x88;
    u8 pad8C[4];
    s32 x90;
    u8 pad94[0x14];
    s32 xA8;
    u8 padAC[4];
    f32 xB0;
    f32 xB4;
    f32 xB8;
    u8 padBC[4];
    u8 xC0[0x10];
    u8 xD0[0x44];
    Bits f114;
} O;
extern s8 D_001F2160[];
extern Mtx D_001F2170;
extern f32 D_001FB738[];
void func_001465C0(Actor *, Vec *);
Actor *func_00146EF0(f32, s8 *, f32, Vec *, f32, s32);
void func_00146310(s8 *, Vec *, s8 *, f32 *, f32 *);
void func_00145F40(Actor *, f32 *, s32);
f32 fabsf(f32);
f32 atan2f(f32, f32);
void sceVu0CopyVector(void *, void *);
void sceVu0RotMatrixX(Mtx *, Mtx *, f32);
void sceVu0RotMatrixY(f32, Mtx *, Mtx *);
void sceVu0CopyMatrix(void *, Mtx *);
void sceVu0ScaleVector(Vec *, void *, f32);
void sceVu0AddVector(Vec *, Vec *, void *);
s32 func_00145D10(O *, Vec *, s32, s32, Res *);
s32 func_00145A80(O *, Vec *, s32, s32, Res *);
Actor *func_001A5710(void);
Actor *func_001A5660(void);
s32 func_00146C70(O *, Vec *, Actor *, s32 *, Vec *, f32);
f32 func_00146940(void *, void *);
s8 *func_00169B50(s32, s32, s32, s32);
void func_00146A70(s32, Actor *, u8, s32);
void func_00146980(s32, Res *, s32);
void func_00167710(s8 *, Vec *);
static inline f32 u2f(u32 x) { return x; }
static inline void spawn(s32 id, Vec *p) {
    s8 *q = func_00169B50(id, 0, 0, 0);
    if (q) func_00167710(q, p);
}
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define BASE() ((D_002022E4 != NULL && D_002022E4->unk518 != NULL) ? D_002022E4->unk518 + 0x1C0 : D_001F2160)
static inline s8 *base(void) {
    s32 ok = 0;
    if (D_002022E4 && D_002022E4->unk518) ok = 1;
    return ok ? D_002022E4->unk518 + 0x1C0 : D_001F2160;
}

void func_0014B1B0(O *o, f32 kk) {
    f32 ang;
    f32 k = kk;
    s32 cc;
    volatile s32 v198;
    volatile s32 v194;
    f32 ang190;
    f32 a18C;
    Mtx m;
    Res r100;
    Res rC0;
    Vec vB0;
    Vec vA0;
    Vec v90;
    Vec v80;
    Vec v70;
    Actor *r;

    f32 lim;
    f32 t;
    f32 d;
    s32 s3;
    s32 s2;
    s32 id;

    Actor *n;
    s32 ok;
    f32 w;
    f32 u;

    s8 *q;
    s8 *pos;

    func_001465C0(D_002022E4, &v80);
    r = func_00146EF0(D_001FB738[0], base(), 1.5707964f, &v80, 1.5707964f, 1);
    if (r) {
        func_001465C0(D_002022E4, &v70);
        func_00146310(base(), &v70, r ? r->unk518 + 0x90 : D_001F2160, &ang190, NULL);
    } else {
        ang190 = 0.0f;
    }
    func_00145F40(D_002022E4, &a18C, 0);
    ang = ang190 + a18C;
    ang190 = ang;
    if (3.1415927f < fabsf(ang - o->xB4)) {
        if (ang < o->xB4) {
            w = 6.2831855f;
        } else {
            w = -6.2831855f;
        }
        ang += w;
    }
    ang -= o->xB4;
    u = o->v50.x ? 0.01745f * o->v50.x : 0.0f;


    lim = k * u;
    if (lim < fabsf(ang)) {
        ang = lim * (f32)(ang < 0.0f ? -1 : 1);
    }
    ang += o->xB4;
    o->xB4 = ang;
    t = o->x60;
    sceVu0CopyVector(o, base());
    o->pos.w = 1.0f;
    o->pos.y += o->v50.y;
    o->xB0 += t * k;
    t = atan2f(o->xB0, 190.0f);
    sceVu0RotMatrixX(&m, &D_001F2170, WRAP(t));
    sceVu0RotMatrixY(WRAP(ang), &m, &m);
    sceVu0CopyMatrix(o->xC0, &m);
    sceVu0ScaleVector(&vB0, o->xD0, 10000.0f);
    sceVu0AddVector(&vB0, &vB0, o);
    s3 = func_00145D10(o, &vB0, 6, 0, &rC0);
    if (s3) {
        sceVu0CopyVector(&vB0, &rC0);
        vB0.w = 1.0f;
    }
    s2 = func_00145A80(o, &vB0, 0xFF, 0, &r100);
    if (s2) {
        sceVu0CopyVector(&vB0, &r100);
        vB0.w = 1.0f;
    }
    d = o->v50.z;
    for (n = func_001A5710(); n != NULL; n = func_001A5660()) {
        if (*(u16 *)n && func_00146C70(o, &vB0, n, &cc, &vA0, d)) {
            ok = 1;
            goto found;
        }
    }
    cc = 0;
    n = NULL;
    ok = 0;
found:
    if (ok) {
        sceVu0CopyVector(&vB0, &vA0);
    }
    if (!s2 && !ok && !s3) {
        o->x88 = u2f(o->f114.b1 = 0);
        return;
    }
    d = o->xB8;
    t = func_00146940(o, &vB0);
    if (1.5f * d < t) {
        o->x88 = u2f(o->f114.b1 = 0);
        return;
    }
    o->xB8 = t;
    if (o->xA8 == 0) {
        v198 = (s32)func_00169B50((s32)o->x68, 0, 0, 0);
        o->xA8 = v198;
    }
    if (ok) {
        id = (u32)o->x6C;
        func_00146A70(o->x90, n, cc, 0x2B);
        if (id) {
            spawn(id, (Vec *)(n ? n->unk518 + 0x90 : D_001F2160));
        }
        o->x88 = u2f(o->f114.b1 = 0);
        return;
    }
    if (s2 || s3) {
        if (s2) {
            func_00146980(o->x90, &r100, 0x2B);
            sceVu0CopyVector(&v90, &r100);
            v90.w = 1.0f;
            spawn(0x2D, &v90);
            o->x88 = u2f(o->f114.b1 = 0);
        } else {
            sceVu0CopyVector(&v90, &rC0);
            v90.w = 1.0f;
        }
        if (o->xA8) {
            v194 = o->xA8;
            func_00167710((s8 *)v194, &v90);
        }
        o->x74 = func_00146940(&v90, o);
    }
}
