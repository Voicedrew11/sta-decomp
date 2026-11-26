#include "common.h"

typedef struct { u32 p; s32 x4; s32 x8; u32 sz; u8 pad[0x10]; } E;
extern E D_004BA500[16];
extern s32 D_00202330;
void FlushCache(s32);
u32 sceSifAllocIopHeap(u32);
s32 func_001DB830(void);
s32 func_001DB9B0(u32, s32, s32);

s32 func_001DB510(s32 i, s32 a1, u32 sz)
{
    E *e;
    s32 ret = -1;

    if (i < 0 || i >= 16)
        return -1;
    e = &D_004BA500[i];
    switch (D_00202330) {
    case 0:
        sz = (sz + 15) & ~15;
        if (e->p == 0) {
            e->p = sceSifAllocIopHeap(sz);
            if (e->p == 0)
                break;
            if (e->p + sz > 0x1FFFFF)
                break;
        } else if (e->sz != sz) {
            break;
        }
        e->sz = sz;
        D_00202330 = 1;
    case 1:
        if (func_001DB830() != 0) {
            D_00202330 = 2;
        } else {
            ret = 0;
            break;
        }
    case 2:
        if (func_001DB9B0(e->p, a1, e->sz) < 0) {
            D_00202330 = 0;
            break;
        }
        D_00202330 = 3;
    case 3:
        if (func_001DB830() != 0) {
            D_00202330 = 0;
            ret = 1;
        } else {
            ret = 0;
        }
    }
    FlushCache(0);
    return ret;
}
