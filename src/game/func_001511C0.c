#include "common.h"
typedef struct { Vec p; Vec d; } Cap;
f32 func_00102848(Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_001029E8(Vec *, Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_00102870(Vec *, Vec *);
void func_00102828(Vec *, Vec *, Vec *);
void func_00102A60(Vec *, Vec *);
f32 sqrtf(f32);
static inline f32 clampf(f32 v, f32 lo, f32 hi) { if (v < lo) return lo; if (!(v <= hi)) return hi; return v; }

s32 func_001511C0(Cap *c, Vec *p, Vec *d, Vec *r1, Vec *r2, f32 *out) {
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

    func_00102A18(&n, d, func_00102848(d, &c->d));
    func_001029E8(&n, d, &n);
    func_00102870(&n, &n);
    func_00102828(&cr, &n, &c->d);
    func_001029E8(&dp, p, &c->p);
    x = func_00102848(&cr, &dp);
    x = x < 0.0f ? -x : x;
    if (!(x <= c->p.w)) return 0;
    a = func_00102848(&n, d);
    b = func_00102848(&c->d, d);
    s = func_00102848(&n, &dp);
    dd = func_00102848(&c->d, &dp);
    if (s < -c->p.w && s + a < -c->p.w) return 0;
    if (!(s <= c->p.w) && !(s + a <= c->p.w)) return 0;
    if (dd < -c->p.w && dd + b < -c->p.w) return 0;
    if (!(dd <= c->d.w + c->p.w) && !(dd + b <= c->d.w + c->p.w)) return 0;

    func_001029E8(&e, p, &c->p);
    a = func_00102848(&c->d, d);
    b = func_00102848(&e, &c->d);
    s = func_00102848(&e, d);
    dd = func_00102848(d, d);
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
    func_00102A18(&A, &c->d, x);
    func_001029D0(&P1, &A, &c->p);
    func_00102A18(&B, d, b);
    func_001029D0(&P2, &B, p);
    func_001029E8(&D, &P2, &P1);
    if (fl) {
        if (fl & 0xC) {
            func_001029E8(&t180, &P2, &c->p);
            dd = func_00102848(&t180, &c->d);
            if (dd < 0.0f) x = 0.0f;
            else if (!(dd <= c->d.w)) x = c->d.w;
            else x = dd;
            func_00102A18(&t170, &c->d, x);
            func_001029D0(&P1, &t170, &c->p);
        }
        if (fl & 3) {
            func_001029E8(&t160, &P1, p);
            x = func_00102848(&t160, d) / func_00102848(d, d);
            x = clampf(x, 0.0f, 1.0f);
            func_00102A18(&t150, d, x);
            func_001029D0(&P2, &t150, p);
        }
        func_001029E8(&D, &P2, &P1);
    }
    a = c->p.w;
    a *= a;
    if (!(func_00102848(&D, &D) <= a)) return 0;
    func_00102A18(&t110, &c->d, s);
    func_001029D0(&Q1, &t110, &c->p);
    func_00102A18(&t100, d, u);
    func_001029D0(&Q2, &t100, p);
    func_001029E8(&W, &Q2, &Q1);
    s = s - sqrtf(a - func_00102848(&W, &W));
    if (s < 0.0f) s = 0.0f;
    else if (!(s <= c->d.w)) s = c->d.w;
    func_00102A18(&tD0, &c->d, s);
    func_001029D0(&Q1, &tD0, &c->p);
    func_001029E8(&tF0, &Q1, p);
    x = func_00102848(&tF0, d) / func_00102848(d, d);
    if (x < 0.0f || !(x <= 1.0f)) {
        if (x < 0.0f) x = 0.0f;
        else if (!(x <= 1.0f)) x = 1.0f;
        func_00102A18(&tC0, d, x);
        func_001029D0(&Q2, &tC0, p);
        func_001029E8(&tE0, &Q2, &c->p);
        s = func_00102848(&tE0, &c->d);
        func_00102A18(&tB0, &c->d, s);
        func_001029D0(&Q1, &tB0, &c->p);
        func_001029E8(&W, &Q2, &Q1);
        s = s - sqrtf(a - func_00102848(&W, &W));
        if (s < 0.0f) s = 0.0f;
        else if (!(s <= c->d.w)) s = c->d.w;
        func_00102A18(&tA0, &c->d, s);
        func_001029D0(&Q1, &tA0, &c->p);
    } else {
        func_00102A18(&t90, d, x);
        func_001029D0(&Q2, &t90, p);
    }
    func_00102A60(r1, &Q2);
    r1->w = 0.0f;
    func_001029E8(r2, &Q1, &Q2);
    r2->w = 0.0f;
    *out = s / c->d.w;
    return 1;
}
