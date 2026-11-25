#include "m2c.h"
s32 func_00131600(s32, s32);

s32 func_001CA1C0(u32 a) {
    switch (a) {
    case 0: return func_00131600(0x131, 0x7F);
    case 1: return func_00131600(0x12F, 0x7F);
    case 2: return func_00131600(0x12D, 0x7F);
    case 3: return func_00131600(0x137, 0x7F);
    case 4: return func_00131600(0x133, 0x7F);
    case 5: return func_00131600(0x135, 0x7F);
    case 7: return func_00131600(0x139, 0x7F);
    default: return -1;
    }
}
