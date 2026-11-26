#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { Vec m[4]; } Mtx;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; } Bits;
typedef struct { u16 x0; u8 pad2[2]; u8 x4; u8 x5; u8 x6; Bits x7; u8 pad8[0x74 - 8]; u8 x74[4]; f32 x78; u8 pad7C[0x108-0x7C]; s32 rows[4][5]; } M;
typedef struct { s32 r[5]; } R5;
typedef struct { u8 pad[0x210]; M *tbl[1]; } S90;
typedef struct {
    u8 pad[0x60];
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    u8 pad70[0x18];
    f32 x88;
    f32 x8C;
    S90 *p90;
    u16 x94;
    u8 pad96[0x114 - 0x96];
    Bits f114;
} O;
void func_001631E0(Vec *, f32, u8 *, void *, u8 *, f32, s32);
void func_00163C80(O *, Mtx *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
u16 *func_001A5710(void);
u16 *func_001A5660(void);
s32 func_00146C70(Vec *, Vec *, u16 *, s32 *, Vec *, f32);
void func_00146A70(S90 *, u16 *, u8, u32);
s8 *func_00169B50(s32, s32, s32, s32);
void func_00167710(s8 *, Vec *);
s32 func_001470F0(O *, Vec *, s32, s32, s32, Vec *);
static inline f32 u2f(u32 x) { return x; }

void func_001494A0(O *o) {
    Vec b;
    Vec a;
    Vec out;
    Mtx mtx;
    Vec hit;
    s32 cc;
    M *m;
    u8 *p;
    f32 r;
    u16 *n;
    s32 ok;
    s32 t;
    s8 *q;

    m = o->p90->tbl[o->x94];
    p = (u8 *)&((R5 *)((u8 *)m + 0x108))[m->x4].r[m->x5] + m->x6 * 12;
    p = m->x7.b1 ? p + 0x40 : p;
    p = m->x7.b2 ? p + 0xA0 : p;
    b.x = 0.0f;
    b.y = m->x78;
    b.w = 1.0f;
    b.z = 0.0f;
    func_001631E0(&a, o->x8C, m->x74, NULL, p, 0.033333335f * u2f(m->x0), m->x7.b0);
    a.w = 1.0f;
    a.x = 0.0f;
    a.z = 0.0f;
    func_00163C80(o, &mtx);
    sceVu0ApplyMatrix(&b, &mtx, &b);
    sceVu0ApplyMatrix(&a, &mtx, &a);
    r = o->x60;
    for (n = func_001A5710(); n != NULL; n = func_001A5660()) {
        if (*n && func_00146C70(&b, &a, n, &cc, &out, r)) {
            ok = 1;
            goto found;
        }
    }
    cc = 0;
    n = NULL;
    ok = 0;
found:
    if (ok) {
        func_00146A70(o->p90, n, cc, o->x64);
        o->x88 = u2f(o->f114.b1 = 0);
        t = o->x6C;
        if (t) {
            q = func_00169B50(t, 0, 0, 0);
            if (q) {
                func_00167710(q, &out);
            }
        }
    } else if (func_001470F0(o, &a, 3, 6, 0, &hit)) {
        q = func_00169B50(o->x68, 0, 0, 0);
        if (q) {
            func_00167710(q, &hit);
        }
        o->x88 = u2f(o->f114.b1 = 0);
    }
}
