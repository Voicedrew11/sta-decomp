#include "actor.h"
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 xB;
    u8 padC[2];
    u8 xE;
} Obj18EC40;
s32 func_0017F470(s32 arg0, s32 arg1, f32 val);
void func_00131600(s32, u8);
void func_0012C320(void);
void func_0012C720(s32);
void func_0012C6B0(void);
extern s32 D_004A10D0[];
extern s32 D_004A10D4[];
extern f32 D_004A10D8[];
extern Flags8 D_004A10DC[];
extern u8 D_004A1075[];
extern s32 D_00202128;

void func_0018EC40(Obj18EC40 *o) {
    s32 fl;
    s32 v;
    func_0017F470(0xD, 0, D_004A10D0[0]);
    if (D_004A10D8[0] <= 10.0f) return;
    fl = o->x4;
    if (fl & 0x2000) {
        func_0012C320();
        func_00131600(0x69, o->xE);
        o->xA = 2;
        o->xB = 0;
        D_004A10D4[0] = 5;
        D_004A10D8[0] = 0;
        D_004A10DC[0].f.b1 = 1;
        if (D_004A10DC[0].f.b4) {
            v = D_004A1075[0] * 2;
            if (v > 0x7F) v = 0x7F;
            func_0012C720(v);
            func_0012C6B0();
        } else {
            func_0012C720(0x7F);
        }
    } else if (fl & 0x4000) {
        func_00131600(0x68, o->xE);
        o->xA = 2;
        o->xB = 0;
        D_00202128 = 2;
        D_004A10D4[0] = 0;
    }
    func_0017F470(0xD, 0, D_004A10D0[0]);
}
