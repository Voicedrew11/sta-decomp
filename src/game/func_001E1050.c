#include "common.h"
typedef struct { s32 h; s32 x4, x8, xC; char p[0x20]; f32 x30, x34; char q[8]; } E;
typedef struct { s32 v; char p[0x3C]; } F;
extern E D_004BAC50[16];

extern u8 D_002023AC;
extern Vec D_001F2160, D_003139A0;
s32 func_0015DBF0(s32, Vec *, Vec *, f32, f32);
void func_0015D800(s32, Vec *, Vec *, f32, f32);
void sceVu0CopyVector(void *, void *);
static inline s32 find(void) {
    s32 i;
    E *e;
    if (D_002023AC == 16) return -1;
    for (i = 0, e = D_004BAC50; i < 16; i++, e++) if (e->h == -1) return i;
    return -1;
}
static inline s32 valid(s32 i) {
    s32 ok;
    if (i < 0 || i >= 16)
        ok = 0;
    else if (D_004BAC50[i].h == -1)
        ok = 0;
    else
        ok = 1;
    return ok;
}
static inline void setup(s32 i) {
    s32 ok;
    E *f;
    if (i < 0 || i >= 16) ok = 0; else if (D_004BAC50[i].h == -1) ok = 0; else ok = 1;
    if (ok) {
        f = (E *)((s32)D_004BAC50 + (i << 6));
        sceVu0CopyVector(f->p, &D_001F2160);
        sceVu0CopyVector(f->p + 0x10, &D_003139A0);
        D_004BAC50[i].x30 = 0.0f;
        D_004BAC50[i].x34 = 0.0f;
        func_0015D800(f->h, &D_001F2160, &D_003139A0, 0.0f, 0.0f);
    }
}
s32 func_001E1050(void) {
    s32 i = find();
    if (i != -1) {
        s32 h = func_0015DBF0(0, &D_001F2160, &D_003139A0, 0.0f, 0.0f); E *e = &D_004BAC50[i]; e->h = h; D_004BAC50[i].x4 = 0; D_004BAC50[i].x8 = 0;
        setup(i);
        D_002023AC++;
    }
    return i;
}
