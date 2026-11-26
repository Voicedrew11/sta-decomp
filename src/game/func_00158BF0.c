#include "m2c.h"
typedef struct {
    s32 x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24, x28, x2C, x30, x34, x38, x3C, x40;
    s32 col;
    s32 x48;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; } f4C;
    u8 pad4D[3];
} Buf;
extern s32 D_00201F2C;
void func_001545D0(void);
void func_001543E0(s32, u64);
void func_001544C0(void);
void memset(void *, s32, s32);
void func_00155BD0(void *);
void func_00176AE0(void);

void func_00158BF0(s32 dx, s32 dy) {
    Buf b;
    u32 w;
    s32 step;
    s32 i;
    u8 z;

    { s32 v = !(D_00201F2C != 0); if (v == 0) w = 0; else if (v == 1) w = 0x118000; else w = 0; }
    func_001545D0();
    func_001543E0(6, (u64)(w >> 8) | 0x68028000 | ((u64)2 << 32));
    func_001543E0(0x14, 0);
    func_001543E0(0x47, 0x31001);
    func_001543E0(0x22, 3);
    func_001544C0();
    memset(&b, 0, 0x50);
    b.col = 0xFF808080;
    if (dx <= 0) {
        b.x0 = 0x6C00;
        b.x0 -= 8;
        b.x10 = 0x6E00;
        b.x20 = 0;
        b.x30 = 0x200;
    } else {
        b.x0 = 0x9400;
        b.x10 = 0x9200;
        b.x10 -= 8;
        b.x20 = 0x2800;
        b.x30 = 0x2600;
    }
    if (dy <= 0) {
        b.x4 = 0x7200;
        b.x4 -= 8;
        b.x14 = 0x8E00;
        b.x34 = 0x1C00;
        b.x24 = 0;
    } else {
        b.x4 = 0x8E00;
        b.x14 = 0x7200;
        b.x14 -= 8;
        b.x24 = 0x1C00;
        b.x34 = 0;
    }
    b.x0 += dx;
    b.x10 += dx;
    b.x4 += dy;
    b.x14 += dy;
    if (dx <= 0) step = 0x200; else step = -0x200;
    for (i = 0; i < 20; i++) {
        z = 0;
        b.f4C.b0 = z;
        b.f4C.b1 = 1;
        b.f4C.b2 = z;
        func_00155BD0(&b);
        b.x0 += step;
        b.x10 += step;
        b.x20 += step;
        b.x30 += step;
    }
    func_001545D0();
    func_001543E0(0x22, 0);
    func_001544C0();
    func_00176AE0();
}
