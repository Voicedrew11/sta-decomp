#include "common.h"
extern Vec D_001F2160;
s8 *func_001A5460(s32 *);
s32 func_0013EE40(s8 *);
f32 func_00146940(void *, void *);
s8 *func_00147450(void *pos, f32 d) {
    s32 it;
    s8 *e;
    s8 *r;
    f32 t;
    it = 0;
    e = func_001A5460(&it);
    r = NULL;
    while (e != NULL) {
        if (*(u16 *)e != 0 && func_0013EE40(e) == 0) {
            t = func_00146940(e ? (void *)(*(s8 **)(e + 0x518) + 0x90) : (void *)&D_001F2160, pos);
            if (t < d) { d = t; r = e; }
        }
        e = func_001A5460(&it);
    }
    return r;
}
