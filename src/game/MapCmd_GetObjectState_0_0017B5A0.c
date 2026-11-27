#include "m2c.h"
s32 MapObj_Find_1_001B19A0(s32);
s8 *Map_GetFogEntry_0_001B40F0(s32, s32);
void Map_UpdateFog_0_001B4100(s32);
f32 *Script_GetArgPtr_2_00165130(s8 *, s32);

void MapCmd_GetObjectState_0_0017B5A0(s8 *a0) {
    s8 *p;
    s32 s0;
    s0 = *(s32 *)(a0 + 8);
    p = Map_GetFogEntry_0_001B40F0(MapObj_Find_1_001B19A0(s0), *(s32 *)(a0 + 0x10));
    if (p != 0) {
        f32 f;
        f = *(f32 *)(p + 0x10); *Script_GetArgPtr_2_00165130(a0, 2) = f;
        f = *(f32 *)(p + 0x14); *Script_GetArgPtr_2_00165130(a0, 3) = f;
        f = *(f32 *)(p + 0x18); *Script_GetArgPtr_2_00165130(a0, 4) = f;
        f = *(f32 *)(p + 0x1C); *Script_GetArgPtr_2_00165130(a0, 5) = f;
        f = *(f32 *)(p + 0x30); *Script_GetArgPtr_2_00165130(a0, 6) = f;
        f = *(f32 *)(p + 0x34); *Script_GetArgPtr_2_00165130(a0, 7) = f;
        f = *(f32 *)(p + 0x38); *Script_GetArgPtr_2_00165130(a0, 8) = f;
        f = *(f32 *)(p + 0x3C); *Script_GetArgPtr_2_00165130(a0, 9) = f;
        f = *(f32 *)(p + 0x40); *Script_GetArgPtr_2_00165130(a0, 10) = f;
        f = *(f32 *)(p + 0x44); *Script_GetArgPtr_2_00165130(a0, 11) = f;
        f = *(f32 *)(p + 0x48); *Script_GetArgPtr_2_00165130(a0, 12) = f;
        f = *(f32 *)(p + 0x4C); *Script_GetArgPtr_2_00165130(a0, 13) = f;
        f = *(f32 *)(p + 0x50); *Script_GetArgPtr_2_00165130(a0, 14) = f;
        f = *(f32 *)(p + 0x54); *Script_GetArgPtr_2_00165130(a0, 15) = f;
        Map_UpdateFog_0_001B4100(MapObj_Find_1_001B19A0(s0));
    }
}
