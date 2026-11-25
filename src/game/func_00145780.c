#include "common.h"

typedef struct { char pad[0x518]; f32 *v; } S;
extern S *D_002022E4;
void sceVu0CopyVector(f32 *v0, f32 *v1);

void func_00145780(f32 *v)
{
    sceVu0CopyVector(v, D_002022E4->v);
}
