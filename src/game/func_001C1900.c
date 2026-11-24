#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 rest:6; } BFa;
typedef struct { u8 pad:3; u8 b3:1; u8 rest:4; } BFb;
typedef struct { s8 pad[0x94]; u8 b94; } S390;
typedef struct { s8 pad[0xA8]; BFa a8; } SV;
typedef struct { s8 pad[0x390]; S390 *p390; s8 pad2[0x39C-0x394]; u8 b39C; s8 pad3[0x3C0-0x39D]; SV *p3C0; SV *p3C4; } SS;
s32 func_001D1D50(u8);
s32 func_001D1DA0(u8);
s32 func_0012C400(s32);
void func_001C1A00(s8 *, s8 *);
void func_001C2190(s8 *, s8 *);
void func_001C23E0(s8 *, s8 *);

void func_001C1900(s8 *arg0, s8 *arg1) {
    s8 *t;
    SS *s;
    SV *v;

    t = M2C_FIELD(arg0, s8 **, 0x518);
    s = (SS *)(t + 0x180);
    if (M2C_FIELD(t, BFb *, 0x556).b3 == 0) {
        if (s->p390->b94 & 1) {
            v = s->p3C4;
        } else {
            v = s->p3C0;
        }
        if (v->a8.b1) goto ret; if (v->a8.b0) goto go; ret: return; go: {
            if (func_0012C400(3) != 0) {
                if (func_001D1D50(s->b39C) != 0) {
                    if (func_001D1DA0(s->b39C) != 0) {
                        func_001C2190(arg0, arg1);
                    } else {
                        func_001C1A00(arg0, arg1);
                    }
                } else {
                    func_001C23E0(arg0, arg1);
                }
            }
        }
    }
}
