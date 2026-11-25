#include "common.h"

typedef struct { unsigned char : 2; unsigned char f : 1; char pad[3]; } H;
void func_0016B360(void *a, H h, s32 c);

s32 func_001B3F30(void *a, H h)
{
    if (!h.f)
        return 1;
    func_0016B360(a, h, 0);
    return 0;
}
