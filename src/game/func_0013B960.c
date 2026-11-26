#include "m2c.h"
void sceVu0AddVector(f32 *, f32 *, f32 *);
s32 func_0013FB90(s8 *, u8, f32 **, f32 **);
s32 func_0013FC00(s8 *);

void func_0013B960(s8 *arg0, f32 *arg1) {
    f32 *a[4];
    f32 *b[4];
    u8 i;
    u8 n;

    sceVu0AddVector((f32 *)(arg0 + 0x620), (f32 *)(arg0 + 0x620), arg1);
    sceVu0AddVector((f32 *)(arg0 + 0x640), (f32 *)(arg0 + 0x640), arg1);
    sceVu0AddVector((f32 *)(arg0 + 0x660), (f32 *)(arg0 + 0x660), arg1);
    sceVu0AddVector((f32 *)(arg0 + 0x680), (f32 *)(arg0 + 0x680), arg1);
    n = func_0013FC00(arg0);
    for (i = 0; i < n; i++) {
        a[0] = 0;
        b[0] = 0;
        if ((u8)func_0013FB90(arg0, i, a, b)) {
            sceVu0AddVector(a[0], a[0], arg1);
            sceVu0AddVector(b[0], b[0], arg1);
        }
    }
}
