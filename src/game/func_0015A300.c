#include "common.h"
s32 func_0015A300(void *arg0) {
    s32 temp_3;

    temp_3 = M2C_FIELD(arg0, u16 *, 0x10) & 1;
    switch (temp_3) {                               /* irregular */
    case 0:
        return M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), s32 *, 0xC);
    case 1:
        return M2C_FIELD(arg0, s32 *, 0x18);
    default:
        return 0;
    }
}
