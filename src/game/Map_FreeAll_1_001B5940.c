#include "common.h"

typedef struct { f32 v[4]; s32 x10; u8 b14; char p15[3]; s32 x18; } Out;
extern s32 D_00201E88, D_00201E8C;
extern s32 D_002022B8;
s32 Map_StreamGetResult_1_001B0660(Out *o);
void Map_FreeArea_1_001B5640(s32 h);
void Map_StreamFlush_1_001B03E0(void);
void PointLightGroup_Clear_0_0015C6D0(s32 i);
void LightGroup_Clear_0_0015B890(s32 i);
void SndEmit_KillAll_1_0012F920(void);
void MapSe_Flush_0_001E1CC0(void);

void Map_FreeAll_1_001B5940(void)
{
    Out t;
    Map_StreamGetResult_1_001B0660(&t);
    if (t.x18)
        Map_FreeArea_1_001B5640(t.x18);
    Map_StreamFlush_1_001B03E0();
    if (D_00201E88) {
        PointLightGroup_Clear_0_0015C6D0(0);
        LightGroup_Clear_0_0015B890(0);
        Map_FreeArea_1_001B5640(D_00201E88);
        D_00201E88 = 0;
    }
    if (D_00201E8C) {
        PointLightGroup_Clear_0_0015C6D0(1);
        LightGroup_Clear_0_0015B890(1);
        Map_FreeArea_1_001B5640(D_00201E8C);
        D_00201E8C = 0;
    }
    SndEmit_KillAll_1_0012F920();
    D_002022B8 = 0;
    MapSe_Flush_0_001E1CC0();
}
