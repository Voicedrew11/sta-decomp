#include "common.h"
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9; u8 xA; u8 padB[3]; u8 xE; u8 padF[5]; Flags8 x14; } O;
extern Flags8 D_004A1010[];
extern s32 D_004A0FF0[];
extern s32 D_00202120[2];
s32 func_001E8290(void);
void func_001304B0(s32);
void func_00131600(s32, u8);
void func_0018D140(O *o) {
    if (o->x4 & 0x2000) {
        o->xA = 2;
        o->x14.f.b2 = 1;
        D_004A1010[0].f.b0 = 0;
        func_001304B0(-0x666);
        D_00202120[func_001E8290()] = D_004A0FF0[0];
        func_00131600(0x67, o->xE);
    }
}
