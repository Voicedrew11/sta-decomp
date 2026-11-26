#include "common.h"
#include "actor.h"
typedef struct { u8 pad[0x94]; u8 x94; } S390;
typedef struct { u8 pad1C[0x390]; S390 *x390; u8 pad394[0x3CD - 0x394]; s8 x3CD; } P;
typedef struct { u8 b0:4; u8 f:3; u8 b7:1; } F30;
typedef struct { u16 h[6]; u8 padC[4]; u8 y[0x20]; F30 f30; u8 pad31[0xF]; } X;
s32 func_001CCD90(s32);
void memset(void *, s32, s32);
void func_001CEBF0(X *, u8 *, s8);
s32 func_001CC250(s32);

void func_001C79B0(X *x) {
    P *c;
    if (D_002022E4 == NULL) {
        c = NULL;
    } else {
        s8 *p = D_002022E4->unk518;
        if (p == NULL) c = NULL;
        else c = (P *)(p + 0x180);
    }
    if (c != 0) {
        memset(x, 0, 0x40);
        func_001CEBF0(x, x->y, c->x3CD);
        x->f30.f = func_001CC250(func_001CCD90(c->x390->x94 & 1));
    }
}

