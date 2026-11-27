#include "common.h"
extern u16 D_0020230C;

void Strm_DrvClose_1_001D8DF0(void) {
    if (D_0020230C != 0) {
        SndDrv_Call_2_001D85D0(5, 1, 0x40000);
        D_0020230C = 0;
    }
}
