#include "common.h"
typedef union { u128 q; u32 w[4]; } Q;
typedef union { u64 d[2]; u128 q; } T;
typedef struct { u8 pad0[2]; u16 x2; u16 x4; u8 pad6[2]; u16 x8; u8 padA[6]; } H;
typedef struct { H h; Vec x10; } E32;
typedef struct { u8 pad0[0xF]; Flags8 xF; } P;
typedef struct { u8 pad0[0x134]; f32 x134; } M;
typedef struct { Flags8 f; u8 pad[3]; } F4;
extern s16 D_00222A18[];
extern Flags8 D_00222A50[];
extern s32 D_00201F4C;
extern s32 D_00201F50;
extern s32 D_00202008;
extern T D_0042D8C0[][2];
extern T D_0042DDC0[][2];
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, M *, Vec *);
s32 Gfx_SphereInFrustum_1_00153FA0(Vec *);
Q *GsPkt_Alloc_3_00154A80(s32);
void GsPkt_Commit_1_00154A70(void);

void Mdl_EmitMeshVu1B_1_0016EB70(P *pp, s8 *a1, Vec *fp, u32 n, M *mt, s32 mode, s32 off, F4 f) {
    Q tag;
    Vec v;
    f32 t;
    H *e;
    s32 cur;
    u32 k;
    Q *q;

    cur = mode;
    for (k = 0; k < n; k++) {
        if (D_00222A18[0] != -1 && D_00222A18[0] != k) continue;
        if (pp->xF.f.b1) {
            e = &((E32 *)a1)[k].h;
            cur = mode;
            if (mode == 2) {
                if (D_00222A50[0].f.b3) {
                    cur = 2;
                } else {
                    sceVu0CopyVector(&v, &((E32 *)a1)[k].x10);
                    v.w = 1.0f;
                    sceVu0ApplyMatrix(&v, mt, &v);
                    t = ((E32 *)a1)[k].x10.w;
                    v.w = t * mt->x134;
                    cur = Gfx_SphereInFrustum_1_00153FA0(&v);
                }
                if (cur < 0) continue;
            }
        } else {
            e = &((H *)a1)[k];
        }
        if (f.f.f.b5) {
            s8 *base = (s8 *)&fp[e->x4];
            q = GsPkt_Alloc_3_00154A80(4);
            tag.q = 0;
            tag.w[0] = 0x30000002;
            tag.w[1] = (u32)D_0042DDC0[(e->x2 << 5) | (f.f.f.b0 << 4) | (f.f.f.b1 << 3) | (f.f.f.b4 << 2) | (f.f.f.b2 << 1) | f.f.f.b6];
            tag.w[3] = 0x6C028000;
            q[0].q = tag.q;
            tag.q = 0;
            tag.w[0] = 0x30000002;
            tag.w[1] = (u32)D_0042D8C0[e->x2];
            tag.w[3] = 0x6C0200A6;
            q[1].q = tag.q;
            tag.q = 0;
            tag.w[0] = e->x8 | 0x30000000;
            tag.w[1] = (u32)(base + off);
            q[2].q = tag.q;
            tag.q = 0;
            tag.w[0] = 0x10000000;
            tag.w[3] = 0x10000000;
            tag.w[2] = D_00201F50 | 0x15000000;
            q[3].q = tag.q;
            GsPkt_Commit_1_00154A70();
        } else {
            s8 *base = (s8 *)&fp[e->x4];
            q = GsPkt_Alloc_3_00154A80(3);
            tag.q = 0;
            tag.w[0] = 0x30000002;
            tag.w[1] = (u32)D_0042DDC0[(e->x2 << 5) | (f.f.f.b0 << 4) | (f.f.f.b1 << 3) | (f.f.f.b4 << 2) | (f.f.f.b2 << 1) | f.f.f.b6];
            tag.w[3] = 0x6C028000;
            q[0].q = tag.q;
            tag.q = 0;
            tag.w[0] = e->x8 | 0x30000000;
            tag.w[1] = (u32)(base + off);
            q[1].q = tag.q;
            tag.q = 0;
            tag.w[0] = 0x10000000;
            if (cur < 2) {
                tag.w[3] = 0x10000000;
                tag.w[2] = D_00202008 | 0x15000000;
            } else {
                tag.w[3] = 0x10000000;
                tag.w[2] = D_00201F4C | 0x15000000;
            }
            q[2].q = tag.q;
            GsPkt_Commit_1_00154A70();
        }
    }
}
