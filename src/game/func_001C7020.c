#include "actor.h"
typedef struct { u8 pad[0x16]; u16 n; } H;
typedef struct { u16 lo:5; u16 mid:5; u16 rest:6; } B;
typedef struct { u8 a; u8 b; B q; } E;
typedef struct { u8 pad[0xC]; f32 c; f32 x10; u8 pad14[0xC]; f32 x20; } R;
typedef struct {
    u8 pad0[0xC];
    H **h;
    u8 pad10[8];
    s8 *x18;
    u8 pad1C[4];
    E *tbl;
    u8 pad24[4];
    R *r;
    u8 pad2C[0x3AA];
    Flags8 f3D6;
    Flags8 f3D7;
} S;
typedef union {
    u8 b;
    struct { u8 b0:1; u8 b1:2; u8 b3:5; } f;
} F3;
void func_001710D0(R *, s16, f32, f32, f32);
void sceVu0CopyVector(s8 *, void *);
f32 func_00173F70(H *, u16);
extern u8 D_003139A0[];
static inline f32 u2f(u32 x) { return x; }

void func_001C7020(u16 idx, f32 t, s32 flags, f32 b, f32 c) {
    H **h;
    S *s;
    B *q;
    u8 a;
    E *e;
    f32 res;

    if (D_002022E4 == NULL) {
        s = NULL;
    } else if (D_002022E4->unk518 == NULL) {
        s = NULL;
    } else {
        s = (S *)(D_002022E4->unk518 + 0x180);
    }
    if (s == NULL) {
        return;
    }
    h = s->h;
    if (h == NULL || *h == NULL) {
        return;
    }
    if ((*h)->n <= 0) {
        return;
    }
    e = &s->tbl[idx];
    a = e->a;
    if (a == 0xFF) {
        return;
    }
    q = &e->q;
    func_001710D0(s->r, a, c * (0.0078125f * u2f(e->b)), 0.033333335f * (b + u2f(q->lo)), 0.033333335f * u2f(q->mid));
    sceVu0CopyVector(s->x18 + 0xA0, D_003139A0);
    if (flags & 2) {
        s->f3D6.f.b7 = 1;
    } else {
        s->f3D6.f.b7 = 0;
    }
    if (flags & 4) {
        s->f3D7.f.b0 = 1;
    } else {
        s->f3D7.f.b0 = 0;
    }
    res = func_00173F70(*h, s->tbl[idx].a);
    if (!(flags & 1)) {
        s->r->c = t;
        s->r->x10 = s->r->c;
        s->r->x20 = s->r->c;
    } else {
        s->r->c = res - t;
        if (s->r->c < 0.0f) {
            s->r->c = 0.0f;
        }
        s->r->x10 = s->r->c;
        s->r->x20 = s->r->c;
    }
    ((F3 *)&s->f3D7)->f.b1 = 0;
}
