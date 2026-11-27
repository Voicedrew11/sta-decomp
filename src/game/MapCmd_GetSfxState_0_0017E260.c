#include "common.h"
typedef struct { u8 pad[8]; s32 x8; u8 padC[4]; s32 x10; u8 pad14[4]; s32 x18; u8 pad1C[0x1C]; s32 x38; u8 pad3C[4]; s32 x40; } O;
f32 *Script_GetArgPtr_2_00165130(O *, s32);
void MapObj_GetSfxMatrix_0_001B1050(s32, s32, Mtx *);
void MapObj_SetNodeMatrix_0_001B78D0(s32, s32, s32, Mtx *);
void MapObj_SetSfxMatrix_0_001B0EB0(s32, s32, Mtx *);

void MapCmd_GetSfxState_0_0017E260(O *o) {
    s32 a;
    s32 b;
    s32 t;
    f32 *p;
    f32 *q;
    f32 *r;
    s32 g;
    s32 h;
    Mtx m;
    a = o->x8;
    b = o->x10;
    t = o->x18;
    p = Script_GetArgPtr_2_00165130(o, 3);
    q = Script_GetArgPtr_2_00165130(o, 4);
    r = Script_GetArgPtr_2_00165130(o, 5);
    g = o->x38;
    h = o->x40;
    MapObj_GetSfxMatrix_0_001B1050(a, b, &m);
    switch (t) {
    case 1:
        m.m[3].x = *p;
        m.m[3].y = *q;
        m.m[3].z = *r;
        break;
    case 2:
        MapObj_SetNodeMatrix_0_001B78D0(a, g, h, &m);
        break;
    }
    MapObj_SetSfxMatrix_0_001B0EB0(a, b, &m);
}
