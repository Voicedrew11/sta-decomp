#include "m2c.h"
typedef struct { u128 a; u128 b; } Ray;
typedef struct { s32 w[16]; } Res;
s32 func_001B2800(s8 *, Res *, Ray *, u16, s32, s32);
s32 func_001B3240(s8 *, Res *, Ray *, s32, s32);

s32 func_0013D430(s8 *o, Res *res, Ray *src, s32 mode, u8 fl) {
    Ray ray;
    u16 i;

    ray = *src;
    if (fl & 1) {
        func_001B3240(o, res, &ray, mode, 0);
    }
    if ((fl & 2) && o != NULL) {
        for (i = 0; i < *(u16 *)(o + 0x6E); i++) {
            func_001B2800(o, res, &ray, i, mode, 0);
        }
    }
    return res->w[9];
}
