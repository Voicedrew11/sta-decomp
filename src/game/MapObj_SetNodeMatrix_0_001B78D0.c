#include "m2c.h"
typedef struct { u8 pad[0x14]; u16 n; } C;
typedef struct { u8 pad[0x1A]; u16 id; u8 pad2[0x14]; } E30;
typedef struct { u8 pad[0x40]; void ***m; u8 pad2[0x3C]; } E80;
typedef struct { u8 pad[0x6E]; u16 count; u8 pad2[0x138-0x70]; E30 *arr; u8 pad3[0x180-0x13C]; E80 *ent; } Obj;
Obj *MapObj_Find_1_001B19A0(s32);
s8 *Mdl_GetFrameData_0_001715B0(void ***);
void sceVu0CopyMatrix(s32, s8 *);
static inline s32 find(s32 a0, s32 a1) {
    Obj *p = MapObj_Find_1_001B19A0(a0);
    s32 i;
    if (p == NULL) return -1;
    for (i = 0; i < p->count; i++) {
        if (a1 == p->arr[i].id % 100) return i;
    }
    return -1;
}

void MapObj_SetNodeMatrix_0_001B78D0(s32 arg0, s32 arg1, u32 arg2, s32 arg3) {
    Obj *o = MapObj_Find_1_001B19A0(arg0);
    u32 i = find(arg0, arg1);
    void ***m;
    C *c;
    s8 *v;
    if (o != NULL && i < o->count) {
        m = ((E80 *)((s8 *)o->ent + (i << 7)))->m;
        if (m == NULL || *m == NULL) return;
        if (**m == NULL || (c = **(C ***)*m) == NULL) return;
        v = Mdl_GetFrameData_0_001715B0(m);
        if (arg2 < c->n) {
            sceVu0CopyMatrix(arg3, v + (arg2 + 1) * 0x140 + 0xC0);
        }
    }
}
