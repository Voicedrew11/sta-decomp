#include "common.h"

void sceVu0CopyVector(f32 *v0, f32 *v1);

void func_00140350(u8 *obj, f32 *v)
{
    sceVu0CopyVector(v, (f32 *)(obj + 0x660));
}
