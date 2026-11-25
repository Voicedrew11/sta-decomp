#include "m2c.h"
typedef struct { u8 pad[0x14]; f32 x14; f32 x18; u8 pad1C[0x10]; f32 x2C; f32 x30; u8 pad34[8]; u32 x3C; } G;
extern G D_0048D060;
void func_001832D0(G *, s32, s32);

void func_00184CF0(s8 *a0, s32 a1, u32 n) {
    if (n >= 500) {
        D_0048D060.x2C = *(f32 *)(a0 + 0x38);
        D_0048D060.x30 = *(f32 *)(a0 + 0x3C);
        D_0048D060.x14 = 1.0f;
        D_0048D060.x18 = 1.0f;
        D_0048D060.x3C = 0x80FFFFFF;
        switch (n - 500) {
        case 0: case 1: case 2: case 3: case 4: case 5: break;
        case 6: case 7: case 8: case 9:
            D_0048D060.x2C = 3.0f + *(f32 *)(a0 + 0x38);
            D_0048D060.x30 = 3.0f + *(f32 *)(a0 + 0x3C);
            break;
        }
        if (n > 1000) func_001832D0(&D_0048D060, n - 1500, 1);
        else func_001832D0(&D_0048D060, n - 500, 0);
    }
}
