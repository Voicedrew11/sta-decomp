#include "common.h"
void sceVu0Normalize(Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sqrtf(f32);
void Actor_ClosestOnSegment_0_001A58A0(Vec *a, Vec *b, Vec *o1, Vec *o2, f32 f) {
    Vec p;
    Vec q;
    Vec d;
    f32 l;
    p.x = a->x; p.y = a->y; p.z = a->z; p.w = 0.0f;
    q.x = b->x; q.y = b->y; q.z = b->z; q.w = 0.0f;
    sceVu0SubVector(&d, &q, &p);
    l = sqrtf(sceVu0InnerProduct(&d, &d));
    sceVu0CopyVector(o1, &p);
    sceVu0Normalize(o2, &d);
    o2->w = l;
    o1->w = f;
}
