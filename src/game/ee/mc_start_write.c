#include "common.h"
#include "game/ee.h"


s32 Mc_StartWrite_1_001D6A80(u32 a, u32 b, s32 c, s32 d, s32 e)
{
    if (D_004B63B8.cmd != 0)
        return 1;
    if (a >= 3)
        return -1;
    if (b >= 5)
        return -1;
    D_004B63B8.cmd = 7;
    D_004B63B8.x90 = 0;
    D_004B63B8.step = 0;
    D_004B63B8.port = a;
    D_004B63B8.slot = b;
    D_004B63B8.name = c;
    D_004B63B8.xB8 = d;
    D_004B63B8.size = e;
    D_004B63B8.err = 0x3C;
    return 0;
}
