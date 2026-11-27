#include "common.h"
void memset(s32 *, s32, s32);        /* extern */
extern s32 D_003172E0[];

void Vibe_StopAll_1_00160300(void) {
    Pad_SetRumbleLarge_2_001D7D58(0, 0, 0);
    Pad_SetRumble_3_001D7D08(0, 0, 0);
    memset(D_003172E0, 0, 0x200);
}
