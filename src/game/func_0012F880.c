#include "common.h"

typedef struct { s32 a; s32 b; char p8[0x10]; s32 x18; char p1c; u8 b1d; s16 h1e; char p20[0x30]; } E;
extern E D_0026F0D0[64];
void func_00131440(s32 h);

void func_0012F880(void)
{
    s32 n = 64;
    E *e = D_0026F0D0;
    while (n--) {
        if (e->b != -1) {
            func_00131440(e->b);
            e->b = -1;
        }
        if (e->h1e == 2 || e->h1e == 3) {
            func_00131440(e->x18);
            e->x18 = -1;
        }
        e->b1d = 0;
        e++;
    }
}
