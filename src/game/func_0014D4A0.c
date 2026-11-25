#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef union { u32 w; struct { u16 id; u8 f2; u8 f3; } s; } K;
typedef struct {
    Vec p;
    Vec v;
    u8 pad20[0x40];
    f32 x60;
    u8 pad64[0x44];
    K xA8;
    u8 padAC[4];
    Vec xB0;
} O;
typedef struct { u8 pad[0x20]; Vec a; Vec b; } M;
extern f32 D_001FB738[];
s8 *func_001A5460(s32 *);
u16 func_0013E110(s8 *);
s32 func_0013EE40(s8 *);
void func_00163C80(O *, M *);
s8 *func_00146EF0(f32, Vec *, f32, Vec *, f32, s32);
Vec *func_0013FFA0(s8 *);
void func_00102A60(Vec *, Vec *);
void func_001029E8(Vec *, Vec *, void *);
f32 func_00102848(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_001029D0(Vec *, Vec *, Vec *);
float sqrtf(float);
static inline s8 *find(s32 *it, K *k) {
    s8 *p;
    u16 kid;
    *it = 0;
    p = func_001A5460(it);
    if (p != NULL) {
    kid = k->s.id;
    do {
        if (*(u16 *)p != 0 && func_0013E110(p) == kid) {
            return p;
        }
        p = func_001A5460(it);
    } while (p != NULL);
    }
    return NULL;
}

void func_0014D4A0(O *o) {
    K k;
    s32 it;
    K k2;
    Vec b0;
    M m;
    Vec v60;
    Vec v50;
    s8 *p;
    u16 id;
    f32 s;
    f32 h;
    f32 t;

    k.w = o->xA8.w;
    p = NULL;
    if (*(u16 *)&k != 0) {
        p = find(&it, &k);
    }
    if (p == NULL || (p != NULL && func_0013EE40(p) != 0)) {
        func_00163C80(o, &m);
        p = func_00146EF0(D_001FB738[0], &m.b, 1.5707964f, &m.a, 1.5707964f, 1);
        if (p != NULL) {
            s = o->xB0.w;
            id = func_0013E110(p);
            k2.w = o->xA8.w;
            k2.s.id = id;
            k2.s.f2 = id == 0 && k2.s.f2 == 1;
            k2.s.f3 = 0;
            o->xA8.w = k2.w;
            o->xB0.w = s;
        }
    }
    if (p != NULL) {
        func_00102A60(&b0, func_0013FFA0(p));
    } else if (k.s.f2) {
        func_00102A60(&b0, &o->xB0);
        b0.w = 1.0f;
    }
    if (p != NULL || k.s.f2) {
        h = o->x60;
        t = o->xB0.w;
        func_001029E8(&v60, &b0, o);
        s = sqrtf(func_00102848(&o->v, &o->v));
        func_00102870(&v50, &v60);
        func_00102A18(&v50, &v50, -1.0f * t);
        func_001029D0(&o->v, &o->v, &v50);
        func_00102870(&o->v, &o->v);
        func_00102A18(&o->v, &o->v, s);
        o->xB0.w = o->xB0.w - h;
    }
}
