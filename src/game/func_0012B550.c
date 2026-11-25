#include "common.h"
void func_00154AF0();                            /* extern */
extern s32 D_00222AF0[];
extern s32 D_00222B20[];

void func_0012B550(void) {
    s32 var_16;

    func_00155370();
    func_00128210(D_00222AF0);
    func_00128210(D_00222B20);
    func_001552A0();
    var_16 = 0;
    do {
        func_00154B70();
        func_00153B50(0x80000000);
        func_00154AF0();
        func_00155370();
        func_001552A0();
        var_16 += 1;
    } while (var_16 < 4);
    func_00189080();
    func_00128460(D_00222B20, -1U);
    func_00128210(D_00222B20);
}
