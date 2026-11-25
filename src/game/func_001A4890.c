#include "common.h"
typedef struct { char pad[0x14]; unsigned char : 3; unsigned char f : 1; } BF_14_3_1;
s64 func_001303C0(s32);                             /* extern */
extern s32 D_001FD8D0[];
extern s32 D_00202270;

void func_001A4890(void *arg0) {
    s32 temp_4;

    temp_4 = M2C_FIELD(arg0, s32 *, 0);
    if ((temp_4 == 0x16) && (D_00202270 != 0) && (((s64) (func_001303C0(temp_4) << 0x30) >> 0x30) <= 0) && (func_0012C1B0() == 0)) {
        func_00155900();
        func_0017FF70((s32) D_001FD8D0);
        func_00154700(5, 0);
        ((BF_14_3_1 *)arg0)->f = 1;
        D_00202270 = 0;
    }
}
