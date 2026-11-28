#include "common.h"
#include "game/ee.h"
extern GsTextStyle *D_00201E60;

void GsText_SetPos_1_001E2B18(void *arg0) {
    if (arg0 != NULL) {
        D_00201E60->x10 = (f32) M2C_FIELD(arg0, f32 *, 0);
        D_00201E60->x14 = (f32) M2C_FIELD(arg0, f32 *, 4);
    }
}
