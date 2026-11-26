#include "m2c.h"
typedef struct { s16 x0; u16 x2; } P;
extern s32 D_00202278;
extern P **D_004A4570[];
extern s16 D_004A4774[];
extern u16 D_004A4776[];
P **func_001288C0(s32, s32);
void memset(P *, s32, s32);
void func_001A51E0(P **, s32);
static inline s32 reg(P **h) {
    P *p = *h;
    memset(p, 0, 0x750);
    D_004A4570[p->x2 = D_004A4776[--D_004A4774[0]]] = h;
    return 1;
}

P **func_001A7D90(s16 a) {
    P ** volatile h;
    h = func_001288C0(D_00202278, 0x750);
    if (!reg(h)) return NULL;
    (*h)->x0 = a;
    func_001A51E0(h, 1);
    return h;
}
