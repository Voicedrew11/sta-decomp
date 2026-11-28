#include "common.h"

typedef struct { s32 x0; s32 x4; } H;
H *Credits_Alloc_1_001E4030(s32 n, s32 flush);
void *memset(void *p, s32 c, u32 n);

H *Credits_AllocNode_1_001E3FD8(s32 a)
{
    H *p = Credits_Alloc_1_001E4030(0x80, 1);
    if (!p)
        return NULL;
    memset(p, 0, 0x80);
    p->x4 = a;
    return p;
}
