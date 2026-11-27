#include "m2c.h"
void MapObj_GetNodeMatrix_0_001B7B30(s32, s32, f32 (*)[4]);
f32 *Script_GetArgPtr_2_00165130(s8 *, s32);

void MapCmd_GetNodePos_0_0017DA60(s8 *arg0) {
    f32 f[4][4];
    f32 a[4][4];
    s32 s1;
    s32 s0;
    f32 *px;
    f32 *py;
    f32 *pz;
    s32 i;
    f32 *p;
    f32 *q;

    s1 = *(s32 *)(arg0 + 8);
    s0 = *(s32 *)(arg0 + 0x10);
    px = Script_GetArgPtr_2_00165130(arg0, 2);
    py = Script_GetArgPtr_2_00165130(arg0, 3);
    pz = Script_GetArgPtr_2_00165130(arg0, 4);
    MapObj_GetNodeMatrix_0_001B7B30(s1, s0, a);
    i = 0;
    p = a[0];
    q = f[0];
    do {
        i++;
        q[0] = p[0];
        q[1] = p[1];
        q[2] = p[2];
        q[3] = p[3];
        p += 4;
        q += 4;
    } while (i < 4);
    *px = f[3][0];
    *py = f[3][1];
    *pz = f[3][2];
}
