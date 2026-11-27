#include "common.h"
typedef struct { s8 on; u8 p1[0xF]; f32 v[4]; s32 x20; u8 p24[0x10]; s32 x34; u8 p38[0x48]; } Snd;
extern Snd D_0022CBC0[];
void sceVu0AddVector(f32 *, f32 *, f32 *);
void SndCh_OffsetPositions_1_0012C440(f32 *a) {
    s32 n = 0x3F;
    Snd *s = D_0022CBC0;
    while (n--) {
        if (s->on && !s->x34 && !s->x20) sceVu0AddVector(s->v, s->v, a);
        s++;
    }
}

