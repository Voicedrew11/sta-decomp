#include "m2c.h"
typedef struct { s32 v[12]; } Buf;
typedef struct { u8 b[0xF0]; } Ent;
void func_0018B150(f32, s32 *, s32, s32, void (*)(s8 *), s32);
void func_0018B320(s32 *);
void func_00194D90(s32, s32 *);
void func_001E6080(s32 *);
void func_001E5E80(Buf *);
s32 func_001E6060(void);
s32 func_001E6110(void);
s32 func_001E8290(void);
void func_001E8500(void);
s32 func_001E5F30(s32, s32);
s32 func_001E6170(s32, void *, s32);
s8 *func_00188FF0(s32);
void func_00189ED0(s32);
void func_001AB0A0(Ent *);
void memset(void *, s32, s32);
void func_00194D20(s8 *);
void func_00194C20(s8 *);
extern s32 D_004A1150[];
extern f32 D_004A1168[];
extern s32 D_004A1184[];
extern s32 D_004A1188[];
extern f32 D_004A118C[];
extern s32 D_004A1198[];
extern s32 D_004A119C[];
extern Ent D_004A0900[];

void func_001945B0(s8 *arg0) {
    s32 r = 0;
    Buf buf = {0};
    s32 idx;
    s32 st;
    s32 done;

    idx = func_001E8290();
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
    if (done) return;
    switch (D_004A1188[0]) {
    case 0:
        if (func_001E5F30(0, 0) == 0) {
            func_001AB0A0(&D_004A0900[idx]);
            memset(func_00188FF0(0), 0, 8);
            D_004A1188[0]++;
        }
        break;
    case 1:
        func_001E6080(&r);
        if (r == 0) {
            D_004A1188[0]++;
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
    case 2:
        func_001E5E80(&buf);
        if (!((buf.v[0] != 0) | (buf.v[1] != 0) | (buf.v[2] != 0) | (buf.v[3] != 0) | (buf.v[4] != 0) | (buf.v[5] != 0) |
              (buf.v[6] != 0) | (buf.v[7] != 0) | (buf.v[8] != 0) | (buf.v[9] != 0) | (buf.v[10] != 0)) &&
            func_001E6060() < 0x6F) {
            func_0018B150(0.9f, D_004A1150, idx + 0x85, 2, func_00194C20, 0);
            D_004A1168[0] = -20.0f;
            func_0018B320(D_004A1150);
            D_004A1184[0] = 0;
            D_004A1188[0] = 0;
        } else if (buf.v[3] == 1) {
            if (func_001E6170(-1, &D_004A0900[idx], 0xF0) != -1) {
                D_004A1188[0]++;
            } else {
                D_004A1188[0] = 0;
            }
        } else {
            D_004A1184[0] = 0;
            D_004A1188[0] = 0;
            D_004A118C[0] = 128.0f;
            func_00189ED0(10);
            arg0[8] = 12;
            *(s32 *)(arg0 + 4) = 0;
            *(s32 *)arg0 = 0x1A;
            arg0[0xA] = 2;
        }
        break;
    case 3:
        do {
            func_001E8500();
            func_001E6080(&r);
        } while (r == 2);
        if (r == 0) {
            D_004A1188[0]++;
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
    case 4:
        func_001E5E80(&buf);
        if (buf.v[11] == 1) {
            if (func_001E6170(7, func_00188FF0(0), 8) != -1) {
                D_004A1188[0]++;
            } else {
                D_004A1188[0] = 0;
            }
        } else {
            D_004A1188[0]++;
            D_004A1188[0]++;
        }
        break;
    case 5:
        do {
            func_001E8500();
            func_001E6080(&r);
        } while (r == 2);
        if (r == 0) {
            D_004A1188[0]++;
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
    case 6:
        D_004A1188[0]++;
        D_004A118C[0] = 128.0f;
        D_004A1184[0] = 0;
        func_00189ED0(10);
        arg0[8] = 12;
        *(s32 *)(arg0 + 4) = 0;
        *(s32 *)arg0 = 0x1A;
        arg0[0xA] = 2;
        break;
    case 7:
        if (*(s32 *)arg0 == 0x1E) {
            D_004A1188[0] = 0;
        }
        break;
    }
}
