#include "m2c.h"
typedef struct {
    s8 on; s8 idx; s8 x2; s8 x3;
    u8 p4[0x7C];
} Snd;
extern Snd D_0022CBC0[];
extern s8 D_0022EBC8[];
extern s8 D_0022EBC0[];
void func_001D9EE0(s32);
void func_001DA920(s8);
void func_001DACB0(s8);

void func_0012E730(s32 arg0) {
    s32 n;
    Snd *s;
    s8 *p;

    n = 0x3F;
    s = D_0022CBC0;
    while (n--) {
        if (s->on != 0 && s->x2 == arg0) {
            s->on = 0;
        }
        s++;
    }
    func_001D9EE0(arg0);
    p = &D_0022EBC8[arg0];
    if (*p != -1) {
        func_001DA920(*p);
    }
    *p = -1;
    p = &D_0022EBC0[arg0];
    if (*p != -1) {
        func_001DACB0(*p);
    }
    *p = -1;
}
