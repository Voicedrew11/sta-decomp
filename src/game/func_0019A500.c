#include "m2c.h"
typedef struct { s16 v[10]; } Ids;
typedef struct { u8 b[4]; } Col;
s8 *func_001C9BA0(void);
void memset(void *, s32, s32);
void func_001CCF50(Ids *, s32, s16);
u8 *func_001A97D0(s16);
void func_001CF480(s32, s32, s32, s32, Ids *, Col *, s32);
u32 func_001D1170(void);
u16 func_001D1110(s32);
u16 func_001D10B0(s32);

void func_0019A500(s32 a0, s32 a1, u32 *a2, u32 *a3, u32 *t0, s32 t1, s32 t2, s32 t3) {
    s8 *base;
    s32 i;
    Ids ids;
    Col col[10];

    base = func_001C9BA0();
    ids = *(Ids *)(base + 0x80);
    memset(col, 0, 0x28);
    if (t1 >= 0) {
        func_001CCF50(&ids, t1, t2);
    }
    for (i = 0; i < 10; i++) {
        if (ids.v[i] != -1) {
            col[i] = *(Col *)(base + 0xA0 + ids.v[i] * 4);
            if (i == t1 && t3 != 0) {
                col[i].b[0] = *func_001A97D0(ids.v[i]);
            }
        }
    }
    func_001CF480(a0, 0, a1, 0, &ids, col, 3);
    *a2 = func_001D1170();
    *a3 = func_001D1110(a0);
    *t0 = func_001D10B0(a0);
}
