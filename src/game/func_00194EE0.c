#include "common.h"
typedef struct { char pad[0x14]; unsigned char : 3; unsigned char f : 1; } BF_14_3_1;
extern s32 D_001FD230[];

void func_00194EE0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) == 0) {
        func_00155900();
        func_0017FF70((s32) D_001FD230);
        func_00154700(5, 0);
        func_00155900();
        func_00194FC0();
        func_00154700(5, 0);
        ((BF_14_3_1 *)arg0)->f = 1;
    }
}
