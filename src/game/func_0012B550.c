#include "m2c.h"
M2C_UNK func_00154B70();                            /* extern */
extern s8 D_00222AF0[];
extern s8 D_00222B20[];

void func_0012B550(void) {
    s32 var_s0;

    func_00155370();
    func_00128210(D_00222AF0);
    func_00128210(D_00222B20);
    func_001552A0();
    var_s0 = 0;
    do {
        func_00154B70();
        func_00153B50(0x80000000);
        func_00154AF0();
        func_00155370();
        func_001552A0();
        var_s0 += 1;
    } while (var_s0 < 4);
    func_00189080();
    func_00128460(D_00222B20, -1U);
    func_00128210(D_00222B20);
}
