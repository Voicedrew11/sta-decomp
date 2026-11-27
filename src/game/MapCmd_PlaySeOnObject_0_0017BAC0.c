#include "common.h"
typedef struct { u8 pad[0x180]; s8 *x180; } C;
typedef struct { u8 pad[8]; s32 x8; u8 padC[4]; s32 x10; u8 pad14[0xC]; u8 x20; u8 pad21[7]; u16 x28; u8 pad2A[6]; f32 x30; u8 pad34[4]; f32 x38; } O;
typedef struct { f32 x, z; } V2;
extern s32 D_00201E80;
#define CC (((C ***)&D_00201E80)[2])
#define DD (((C ***)&D_00201E80)[3])
C *MapObj_Find_1_001B19A0(u8);
s32 MapObj_GetNodeIndex_0_001B7840(u8, u16);
s8 *Mdl_GetFrameData_0_001715B0(s32);
s32 *Script_GetArgPtr_2_00165130(O *, s32);
s32 Snd_PlaySeVolPan_1_00131520(s32, s32, C **, s32);
void SndCh_GetPosition_1_00131180(s32, V2 *);

void MapCmd_PlaySeOnObject_0_0017BAC0(O *o) {
    C **s;
    C *c;
    s8 *t;
    s32 *w;
    s32 r;
    V2 v;
    s32 k;
    s = 0;
    c = MapObj_Find_1_001B19A0(o->x20);
    if (c) {
        if (CC) { C *x = *CC; if (x && x == c) s = CC; }
        if (DD && *DD && *DD == c) s = DD;
        if (s) {
            r = MapObj_GetNodeIndex_0_001B7840(o->x20, o->x28);
            if (r >= 0) {
                t = Mdl_GetFrameData_0_001715B0(*(s32 *)(c->x180 + r * 0x80 + 0x40));
                if (t) {
                    w = Script_GetArgPtr_2_00165130(o, 2);
                    *w = Snd_PlaySeVolPan_1_00131520(o->x8, o->x10, s, t + 0x230 - (s8 *)c);
                    k = *w;
                    v.x = o->x30;
                    v.z = o->x38;
                    if (o->x30 != -1.0f) {
                        SndCh_GetPosition_1_00131180(k, &v);
                    }
                }
            }
        }
    }
}
