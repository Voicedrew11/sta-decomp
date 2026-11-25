#include "common.h"
extern s32 D_00201CF0;
extern s8 D_004A0B2F[];

void func_0018A330(s8 arg0) {
    if (D_00201CF0 == 0x12) {
        (*D_004A0B2F) = arg0;
    }
}
