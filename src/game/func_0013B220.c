#include "common.h"
typedef struct { u8 pad[8]; u16 id; u8 pada[2]; f32 x; f32 y; } Anim;
typedef struct { u8 pad[0x10]; Vec v; u8 pad20[0xA0]; s32 xC0; } Sub10;
typedef struct { u8 pad[0x40]; Vec v; } Sub18;
typedef struct {
    u8 pad[0x10];
    Sub10 *p10;
    u8 pad14[4];
    Sub18 *p18;
    u8 pad1C[0xC];
    Anim *p28;
    u8 pad2C[0x14];
    Vec v40;
    Vec v50;
    u8 pad60[0x40];
    Vec vA0;
    u8 padB0[0x44];
    s32 xF4;
} Body;
typedef struct Obj Obj;
typedef void (*Cb)(Obj *, f32);
struct Obj {
    u8 pad[0x518];
    s8 *unk518;
    u8 pad51C[0x1C];
    s32 x538;
    Cb f53C;
    Cb f540;
    Cb f544;
    void *f548;
};
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0CopyVector(void *, void *);
s32 func_0013EE30(Obj *);
void func_0013EAE0(Obj *, s32);
void func_0013EAB0(Obj *, s32);
void func_001717A0(Anim *, u16, f32, f32, void *);
void func_00139D30();
void func_00137730(Obj *, Vec *);
void func_0013A2C0(Obj *, f32);
void func_0013A450(Obj *, f32);
void func_0013A720(Obj *, f32);
void func_00136400(Obj *, f32);
void func_0013A190(Obj *, f32);
void func_00139F30(Obj *);
void func_00139E20(Obj *);
void func_001C5DE0(Obj *);
void func_001A83E0(Obj *);
extern s32 D_00201E80;

void func_0013B220(Obj *a, s32 skip, f32 dt) {
    Body *b;
    Vec v;

    b = (Body *)(a->unk518 + 0x180);
    if (!func_0013EE30(a) && skip) {
        return;
    }
    func_0013EAE0(a, 0);
    func_0013EAB0(a, 0);
    if (a->f548) {
        func_001717A0(b->p28, b->p28->id, b->p28->x, b->p28->y, a->f548);
    } else {
        func_001717A0(b->p28, b->p28->id, b->p28->x, b->p28->y, func_00139D30);
    }
    if (!func_0013EE30(a)) {
        func_00137730(a, &b->vA0);
        func_0013A2C0(a, dt);
    }
    if (!func_0013EE30(a) && ((&D_00201E80)[2] || (&D_00201E80)[3])) {
        if (a->f53C) {
            a->f53C(a, dt);
        } else {
            func_0013A450(a, dt);
            func_0013A720(a, dt);
        }
    }
    if (!skip) {
        if (a->f540) {
            a->f540(a, dt);
        } else {
            func_00136400(a, dt);
        }
    }
    if (func_0013EE30(a)) {
        sceVu0SubVector(&v, &b->v40, &b->p10->v);
        func_00137730(a, &v);
        func_0013A190(a, dt);
        sceVu0CopyVector(&v, &b->v40);
        if (a->f53C) {
            a->f53C(a, dt);
        }
        b->p10->xC0 = 0;
        if (b->xF4) {
            func_00139F30(a);
        }
        if (a->f544) {
            a->f544(a, dt);
        }
        sceVu0SubVector(&v, &b->v40, &v);
        func_00137730(a, &v);
    } else {
        b->p10->xC0 = 0;
        func_00139F30(a);
        if (a->f544) {
            a->f544(a, dt);
        } else {
            func_00139E20(a);
        }
    }
    if (a->x538) {
        if (func_0013EE30(a)) {
            func_001C5DE0(a);
        }
    } else {
        func_001A83E0(a);
    }
    sceVu0CopyVector(b->p18, &b->v40);
    sceVu0CopyVector(&b->p18->v, &b->v50);
}
