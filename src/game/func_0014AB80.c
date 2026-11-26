#include "actor.h"
typedef struct { u8 p:2; u8 v:1; } B2;
typedef struct {
    u8 pad0[0x60];
    f32 x60;
    f32 x64;
    u8 pad68[8];
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    u8 pad80[8];
    f32 x88;
    u8 pad8C[4];
    u8 *x90;
    u8 pad94[0x1C];
    f32 xB0;
    u8 padB4[0x60];
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:1;
} O;
typedef struct { u8 pad[0x30]; f32 v[4]; } M;
void sceVu0CopyVector(void *, void *);
Actor *func_00147450(f32, void *);
void func_00163C80(O *, M *);
s8 *func_00145730(void);
extern s8 D_001F2160[];

void func_0014AB80(O *o) {
    Actor *a;
    s32 f;
    f32 pos[4];
    M m;
    f32 t;

    f = 1;
    if (o->x60 == 0.0f) {
        f = 0;
    }
    if ((s32)o->x64 == 0) {
        if (o->b5) {
            func_00163C80(o, &m);
            sceVu0CopyVector(pos, m.v);
        } else {
            sceVu0CopyVector(pos, o);
        }
        a = func_00147450(1000.0f, pos);
    } else {
        a = D_002022E4;
    }
    if (a == NULL) {
        o->x88 = (f32)(u32)(o->b1 = 0);
        ((B2 *)(o->x90 + 0x188))->v = 0;
        return;
    }
    if (*(u16 *)a != 0) {
        sceVu0CopyVector(o, a != NULL ? a->unk518 + 0x90 : D_001F2160);
    } else {
        sceVu0CopyVector(o, D_002022E4 != NULL ? func_00145730() : D_001F2160);
    }
    if (f != 0) {
        t = (f32)(u32)*(u16 *)(a->unk4B0 + 4) * o->x60;
        o->x70 = o->x74 = o->x78 = t;
        o->x7C = 1.0f;
        o->xB0 = t;
    }
}
