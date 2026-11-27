#include "common.h"
typedef struct { u8 pad0[0x18]; u16 x18; u8 pad1A[0xA]; Flags8_6x2 f24; Flags8 f25; u8 pad26[4]; u16 x2A; u8 pad2C[4]; } A;
typedef struct { u8 st:2; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } F50;
typedef struct { u8 b0:1; u8 c:2; u8 r:5; } F51;
typedef struct {
    u8 pad0[0x40];
    s32 **x40;
    s32 **x44;
    u8 pad48[8];
    F50 f50;
    F51 f51;
    Flags8 f52;
    Flags8 f53;
    void *x54;
    f32 x58;
    f32 x5C;
    f32 x60;
    u8 pad64[0xC];
    Vec x70;
} B;
typedef struct { u8 pad0[2]; u8 x2; u8 pad3; u16 x4; u16 x6; u16 x8; u8 padA[8]; Flags8 f12; u8 pad13[0xD]; Vec x20; u8 pad30[0x10]; } C;
typedef struct { u8 pad0[8]; u16 x8; u8 padA[2]; f32 xC; f32 x10; f32 x14; u8 pad18[0x18]; Vec x30; } H;
typedef struct { u8 pad0[0x14]; u16 x14; u16 x16; } K;
typedef struct { u8 pad[0x10]; s32 x10; } M;
typedef struct {
    s32 x0;
    M **x4;
    u8 pad8[8];
    Vec x10;
    s32 x20;
    u8 pad24[0x6E - 0x24];
    u16 n;
    u8 pad70[0xB4 - 0x70];
    u8 xB4[0x138 - 0xB4];
    A *x138;
    u8 pad13C[0x170 - 0x13C];
    C *x170;
    u8 pad174[0xC];
    B *x180;
    u8 pad184[0x1D8 - 0x184];
    Flags8 f1D8;
} O;
extern O *D_002022D4;
void MapObj_InitAnim_1_001BB320(O *, s32);
void sceVu0CopyVector(Vec *, Vec *);
void MapObj_CheckProximity_0_001B7F90(A *, B *, s32, s32);
void Trap_SetState_0_001BA850(f32, f32, O *, s32);
void Trap_UpdateIdle_1_001BA680(O *, s32, f32, f32);
void Trap_Update_0_001BA3F0(O *, s32, f32, f32);
s8 *Mdl_GetFrameData_0_001715B0(s32 **);
void Player_GetPos_1_001C9410(Vec *);
f32 Vec_DistB_3_0015DF50(Vec *, s8 *);
void MapObj_SetAnimFrame_0_001B87C0(O *, s32, s32, s32, f32, f32);
void MapState_SetField_0_001A9E10(s32, u16, s32);
f32 Mdl_GetMotionLength_0_00173F70(K *, u16);
void Mdl_AnimateWrap_0_00171B70(H *, u16, f32);
void Mdl_UpdateBoneMatricesCur_0_00171540(H *, B *);
void Mdl_RunMotionEvents_0_001717A0(H *, u16, f32, f32, void (*)(void));
void Trap_Attack_0_001BAA10(void);
void sceVu0ApplyMatrix(Vec *, s8 *, Vec *);
s32 Sfx_IsLoaded_2_00169BB0(s32);
void *Sfx_Spawn_2_00169B50(u16, s32, s32, s32);
void *Sfx_SpawnFromStam_2_00169BD0(u16, s32, u8 *, s32, s32, s32);
void Sfx_SetTransform_1_001677C0(void *, s8 *);

static inline C *getc(O *o, s32 i, s32 ***hp) {
    B *e = &o->x180[i];
    A *e30 = &o->x138[i];
    C *base = o->x170;
    C *t = &base[e30->x18];
    if (e->f50.st && t->f12.f.b3) {
        *hp = e->x44;
        return &base[t->x6];
    }
    *hp = e->x40;
    return t;
}

