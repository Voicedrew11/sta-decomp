#include "common.h"
typedef union { u128 q; u64 d[2]; } Q;
extern Q *D_002F1994[];
void func_001541F0(u32 a, u64 b) {
    Q t; Q *p;
    t.d[0] = b; t.d[1] = a;
    p = D_002F1994[0];
    D_002F1994[0] = p + 1;
    *p = t;
}

