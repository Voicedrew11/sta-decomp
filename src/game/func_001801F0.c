#include "m2c.h"
typedef struct { s32 pad[3]; s32 f0C; s32 f10[7]; s32 pad2[1]; } St;
void func_001E5E80(St *);
s32 func_001E5F30(s32, s32);
void func_001E6080(s32 *);
s32 func_001E8290(void);
s32 func_001E82A0(s32);
extern s32 D_0020203C;

s32 func_001801F0(s32 arg0) {
    s32 s;
    St st = {0};
    s32 r;

    r = -1;
    switch (D_0020203C) {
    case 0:
        if (func_001E82A0(arg0) != 0) {
            D_0020203C++;
        } else {
            r = 0;
            break;
        }
    case 1:
        if (func_001E5F30(0, 0) == 0) {
            r = 0;
            D_0020203C++;
        } else {
            D_0020203C = 0;
        }
        break;
    case 2:
        if (arg0 != func_001E8290()) {
            D_0020203C = 0;
            break;
        }
        func_001E6080(&s);
        if (s == 2) {
            r = 0;
        } else if (s == 0) {
            func_001E5E80(&st);
            if (st.f10[0] != 0 || st.f10[1] != 0 || st.f10[2] != 0 || st.f10[3] != 0 || st.f10[4] != 0 ||
                st.f10[5] != 0 || st.f10[6] != 0) {
                r = 2;
            } else {
                r = 1;
            }
            if (st.f0C == 1) {
                r |= 4;
            }
            D_0020203C = 0;
} else {
            D_0020203C = 0;
            r = 0x40000000;
        }
        break;
    default:
        D_0020203C = 0;
        break;
    }
    return r;
}
