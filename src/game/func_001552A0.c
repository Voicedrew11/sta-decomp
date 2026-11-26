#include "m2c.h"
extern u32 D_002F1990[];
extern u32 D_002F199C[];
extern u32 D_002F19A0[];
extern u32 D_002F19A8[];
extern s32 D_00201C58;
void FlushCache(s32);
void sceGsSyncPath(s32, s32);

void func_001552A0(void) {
    if (D_002F1990[0] != 0) {
        FlushCache(0);
        sceGsSyncPath(0, 0);
        while (*(volatile u32 *)0x10009000 & 0x100) {
        }
        FlushCache(0);
        *(volatile u32 *)0x10009020 = 0;
        *(volatile u32 *)0x10009010 = 0;
        *(volatile u32 *)0x10009030 = D_002F19A8[0] & 0x0FFFFFFF;
        *(volatile u32 *)0x10009000 = 0x145;
        if (*(volatile u32 *)D_002F19A8 == D_002F199C[0]) {
            D_002F19A8[0] = D_002F19A0[0];
        } else {
            D_002F19A8[0] = D_002F199C[0];
        }
        D_00201C58 = 1;
    }
}
