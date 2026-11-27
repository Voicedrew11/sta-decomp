#include "common.h"
typedef struct { u32 w; u32 pad; } W;
typedef struct { W x0; W x8; W x10; W x18; } Arg;
u8 *Script_GetArgPtr_2_00165130(Arg *, s32);
void *MapObj_FindById_0_00179DB0(u16, u16);
u8 Msg_ShowWrap_1_0018AC90(void *, s32);

void EnemyCmd_SpawnItem_0_001454E0(Arg *a) {
    u32 v = a->x8.w;
    u8 *p = Script_GetArgPtr_2_00165130(a, 1);
    u8 k = a->x18.w;
    void *o = MapObj_FindById_0_00179DB0(v / 1000, v % 1000);
    if (o) {
        if (k == 0) *p = Msg_ShowWrap_1_0018AC90(o, 0);
        if (k == 1) *p = Msg_ShowWrap_1_0018AC90(o, -1);
    } else {
        *p = 3;
    }
}
