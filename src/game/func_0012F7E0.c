#include "common.h"

typedef struct { char p0[0x1D]; s8 b1d; s16 h1e; f32 v20[4]; f32 v30[4]; char p40[0x10]; } E;
extern E D_0026F0D0[64];
extern s32 D_00201ED8;
void sceVu0AddVector(f32 *v0, f32 *v1, f32 *v2);
void func_0012C440(f32 *v);

void func_0012F7E0(f32 *v)
{
    s32 n = 64;
    E *e = D_0026F0D0;
    while (n--) {
        if (e->b1d) {
            sceVu0AddVector(e->v20, e->v20, v);
            if (e->h1e == 1)
                sceVu0AddVector(e->v30, e->v30, v);
        }
        e++;
    }
    func_0012C440(v);
    D_00201ED8 = 1;
}
