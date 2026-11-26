#include "m2c.h"
typedef struct { u8 pad[0x1A]; u16 id; u8 pad2[0x14]; } E30;
typedef struct { u8 pad[0x51]; u8 b0:1; u8 b1:2; u8 b3:5; u8 pad2[0x2E]; } E80;
typedef struct { u8 pad[0x6E]; u16 count; u8 pad2[0x138-0x70]; E30 *arr; u8 pad3[0x180-0x13C]; E80 *ent; } Obj;
Obj *func_001B19A0(s32);
void sceVu0CopyMatrix(void *, void *);
static inline s32 find(s32 a0, s32 a1) {
    Obj *p = func_001B19A0(a0);
    s32 i;
    if (p == NULL) return -1;
    for (i = 0; i < p->count; i++) {
        if (a1 == p->arr[i].id % 100) return i;
    }
    return -1;
}

void func_001B7A30(s32 arg0, s32 arg1, void *arg2) {
    Obj *o = func_001B19A0(arg0);
    u32 i = find(arg0, arg1);
    E80 *e;
    if (o != NULL && i < o->count) {
        e = (E80 *)((s8 *)o->ent + (i << 7));
        sceVu0CopyMatrix(e, arg2);
        e->b1 = 2;
    }
}
