#include "common.h"
void func_0017F840(s32, s32 *);
extern f32 *D_00201D24;
extern s32 D_00202154;
void func_00195D80(s32 i, f32 *a1, f32 *a2) { s32 sp; f32 f; func_0017F840(3, &sp);  if (i >= D_00202154 - 3 && i <= D_00202154 + 3) { f = a2[2] - (f32)i; D_00201D24[i] = f; a1[5] = f; return; } D_00201D24[i] = -5.0f; a1[5] = -5.0f; }

