#include "m2c.h"
#include "actor.h"
M2C_UNK func_0018E120(M2C_UNK, M2C_UNK *);          /* static */
extern M2C_UNK D_004A1068[];
extern M2C_UNK D_004A106C[];

void func_0018E0B0(s8 *arg0) {
    func_0018E120(0, D_004A1068);
    func_0018E120(1, D_004A106C);
    if (M2C_FIELD(arg0, s32 *, 4) & 0x2000) {
        M2C_FIELD(arg0, s8 *, 0xA) = 2;
        func_00131600(0x67, (s32) M2C_FIELD(arg0, u8 *, 0xE));
    }
}
