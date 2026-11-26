#include "m2c.h"
s32 func_001E82A0(s32);
s32 func_001E6110(void);

s32 func_00180110(void) {
    s32 r = 0;
    func_001E82A0(0);
    switch (func_001E6110()) {
    case 1: r &= ~0xF; break;
    case 0: r |= 3; break;
    case 2: r |= 1; break;
    }
    func_001E82A0(1);
    switch (func_001E6110()) {
    case 1: r &= ~0xF0; break;
    case 0: r |= 0x30; break;
    case 2: r |= 0x10; break;
    }
    return r;
}
