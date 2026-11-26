#include "actor.h"
typedef struct { u8 id; u8 spd; u16 x : 5; u16 y : 5; } Rec;
typedef struct { u8 pad[8]; u32 id; f32 f; u8 pad10[0xC]; f32 x1C; } Mdl;
typedef struct {
    u8 pad[0xC];
    s32 *pC;
    u8 pad10[8];
    s8 *p18;
    u8 pad1C[4];
    Rec *p20;
    u8 pad24[4];
    Mdl *p28;
} Sub;
typedef struct { u8 pad[0x140]; s16 id; u8 p142[2]; f32 f144; f32 f148; u8 p14C[4]; f32 f150; } Ent;
static inline f32 u2f(u32 x) { return x; }
u32 func_0013E5E0(Actor *);
Ent *func_0013DC70(Actor *, u8);
f32 func_00173F70(s32, u8);
void func_001710D0(Mdl *, s16, f32, f32, f32);
void sceVu0CopyVector(s8 *, s8 *);
extern s8 D_003139A0[];

void func_0013C0D0(Actor *a, u8 slot, s16 id, s8 dx, s8 dy, u8 flags) {
    f32 scale;
    f32 x;
    f32 y;
    Sub *s;
    Mdl *m;
    Ent *e;
    Rec *r;
    u32 i;

    scale = 1.0f;
    if ((u8)func_0013E5E0(a) & 4) {
        scale = 0.75f;
    }
    if (id == -1) {
        return;
    }
    if (id >= 1000 && slot != 0xFF) {
        e = func_0013DC70(a, slot);
        e->f150 = 1.0f;
        e->id = (*(u8 **)((s8 *)a + 0x514))[id * 4 - 4000];
        e->f148 = scale * (u2f((*(u8 **)((s8 *)a + 0x514))[id * 4 - 3999]) * 0.0078125f);
        e->f144 = 0;
        return;
    }
    i = (u16)id;
    s = (Sub *)(a->unk518 + 0x180);
    r = &s->p20[i];
    x = 0.033333335f * (f32)(dx + r->x);
    y = 0.033333335f * (f32)(dy + r->y);
    if (flags & 2) {
        x = 0.0f;
        s->p28->x1C = 0;
    } else if (flags & 1) {
        m = s->p28;
        if (m->id == r->id && !(m->f < func_00173F70(*s->pC, r->id))) {
            x = 0.0f;
            m->x1C = 0;
        }
    }
    func_001710D0(s->p28, s->p20[i].id, scale * (u2f(s->p20[i].spd) * 0.0078125f), x, y);
    sceVu0CopyVector(s->p18 + 0xA0, D_003139A0);
}
