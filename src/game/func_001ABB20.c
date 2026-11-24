#include "m2c.h"
extern s8 D_004AC630[];
extern s8 D_004AC970[];
extern s8 D_004AD670[];
extern s8 D_004AE370[];
extern s8 D_004B1770[];

s8 *func_001ABB20(void) {
    s8 *var_v0;
    s8 *var_v0_2;
    s8 *var_v0_3;
    s8 *var_v0_4;
    s8 *var_v0_5;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_a2_4;
    s32 var_a2_5;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a0_5;

    var_a2 = 0;
    var_v0_5 = D_004AC630;
loop_1:
    if (M2C_FIELD(var_v0_5, s16 *, 0x9C) != -1) {
        temp_a0 = M2C_FIELD(var_v0_5, u8 *, 0xA8);
        if (!(temp_a0 & 1) && (((u64) ((s64) temp_a0 << 0x3E) >> 0x3F) == 0)) {
            return var_v0_5;
        }
    }
    var_a2 += 1;
    var_v0_5 += 0xD0;
    if (var_a2 >= 4) {
        var_a2_2 = 0;
        var_v0_4 = D_004AC970;
loop_7:
        if (M2C_FIELD(var_v0_4, s16 *, 0x9C) != -1) {
            temp_a0_2 = M2C_FIELD(var_v0_4, u8 *, 0xA8);
            if (!(temp_a0_2 & 1) && (((u64) ((s64) temp_a0_2 << 0x3E) >> 0x3F) == 0)) {
                return var_v0_4;
            }
        }
        var_a2_2 += 1;
        var_v0_4 += 0xD0;
        if (var_a2_2 >= 0x10) {
            var_a2_3 = 0;
            var_v0_3 = D_004AD670;
loop_13:
            if (M2C_FIELD(var_v0_3, s16 *, 0x9C) != -1) {
                temp_a0_3 = M2C_FIELD(var_v0_3, u8 *, 0xA8);
                if (!(temp_a0_3 & 1) && (((u64) ((s64) temp_a0_3 << 0x3E) >> 0x3F) == 0)) {
                    return var_v0_3;
                }
            }
            var_a2_3 += 1;
            var_v0_3 += 0xD0;
            if (var_a2_3 >= 0x10) {
                var_a2_4 = 0;
                var_v0_2 = D_004AE370;
loop_19:
                if (M2C_FIELD(var_v0_2, s16 *, 0x9C) != -1) {
                    temp_a0_4 = M2C_FIELD(var_v0_2, u8 *, 0xA8);
                    if (!(temp_a0_4 & 1) && (((u64) ((s64) temp_a0_4 << 0x3E) >> 0x3F) == 0)) {
                        return var_v0_2;
                    }
                }
                var_a2_4 += 1;
                var_v0_2 += 0xD0;
                if (var_a2_4 >= 0x40) {
                    var_a2_5 = 0;
                    var_v0 = D_004B1770;
loop_25:
                    if (M2C_FIELD(var_v0, s16 *, 0x9C) != -1) {
                        temp_a0_5 = M2C_FIELD(var_v0, u8 *, 0xA8);
                        if (!(temp_a0_5 & 1) && (((u64) ((s64) temp_a0_5 << 0x3E) >> 0x3F) == 0)) {
                            return var_v0;
                        }
                    }
                    var_a2_5 += 1;
                    var_v0 += 0xD0;
                    if (var_a2_5 >= 0x40) {
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
