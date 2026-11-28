#include "common.h"
typedef struct { u8 pad[0x60]; s16 x60[16]; Vec x80[16]; u8 pad2[0x40]; } G;
typedef struct { s8 pad[0x60]; s16 h[16]; Vec v[20]; } Rec;
extern G *D_00201DC4;
extern s16 D_001F37B0[];
extern Vec D_003139A0;
void MapState_OffsetObjects_0_001A9810(s32 k);
s16 MapState_GetObjectPos_0_001A9900(s32 id, s32 k, Vec *a, Vec *b);
void MapState_SetObjectPos_0_001A9A20(s32 id, s32 k, s16 h, Vec *a, Vec *b);
void sceVu0CopyVector(void *, void *);

/* MapState_OffsetObjects_0_001A9810 */
static inline s32 find_MapState_OffsetObjects_0_001A9810(s32 k) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (k == D_001F37B0[i]) return i;
    }
    return -1;
}

void MapState_OffsetObjects_0_001A9810(s32 k) {
    s32 i;
    s32 j;
    i = find_MapState_OffsetObjects_0_001A9810(k);
    if (i != -1) {
        for (j = 0; j < 16; j++) {
            D_00201DC4[i].x60[j] = -1;
            sceVu0CopyVector(&D_00201DC4[i].x80[j], &D_003139A0);
        }
    }
}

/* MapState_GetObjectPos_0_001A9900 */
#define D_00201DC4 D_00201DC4__as_MapState_GetObjectPos_0_001A9900
extern Rec *D_00201DC4__as_MapState_GetObjectPos_0_001A9900;
static inline u32 find_MapState_GetObjectPos_0_001A9900(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}

s16 MapState_GetObjectPos_0_001A9900(s32 id, s32 k, Vec *a, Vec *b) {
    u32 i = find_MapState_GetObjectPos_0_001A9900(id);
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
#undef D_00201DC4

/* MapState_SetObjectPos_0_001A9A20 */
#define D_00201DC4 D_00201DC4__as_MapState_SetObjectPos_0_001A9A20
extern Rec *D_00201DC4__as_MapState_SetObjectPos_0_001A9A20;
static inline u32 find_MapState_SetObjectPos_0_001A9A20(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}

void MapState_SetObjectPos_0_001A9A20(s32 id, s32 k, s16 h, Vec *a, Vec *b) {
    u32 i = find_MapState_SetObjectPos_0_001A9A20(id);
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
#undef D_00201DC4
