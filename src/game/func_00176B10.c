#include "m2c.h"
M2C_UNK func_001543E0(M2C_UNK, s64);                /* extern */
extern s64 D_00202010;
extern s32 D_004830E8[];
extern s32 D_004830EC[];
extern s32 D_004830F4[];

void func_00176B10(s8 *arg0, M2C_UNK arg1) {
    if (arg0 != NULL) {
        if ((M2C_FIELD(arg0, u8 *, 0x28) & 7) == 3) {
            D_004830E8[0] += 1;
            D_004830EC[0] += 1;
            func_001545D0();
            func_001543E0(0x14, M2C_FIELD(arg0, s64 *, 8));
            func_001543E0(6, M2C_FIELD(arg0, s64 *, 0));
            func_00154420();
            D_00202010 = 0;
            D_004830F4[0] = 1;
            return;
        }
        D_004830F4[0] = 2;
        func_00176440(/* s64+0x0 */ arg0, /* s64+0x4 */ arg1);
    }
}
