#include "common.h"
#include "actor.h"
typedef struct { u8 pad[8]; u16 x8; u16 xA; } E;
typedef struct { u8 b[0x40]; } Dst;
extern Actor *D_002022E4;
void func_001D1E80(s32, s32, E *, s32, s32);
s8 *func_001D1F20(s32, s32, s32, s32, E *, s32);
void func_00167600(s8 *, Actor *);
void func_001C79B0(Dst *);
void func_001672B0(s8 *, Dst *);
void func_001AD2C0(s32 a0, s32 a1, s32 a2, E *e, s32 t0, s32 t1) {
    Dst d;
    s8 *o;
    if (t1) {
        switch (e->x8) {
        case 0:
            func_001D1E80(a0, a2, e, t0, t1);
            break;
        case 1:
            o = func_001D1F20(a0, 0, a1, a2, e, t0);
            if (o) {
                func_00167600(o, D_002022E4);
                if (e->xA == 0xFFFF) {
                    func_001C79B0(&d);
                    func_001672B0(o, &d);
                }
            }
            break;
        }
    }
}
