#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
Vec *func_00140460(s8 *);
Vec *func_00140430(s8 *);
void func_001403D0(s8 *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 func_0011DA18(f32);
f32 func_0011D778(f32);
float sqrtf(float);
extern u8 D_00201C48;

void func_00134620(s8 *a, Vec *pos, Vec *tgt) {
    Vec d;
    Vec r;
    Vec m;
    f32 len;
    f32 dy;
    f32 dot;

    sceVu0SubVector(&d, pos, func_00140460(a));
    d.y = 0.0f;
    len = sqrtf(sceVu0InnerProduct(&d, &d));
    dy = tgt->y - func_00140430(a)->y;
    if (len == 0.0f) {
        if (dy == 0.0f) return;
    } else {
        d.x /= len;
        d.y /= len;
        d.z /= len;
    }
    func_001403D0(a, &m);
    if (D_00201C48 == 0) {
        r.x = func_0011DA18(tgt->y);
        r.y = 0.0f;
        r.z = func_0011D778(tgt->y);
    }
    if (D_00201C48 == 1) {
        r.x = -func_0011DA18(tgt->y);
        r.y = 0.0f;
        r.z = -func_0011D778(tgt->y);
    }
    if (D_00201C48 == 2) {
        r.x = func_0011D778(tgt->y);
        r.y = 0.0f;
        r.z = -func_0011DA18(tgt->y);
    }
    if (D_00201C48 == 3) {
        r.x = -func_0011D778(tgt->y);
        r.y = 0.0f;
        r.z = func_0011DA18(tgt->y);
    }
    dot = sceVu0InnerProduct(&r, &d);
    if (dot < -0.70710677f) {
        r.y = r.x;
        r.x = -r.z;
        r.z = r.y;
        r.y = 0.0f;
        dot = sceVu0InnerProduct(&r, &d);
        if (len < 300.0f) len = 500.0f;
        if (!(len <= 600.0f)) len = 400.0f;
        if (dot < 0.0f) {
            pos->x += r.x * len;
            pos->z += r.z * len;
        } else {
            pos->x -= r.x * len;
            pos->z -= r.z * len;
        }
    } else if (dot < 0.70710677f) {
        if (len < 300.0f) len = 500.0f;
        if (!(len <= 600.0f)) len = 400.0f;
        pos->x -= r.x * len;
        pos->z -= r.z * len;
    }
}
