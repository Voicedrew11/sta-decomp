#include "m2c.h"

void func_001B59E0(s8 *arg0, s8 *arg1, s8 *arg2, s8 *arg3) {
    M2C_FIELD(arg1, f32 *, 0) = M2C_FIELD(arg0, f32 *, 0);
    M2C_FIELD(arg2, f32 *, 0) = 0.00024414062f * M2C_FIELD(arg0, s16 *, 0xC);
    M2C_FIELD(arg3, f32 *, 0) = 0.00024414062f * (u32)M2C_FIELD(arg0, u16 *, 0x12);
    M2C_FIELD(arg1, f32 *, 4) = M2C_FIELD(arg0, f32 *, 4);
    M2C_FIELD(arg2, f32 *, 4) = 0.00024414062f * M2C_FIELD(arg0, s16 *, 0xE);
    M2C_FIELD(arg3, f32 *, 4) = 0.00024414062f * (u32)M2C_FIELD(arg0, u16 *, 0x14);
    M2C_FIELD(arg1, f32 *, 8) = M2C_FIELD(arg0, f32 *, 8);
    M2C_FIELD(arg2, f32 *, 8) = 0.00024414062f * M2C_FIELD(arg0, s16 *, 0x10);
    M2C_FIELD(arg3, f32 *, 8) = 0.00024414062f * (u32)M2C_FIELD(arg0, u16 *, 0x16);
    M2C_FIELD(arg1, f32 *, 0xC) = 1.0f;
    M2C_FIELD(arg2, f32 *, 0xC) = 0.0f;
    M2C_FIELD(arg3, f32 *, 0xC) = 1.0f;
}
