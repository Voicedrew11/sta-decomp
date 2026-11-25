#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
f32 func_0013FCB0(s8 *);
void func_0013FEB0(s8 *, f32 *, f32 *);
Vec *func_00140340(s8 *);
Vec *func_00140460(s8 *);
void func_001029E8(Vec *, Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_00102A60(Vec *, Vec *);
float sqrtf(float);
static inline f32 u2f(u32 x) { return x; }

f32 func_00133D00(s8 *a, f32 *o1, f32 *o2, f32 *o3) {
    Vec d1;
    Vec d2;
    Vec d3;
    Vec h;
    f32 sx;
    f32 sy;
    f32 l1, l2;
    f32 len;
    f32 t;
    f32 y;
    f32 hl;
    f32 r;
    f32 m0, m1;
    Vec *p;
    t = func_0013FCB0(a);
    sx = 0.0f;
    sy = 0.0f;
    func_0013FEB0(a, &sx, &sy);
    func_001029E8(&d1, (Vec *)(a + 0x680), func_00140340(a));
    p = func_00140460(a);
    func_001029E8(&d2, p, func_00140340(a));
    func_001029E8(&d3, (Vec *)(a + 0x680), func_00140460(a));
    l1 = sqrtf(func_00102848(&d1, &d1));
    l2 = sqrtf(func_00102848(&d2, &d2));
    len = sqrtf(func_00102848(&d3, &d3));
    func_00102A60(&h, &d1);
    y = h.y;
    y = (y < 0.0f) ? -y : y;
    h.y = 0.0f;
    hl = sqrtf(func_00102848(&h, &h)) / sx;
    m0 = y / sy;
    if (hl < m0) {
        hl = m0;
    }
    if (hl < t) {
        r = 1.0f;
    } else if (t < 0.3f) {
        r = 0.9f;
    } else if (hl < 0.8f) {
        r = 0.8f;
    } else {
        m1 = u2f(*(u16 *)(a + 0x6B2));
        m0 = u2f(*(u16 *)(a + 0x6B0));
        if (len < m0) {
            r = 0.8f;
        } else if (len < m1) {
            r = 0.5f;
        } else {
            r = 0.2f;
        }
    }
    if (o1) {
        *o1 = t;
    }
    if (o2) {
        *o2 = hl;
    }
    if (o3) {
        *o3 = len;
    }
    return r;
}
