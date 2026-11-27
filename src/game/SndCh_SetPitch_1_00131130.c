#include "common.h"
typedef struct { u8 p[0x3C]; s16 x3C; u8 q[0x42]; } Snd;
extern Snd D_0022CBC0[];
static inline Snd *get(s32 i) {
    if (0 <= i && i < 0x3F) return &D_0022CBC0[i];
    return 0;
}
s32 SndCh_SetPitch_1_00131130(s32 i, s16 v) {
    Snd *s = get(i);
    if (s == 0) return -1;
    s->x3C = v;
    return 0;
}

