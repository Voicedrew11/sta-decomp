#include "common.h"

typedef struct { char pad[0x518]; u8 *p; } S;
extern S *D_002022E4;
typedef struct { unsigned int : 3; unsigned int f : 1; } B;

u32 Player_IsMoving_0_001C9A80(void)
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
    return ((B *)(t + 0x3A2))->f;
}
