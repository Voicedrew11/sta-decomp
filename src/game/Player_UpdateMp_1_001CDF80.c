#include "m2c.h"
typedef struct { s16 x0; s16 max; s16 x4; s16 cur; u8 pad8[0x28]; u32 a30; u8 pad34[0xC]; u32 a40; u8 pad44[0xC]; s32 b50; u8 pad54[0xC]; s32 b60; } B;
typedef struct { u8 pad[0x418]; u16 max; u16 hp; } C;
extern u32 D_00201E94;
extern u8 D_00222A54[];
C *Player_GetBodyState_1_001C9B60(void);
B *PlayerData_Get_2_001C9BA0(void);
void Player_AddExp_0_001CEAA0(s32);
static inline u32 lvlA(void) {
    B *b = PlayerData_Get_2_001C9BA0();
    if (b->b50 == 0 && b->a30 != 0) {
        return b->a30 >> 24;
    }
    return 0;
}
static inline u32 lvlB(void) {
    B *b = PlayerData_Get_2_001C9BA0();
    if (b->b60 == 0 && b->a40 != 0) {
        return b->a40 >> 24;
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

void Player_UpdateMp_1_001CDF80(void) {
    C *r;
    s16 n;
    s16 d;
    B *b;

    r = Player_GetBodyState_1_001C9B60();
    n = 0;
    d = 0;
    if (D_00201E94 % 30 == 0 && r != NULL) {
        switch (lvlA()) {
        case 1:
            n = 3;
            break;
        case 2:
            n = 6;
            break;
        }
        if ((s32)lvlB() >= 2) {
            n = (n <= 0) ? 1 : n;
            d = 1;
        }
        if (!(D_00222A54[0] & 1)) {
            switch (hpState()) {
            case 2:
                n = (n < 5) ? 5 : n;
                break;
            }
        }
        Player_AddExp_0_001CEAA0(-n);
        b = PlayerData_Get_2_001C9BA0();
        b->cur += (s16)-d;
        if (b->cur < 0) {
            b->cur = 0;
        }
        if (b->max < b->cur) {
            b->cur = b->max;
        }
    }
}
