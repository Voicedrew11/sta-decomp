#include "m2c.h"
typedef struct { u8 b; u8 pad[7]; } W;
typedef struct { W x0; W x8; W x10; W x18; } Arg;
u32 MapState_GetWord_1_001AA540(u8, s16);
void MapState_SetWord_1_001AA5D0(u8, s16, u32);

void MapCmd_SetFlagBits_0_0017A920(Arg *p) {
    s32 q;
    s32 r;
    u32 m = 0;
    s32 a = p->x8.b;
    s32 b;

    if (a <= 200 && (b = p->x10.b) <= 32 && p->x18.b <= 255) {
        q = (u32)b / 4;
        r = b % 4;
        switch (r) {
        case 0: m = 0xFFFFFF00; break;
        case 1: m = 0xFFFF00FF; break;
        case 2: m = 0xFF00FFFF; break;
        case 3: m = 0x00FFFFFF; break;
        }
        MapState_SetWord_1_001AA5D0(p->x8.b, q, (m & MapState_GetWord_1_001AA540(a, q)) | (p->x18.b << (r * 8)));
    }
}
