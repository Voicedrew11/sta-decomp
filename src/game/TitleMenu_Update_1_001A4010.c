#include "common.h"
void TitleMenu_Update_1_001A4010(s32 *arg0) {
    TitleMenu_Open_1_001A4420(arg0);
    if (*arg0 == 0x16) {
        TitleMenu_Select_1_001A40A0(arg0);
    }
}
