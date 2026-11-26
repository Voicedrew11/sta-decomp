#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef union { u128 q; Vec v; } VQ;
void func_00181240(void);
void func_00128A60(void *, s32, s32, s32);
void func_00128460(void *, s32);
void func_00128210(void *);
void func_001891C0(void);
void func_0018A350(u8);
u8 func_001A9470(void);
u8 func_001A9480(void);
u8 func_001A9460(void);
u8 func_001A94A0(void);
void func_0012C6C0(s32);
void func_0012C730(s32);
void func_0012DA60(s32);
void func_001E8500(void);
void func_00155370(void);
void func_00178760(void);
void func_001769C0(void);
void func_0015FC10(void);
void func_0012D650(void);
void func_001296C0(void);
void func_001552A0(void);
s32 func_001C9BF0(void);
void func_001C8F90(void *);
void sceVu0RotMatrixX(Mtx *, Mtx *, f32);
void sceVu0RotMatrixY(Mtx *, Mtx *, f32);
void sceVu0CameraMatrix(Mtx *, void *, Vec *, Vec *);
void sceVu0MulMatrix(void *, void *, Mtx *);
void func_00188F80(void);
void func_0012B600(void);
void func_0012B550(void);
extern s32 D_00201E94;
extern s32 D_00201E98;
extern f32 D_00201C2C;
extern f32 D_00201EB4;
extern s8 D_00222AF0[];
extern s8 D_00222B20[];
extern s32 D_00222B5C[];
extern s32 D_00222B7C[];
typedef struct { u8 a:3; u8 b:3; u8 c:2; } BF;
extern BF D_00222A54[];
extern s8 D_00222A11[];
extern u8 D_00222A10[];
extern VQ D_001F1BF0;
extern VQ D_001F1C00;
extern Mtx D_001F2170;
extern s8 D_001F1BB0[];
extern s8 D_00222810[];
extern s8 D_002227D0[];
extern s8 D_002F1900[];
extern s8 D_002F1700[];

s32 func_0012B8E0(s32 arg0) {
    Mtx v;
    VQ a;
    VQ b;
    Mtx m;
    s32 t;

    func_00181240();
    func_00128A60(D_00222AF0, D_00222B5C[0], D_00222B7C[0], 0x200);
    func_00128460(D_00222AF0, -1);
    func_00128460(D_00222B20, -1);
    func_001891C0();
    func_0018A350(arg0);
    t = func_001A9470() * 2;
    t = (t > 0x7F) ? 0x7F : t;
    func_0012C6C0(t);
    t = func_001A9480() * 2;
    t = (t > 0x7F) ? 0x7F : t;
    func_0012C730(t);
    func_0012DA60(func_001A9460());
    while (!D_00201E98 != 0) {
        func_001E8500();
        D_00222A54[0].b = 0;
        func_00155370();
        func_00128210(D_00222AF0);
        func_00128210(D_00222B20);
        func_00178760();
        func_001769C0();
        func_0015FC10();
        func_0012D650();
        func_001296C0();
        func_001552A0();
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
        func_00188F80();
        func_00128460(D_00222AF0, -1);
        func_00128460(D_00222B20, -1);
        D_00222A10[0] = func_001A94A0();
        func_0012B600();
        D_00201E94++;
    }
    func_0012B550();
    return 0;
}
