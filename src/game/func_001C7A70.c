#include "actor.h"
typedef union { u128 q[2]; f32 f[8]; } M;
s32 func_001CCD90(s32);
void func_00102A60(f32 *, s8 *);
void func_001502A0(f32, M *, f32 *, f32 *);
f32 func_0011D850(f32);
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
inline s8 *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}

s32 func_001C7A70(M *out) {
    M m;
    f32 a[4];
    f32 b[4];
    s8 *p;
    s8 *q;
    s8 *r;
    f32 *pf;
    f32 x;
    f32 c;
    f32 d;

    p = get();
    if (p == NULL) {
        return 0;
    }
    if ((s16)func_001CCD90(*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) == -1) {
        return 0;
    }
    if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
        q = *(s8 **)(p + 0x3C4);
    } else {
        q = *(s8 **)(p + 0x3C0);
    }
    if (q != NULL && *(s32 *)(q + 0x84) != 0) {
        r = *(s8 **)(q + 0x88);
        if (r != NULL) {
            func_00102A60(a, r);
            func_00102A60(b, r + 0x10);
            func_001502A0(a[3], &m, b, a);
            pf = &m.f[7];
            x = *pf;
            p = get();
            if (p != NULL) {
                c = func_0011D850(-1.0471976f);
                d = func_0011D850(WRAP(*(f32 *)(*(s8 **)(p + 0x18) + 0x30)));
                if (!(d <= c)) {
                    d = c;
                }
                x *= 1.0f + d / c;
            }
            *pf = x;
            *out = m;
            return 1;
        }
    }
    return 0;
}
