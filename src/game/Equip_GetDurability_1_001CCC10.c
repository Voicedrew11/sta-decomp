#include "m2c.h"
typedef struct { u8 pad[0xA]; u16 a; u8 pad2[0x32]; u8 div; u8 pad3[0x90-0x3F]; } S;
typedef struct { u8 hp; u8 rem; u8 c; u8 pad1; } T;
typedef struct { u8 pad[0xA0]; T t[1]; } X;
X *PlayerData_Get_2_001C9BA0(void);
S *Item_GetTable_1_001AFC90(void);

s32 Equip_GetDurability_1_001CCC10(s16 id, s32 arg1) {
    X *x;
    S *s;
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
