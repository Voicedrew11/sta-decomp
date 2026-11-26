#include "m2c.h"
s32 func_0013E8B0(s8 *);
s8 *func_001A5460(s32 *);
s32 func_00137E60(s8 *, s8 *, f32 *);
void sceVu0AddVector(s8 *, s8 *, f32 *);
void func_00137730(s8 *, f32 *);
void sceVu0CopyVector(f32 *, s8 *);
f32 sceVu0InnerProduct(f32 *, f32 *);
f32 sqrtf(f32);

void func_0013A190(s8 *arg0) {
    f32 vec[4] __attribute__((aligned(16)));
    s32 it;
    s8 *o;
    s8 *other;
    f32 *y;

    o = M2C_FIELD(arg0, s8 **, 0x518) + 0x180;
    it = 0;
    sceVu0CopyVector(vec, o + 0x50);
    y = &vec[1];
    *y = 0.0f;
    if (sqrtf(sceVu0InnerProduct(vec, vec)) < 0.1f) return;
    it = 0;
    other = func_001A5460(&it);
    if (other != NULL) {
        do {
            if (other != arg0 && !(func_0013E8B0(other) & 0xFF)) {
                if (func_00137E60(arg0, other, vec)) {
                    if (*y > 0.0f) {
                        *y = 0.0f;
                    }
                    sceVu0AddVector(o + 0x40, o + 0x40, vec);
                    func_00137730(arg0, vec);
                }
            }
            other = func_001A5460(&it);
        } while (other != NULL);
    }
}
