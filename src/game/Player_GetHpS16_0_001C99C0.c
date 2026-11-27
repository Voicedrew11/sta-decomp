#include "common.h"

typedef struct { char pad[0x518]; u8 *p; } S;
extern S *D_002022E4;
typedef struct { char p[4]; s16 h; } U;

s16 Player_GetHpS16_0_001C99C0(void)
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
    return (*(U **)(t + 0x390))->h;
}
