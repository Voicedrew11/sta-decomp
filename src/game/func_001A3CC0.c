#include "common.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { s32 idx; u8 pad4[0x38]; u8 c0, c1, c2, c3; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { u8 pad[0x8]; List *list; } Res;
Res *func_00189050(s32);
s32 func_00189020(s32);
void func_00182080(s32, f32, Vec *, Vec *, Col *, s32);
void func_00182C10(Item *, s32);
extern Vec D_001F3310;
extern f32 D_00202264;

void func_001A3CC0(void) {
    u32 i;
    List *l;
    s32 base;
    f32 t;

    l = func_00189050(3)->list;
    base = func_00189020(3);
    {
    Vec a = D_001F3310;
    Vec b = {0};
    Col col;
    col.c.r = col.c.g = col.c.b = 2;
    col.c.a = 0xFF;
    func_00182080(0, 0.0f, &a, &b, &col, 0);
    }
    for (i = 0; i < l->n; i++) {
        l->items[i].c2 = 0xFF;
        l->items[i].c1 = 0xFF;
        l->items[i].c0 = 0xFF;
        t = 30.0f;
        if (D_00202264 < t) {
            l->items[i].c3 = (s32)(127.0f - 127.0f * (t - D_00202264) / t);
        } else if (!(D_00202264 <= 150.0f)) {
            l->items[i].c3 = 0;
        } else if (!(D_00202264 < 120.0f)) {
            l->items[i].c3 = (s32)(127.0f - 127.0f * (D_00202264 - 120.0f) / t);
        }
        func_00182C10(&l->items[i], base + l->items[i].idx * 8);
    }
}
