#include "common.h"
typedef struct {
    s32 x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24, x28, x2C, x30, x34, x38, x3C, x40;
    s32 col;
    s32 x48;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; } f4C;
    u8 pad4D[3];
} Buf;
typedef struct {
    u32 x0;
    u16 w, h;
    u8 r, g, b, a;
    s16 xC, xE, x10, x12;
    u16 x14, x16, x18;
    u8 x1A, x1B;
    s8 x1C, x1D, x1E, x1F;
} P;
void memset(void *, s32, s32);
void func_001545D0(void);
void func_001543E0(s32, s64);
void func_001544C0(void);
void func_00155BD0(void *);
void func_00153740(void);
void func_00176AE0(void);
f32 cosf(f32);
f32 sinf(f32);
extern s32 D_00201F2C;
extern u64 D_00201F78;

void func_001580E0(P *p) {
    Buf b;
    u64 tex, frame, sc;
    s32 k;
    u32 v;
    s32 dx, dy;
    u32 i;
    s32 ang;
    u8 a;
    s16 c, s;
    f32 f;
    if (p->x1A) {
        memset(&b, 0, 0x50);
        b.f4C.b0 = 1;
        b.f4C.b1 = 1;
        b.f4C.b2 = 1;
        k = p->x1C ? D_00201F2C : !(D_00201F2C != 0);
        if (k == 0) v = 0; else if (k == 1) v = 0x118000; else v = 0;
        tex = (u64)(v >> 8) | 0x68028000 | ((u64)2 << 32);
        sc = ((s64)(p->w - 1) << 16) | ((s64)(p->h - 1) << 48);
        frame = (u64)p->x0 | ((s64)(s32)((u32)p->w >> 6) << 16) | 0xA000000;
        func_001545D0();
        func_001543E0(0x4C, frame);
        func_001543E0(0x40, sc);
        func_001543E0(0x18, 0x8000 | ((u64)0x8000 << 32));
        func_001543E0(0x47, 0x31001);
        if (p->x1F) {
            func_001543E0(0x45, 1);
            func_001543E0(0x44, D_00201F78);
        }
        func_001543E0(6, tex);
        func_001543E0(0x14, 0x60);
        func_001544C0();
        b.f4C.b1 = 1;
        b.f4C.b2 = 0;
        b.col = 0x80808080;
        b.x0 = 0x8000;
        b.x4 = 0x8000;
        b.x8 = -1;
        b.x10 = (p->w + 0x800) << 4;
        b.x14 = (p->h + 0x800) << 4;
        b.x18 = -1;
        b.x20 = 0;
        b.x24 = 0;
        b.x30 = 0x2800;
        b.x34 = 0x1C00;
        func_00155BD0(&b);
        if (p->x1D) {
            dx = 0x1400 / p->w;
            dy = 0xE00 / p->h;
            func_001545D0();
            func_001543E0(0x42, 0x64 | ((u64)0x40 << 32));
            func_001544C0();
            b.f4C.b1 = 1;
            b.f4C.b2 = 1;
            b.col = 0x80808080;
            b.x0 = 0x8000;
            b.x4 = 0x8000;
            b.x8 = -1;
            b.x10 = (p->w + 0x800) << 4;
            b.x14 = (p->h + 0x800) << 4;
            b.x18 = -1;
            b.x20 = dx;
            b.x24 = dx;
            b.x30 = dy + 0x2800;
            b.x34 = dy + 0x1C00;
            func_00155BD0(&b);
        }
        if (p->r | p->g | p->b) {
            func_001545D0();
            func_001543E0(0x42, 0x62 | ((u64)0x80 << 32));
            func_001544C0();
            b.f4C.b1 = 0;
            b.f4C.b2 = 1;
            b.col = p->r | 0x80000000 | (p->g << 8) | (p->b << 16);
            func_00155BD0(&b);
        }
        func_00153740();
        if (p->x1A && p->x18) {
            tex = (u64)(p->x0 << 5) | ((s64)(s32)((u32)p->w >> 6) << 14) | (0x68A00000 | ((u64)2 << 32));
            b.f4C.b1 = 1;
            b.f4C.b2 = 1;
            func_001545D0();
            func_001543E0(0x42, 0x48);
            func_001543E0(6, tex);
            if (p->x1F) {
                func_001543E0(0x45, 0);
            }
            func_001544C0();
            b.x0 = 0x6C00;
            b.x4 = 0x7200;
            b.x10 = 0x9400;
            b.x14 = 0x8E00;
            b.x20 = p->xC;
            b.x24 = p->xE + 8;
            b.x30 = (p->w << 4) + p->x10;
            b.x34 = (p->h << 4) + p->x12;
            b.col = (p->a << 24) | 0x808080;
            func_00155BD0(&b);
            p->x16 += p->x1E;
            while (p->x16 >= p->x18) {
                p->x16 -= p->x18;
            }
            a = p->a;
            for (i = 1; i < p->x1A; i++) {
                a = (a * p->x1B) >> 7;
                b.col &= 0xFFFFFF;
                b.col |= a << 24;
                for (ang = p->x16; ang < 360; ang += p->x18) {
                    f = 3.1415f * ang / 180.0f;
                    c = (s32)(i * (p->x14 * cosf(f)));
                    s = (s32)(i * (p->x14 * sinf(f)));
                    b.x0 = c + 0x6C00;
                    b.x4 = s + 0x7200;
                    b.x10 = c + 0x9400;
                    b.x14 = s + 0x8E00;
                    func_00155BD0(&b);
                }
            }
        }
        func_00176AE0();
    }
}
