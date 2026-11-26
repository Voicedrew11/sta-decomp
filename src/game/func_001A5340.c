#include "m2c.h"
typedef struct { s32 v; s32 pad[9]; } E;
extern s32 D_00201DA8;
extern E D_004A43B0[];
extern E D_004A43B8[];
void func_0014DAB0(s32);
void func_0014DB10(void (*)());
void func_001A4990();
void memset(void *, s32, s32);

void func_001A5340(void) {
    s32 i;

    if (D_00201DA8 != -1 && *(volatile s32 *)&D_004A43B8[D_00201DA8].v != 0) {
        func_0014DAB0(D_004A43B8[D_00201DA8].v);
        D_004A43B8[D_00201DA8].v = 0;
    }
    D_00201DA8 = -1;
    func_0014DB10(func_001A4990);
    memset(D_004A43B0, 0, 0x1B8);
    for (i = 10; i >= 0; i--) {
        D_004A43B0[i].v = -1;
    }
    D_00201DA8 = -1;
}
