#include "m2c.h"
extern s32 D_00201F28;
extern s32 D_002F1948[];
extern volatile s32 D_002F194C[];
extern s32 D_002F1950[];
extern s32 D_002F1994[];
extern volatile s32 D_002F19A8[];
void func_001549D0(void);
static inline s32 used(void) { return (D_002F194C[0] - D_002F19A8[0]) / 32; }

void func_001559C0(s32 a) {
    s32 d; s32 q; u32 u;
    if (D_002F1994[0] != 0) {
        func_001549D0();
    }
    d = a * 32; D_002F194C[0] = D_002F19A8[0] + d;
    D_002F1950[D_002F1948[0]] = D_002F194C[0];
    D_002F1948[0]++;
    d = D_002F194C[0] - D_002F19A8[0]; q = d / 32; if ((u32)q < 0x660) { D_00201F28 = 1; } else { D_00201F28 = 0; }
}
