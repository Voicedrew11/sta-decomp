#include "common.h"

typedef struct { char pad[0x518]; u8 *p; } S;
extern S *D_002022E4;
typedef struct { char pad[0x430]; s32 a; s32 b; f32 v[4]; } T;

void Camera_SetParams_0_001C8F30(f32 x, f32 y, f32 z, f32 w)
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
        t->v[0] = x;
        t->v[1] = y;
        t->v[2] = z;
        t->v[3] = w;
        t->b = 0;
        t->a = 0;
    }
}
