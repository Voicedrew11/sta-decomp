#include "common.h"
typedef struct { u8 b0:1; } B;
typedef struct { u128 q[4]; } M;
void sceVu0CopyVector(Vec *, Vec *);
void memset(void *, s32, s32);
extern s8 D_0030A2D0[];
extern M D_0030A310;
extern M D_0030A350;
extern Vec D_0030A390[];
extern f32 D_0030A39C[];
extern Vec D_0030A3A0[];
extern f32 D_0030A3AC[];
extern Vec D_0030A3B0[];
extern f32 D_0030A3B4[];
extern f32 D_0030A3B8[];
extern f32 D_0030A3BC[];
extern f32 D_0030A3C0[];
extern f32 D_0030A3C4[];
extern B D_0030A3C8[];
extern Vec D_003139A0[];

void func_0015BCA0(void) {
    memset(D_0030A2D0, 0, 0x2110);
    sceVu0CopyVector(D_0030A390, D_003139A0);
    D_0030A39C[0] = 30000.0f;
    sceVu0CopyVector(D_0030A3A0, D_003139A0);
    D_0030A3A0[0].x = 0.0f;
    D_0030A3AC[0] = 100.0f;
    D_0030A3B0[0].x = 1000.0f;
    D_0030A3B8[0] = 0.0f;
    D_0030A3B4[0] = 15000.0f;
    D_0030A3BC[0] = 1.0f;
    D_0030A3C0[0] = 1.0f;
    D_0030A3C4[0] = 0.1f;
    D_0030A3C8[0].b0 = 1;
    D_0030A350 = *(M *)D_0030A390;
    D_0030A310 = *(M *)D_0030A390;
}
