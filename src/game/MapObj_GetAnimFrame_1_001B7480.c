#include "m2c.h"
typedef struct { u8 p:3; u8 v:1; } BF3;
s8 *MapObj_Find_1_001B19A0(s32);
f32 Mdl_GetMotionLength_0_00173F70(s8 *, u16);

f32 MapObj_GetAnimFrame_1_001B7480(s32 a0, s32 a1, u32 a2) {
    s8 ****pp;
    s8 **q;
    u16 k;
    s8 *e;
    u16 idx;
    s8 *p;
    s8 *tbl;
    s8 *t;
    s8 *o;
    s8 *s;
    s32 c;

    p = MapObj_Find_1_001B19A0(a0);
    if (p == NULL) {
        return 0.0f;
    }
    e = *(s8 **)(p + 0x180) + (a1 << 7);
    idx = *(u16 *)(*(s8 **)(p + 0x138) + a1 * 0x30 + 0x18);
    tbl = *(s8 **)(p + 0x170);
    t = tbl + (idx << 6);
    if ((*(u8 *)(e + 0x50) & 3) && ((BF3 *)(t + 0x12))->v) {
        k = *(u16 *)(tbl + (*(u16 *)(t + 6) << 6));
        pp = *(s8 *****)(e + 0x44);
    } else {
        pp = *(s8 *****)(e + 0x40);
        k = idx;
    }
    if (pp == NULL || *pp == NULL) {
        return 0.0f;
    }
    q = **pp;
    s = *(s8 **)(p + 0x194) + k * 0x10;
    if (q == NULL || (o = *q) == NULL) {
        return 0.0f;
    }
    if (*(u16 *)(o + 0x16) <= 0) {
        return 0.0f;
    }
    if (a2 >= *(u32 *)(s + 4)) {
        return 0.0f;
    }
    c = (*(u8 **)(s + 8))[a2];
    if (c == 0xFF) {
        return 0.0f;
    }
    if (q && q) {
    } /* permuter: scheduling barrier */
    return 30.0f * Mdl_GetMotionLength_0_00173F70(o, c);
}
