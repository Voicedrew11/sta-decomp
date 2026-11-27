#include "m2c.h"
typedef struct { u8 hp; u8 rem; u8 c; u8 pad1; } T;
typedef struct { s16 h0; u8 pad[0x7E]; s16 h80[2]; s16 h84; s16 h86; s16 h88; s16 h8A; u8 pad2[0x14]; T t[1]; } X;
X *PlayerData_Get_2_001C9BA0(void);
s32 rand(void);
s32 Equip_GetDurability_1_001CCC10(s16 id, s32 arg1);
void Equip_Assign_1_001CCF50(s16 *, s32, s32);
void Player_RecalcStats_1_001CEDC0(s32);
void Snd_PlaySe_3_00131600(s32, s32);
static inline T *getT(s32 i) {
    X *x = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10 && x->h80[i] != -1) return &x->t[x->h80[i]];
    return 0;
}

void Equip_DamageArmor_0_001CC830(s32 a0, u32 a1, s32 a2, s32 a3) {
    X *x;
    s32 hit;
    s32 m;
    s32 k;
    s32 v;
    s32 i;
    T *t;

    x = PlayerData_Get_2_001C9BA0();
    hit = 0;
    if (a3 == 4) a3 = rand() % 4;
    if (a0 * 100 / x->h0 >= 5) m = 3; else m = 1;
    if (a2 == 1) k = 1;
    else if (a2 == 0) k = 2;
    else k = 4;
    if (a3 == 3) v = a1 * 0.01f + m * 3 * k;
    else v = a1 * 0.01f + m * k;
    if (Equip_GetDurability_1_001CCC10(PlayerData_Get_2_001C9BA0()->h84, v)) hit = 1;
    if (a3 == 0) v = a1 * 0.01f + m * 3 * k;
    else v = a1 * 0.01f + m * k;
    if (Equip_GetDurability_1_001CCC10(PlayerData_Get_2_001C9BA0()->h86, v)) hit = 1;
    if (a3 == 2) v = a1 * 0.01f + m * 3 * k;
    else v = a1 * 0.01f + m * k;
    if (Equip_GetDurability_1_001CCC10(PlayerData_Get_2_001C9BA0()->h88, v)) hit = 1;
    if (a3 == 1) v = a1 * 0.01f + m * 3 * k;
    else v = a1 * 0.01f + m * k;
    if (Equip_GetDurability_1_001CCC10(PlayerData_Get_2_001C9BA0()->h8A, v)) hit = 1;
    for (i = 0; i <= 6; i++) {
        t = getT(i);
        if (t && t->hp <= 0) {
            Equip_Assign_1_001CCF50(PlayerData_Get_2_001C9BA0()->h80, i, -1);
            Player_RecalcStats_1_001CEDC0(3);
        }
    }
    if (hit) Snd_PlaySe_3_00131600(0x141, 0x7F);
}
