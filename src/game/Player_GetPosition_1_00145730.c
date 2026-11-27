#include "common.h"
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_00270550[0x4];

s32 *Player_GetPosition_1_00145730(void) {
    Player_GetPos_1_001C9410(D_00270550);
    return D_00270550;
}
