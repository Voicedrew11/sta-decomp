#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
f32 sqrtf(f32);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, s8 *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 func_0011DA18(f32);
f32 func_0011D778(f32);
void func_00140440(s8 *, Vec *);
void func_00134620(s8 *, Vec *, Vec *);
Vec *func_00140430(s8 *);
Vec *func_00140460(s8 *);
s8 *func_0013DD10(s8 *);
s8 *func_0013DCE0(s8 *);
u8 func_001435D0(s8 *, s8 *, Vec *);
u8 func_00143810(s8 *, u8, u8);
s32 func_00143290(s8 *, s8 *, Vec *, u8, u8);
Vec *func_00143840(s8 *, u8);

u8 func_00134960(s8 *a) {
    Vec p;
    Vec r;
    Vec d;
    s8 *o;
    s8 *g;
    u8 k0;
    u8 k1;
    u8 k;
    f32 dist;

    sceVu0CopyVector(&p, (Vec *)(a + 0x620));
    sceVu0CopyVector(&r, (Vec *)(a + 0x630));
    switch (*(u8 *)(a + 0x610)) {
    case 0:
        func_00140440(a, &r);
        break;
    case 1:
        func_00134620(a, &p, &r);
        break;
    case 2: {
        f32 ang;
        f32 x;
        f32 y;
        f32 z;
        ang = func_00140430(a)->y + 0.17453293f;
        x = 200.0f * func_0011DA18(ang - 3.1415927f);
        y = p.y;
        z = 200.0f * func_0011D778(ang - 3.1415927f);
        p.x = x;
        p.y = y;
        p.z = z;
        r.y = WRAP(ang);
        break;
    }
    case 3: {
        Vec e;
        f32 len;
        sceVu0SubVector(&e, &p, func_00140460(a));
        *(s32 *)&e.y = 0;
        len = sqrtf(sceVu0InnerProduct(&e, &e));
        e.x /= len;
        e.y /= len;
        e.z /= len;
        e.x *= 8.0f;
        e.y *= 8.0f;
        e.z *= 8.0f;
        sceVu0SubVector(&p, func_00140460(a), &e);
        break;
    }
    }
    o = func_0013DD10(a);
    g = func_0013DCE0(a);
    if (o) {
        k0 = func_001435D0(o, g, func_00140460(a));
        k1 = func_001435D0(o, g, &p);
        if (k0 != 0xFF && k1 != 0xFF && k0 != k1) {
            k = func_00143810(o, k0, k1);
            if (!func_00143290(o, g, func_00140460(a), k0, k)) k = k0;
            if (k == k1) k = 0xFF;
            if (k != 0xFF) {
                Vec *q = func_00143840(o, k);
                if (q) sceVu0AddVector(&p, q, g);
            }
            *(u8 *)(a + 0x6C0) = k;
        } else {
            *(u8 *)(a + 0x6C0) = 0xFF;
        }
    } else {
        *(u8 *)(a + 0x6C0) = 0xFF;
    }
    sceVu0CopyVector((Vec *)(a + 0x640), &p);
    sceVu0CopyVector((Vec *)(a + 0x650), &r);
    sceVu0SubVector(&d, (Vec *)(a + 0x620), func_00140460(a));
    *(s32 *)&d.y = 0;
    dist = sqrtf(sceVu0InnerProduct(&d, &d));
    if (dist < 100.0f) return 2;
    if (!(dist < 300.0f)) return 0;
    return 1;
}

