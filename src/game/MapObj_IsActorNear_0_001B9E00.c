#include "m2c.h"
f32 Vec_DistSqXZ_2_0015DEB0(void *, s32);
f32 Vec_DistSq_3_0015DF20(void *, s32);
void Player_GetPos_1_001C9410(void *);
u16 *ActorList_NextB_0_001A5710(void);
u16 *ActorList_NextTargetable_0_001A5660(void);
void Enemy_CopyPosition_2_00140470(u16 *, void *);

s32 MapObj_IsActorNear_0_001B9E00(s32 arg0, s32 arg1, f32 r) {
    f32 sp40[4];
    u16 *p;

    r = r * r;
    Player_GetPos_1_001C9410(sp40);
    if (arg1 != 0) {
        if (Vec_DistSq_3_0015DF20(sp40, arg0) <= r) return 1;
    } else {
        if (Vec_DistSqXZ_2_0015DEB0(sp40, arg0) <= r) return 1;
    }
    p = ActorList_NextB_0_001A5710();
    if (p != NULL) {
        do {
            if (*p != 0) {
                Enemy_CopyPosition_2_00140470(p, sp40);
                if (arg1 != 0) {
                    if (Vec_DistSq_3_0015DF20(sp40, arg0) <= r) return 1;
                } else {
                    if (Vec_DistSqXZ_2_0015DEB0(sp40, arg0) <= r) return 1;
                }
            }
            p = ActorList_NextTargetable_0_001A5660();
        } while (p != NULL);
    }
    return 0;
}
