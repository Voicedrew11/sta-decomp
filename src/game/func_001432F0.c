#include "common.h"
void func_001029E8(Vec *, Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
float sqrtf(float);
typedef struct { u8 pad[0x10010]; Vec tbl[1]; } Obj;
static inline Vec *get(Obj *o, u8 i)
{ Vec *p = &o->tbl[i]; if (o->tbl[i].w <= 0.0f) p = 0; return p; }
static inline u8 inner(Obj *o, Vec *pos, u8 a, u8 b) {
    Vec d;
    Vec e;
    Vec f;
    f32 len;
    f32 w;
    u8 r;
    Vec *p;
    if (a == b) return 1;
    if (a != 0xFF && b != 0xFF) {
    func_001029E8(&d, get(o, b), get(o, a));
    func_001029E8(&e, pos, get(o, a));
    len = sqrtf(func_00102848(&d, &d));
    func_00102870(&d, &d);
    {
        f32 t = func_00102848(&d, &e);
        if (!(t < 0.0f) && t <= len) return 1;
    }
    r = 0;
    if (a != 0xFF) {
        p = get(o, a);
        w = p->w;
        func_001029E8(&f, p, pos);
        if (sqrtf(func_00102848(&f, &f)) - w < 0.0f) r = 1;
    }
    return r;
    }
    return 1;
}

u8 func_001432F0(Obj *o, Vec *pos, u8 a, u8 b)
{ return inner(o, pos, a, b); }
