#include "m2c.h"
s32 Script_SendEvent_2_00166F80(void *, s32, void *);
void Script_SetArgU8_1_00165070(void *, u8, s32, u32);
void Script_SetArgF32_1_00164FF0(void *, u8, s32, f32);
s8 Script_RunEvent_2_00166C10(void *, s32);
u8 Script_GetResultU8_1_00164FC0(void *, u8, s32);
f32 Script_GetResultF32_1_00164F60(void *, u8, s32);
f32 *Enemy_GetPositionPtr_2_00140460(void *);
f32 *Enemy_GetRotationPtr_1_00140430(void *);
f32 *Enemy_PtrVec660_1_00140340(void *);
f32 *Enemy_PtrVec670_1_00140320(void *);
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
static inline u16 mk(u16 lo, u16 hi) { return (u8)lo | ((u8)hi << 8); }
#define H(a) (*(a)->p)

u16 EnemyScr_Event2024GetMove_1_001409A0(Obj *a0, s32 a1, f32 *px, f32 *py, f32 *pz) {
    s32 h4;
    s32 h5;
    u16 r;
    h5 = Script_SendEvent_2_00166F80(H(a0), 0x2024, a0);
    h4 = Script_SendEvent_2_00166F80(H(a0), 0x2020, a0);
    Script_SetArgU8_1_00165070(H(a0), h4, 0, 0);
    while (Script_RunEvent_2_00166C10(H(a0), h4) != 0) {}
    if ((u8)Script_GetResultU8_1_00164FC0(H(a0), h4, 0) != 0) {
        Script_SetArgU8_1_00165070(H(a0), h5, 0, 1);
        Script_SetArgU8_1_00165070(H(a0), h5, 1, 1);
        Script_SetArgU8_1_00165070(H(a0), h5, 2, a1);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 3, Enemy_GetPositionPtr_2_00140460(a0)[0]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 4, Enemy_GetPositionPtr_2_00140460(a0)[2]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 5, Enemy_GetRotationPtr_1_00140430(a0)[1]);
    } else {
        Script_SetArgU8_1_00165070(H(a0), h5, 0, 8);
        Script_SetArgU8_1_00165070(H(a0), h5, 1, 6);
        Script_SetArgU8_1_00165070(H(a0), h5, 2, a1);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 3, Enemy_PtrVec660_1_00140340(a0)[0]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 4, Enemy_PtrVec660_1_00140340(a0)[2]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 5, Enemy_PtrVec670_1_00140320(a0)[1]);
    }
    while (Script_RunEvent_2_00166C10(H(a0), h5) != 0) {}
    h4 = Script_GetResultU8_1_00164FC0(H(a0), h5, 0);
    r = mk(h4, Script_GetResultU8_1_00164FC0(H(a0), h5, 1));
    if (px) *px = Script_GetResultF32_1_00164F60(H(a0), h5, 3);
    if (py) *py = Script_GetResultF32_1_00164F60(H(a0), h5, 4);
    if (pz) *pz = Script_GetResultF32_1_00164F60(H(a0), h5, 5);
    return r;
}
