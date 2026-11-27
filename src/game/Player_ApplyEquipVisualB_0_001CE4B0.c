/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
#include "m2c.h"
typedef struct { u8 pad0[0x394]; s8 x394; u8 pad1; s8 x396; u8 pad2; s16 x398; u8 pad3[2]; u8 x39C; } Obj;
typedef struct { u8 pad0[0x80]; s16 x80[2]; u8 pad1[0x10]; u8 x94; } V;
typedef struct { u8 pad0[4]; u16 x4; u8 pad1[0x8A]; } E;
V *PlayerData_Get_2_001C9BA0(void);
E *Item_GetTable_1_001AFC90(void);
static inline f32 u2f(u32 x) { return x; }
static inline s32 cls(s32 x) {
    switch (x) {
    case 7: case 8: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        return 1;
    case 9: case 19:
        return 2;
    }
    return 0;
}

void Player_ApplyEquipVisualB_0_001CE4B0(Obj *a0) {
    u16 *q = (u16 *)((u8 *)a0 + 0x460);
    V *v;
    E *t;
    s32 idx;
    u16 h;

    v = PlayerData_Get_2_001C9BA0();
    t = Item_GetTable_1_001AFC90();
    if (cls(a0->x39C) == 0) {
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

