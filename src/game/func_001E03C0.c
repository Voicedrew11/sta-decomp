/* round 2 near-miss: 8 words: li constants scheduled between the two lw of the loop-2 preheader */
#include "common.h"
typedef struct { u8 *base; s32 stride; u32 n; s32 st; void (**fn)(s32); u32 cnt; u32 cur; u8 fl; Flags8 f; } L;
extern L D_004BAC30;
void func_001E0680();
static inline u8 *get(u32 i) { L *l = &D_004BAC30; return l->base + l->stride * i; }

void func_001E03C0(void) {
    u32 i;
    s32 j;
    u32 n;
    if (!D_004BAC30.f.f.b1) {
        for (i = 0; i < D_004BAC30.cnt; i++) {
            D_004BAC30.cur = i;
            D_004BAC30.fn[i](0);
        }
        D_004BAC30.cur = -1;
    } else if (D_004BAC30.cur != -1) {
        D_004BAC30.fn[D_004BAC30.cur](0);
    }
    D_004BAC30.st = 0; n = D_004BAC30.n;
    for (j = 0; j < n; j++) {
        u8 c = *get(j);
        if (c == 1) { D_004BAC30.st = 1; break; }
        if (c == 3) D_004BAC30.st = 3;
        if (c == 6) D_004BAC30.st = 6;
        if (c == 2 && D_004BAC30.st != 3 && D_004BAC30.st != 6) D_004BAC30.st = 2;
    }
    if (!(D_004BAC30.fl & 1)) func_001E0680();
}

