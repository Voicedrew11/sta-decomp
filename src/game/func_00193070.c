#include "common.h"
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
} O;
typedef struct { s16 v[8]; } P;
s8 *func_00188FF0(s32);
void func_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void func_0018B320(s32 *);
s32 func_001E5F30(s32, s32);
void func_001E6080(s32 *);
s32 func_001E62A0(s32, void *, s32);
s32 func_001E8290(void);
void func_001E8500(void);
void func_00192E90(O *, s32);
void func_001A8CA0(void);
void func_001A9080(void);
void *func_001A9400(void);
void func_001A94E0(void *);
P *func_001C9BA0(void);
void func_0018B840(s32, s32);
void func_00193780();
void func_001937E0();
extern u8 D_004A0900[][0xF0];
extern u8 D_004A0950[];
extern s32 D_004A10F0[];
extern s32 D_004A1120[];
extern s32 D_004A1124[];
extern s32 D_004A1128[];
extern s32 D_004A1130[];
extern Flags8 D_004A1140[];
static inline void start(O *o, s32 s) {
    if (s == 1) {
        func_0018B150(D_004A10F0, 0x7B, 2, func_00193780, 0, 1.0f);
        func_0018B320(D_004A10F0);
        o->xA = 1;
        D_004A1124[0] = 0;
        D_004A1130[0] = 0;
        D_004A1140[0].f.b0 = 0;
    }
}
static inline void ok(O *o) {
    func_0018B150(D_004A10F0, 0x6F, 2, func_001937E0, 0, 1.0f);
    func_0018B320(D_004A10F0);
    o->xA = 1;
}

void func_00193070(O *o) {
    s32 n;
    s32 s;
    P *src;
    P *dst;
    s32 off;
    u8 *p;

    n = func_001E8290();
    func_00192E90(o, 1);
    D_004A1140[0].f.b1 = 0;
    switch (D_004A1128[0]) {
    case 0:
        if (func_001E5F30(0, 0) == 0) D_004A1128[0]++;
        break;
    case 1:
        func_001E6080(&s);
        if (s == 0) D_004A1128[0]++;
        start(o, s);
        break;
    case 2:
        func_00188FF0(0)[D_004A1120[0]] = 1;
        if (func_001E62A0(7, func_00188FF0(0), 8) == 0) {
            D_004A1128[0]++;
            break;
        }
        ok(o);
        break;
    case 3:
        do {
            func_001E8500();
            func_001E6080(&s);
        } while (s == 2);
        if (s == 0) D_004A1128[0]++;
        start(o, s);
        break;
    case 4:
        func_001A8CA0();
        func_001A9080();
        if (func_001E62A0(D_004A1120[0], func_001A9400(), 0x7C20) == 0) {
            D_004A1128[0]++;
            break;
        }
        ok(o);
        break;
    case 5:
        do {
            func_001E8500();
            func_001E6080(&s);
        } while (s == 2);
        if (s == 0) D_004A1128[0]++;
        start(o, s);
        break;
    case 6:
        off = n * 0xF0;
        p = (u8 *)D_004A0900 + off;
        func_001A94E0(p + 0x20);
        src = func_001C9BA0();
        dst = (P *)(D_004A1120[0] * 16 + ((u8 *)D_004A0950 + off));
        *dst = *src;
        if (func_001E62A0(-1, p, 0xF0) == 0) {
            D_004A1128[0]++;
            break;
        }
        ok(o);
        break;
    case 7:
        do {
            func_001E8500();
            func_001E6080(&s);
        } while (s == 2);
        if (s == 0) D_004A1128[0]++;
        start(o, s);
        break;
    case 8:
        func_00188FF0(0)[D_004A1120[0]] = 0;
        if (func_001E62A0(7, func_00188FF0(0), 8) == 0) {
            D_004A1128[0]++;
            break;
        }
        ok(o);
        break;
    case 9:
        do {
            func_001E8500();
            func_001E6080(&s);
        } while (s == 2);
        if (s == 0) {
            func_0018B150(D_004A10F0, 0x70, 2, func_001937E0, 0, 1.0f);
            func_0018B320(D_004A10F0);
            o->xA = 1;
            func_0018B840(func_001E8290(), D_004A1120[0]);
        }
        start(o, s);
        break;
    }
}