void MapObj_UpdateAll_0_001BAB70(O *o, f32 dt) {
    s32 i;
    A *a;
    B *b;
    C *c;
    s32 **h;
    H *hh;
    K **x;
    s32 flag;
    B *b2;
    A *a2;
    s8 *sk;
    f32 r;
    u8 t;
    u16 id;
    Vec v;
    B *e;
    A *e30;
    C *base;

    for (i = 0; i < o->n; i++) {
        a = &o->x138[i];
        b = &o->x180[i];
        flag = 0;
        if (!o->f1D8.f.b4) MapObj_InitAnim_1_001BB320(o, i);
        e = &o->x180[i];
        e30 = &o->x138[i];
        base = o->x170;
        c = &base[e30->x18];
        if (e->f50.st && c->f12.f.b3) {
            c = &base[c->x6];
            h = e->x44;
        } else {
            h = e->x40;
        }
        hh = (H *)*h;
        x = *(K ***)hh;
        sceVu0CopyVector(&hh->x30, &o->x10);
        if (o->x20 != 0) b->f51.c = 2;
        MapObj_CheckProximity_0_001B7F90(a, b, o->x0, i);
        switch (c->x4) {
        case 0:
            Trap_SetState_0_001BA850(dt, 0.0f, o, i);
            break;
        case 1:
            a2 = &o->x138[i];
            b2 = &o->x180[i];
            if (b2->f52.f.b6) break;
            if (a2->f24.f.b6 == 2) {
                sk = Mdl_GetFrameData_0_001715B0(b2->x40);
                Player_GetPos_1_001C9410(&v);
                if (Vec_DistB_3_0015DF50(&v, sk + 0x230) <= (f32)a2->x2A) {
                    MapObj_SetAnimFrame_0_001B87C0(o, i, 0xB, 0, 0.0f, 1.0f);
                    b2->f52.f.b6 = 1;
                    MapState_SetField_0_001A9E10(o->x0, i, 1);
                    break;
                }
            }
            Trap_SetState_0_001BA850(dt, 0.0f, o, i);
            break;
        case 2:
            Trap_UpdateIdle_1_001BA680(o, i, dt, 0.0f);
            break;
        case 3:
            if (!o->x180[i].f52.f.b5) Trap_SetState_0_001BA850(dt, 0.0f, o, i);
            break;
        case 4:
            Trap_Update_0_001BA3F0(o, i, dt, 0.0f);
            break;
        case 5:
            if (!o->x180[i].f53.f.b3) Trap_SetState_0_001BA850(dt, 0.0f, o, i);
            break;
        }
        if ((a->f25.f.b0 || (!a->f25.f.b0 && b->f52.f.b3 && b->f53.f.b0)) && (*x)->x16 != 0 && b->f50.b2) {
            r = Mdl_GetMotionLength_0_00173F70(*x, hh->x8);
            hh->x10 = hh->xC;
            if (b->f50.b5) {
                hh->xC -= dt * hh->x14;
            } else {
                hh->xC += dt * hh->x14;
            }
            t = b->f50.b4;
            if (!t && b->f52.f.b3) flag = 1;
            if (b->f50.b3) {
                if (b->f50.b5) {
                    if (hh->xC < 0.0f) hh->xC = hh->xC + r;
                } else {
                    if (!(hh->xC <= r)) hh->xC = hh->xC - r;
                }
            } else {
                if (t) b->f50.b2 = 0;
                if (b->f50.b5) {
                    if (hh->xC < 0.0f) {
                        hh->xC = 0.0f;
                        b->f50.b4 = 1;
                    }
                } else {
                    if (!(hh->xC <= r)) {
                        hh->xC = r;
                        b->f50.b4 = 1;
                    }
                }
            }
            Mdl_AnimateWrap_0_00171B70(hh, hh->x8, hh->xC);
            b->f51.c = 2;
        }
        if (b->f51.c) {
            Mdl_UpdateBoneMatricesCur_0_00171540(hh, b);
            b->f51.c--;
        }
        if (flag) {
            D_002022D4 = o;
            Mdl_RunMotionEvents_0_001717A0(hh, hh->x8, hh->xC, hh->x10, Trap_Attack_0_001BAA10);
        }
        sk = Mdl_GetFrameData_0_001715B0(h);
        if (!b->f52.f.b4 && b->f52.f.b3 && !b->f50.st && c->f12.f.b6) {
            sceVu0CopyVector(&b->x70, &c->x20);
            b->x70.w = 1.0f;
            sceVu0ApplyMatrix(&b->x70, sk + 0x200, &b->x70);
            b->x70.w = c->x20.w * b->x60;
        }
        if (!o->f1D8.f.b4 && a->f24.f.b4 && (id = c->x8) != 0) {
            if (Sfx_IsLoaded_2_00169BB0(id)) {
                b->x54 = Sfx_Spawn_2_00169B50(c->x8, 0, 0, 0);
            } else {
                b->x54 = Sfx_SpawnFromStam_2_00169BD0(c->x8, (*o->x4)->x10, o->xB4, 0, 0, 0);
            }
        }
        if (b->x54 != 0) {
            if (c->x2 < (*x)->x14) {
                Sfx_SetTransform_1_001677C0(b->x54, sk + (c->x2 + 1) * 0x140 + 0xC0);
            } else {
                Sfx_SetTransform_1_001677C0(b->x54, sk + 0x200);
            }
        }
    }
    o->f1D8.f.b4 = 1;
}

