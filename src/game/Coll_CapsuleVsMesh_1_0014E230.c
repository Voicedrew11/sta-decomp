#include "common.h"
typedef struct { Vec v0; Vec v10; u8 pad20[4]; s32 x24; s8 *x28; s8 *x2C; u8 pad30[4]; s32 x34; s32 x38; } Out;
extern Vec D_003139A0;
extern s16 D_00222A18[];
extern s16 D_00222A16[];
void sceVu0CopyVector(void *, void *);
void sceVu0InversMatrix(Mtx *, Mtx *);
void sceVu0ApplyMatrix(Vec *, Mtx *, void *);
void sceVu0CopyMatrix(Mtx *, Mtx *);
void sceVu0Normalize(Vec *, Vec *);
s32 Coll_RayVsAabb_1_0014F0C0(f32, Vec *, Vec *, s8 *);
s32 Coll_SweptVsTriangle_1_0014F520(Vec *, Vec *, Vec *, Vec *, Vec *, s32, s32, s32 *);

typedef f32 FV[4] __attribute__((aligned(16)));
s32 Coll_CapsuleVsMesh_1_0014E230(Out *out, s32 *lst, s32 base, FV o1, FV o2, Mtx *m, u8 mask, u8 flag) {
    Mtx m250;
    Mtx m210;
    Vec CD[2];
    Vec S[2];
    Vec hit[4];
    Vec t[3];
    Vec v150;
    s32 x29C;
    u16 *cnt;
    s8 *s4;
    s8 *s6;
    s32 j;
    s8 *s2;
    s32 k;
    Vec *s0;
    s32 h;
    s8 *q;
    u32 i;
    s32 r;
    s32 ret;
    s32 f2;
    s32 msk;

    ret = 0;
    if (lst[0] == 0) return 0;
    if (lst[2] == 0) return 0;
    h = base + lst[0];
    q = (s8 *)(base + lst[2]);
    r = base + lst[1];
    sceVu0CopyVector(&S[0], o1);
    S[0].w = 1.0f;
    sceVu0CopyVector(&S[1], o2);
    S[1].w = 1.0f;
    sceVu0InversMatrix(&m250, m);
    sceVu0ApplyMatrix(&CD[0], &m250, &S[0]);
    sceVu0ApplyMatrix(&CD[1], &m250, &S[1]);
    sceVu0CopyMatrix(&m210, m);
    sceVu0CopyVector(&m210.m[3], &D_003139A0);
    cnt = (u16 *)h;
    msk = mask;
    for (i = 0; i < 8; i++) {
        if (((1 << i) & msk) && lst[4] != 0 && lst[12] != 0) {
            if (!flag || Coll_RayVsAabb_1_0014F0C0(0.0f, &CD[0], &CD[1], q + 0x20)) {
                s4 = (s8 *)(base + lst[4]);
                s6 = (s8 *)(base + lst[12]);
                for (j = 0; j < *cnt; j++) {
                    f2 = 0;
                    if (D_00222A18[0] == -1 || j == D_00222A18[0]) {
                        if (!flag || Coll_RayVsAabb_1_0014F0C0(0.0f, &CD[0], &CD[1], s6)) {
                            s0 = (Vec *)(r + *(s32 *)(s4 + 4));
                            s2 = (s8 *)s0 + 0x20;
                            if (*((u8 *)s0 + 0xC) & 1) f2 = 1;
                            sceVu0CopyVector(&t[0], s0);
                            t[0].w = 1.0f;
                            sceVu0CopyVector(&t[1], (s8 *)s0 + 0x10);
                            t[1].w = 1.0f;
                            sceVu0ApplyMatrix(&t[0], m, &t[0]);
                            sceVu0ApplyMatrix(&t[1], m, &t[1]);
                            for (k = 0; k < *(u16 *)s4 - 2; k++) {
                                s0 = &t[(k + 2) % 3];
                                sceVu0CopyVector(s0, s2);
                                s0->w = 1.0f;
                                sceVu0ApplyMatrix(s0, m, s0);
                                if (D_00222A16[0] == -1 || k == D_00222A16[0]) {
                                    sceVu0ApplyMatrix(&v150, &m210, s2 + 0x10);
                                    sceVu0Normalize(&v150, &v150);
                                    v150.w = 0.0f;
                                    if (Coll_SweptVsTriangle_1_0014F520(&hit[0], &S[0], &S[1], t, &v150, k, f2, &x29C)) {
                                        sceVu0CopyVector(&S[1], &hit[0]);
                                        S[1].w = 1.0f;
                                        sceVu0CopyVector(&out->v0, &hit[0]);
                                        sceVu0CopyVector(&out->v10, &hit[1]);
                                        out->x24 = h;
                                        ret = 1;
                                        out->x28 = s4;
                                        out->x2C = s2;
                                        out->x38 = 0;
                                        out->x34 = 0;
                                    }
                                }
                                s2 += 0x30;
                            }
                        }
                    }
                    s4 += 0x20;
                    s6 += 0x20;
                }
            }
        }
        lst++;
        q += 0x20;
        cnt++;
    }
    sceVu0CopyVector(o1, &S[0]);
    sceVu0CopyVector(o2, &S[1]);
    return ret;
}
