#include "m2c.h"
typedef struct { u8 pad[0x10]; f32 pos[3]; u8 pad1C[0x14]; f32 rot[3]; f32 rz; u8 pad40[0x20]; f32 range[3]; f32 ang; } O;
typedef struct { f32 m[4][4]; } M;
u32 func_0015ED20(void);
void func_00163C80(O *, M *);
void sceVu0ApplyMatrix(f32 *, M *, f32 *);

static inline f32 sc(f32 x) { return x ? 0.01745f * x : 0.0f; }
void func_0014C890(O *o) {
    f32 v[4];
    M m;
    s32 i;

    f32 *r;
    f32 *q;
    f32 *p;

    p = v;
    q = p;
    r = (f32 *)o;
    for (i = 0; i < 3; i++) {
        *q++ = r[0x18] * (0.000015259022f * (f32)(func_0015ED20() & 0xFFFF) - 0.5f);
        r++;
    }
    v[3] = 0.0f;
    func_00163C80(o, &m);
    sceVu0ApplyMatrix(v, &m, v);
    o->pos[0] += p[0];
    o->pos[1] += v[1];
    o->pos[2] += v[2];
    if (o->ang != -1.0f) {
        for (i = 0; i < 3; i++) {
            o->rot[i] = 0.000015259022f * (f32)(func_0015ED20() & 0xFFFF);
        }
        o->rz += (0.000015259022f * (f32)(func_0015ED20() & 0xFFFF) - 0.5f) * sc(o->ang);
    }
}
