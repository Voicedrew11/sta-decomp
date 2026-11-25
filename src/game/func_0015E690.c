#include "common.h"

void sceVu0InterVector(f32 *v0, f32 *v1, f32 *v2, f32 t);
void func_00102870(f32 *v0, f32 *v1);

void func_0015E690(f32 (*m0)[4], f32 (*m1)[4], f32 (*m2)[4], f32 t)
{
    sceVu0InterVector(m0[0], m1[0], m2[0], t);
    sceVu0InterVector(m0[1], m1[1], m2[1], t);
    sceVu0InterVector(m0[2], m1[2], m2[2], t);
    func_00102870(m0[0], m0[0]);
    func_00102870(m0[1], m0[1]);
    func_00102870(m0[2], m0[2]);
}
