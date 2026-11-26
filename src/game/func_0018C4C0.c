#include "common.h"
extern Flags8 D_004A1010[];
extern s32 D_004A0FF0[];
extern s32 D_004A1008[];
extern f32 D_0020211C;
extern s32 D_00202120[2];
s32 func_001E8290(void);
void func_0018C590(s32 *);

void func_0018C4C0(s32 *a) {
    switch (a[0]) {
    case 0x19:
        D_0020211C = 0.0f;
        D_004A0FF0[0] = D_00202120[func_001E8290()];
        D_004A1010[0].f.b0 = 1;
        D_004A1008[0] = 0;
        D_0020211C = D_004A0FF0[0] + 1;
        break;
    case 0x16:
        if (D_004A1010[0].f.b0) {
            func_0018C590(a);
            a[1] = 0;
        }
        break;
    }
}
