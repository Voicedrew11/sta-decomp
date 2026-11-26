#include "common.h"
s16 *func_001C9BA0(void);
void func_001C9FB0(s32);
void func_00169B50(s32, s32, s32, s32);
void func_001452E0(u8 *o) {
    u8 m = o[8];
    s16 *p = func_001C9BA0();
    u8 fl = 0;
    u8 i;
    if (m & 1) { fl |= 1; p[2] = p[0]; }
    if (m & 2) { fl |= 2; p[3] = p[1]; }
    if (fl) func_001C9FB0(0);
    for (i = 0; i < 3; i++) if (fl & (1 << i)) func_00169B50(i + 0x1EA, 0, 1, 0);
}
