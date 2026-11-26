#include "m2c.h"
typedef struct {
    s32 id;
    s32 h;
    f32 r;
    s32 xC;
    f32 f10;
    s32 id2;
    s32 h2;
    s8 s1C;
    u8 pad1D;
    s16 x1E;
    f32 pos[4];
    f32 pad30[4];
    f32 box[4];
} S;
f32 sqrtf(f32);
void func_001027B0(f32 *, f32 *, f32 *);
f32 func_00102848(f32 *, f32 *);
f32 func_0011D850(f32);
f32 func_0011DBD8(f32);
s32 func_00131600(s32, s8);
void func_00131130(s32, s32);
void func_001310B0(s32, s16);
void func_00131440(s32);
s32 func_00131060(s32);
extern f32 D_0026F090[];
extern f32 D_002F16C0[];
extern f32 D_001F2160[];

void func_0012FC20(S *o) {
    f32 d[4];
    f32 e[4];
    f32 w[4];
    s32 in;
    s16 vol;
    f32 dist;
    f32 g;
    f32 ex;
    f32 v;
    f32 dd;

    func_001027B0(d, D_002F16C0, o->pos);
    if (o->xC == 0) {
        dist = func_00102848(d, d);
        g = o->r + o->f10;
        in = dist < g * g;
    } else {
        func_001027B0(e, D_0026F090, D_001F2160);
        d[0] = func_0011D850(o->pos[0] - e[0]);
        d[1] = func_0011D850(o->pos[1] - e[1]);
        d[2] = func_0011D850(o->pos[2] - e[2]);
        if (d[0] <= o->box[0] + o->f10 && d[1] <= o->box[1] + o->f10 && d[2] <= o->box[2] + o->f10) {
            in = 1;
        } else {
            in = 0;
        }
    }
    if (o->x1E == 3) {
        if (o->xC == 0) {
            if (in) {
                dist = sqrtf(func_00102848(d, d));
                ex = o->r;
                if (!(dist <= ex)) {
                    ex = dist - ex;
                    g = 0.0f;
                    if (!(o->f10 <= g)) g = func_0011DBD8(-4.84418678f / o->f10 * ex);
                    vol = (s32)(o->s1C * g);
                } else {
                    vol = o->s1C;
                }
            }
        } else {
            if (in) {
                w[0] = d[0] > o->box[0] ? d[0] - o->box[0] : 0.0f;
                w[1] = d[1] > o->box[1] ? d[1] - o->box[1] : 0.0f;
                w[2] = d[2] > o->box[2] ? d[2] - o->box[2] : 0.0f;
                w[3] = 1.0f;
                dd = sqrtf(func_00102848(w, w));
                if (!(o->f10 <= dd)) {
                    if (!(o->f10 <= 0.0f)) func_0011DBD8(-4.84418678f / o->f10 * dd);
                } else {
                    vol = o->s1C;
                }
            }
        }
    }
    if (o->h == -1) {
        if (in) {
            o->h = func_00131600(o->id, o->s1C);
            if (o->x1E == 2) {
                func_00131130(o->h, 0);
                func_001310B0(o->h, -1);
            } else {
                func_001310B0(o->h, vol);
            }
        }
    } else {
        if (!in) {
            func_00131440(o->h);
            o->h = -1;
        }
        if (func_00131060(o->h) == 0) {
            o->h = -1;
        } else {
            func_001310B0(o->h, vol);
        }
    }
    if (o->h2 == -1) {
        if (in) {
            o->h2 = func_00131600(o->id2, o->s1C);
            if (o->x1E == 2) {
                func_00131130(o->h2, 0);
                func_001310B0(o->h2, -1);
            } else {
                func_001310B0(o->h2, vol);
            }
        }
    } else {
        if (!in) {
            func_00131440(o->h2);
            o->h2 = -1;
        }
        if (func_00131060(o->h2) == 0) {
            o->h2 = -1;
        } else {
            func_001310B0(o->h2, vol);
        }
    }
}
