#include "common.h"

void func_001545D0(void);
void func_001543E0(s32 reg, u64 v);
void func_00154420(void);
void func_00176AE0(void);

void func_00145790(void)
{
    func_001545D0();
    func_001543E0(0x1A, 1);
    func_001543E0(0x42, 0xAA);
    func_001543E0(0x43, 0x48);
    func_001543E0(0x47, 0x50000);
    func_001543E0(0x48, 0x50000);
    func_001543E0(1, 0x80000);
    func_001543E0(0x4E, ((u64)1 << 32) | 0x3A000118);
    func_001543E0(0x4F, ((u64)1 << 32) | 0x3A000118);
    func_00154420();
    func_00176AE0();
}
