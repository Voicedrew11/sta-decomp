#include "common.h"
typedef struct { u8 pad[0x10010]; Vec s[1]; } Big;
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 sqrtf(f32);

u8 func_001434F0(Big *b, Vec *p1, Vec *p2, u8 idx) {
    Vec a;
    Vec d;
    Vec *s;
    f32 r;
    u8 hit;

    sceVu0SubVector(&a, p2, p1);
    hit = 0;
    if (idx != 0xFF) {
        s = &b->s[idx];
        if (b->s[idx].w <= 0.0f) {
            s = NULL;
        }
        r = s->w;
        sceVu0SubVector(&d, s, &a);
        if (sqrtf(sceVu0InnerProduct(&d, &d)) - r < 0.0f) {
            hit = 1;
        }
    }
    return hit;
}
