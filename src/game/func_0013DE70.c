#include "m2c.h"
typedef struct { u8 b:7; u8 flag:1; } BF;
void func_00142090(void *, void *, void *, f32 *, f32 *);

void func_0013DE70(u8 *obj, u16 *in, u16 *out) {
    f32 sx;
    f32 sy;
    u8 flag;
    u8 i;
    f32 one = 1.0f;
    u16 *p, *q;
    flag = ((BF *)(obj + 0x5B3))->flag;
    sx = 1.0f;
    sy = 1.0f;
    func_00142090(obj, NULL, NULL, &sx, &sy);
    for (i = 0; i < 4; i++) {
        u16 *p = &in[i];
        out[i] = (u32)(one * (sx * (f32)(u32)p[0]));
        if (flag) out[i] += p[8];
    }
    for (i = 4; i < 8; i++) {
        u16 *p = &in[i];
        out[i] = (u32)(one * (sy * (f32)(u32)p[0]));
        if (flag) out[i] += p[8];
    }
}
