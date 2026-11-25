#include "common.h"

extern s32 D_004BA2F8[];
extern s32 D_004BA2E0[];
s32 sceSifDmaStat(u32 id);
s32 func_001D8680(s32 a, s32 b, s32 c, ...);

s32 func_001DAF80(void)
{
    if (sceSifDmaStat(D_004BA2F8[0]) >= 0)
        return 1;
    if (!func_001D8680(4, 1, 0x800, 0, 0))
        return 1;
    if (!func_001D8680(4, 1, 0x800, 1, 0))
        return 1;
    D_004BA2E0[0] = 0;
    return 0;
}
