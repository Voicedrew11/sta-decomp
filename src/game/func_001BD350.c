#include "actor.h"
s32 func_001CCD90(s32);
inline s8 *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}

s32 func_001BD350(s32 a) {
    s8 *p;
    s8 *q;
    s32 v;

    p = get();
    if (p == NULL) {
        return 1;
    }
    q = *(s8 **)(p + 0x3C8);
    if (q == NULL) {
        return 1;
    }
    if (!((Flags8 *)(q + 0xA8))->f.b0 || !((Flags8 *)(q + 0xA8))->f.b7) {
        return 1;
    }
    v = (s16)func_001CCD90(4);
    if ((v >= 300 && v <= 311) || (v >= 340 && v < 344)) {
        if ((a >= 4 && a <= 14) || (a >= 18 && a < 29)) {
            return 0;
        }
    }
    if (v == 0x14B || v == 0x14C) {
        if (a == 3 || a == 17) {
            return 0;
        }
    }
    if (v == 0x152 || v == 0x153) {
        if (a != 4 && a != 18) {
            return 0;
        }
    }
    return 1;
}
