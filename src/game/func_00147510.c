#include "common.h"
typedef struct { f32 m[4][4]; } MtxF;
typedef struct { u8 pad[0x170]; s32 *x170; } S90;
typedef struct {
    Vec p;
    u8 pad10[0x50];
    f32 x60;
    u8 pad64[0x2C];
    S90 *x90;
    u16 x94;
    u8 pad96[0x2A];
    MtxF xC0;
} O;
extern Vec D_001F2160;
void sceVu0CopyVector(void *, void *);
void sceVu0ApplyMatrix(void *, void *, void *);
s32 func_001464A0(s32, u8, MtxF *);
static inline s32 cur(O *o) { s32 *p = o->x90->x170; return p ? *p : 0; }

void func_00147510(O *o) {
    Vec v;
    s32 c;
    u8 f = o->x60;
    c = cur(o);
    if (c && func_001464A0(c, f, &o->xC0)) {
        sceVu0CopyVector(&v, (u8 *)o->x90 + o->x94 * 128 + 0x2C0);
        v.w = 1.0f;
        sceVu0ApplyMatrix(o, &o->xC0, &v);
        sceVu0CopyVector(o->xC0.m[3], &D_001F2160);
    }
}
