#include "common.h"
#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef union { u128 q; Vec v; } VQ;
typedef struct { s32 pad[4]; s32 x10; u8 x14; u8 pad15[3]; s32 *x18; s32 pad1C; } Info;
void func_00189580(void);
void func_0018A350(u8);
void func_00128460(void *, s32);
void func_00128210(void *);
void func_00155370(void);
void func_00178760(void);
void func_001769C0(void);
void func_0015FC10(void);
void func_0012D650(void);
void func_001296C0(void);
void func_001552A0(void);
void func_001A7D90(s32);
void func_001C9E30(void);
void func_001A8E30(void);
void func_001B06E0(s32, void *, s32);
void func_001B0660(Info *);
void func_001B0450(void);
void func_001B7380(s32, s32);
void func_001B7190(s32, s32);
u8 func_001AA740(void);
void func_001C96F0(s32);
void func_001AA700(s32);
void func_001E1CC0(void);
void func_001E1D30(s32, s32);
s32 func_001E1D20(void);
s32 func_0012C7C0(void);
void func_0012C1A0(s32);
void func_0012F9D0(s32);
void func_0012F6E0(s32);
void func_0012C430(void);
void func_0019A840(void);
s32 func_001C9BF0(void);
void func_001C8F90(void *);
void sceVu0RotMatrixX(Mtx *, Mtx *, f32);
void sceVu0RotMatrixY(Mtx *, Mtx *, f32);
void sceVu0CameraMatrix(Mtx *, void *, Vec *, Vec *);
void sceVu0MulMatrix(void *, void *, Mtx *);
void func_00188F80(void);
void func_0012B600(void);
extern Actor *D_002022E4;
extern s32 D_00201EA4;
extern s32 D_00201E80;
#define IDX ((&D_00201E80)[1])
#define ARR ((s32 **)(&D_00201E80 + 2))
extern s8 D_003139A0[];
extern s32 D_00201E94;
extern f32 D_00201C2C;
extern f32 D_00201EB4;
extern s8 D_00222AF0[];
extern s8 D_00222B20[];
extern s8 D_00222A11[];
extern VQ D_001F1BF0;
extern VQ D_001F1C00;
extern Mtx D_001F2170;
extern s8 D_001F1BB0[];
extern s8 D_00222810[];
extern s8 D_002227D0[];
extern s8 D_002F1900[];
extern s8 D_002F1700[];

void func_0012AC00(s32 arg0) {
    Info info;
    Mtx v;
    VQ a;
    VQ b;
    Mtx m;
    s32 st;
    u64 f;
    s32 i;
    s32 **p;

    func_00189580();
    func_0018A350(0x27);
    st = 1;
    do {
        func_00155370();
        func_00128210(D_00222AF0);
        func_00128210(D_00222B20);
        func_00178760();
        func_001769C0();
        func_0015FC10();
        func_0012D650();
        func_001296C0();
        func_001552A0();
        switch (st) {
        case 0:
            break;
        case 1:
            func_001A7D90(0);
            st++;
            break;
        case 2:
            if (D_002022E4 != NULL && ((f = D_002022E4->pad520[0x80]) & 1) && !((f & 1) && ((f << 61) >> 63))) {
                func_001C9E30();
                if (D_00201EA4 == 1) {
                    func_001A8E30();
                }
                st++;
            }
            break;
        case 3:
            IDX = 0;
            func_001B06E0(arg0, D_003139A0, 0);
            st++;
            break;
        case 4:
            func_001B0660(&info);
            if (info.x10 == arg0 && info.x14 == 3) {
                func_001B0450();
                i = IDX;
                ARR[i] = info.x18;
                func_001B7380(*ARR[i], i);
                func_001B7190(*ARR[IDX], IDX);
                if (D_00201EA4 == 1) {
                    if (func_001AA740() == 1) {
                        func_001C96F0(*ARR[IDX]);
                        func_001AA700(2);
                    }
                } else {
                    func_001C96F0(*ARR[IDX]);
                }
                st++;
            }
            break;
        case 5:
            func_001E1CC0();
            func_001E1D30(arg0, 0);
            st++;
            break;
        case 6:
            if (func_001E1D20()) {
                st++;
            }
            break;
        case 7:
            if (func_0012C7C0()) {
                IDX = !(IDX != 0);
                func_0012C1A0(*ARR[!(IDX != 0)]);
                func_0012F9D0(*info.x18);
                func_0012F6E0(1);
                if (D_00201EA4 == 1) {
                    func_0012C430();
                }
                st = 0;
            }
            break;
        }
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
        func_0012B600();
        D_00201E94++;
    } while (st != 0);
    func_0018A350(0x12);
    func_0019A840();
}
