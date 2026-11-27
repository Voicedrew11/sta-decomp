#include "common.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 pad; s16 h; s16 vol; } St;
extern St D_00201EE0;
s32 Strm_DrvGetStatus_1_001D8C50(void);
void Strm_DrvSetVolume_1_001D8CA0(s32, u16, u16);
s32 Strm_DrvSetMode_1_001D8CC0(s32, s32);
void Strm_Update_1_001304C0(void) {
    if (!D_00201EE0.b1) return;
    if (Strm_DrvGetStatus_1_001D8C50() == 0) return;
    if (D_00201EE0.b0) {
        Strm_DrvSetMode_1_001D8CC0(1, D_00201EE0.b2 != 0);
        D_00201EE0.b0 = 0;
    }
    if (D_00201EE0.h != 0) {
        D_00201EE0.vol += D_00201EE0.h;
        if (D_00201EE0.vol < 0) D_00201EE0.vol = 0;
        if (D_00201EE0.vol > 0x7FFF) D_00201EE0.vol = 0x7FFF;
        Strm_DrvSetVolume_1_001D8CA0(1, D_00201EE0.vol, D_00201EE0.vol);
    }
}
