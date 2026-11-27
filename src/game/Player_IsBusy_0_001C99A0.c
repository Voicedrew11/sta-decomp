#include "common.h"
s32 Game_GetBusy_0_0012C020();                                /* extern */

s32 Player_IsBusy_0_001C99A0(void) {
    return Game_GetBusy_0_0012C020() != 0;
}
