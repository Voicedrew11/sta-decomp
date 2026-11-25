#include "m2c.h"
#include "actor.h"
M2C_UNK func_00194D90(M2C_UNK, M2C_UNK *);          /* static */
extern M2C_UNK D_004A1198[];
extern M2C_UNK D_004A119C[];

void func_00194D20(s8 *arg0) {
    func_00194D90(0, D_004A1198);
    func_00194D90(1, D_004A119C);
    if (M2C_FIELD(arg0, s32 *, 4) & 0x2000) {
        M2C_FIELD(arg0, s8 *, 0xA) = 2;
        func_00131600(0x67, (s32) M2C_FIELD(arg0, u8 *, 0xE));
    }
}
