#include "common.h"

typedef struct { char p[4]; } E;
typedef struct { char pad[0x80]; s16 a; s16 b; char p84[0x10]; u8 f; char p95[0xB]; E e[0x400]; } T;
T *func_001C9BA0(void);

E *func_001D1E10(void)
{
    T *t = func_001C9BA0();
    s16 k;
    if (t->f & 1)
        k = t->b;
    else
        k = t->a;
    if (k >= 0 && k <= 0x3FF)
        return &t->e[k];
    return NULL;
}
