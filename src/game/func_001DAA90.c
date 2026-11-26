#include "common.h"
typedef struct { s32 addr; u32 size; s32 pad[2]; } E;
extern struct { char pad[0x200]; E e[8]; } D_004BA500;
extern s32 D_0020232C;
void FlushCache(s32);
s32 sceSifAllocIopHeap(u32);
s32 func_001DB830(void);
s32 func_001DB9B0(s32, s32, u32);
s32 func_001DAA90(s32 i, s32 b, u32 sz) {
    E *e;
    s32 r;

    r = -1;
    if (i < 0 || i >= 8) return -1;
    e = &D_004BA500.e[i];
    switch (D_0020232C) {
    case 0:
        sz = (sz + 15) & ~15;
        if (e->addr == 0) {
            e->addr = sceSifAllocIopHeap(sz);
            if (e->addr == 0) break;
            if (e->addr + sz > 0x1FFFFF) break;
        } else if (e->size != sz) break;
        e->size = sz;
        D_0020232C = 1;
    case 1:
        if (func_001DB830() != 0) { D_0020232C = 2; } else { r = 0; break; }
    case 2:
        if (func_001DB9B0(e[0].addr, b, (&e->addr)[1]) < 0) { D_0020232C = 0; break; }
        D_0020232C = 3;
    case 3:
        if (func_001DB830() != 0) { D_0020232C = 0; r = 1; } else r = 0;
    }
    FlushCache(0);
    return r;
}

