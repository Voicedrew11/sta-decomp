#include "common.h"
extern u8 *volatile D_004BAC30[];
extern volatile s32 D_004BAC34[];
extern volatile u32 D_004BAC38[];
void func_001E0180(u8 *a) {
    u32 i;
    if (a == 0) {
        for (i = 0; i < D_004BAC38[0]; i++) (D_004BAC30[0] + D_004BAC34[0] * i)[1] = 1;
    } else {
        a[1] = 1;
    }
}
