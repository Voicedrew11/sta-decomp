#include "common.h"
typedef union { f32 f; struct { Flags8 b0; Flags8 b1; Flags8 b2; u8 b3; } s; } P;
typedef struct {
    Mtx m;
    Vec x40;
    Vec x50;
    Vec x60;
    Vec x70;
    P x80;
    s8 **x84;
    s32 x88;
    s8 **x8C;
    u8 pad90[0xC];
    s16 x9C;
    s16 x9E;
    u8 padA0[6];
    s8 xA6;
    s8 xA7;
    Flags8 xA8;
    Flags8 xA9;
    u16 xAA;
    s16 xAC;
    s16 xAE;
    s32 xB0;
    f32 xB4;
    s8 *xB8;
    s8 *xBC;
    s8 *xC0[2][2];
} O;
extern s8 D_0030D0E0[];
void func_00167640(s8 *, s32);
void func_0016B200(s8 *, s32);
s32 func_001C9A20(void);
void func_00154700(s32, s32);
s8 *func_001B7300(s8 *, s32);
void func_0015B6B0(Vec *, s8 *);
void func_0015B1C0(Vec *, s8 *);
void func_0015B270(void);
s8 *func_001715B0(s8 **);
s8 *func_001C9B40(void);
void memcpy(void *, void *, s32);
void func_0015CC40(void *, f32);
void func_0016B970(s8 *, void *, s32, s8 *, s32, s32, s32);
void func_0016B960(s8 *, void *, s32, s8 *, s32, s32);
void func_0016C7E0(s32, s8 *, s8 *, P);
void func_0016CD80(s32, s8 *, s8 *, P);
void func_00155900(void);
void func_001B40B0(s8 *);
s32 func_001ACD90(s8 **, s16);

void func_001AC820(O *o, s32 (*cb)(s8 **, P), s32 chk) {
    s32 i;
    Flags8 *f;
    s8 **pp;
    s8 *q;
    s8 **h;
    s32 id;
    s8 *r;
    s8 *v;
    Vec buf;
    u8 buf2[0xA0];
    P p;

    if (o->x9C != -1 && o->xA8.f.b0) {
    if (o->xB8 != NULL) func_00167640(o->xB8, 0);
    if (o->xBC != NULL) func_00167640(o->xBC, 0);
    for (i = 0; i < 4; i++) {
        if (o->xC0[i / 2][i % 2] != NULL) func_00167640(o->xC0[i / 2][i % 2], 0);
    }
    if (o->xA8.f.b7 && !cb(o->x84, o->x80) && (chk == 0 || func_001ACD90(o->x8C, o->xAE))) {
    if (o->x8C != NULL && *o->x8C != NULL) func_001B40B0(*o->x8C);
    p = o->x80;
    f = &p.s.b2;
    f->f.b4 = 0;
    if (o->xB4 < 1.0f) {
        p.s.b0.f.b4 = 1;
        f->f.b4 = 1;
    }
    if (o->xB8 != NULL) {
        func_00167640(o->xB8, 1);
        if (o->xA8.f.b2) func_0016B200(o->xB8, 1);
    }
    if (o->xBC != NULL && func_001C9A20()) {
        func_00167640(o->xBC, 1);
        func_0016B200(o->xBC, 1);
    }
    for (i = 0; i < 4; i++) {
        pp = &o->xC0[i / 2][i % 2];
        if (*pp != NULL) {
            func_00167640(*pp, 1);
            if (o->xA8.f.b2) func_0016B200(*pp, 1);
        }
    }
    if (o->xA8.f.b2) {
        func_00154700(5, 0);
        if (o->x9C / 100 == 3) f->f.b5 = 1;
    }
    q = NULL;
    if (o->xA7 != -1 && o->x8C != NULL) q = func_001B7300(*o->x8C, o->xA7);
    if (q != NULL) {
        func_0015B6B0(&buf, q + 0x20);
        func_0015B1C0(&buf, q + 0x10);
    } else {
        func_0015B270();
    }
    h = o->x84;
    id = ***(s32 ***)h;
    r = func_001715B0(h);
    if (o->xA8.f.b2 && o->x9C == 0x14A) {
        ((Flags8 *)(r + 0x5B8))->f.b3 = 1;
        ((Flags8 *)(r + 0x1738))->f.b3 = 1;
    }
    if (o->xA8.f.b2) {
        if (o->x8C != NULL && *o->x8C != NULL && o->xA6 != -1) {
            v = *(s8 **)(*o->x8C + 0x188) + o->xA6 * 0xA0;
        } else {
            v = func_001C9B40();
        }
    } else if (o->xA6 == -1 || o->x8C == NULL) {
        v = D_0030D0E0;
    } else {
        v = *(s8 **)(*o->x8C + 0x188) + o->xA6 * 0xA0;
    }
    if (o->xB4 < 1.0f) {
        memcpy(buf2, v, 0xA0);
        func_0015CC40(buf2, o->xB4);
        func_0016B970(r, buf2, id, r + 0x200, 0, 2, 1);
    } else {
        func_0016B960(r, v, id, r + 0x200, 0, 2);
    }
    if (o->x80.s.b1.f.b7) {
        func_0016C7E0(id, *h, r, p);
    } else {
        func_0016CD80(id, *h, r, p);
    }
    if (o->xA8.f.b2) func_00155900();
    }
    }
}
