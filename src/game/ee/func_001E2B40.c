#include "common.h"
extern void *D_00201E60;

void func_001E2B40(void *arg0) {
    M2C_FIELD(arg0, f32 *, 0) = (f32) M2C_FIELD(D_00201E60, f32 *, 0x10);
    M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(D_00201E60, f32 *, 0x14);
}
