#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
extern Vec D_001F2160;
s8 *func_001A5460(s32 *);
s32 func_0013EE40(s8 *);
void func_001029E8(Vec *, Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
f32 func_0011D850(f32);
f32 sqrtf(f32);
static inline Vec *pos(s8 *o) { return o ? (Vec *)(*(s8 **)(o + 0x518) + 0x90) : &D_001F2160; }

s8 *func_001472A0(Vec *a0, Vec *a1, f32 best_, f32 ang, f32 k_) {
    s32 it;
    Vec d;
    s8 *cur;
    s8 *bestObj;
    f32 kk;
    f32 bb;
    f32 dist;
    f32 dp;
    f32 h;
    kk = k_;
    bb = best_;
    it = 0;
    cur = func_001A5460(&it);
    bestObj = NULL;
    if (cur != NULL) {
        h = 0.5f * ang;
        do {
            if (*(u16 *)cur != 0 && !func_0013EE40(cur)) {
                func_001029E8(&d, pos(cur), a0);
                d.z = 0.0f;
                d.w = 1.0f;
                dist = sqrtf(func_00102848(&d, &d));
                func_00102870(&d, &d);
                dp = func_00102848(a1, &d);
                if (!(h < func_0011D850(dp))) {
                    dist = dist * ((3.1415927f - kk * func_0011D850(dp)) / 3.1415927f);
                    if (dist < bb) {
                        bb = dist;
                        bestObj = cur;
                    }
                }
            }
            cur = func_001A5460(&it);
        } while (cur != NULL);
    }
    return bestObj;
}
