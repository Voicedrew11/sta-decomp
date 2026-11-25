#include "m2c.h"
#include "actor.h"
M2C_UNK func_00102A60(s32, M2C_UNK *);                   /* extern */
extern u8 D_00201E24;
extern M2C_UNK D_004B4CE0[];

u8 func_001C9C00(s32 arg0) {
    if (arg0 != 0) {
        func_00102A60(arg0, D_004B4CE0);
    }
    return D_00201E24;
}
