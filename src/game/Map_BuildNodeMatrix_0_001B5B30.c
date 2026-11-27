#include "common.h"
typedef struct { f32 x, y, z; s16 rx, ry, rz; u16 sx, sy, sz; } E;
void Mtx_Compose_2_00173FD0(void *, f32 *, f32 *, f32 *);
static inline f32 u2f(u32 x) { return x; }

void Map_BuildNodeMatrix_0_001B5B30(void *o, E *e) {
    f32 pos[4];
    f32 rot[4];
    f32 scl[4];
    s32 k;

    for (k = 0; k < 3; k++) {
        pos[k] = (&e->x)[k];
        rot[k] = 0.00024414062f * (&e->rx)[k];
        scl[k] = 0.00024414062f * u2f((&e->sx)[k]);
    }
    pos[3] = 1.0f;
    rot[3] = 0.0f;
    scl[3] = 1.0f;
    Mtx_Compose_2_00173FD0(o, pos, rot, scl);
}
