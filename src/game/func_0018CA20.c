#include "common.h"
typedef struct { u8 pad0[0xA]; u8 xA; } O;
typedef struct { s32 pad[3]; s32 xC; s32 arr[8]; } Buf;
typedef struct { s16 x0; s16 x2; s16 x4; s16 x6; u8 pad8[4]; s16 xC; u8 xE; u8 xF; } R;
typedef struct { u8 pad[0x20]; R r; } S1;
typedef struct { u8 pad[0x50]; R r[1]; } S0;
void func_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void func_0018B320(s32 *);
s32 func_001E6110();
void func_001E8290();
S1 *func_00189000(s32);
s32 func_001E5F30(s32, s32);
void func_001E6080(s32 *);
void func_001E5E80(Buf *);
s32 func_001E6170(s32, void *, s32);
void func_001E8500(void);
void func_0018D000();
void func_0018D060();
void func_0018D140();
extern s32 D_004A0FC0[];
extern s32 D_004A0FF0[];
extern s32 D_004A0FF4[];
extern s32 D_004A0FF8[];
extern s32 D_004A1000[];
extern Flags8 D_004A1010[];
static inline s32 diff(R *a, R *b) {
    if (a->x4 != b->x4 || a->x6 != b->x6 || a->x0 != b->x0 || a->x2 != b->x2 ||
        a->xE != b->xE || a->xC != b->xC || a->xF != b->xF) {
        return 1;
    }
    return 0;
}

void func_0018CA20(O *o) {
    Buf buf = {0};
    S1 *s1;
    S0 *s0;
    s32 st;

    func_001E8290();
    s1 = func_00189000(0);
    s0 = (S0 *)func_00189000(1);
    if (func_001E6110() != 0) {
        func_0018B150(D_004A0FC0, 0x79, 2, func_0018D000, 0, 1.0f);
        func_0018B320(D_004A0FC0);
        o->xA = 1;
        D_004A0FF4[0] = 0;
        D_004A1000[0] = 0;
        D_004A1010[0].f.b0 = 0;
    }
    D_004A1010[0].f.b1 = 0;
    switch (D_004A0FF8[0]) {
    case 0:
        if (!func_001E5F30(0, 0)) {
            D_004A0FF8[0]++;
        }
        break;
    case 1:
        func_001E6080(&st);
        if (st == 0) {
            D_004A0FF8[0]++;
        }
        if (st == 1) {
            func_0018B150(D_004A0FC0, 0x79, 2, func_0018D000, 0, 1.0f);
            func_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A0FF4[0] = 0;
            D_004A1000[0] = 0;
            D_004A1010[0].f.b0 = 0;
        }
        break;
    case 2:
        func_001E5E80(&buf);
        switch (buf.arr[D_004A0FF0[0]]) {
        case 2:
            func_0018B150(D_004A0FC0, 0x6C, 2, func_0018D060, 0, 1.0f);
            func_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A1010[0].f.b0 = 0;
            return;
        case 0:
            break;
        case 1:
            break;
        }
        if (buf.xC == 1) {
            if (!func_001E6170(-1, s0, 0xF0)) {
                D_004A0FF8[0]++;
            }
        } else {
            D_004A0FF8[0]++;
            D_004A0FF8[0]++;
        }
        break;
    case 3:
        do {
            func_001E8500();
            func_001E6080(&st);
        } while (st == 2);
        if (st == 0) {
            D_004A0FF8[0]++;
        }
        if (st == 1) {
            func_0018B150(D_004A0FC0, 0x79, 2, func_0018D000, 0, 1.0f);
            func_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A0FF4[0] = 0;
            D_004A1000[0] = 0;
            D_004A1010[0].f.b0 = 0;
        }
        break;
    case 4:
        if (!func_001E6170(D_004A0FF0[0], s1, 0x7C20)) {
            D_004A0FF8[0]++;
        }
        break;
    case 5:
        do {
            func_001E8500();
            func_001E6080(&st);
        } while (st == 2);
        if (st == 0) {
            if (diff(&s0->r[D_004A0FF0[0]], &s1->r)) {
                func_0018B150(D_004A0FC0, 0x6C, 2, func_0018D060, 0, 1.0f);
                func_0018B320(D_004A0FC0);
                o->xA = 1;
                D_004A1010[0].f.b0 = 0;
            } else {
                func_0018B150(D_004A0FC0, 0x6D, 2, func_0018D140, 0, 1.0f);
                func_0018B320(D_004A0FC0);
                o->xA = 1;
            }
        }
        if (st == 1) {
            func_0018B150(D_004A0FC0, 0x79, 2, func_0018D000, 0, 1.0f);
            func_0018B320(D_004A0FC0);
            o->xA = 1;
            D_004A0FF4[0] = 0;
            D_004A1000[0] = 0;
            D_004A1010[0].f.b0 = 0;
        }
        break;
    }
}
