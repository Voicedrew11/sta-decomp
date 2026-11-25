#include "common.h"

typedef struct { s32 idx; char p4[0x20]; f32 t; char rest[0x18]; } E;
typedef struct { u32 n; E *e; } L;
typedef struct { L *l[4]; } G;
G *func_00189050(s32 i);
u8 *func_00189020(s32 i);
void func_00182C10(E *e, u8 *p);

void func_00186F20(f32 t)
{
    u32 i;
    L *l;
    u8 *b;
    l = func_00189050(0)->l[2];
    b = func_00189020(0);
    for (i = 0; i < l->n; i++) {
        l->e[i].t = t;
        func_00182C10(&l->e[i], b + l->e[i].idx * 8);
    }
}
