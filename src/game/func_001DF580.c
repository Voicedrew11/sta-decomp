#include "common.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; s8 b[4]; } Col;
typedef struct { u8 pad0[0x10]; u8 x10[0x18]; s32 x28; u8 x2C[4]; f32 x30; f32 x34; f32 x38; f32 x3C; } O;
#pragma explicit_zero_data on
S D_001F3A30 = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
void func_00181680(s32, void *, void *, void *, S *, u32);
void func_001875C0(f32, f32, f32, s32, s32, Col);
s32 func_00195B10(s32);
void func_001DF580(O *o, s32 a1, u32 mode, Col a3) {
    S buf __attribute__((aligned(16)));
    Col col;
    s32 id = a3.w;
    if (mode < 0x2BC) {
        buf = D_001F3A30;
        buf.x = o->x30;
        buf.y = o->x34;
        func_00181680(o->x28, o, o->x10, o->x2C, &buf, mode);
        return;
    }
    switch (mode) {
    case 0x2BC:
        if (id == 100) id = 10;
        col.w = 0x80808080;
        func_001875C0(o->x38, o->x3C, 0.8f, func_00195B10(id + 0x50), 1, col);
        break;
    case 0x2BD:
        break;
    }
}

