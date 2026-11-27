#include "common.h"
void memset(void *, s32, s32);           /* extern */

void DbChar_CalcStatBars_0_00196D10(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    memset(arg1, 0, 0x10);
    memset(arg0, 0, 0x10);
    memset(arg3, 0, 0x10);
    memset(arg2, 0, 0x10);
    if (arg4 != NULL) {
        M2C_FIELD(arg0, u16 *, 0) = (u16) M2C_FIELD(arg4, u16 *, 8);
        M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg4, u16 *, 0xA);
        M2C_FIELD(arg0, u16 *, 4) = (u16) M2C_FIELD(arg4, u16 *, 0xC);
        M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg4, u16 *, 0xE);
        M2C_FIELD(arg0, u16 *, 8) = (u16) M2C_FIELD(arg4, u16 *, 0x10);
        M2C_FIELD(arg0, u16 *, 0xA) = (u16) M2C_FIELD(arg4, u16 *, 0x12);
        M2C_FIELD(arg0, u16 *, 0xC) = (u16) M2C_FIELD(arg4, u16 *, 0x14);
        M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg4, u16 *, 0x16);
        M2C_FIELD(arg1, u16 *, 0) = (u16) M2C_FIELD(arg4, u16 *, 0x18);
        M2C_FIELD(arg1, u16 *, 2) = (u16) M2C_FIELD(arg4, u16 *, 0x1A);
        M2C_FIELD(arg1, u16 *, 4) = (u16) M2C_FIELD(arg4, u16 *, 0x1C);
        M2C_FIELD(arg1, u16 *, 6) = (u16) M2C_FIELD(arg4, u16 *, 0x1E);
        M2C_FIELD(arg1, u16 *, 8) = (u16) M2C_FIELD(arg4, u16 *, 0x20);
        M2C_FIELD(arg1, u16 *, 0xA) = (u16) M2C_FIELD(arg4, u16 *, 0x22);
    }
}
