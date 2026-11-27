#include "common.h"
typedef struct { u8 pad[4]; u8 b4, b5, b6; } E;
typedef struct { u8 pad[0x210]; E *x210[1]; } B;
typedef struct { u8 pad[0x90]; B *x90; u16 x94; } A;
u8 *Attack_GetParams_0_001D2C60(A *a) {
    E *t = a->x90->x210[a->x94];
    s32 x = t->b4 * 0x14; return (u8 *)(t->b6 * 0xC + (t->b5 * 4 + (x + (s32)t)) + 0x108);
}
