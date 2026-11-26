#include "common.h"
typedef union Q { u128 q; struct { u32 a; u32 b; union Q *p; u32 d; } s; } Q;
extern u32 D_002F1990[];
extern Q *D_002F1994[];
void func_00154310(Q *a) {
    Q tag;
    tag.q = 0;
    tag.s.a = 0x20000000;
    tag.s.b = D_002F1990[0] & 0x0FFFFFFF;
    *a = tag;
    tag.q = 0;
    tag.s.a = 0x20000000;
    tag.s.b = (u32)(a + 1) & 0x0FFFFFFF;
    *D_002F1994[0] = tag;
    D_002F1990[0] = (u32)(*(Q *volatile *)D_002F1994 + 1);
    D_002F1994[0] = 0;
}

