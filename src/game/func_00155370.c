#include "m2c.h"
extern s32 D_00201C58;
extern u32 D_00201C5C;
extern s32 D_00201F2C;
extern u64 D_002F1490[];
extern u64 D_002F1580[];
extern s8 D_002F1390[];
extern s8 D_002F1160[];
void func_0014DAA0(void);
void func_00101120(s32, s32);
void func_001787A0(void);
s32 sceGsSyncV(s32);
void FlushCache(s32);
void sceGsSwapDBuff(s8 *, s32);

void func_00155370(void) {
    func_0014DAA0();
    if (D_00201C58 == 1) {
        D_00201C58 = 0;
        func_00101120(0, 0);
        while (*(volatile u32 *)0x10009000 & 0x100) {
        }
        func_00101120(0, 0);
        func_001787A0();
        while (sceGsSyncV(0) != 1) {
        }
        D_002F1580[0] = D_002F1490[0] = D_00201C5C;
        FlushCache(0);
        sceGsSwapDBuff(D_002F1390, D_00201F2C);
        FlushCache(0);
        sceGsSwapDBuff(D_002F1160, D_00201F2C);
        D_00201F2C = !(D_00201F2C != 0);
        FlushCache(0);
    }
}
