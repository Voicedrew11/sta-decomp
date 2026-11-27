#include "m2c.h"
typedef struct { u8 pad[0x42]; u16 v; u8 pad2[0x90-0x44]; } E;
typedef struct { u8 pad[0x374]; f32 f; u8 pad2[0x395-0x378]; s8 max; u8 p3; s8 cnt; u8 p4[2]; s16 timer; u8 p5[0x460-0x39C]; u8 sub[0x10]; } O;
s8 *PlayerData_Get_2_001C9BA0(void);
E *Item_GetTable_1_001AFC90(void);

void Player_ApplyEquipVisualA_0_001CE370(O *arg0) {
    s8 *q;
    s8 *a;
    E *b;
    E *e;
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
