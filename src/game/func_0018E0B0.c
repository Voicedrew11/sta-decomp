#include "common.h"
extern s32 D_004A1068[];
extern s32 D_004A106C[];

void func_0018E0B0(void *arg0) {
    func_0018E120(NULL, (s32) D_004A1068);
    func_0018E120((u8 *)1, (s32) D_004A106C);
    if (M2C_FIELD(arg0, s32 *, 4) & 0x2000) {
        M2C_FIELD(arg0, s8 *, 0xA) = 2;
        func_00131600(0x67, (s32) M2C_FIELD(arg0, u8 *, 0xE));
    }
}
