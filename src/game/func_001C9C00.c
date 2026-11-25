#include "common.h"

extern u8 D_00201E24;
extern f32 D_004B4CE0[4];
void sceVu0CopyVector(f32 *v0, f32 *v1);

u8 func_001C9C00(f32 *v)
{
    if (v)
        sceVu0CopyVector(v, D_004B4CE0);
    return D_00201E24;
}
