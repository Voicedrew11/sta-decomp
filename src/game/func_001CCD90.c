#include "common.h"

typedef struct { char pad[0x80]; s16 v[10]; } T;
T *func_001C9BA0(void);

s16 func_001CCD90(s32 i)
{
    T *t = func_001C9BA0();
    if (i >= 0 && i < 10)
        return t->v[i];
    return -1;
}
