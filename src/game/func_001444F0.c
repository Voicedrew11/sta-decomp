#include "common.h"
typedef struct { u8 pad0[0x34]; u16 x34; u16 x36; u8 x38; u8 x39; u8 x3A; u8 x3B; u8 pad3C[4]; } T;
typedef struct { u8 pad0[0x5E0]; f32 x5E0[7]; u8 x5FC[7]; u8 pad603; u16 x604; } O;
typedef struct { u8 pad0[0x24]; s32 x24; u8 pad28[0x18]; } Buf;
typedef struct { u8 pad0[8]; u8 x8; u8 pad9[7]; u16 x10; u8 pad12[6]; f32 x18; u8 pad1C[4]; f32 x20; } Msg;
extern s8 *D_00201FA8;
extern s32 D_00201E80;
u8 *func_00165130(Msg *, s32);
T *func_0013E070(O *);
u32 func_0013EB60(O *);
u32 func_0013E940(O *);
s32 func_0013E220(O *);
u32 func_0013EAA0(O *);
Vec *func_00140460(O *);
Vec *func_00145770(void);
s32 func_0013D500(s32);
f32 func_0011D778(f32);
void func_00102A60(Vec *, Vec *);
void func_00123C40(void *, s32, s32);
void func_0013D320(s32, Buf *, Vec *, s32, s32);

void func_001444F0(Msg *m) {
    u8 list[8];
    Buf buf;
    Vec B;
    Vec A;
    f32 f20;
    u8 mask;
    f32 f21;
    u16 id;
    O *o;
    u8 *res;
    T *e;
    u16 best;
    u8 n;
    u8 i;
    u8 ok;
    u8 r;
    u8 *p;
    u8 flag;

    f20 = m->x18;
    mask = m->x8;
    f21 = m->x20;
    id = m->x10;
    o = *(O **)(D_00201FA8 + 0x154);
    res = func_00165130(m, 4);
    e = func_0013E070(o);
    best = 0xFFFF;
    n = 0;
    *res = 0xFF;
    o->x5FC[0] = 0;
    o->x5FC[1] = 0;
    o->x5FC[2] = 0;
    o->x5FC[3] = 0;
    o->x5FC[4] = 0;
    o->x5FC[5] = 0;
    o->x5FC[6] = 0;
    o->x604 = id;
    if (mask == 0) return;
    for (i = 0; i < 7; i++) {
        if (mask & (1 << i)) {
            o->x5FC[i] |= 1;
            if (!(o->x5E0[i] <= f21)) {
                o->x5E0[i] -= f21;
            } else {
                o->x5E0[i] = 0.0f;
            }
        }
    }
    if (func_0013EB60(o) != 0) return;
    if (func_0013E940(o) != 0) return;
    for (i = 0; i < 7; i++) {
        if (mask & 1) {
            ok = 0;
            p = &o->x5FC[i];
            *p |= 1;
            if (id < e->x36 && !(id < e->x34)) {
                if (!(f20 <= func_0011D778(3.1415927f * (e->x38 / 180.0f)))) {
                    *p |= 2;
                    if (o->x5E0[i] == 0.0f) {
                        o->x5E0[i] = e->x3B / 10.0f;
                        ok = 1;
                    }
                }
            }
            if (ok) {
                r = func_0013D500(100);
                if (r <= e->x3A) {
                if (best > e->x39) {
                    list[0] = i;
                    best = e->x39;
                    n = 1;
                } else if (best == e->x39) {
                    list[n++] = i;
                }
                }
            }
        }
        mask >>= 1;
        e++;
    }
    if (n) {
        *res = list[(u8)func_0013D500(n - 1)];
    } else {
        *res = 0xFF;
    }
    if (*res == 0xFF) return;
    flag = 1;
    if ((u8)func_0013E220(o) == 0x69) flag = 0;
    if (!flag) return;
    if (!func_0013EAA0(o)) return;
    func_00102A60(&A, func_00140460(o));
    A.y -= 100.0f;
    A.w = 1.0f;
    func_00102A60(&B, func_00145770());
    B.w = 1.0f;
    func_00123C40(&buf, 0, 0x40);
    if ((&D_00201E80)[2]) func_0013D320(*(s32 *)(&D_00201E80)[2], &buf, &A, 6, 7);
    if (buf.x24 == 0 && (&D_00201E80)[3]) func_0013D320(*(s32 *)(&D_00201E80)[3], &buf, &A, 6, 7);
    if (buf.x24) *res = 0xFF;
}
