#include "m2c.h"
void PlayerData_ClearStatus_0_001CE270(s32);
void Inventory_AddItem_1_001A95A0(s16, u8);
void Item_ClearNewFlag_0_001A9510(s16);
void Msg_Close_1_0018B0C0(void);
void MapCmd_SetObjectTexture_0_0017E150(s32, s32, s32);
void Snd_PlaySe_3_00131600(s32, s32);
void SndCh_Stop_2_00131440(s32);
void MapSheet_Open_0_001ED620(s32);

void MapCmd_PlayBgm_0_0017E050(s8 *arg0) {
    s32 mode;
    s32 a;
    s32 b;
    s32 c;
    mode = *(s32 *)(arg0 + 8);
    a = *(s32 *)(arg0 + 0x10);
    b = *(s32 *)(arg0 + 0x18);
    c = *(s32 *)(arg0 + 0x20);
    if (mode == 2) PlayerData_ClearStatus_0_001CE270(a);
    if (mode == 3) Inventory_AddItem_1_001A95A0(a, b);
    if (mode == 4) Item_ClearNewFlag_0_001A9510(a);
    if (mode == 5) Msg_Close_1_0018B0C0();
    if (mode == 6) MapCmd_SetObjectTexture_0_0017E150(a, b, c);
    if (mode == 7) Snd_PlaySe_3_00131600(a, b);
    if (mode == 8) SndCh_Stop_2_00131440(a);
    if (mode == 9) MapSheet_Open_0_001ED620(a);
}
