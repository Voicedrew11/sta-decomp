#include "common.h"
typedef struct { Vec p; Vec d; } Seg;
typedef struct { Vec a; Vec b; Vec c; s32 r2C; } Hdr;
typedef struct { Vec a; Vec b; Vec c; s32 hit; f32 t1; f32 t2; } Res;
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0CopyVector(Vec *, Vec *);

void func_00151B20(Res *arg0, Seg *arg1, Seg *arg2) {
    Vec spF0;
    Vec spE0;
    Vec spD0;
    Vec spC0;
    Vec spB0;
    Vec spA0;
    Vec sp90;
    Vec sp80;
    Vec sp70;
    Vec sp60;
    f32 d12, a, b, det, d;
    f32 t1, t2;
    u8 flags;

    sceVu0SubVector(&spF0, &arg2->p, &arg1->p);
    d12 = sceVu0InnerProduct(&arg1->d, &arg2->d);
    a = sceVu0InnerProduct(&spF0, &arg1->d);
    b = sceVu0InnerProduct(&spF0, &arg2->d);
    det = 1.0f - d12 * d12;
    flags = 0;
    t1 = (a - d12 * b) / det;
    t2 = (d12 * a - b) / det;
    arg0->t1 = t1 / arg1->d.w;
    arg0->t2 = t2 / arg2->d.w;
    arg0->hit = 0;
    if (t1 < 0.0f) {
        flags |= 1;
        t1 = 0.0f;
    } else if (!(t1 <= arg1->d.w)) {
        flags |= 2;
        t1 = arg1->d.w;
    }
    if (t2 < 0.0f) {
        flags |= 4;
        t2 = 0.0f;
    } else if (!(t2 <= arg2->d.w)) {
        flags |= 8;
        t2 = arg2->d.w;
    }
    sceVu0ScaleVector(&spB0, &arg1->d, t1);
    sceVu0AddVector(&spE0, &spB0, &arg1->p);
    sceVu0ScaleVector(&spA0, &arg2->d, t2);
    sceVu0AddVector(&spD0, &spA0, &arg2->p);
    sceVu0SubVector(&spC0, &spD0, &spE0);
    if (flags) {
        u32 f = flags;
        if (f & 0xC) {
            sceVu0SubVector(&sp90, &spD0, &arg1->p);
            d = sceVu0InnerProduct(&sp90, &arg1->d);
            if (d < 0.0f) t1 = 0.0f; else if (d > arg1->d.w) t1 = arg1->d.w; else t1 = d;
            sceVu0ScaleVector(&sp80, &arg1->d, t1);
            sceVu0AddVector(&spE0, &sp80, &arg1->p);
        }
        if (f & 3) {
            sceVu0SubVector(&sp70, &spE0, &arg2->p);
            d = sceVu0InnerProduct(&sp70, &arg2->d);
            if (d < 0.0f) t2 = 0.0f; else if (d > arg2->d.w) t2 = arg2->d.w; else t2 = d;
            sceVu0ScaleVector(&sp60, &arg2->d, t2);
            sceVu0AddVector(&spD0, &sp60, &arg2->p);
        }
        sceVu0SubVector(&spC0, &spD0, &spE0);
    }
    sceVu0CopyVector(&arg0->c, &spC0);
    sceVu0CopyVector(&arg0->a, &spE0);
    sceVu0CopyVector(&arg0->b, &spD0);
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    arg0->a.w = t1 / arg1->d.w;
    arg0->b.w = t2 / arg2->d.w;
    d = arg1->p.w + arg2->p.w;
    if (sceVu0InnerProduct(&spC0, &spC0) <= d * d) {
        arg0->hit = 1;
    }
}
