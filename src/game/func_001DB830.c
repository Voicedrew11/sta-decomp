#include "common.h"
void FlushCache(s32, s32);
s32 sceSifDmaStat(u32);
u32 sceSifSetDma(void *, s32);
void func_001D8680(s32 a, s32 b, s32 c, ...);
extern s32 D_004BAA2C[];
extern s32 D_004BAA40[];
extern s32 D_004BAA44[];
extern s32 D_004BAA48[];
extern s32 D_004BAA4C[];
extern s32 D_004BAA50[];
extern s32 D_004BAA54[];
extern s32 D_004BAA58[];
extern s32 D_004BAA60[];
extern s32 D_004BAA64[];
extern s32 D_004BAA68[];
extern s32 D_004BAA6C[];

s32 func_001DB830(void) {
    if (D_004BAA58[0] == 0) return 1;
    if (sceSifDmaStat(D_004BAA54[0]) >= 0) return 0;
    func_001D8680(4, 1, 0xB00, D_004BAA40[0], D_004BAA50[0]);
    D_004BAA48[0] -= D_004BAA50[0];
    if (D_004BAA48[0] <= 0) {
        D_004BAA58[0] = 0;
        return 1;
    }
    D_004BAA44[0] += 0x4000;
    D_004BAA40[0] += 0x4000;
    if (D_004BAA48[0] > 0x4000) {
        D_004BAA4C[0] = 0x4000;
        D_004BAA50[0] = 0x4000;
    } else {
        D_004BAA4C[0] = D_004BAA48[0];
        D_004BAA50[0] = D_004BAA48[0];
        D_004BAA4C[0] = (D_004BAA4C[0] + 0xF) & ~0xF;
    }
    D_004BAA6C[0] = 0;
    D_004BAA60[0] = D_004BAA44[0];
    D_004BAA64[0] = D_004BAA2C[0];
    D_004BAA68[0] = D_004BAA4C[0];
    FlushCache(0, D_004BAA44[0]);
    D_004BAA54[0] = sceSifSetDma(D_004BAA60, 1);
    return 0;
}
