#include "m2c.h"
typedef struct { s32 idx; u8 pad4[0x28]; f32 f2C; f32 f30; u8 pad34[8]; u8 c[4]; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { u8 pad[4]; List *list; } Res;
Res *func_00189050(s32);
static inline f32 u2f(u32 x) { return x; }

void func_0018C140(f32 *a0, f32 *a1, u8 *a2, f32 f) {
    s32 i;
    List *l;
    Item A;
    Item B;
    f32 t;
    f32 u;

    i = f;
    l = func_00189050(4)->list;
    A = l->items[i % l->n];
    B = l->items[(i + 1) % l->n];
    t = f - i;
    u = 1.0f - t;
    *a0 = A.f2C * t + B.f2C * u;
    *a1 = A.f30 * t + B.f30 * u;
    a2[0] = (s32)((f32)(u32)A.c[0] * t + (f32)(u32)B.c[0] * u);
    a2[1] = (s32)((f32)(u32)A.c[1] * t + (f32)(u32)B.c[1] * u);
    a2[2] = (s32)((f32)(u32)A.c[2] * t + (f32)(u32)B.c[2] * u);
    a2[3] = (s32)((f32)(u32)A.c[3] * t + (f32)(u32)B.c[3] * u);
    if (a2[0] == 0x7F) a2[0] = 0x80;
    if (a2[1] == 0x7F) a2[1] = 0x80;
    if (a2[2] == 0x7F) a2[2] = 0x80;
    if (a2[3] == 0x7F) a2[3] = 0x80;
}
