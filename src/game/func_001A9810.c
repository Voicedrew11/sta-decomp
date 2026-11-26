#include "common.h"
typedef struct { u8 pad[0x60]; s16 x60[16]; Vec x80[16]; u8 pad2[0x40]; } G;
extern G *D_00201DC4;
extern s16 D_001F37B0[];
extern Vec D_003139A0;
void sceVu0CopyVector(void *, void *);
static inline s32 find(s32 k) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (k == D_001F37B0[i]) return i;
    }
    return -1;
}

void func_001A9810(s32 k) {
    s32 i;
    s32 j;
    i = find(k);
    if (i != -1) {
        for (j = 0; j < 16; j++) {
            D_00201DC4[i].x60[j] = -1;
            sceVu0CopyVector(&D_00201DC4[i].x80[j], &D_003139A0);
        }
    }
}
