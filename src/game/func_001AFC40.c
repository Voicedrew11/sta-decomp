#include "common.h"

typedef struct { char b[0x90]; } E;
extern E *D_002022B0;

E *func_001AFC40(s16 i)
{
    if (D_002022B0 && i > 0 && i <= 0x3FF)
        return &D_002022B0[i];
    return NULL;
}
