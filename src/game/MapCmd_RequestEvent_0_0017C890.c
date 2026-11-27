#include "common.h"
void MapCmd_RequestEvent_0_0017C890(void *arg0) {
    s32 temp_16;

    temp_16 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_16 == 1) {
        Game_TryRequestEvent_0_0012C110(0xA);
    }
    if (temp_16 == 2) {
        Game_TryRequestEvent_0_0012C110(0x1F);
    }
    if (temp_16 == 3) {
        Game_TryRequestEvent_0_0012C110(0x80);
    }
    if (temp_16 == 4) {
        Game_TryRequestEvent_0_0012C110(0x81);
    }
    if (temp_16 == 0xF) {
        Game_TryRequestEvent_0_0012C110(0x25);
    }
}
