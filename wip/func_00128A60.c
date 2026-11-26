#include "m2c.h"
typedef struct E {
    struct E *x0;
    struct E *x4;
    struct E *x8;
    struct E *xC;
    u8 pad10[4];
    u8 b0:2;
    u8 b2:6;
    u8 pad15[0x1B];
} E;
typedef struct {
    E *x0;
    E *x4;
    E *x8;
    s32 xC;
    s32 x10;
    s32 x14;
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:3;
    s32 x1C;
    s32 x20;
    E *x24;
    E *x28;
} S;

void func_00128A60(S *a0, E *a1, E *a2, s32 a3) {
    s32 i;
    a0->x0 = a1;
    a0->x4 = a2;
    a0->x8 = a2 - a3;
    a0->xC = a3;
    a0->x10 = a3;
    a0->x14 = 0;
    a0->x1C = 0;
    a0->x20 = 0;
    a0->b1 = 0;
    a0->b2 = 0;
    a0->b0 = 0;
    a0->b3 = 0;
    a0->b4 = 0;
    a0->x28 = a1;
    for (i = 0; i < a3; i++) {
        a1->x0 = 0;
        a1->x4 = 0;
        a1->x8 = 0;
        a1->b0 = 0;
        a1->xC = a1 + 1;
        a1 += 1;
    }
    a0->x28->x0 = a0->x0 + a3;
    a0->x28->x4 = a0->x28->x0;
    a0->x28->x8 = a0->x8;
    a1[-1].xC = 0;
    a0->x24 = a0->x28;
}
