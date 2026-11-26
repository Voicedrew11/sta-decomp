#include "common.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
extern Q *func_00154A80(s32);
extern void func_00154A70(void);
extern void func_001545D0(void);
extern void func_00154420(void);
extern void func_001543E0(s32, u64);
extern u64 func_0011F650(f32);
void func_0015B1C0(Q *src, f32 *c) {
    Q q;
    Q *p;
    q.q = 0;
    p = func_00154A80(2);
    q.w[0] = 0x10000001;
    q.w[3] = 0x6C010059;
    p[0].q = q.q;
    p[1].q = src->q;
    func_00154A70();
    func_001545D0();
    func_001543E0(0x3D, func_0011F650(c[0]) | func_0011F650(c[1]) << 8 | func_0011F650(c[2]) << 16);
    func_00154420();
}

