#include "common.h"
void func_00159DD0(s32, s32, s32 *, s32 *);
void func_00189D50(s32, s32 *, s32);
extern s32 D_002020DC;
extern s32 D_0049F8A0[];
extern s32 D_0049FFD0[];
extern s32 D_004A01D4[];
extern u32 D_004A01D8[];
extern s32 D_004A01DC[];
void func_001891C0(void) {
    u32 i;
    s32 *pl;
    s32 *g;
    s32 a;
    s32 b;
    a = 0;
    b = 0;
    func_00159DD0(0x45E87010, D_002020DC, &a, &b);
    i = 0;
    if (i < D_004A01D8[0]) {
        pl = D_0049F8A0;
        g = D_0049FFD0;
        do {
            func_00189D50(pl[0x1BC], g, a);
            i++;
            pl++;
        } while (i < D_004A01D8[0]);
    }
    D_004A01D4[0] = a;
    D_004A01DC[0] = b;
}
