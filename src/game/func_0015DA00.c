#include "m2c.h"
f32 func_0015DF20(s8 *, f32 *);
extern s32 D_00201F2C;
extern s8 D_0030D180[];
extern s8 D_0030D9A0[];

s32 func_0015DA00(s64 arg0, s32 arg1, s32 *arg2, f32 *arg3) {
    s32 j;
    s32 i;
    s32 n;
    s32 id;
    s8 *s1;
    u16 *cnt;
    u16 *fp;
    s8 *e;
    f32 r;

    n = 0;
    s1 = D_0030D180;
    for (i = 0; i < 8; i++, s1 += 0x82) {
        cnt = (u16 *)(s1 + 0x408);
        if (arg0 & (1 << i)) {
            for (j = 0, fp = cnt; j < *cnt; j++, fp++) {
                id = fp[1];
                e = D_0030D9A0 + id * 0x60;
                r = M2C_FIELD(e, f32 *, 0x54) + arg3[3];
                if (func_0015DF20(e + (D_00201F2C << 5), arg3) < r * r) {
                    arg2[n++] = id;
                    if (n == arg1) return n;
                }
            }
        }
    }
    return n;
}
