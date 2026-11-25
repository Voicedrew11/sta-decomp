#include "m2c.h"
typedef struct { s32 *p; } O;
extern O *D_00201E80[2];
s32 func_001CC0C0(s32, s32);
void func_001AE900(O *, s16, s32, s32, s32, s32);

void func_001B0990(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, u16 id, s32 t2) {
    O *o;
    O *p;
    o = 0;
    p = D_00201E80[2];
    if (p && p->p && *p->p == id) o = p;
    p = D_00201E80[3];
    if (p && p->p && *p->p == id) o = p;
    if (o && (u32)a0 < 0x400 && id < 200 && func_001CC0C0(a0, 1)) {
        func_001AE900(o, a0, a1, a2, t2, 0);
    }
}
