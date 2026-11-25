#include "m2c.h"
void func_0018B150(f32, s32 *, s32, s32, void (*)(s8 *), s32);
void func_0018B320(s32 *);
void func_00194D90(s32, s32 *);
void func_001E6080(s32 *);
s32 func_001E6410(s32);
void func_00194150(s8 *);
void func_00194D20(s8 *);
extern s32 D_004A1150[];
extern s32 D_004A1184[];
extern s32 D_004A1188[];
extern s32 D_004A1198[];
extern s32 D_004A119C[];

void func_001942E0(s8 *arg0) {
    s32 r = 0;

    func_00194D90(0, D_004A1198);
    func_00194D90(1, D_004A119C);
    switch (D_004A1188[0]) {
    case 0:
        D_004A1188[0]++;
        break;
    case 1:
        if (func_001E6410(D_004A1188[0]) != -1) {
            D_004A1188[0]++;
        }
        break;
    case 2:
        func_001E6080(&r);
        if (r == 0) {
            func_0018B150(1.0f, D_004A1150, 0x74, 2, func_00194150, 0);
            func_0018B320(D_004A1150);
            D_004A1184[0] = 0;
            D_004A1188[0] = 0;
        }
        if (r == 1) {
            func_0018B150(1.0f, D_004A1150, 0x79, 2, func_00194D20, 0);
            func_0018B320(D_004A1150);
            arg0[0xA] = 1;
            arg0[0xB] = 1;
            D_004A1184[0] = 0;
            D_004A1188[0] = 0;
        }
        break;
    }
}
