#include "common.h"
s32 func_001D6F80();                                /* extern */
void memset(s32 *, s32, s32);        /* extern */
extern s32 D_002023B8;
extern s32 D_002023C4;
extern s32 D_002023C8;
extern s32 D_002023CC;
extern s32 D_002023D0;
extern s32 D_002023D4;
extern s32 D_002023D8;
extern s32 D_002023DC;
extern s32 D_002023E0;
extern s32 D_002023E4;
extern s32 D_002023E8;
extern s32 D_004BC380[];
extern s32 D_004BCBC0[];
extern s32 D_004BCF40[];

s32 func_001E85E0(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4) {
    s32 var_4_2;
    s32 *var_4;
    s32 var_3;
    s32 *var_16;
    s32 *var_3_2;

    var_16 = (s32 *) (arg2);
    if (D_002023B8 != 0) {
        return -1;
    }
    if (func_001D6F80() != 0) {
        return -1;
    }
    D_002023E4 = arg0;
    D_002023E0 = arg1;
    D_002023E8 = 0;
    D_002023D0 = 0;
    D_002023D4 = 0;
    memset(D_004BCBC0, 0, 0x206);
    D_002023C8 = arg3;
    var_4 = (s32 *) (D_004BCF40);
    D_002023C4 = arg4;
    var_3 = 0xF1;
    D_002023CC = 0;
    do {
        var_3 -= 1;
        *var_4 = *var_16;
        var_16 = (s32*)((u8 *)var_16 + 4);
        var_4 = (s32*)((u8 *)var_4 + 4);
    } while (var_3 > 0);
    var_4_2 = 0;
    var_3_2 = (s32 *) (D_004BC380);
    do {
        M2C_FIELD(var_3_2, s32 *, 0) = 0;
        M2C_FIELD(var_3_2, s32 *, 4) = 0;
        var_4_2 += 1;
        M2C_FIELD(var_3_2, s32 *, 8) = 0;
        M2C_FIELD(var_3_2, s32 *, 0xC) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x10) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x14) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x18) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x1C) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x20) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x3C0) = 0;
        M2C_FIELD(var_3_2, s32 *, 0x3C4) = 0;
        var_3_2 = (s32*)((u8 *)var_3_2 + 0x400);
    } while (var_4_2 < 2);
    D_002023D8 = 0;
    D_002023DC = 1;
    D_002023B8 = 1;
    return 0;
}
