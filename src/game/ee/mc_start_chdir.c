#include "common.h"
#include "game/ee.h"


s32 Mc_StartChdir_1_001D6C60(u32 a, u32 b, s32 c)
{
    if (D_004B63B8.cmd != 0)
        return 1;
    if (a >= 3)
        return -1;
    if (b >= 5)
        return -1;
    D_004B63B8.name = c;
    D_004B63B8.slot = b;
    D_004B63B8.port = a;
    D_004B63B8.step = 0;
    D_004B63B8.cmd = 0xB;
    return 0;
}
