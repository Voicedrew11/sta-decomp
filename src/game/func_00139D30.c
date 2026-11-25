#include "m2c.h"
typedef struct { u8 pad[8]; u16 h8; u8 pA[4]; u16 hE; } Key;
void func_001D1E80(s32, s32, Key *, s32 *, s32);
void func_001395A0(s32, s32, s32, Key *, s32 *, s32);
void func_00139330(s32, s32, s32, Key *, s32 *, s32);
s32 func_001A5430(s32, s32, s32, Key *, s32 *, s32);
void func_0013EAB0(s32, s32);
void func_0013EAE0(s32, s32);

void func_00139D30(s32 a0, s32 a1, s32 a2, Key *a3, s32 *t0, s32 t1) {
    s32 a;

    switch (a3->h8) {
    case 0:
        if (t1 != 0) {
            func_001D1E80(a0, a2, a3, t0, t1);
        }
        break;
    case 1:
        func_001395A0(a0, a1, a2, a3, t0, t1);
        break;
    case 2:
        func_00139330(a0, a1, a2, a3, t0, t1);
        break;
    case 3:
        a = func_001A5430(a0, a1, a2, a3, t0, t1);
        t0 += a3->hE;
        if (*t0 == 0) {
            func_0013EAB0(a, 1);
        }
        if (*t0 == 1) {
            func_0013EAE0(a, 1);
        }
        break;
    }
}
