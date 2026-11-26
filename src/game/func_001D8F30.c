#include "common.h"
void *malloc(u32);
extern s32 D_00202310;
extern s32 D_00202314;
extern s32 D_00202318;
extern s32 D_004B9FA0[];
extern s32 D_004B9FB0[];
extern s32 D_004B9FB4[];

void func_001D8F30(void) {
    if (D_00202318 != 0) return;
    D_00202318 = (s32)malloc(0x8040);
    D_00202310 = (D_00202318 + 0x3F) & ~0x3F;
    D_004B9FA0[0] = 0x40000;
    D_004B9FB0[0] = 0x8000;
    D_004B9FB4[0] = 0x2000;
    D_00202314 = 0x8000;
}
