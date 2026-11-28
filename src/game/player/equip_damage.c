#include "m2c.h"
#include "common.h"
#include "game/player.h"
typedef struct { u8 hp; u8 rem; u8 c; u8 pad1; } T_Equip_DamageWeapon_0_001CC450;
typedef struct { s16 h0; u8 pad[0x7E]; s16 h80[2]; s16 h84; s16 h86; s16 h88; s16 h8A; s16 h8C; u8 pad2[0x12]; T_Equip_DamageWeapon_0_001CC450 t[1]; } X_Equip_DamageWeapon_0_001CC450;
typedef struct { u8 pad[0x3F]; u8 b3F; u8 pad2[0x50]; } S_Equip_DamageWeapon_0_001CC450;
typedef struct { u8 hp; u8 rem; u8 c; u8 pad1; } T_Equip_DamageAmmo_0_001CC5E0;
typedef struct { s16 h0; u8 pad[0x7E]; s16 h80[10]; u8 pad2[0x0C]; T_Equip_DamageAmmo_0_001CC5E0 t[1]; } X_Equip_DamageAmmo_0_001CC5E0;
typedef struct { u8 hp; u8 rem; u8 c; u8 pad1; } T_Equip_DamageOnHit_0_001CC6F0;
typedef struct { s16 h0; u8 pad[0x7E]; s16 h80[2]; s16 h84; s16 h86; s16 h88; s16 h8A; s16 h8C; u8 pad8E[6]; u8 x94; u8 pad95[0xB]; T_Equip_DamageOnHit_0_001CC6F0 t[1]; } X_Equip_DamageOnHit_0_001CC6F0;
typedef struct { u8 hp; u8 rem; u8 c; u8 pad1; } T_Equip_DamageArmor_0_001CC830;
typedef struct { s16 h0; u8 pad[0x7E]; s16 h80[2]; s16 h84; s16 h86; s16 h88; s16 h8A; u8 pad2[0x14]; T_Equip_DamageArmor_0_001CC830 t[1]; } X_Equip_DamageArmor_0_001CC830;
typedef struct { u8 pad[0xA]; u16 a; u8 pad2[0x32]; u8 div; u8 pad3[0x90-0x3F]; } S_Equip_GetDurability_1_001CCC10;
typedef struct { u8 hp; u8 rem; u8 c; u8 pad1; } T_Equip_GetDurability_1_001CCC10;
typedef struct { u8 pad[0xA0]; T_Equip_GetDurability_1_001CCC10 t[1]; } X_Equip_GetDurability_1_001CCC10;
typedef struct { char p[4]; } E;
typedef struct { char pad[0x80]; s16 idx[10]; char p94[0xC]; E e[1]; } T_Equip_GetSlotEntry_0_001CCD30;
typedef struct { char pad[0x80]; s16 v[10]; } T_Equip_GetSlotItem_1_001CCD90;
void Equip_DamageWeapon_0_001CC450(u32 a0);
s32 Equip_GetDurability_1_001CCC10(s16 id, s32 arg1);
E* Equip_GetSlotEntry_0_001CCD30(s32 i);
s16 Equip_GetSlotItem_1_001CCD90(s32 i);
X_Equip_DamageWeapon_0_001CC450* PlayerData_Get_2_001C9BA0(void);
S_Equip_DamageWeapon_0_001CC450* Item_GetTable_1_001AFC90(void);
void Equip_Assign_1_001CCF50(s16 *, s32, s32);
void Player_RecalcStats_1_001CEDC0(s32);
void Snd_PlaySe_3_00131600(s32, s32);
s32 rand(void);

/* Equip_DamageWeapon_0_001CC450 */
static inline f32 u2f(u32 x) { return x; }
static inline T_Equip_DamageWeapon_0_001CC450 *getT_Equip_DamageWeapon_0_001CC450(s32 i) {
    X_Equip_DamageWeapon_0_001CC450 *x = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10 && x->h80[i] != -1) return &x->t[x->h80[i]];
    return 0;
}

