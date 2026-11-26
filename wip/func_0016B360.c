#include "m2c.h"
#include "common.h"
typedef union { u32 w; struct { u8 lo:2; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:3; u8 pad[3]; } f; } F;
typedef struct M { struct M *x0; u16 p4; u16 n; } M;
typedef struct { M *m; s32 x4; } H;
typedef struct { u8 p[0xB0]; s32 xB0; u8 pB4[0x3C]; Vec xF0; } R;
extern s32 D_00201F2C;
extern s32 D_00201FF8;
extern s32 D_00201FFC;
extern s32 D_00202000;
extern s32 D_00202004;
void sceVu0AddVector(Vec *, M *, s8 *);
void func_001549D0(void);
void func_00155900(void);
void func_001548F0(s32);
s32 func_0016B500(Vec *, F, s32);

s32 func_0016B360(H *h, F f, s32 a2) {
    Vec v;
    F g;
    s32 k;
    s32 ret;
    s32 d;
    M *m;
    R *r;

    if (f.f.b4) {
        d = D_00201F2C;
        if (h == NULL || (m = h->m) == NULL) {
            r = NULL;
        } else {
            r = (R *)((s8 *)m + 0x40);
            r = (R *)((s8 *)r + d * (m->n * 0x140 + 0x200));
            r->xB0 = h->x4 - (s32)m;
        }
        sceVu0AddVector(&v, h->m->x0->x0, (s8 *)&r->xF0);
        return func_0016B500(&v, f, a2);
    }
    g = f;
    k = (g.f.lo) + a2;
    ret = 0;
    if (D_00201FFC != k || D_00202004 != 0 || D_00202000 != 0) {
        D_00201FFC = k;
        func_001549D0();
        func_00155900();
        func_001548F0(D_00201FFC);
        ret = 1;
        D_00201FF8 = 1;
    }
    D_00202000 = 0;
    D_00202004 = 0;
    return ret;
}
