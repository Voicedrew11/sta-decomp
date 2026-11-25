#include "common.h"
extern u8 D_00222A53[];

s32 func_0013E2B0(void *arg0) {
    if (((u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B3) << 0x3C) >> 0x3F) != 0) {
        return 0;
    }
    if (((u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B2) << 0x3C) >> 0x3F) != 0) {
        return 0;
    }
    if (((u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B6) << 0x3A) >> 0x3F) != 0) {
        return 0;
    }
    if ((((u64) ((s64) (*D_00222A53) << 0x3C) >> 0x3F) != 0) && (M2C_FIELD(arg0, f32 *, 0x5D4) == 0.0f) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0x4B0), f32 *, 0x290) == 0.0f)) {
        return 0;
    }
    return 1;
}
