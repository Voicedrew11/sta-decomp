#include "common.h"
typedef struct { s32 a; s32 b; s32 x8; s32 xC; s32 x10; u16 x14; u16 x16; u8 x18; u8 pad[7]; } E;
extern E D_004B9F20[4];
s32 SndDrv_CallArgs_2_001D8680(s32 a, s32 b, s32 c, ...);
s32 Bgm_SetTrackParam_0_001D98D0(s32 i, s32 p1, s32 p2, s32 p3, u16 p4, u16 p5) {
    E *e;
    if (i < 0 || i >= 4) return 0;
    e = &D_004B9F20[i];
    if (e->a == 0) return 0;
    e->x8 = p1;
    e->x10 = p2;
    e->xC = p3;
    e->x14 = p4;
    e->x16 = p5;
    SndDrv_CallArgs_2_001D8680(3, 0, 0x20B0000, i, e->a, p2, p3, e->b, (u16)p4, (u16)p5);
    e->x18 = 1;
    return 1;
}
