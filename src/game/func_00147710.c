#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { f32 m[4][4]; } MtxF;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:6; } Bits;
typedef struct { u8 pad[0x138]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } R;
typedef struct { u8 pad[0x170]; s32 *x170; } S90;
typedef struct {
    Vec p;
    u8 pad10[0x40];
    f32 x50;
    f32 x54;
    f32 x58;
    u8 pad5C[4];
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    u8 pad70[4];
    f32 x74;
    u8 pad78[0x10];
    f32 x88;
    u8 pad8C[4];
    S90 *x90;
    u16 x94;
    u8 pad96[0x12];
    s8 *xA8;
    u8 padAC[4];
    f32 xB0;
    f32 xB4;
    u8 padB8[8];
    MtxF xC0;
    u8 pad100[0x14];
    Bits f114;
} O;
extern Vec D_001F2160;
extern MtxF D_001F2170;
R *func_001468F0(s32, u32);
void func_00145FB0(Vec *, R *);
void sceVu0CopyVector(void *, void *);
void sceVu0ApplyMatrix(Vec *, void *, void *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void func_00146310(O *, Vec *, void *, f32 *, f32 *);
f32 atan2f(f32, f32);
f32 fabsf(f32);
void sceVu0RotMatrixX(MtxF *, MtxF *, f32);
void sceVu0RotMatrixY(MtxF *, MtxF *, f32);
void sceVu0CopyMatrix(void *, void *);
void sceVu0ScaleVector(Vec *, void *, f32);
s32 func_001470F0(O *, Vec *, s32, s32, s32, Vec *);
f32 func_00146940(void *, void *);
s32 func_00146C70(O *, Vec *, Actor *, s32 *, Vec *, f32);
void func_00146A70(S90 *, Actor *, u8, s32);
s8 *func_00169B50(s32, s32, s32, s32);
void func_001677C0(s8 *, void *);
void func_00167710(s8 *, Vec *);
static inline s32 cur(O *o) { s32 *p = o->x90->x170; return p ? *p : 0; }
static inline s32 e10(u16 t) { return t == 0x10; }
static inline s32 e1031(u16 t) { return t == 0x10 || t == 0x31; }
static inline s32 chk(O *o) {
    s32 s;
    R *r;
    u16 a;
    u16 t;
    s32 n1, n2, n3;
    s = cur(o);
    if (s == 0) return 0;
    r = func_001468F0(s, (u32)o->x54);
    if (r == 0 || r->b6) return 0;
    a = *(u16 *)s;
    t = *(u16 *)(s + 0x6D0);
    n1 = 0; if (a == 0x2F && !e10(t) != 0) n1 = 1;
    n2 = 0; if (a == 0x43 && !e1031(t) != 0) n2 = 1;
    n1 += n2;
    n3 = 0; if (a == 0x6C && !e10(t) != 0) n3 = 1;
    n1 += n3;
    return !(n1 != 0);
}

void func_00147710(O *o, f32 dt) {
    f32 ang;
    f32 f;
    volatile f32 at;
    s32 idx;
    volatile s32 t1;
    volatile s32 t2;
    Vec v110;
    MtxF m;
    Vec vC0;
    Vec vB0;
    Vec vA0;
    MtxF m60;
    s32 c;
    f32 k;
    f32 lim;
    Actor *s0;
    s8 *e;
    s32 id;
    s8 *s3;

    if (!chk(o)) {
        o->x88 = o->f114.b1 = 0;
        return;
    }
    func_00145FB0((Vec *)&o->xC0, func_001468F0(cur(o), (u32)o->x54));
    sceVu0CopyVector(o, &o->xC0.m[3]);
    sceVu0CopyVector(&o->xC0.m[3], &D_001F2160);
    sceVu0ApplyMatrix(&v110, &o->xC0, (u8 *)o->x90 + o->x94 * 128 + 0x2C0);
    sceVu0AddVector(&o->p, &o->p, &v110);
    o->p.w = 1.0f;
    c = 0;
    if (D_002022E4 != 0 && D_002022E4->unk518 != 0) c = 1;
    func_00146310(o, (Vec *)&o->xC0.m[2], c ? (void *)(D_002022E4->unk518 + 0x1C0) : (void *)&D_001F2160, &ang, 0);
    at = atan2f(o->xC0.m[2][0], o->xC0.m[2][2]);
    ang += at;
    if (3.1415927f < fabsf(ang - o->xB4)) {
        if (ang < o->xB4) k = 6.2831855f;
        else k = -6.2831855f;
        ang += k;
    }
    ang -= o->xB4;
    lim = dt * (o->x50 ? 0.0174499992f * o->x50 : 0.0f);
    if (lim < fabsf(ang)) {
        ang = lim * (f32)(ang < 0.0f ? -1 : 1);
    }
    o->xB4 = ang = ang + o->xB4;
    o->xB0 += o->x60 * dt;
    f = atan2f(o->xB0, 190.0f);
    sceVu0RotMatrixX(&m, &D_001F2170, WRAP(f));
    sceVu0RotMatrixY(&m, &m, WRAP(ang));
    sceVu0CopyMatrix(&o->xC0, &m);
    sceVu0ScaleVector(&vB0, &o->xC0.m[1], 10000.0f);
    sceVu0AddVector(&vB0, &vB0, &o->p);
    if (func_001470F0(o, &vB0, 3, 6, 0, &vC0)) f = func_00146940(o, &vC0);
    else f = -1.0f;
    sceVu0ScaleVector(&vA0, &o->xC0.m[1], f);
    sceVu0AddVector(&vA0, &vA0, &o->p);
    s0 = D_002022E4;
    if (func_00146C70(o, &vA0, s0, &idx, 0, o->x58)) {
        func_00146A70(o->x90, s0, idx, 0x2B);
        o->x88 = o->f114.b1 = 0;
        id = (s32)o->x6C;
        if (id != 0) {
            e = func_00169B50(id, 0, 1, 0);
            if (e != 0) {
            s3 = (s8 *)s0->unk51C + idx * 0x170;
            sceVu0CopyMatrix(&m60, &D_001F2170);
            sceVu0CopyVector(m60.m[3], s3 + 0xA0);
            func_001677C0(e, s0 ? (void *)(s0->unk518 + 0x60) : (void *)&D_001F2170);
            }
        }
    }
    if (o->xA8 == 0) {
        t1 = (s32)func_00169B50((s32)o->x68, 0, 0, 0);
        o->xA8 = (s8 *)t1;
    }
    if (o->xA8 != 0) {
        t2 = (s32)o->xA8;
        func_00167710((s8 *)t2, &vC0);
    }
    o->x74 = func_00146940(&vC0, o);
}
