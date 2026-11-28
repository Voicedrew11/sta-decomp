#include "common.h"
#include "game/gfx.h"

void GsPkt_SetReg_3_001543E0(s32 reg, u64 v);

void Gfx_ResetBlendState_0_00145790(void)
{
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x1A, 1);
    GsPkt_SetReg_3_001543E0(0x42, 0xAA);
    GsPkt_SetReg_3_001543E0(0x43, 0x48);
    GsPkt_SetReg_3_001543E0(0x47, 0x50000);
    GsPkt_SetReg_3_001543E0(0x48, 0x50000);
    GsPkt_SetReg_3_001543E0(1, 0x80000);
    GsPkt_SetReg_3_001543E0(0x4E, ((u64)1 << 32) | 0x3A000118);
    GsPkt_SetReg_3_001543E0(0x4F, ((u64)1 << 32) | 0x3A000118);
    GsPkt_EndAD_3_00154420();
    Tex_FlushAll_1_00176AE0();
}
