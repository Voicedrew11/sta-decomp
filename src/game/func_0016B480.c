#include "common.h"
typedef struct { u8 lo:2; u8 rest:6; u8 pad[3]; } P;
void func_001548F0(s32);
void func_001549D0(s32);
void func_00155900(void);
extern s32 D_00201FF8;
extern s32 D_00201FFC;
extern s32 D_00202000;
extern s32 D_00202004;
s32 func_0016B480(P p, s32 b) {
    s32 t = p.lo + b;
    s32 r = 0;
    if (D_00201FFC != t || D_00202004 != 0 || D_00202000 != 0) {
        D_00201FFC = t;
        func_001549D0(t);
        func_00155900();
        func_001548F0(D_00201FFC);
        r = 1;
        D_00201FF8 = r;
    }
    D_00202000 = 0;
    D_00202004 = 0;
    return r;
}

