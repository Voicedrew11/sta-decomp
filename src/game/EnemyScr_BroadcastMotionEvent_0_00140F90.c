#include "m2c.h"
s8 *ActorList_Next_2_001A5460(s32 *);
s32 Ent_IsNull0_1_0013EE30(s8 *);
s32 Enemy_GetTargetHandle_0_0013EDE0(s8 *);
s32 Enemy_GetMotionId_0_0013ED20(s8 *);
void Script_SetArgU8_1_00165070(void *, u8, s32, u32);
s32 Script_RunEvent_2_00166C10(void *, s32);
s32 Script_SendEvent_2_00166F80(void *, s32, void *);
#define H(o) (**(void ***)((o) + 0x4A4))

void EnemyScr_BroadcastMotionEvent_0_00140F90(u8 a, u8 b, u32 c, u32 d) {
    s32 it;
    s8 *o;
    s32 h;
    it = 0;
    o = ActorList_Next_2_001A5460(&it);
    while (o != NULL) {
        if (!Ent_IsNull0_1_0013EE30(o) && a == Enemy_GetTargetHandle_0_0013EDE0(o) && b == (u8)Enemy_GetMotionId_0_0013ED20(o)) {
            h = Script_SendEvent_2_00166F80(H(o), 0x2019, o);
            Script_SetArgU8_1_00165070(H(o), h, 0, c);
            Script_SetArgU8_1_00165070(H(o), h, 1, d);
            while ((s8)Script_RunEvent_2_00166C10(H(o), h)) {
            }
            return;
        }
        o = ActorList_Next_2_001A5460(&it);
    }
}
