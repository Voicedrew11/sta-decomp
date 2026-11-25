#include "common.h"
extern u16 D_00317238[];

s32 func_00180F10(void) {
    func_0015FC10();
    return ((*D_00317238) & 0xF008) != 0;
}
