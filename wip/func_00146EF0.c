#include "m2c.h"
typedef struct { f32 v[4]; } Vec;
u16 *func_001A5460(s32 *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
f32 fabsf(f32);
s32 func_0013EE40(u16 *);
Vec *func_0013FFA0(u16 *);
f32 func_00146940(Vec *, Vec *);
void func_00146310(Vec *, Vec *, Vec *, f32 *, f32 *);
s32 func_001470F0(Vec *, Vec *, s32, s32, s32, Vec *);

u16 *func_00146EF0(Vec *pos, Vec *dir, s32 check, f32 maxd, f32 w, f32 h) {
    f32 cc;
    f32 c8;
    s32 it;
    Vec b0;
    Vec a0;
    Vec p;
    Vec out;
    u16 *res;
    u16 *e;
    f32 best;
    f32 hh;
    f32 hw;
    f32 d;
    s32 ok;

    res = NULL;
    best = 65535.0f;
    it = 0;
    e = func_001A5460(&it);
    sceVu0Normalize(&a0, dir);
    if (e != NULL) {
        hw = 0.5f * w;
        hh = 0.5f * h;
        do {
            if (*e != 0 && func_0013EE40(e) == 0) {
                sceVu0CopyVector(&p, func_0013FFA0(e));
                d = func_00146940(&p, pos);
                if (!(maxd < d)) {
                    sceVu0SubVector(&b0, &p, pos);
                    sceVu0Normalize(&b0, &b0);
                    func_00146310(pos, dir, &p, &cc, &c8);
                    cc = fabsf(cc);
                    c8 = fabsf(c8);
                    if (!(hw < c8) && !(hh < cc)) {
                        d = (1.0f + c8) * (d * (1.0f + cc));
                        if (d < 0.0f) {
                            d = -d;
                        }
                        if (d < best) {
                            ok = 1;
                            if (check != 0) {
                                ok = !func_001470F0(pos, &p, 3, 0x26, 0, &out);
                            }
                            if (ok != 0) {
                                best = d;
                                res = e;
                            }
                        }
                    }
                }
            }
            e = func_001A5460(&it);
        } while (e != NULL);
    }
    return res;
}
