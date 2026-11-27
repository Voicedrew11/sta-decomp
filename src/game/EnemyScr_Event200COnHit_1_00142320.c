#include "common.h"
s32 Script_SendEvent_2_00166F80(void *, s32, void *);
void Script_SetArgU8_1_00165070(void *, u8, s32, u32);
s8 Script_RunEvent_2_00166C10(void *, s32);
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
f32 Enemy_GetParam298_1_0013DD40(Obj *);
void Enemy_Set5D8_1_0013E430(Obj *, f32);
void Enemy_IncCounter6B8_1_0013EF50(Obj *);
#define H(a) (*(a)->p)
void EnemyScr_Event200COnHit_1_00142320(Obj *a0, s32 a1, s32 a2) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x200C, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, a1);
    Script_SetArgU8_1_00165070(H(a0), id, 1, a2);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    Enemy_Set5D8_1_0013E430(a0, Enemy_GetParam298_1_0013DD40(a0));
    Enemy_IncCounter6B8_1_0013EF50(a0);
}
