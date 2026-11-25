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
void func_001419C0(Actor *, f32);
void func_0013CBC0(Actor *, f32);
void func_00171B70(Mdl *, u16, f32);
Pt *func_0013DCA0(Actor *, u8);
Ent *func_0013DC70(Actor *, u8);
void func_00171AF0(Mdl *, u16, u8, u8, f32);
void func_00171980(Mdl *, u16, u8, u8, f32, f32);
void func_001029E8(Vec *, s8 *, s8 *);
void func_00102A60(s8 *, s8 *);
void func_00102A70(s8 *, s8 *);
void func_001370A0(Actor *);
void func_001027B0(Vec *, Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);

void func_0013AB00(Actor *a0, f32 f) {
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
    func_001419C0(a0, f);
    func_0013CBC0(a0, f);
    func_00171B70(s->p28, s->p28->id, s->p28->f);
    for (i = 0; i < *(u32 *)(a0->pad000 + 0x7C); i++) {
        pt = func_0013DCA0(a0, i);
        e = func_0013DC70(a0, i);
        { f32 w = e->f150; s16 id; f32 g; s32 a; s32 b2; if (w != 0.0f) { id = e->id; g = e->f144; a = pt->a; b2 = pt->b;
            if (w == 1.0f) {
                func_00171AF0(s->p28, id, a, b2, g);
            } else {
                func_00171980(s->p28, id, a, b2, g, 1.0f - w);
            }
        } }
    }
    func_001029E8(&v, s->p2C + 0x2B0, s->p18 + 0xA0);
    func_00102A60(s->p18 + 0xA0, s->p2C + 0x2B0);
    func_00102A70(s->p2C + 0x280, s->p18 + 0x60);
    func_001370A0(a0);
    func_001027B0(&s->mA0, &s->m60, &v);
    func_001029D0(&s->m40, &s->m40, &s->mA0);
}
