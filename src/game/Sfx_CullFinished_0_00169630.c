#include "common.h"
typedef struct { f32 v[12]; } M3;
typedef struct { M3 m[2]; } E;
typedef struct { u8 pad[0x114]; Flags8 f114; u8 pad2[0x120 - 0x115]; } B;
typedef struct { u16 prev; u16 next; u16 x4; } L;
extern s32 D_00201F2C;
extern u16 D_00201C9C;
extern u16 D_00201CA4;
extern B *D_00201FC0;
extern L *D_00201FD4;
extern E *D_00201FD0;

void Sfx_CullFinished_0_00169630(void) {
    u16 h[2] = {0};
    s32 i; s32 idx; s32 next;

    h[0] = D_00201C9C;
    h[1] = D_00201CA4;
    for (i = 0; i < 2; i++) {
        idx = h[i];
        while (idx != 0xFFFF) {
            next = D_00201FD4[idx].next;
            if (D_00201FC0[idx].f114.f.b0) { *(M3 *)((s32)&D_00201FD0[idx] + D_00201F2C * 0x30) = *(M3 *)((s32)&D_00201FD0[idx] + !(D_00201F2C != 0) * 0x30); }
            idx = next;
        }
    }
}
