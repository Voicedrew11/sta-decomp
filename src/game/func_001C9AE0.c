#include "common.h"

typedef struct { char pad[0x518]; u8 *p; } S;
extern S *D_002022E4;
typedef struct { unsigned int : 14; unsigned int f : 4; } B;

u32 func_001C9AE0(void)
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
    return ((B *)(t + 0x39C))->f;
}
