#include "common.h"

typedef struct { s32 id; s32 off; } E;
typedef struct { char p0[4]; u32 n; char p8[8]; E e[1]; } T;
extern T **D_00202180;

void *func_00195B10(s32 id)
{
    u32 i;
    E *e;
    T *t = *D_00202180;
    if (!t)
        return NULL;
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id)
            return (u8 *)t + e->off;
    }
    return NULL;
}
