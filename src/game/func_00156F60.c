#include "m2c.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
extern s32 D_00201F2C;
extern s8 D_00222A10[];
extern void func_001545D0(void);
extern void func_001543E0(s32, u64);
extern void func_00154420(void);
extern Q *func_00154A80(s32);
extern void func_00154A70(void);
extern void func_00176AE0(void);
static inline s32 wd(void) { return D_00201F2C ? 0 : 0x1180; }

void func_00156F60(void) {
    Q q;
    Q *p;
    if (D_00222A10[0] == 2) {
        func_001545D0();
        func_001543E0(0x4C, (s64)(wd() / 32) | 0xA0000);
        func_001543E0(0x4E, 0x3A000118);
        func_001543E0(0x40, 0x027F0000 | ((s64)0x01BF0000 << 32));
        func_001543E0(0x47, 0x31001);
        func_00154420();
        p = func_00154A80(7);
        q.q = 0;
        q.w[0] = 0x10000006;
        q.w[3] = 0x50000006;
        p[0].q = q.q;
        q.d[0] = ((u64)0x50834000 << 32) | 0x8001;
        q.d[1] = 0x55551;
        p[1].q = q.q;
        q.w[0] = 0;
        q.w[1] = 0;
        q.w[2] = 0;
        q.w[3] = 0;
        p[2].q = q.q;
        q.w[0] = 0x6C00;
        q.w[1] = 0x7200;
        q.w[2] = 0;
        q.w[3] = 0;
        p[3].q = q.q;
        q.w[0] = 0x9400;
        q.w[1] = 0x74C0;
        q.w[2] = 0;
        q.w[3] = 0;
        p[4].q = q.q;
        q.w[0] = 0x6C00;
        q.w[1] = 0x8B40;
        q.w[2] = 0;
        q.w[3] = 0;
        p[5].q = q.q;
        q.w[0] = 0x9400;
        q.w[1] = 0x8E00;
        q.w[2] = 0;
        q.w[3] = 0;
        p[6].q = q.q;
        func_00154A70();
        func_00176AE0();
    }
}
