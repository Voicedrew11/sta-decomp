#include "m2c.h"
#include "actor.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { u8 pad[0x22]; u16 w22; u16 w24; } Ent;
typedef struct { u8 pad[0x13C]; u8 *tbl; } Tb;
typedef struct { Tb *t; } Hd;
typedef struct { u8 pad[0x198]; Vec *p198; } S518;
void func_00102A60(Vec *, void *);
void func_001029E8(Vec *, Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
f32 sqrtf(f32);
static inline f32 u2f(u32 x) { return x; }
s32 func_0013FCC0(Actor *o, f32 *out) {
    s32 r = 0;
    Vec v;
    f32 sz[2];
    f32 a = 4000.0f, b = 4000.0f;
    f32 len, ay;
    Ent *e;
    f32 *pz = sz;
    sz[1] = 0; sz[0] = 0;
    if (!o->flags5A1.f.b3) {
        Hd *h = (Hd *)o->unk4A8;
        e = h ? (Ent *)(h->t->tbl + o->unk4AC * 0x54) : 0;
        if (e) {
            a = u2f(e->w22);
            b = u2f(e->w24);
        }
    }
    sz[1] = a; sz[0] = b;
    func_00102A60(&v, &o->pad60C[0x54]);
    func_001029E8(&v, ((S518 *)o->unk518)->p198, &v);
    ay = v.y;
    if (ay < 0.0f) ay = -ay;
    v.y = 0;
    len = sqrtf(func_00102848(&v, &v));
    if (out) {
        out[0] = len;
        out[1] = ay;
        out[2] = sz[1];
        out[3] = sz[0];
    }
    if (ay < sz[0] && len < sz[1]) r = 1;
    {
        f32 p = ay / sz[0];
        f32 q = len / sz[1];
        if (q < p) q = p;
        o->unk6BC = q;
    }
    return r;
}
