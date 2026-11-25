#include "common.h"

typedef struct { f32 v[8]; } M;
extern M D_004BA880[5];
extern M D_004BA900;
s32 func_001D8350(s32 a, s32 b, s32 c, s32 d, s32 e, M *m);

s32 func_001DA720(s32 i)
{
    if (i < 0 || i > 4)
        return 0;
    D_004BA900 = D_004BA880[i];
    return func_001D8350(4, 1, 0x20, 4, 0x400800, &D_004BA900);
}
