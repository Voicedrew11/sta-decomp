#include "actor.h"
#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { u8 pad[0x18]; Vec *m; } S;
void sceVu0CopyVector(Vec *, Vec *);
extern Vec D_003139A0;
static inline S *cur(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (S *)(D_002022E4->unk518 + 0x180);
}

void Player_LoadStartPos_0_001C96F0(s8 *a0) {
    Vec *r;
    S *s;
    Vec v;
    if (a0 != NULL) {
        r = *(Vec **)(a0 + 0x158);
        s = cur();
        if (s != NULL) {
            v.x = 0.0f;
            v.y = WRAP(r->w);
            v.w = 0.0f;
            v.z = 0.0f;
            sceVu0CopyVector(&s->m[0], r);
            sceVu0CopyVector(&s->m[1], r);
            sceVu0CopyVector(&s->m[2], &v);
            sceVu0CopyVector(&s->m[3], &v);
            sceVu0CopyVector(&s->m[4], &D_003139A0);
        }
    }
}
