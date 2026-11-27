#include "common.h"
typedef struct { u8 pad0[0x24]; Flags8 x24; } M;
typedef struct { u8 pad0[0x40]; M **x40; M **x44; s32 x48; s32 x4C;
    u32 p0:6; u32 a:1; u32 b:1; u32 c:1; u32 d:2; u32 f:8; u32 g:1; u32 rest:12;
    u8 pad54[4]; f32 x58; u8 pad5C[4]; f32 x60; u8 pad64[0x1C]; } E;
typedef struct { u8 pad0[0x18]; u16 x18; u8 pad1A[0x16]; } S;
typedef struct { u16 x0; u8 pad2[4]; u16 x6; u8 pad8[0xA]; Flags8 x12; u8 pad13; u16 x14; u8 pad16[0x2A]; } T;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } P;
typedef struct { u8 pad0[0x10]; s32 x10; } C10;
typedef struct {
    u8 pad0[4];
    C10 **x4;
    u8 pad8[0x1C];
    s32 x24;
    u8 pad28[0x46];
    u16 x6E;
    u8 pad70[0x10];
    u16 x80;
    u8 pad82[0xB6];
    S *x138;
    u8 pad13C[0x34];
    T *x170;
    u8 pad174[0xC];
    E *x180;
    u8 pad184[0x10];
    P *x194;
} O;
extern s32 D_00201F2C;
void Tex_LoadAnimated_0_0016FB80(s32, s32, s32 **, s32 **, s32 **);
void Mdl_SetDrawFlag_0_0016F410(s32, s32, s32);
s32 Frame_IncCounter_1_0015C9E0(void);
void Map_DecodeTransform_0_001B59E0(S *, Vec *, Vec *, Vec *);
void Mtx_Compose_2_00173FD0(E *, Vec *, Vec *, Vec *);
M **Mdl_CreateInstance_0_00174230(s32, s32, s32, s32);
void Mdl_UpdateBoneMatricesCur_0_00171540(M *, E *);
#define MAX(a, b) ((a) < (b) ? (b) : (a))

void MapObj_Create_0_001BB8A0(s32 a0, O *o, s32 a2) {
    Vec v0;
    Vec v1;
    Vec v2;
    s32 *A[256];
    s32 *B[256];
    s32 *C[256];
    s32 i;
    S *s;
    s32 k;
    E *e;
    T *t;
    s16 id;

    if (a2) {
        for (i = 0; i < o->x80; i++) {
            A[i] = &o->x194[i].x0;
            B[i] = &o->x194[i].x4;
            C[i] = &o->x194[i].xC;
        }
        Tex_LoadAnimated_0_0016FB80(a0, (*o->x4)->x10, A, B, C);
        for (i = 0; i < o->x80; i++) {
            Mdl_SetDrawFlag_0_0016F410(*(s32 *)*A[i], o->x24, 0);
        }
    }
    for (i = 0; i < o->x6E; i++) {
        s = &o->x138[i];
        e = &o->x180[i];
        t = &o->x170[s->x18];
        id = s->x18;
        e->x48 = Frame_IncCounter_1_0015C9E0();
        e->x4C = t->x14;
        e->a = t->x12.f.b1;
        e->b = t->x12.f.b2;
        e->c = t->x12.f.b3;
        e->f = 0xFF;
        e->g = 1;
        e->d = 2;
        e->x58 = 1.0f;
        Map_DecodeTransform_0_001B59E0(s, &v0, &v1, &v2);
        Mtx_Compose_2_00173FD0(e, &v0, &v1, &v2);
        e->x60 = MAX(MAX(v2.x, v2.y), v2.z);
        e->x40 = Mdl_CreateInstance_0_00174230(a0, o->x194[id].x0, -1, -1);
        (*e->x40)->x24.f.b2 = 0;
        for (k = 0; k < 2; k++) {
            D_00201F2C = k;
            Mdl_UpdateBoneMatricesCur_0_00171540(*e->x40, e);
        }
        if (t->x12.f.b3 && o->x170[t->x6].x0 < o->x80) {
            e->x44 = Mdl_CreateInstance_0_00174230(a0, o->x194[o->x170[t->x6].x0].x0, -1, -1);
            (*e->x44)->x24.f.b2 = 0;
            for (k = 0; k < 2; k++) {
                D_00201F2C = k;
                Mdl_UpdateBoneMatricesCur_0_00171540(*e->x44, e);
            }
        }
    }
}
