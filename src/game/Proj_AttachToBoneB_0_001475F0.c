#include "common.h"
extern Vec D_001F2160;
s32 Actor_GetBoneWorldMatrix_0_001464A0(s32, u8, void *);
void sceVu0CopyVector(void *, void *);
void sceVu0ApplyMatrix(void *, void *, void *);

void Proj_AttachToBoneB_0_001475F0(s8 *o) {
    Vec v;
    u8 b;
    s32 *p;
    s32 q;
    b = (u32)*(f32 *)(o + 0x60);
    p = *(s32 **)(*(s8 **)(o + 0x90) + 0x170);
    q = p ? *p : 0;
    if (q && Actor_GetBoneWorldMatrix_0_001464A0(q, b, o + 0xC0)) {
        sceVu0CopyVector(&v, *(s8 **)(o + 0x90) + *(u16 *)(o + 0x94) * 0x80 + 0x2C0);
        v.w = 1.0f;
        sceVu0ApplyMatrix(o, o + 0xC0, &v);
        sceVu0CopyVector(o + 0xF0, &D_001F2160);
    }
}
