#include "m2c.h"
typedef struct { u8 hp; u8 rem; u8 c; u8 pad1; } T;
typedef struct { s16 h0; u8 pad[0x7E]; s16 h80[10]; u8 pad2[0x0C]; T t[1]; } X;
X *PlayerData_Get_2_001C9BA0(void);
s32 Equip_GetDurability_1_001CCC10(s16 id, s32 arg1);
void Equip_Assign_1_001CCF50(s16 *, s32, s32);
void Player_RecalcStats_1_001CEDC0(s32);
void Snd_PlaySe_3_00131600(s32, s32);
static inline s16 slot(s32 i) {
    X *x = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10) return x->h80[i];
    return -1;
}
static inline T *getT(s32 i) {
    X *x = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10 && x->h80[i] != -1) return &x->t[x->h80[i]];
    return 0;
}

void Equip_DamageAmmo_0_001CC5E0(void) {
    s32 i;
    T *t;

    if (Equip_GetDurability_1_001CCC10(slot(((u8 *)PlayerData_Get_2_001C9BA0())[0x94] & 1), 1)) Snd_PlaySe_3_00131600(0x141, 0x7F);
    for (i = 0; i <= 6; i++) {
        t = getT(i);
        if (t && t->hp <= 0) {
            Equip_Assign_1_001CCF50(PlayerData_Get_2_001C9BA0()->h80, i, -1);
            Player_RecalcStats_1_001CEDC0(3);
        }
    }
}
