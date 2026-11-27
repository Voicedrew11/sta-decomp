#include "m2c.h"
typedef struct { u8 x0, x1, x2, x3; } BE;
typedef struct { s8 pad[0x70]; u16 x70[8]; s16 x80[10]; u8 x94; s8 pad95[0xA0 - 0x95]; BE e[1]; } B;
B *PlayerData_Get_2_001C9BA0(void);
s8 *Player_GetBodyState_1_001C9B60(void);
void memset(void *, s32, s32);
void Stats_CalcAttack_0_001CF510(u16 *, s32, s8 *, s16 *, BE *, s32, s32);
static inline f32 u2f(u32 x) { return x; }

void Player_CalcAttack_1_001CEBF0(u16 *p, s32 a1, s32 a2) {
    B *b;
    s8 *c;
    BE buf[10];
    s32 i;

    b = PlayerData_Get_2_001C9BA0();
    c = Player_GetBodyState_1_001C9B60();
    if (c == NULL) return;
    memset(buf, 0, 0x28);
    for (i = 0; i < 10; i++) {
        if (b->x80[i] != -1) buf[i] = b->e[b->x80[i]];
    }
    Stats_CalcAttack_0_001CF510(p, a1, c + 0x460, b->x80, buf, b->x94 & 1, a2);
    for (i = 0; i < 6; i++) {
        if (b->x70[i]) {
            p[i] += (u16)(0.5f * u2f(p[i]));
            if ((s16)p[i] < 0) p[i] = 0;
            if ((s16)p[i] > 999) p[i] = 999;
        }
    }
}
