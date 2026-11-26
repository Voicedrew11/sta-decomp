#include "common.h"
typedef struct { u8 pad[0x5A0]; u8 b0:1; u8 b1:1; u8 b2:1; } Ent;
s32 func_0013D6B0(void);
s32 func_0013EE30(Ent *);
s32 func_0013E220(Ent *);
u8 func_00142820(Ent *, s32);
Ent *func_001675D0(s8 *);
static inline u8 can(Ent *a0, Ent *a2) {
    if (func_0013EE30(a0)) {
        if (func_0013EE30(a2)) return 0;
        return 1;
    }
    return func_00142820(a0, func_0013E220(a2));
}

u8 func_0013BA90(s8 *a0, Ent *a1) {
    u8 ok;
    Ent *o;
    u8 r;
    ok = 1;
    o = func_001675D0(a0);
    if (o && o->b0 && o->b2) {
        if (func_0013D6B0()) r = 0; else r = can(o, a1);
        ok = r;
    }
    return ok;
}
