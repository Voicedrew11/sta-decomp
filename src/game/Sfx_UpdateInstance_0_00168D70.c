#include "actor.h"
typedef struct {
    u8 pad0[8];
    u16 f8;
    u8 padA[6];
    u8 f10;
    u8 pad11[3];
    Flags8 f14;
} Dat;
typedef struct {
    u8 pad0[8];
    u16 f8;
    u16 fA;
    u8 padC[0x74];
} Ch;
typedef struct {
    u8 pad0[0x210];
    Dat *dat[24];
    Ch ch[1];
} Mgr;
typedef struct {
    u8 pad0[0x88];
    f32 f88;
    u8 pad8C[4];
    Mgr *f90;
    u16 f94;
    u8 pad96[0x7A];
    s32 f110;
    Flags8 f114;
} Obj;
typedef struct {
    u8 pad0[0x2D];
    Flags8 f2D;
} X;
typedef struct {
    u8 pad0[0xC];
    s8 *fC;
    u8 pad10[0x1D];
    Flags8 f2D;
    u8 pad2E[0x32];
} E;
typedef struct {
    u16 prev;
    u16 next;
    u16 f4;
} Node;
void Sfx_ListInsert_0_0016AF40(u16, u16, u32);
void FxTable_CallA_0_0014D8E0(u16, Obj *);
void Fx_GetWorldMatrix_1_00163C80(Obj *, f32 *);
void sceVu0CopyVector(f32 *, void *);
void SndCh_SetPositionStatic_1_00131330(s32, f32 *);
void SndCh_Stop_2_00131440(s32);
void Attack_TriggerSfxEvent_0_001D21E0(Obj *, s32);
void Mdl_DestroyInstance_0_001745D0(void *, s8 *);
extern E *D_00201FD0;
extern Node *D_00201FD4;
extern u16 D_00201FDC;
extern u8 D_0042D7E0[];

s32 Sfx_UpdateInstance_0_00168D70(u16 id, Obj *o, X *x) {
    f32 v[4];
    f32 m[16];
    Dat *d;
    Ch *ch;
    E *e;

    d = o->f90->dat[o->f94];
    x->f2D.f.b3 = 0;
    if ((d->f10 & 7) == 2) {
        D_00201FD0[id].f2D.f.b2 = 0;
        D_00201FDC--;
    }
    if (o->f114.f.b2) {
        o->f114.f.b0 = 0;
        o->f114.f.b1 = 0;
        o->f114.f.b2 = 0;
        ch = &o->f90->ch[o->f94];
        ch->fA--;
        if (id == ch->f8) {
            ch->f8 = D_00201FD4[ch->f8].f4;
        }
        Sfx_ListInsert_0_0016AF40(ch->f8, id, d->f14.f.b4);
        return 0;
    }
    FxTable_CallA_0_0014D8E0(d->f8, o);
    if (o->f110 != -1) {
        if (o->f114.f.b5) {
            Fx_GetWorldMatrix_1_00163C80(o, m);
            sceVu0CopyVector(v, &m[12]);
        } else {
            sceVu0CopyVector(v, o);
        }
        SndCh_SetPositionStatic_1_00131330(o->f110, v);
        SndCh_Stop_2_00131440(o->f110);
    }
    Attack_TriggerSfxEvent_0_001D21E0(o, 1);
    o->f114.f.b2 = 1;
    o->f88 = (u32)(o->f114.f.b1 = 0);
    if ((d->f10 & 7) == 2) {
        e = &D_00201FD0[id];
        if (e->fC) {
            Mdl_DestroyInstance_0_001745D0(D_0042D7E0, e->fC);
            e->fC = 0;
        }
    }
    return 1;
}
