#include "common.h"

extern volatile s32 D_00202308;
extern s16 D_0020230C;
void FlushCache(s32 mode);
void SndDrv_CallArgs_2_001D8680(s32 a, s32 b, s32 c, ...);

s32 SndDrv_FlushEffects_0_001D8E70(void)
{
    FlushCache(0);
    D_00202308 = 0x3FFF;
    {
        s32 v = D_00202308;
        SndDrv_CallArgs_2_001D8680(5, 1, 0x50000, v, v);
    }
    D_0020230C = 0;
    FlushCache(0);
    return 1;
}
