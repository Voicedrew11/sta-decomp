#include "m2c.h"
f32 func_001B7480(s32, s32, M2C_UNK);
s8 *func_001B19A0(s32);

f32 func_001B7610(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s8 *e;
    s8 *p;
    s32 n;
    s32 i;

    p = func_001B19A0(arg0);
    if (p == NULL) {
        return 0.0f;
    }
    n = M2C_FIELD(p, u16 *, 0x6E);
    i = 0;
    if (i < n) {
        e = M2C_FIELD(p, s8 **, 0x138);
        do {
            if (arg1 == M2C_FIELD(e, u16 *, 0x1A) % 100) {
                return func_001B7480(arg0, i, arg2);
            }
            i++;
            e += 0x30;
        } while (i < n);
    }
    return 0.0f;
}
