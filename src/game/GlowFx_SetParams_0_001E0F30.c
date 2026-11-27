#include "common.h"

typedef struct { s32 h; s32 pad[3]; f32 a[4]; f32 b[4]; f32 x; f32 y; s32 pad2[2]; } E;
extern E D_004BAC50[16];
void Glow_SetParams_0_0015D800(s32, s32, s32, f32, f32);
void sceVu0CopyVector(void *, s32);

s32 GlowFx_SetParams_0_001E0F30(s32 i, s32 p, s32 q, f32 x, f32 y)
{
    s32 ok;
    s32 off;
    E *e;
    if (i < 0 || i >= 16)
        ok = 0;
    else if (D_004BAC50[i].h == -1)
        ok = 0;
    else
        ok = 1;
    if (!ok)
        return 0;
    off = i << 6;
    e = (E *)((u8 *)D_004BAC50 + off);
    sceVu0CopyVector(e->a, p);
    sceVu0CopyVector(e->b, q);
    *(f32 *)((u8 *)&D_004BAC50[0].x + off) = x;
    *(f32 *)((u8 *)&D_004BAC50[0].y + off) = y;
    Glow_SetParams_0_0015D800(e->h, p, q, x, y);
    return 1;
}
