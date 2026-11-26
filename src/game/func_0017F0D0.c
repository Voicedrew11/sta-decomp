#include "m2c.h"
typedef union { u128 q; f32 f[4]; } Q;
typedef struct { s32 idx; u8 pad4[0x28]; f32 f2C; u8 pad30[0x10]; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { u8 pad[0x10]; List *list; } Res;
Res *func_00189050(s32);
s32 func_00189020(s32);
f32 sinf(f32);
void func_00187B20(s32);
void func_001829B0(Item *, s32, void (*)(), s32);
void func_001803E0();
void func_001805D0(Q *, s32, s32, s32);
extern Q D_001F25D0[];
extern f32 D_00202058;
extern s32 D_00486980[];
extern f32 D_00486984[];
extern f32 D_00486988[];

void func_0017F0D0(s32 a0, s32 a1, s32 a2, s32 a3) {
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
    d = 0.25f * (t - D_00202058);
    D_00486980[0] += 5;
    D_00486980[0] %= 180;
    D_00486984[0] = 10.0f * sinf(3.1415927f * D_00486980[0] / 180.0f);
    D_00486988[0] = -10.0f * sinf(3.1415927f * D_00486980[0] / 180.0f);
    func_00187B20(0);
    for (i = 0; i < l->n; i++) {
        it = l->items[i];
        it.f2C -= 80.0f * (1.0f - D_00202058);
        func_001829B0(&it, base + l->items[i].idx * 8, func_001803E0, 1);
    }
    v = D_001F25D0[0];
    v.f[0] -= 80.0f * (1.0f - D_00202058);
    v.f[2] -= 80.0f * (1.0f - D_00202058);
    func_001805D0(&v, a1, a2, a3);
    D_00202058 += d;
    if (D_00202058 > 1.0f) {
        D_00202058 = 1.0f;
    }
    if (D_00202058 < 0.0f) {
        D_00202058 = 0.0f;
    }
}
