#include "m2c.h"
#include "actor.h"
M2C_UNK func_00128210(M2C_UNK *);                   /* extern */
M2C_UNK func_00128460(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_00128A60(M2C_UNK *, s32, s32, M2C_UNK); /* extern */
M2C_UNK func_0012B350(s32);                         /* extern */
M2C_UNK func_0012DEE0(M2C_UNK *);                   /* extern */
M2C_UNK func_00189AD0(M2C_UNK *);                   /* extern */
M2C_UNK func_0012B8E0(s32);                         /* static */
M2C_UNK func_0012BC80();                            /* static */
extern s32 D_00201C28;
extern s32 D_00201C30;
extern s32 D_00201E94;
extern s32 D_00201E98;
extern s32 D_00201E9C;
extern M2C_UNK D_00222AF0[];
extern M2C_UNK D_00222B20[];
extern s32 D_00222B5C[];
extern s32 D_00222B68[];
extern s32 D_00222B7C[];
extern s32 D_00222B88[];

void func_0012BF40(void) {
    D_00201E94 = 0;
    func_0012BC80();
    func_001AB280();
    func_00128A60(D_00222B20, D_00222B68[0], D_00222B88[0], 0x100);
    func_00128460(D_00222B20, -1);
    func_00189AD0(D_00222B20);
    func_00128210(D_00222B20);
    func_00128A60(D_00222AF0, D_00222B5C[0], D_00222B7C[0], 0x200);
    func_00128460(D_00222AF0, -1);
    func_0012DEE0(D_00222AF0);
    func_00128210(D_00222AF0);
loop_1:
    if (D_00201E9C == 0) {
        func_0012B8E0(D_00201C28);
    }
    D_00201E98 = 0;
    D_00201E9C = 0;
    func_0012B350(D_00201C30);
    D_00201E98 = 0;
    goto loop_1;
}

extern s32 D_00201EA0;

s32 func_0012C020(void) {
    return D_00201EA0;
}
