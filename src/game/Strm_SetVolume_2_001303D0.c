#include "common.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 pad; s16 h; u16 vol; } St;
extern St D_00201EE0;
void Strm_DrvSetVolume_1_001D8CA0(s32, u16, u16);

void Strm_SetVolume_2_001303D0(u16 v) {
    if (v < 0) v = 0;
    if (v > 0x7FFF) v = 0x7FFF;
    D_00201EE0.vol = v;
    if (D_00201EE0.b1) Strm_DrvSetVolume_1_001D8CA0(1, D_00201EE0.vol, D_00201EE0.vol);
}
