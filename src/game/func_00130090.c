#include "m2c.h"
typedef struct {
    s32 id;     /* 0x00 */
    s32 h;      /* 0x04 */
    f32 r;      /* 0x08 */
    f32 pad0C;
    f32 f10;    /* 0x10 */
    f32 f14;    /* 0x14 */
    f32 f18;    /* 0x18 */
    s8 s1C;     /* 0x1C */
    f32 pos[4]; /* 0x20 */
    f32 v[4];   /* 0x30 */
} S;
void func_001027B0(f32 *, f32 *, f32 *);
f32 func_00102848(f32 *, f32 *);
f32 func_0011D778(f32);
f32 func_0011DA18(f32);
s32 func_00131060(s32);
s32 func_00131560(s32, s8, f32 *);
u32 func_0015ED20(void);
extern f32 D_0026F090[];
extern f32 D_002F16C0[];

void func_00130090(S *o) {
    f32 d[4];
    f32 a;

    if (o->h == -1) {
        func_001027B0(d, D_002F16C0, o->pos);
        a = func_00102848(d, d);
        if (a < o->r * o->r) {
            if (!(o->f10 <= 0.000015259022f * (f32)(func_0015ED20() & 0xFFFF) + o->f14 * (0.000015259022f * (f32)(func_0015ED20() & 0xFFFF) - 0.5f))) {
                a = 6.283184f * (0.000015259022f * (f32)(func_0015ED20() & 0xFFFF) - 0.5f);
                o->v[0] = o->f18 * func_0011D778(a);
                o->v[1] = o->pos[1];
                o->v[2] = o->f18 * func_0011DA18(a);
                o->v[3] = 1.0f;
                func_001027B0(o->v, D_0026F090, o->v);
                o->h = func_00131560(o->id, o->s1C, o->v);
            }
        }
    } else if (func_00131060(o->h) == 0) {
        o->h = -1;
    }
}
