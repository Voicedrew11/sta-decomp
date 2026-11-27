#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
u8 Enemy_GetTargetHandle_0_0013EDE0(void *p);
s32 Enemy_GetMotionId_0_0013ED20(void *p);
void EnemyScr_BroadcastMotionEvent_0_00140F90(u8 x, u8 a, u8 y, u8 b);

void EnemyCmd_BroadcastMotion_1_001442F0(u8 *o)
{
    u8 a = o[8];
    u8 b = o[0x10];
    void *p = D_00201FA8->p;
    u8 x = Enemy_GetTargetHandle_0_0013EDE0(p);
    EnemyScr_BroadcastMotionEvent_0_00140F90(x, a, (u8)Enemy_GetMotionId_0_0013ED20(p), b);
}
