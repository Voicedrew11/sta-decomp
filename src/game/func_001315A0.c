#include "common.h"

typedef struct { char p0[0xA]; u16 hA; char pc[2]; u8 bE; char pf; f32 v[4]; s32 x20; char p24[0xC]; s32 x30; s32 x34; } T;
extern T *volatile D_00201ED0;
void sceVu0CopyVector(f32 *v0, f32 *v1);
void func_00131640(void);

void func_001315A0(s32 a, u8 b, f32 *v)
{
    D_00201ED0->x30 = a;
    D_00201ED0->bE = 4;
    D_00201ED0->hA = b;
    D_00201ED0->x20 = 0;
    D_00201ED0->x34 = 0;
    sceVu0CopyVector(D_00201ED0->v, v);
    func_00131640();
}
