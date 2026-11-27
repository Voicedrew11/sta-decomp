#include "common.h"
s32 Enemy_GetMotionId_0_0013ED20(void *p);
u8 Enemy_GetTargetHandle_0_0013EDE0(void *p);
s32 Ent_IsNull0_1_0013EE30(s8 *);
s8 *ActorList_Next_2_001A5460(s32 *);
void EnemyScr_Event2015_1_00141510(s8 *, u8, u8, u8);
void MapCmd_NotifyEnemies_0_0017A790(u8 *o) {
    s32 it;
    s8 *p;
    it = 0;
    for (p = ActorList_Next_2_001A5460(&it); p != NULL; p = ActorList_Next_2_001A5460(&it)) {
        if (Ent_IsNull0_1_0013EE30(p) == 0) {
            u8 a = Enemy_GetMotionId_0_0013ED20(p);
            u8 b = Enemy_GetTargetHandle_0_0013EDE0(p);
            if (a == o[0x10] && b == o[8]) EnemyScr_Event2015_1_00141510(p, o[8], o[0x18], o[0x20]);
        }
    }
}
