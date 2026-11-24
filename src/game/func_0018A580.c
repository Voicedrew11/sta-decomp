#include "m2c.h"
typedef struct { u8 b[4]; } Buf;
extern M2C_UNK D_001F27B0[];
extern M2C_UNK D_001F27C0[];
void func_00182080(f32, s32, void *, void *, void *, s32);
void func_00181420(void);

void func_0018A580(s32 arg0, f32 *arg1, f32 min, f32 max, f32 step) {
    f32 v = *arg1; Buf s = {0};
    if (arg0 != 0) {
        v += step;
        if (v > max) v = max;
    } else {
        v -= step;
        if (v < min) v = min;
    }
    s.b[3] = (s32)v;
    *arg1 = v;
    if (s.b[3] > 0) {
        func_00182080(0.0f, 0, D_001F27B0, D_001F27C0, &s, 0);
        func_00181420();
    }
}
