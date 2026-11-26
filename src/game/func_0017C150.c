#include "common.h"
typedef struct { u8 pad[8]; s32 x8; u8 padC[4]; s32 x10; u8 pad14[0x1C]; f32 f[0x14]; } O;
void *func_001B19A0(s32);
f32 *func_001B7300(void *, s32);

void func_0017C150(O *o) {
    f32 a;
    f32 e;
    f32 g;
    f32 h;
    f32 i;
    f32 j;
    f32 k;
    f32 l;
    f32 b;
    f32 c;
    f32 d;
    f32 *p;
    f32 tb;
    f32 tc;
    f32 td;
    tb = o->f[2];
    tc = o->f[4];
    a = o->f[0];
    e = o->f[8];
    g = o->f[10];
    h = o->f[12];
    i = o->f[14];
    j = o->f[16];
    k = o->f[18];
    l = o->f[20];
    td = o->f[6];
    b = tb / 255.0f;
    c = tc / 255.0f;
    d = td / 255.0f;
    p = func_001B7300(func_001B19A0(o->x8), o->x10);
    if (p) {
        p[3] = a;
        p[4] = b;
        p[5] = c;
        p[6] = d;
        p[7] = e;
        p[8] = g;
        p[9] = h;
        p[10] = i;
        p[11] = j;
        p[12] = k;
        p[13] = l;
    }
}
