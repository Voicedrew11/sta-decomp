#include "common.h"
typedef struct { u8 pad[4]; u16 x4; u8 pad6[0x8A]; } E;
typedef struct { u8 pad[2]; u8 x2; u8 pad3; } C;
typedef struct { u8 pad[0xA0]; C c[1024]; } S;
S *PlayerData_Get_2_001C9BA0(void);
E *Item_GetTable_1_001AFC90(void);

s32 Stats_CalcWeight_0_001D1170(void) {
    S *s;
    E *e;
    u32 i;
    s32 sum;
    s = PlayerData_Get_2_001C9BA0();
    e = Item_GetTable_1_001AFC90();
    sum = 0;
    for (i = 0; i < 1024; i++) {
        sum += s->c[i].x2 * e[i].x4;
    }
    return sum;
}
