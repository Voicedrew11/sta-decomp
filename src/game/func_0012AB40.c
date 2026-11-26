#include "m2c.h"
void func_00128210(M2C_UNK *);
void func_00128460(M2C_UNK *, M2C_UNK);
void func_00153B50(M2C_UNK);
void func_00154B70();
void func_001552A0();
void func_00155370();
void func_00169780();
void func_00169790();
void func_00154AF0();
extern M2C_UNK D_00222AF0[];
extern M2C_UNK D_00222B20[];

void func_0012AB40(s32 arg0) {
    s32 i;

    for (i = 0; i < arg0; i++) {
        func_00155370();
        func_00128210(D_00222AF0);
        func_00128210(D_00222B20);
        func_00169780();
        func_001552A0();
        func_00128460(D_00222AF0, -1);
        func_00128460(D_00222B20, -1);
        func_00169790();
        func_00154B70();
        func_00153B50(0x80000000);
        func_00154AF0();
    }
}
