/* round 2 near-miss: 8 words: li constants scheduled between the two lw of the loop-2 preheader */
#include "common.h"
typedef struct { u8 *base; s32 stride; u32 n; } L; extern L D_004BAC30;
extern s32 D_004BAC3C[];
extern void (**D_004BAC40[])(s32);
extern u32 D_004BAC44[];
extern u32 D_004BAC48[];
extern u8 D_004BAC4C[];
extern Flags8 D_004BAC4D[];
void func_001E0680();
static inline u8 *get(u32 i) { L *l = &D_004BAC30; return l->base + l->stride * i; }

void func_001E03C0(void) {
    u32 i;
    s32 j;
    u32 n;
    if (!D_004BAC4D[0].f.b1) {
        for (i = 0; i < D_004BAC44[0]; i++) {
            D_004BAC48[0] = i;
            D_004BAC40[0][i](0);
        }
        D_004BAC48[0] = -1;
    } else if (D_004BAC48[0] != -1) {
        D_004BAC40[0][D_004BAC48[0]](0);
    }
    D_004BAC3C[0] = 0; n = D_004BAC30.n;
    for (j = 0; j < n; j++) {
        u8 c = *get(j);
        if (c == 1) { D_004BAC3C[0] = 1; break; }
        if (c == 3) D_004BAC3C[0] = 3;
        if (c == 6) D_004BAC3C[0] = 6;
        if (c == 2 && D_004BAC3C[0] != 3 && D_004BAC3C[0] != 6) D_004BAC3C[0] = 2;
    }
    if (!(D_004BAC4C[0] & 1)) func_001E0680();
}
