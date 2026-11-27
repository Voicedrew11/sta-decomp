#include "common.h"
typedef struct { s8 b0; s8 b1; char p2[0xE]; Vec v; char p20[0x14]; s32 x34; s32 x38; char rest[0x44]; } E;
extern E D_0022CBC0[];
void sceVu0CopyVector(Vec *, Vec *);
static inline E *get(s32 i) {
    E *p;
if (0 <= i && i < 0x3F) p = &D_0022CBC0[i]; else p = NULL;
    return p;
}
s32 SndCh_SetPositionStatic_1_00131330(s32 arg0, Vec *v) {
    E *p = get(arg0);
    if (p == NULL) return -1;
    p->x34 = 0;
    p->x38 = 0;
    sceVu0CopyVector(&p->v, v);
    return 0;
}
