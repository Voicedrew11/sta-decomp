#include "common.h"
typedef struct { s32 idx; u8 pad[0x3C]; } Item;
typedef struct { u32 n; Item *items; } List;
List **func_00189050(s32);
s32 func_00189020(s32);
void func_001829B0(Item *, s32, void (*)(), s32);
void func_001DCF80();
void func_00187B20(s32);
extern f32 D_00201E44;
extern f32 D_00201E48;

void func_001DCE70(void) {
    u32 i;
    List *l;
    s32 base;
    Item *it;

    l = func_00189050(3)[1];
    base = func_00189020(3);
    D_00201E48 += 4.0f;
    if (!(D_00201E48 <= 128.0f)) D_00201E48 = 128.0f;
    D_00201E44 += 4.0f;
    if (!(D_00201E44 <= 128.0f)) D_00201E44 = 128.0f;
    for (i = 0; i < l->n; i++) {
        it = &l->items[i];
        func_001829B0(it, base + it->idx * 8, func_001DCF80, 0);
    }
    func_00187B20(0);
}

