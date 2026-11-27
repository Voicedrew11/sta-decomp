#include "common.h"
void Sfx_RequestStop_1_00167240(s32);
typedef struct { u8 p[0xA8]; s32 xA8; } S;
void Proj_ReleaseEffect_0_001476D0(S *a) {
 volatile s32 t; s32 x; t = a->xA8; x = t; if (x != 0) { Sfx_RequestStop_1_00167240(x); a->xA8 = 0; }
}
