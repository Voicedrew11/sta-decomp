#include "common.h"
void Mdl_GetSectionPtrs_1_00171050(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg1, u8 **, 0) = (u8 *) (arg0 + 0x40);
    M2C_FIELD(arg1, u8 **, 4) = (u8 *) (M2C_FIELD(arg1, u8 **, 0) + (M2C_FIELD(arg0, u16 *, 0x14) * 0x10));
    M2C_FIELD(arg1, u8 **, 8) = (u8 *) (M2C_FIELD(arg1, u8 **, 4) + (M2C_FIELD(arg0, u16 *, 0x16) * 8));
    M2C_FIELD(arg1, u8 **, 0xC) = (u8 *) (M2C_FIELD(arg1, u8 **, 8) + (M2C_FIELD(arg0, u16 *, 0x18) * 4));
    M2C_FIELD(arg1, u8 **, 0x10) = (u8 *) (M2C_FIELD(arg1, u8 **, 0xC) + (M2C_FIELD(arg0, u16 *, 0x1C) * 0x50));
    M2C_FIELD(arg1, u8 **, 0x14) = (u8 *) (M2C_FIELD(arg1, u8 **, 0x10) + (M2C_FIELD(arg0, u16 *, 0x1E) * 4));
}
