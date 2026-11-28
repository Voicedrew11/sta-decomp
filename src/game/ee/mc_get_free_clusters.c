#include "common.h"
#include "game/ee.h"
s32 Mc_GetFreeClusters_3_001D7008(s32 i, s32 j) {
    s32 r;
    if (D_004B63B8.free[(i) * 4 + (j)] == 0 && D_004B63B8.type[(i) * 4 + (j)] == 0) { D_004B63B8.err = 1; return -1; }
    r = D_004B63B8.free[(i) * 4 + (j)] - 2;
    if (r <= 0) { r = 0; D_004B63B8.err = 30; }
    D_004B63B8.err = 0;
    return r;
}
