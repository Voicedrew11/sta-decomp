#include "common.h"

typedef struct { char pad[0x518]; u8 *p; } S;
extern S *D_002022E4;
typedef struct { char pad[0x37C]; f32 f; char p380[0x22]; unsigned char : 1; unsigned char b : 1; char p3a3[0x5D]; f32 v[4]; } T;
void sceVu0CopyVector(f32 *v0, f32 *v1);

void func_001C8EA0(f32 *v, f32 f)
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
        sceVu0CopyVector(t->v, v);
        t->f = f;
        t->b = 1;
    }
}
