#include "common.h"

typedef struct { u8 b[0x40]; } E;
typedef struct { char pad[0x100]; E e[0x3C]; } B;
extern B D_0030A2D0[];
extern char D_0030A310[];
extern char D_0030A390[];

void *func_0015B900(s32 i)
{
    if (i < 0) {
        if (i == -1)
            return D_0030A310;
        return D_0030A390;
    }
    return &D_0030A2D0[i / 64].e[i % 64];
}
