#include "m2c.h"
s32 func_001D9710();                                /* extern */
M2C_UNK func_001D9EE0(s32);                         /* extern */
extern u8 D_0022EC20[];

void func_0012C380(void) {
    s32 var_s0;

    if (D_0022EC20[0] != 0) {
        D_0022EC20[0] = 0;
        do {

        } while (func_001D9710() == 0);
    }
    func_0012F920();
    var_s0 = 0;
    do {
        func_001D9EE0(var_s0);
        var_s0 += 1;
    } while (var_s0 < 4);
}
