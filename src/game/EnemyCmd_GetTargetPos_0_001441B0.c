#include "m2c.h"
void sceVu0CopyVector(s8 *, s8 *);
void EnemyCmd_FindTargetInCone_0_00143E20(s8 *, s32, s32, s32, s32, s32, f32);
s8 *Enemy_GetPositionPtr_2_00140460(s8 *);
s8 *Enemy_PtrVec660_1_00140340(s8 *);
extern s8 *D_00201FA8;

void EnemyCmd_GetTargetPos_0_001441B0(s8 *arg0) {
    s32 type;
    s32 b;
    s32 x, y, z;
    s8 *obj;
    s8 *p;
    f32 f;

    type = M2C_FIELD(arg0, u8 *, 8);
    b = M2C_FIELD(arg0, u8 *, 0x10);
    x = M2C_FIELD(arg0, s16 *, 0x18);
    y = M2C_FIELD(arg0, s16 *, 0x20);
    z = M2C_FIELD(arg0, s16 *, 0x28);
    obj = M2C_FIELD(D_00201FA8, s8 **, 0x154);
    f = M2C_FIELD(arg0, f32 *, 0x30);
    if (type == 0) {
        EnemyCmd_FindTargetInCone_0_00143E20(obj, type, b, x, y, z, f);
    } else if (type == 1) {
        p = Enemy_GetPositionPtr_2_00140460(obj);
        M2C_FIELD(p, f32 *, 0) += x;
        M2C_FIELD(p, f32 *, 4) += y;
        M2C_FIELD(p, f32 *, 8) += z;
        sceVu0CopyVector(M2C_FIELD(obj, s8 **, 0x518) + 0x1C0, p);
    } else if (type == 2) {
        p = Enemy_PtrVec660_1_00140340(obj);
        M2C_FIELD(p, f32 *, 0) += x;
        M2C_FIELD(p, f32 *, 4) += y;
        M2C_FIELD(p, f32 *, 8) += z;
    }
}
