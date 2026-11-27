#include "m2c.h"
typedef struct { u8 pad[0x1D]; s8 b1D; s16 h1E; u8 pad2[0x30]; } S;
void sceVu0InversMatrix(void *, void *);
void SndEmit_Update3D_1_0012FC20(S *);
void SndEmit_UpdateAmbientRandom_1_00130090(S *);
void SndEmit_UpdateLooping_1_001302A0(S *);
extern u8 D_00201C38;
extern s32 D_00201ED8;
extern f32 D_0026F090[];
extern S D_0026F0D0[];
extern f32 D_002F16C0[];

void SndEmit_Update_1_0012F6F0(void) {
    S *p;
    s32 n;

    if (D_00201ED8 != 0) {
        D_00201ED8 = 0;
        return;
    }
    if (D_00201C38 != 0) {
        sceVu0InversMatrix(D_0026F090, D_002F16C0);
        n = 0x40;
        p = D_0026F0D0;
        while (n--) {
            if (p->b1D) {
                if (p->h1E == 0) SndEmit_UpdateLooping_1_001302A0(p);
                else if (p->h1E == 1) SndEmit_UpdateAmbientRandom_1_00130090(p);
                else if (p->h1E == 2 || p->h1E == 3) SndEmit_Update3D_1_0012FC20(p);
            }
            p++;
        }
    }
}
