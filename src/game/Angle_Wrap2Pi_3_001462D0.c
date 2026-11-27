#include "common.h"

f32 Angle_Wrap2Pi_3_001462D0(f32 a)
{
    a -= 6.2831855f * (s32)(a / 6.2831855f);
    if (a < 0.0f)
        a += 6.2831855f;
    return a;
}
