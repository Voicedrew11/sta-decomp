#include "common.h"
typedef struct { u8 p[0x20]; f32 x; f32 y; f32 z; } R;
typedef struct { u8 p[0x18]; R *r; } Q;
typedef struct { u8 p[0x518]; u8 *x518; } Actor_;
extern Actor_ *D_002022E4;
f32 *func_00165130(s32, s32);
void func_0017CE80(s32 a) {
    Q *q = (Q *)(D_002022E4->x518 + 0x180);
    f32 *px = func_00165130(a, 0);
    f32 *py = func_00165130(a, 1);
    f32 *pz = func_00165130(a, 2);
    if (q != NULL) {
        *px = 180.0f * q->r->x / 3.1415927f;
        *py = 180.0f * q->r->y / 3.1415927f;
        *pz = 180.0f * q->r->z / 3.1415927f;
    }
}

