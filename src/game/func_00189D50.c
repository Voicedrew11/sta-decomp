#include "m2c.h"
typedef struct { s32 f0; s32 f4; u64 f8; u8 pad[0x28]; } E;
typedef struct { u32 n; E *e; } T;
typedef struct { u32 idx; u8 pad[0x3C]; } I;
typedef struct { u32 n; I *i; } A;
s32 func_00177AF0(u64, s32);
s32 func_00177B20(u64);

s32 func_00189D50(A *a, T *t, s32 k) {
    u32 i, j;
    if (a == 0) return 1;
    for (i = 0; i < a->n; i++) {
        T *tt = &t[a->i[i].idx];
        for (j = 0; j < tt->n; j++) {
            E *e = (E *)((u8 *)tt->e + j * 0x30);
            e->f4 = 0;
            if (e->f8 != -1 && e->f8 != 0) {
                if (k) e->f4 = func_00177AF0(e->f8, k);
                else e->f4 = func_00177B20(e->f8);
            }
        }
    }
    return 0;
}
