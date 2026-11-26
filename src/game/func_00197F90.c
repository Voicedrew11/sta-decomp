#include "m2c.h"
u8 *func_001AFC90(void);
void memset(void *, s32, s32);
s32 func_00195BE0(s32);
void func_001CC3F0(s16);
s32 func_001A9B40(s16);
extern s32 *D_00201D3C;
extern s32 D_00202198;

void func_00197F90(s32 a0) {
    s32 r;
    u8 *e;
    s32 i;
    u8 *base;
    s32 v;

    base = func_001AFC90();
    D_00202198 = 0;
    memset(D_00201D3C, -1, 4);
    for (i = 100; i < 0x400; i++) {
        func_001CC3F0(func_00195BE0(i));
        e = base + func_00195BE0(i) * 0x90;
        if (*(u16 *)(e + 4) > 0 && (a0 >= 2 || *(u16 *)(e + 0xA) == 2)) {
            if (a0 < 2 || a0 >= 9 || (*(u16 *)(e + 0xA) == 1 && *(u16 *)(e + 0x20) == a0 - 2)) {
                v = func_00195BE0(i);
                if (v < 0) {
                    r = 0;
                } else {
                    r = func_001A9B40(v);
                }
                if (r != 0) {
                    D_00201D3C[D_00202198] = v;
                } else {
                    D_00201D3C[D_00202198] = -1;
                }
                D_00202198++;
            }
        }
    }
}
