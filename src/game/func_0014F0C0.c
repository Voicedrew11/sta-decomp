#include "common.h"
s32 func_0014F0C0(void *arg0, void *arg1, void *arg2, f32 fparg0) {
    f32 temp_f4;
    f32 temp_f3;
    f32 temp_f2;
    f32 temp_f1_6;
    f32 temp_f1_5;
    f32 temp_f1_4;
    f32 temp_f1_3;
    f32 temp_f1_2;
    f32 temp_f1;

    temp_f4 = M2C_FIELD(arg0, f32 *, 0);
    temp_f1 = M2C_FIELD(arg2, f32 *, 0);
    if (((temp_f4 + fparg0) < temp_f1) && ((M2C_FIELD(arg1, f32 *, 0) + fparg0) < temp_f1)) {
        return 0;
    }
    temp_f3 = M2C_FIELD(arg0, f32 *, 4);
    temp_f1_2 = M2C_FIELD(arg2, f32 *, 4);
    if (((temp_f3 + fparg0) < temp_f1_2) && ((M2C_FIELD(arg1, f32 *, 4) + fparg0) < temp_f1_2)) {
        return 0;
    }
    temp_f2 = M2C_FIELD(arg0, f32 *, 8);
    temp_f1_3 = M2C_FIELD(arg2, f32 *, 8);
    if (((temp_f2 + fparg0) < temp_f1_3) && ((M2C_FIELD(arg1, f32 *, 8) + fparg0) < temp_f1_3)) {
        return 0;
    }
    temp_f1_4 = M2C_FIELD(arg2, f32 *, 0x10);
    if (!((temp_f4 - fparg0) <= temp_f1_4) && !((M2C_FIELD(arg1, f32 *, 0) - fparg0) <= temp_f1_4)) {
        return 0;
    }
    temp_f1_5 = M2C_FIELD(arg2, f32 *, 0x14);
    if (!((temp_f3 - fparg0) <= temp_f1_5) && !((M2C_FIELD(arg1, f32 *, 4) - fparg0) <= temp_f1_5)) {
        return 0;
    }
    temp_f1_6 = M2C_FIELD(arg2, f32 *, 0x18);
    if (!((temp_f2 - fparg0) <= temp_f1_6) && !((M2C_FIELD(arg1, f32 *, 8) - fparg0) <= temp_f1_6)) {
        return 0;
    }
    return 1;
}
