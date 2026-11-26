#include "common.h"
typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
u16 func_0013F700(void *);
u16 func_0013F710(void *, s32);
void func_00144E40(u8 *o) {
    void *p;
    u8 pct;
    u16 hp;
    pct = o[8];
    p = D_00201FA8->p;
    hp = func_0013F700(p);
    func_0013F710(p, -hp);
    if (pct > 100) pct = 100;
    func_0013F710(p, hp * pct / 100);
}
