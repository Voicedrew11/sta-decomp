#include "actor.h"
#include "obj3d.h"
typedef struct { s32 type; s32 a; s32 b; s32 c; f32 x, y, z, w; f32 h; f32 p; f32 r; s32 f; } Msg;
typedef struct {
    u8 pad[0x39C];
    u32 lo:13;
    u32 b13:1;
    u32 f14:4;
    u32 f18:4;
    u32 hi:10;
    u8 pad3A0[0x414 - 0x3A0];
    Obj3D *x414;
} S;
typedef struct { u8 pad[0x30]; s32 x30; } P;
extern s32 D_002022EC;
extern s32 **D_002022BC;
void func_001C0860(Obj3D *, Obj3D *, s32, s32, f32);
s32 func_001A9D50(s32, u16);
void func_001A9E10(s32, u16, u8);
void func_001AF4A0(Obj3D *);
void func_001AF3F0(Obj3D *);
void memset(void *, s32, s32);
s32 func_00179F80(Msg *);
void func_001CBCD0(s32);

void func_001C0A10(Actor *a, P *p) {
    S *s = (S *)(a->unk518 + 0x180);
    Obj3D *o = s->x414;
    u8 n;
    f32 q;
    s32 *id;
    u16 k;
    Msg msg;

    if (o == NULL) return;
    if (o->xA8.f.b1) goto ret;
    if (o->xA8.f.b0) goto go;
ret:
    return;
go:
    n = s->f18;
    if (n != 0) {
        if (s->b13) {
            q = 1.0f - n / 15.0f;
            func_001C0860(o, o, 0, 0, q * q);
        } else {
            q = n / 15.0f;
            func_001C0860(o, o, D_002022EC, 1, q * (2.0f - q));
        }
        s->f18 = s->f18 + 1;
        if (s->f18 < 15) return;
        if (o->x9E == 2 && o->xA9.f.b2) {
            if (!s->b13) {
                id = *(s32 **)o->x8C;
                func_001A9E10(*id, o->xAC, func_001A9D50(*id, o->xAC) | 2);
            }
            func_001AF4A0(o);
        } else if (!s->b13) {
            if (o->x9E == 0 && (k = o->xAA) != 0 && D_002022BC != NULL && *D_002022BC != NULL) {
                memset(&msg, 0, 0x30);
                                msg.type = 5;
msg.a = k;
                msg.b = **D_002022BC;
                func_00179F80(&msg);
            }
            func_001AF3F0(o);
        }
        s->f18 = 0;
        s->f14 = 0;
        s->x414 = NULL;
        return;
    }
    D_002022EC++;
    if (s->f14 < 15) {
        s->f14 = s->f14 + 1;
        D_002022EC = 0;
    }
    q = s->f14 / 15.0f;
    func_001C0860(o, o, D_002022EC, 0, q * (2.0f - q));
    if (p->x30 & 0x2000) {
        func_001CBCD0(o->x9C);
        s->b13 = 0;
        s->f18 = 1;
        s->f14 = 0;
    } else if (p->x30 & 0x4000) {
        s->b13 = 1;
        s->f18 = 1;
        s->f14 = 0;
    }
}
