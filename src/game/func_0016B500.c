#include "common.h"
typedef struct { u8 lo:2; u8 r:6; u8 pad[3]; } P;
void func_00102A60(Vec *, void *);
void func_001027B0(Vec *, void *, Vec *);
void func_001549D0(void);
void func_00155900(void);
void func_00154610(s32, s32);
extern s32 D_00201FF8;
extern s32 D_00201FFC;
extern s32 D_00202000;
extern u8 D_002F1840[];

s32 func_0016B500(void *a0, P a1, s32 a2) {
    f32 *w;
    s32 n;
    s32 k;
    Vec v;
    n = a1.lo + a2;
    func_00102A60(&v, a0);
    w = &v.w;
    *w = 1.0f;
    func_001027B0(&v, D_002F1840, &v);
    if (*w < 0.0f) *w = 0.0f;
    if (!(*w <= 32000.0f)) *w = 32000.0f;
    k = 511.0f - 512.0f * *w / 32000.0f;
    D_00201FFC = n;
    func_001549D0();
    func_00155900();
    func_00154610(D_00201FFC, k);
    D_00201FF8 = 1;
    D_00202000 = 1;
    return 1;
}
