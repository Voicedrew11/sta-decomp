#include "m2c.h"
#include "common.h"
typedef struct { u8 pad0[0x22]; u8 k[2]; u8 v[2]; u8 pad2[0x90-0x26]; } E;
typedef struct { s16 x0; s16 x2; s16 x4; s16 x6; } S9BA0;
typedef struct { u8 pad[0x418]; u16 max; u16 hp; } C;
typedef struct { u8 pad[0x418]; u16 x418; u16 x41A; } P;
typedef struct { s16 x0; s16 max; s16 x4; s16 cur; u8 pad8[0x28]; u32 a30; u8 pad34[0xC]; u32 a40; u8 pad44[0xC]; s32 b50; u8 pad54[0xC]; s32 b60; } B;
extern u32 D_00201E94;
extern u8 D_00222A54[];
s32 Player_GetStat_2_001CD450(s32 a0, u8 *out, s32 a2, s32 a3);
void Player_UpdateRegen_1_001CD6C0(void);
s32 Player_GetLevelInfo_0_001CD980(u8 *out, s8 *lv);
s32 Player_GetWeight_1_001CDEC0(void);
void Player_UpdateMp_1_001CDF80(void);
S9BA0* PlayerData_Get_2_001C9BA0(void);
u8* Item_GetTable_1_001AFC90(void);
void Player_AddStatus_1_001C88E0(s32, s32, s32);
void Player_AddExp_0_001CEAA0(s32);
C* Player_GetBodyState_1_001C9B60(void);

/* Player_GetStat_2_001CD450 */
s32 Player_GetStat_2_001CD450(s32 a0, u8 *out, s32 a2, s32 a3) {
    u8 *p = (u8 *)PlayerData_Get_2_001C9BA0();
    E *base = (E *)Item_GetTable_1_001AFC90();
    s16 idx;
    s16 *slots;
    s32 found;
    u8 val;
    s32 i, j;
    found = 0;
    val = a3 ? 0 : 0xFF;
    slots = (s16 *)(p + 0x80);
    if (a2) {
        idx = slots[p[0x94] & 1];
        if (idx > 0) {
            for (j = 0; j < 2; j++) {
                if ((u8)a0 == base[idx].k[j]) {
                    if (a3) {
                        val = (base[idx].v[j] < val) ? val : base[idx].v[j];
                    } else {
                        val = (val < base[idx].v[j]) ? val : base[idx].v[j];
                    }
                    found = 1;
                }
            }
        }
        if (out) *out = val;
        return found;
    }
    for (i = 0; i < 2; i++) {
        idx = slots[i];
        if (idx > 0) {
            for (j = 0; j < 2; j++) {
                if ((u8)a0 == base[idx].k[j]) {
                    if (a3) {
                        val = (base[idx].v[j] < val) ? val : base[idx].v[j];
                    } else {
                        val = (val < base[idx].v[j]) ? val : base[idx].v[j];
                    }
                    found = 1;
                }
            }
        }
    }
    for (i = 2; i < 9; i++) {
        idx = slots[i];
        if (idx > 0) {
            for (j = 0; j < 2; j++) {
                if ((u8)a0 == base[idx].k[j]) {
                    if (a3) {
                        val = (base[idx].v[j] < val) ? val : base[idx].v[j];
                    } else {
                        val = (val < base[idx].v[j]) ? val : base[idx].v[j];
                    }
                    found = 1;
                }
            }
        }
    }
    if (out) *out = val;
    return found;
}

/* Player_UpdateRegen_1_001CD6C0 */
void Player_UpdateRegen_1_001CD6C0(void) {
    u8 c;
    S9BA0 *p;

    if (Player_GetStat_2_001CD450(8, &c, 0, 0) && c && D_00201E94 % c == 0) {
        Player_AddExp_0_001CEAA0(1);
    }
    if (Player_GetStat_2_001CD450(9, &c, 0, 0) && c && D_00201E94 % c == 0) {
        Player_AddExp_0_001CEAA0(-1);
    }
    if (Player_GetStat_2_001CD450(0xB, &c, 0, 0) && c && D_00201E94 % c == 0) {
        p = PlayerData_Get_2_001C9BA0();
        p->x6++;
        if (p->x6 < 0) {
            p->x6 = 0;
        }
        if (p->x2 < p->x6) {
            p->x6 = p->x2;
        }
    }
    if (Player_GetStat_2_001CD450(0xC, &c, 0, 0) && c && D_00201E94 % c == 0) {
        p = PlayerData_Get_2_001C9BA0();
        p->x6--;
        if (p->x6 < 0) {
            p->x6 = 0;
        }
        if (p->x2 < p->x6) {
            p->x6 = p->x2;
        }
    }
    if (Player_GetStat_2_001CD450(1, NULL, 0, 1)) Player_AddStatus_1_001C88E0(0, 1, 0);
    if (Player_GetStat_2_001CD450(2, NULL, 0, 1)) Player_AddStatus_1_001C88E0(1, 1, 0);
    if (Player_GetStat_2_001CD450(3, NULL, 0, 1)) Player_AddStatus_1_001C88E0(2, 1, 0);
    if (Player_GetStat_2_001CD450(4, NULL, 0, 1)) Player_AddStatus_1_001C88E0(4, 1, 0);
    if (Player_GetStat_2_001CD450(5, NULL, 0, 1)) Player_AddStatus_1_001C88E0(3, 1, 0);
    if (Player_GetStat_2_001CD450(6, NULL, 0, 1)) Player_AddStatus_1_001C88E0(5, 1, 0);
}

/* Player_GetLevelInfo_0_001CD980 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Player_GetLevelInfo_0_001CD980
s32 *PlayerData_Get_2_001C9BA0__as_Player_GetLevelInfo_0_001CD980(void);
static inline u32 lvl(s32 k) {
    s32 *b = PlayerData_Get_2_001C9BA0();
    if (b[k + 8] == 0 && b[k] != 0) {
        return (u32)b[k] >> 24;
    }
    return 0;
}
static inline s32 hpState_Player_GetLevelInfo_0_001CD980(void) {
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
        *lv = hpState_Player_GetLevelInfo_0_001CD980();
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
        *lv = hpState_Player_GetLevelInfo_0_001CD980();
    if (*lv > 0) { *out = 7; return 1; }
    }
    return 0;
}
#undef PlayerData_Get_2_001C9BA0

/* Player_GetWeight_1_001CDEC0 */
#define Player_GetBodyState_1_001C9B60 Player_GetBodyState_1_001C9B60__as_Player_GetWeight_1_001CDEC0
P *Player_GetBodyState_1_001C9B60__as_Player_GetWeight_1_001CDEC0(void);
static inline f32 u2f(u32 x) { return x; }
s32 Player_GetWeight_1_001CDEC0(void) {
    P *p = Player_GetBodyState_1_001C9B60();
    u16 a, b;
    if (p == NULL) return 0;
    a = p->x41A;
    b = p->x418;
    if (a < b) {
        if (100.0f * (s32)(b - a) / u2f(a) >= 10.0f) return 2; return 1;
    }
    return 0;
}
#undef Player_GetBodyState_1_001C9B60

/* Player_UpdateMp_1_001CDF80 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Player_UpdateMp_1_001CDF80
B *PlayerData_Get_2_001C9BA0__as_Player_UpdateMp_1_001CDF80(void);
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
static inline s32 hpState_Player_UpdateMp_1_001CDF80(void) {
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
            switch (hpState_Player_UpdateMp_1_001CDF80()) {
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
#undef PlayerData_Get_2_001C9BA0
