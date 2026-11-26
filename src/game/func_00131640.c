#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct {
    s8 on; s8 idx; s8 x2; s8 x3;
    s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF;
    Vec v;
    s32 x20; f32 x24; f32 x28; f32 x2C; s32 x30; s32 *x34; s32 x38; s16 x3C; s16 x3E;
    s32 x40; s32 x44; u8 p48[0x18]; s32 x60; s32 x64; s32 x68; s8 x6C; u8 p6D[0x13];
} Snd;
typedef struct { s8 a; s8 b; s8 c; s8 lo:2; s8 hi:6; } E;
extern Snd *D_00201ED0;
extern s32 D_00201EE8;
extern f32 D_00201EC0;
extern f32 D_00201EC4;
extern E D_00222BC0[];
extern Snd D_0022CBC0[];
extern s8 D_0022EBC8[];
extern Vec D_002F16C0;
s32 func_0012C400(s8);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void FlushCache(s32);
s32 func_001DA620(s32, s8, u8, u8, u8);
f32 sqrtf(f32);

s32 func_00131640(void) {
    E *e;
    Snd *s;
    s32 i;
    s32 id;
    s32 st;
    Vec b;
    Vec a;

    s = 0;
    id = D_00201ED0->x30;
    if (id < 0 || id >= 0x2800) return -1;
    e = &D_00222BC0[id];
    if (!func_0012C400(e->c)) return -1;
    st = D_00201EE8;
    for (i = st; i < 0x3F; i++) {
        if (D_0022CBC0[i].on == 0) {
            s = &D_0022CBC0[i];
            break;
        }
    }
    if (s == 0) {
        for (i = 0; i < st; i++) {
            if (D_0022CBC0[i].on == 0) {
                s = &D_0022CBC0[i];
                break;
            }
        }
    }
    D_00201EE8 = (st + 1) % 0x3F;
    if (s == 0) return -1;
    if (i == 0x3F) return -1;
    s->idx = i;
    s->x30 = D_00201ED0->x30;
    sceVu0CopyVector(&s->v, &D_00201ED0->v);
    s->x20 = D_00201ED0->x20;
    s->x34 = D_00201ED0->x34;
    s->x38 = D_00201ED0->x38;
    s->xE = D_00201ED0->xE;
    s->xA = D_00201ED0->xA;
    s->x8 = D_00201ED0->x8;
    s->xC = -0x100;
    s->x24 = D_00201EC4;
    s->x28 = D_00201EC0;
    s->x4 = e->a;
    s->x6 = e->b;
    s->x2 = e->c;
    s->xF = e->lo;
    s->x3 = 0;
    s->x3C = 0x100;
    s->x3E = 0x100;
    s->x44 = 0;
    s->x40 = 0;
    s->x6C = 0;
    s->x68 = 0;
    s->x64 = 0;
    s->x60 = 0;
    s->x3E += e->hi;
    s->x3C = s->x3E;
    if (s->x34 == 0 && s->x20 == 0) {
        sceVu0CopyVector(&a, &s->v);
    } else if (s->x34 != 0) {
        sceVu0CopyVector(&a, (Vec *)(*s->x34 + s->x38));
    } else if (s->x20 != 0) {
        sceVu0CopyVector(&a, (Vec *)s->x20);
    }
    sceVu0ApplyMatrix(&b, &D_002F16C0, &a);
    s->x2C = sqrtf(sceVu0InnerProduct(&b, &b));
    FlushCache(0);
    if (func_001DA620(i, D_0022EBC8[s->x2], s->x4, s->x6, s->xF) < 0) return -1;
    s->on = 1;
    return i;
}
