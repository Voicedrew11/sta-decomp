#include "common.h"

void *func_001958A0(void);
void *func_00195840(void *h, s32 id);

void *func_0019D510(s32 id)
{
    void *h = func_001958A0();
    if (!id)
        return NULL;
    if (id == -1)
        return NULL;
    if (h)
        return func_00195840(h, id);
    return NULL;
}
