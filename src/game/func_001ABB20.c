#include "common.h"
extern s32 D_004AC630[];
extern s32 D_004AC970[];
extern s32 D_004AD670[];
extern s32 D_004AE370[];
extern s32 D_004B1770[];

s32 *func_001ABB20(void) {
    u8 temp_4_5;
    u8 temp_4_4;
    u8 temp_4_3;
    u8 temp_4_2;
    u8 temp_4;
    s32 var_6_5;
    s32 var_6_4;
    s32 var_6_3;
    s32 var_6_2;
    s32 var_6;
    s32 *var_2_5;
    s32 *var_2_4;
    s32 *var_2_3;
    s32 *var_2_2;
    s32 *var_2;

    var_6 = 0;
    var_2_5 = (s32 *) (D_004AC630);
loop_1:
    if (M2C_FIELD(var_2_5, s16 *, 0x9C) != -1) {
        temp_4 = M2C_FIELD(var_2_5, u8 *, 0xA8);
        if (!(temp_4 & 1) && (((u64) ((s64) temp_4 << 0x3E) >> 0x3F) == 0)) {
            return (s32 *) (var_2_5);
        }
    }
    var_6 += 1;
    var_2_5 = (s32*)((u8 *)var_2_5 + 0xD0);
    if (var_6 >= 4) {
        var_6_2 = 0;
        var_2_4 = (s32 *) (D_004AC970);
loop_7:
        if (M2C_FIELD(var_2_4, s16 *, 0x9C) != -1) {
            temp_4_2 = M2C_FIELD(var_2_4, u8 *, 0xA8);
            if (!(temp_4_2 & 1) && (((u64) ((s64) temp_4_2 << 0x3E) >> 0x3F) == 0)) {
                return (s32 *) (var_2_4);
            }
        }
        var_6_2 += 1;
        var_2_4 = (s32*)((u8 *)var_2_4 + 0xD0);
        if (var_6_2 >= 0x10) {
            var_6_3 = 0;
            var_2_3 = (s32 *) (D_004AD670);
loop_13:
            if (M2C_FIELD(var_2_3, s16 *, 0x9C) != -1) {
                temp_4_3 = M2C_FIELD(var_2_3, u8 *, 0xA8);
                if (!(temp_4_3 & 1) && (((u64) ((s64) temp_4_3 << 0x3E) >> 0x3F) == 0)) {
                    return (s32 *) (var_2_3);
                }
            }
            var_6_3 += 1;
            var_2_3 = (s32*)((u8 *)var_2_3 + 0xD0);
            if (var_6_3 >= 0x10) {
                var_6_4 = 0;
                var_2_2 = (s32 *) (D_004AE370);
loop_19:
                if (M2C_FIELD(var_2_2, s16 *, 0x9C) != -1) {
                    temp_4_4 = M2C_FIELD(var_2_2, u8 *, 0xA8);
                    if (!(temp_4_4 & 1) && (((u64) ((s64) temp_4_4 << 0x3E) >> 0x3F) == 0)) {
                        return (s32 *) (var_2_2);
                    }
                }
                var_6_4 += 1;
                var_2_2 = (s32*)((u8 *)var_2_2 + 0xD0);
                if (var_6_4 >= 0x40) {
                    var_6_5 = 0;
                    var_2 = (s32 *) (D_004B1770);
loop_25:
                    if (M2C_FIELD(var_2, s16 *, 0x9C) != -1) {
                        temp_4_5 = M2C_FIELD(var_2, u8 *, 0xA8);
                        if (!(temp_4_5 & 1) && (((u64) ((s64) temp_4_5 << 0x3E) >> 0x3F) == 0)) {
                            return (s32 *) (var_2);
                        }
                    }
                    var_6_5 += 1;
                    var_2 = (s32*)((u8 *)var_2 + 0xD0);
                    if (var_6_5 >= 0x40) {
                        return NULL;
                    }
                    goto loop_25;
                }
                goto loop_19;
            }
            goto loop_13;
        }
        goto loop_7;
    }
    goto loop_1;
}
