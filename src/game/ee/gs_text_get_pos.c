#include "common.h"
#include "game/ee.h"
extern GsTextStyle *D_00201E60;

void GsText_GetPos_1_001E2B40(void *arg0) {
    M2C_FIELD(arg0, f32 *, 0) = (f32) D_00201E60->x10;
    M2C_FIELD(arg0, f32 *, 4) = (f32) D_00201E60->x14;
}
