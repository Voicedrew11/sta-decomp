#include "m2c.h"
s32 Script_SendEvent_2_00166F80(void *, s32, void *);
void Script_SetArgU8_1_00165070(void *, u8, s32, u32);
void Script_SetArgF32_1_00164FF0(void *, u8, s32, f32);
s8 Script_RunEvent_2_00166C10(void *, s32);
u8 Script_GetResultU8_1_00164FC0(void *, u8, s32);
f32 Script_GetResultF32_1_00164F60(void *, u8, s32);
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)

void EnemyScr_Event2023_1_00140CB0(Obj *a0, u8 *pa, f32 *pb, f32 *pc) {
    s32 h;
    h = Script_SendEvent_2_00166F80(H(a0), 0x2023, a0);
    Script_SetArgU8_1_00165070(H(a0), h, 0, 0);
    Script_SetArgF32_1_00164FF0(H(a0), h, 1, 2.0f);
    Script_SetArgF32_1_00164FF0(H(a0), h, 2, 0.0f);
    while (Script_RunEvent_2_00166C10(H(a0), h) != 0) {}
    if (pa) *pa = Script_GetResultU8_1_00164FC0(H(a0), h, 0);
    if (pb) *pb = Script_GetResultF32_1_00164F60(H(a0), h, 1);
    if (pc) *pc = Script_GetResultF32_1_00164F60(H(a0), h, 2);
}
