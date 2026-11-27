#include "common.h"
extern s16 D_004BAA34[];
extern u16 D_004BAA36[];

void Se_Stop_0_001DB780(void) {
    if ((*D_004BAA36) != 0) {
        SndDrv_Call_2_001D85D0(4, 1, 0x600);
    }
    (*D_004BAA34) = 0;
    SndDrv_Call1_1_001D84F0(4, 1, 0xC00, 0);
    if ((*D_004BAA36) != 0) {
        SndDrv_Call_2_001D85D0(4, 1, 0x500);
    }
}
