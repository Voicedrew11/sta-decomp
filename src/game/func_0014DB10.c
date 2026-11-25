#include "m2c.h"
#include "actor.h"
M2C_UNK func_001E0560(M2C_UNK *, s32);              /* extern */
extern s32 D_00201F20;
extern M2C_UNK D_002F0F40[];

void func_0014DB10(s32 arg0) {
    if (arg0 != 0) {
        D_002F0F40[D_00201F20] = arg0;
        D_00201F20 += 1;
        func_001E0560(D_002F0F40, D_00201F20);
    }
}
