#include "common.h"
typedef struct { Vec v0; Vec v10; u8 pad20[4]; s32 x24; s8 *x28; s8 *x2C; u8 pad30[4]; s32 x34; s32 x38; } Out;
extern Vec D_003139A0;
extern s16 D_00222A18[];
extern s16 D_00222A16[];
void func_00102A60(Vec *, void *);
void func_001028F8(Mtx *, Mtx *);
void func_001027B0(Vec *, Mtx *, void *);
void func_00102A70(Mtx *, Mtx *);
void func_00102870(Vec *, Vec *);
s32 func_0014F0C0(f32, Vec *, Vec *, s8 *);
s32 func_0014F520(Vec *, Vec *, Vec *, Vec *, Vec *, s32, s32, s32 *);

s32 func_0014E230(Out *out, s32 *lst, s32 base, Vec *o1 __attribute__((aligned(16))), Vec *o2 __attribute__((aligned(16))), Mtx *m, u8 mask, u8 flag) {
    Mtx m250;
    Mtx m210;
    Vec v200;
    Vec v1F0;
    Vec v1E0;
    Vec v1D0;
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
    func_00102A60(&v1D0, o1);
    v1D0.w = 1.0f;
    func_00102A60(&v1E0, o2);
    (&v1E0)->w = 1.0f;
    func_001028F8(&m250, m);
    func_001027B0(&v1F0, &m250, &v1D0);
    func_001027B0(&v200, &m250, &v1E0);
    func_00102A70(&m210, m);
    func_00102A60(&m210.m[3], &D_003139A0);
    cnt = (u16 *)h;
    msk = mask;
    for (i = 0; i < 8; i++) {
        if (((1 << i) & msk) && lst[4] != 0 && lst[12] != 0) {
            if (!flag || func_0014F0C0(0.0f, &v1F0, &v200, q + 0x20)) {
                s4 = (s8 *)(base + lst[4]);
                s6 = (s8 *)(base + lst[12]);
                for (j = 0; j < *cnt; j++) {
                    f2 = 0;
                    if (D_00222A18[0] == -1 || j == D_00222A18[0]) {
                        if (!flag || func_0014F0C0(0.0f, &v1F0, &v200, s6)) {
                            s0 = (Vec *)(r + *(s32 *)(s4 + 4));
                            s2 = (s8 *)s0 + 0x20;
                            if (*((u8 *)s0 + 0xC) & 1) f2 = 1;
                            func_00102A60(&t[0], s0);
                            t[0].w = 1.0f;
                            func_00102A60(&t[1], (s8 *)s0 + 0x10);
                            t[1].w = 1.0f;
                            func_001027B0(&t[0], m, &t[0]);
                            func_001027B0(&t[1], m, &t[1]);
                            for (k = 0; k < *(u16 *)s4 - 2; k++) {
                                s0 = &t[(k + 2) % 3];
                                func_00102A60(s0, s2);
                                s0->w = 1.0f;
                                func_001027B0(s0, m, s0);
                                if (D_00222A16[0] == -1 || k == D_00222A16[0]) {
                                    func_001027B0(&v150, &m210, s2 + 0x10);
                                    func_00102870(&v150, &v150);
                                    v150.w = 0.0f;
                                    if (func_0014F520(&hit[0], &v1D0, &v1E0, t, &v150, k, f2, &x29C)) {
                                        func_00102A60(&v1E0, &hit[0]);
                                        v1E0.w = 1.0f;
                                        func_00102A60(&out->v0, &hit[0]);
                                        func_00102A60(&out->v10, &hit[1]);
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
    func_00102A60(o1, &v1D0);
    func_00102A60(o2, &v1E0);
    return ret;
}
