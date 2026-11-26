#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef union { u128 q; Vec v; } VQ;
typedef struct { u8 pad[0x1D8]; u8 f; } Inner;
extern Inner **D_00201E80[2];
#define C (D_00201E80[2])
#define D (D_00201E80[3])
static inline s32 IS(Inner **p) { if (p != NULL) return ((*p)->f & 1) != 0; else return 0; }
void func_001B4F20(Inner *);
void func_001B4B50(Inner *, f32);
void func_001B4AF0(Inner *);
void func_001ADD30(void);
void func_001A6950(void);
void func_0012D650(void);
void func_0012C7C0(void);
void func_001B4CB0(void);
s32 func_0019A790(void);
s32 func_001787A0(void);
void func_0015D650(void);
void func_0015BB40(void *, void *, f32);
s32 func_001C9B50(void);
void func_0015B360(void *, s32);
void func_001B7290(void);
void func_0015C0C0(void *);
void func_0013BBC0(f32);
void func_001BC0E0(void);
s32 func_001C9BF0(void);
void func_001C8F90(void *);
void sceVu0RotMatrixX(Mtx *, Mtx *, f32);
void sceVu0RotMatrixY(Mtx *, Mtx *, f32);
void sceVu0CameraMatrix(Mtx *, void *, Vec *, Vec *);
void sceVu0MulMatrix(void *, void *, Mtx *);
void func_001ADA30(f32);
void func_0015D300(void);
void func_00169400(f32);
void func_00159970(f32);
void func_00175B10(f32);
void func_00159310(s32);
void func_001601C0(s32);
u8 func_001A9490(void);
void func_0015FEB0(s32, f32);
u8 func_001A94A0(void);
void func_0013BB70(void);
void func_001AD390(void);
void func_00169630(void);
void func_00188F80(void);
extern s8 *D_002022E4;
extern f32 D_00201C2C;
extern f32 D_00201EB4;
extern s8 D_00222A11[];
extern u8 D_00222A10[];
extern Flags8 D_00222A52[];
extern VQ D_001F1BF0;
extern VQ D_001F1C00;
extern Mtx D_001F2170;
extern s8 D_001F1BB0[];
extern s8 D_00222810[];
extern s8 D_002227D0[];
extern s8 D_002F1900[];
extern s8 D_002F1700[];
extern f32 D_002F16C0[];
extern s32 D_00222738[];
extern s32 D_0022273C[];
extern s32 D_00222740[];
extern s32 D_00222744[];

void func_0012A520(f32 dt) {
    Mtx v;
    VQ a;
    VQ b;
    Mtx m;
    s32 t;

    if (C) func_001B4F20(*C);
    if (D) func_001B4F20(*D);
    func_001ADD30();
    func_001A6950();
    func_0012D650();
    func_0012C7C0();
    func_001B4CB0();
    if (!(func_0019A790() != 0) == 0) {
        t = func_001787A0();
        if (IS(C)) func_001B4B50(*C, dt);
        if (IS(D)) func_001B4B50(*D, dt);
        D_00222738[0] = func_001787A0() - t;
        func_0015D650();
        if (D_002022E4) func_0015BB40(D_002022E4 + 0x560, D_002022E4 + 0x550, *(f32 *)(D_002022E4 + 0x570));
        func_0015B360(D_002F16C0, 1 << func_001C9B50());
        func_001B7290();
        func_0015C0C0(D_002F16C0);
        t = func_001787A0();
        func_0013BBC0(dt);
        D_0022273C[0] = func_001787A0() - t;
        func_001BC0E0();
        switch (D_00222A11[0]) {
        case 0:
            a = D_001F1BF0;
            b = D_001F1C00;
            sceVu0RotMatrixX(&m, &D_001F2170, WRAP(D_00201C2C));
            sceVu0RotMatrixY(&m, &m, WRAP(D_00201EB4));
            sceVu0CameraMatrix(&v, D_001F1BB0, &a.v, &b.v);
            sceVu0MulMatrix(&v, &v, &m);
            break;
        case 1:
            if (func_001C9BF0()) {
                func_001C8F90(&v);
            }
            break;
        }
        sceVu0MulMatrix(D_00222810, D_002F1900, &v);
        sceVu0MulMatrix(D_002227D0, D_002F1700, &v);
        t = func_001787A0();
        func_001ADA30(dt);
        D_00222740[0] = func_001787A0() - t;
        func_0015D300();
        t = func_001787A0();
        func_00169400(dt);
        D_00222744[0] = func_001787A0() - t;
        func_00159970(dt);
        func_00175B10(dt);
        func_00159310(0);
        func_001601C0(0);
        func_0015FEB0(func_001A9490(), dt);
        D_00222A10[0] = func_001A94A0();
    } else {
        t = func_001787A0();
        if (IS(C)) func_001B4AF0(*C);
        if (IS(D)) func_001B4AF0(*D);
        D_00222738[0] = func_001787A0() - t;
        func_0013BB70();
        t = func_001787A0();
        func_001AD390();
        D_00222740[0] = func_001787A0() - t;
        t = func_001787A0();
        func_00169630();
        D_00222744[0] = func_001787A0() - t;
        func_00159310(1);
        func_001601C0(1);
    }
    if (!D_00222A52[0].f.b3) func_00188F80();
}
