#include "common.h"
typedef struct { u8 pad[0x418]; u16 x418; u16 x41A; } P;
P *func_001C9B60(void);
static inline f32 u2f(u32 x) { return x; }
s32 func_001CDEC0(void) {
    P *p = func_001C9B60();
    u16 a, b;
    if (p == NULL) return 0;
    a = p->x41A;
    b = p->x418;
    if (a < b) {
        if (100.0f * (s32)(b - a) / u2f(a) >= 10.0f) return 2; return 1;
    }
    return 0;
}
