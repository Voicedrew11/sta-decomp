#include "common.h"
#include "game/ee.h"


s32 Mc_StartCheck_1_001D6BB8(u32 a, u32 b)
{
    if (D_004B63B8.cmd != 0)
        return 1;
    if (a >= 3)
        return -1;
    if (b >= 5)
        return -1;
    D_004B63B8.port = a;
    D_004B63B8.slot = b;
    D_004B63B8.step = 0;
    D_004B63B8.cmd = 9;
    D_004B63B8.err = 0x33;
    return 0;
}
