#include "common.h"

typedef struct { char p[0x1A]; u16 id; char rest[0x14]; } E;
typedef struct { char pad[0x6E]; u16 n; char p70[0xC8]; E *e; } T;
T *func_001B19A0(s32 a);

E *func_001B77A0(s32 a, s32 k)
{
    T *t = func_001B19A0(a);
    s32 i;
    if (!t)
        return NULL;
    for (i = 0; i < t->n; i++) {
        if (k == t->e[i].id % 100)
            return &t->e[i];
    }
    return NULL;
}
