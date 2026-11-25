#include "common.h"
typedef struct { Vec p; Vec d; } Seg;
typedef struct { Vec a; Vec b; Vec c; s32 r2C; } Hdr;
typedef struct { Vec a; Vec b; Vec c; s32 hit; f32 t1; f32 t2; } Res;
f32 func_00102848(Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_001029E8(Vec *, Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_00102A60(Vec *, Vec *);

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

    func_001029E8(&spF0, &arg2->p, &arg1->p);
    d12 = func_00102848(&arg1->d, &arg2->d);
    a = func_00102848(&spF0, &arg1->d);
    b = func_00102848(&spF0, &arg2->d);
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
    func_00102A18(&spB0, &arg1->d, t1);
    func_001029D0(&spE0, &spB0, &arg1->p);
    func_00102A18(&spA0, &arg2->d, t2);
    func_001029D0(&spD0, &spA0, &arg2->p);
    func_001029E8(&spC0, &spD0, &spE0);
    if (flags) {
        u32 f = flags;
        if (f & 0xC) {
            func_001029E8(&sp90, &spD0, &arg1->p);
            d = func_00102848(&sp90, &arg1->d);
            if (d < 0.0f) t1 = 0.0f; else if (d > arg1->d.w) t1 = arg1->d.w; else t1 = d;
            func_00102A18(&sp80, &arg1->d, t1);
            func_001029D0(&spE0, &sp80, &arg1->p);
        }
        if (f & 3) {
            func_001029E8(&sp70, &spE0, &arg2->p);
            d = func_00102848(&sp70, &arg2->d);
            if (d < 0.0f) t2 = 0.0f; else if (d > arg2->d.w) t2 = arg2->d.w; else t2 = d;
            func_00102A18(&sp60, &arg2->d, t2);
            func_001029D0(&spD0, &sp60, &arg2->p);
        }
        func_001029E8(&spC0, &spD0, &spE0);
    }
    func_00102A60(&arg0->c, &spC0);
    func_00102A60(&arg0->a, &spE0);
    func_00102A60(&arg0->b, &spD0);
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    arg0->a.w = t1 / arg1->d.w;
    arg0->b.w = t2 / arg2->d.w;
    d = arg1->p.w + arg2->p.w;
    if (func_00102848(&spC0, &spC0) <= d * d) {
        arg0->hit = 1;
    }
}
