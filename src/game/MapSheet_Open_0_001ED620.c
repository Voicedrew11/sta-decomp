#include "common.h"
void Menu_SetSubMode_0_0018A330(s32);                     /* extern */
extern s32 D_00201E78;

void MapSheet_Open_0_001ED620(s32 arg0) {
    D_00201E78 = arg0;
    Menu_SetSubMode_0_0018A330(0x11);
}
