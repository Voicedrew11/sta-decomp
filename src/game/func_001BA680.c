#include "m2c.h"
typedef struct { u8 st:2; u8 b2:1; } F50;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } F52;
typedef struct { u8 p:3; u8 v:1; } BF3;
typedef struct { u8 p:7; u8 v:1; } BF7;
void func_001BA850(s8 *p, u32 i, f32 dt);
static inline s8 *getT(s8 *p, s8 *e30, s8 *e) {
    s8 *base = *(s8 **)(p + 0x170);
    s8 *t = base + (*(u16 *)(e30 + 0x18) << 6);
    if ((*(u8 *)(e + 0x50) & 3) && ((BF3 *)(t + 0x12))->v) {
        return base + (*(u16 *)(t + 6) << 6);
    }
    return t;
}

void func_001BA680(s8 *p, u32 i, f32 dt) {
    s8 *e30;
    s8 *e;
    s8 *t;
    s32 st;

    e = *(s8 **)(p + 0x180) + (i << 7);
    e30 = *(s8 **)(p + 0x138) + i * 0x30;
    t = getT(p, e30, e);
    st = *(u8 *)(e + 0x50) & 3;
    switch ((u8)st) {
    case 0:
        func_001BA850(p, i, dt);
        break;
    case 1:
        if (((F50 *)(e + 0x50))->b2) {
            break;
        }
        if (((BF7 *)(t + 0x12))->v) {
            ((F50 *)(e + 0x50))->st = 2;
            *(f32 *)(e + 0x5C) = 1.0f;
            break;
        }
        ((F50 *)(e + 0x50))->st = 3;
        ((F52 *)(e + 0x52))->b4 = 1;
        break;
    case 2:
        *(f32 *)(e + 0x5C) -= dt;
        if (*(f32 *)(e + 0x5C) < 0.0f) {
            ((F50 *)(e + 0x50))->st = 3;
            ((F52 *)(e + 0x52))->b3 = 0;
            ((F52 *)(e + 0x52))->b4 = 1;
            break;
        }
        *(f32 *)(e + 0x58) = *(f32 *)(e + 0x5C);
        break;
    case 3:
        ((F52 *)(e + 0x52))->b4 = 1;
        break;
    }
}
