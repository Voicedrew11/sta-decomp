#include "actor.h"
typedef union { u32 w; Flags8 f; } Col;
typedef struct { Vec p; Vec r; u8 pad[0x40]; Col c; } P;
typedef struct { u8 pad[0x160]; Flags8 f; u8 pad2[3]; s32 h; u8 pad3[8]; } E;
typedef struct { u8 pad[0x240]; Col c; } C;
typedef struct { s32 *pp; u8 pad[0x20]; Flags8 f; } H2;
typedef struct { H2 *h; } H;
typedef struct { u128 q[10]; } Big;
typedef struct {
    u8 pad0[0x78];
    s32 n;
    u8 pad7C[0x19A - 0x7C];
    u8 a[0x100];
    u8 b[0x100];
    u8 pad39A[0x4B0 - 0x39A];
    C *x4B0;
    P *tbl[0x19];
    s8 *x518;
    E *x51C;
    u8 pad520[0x80];
    Flags8 f5A0;
    Flags8 f5A1;
} O;
typedef struct { Vec m[2]; } M;
extern Flags8 D_00222A50[];
extern Big D_004B4C40;
extern u64 D_002F1420[];
s8 *Mdl_GetFrameData_0_001715B0(H *);
void Mdl_SetLayerTex_0_0016B2D0(H *, Col, s32, s32);
void GsPkt_BeginAD_3_001545D0(void);
void GsPkt_SetReg_3_001543E0(s32, u64);
void GsPkt_Flush_1_001544C0(void);
void Mdl_DrawLitWrap_0_0016B960(s8 *, s32, s32, s8 *, s32, s32);
void Fog_ApplyDefault_0_0015B270(void);
void Mdl_DrawMeshesC_1_0016D380(s32, H2 *, s8 *, s32, Col, s32);
void Seg_Init_1_001502A0(M *, P *, Vec *, f32);
void Sfx_SetColor_0_00167670(s32, M *);
void Sfx_SetTransform_1_001677C0(s32, s8 *);
void GsPkt_CloseChain_1_001549D0(void);
void Mdl_FlushLayer_0_0016B280(void);

void Player_DrawWeapon_0_001BCFF0(O *o) {
    u32 sv;
    H *h;
    s32 x;
    s8 *s1;
    s32 i;
    E *e;
    P *p;
    u8 k;
    u8 v;
    Col c;
    Col c2;
    M m;

    sv = D_00222A50[0].f.b3;
    if (o == NULL) return;
    if (!o->f5A0.f.b0 || !o->f5A0.f.b2) return;
    h = *(H **)(o->x518 + 0xB0);
    x = *h->h->pp;
    s1 = Mdl_GetFrameData_0_001715B0(h);
    o->f5A1.f.b6 = 1;
    if (!h->h->f.f.b1) return;
    D_00222A50[0].f.b3 = 1;
    *(Big *)(s1 + 0x10) = D_004B4C40;
    c = o->x4B0->c;
    D_00222A50[0].f.b4 = 1;
    Mdl_SetLayerTex_0_0016B2D0(h, c, 5, 0);
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x40, D_002F1420[0]);
    GsPkt_SetReg_3_001543E0(0x41, D_002F1420[0]);
    GsPkt_Flush_1_001544C0();
    Mdl_DrawLitWrap_0_0016B960(s1, 0, x, s1 + 0x280, 0, 2);
    Fog_ApplyDefault_0_0015B270();
    for (i = 0; i < o->n; i++) {
        v = o->a[i];
        p = o->tbl[v];
        if ((u32)i <= 1 || i == 15 || i == 29) continue;
        if (v == 0xFF) {
            c2 = o->x4B0->c;
        } else {
            c2 = p->c;
        }
        if (!c2.f.f.b3) {
            Mdl_DrawMeshesC_1_0016D380(*h->h->pp, h->h, s1, i, c2, 0);
        }
        k = o->b[i];
        p = o->tbl[k];
        e = &o->x51C[k];
        if (k == 0xFF) continue;
        if (e->h == 0) continue;
        if (e->f.f.b2) continue;
        Seg_Init_1_001502A0(&m, p, &p->r, p->p.w);
        Sfx_SetColor_0_00167670(e->h, &m);
        Sfx_SetTransform_1_001677C0(e->h, (s1 + (i + 1) * 0x140) + 0xC0);
    }
    D_00222A50[0].f.b4 = 0;
    GsPkt_CloseChain_1_001549D0();
    D_00222A50[0].f.b3 = sv;
    Mdl_FlushLayer_0_0016B280();
}
