#include "m2c.h"
typedef union { u128 q; u32 w[4]; } Q;
void func_001323C0(s8 *, u16, u16, s8 *);
u128 *func_00154A80(s32);
void func_00154A70(void);
void func_00176AE0(void);
extern u16 D_00201F04;
extern u16 D_00201F08;
extern s8 D_33C0[];

void func_00132A70(s8 *arg0) {
    Q a;
    Q b;
    s8 *e = *(s8 **)(arg0 + 0xC);
    s32 off;
    u128 *p;

    if (*(u16 *)(*(s8 **)arg0 + 0x1E) != 0) {
        b.q = 0;
        b.w[0] = 0x10000000;
        b.w[3] = 0x10000000;
        b.w[2] = ((u32)D_33C0 >> 3) | 0x15000000;
        while (*(s32 *)(e + 4) != 0) {
            off = *(s32 *)(arg0 + 0x28);
            p = func_00154A80(1);
            a.q = 0;
            a.w[0] = *(u32 *)e | 0x30000000;
            a.w[1] = (u32)(e + 0x10) + off;
            *p = a.q;
            func_00154A70();
            func_00176AE0();
            func_001323C0(e, D_00201F04, D_00201F08, arg0);
            *func_00154A80(1) = b.q;
            func_00154A70();
            func_00176AE0();
            if (*(s32 *)(e + 8) == 0) {
                break;
            }
            e += *(s32 *)(e + 8);
        }
    }
}
