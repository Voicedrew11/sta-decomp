#include "common.h"
void func_001D9DC0(void);
void func_001D8320(s32, void (*)(void));
s32 func_001D85D0(s32, s32, s32);
void func_001D8210(void);
void *memset(void *, s32, u32);
extern s32 D_00202310;
extern s32 D_00202314;
extern s32 D_00202318;
extern s32 D_004B9F20[];
extern s32 D_004B9F24[];
extern s32 D_004B9F44[];
extern s32 D_004B9F64[];
extern s32 D_004B9F84[];
extern s32 D_004B9FA0[];
extern s16 D_004B9FA8[];
extern s16 D_004B9FAA[];
extern s32 D_004B9FB0[];
extern s32 D_004B9FB4[];
s32 func_001D99A0(void) {
    func_001D8320(3, func_001D9DC0);
    if (func_001D85D0(3, 1, 0x10000) == 0) {
        return 0;
    }
    func_001D8210();
    memset(D_004B9FA0, 0, 0x20);
    memset(D_004B9F20, 0, 0x20);
    D_004B9FA0[0] = 0x40000;
    D_004B9FB0[0] = 0x8000;
    D_004B9FB4[0] = 0x2000;
    D_00202318 = 0;
    D_004B9FA8[0] = 0x3FFF;
    D_00202310 = 0;
    D_004B9FAA[0] = 0x3FFF;
    D_00202314 = 0;
    D_004B9F84[0] = 0x40000;
    D_004B9F64[0] = 0x40000;
    D_004B9F44[0] = 0x40000;
    D_004B9F24[0] = 0x40000;
    return 1;
}
