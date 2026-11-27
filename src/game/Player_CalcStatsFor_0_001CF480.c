#include "common.h"

void Stats_CalcBase_0_001D08E0(s32 a, s32 b, s32 e, s32 f);
void Stats_CalcDefense_0_001D0000(s32 c, s32 d, s32 a, s32 e, s32 f, s32 g);

void Player_CalcStatsFor_0_001CF480(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g)
{
    Stats_CalcBase_0_001D08E0(a, b, e, f);
    Stats_CalcDefense_0_001D0000(c, d, a, e, f, g);
}
