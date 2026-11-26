#include "actor.h"
typedef struct {
    u8 pad[0x20];
    u8 x20;
    u8 pad21[0x27];
    s32 x48;
} Hit;
typedef struct {
    u8 pad[0x8C];
    s16 x8C;
    u8 pad8E[0x1E];
    Hit *xAC;
    Hit *xB0;
} Obj;
typedef struct {
    u8 pad[0xC0];
    Obj *xC0;
    Hit *xC4;
    Hit *xC8;
    Hit *xCC;
    u8 padD0[0x40];
    s32 x110;
    s32 x114;
} St;
typedef struct {
    u8 pad[0xC];
    u8 lo : 4;
    u8 hi : 4;
    u8 t : 3;
} Ev;
typedef struct { s32 a; s32 b; Obj **p[2]; } DE_t;
extern Obj **D_00201E80[2];
#define DE D_00201E80
void func_0013E2A0(Actor *, s8);
Hit *func_001B1D00(Obj *, void *);
Hit *func_001B1CB0(Obj *, void *, Hit **);
void func_001374E0(Actor *, Obj *, Hit *, Hit *);
s32 func_0013EE30(Actor *);

void func_00139F30(Actor *a) {
    s8 *b;
    s8 *u;
    Ev *ev;
    Obj *obj;
    Hit *r1;
    Hit *r2;
    void *pos;
    Hit *hit;
    obj = 0;
    r1 = 0;
    r2 = 0;
    u = a->unk518;
    b = u + 0x180;
    hit = 0;
    ev = *(Ev **)(u + 0x27C);
    pos = b + 0xD0;
    func_0013E2A0(a, -1);
    if (DE[2]) {
        obj = *DE[2];
        r1 = func_001B1D00(obj, pos);
        if (!r1) {
            r2 = func_001B1CB0(obj, pos, &hit);
            if (!r2) obj = 0;
        }
    }
    if (!obj && DE[3]) {
        obj = *DE[3];
        r1 = func_001B1D00(obj, pos);
        if (!r1) {
            r2 = func_001B1CB0(obj, pos, &hit);
            if (!r2) obj = 0;
        }
    }
    if (obj) {
        (*(St **)(b + 0x10))->xC0 = obj;
        (*(St **)(b + 0x10))->xC4 = r1;
        (*(St **)(b + 0x10))->xC8 = r2;
        (*(St **)(b + 0x10))->xCC = hit;
        if (r2) {
            (*(St **)(b + 0x10))->x110 = (*(St **)(b + 0x10))->x114;
            (*(St **)(b + 0x10))->x114 = hit->x48;
        } else {
            (*(St **)(b + 0x10))->x110 = (*(St **)(b + 0x10))->x114;
            (*(St **)(b + 0x10))->x114 = 0;
        }
    }
    func_001374E0(a, obj, r1, r2);
    if (func_0013EE30(a)) {
        if (DE[2]) {
            Obj *o = *DE[2];
            o->x8C = -1;
            o->xAC = 0;
            o->xB0 = 0;
        }
        if (DE[3]) {
            Obj *o = *DE[3];
            o->x8C = -1;
            o->xAC = 0;
            o->xB0 = 0;
        }
        if (obj) {
            if (r1) obj->x8C = r1->x20;
            if (r2) obj->x8C = r2->x20;
            obj->xAC = r1;
            obj->xB0 = r2;
        }
    }
    if (ev) {
        switch (ev->t) {
        case 2:
            func_0013E2A0(a, ev->lo);
            break;
        case 3:
            break;
        }
    }
}
