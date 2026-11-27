#include "m2c.h"
typedef struct { u8 pad[0x418]; u16 max; u16 hp; } C;
extern u8 D_00222A54[];
C *Player_GetBodyState_1_001C9B60(void);
s32 *PlayerData_Get_2_001C9BA0(void);
static inline u32 lvl(s32 k) {
    s32 *b = PlayerData_Get_2_001C9BA0();
    if (b[k + 8] == 0 && b[k] != 0) {
        return (u32)b[k] >> 24;
    }
    return 0;
}
static inline s32 hpState(void) {
    C *c = Player_GetBodyState_1_001C9B60();
    u16 hp;
    u16 max;
    if (c == NULL) {
        return 0;
    }
    hp = c->hp;
    max = c->max;
    if (hp < max) {
        if (!(100.0f * (f32)(max - hp) / (f32)(u32)hp < 10.0f)) {
            return 2;
        }
        return 1;
    }
    return 0;
}

s32 Player_GetLevelInfo_0_001CD980(u8 *out, s8 *lv) {
    if (out == NULL || lv == NULL) return 0;
    *lv = lvl(13);
    if (*lv >= 2) { *out = 1; return 1; }
    *lv = lvl(12);
    if (*lv >= 2) { *out = 0; return 1; }
    *lv = lvl(16);
    if (*lv >= 2) { *out = 4; return 1; }
    *lv = lvl(17);
    if (*lv >= 2) { *out = 5; return 1; }
    *lv = lvl(15);
    if (*lv >= 2) { *out = 3; return 1; }
    if (!(D_00222A54[0] & 1)) {
        *lv = hpState();
    if (*lv >= 2) { *out = 7; return 1; }
    }
    *lv = lvl(13);
    if (*lv > 0) { *out = 1; return 1; }
    *lv = lvl(12);
    if (*lv > 0) { *out = 0; return 1; }
    *lv = lvl(16);
    if (*lv > 0) { *out = 4; return 1; }
    *lv = lvl(17);
    if (*lv > 0) { *out = 5; return 1; }
    *lv = lvl(15);
    if (*lv > 0) { *out = 3; return 1; }
    if (!(D_00222A54[0] & 1)) {
        *lv = hpState();
    if (*lv > 0) { *out = 7; return 1; }
    }
    return 0;
}
