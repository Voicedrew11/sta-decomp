#include "m2c.h"
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 1; u8 b5 : 1; u8 b6 : 1; u8 b7 : 1; } BF8;
typedef struct { u8 v : 2; } BF50;
typedef struct { u8 p : 1; u8 v : 2; } BF51;
typedef struct { u8 p : 2; u8 v : 2; } BF24;
extern s32 D_00201F2C;
void func_001B87C0(s8 *, u32, s32, s32, f32, f32);
s32 func_001A9D50(s32, u16);
void func_001BB760(s8 *, u32, s32, s8 *, s32);
void func_00171B30(s8 *, u16, f32, s32);
void func_00171610(s8 **);

void func_001BB320(s8 *p, u32 i) {
    s8 *t;
    s8 *s;
    s8 **m;
    s32 r;
    s8 *e;
    s8 *e30;
    s32 mode; s8 *q;

    e30 = *(s8 **)(p + 0x138) + i * 0x30;
    e = *(s8 **)(p + 0x180) + (i << 7);
    t = *(s8 **)(p + 0x170) + (*(u16 *)(e30 + 0x18) << 6);
    if ((*(u8 *)(e + 0x50) & 3) && ((BF8 *)(t + 0x12))->b3) {
        t = *(s8 **)(p + 0x170) + (*(u16 *)(t + 6) << 6);
        m = *(s8 ***)(e + 0x44);
    } else {
        m = *(s8 ***)(e + 0x40);
    }
    s = *m; q = *(s8 **)s;
    if ((*(u8 *)(t + 0x12) & 1) && *(u16 *)(*(s8 **)q + 0x16) != 0) {
        mode = ((BF24 *)(e30 + 0x24))->v;
        if (mode == 1) {
            func_001B87C0(p, i, 0, 0x80, 0.0f, 1.0f);
        } else if (mode == 2) {
            func_001B87C0(p, i, 0, 0, 0.0f, 1.0f);
            ((BF8 *)(e + 0x52))->b7 = 1;
        }
    }
    r = func_001A9D50(*(s32 *)p, i);
    switch (*(u16 *)(t + 4)) {
    case 0:
        break;
    case 1:
        if (r & 1) {
            func_001B87C0(p, i, 0xB, 1, 0.0f, 1.0f);
            ((BF8 *)(e + 0x52))->b6 = 1;
        }
        break;
    case 2:
        if (r & 1) {
            s8 *e2;
            s8 *t2;
            ((BF50 *)(e + 0x50))->v = 3;
            ((BF8 *)(e + 0x52))->b4 = 1;
            e2 = *(s8 **)(p + 0x180) + (i << 7);
            t2 = *(s8 **)(p + 0x170) + (*(u16 *)(*(s8 **)(p + 0x138) + i * 0x30 + 0x18) << 6);
            if ((*(u8 *)(e2 + 0x50) & 3) && ((BF8 *)(t2 + 0x12))->b3) {
                t2 = *(s8 **)(p + 0x170) + (*(u16 *)(t2 + 6) << 6);
                m = *(s8 ***)(e2 + 0x44);
            } else {
                m = *(s8 ***)(e2 + 0x40);
            }
            s = *m;
            func_001B87C0(p, i, 1, 1, 0.0f, 1.0f);
            if (((BF8 *)(t2 + 0x12))->b7) {
                ((BF8 *)(e + 0x52))->b3 = 0;
            }
            if (!(r & 2)) {
                func_001BB760(p, i, *(s16 *)(e30 + 0x28), e30, 0);
            }
        }
        break;
    case 3:
        if (r & 1) {
            func_001B87C0(p, i, 0xA, 1, 0.0f, 1.0f);
            ((BF8 *)(e + 0x52))->b5 = 1;
            if (!(r & 2)) {
                func_001BB760(p, i, *(s16 *)(e30 + 0x28), e30, 1);
            }
        }
        break;
    case 4:
        ((BF8 *)(e + 0x52))->b6 = 0;
        break;
    case 5:
        if (r & 1) {
            func_001B87C0(p, i, 0xA, 1, 0.0f, 1.0f);
            ((BF8 *)(e + 0x53))->b3 = 1;
        }
        break;
    }
    if (((BF8 *)(e + 0x50))->b2) {
        func_00171B30(s, *(u16 *)(s + 8), *(f32 *)(s + 0xC), !(D_00201F2C != 0));
        func_00171610(m);
    }
    ((BF51 *)(e + 0x51))->v = 2;
}
