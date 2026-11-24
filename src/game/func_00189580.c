#include "m2c.h"
extern s32 *D_002020DC;
extern s32 D_0049F8A0[];
extern s32 D_0049FB30[];
extern s32 D_0049FD34[];
extern u32 D_0049FD38[];
extern s32 D_0049FD3C[];
extern s32 D_0049FD80[];
extern s32 D_0049FF84[];
extern u32 D_0049FF88[];
extern s32 D_0049FF8C[];
extern s32 D_004A06C0[];
extern s32 D_004A08C4[];
extern u32 D_004A08C8[];
extern s32 D_004A08CC[];
void func_00159DD0(s32, s32 *, s32 *, s32 *);
void func_00189D50(s32, s32 *, s32);

void func_00189580(void) {
    s32 a; s32 b; s32 c; s32 d; s32 e; s32 f;
    u32 i; s32 *p; s32 *q;
    a = 0; b = 0;
    func_00159DD0(0x0EBC6141, D_002020DC, &a, &b);
    i = 0; if (i < D_0049FF88[0]) { p = D_0049F8A0; q = D_0049FD80; do { func_00189D50(p[0x128], q, a); i++; p++; } while (i < D_0049FF88[0]); }
    c = 0; d = 0;
    D_0049FF84[0] = a; D_0049FF8C[0] = b;
    func_00159DD0(0xF732041D, D_002020DC, &c, &d);
    i = 0; if (i < D_0049FD38[0]) { p = D_0049F8A0; q = D_0049FB30; do { func_00189D50(p[0x94], q, c); i++; p++; } while (i < D_0049FD38[0]); }
    e = 0; f = 0;
    D_0049FD34[0] = c; D_0049FD3C[0] = d;
    func_00159DD0(0x90BC19D0, D_002020DC, &e, &f);
    i = 0; if (i < D_004A08C8[0]) { p = D_0049F8A0; q = D_004A06C0; do { func_00189D50(p[0x378], q, e); i++; p++; } while (i < D_004A08C8[0]); }
    D_004A08C4[0] = e; D_004A08CC[0] = f;
}
