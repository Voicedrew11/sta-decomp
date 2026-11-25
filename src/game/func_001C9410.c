#include "common.h"

typedef struct { char pad[0x518]; u8 *p; } S;
extern S *D_002022E4;
void sceVu0CopyVector(f32 *v0, f32 *v1);

void func_001C9410(f32 *v)
{
    u8 *t;
    if (D_002022E4 == NULL) {
        t = NULL;
    } else {
        u8 *p = D_002022E4->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t != NULL)
        sceVu0CopyVector(v, (f32 *)(t + 0x40));
    v[1] += 220.0f;
}
