#include "common.h"

typedef struct { char pad[0x60]; f32 f60; f32 f64; char p68[8]; f32 v[4]; char p80[0x30]; f32 fb0; } Obj;
extern void *D_002022E4;
extern f32 D_001F2160[4];
f32 *func_00145730(s32 k);
void sceVu0CopyVector(f32 *v0, f32 *v1);

void func_0014AAF0(Obj *o)
{
    s32 k;
    if (0.0f != o->f60) {
        f32 v = o->fb0;
        o->v[2] = v;
        o->v[1] = v;
        o->v[0] = v;
        o->v[3] = 1.0f;
    }
    k = o->f64;
    if (k == 1) {
        f32 *src;
        if (D_002022E4)
            src = func_00145730(k);
        else
            src = D_001F2160;
        sceVu0CopyVector((f32 *)o, src);
    }
}
