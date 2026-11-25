#include "common.h"
extern f32 D_004A0B10[];
extern f32 D_004A0B14[];
extern f32 D_004A0B18[];
extern f32 D_004A0B1C[];

void func_00189F00(void *arg0) {
    (*D_004A0B10) = M2C_FIELD(arg0, f32 *, 0);
    (*D_004A0B14) = M2C_FIELD(arg0, f32 *, 4);
    (*D_004A0B18) = M2C_FIELD(arg0, f32 *, 8);
    (*D_004A0B1C) = M2C_FIELD(arg0, f32 *, 0xC);
}
