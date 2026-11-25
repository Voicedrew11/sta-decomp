#include "m2c.h"
typedef struct { u8 v:1; } BF0;
typedef struct { s32 type; s32 pad; s8 st; u8 pad9[5]; u8 eE; u8 padF[5]; BF0 x14; } Arg;
f32 func_00187770(f32, f32, f32);
void func_00131600(s32, s32);
void func_001304B0(s32);
s32 func_00130590(s32, s32, s32);
void func_0018E470(s32);
void func_00189ED0(s32);
void func_0012C320(void);
extern s8 D_001FD680[];
extern s32 D_0020220C;
extern s32 D_00202210;
extern s32 D_00202214;
extern s32 D_00202218;
extern f32 D_0020221C;

void func_0019EDC0(Arg *arg0) {
    s32 b;

    switch (arg0->type) {
    case 0x19:
        D_0020220C = 0;
        D_00202214 = 0;
        D_00202218 = 0;
        func_0012C320();
        func_00130590((s32)D_001FD680, 0, 0);
    }
    if (D_00202210 == 2 && arg0->type == 0x16) {
        if (!arg0->x14.v) {
            b = arg0->pad;
            if (b & 0x10) {
                D_0020221C = 0.0f;
                D_0020220C = !D_0020220C;
                func_00131600(0x66, arg0->eE);
            } else if (b & 0x40) {
                D_0020221C = 0.0f;
                D_0020220C = !D_0020220C;
                func_00131600(0x66, arg0->eE);
            } else if (b & 0x2000) {
                if (D_0020220C == 0) {
                    arg0->x14.v = 1;
                    D_00202210 = 0;
                } else {
                    arg0->st = 9;
                    func_00189ED0(0x28);
                    func_0018E470(0);
                    arg0->pad = 0;
                    arg0->type = 0x1A;
                    D_00202210 = 1;
                }
                func_001304B0(-0x222);
                func_00131600(0x67, arg0->eE);
            }
        }
        D_0020221C = func_00187770(D_0020221C, 1.0f, 3.5f);
    }
}
