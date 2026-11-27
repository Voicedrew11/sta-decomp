#include "m2c.h"
#include "common.h"
typedef struct { f32 x, y, z, w; } V;
typedef struct { u16 v[4]; } Ids __attribute__((aligned(8)));
extern u8 D_00201C48;
extern Ids D_00201C40;
void func_00134620(s8 *a, Vec *pos, Vec *tgt);
u8 func_00134960(s8 *a);
void func_00134D70(s8 *a0, s32 a1);
void func_00135240(s8 *a0, s32 a1);
u8 func_00135490(s8 *a, f32 *pl, f32 *pc, f32 *py);
Vec* func_00140460(s8 *);
Vec* func_00140430(s8 *);
void func_001403D0(s8 *, Vec *);
void sceVu0SubVector(void *, void *, void *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 sinf(f32);
f32 cosf(f32);
f32 sqrtf(float);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0AddVector(void *, void *, s8*);
void func_00140440(s8*, void *);
s8* func_0013DD10(s8 *);
s8* func_0013DCE0(s8 *);
u8 func_001435D0(s8 *, s8 *, Vec *);
u8 func_00143810(s8 *, u8, u8);
s32 func_00143290(s8 *, s8 *, Vec *, u8, u8);
Vec* func_00143840(s8 *, u8);
u16 func_001409A0(s8 *, s32, f32 *, f32 *, f32 *);
void func_00145760(s8 *);
void func_00140470(s8 *, s8 *);
void func_00140350(s8 *, s8 *);
void func_00140310(s8 *, s8 *);
void func_001456B0(Vec *);
void func_00145640(Vec *);
void func_00140360(s8 *, Vec *);
u8 func_00143150(s8 *, s8 *, s8 *);
void func_00145720(s8 *);
s8* func_00145730(void);
f32 func_0013FC10(void *);
void func_00140330(s8 *, s8 *);
void func_00140300(s8 *, s8 *);
u16 func_001416B0(s8 *, s32, s32 *, s32 *, s32 *);
u8 func_0013E240(s8 *);
u8 func_00135990(s8 *, f32 *, f32 *, f32 *);
void func_0013EA80(s8 *, s32);
u16 func_0013E110(s8 *);
s8* func_001A5460(s32 *);
s32 func_0013EE30(s8 *);
s32 func_0013EEE0(s8 *);
s32 func_0013E220(s8 *);
s8 func_0013E290(s8 *);

/* func_00134620 */
#define sceVu0SubVector sceVu0SubVector__as_func_00134620
void sceVu0SubVector__as_func_00134620(Vec *, Vec *, Vec *);

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
        r.x = sinf(tgt->y);
        r.y = 0.0f;
        r.z = cosf(tgt->y);
    }
    if (D_00201C48 == 1) {
        r.x = -sinf(tgt->y);
        r.y = 0.0f;
        r.z = -cosf(tgt->y);
    }
    if (D_00201C48 == 2) {
        r.x = cosf(tgt->y);
        r.y = 0.0f;
        r.z = -sinf(tgt->y);
    }
    if (D_00201C48 == 3) {
        r.x = -cosf(tgt->y);
        r.y = 0.0f;
        r.z = sinf(tgt->y);
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
#undef sceVu0SubVector

/* func_00134960 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define sceVu0SubVector sceVu0SubVector__as_func_00134960
void sceVu0SubVector__as_func_00134960(Vec *, Vec *, Vec *);
#define sceVu0AddVector sceVu0AddVector__as_func_00134960
void sceVu0AddVector__as_func_00134960(Vec *, Vec *, s8 *);
#define func_00140440 func_00140440__as_func_00134960
void func_00140440__as_func_00134960(s8 *, Vec *);

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
        x = 200.0f * sinf(ang - 3.1415927f);
        y = p.y;
        z = 200.0f * cosf(ang - 3.1415927f);
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
#undef sceVu0SubVector
#undef sceVu0AddVector
#undef func_00140440

/* func_00134D70 */
#define func_0013DCE0 func_0013DCE0__as_func_00134D70
f32 *func_0013DCE0__as_func_00134D70(s8 *);
#define func_00140460 func_00140460__as_func_00134D70
s8 *func_00140460__as_func_00134D70(s8 *);
#define func_00143840 func_00143840__as_func_00134D70
s8 *func_00143840__as_func_00134D70(s8 *, u8);
#define sceVu0AddVector sceVu0AddVector__as_func_00134D70
void sceVu0AddVector__as_func_00134D70(s8 *, s8 *, s8 *);
#define func_00140440 func_00140440__as_func_00134D70
void func_00140440__as_func_00134D70(s8 *, s8 *);
#define sceVu0SubVector sceVu0SubVector__as_func_00134D70
void sceVu0SubVector__as_func_00134D70(Vec *, s8 *, s8 *);
#define func_0013FC10 func_0013FC10__as_func_00134D70
f32 func_0013FC10__as_func_00134D70(Vec *);
#define F(o) (*(f32 *)(a0 + (o)))

void func_00134D70(s8 *a0, s32 a1) {
    f32 x, y, z;
    u16 r;
    u8 lo, hi;
    r = func_001409A0(a0, a1, &x, &y, &z);
    lo = r & 0xFF;
    hi = r >> 8;
    switch (lo) {
    case 0: {
        f32 *p;
        func_00140470(a0, a0 + 0x620);
        p = func_0013DCE0(a0);
        F(0x620) = x;
        F(0x628) = y;
        if (p) {
            F(0x620) += p[0];
            F(0x628) += p[2];
        }
        break;
    }
    case 1:
        func_00145760(a0 + 0x620);
        break;
    case 2:
        func_00140470(a0, a0 + 0x620);
        break;
    case 3:
        func_00145760(a0 + 0x620);
        F(0x620) += x;
        F(0x628) += y;
        break;
    case 4:
        func_00140470(a0, a0 + 0x620);
        F(0x620) += x;
        F(0x628) += y;
        break;
    case 5: {
        Vec v;
        func_00145760(a0 + 0x620);
        func_001456B0(&v);
        F(0x620) += v.x * x;
        F(0x628) += v.z * x;
        func_00145640(&v);
        F(0x620) += v.x * y;
        F(0x628) += v.z * y;
        break;
    }
    case 6: {
        Vec v;
        func_00140470(a0, a0 + 0x620);
        func_001403D0(a0, &v);
        F(0x620) += v.x * x;
        F(0x628) += v.z * x;
        func_00140360(a0, &v);
        F(0x620) += v.x * y;
        F(0x628) += v.z * y;
        break;
    }
    case 7:
        break;
    case 8:
        func_00140350(a0, a0 + 0x620);
        break;
    case 9:
        func_00140350(a0, a0 + 0x620);
        F(0x620) += x;
        F(0x628) += y;
        break;
    case 10: {
        Vec v;
        func_00140350(a0, a0 + 0x620);
        func_001403D0(a0, &v);
        F(0x620) += v.x * x;
        F(0x628) += v.z * x;
        func_00140360(a0, &v);
        F(0x620) += v.x * y;
        F(0x628) += v.z * y;
        break;
    }
    case 11:
        func_00140310(a0, a0 + 0x620);
        break;
    case 12: {
        s8 *s3 = func_0013DD10(a0);
        s8 *s2 = (s8 *)func_0013DCE0(a0);
        func_00140350(a0, a0 + 0x620);
        if (s3) {
            u8 k = func_00143150(s3, s2, func_00140460(a0));
            if (k != 0xFF) {
                sceVu0AddVector(a0 + 0x620, func_00143840(s3, k), s2);
            }
        }
        break;
    }
    }
    switch (hi) {
    case 0:
        func_00140440(a0, a0 + 0x630);
        F(0x634) = z;
        break;
    case 1:
        func_00145720(a0 + 0x630);
        break;
    case 2:
        func_00140440(a0, a0 + 0x630);
        break;
    case 3: {
        Vec v;
        s8 *p = func_00145730();
        sceVu0SubVector(&v, p, func_00140460(a0));
        *(s32 *)&v.y = 0;
        F(0x634) = func_0013FC10(&v);
        break;
    }
    case 4: {
        Vec v;
        sceVu0SubVector(&v, func_00140460(a0), func_00145730());
        *(s32 *)&v.y = 0;
        F(0x634) = func_0013FC10(&v);
        break;
    }
    case 5:
        break;
    case 6:
        func_00140330(a0, a0 + 0x630);
        break;
    case 7:
        func_00140300(a0, a0 + 0x630);
        break;
    }
}
#undef func_0013DCE0
#undef func_00140460
#undef func_00143840
#undef sceVu0AddVector
#undef func_00140440
#undef sceVu0SubVector
#undef func_0013FC10

/* func_00135240 */
#define func_00140460 func_00140460__as_func_00135240
s8 *func_00140460__as_func_00135240(s8 *);
#define func_00143840 func_00143840__as_func_00135240
s8 *func_00143840__as_func_00135240(s8 *, u8);
#define sceVu0AddVector sceVu0AddVector__as_func_00135240
void sceVu0AddVector__as_func_00135240(s8 *, s8 *, s8 *);
#define func_00140440 func_00140440__as_func_00135240
void func_00140440__as_func_00135240(s8 *, s8 *);
#define sceVu0SubVector sceVu0SubVector__as_func_00135240
void sceVu0SubVector__as_func_00135240(V *, s8 *, s8 *);
#define func_0013FC10 func_0013FC10__as_func_00135240
f32 func_0013FC10__as_func_00135240(V *);

void func_00135240(s8 *a0, s32 a1) {
    s32 x, y, z;
    u16 r;
    u8 lo, hi;
    r = func_001416B0(a0, a1, &x, &y, &z);
    lo = r & 0xFF;
    hi = r >> 8;
    switch (lo) {
    case 1:
        func_00145760(a0 + 0x620);
        break;
    case 2:
        func_00140470(a0, a0 + 0x620);
        break;
    case 7:
        break;
    case 8:
        func_00140350(a0, a0 + 0x620);
        break;
    case 11:
        func_00140310(a0, a0 + 0x620);
        break;
    case 12: {
        s8 *s3 = func_0013DD10(a0);
        s8 *s2 = func_0013DCE0(a0);
        func_00140350(a0, a0 + 0x620);
        if (s3) {
            u8 k = func_00143150(s3, s2, func_00140460(a0));
            if (k != 0xFF) {
                sceVu0AddVector(a0 + 0x620, func_00143840(s3, k), s2);
            }
        }
        break;
    }
    }
    switch (hi) {
    case 0:
        break;
    case 1:
        func_00145720(a0 + 0x630);
        break;
    case 2:
        func_00140440(a0, a0 + 0x630);
        break;
    case 3: {
        V v;
        s8 *p = func_00145730();
        sceVu0SubVector(&v, p, func_00140460(a0));
        *(s32 *)&v.y = 0;
        *(f32 *)(a0 + 0x634) = func_0013FC10(&v);
        break;
    }
    case 4: {
        V v;
        sceVu0SubVector(&v, func_00140460(a0), func_00145730());
        *(s32 *)&v.y = 0;
        *(f32 *)(a0 + 0x634) = func_0013FC10(&v);
        break;
    }
    case 5:
        break;
    case 6:
        func_00140330(a0, a0 + 0x630);
        break;
    case 7:
        func_00140300(a0, a0 + 0x630);
        break;
    }
}
#undef func_00140460
#undef func_00143840
#undef sceVu0AddVector
#undef func_00140440
#undef sceVu0SubVector
#undef func_0013FC10

/* func_00135490 */
#define func_00140440 func_00140440__as_func_00135490
void func_00140440__as_func_00135490(s8 *, s8 *);
#define func_00145730 func_00145730__as_func_00135490
Vec *func_00145730__as_func_00135490(void);
#define sceVu0SubVector sceVu0SubVector__as_func_00135490
void sceVu0SubVector__as_func_00135490(Vec *, Vec *, Vec *);

u8 func_00135490(s8 *a, f32 *pl, f32 *pc, f32 *py) {
    s32 it;
    s32 it2;
    Ids ids;
    Vec d;
    Vec d2;
    Vec m;
    u8 t;
    u8 i;
    s8 *e;
    s8 *best;
    u16 id;
    u16 id2;
    s8 *e2;
    u8 k;
    f32 min;
    f32 dist;
    f32 len;
    f32 cs;
    f32 dy;

    t = func_0013E240(a);
    if (t == 0) return func_00135990(a, pl, pc, py);
    best = NULL;
    func_0013EA80(a, 0);
    if (t == 1) {
        id = func_0013E110(a);
        ids = D_00201C40;
        switch (id) {
        case 0x1068:
        case 0x1069:
            ids.v[0] = 0x106C;
            ids.v[1] = 0x106D;
            break;
        case 0x106A:
        case 0x106B:
            ids.v[0] = 0x106D;
            ids.v[1] = 0x106C;
            break;
        case 0x106C:
            ids.v[0] = 0x106B;
            ids.v[1] = 0x1068;
            ids.v[2] = 0x1069;
            ids.v[3] = 0x106A;
            break;
        case 0x106D:
            ids.v[0] = 0x106B;
            ids.v[1] = 0x106A;
            ids.v[2] = 0x1069;
            ids.v[3] = 0x1068;
            break;
        case 0x1078:
            ids.v[0] = 0x1079;
            break;
        case 0x1079:
            ids.v[0] = 0x1078;
            break;
        }
        it = 0;
        for (e = func_001A5460(&it); e != NULL; e = func_001A5460(&it)) {
            if (!func_0013EE30(e) && !func_0013EEE0(e)) {
                id2 = func_0013E110(e);
                for (i = 0; i < 4; i++) {
                    if (id2 == ids.v[i]) {
                        best = e;
                        func_00140470(e, a + 0x680);
                        func_00140440(e, a + 0x690);
                        break;
                    }
                }
            }
            if (best) break;
        }
    } else if (t == 2) {
        min = 4000000.0f;
        it2 = 0;
        for (e2 = func_001A5460(&it2); e2 != NULL; e2 = func_001A5460(&it2)) {
            if (!func_0013EE30(e2) && !func_0013EEE0(e2)) {
                k = func_0013E220(e2);
                if (k >= 0x33 && k < 0x36 && func_0013E290(e2) == 0xF) {
                    sceVu0SubVector(&d, func_00140460(e2), func_00140460(a));
                    dist = sceVu0InnerProduct(&d, &d);
                    if (dist < min) {
                        min = dist;
                        best = e2;
                        func_00140470(e2, a + 0x680);
                        func_00140440(e2, a + 0x690);
                    }
                }
            }
        }
    }
    if (best != NULL) {
    sceVu0SubVector(&d2, func_00140460(best), func_00140460(a));
    sqrtf(sceVu0InnerProduct(&d2, &d2));
    dy = d2.y;
    dy = dy < 0.0f ? -dy : dy;
    *(s32 *)&d2.y = 0;
    len = sqrtf(sceVu0InnerProduct(&d2, &d2));
    if (len > 0.0f) {
        d2.x /= len;
        d2.y /= len;
        d2.z /= len;
    }
    func_001403D0(a, &m);
    cs = sceVu0InnerProduct(&d2, &m);
    if (pl) *pl = len;
    if (pc) *pc = cs;
    if (py) *py = dy;
    if (t == 1) {
        dy = func_00140460(a)->y - func_00145730()->y;
        if (dy < -500.0f || !(dy <= 500.0f)) return 0;
    }
    return 1;
    }
    return func_00135990(a, pl, pc, py);
}
#undef func_00140440
#undef func_00145730
#undef sceVu0SubVector
