#include "common.h"
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_004A4980[0x438];

void Save_StartNewGame_0_001AB290(void) {
    Save_BuildGame_1_001AAAE0(D_004A4980);
    PlayerData_InitNew_0_001C9EA0();
    PlayTime_Reset_1_001DFBB0();
}
