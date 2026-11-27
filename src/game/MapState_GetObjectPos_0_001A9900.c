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

s16 MapState_GetObjectPos_0_001A9900(s32 id, s32 k, Vec *a, Vec *b) {
    u32 i = find(id);
    if (i == -1) {
        return 0;
    }
    if (a) {
        a->x = D_00201DC4[i].v[k].x;
        a->y = D_00201DC4[i].v[k].y;
        a->z = D_00201DC4[i].v[k].z;
        a->w = 1.0f;
    }
    if (b) {
        b->y = D_00201DC4[i].v[k].w;
        b->w = 0.0f;
        b->z = 0.0f;
        b->x = 0.0f;
    }
    return D_00201DC4[i].h[k];
}
