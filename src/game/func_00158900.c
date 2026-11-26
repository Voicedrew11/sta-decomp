#include "common.h"
typedef struct {
    s32 x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24, x28, x2C, x30, x34, x38, x3C, x40;
    s32 col;
    s32 x48;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; } f4C;
    u8 pad4D[3];
} Buf;
typedef struct {
    s32 x0, x4;
    s16 x8;
    u8 xA, xB;
} Arg;
extern s32 D_00201F2C;
extern void func_001545D0(void);
extern void func_001543E0(s32, u64);
extern void func_001544C0(void);
extern void func_00123C40(void *, s32, s32);
extern void func_00155BD0(void *);
extern void func_00176AE0(void);

void func_00158900(Arg *a0) {
    Buf b;
    u32 fbp;
    s32 i;
    s32 sel;
    sel = a0->x8 ? D_00201F2C : !D_00201F2C;
    if (sel == 0) fbp = 0;
    else if (sel == 1) fbp = 0x118000;
    else fbp = 0;
    func_001545D0();
    func_001543E0(0x3F, 0xFFFFFFFF);
    func_001543E0(0x42, 0x44);
    func_001543E0(0x47, 0x31001);
    func_001543E0(6, (u64)(fbp >> 8) | 0x68028000 | ((u64)2 << 32));
    func_001543E0(0x14, 0);
    func_001544C0();
    func_00123C40(&b, 0, 0x50);
    b.f4C.b0 = 1;
    b.f4C.b1 = 1;
    b.f4C.b2 = 1;
    b.x0 = 0x7000;
    b.x4 = 0x8E10;
    b.x8 = -1;
    b.x10 = 0x6C00;
    b.x14 = 0x7210;
    b.x18 = -1;
    b.x20 = 0x400;
    b.x24 = 0x1C00;
    b.x30 = 0;
    b.x34 = 0;
    if (a0->xA) {
        b.x0 += a0->x0;
        b.x4 += a0->x4;
        b.col = (a0->xA << 24) | 0x808080;
        for (i = 0; i < 0x280; i += 0x40) {
            func_00155BD0(&b);
            b.x0 += 0x400;
            b.x10 += 0x400;
            b.x20 += 0x400;
            b.x30 += 0x400;
        }
    }
    if (a0->xB) {
        b.x0 -= a0->x0;
        b.x4 -= a0->x4;
        b.col = (a0->xB << 24) | 0x808080;
        for (i = 0; i < 0x280; i += 0x40) {
            func_00155BD0(&b);
            b.x0 += 0x400;
            b.x10 += 0x400;
            b.x20 += 0x400;
            b.x30 += 0x400;
        }
    }
    func_00176AE0();
}
