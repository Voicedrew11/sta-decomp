#include "common.h"

typedef struct { unsigned char : 3; unsigned char f : 1; char pad[3]; } H;
void func_0016B360(void *a, H h, s32 c);

s32 func_001ACFE0(void *a, H h)
{
    if (h.f)
        return 1;
    func_0016B360(a, h, 3);
    return 0;
}
