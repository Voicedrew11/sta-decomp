#include "common.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct { u8 pad[6]; u16 m6; u8 pad8[0x1C]; Bits f24; u8 pad25[0x1B]; u8 m40[1]; } Mdl;
typedef struct {
    Vec m0;
    Vec m10;
    Vec m20;
    Vec m30;
    Vec m40;
    Vec m50;
    u8 pad60[0x50];
    Mdl **pB0;
    u8 mB4;
    u8 mB5;
    u8 mB6;
    u8 mB7;
    u8 padB8[0xB4];
    s32 m16C;
    f32 m170;
} Sub;
typedef struct {
    u8 pad0[0x8C];
    s32 m8C;
    u8 pad90[0xC];
    s32 m9C;
    u8 padA0[0xBC];
    u16 m15C;
    u8 pad15E[6];
    s32 m164;
    u8 pad168[8];
} Ent;
typedef struct { u8 pad[0x20]; u16 m20; u8 pad22[8]; u8 m2A; u8 pad2B; u8 m2C; u8 pad2D[0x7F]; f32 mAC; } Src;
typedef struct A {
    u16 m0;
    u8 pad2[2];
    s32 ***m4;
    s32 **m8;
    s32 mC;
    s32 m10;
    s32 m14;
    s32 m18[0x19];
    s32 m7C;
    u8 pad80;
    u8 m81;
    u8 m82[0x41A];
    s32 m49C;
    s32 m4A0;
    s32 m4A4;
    s32 *m4A8;
    u16 m4AC;
    u8 pad4AE[2];
    s32 m4B0;
    Src *m4B4[0x18];
    s32 m514;
    Sub *m518;
    s32 m51C;
    u8 pad520[0x80];
    Bits f5A0;
} A;
typedef void (*Fn)(A *, f32);
extern Fn D_001F33A0[];
extern s8 D_001F2170[];
extern Vec D_001F2120;
extern s32 D_00201F2C;
extern s32 D_00202278;
extern s32 D_00202280;
Mdl **func_00174230(s32, s32 ***, s32, s32);
void func_00171540(Mdl *, s8 *);
void sceVu0CopyVector(Vec *, void *);
void func_001B59E0(s8 *, Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, void *);
void func_00142930(u8, u8 *);
s32 func_001288C0(s32, s32);
void func_00166F90(s32, s32, s32, s32);
void func_001A7E60(A *);
void func_001A71B0(A *);

void func_001A7420(A **pp) {
    Vec v0;
    Vec v1;
    u8 buf[0x100];
    A *a;
    Sub *b;
    s8 *base;
    s32 ***p4;
    s32 i;
    s32 bs;
    Src *e;
    Ent *ent;
    Mdl *m;

    a = *pp;
    p4 = a->m4;
    bs = *(*p4)[4];
    a->m4B0 = bs + a->m10;
    a->m514 = bs + a->m14;
    for (i = 0; i < a->m7C; i++) {
        a->m4B4[i] = (Src *)(bs + a->m18[i]);
    }
    a->m518 = (Sub *)a->m8[0];
    a->m51C = (s32)a->m518 + 0x640;
    b = a->m518;
    a->m518->pB0 = func_00174230(D_00202280, p4, -1, -1);
    a->m518->pB0[0]->f24.b2 = 0;
    a->m518->pB0[0]->f24.b5 = 1;
    a->m518->m0.y = -170.0f;
    b->m16C = *(u16 *)a->m4B0;
    a->m81 = 0;
    b->mB4 = 0xFF;
    b->mB5 = 0xFF;
    for (i = 0; i < a->m7C; i++) {
        e = ((Src **)a)[i + 0x12D];
        ent = &((Ent *)a->m51C)[i];
        switch (e->m2C & 7) {
        case 1:
            b->mB4 = e->m2A;
            b->mB6 = i;
            break;
        case 2:
            b->mB5 = e->m2A;
            b->mB7 = i;
            break;
        }
        ent->m15C = e->m20;
        ent->m164 = 0;
        if (!(e->mAC <= 0.0f)) {
            a->m82[a->m81] = i;
            a->m81++;
            ent->m8C = 0xC2C80000;
            ent->m9C = 0xC2C80000;
        }
    }
    m = b->pB0[0];
    base = (s8 *)(D_00201F2C * (m->m6 * 0x140 + 0x200) + (s32)m->m40);
    func_00171540(m, D_001F2170);
    sceVu0CopyVector(&v0, base + (b->mB5 + 1) * 0x140 + 0xF0);
    sceVu0CopyVector(&v1, base + (b->mB4 + 1) * 0x140 + 0xF0);
    b->m170 = v0.y - v1.y;
    if (D_001F33A0[a->m0] != 0) D_001F33A0[a->m0](a, 0.0f);
    if (a->m518->m50.x == 0.0f) sceVu0CopyVector(&a->m518->m50, &D_001F2120);
    if (a->m4A8 != 0) {
        s8 *s = (s8 *)*a->m4A8;
        Sub *t = a->m518;
        func_001B59E0(*(s8 **)(s + 0x13C) + a->m4AC * 0x54, &t->m0, &t->m20, &t->m50);
        sceVu0AddVector(&t->m0, &t->m0, s + 0x10);
        sceVu0CopyVector(&t->m10, &t->m0);
        sceVu0CopyVector(&t->m30, &t->m20);
    }
    a->m49C = 0;
    a->m4A4 = 0;
    if (a->m0 != 0) {
        func_00142930(a->m0, buf);
        a->m4A4 = func_001288C0(D_00202278, 0x1554);
        func_00166F90(a->m4A4, a->mC, a->m4A0, 8);
    }
    if (a->m0 != 0) func_001A7E60(a);
    func_001A71B0(a);
    a->f5A0.b1 = 0;
    a->f5A0.b0 = 1;
}
