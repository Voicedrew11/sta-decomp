#include "m2c.h"
#include "common.h"
typedef struct { u8 pad[0x42]; u16 v; u8 pad2[0x90-0x44]; } E_Player_ApplyEquipVisualA_0_001CE370;
typedef struct { u8 pad[0x374]; f32 f; u8 pad2[0x395-0x378]; s8 max; u8 p3; s8 cnt; u8 p4[2]; s16 timer; u8 p5[0x460-0x39C]; u8 sub[0x10]; } O_Player_ApplyEquipVisualA_0_001CE370;
typedef struct { u8 pad0[0x394]; s8 x394; u8 pad1; s8 x396; u8 pad2; s16 x398; u8 pad3[2]; u8 x39C; } Obj_Player_ApplyEquipVisualB_0_001CE4B0;
typedef struct { u8 pad0[0x80]; s16 x80[2]; u8 pad1[0x10]; u8 x94; } V_Player_ApplyEquipVisualB_0_001CE4B0;
typedef struct { u8 pad0[4]; u16 x4; u8 pad1[0x8A]; } E_Player_ApplyEquipVisualB_0_001CE4B0;
typedef struct { u8 pad[0x40]; u16 on; u16 v; u8 pad2[0x90-0x44]; } E_Player_UpdateEquipModelA_1_001CE660;
typedef struct { u8 pad[0x395]; s8 max; u8 p3; s8 cnt; u8 p4[2]; s16 timer; u8 p5[0x460-0x39C]; u8 sub[0x10]; } O_Player_UpdateEquipModelA_1_001CE660;
typedef struct { u8 pad0[0x394]; s8 x394; u8 pad1; s8 x396; u8 pad2; s16 x398; } Obj_Player_UpdateEquipModel_0_001CE7D0;
typedef struct { u8 pad0[0x80]; s16 x80; s16 x82; u8 pad1[0x10]; u8 x94; u8 pad2[0xB]; u8 col[10][4]; } V_Player_UpdateEquipModel_0_001CE7D0;
typedef struct { u8 pad0[4]; u16 x4; u8 pad1[0x1A]; u16 x20; u8 pad2[0x1D]; u8 x3F; u8 pad3[0x50]; } E_Player_UpdateEquipModel_0_001CE7D0;
typedef struct { u8 r, g, b, a; } Col;
typedef struct { s16 x0; s16 x2; s16 x4; } S;
typedef struct { u8 pad[0x3A2]; Flags8 x3A2; u8 pad3A3[0x7B]; s16 x41E; } O_Player_AddExp_0_001CEAA0;
void Player_ApplyEquipVisualA_0_001CE370(O_Player_ApplyEquipVisualA_0_001CE370 *arg0);
void Player_ApplyEquipVisualB_0_001CE4B0(Obj_Player_ApplyEquipVisualB_0_001CE4B0 *a0);
void Player_UpdateEquipModelA_1_001CE660(O_Player_UpdateEquipModelA_1_001CE660 *arg0, s32 arg1);
void Player_UpdateEquipModel_0_001CE7D0(Obj_Player_UpdateEquipModel_0_001CE7D0 *a0, s32 a1);
void Player_RefreshEquipModel_0_001CEA50(s32 arg0);
void Player_AddExp_0_001CEAA0(s32 d);
s8* PlayerData_Get_2_001C9BA0(void);
E_Player_ApplyEquipVisualA_0_001CE370* Item_GetTable_1_001AFC90(void);
O_Player_AddExp_0_001CEAA0* Player_GetBodyState_1_001C9B60(void);
s32 Game_GetBusy_0_0012C020(void);
void Menu_SetSubMode_0_0018A330(s32);
u32 Rand_Next_3_0015ED20(void);
void Snd_PlaySe_3_00131600(s32, s32);

/* Player_ApplyEquipVisualA_0_001CE370 */
void Player_ApplyEquipVisualA_0_001CE370(O_Player_ApplyEquipVisualA_0_001CE370 *arg0) {
    s8 *q;
    s8 *a;
    E_Player_ApplyEquipVisualA_0_001CE370 *b;
    E_Player_ApplyEquipVisualA_0_001CE370 *e;
    s16 idx;
    s16 t;
    u16 v;
    f32 x, y, z;

    q = arg0->sub;
    a = PlayerData_Get_2_001C9BA0();
    b = Item_GetTable_1_001AFC90();
    idx = M2C_FIELD(a, s16 *, 0x8C);
    if (idx != -1) { e = &b[idx]; if (arg0->cnt < arg0->max && arg0->f <= 0.0f) {
        if (arg0->timer > (s32)(30.0f * (0.03f * (f32)e->v - 0.00003f * (f32)(M2C_FIELD(q, u16 *, 0xA) * e->v)))) {
            arg0->cnt++;
            arg0->timer = 0;
        }
        arg0->timer++;
    } }
}

