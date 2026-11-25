#include "common.h"
extern void *D_00201E5C;
extern s32 D_00201E60;

void func_001E2610(s32 arg0) {
    func_001E5C60(M2C_FIELD(D_00201E5C, s32 *, 0x134), 0x100, (u32) arg0, -1);
    func_001E2748(D_00201E60 + 0x10, (u16 *) M2C_FIELD(D_00201E5C, s32 *, 0x134));
}
