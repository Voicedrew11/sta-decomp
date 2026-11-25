#include "common.h"
extern void *D_00201E60;

void func_001E2B18(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(D_00201E60, f32 *, 0x10) = (f32) M2C_FIELD(arg0, f32 *, 0);
        M2C_FIELD(D_00201E60, f32 *, 0x14) = (f32) M2C_FIELD(arg0, f32 *, 4);
    }
}
