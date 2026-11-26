#include "m2c.h"
s32 func_0013E8B0(s8 *);
s32 func_0013E910(s8 *);
s8 *func_001A5460(s32 *);
s32 func_0013EE30(s8 *);
s32 func_00137870(s8 *, s8 *, f32 *);
s32 func_00138460(s8 *, s8 *, f32 *);
void func_0013E6A0(s8 *, s32);
void sceVu0AddVector(s8 *, s8 *, f32 *);
void func_00137730(s8 *, f32 *);

void func_0013A2C0(s8 *arg0) {
    f32 vec[4] __attribute__((aligned(16)));
    s32 it;
    s8 *o;
    s8 *other;
    o = M2C_FIELD(arg0, s8 **, 0x518) + 0x180;
    it = 0;
    if ((func_0013E8B0(arg0) & 0xFF) != 1 && (func_0013E910(arg0) & 0xFF) != 1) {
        it = 0;
        other = func_001A5460(&it);
        if (other != NULL) {
            do {
                if (other != arg0 && !(func_0013E8B0(other) & 0xFF)) {
                    if (func_0013EE30(other)) {
                        if (func_00137870(arg0, other, vec)) {
                            func_0013E6A0(arg0, 1);
                            if (vec[1] > 0.0f) {
                                vec[1] = 0.0f;
                            }
                            sceVu0AddVector(o + 0x40, o + 0x40, vec);
                            func_00137730(arg0, vec);
                        }
                    } else if (func_00138460(arg0, other, vec)) {
                        if (vec[1] > 0.0f) {
                            vec[1] = 0.0f;
                        }
                        sceVu0AddVector(o + 0x40, o + 0x40, vec);
                        func_00137730(arg0, vec);
                    }
                }
                other = func_001A5460(&it);
            } while (other != NULL);
        }
    }
}
