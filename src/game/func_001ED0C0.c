#include "common.h"
void func_001E9420(u8 *, s32);
void func_001E9AA0(u8 *, s32, s32, s32, s32, s32, s32);
s32 func_001ED070(s32, s32);
void memset(s32 *, s32, s32);
extern s8 D_004BD310[];
extern s8 D_004BD311[];
extern s8 D_004BD312[];
extern s8 D_004BD313[];
extern s32 D_004BD314[];
extern s32 D_004BD318[];
extern s32 D_004BD31C[];
extern u32 D_004BE000[];
extern volatile u32 D_004BE004[];
extern volatile u32 D_004BE008[];
extern s32 D_004BE010[];
extern s32 D_004BE014[];
extern s32 D_004BE018[];
extern s32 D_004BE01C[];
extern s32 D_004BE020[];
extern s32 D_004BE024[];
extern s32 D_004BE028[];
extern s32 D_004BE02C[];
extern s32 D_004BE030[];
extern s32 D_004BE034[];
extern s32 D_004BE038[];
extern u8 D_004BE080[];
extern u32 D_004BE0D0[];
extern s16 D_004BE0D4[];
extern s16 D_004BE0D6[];
extern s16 D_004BE0D8[];

static inline s32 al(u32 size) {
    u8 *p = (u8 *)((*D_004BE004 + 0x3F) & ~0x3F);
    if (*D_004BE008 < (u32)(p + size)) { p = 0; } else { *D_004BE004 = (u32)(p + size); }
    return (s32)p;
}

s32 func_001ED0C0(s32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s16 arg5, s16 arg6, s16 arg7) {
    *D_004BE000 = arg1;
    *D_004BE004 = arg1;
    *D_004BE008 = arg1 + arg2 - 1;
    if ((*D_004BE010 = al(0x800)) == 0) return -1;
    if ((*D_004BE014 = al(0x4000)) == 0) return -1;
    if ((*D_004BE018 = al(0x13C768)) == 0) return -1;
    if ((*D_004BE01C = al(0xC000)) == 0) return -1;
    if ((*D_004BE020 = al(0x40000)) == 0) return -1;
    if ((*D_004BE024 = al(0x810)) == 0) return -1;
    if ((*D_004BE028 = al(0x578000)) == 0) return -1;
    if ((*D_004BE02C = al(0x10AF40)) == 0) return -1;
    if ((*D_004BE030 = al(0x3C00)) == 0) return -1;
    if ((*D_004BE034 = al(0x100)) == 0) return -1;
    if ((*D_004BE038 = al(0x5000C)) == 0) return -1;
    *D_004BE0D8 = arg7;
    *D_004BE0D4 = arg5;
    *D_004BE0D6 = arg6;
    func_001E9AA0(D_004BE080, 0, 0, 0x280, 0x1C0, 0x280, 0x1C0);
    func_001E9420(D_004BE080, 0);
    if (arg4 > 0x3FFF) {
        arg4 = 0x3FFF;
    }
    *D_004BE0D0 = arg4;
    func_001ED070(arg0, arg3);
    func_001E9420(D_004BE080, 0);
    *D_004BD310 = 0;
    *D_004BD311 = 0;
    *D_004BD312 = 0;
    *D_004BD313 = 0;
    *D_004BD314 = 0;
    *D_004BD318 = 0;
    memset(D_004BD31C, 0, 0x28);
    return 0;
}
