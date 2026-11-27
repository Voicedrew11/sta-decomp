#include "m2c.h"
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)
Obj *ActorList_Next_2_001A5460(s32 *);
s32 Ent_IsNull0_1_0013EE30(Obj *);
s32 Enemy_GetTargetHandle_0_0013EDE0(Obj *);
s32 Enemy_GetMotionFrame_0_0013ECA0(Obj *);
s32 Script_SendEvent_2_00166F80(void *, s32, void *);
void Script_SetArgU8_1_00165070(void *, u8, s32, u32);
s8 Script_RunEvent_2_00166C10(void *, s32);

void EnemyScr_BroadcastFrameEvent_0_001410C0(u8 a0, u8 a1, u32 a2, u32 a3) {
    s32 it;
    Obj *cur;
    s32 id;
    it = 0;
    cur = ActorList_Next_2_001A5460(&it);
    if (cur != NULL) {
        do {
            if (!Ent_IsNull0_1_0013EE30(cur) && Enemy_GetTargetHandle_0_0013EDE0(cur) == a0 && (u8)Enemy_GetMotionFrame_0_0013ECA0(cur) == a1) {
                id = Script_SendEvent_2_00166F80(H(cur), 0x2019, cur);
                Script_SetArgU8_1_00165070(H(cur), id, 0, a2);
                Script_SetArgU8_1_00165070(H(cur), id, 1, a3);
                while (Script_RunEvent_2_00166C10(H(cur), id) != 0) {}
            }
            cur = ActorList_Next_2_001A5460(&it);
        } while (cur != NULL);
    }
}
