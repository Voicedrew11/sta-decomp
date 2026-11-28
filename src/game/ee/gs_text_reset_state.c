#include "common.h"
#include "game/ee.h"
extern const f32 D_00201B80;
extern GsTextState *D_00201E5C;
extern GsTextStyle *D_00201E60;

void GsText_ResetState_0_001E2148(void) {
D_00201E60->x5C = 0; D_00201E60->x48 = -1; D_00201E60->x4C = -1; D_00201E60->x10 = 0; D_00201E60->x14 = 0; D_00201E60->x30 = 1.0f; D_00201E60->x34 = 1.0f; D_00201E60->x40 = D_00201B80; D_00201E60->x44 = D_00201B80; D_00201E60->x58 = D_00201E60->x54 = D_00201E60->x50 = 0; D_00201E60->x60 = 3.0f; D_00201E60->x0 = 0; D_00201E5C->x1C = D_00201E5C->x18; D_00201E5C->x24 = 0;
}
