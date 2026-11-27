#include "m2c.h"
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)
Obj *ActorList_Next_2_001A5460(s32 *);
s32 Ent_IsNull0_1_0013EE30(Obj *);
s32 Enemy_GetTargetHandle_0_0013EDE0(Obj *);
s32 Ent_GetTypeByte_1_0013E220(Obj *);
s32 Enemy_IsDead_1_0013EEE0(Obj *);
s32 Script_SendEvent_2_00166F80(void *, s32, void *);
void Script_SetArgU8_1_00165070(void *, u8, s32, u32);
s8 Script_RunEvent_2_00166C10(void *, s32);
s32 Script_GetResultU8_1_00164FC0(void *, u8, s32);

u8 EnemyScr_BroadcastQuery_0_00141380(u32 a0, u32 a1) {
    s32 it;
    u8 n;
    Obj *cur;
    s32 k;
    s32 id;
    u8 v;
    n = 0;
    it = 0;
    cur = ActorList_Next_2_001A5460(&it);
    if (cur != NULL) {
        do {
            if (!Ent_IsNull0_1_0013EE30(cur)) {
                k = (u8)Enemy_GetTargetHandle_0_0013EDE0(cur);
                v = Ent_GetTypeByte_1_0013E220(cur);
                if (v >= 0x25 && v <= 0x28 && !Enemy_IsDead_1_0013EEE0(cur)) {
                    id = Script_SendEvent_2_00166F80(H(cur), 0x2015, cur);
                    Script_SetArgU8_1_00165070(H(cur), id, 0, 0);
                    Script_SetArgU8_1_00165070(H(cur), id, 1, k);
                    Script_SetArgU8_1_00165070(H(cur), id, 2, a0);
                    Script_SetArgU8_1_00165070(H(cur), id, 3, a1);
                    while (Script_RunEvent_2_00166C10(H(cur), id) != 0) {}
                    n += (u8)Script_GetResultU8_1_00164FC0(H(cur), id, 0);
                }
            }
            cur = ActorList_Next_2_001A5460(&it);
        } while (cur != NULL);
    }
    return n;
}
