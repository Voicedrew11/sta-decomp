#include "common.h"

typedef struct { char pad[0x70]; u16 t[6]; } T;
T *func_001C9BA0(void);

void func_001CEBA0(void)
{
    T *t = func_001C9BA0();
    s32 i;
    for (i = 0; i < 6; i++) {
        if (t->t[i])
            t->t[i]--;
    }
}
