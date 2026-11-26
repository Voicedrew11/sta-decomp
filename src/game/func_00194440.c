#include "m2c.h"
void func_0018B150(f32, s32 *, s32, s32, void (*)(s8 *), s32);
void func_0018B320(s32 *);
void func_00194D90(s32, s32 *);
void func_001E6080(s32 *);
s32 func_001E6410(s32);
void func_00194150(s8 *);
void func_00194D20(s8 *);
void func_001942E0(s8 *);
s32 func_001E6110(void);
void func_00131600(s32, s32);
extern s32 D_004A1150[];
extern s32 D_004A1184[];
extern s32 D_004A1188[];
extern s32 D_004A1198[];
extern s32 D_004A119C[];

void func_00194440(s8 *arg0) {
    s32 st;
    s32 done;
    s32 b;

    func_00194D90(0, D_004A1198);
    func_00194D90(1, D_004A119C);
    st = func_001E6110();
    func_00194D90(0, D_004A1198);
    func_00194D90(1, D_004A119C);
    if (st == 1) {
        func_0018B150(1.0f, D_004A1150, 0x79, 2, func_00194D20, 0);
        func_0018B320(D_004A1150);
        arg0[0xA] = 1;
        arg0[0xB] = 1;
        D_004A1184[0] = 0;
        D_004A1188[0] = 0;
        done = 1;
    } else {
        done = 0;
    }
    if (done == 0) {
        b = *(s32 *)(arg0 + 4);
        if (b & 0x2000) {
            func_0018B150(1.0f, D_004A1150, 0x75, 0, func_001942E0, 0);
            func_0018B320(D_004A1150);
            arg0[0xA] = 1;
            arg0[0xB] = 1;
            func_00131600(0x67, *(u8 *)(arg0 + 0xE));
        } else if (b & 0x4000) {
            arg0[0xA] = 2;
            func_00131600(0x68, *(u8 *)(arg0 + 0xE));
        }
    }
}
