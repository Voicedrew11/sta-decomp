#include "m2c.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q;
extern s32 D_00201F2C;
void func_001545D0(void);
void func_001543E0(s32, s64);
void func_00154420(void);
s32 func_00154A80(s32);
void func_00154A70(void);
void func_00176AE0(void);

void func_00157110(u8 a0) {
    Q *p;
    Q q;
    u16 x;
    if (a0 != 0x80) {
        func_001545D0();
        func_001543E0(0x4C, (s64)((D_00201F2C ? 0 : 0x1180) / 32) | 0xA0000);
        func_001543E0(0x4E, 0x3A000118);
        func_001543E0(0x40, 0x027F0000 | ((s64)0x01BF0000 << 32));
        func_001543E0(0x47, 0x31001);
        if (a0 > 0x80) {
            func_001543E0(0x42, 0x49 | ((s64)0x80 << 32));
        } else {
            func_001543E0(0x42, 0x46 | ((s64)0x80 << 32));
        }
        func_00154420();
        p = (Q *)func_00154A80(0x20);
        q.q = 0;
        q.w[0] = 0x1000001F;
        q.w[3] = 0x5000001F;
        p[0].q = q.q;
        q.d[0] = 0x800A | ((u64)0x30A34000 << 32);
        q.d[1] = 0x551;
        p[1].q = q.q;
        p += 2;
        x = 0;
        do {
            q.w[0] = 0;
            q.w[1] = 0;
            q.w[2] = 0;
            q.w[3] = (a0 > 0x80) ? a0 - 0x80 : 0x80 - a0;
            p[0].q = q.q;
            q.w[0] = (x + 0x6C0) << 4;
            q.w[1] = 0x7200;
            q.w[2] = 0;
            q.w[3] = 0;
            p[1].q = q.q;
            q.w[0] = (x + 0x700) << 4;
            q.w[1] = 0x8E00;
            q.w[2] = 0;
            q.w[3] = 0;
            p[2].q = q.q;
            x += 0x40;
            p += 3;
        } while (x < 0x280);
        func_00154A70();
        func_00176AE0();
    }
}
