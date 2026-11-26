#include "common.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
Q *func_00154A80(s32);
void func_001549D0(void);
void func_001559C0(s32);
void func_00155900(void);
void func_001741D0(void) {
    Q q;
    Q *p;
    q.q = 0;
    func_001559C0(0);
    p = func_00154A80(1);
    q.w[0] = 0x10000000;
    q.w[2] = 0x30000C0;
    q.w[3] = 0x2000144;
    p[0] = q;
    func_001549D0();
    func_00155900();
}

