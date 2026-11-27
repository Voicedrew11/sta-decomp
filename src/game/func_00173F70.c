#include "common.h"
typedef struct { s32 off; s32 x4; } Ent;
typedef struct { u8 pad[0x10]; u8 **base; u16 x14; u16 x16; u8 p18[0x28]; Ent e[1][2]; } T;

f32 func_00173F70(T *t, u16 i) {
    f32 r;
    if (t->x16 == 0) {
        r = 0.0f;
    } else {
        r = 0.00041666668f * (f32)*(s32 *)(*t->base + ((Ent (*)[2])((s32)t + 0x40))[t->x14][i].off + 4);
    }
    return r;
}
