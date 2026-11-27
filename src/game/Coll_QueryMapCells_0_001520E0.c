#include "common.h"
typedef struct { u8 b0:1; u8 b1:1; } B2;
typedef struct { u8 pad[4]; B2 f; u8 pad5[3]; } Sel;
typedef struct { u8 pad[0x178]; Sel *sel; } Ctx;
typedef struct { u8 pad[0x10]; s32 *x10; u16 x14; u16 x16; u16 x18; u16 x1A; u16 x1C; u8 pad1E[0x22]; u8 x40[1]; } H;
typedef struct { H *m; } O;
typedef struct { O *o; u8 pad4[2]; u16 x6; u8 pad8[0x38]; s8 x40[1]; } A0;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10[8]; u8 pad30[0x20]; } G;
typedef struct { u16 n[8]; u8 pad10[0x10]; Vec sph[8]; } Q;
typedef struct { u16 n; u16 pad; s32 off; u8 p8[8]; Vec sph; } Item;
typedef struct { u8 p0[0xC]; f32 r; u8 p10[0xC]; f32 w; } Ray;
extern s32 D_00201F2C;
extern s16 D_00222A18[];
extern s16 D_00222A16[];
void memset(void *, s32, s32);
void sceVu0CopyMatrix(Mtx *, void *);
void sceVu0CopyVector(Vec *, void *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
void sceVu0SubVector(Vec *, Ray *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
s32 Coll_TestCellTriangles_1_00152700(Vec *, A0 *, Ray *, s32, s32 *, s32, s32 *, Vec *, Vec *, Vec *, Q *, Item *, u8 *, Mtx *, f32 *, s32, s32, s32);
static inline s32 inr(Vec *c, f32 r) { r *= r; return sceVu0InnerProduct(c, c) <= r; }

void Coll_QueryMapCells_0_001520E0(Vec *o, A0 *a, Ray *ray, u8 mask, s32 mode, s32 *pcnt, s32 x6, s32 x7, Ctx *ctx, s32 skip) {
    Vec X;
    Vec Y;
    Mtx M;
    Vec T[3];
    Vec C;
    Vec B;
    f32 best;
    H *h;
    s32 base;
    u32 k;
    u8 *tbl;
    Q *q;
    u8 *base2;
    s32 j;
    u8 *s;
    Sel *sl;
    u32 idx;
    G *g;
    s32 i;
    u8 *e;
    s32 c0;
    s32 t;
    Item *it;
    u8 *tp;
    Vec *v;
    f32 lim;
    s32 ok;
    f32 r;

    h = a->o->m;
    if (pcnt) *pcnt = 0;
    best = r = 1.0f + ray->r / ray->w;
    memset(o, 0, 0x40);
    base = *h->x10;
    tbl = (u8 *)((s32)h + 0x40) + h->x14 * 16 + h->x16 * 8 + h->x18 * 4;
    for (k = 0; k < 8; k++) {
        if (!((1 << k) & mask)) continue;
        for (j = skip != 0; j < a->x6; j++) {
            s = (u8 *)((s32)a + 0x40) + D_00201F2C * (a->x6 * 0x140 + 0x200);
            if (ctx) {
                sl = &ctx->sel[j];
                if (!sl->f.b0) continue;
                if (sl->f.b1) continue;
            }
            idx = s[j * 0x140 + 0x332];
            if (idx == 0xFF) continue;
            if (idx >= h->x1C) continue;
            sceVu0CopyMatrix(&M, s + (j + 1) * 0x140 + 0xC0);
            g = (G *)(tbl + idx * 0x50);
            if (!g->x0) continue;
            if (!g->x10[k]) continue;
            q = (Q *)(base + g->x0);
            it = (Item *)(base + g->x10[k]);
            base2 = (u8 *)(base + g->x4);
            sceVu0CopyVector(&C, (u8 *)q + k * 16 + 0x20);
            C.w = 1.0f;
            sceVu0ApplyMatrix(&C, &M, &C);
            sceVu0SubVector(&C, ray, &C);
            if ((ok = inr(&C, q->sph[k].w + (ray->w + ray->r))) == 0) continue;
            for (i = 0; i < q->n[k]; i++, it++) {
                c0 = 0;
                sceVu0CopyVector(&B, &it->sph);
                B.w = 1.0f;
                sceVu0ApplyMatrix(&B, &M, &B);
                sceVu0SubVector(&B, ray, &B);
                if ((ok = inr(&B, it->sph.w + (ray->w + ray->r))) == 0) continue;
                if (D_00222A18[0] != -1 && i != D_00222A18[0]) continue;
                e = base2 + it->off;
                if (e[0xC] & 1) c0 = 1;
                tp = e + 0x20;
                sceVu0CopyVector(&T[0], e);
                T[0].w = 1.0f;
                sceVu0CopyVector(&T[1], e + 0x10);
                T[1].w = 1.0f;
                sceVu0ApplyMatrix(&T[0], &M, &T[0]);
                sceVu0ApplyMatrix(&T[1], &M, &T[1]);
                for (t = 0; t < it->n - 2; t++, tp += 0x30) {
                    v = &T[(t + 2) % 3];
                    sceVu0CopyVector(v, tp);
                    v->w = 1.0f;
                    sceVu0ApplyMatrix(v, &M, v);
                    if (D_00222A16[0] != -1 && t != D_00222A16[0]) continue;
                    if (Coll_TestCellTriangles_1_00152700(o, a, ray, mode, pcnt, x6, &x7, &X, &Y, T, q, it, tp, &M, &best, t, c0, j) == 1) goto out;
                }
            }
        }
        if (mode == 1 && best < 1.0f) goto out;
    }
out:
    if (best < r) {
        sceVu0CopyVector(o, &X);
        sceVu0CopyVector(o + 1, &Y);
    }
}
