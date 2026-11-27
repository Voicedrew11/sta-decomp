#include "common.h"

typedef struct { char pad[0x518]; u8 *p; } S;
extern S *D_002022E4;

u8 Player_IsCrouching_0_001C9A20(void)
{
    u8 *t;
    if (D_002022E4 == NULL) {
        t = NULL;
    } else {
        u8 *p = D_002022E4->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t == NULL)
        return 0;
    return t[0x3D6] & 1;
}
