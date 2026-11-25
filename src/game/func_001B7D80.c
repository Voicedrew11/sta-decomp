#include "m2c.h"
typedef struct { u8 pad[0x1A]; u16 id; u8 pad2[0x14]; } E30;
typedef struct { u8 pad[0x50]; u32 a:11; u32 f:8; u32 b:13; u8 pad2[0x2C]; } E80;
typedef struct { u8 pad[0x6E]; u16 count; u8 pad2[0x138-0x70]; E30 *arr; u8 pad3[0x180-0x13C]; E80 *ent; } Obj;
Obj *func_001B19A0(s32);
static inline s32 find(s32 a0, s32 a1) {
    Obj *p = func_001B19A0(a0);
    s32 i;
    if (p == NULL) return -1;
    for (i = 0; i < p->count; i++) {
        if (a1 == p->arr[i].id % 100) return i;
    }
    return -1;
}

u16 func_001B7D80(s32 arg0, s32 arg1) {
    Obj *o = func_001B19A0(arg0);
    s32 i = find(arg0, arg1);
    if (o == NULL) return 0;
    if (i < 0 || i >= o->count) return 0;
    return o->ent[i].f;
}
