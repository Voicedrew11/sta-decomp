#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; } F;
s32 func_001E60C0(s32);

void func_00194D90(s32 a, F *f) {
    switch (func_001E60C0(a)) {
    case 0:
        f->b0 = 1; f->b1 = 1; f->b2 = 1;
        break;
    case 1:
        f->b0 = 0; f->b1 = 0; f->b2 = 0;
        break;
    case 2:
        f->b0 = 1; f->b1 = 0; f->b2 = 0;
        break;
    case 3:
        break;
    }
}
