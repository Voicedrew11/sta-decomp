#include "m2c.h"
typedef struct { u8 b0 : 2; } BF50;
typedef struct { u8 p : 1; u8 v : 2; } BF51;
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 1; u8 b5 : 1; u8 b6 : 1; u8 b7 : 1; } BF8;
typedef struct { u8 p : 2; u8 v : 2; } BF24;
s8 *func_001B19A0(s32);
s32 func_001A9D50(s32, u16);
void func_001A9E10(s32, u16, u8);
void func_001B87C0(s8 *, u32, s32, s32, f32, f32);
void func_00171B70(s8 *, u16, f32);
void sceVu0CopyVector(s8 *, s8 *);
void func_00171540(s8 *, s8 *);
s8 *func_001715B0(s8 **);
void func_001677C0(s8 *, s8 *);

void func_001B80B0(s32 a0, u32 a1) {
    s8 *p;
    s8 *t;
    s8 *e;
    s8 *s;
    s8 **q;
    s8 **m;
    s8 *r;
    s32 mode;

    p = func_001B19A0(a0);
    if (p != NULL) {
    t = *(s8 **)(p + 0x138) + a1 * 0x30;
    e = *(s8 **)(p + 0x180) + (a1 << 7);
    s = *(s8 **)(p + 0x170) + (*(u16 *)(t + 0x18) << 6);
    if (*(u16 *)(s + 4) == 2 && (*(u8 *)(e + 0x50) & 3)) {
    func_001A9E10(*(s32 *)p, a1, func_001A9D50(*(s32 *)p, a1) & ~1);
    ((BF50 *)(e + 0x50))->b0 = 0;
    ((BF8 *)(e + 0x52))->b3 = 1;
    ((BF8 *)(e + 0x52))->b4 = 0;
    *(f32 *)(e + 0x58) = 1.0f;
    m = *(s8 ***)(e + 0x40);
    if (m == NULL || *m == NULL) {
        return;
    }
    q = *(s8 ***)*m;
    if (q == NULL || *q == NULL) {
        return;
    }
    if (((BF8 *)(s + 0x12))->b0 && *(u16 *)(*q + 0x16) != 0) {
        mode = ((BF24 *)(t + 0x24))->v;
        if (mode == 1) {
            func_001B87C0(p, a1, 0, 0x80, 0.0f, 1.0f);
        } else if (mode == 2) {
            func_001B87C0(p, a1, 0, 0, 0.0f, 1.0f);
            ((BF8 *)(e + 0x52))->b7 = 1;
        }
        func_00171B70(*m, *(u16 *)(*m + 8), *(f32 *)(*m + 0xC));
    }
    sceVu0CopyVector(*m + 0x30, p + 0x10);
    func_00171540(*m, e);
    ((BF51 *)(e + 0x51))->v = 2;
    if (*(s8 **)(e + 0x54) != NULL) {
        r = func_001715B0(m);
        if (*(u8 *)(s + 2) < *(u16 *)(*q + 0x14)) {
            func_001677C0(*(s8 **)(e + 0x54), r + (*(u8 *)(s + 2) + 1) * 0x140 + 0xC0);
            return;
        }
        func_001677C0(*(s8 **)(e + 0x54), r + 0x200);
    }
    }
    }
}
