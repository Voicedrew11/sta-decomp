#include "m2c.h"
typedef struct { u8 b[4]; } Buf;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } B;
extern M2C_UNK D_001F27B0[];
extern M2C_UNK D_001F27C0[];
extern s32 D_00201CF0;
extern f32 D_0020210C;
extern f32 D_00202110;
extern f32 D_00202114;
extern B D_004A0B34[];
extern u8 D_004A0B2A[];
extern s8 D_004A0B2C[];
extern s32 D_004A0AE8[];
extern s32 D_004A0AEC[];
extern f32 D_004A0B10[];
extern f32 D_004A0B14[];
extern f32 D_004A0B18[];
extern f32 D_004A0B1C[];
extern s8 D_004A0B20[];
extern void (*D_001F2930[])(void *);
extern void (*D_001F2880[])(void *);
void func_00182080(f32, s32, void *, void *, void *, s32);
void func_00181420(void);
void func_0018A580(s32, f32 *, f32, f32, f32);
void func_0018A650(void *);
void func_00154700(s32, s32);
void func_001545D0(void);
void func_001543E0(s32, s32);
void func_001544C0(void);
void func_0018A910(void);
void func_001DD700(s32, s8);
void func_00187B20(s32);
u8 func_001A9430(void);
void func_00157110(u8);
void func_00155900(void);

void func_00189F40(void) {
    Buf s;

    func_00154700(5, 0);
    func_001545D0();
    func_001543E0(0x42, 0x44);
    func_001544C0();
    func_0018A580(D_00201CF0 != 0x12 && D_00201CF0 != 0x28, &D_0020210C, 0.0f, 64.0f, 4.0f);
    func_0018A580(D_004A0B34[0].b4, &D_00202114, 0.0f, 128.0f, 2.0f);
    if (D_001F2930[D_00201CF0] != NULL) {
        D_004A0AE8[0] = 0;
        D_004A0AEC[0] = 0;
        D_001F2930[D_00201CF0](D_004A0B20);
        func_00181420();
    }
    func_0018A910();
    func_001DD700(D_00201CF0, D_004A0B2C[0]);
    func_00181420();
    if (D_001F2880[D_00201CF0] != NULL) {
        D_004A0AE8[0] = 0;
        D_004A0AEC[0] = 0;
        D_001F2880[D_00201CF0](D_004A0B20);
        func_00181420();
    }
    if (!D_004A0B34[0].b3) {
        func_0018A580(D_004A0B2A[0], &D_00202110, 0.0f, 64.0f, 4.0f);
        if (D_004A0B2A[0]) {
            D_001F2880[0](D_004A0B20);
            func_00187B20(0);
            func_00181420();
        }
        func_0018A650(D_004A0B20);
        func_00187B20(0);
        func_00181420();
        func_00157110((func_001A9430() - 0x20) * 2 + 0x80);
        if (!(D_004A0B1C[0] <= 0.0f)) {
            s.b[0] = (s32)(D_004A0B10[0] / 2.0f);
            s.b[1] = (s32)(D_004A0B14[0] / 2.0f);
            s.b[2] = (s32)(D_004A0B18[0] / 2.0f);
            s.b[3] = (s32)(D_004A0B1C[0] / 2.0f);
            func_00182080(0.0f, 0, D_001F27B0, D_001F27C0, &s, 0);
            func_00181420();
        }
    } else {
        D_004A0B34[0].b3 = 0;
    }
    func_00155900();
}
