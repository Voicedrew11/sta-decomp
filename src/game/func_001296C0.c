#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef union { u128 q; Vec v; } VQ;
s32 func_001C9BF0(void);
void func_001C8F90(void *);
void func_00102C20(Mtx *, Mtx *, f32);
void func_00102CC8(Mtx *, Mtx *, f32);
void func_00102DE8(void *, void *, Vec *, Vec *);
void func_001027E0(void *, void *, void *);
void func_00102A70(void *, void *);
f32 func_0011DB00(f32);
extern u64 func_0011F650(f32);
void func_001294A0(void *m0, void *m1, void *m2, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i, f32 j, f32 k);
extern f32 D_00201C2C;
extern f32 D_00201EB4;
extern f32 D_00201C14;
extern f32 D_00201C18;
extern f32 D_00201C1C;
extern u32 D_00201C20;
extern u32 D_00201C24;
extern f32 D_00201E90;
extern f32 D_00222A40[];
extern f32 D_00222A44[];
extern s8 D_00222A11[];
extern s8 D_00222A10[];
extern VQ D_001F1BD0;
extern VQ D_001F1BE0;
extern Mtx D_001F2170;
extern s8 D_001F1BB0[];
extern Mtx D_00222850;
extern Mtx D_00222890;
extern Mtx D_002228D0;
extern Mtx D_00222910;
extern Mtx D_00222950;
extern Mtx D_00222990;
extern Mtx D_002229D0;
extern u64 D_002F1420[];
extern u64 D_002F1510[];
extern Mtx D_002F1680;
extern f32 D_002F1690[];
extern f32 D_002F1694[];
extern f32 D_002F1698[];
extern Mtx D_002F16C0;
extern Mtx D_002F1700;
extern Mtx D_002F1740;
extern Mtx D_002F1780;
extern Mtx D_002F17C0;
extern Mtx D_002F1800;
extern Mtx D_002F1840;
extern Mtx D_002F1880;
extern Mtx D_002F18C0;
extern Mtx D_002F1900;
extern f32 D_001F1BC0[];
extern f32 D_001F1BC4[];
extern f32 D_001F1BC8[];
extern f32 D_001F1BCC[];

void func_001296C0(void) {
    VQ a;
    VQ b;
    Mtx m;
    f32 fov;
    f32 s;
    s32 w;
    f32 k;

    fov = D_00222A40[0];
    switch (D_00222A11[0]) {
    case 0:
        a = D_001F1BD0;
        b = D_001F1BE0;
        func_00102C20(&m, &D_001F2170, WRAP(D_00201C2C));
        func_00102CC8(&m, &m, WRAP(D_00201EB4));
        func_00102DE8(&D_00222850, D_001F1BB0, &a.v, &b.v);
        func_001027E0(&D_00222850, &D_00222850, &m);
        break;
    case 1:
        if (func_001C9BF0()) {
            func_001C8F90(&D_00222850);
        }
        break;
    }
    s = (D_00222A10[0] == 1) ? 0.622222245f : 1.0f;
    fov = 3.1415927f * fov / 360.0f;
    D_00201C14 = s * (128.0f * (1.0f / func_0011DB00(fov)));
    if (D_00222A10[0] == 1) {
        func_001294A0(&D_00222910, &D_002228D0, &D_00222890, D_00201C14, 1.42857146f, 2.22996521f, 2048.0f, 2048.0f, 650.0f, 564.0f, (f32)D_00201C20, (f32)D_00201C24, D_00201C18, D_00201C1C);
    } else {
        if (D_00222A10[0] == 2) {
            k = 1.56097567f;
            w = 616;
        } else {
            k = 1.42857146f;
            w = 616;
        }
        func_001294A0(&D_00222910, &D_002228D0, &D_00222890, D_00201C14, 1.0f, k, 2048.0f, 2048.0f, 929.0f, (f32)w, (f32)D_00201C20, (f32)D_00201C24, D_00201C18, D_00201C1C);
    }
    D_00201E90 = 0.0f;
    s = (D_00222A10[0] == 1) ? 1.24444449f : 1.0f;
    D_00201C14 = s * (320.0f * (1.0f / func_0011DB00(fov)));
    D_00222A44[0] = 0.933300018f;
    if (D_00222A10[0] == 1) {
        func_001294A0(&D_002229D0, &D_00222990, &D_00222950, D_00201C14, 0.803571403f, 1.0f, 2048.0f, 2048.0f, 1355.0f, 993.0f, (f32)D_00201C20, (f32)D_00201C24, D_00201C18, D_00201C1C);
        D_00222A44[0] = 1.01980102f;
    } else {
        func_001294A0(&D_002229D0, &D_00222990, &D_00222950, D_00201C14, 1.0f, 1.0f, 2048.0f, 2048.0f, 1089.0f, 993.0f, (f32)D_00201C20, (f32)D_00201C24, D_00201C18, D_00201C1C);
    }
    fov = D_00201E90;
    D_002F1510[0] = D_002F1420[0] = 0x27F0000 | ((u64)func_0011F650(fov) << 32) | ((u64)func_0011F650(448.0f - fov - 1.0f) << 48);
    func_00102A70(&D_002F18C0, &D_00222950);
    func_00102A70(&D_002F1900, &D_002229D0);
    func_00102A70(&D_002F1700, &D_00222990);
    func_00102A70(&D_002F16C0, &D_00222850);
    func_001027E0(&D_002F1840, &D_002F1900, &D_002F16C0);
    func_001027E0(&D_002F1880, &D_002F1700, &D_002F16C0);
    func_00102A70(&D_002F1780, &D_00222890);
    func_00102A70(&D_002F1740, &D_00222910);
    func_00102A70(&D_002F1680, &D_002F16C0);
    D_002F1690[0] *= -1.0f;
    D_002F1694[0] *= -1.0f;
    D_002F1698[0] *= -1.0f;
    func_001027E0(&D_002F1800, &D_00222910, &D_002F1680);
    func_001027E0(&D_002F17C0, &D_002228D0, &D_002F1680);
    D_001F1BCC[0] = 0.0f;
    D_001F1BC0[0] = 15000.0f;
    D_001F1BC4[0] = 32000.0f;
    D_001F1BC8[0] = 0.499999493f;
}
