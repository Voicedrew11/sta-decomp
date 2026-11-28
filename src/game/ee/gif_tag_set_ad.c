#include "common.h"

u64 *GifTag_SetAd_1_001E51A8(u64 *p, u16 a, s32 b)
{
    p[1] = 0;
    p[0] = ((b & 7) << 28) | a;
    return p + 2;
}
