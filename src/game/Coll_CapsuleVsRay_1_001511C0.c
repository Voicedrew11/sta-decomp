#include "common.h"
typedef struct { Vec p; Vec d; } Cap;
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0OuterProduct(Vec *, Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
f32 sqrtf(f32);
static inline f32 clampf(f32 v, f32 lo, f32 hi) { if (v < lo) return lo; if (!(v <= hi)) return hi; return v; }

s32 Coll_CapsuleVsRay_1_001511C0(Cap *c, Vec *p, Vec *d, Vec *r1, Vec *r2, f32 *out) {
    Vec n;
    Vec cr;
    Vec dp;
    Vec e;
    Vec P1;
    Vec P2;
    Vec D;
    Vec A;
    Vec B;
    Vec t180;
    Vec t170;
    Vec t160;
    Vec t150;
    Vec Q1;
    Vec Q2;
    Vec W;
    Vec t110;
    Vec t100;
    Vec tF0;
    Vec tE0;
    Vec tD0;
    Vec tC0;
    Vec tB0;
    Vec tA0;
    Vec t90;
    f32 a;
    f32 b;
    f32 s;
    f32 u;
    f32 dd, x;
    u8 fl;

    sceVu0ScaleVector(&n, d, sceVu0InnerProduct(d, &c->d));
    sceVu0SubVector(&n, d, &n);
    sceVu0Normalize(&n, &n);
    sceVu0OuterProduct(&cr, &n, &c->d);
    sceVu0SubVector(&dp, p, &c->p);
    x = sceVu0InnerProduct(&cr, &dp);
    x = x < 0.0f ? -x : x;
    if (!(x <= c->p.w)) return 0;
    a = sceVu0InnerProduct(&n, d);
    b = sceVu0InnerProduct(&c->d, d);
    s = sceVu0InnerProduct(&n, &dp);
    dd = sceVu0InnerProduct(&c->d, &dp);
    if (s < -c->p.w && s + a < -c->p.w) return 0;
    if (!(s <= c->p.w) && !(s + a <= c->p.w)) return 0;
    if (dd < -c->p.w && dd + b < -c->p.w) return 0;
    if (!(dd <= c->d.w + c->p.w) && !(dd + b <= c->d.w + c->p.w)) return 0;

    sceVu0SubVector(&e, p, &c->p);
    a = sceVu0InnerProduct(&c->d, d);
    b = sceVu0InnerProduct(&e, &c->d);
    s = sceVu0InnerProduct(&e, d);
    dd = sceVu0InnerProduct(d, d);
    fl = 0;
    x = (dd * b - a * s) / (dd - a * a);
    u = (a * b - s) / (dd - a * a);
    s = x;
    x = s;
    b = u;
    if (s < 0.0f) {
        x = 0.0f;
        fl |= 1;
    } else if (!(s <= c->d.w)) {
        x = c->d.w;
        fl |= 2;
    }
    if (u < 0.0f) {
        b = 0.0f;
        fl |= 4;
    } else if (!(u <= 1.0f)) {
        b = 1.0f;
        fl |= 8;
    }
    sceVu0ScaleVector(&A, &c->d, x);
    sceVu0AddVector(&P1, &A, &c->p);
    sceVu0ScaleVector(&B, d, b);
    sceVu0AddVector(&P2, &B, p);
    sceVu0SubVector(&D, &P2, &P1);
    if (fl) {
        if (fl & 0xC) {
            sceVu0SubVector(&t180, &P2, &c->p);
            dd = sceVu0InnerProduct(&t180, &c->d);
            if (dd < 0.0f) x = 0.0f;
            else if (!(dd <= c->d.w)) x = c->d.w;
            else x = dd;
            sceVu0ScaleVector(&t170, &c->d, x);
            sceVu0AddVector(&P1, &t170, &c->p);
        }
        if (fl & 3) {
            sceVu0SubVector(&t160, &P1, p);
            x = sceVu0InnerProduct(&t160, d) / sceVu0InnerProduct(d, d);
            x = clampf(x, 0.0f, 1.0f);
            sceVu0ScaleVector(&t150, d, x);
            sceVu0AddVector(&P2, &t150, p);
        }
        sceVu0SubVector(&D, &P2, &P1);
    }
    a = c->p.w;
    a *= a;
    if (!(sceVu0InnerProduct(&D, &D) <= a)) return 0;
    sceVu0ScaleVector(&t110, &c->d, s);
    sceVu0AddVector(&Q1, &t110, &c->p);
    sceVu0ScaleVector(&t100, d, u);
    sceVu0AddVector(&Q2, &t100, p);
    sceVu0SubVector(&W, &Q2, &Q1);
    s = s - sqrtf(a - sceVu0InnerProduct(&W, &W));
    if (s < 0.0f) s = 0.0f;
    else if (!(s <= c->d.w)) s = c->d.w;
    sceVu0ScaleVector(&tD0, &c->d, s);
    sceVu0AddVector(&Q1, &tD0, &c->p);
    sceVu0SubVector(&tF0, &Q1, p);
    x = sceVu0InnerProduct(&tF0, d) / sceVu0InnerProduct(d, d);
    if (x < 0.0f || !(x <= 1.0f)) {
        if (x < 0.0f) x = 0.0f;
        else if (!(x <= 1.0f)) x = 1.0f;
        sceVu0ScaleVector(&tC0, d, x);
        sceVu0AddVector(&Q2, &tC0, p);
        sceVu0SubVector(&tE0, &Q2, &c->p);
        s = sceVu0InnerProduct(&tE0, &c->d);
        sceVu0ScaleVector(&tB0, &c->d, s);
        sceVu0AddVector(&Q1, &tB0, &c->p);
        sceVu0SubVector(&W, &Q2, &Q1);
        s = s - sqrtf(a - sceVu0InnerProduct(&W, &W));
        if (s < 0.0f) s = 0.0f;
        else if (!(s <= c->d.w)) s = c->d.w;
        sceVu0ScaleVector(&tA0, &c->d, s);
        sceVu0AddVector(&Q1, &tA0, &c->p);
    } else {
        sceVu0ScaleVector(&t90, d, x);
        sceVu0AddVector(&Q2, &t90, p);
    }
    sceVu0CopyVector(r1, &Q2);
    r1->w = 0.0f;
    sceVu0SubVector(r2, &Q1, &Q2);
    r2->w = 0.0f;
    *out = s / c->d.w;
    return 1;
}
