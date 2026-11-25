#include "m2c.h"
typedef struct { u8 b[4]; } Buf;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; } B;
typedef struct { u8 pad[0x14]; B x14; } Arg;
extern M2C_UNK D_001F27B0[];
extern M2C_UNK D_001F27C0[];
extern f32 D_001F29E0[];
extern f32 D_001F29E4[];
extern f32 D_001F29E8[];
extern f32 D_001F29EC[];
extern f32 D_00202104;
extern B D_004A0B34[];
void func_00182080(f32, s32, void *, void *, void *, s32);
void func_00181420(void);
void func_00189E90(void);
s32 func_00189000(s32);
void func_001A8B90(s32);
void func_001A8F00(s32);
void func_0012C0A0(void);
void func_00130440(void);
void func_0012C070(s32);
void func_001AB280(void);

void func_0018A650(Arg *arg0) {
    Buf s = {0};

    if (arg0->x14.b2) {
        D_00202104 += 4.0f;
        if (D_00202104 > 128.0f) {
            func_00189E90();
            func_001A8B90(func_00189000(1));
            func_001A8F00(func_00189000(0));
            func_0012C0A0();
            func_00130440();
            D_001F29EC[0] = -2.89f;
            D_001F29E8[0] = -2.89f;
            D_001F29E4[0] = -2.89f;
            D_001F29E0[0] = -2.89f;
            D_004A0B34[0].b2 = 0;
        }
    } else if (D_004A0B34[0].b0) {
        D_00202104 += 4.0f;
        if (D_00202104 > 128.0f) {
            func_00189E90();
            func_0012C070(0);
            func_001AB280();
            func_00130440();
            D_001F29EC[0] = -2.89f;
            D_001F29E8[0] = -2.89f;
            D_001F29E4[0] = -2.89f;
            D_001F29E0[0] = -2.89f;
            D_004A0B34[0].b0 = 0;
        }
    } else if (D_004A0B34[0].b1) {
        D_00202104 += 4.0f;
        if (D_00202104 > 128.0f) {
            func_00189E90();
            func_0012C070(1);
            D_001F29EC[0] = -2.89f;
            D_001F29E8[0] = -2.89f;
            D_001F29E4[0] = -2.89f;
            D_001F29E0[0] = -2.89f;
            D_004A0B34[0].b0 = 0;
        }
    } else {
        D_00202104 -= 4.0f;
        if (D_00202104 < 0.0f) {
            D_00202104 = 0.0f;
        }
    }
    s.b[3] = (s32)D_00202104;
    if (s.b[3] > 0) {
        func_00182080(0.0f, 0, D_001F27B0, D_001F27C0, &s, 0);
        func_00181420();
    }
}
