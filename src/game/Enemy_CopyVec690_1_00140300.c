#include "common.h"

void sceVu0CopyVector(f32 *v0, f32 *v1);

void Enemy_CopyVec690_1_00140300(u8 *obj, f32 *v)
{
    sceVu0CopyVector(v, (f32 *)(obj + 0x690));
}
