#include "common.h"
s32 func_001E60C0(s32);

void func_0018E120(s32 a0, Flags8 *f) {
    switch (func_001E60C0(a0)) {
    case 0: f->f.b0 = 1; f->f.b1 = 1; f->f.b2 = 1; break;
    case 1: f->f.b0 = 0; f->f.b1 = 0; f->f.b2 = 0; break;
    case 2: f->f.b0 = 1; f->f.b1 = 0; f->f.b2 = 0; break;
    case 3: break;
    }
}
