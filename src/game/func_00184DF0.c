#include "m2c.h"
typedef struct { s32 idx; u8 pad[0x28]; f32 x, z; u8 pad2[0xC]; } Obj;
typedef struct { u32 n; Obj *e; } L;
typedef struct { u8 pad[0x10]; L *l; } R;
typedef struct { f32 x, z; } V2;
R *func_00189050(s32);
u8 *func_00189020(s32);
void func_00187B20(s32);
f32 func_0011D4A8(f32);
f32 func_0011DA18(f32);
f32 func_0011D778(f32);
void func_001829B0(Obj *, u8 *, void *, s32);
void func_00185030(void);
extern f32 sqrtf(f32);

void func_00184DF0(s32 a0, f32 ang) {
    u32 i;
    L *l;
    u8 *t;
    Obj o;

    l = func_00189050(2)->l;
    t = func_00189020(2);
    func_00187B20(0);
    for (i = 0; i < l->n; i++) {
        o = l->e[i];
        {
        V2 c = {0};
        f32 d, dx, dz, a, r;
        f32 ox, oz;
        f32 fx, fz;
        c.x = 108.0f;
        c.z = 72.0f;
        fx = o.x; fz = o.z; ox = fx - 108.0f; oz = fz - 72.0f;
        d = sqrtf(ox * ox + oz * oz);
        dx = fx - c.x;
        dz = fz - c.z;
        if (dx == 0.0f) {
            a = 0.0f;
        } else {
            a = func_0011D4A8(dx / dz);
        }
        if (dz < 0.0f) {
            a += 3.141592f;
        }
        r = a + ang;
        o.x = 108.0f + d * func_0011DA18(r);
        o.z = 72.0f + d * func_0011D778(r);
        }
        func_001829B0(&o, t + (l->e[i].idx << 3), func_00185030, a0);
    }
}
