#include "m2c.h"
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 xB;
} Obj;
typedef struct {
    u8 pad0[0xC];
    s32 xC;
    s32 arr[8];
} Buf;
s8 *func_00188FF0(s32);
void func_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void func_0018B320(s32 *);
void func_001E5E80(Buf *);
s32 func_001E5F30(s32, s32);
void func_001E6080(s32 *);
s32 func_001E6110(void);
s32 func_001E6170(s32, void *, s32);
s32 func_001E8290(void);
void func_001E8500(void);
void func_0018E120(s32, void *);
void func_001AB0A0(void *);
void func_00123C40(void *, s32, s32);
void func_00189ED0(s32);
void func_0018E0B0();
void func_0018DFB0();
extern u8 D_004A0900[][0xF0];
extern s32 D_004A1020[];
extern s32 D_004A1054[];
extern s32 D_004A1058[];
extern f32 D_004A105C[];
extern s32 D_004A1068[];
extern s32 D_004A106C[];
static inline s32 start(Obj *o, s32 r) {
    if (r == 1) {
        func_0018B150(D_004A1020, 0x79, 2, func_0018E0B0, 0, 1.0f);
        func_0018B320(D_004A1020);
        o->xA = 1;
        o->xB = 1;
        D_004A1054[0] = 0;
        D_004A1058[0] = 0;
        return 1;
    }
    return 0;
}

void func_0018DA20(Obj *o) {
    s32 s = 0;
    Buf buf = {0};
    s32 n;
    s32 r;

    n = func_001E8290();
    r = func_001E6110();
    func_0018E120(0, D_004A1068);
    func_0018E120(1, D_004A106C);
    if (start(o, r)) return;
    switch (D_004A1058[0]) {
    case 0:
        if (func_001E5F30(0, 0) == 0) {
            func_001AB0A0(D_004A0900[n]);
            func_00123C40(func_00188FF0(0), 0, 8);
            D_004A1058[0]++;
        }
        break;
    case 1:
        func_001E6080(&s);
        if (s == 0) D_004A1058[0]++;
        start(o, s);
        break;
    case 2:
        func_001E5E80(&buf);
        if ((buf.arr[0] == 1) | (buf.arr[1] == 1) | (buf.arr[2] == 1) | (buf.arr[3] == 1) | (buf.arr[4] == 1) |
            (buf.arr[5] == 1) | (buf.arr[6] == 1)) {
            if (buf.xC == 1) {
                if (func_001E6170(-1, D_004A0900[n], 0xF0) != -1) D_004A1058[0]++;
            } else {
                D_004A1054[0] = 0;
                D_004A1058[0] = 0;
                D_004A105C[0] = 128.0f;
                func_00189ED0(9);
                o->x8 = 0xB;
                o->x4 = 0;
                o->x0 = 0x1A;
                o->xA = 2;
            }
        } else {
            func_0018B150(D_004A1020, 0x78, 2, func_0018DFB0, 0, 1.0f);
            func_0018B320(D_004A1020);
            D_004A1054[0] = 0;
            D_004A1058[0] = 0;
        }
        break;
    case 3:
        do {
            func_001E8500();
            func_001E6080(&s);
        } while (s == 2);
        if (s == 0) D_004A1058[0]++;
        start(o, s);
        break;
    case 4:
        func_001E5E80(&buf);
        if (buf.arr[7] == 1) {
            if (func_001E6170(7, func_00188FF0(0), 0xF0) != -1) {
                D_004A1058[0]++;
            } else {
                D_004A1058[0] = 0;
            }
        } else {
            D_004A1058[0]++;
            D_004A1058[0]++;
        }
        break;
    case 5:
        do {
            func_001E8500();
            func_001E6080(&s);
        } while (s == 2);
        if (s == 0) D_004A1058[0]++;
        start(o, s);
        break;
    case 6:
        D_004A1058[0]++;
        D_004A105C[0] = 128.0f;
        D_004A1054[0] = 0;
        func_00189ED0(9);
        o->x8 = 0xB;
        o->x4 = 0;
        o->x0 = 0x1A;
        o->xA = 2;
        break;
    case 7:
        if (o->x0 == 0x1E) D_004A1058[0] = 0;
        break;
    }
}
