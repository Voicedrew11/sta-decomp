#include "m2c.h"
typedef struct { s32 idx; u8 pad4[0x28]; f32 f2C; f32 f30; u8 pad34[0xC]; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { u8 pad[0x24]; List *list; } Res;
Res *func_00189050(s32);
s32 func_00189020(s32);
void func_001829B0(Item *, s32, void (*)(), s32);
void func_001DF580();

void func_001DF470(s32 a0, f32 f) {
    Item it;
    u32 i;
    List *l;
    s32 base;

    l = func_00189050(0)->list;
    base = func_00189020(0);
    for (i = 0; i < l->n; i++) {
        it = l->items[i];
        it.f2C -= 80.0f * f;
        func_001829B0(&it, base + l->items[i].idx * 8, func_001DF580, a0);
    }
}

