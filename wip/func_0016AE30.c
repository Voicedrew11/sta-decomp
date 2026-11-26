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
    Chk *b = *D_00201FE8;
    Chk *p;
    Chk *q;
    u32 i;
    memset(D_0033F6D0, 0, 0x1000);
    p = (Chk *)((u8 *)b + b->off);
    for (i = 0; i < b->xE; i++) {
        if (p->x0 == D_00201CA8) break;
        p = (Chk *)((u8 *)p + p->x4);
    }
    q = (Chk *)((u8 *)p + p->off);
    for (i = 0; i < p->xE; i++) {
        if (q->x0 == D_00201CAC) D_0033F6D0[q->x18] = (u8 *)q - (u8 *)*D_00201FE8;
        q = (Chk *)((u8 *)q + q->x4);
    }
    func_00169D70(D_00201FE8, D_003406E0, 0x40);
    func_00178080(D_00201FE8);
}
