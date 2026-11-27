#include "common.h"
void Pool_Free_2_00128580(s32, s32);                    /* extern */
void Task_RunWrap_0_0014DAB0(s32);                         /* extern */
extern s32 D_00202288;
extern s32 D_0020228C;
extern s32 D_00202290;
extern s16 D_004AC5A0[];
extern s16 D_004AC5A2[];
extern s16 D_004AC5A4[];
extern s16 D_004AC5A6[];
extern u8 D_004AC630[];
extern u8 D_004AC970[];
extern u8 D_004AE370[];
extern s32 D_004B4B70[];
extern s32 D_004B4B74[];
extern s32 D_004B4B80[];
extern s32 D_004B4B88[];

void ItemObj_FreeAll_0_001AF840(void) {
    u8 *var_17_3;
    u8 *var_17_2;
    s32 var_17;
    u8 *var_16;
    s32 var_16_3;
    s32 var_16_2;

    if ((*D_004B4B80) != 0) {
        Pool_Free_2_00128580(D_00202290, (*D_004B4B80));
    }
    if ((*D_004B4B74) != 0) {
        Task_RunWrap_0_0014DAB0((*D_004B4B74));
        (*D_004B4B74) = 0;
    }
    (*D_004B4B80) = 0;
    var_17 = 0;
    (*D_004B4B74) = 0;
    var_16 = (u8 *) (D_004AE370);
    D_00202288 = 0;
    (*D_004B4B70) = 0;
    D_0020228C = 0;
    (*D_004B4B88) = 0;
    do {
        ItemObj_Free_1_001AF4A0(var_16);
        ItemObj_Free_1_001AF4A0(var_16 + 0x3400);
        var_17 += 1;
        var_16 += 0xD0;
    } while (var_17 < 0x40);
    var_16_2 = 0;
    var_17_2 = (u8 *) (D_004AC970);
    do {
        ItemObj_Free_1_001AF4A0(var_17_2);
        ItemObj_Free_1_001AF4A0(var_17_2 + 0xD00);
        var_16_2 += 1;
        var_17_2 += 0xD0;
    } while (var_16_2 < 0x10);
    var_16_3 = 0;
    var_17_3 = (u8 *) (D_004AC630);
    do {
        ItemObj_Free_1_001AF4A0(var_17_3);
        var_16_3 += 1;
        var_17_3 += 0xD0;
    } while (var_16_3 < 4);
    (*D_004AC5A0) = 0;
    (*D_004AC5A2) = 0;
    (*D_004AC5A4) = 0;
    (*D_004AC5A6) = 0;
}
