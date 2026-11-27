#include "m2c.h"
typedef struct { u8 pad[0x1C]; u16 id; u8 pad1E[3]; s8 x21; u8 pad22[0xE]; } E30;
typedef struct { s32 a; s32 b; } E8;
typedef struct { u8 pad[0x6C]; u16 count; u8 pad2[0x134-0x6E]; E30 *arr; u8 pad3[0x178-0x138]; E8 *e8; } Obj;
Obj *MapObj_Find_1_001B19A0(s32);

s32 MapCmd_SetObjectTexture_0_0017E150(s32 arg0, s32 id, s32 v) {
    Obj *o = MapObj_Find_1_001B19A0(arg0);
    E30 *p;
    E8 *q;
    s32 i;

    if (o == NULL) return 0;
    p = o->arr;
    q = o->e8;
    if (v < -1 || v > 31) return 0;
    for (i = 0; i < o->count; i++, p++, q++) {
        if (p == NULL) return 0;
        if (q == NULL) return 0;
        if (p->id == id) p->x21 = v;
    }
    return 1;
}
