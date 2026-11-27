#include "m2c.h"
void MenuStack_Push_1_00189ED0(s32);
void UiAnim_SetVisible_1_0017F7C0(s32, s32, s32);
void Snd_PlaySe_3_00131600(s32, s32);
s32 UiAnim_SetTarget_1_0017F470(s32, s32, f32);
void Shop_ResetPrices_0_001A2DE0(void);
void Shop_RecalcPrices_0_001A2EA0(void);
extern s32 D_004A3320[];
extern s32 D_004A4350[];
typedef struct { s32 state; s32 input; s8 b8; s8 b9; u8 pad[4]; u8 bE; } S;

void Storage_Update_0_001A3380(S *arg0) {
    s32 temp_v1;
    s32 var_s0;

    temp_v1 = arg0->input;
    var_s0 = D_004A4350[0];
    if (temp_v1 & 0x10) {
        var_s0 -= 1;
        if (var_s0 < 0) {
            var_s0 = 3;
        }
    } else if (temp_v1 & 0x40) {
        var_s0 += 1;
        if (var_s0 > 3) {
            var_s0 = 0;
        }
    } else if (temp_v1 & 0x2000) {
        D_004A3320[0] = var_s0 + 1;
        arg0->b9 = D_004A3320[0];
        arg0->b8 = 0x22;
        MenuStack_Push_1_00189ED0(0x1F);
        UiAnim_SetVisible_1_0017F7C0(0, 0, 0);
        arg0->input = 0;
        arg0->state = 0x1A;
        Snd_PlaySe_3_00131600(0x69, arg0->bE);
    } else if (temp_v1 & 0x4000) {
        D_004A4350[0] = 0;
        UiAnim_SetVisible_1_0017F7C0(0, 0, 0);
        arg0->b8 = 0x12;
        arg0->input = 0;
        arg0->state = 0x1A;
        Shop_ResetPrices_0_001A2DE0();
        Shop_RecalcPrices_0_001A2EA0();
        Snd_PlaySe_3_00131600(0x65, arg0->bE);
    }
    if (UiAnim_SetTarget_1_0017F470(0, 0, D_004A4350[0]) != 0) {
        if (D_004A4350[0] != var_s0) {
            Snd_PlaySe_3_00131600(0x66, arg0->bE);
        }
        D_004A4350[0] = var_s0;
    }
    arg0->input = 0;
}
