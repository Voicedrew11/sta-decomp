#include "m2c.h"
void func_001C8570(u32 *);
typedef struct { s32 pad[2]; s32 n; s32 pad2; f32 f; s32 pad3; s32 m; } A;

void func_0017CD50(A *a0) {
    u32 v[7];
    s32 n = a0->n;
    f32 f = a0->f;
    s32 m = a0->m;

    v[6] = 0;
    v[5] = 0;
    v[4] = 0;
    v[3] = 0;
    v[2] = 0;
    v[1] = 0;
    v[0] = 0;
    if (n < 0 || n >= 7) {
        return;
    }
    if (m == 1) {
        v[n] = 1000000;
    } else {
        v[n] = f;
    }
    func_001C8570(v);
}
