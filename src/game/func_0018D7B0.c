#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 r:6; u8 pad[3]; } E;
typedef struct { s32 sel; s32 x4; s32 x8; f32 xC; s32 x10; s32 x14; E e[2]; } M;
extern M D_004A1050;
extern s32 D_004A1020[];
void func_0018B150(s32 *, s32, s32, void (*)(s8 *), s32, f32);
void func_0018B320(s32 *);
void func_00131600(s32, s32);
s32 func_001E82A0(s32);
s8 func_00189EA0(void);
void func_0018DA20(s8 *);
void func_0018DFB0(s8 *);
void func_0018E0B0(s8 *);

void func_0018D7B0(s8 *arg0) {
    s32 b;

    b = *(s32 *)(arg0 + 4);
    if (b & 0x80) {
        D_004A1050.sel--;
        if (D_004A1050.sel < 0) {
            D_004A1050.sel = 1;
        }
        D_004A1050.x10 = 0;
        func_00131600(0x66, *(u8 *)(arg0 + 0xE));
    } else if (b & 0x20) {
        D_004A1050.sel++;
        if (D_004A1050.sel > 1) {
            D_004A1050.sel = 0;
        }
        D_004A1050.x10 = 0;
        func_00131600(0x66, *(u8 *)(arg0 + 0xE));
    } else if (b & 0x2000) {
        if (D_004A1050.e[D_004A1050.sel].b0) {
            func_001E82A0(D_004A1050.sel);
            if (D_004A1050.e[D_004A1050.sel].b1) {
                func_0018B150(D_004A1020, 0x7A, 0, func_0018DA20, 0, 1.0f);
                func_0018B320(D_004A1020);
                D_004A1050.x8 = 0;
                arg0[0xA] = 1;
                arg0[0xB] = 1;
            } else {
                func_0018B150(D_004A1020, 0x78, 2, func_0018DFB0, 0, 1.0f);
                func_0018B320(D_004A1020);
                D_004A1050.x8 = 0;
                arg0[0xA] = 1;
                arg0[0xB] = 1;
            }
        } else {
            func_0018B150(D_004A1020, D_004A1050.sel + 0x81, 2, func_0018E0B0, 0, 1.0f);
            func_0018B320(D_004A1020);
            arg0[0xA] = 1;
            arg0[0xB] = 1;
        }
        func_00131600(0x67, *(u8 *)(arg0 + 0xE));
    } else if (b & 0x4000) {
        D_004A1050.xC = 128.0f;
        arg0[8] = func_00189EA0();
        *(s32 *)(arg0 + 4) = 0;
        *(s32 *)(arg0 + 0) = 0x1A;
        func_00131600(0x69, *(u8 *)(arg0 + 0xE));
    }
    *(s32 *)(arg0 + 4) = 0;
}