void Equip_DamageWeapon_0_001CC450(u32 a0) {
    S_Equip_DamageWeapon_0_001CC450 *s;
    s32 n;
    s32 i;
    T_Equip_DamageWeapon_0_001CC450 *t;

    s = Item_GetTable_1_001AFC90();
    n = PlayerData_Get_2_001C9BA0()->h8C;
    if (n > 0) {
        if (Equip_GetDurability_1_001CCC10(n, (1.0f - 0.0007f * u2f(a0)) * u2f(s[n].b3F))) Snd_PlaySe_3_00131600(0x141, 0x7F);
        for (i = 0; i <= 6; i++) {
            t = getT_Equip_DamageWeapon_0_001CC450(i);
            if (t && t->hp <= 0) {
                Equip_Assign_1_001CCF50(PlayerData_Get_2_001C9BA0()->h80, i, -1);
                Player_RecalcStats_1_001CEDC0(3);
            }
        }
    }
}

/* Equip_DamageAmmo_0_001CC5E0 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Equip_DamageAmmo_0_001CC5E0
X_Equip_DamageAmmo_0_001CC5E0 *PlayerData_Get_2_001C9BA0__as_Equip_DamageAmmo_0_001CC5E0(void);
static inline s16 slot(s32 i) {
    X_Equip_DamageAmmo_0_001CC5E0 *x = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10) return x->h80[i];
    return -1;
}
static inline T_Equip_DamageAmmo_0_001CC5E0 *getT_Equip_DamageAmmo_0_001CC5E0(s32 i) {
    X_Equip_DamageAmmo_0_001CC5E0 *x = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10 && x->h80[i] != -1) return &x->t[x->h80[i]];
    return 0;
}

void Equip_DamageAmmo_0_001CC5E0(void) {
    s32 i;
    T_Equip_DamageAmmo_0_001CC5E0 *t;

    if (Equip_GetDurability_1_001CCC10(slot(((u8 *)PlayerData_Get_2_001C9BA0())[0x94] & 1), 1)) Snd_PlaySe_3_00131600(0x141, 0x7F);
    for (i = 0; i <= 6; i++) {
        t = getT_Equip_DamageAmmo_0_001CC5E0(i);
        if (t && t->hp <= 0) {
            Equip_Assign_1_001CCF50(PlayerData_Get_2_001C9BA0()->h80, i, -1);
            Player_RecalcStats_1_001CEDC0(3);
        }
    }
}
#undef PlayerData_Get_2_001C9BA0

/* Equip_DamageOnHit_0_001CC6F0 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Equip_DamageOnHit_0_001CC6F0
X_Equip_DamageOnHit_0_001CC6F0 *PlayerData_Get_2_001C9BA0__as_Equip_DamageOnHit_0_001CC6F0(void);
static inline T_Equip_DamageOnHit_0_001CC6F0 *getT_Equip_DamageOnHit_0_001CC6F0(s32 i) {
    X_Equip_DamageOnHit_0_001CC6F0 *x = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10 && x->h80[i] != -1) return &x->t[x->h80[i]];
    return 0;
}
static inline s16 getH(s32 i) {
    X_Equip_DamageOnHit_0_001CC6F0 *x = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10) return x->h80[i];
    return -1;
}

void Equip_DamageOnHit_0_001CC6F0(s32 a0, s32 a1) {
    X_Equip_DamageOnHit_0_001CC6F0 *x;
    s32 k;
    s32 i;
    T_Equip_DamageOnHit_0_001CC6F0 *t;

    x = PlayerData_Get_2_001C9BA0();
    if (a1 == 1) k = 1;
    else if (a1 == 0) k = 2;
    else k = 4;
    a0 *= k;
    if (Equip_GetDurability_1_001CCC10(getH(x->x94 & 1), a0)) Snd_PlaySe_3_00131600(0x141, 0x7F);
    for (i = 0; i <= 6; i++) {
        t = getT_Equip_DamageOnHit_0_001CC6F0(i);
        if (t && t->hp <= 0) {
            Equip_Assign_1_001CCF50(PlayerData_Get_2_001C9BA0()->h80, i, -1);
            Player_RecalcStats_1_001CEDC0(3);
        }
    }
}
#undef PlayerData_Get_2_001C9BA0

/* Equip_DamageArmor_0_001CC830 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Equip_DamageArmor_0_001CC830
X_Equip_DamageArmor_0_001CC830 *PlayerData_Get_2_001C9BA0__as_Equip_DamageArmor_0_001CC830(void);
static inline T_Equip_DamageArmor_0_001CC830 *getT_Equip_DamageArmor_0_001CC830(s32 i) {
    X_Equip_DamageArmor_0_001CC830 *x = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10 && x->h80[i] != -1) return &x->t[x->h80[i]];
    return 0;
}

void Equip_DamageArmor_0_001CC830(s32 a0, u32 a1, s32 a2, s32 a3) {
    X_Equip_DamageArmor_0_001CC830 *x;
    s32 hit;
    s32 m;
    s32 k;
    s32 v;
    s32 i;
    T_Equip_DamageArmor_0_001CC830 *t;

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
        t = getT_Equip_DamageArmor_0_001CC830(i);
        if (t && t->hp <= 0) {
            Equip_Assign_1_001CCF50(PlayerData_Get_2_001C9BA0()->h80, i, -1);
            Player_RecalcStats_1_001CEDC0(3);
        }
    }
    if (hit) Snd_PlaySe_3_00131600(0x141, 0x7F);
}
#undef PlayerData_Get_2_001C9BA0

/* Equip_GetDurability_1_001CCC10 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Equip_GetDurability_1_001CCC10
X_Equip_GetDurability_1_001CCC10 *PlayerData_Get_2_001C9BA0__as_Equip_GetDurability_1_001CCC10(void);
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Equip_GetDurability_1_001CCC10
S_Equip_GetDurability_1_001CCC10 *Item_GetTable_1_001AFC90__as_Equip_GetDurability_1_001CCC10(void);

s32 Equip_GetDurability_1_001CCC10(s16 id, s32 arg1) {
    X_Equip_GetDurability_1_001CCC10 *x;
    S_Equip_GetDurability_1_001CCC10 *s;
    s32 sum;
    s32 d;
    s32 q;

    x = PlayerData_Get_2_001C9BA0();
    s = Item_GetTable_1_001AFC90();
    if (id < 0 || id >= 0x400) return 0;
    if (s[id].a == 0) return 0;
    if (x->t[id].c <= 0) return 0;
    d = s[id].div;
    sum = x->t[id].rem + arg1;
    if (d <= 0) d = 1;
    q = sum / d;
    if (x->t[id].hp >= q) x->t[id].hp -= q;
    else x->t[id].hp = 0;
    x->t[id].rem = sum % d;
    return (u8)!x->t[id].hp;
}
#undef PlayerData_Get_2_001C9BA0
#undef Item_GetTable_1_001AFC90

/* Equip_GetSlotEntry_0_001CCD30 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Equip_GetSlotEntry_0_001CCD30
T_Equip_GetSlotEntry_0_001CCD30 *PlayerData_Get_2_001C9BA0__as_Equip_GetSlotEntry_0_001CCD30(void);

E *Equip_GetSlotEntry_0_001CCD30(s32 i)
{
    T_Equip_GetSlotEntry_0_001CCD30 *t = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10) {
        s16 k = t->idx[i];
        if (k != -1)
            return &t->e[k];
    }
    return NULL;
}
#undef PlayerData_Get_2_001C9BA0

/* Equip_GetSlotItem_1_001CCD90 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Equip_GetSlotItem_1_001CCD90
T_Equip_GetSlotItem_1_001CCD90 *PlayerData_Get_2_001C9BA0__as_Equip_GetSlotItem_1_001CCD90(void);

s16 Equip_GetSlotItem_1_001CCD90(s32 i)
{
    T_Equip_GetSlotItem_1_001CCD90 *t = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10)
        return t->v[i];
    return -1;
}
#undef PlayerData_Get_2_001C9BA0
