#include "common.h"

void *func_001958A0(void);
void *func_001957E0(void *h, s32 id);

void *func_0019D4A0(s32 id)
{
    void *h = func_001958A0();
    if (!id)
        return NULL;
    if (id == -1)
        return NULL;
    if (h)
        return func_001957E0(h, id);
    return NULL;
}
