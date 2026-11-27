#include "common.h"
typedef struct { u8 pad[8]; s32 x8; u8 padC[4]; s32 x10; u8 pad14[4]; s32 x18; } O;
f32 *Script_GetArgPtr_2_00165130(O *, s32);
void MapObj_SetNodeMatrix_0_001B78D0(s32, s32, s32, Mtx *);
void MapCmd_GetObjectFlag_0_0017DD90(O *o) {
    s32 a;
    s32 b;
    s32 t;
    f32 *p;
    f32 *q;
    f32 *r;
    Mtx m;
    a = o->x8;
    b = o->x10;
    t = o->x18;
    p = Script_GetArgPtr_2_00165130(o, 3);
    q = Script_GetArgPtr_2_00165130(o, 4);
    r = Script_GetArgPtr_2_00165130(o, 5);
    MapObj_SetNodeMatrix_0_001B78D0(a, b, t, &m);
    *p = m.m[3].x;
    *q = m.m[3].y;
    *r = m.m[3].z;
}
