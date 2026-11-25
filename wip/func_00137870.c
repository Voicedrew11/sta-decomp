#include "common.h"
u8 func_0013FC00(s8 *);
s32 func_0013FB90(s8 *, u8, Vec **, Vec **);
void func_001029E8(Vec *, Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_00102A60(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_001C9490(Vec *);
void func_001C9410(Vec *);
f32 sqrtf(f32);
static inline f32 u2f(u32 x) { return x; }

s32 func_00137870(s8 *a, s8 *b, Vec *out) {
    Vec *pa[4];
    Vec *pb[4];
    Vec *qa[4];
    Vec *qb[4];
    Vec d;
    Vec e;
    Vec c;
    Vec g;
    Vec h;
    Vec lo;
    Vec hi;
    u8 na;
    u8 i;
    u8 nb;
    u8 j;
    u8 k;
    u32 steps;
    f32 len;
    f32 t;
    f32 r;
    f32 rr;
    f32 f;
    f32 dd;

    na = func_0013FC00(a);
    nb = func_0013FC00(b);
    for (i = 0; i < na; i++) {
        func_0013FB90(a, i, pa, qa);
        func_001029E8(&d, pa[0], qa[0]);
        len = sqrtf(func_00102848(&d, &d));
        t = 0.9f * pa[0]->w;
        if (!(len <= t)) {
            steps = (u32)(len / t) + 1;
            if (steps > 6) steps = 6;
            for (j = 0; j < nb; j++) {
                func_0013FB90(b, j, pb, qb);
                r = pa[0]->w + pb[0]->w;
                k = 0;
                if (k < steps) {
                    rr = r * r;
                    do {
                        f = u2f(k) / u2f(steps);
                        func_00102A18(&c, &d, f);
                        func_001029D0(&c, &c, qa[0]);
                        func_001029E8(&e, pb[0], &c);
                        e.y = 0.0f;
                        if (func_00102848(&e, &e) - rr <= 0.0f) {
                            func_001C9490(&lo);
                            func_001C9410(&hi);
                            if (c.y < lo.y) {
                                if (c.y < lo.y - r) continue;
                                func_00102A60(&g, &lo);
                            } else if (!(c.y <= hi.y)) {
                                if (!(c.y <= hi.y + r)) continue;
                                func_00102A60(&g, &hi);
                            } else {
                                func_00102A60(&g, &lo);
                                g.y = c.y;
                            }
                            func_001029E8(&e, &g, &c);
                            dd = r - sqrtf(func_00102848(&e, &e));
                            if (!(dd <= 0.0f)) {
                                func_00102A18(&h, &d, f);
                                func_001029E8(out, pa[0], &g);
                                func_00102870(out, out);
                                func_00102A18(out, out, 1.0f + dd);
                                func_001029D0(out, out, &h);
                                *(s32 *)&out->w = 0;
                                return 1;
                            }
                        }
                    } while (++k < steps);
                }
            }
        } else {
            Vec e2;
            Vec g2;
            Vec lo2;
            Vec hi2;
            for (k = 0; k < nb; k++) {
                func_0013FB90(b, k, pb, qb);
                r = pa[0]->w + pb[0]->w;
                func_001029E8(&e2, pb[0], pa[0]);
                e2.y = 0.0f;
                if (func_00102848(&e2, &e2) - r * r <= 0.0f) {
                    func_001C9490(&lo2);
                    func_001C9410(&hi2);
                    if (pa[0]->y < lo2.y) {
                        if (pa[0]->y < lo2.y - r) continue;
                        func_00102A60(&g2, &lo2);
                    } else if (!(pa[0]->y <= hi2.y)) {
                        if (!(pa[0]->y <= hi2.y + r)) continue;
                        func_00102A60(&g2, &hi2);
                    } else {
                        func_00102A60(&g2, &lo2);
                        g2.y = pa[0]->y;
                    }
                    func_001029E8(&e2, &g2, pa[0]);
                    r = r - sqrtf(func_00102848(&e2, &e2));
                    if (!(r <= 0.0f)) {
                        func_001029E8(out, pa[0], &g2);
                        func_00102870(out, out);
                        func_00102A18(out, out, 1.0f + r);
                        *(s32 *)&out->w = 0;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
