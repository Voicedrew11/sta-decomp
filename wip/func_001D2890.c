#include "common.h"
typedef struct { Vec a; Vec b; } Ray;
typedef struct { Vec p; Vec d; } Seg;
typedef union { u128 q[4]; struct { Vec a; Vec b; Vec c; s32 hit; f32 t1; f32 t2; } s; } Res;
typedef struct { u8 pad[0x2C]; u8 kind:3; u8 k3:5; u8 b0:5; u8 en:1; u8 b6:2; } AI;
typedef struct { u16 x0; u8 pad2[0x7A]; s32 x7C; u8 pad80[0x434]; AI *x4B4[0x1A]; s8 *x51C; } A;
typedef struct { u8 pad[0x90]; s32 x90; } O;
s32 func_0013BA70(s32, A *, s8 *);
void func_00151B20(Res *, Ray *, s8 *);

s32 func_001D2890(O *o, A *a, Ray *ray, Res *out) {
    s32 ret;
    s32 i;
    f32 best;
    s8 *seg;
    AI *ai;
    Res r;
    best = 5.0f;
    ret = -1;
    out->s.hit = 0;
    for (i = 0; i < a->x7C; i++) {
        seg = a->x51C + i * 0x170;
        ai = a->x4B4[i];
        if (!ai->en) continue;
        if (a->x0 != 0 && ai->kind == 1) continue;
        if (a->x0 != 0 && ai->kind == 2) continue;
        if (!func_0013BA70(o->x90, a, seg)) continue;
        func_00151B20(&r, ray, seg);
        if (r.s.hit == 0) continue;
        if (r.s.a.w < best) {
            ret = i;
            best = r.s.a.w;
            *out = r;
        }
    }
    return ret;
}
