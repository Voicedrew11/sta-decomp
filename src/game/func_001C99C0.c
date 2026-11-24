#include "m2c.h"
extern s8 *D_002022E4;

s16 func_001C99C0(void) {
    s32 temp_v0;
    s8 *var_v0;

    if (D_002022E4 == NULL) {
        var_v0 = NULL;
    } else {
        temp_v0 = M2C_FIELD(D_002022E4, s32 *, 0x518);
        if (temp_v0 == 0) {
            var_v0 = NULL;
        } else {
            var_v0 = (signed char *)(temp_v0 + 0x180);
        }
    }
    if (var_v0 == NULL) {
        return 0;
    }
    return M2C_FIELD(M2C_FIELD(var_v0, s8 **, 0x390), s16 *, 4);
}

s32 func_001C9A20(void) {
    s32 temp_v0;
    s8 *var_v0;

    if (D_002022E4 == NULL) {
        var_v0 = NULL;
    } else {
        temp_v0 = M2C_FIELD(D_002022E4, s32 *, 0x518);
        if (temp_v0 == 0) {
            var_v0 = NULL;
        } else {
            var_v0 = (signed char *)(temp_v0 + 0x180);
        }
    }
    if (var_v0 == NULL) {
        return 0;
    }
    return M2C_FIELD(var_v0, u8 *, 0x3D6) & 1;
}

u64 func_001C9A80(void) {
    s32 temp_v0;
    s8 *var_v0;

    if (D_002022E4 == NULL) {
        var_v0 = NULL;
    } else {
        temp_v0 = M2C_FIELD(D_002022E4, s32 *, 0x518);
        if (temp_v0 == 0) {
            var_v0 = NULL;
        } else {
            var_v0 = (signed char *)(temp_v0 + 0x180);
        }
    }
    if (var_v0 == NULL) {
        return 0U;
    }
    return (u64) ((s64) M2C_FIELD(var_v0, u8 *, 0x3A2) << 0x3C) >> 0x3F;
}

u64 func_001C9AE0(void) {
    s32 temp_v0;
    s8 *var_v0;

    if (D_002022E4 == NULL) {
        var_v0 = NULL;
    } else {
        temp_v0 = M2C_FIELD(D_002022E4, s32 *, 0x518);
        if (temp_v0 == 0) {
            var_v0 = NULL;
        } else {
            var_v0 = (signed char *)(temp_v0 + 0x180);
        }
    }
    if (var_v0 == NULL) {
        return 0U;
    }
    return (u64) ((s64) M2C_FIELD(var_v0, s32 *, 0x39C) << 0x2E) >> 0x3C;
}
