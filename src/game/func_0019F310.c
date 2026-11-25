#include "m2c.h"
f32 func_0018B110(void);
s32 func_00195B10(s32);
s32 func_0019D510(s32);
void func_00125CE8(s8 *, s32);
void func_001875C0(f32, f32, f32, s32, s32, u32);
extern u16 D_004A3310[];

void func_0019F310(void) {
    s8 buf[0x100] = {0};
    union { u32 w; s8 b[4]; } col;

    col.w = 0x80808080;
    col.b[3] = func_0018B110();
    func_001875C0(320.0f, 150.0f, 1.1f, func_00195B10(0x91), 1, col.w);
    func_001875C0(320.0f, 180.0f, 1.1f, func_0019D510(D_004A3310[0]), 1, col.w);
    func_00125CE8(buf, func_00195B10(0x9D));
    func_001875C0(320.0f, 220.0f, 1.0f, (s32)buf, 1, col.w);
}
