#include "common.h"
void memset(void *, s32, s32);
extern s32 D_00202278;
extern s32 D_00202280;
typedef struct { u8 pad[0x204]; s16 n; s16 a[0x81]; u8 pad2[2]; } T;
extern T D_004A4570;
void func_001A82B0(s32 arg0, s32 arg1) {
    u16 i; D_00202278 = arg0; D_00202280 = arg1; memset(&D_004A4570, 0, 0x30C); for (i = 0; i < 0x81; i++) D_004A4570.a[i] = i; D_004A4570.n = 0x81;
}
