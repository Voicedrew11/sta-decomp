#include "common.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:6; } Bits;
typedef struct {
    Vec p;
    u8 pad10[0x54];
    f32 x64;
    u8 pad68[0x20];
    f32 x88;
    u8 pad8C[0x88];
    Bits f114;
} O;
void sceVu0CopyVector(void *, void *);
s32 func_001470F0(Vec *, Vec *, s32, s32, s32, Vec *);

void func_0014CDC0(O *o) {
    Vec out;
    Vec a;
    Vec b;
    f32 h = o->x64;

    a.x = o->p.x;
    a.y = o->p.y - h;
    a.z = o->p.z;
    b.x = o->p.x;
    b.y = o->p.y + h;
    b.z = o->p.z;
    b.w = 1.0f;
    a.w = 1.0f;
    if (func_001470F0(&a, &b, 3, 4, 1, &out)) {
        sceVu0CopyVector(o, &out);
        return;
    }
    o->x88 = (f32)(u32)(o->f114.b1 = 0);
}
