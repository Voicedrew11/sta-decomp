#include "common.h"
typedef struct { s32 a; s32 b; s32 c[2]; } E;
typedef struct { char pad[0x200]; E e[1]; } T;
extern T D_004BA500;
s32 sceSifFreeSysMemory(s32);
void FlushCache(s32);
s32 func_001DA920(s32 i) {
    E *e = &D_004BA500.e[i];
    if (e->a != 0) {
        if (sceSifFreeSysMemory(e->a) != 0) return -1;
        e->a = 0; e->b = 0;
    } else {
        return -1;
    }
    FlushCache(0);
    return 0;
}
