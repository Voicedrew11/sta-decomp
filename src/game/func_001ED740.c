#include "common.h"
void func_00183750(s32);
extern s32 D_00201E78;
extern f32 D_00202404;
typedef struct { s32 x0; s32 x4; s8 x8; s8 p9[3]; s8 xC; } S;

void func_001ED740(S *a) {
    func_00183750(D_00201E78);
    a->xC = -0x11;
    if (a->x0 == 0x19) D_00202404 = 0.0f;
    if (a->x0 == 0x1E) a->xC = 0;
    if (a->x0 == 0x1C) {
        D_00202404 -= 8.0f;
        if (D_00202404 < 0.0f) D_00202404 = 0.0f;
    }
    if (a->x0 == 0x16) {
        D_00202404 += 8.0f;
        if (D_00202404 > 128.0f) D_00202404 = 128.0f;
        if ((a->x4 & 0x4000) || (a->x4 & 0x2000)) {
            a->x8 = 0x12;
            a->x4 = 0;
            a->x0 = 0x1A;
        }
    }
}
