#include "m2c.h"
typedef struct { s16 x0; s16 x2; s16 x4; s16 x6; } S9BA0;
void func_001C88E0(s32, s32, s32);
void func_001CEAA0(s32);
s32 func_001CD450(s32, u8 *, s32, s32);
S9BA0 *func_001C9BA0(void);
extern u32 D_00201E94;

void func_001CD6C0(void) {
    u8 c;
    S9BA0 *p;

    if (func_001CD450(8, &c, 0, 0) && c && D_00201E94 % c == 0) {
        func_001CEAA0(1);
    }
    if (func_001CD450(9, &c, 0, 0) && c && D_00201E94 % c == 0) {
        func_001CEAA0(-1);
    }
    if (func_001CD450(0xB, &c, 0, 0) && c && D_00201E94 % c == 0) {
        p = func_001C9BA0();
        p->x6++;
        if (p->x6 < 0) {
            p->x6 = 0;
        }
        if (p->x2 < p->x6) {
            p->x6 = p->x2;
        }
    }
    if (func_001CD450(0xC, &c, 0, 0) && c && D_00201E94 % c == 0) {
        p = func_001C9BA0();
        p->x6--;
        if (p->x6 < 0) {
            p->x6 = 0;
        }
        if (p->x2 < p->x6) {
            p->x6 = p->x2;
        }
    }
    if (func_001CD450(1, NULL, 0, 1)) func_001C88E0(0, 1, 0);
    if (func_001CD450(2, NULL, 0, 1)) func_001C88E0(1, 1, 0);
    if (func_001CD450(3, NULL, 0, 1)) func_001C88E0(2, 1, 0);
    if (func_001CD450(4, NULL, 0, 1)) func_001C88E0(4, 1, 0);
    if (func_001CD450(5, NULL, 0, 1)) func_001C88E0(3, 1, 0);
    if (func_001CD450(6, NULL, 0, 1)) func_001C88E0(5, 1, 0);
}
