#include "m2c.h"
typedef union { u128 q; f32 f[4]; } Q;
typedef struct { Q a; Q b; } Ray;
typedef struct { s32 w[16]; } Res;
void func_00150160(Ray *, s8 *, s8 *);
s32 func_001B23E0(s8 *, Res *, Ray *, u16, s32, s32);
s32 func_001B2F30(s32, Res *, Ray *, s32, s32);
void func_001C7730(Res *, s32);
extern s32 D_00201E80;

s32 func_001C7850(s8 *a0, s32 a1) {
    Res res;
    Ray ray;
    s8 *o;
    s32 j;
    s32 i;
    s8 ***pp;
    s32 **q;

    func_00150160(&ray, a0 + 0x60, a0 + 0x40);
    for (i = 0, pp = (s8 ***)(&D_00201E80 + 2); i < 2; i++, pp++) {
        if (*pp != 0) {
            o = **pp;
            if (o != 0) {
                for (j = 0; j < *(u16 *)(o + 0x6E); j++) {
                    if (func_001B23E0(o, &res, &ray, j, 2, 1) != 0) {
                        func_001C7730(&res, a1);
                    }
                }
            }
        }
    }
    ray = *(Ray *)(a0 + 0x40);
    for (i = 0, q = (s32 **)(&D_00201E80 + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0 && func_001B2F30(**q, &res, &ray, 2, 1) != 0) {
            func_001C7730(&res, a1);
            return 1;
        }
    }
    return 0;
}
