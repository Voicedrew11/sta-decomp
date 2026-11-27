#include "m2c.h"
typedef struct { u8 pad[0x4A4]; s32 *x4A4; } A;
s32 Script_SendEvent_2_00166F80(s32, s32, A *);
void Script_SetArgU8_1_00165070(s32, u8, s32, s32);
void Script_SetArgU16_1_001650F0(s32, u8, s32, u16);
void Script_SetArgF32_1_00164FF0(s32, u8, s32, f32);
s32 Script_RunEvent_2_00166C10(s32, s32);

void EnemyScr_Event200F_1_00141E10(A *a, s32 a1, f32 x, f32 y, f32 z, f32 w) {
    s32 h;
    u16 p;
    s32 q;
    h = Script_SendEvent_2_00166F80(*a->x4A4, 0x200F, a);
    p = (x < 30000.0f) ? (u16)(u32)x : 30000;

    q = (z < 30000.0f) ? (u16)(u32)z : 30000;
    Script_SetArgU8_1_00165070(*a->x4A4, h, 0, a1);
    Script_SetArgU16_1_001650F0(*a->x4A4, h, 1, p);
    Script_SetArgF32_1_00164FF0(*a->x4A4, h, 2, y);
    Script_SetArgF32_1_00164FF0(*a->x4A4, h, 3, w);
    Script_SetArgU16_1_001650F0(*a->x4A4, h, 4, q);
    while ((s8)Script_RunEvent_2_00166C10(*a->x4A4, h)) {
    }
}
