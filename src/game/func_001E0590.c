#include "common.h"
typedef struct { f32 x, y, z, w; } V4;
typedef struct { u16 a:1; u16 b:8; u16 c:1; u16 r:6; } BF;
extern s32 D_002023A8;
extern V4 D_004BAC20[];
extern s32 D_004BAC30[];
extern s32 D_004BAC34[];
extern s32 D_004BAC38[];
extern BF D_004BAC4C[];
void func_001DFCB0(s32);
void func_001E0590(s32 a0, s32 a1, s32 a2, V4 *v) {
    if (D_002023A8 == 0 && a0 != 0 && v != NULL) {
        D_004BAC20[0] = *v;
        D_004BAC38[0] = a2;
        D_004BAC34[0] = a1;
        D_004BAC30[0] = a0;
        D_004BAC4C[0].a = 0;
        D_004BAC4C[0].b = 0;
        D_004BAC4C[0].c = 0;
        func_001DFCB0(0);
        D_002023A8 = 1;
    }
}
