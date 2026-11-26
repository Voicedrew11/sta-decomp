#include "common.h"
typedef struct { s8 x0; s8 x1; s8 x2; s8 x3; } C;
extern struct { char pad[0x280]; C c[64]; } D_004BA500;
typedef struct { s32 v; char pad[12]; } E;
extern E D_004BA70C[];
extern s8 D_004BA920[][32];
extern u16 D_004BAA36[];
void func_001DBDB0(s32, s32, s32, s32);
s32 func_001DA530(s32 i) {
    C *c;
    if (D_004BAA36[0] == 0) return -1;
    if (i < 0 || i >= 64) return -1;
    c = &D_004BA500.c[i];
    if (c->x2 != -1 && !(0 > c->x1) && c->x1 < 8 && c->x0 >= 0) {
        func_001DBDB0(2, 2, c->x0, D_004BA70C[c->x1].v);
        c->x2 = -1;
        D_004BA920[c->x1][c->x0] = -1;
    }
    return 0;
}
