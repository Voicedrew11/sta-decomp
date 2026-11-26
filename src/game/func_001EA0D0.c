#include "common.h"
s32 WaitSema(s32);
s32 SignalSema(s32);
void func_00123A88(void *, void *, s32);
typedef struct { u8 pad[0x48]; u8 x48[0x14]; s32 x5C; u8 p60[0x28]; s32 x88; u8 p8C[0x1C]; s32 xA8; } P;
void func_001EAF60(void *, s32 *, s32 *, s32 *, s32 *);
typedef union { u32 w; f32 f; } T;
extern T D_00201E74;
extern s32 D_004BDF9C[];
extern s32 D_004BDFC8[];
extern s64 D_004BDFD0[];

static inline s32 put(u8 *p1, s32 n1, u8 *p2, s32 n2, u8 *s1, s32 l1, u8 *s2, s32 l2) {
    if (n1 + n2 < l1 + l2) return 0;
    if (n1 <= l1) {
        func_00123A88(p1, s1, n1);
        func_00123A88(p2, s1 + n1, l1 - n1);
        func_00123A88(p2 + l1 - n1, s2, l2);
    } else if (!(l2 < n1 - l1)) {
        func_00123A88(p1, s1, l1);
        func_00123A88(p1 + l1, s2, n1 - l1);
        func_00123A88(p2, s2 + n1 - l1, l2 - (n1 - l1));
    } else {
        func_00123A88(p1, s1, l1);
        func_00123A88(p1 + l1, s2, l2);
    }
    return l1 + l2;
}

s32 func_001EA0D0(P *p) {
    s32 a1;
    s32 a2;
    T v;
    s32 n1;
    s32 n2;
    s32 r;
    u8 *p1;
    u8 *p2;
    v = D_00201E74;
    func_001EAF60(p->x48, &a1, &n1, &a2, &n2);
    if (n1 + n2 < 4) return 0;
    p1 = (u8 *)(((u32)a1 & 0x0FFFFFFF) | 0x20000000);
    p2 = (u8 *)(((u32)a2 & 0x0FFFFFFF) | 0x20000000);
    r = put(p1, n1, p2, n2, (u8 *)&v, 4, NULL, 0);
    WaitSema(*D_004BDFC8);
    *D_004BDF9C += r;
    *D_004BDFD0 += r;
    SignalSema(*D_004BDFC8);
    WaitSema(p->x88);
    p->x5C = (p->x5C + 0x7FF) / 0x800 * 0x800;
    SignalSema(p->x88);
    if (p->xA8 == 0) p->xA8 = 2;
    return 1;
}

