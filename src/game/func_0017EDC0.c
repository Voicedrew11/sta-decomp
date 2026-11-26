#include "m2c.h"
typedef union { u128 q; f32 f[4]; } Q;
typedef struct { s32 idx; u8 pad4[0x28]; f32 f2C; f32 f30; u8 pad34[0xC]; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { u8 pad[0x10]; List *list; } Res;
Res *func_00189050(s32);
s32 func_00189020(s32);
f32 func_0011DA18(f32);
void func_00187B20(s32);
void func_001829B0(Item *, s32, void (*)(), s32);
void func_001803E0();
void func_001805D0(Q *, s32, s32, s32);
extern Q D_001F25E0[];
extern f32 D_0020205C;
extern s32 D_00486980[];
extern f32 D_00486984[];
extern f32 D_00486988[];

void func_0017EDC0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    Item it;
    Q v;
    s32 base;
    u32 i;
    List *l;
    f32 t;
    f32 d;

    l = func_00189050(5)->list;
    base = func_00189020(5);
    if (a0) {
        t = 1.0f;
    } else {
        D_00486980[0] = 0;
        t = 0.0f;
        D_00486988[0] = 0.0f;
        D_00486984[0] = 0.0f;
    }
    d = 0.25f * (t - D_0020205C);
    D_00486980[0] += 5;
    D_00486980[0] %= 180;
    D_00486984[0] = 10.0f * func_0011DA18(3.1415927f * D_00486980[0] / 180.0f);
    D_00486988[0] = -10.0f * func_0011DA18(3.1415927f * D_00486980[0] / 180.0f);
    func_00187B20(0);
    for (i = 0; i < l->n; i++) {
        it = l->items[i];
        it.f2C -= 80.0f * (1.0f - D_0020205C);
        it.f30 = 166.0f;
        func_001829B0(&it, base + l->items[i].idx * 8, func_001803E0, a1);
    }
    v = D_001F25E0[0];
    v.f[0] -= 80.0f * (1.0f - D_0020205C);
    v.f[2] -= 80.0f * (1.0f - D_0020205C);
    func_001805D0(&v, a2, a3, a4);
    D_0020205C += d;
    if (D_0020205C > 1.0f) {
        D_0020205C = 1.0f;
    }
    if (D_0020205C < 0.0f) {
        D_0020205C = 0.0f;
    }
}
