#include "common.h"
typedef struct { u8 *base; s32 stride; u32 n; } L;
extern L D_004BAC30;
static inline void f(u8 *p) { if (p[0] == 2 || p[0] == 5) { p[1] = 2; p[0] = 2; } }
void Task_Remove_0_001E01F0(u8 *a) {
    u32 i;
    if (a == NULL) {
        for (i = 0; i < D_004BAC30.n; i++) f(D_004BAC30.base + D_004BAC30.stride * i);
    } else {
        f(a);
    }
}
