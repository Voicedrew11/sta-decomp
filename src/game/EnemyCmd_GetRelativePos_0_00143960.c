#include "common.h"
typedef struct { f32 x, y, z; s32 w; } V3;
typedef struct { s32 p0, p4; u8 type; u8 p9[7]; f32 a; s32 p14; f32 b; s32 p1C; f32 c; } Arg;
Vec *Enemy_Ptr700_1_0013FF90(s8 *);
Vec *Enemy_Ptr6E0_1_0013FFB0(s8 *);
Vec *Enemy_PtrVec660_1_00140340(s8 *);
Vec *Enemy_GetPositionPtr_2_00140460(s8 *);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, void *);
void Enemy_GetForwardVector_2_001403D0(s8 *, Vec *, s8 *);
void Enemy_GetRightVector_1_00140360(s8 *, Vec *);
extern s8 *D_00201FA8;

void EnemyCmd_GetRelativePos_0_00143960(Arg *arg0) {
    V3 d;
    Vec t;
    s8 *o;
    s8 *g;
    u8 type;

    g = D_00201FA8;
    type = arg0->type;
    o = *(s8 **)(g + 0x154);
    d.x = arg0->a;
    d.y = arg0->b;
    d.z = arg0->c;
    d.w = 0;
    switch (type) {
    case 0:
        sceVu0CopyVector(Enemy_Ptr700_1_0013FF90(o), Enemy_Ptr6E0_1_0013FFB0(o));
        break;
    case 1:
        sceVu0AddVector(Enemy_Ptr700_1_0013FF90(o), Enemy_PtrVec660_1_00140340(o), &d);
        break;
    case 2: {
        Vec v = {0};
        Enemy_GetForwardVector_2_001403D0(o, &t, g);
        v.x += t.x * d.x;
        v.z += t.z * d.x;
        v.y += d.y;
        Enemy_GetRightVector_1_00140360(o, &t);
        v.x += t.x * d.z;
        v.z += t.z * d.z;
        sceVu0AddVector(Enemy_Ptr700_1_0013FF90(o), Enemy_GetPositionPtr_2_00140460(o), &v);
        break;
    }
    }
}
