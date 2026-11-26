#include "m2c.h"
extern u8 *D_001F2300[];
extern u8 *D_001F1C50[];
extern u8 *D_0033F500[];
extern u8 *D_00201FA4;
void func_00164F10(void *);

void func_00165400(u8 *a0, s32 a1, s32 a2) {
    u16 k;
    u8 *p;
    u32 i;
    u8 *dst;
    u8 *q;
    s32 t;
    dst = 0;
    k = (a1 & 0xFFFF00) >> 8;
    t = a1 & 0xFF;
    if (t >= 0x40) {
        p = D_00201FA4;
        if (p != 0) {
            i = 0;
            if (i < *(u32 *)(p + 4)) {
                q = p;
                do {
                    if (*(u32 *)(q + 0x294) != 0) {
                        func_00164F10(q + 0x294);
                    }
                    q += 0x258;
                    i++;
                } while (i < *(u32 *)(p + 4));
            }
        }
    } else if (t >= 0x20) {
        dst = D_001F2300[t] + a2;
    } else if (t >= 0x10) {
        dst = D_001F1C50[t] + a2;
    } else {
        dst = D_0033F500[t] + a2;
    }
    switch (k) {
    case 0: *(s8 *)dst = *(s8 *)(a0 + 4); break;
    case 1: *(u8 *)dst = *(u8 *)(a0 + 4); break;
    case 2: *(s16 *)dst = *(s16 *)(a0 + 4); break;
    case 3: *(u16 *)dst = *(u16 *)(a0 + 4); break;
    case 4: *(s32 *)dst = *(s32 *)(a0 + 4); break;
    case 5: *(u32 *)dst = *(u32 *)(a0 + 4); break;
    case 6: *(f32 *)dst = *(f32 *)(a0 + 4); break;
    }
}