/* Player_ApplyEquipVisualB_0_001CE4B0 */
/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Player_ApplyEquipVisualB_0_001CE4B0
V_Player_ApplyEquipVisualB_0_001CE4B0 *PlayerData_Get_2_001C9BA0__as_Player_ApplyEquipVisualB_0_001CE4B0(void);
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Player_ApplyEquipVisualB_0_001CE4B0
E_Player_ApplyEquipVisualB_0_001CE4B0 *Item_GetTable_1_001AFC90__as_Player_ApplyEquipVisualB_0_001CE4B0(void);
static inline f32 u2f(u32 x) { return x; }
static inline s32 cls_Player_ApplyEquipVisualB_0_001CE4B0(s32 x) {
    switch (x) {
    case 7: case 8: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        return 1;
    case 9: case 19:
        return 2;
    }
    return 0;
}

void Player_ApplyEquipVisualB_0_001CE4B0(Obj_Player_ApplyEquipVisualB_0_001CE4B0 *a0) {
    u16 *q = (u16 *)((u8 *)a0 + 0x460);
    V_Player_ApplyEquipVisualB_0_001CE4B0 *v;
    E_Player_ApplyEquipVisualB_0_001CE4B0 *t;
    s32 idx;
    u16 h;

    v = PlayerData_Get_2_001C9BA0();
    t = Item_GetTable_1_001AFC90();
    if (cls_Player_ApplyEquipVisualB_0_001CE4B0(a0->x39C) == 0) {
        idx = v->x80[v->x94 & 1];
        if (idx == -1 || idx == 0) {
            h = (u16)3;
        } else {
            h = t[idx].x4;
        }
        if (a0->x396 < a0->x394) {
            if (a0->x398 > (s32)((0.3f + 0.05f * h - 0.00004f * (q[3] * (u16)h)) * 30.0f)) {
                a0->x396++;
                a0->x398 = 0;
            }
            a0->x398++;
        }
    }
}
#undef PlayerData_Get_2_001C9BA0
#undef Item_GetTable_1_001AFC90

/* Player_UpdateEquipModelA_1_001CE660 */
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Player_UpdateEquipModelA_1_001CE660
E_Player_UpdateEquipModelA_1_001CE660 *Item_GetTable_1_001AFC90__as_Player_UpdateEquipModelA_1_001CE660(void);

void Player_UpdateEquipModelA_1_001CE660(O_Player_UpdateEquipModelA_1_001CE660 *arg0, s32 arg1) {
    s8 *q;
    s8 *a;
    E_Player_UpdateEquipModelA_1_001CE660 *b;
    E_Player_UpdateEquipModelA_1_001CE660 *e;
    s16 idx;
    u16 v;

    q = arg0->sub;
    a = PlayerData_Get_2_001C9BA0();
    b = Item_GetTable_1_001AFC90();
    idx = M2C_FIELD(a, s16 *, 0x8C);
    if (idx == -1) {
        arg0->timer = 0;
        arg0->max = 0;
        arg0->cnt = 0;
        return;
    }
    e = &b[idx];
    if (e->on == 0) {
        arg0->timer = 0;
        arg0->max = 0;
        arg0->cnt = 0;
        return;
    }
    v = e->v;
    if (v >= 100) {
        arg0->max = 1;
    } else if (v >= 50) {
        arg0->max = 2;
    } else {
        arg0->max = 3;
    }
    arg0->max += (s8)(M2C_FIELD(q, u16 *, 0xE) / 300);
    if (arg0->max > 6) {
        arg0->max = 6;
    }
    if (arg1) {
        arg0->timer = 0;
        arg0->cnt = 0;
        return;
    }
    if (arg0->cnt < 0) {
        arg0->cnt = 0;
    }
    if (arg0->max < arg0->cnt) {
        arg0->cnt = arg0->max;
    }
}
#undef Item_GetTable_1_001AFC90

/* Player_UpdateEquipModel_0_001CE7D0 */
/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Player_UpdateEquipModel_0_001CE7D0
V_Player_UpdateEquipModel_0_001CE7D0 *PlayerData_Get_2_001C9BA0__as_Player_UpdateEquipModel_0_001CE7D0(void);
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Player_UpdateEquipModel_0_001CE7D0
E_Player_UpdateEquipModel_0_001CE7D0 *Item_GetTable_1_001AFC90__as_Player_UpdateEquipModel_0_001CE7D0(void);
static inline s32 cls_Player_UpdateEquipModel_0_001CE7D0(s32 x) {
    switch (x) {
    case 7: case 8: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        return 1;
    case 9: case 19:
        return 2;
    }
    return 0;
}

