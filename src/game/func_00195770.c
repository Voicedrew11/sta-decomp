#include "common.h"

typedef struct { s32 id; char p[0x2C]; } E;
typedef struct { char p0[4]; u32 n; char p8[8]; E e[1]; } T;
extern T **D_00202168;

E *func_00195770(s32 id)
{
    T *t;
    E *e;
    u32 i;
    if (!D_00202168)
        return NULL;
    t = *D_00202168;
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id)
            return e;
    }
    return NULL;
}
