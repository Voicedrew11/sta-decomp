#include "common.h"
typedef struct { u8 p0[0xC]; f32 r; Vec dir; } Ray;   /* 0x1C = dir.w */
typedef struct { s32 off[4]; s32 x10[8]; s32 x30[8]; } Hdr;
typedef struct { u16 n; u16 pad; s32 off; u8 p8[0x18]; } Item;
typedef struct { Vec v; u8 p10[0x20]; } Tri;
typedef struct { Vec a; Vec b; u8 p20[0x20]; } Res;
typedef struct { Vec a; Vec b; s32 x20; u16 *x24; Item *x28; Tri *x2C; s32 x30; s32 x34; s32 x38; } Out;
typedef struct { u8 b[0x20]; } Box;
extern s16 D_00222A18[];
extern s16 D_00222A16[];
void sceVu0CopyVector(Vec *, void *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0InversMatrix(Mtx *, Mtx *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
s32 Coll_RayVsAabb_1_0014F0C0(Vec *, Vec *, f32, void *);
s32 Coll_TestTriangle_1_00152D90(Res *, Ray *, Vec *, Tri *, Mtx *, s32, s32);

s32 Coll_RayVsMesh_1_0014DDE0(Out *out, Hdr *h, s32 base, Ray *ray, Mtx *m, u8 mask, u8 flag) {
    u16 *cnt;
    Box *bx;
    Item *it;
    s32 j;
    Tri *t;
    s32 i;
    u8 *e;
    u16 *q0;
    Box *q8;
    u32 k;
    u8 *q4;
    s32 ret;
    s32 c0;
    f32 best;
    Mtx M;
    Vec D;
    Vec C;
    Vec S[2];
    Res res;
    Vec tri[3];
    Vec *v;

    ret = 0;
    if (h->off[0] == 0) return 0;
    if (h->off[2] == 0) return 0;
    q0 = (u16 *)(base + h->off[0]);
    q8 = (Box *)(base + h->off[2]);
    q4 = (u8 *)(base + h->off[1]);
    sceVu0CopyVector(&S[0], ray);
    S[0].w = 1.0f;
        sceVu0ScaleVector(&S[1], &ray->dir, ray->dir.w);
    sceVu0AddVector(&S[1], &S[1], &S[0]);
    S[1].w = 1.0f;
    sceVu0InversMatrix(&M, m);
    sceVu0ApplyMatrix(&C, &M, &S[0]);
    sceVu0ApplyMatrix(&D, &M, &S[1]);
    best = 1.0f;
    if (!(ray->dir.w <= 0.0f)) best += ray->r / ray->dir.w;
    cnt = q0;
    for (k = 0; k < 8; h = (Hdr *)&h->off[1], q8++, k++) {
        if (!((1 << k) & mask)) continue;
        if (!h->x10[0]) continue;
        if (!h->x30[0]) continue;
        if (flag && !Coll_RayVsAabb_1_0014F0C0(&C, &D, ray->r, &q8[1])) continue;
        it = (Item *)(base + h->x10[0]);
        bx = (Box *)(base + h->x30[0]);
        for (j = 0; j < cnt[k]; j++, it++, bx++) {
            c0 = 0;
            if (D_00222A18[0] != -1 && j != D_00222A18[0]) continue;
            if (flag && !Coll_RayVsAabb_1_0014F0C0(&C, &D, ray->r, bx)) continue;
            e = q4 + it->off;
            t = (Tri *)(e + 0x20);
            if (e[0xC] & 1) c0 = 1;
            sceVu0CopyVector(&tri[0], e);
            tri[0].w = 1.0f;
            sceVu0CopyVector(&tri[1], e + 0x10);
            tri[1].w = 1.0f;
            sceVu0ApplyMatrix(&tri[0], m, &tri[0]);
            sceVu0ApplyMatrix(&tri[1], m, &tri[1]);
            for (i = 0; i < it->n - 2; i++, t++) {
                v = &tri[(i + 2) % 3];
                sceVu0CopyVector(v, t);
                v->w = 1.0f;
                sceVu0ApplyMatrix(v, m, v);
                if (D_00222A16[0] != -1 && i != D_00222A16[0]) continue;
                if (Coll_TestTriangle_1_00152D90(&res, ray, tri, t, m, i, c0) && res.a.w < best) {
                    best = res.a.w;
                    sceVu0CopyVector(&out->a, &res.a);
                    sceVu0CopyVector(&out->b, &res.b);
                    out->x24 = q0;
                    ret = 1;
                    out->x28 = it;
                    out->x2C = t;
                    out->x38 = 0;
                    out->x34 = 0;
                }
            }
        }
    }
    return ret;
}
