#include "m2c.h"
typedef struct {
    s32 x0;
    s32 x4;
    u32 lo:8;
    u32 off:24;
    u16 xC;
    u16 xE;
    u8 pad10[8];
    s32 x18;
} Chk;
void memset(void *, s32, s32);
void func_00169D70(Chk **, void *, s32);
void func_00178080(Chk **);
extern Chk **D_00201FE8;
extern s32 D_00201CA8;
extern s32 D_00201CAC;
extern s32 D_0033F6D0[];
extern u8 D_003406E0[];

void func_0016AE30(void) {
    Chk * b;
    Chk * p;
    u32 i;
    u32 j;
    b = *D_00201FE8;
    memset(D_0033F6D0, 0, 0x1000);
    p = (Chk *)((u8 *)b + b->off);
    for (i = 0; i < b->xE; i++) {
        if (p->x0 == D_00201CA8) break;
        p = (Chk *)((u8 *)p + p->x4);
    }
    b = (Chk *)((u8 *)p + p->off);
    for (j = 0; j < p->xE; j++) {
        if (b->x0 == D_00201CAC) D_0033F6D0[b->x18] = (u8 *)b - (u8 *)*D_00201FE8;
        b = (Chk *)((u8 *)b + b->x4);
    }
    func_00169D70(D_00201FE8, D_003406E0, 0x40);
    func_00178080(D_00201FE8);
}

