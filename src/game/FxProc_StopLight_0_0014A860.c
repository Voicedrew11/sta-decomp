#include "common.h"
typedef struct { u8 pad[0x68]; f32 x68; u8 pad6C[0x44]; f32 xB0; } O;
void GlowFx_Stop_0_001E0D30(f32, s32);
void FxProc_StopLight_0_0014A860(O *o) {
    if ((s32)o->xB0 != -1) {
        GlowFx_Stop_0_001E0D30(o->x68, (s32)o->xB0);
    }
}
