#include "m2c.h"
#include "common.h"

/* func_00157320 */
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q;
extern s32 D_00201F2C;
extern f32 D_00201E90;
extern Q D_001F2050;
extern void func_001545D0(void);
extern void func_001543E0(s32, u64);
extern void func_00154420(void);
extern Q *func_00154A80(s32);
extern void func_00154A70(void);
extern void func_00176AE0(void);
extern u64 __fixunssfdi(f32);
static inline s32 wd(void) { return D_00201F2C ? 0 : 0x1180; }

void func_00157320(s32 a0) {
    Q q;
    Q c;
    Q *p;
    u64 v;
    f32 f;
    u16 i;
    func_001545D0();
    func_001543E0(0x3F, 0xFFFFFFFF);
    func_001543E0(0x4C, (s64)(wd() / 32) | 0xA0000);
    func_001543E0(0x4E, 0x3A000118);
    f = D_00201E90;
    v = (__fixunssfdi(f) << 32) | 0x27F0000;
    func_001543E0(0x40, v | (__fixunssfdi(448.0f - f - 1.0f) << 48));
    func_001543E0(0x47, 0x32001);
    func_00154420();
    p = func_00154A80(0x20);
    q.q = 0;
    q.w[0] = 0x1000001F;
    q.w[3] = 0x5000001F;
    p[0].q = q.q;
    q.d[0] = ((u64)0x30834000 << 32) | 0x800A;
    q.d[1] = 0x551;
    p[1].q = q.q;
    p += 2;
    i = 0;
    do {
        c = D_001F2050;
        q.w[0] = 128.0f * c.f[0];
        q.w[1] = 128.0f * c.f[1];
        q.w[2] = 128.0f * c.f[2];
        q.w[3] = 128.0f * c.f[3];
        p[0].q = q.q;
        q.w[0] = (i + 0x6C0) << 4;
        q.w[1] = 0x7200;
        q.w[2] = a0;
        q.w[3] = 0;
        p[1].q = q.q;
        q.w[0] = (i + 0x700) << 4;
        q.w[1] = 0x8E00;
        q.w[2] = a0;
        q.w[3] = 0;
        p[2].q = q.q;
        p += 3;
        i += 0x40;
    } while (i < 0x280);
    func_00154A70();
    func_00176AE0();
}

/* func_00157620 */
extern s32 D_002F1AE0[];

s32 *func_00157620(void) {
    return D_002F1AE0;
}
