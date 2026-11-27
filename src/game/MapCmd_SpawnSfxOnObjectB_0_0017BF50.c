#include "m2c.h"
f32 *Script_GetArgPtr_2_00165130(s8 *, s32);
s8 *MapObj_Find_1_001B19A0(s32);
f32 *Map_FindSfxEntry_0_001B7300(s8 *, s32);

void MapCmd_SpawnSfxOnObjectB_0_0017BF50(s8 *arg0) {
    s32 h = *(s32 *)(arg0 + 0x8);
    s32 k = *(s32 *)(arg0 + 0x10);
    f32 *p2 = Script_GetArgPtr_2_00165130(arg0, 2);
    f32 *p3 = Script_GetArgPtr_2_00165130(arg0, 3);
    f32 *p4 = Script_GetArgPtr_2_00165130(arg0, 4);
    f32 *p5 = Script_GetArgPtr_2_00165130(arg0, 5);
    f32 *p6 = Script_GetArgPtr_2_00165130(arg0, 6);
    f32 *p7 = Script_GetArgPtr_2_00165130(arg0, 7);
    f32 *p8 = Script_GetArgPtr_2_00165130(arg0, 8);
    f32 *p9 = Script_GetArgPtr_2_00165130(arg0, 9);
    f32 *p10 = Script_GetArgPtr_2_00165130(arg0, 10);
    f32 *p11 = Script_GetArgPtr_2_00165130(arg0, 11);
    f32 *p12 = Script_GetArgPtr_2_00165130(arg0, 12);
    f32 *p13 = Script_GetArgPtr_2_00165130(arg0, 13);
    f32 *p14 = Script_GetArgPtr_2_00165130(arg0, 14);
    f32 *p15 = Script_GetArgPtr_2_00165130(arg0, 15);
    f32 *d = Map_FindSfxEntry_0_001B7300(MapObj_Find_1_001B19A0(h), k);
    if (d != 0) {
        *p2 = d[0];
        *p3 = d[1];
        *p4 = d[2];
        *p5 = d[3];
        *p6 = 255.0f * d[4];
        *p7 = 255.0f * d[5];
        *p8 = 255.0f * d[6];
        *p9 = d[7];
        *p10 = d[8];
        *p11 = d[9];
        *p12 = d[10];
        *p13 = d[11];
        *p14 = d[12];
        *p15 = d[13];
    }
}
