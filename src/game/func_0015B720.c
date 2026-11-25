#include "common.h"
extern Vec D_0030A290, D_001F2150, D_0030A360, D_0030A370;
void func_00102A60(void *, void *);
void func_001027B0(Vec *, Vec *, Vec *);
void func_00102870(Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_00102A18(Vec *, void *, f32);
void func_001029D0(Vec *, Vec *, Vec *);
f32 func_0011DBF0(f32, f32);
float sqrtf(float);

f32 func_0015B720(void *a0, u8 *a1) {
    Vec v60;
    Vec v50;
    Vec v40;
    Vec v30;
    f32 r = 0.01f * *(f32 *)(a1 + 0x30);
    f32 k = *(f32 *)(a1 + 0x1C);
    f32 d;
    f32 s;
    func_00102A60(&v60, a1);
    v60.w = 1.0f;
    func_001027B0(&v60, &D_0030A290, &v60);
    func_00102870(&v50, &v60);
    d = func_00102848(&v50, &D_001F2150);
    d += k;
    if (d < 0.0f) {
        return 0.0f;
    }
    r *= d / (1.0f + k);
    s = sqrtf(func_00102848(&v60, &v60));
    if (*(f32 *)(a1 + 0xC) < s) {
        return 0.0f;
    }
    r *= func_0011DBF0(1.0f - s / *(f32 *)(a1 + 0xC), *(f32 *)(a1 + 0x34));
    func_00102A18(&v40, a1 + 0x10, r);
    func_001029D0(&D_0030A360, &v40, &D_0030A360);
    func_00102A18(&v30, a1 + 0x20, r);
    func_001029D0(&D_0030A370, &v30, &D_0030A370);
    return r;
}
