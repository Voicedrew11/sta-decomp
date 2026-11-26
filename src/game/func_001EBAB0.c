#include "common.h"
typedef struct { s32 x0; u8 pad[0x28]; s32 x2C; s32 x30; s32 x34; s32 x38; s32 x3C; } S;
void func_001EBAB0(S *s, s32 *a1, s32 *a2, s32 *a3, s32 *a4) {
    s32 n;
    if (s->x0 == 0) {
        *a1 = s->x2C + (s32)s + 4;
        *a2 = 0x28 - s->x2C;
        *a3 = s->x30;
        *a4 = s->x3C;
        return;
    }
    n = s->x3C - s->x38;
    if (s->x3C - s->x34 >= n) {
        *a1 = s->x30 + s->x34;
        *a2 = n;
        *a3 = 0;
        *a4 = 0;
    } else {
        *a1 = s->x30 + s->x34;
        *a2 = s->x3C - s->x34;
        *a3 = s->x30;
        *a4 = n - (s->x3C - s->x34);
    }
}
