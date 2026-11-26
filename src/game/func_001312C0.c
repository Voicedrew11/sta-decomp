#include "common.h"
typedef struct { u8 p[0x40]; f32 x40; u8 r[0x3C]; } Snd;
extern Snd D_0022CBC0[];
static inline Snd *get(s32 i) {
    if (0 <= i && i < 0x3F) {
        return &D_0022CBC0[i];
    }
    return NULL;
}
s32 func_001312C0(s32 i, f32 v) {
    Snd *s = get(i);
    if (s == NULL) return -1;
    if (v < 0.0f) v = 0.0f;
    s->x40 = v;
    return 0;
}

