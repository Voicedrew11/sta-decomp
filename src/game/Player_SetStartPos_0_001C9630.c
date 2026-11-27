#include "common.h"
typedef struct { char pad[0x518]; u8 *p; } S;
typedef struct { char pad[0x18]; f32 *m; } T;
extern S *D_002022E4;
extern f32 D_003139A0[];
void sceVu0CopyVector(f32 *v0, f32 *v1);
void Player_SetStartPos_0_001C9630(f32 *a, f32 *b)
{
    T *t;
    if (D_002022E4 == NULL) {
        t = NULL;
    } else {
        u8 *p = D_002022E4->p;
        if (p == NULL)
            t = NULL;
        else
            t = (T *)(p + 0x180);
    }
    if (t != NULL) {
        sceVu0CopyVector(t->m, a);
        sceVu0CopyVector(t->m + 4, a);
        sceVu0CopyVector(t->m + 8, b);
        sceVu0CopyVector(t->m + 12, b);
        sceVu0CopyVector(t->m + 16, D_003139A0);
    }
}
