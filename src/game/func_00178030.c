#include "common.h"

typedef struct { void *p; s32 x; } E;
extern E D_0047F080[8];

void func_00178030(void *p)
{
    s32 i;
    if (!p)
        return;
    for (i = 0; i < 8; i++) {
        if (D_0047F080[i].p == p) {
            D_0047F080[i].p = NULL;
            return;
        }
    }
}
