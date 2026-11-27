#include "common.h"
extern u8 D_00201ED4[4];
extern Flags8 D_0022EC40[];
extern s32 D_0022EC44[];
extern s16 D_0022EC48[];
extern s32 D_0022F040[];

s32 Snd_StopStream_1_0012F550(s32 i) {
    Flags8 *f;
    s32 j;
    D_00201ED4[i] = 0;
    f = &D_0022EC40[i];
    if (f->f.b1) {
        D_0022EC44[0] = 1;
        f->f.b1 = 0;
        D_0022F040[i * 4] = 0;
    }
    f->f.b0 = 0;
    f->f.b2 = 0;
    D_0022EC48[0] = 0;
    for (j = 0; j < 4; j++) {
        if (!(D_0022EC40[j].f.b0 != 0) == 0) {
            D_0022EC48[0] = 1;
            break;
        }
    }
    return 0;
}
