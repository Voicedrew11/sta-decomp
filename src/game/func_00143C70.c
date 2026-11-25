#include "common.h"

typedef struct { char pad[0x154]; s32 p; } S;
extern S *D_00201FA8;
void *func_00165130(u8 *o, s32 b);
void func_00135E30(s32 a, u8 mode, void *p, void *q, void *r, void *s);

void func_00143C70(u8 *o)
{
    s32 h = D_00201FA8->p;
    u8 m = o[8];
    void *p = func_00165130(o, 1);
    void *q = func_00165130(o, 2);
    void *r = func_00165130(o, 3);
    func_00135E30(h, m, p, q, r, func_00165130(o, 4));
}
