#include "m2c.h"
s32 Script_SendEvent_2_00166F80(void *, s32, void *);
void Script_SetArgU8_1_00165070(void *, u8, s32, u32);
s8 Script_RunEvent_2_00166C10(void *, s32);
u8 Script_GetResultU8_1_00164FC0(void *, u8, s32);
static inline f32 u2f(u32 x) { return x; }
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)

void EnemyScr_Event200DGetStats_1_00142090(Obj *a0, f32 *p0, f32 *p1, f32 *p2, f32 *p3) {
    s32 id;
    u32 a, b, c, d;
    id = Script_SendEvent_2_00166F80(H(a0), 0x200D, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 100);
    Script_SetArgU8_1_00165070(H(a0), id, 1, 100);
    Script_SetArgU8_1_00165070(H(a0), id, 2, 100);
    Script_SetArgU8_1_00165070(H(a0), id, 3, 100);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    a = Script_GetResultU8_1_00164FC0(H(a0), id, 0);
    b = Script_GetResultU8_1_00164FC0(H(a0), id, 1);
    c = Script_GetResultU8_1_00164FC0(H(a0), id, 2);
    d = Script_GetResultU8_1_00164FC0(H(a0), id, 3);
    if (p0) *p0 = u2f(a) / 100.0f;
    if (p1) *p1 = u2f(b) / 100.0f;
    if (p2) *p2 = u2f(c) / 100.0f;
    if (p3) *p3 = u2f(d) / 100.0f;
}