void Player_UpdateEquipModel_0_001CE7D0(Obj_Player_UpdateEquipModel_0_001CE7D0 *a0, s32 a1) {
    u16 *q = (u16 *)((u8 *)a0 + 0x460);
    V_Player_UpdateEquipModel_0_001CE7D0 *v;
    E_Player_UpdateEquipModel_0_001CE7D0 *t;
    E_Player_UpdateEquipModel_0_001CE7D0 *e;
    s32 idx;
    s32 m;
    u16 h;
    Col c;

    v = PlayerData_Get_2_001C9BA0();
    t = Item_GetTable_1_001AFC90();
    if (a1) {
        a0->x398 = 0;
    }
    idx = (v->x94 & 1) ? v->x82 : v->x80;
    if (idx == -1 || idx == 0) {
        a0->x394 = 1;
        if (a1) {
            a0->x396 = 0;
        } else {
            if (a0->x396 < 0) {
                a0->x396 = 0;
            }
            if (a0->x394 < a0->x396) {
                a0->x396 = a0->x394;
            }
        }
        return;
    }
    e = &t[idx];
    c = ((Col *)((u8 *)v + 0xA0))[idx];
    m = cls_Player_UpdateEquipModel_0_001CE7D0(e->x20);
    switch (m) {
    case 0:
        h = e->x4;
        if (h >= 30) {
            a0->x394 = 1;
        } else if (h >= 15) {
            a0->x394 = 2;
        } else {
            a0->x394 = 3;
        }
        a0->x394 += (s8)(q[1] / 300);
        if (a0->x394 > 6) {
            a0->x394 = 6;
        }
        if (a1) {
            a0->x396 = 0;
        } else {
            if (a0->x396 < 0) {
                a0->x396 = 0;
            }
            if (a0->x394 < a0->x396) {
                a0->x396 = a0->x394;
            }
        }
        break;
    case 1:
        a0->x394 = e->x3F;
        a0->x396 = c.a;
        break;
    case 2:
        a0->x394 = e->x3F;
        a0->x396 = 0;
        break;
    }
}
#undef PlayerData_Get_2_001C9BA0
#undef Item_GetTable_1_001AFC90

/* Player_RefreshEquipModel_0_001CEA50 */
#define Player_GetBodyState_1_001C9B60 Player_GetBodyState_1_001C9B60__as_Player_RefreshEquipModel_0_001CEA50
int Player_GetBodyState_1_001C9B60__as_Player_RefreshEquipModel_0_001CEA50();
#define Player_UpdateEquipModelA_1_001CE660 Player_UpdateEquipModelA_1_001CE660__as_Player_RefreshEquipModel_0_001CEA50
int Player_UpdateEquipModelA_1_001CE660__as_Player_RefreshEquipModel_0_001CEA50();
#define Player_UpdateEquipModel_0_001CE7D0 Player_UpdateEquipModel_0_001CE7D0__as_Player_RefreshEquipModel_0_001CEA50
int Player_UpdateEquipModel_0_001CE7D0__as_Player_RefreshEquipModel_0_001CEA50();
void Player_RefreshEquipModel_0_001CEA50(s32 arg0) {
    s32 temp_2;

    temp_2 = Player_GetBodyState_1_001C9B60();
    if (temp_2 != 0) {
        Player_UpdateEquipModel_0_001CE7D0((void *) temp_2, arg0);
        Player_UpdateEquipModelA_1_001CE660((void *) temp_2, arg0);
    }
}
#undef Player_GetBodyState_1_001C9B60
#undef Player_UpdateEquipModelA_1_001CE660
#undef Player_UpdateEquipModel_0_001CE7D0

/* Player_AddExp_0_001CEAA0 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Player_AddExp_0_001CEAA0
S *PlayerData_Get_2_001C9BA0__as_Player_AddExp_0_001CEAA0(void);

void Player_AddExp_0_001CEAA0(s32 d) {
    S *s;
    O_Player_AddExp_0_001CEAA0 *o;
    s = PlayerData_Get_2_001C9BA0();
    o = Player_GetBodyState_1_001C9B60();
    if (o && s->x4 > 0 && !Game_GetBusy_0_0012C020()) {
        s->x4 += (s16)d;
        if (s->x4 < 0) s->x4 = 0;
        if (s->x0 < s->x4) s->x4 = s->x0;
        if (s->x4 <= 0) {
            Menu_SetSubMode_0_0018A330(0);
            Snd_PlaySe_3_00131600(Rand_Next_3_0015ED20() % 3 + 0x128, 0x7F);
            o->x41E = 0;
            o->x3A2.f.b4 = 1;
        }
    }
}
#undef PlayerData_Get_2_001C9BA0
