#include "common.h"
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 padB[3];
    u8 xE;
} O;
typedef struct {
    s32 a[4];
    s32 arr[8];
} Buf;
s8 *func_00188FF0(s32);
u8 func_00189EA0(void);
void func_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void func_0018B320(s32 *);
void func_001E5E80(Buf *);
s32 func_001E6060();
void func_00131600(s32, u8);
void func_00192E90(O *, s32);
void func_00192F70();
void func_001937E0();
extern s32 D_004A10F0[];
extern s32 D_004A1120[];
extern s32 D_004A112C[];
extern f32 D_004A113C[];
extern Flags8 D_004A1140[];

void func_001929C0(O *o) {
    Buf buf = {0};
    s32 fl;
    s32 c;
    s32 k;

    func_00192E90(o, 0);
    D_004A1140[0].f.b1 = 1;
    fl = o->x4;
    if (fl & 0x10) {
        D_004A1120[0]--;
        func_00131600(0x66, o->xE);
        if (D_004A1120[0] < 0) {
            D_004A113C[0] = 10.0f;
            D_004A112C[0] = 1;
            D_004A1140[0].f.b0 = 0;
        }
    } else if (fl & 0x40) {
        D_004A1120[0]++;
        func_00131600(0x66, o->xE);
        if (D_004A1120[0] > 6) {
            D_004A113C[0] = 10.0f;
            D_004A112C[0] = 3;
            D_004A1140[0].f.b0 = 0;
        }
    } else if (fl & 0x2000) {
        func_00131600(0x67, o->xE);
        func_001E5E80(&buf);
        switch (buf.arr[D_004A1120[0]]) {
        case 2:
            if ((buf.a[0] == 1) & (buf.a[1] == 1) & (buf.a[2] == 1) & (buf.a[3] == 1)) {
                c = (u32)func_001E6060() < 0x24;
                k = 0x89;
            } else {
                c = func_001E6060() < 0x6F;
                k = 0x7C;
            }
            if (c) {
                func_0018B150(D_004A10F0, k, 2, func_001937E0, 0, 1.0f);
                func_0018B320(D_004A10F0);
                o->xA = 1;
                D_004A1140[0].f.b0 = 0;
                break;
            }
        case 1:
            func_0018B150(D_004A10F0, 0x72, 3, func_00192F70, 0, 1.0f);
            func_0018B320(D_004A10F0);
            o->xA = 1;
            D_004A1140[0].f.b0 = 0;
            break;
        case 0:
            if ((buf.a[0] == 1) & (buf.a[1] == 1) & (buf.a[2] == 1) & (buf.a[3] == 1)) {
                c = (u32)func_001E6060() < 0x24;
                k = 0x89;
            } else {
                c = func_001E6060() < 0x6F;
                k = 0x7C;
            }
            if (c) {
                func_0018B150(D_004A10F0, k, 2, func_001937E0, 0, 0.9f);
                func_0018B320(D_004A10F0);
                o->xA = 1;
                D_004A1140[0].f.b0 = 0;
            } else if (func_00188FF0(0)[D_004A1120[0]]) {
                func_0018B150(D_004A10F0, 0x72, 3, func_00192F70, 0, 1.0f);
                func_0018B320(D_004A10F0);
                o->xA = 1;
                D_004A1140[0].f.b0 = 0;
            } else {
                func_0018B150(D_004A10F0, 0x73, 3, func_00192F70, 0, 1.0f);
                func_0018B320(D_004A10F0);
                o->xA = 1;
                D_004A1140[0].f.b0 = 0;
            }
            break;
        }
    } else if (fl & 0x4000) {
        o->x8 = func_00189EA0();
        o->x4 = 0;
        o->x0 = 0x1A;
        func_00131600(0x69, o->xE);
    }
}
