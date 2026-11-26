#include "m2c.h"
typedef struct { u8 pad[0x5B7]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; } A;
s32 func_0013D500(s32);
void func_0013E4F0(A *, s32);

void func_00133FD0(A *arg0, s8 *arg1, u8 *arg2) {
    s32 t;
    t = M2C_FIELD(arg1, s32 *, 0x10) - arg2[0x24];
    if (func_0013D500(0x63) < t) func_0013E4F0(arg0, 1);
    t = M2C_FIELD(arg1, s32 *, 0x18) - arg2[0x25];
    if (func_0013D500(0x63) < t) func_0013E4F0(arg0, 2);
    t = M2C_FIELD(arg1, s32 *, 0x1C) - arg2[0x26];
    if (func_0013D500(0x63) < t) func_0013E4F0(arg0, 4);
    t = M2C_FIELD(arg1, s32 *, 0x24) - arg2[0x27];
    if (func_0013D500(0x63) < t) func_0013E4F0(arg0, 8);
    if (arg2[0x24] < 0x64 && arg0->b2) func_0013E4F0(arg0, 1);
    if (arg2[0x25] < 0x64 && arg0->b3) func_0013E4F0(arg0, 2);
    if (arg2[0x26] < 0x64 && arg0->b4) func_0013E4F0(arg0, 4);
    if (arg2[0x27] < 0x64 && arg0->b5) func_0013E4F0(arg0, 8);
}
