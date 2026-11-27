#include "m2c.h"
void Script_SetArgU8_1_00165070(void *, u8, s32, u32);
s32 Script_SendEvent_2_00166F80(void *, s32, void *);
s8 Script_RunEvent_2_00166C10(void *, s32);
s32 Script_GetResultU8_1_00164FC0(void *, u8, s32);
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)

u8 EnemyScr_Event2015_1_00141510(Obj *a0, u32 a1, u32 a2, u32 a3) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2015, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 0);
    Script_SetArgU8_1_00165070(H(a0), id, 1, a1);
    Script_SetArgU8_1_00165070(H(a0), id, 2, a2);
    Script_SetArgU8_1_00165070(H(a0), id, 3, a3);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}
