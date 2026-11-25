#include "common.h"
extern s16 D_001F37B0[];
typedef struct { s8 pad[0x60]; s16 h[16]; Vec v[20]; } Rec;
extern Rec *D_00201DC4;
static inline u32 find(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}

void func_001A9A20(s32 id, s32 k, s16 h, Vec *a, Vec *b) {
    u32 i = find(id);
    if (i == -1) {
        return;
    }
    D_00201DC4[i].h[k] = h;
    if (h != -1) {
        D_00201DC4[i].v[k].x = a->x;
        D_00201DC4[i].v[k].y = a->y;
        D_00201DC4[i].v[k].z = a->z;
        D_00201DC4[i].v[k].w = b->y;
    } else {
        D_00201DC4[i].v[k].w = 0.0f;
        D_00201DC4[i].v[k].z = 0.0f;
        D_00201DC4[i].v[k].y = 0.0f;
        D_00201DC4[i].v[k].x = 0.0f;
    }
}
