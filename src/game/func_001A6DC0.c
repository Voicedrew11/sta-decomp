#include "actor.h"
typedef struct {
    u8 pad[0xB0];
    s32 *pB0;
    u8 padB4[0xC];
    u8 mC0[0x60];
    Flags8 f120;
    u8 pad121[0x23];
    u8 m144[0x28];
    s32 m16C;
} Sub;
typedef struct {
    u8 m00[0x20];
    u8 m20[0x20];
    u8 m40[0x20];
    u8 m60[0x20];
    u8 pad80[0xC];
    s32 m8C;
    u8 pad90[0xC];
    s32 m9C;
    u8 padA0[0xBC];
    u16 m15C;
    u8 pad15E[2];
    Flags8 f160;
    u8 pad161[0xF];
} Ent;
typedef struct { u8 pad[0x20]; u16 m20; u8 pad22[0x8A]; f32 mAC; } Src;
extern s8 D_001F2170[];
void func_00123C40(void *, s32, s32);
void func_001A8510(Actor *, u8);
void func_001A8670(Actor *, u8);
void func_00166F90(s32, s32, s32, s32);
void func_00171270(s32, s8 *, s32);

void func_001A6DC0(Actor *a0) {
    Sub *b;
    u32 i;
    Src *e;
    Ent *ent;
    u16 *t;

    if (a0 != 0 && *(u16 *)a0 != 0) {
    t = (u16 *)a0->unk4B0;
    b = (Sub *)a0->unk518;
    b->m16C = *t;
    b->f120.f.b0 = 0;
    b->f120.f.b1 = 0;
    func_00123C40(b->mC0, 0, 0x60);
    func_00123C40(b->m144, 0, 0x28);
    for (i = 0; i < *(u32 *)(a0->pad000 + 0x7C); i++) {
        e = ((Src **)a0)[i + 0x12D]; /* (&a0->unk4B4)[i], indexed from a0 for the walk */
        ent = &((Ent *)a0->unk51C)[i];
        ent->m15C = e->m20;
        ent->f160.f.b0 = 0;
        ent->f160.f.b2 = 0;
        func_00123C40(ent->m00, 0, 0x20);
        func_00123C40(ent->m20, 0, 0x20);
        func_00123C40(ent->m40, 0, 0x20);
        func_00123C40(ent->m60, 0, 0x20);
        if (!(e->mAC <= 0.0f)) {
            ent->m8C = 0xC2C80000;
            ent->m9C = 0xC2C80000;
        }
        func_001A8510(a0, i);
        func_001A8670(a0, i);
    }
    func_00123C40(a0->pad520, 0, 0x18);
    a0->pad000[0x80] = 0;
    a0->flags5A1.f.b5 = 0;
    func_00166F90(*(s32 *)(a0->pad000 + 0x4A4), *(s32 *)(a0->pad000 + 0xC), *(s32 *)(a0->pad000 + 0x4A0), 8);
    func_00171270(*b->pB0, D_001F2170, 0);
    func_00171270(*b->pB0, D_001F2170, 1);
    }
}
