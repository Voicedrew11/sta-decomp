#include "common.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } F;
typedef struct { u16 x0, x2, x4, x6, x8; u8 padA[6]; } E;
typedef struct { E e; Vec v; } E2;
typedef struct { u8 pad[0xF]; u8 b0:1; u8 b1:1; } H;
typedef struct { u8 pad[0x134]; f32 x134; } M;
extern s16 D_00222A18[];
extern Flags8 D_00222A50[];
extern Q D_0042DDC0[][2];
extern Q D_0042D8C0[][2];
extern u32 D_00201F50;
extern u32 D_00201F4C;
extern u32 D_00202008;
extern Q *GsPkt_Alloc_3_00154A80(s32);
extern void GsPkt_Commit_1_00154A70(void);
s32 Gfx_SphereInFrustum_1_00153FA0(Vec *);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, M *, Vec *);
void Mdl_BindTexture_0_0016F440(s32, s32, u8 *, s32, F *);

void Mdl_EmitMeshVu1_1_0016E760(H *h, E2 *arr, u8 *verts, u32 n, M *mtx, s32 mode, s32 off, u8 *tex, s32 a8, s32 a9, F f) {
    E *e;
    s32 m;
    u32 i;
    u8 *vp;
    Q *p;
    Q q;
    Vec v;

    m = mode;
    for (i = 0; i < n; i++) {
        if (D_00222A18[0] != -1 && D_00222A18[0] != i) continue;
        if (h->b1) {
            m = mode;
            e = &arr[i].e;
            if (m == 2) {
                if (D_00222A50[0].f.b3) {
                    m = 2;
                } else {
                    sceVu0CopyVector(&v, &arr[i].v);
                    v.w = 1.0f;
                    sceVu0ApplyMatrix(&v, mtx, &v);
                    v.w = ((E2 *)e)->v.w * mtx->x134;
                    m = Gfx_SphereInFrustum_1_00153FA0(&v);
                }
                if (m < 0) continue;
            }
        } else {
            e = &((E *)arr)[i];
        }
        vp = verts + e->x4 * 16;
        if (e->x0 != 0xFFFF) {
            Mdl_BindTexture_0_0016F440(a8, a9, tex + e->x0 * 64, off, &f);
        }
        if (f.b5) {
            p = GsPkt_Alloc_3_00154A80(4);
            q.q = 0;
            q.w[0] = 0x30000002;
            q.w[1] = (u32)&D_0042DDC0[(e->x2 << 5) | (f.b0 << 4) | (f.b1 << 3) | (f.b4 << 2) | (f.b2 << 1) | f.b6];
            q.w[3] = 0x6C028000;
            p[0].q = q.q;
            q.q = 0;
            q.w[0] = 0x30000002;
            q.w[1] = (u32)&D_0042D8C0[e->x2];
            q.w[3] = 0x6C0200A6;
            p[1].q = q.q;
            q.q = 0;
            q.w[0] = e->x8 | 0x30000000;
            q.w[1] = (u32)(vp + off);
            p[2].q = q.q;
            q.q = 0;
            q.w[0] = 0x10000000;
            q.w[3] = 0x10000000;
            q.w[2] = D_00201F50 | 0x15000000;
            p[3].q = q.q;
            GsPkt_Commit_1_00154A70();
        } else {
            p = GsPkt_Alloc_3_00154A80(3);
            q.q = 0;
            q.w[0] = 0x30000002;
            q.w[1] = (u32)&D_0042DDC0[(e->x2 << 5) | (f.b0 << 4) | (f.b1 << 3) | (f.b4 << 2) | (f.b2 << 1) | f.b6];
            q.w[3] = 0x6C028000;
            p[0].q = q.q;
            q.q = 0;
            q.w[0] = e->x8 | 0x30000000;
            q.w[1] = (u32)(vp + off);
            p[1].q = q.q;
            q.q = 0;
            q.w[0] = 0x10000000;
            if (m < 2) {
                q.w[3] = 0x10000000;
                q.w[2] = D_00202008 | 0x15000000;
            } else {
                q.w[3] = 0x10000000;
                q.w[2] = D_00201F4C | 0x15000000;
            }
            p[2].q = q.q;
            GsPkt_Commit_1_00154A70();
        }
    }
}
