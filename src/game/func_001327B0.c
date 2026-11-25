#include "m2c.h"
void func_001543E0(s32, s64);
void func_00154420(void);
void func_001545D0(void);
void func_00176AE0(void);
extern u16 D_00201F04;
extern u16 D_00201F08;
extern u32 D_00201EF4;
extern u32 D_00201F00;

void func_001327B0(void) {
    u16 w;
    u16 h;
    s64 a;
    h = D_00201F08; w = D_00201F04;
    func_001545D0();
    a = (s32)((u32)w >> 6);
    a = a << 16;
    func_001543E0(0x4C, (u64)D_00201EF4 | a | 0xA000000);
    func_001543E0(0x4D, (u64)D_00201EF4 | a | 0xA000000);
    func_001543E0(0x4E, (u64)D_00201F00 | 0x3A000000);
    func_001543E0(0x4F, (u64)D_00201F00 | 0x3A000000);
    a = (s64)(s32)(w - 1) << 16 | (s64)(s32)(h - 1) << 48;
    func_001543E0(0x40, a);
    func_001543E0(0x41, a);
    func_00154420();
    func_00176AE0();
    func_001545D0();
    func_001543E0(0x1A, 0);
    func_001543E0(0x42, 0x68 | (s64)0x80 << 32);
    func_001543E0(0x43, 0xA1 | (s64)0x80 << 32);
    func_001543E0(0x47, 0x51001);
    func_001543E0(0x48, 0x51001);
    func_001543E0(1, 0x80000);
    func_00154420();
    func_00176AE0();
}
