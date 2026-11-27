#include "m2c.h"
typedef struct {
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1;
    u8 pad1;
    u8 c0:1; u8 c1:2; u8 c3:5;
    u8 pad3;
} Arg;
extern u8 D_00201CBC[4];
void GsPkt_SetReg_3_001543E0(s32, s64);
void GsPkt_EndAD_3_00154420(void);
void GsPkt_BeginAD_3_001545D0(void);

void Mdl_SetBlendMode_1_0016F280(Arg a) {
    switch ((a.b5 ? 2 : 0) | (a.b6 ? 1 : 0)) {
    case 0:
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x47, ((u64)D_00201CBC[a.c1] << 4) | 0x5000D);
        GsPkt_SetReg_3_001543E0(0x49, 0);
        GsPkt_EndAD_3_00154420();
        break;
    case 1:
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x47, 0x51001);
        GsPkt_SetReg_3_001543E0(0x49, 0);
        GsPkt_EndAD_3_00154420();
        break;
    case 2:
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x47, ((u64)D_00201CBC[a.c1] << 4) | 0x3000D);
        GsPkt_SetReg_3_001543E0(0x49, 0);
        GsPkt_EndAD_3_00154420();
        break;
    case 3:
        GsPkt_BeginAD_3_001545D0();
        GsPkt_SetReg_3_001543E0(0x47, 0x31001);
        GsPkt_SetReg_3_001543E0(0x49, 0);
        GsPkt_EndAD_3_00154420();
        break;
    }
}
