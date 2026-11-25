#include "common.h"

typedef struct { char p[4]; } E;
typedef struct { char pad[0xA0]; E e[0x400]; } T;
T *func_001C9BA0(void);

E *func_001CC3F0(s16 i)
{
    T *t = func_001C9BA0();
    if (i >= 0 && i <= 0x3FF)
        return &t->e[i];
    return NULL;
}
