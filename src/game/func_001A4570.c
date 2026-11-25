#include "m2c.h"
typedef struct { s32 pad[4]; s32 f10[7]; s32 pad2[1]; } St;
void func_001E5E80(St *);
s32 func_001E5F30(s32, s32);
void func_001E6080(s32 *);
s32 func_001E6170(s32, s8 *, s32);
s32 func_001E8290(void);
s32 func_001E82A0(s32);
s8 *func_00188FF0(s32);
extern s32 D_0020226C;
extern s32 D_00202268;

s32 func_001A4570(void) {
    s32 r = 0;
    St st = {0};
    s32 s;
    s32 any, i, t;

    switch (D_0020226C) {
    case 0:
        D_0020226C++;
        D_00202268 = 0;
        break;
    case 1:
        if (func_001E82A0(D_00202268) != 0) {
            D_0020226C++;
        } else {
            D_0020226C = 0;
            r = 1;
        }
        break;
    case 2:
        if (func_001E5F30(0, 0) == 0) {
            D_0020226C++;
        } else {
            D_0020226C = 0;
            r = 1;
        }
        break;
    case 3:
        func_001E6080(&s);
        if (s == 2) {
            r = 0;
        } else if (s == 0) {
            func_001E5E80(&st);
            if ((st.f10[0] == 1) | (st.f10[1] == 1) | (st.f10[2] == 1) | (st.f10[3] == 1) | (st.f10[4] == 1) |
                (st.f10[5] == 1) | (st.f10[6] == 1)) {
                D_0020226C = 0;
                r = 2;
            } else {
                if (func_001E8290() == 1) {
                    D_0020226C = 0;
                    r = 1;
                } else {
                    D_0020226C = 1;
                    D_00202268 = 1;
                    r = 0;
                }
            }
        } else {
            if (func_001E8290() == 1) {
                D_0020226C = 0;
                r = 1;
            } else {
                D_0020226C = 1;
                D_00202268 = 1;
                r = 0;
            }
        }
        break;
    case 4:
        if (func_001E6170(7, func_00188FF0(0), 8) != -1) {
            D_0020226C++;
        } else {
            r = 1;
        }
        break;
    case 5:
        func_001E6080(&s);
        if (s == 0) {
            any = 0;
            for (i = 0; i < 7; i++) {
                t = 0;
                if (st.f10[i] == 1 && !(func_00188FF0(0)[i] != 0) != 0) {
                    t = 1;
                }
                any |= t;
            }
            if (any) {
                D_0020226C = 0;
                r = 2;
            } else {
                if (func_001E8290() == 1) {
                    D_0020226C = 0;
                    r = 1;
                } else {
                    D_0020226C = 1;
                    D_00202268 = 1;
                    r = 0;
                }
            }
        }
        if (s == 1) {
            r = 1;
            D_0020226C = 0;
        }
        break;
    }
    return r;
}
