#include "m2c.h"
u8 *func_001AFC90(void);
void memset(void *, s32, s32);
s32 func_00195BE0(s32);
u8 *func_001CC3F0(s16);
u8 *func_001A97D0(s16);
extern s32 *D_00201D7C;
extern s32 D_00202224;

void func_001A2C00(s32 a0, s32 a1) {
    u8 *e;
    s32 i;
    u8 *base;
    u8 *c;

    base = func_001AFC90();
    D_00202224 = 0;
    memset(D_00201D7C, -1, 0x1000);
    for (i = 0; i < 0x400; i++) {
        c = func_001CC3F0(func_00195BE0(i));
        switch (a1) {
        case 0:
            if (func_001A97D0(func_00195BE0(i))[5] == 0) {
                continue;
            }
            if ((s32)func_001A97D0(func_00195BE0(i))[2] <= 0) {
                continue;
            }
            break;
        case 1:
            if ((s32)func_001A97D0(func_00195BE0(i))[4] <= 0) {
                continue;
            }
            break;
        case 2:
            if ((s32)c[2] <= 0) {
                continue;
            }
            break;
        }
        e = base + func_00195BE0(i) * 0x90;
        if (a0 >= 2 || *(u16 *)(e + 0xA) == 2) {
            if (a0 < 2 || a0 >= 9 || (*(u16 *)(e + 0xA) == 1 && *(u16 *)(e + 0x20) == a0 - 2)) {
                if (a0 != 9 || *(u16 *)(e + 0xA) == 0) {
                    D_00201D7C[D_00202224] = func_00195BE0(i);
                    D_00202224++;
                }
            }
        }
    }
}
