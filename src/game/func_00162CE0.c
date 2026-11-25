#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 rest:5; } Bits;
typedef struct {
    u16 m0;
    u8 pad2[2];
    u8 m4;
    u8 pad5[2];
    Bits f7;
    u8 pad8[0x20];
    u16 m28;
    u8 pad2A[2];
    u8 m2C[8];
    u8 m34[0x10];
    f32 m44;
    u8 pad48[4];
    u8 m4C[0x10];
    u8 m5C[8];
    u8 m64[8];
    u8 m6C[0x9C];
    u8 tbl[1];
} Src;
void func_00163700(f32, void *, void *, void *, void *, s32, f32);
void func_001631E0(f32, void *, void *, void *, void *, s32, f32);

void func_00162CE0(s8 *a0, Src *a1, f32 f) {
    s8 *base;
    s8 *p;
    s32 flag;
    f32 t;

    base = (s8 *)a1->tbl;
    p = base + a1->m4 * 0x14;
    p = a1->f7.b1 ? p + 0x40 : p;
    p = a1->f7.b2 ? p + 0xA0 : p;
    flag = (0.0f < a1->m44) ^ 1;
    t = 0.033333335f * (u32)a1->m0;
    if (a1->m28 & 1) {
        func_00163700(f, a0 + 0x20, a1->m2C, base, p, flag, t);
    }
    if (a1->m28 & 2) {
        func_001631E0(f, a0, a1->m34, base, p, flag, t);
        *(f32 *)(a0 + 0xC) = 1.0f;
    }
    if (a1->m28 & 4) {
        func_00163700(f, a0 + 0x24, &a1->m44, base, p, flag, t);
    }
    if (a1->m28 & 8) {
        func_001631E0(f, a0 + 0x10, a1->m4C, base, p, flag, t);
    }
    if (a1->m28 & 0x10) {
        func_00163700(f, a0 + 0xC, a1->m5C, base, p, flag, t);
    }
    if (a1->m28 & 0x20) {
        func_00163700(f, a0 + 0x28, a1->m64, base, p, flag, t);
    }
    if (a1->m28 & 0x40) {
        func_00163700(f, a0 + 0x2C, a1->m6C, base, p, flag, t);
    }
}
