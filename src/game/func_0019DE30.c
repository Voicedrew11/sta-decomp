#include "common.h"

typedef struct { char p0[0xA]; u16 h; char pc[0x1D]; u8 b; char rest[0x66]; } E;
E *func_001AFC90(s32 i);

s32 func_0019DE30(s32 i)
{
    E *e = func_001AFC90(i);
    E *p = &e[i];
    if (p->h == 0 && p->b == 5)
        return 1;
    return 0;
}
