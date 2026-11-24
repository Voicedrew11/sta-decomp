#include "m2c.h"

s32 func_0015A300(s8 *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u16 *, 0x10) & 1;
    switch (temp_v1) {                              /* irregular */
    case 0:
        return M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xC), s32 *, 0xC);
    case 1:
        return M2C_FIELD(arg0, s32 *, 0x18);
    default:
        return 0;
    }
}

s32 func_0015A350(s8 *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u16 *, 0x10) & 1;
    switch (temp_v1) {                              /* irregular */
    case 0:
        return M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xC), s32 *, 4);
    case 1:
        return M2C_FIELD(arg0, s32 *, 0x18);
    default:
        return 0;
    }
}
