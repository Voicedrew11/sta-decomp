#include "common.h"
extern void *D_00201E60;

void GsText_SetScale_1_001E2A28(void *arg0) {
    M2C_FIELD(D_00201E60, f32 *, 0x30) = (f32) M2C_FIELD(arg0, f32 *, 0);
    M2C_FIELD(D_00201E60, f32 *, 0x34) = (f32) M2C_FIELD(arg0, f32 *, 4);
}
