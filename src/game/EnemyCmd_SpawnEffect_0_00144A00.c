#include "common.h"
extern s8 *D_00201FA8;
s8 *Script_GetArgPtr_2_00165130(s8 *, s32);
s8 Player_ThrowItem_0_001CA960(void);
s8 Player_HoldItem_0_001CAB20(s16, u8, Vec *, Vec *);
void Enemy_CopyPosition_2_00140470(s8 *, Vec *);
void Enemy_GetForwardVector_2_001403D0(s8 *, Vec *);
void Enemy_GetRightVector_1_00140360(s8 *, Vec *);
void Enemy_CopyRotation_2_00140440(s8 *, Vec *);

void EnemyCmd_SpawnEffect_0_00144A00(s8 *a0) {
    Vec A;
    Vec B;
    Vec C;
    s8 *o = *(s8 **)(D_00201FA8 + 0x154);
    u16 id = *(u16 *)(a0 + 8);
    s32 k = *(u8 *)(a0 + 0x10);
    s8 *res = Script_GetArgPtr_2_00165130(a0, 2);
    f32 f1 = *(f32 *)(a0 + 0x20);
    f32 f2 = *(f32 *)(a0 + 0x28);
    f32 f3 = *(f32 *)(a0 + 0x30);
    s8 r = Player_ThrowItem_0_001CA960();
    if (r == -1) {
        Enemy_CopyPosition_2_00140470(o, &A);
        Enemy_GetForwardVector_2_001403D0(o, &B);
        A.x = A.x + B.x * f1;
        A.z = A.z + B.z * f1;
        A.y = A.y + f2;
        Enemy_GetRightVector_1_00140360(o, &B);
        A.x = A.x + B.x * f3;
        A.z = A.z + B.z * f3;
        Enemy_CopyRotation_2_00140440(o, &C);
        r = Player_HoldItem_0_001CAB20(id, k, &A, &C);
    }
    if (r == 0) {
        *res = 0;
    } else {
        *res = 1;
    }
}
