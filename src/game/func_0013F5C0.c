#include "common.h"
typedef struct { u8 pad[0x15C]; u16 v; u8 pad2[0x170 - 0x15E]; } E;
typedef struct { u8 pad[0x20]; u16 max; } M;
typedef struct { u8 pad[0x4B4]; M *m[26]; E *e; } A;
s32 func_0013F5C0(A *a, u8 i, s32 d) {
    E *e = &a->e[i];
    s32 v = e->v + d;
    s32 mx = a->m[i]->max;
    if (v < 0) v = 0;
    if (mx < v) v = mx;
    e->v = v;
    return (u16)v;
}

