#include "m2c.h"
typedef struct { u8 x0; u8 x1; u8 x2; u8 x3; } P;
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[0x14]; u16 x20; u8 pad22[0x6E]; } E;
void memset(void *, s32, s32);
s32 func_00195BE0(s32);
P *func_001CC3F0(s16);
s32 func_0019DE30(s32);
s16 func_001CCD90(s32);
E *func_001AFC90(void);
extern s32 *D_00201D4C;
extern s32 D_002021B4;
extern s32 D_004A28C0[];

void func_0019A1D0(s32 arg0) {
    s32 i;
    E *base;
    P *p;
    E *e;
    s32 v;

    base = func_001AFC90();
    D_002021B4 = 0;
    memset(D_00201D4C, -1, 0x1000);
    for (i = 0; i < 0x400; i++) {
        p = func_001CC3F0(func_00195BE0(i));
        if (!(p->x2 > 0)) {
            if (func_0019DE30(func_00195BE0(i)) == 0) {
                continue;
            }
            if (!(p->x3 > 0)) {
                continue;
            }
        }
        e = &base[func_00195BE0(i)];
        if (arg0 < 2 && e->xA != 2) {
            continue;
        }
        if (!(arg0 < 2) && arg0 < 9) {
            if (e->xA != 1) {
                continue;
            }
            if (e->x20 != arg0 - 2) {
                continue;
            }
        }
        if (arg0 == 9) {
            if (e->xA != 0) {
                continue;
            }
            if (func_00195BE0(i) == 0) {
                continue;
            }
        }
        v = func_00195BE0(i);
        D_00201D4C[D_002021B4] = v;
        if (v == func_001CCD90(arg0)) {
            D_004A28C0[0] = D_002021B4;
        }
        D_002021B4++;
    }
}
