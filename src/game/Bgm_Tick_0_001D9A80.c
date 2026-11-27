#include "common.h"
typedef struct { s32 x0; s32 x4; s32 x8; u8 xC; u8 xD; u8 xE; u8 xF; } S;
extern S D_004B9FA0;
s32 SndDrv_Call_2_001D85D0(s32, s32, s32);
s32 sceSifDmaStat(u32 id);
static inline s32 stop_9710(void) {
    S *s = &D_004B9FA0;
    if (D_004B9FA0.xC == 0) {
        return -1;
    }
    SndDrv_Call_2_001D85D0(3, 0, 0x02060000);
    if (s->x4 != 0) {
        if (sceSifDmaStat(s->x4) >= 0) {
            return 0;
        }
        s->x4 = 0;
    }
    s->xC = 0;
    s->xE = 0;
    return 1;
}
void Bgm_Tick_0_001D9A80(void) {
    S *s = &D_004B9FA0;
    s32 r = SndDrv_Call_2_001D85D0(3, 1, 0x02070000);
    switch (D_004B9FA0.xC) {
    case 1:
        if (r == 3) {
            SndDrv_Call_2_001D85D0(3, 0, 0x02010000);
            s->xE = 1;
            s->xC = 2;
        }
        break;
    case 2:
        if (r == 8) {
            stop_9710();
        }
        break;
    case 6:
        if (r == 3) {
            s->xC = 7;
        }
        break;
    }
    if (s->x4 != 0 && sceSifDmaStat(s->x4) < 0) {
        if (s->xC != 0) {
            SndDrv_Call_2_001D85D0(3, 0, 0x02050000);
        }
        s->x4 = 0;
    }
}
