#include "m2c.h"
M2C_UNK func_001256E0(s8 *, M2C_UNK *, s32);
M2C_UNK func_00125CE8(s32, s8 *);
s32 func_00159D10(s8 *);
M2C_UNK func_0015AB80(s8 *);
s8 *func_0015ABD0(s32);
s32 func_0015A300(s8 *);
extern M2C_UNK D_001FDA80[];

void func_001B7050(s32 arg0, s32 arg1, s32 *arg2) {
    s8 sp30[0x100];
    s8 *temp_v0;

    func_001256E0((s8 *)sp30, D_001FDA80, arg0);
    if (arg1 != 0) {
        func_00125CE8(arg1, (s8 *)sp30);
    }
    if (arg2 != NULL) {
        temp_v0 = func_0015ABD0(func_00159D10((s8 *)sp30));
        *arg2 = func_0015A300(temp_v0);
        func_0015AB80(temp_v0);
    }
}
