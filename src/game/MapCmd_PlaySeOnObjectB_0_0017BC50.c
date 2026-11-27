#include "common.h"
typedef struct { u8 pad[8]; s32 x8; u8 pc[4]; s32 x10; u8 p14[4]; u8 x18; u8 p19[7]; u16 x20; u8 p22[6]; f32 x28; u8 p2c[4]; f32 x30; } A;
typedef struct { f32 a; f32 b; } P;
extern s8 **D_00201E80[2];
#define C (D_00201E80[2])
#define D (D_00201E80[3])
s8 *MapObj_Find_1_001B19A0(u8);
s32 MapObj_GetNodeIndex_0_001B7840(u8, u16);
s8 *Mdl_GetFrameData_0_001715B0(s32);
s32 Snd_PlaySeVolPan_1_00131520(s32, s32, s8 **, s32);
void SndCh_GetPosition_1_00131180(s32, P *);

void MapCmd_PlaySeOnObjectB_0_0017BC50(A *a) {
    s8 **h;
    s8 *o;
    s32 i;
    s8 *r;
    s32 q;
    P p;
    h = 0;
    o = MapObj_Find_1_001B19A0(a->x18);
    if (o == 0) return;
    if (C) { s8 *t = *C; if (t && t == o) h = C; }
    if (D && *D && *D == o) h = D;
    if (h == 0) return;
    i = MapObj_GetNodeIndex_0_001B7840(a->x18, a->x20);
    if (i < 0) return;
    r = Mdl_GetFrameData_0_001715B0(*(s32 *)(*(s8 **)(o + 0x180) + i * 128 + 0x40));
    if (r == 0) return;
    q = Snd_PlaySeVolPan_1_00131520(a->x8, a->x10, h, r + 0x230 - o);
    p.a = a->x28;
    p.b = a->x30;
    if (a->x28 != -1.0f) SndCh_GetPosition_1_00131180(q, &p);
}
