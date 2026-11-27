#include "common.h"
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
float sqrtf(float);
typedef struct { u8 pad[0x10010]; Vec tbl[1]; } Obj;
static inline Vec *get(Obj *o, u8 i)
{ Vec *p = &o->tbl[i]; if (o->tbl[i].w <= 0.0f) p = 0; return p; }
static inline s32 ok(Obj *o, u8 i) { return o->tbl[i].w > 0.001f; }
static inline u8 next(Obj *o, u8 *it) {
    u8 r = 0xFF;
    u8 i = *it;
    while (i < 0xFF) {
        if (ok(o, i)) {
            r = i++;
            break;
        }
        i++;
    }
    *it = i;
    return r;
}

u8 Enemy_FindNearestWaypoint_1_00143610(Obj *o, Vec *pos) {
    Vec d;
    u8 best;
    u8 it;
    u8 i;
    f32 bd;
    f32 w;
    f32 dist;
    Vec *p;
    best = 0xFF;
    bd = -100000.0f;
    it = 0;
    i = next(o, &it);
    while (i != 0xFF) {
        p = get(o, i);
        w = p->w;
        sceVu0SubVector(&d, p, pos);
        dist = sqrtf(sceVu0InnerProduct(&d, &d)) - w;
        if (best == 0xFF || dist < bd) {
            best = i;
            bd = dist;
        }
        i = next(o, &it);
    }
    return best;
}
