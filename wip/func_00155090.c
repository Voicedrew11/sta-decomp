#include "common.h"
f32 sqrtf(f32);
void func_00102A70(void *, void *);
void func_00102A18(Vec *, void *, f32);
void func_001027E0(void *, void *, void *);
extern f32 D_00201F58, D_00201F5C, D_00201F60, D_00201F64, D_00201F68, D_00201F6C, D_00201F70, D_00201F74;
extern s32 D_002022C0;
extern Mtx D_002F1900, D_002F16C0, D_002F1680, D_001F2170, D_002F15C0, D_002F1740, D_002F1640, D_002F1600;
extern Vec D_004B4BD0;

void func_00155090(void) {
    Mtx A;
    Mtx B;
    Mtx C;
    Mtx D;
    Mtx E;

    func_00102A70(&A, &D_002F1900);
    D_00201F74 = 320.0f / A.m[0].x;
    D_00201F70 = 1.0f / sqrtf(1.0f + D_00201F74 * D_00201F74);
    D_00201F74 = D_00201F74 * D_00201F70;
    D_00201F64 = 2000.0f / A.m[0].x;
    D_00201F60 = 1.0f / sqrtf(1.0f + D_00201F64 * D_00201F64);
    D_00201F64 = D_00201F64 * D_00201F60;
    D_00201F6C = 224.0f / A.m[1].y;
    D_00201F68 = 1.0f / sqrtf(1.0f + D_00201F6C * D_00201F6C);
    D_00201F6C = D_00201F6C * D_00201F68;
    D_00201F5C = 2000.0f / A.m[1].y;
    D_00201F58 = 1.0f / sqrtf(1.0f + D_00201F5C * D_00201F5C);
    D_00201F5C = D_00201F5C * D_00201F58;
    func_00102A70(&C, &D_002F16C0);
    func_00102A70(&D, &D_002F1680);
    if (D_002022C0 == -1) {
        func_00102A70(&E, &D_001F2170);
        func_00102A18(&E.m[3], &D_004B4BD0, 1.0f);
        E.m[3].w = 1.0f;
        func_001027E0(&C, &C, &E);
        func_001027E0(&D, &D, &E);
        D_002022C0 = 0;
    }
    func_00102A70(&D_002F15C0, &C);
    func_00102A70(&B, &D_002F1900);
    B.m[0].x = 1.0f;
    B.m[1].y = 1.0f;
    B.m[2].x = 0.0f;
    B.m[2].y = 0.0f;
    func_001027E0(&D_002F1640, &B, &C);
    func_00102A70(&B, &D_002F1740);
    B.m[0].x = 1.0f;
    B.m[1].y = 1.0f;
    B.m[2].x = 0.0f;
    B.m[2].y = 0.0f;
    func_001027E0(&D_002F1600, &B, &D);
}
