#include "common.h"
extern s32 D_00201F28;
extern  s32 D_002F1948[];
extern  s32 D_002F194C[];
extern s32 D_002F1950[];
extern s32 D_002F1994[];
extern  s32 D_002F19A8[];
void func_001549D0(void);
void func_00164320(void);
void func_00155900(void) {
    s32 d; s32 q;
    if (D_002F1994[0] != 0) {
        func_001549D0();
    }
D_002F1948[0]--; D_002F194C[0] = D_002F1950[D_002F1948[0]];
    d = D_002F194C[0] - D_002F19A8[0]; q = d / 32; if ((u32)q < 0x660) { D_00201F28 = 1; } else { D_00201F28 = 0; }
    func_00164320();
}
