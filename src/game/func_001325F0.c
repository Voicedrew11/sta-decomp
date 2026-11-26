#include "m2c.h"
extern s32 D_00201F2C;
extern f32 D_00201E90;
extern void func_001545D0(void);
extern void func_001543E0(s32, u64);
extern void func_00154420(void);
extern void func_00176AE0(void);
extern u64 func_0011F650(f32);
static inline s32 wd(void) { return D_00201F2C ? 0 : 0x1180; }

void func_001325F0(void) {
    f32 f;
    func_001545D0();
    func_001543E0(0x4C, (s64)(wd() / 32) | 0xA0000);
    func_001543E0(0x4D, (s64)(wd() / 32) | 0xA0000);
    func_001543E0(0x4E, 0x3A000118);
    func_001543E0(0x4F, 0x3A000118);
    f = D_00201E90;
    func_001543E0(0x40, 0x27F0000 | ((u64)func_0011F650(f) << 32) | ((u64)func_0011F650(448.0f - f - 1.0f) << 48));
    f = D_00201E90;
    func_001543E0(0x41, 0x27F0000 | ((u64)func_0011F650(f) << 32) | ((u64)func_0011F650(448.0f - f - 1.0f) << 48));
    func_00154420();
    func_00176AE0();
    func_001545D0();
    func_001543E0(0x1A, 1);
    func_001543E0(0x42, 0xAA);
    func_001543E0(0x43, 0x48);
    func_001543E0(0x47, 0x50000);
    func_001543E0(0x48, 0x50000);
    func_001543E0(1, 0x80000);
    func_00154420();
    func_00176AE0();
}
