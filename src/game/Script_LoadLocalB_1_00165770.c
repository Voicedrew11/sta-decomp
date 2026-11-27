#include "m2c.h"
extern u8 *D_001F2300[];
extern u8 *D_001F1C50[];
extern u8 *D_0033F500[];
extern u8 *D_00201FA4;
void Script_ResetSlot_1_00164F10(void *);

void Script_LoadLocalB_1_00165770(u8 *a0, s32 a1, s32 a2) {
    u16 k;
    u8 *p;
    u32 i;
    u8 *src;
    u8 *q;
    s32 t;
    src = 0;
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
                        Script_ResetSlot_1_00164F10(q + 0x294);
                    }
                    q += 0x258;
                    i++;
                } while (i < *(u32 *)(p + 4));
            }
        }
    } else if (t >= 0x20) {
        src = D_001F2300[t] + a2;
    } else if (t >= 0x10) {
        src = D_001F1C50[t] + a2;
    } else {
        src = D_0033F500[t] + a2;
    }
    switch (k) {
    case 0: *(s32 *)(a0 + 4) = *(s8 *)src; break;
    case 1: *(s32 *)(a0 + 4) = *(u8 *)src; break;
    case 2: *(s32 *)(a0 + 4) = *(s16 *)src; break;
    case 3: *(s32 *)(a0 + 4) = *(u16 *)src; break;
    case 4: *(s32 *)(a0 + 4) = *(s32 *)src; break;
    case 5: *(u32 *)(a0 + 4) = *(u32 *)src; break;
    case 6: *(f32 *)(a0 + 4) = *(f32 *)src; break;
    }
    *(u32 *)a0 = k;
}
