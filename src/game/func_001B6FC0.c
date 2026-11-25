#include "common.h"
typedef struct { char pad[0x3C]; unsigned int : 4; unsigned int f : 1; } BF_3C_4_1;
void sceVu0CopyVector(u8 *, s32 *);          /* extern */
extern s32 *D_002022D0;
extern s32 D_003139A0[];

void func_001B6FC0(u8 **arg0) {
    u8 *temp_3;
    u8 *temp_17;
    u8 **temp_2;
    s32 **temp_4;

    temp_17 = (u8 *) (*arg0);
    temp_2 = (u8 **) (func_0016F950(D_002022D0, M2C_FIELD(temp_17, u8 ***, 0x24)));
    M2C_FIELD(temp_17, u8 ***, 4) = temp_2;
    sceVu0CopyVector(temp_17 + 0x10, D_003139A0);
    temp_3 = (u8 *) (*temp_2);
    if (((BF_3C_4_1 *)temp_3)->f != 0) {
        temp_4 = (s32 **) (M2C_FIELD(temp_3, s32 ***, 0x10));
        if (temp_4 != NULL) {
            func_00178080(temp_4);
        }
    }
    func_00170F40(temp_2);
}
