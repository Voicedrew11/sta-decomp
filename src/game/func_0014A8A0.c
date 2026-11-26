#include "common.h"
typedef struct { u8 pad[0x188]; Flags8 x188; } P;
typedef struct {
    Vec x0; u8 pad10[0x40]; Vec x50; f32 x60; f32 x64; f32 x68; u8 pad6C[0x24];
    P *x90; u8 pad94[0x1C]; f32 xB0; u8 padB4[0x60]; Flags8 x114;
} O;
s32 func_001E1050(s32);
void func_001E0D30(f32, s32);
void func_001E0F30(f32, f32, s32, Vec *, Vec *);
void func_00163C80(O *, Mtx *);
void func_00102A60(void *, void *);

void func_0014A8A0(O *o) {
    Vec v;
    Mtx m;
    if (o->x90->x188.f.b2) {
        if ((s32)o->xB0 == -1) {
            o->xB0 = func_001E1050((s32)o->xB0);
        }
    } else {
        if ((s32)o->xB0 != -1) {
            func_001E0D30(o->x68, (s32)o->xB0);
            o->xB0 = -1.0f;
        }
    }
    if ((s32)o->xB0 != -1) {
        if (o->x114.f.b5) {
            func_00163C80(o, &m);
            func_00102A60(&v, &m.m[3]);
        } else {
            func_00102A60(&v, o);
        }
        func_001E0F30(o->x60, o->x64, (s32)o->xB0, &v, &o->x50);
    }
}
