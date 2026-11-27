#include "actor.h"
extern s32 D_002022E0;
f32 sinf(f32);
void GsPkt_BeginAD_3_001545D0(void);
void GsPkt_SetReg_3_001543E0(s32, s32);
void GsPkt_Flush_1_001544C0(void);
void Hud_DrawQuad_1_001BC610(s32, s32, s32, s32, u32, s32, s32);
static inline f32 u2f(u32 x) { return x; }
static inline s8 *getp(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return D_002022E4->unk518 + 0x180;
}

void Hud_DrawWarning_0_001BC7A0(u32 a0, s32 a1, s32 a2) {
    u8 lo;
    s32 amp;
    s8 *p;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    u8 hi;
    s32 per;

    if (D_002022E4 == 0) p = 0; else if (D_002022E4->unk518 == 0) p = 0; else p = D_002022E4->unk518 + 0x180;
    if (p == 0) return;
    if (a1 <= 0 || a1 > 2) return;
    switch (a0) {
    case 1:
        per = (u8)((a1 == 1) ? 60 : 20);
        lo = 0x40; hi = 0x80; r = 100; g = 100; b = 100; a = 0x30;
        break;
    case 0:
        per = (u8)((a1 == 1) ? 60 : 20);
        lo = 0; hi = 0x80; r = 0x32; g = 0x20; b = 0x50; a = 0x30;
        break;
    case 4:
        per = (u8)((a1 == 1) ? 60 : 20);
        lo = 0x40; hi = 0x80; r = 0; g = 0x10; b = 0x40; a = 0x30;
        break;
    case 5:
        per = (u8)((a1 == 1) ? 60 : 20);
        lo = 0; hi = 0x80; r = 0x30; g = 0x30; b = 0x12; a = 0x30;
        break;
    case 3:
    case 7:
        per = (u8)((a1 == 1) ? 60 : 20);
        lo = 0x40; hi = 0x80; r = 0x48; g = 0x2A; b = 0x20; a = 0x2B;
        break;
    default:
        return;
    }
    amp = (u8)((hi - lo) / 2);
    amp = (u8)((f32)(lo + (u8)amp) + u2f(amp) * sinf(6.2831855f * (f32)(a2 % (u8)per) / u2f(per)));
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x42, 0x44);
    GsPkt_Flush_1_001544C0();
    Hud_DrawQuad_1_001BC610(-320, -224.0f + D_002022E0, 320, 224.0f - D_002022E0, a << 24 | b << 16 | g << 8 | r, 1, 0);
    Hud_DrawQuad_1_001BC610(-320, -224.0f + D_002022E0, 320, 224.0f - D_002022E0, (u8)amp << 24 | b << 16 | g << 8 | r, 1, *(s32 *)(p + 0x3B4));
}
