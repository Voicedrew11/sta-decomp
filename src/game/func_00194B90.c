#include "common.h"
typedef struct { s32 x0; s32 x4; s8 x8; s8 x9; s8 xA; s8 xB; s8 xC; s8 xD; u8 xE; } A;
void func_00131600(s32 a, u8 b);
s8 func_00189EA0(s32);
extern f32 D_004A118C[];
void func_00194B90(A *a) {
    s32 f = a->x4;
    if (f & 0x2000) {
        a->x8 = func_00189EA0(f);
        a->x4 = 0;
        a->x0 = 0x1A;
        D_004A118C[0] = 128.0f;
        a->xA = 2;
        func_00131600(0x69, a->xE);
    } else if (f & 0x4000) {
        a->xA = 2;
        func_00131600(0x68, a->xE);
    }
}
