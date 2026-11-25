#include "common.h"
void func_001AB280();                            /* extern */
extern s32 D_00201C28;
extern s32 D_00201C30;
extern s32 D_00201E94;
extern s32 D_00201E98;
extern s32 D_00201E9C;
extern s32 D_00222AF0[];
extern s32 D_00222B20[];
extern void *D_00222B5C[];
extern void *D_00222B68[];
extern s32 D_00222B7C[];
extern s32 D_00222B88[];

void func_0012BF40(void) {
    D_00201E94 = 0;
    func_0012BC80();
    func_001AB280();
    func_00128A60(D_00222B20, (*D_00222B68), (*D_00222B88), 0x100);
    func_00128460(D_00222B20, -1U);
    func_00189AD0((s32) D_00222B20);
    func_00128210(D_00222B20);
    func_00128A60(D_00222AF0, (*D_00222B5C), (*D_00222B7C), 0x200);
    func_00128460(D_00222AF0, -1U);
    func_0012DEE0((s32) D_00222AF0);
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
