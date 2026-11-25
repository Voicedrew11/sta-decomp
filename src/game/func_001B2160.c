#include "common.h"

void func_001B1DF0(void *a, s32 *b, s32 *c, s32 d, s32 e, void *f, s32 g, void *h);

void func_001B2160(void *a, s32 *b, s32 *c, s32 d, s32 e)
{
    if (e < -1)
        e = -1;
    func_001B1DF0(a, b, c, d, e, NULL, 0, NULL);
}
