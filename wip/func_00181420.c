#include "m2c.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
extern s32 D_0020206C;
extern s32 D_00201CD4;
extern s32 D_00201F3C;
extern Q D_0048C4B0[];
void func_00176BC0(void);
s32 func_00154A80(s32);
void func_001549D0(void);
void func_00181420(void) {
    Q q;
    Q *p;
    u32 i;

    if (D_0020206C > 0) {
        if (D_00201CD4 != 0) func_00176BC0();
        p = (Q *)func_00154A80(D_0020206C * 9 + 3);
        q.q = 0;
        q.w[0] = (D_0020206C * 9 + 2) | 0x10000000;
        q.w[3] = ((D_0020206C * 9 + 1) << 16) | 0x6C00C000;
        p[0] = q;
        if (D_00201CD4 != 0) {
            q.q = 0;
            q.d[0] = (u64)D_0020206C | (0x8000 | ((u64)0x90AE4000 << 32));
            q.d[1] = 0x3434343E | ((u64)4 << 32);
            p[1] = q;
            p += 2;
        } else {
            q.q = 0;
            q.d[0] = (u64)D_0020206C | (0x8000 | ((u64)0x90A64000 << 32));
            q.d[1] = 0x3434343E | ((u64)4 << 32);
            p[1] = q;
            p += 2;
        }
        D_00201CD4 = -1;
        for (i = 0; i < D_0020206C * 9; i++) p[i] = D_0048C4B0[i];
        p += i;
        q.q = 0;
        q.w[2] = D_00201F3C | 0x15000000;
        q.w[3] = 0x11000000;
        *p = q;
        func_001549D0();
        D_0020206C = 0;
    }
}
