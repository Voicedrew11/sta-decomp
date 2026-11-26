#include "m2c.h"
extern f32 D_001F2160[];
s8 *func_001A5460(s32 *);
s32 func_0013EE40(s8 *);
double func_0011DB78(double, double);
double fptodp(f32);
double dpadd(double, double);
f32 dptofp(double);
s8 *func_00169B50(s32, s32, s32, s32);
void func_00167710(s8 *, f32 *);
void func_00146A70(s32, s8 *, s32, u16);
float sqrtf(float);
#define POS(p) ((p) ? (f32 *)(*(s32 *)((p) + 0x518) + 0x90) : D_001F2160)

void func_0014A5F0(s8 *a0) {
    f32 *q;
    s32 it;
    s8 *p;
    u32 id;
    s32 n;
    s32 ok;
    f32 *pos;
    double dz;
    s8 *e;
    if (*(s32 *)(a0 + 0xA8) == 0) {
        it = 0;
        p = func_001A5460(&it);
        id = (u32)*(f32 *)(a0 + 0x60);
        while (p) {
            n = 0;
            if (*(u16 *)p != 0 && !func_0013EE40(p)) {
                pos = POS(p);
                q = POS(p);
                dz = func_0011DB78(fptodp(pos[2] - *(f32 *)(a0 + 8)), 2.0);
                n += sqrtf(dptofp(dpadd(func_0011DB78(fptodp(q[0] - *(f32 *)(a0 + 0)), 2.0), dz))) < *(f32 *)(a0 + 0x50);
                ok = 0;
                if (*(f32 *)(a0 + 4) + *(f32 *)(a0 + 0x54) <= POS(p)[1] && POS(p)[1] <= *(f32 *)(a0 + 4) + *(f32 *)(a0 + 0x58)) {
                    ok = 1;
                }
                n *= ok;
                if (n) {
                    if (id && (e = func_00169B50(id, 0, 0, 0))) {
                        func_00167710(e, POS(p));
                    }
                    func_00146A70(*(s32 *)(a0 + 0x90), p, 0, (s32)*(f32 *)(a0 + 0x64));
                }
            }
            p = func_001A5460(&it);
        }
        *(s32 *)(a0 + 0xA8) = 1;
    }
}
