#include "common.h"
typedef struct { u8 pad[0xA]; u16 xA; u8 pc[0x1D]; u8 x29; u8 p2a[0x66]; } E;
typedef struct { u8 pad[2]; u8 x2; u8 x3; } C;
E *func_001AFC90(void);
void func_00123C40(void *, s32, s32);
s32 func_00195BE0(s32);
C *func_001CC3F0(s16);
extern s32 *D_00201D68;
extern s32 D_002021F8;
static inline s32 is5(s32 id) {
    E *e = &func_001AFC90()[id];
    if (e->xA == 0 && e->x29 == 5) return 1;
    return 0;
}

void func_0019DCF0(void) {
    s32 i;
    E *t;
    C *c;
    t = func_001AFC90();
    D_002021F8 = 0;
    func_00123C40(D_00201D68, -1, 0x1000);
    for (i = 0; i < 0x400; i++) {
        c = func_001CC3F0(func_00195BE0(i));
        if (c->x2 > 0 || (is5(func_00195BE0(i)) && c->x3 > 0)) {
            if (t[func_00195BE0(i)].xA == 0) {
                D_00201D68[D_002021F8] = func_00195BE0(i);
                D_002021F8++;
            }
        }
    }
}
