#include "common.h"
s8 *func_001C9BA0(void);
s8 *func_001C9B60(void);
s32 func_001C9BF0(void);
void func_00186440(f32, s8 *, s8 *, s8 *, s8 *);
void func_00185B30(s32, s32);
void func_00185510(f32, s8 *);
void func_00185B40(f32, s8 *);
void func_00185390(f32, s32, s32, s32);
void func_0017F5C0(void);
extern s32 D_004A4350[];
void func_001A31E0(f32 f) { s8 *p; s8 *q; s8 *a; s8 *b; func_001C9BA0(); a = func_001C9B60(); b = func_001C9BA0(); if (func_001C9BF0()) { p = a + 0x460; q = a + 0x470; } else { return; } func_00186440(f, p, q, 0, 0); func_00185510(f, b); func_00185B30(0, 0); func_00185B40(f, a); func_0017F5C0(); func_00185390(f, 1, 4, D_004A4350[0]); }

