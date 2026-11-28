#include "common.h"
#include "game/ee.h"
extern GsTextStyle *D_00201E60;

void GsText_SetScale_1_001E2A28(void *arg0) {
    D_00201E60->x30 = (f32) M2C_FIELD(arg0, f32 *, 0);
    D_00201E60->x34 = (f32) M2C_FIELD(arg0, f32 *, 4);
}
