#include "m2c.h"
typedef struct { s32 idx; u8 pad[0x28]; f32 x2C; u8 pad30[0x10]; } Elem;
typedef struct { u32 n; Elem *e; } List;
typedef struct { u8 pad[0x1C]; List *list; } Ctx;
typedef union { u128 q; f32 f[4]; } V;
Ctx *func_00189050(s32);
s32 func_00189020(s32);
void func_00187B20(s32);
void func_00182C10(Elem *, s32);
void func_00183090(V *, s32, s32, s32);
extern V D_001F26F0[];

void func_00185390(s32 a0, s32 a1, s32 a2, f32 f) {
    Elem el;
    V v;
    u32 i;
    List *list;
    s32 base;

    list = func_00189050(0)->list;
    base = func_00189020(0);
    func_00187B20(0);
    for (i = 0; i < list->n; i++) {
        el = list->e[i];
        el.x2C -= 40.0f * f;
        func_00182C10(&el, base + list->e[i].idx * 8);
    }
    v = D_001F26F0[0];
    v.f[0] -= 40.0f * f;
    v.f[2] -= 40.0f * f;
    func_00183090(&v, a0, a1, a2);
}
