#include "common.h"
typedef struct { u8 pad[0x10010]; Vec s[1]; } Big;
void func_001029E8(Vec *, Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
f32 sqrtf(f32);

u8 func_001434F0(Big *b, Vec *p1, Vec *p2, u8 idx) {
    Vec a;
    Vec d;
    Vec *s;
    f32 r;
    u8 hit;

    func_001029E8(&a, p2, p1);
    hit = 0;
    if (idx != 0xFF) {
        s = &b->s[idx];
        if (b->s[idx].w <= 0.0f) {
            s = NULL;
        }
        r = s->w;
        func_001029E8(&d, s, &a);
        if (sqrtf(func_00102848(&d, &d)) - r < 0.0f) {
            hit = 1;
        }
    }
    return hit;
}
