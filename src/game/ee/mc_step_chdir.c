#include "common.h"
#include "game/ee.h"
s32 sceMcChdir(s32, s32, s32, s32);
s32 sceMcSync(s32, s32 *, s32 *);

s32 Mc_StepChdir_5_001D6550(void)
{
    s32 r;
    s32 port = D_004B63B8.port;
    s32 slot = D_004B63B8.slot;

    switch (D_004B63B8.step) {
    case 0:
        D_004B63B8.step = 1;
        D_004B63B8.retry = 0;
        break;
    case 1:
        if (sceMcChdir(port, slot, D_004B63B8.name, D_004B63B8.xA4) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.err = 100;
                return -10;
            }
            D_004B63B8.retry++;
        } else {
            D_004B63B8.step++;
        }
        break;
    case 2:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r == 0) {
            D_004B63B8.cmd = 0;
            D_004B63B8.err = 0;
            return 1;
        }
        if (D_004B63B8.retry == 2) {
            D_004B63B8.cmd = 0;
            if (r == -2) D_004B63B8.err = 3; else D_004B63B8.err = 100;
            return r;
        }
        D_004B63B8.retry++;
        D_004B63B8.step--;
        break;
    }
    return 0;
}
