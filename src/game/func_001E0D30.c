#include "common.h"

typedef struct { s32 h; f32 x4; f32 x8; char p[0x34]; } E;
extern E D_004BAC50[16];
extern u8 D_002023AC;
void func_0015DB60(s32 h);

static inline s32 valid(s32 i)
{
    s32 ok;
    if (i < 0 || i >= 16)
        ok = 0;
    else if (D_004BAC50[i].h == -1)
        ok = 0;
    else
        ok = 1;
    return ok;
}

static inline s32 release(s32 i)
{
    s32 ok;
    if (i < 0 || i >= 16)
        ok = 0;
    else if (D_004BAC50[i].h == -1)
        ok = 0;
    else
        ok = 1;
    if (!ok)
        return 0;
    func_0015DB60(D_004BAC50[i].h);
    D_004BAC50[i].h = -1;
    D_002023AC--;
    return 1;
}

s32 func_001E0D30(s32 i, s32 unused, f32 t)
{
    if (!valid(i))
        return 0;
    if (t == 0.0f)
        return release(i);
    D_004BAC50[i].x4 = t;
    D_004BAC50[i].x8 = t;
    return 1;
}
