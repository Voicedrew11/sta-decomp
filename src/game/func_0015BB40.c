#include "common.h"
typedef struct { u8 b0:1; } B;
void func_00102A60(Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
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

void func_0015BB40(Vec *a, Vec *b, f32 f) {
    func_00102A60(D_0030A390, D_003139A0);
    D_0030A39C[0] = 30000.0f;
    if (b != NULL) {
        func_00102A18(D_0030A3A0, b, 1.0f / 255.0f);
    } else {
        func_00102A60(D_0030A3A0, D_003139A0);
        D_0030A3A0[0].x = 0.0f;
    }
    D_0030A3AC[0] = 100.0f;
    if (a != NULL) {
        func_00102A60(D_0030A3B0, a);
    } else {
        D_0030A3B8[0] = 0.0f;
        D_0030A3B0[0].x = 1000.0f;
        D_0030A3B4[0] = 15000.0f;
        D_0030A3BC[0] = 1.0f;
    }
    if (f < 0.0f) {
        D_0030A3C0[0] = 1.0f;
    } else {
        D_0030A3C0[0] = f;
    }
    D_0030A3C4[0] = 0.1f;
    D_0030A3C8[0].b0 = 1;
}
