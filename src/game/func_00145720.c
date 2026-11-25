#include "common.h"

typedef struct { char pad[0x518]; u8 *p; } S;
extern S *D_002022E4;
void sceVu0CopyVector(f32 *v0, f32 *v1);

void func_00145720(f32 *v)
{
    sceVu0CopyVector(v, (f32 *)(D_002022E4->p + 0x20));
}
