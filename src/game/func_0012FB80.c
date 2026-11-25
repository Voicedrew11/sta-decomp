#include "common.h"

typedef struct { s32 a; s32 b; s32 x8; char pc[4]; s32 x10; s32 x14; s32 x18; u8 b1c; u8 b1d; s16 h1e; f32 v20[4]; f32 v30[4]; char p40[0x10]; } E;
extern E D_0026F0D0[64];
extern f32 D_001F2160[4];
void sceVu0CopyVector(f32 *v0, f32 *v1);

void func_0012FB80(void)
{
    s32 n = 64;
    E *e = D_0026F0D0;
    while (n--) {
        e->a = -1;
        e->b = -1;
        e->x18 = 0;
        e->x14 = 0;
        e->x10 = 0;
        e->x8 = 0;
        e->b1c = 0;
        e->b1d = 0;
        e->h1e = 0;
        sceVu0CopyVector(e->v20, D_001F2160);
        sceVu0CopyVector(e->v30, D_001F2160);
        e++;
    }
}
