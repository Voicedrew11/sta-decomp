#include "common.h"
typedef struct { char pad[0x3C]; unsigned int : 4; unsigned int f : 1; } BF_3C_4_1;
extern s32 *D_00202280;

u8 **func_001A7C70(s32 arg0) {
    u8 *temp_3;
    u8 **temp_2;
    s32 **var_16;

    var_16 = (s32 **) (NULL);
    temp_2 = (u8 **) (func_0016F950(D_00202280, (u8 **) arg0));
    if (temp_2 == NULL) {
        return NULL;
    }
    temp_3 = (u8 *) (*temp_2);
    if (((BF_3C_4_1 *)temp_3)->f != 0) {
        var_16 = (s32 **) (M2C_FIELD(temp_3, s32 ***, 0x10));
    }
    if (var_16 != NULL) {
        func_00178080(var_16);
    }
    return (u8 **) (temp_2);
}
