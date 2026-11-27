#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } F;
typedef struct { u8 pad[0x10]; s32 x10; u8 pad14[0x28]; F f3C; } M;
typedef struct { M *m; } O;
typedef struct { u8 pad[0x40]; s32 x40; s32 x44; u8 pad48[0xC]; s32 x54; u8 pad58[0x28]; } E;
typedef struct { s32 p; s32 pad; } P8;
typedef struct {
    s32 pad0;
    O *o;
    s32 x8;
    s32 xC;
    u8 pad10[0x14];
    s32 x24;
    u8 pad28[0x46];
    u16 n6E;
    u16 n70;
    u8 pad72[4];
    u16 n76;
    u16 n78;
    u8 pad7A[8];
    u16 n82;
    u8 pad84[0x30];
    u8 xB4[0xC4];
    s32 *x178;
    P8 *x17C;
    E *x180;
    u8 pad184[8];
    s32 *x18C;
    P8 *x190;
    u8 pad194[4];
    s32 x198[16];
    u8 f1D8;
} S;
void Pool_Free_2_00128580(s32, void *);
void Glow_Enable_0_0015DB60(s32);
void Sfx_Release_1_00167030(s32);
void Sfx_RegisterList_0_00169D00(void *, s32);
void Mdl_Free_0_00170250(s32, O *);
void Mdl_ReleaseTexAnims_0_00170E90(O *);
void Tex_ReleaseList_0_00178030(s32);
void Enemy_Destroy_0_001A6A10(s32);
void ItemObj_FreeOwned_0_001AF740(S **);
void Map_ResetArea_1_001B4F20(S *);
void Mdl_DestroyInstance_0_001745D0(s32, s32);
extern S **D_002022BC;
extern s32 D_002022C4;
extern s32 D_002022D0;

void Map_FreeArea_1_001B5640(S **a0) {
    S *s;
    O *o;
    s32 i;

    E *e;

    if (a0 == NULL || (s = *a0) == NULL) {
        return;
    }
    o = s->o;
    if (D_002022BC == a0) {
        D_002022BC = NULL;
    }
    if (s->f1D8 & 1) {
        Map_ResetArea_1_001B4F20(*a0);
        for (i = 0; i < s->n6E; i++) {
            e = &s->x180[i];
            if (e->x54) {
                Sfx_Release_1_00167030(e->x54);
            }
            Mdl_DestroyInstance_0_001745D0(D_002022D0, e->x40);
            if (e->x44) {
                Mdl_DestroyInstance_0_001745D0(D_002022D0, e->x44);
            }
        }
        for (i = 0; i < s->n82; i++) {
            Enemy_Destroy_0_001A6A10(s->x198[i]);
        }
        for (i = 0; i < s->n70; i++) {
            if (s->x17C[i].p) {
                Enemy_Destroy_0_001A6A10(s->x17C[i].p);
            }
        }
        ItemObj_FreeOwned_0_001AF740(a0);
        for (i = 0; i < s->n78; i++) {
            if (s->x190[i].p) {
                Sfx_Release_1_00167030(s->x190[i].p);
            }
        }
        Sfx_RegisterList_0_00169D00(s->xB4, 0x20);
        for (i = 0; i < s->n76; i++) {
            Glow_Enable_0_0015DB60(s->x18C[i]);
        }
        Mdl_ReleaseTexAnims_0_00170E90(o);
        if (o->m->f3C.b4) {
            Tex_ReleaseList_0_00178030(o->m->x10);
        }
        Mdl_DestroyInstance_0_001745D0(D_002022D0, *s->x178);
        if (s->xC) {
            Pool_Free_2_00128580(D_002022C4, (void *)s->xC);
        }
        Pool_Free_2_00128580(D_002022C4, (void *)s->x8);
    } else if (o) {
        Mdl_ReleaseTexAnims_0_00170E90(o);
        if (o->m->f3C.b4) {
            Tex_ReleaseList_0_00178030(o->m->x10);
        }
        Mdl_Free_0_00170250(D_002022D0, o);
    } else if (s->x24) {
        Pool_Free_2_00128580(D_002022C4, (void *)s->x24);
    }
    Pool_Free_2_00128580(D_002022C4, a0);
}
