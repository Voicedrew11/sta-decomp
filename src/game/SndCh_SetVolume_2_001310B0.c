#include "common.h"
typedef struct { s8 on; s8 idx; s8 x2; s8 x3; s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF; u8 p10[0x40]; Vec v; u8 p60[0x20]; } Snd;
extern Snd D_0022CBC0[];
static inline Snd *get(s32 i) { if (!(0 > i) && i < 0x3F) return &D_0022CBC0[i]; return 0; }
s32 SndCh_SetVolume_2_001310B0(s32 a, s16 v) {
    Snd *s = get(a);
    if (s == 0) return -1;
    if (v < 0) v = 0;
    if (v > 0x7F) v = 0x7F;
    s->x8 = v;
    return 0;
}
