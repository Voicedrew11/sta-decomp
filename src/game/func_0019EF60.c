#include "m2c.h"
typedef union { u128 q; u32 w[4]; } V;
typedef union { u32 w; u8 b[4]; } C;
typedef struct { u8 p:2; u8 v:1; } B;
void func_001545D0(void);
void func_001543E0(s32, s32);
void func_001544C0(void);
void func_00181420(void);
void func_00182080(s32, f32, V *, V *, C *, s32);
extern V D_001F3200[];
extern V D_001F3210[];
extern s32 D_004A331C[];
extern s32 D_004A3324[];
extern s32 D_004A3328[];
extern B D_004A332C[];

void func_0019EF60(s8 *arg0) {
    C col;
    V a;
    V b;

    a = D_001F3200[0];
    b = D_001F3210[0];
    col.w = 0x80808080;
    col.b[3] = D_004A3324[0];
    if (D_004A332C[0].v) {
        D_004A3324[0] = 0;
        D_004A3328[0] = 0x41200000;
        D_004A331C[0] = 0;
        arg0[0xA] = 2;
    }
    func_001545D0();
    func_001543E0(0x42, 0x46);
    func_001544C0();
    func_00182080(0, 0.0f, &a, &b, &col, 0);
    func_00181420();
    func_001545D0();
    func_001543E0(0x42, 0x44);
    func_001544C0();
}
