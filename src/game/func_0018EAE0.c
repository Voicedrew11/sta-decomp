#include "m2c.h"
extern s32 D_004A10D4[];
extern f32 D_004A10D8[];
typedef struct { u8 b0:1; u8 b1:1; u8 r:6; } F;
extern F D_004A10DC[];
extern s32 D_00202130;
typedef struct { u8 b0:1; u8 r:7; } G;
typedef struct { s32 x0; s32 x4; s8 x8; u8 p9[3]; s8 xC; u8 pD[7]; G x14; } O;
void func_0018FFE0(O *);
void func_0018F940(O *);
void func_0018F490(O *);
void func_0018F0D0(O *);
void func_0018EDA0(O *);
void func_0018EC40(O *);
s8 func_00189EA0(void);
void func_0017F7C0(s32, s32, s32);

void func_0018EAE0(O *arg0) {
    func_0018FFE0(arg0);
    if (arg0->x0 == 0x16) {
        switch (D_004A10D4[0]) {
        case 0:
            if (D_00202130 != 0) {
                arg0->xC = 4;
            } else {
                arg0->xC = 0;
            }
            func_0018F940(arg0);
            break;
        case 1:
            arg0->xC = 1;
            func_0018F490(arg0);
            break;
        case 2:
            arg0->xC = 2;
            func_0018F0D0(arg0);
            break;
        case 3:
            arg0->xC = 3;
            func_0018EDA0(arg0);
            break;
        case 4:
            func_0018EC40(arg0);
            break;
        case 5:
            if (!(D_004A10D8[0] <= 12.0f)) {
                if (D_004A10DC[0].b1) {
                    arg0->x14.b0 = 1;
                } else {
                    arg0->x8 = func_00189EA0();
                    arg0->x4 = 0;
                    arg0->x0 = 0x1A;
                }
                func_0017F7C0(0xD, 0, 0);
            }
            break;
        }
    }
}
