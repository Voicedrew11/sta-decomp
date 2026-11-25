#include "common.h"

extern struct { f32 v[4]; char p10[0x14]; s32 x24; char p28[8]; s32 h; s32 x34; } D_004B4B90;
s32 func_0014DAF0(s32 h);
void sceVu0CopyVector(f32 *v0, f32 *v1);

typedef struct { f32 v[4]; s32 x10; u8 b14; char p15[3]; s32 x18; } Out;

s32 func_001B0660(Out *o)
{
    s32 r = 0;
    if (D_004B4B90.h)
        r = func_0014DAF0(D_004B4B90.h);
    if (o) {
        sceVu0CopyVector(o->v, D_004B4B90.v);
        o->x10 = D_004B4B90.x24;
        o->b14 = r;
        o->x18 = D_004B4B90.x34;
    }
    return r;
}
