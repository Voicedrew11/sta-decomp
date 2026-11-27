#include "common.h"
extern u8 D_004B9FAC[];
s32 SndDrv_Call_2_001D85D0(s32, s32, s32);
s32 Bgm_Poll_0_001D95E0(void) {
    u8 r;
    if (*D_004B9FAC == 0) return 0;
    r = SndDrv_Call_2_001D85D0(3, 1, 0x02070000);
    switch (r) {
    case 0:
    case 8:
        return 0;
    }
    return 1;
}

