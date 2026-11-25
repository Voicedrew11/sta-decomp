#include "common.h"
extern u8 D_0022EC20[];

void func_0012C380(void) {
    s32 var_16;

    if ((*D_0022EC20) != 0) {
        (*D_0022EC20) = 0;
        do {

        } while (func_001D9710() == 0);
    }
    func_0012F920();
    var_16 = 0;
    do {
        func_001D9EE0(var_16);
        var_16 += 1;
    } while (var_16 < 4);
}
