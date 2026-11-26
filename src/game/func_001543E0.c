#include "common.h"
typedef union { u128 q; u64 d[2]; } Q;
extern s32 D_002F1994[];
void func_001543E0(u32 a, u64 b) {
    Q q;
    Q *p;
    q.d[0] = b;
    q.d[1] = a;
    p = (Q *)D_002F1994[0];
    D_002F1994[0] = (s32)(p + 1);
    *p = q;
}
