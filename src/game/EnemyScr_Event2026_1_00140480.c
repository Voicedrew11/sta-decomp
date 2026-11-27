#include "m2c.h"
s32 Script_SendEvent_2_00166F80(void *, s32, void *);
void Script_SetArgU8_1_00165070(void *, u8, s32, u32);
void Script_SetArgU16_1_001650F0(void *, u8, s32, u32);
s8 Script_RunEvent_2_00166C10(void *, s32);
s32 Script_GetResultU8_1_00164FC0(void *, u8, s32);
static inline u32 cv(f32 x) { return (u32)x; }
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)

u8 EnemyScr_Event2026_1_00140480(Obj *a0, s32 a1, s32 a2, f32 f0, f32 f1, f32 f2, f32 f3) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2026, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, a1);
    if (f0 > 1.0f) f0 = 1.0f;
    if (f0 < 0.0f) f0 = 0.0f;
    Script_SetArgU8_1_00165070(H(a0), id, 1, cv(100.0f * f0));
    if (f1 > 1.2f) f1 = 1.2f;
    Script_SetArgU8_1_00165070(H(a0), id, 2, cv(100.0f * f1));
    if (f2 > 1.2f) f2 = 1.2f;
    Script_SetArgU8_1_00165070(H(a0), id, 3, cv(100.0f * f2));
    Script_SetArgU16_1_001650F0(H(a0), id, 4, (u32)f3);
    Script_SetArgU8_1_00165070(H(a0), id, 5, a2);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}
