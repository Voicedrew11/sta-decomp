#include "m2c.h"
typedef struct {
    f32 p[2][2][4];
    f32 c[4];
    union { s32 w; struct { u8 b0:1; u8 b1:1; u8 k:6; } f; } x50;
    f32 x54;
    f32 x58;
    s32 x5C;
} Obj;
void sceVu0CopyVector(f32 *, f32 *);
void memset(void *, s32, s32);
extern s32 D_0030D184[];
extern s32 D_0030D188[];
extern u16 D_0030D588[];
extern u16 D_0030D58A[];
extern Obj D_0030D9A0[];

s32 func_0015DBF0(s32 kind, f32 *a, f32 *b, f32 r, f32 h) {
    f32 v80[4];
    f32 v70[4];
    Obj *o;
    s32 i;
    s32 idx;
    u16 *cnt;

    idx = D_0030D188[--D_0030D184[0]];
    o = &D_0030D9A0[idx];
    memset(o, 0, 0x60);
    sceVu0CopyVector(v80, a);
    sceVu0CopyVector(v70, b);
    v70[3] = h;
    v80[3] = -1.0f / (r * r);
    o->x54 = r;
    o->x58 = h;
    o->x50.w = 0;
    o->x50.f.b0 = 1;
    o->x50.f.k = kind;
    cnt = &D_0030D588[kind * 0x41];
    D_0030D58A[kind * 0x41 + (*cnt)++] = idx;
    for (i = 0; i < 2; i++) {
        sceVu0CopyVector(o->p[i][0], v80);
        sceVu0CopyVector(o->p[i][1], v70);
    }
    sceVu0CopyVector(o->c, v80);
    return idx;
}
