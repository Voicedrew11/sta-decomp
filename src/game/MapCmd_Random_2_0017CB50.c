#include "common.h"

s32 *Script_GetArgPtr_2_00165130(s32 a, s32 b);
s32 Rand_Next_3_0015ED20(void);

void MapCmd_Random_2_0017CB50(s32 a)
{
    s32 *p = Script_GetArgPtr_2_00165130(a, 0);
    s32 v = Rand_Next_3_0015ED20();
    if (v < 0)
        v = -v;
    *p = v;
}
