#include "m2c.h"
s32 func_00117348(M2C_UNK);                         /* extern */
M2C_UNK func_00117820(M2C_UNK);                     /* extern */
M2C_UNK func_00123C40(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern s32 D_00201F84;
extern M2C_UNK D_002F20C0[];
extern M2C_UNK D_0030A0D0[];

void func_0015B040(s32 arg0, s32 arg1) {
    if ((D_00201F84 == 0) || (arg1 != 0)) {
        if (arg0 != 0) {
            do {

            } while (func_00117348(0) == 0);
            if (arg0 == 0x100) {
                func_00117820(1);
            } else if (arg0 == 0x200) {
                func_00117820(2);
            }
        }
        if (D_00201F84 == 0) {
            func_00123C40(D_0030A0D0, 0, 0x1C0);
            func_00123C40(D_002F20C0, 0, 0x18010);
            D_00201F84 = 1;
        }
    }
}
