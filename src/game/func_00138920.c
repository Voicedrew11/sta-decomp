#include "actor.h"
typedef struct { Vec a; Vec b; u8 pad20[4]; s32 x24; u8 pad28[0x18]; } Big;
extern s32 D_00201E80;
s32 func_0013FB90(Actor *, u8, Vec **, Vec **);
void func_001029E8(Vec *, Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_00102A60(Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_00123C40(void *, s32, s32);
void func_0013D250(s32, Big *, Vec *, u8, u8);
f32 sqrtf(f32);

u8 func_00138920(Actor *a, u8 i, s32 m2, s32 m1, Vec *out, u8 n) {
    Vec *p[4];
    Vec *q[4];
    Vec d;
    Vec c[2];
    Big b;
    Vec e;
    u8 ok;
    u32 j;
    u32 steps;
    f32 len;
    f32 t;
    f32 f;

    ok = 0;
    p[0] = 0;
    q[0] = 0;
    if ((u8)func_0013FB90(a, i, p, q)) {
        func_001029E8(&d, p[0], q[0]);
        len = sqrtf(func_00102848(&d, &d));
        t = 0.9f * p[0]->w;
        if (!(len <= t)) {
            steps = (u32)(len / t) + 1;
            if (steps > 8) steps = 8;
            for (j = n; j <= steps; j++) {
                f = (f32)j / (f32)steps;
                func_00102A18(c, &d, f);
                func_001029D0(c, c, q[0]);
                c[0].w = p[0]->w;
                func_00123C40(&b, 0, 0x40);
                if ((&D_00201E80)[2]) {
                    func_0013D250(*(s32 *)(&D_00201E80)[2], &b, c, m2, m1);
                }
                if ((&D_00201E80)[3]) {
                    func_0013D250(*(s32 *)(&D_00201E80)[3], &b, c, m2, m1);
                }
                if (b.x24) {
                    func_00102A18(&e, &d, f - 1.0f);
                    func_00102A18(out, &b.b, c[0].w);
                    func_001029D0(out, out, &b.a);
                    func_001029E8(out, out, c);
                    func_001029D0(out, out, &e);
                    ok = 1;
                    break;
                }
            }
        } else {
            func_00102A60(c, p[0]);
            func_00123C40(&b, 0, 0x40);
            if ((&D_00201E80)[2]) {
                func_0013D250(*(s32 *)(&D_00201E80)[2], &b, c, m2, m1);
            }
            if ((&D_00201E80)[3]) {
                func_0013D250(*(s32 *)(&D_00201E80)[3], &b, c, m2, m1);
            }
            if (b.x24) {
                func_00102A18(out, &b.b, c[0].w);
                func_001029D0(out, out, &b.a);
                func_001029E8(out, out, c);
                ok = 1;
            }
        }
    }
    return ok;
}
