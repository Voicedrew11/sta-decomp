#include "common.h"
s32 func_0013FC00(s8 *);
s32 func_0013FB90(s8 *, u8, Vec **, Vec **);
void func_001029E8(Vec *, Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_00102A60(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_001C93A0(Vec *);
void func_001C9320(Vec *);
void func_001C9490(Vec *);
void func_001C9410(Vec *);
f32 sqrtf(f32);
static inline f32 u2f(u32 x) { return x; }

s32 func_00137E60(s8 *a, s8 *b, Vec *out) {
    Vec *pa[4];
    Vec *pb[4];
    Vec *qa[4];
    Vec *qb[4];
    Vec d;
    Vec e;
    Vec f;
    Vec c1;
    Vec c2;
    Vec g;
    Vec h;
    Vec e2;
    Vec c3;
    Vec c4;
    Vec g2;
    u8 i;
    u8 j;
    u32 steps;
    u32 k;
    u8 nb;
    u8 na;
    f32 rr;
    f32 dd;
    f32 t;
    f32 r;
    f32 len;

    na = func_0013FC00(a);
    nb = func_0013FC00(b);
    for (i = 0; i < na; i++) {
        func_0013FB90(a, i, pa, qa);
        func_001029E8(&d, pa[0], qa[0]);
        len = sqrtf(func_00102848(&d, &d));
        if (!(len <= 0.9f * pa[0]->w)) {
            steps = (u32)(len / (0.9f * pa[0]->w)) + 1;
            if (steps > 6) steps = 6;
            for (j = 0; j < nb; j++) {
                func_0013FB90(b, j, pb, qb);
                r = pa[0]->w + pb[0]->w;
                for (k = 0; k < steps; k = (u8)(k + 1)) {
                    rr = r * r;
                    func_001C93A0(&c1);
                    func_001C9320(&c2);
                    t = u2f(k) / u2f(steps);
                    func_00102A18(&f, &d, t);
                    func_001029D0(&c1, &f, &c1);
                    func_001029D0(&c2, &f, &c2);
                    func_001029D0(&f, &f, qa[0]);
                    func_001029E8(&e, pb[0], &f);
                    e.y = 0.0f;
                    if (func_00102848(&e, &e) - rr <= 0.0f) {
                        if (pb[0]->y < c1.y) {
                            if (pb[0]->y < c1.y - r) continue;
                            func_00102A60(&g, &c1);
                        } else if (!(pb[0]->y <= c2.y)) {
                            if (!(pb[0]->y <= c2.y + r)) continue;
                            func_00102A60(&g, &c2);
                        } else {
                            func_00102A60(&g, &c1);
                            g.y = pb[0]->y;
                        }
                        func_001029E8(&e, pb[0], &g);
                        dd = r - sqrtf(func_00102848(&e, &e));
                        if (!(dd <= 0.0f)) {
                            func_00102A18(&h, &d, t);
                            func_001029E8(out, &g, pb[0]);
                            func_00102870(out, out);
                            func_00102A18(out, out, 1.0f + dd);
                            func_001029D0(out, out, &h);
                            out->w = 0.0f;
                            return 1;
                        }
                    }
                }
            }
        } else {
            for (j = 0; j < nb; j++) {
                func_0013FB90(b, j, pb, qb);
                r = pa[0]->w + pb[0]->w;
                func_001C9490(&c3);
                func_001C9410(&c4);
                func_001029E8(&e2, pb[0], pa[0]);
                e2.y = 0.0f;
                if (func_00102848(&e2, &e2) - r * r <= 0.0f) {
                    if (pb[0]->y < c3.y) {
                        if (pb[0]->y < c3.y - r) continue;
                        func_00102A60(&g2, &c3);
                    } else if (!(pb[0]->y <= c4.y)) {
                        if (!(pb[0]->y <= c4.y + r)) continue;
                        func_00102A60(&g2, &c4);
                    } else {
                        func_00102A60(&g2, &c3);
                        g2.y = pb[0]->y;
                    }
                    func_001029E8(&e2, pb[0], &g2);
                    r = r - sqrtf(func_00102848(&e2, &e2));
                    if (!(r <= 0.0f)) {
                        func_001029E8(out, &g2, pb[0]);
                        func_00102870(out, out);
                        func_00102A18(out, out, 1.0f + r);
                        out->w = 0.0f;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
