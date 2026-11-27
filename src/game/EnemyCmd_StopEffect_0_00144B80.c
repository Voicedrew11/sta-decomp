#include "common.h"
typedef struct { u8 pad[2]; u8 x2; } C;
u8 *Script_GetArgPtr_2_00165130(s32, s32);
C *Inventory_GetEntry_1_001CC3F0(s16);
void EnemyCmd_StopEffect_0_00144B80(u16 *a0) {
    u16 v;
    u8 *p;
    u8 b;
    v = a0[4];
    p = Script_GetArgPtr_2_00165130((s32)a0, 1);
    b = Inventory_GetEntry_1_001CC3F0(v)->x2;
    if (b > 0x80) {
        *p = 0x80;
        return;
    }
    *p = b;
}

