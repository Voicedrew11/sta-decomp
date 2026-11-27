#include "actor.h"
typedef struct { u8 pad[8]; u16 id; u8 pad2[2]; f32 f; } Mdl;
typedef struct {
    u8 pad[0x18];
    s8 *p18;
    u8 pad1C[0xC];
    Mdl *p28;
    s8 *p2C;
    u8 pad30[0x10];
    Vec m40;
    u8 pad50[0x10];
    Vec m60;
    u8 pad70[0x30];
    Vec mA0;
} Sub;
typedef struct { u8 pad[0x140]; s16 id; u8 p142[2]; f32 f144; u8 p148[8]; f32 f150; } Ent;
typedef struct { u8 pad[0x2A]; u8 a; u8 b; } Pt;
typedef struct { u8 pad[0x7C]; u32 n; } A7C;
void EnemyScr_Event2012_1_001419C0(Actor *, f32);
void Enemy_UpdateMotion_1_0013CBC0(Actor *, f32);
void Mdl_AnimateWrap_0_00171B70(Mdl *, u16, f32);
Pt *Enemy_GetPartValue_1_0013DCA0(Actor *, u8);
Ent *Enemy_GetPart_1_0013DC70(Actor *, u8);
void Mdl_AnimateCur_0_00171AF0(Mdl *, u16, u8, u8, f32);
void Mdl_BlendMotion_0_00171980(Mdl *, u16, u8, u8, f32, f32);
void sceVu0SubVector(Vec *, s8 *, s8 *);
void sceVu0CopyVector(s8 *, s8 *);
void sceVu0CopyMatrix(s8 *, s8 *);
void Actor_UpdateBones_0_001370A0(Actor *);
void sceVu0ApplyMatrix(Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);

void Actor_UpdateAttachments_0_0013AB00(Actor *a0, f32 f) {
    Sub *s;
    u32 i;
    Pt *pt;
    Ent *e;
    s8 *b;
    Vec v;
    void (*cb)(Actor *, f32);

    b = a0->unk518;
    s = (Sub *)(b + 0x180);
    if (*(u16 *)(**(s8 ***)(b + 0x18C) + 0x16) == 0) {
        return;
    }
    if (a0->flags5B7.f.b6) {
        f = 0.0f;
    }
    cb = *(void (**)(Actor *, f32))((s8 *)a0 + 0x538);
    if (cb != 0) {
        cb(a0, f);
        return;
    }
    EnemyScr_Event2012_1_001419C0(a0, f);
    Enemy_UpdateMotion_1_0013CBC0(a0, f);
    Mdl_AnimateWrap_0_00171B70(s->p28, s->p28->id, s->p28->f);
    for (i = 0; i < *(u32 *)(a0->pad000 + 0x7C); i++) {
        pt = Enemy_GetPartValue_1_0013DCA0(a0, i);
        e = Enemy_GetPart_1_0013DC70(a0, i);
        { f32 w = e->f150; s16 id; f32 g; s32 a; s32 b2; if (w != 0.0f) { id = e->id; g = e->f144; a = pt->a; b2 = pt->b;
            if (w == 1.0f) {
                Mdl_AnimateCur_0_00171AF0(s->p28, id, a, b2, g);
            } else {
                Mdl_BlendMotion_0_00171980(s->p28, id, a, b2, g, 1.0f - w);
            }
        } }
    }
    sceVu0SubVector(&v, s->p2C + 0x2B0, s->p18 + 0xA0);
    sceVu0CopyVector(s->p18 + 0xA0, s->p2C + 0x2B0);
    sceVu0CopyMatrix(s->p2C + 0x280, s->p18 + 0x60);
    Actor_UpdateBones_0_001370A0(a0);
    sceVu0ApplyMatrix(&s->mA0, &s->m60, &v);
    sceVu0AddVector(&s->m40, &s->m40, &s->mA0);
}
