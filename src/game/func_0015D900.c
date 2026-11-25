#include "m2c.h"
typedef union { u128 q; u32 w[4]; } Q;
extern Q *func_00154A80(s32);
extern void func_00154A70(void);
extern s32 D_00201F2C;
extern u8 D_0030D9A0[];

s32 func_0015D900(s32 n, s32 *ids) {
    s32 i;
    s32 cnt;
    u8 *base;
    s32 m;
    Q *p;
    s32 *q;
    s32 k;
    Q t;

    i = 0;
    cnt = 0;
    if (i < n) {
        q = ids;
        m = n;
        k = 0x3C;
        do {
            base = D_0030D9A0 + *q * 0x60;
            p = func_00154A80(1);
            t.q = 0;
            t.w[0] = 0x30000002;
            t.w[1] = (u32)(base + D_00201F2C * 0x20);
            t.w[3] = k | 0x6C020000;
            p->q = t.q;
            i++;
            cnt++;
            q++;
            k += 2;
        } while (i < m);
    }
    func_00154A70();
    return cnt;
}
