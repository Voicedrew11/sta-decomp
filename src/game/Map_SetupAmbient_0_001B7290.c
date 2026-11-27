#include "common.h"

typedef struct { char p[0x10]; f32 a[4]; f32 b[4]; f32 f; } T;
extern f32 D_001F3850[4];
extern f32 D_001F3860[4];
extern f32 D_001F3870[];
T *LightGroup_Get_0_0015B900(s32 i);
void sceVu0CopyVector(f32 *v0, f32 *v1);
void sceVu0ScaleVector(f32 *v0, f32 *v1, f32 s);

void Map_SetupAmbient_0_001B7290(void)
{
    T *t = LightGroup_Get_0_0015B900(-1);
    sceVu0CopyVector(D_001F3860, t->b);
    sceVu0ScaleVector(D_001F3850, t->a, 255.0f);
    D_001F3870[0] = t->f;
}
