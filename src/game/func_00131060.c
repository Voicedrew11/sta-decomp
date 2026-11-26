#include "common.h"
typedef struct { s8 b0; char rest[0x7F]; } E;
extern E D_0022CBC0[];
static inline E *get(s32 i) { if (0 <= i && i < 63) return &D_0022CBC0[i]; return 0; }
s8 func_00131060(s32 i)
{
    E *e = get(i);
    if (e) return e->b0;
    return 0;
}
