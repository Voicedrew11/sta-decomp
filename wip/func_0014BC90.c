#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { Vec m[4]; } Mtx;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct {
    Vec pos;
    u8 pad10[0x54];
    f32 x64;
    u8 pad68[0x50];
    f32 xB8;
    f32 xBC;
    u8 padC0[0x54];
    Bits f114;
} Obj;
u16 *func_001A5460(s32 *);
u32 func_0013E110(u16 *);
Vec *func_0013FFA0(u16 *);
void func_00102A60(void *, void *);
void func_00163C80(Obj *, Mtx *);
void func_001029E8(Vec *, Vec *, Vec *);
float sqrtf(float);
static inline f32 u2f(u32 x) { return x; }
static inline f32 h(f32 dist, f32 r) { return (r - dist) / (2.0f * r); }

void func_0014BC90(Obj *a) {
    s32 it;
    Vec d;
    Vec t;
    Vec s;
    Mtx m;
    u16 id;
    u16 *p;
    f32 k;
    f32 r;

    r = 0.05f;
    id = a->x64;
    it = 0;
    for (p = func_001A5460(&it); p != 0; p = func_001A5460(&it)) {
        if (*p != 0 && *p == id) break;
    }
    if (p) {
        a->xB8 = u2f(func_0013E110(p));
    } else {
        a->xB8 = 0.0f;
    }
    if (p) {
        func_00102A60(&t, func_0013FFA0(p));
        if (a->f114.b5) {
            func_00163C80(a, &m);
            func_00102A60(&s, &m.m[3]);
        } else {
            func_00102A60(&s, a);
        }
        func_001029E8(&d, &t, &s);

        k = (r - sqrtf(d.x * d.x + d.z * d.z)) / (2.0f * r) * 0.001f;
    } else {
        k = 0.0f;
    }
    a->xBC = k;
}
