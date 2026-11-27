#include "common.h"
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
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
    sceVu0SubVector(&d, get(o, b), get(o, a));
    sceVu0SubVector(&e, pos, get(o, a));
    len = sqrtf(sceVu0InnerProduct(&d, &d));
    sceVu0Normalize(&d, &d);
    {
        f32 t = sceVu0InnerProduct(&d, &e);
        if (!(t < 0.0f) && t <= len) return 1;
    }
    r = 0;
    if (a != 0xFF) {
        p = get(o, a);
        w = p->w;
        sceVu0SubVector(&f, p, pos);
        if (sqrtf(sceVu0InnerProduct(&f, &f)) - w < 0.0f) r = 1;
    }
    return r;
    }
    return 1;
}

u8 Enemy_FindWaypointDir_0_001432F0(Obj *o, Vec *pos, u8 a, u8 b)
{ return inner(o, pos, a, b); }
