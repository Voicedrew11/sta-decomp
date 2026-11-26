#include "common.h"
typedef struct { s32 a, b; } P8;
typedef struct { u8 pad[0x1C]; s32 x1C; u8 pad20[8]; void *x28[4]; P8 x38[3]; P8 x50[3]; } G;
extern G D_004BC2F0;
s32 func_001E1FC8(s32);
s32 func_001E1EE0(s32, s32);
s32 func_001E4030(s32, s32);
void func_001E2018(s32, s32, s32);
void func_001E1EA8(s32);
void func_001E1F28(s32, s32);
void func_001E1E70(s32);
void func_00101120(s32, s32);
void func_001E54E8(void *, P8 *, P8 *);
void func_001E3DD8(void) {
    s32 i;
    s32 a;
    s32 b;
    a = func_001E1FC8(0);
    b = func_001E1EE0(1, 0x100);
    func_001E2018(func_001E4030(a, 1), 1, 0x100);
    func_001E1EA8(1);
    func_001E1F28(func_001E4030(b, 1), b);
    func_001E1E70(D_004BC2F0.x1C);
    func_00101120(0, 0);
    for (i = 0; i < 3; i++) {
        if (D_004BC2F0.x28[i]) {
            func_001E54E8(D_004BC2F0.x28[i], &D_004BC2F0.x38[i], &D_004BC2F0.x50[i]);
        }
    }
}
