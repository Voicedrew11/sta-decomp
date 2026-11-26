#include "common.h"
typedef struct { s8 on; s8 idx; s8 x2; s8 x3; s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF; u8 p10[0x40]; Vec v; u8 p60[0x20]; } Snd;
extern Snd D_0022CBC0[];
void sceVu0CopyVector(Vec *, Vec *);
static inline Snd *get(s32 i) { if (!(0 > i) && i < 0x3F) return &D_0022CBC0[i]; return 0; }
s32 func_001311E0(s32 a, Vec *b) {
    Snd *s = get(a);
    if (s == 0) return -1;
    sceVu0CopyVector(&s->v, b);
    return 0;
}
